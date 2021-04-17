// Voxel Art Plugin © limit 2018

#include "VoxelWorld.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"
#include "AssetRegistryModule.h"
#include "VoxelLogInterface.h"
#include "AssetToolsModule.h"
#include "VoxelPlayerGame.h"
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

AVoxelWorld::AVoxelWorld()
{
	PrimaryActorTick.bCanEverTick = true;

	WorldComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = WorldComponent;

	/* Object pooler component */
	PoolChunks = CreateDefaultSubobject<UVoxelPoolComponent>(TEXT("PoolChunks"));

	ThreadPool = FQueuedThreadPool::Allocate();
}

void AVoxelWorld::BeginPlay()
{
	Super::BeginPlay();

	if (EnabledWorldInGame)
	{
		VoxelScenePlayer = nullptr;

		FActorSpawnParameters Transient = FActorSpawnParameters();
		Transient.ObjectFlags = RF_Transient;

		VoxelScenePlayerClass = AVoxelPlayerGame::StaticClass();
		VoxelScenePlayer = GetWorld()->SpawnActor<AVoxelPlayerInterface>(VoxelScenePlayerClass, Transient);
		VoxelScenePlayer->SetVoxelWorld(this);

		CreateVoxelWorld();
	}
}

void AVoxelWorld::Destroyed()
{
	DestroyVoxelWorld();
}


void AVoxelWorld::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (bWorldCreated)
	{
		DestroyVoxelWorld();
	}
}

void AVoxelWorld::Tick(float DeltaTime)
{
	if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor)
	{
#if WITH_EDITOR
		if (bWorldCreated && bEnableUpdateOctree)
		{
			UpdateOctree();

			TimeToCallGarbageCollection += 0.01f;
			if (TimeToCallGarbageCollection > 15.f)
			{
				TimeToCallGarbageCollection = 0.f;

				UE_LOG(VoxelArt, Log, TEXT("GC called"));
			}
		}
#endif
	}
	else
	{
		Super::Tick(DeltaTime);

		if (bWorldCreated && bEnableUpdateOctree)
		{
			UpdateOctree();
		}
	}
}

void AVoxelWorld::CreateVoxelWorldInEditor()
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

	StartupDelegates(this);

	if (bWorldCreated)
	{
		DestroyVoxelWorld();
	}
	if (!VoxelScenePlayer)
	{
		FActorSpawnParameters Transient = FActorSpawnParameters();
		Transient.ObjectFlags = RF_Transient;

		VoxelScenePlayer = GetWorld()->SpawnActor<AVoxelPlayerInterface>(VoxelScenePlayerClass, Transient);
	}
	CreateVoxelWorld();
}

void AVoxelWorld::CreateVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

	if (!WorldGenerator)
	{
		IVoxelLogInterface::LogMessage(INVTEXT("World Generator is not exist! (Select: Voxel World -> Main -> World Generator)"), "Error");
		return;
	}
	if (MinimumLOD < 0)
	{
		IVoxelLogInterface::LogMessage(INVTEXT("Minimum LOD cannot be less then zero!"), "Error");
		return;
	}
	if (MinimumLOD > MaximumLOD)
	{
		IVoxelLogInterface::LogMessage(INVTEXT("Minimum LOD cannot be greater then Maximum LOD!"), "Error");
		return;
	}

	TimeForWorldGenerate = FDateTime::Now().GetTicks();
	//ThreadPool->Create(4, 128 * 1024);

	SetActorScale3D(FVector(VoxelMin, VoxelMin, VoxelMin));
	WorldGenerator->GeneratorInit();
	GenerateLandscape();

	if (SaveFile)
	{
		if (SaveFile->IsDataSaved())
		{
			SaveFile->SetVoxelWorld(this);
			SaveFile->LoadSavedData();
		}
		else
		{
			IVoxelLogInterface::LogMessage(INVTEXT("World has not been saved!"), "Error");
		}
	}
	if (EnabledLOD)
	{
		OctreeManagerThread = new VoxelOctreeManager(this, DrawingRange, MaximumLOD);

		if (TransitionMesh && MesherType == Meshers::MarchingCubes)
		{
			OctreeNeighborsCheckerThread = new VoxelOctreeNeighborsChecker(this);
		}
	}
	else
	{
		bEnableUpdateOctree = true;
	}
	bWorldCreated = true;
}

void AVoxelWorld::SaveWorldUtility()
{
	if (SaveFile)
	{
		SaveFile->SetVoxelWorld(this);
		SaveFile->SaveData();

		SaveFile->MarkPackageDirty();
		SaveFile->PostEditChange();
		SaveFile->AddToRoot();
	}
	else
	{
		SaveFile = SaveWorldToFile();
	}
}

AVoxelPlayerInterface* AVoxelWorld::GetVoxelScenePlayer()
{
	return VoxelScenePlayer;
}

UVoxelSaveData* AVoxelWorld::SaveWorldToFile()
{
	if (bWorldCreated)
	{
		FString ObjectName = TEXT("WorldSave");

		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		FString PackageName = FString(TEXT("/Game/VoxelSaves/"));
		AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

		UPackage* Package = CreatePackage(*PackageName);
		UPackage* OuterPack = Package->GetOutermost();
		Package->FullyLoad();

		UVoxelSaveData* NewSave = NewObject<UVoxelSaveData>(OuterPack, *ObjectName, RF_Public | RF_Standalone);
		
		NewSave->SetVoxelWorld(this);
		NewSave->SaveData();

		FAssetRegistryModule::AssetCreated(NewSave);

		NewSave->MarkPackageDirty();
		NewSave->PostEditChange();
		NewSave->AddToRoot();

		FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

		bool bSaveSuccess = UPackage::SavePackage(
			Package,
			NewSave,
			EObjectFlags::RF_Public | EObjectFlags::RF_Standalone,
			*PackageFileName,
			GError, nullptr, true, true, SAVE_NoError);

		if (bSaveSuccess)
		{
			IVoxelLogInterface::LogMessage(INVTEXT("Voxel World has been successfully saved"), "Log");
			return NewSave;
		}
		else
		{
			IVoxelLogInterface::LogMessage(INVTEXT("Voxel World has not been saved"), "Error");
		}
	}
	return nullptr;
}

void AVoxelWorld::DestroyVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_DestroyVoxelWorld);

	if (bWorldCreated)
	{
		int TimeBeforeDestroy = FDateTime::Now().GetTicks();
		int32 TotalChunks = 0;
		{
			SCOPE_CYCLE_COUNTER(STAT_DestroyThreads);

			delete OctreeManagerThread;
			OctreeManagerThread = nullptr;

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

			// TODO: to make memory deleting for leaves otherwise memory is wrong
			delete OctreeDensity;
			OctreeDensity = nullptr;

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
			bWorldCreated = false;
			bStatsShowed = false;
			bEnableUpdateOctree = false;
		}
		int32 TimeAfterDestroy = FDateTime::Now().GetTicks();
		UE_LOG(VoxelArt, Log, TEXT("Voxel World was destroyd in %f s. (chunks %d)"), (TimeAfterDestroy - TimeBeforeDestroy) / 1000.f / 10000.f, TotalChunks);
	}
}

void AVoxelWorld::OnPreBeginPIE(bool isSimulating) 
{
	if (bWorldCreated)
	{
		SaveWorldUtility();
		DestroyVoxelWorld();
	}
}

void AVoxelWorld::OnEndPIE(bool bIsSimulating)
{
	if (bCreatedInEditor)
	{
		CreateVoxelWorldInEditor();
	}
}

void AVoxelWorld::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void AVoxelWorld::UpdateOctree()
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

		check(GetVoxelScenePlayer() != nullptr);

		FIntVector PlayerPositionToWorld = TransferToVoxelWorld(GetVoxelScenePlayer()->GetActorLocation());

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
					if (!bStatsShowed)
					{
						UE_LOG(VoxelArt, Log, TEXT("Voxel World was generated in %f s. (%d chunks)"), 
							(FDateTime::Now().GetTicks() - TimeForWorldGenerate) / 1000.f / 10000.f, 
							PoolChunks->PoolChunks.Num()
						);
						bStatsShowed = true;
					}
					//while (ChunksRemoving.Num() > 0)
					{
						FVoxelChunkData* ChunkData = ChunksRemoving.Pop();

						if (IsValid(ChunkData->Chunk) && ChunkData->Chunk->IsPoolActive())
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
	{
		SCOPE_CYCLE_COUNTER(STAT_UpdateChunks);

		while (ChunksGeneration.Num() > 0)
		{
			FVoxelChunkData* ChunkData = ChunksGeneration.Pop();

			if (ChunkData != nullptr)
			{
				PutChunkOnGeneration(ChunkData);
			}
		}
	}
}

/*
* UpdateWorld doesn't support the Priorities
* because its not needed
*/
void AVoxelWorld::UpdateWorld()
{
	if (!bWorldCreated)
	{
		IVoxelLogInterface::LogMessage(INVTEXT("MWorld has not been created!"), "Error");
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

void AVoxelWorld::GetLeavesAndQueueToGeneration(TSharedPtr<FVoxelOctreeData> Octant)
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

void AVoxelWorld::GenerateLandscape()
{
	OctreeDensity = new FVoxelOctreeDensity(WorldGenerator, 0, WorldSize, VoxelsPerChunk, FIntVector(0, 0, 0));
	MainOctree = TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(nullptr, (1 << 3) | 0x00, 0, WorldSize, FIntVector(0, 0, 0)));

	GenerateOctree(MainOctree);
}

void AVoxelWorld::CreateTextureDensityMap()
{
	//TODO: Check texture import work :)

	if (WorldGenerator)
	{
		FString FileName = MapName;
		int width = MapSize;
		int height = MapSize;
		uint8* pixels = (uint8*)malloc(width * height * 4);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				uint8 PixelColorWB = (uint8)(FMath::Clamp(WorldGenerator->GetDensityMap(FIntVector(
					(x - width / 2)  * VoxelMin,
					(y - height / 2) * VoxelMin,
					0)
				), -1.f, 1.0f) * 63.f + 128);

				if (PixelColorWB == 191 && RenderType == RenderTexture::RedGreenBlue)
				{
					FColor PixelColorRGB = WorldGenerator->GetColorMap(FIntVector(
						(x - width / 2) * VoxelMin,
						(y - height / 2) * VoxelMin,
						0)
					);

					pixels[y * 4 * width + x * 4 + 0] = PixelColorRGB.R; // R
					pixels[y * 4 * width + x * 4 + 1] = PixelColorRGB.G; // G
					pixels[y * 4 * width + x * 4 + 2] = PixelColorRGB.B; // B
					pixels[y * 4 * width + x * 4 + 3] = PixelColorRGB.A; // A
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
		
		// Create Package
		FString pathPackage = FString("/Game/" + DirectoryName);
		FString absolutePathPackage = FPaths::ProjectContentDir() + "/" + DirectoryName + "/";

		FPackageName::RegisterMountPoint(*pathPackage, *absolutePathPackage);

		UPackage* Package = CreatePackage(*pathPackage);
		FName TextureName = MakeUniqueObjectName(Package, UTexture2D::StaticClass(), FName(*FileName));

		UTexture2D* Texture = UTexture2D::CreateTransient(width, height);//NewObject<UTexture2D>(Package, TextureName, RF_Public | RF_Standalone);

		// Texture Settings
	//	Texture->PlatformData = new FTexturePlatformData();
		//Texture->PlatformData->SizeX = width;
		//Texture->PlatformData->SizeY = height;
	//	Texture->PlatformData->PixelFormat = PF_R8G8B8A8;

		// Passing the pixels information to the texture
		FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
		Mip.SizeX = width;
		Mip.SizeY = height;

		Mip.BulkData.Lock(LOCK_READ_WRITE);
		uint8* TextureData = (uint8*)Mip.BulkData.Realloc(height * width * sizeof(uint8) * 4);
		FMemory::Memcpy(TextureData, pixels, sizeof(uint8) * height * width * 4);
		Mip.BulkData.Unlock();

		// Updating Texture & mark it as unsaved
		Texture->AddToRoot();
		Texture->UpdateResource();
		Package->MarkPackageDirty();

		IVoxelLogInterface::LogMessage(INVTEXT("Density Map Texture was created! Check your directory to find it"), "Log");

		free(pixels);
		pixels = NULL;

	}
	else
	{
		IVoxelLogInterface::LogMessage(INVTEXT("World Generator is not exist! (Voxel World -> Main -> World Generator)"), "Error");
	}
}

void AVoxelWorld::GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant)
{
	if (Octant->Depth == MinimumLOD)
	{
		Octant->Data = new FVoxelChunkData(Octant, Octant->Depth, Octant->Position, Octant->Size, VoxelsPerChunk, 0.f);
		/*
		* Put new chunk in queue and generate priority later
		* To make sure we get the chunks closest to the player at the beginning of the output
		*/
		ChunksCreation.Add(Octant->Data);
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

void AVoxelWorld::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (auto* Property = PropertyChangedEvent.MemberProperty)
	{
		const FName Name = Property->GetFName();

		if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, WorldSize))
		{
			WorldSize = FMath::RoundUpToPowerOfTwo(FMath::Max(WorldSize, 2));

			MaximumLOD = 0;

			int MaxLOD = WorldSize;
			while (MaxLOD != VoxelsPerChunk)
			{
				MaxLOD = MaxLOD >> 1;
				MaximumLOD++;
			}
			if (bWorldCreated)
			{
				CreateVoxelWorld();
			}
		}
		else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, VoxelsPerChunk))
		{
			VoxelsPerChunk = FMath::RoundUpToPowerOfTwo(FMath::Max(VoxelsPerChunk, 2));

			MaximumLOD = 0;

			int MaxLOD = WorldSize;
			while (MaxLOD != VoxelsPerChunk)
			{
				MaxLOD = MaxLOD >> 1;
				MaximumLOD++;
			}
			if (bWorldCreated)
			{
				CreateVoxelWorld();
			}
		}
		else if (Name == GET_MEMBER_NAME_STRING_CHECKED(AVoxelWorld, MinimumLOD))
		{
			if (MinimumLOD > MaximumLOD)
			{
				MinimumLOD = MaximumLOD;
			}
			if (bWorldCreated)
			{
				CreateVoxelWorld();
			}
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AVoxelWorld::SpawnChunk(FVoxelChunkData* ChunkData)
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

void AVoxelWorld::PutChunkOnGeneration(FVoxelChunkData* ChunkData)
{
	TaskWorkGlobalCounter.Increment();
	FAsyncTask<FMesherAsyncTask>* MesherTask = new FAsyncTask<FMesherAsyncTask>(this, ChunkData);
	MesherTask->StartBackgroundTask(/*ThreadPool*/);

	PoolThreads.Add(MesherTask);
}

void AVoxelWorld::ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData)
{
	if (Chunk)
	{
		ChunkData->Chunk = Chunk;

		Chunk->CurrentOctree = ChunkData->CurrentOctree;
		Chunk->Material = Material;
		Chunk->WorldGenerator = WorldGenerator;

		Chunk->SetMaterial(0, Material);
		Chunk->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //QueryAndPhysics
		Chunk->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic); //ECC_WorldDynamic
		Chunk->AttachToComponent(WorldComponent, FAttachmentTransformRules::KeepWorldTransform);
		Chunk->SetWorldLocation(TransferToGameWorld(ChunkData->Position));
		Chunk->SetPoolActive(true);
	}
}

void AVoxelWorld::GetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float& Value, FColor& Color)
{
	if (!OctreeDensity->IsInside(Position)) return;

	if (OutOctant == nullptr || OutOctant->HasChildren() || !OutOctant->IsInside(Position))
	{
		OutOctant = OctreeDensity->GetLeaf(Position);
	}
	OutOctant->GetVoxelDensity(this, Position, Value, Color);
}

void AVoxelWorld::SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor)
{
	if (!OctreeDensity->IsInside(Position)) return;

	if (OutOctant == nullptr || OutOctant->HasChildren() || !OutOctant->IsInside(Position))
	{
		OutOctant = OctreeDensity->GetLeaf(Position);
	}
	OutOctant->SetVoxelValue(this, Position, Density, Color, bSetDensity, bSetColor);
}

FIntVector AVoxelWorld::TransferToVoxelWorld(FVector P)
{
	return (FIntVector)GetTransform().InverseTransformPosition(P);
}

FVector AVoxelWorld::TransferToGameWorld(FIntVector P)
{
	return GetTransform().TransformPosition((FVector)P);
}

void AVoxelWorld::GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree)
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

FORCEINLINE int AVoxelWorld::GetIndex(FIntVector P)
{
	return P.X + P.Y * (VoxelsPerChunk + 1 + NORMALS) + P.Z * (VoxelsPerChunk + 1 + NORMALS) * (VoxelsPerChunk + 1 + NORMALS);
}

void AVoxelWorld::VoxelDebugBox(FVector Position, float Radius, float Width, FColor Color)
{
	DrawDebugBox(GetWorld(), Position, FVector(Radius, Radius, Radius), Color, false, 13.f, 5, Width);
}

#if WITH_EDITOR
bool AVoxelWorld::ShouldTickIfViewportsOnly() const
{
	return true;
}
#endif

IVoxelDelegatesInterface::FStartupDelegates IVoxelDelegatesInterface::BindStartupDelegates;