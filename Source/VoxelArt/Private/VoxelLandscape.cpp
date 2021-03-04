// limit (c) copyright

#include "VoxelLandscape.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"

#include "Editor.h"
#include "EditorViewportClient.h"


DECLARE_CYCLE_STAT(TEXT("Voxel ~ Create World"), STAT_CreateVoxelWorld, STATGROUP_Voxel);

DECLARE_CYCLE_STAT(TEXT("Voxel ~ Destroy World"), STAT_DestroyVoxelWorld, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Destroy World ~ Destroy Threads"), STAT_DestroyThreads, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Destroy World ~ Clear Data Chunks"), STAT_ClearDataChunks, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Destroy World ~ Destroy Chunks"), STAT_DestroyChunks, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Destroy World ~ Destroy Thread Pool"), STAT_DestroyPoolThread, STATGROUP_Voxel);

DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree"), STAT_UpdateOctree, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Enqueue octants"), STAT_EnqueueOctree, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Update Priority"), STAT_UpdatePriority, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Create chunks"), STAT_CreateChunks, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Create chunks ~ Remove Old Chunk"), STAT_RemoveOldChunk, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Create chunks ~ Octant Init"), STAT_OctantInit, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Create chunks ~ Octant Data Init"), STAT_OctantDataInit, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Create chunks ~ Spawn Chunk"), STAT_SpawnChunk, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Remove chunks"), STAT_RemoveChunks, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Updating Octree ~ Update Octree chunks"), STAT_UpdateChunks, STATGROUP_Voxel);

DECLARE_CYCLE_STAT(TEXT("Voxel ~ Spawn Chunk ~ Adding to Task"), STAT_AddChunkToTask, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Spawn Chunk ~ Initialize"), STAT_ChunkInitialize, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel ~ Spawn Chunk ~ Adding to Pool"), STAT_AddChunkToPool, STATGROUP_Voxel);

DEFINE_LOG_CATEGORY(VoxelArt);

AVoxelLandscape::AVoxelLandscape()
{
	PrimaryActorTick.bCanEverTick = true;
	//	PrimaryActorTick.bHighPriority = true;

	WorldComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = WorldComponent;

	/* Object pooler component */
	PoolChunks = CreateDefaultSubobject<UVoxelPoolComponent>(TEXT("PoolChunks"));

	ThreadPool = FQueuedThreadPool::Allocate();
}

void AVoxelLandscape::BeginPlay()
{
	Super::BeginPlay();

	if (EnabledWorldInGame)
	{
		CreateVoxelWorld();
	}
}

void AVoxelLandscape::Destroyed()
{
	bSaveDensityInGame = false;
	DestroyVoxelWorld();
}

void AVoxelLandscape::CreateVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

	if (GeneratorLandscape)
	{
		if (MinimumLOD < 0)
		{
			UE_LOG(VoxelArt, Error, TEXT("Minimum LOD cannot be less then zero!"));
		}
		else if (MinimumLOD > MaximumLOD)
		{
			UE_LOG(VoxelArt, Error, TEXT("Minimum LOD cannot be greater then Maximum LOD!"));
		}
		else
		{
			if (TerrainCreated)
			{
				bSaveDensityInGame = true;
				DestroyVoxelWorld();
			}

			TimeForWorldGenerate = FDateTime::Now().GetTicks();
			//ThreadPool->Create(4, 128 * 1024);

			SetActorScale3D(FVector(VoxelMin, VoxelMin, VoxelMin));
			GeneratorLandscape->GeneratorInit();
			GenerateLandscape();

			if (EnabledLOD)
			{
				OctreeManagerThread = new VoxelOctreeManager(this, UGameplayStatics::GetPlayerController(GetWorld(), 0), DrawingRange, MaximumLOD);

				if (TransitionMesh)
				{
					OctreeNeighborsCheckerThread = new VoxelOctreeNeighborsChecker(this);
				}
			}
			TerrainCreated = true;
		}
	}
	else
	{
		UE_LOG(VoxelArt, Error, TEXT("Generator of lansdcape is not exist!"));
	}
}

void AVoxelLandscape::DestroyVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_DestroyVoxelWorld);

	if (TerrainCreated)
	{
		int TimeBeforeDestroy = FDateTime::Now().GetTicks();
		int32 TotalChunks = 0;
		{
			SCOPE_CYCLE_COUNTER(STAT_DestroyThreads);

			//OctreeManagerThread->EnsureCompletion();
			delete OctreeManagerThread;
			OctreeManagerThread = nullptr;

			//OctreeNeighborsCheckerThread->EnsureCompletion();
			delete OctreeNeighborsCheckerThread;
			OctreeNeighborsCheckerThread = nullptr;
		}
		{
			SCOPE_CYCLE_COUNTER(STAT_ClearDataChunks);

			MainOctree.Reset();

			ChangesOctree.Empty();
			ChunksCreation.Empty();
			ChunksRemoving.Empty();
			ChunksGeneration.Empty();

			/* World Density should be removed after playing */
			if (!bSaveDensityInGame)
			{
				// TODO: to make memory deleting for leaves otherwise memory is wrong
				delete OctreeDensity;
				OctreeDensity = nullptr;
			}

			for (auto& it : PoolThreads)
			{
				it->Cancel();
			}
			PoolThreads.Empty();
		}
		{
			SCOPE_CYCLE_COUNTER(STAT_DestroyChunks);

			TotalChunks = PoolChunks->PoolChunks.Num();
			for (auto& Chunk : PoolChunks->PoolChunks)
			{
				Chunk->DestroyComponent();
				Chunk = nullptr;
			}
			PoolChunks->PoolChunks.Empty();
			PoolChunks->FreeChunks.Empty();
		}
		{
			SCOPE_CYCLE_COUNTER(STAT_DestroyPoolThread);

			//GEngine->ForceGarbageCollection(true);
			//ThreadPool->Destroy();
			TerrainCreated = false;
			StatsShowed = false;
		}
		int32 TimeAfterDestroy = FDateTime::Now().GetTicks();
		UE_LOG(VoxelArt, Log, TEXT("Voxel World was destroyd in %f s. (chunks %d)"), (TimeAfterDestroy - TimeBeforeDestroy) / 1000.f / 10000.f, TotalChunks);
	}
}

void AVoxelLandscape::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DestroyVoxelWorld();

	Super::EndPlay(EndPlayReason);
}

void AVoxelLandscape::Tick(float DeltaTime)
{
	if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor)
	{
#if WITH_EDITOR
		if (TerrainCreated)
		{
			UpdateOctree();

			TimeToCallGarbageCollection += 0.01f;
			if (TimeToCallGarbageCollection > 5.f)
			{
				/*for (auto& Chunk : ChunksCreation)
				{
					delete Chunk;
					Chunk = nullptr;
				}
				for (auto& Chunk : ChunksRemoving)
				{
					delete Chunk;
					Chunk = nullptr;
				}
				ChunksCreation.Empty();
				ChunksRemoving.Empty();*/

				TimeToCallGarbageCollection = 0.f;

				//GEngine->ForceGarbageCollection(true);

				UE_LOG(VoxelArt, Warning, TEXT("GC called %d"), ChunksCreation.Num());
			}
		}
#endif
	}
	else
	{
		Super::Tick(DeltaTime);

		if (TerrainCreated)
		{
			UpdateOctree();
		}
	}
}

void AVoxelLandscape::UpdateOctree()
{
	SCOPE_CYCLE_COUNTER(STAT_UpdateOctree);
	{
		SCOPE_CYCLE_COUNTER(STAT_EnqueueOctree);

		TSharedPtr<FChunksRenderInfo> ChunksChangesArray;
		while (ChangesOctree.Peek(ChunksChangesArray))
		{
			ChangesOctree.Dequeue(ChunksChangesArray);

			for (auto& Chunk : ChunksChangesArray->ChunksCreation)
			{
				ChunksCreation.Add(Chunk);
			}
			for (auto& Chunk : ChunksChangesArray->ChunksRemoving)
			{
				ChunksRemoving.Add(Chunk);
			}
			for (auto& Chunk : ChunksChangesArray->ChunksGeneration)
			{
				ChunksGeneration.Add(Chunk);
			}
			ChunksChangesArray->ChunksCreation.Empty();
			ChunksChangesArray->ChunksRemoving.Empty();
			ChunksChangesArray->ChunksGeneration.Empty();
		}
	}
	{
		SCOPE_CYCLE_COUNTER(STAT_UpdatePriority);

		FViewport* activeViewport = GEditor->GetActiveViewport();
		FEditorViewportClient* editorViewClient = (activeViewport != nullptr) ? (FEditorViewportClient*)activeViewport->GetClient() : nullptr;
		FIntVector PlayerPositionToWorld;
#if WITH_EDITOR
		if (GetWorld()->WorldType == EWorldType::Editor || GetWorld()->WorldType == EWorldType::EditorPreview)
		{
			PlayerPositionToWorld = TransferToVoxelWorld(editorViewClient->GetViewLocation());
		}
		else
		{
			PlayerPositionToWorld = TransferToVoxelWorld(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation());
		}
#endif

		for (auto& ChunkData : ChunksCreation)
		{
			ChunkData->Priority = (PlayerPositionToWorld - ChunkData->Position).Size();
		}
		ChunksCreation.Sort([](const FVoxelChunkData& A, const FVoxelChunkData& B)
			{
				return A.Priority > B.Priority;
			});
	}
	{
		SCOPE_CYCLE_COUNTER(STAT_CreateChunks);

		int32 Index = 0;
		while (Index < ChunksPerFrame)
		{
			if (ChunksCreation.Num() > 0)
			{
				FVoxelChunkData* ChunkData = ChunksCreation.Pop();
				TSharedPtr<FVoxelOctreeData> Octant;
				{
					SCOPE_CYCLE_COUNTER(STAT_OctantInit);

					//TODO: Fix this line because it takes a lot time for waiting
					OctreeMutex.Lock();
					Octant = ChunkData->CurrentOctree.Pin();
					OctreeMutex.Unlock();
				}

				if (Octant.IsValid())
				{
					if (!Octant->HasChildren())
					{
						/* Remove old chunk if it exist */
						{
							SCOPE_CYCLE_COUNTER(STAT_RemoveOldChunk);

							if (Octant->Data != nullptr)
							{
								ChunksRemoving.Add(Octant->Data);
							}
						}
						/* Octant Data initialize */
						{
							SCOPE_CYCLE_COUNTER(STAT_OctantDataInit);

							OctreeMutex.Lock();
							Octant->Data = ChunkData;
							OctreeMutex.Unlock();
						}
						/* Spawn new chunk for octant */
						{
							SCOPE_CYCLE_COUNTER(STAT_SpawnChunk);

							SpawnChunk(ChunkData);
						}
						Index++;
					}
				}
			}
			else { Index = ChunksPerFrame; }
		}
	}
	{
		SCOPE_CYCLE_COUNTER(STAT_RemoveChunks);

		if (TaskWorkGlobalCounter.GetValue() == 0)
		{
			int32 Index = 0;
			while (Index < ChunksPerFrame)
			{
				if (ChunksRemoving.Num() > 0 && ChunksCreation.Num() == 0)
				{
					if (!StatsShowed)
					{
						int32 timeAfter = FDateTime::Now().GetTicks();
						UE_LOG(VoxelArt, Log, TEXT("Voxel World was generated in %f s. (%d chunks)"), (timeAfter - TimeForWorldGenerate) / 1000.f / 10000.f, PoolChunks->PoolChunks.Num());
						StatsShowed = true;
					}
					//while (ChunksRemoving.Num() > 0)
					{
						FVoxelChunkData* ChunkData = ChunksRemoving.Pop();

						if (IsValid(ChunkData->Chunk) && ChunkData->Chunk->Active)
						{
							ChunkData->Chunk->SetPoolActive(false);
							PoolChunks->FreeChunks.Add(ChunkData->Chunk);

							delete ChunkData;
							ChunkData = nullptr;

							Index++;
						}
					}
				}
				else { Index = ChunksPerFrame; }
			}
		}
	}
	/*{
		SCOPE_CYCLE_COUNTER(STAT_UpdateChunks);

		while (ChunksGeneration.Num() > 0)
		{
			FVoxelChunkData* ChunkData = ChunksGeneration.Pop();

			if (ChunkData != nullptr)
			{
				PutChunkOnGeneration(ChunkData);
			}
		}
	}*/
}

/*
* UpdateWorld doesn't support the Priorities
* because its not needed
*/

void AVoxelLandscape::UpdateWorld()
{
	if (!TerrainCreated)
	{
		UE_LOG(VoxelArt, Error, TEXT("World has not been created!"));
		return;
	}
	OctreeMutex.Lock();
	for (auto& Chunk : PoolChunks->PoolChunks)
	{
		Chunk->ClearAllMeshSections();
	}
	GetLeavesAndQueueToGeneration(MainOctree);
	OctreeMutex.Unlock();
}

void AVoxelLandscape::GetLeavesAndQueueToGeneration(TSharedPtr<FVoxelOctreeData> Octant)
{
	if (!Octant->HasChildren())
	{
		if (Octant->Data != nullptr)
		{
			if (IsValid(Octant->Data->Chunk))
			{
				ChunksGeneration.Add(Octant->Data);
			}
		}
	}
	else
	{
		for (auto& ChildOctant : Octant->GetChildren())
		{
			GetLeavesAndQueueToGeneration(ChildOctant);
		}
	}
}

void AVoxelLandscape::RemoveOctreeDensityLeaves(FVoxelOctreeDensity* Octant)
{
	if (!Octant->HasChildren())
	{
		//if (Octant->Data != nullptr)
		{
			//if (IsValid(Octant->Data->Chunk))
			{
				//ChunksGeneration.Add(Octant->Data);
			}
		}
	}
	else
	{
		for (auto& ChildOctant : Octant->GetChildren())
		{
			RemoveOctreeDensityLeaves(ChildOctant);

			if (!ChildOctant->HasChildren())
			{

			}
		}
	}
}

void AVoxelLandscape::SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks)
{
	for (auto& Chunk : Chunks)
	{
		//if (Chunk->Chunk != nullptr)
		{
			//if (Chunk->Chunk->hasOwnGrid)
			{
				//	Chunk->Grid = Chunk->chunk->DensityMap;
				SavedChunks.Add(Chunk->NodeID, Chunk);
			}
		}
	}
}

void AVoxelLandscape::GenerateLandscape()
{
	if (!OctreeDensity)
	{
		OctreeDensity = new FVoxelOctreeDensity(GeneratorLandscape, 0, WorldSize, TransferToVoxelWorld(FVector(0, 0, 0)));
	}
	MainOctree = TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(nullptr, (1 << 3) | 0x00, 0, WorldSize, TransferToVoxelWorld(FVector(0, 0, 0))));

	GenerateOctree(MainOctree);
}

void AVoxelLandscape::CreateTextureDensityMap()
{
	if (GeneratorDensity)
	{
		FString FileName = MapName;
		int width = MapSize;
		int height = MapSize;
		uint8* pixels = (uint8*)malloc(width * height * 4);

		float StepTexture = WorldSize / MapSize;

		if (RenderType == RenderTexture::RedGreenBlue)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					uint8 PixelColorWB = 0;/*(uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
						static_cast<float>((x - width * 0.5f) * StepTexture),
						static_cast<float>((y - height * 0.5f) * StepTexture),
						0)
					), -1.f, 1.0f) * 63.f + 128);*/

					if (PixelColorWB == 191)
					{
						/*FColor PixelColorRGB = GeneratorDensity->GetColorMap(FVector(
							static_cast<float>((x - width * 0.5f) * StepTexture),
							static_cast<float>((y - height * 0.5f) * StepTexture),
							0
						));

						pixels[y * 4 * width + x * 4 + 0] = PixelColorRGB.R; // R
						pixels[y * 4 * width + x * 4 + 1] = PixelColorRGB.G; // G
						pixels[y * 4 * width + x * 4 + 2] = PixelColorRGB.B; // B
						pixels[y * 4 * width + x * 4 + 3] = PixelColorRGB.A; // A*/
					}
					else
					{
						pixels[y * 4 * width + x * 4 + 0] = PixelColorWB; // R
						pixels[y * 4 * width + x * 4 + 1] = PixelColorWB; // G
						pixels[y * 4 * width + x * 4 + 2] = PixelColorWB; // B
						pixels[y * 4 * width + x * 4 + 3] = 255;
					}
				}
			}
		}
		else
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					/*	uint8 PixelColorWB = (uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
							static_cast<float>((x - width * 0.5f) * StepTexture),
							static_cast<float>((y - height * 0.5f) * StepTexture),
							0)
						), -1.f, 1.0f) * 63.f + 128);

						pixels[y * 4 * width + x * 4 + 0] = PixelColorWB; // R
						pixels[y * 4 * width + x * 4 + 1] = PixelColorWB; // G
						pixels[y * 4 * width + x * 4 + 2] = PixelColorWB; // B
						pixels[y * 4 * width + x * 4 + 3] = 255;*/
				}
			}
		}

		// Create Package
		FString pathPackage = FString("/Game/" + DirectoryName + "/");
		FString absolutePathPackage = FPaths::ProjectContentDir() + "/" + DirectoryName + "/";

		FPackageName::RegisterMountPoint(*pathPackage, *absolutePathPackage);

		UPackage* Package = CreatePackage(nullptr, *pathPackage);
		FName TextureName = MakeUniqueObjectName(Package, UTexture2D::StaticClass(), FName(*FileName));

		UTexture2D* Texture = NewObject<UTexture2D>(Package, TextureName, RF_Public | RF_Standalone);

		// Texture Settings
		Texture->PlatformData = new FTexturePlatformData();
		Texture->PlatformData->SizeX = width;
		Texture->PlatformData->SizeY = height;
		Texture->PlatformData->PixelFormat = PF_R8G8B8A8;

		// Passing the pixels information to the texture
		FTexture2DMipMap* Mip = new(Texture->PlatformData->Mips) FTexture2DMipMap();
		Mip->SizeX = width;
		Mip->SizeY = height;

		Mip->BulkData.Lock(LOCK_READ_WRITE);
		uint8* TextureData = (uint8*)Mip->BulkData.Realloc(height * width * sizeof(uint8) * 4);
		FMemory::Memcpy(TextureData, pixels, sizeof(uint8) * height * width * 4);
		Mip->BulkData.Unlock();

		// Updating Texture & mark it as unsaved
		Texture->AddToRoot();
		Texture->UpdateResource();
		Package->MarkPackageDirty();

		UE_LOG(VoxelArt, Log, TEXT("Density Map Texture was created!"));
		UE_LOG(VoxelArt, Log, TEXT("Check your directory to find it"));

		free(pixels);
		pixels = NULL;

	}
	else
	{
		UE_LOG(VoxelArt, Error, TEXT("You should choose generator of the density!"));
	}
}

void AVoxelLandscape::GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant)
{
	if (Octant->Depth == MinimumLOD)
	{
		Octant->Data = new FVoxelChunkData(Octant, Octant->Depth, Octant->Position, Octant->Size, VoxelsPerChunk, 0.f);
		SpawnChunk(Octant->Data);
	}
	else
	{
		Octant->AddChildren();

		for (auto& Leaf : Octant->GetChildren())
		{
			GenerateOctree(Leaf);
		}
	}
}

void AVoxelLandscape::SpawnChunk(FVoxelChunkData* ChunkData)
{
	UVoxelChunkComponent* PoolChunk = PoolChunks->GetChunkFromPool();
	{
		SCOPE_CYCLE_COUNTER(STAT_AddChunkToPool);

		if (!IsValid(PoolChunk))
		{
			PoolChunk = PoolChunks->AddChunkToPool();
		}
	}
	{
		SCOPE_CYCLE_COUNTER(STAT_ChunkInitialize);

		ChunkInit(PoolChunk, ChunkData);
	} 
	{
		SCOPE_CYCLE_COUNTER(STAT_AddChunkToTask);

		PutChunkOnGeneration(ChunkData);
	}
}

void AVoxelLandscape::PutChunkOnGeneration(FVoxelChunkData* ChunkData)
{
	TaskWorkGlobalCounter.Increment();
	FAsyncTask<FMesherAsyncTask>* MesherTask = new FAsyncTask<FMesherAsyncTask>(this, ChunkData);
	MesherTask->StartBackgroundTask(/*ThreadPool*/);

	PoolThreads.Add(MesherTask);
}

void AVoxelLandscape::ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData)
{
	if (Chunk)
	{
		ChunkData->Chunk = Chunk;

		Chunk->CurrentOctree = ChunkData->CurrentOctree;
		Chunk->Material = Material;
		Chunk->GeneratorLandscape = GeneratorLandscape;

		Chunk->SetMaterial(0, Material);
		Chunk->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //QueryAndPhysics
		Chunk->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic); //ECC_WorldDynamic
		Chunk->AttachToComponent(WorldComponent, FAttachmentTransformRules::KeepWorldTransform);
		Chunk->SetWorldLocation(TransferToGameWorld(ChunkData->Position));
		Chunk->SetPoolActive(true);
	}
}

void AVoxelLandscape::GetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float& Value, FColor& Color)
{
	if (OutOctant == nullptr || OutOctant->HasChildren() || !OutOctant->IsInside(Position))
	{
		OutOctant = OctreeDensity->GetLeaf(Position);
	}
	OutOctant->GetVoxelDensity(this, Position, Value, Color);
}

void AVoxelLandscape::SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor)
{
	if (OutOctant == nullptr || OutOctant->HasChildren() || !OutOctant->IsInside(Position))
	{
		OutOctant = OctreeDensity->GetLeaf(Position);
	}
	OutOctant->SetVoxelValue(this, Position, Density, Color, bSetDensity, bSetColor);
}

FIntVector AVoxelLandscape::TransferToVoxelWorld(FVector P)
{
	return (FIntVector)GetTransform().InverseTransformPosition(P);
}

FVector AVoxelLandscape::TransferToGameWorld(FIntVector P)
{
	return GetTransform().TransformPosition((FVector)P);
}

void AVoxelLandscape::GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree)
{
	if (Box.BoxOverlapOctree(CurrentOctree))
	{
		if (CurrentOctree->HasChildren())
		{
			for (auto& ChildOctant : CurrentOctree->GetChildren())
			{
				GetOverlapingOctree(Box, ChildOctant, OverlapingOctree);
			}
		}
		else
		{
			OverlapingOctree.Add(CurrentOctree);
		}
	}
}

FORCEINLINE int AVoxelLandscape::GetIndex(FIntVector P)
{
	return P.X + P.Y * (VoxelsPerChunk + 1 + NORMALS) + P.Z * (VoxelsPerChunk + 1 + NORMALS) * (VoxelsPerChunk + 1 + NORMALS);
}

void AVoxelLandscape::VoxelDebugBox(FVector Position, float Radius, float Width, FColor Color)
{
	DrawDebugBox(GetWorld(), Position, FVector(Radius, Radius, Radius), Color, false, 13.f, 5, Width);
}

#if WITH_EDITOR
bool AVoxelLandscape::ShouldTickIfViewportsOnly() const
{
	return true;
}
#endif