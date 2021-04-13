// Voxel Art Plugin � limit 2018

#include "VoxelWorld.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"
#include "Misc/MessageDialog.h"
#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"
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
		CreateVoxelWorld();
	}
}

void AVoxelWorld::Destroyed()
{
<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
=======
//	bSaveDensityInGame = false;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
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
<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

	if (!FEditorDelegates::PreBeginPIE.IsBoundToObject(this))
	{
		FEditorDelegates::PreBeginPIE.AddUObject(this, &AVoxelWorld::OnPreBeginPIE);
	}
	if (!FEditorDelegates::EndPIE.IsBoundToObject(this))
	{
		FEditorDelegates::EndPIE.AddUObject(this, &AVoxelWorld::OnEndPIE);
	}
	if (bWorldCreated)
	{
		DestroyVoxelWorld();
	}
	CreateVoxelWorld();
}

void AVoxelWorld::CreateVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

=======
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

	if (!FEditorDelegates::PreBeginPIE.IsBoundToObject(this))
	{
		FEditorDelegates::PreBeginPIE.AddUObject(this, &AVoxelWorld::OnPreBeginPIE);
	}
	if (!FEditorDelegates::EndPIE.IsBoundToObject(this))
	{
		FEditorDelegates::EndPIE.AddUObject(this, &AVoxelWorld::OnEndPIE);
	}
	if (bWorldCreated)
	{
		DestroyVoxelWorld();
	}
	CreateVoxelWorld();
}

void AVoxelWorld::CreateVoxelWorld()
{
	SCOPE_CYCLE_COUNTER(STAT_CreateVoxelWorld);

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
	if (WorldGenerator)
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
					UE_LOG(VoxelArt, Error, TEXT("Ooops SaveFile %p"), SaveFile);
				}
			}
			if (EnabledLOD)
			{
				OctreeManagerThread = new VoxelOctreeManager(this, UGameplayStatics::GetPlayerController(GetWorld(), 0), DrawingRange, MaximumLOD);

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
	}
	else
	{
		UE_LOG(VoxelArt, Error, TEXT("World Generator is not exist! (Select: Voxel World -> Main -> World Generator)"));
	}
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
<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
=======
	}
}

UVoxelSaveData* AVoxelWorld::SaveWorldToFile()
{
	if (bWorldCreated)
	{
		FString ObjectName = TEXT("WorldSave");

		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		FString PackageName = FString(TEXT("/Game/VoxelSaves/"));
		AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

		UPackage* Package = CreatePackage(nullptr, *PackageName);
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

		UE_LOG(LogTemp, Warning, TEXT("Saved Package: %s"), bSaveSuccess ? TEXT("True") : TEXT("False"));

		if (bSaveSuccess)
		{
			return NewSave;
		}
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
	}
	return nullptr;
}

<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
UVoxelSaveData* AVoxelWorld::SaveWorldToFile()
{
	if (bWorldCreated)
	{
		FString ObjectName = TEXT("WorldSave");

		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		FString PackageName = FString(TEXT("/Game/VoxelSaves/"));
		AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

		UPackage* Package = CreatePackage(nullptr, *PackageName);
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

		UE_LOG(LogTemp, Warning, TEXT("Saved Package: %s"), bSaveSuccess ? TEXT("True") : TEXT("False"));

		if (bSaveSuccess)
		{
			return NewSave;
		}
	}
	return nullptr;
}

=======
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
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
<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
=======

#if WITH_EDITOR
	if (GetWorld()->WorldType == EWorldType::EditorPreview || GetWorld()->WorldType == EWorldType::GamePreview || GetWorld()->WorldType == EWorldType::Editor)
	{
	}
#endif
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
}

FEditorViewportClient* AVoxelWorld::GetEditorViewportClient()
{
	FEditorViewportClient* EditorViewportClient = nullptr;

	if (GEditor)
	{
		if (FViewport* Viewport = GEditor->GetActiveViewport())
		{
			if (FViewportClient* CurrentClient = Viewport->GetClient())
			{
				for (FEditorViewportClient* Client : GEditor->AllViewportClients)
				{
					if (Client == CurrentClient)
					{
						EditorViewportClient = Client;
						break;
					}
				}
			}
		}
	}
	return EditorViewportClient;
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
	bool bUpdateNextTick = false;
	{
		SCOPE_CYCLE_COUNTER(STAT_UpdatePriority);

		FEditorViewportClient* EditorViewportClient = GetEditorViewportClient();
		FIntVector PlayerPositionToWorld;

		if (GetWorld() && (GetWorld()->WorldType == EWorldType::Editor || GetWorld()->WorldType == EWorldType::EditorPreview))
		{
			if (EditorViewportClient == nullptr)
			{
				/*
				* Our editor in this tick turned out to be empty
				* So we update the priority and create new chunks in the new tick
				*/
				bUpdateNextTick = true;
			}
		}
		if (!bUpdateNextTick)
		{
#if WITH_EDITOR
			if (GetWorld() && (GetWorld()->WorldType == EWorldType::Editor || GetWorld()->WorldType == EWorldType::EditorPreview))
			{
				PlayerPositionToWorld = TransferToVoxelWorld(EditorViewportClient->GetViewLocation());
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
	}
	{
		SCOPE_CYCLE_COUNTER(STAT_CreateChunks);

		int32 Index = 0;
		while (Index < ChunksPerFrame)
		{
			if (!bUpdateNextTick && ChunksCreation.Num() > 0)
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
	//if(false)
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
<<<<<<< HEAD:Source/VoxelArt/Private/VoxelWorld.cpp
=======

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Private/VoxelLandscape.cpp
void AVoxelWorld::UpdateWorld()
{
	if (!bWorldCreated)
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
	OctreeDensity = new FVoxelOctreeDensity(WorldGenerator, 0, WorldSize, VoxelsPerChunk, TransferToVoxelWorld(FVector(0, 0, 0)));
	MainOctree = TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(nullptr, (1 << 3) | 0x00, 0, WorldSize, TransferToVoxelWorld(FVector(0, 0, 0))));

	GenerateOctree(MainOctree);
}

void AVoxelWorld::CreateTextureDensityMap()
{
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
		UE_LOG(VoxelArt, Error, TEXT("World Generator is not exist! (Voxel World -> Main -> World Generator)"));
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