// limit (c) copyright

#include "VoxelLandscape.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"

#include "Editor.h"
#include "EditorViewportClient.h"


DECLARE_CYCLE_STAT(TEXT("Voxel World ~ Create Voxel World"), STAT_CreateVoxelWorld, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel World ~ Destroying Voxel World"), STAT_DestroyVoxelWorld, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel World ~ Updating Octree"), STAT_UpdateOctree, STATGROUP_Voxel);

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
			ThreadPool->Create(4, 64 * 1024);

			if (TerrainCreated)
			{
				DestroyVoxelWorld();
			}
			/*float RadiusHeighestVoxel = WorldSize / (float)VoxelsPerChunk * 2.f;

			for (int i = 0; i < MaximumLOD; i++)
			{
				RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
			}*/
			SetActorScale3D(FVector(128.f, 128.f, 128.f));
			TimeForWorldGenerate = FDateTime::Now().GetTicks();
			GeneratorLandscape->GeneratorInit();
			GenerateLandscape();

			if (EnabledLOD)
			{
				ManagerCheckPositionThreadHandle = new VoxelManager(this, UGameplayStatics::GetPlayerController(GetWorld(), 0), DrawingRange, MaximumLOD);

				if (TransitionMesh)
				{
					OctreeNeighborsChecker = new VoxelOctreeNeighborsChecker(this);
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

		if (ManagerCheckPositionThreadHandle)
		{
			delete ManagerCheckPositionThreadHandle;
			ManagerCheckPositionThreadHandle = nullptr;
		}
		if (OctreeNeighborsChecker)
		{
			delete OctreeNeighborsChecker;
			OctreeNeighborsChecker = nullptr;
		}

		MainOctree.Reset();

		ChangesOctree.Empty();
		ChunksCreation.Empty();
		ChunksRemoving.Empty();
		ChunksGeneration.Empty();

		for (auto& it : PoolThreads)
		{
			it->Cancel();
		}		
		int TotalChunks = PoolChunks->PoolChunks.Num();
		for (auto& Chunk : PoolChunks->PoolChunks)
		{
			Chunk->DestroyComponent();
		}
		int TimeAfterDestroy = FDateTime::Now().GetTicks();
		UE_LOG(VoxelArt, Log, TEXT("Voxel World was destroyd in %f s. (chunks %d)"), (TimeAfterDestroy - TimeBeforeDestroy) / 10000.f / 1000.f, TotalChunks);
		GEngine->ForceGarbageCollection(true);
		ThreadPool->Destroy();
		TerrainCreated = false;
	}
}

void AVoxelLandscape::SpawnBoxTest(FVector location, float radius, float width, FColor color)
{
	DrawDebugBox(GetWorld(), location, FVector(radius, radius, radius), color, false, 13.f, 5, width);
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
		}
#endif
	}
	else
	{
		Super::Tick(DeltaTime);

		UpdateOctree();
	}
}

void AVoxelLandscape::UpdateOctree()
{
	SCOPE_CYCLE_COUNTER(STAT_UpdateOctree);

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
	{

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
		//FIntVector PlayerPositionToWorld = TransferToWorld(PlayerPositionToWorld);

		for (auto& ChunkData : ChunksCreation)
		{
			ChunkData->Priority = (PlayerPositionToWorld - ChunkData->Position).Size();
		}
		ChunksCreation.Sort([](const FVoxelChunkData& A, const FVoxelChunkData& B)
			{
				return A.Priority > B.Priority;
			});
	}

	int32 Index = 0;
	while (Index < ChunksPerFrame && ChunksCreation.Num() > 0)
	{
		FVoxelChunkData* ChunkData = ChunksCreation.Pop();
		OctreeMutex.Lock();
		TSharedPtr<FVoxelOctreeData> Octant = ChunkData->CurrentOctree.Pin();
		OctreeMutex.Unlock();

		if (Octant.IsValid())
		{
			if (!Octant->HasChildren())
			{
				if(Octant->Data != nullptr)
				{
					//if (chunk->chunk->Active == true)
					{
						ChunksRemoving.Add(Octant->Data);
					}
				}

				OctreeMutex.Lock();
				Octant->Data = ChunkData;
				OctreeMutex.Unlock();

				SpawnChunk(ChunkData);
				Index++;
			}
		} 
	}

	if (ChunksRemoving.Num() > 0 && ChunksCreation.Num() == 0)
	{
		if(TaskWorkGlobalCounter.GetValue() == 0)
		{
			if (!StatsShowed)
			{
				int timeAfter = FDateTime::Now().GetTicks();
				UE_LOG(VoxelArt, Log, TEXT("Voxel World was generated in %f s. (%d chunks)"), (timeAfter - TimeForWorldGenerate) / 10000.f / 1000.f, PoolChunks->PoolChunks.Num());
				StatsShowed = true;
			}
			while (ChunksRemoving.Num() > 0)
			{
				FVoxelChunkData* ChunkData = ChunksRemoving.Pop();

				if (IsValid(ChunkData->Chunk) && ChunkData->Chunk->Active)
				{
					ChunkData->Chunk->SetActive(false);

					delete ChunkData;
					ChunkData = nullptr;
				}
			}
		}
	}
	while (ChunksGeneration.Num() > 0)
	{
		FVoxelChunkData* ChunkData = ChunksGeneration.Pop();

		if (ChunkData != nullptr)
		{
			PutChunkOnGeneration(ChunkData);
		}
	}
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
	OctreeDensity = new FVoxelOctreeDensity(GeneratorLandscape, 0, WorldSize, TransferToVoxelWorld(FVector(0, 0, 0)));
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
		FString absolutePathPackage = FPaths::GameContentDir() + "/" + DirectoryName + "/";

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

	if (!IsValid(PoolChunk))
	{
		PoolChunk = PoolChunks->AddChunkToPool();
	}
	ChunkInit(PoolChunk, ChunkData);
	PutChunkOnGeneration(ChunkData);
}

void AVoxelLandscape::PutChunkOnGeneration(FVoxelChunkData* ChunkData)
{
	TaskWorkGlobalCounter.Increment();
	FAsyncTask<FMesherAsyncTask>* MesherTask = new FAsyncTask<FMesherAsyncTask>(this, ChunkData);
	MesherTask->StartBackgroundTask(ThreadPool);
}

void AVoxelLandscape::ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData)
{
	if (Chunk)
	{
		ChunkData->Chunk = Chunk;

		Chunk->CurrentOctree =			ChunkData->CurrentOctree;
		Chunk->Material =				Material;
		Chunk->GeneratorLandscape =		GeneratorLandscape;

		Chunk->SetMaterial(0, Material);
		Chunk->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //QueryAndPhysics
		Chunk->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic); //ECC_WorldDynamic
		Chunk->AttachToComponent(WorldComponent, FAttachmentTransformRules::KeepWorldTransform);
		Chunk->SetWorldLocation(TransferToGameWorld(ChunkData->Position));
		Chunk->SetActive(true);
	}
}

void AVoxelLandscape::GetVoxelValue(FIntVector Position, float& Value, FColor& Color)
{
	OctreeDensity->GetLeaf(Position)->GetVoxelDensity(this, Position, Value, Color);
}

FIntVector AVoxelLandscape::TransferToVoxelWorld(FVector P)
{
	return (FIntVector)GetTransform().InverseTransformPosition(P);
}

FVector AVoxelLandscape::TransferToGameWorld(FIntVector P)
{
	return GetTransform().TransformPosition((FVector)P);
}

void AVoxelLandscape::SetVoxelValue(FIntVector Position, float Value)
{
	OctreeDensity->GetLeaf(Position)->SetVoxelDensity(this, Position, Value);
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

#if WITH_EDITOR
bool AVoxelLandscape::ShouldTickIfViewportsOnly() const
{
	return true;
}
#endif