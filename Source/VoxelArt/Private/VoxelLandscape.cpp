// limit (c) copyright

#include "VoxelLandscape.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"

AVoxelLandscape::AVoxelLandscape()
{
	PrimaryActorTick.bCanEverTick = true; 
//	PrimaryActorTick.bHighPriority = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	/* Object pooler component */
	PoolChunks = CreateDefaultSubobject<UVoxelPoolComponent>(TEXT("PoolChunks"));
}

void AVoxelLandscape::OnConstruction(const FTransform& Transform)
{
/*	TSubclassOf<UVoxelPoolComponent> TMyObj1;
	FString name = "PoolableChunk";
	UVoxelPoolComponent* PoolableChunk = NewObject<UVoxelPoolComponent>(this, *name, RF_Transient, TMyObj1.GetDefaultObject());
	PoolableChunk->RegisterComponent();
	//PoolableChunk->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] UVoxelPoolComponent Updated %p mesh s"), PoolableChunk);


	TSubclassOf<UVoxelPoolComponent> TMyObj2;
	FString name2 = "PoolableChunk";
	UVoxelPoolComponent* PoolableChunk2 = NewObject<UVoxelPoolComponent>(this, *name2, RF_Transient, TMyObj2.GetDefaultObject());
	PoolableChunk2->RegisterComponent();*/
//	PoolableChunk2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] UVoxelPoolComponent Updated %p mesh s"), PoolableChunk2);
}

void AVoxelLandscape::BeginPlay()
{
	Super::BeginPlay();

	if (TerrainRendering)
	{
		CreateVoxelWorld();
	}
}
void AVoxelLandscape::PostLoad()
{
	Super::PostLoad();
}

void AVoxelLandscape::Destroyed()
{
	for (auto& Chunk : ChunkComponents)
	{
		Chunk->DestroyComponent();
	}
}

void AVoxelLandscape::CreateVoxelWorld()
{
	if (generatorLandscape)
	{
		if (minimumLOD < 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Error: Minimum LOD can't be under zero!"));
		}
		else if (minimumLOD > maximumLOD)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Error: Minimum LOD can't be upper Maximum LOD!"));
		}
		else
		{
			if (!TerrainCreated)
			{
				GenerateLandscape();

				if (LODWorking)
				{
					ManagerCheckPositionThreadHandle = new VoxelManager(this, UGameplayStatics::GetPlayerController(GetWorld(), 0), distanceRadius, maximumLOD);

					if (TransitionWorking)
					{
						OctreeNeighborsChecker = new VoxelOctreeNeighborsChecker(this);
					}
				}
				TerrainCreated = true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Log: Voxel World has already been created!"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Error: Generator of lansdcape is not exist!"));
	}
}

void AVoxelLandscape::DestroyVoxelWorld()
{
	if (TerrainCreated)
	{
		if (ManagerCheckPositionThreadHandle)
		{
			ManagerCheckPositionThreadHandle->EnsureCompletion();
			delete ManagerCheckPositionThreadHandle;
			ManagerCheckPositionThreadHandle = nullptr;
		}
		if (OctreeNeighborsChecker)
		{
			OctreeNeighborsChecker->EnsureCompletion();
			delete OctreeNeighborsChecker;
			OctreeNeighborsChecker = nullptr;
		}

		chunksBuffer.Reset();

		ChunksToRecomputeOctree.Empty();
		ChunksCreation.Empty();
		ChunksRemoving.Empty();
		ChunksGeneration.Empty();

		for (auto& it : PoolThreads)
		{
			it->Cancel();
		}

		/*TSubclassOf<AVoxelChunk> ChunkClass = AVoxelChunk::StaticClass();
		TArray<AActor*> ChunksOctreeToRemove;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ChunkClass, ChunksOctreeToRemove);

		for (auto& Chunk : ChunksOctreeToRemove)
		{
			Chunk->Destroy();
		}*/
		GEngine->ForceGarbageCollection(true);
		TerrainCreated = false;
	}
}

void AVoxelLandscape::SpawnBoxTest(FVector location, float radius, float width, FColor color)
{
	DrawDebugBox(GetWorld(), location, FVector(radius, radius, radius), color, false, 13.f, 5, width);
}

void AVoxelLandscape::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (ManagerCheckPositionThreadHandle)
	{
		ManagerCheckPositionThreadHandle->EnsureCompletion();
		delete ManagerCheckPositionThreadHandle;
		ManagerCheckPositionThreadHandle = nullptr;
	}
	if (OctreeNeighborsChecker)
	{
		OctreeNeighborsChecker->EnsureCompletion();
		delete OctreeNeighborsChecker;
		OctreeNeighborsChecker = nullptr;
	}
	for (auto& it : PoolThreads)
	{
		it->Cancel();
	}
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
	{
		/*while (ChunksToRecomputeOctree.Num() > 0)
		{
			FChunksRenderInfo* renderInfo = ChunksToRecomputeOctree.Pop();

			for (auto& Leaf : renderInfo->LeavesDestroying)
			{
				//Save chunks if they have changes
				SaveChunksBuffer(Leaf->ChildrenChunks);

				Leaf->DestroyChildren();
				Leaf->cUpdating = false;
			}
			for (auto& Leaf : renderInfo->LeavesCreation)
			{
				Leaf->ParentChunk.Pin()->ChildrenChunks.Add(Leaf);
				Leaf->ParentChunk.Pin()->cUpdating = false;
			}
			for (auto& Chunk : renderInfo->ChunksCreation)
			{
				ChunksCreation.Add(Chunk);
			}
			for (auto& Chunk : renderInfo->ChunksRemoving)
			{
				ChunksRemoving.Add(Chunk);
			}
			renderInfo->LeavesCreation.Empty();
			renderInfo->LeavesDestroying.Empty();
			renderInfo->ChunksCreation.Empty();
			renderInfo->ChunksRemoving.Empty();
		}*/

		TSharedPtr<FVoxelChunkRenderData> ChunksCreationNewGroup;

		while (ChunksCreationGroup.Peek(ChunksCreationNewGroup))
		{
			ChunksCreationGroup.Dequeue(ChunksCreationNewGroup);

			ChunksCreation.Add(ChunksCreationNewGroup);
		}

		UVoxelChunkComponent* ChunksRemovingNewGroup;

		while (ChunksRemovingGroup.Peek(ChunksRemovingNewGroup))
		{
			ChunksRemovingGroup.Dequeue(ChunksRemovingNewGroup);

			ChunksRemoving.Add(ChunksRemovingNewGroup);
		}
		
		{
		//	int timeBefore = FDateTime::Now().GetTicks();

			FVector PlayerPositionToWorld = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation() - GetActorLocation();

			for (auto& chunk : ChunksCreation)
			{
				float distancePlayer = sqrt(
					pow(PlayerPositionToWorld.X - chunk->position.X, 2) +
					pow(PlayerPositionToWorld.Y - chunk->position.Y, 2) +
					pow(PlayerPositionToWorld.Z - chunk->position.Z, 2)
				);
				chunk->priority = distancePlayer;
			}
			ChunksCreation.Sort([](const TSharedPtr<FVoxelChunkRenderData> A, const TSharedPtr<FVoxelChunkRenderData> B)
				{
					return A->priority > B->priority;
				});

		//	int timeAfter = FDateTime::Now().GetTicks();
		//	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Time to sort: %d"), timeAfter - timeBefore);

		}
		//FScopeLock Lock(&OctreeMutex);

		int32 Index = 0;
		while (Index < ChunksPerFrame && ChunksCreation.Num() > 0)
		{
			OctreeMutex.Lock();
			TSharedPtr<FVoxelOctreeData> chunk = ChunksCreation.Pop()->CurrentOctree.Pin();
			OctreeMutex.Unlock();

			//If our leaf is exist yet inside Octree, we create chunk for it
			if (chunk.IsValid())
			{
				if (!chunk->HasChildren())
				{
					if (IsValid(chunk->chunk))
					{
						if (chunk->chunk->Active == true)
						{
							ChunksRemoving.Add(chunk->chunk);
						}
					}

					SpawnChunk(chunk);
					Index++;
				}
			}
		}

		if (ChunksRemoving.Num() > 0 && ChunksCreation.Num() == 0)
		{
			auto AreAllTasksDone = [&]()
			{
				bool AreDone = true;

				for (auto& it : PoolThreads)
				{
					if (!it->IsDone())
					{
						AreDone = false;
					}
				}
				return AreDone;
			};

			if (AreAllTasksDone())
			{
				while (ChunksRemoving.Num() > 0)
				{
					UVoxelChunkComponent* chunk = ChunksRemoving.Pop();

					if (IsValid(chunk))
					{
						if (chunk->Active == true)
						{
							chunk->SetActive(false);
						}
					}
				}
			}
		}
	}
	/*{
		int32 Index = 0;
		while (Index < ChunksPerFrame && ChunksGeneration.Num() > 0)
		{
			AVoxelChunk* chunk = ChunksGeneration.Pop();
			{
				if (IsValid(chunk))
				{
					PutChunkOnGeneration(chunk);
					Index++;
				}
			}
		}
	}*/
	/*{
		if (ChunksRemoving.Num() > 0 && ChunksCreation.Num() == 0)
		{
			auto AreAllTasksDone = [&]()
			{
				bool AreDone = true;

				for (auto& it : PoolThreads)
				{
					if (!it->IsDone())
					{
						AreDone = false;
					}
				}
				return AreDone;
			};

			if (AreAllTasksDone())
			{
				while (ChunksRemoving.Num() > 0)
				{
					AVoxelChunk* chunk = ChunksRemoving.Pop();

					if (IsValid(chunk))
					{
						if (chunk->Active == true)
						{
							chunk->SetActive(false);
						}
					}
				}
			}
		}
	}*/
}

void AVoxelLandscape::SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks)
{
	for (auto& Chunk : Chunks)
	{
		if (Chunk->chunk != nullptr)
		{
			if (Chunk->chunk->hasOwnGrid)
			{
				Chunk->Grid = Chunk->chunk->DensityMap;
				SavedChunks.Add(Chunk->nodeID, Chunk);
			}
		}
	}
}

void AVoxelLandscape::GenerateLandscape()
{
	chunksBuffer = TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData());
	chunksBuffer->nodeID = (1 << 3) | 0x00;
	chunksBuffer->level = 0;
	chunksBuffer->radius = radiusOfChunk + 0.f;

	GenerateOctree(chunksBuffer, 0);

	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Landscape was generated"));
}

void AVoxelLandscape::CreateTextureDensityMap()
{
	if (GeneratorDensity)
	{
		FString FileName = MapName;
		int width = MapSize;
		int height = MapSize;
		uint8* pixels = (uint8*)malloc(width * height * 4);

		float StepTexture = radiusOfChunk / MapSize;

		if (RenderType == RenderTexture::RedGreenBlack)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					//	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Density color %d"), (uint8)(FMath::Clamp((GeneratorDensity->GetDensityMap(FVector(static_cast<float>((x - width * 0.5f) * StepTexture), static_cast<float>((y - height * 0.5f) * StepTexture), 0)) / 1), -1.f, 1.0f) * 63.f + 128));
					uint8 PixelColorWB = (uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
						static_cast<float>((x - width * 0.5f) * StepTexture),
						static_cast<float>((y - height * 0.5f) * StepTexture),
						0)
					), -1.f, 1.0f) * 63.f + 128);

					if (PixelColorWB == 191)
					{
						//UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] It's 121"));

						FColor PixelColorRGB = GeneratorDensity->GetColorMap(FVector(
							static_cast<float>((x - width * 0.5f) * StepTexture),
							static_cast<float>((y - height * 0.5f) * StepTexture),
							0
						));

						pixels[y * 4 * width + x * 4 + 0] = PixelColorRGB.R; // R
						pixels[y * 4 * width + x * 4 + 1] = PixelColorRGB.G; // G
						pixels[y * 4 * width + x * 4 + 2] = PixelColorRGB.B; // B
						pixels[y * 4 * width + x * 4 + 3] = PixelColorRGB.A; // A
					}
					else
					{
						//	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] It's not 121 but it's %d"), PixelColorWB);

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
					//	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Density color %d"), (uint8)(FMath::Clamp((GeneratorDensity->GetDensityMap(FVector(static_cast<float>((x - width * 0.5f) * StepTexture), static_cast<float>((y - height * 0.5f) * StepTexture), 0)) / 1), -1.f, 1.0f) * 63.f + 128));
					uint8 PixelColorWB = (uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
						static_cast<float>((x - width * 0.5f) * StepTexture),
						static_cast<float>((y - height * 0.5f) * StepTexture),
						0)
					), -1.f, 1.0f) * 63.f + 128);

					//	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] It's not 121 but it's %d"), PixelColorWB);

					pixels[y * 4 * width + x * 4 + 0] = PixelColorWB; // R
					pixels[y * 4 * width + x * 4 + 1] = PixelColorWB; // G
					pixels[y * 4 * width + x * 4 + 2] = PixelColorWB; // B
					pixels[y * 4 * width + x * 4 + 3] = 255;
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

		UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Density Map Texture was created!"));
		UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Check your directory to find it"));

		free(pixels);
		pixels = NULL;

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin ] Error: You should choose generator of the density!"));
	}
}

void AVoxelLandscape::GenerateOctree(TSharedPtr<FVoxelOctreeData> leaf, uint32 level)
{
	if (level == minimumLOD)
	{
		SpawnChunk(leaf);
		//PoolableActor->CollisionMesh->SetBoxExtent(FVector(leaf->radius, leaf->radius, leaf->radius));
	}
	else
	{
		for (int Index = 0; Index < 8; Index++)
		{
			int X = Index % 2;
			int Y = Index % 4 / 2;
			int Z = Index / 4;

			float radiusChild = (float)(leaf->radius / 2.f);
			FVector positionChunk = FVector(
				X * radiusChild + leaf->position.X - radiusChild / 2.f,
				Y * radiusChild + leaf->position.Y - radiusChild / 2.f,
				Z * radiusChild + leaf->position.Z - radiusChild / 2.f
			);

			TSharedPtr<FVoxelOctreeData> LeafChildren(new FVoxelOctreeData());

			LeafChildren->nodeID = (leaf->nodeID << 3) | Index;
			LeafChildren->ParentChunk = leaf;
			LeafChildren->priority = 0;
			LeafChildren->position = positionChunk;
			LeafChildren->transvoxelDirection = 0x00;
			LeafChildren->level = level;
			LeafChildren->radius = radiusChild;

			GenerateOctree(LeafChildren, level + 1);
			leaf->ChildrenChunks.Add(LeafChildren);
		}
	}
}

void AVoxelLandscape::SpawnChunk(TSharedPtr<FVoxelOctreeData> chunkData)
{
	UVoxelChunkComponent* PoolChunk = nullptr;

	if (IsValid(PoolChunk))
	{
		ChunkInit(PoolChunk, chunkData);
		PoolChunk->SetWorldLocation(chunkData->position);
		PoolChunk->SetActive(true);
	}
	else
	{
		PoolChunk = PoolChunks->AddChunkToPool();

		ChunkInit(PoolChunk, chunkData);

		PoolChunk->SetWorldLocation(chunkData->position);
		PoolChunk->SetActive(true);
	}
	PutChunkOnGeneration(PoolChunk);
}

void AVoxelLandscape::PutChunkOnGeneration(UVoxelChunkComponent* Chunk)
{
	FAsyncTask<TerrainGenerationAsyncTask>* FreeTask = nullptr;

/*	for (auto& it : PoolThreads)
	{
		if (it->IsDone())
		{
			FreeTask = it;
			break;
		}
	}*/
	if (FreeTask == nullptr)
	{
		FreeTask = new FAsyncTask<TerrainGenerationAsyncTask>(
			this,
			Chunk,
			false,
			Chunk->voxels,
			Chunk->level,
			Chunk->radius,
			Chunk->GetComponentLocation(),
			Chunk->transvoxelDirection
		);
		PoolThreads.Add(FreeTask);
	}
	FreeTask->StartBackgroundTask();

	TotalTasksCounter++;
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(0, 1.5f, FColor::Cyan, FString::Printf(TEXT("Total mesh tasks: %d"), TotalTasksCounter), false);
}

void AVoxelLandscape::ChunkInit(UVoxelChunkComponent* chunk, TSharedPtr<FVoxelOctreeData> chunkData)
{
	//FVector actorLocation = GetActorLocation();
	FVector location = chunkData->position;

	if (chunk)
	{
		chunk->CurrentOctree = chunkData;
		chunk->nodeID = chunkData->nodeID;
		chunk->transvoxelDirection = chunkData->transvoxelDirection;
		chunk->level = chunkData->level;
		chunk->radius = chunkData->radius;
		chunk->voxels = voxelsOneChunk;
		chunk->material = material;
		chunk->SetMaterial(0, material);
		chunk->DensityMap = chunkData->Grid;
		chunk->generatorLandscape = generatorLandscape;
		chunkData->chunk = chunk;

	//	int timeBefore = FDateTime::Now().GetTicks();

		chunk->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		chunk->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
		chunk->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepWorldTransform);

	//	chunk->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepWorldTransform);
		//chunk->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		//chunk->SetActorLabel(FString::Printf(TEXT("%d, (%d, %d, %d)"), (int)chunkData->nodeID, chunkData->x, chunkData->y, chunkData->z));
	//	chunk->SetActorLabel(FString::Printf(TEXT("%d, (%p)"), (int)chunkData->nodeID, chunk));
		//chunk->SetActorLocation(location);

	}
}

#if WITH_EDITOR
bool AVoxelLandscape::ShouldTickIfViewportsOnly() const
{
	return true;
}
#endif