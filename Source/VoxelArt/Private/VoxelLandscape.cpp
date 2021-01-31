// limit (c) copyright

#include "VoxelLandscape.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"

AVoxelLandscape::AVoxelLandscape()
{
	PrimaryActorTick.bCanEverTick = true; 
	PrimaryActorTick.bHighPriority = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	/* Object pooler component */
	PoolChunks = CreateDefaultSubobject<UVoxelPoolComponent>(TEXT("PoolChunks"));
}

#if WITH_EDITOR
bool AVoxelLandscape::ShouldTickIfViewportsOnly() const
{
	return true;
}
#endif

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
#include "EditorViewportClient.h"

void AVoxelLandscape::CreateVoxelWorld()
{
	if (generatorLandscape)
	{
		if (minimumLOD < 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Error: Minimum LOD can't be under zero!"));
		}
		else if (minimumLOD > maximumLOD)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Error: Minimum LOD can't be upper Maximum LOD!"));
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
				UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Log: Voxel World has already been created!"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Error: Generator of lansdcape is not exist!"));
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

		TSubclassOf<AVoxelChunk> ChunkClass = AVoxelChunk::StaticClass();
		TArray<AActor*> ChunksOctreeToRemove;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ChunkClass, ChunksOctreeToRemove);

		for (auto& Chunk : ChunksOctreeToRemove)
		{
			Chunk->Destroy();
		}
		GEngine->ForceGarbageCollection(true);
		TerrainCreated = false;
	}
}

void AVoxelLandscape::SpawnBoxTest(FVector location, float radius, float width, FColor color)
{
//	DrawDebugSphere(GetWorld(), location, radius, 26, FColor(181, 0, 0), false, 13.f, 13.f, width);

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
		FScopeLock Lock(&GlobalMutex);

		while (ChunksToRecomputeOctree.Num() > 0)
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
		}

		int32 Index = 0;
		while (Index < ChunksPerFrame && ChunksCreation.Num() > 0)
		{
			TSharedPtr<FVoxelChunkRenderData> chunk = ChunksCreation.Pop();

			//If our leaf is exist yet inside Octree, we create chunk for it
			if (chunk->CurrentOctree.IsValid())
			{
				if (!chunk->CurrentOctree.Pin()->HasChildren())
				{
				//	if (IsValid(chunk->CurrentOctree.Pin()->chunk))
					{
				//		if (chunk->CurrentOctree.Pin()->chunk->Active == true)
						{
							ChunksRemoving.Add(chunk->CurrentOctree.Pin()->chunk);
						}
					}
				//	SpawnChunk(chunk->CurrentOctree.Pin());
					Index++;
				}
			}
		}
	}
	/*{
		FScopeLock Lock(&GlobalMutex);

		while (ChunksGeneration.Num() > 0)
		{
			AVoxelChunk* chunk = ChunksGeneration.Pop();
			{
				if (IsValid(chunk))
				{
					PutChunkOnGeneration(chunk);
				}
			}
		}
	}*/
	{
		FScopeLock Lock(&GlobalMutex);

		if (ChunksRemoving.Num() > 0 && ChunksCreation.Num() == 0) // && ChunksGeneration.Num() == 0
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
							//	FScopeLock Lock(&GlobalMutex);
								//chunk->Destroy();
							chunk->SetActive(false);
						}
					}
				}
			}
		}
	}
}

void AVoxelLandscape::SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks)
{
	for (auto& Chunk : Chunks)
	{
		if (Chunk->chunk != nullptr)
		{
			if (Chunk->chunk->hasOwnGrid)
			{
				Chunk->Grid = Chunk->chunk->Grid;
				SavedChunks.Add(Chunk->nodeID, Chunk);
			}
		}
	}
}

void AVoxelLandscape::GenerateLandscape()
{
	chunksBuffer = TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData());
	chunksBuffer->nodeID = (1 << 3) | 0x00;

	chunksBuffer->x = 0;
	chunksBuffer->y = 0;
	chunksBuffer->z = 0;

	chunksBuffer->level = 0;
	chunksBuffer->radius = radiusOfChunk + 0.f;

	GenerateOctree(chunksBuffer, 0);

	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Landscape was generated"));
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
					//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Density color %d"), (uint8)(FMath::Clamp((GeneratorDensity->GetDensityMap(FVector(static_cast<float>((x - width * 0.5f) * StepTexture), static_cast<float>((y - height * 0.5f) * StepTexture), 0)) / 1), -1.f, 1.0f) * 63.f + 128));
					uint8 PixelColorWB = (uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
						static_cast<float>((x - width * 0.5f) * StepTexture),
						static_cast<float>((y - height * 0.5f) * StepTexture),
						0)
					), -1.f, 1.0f) * 63.f + 128);

					if (PixelColorWB == 191)
					{
						//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] It's 121"));

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
						//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] It's not 121 but it's %d"), PixelColorWB);

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
					//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Density color %d"), (uint8)(FMath::Clamp((GeneratorDensity->GetDensityMap(FVector(static_cast<float>((x - width * 0.5f) * StepTexture), static_cast<float>((y - height * 0.5f) * StepTexture), 0)) / 1), -1.f, 1.0f) * 63.f + 128));
					uint8 PixelColorWB = (uint8)(FMath::Clamp(GeneratorDensity->GetDensityMap(FVector(
						static_cast<float>((x - width * 0.5f) * StepTexture),
						static_cast<float>((y - height * 0.5f) * StepTexture),
						0)
					), -1.f, 1.0f) * 63.f + 128);

					//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] It's not 121 but it's %d"), PixelColorWB);

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

		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Density Map Texture was created!"));
		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Check your directory to find it"));

		free(pixels);
		pixels = NULL;

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Error: You should choose generator of the density!"));
	}
}

//void AVoxelLandscape::ImportTextureToDensity()
//{

/*	FTexture2DMipMap* MyMipMap = &MyTexture->PlatformData->Mips[0];
//	FByteBulkData* RawImageData = &MyMipMap->BulkData;

	// Texture Information
	FString FileName = FString("MyTexture");
	int width = (int)MyMipMap->SizeX;
	int height = (int)MyMipMap->SizeY;
	uint8* pixels = (uint8*)malloc(width * height * 4);
/*
	MyTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	MyTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	MyTexture->SRGB = false;
	MyTexture->UpdateResource();

	TextureCompressionSettings OldCompressionSettings = MyTexture->CompressionSettings; TextureMipGenSettings OldMipGenSettings = MyTexture->MipGenSettings; bool OldSRGB = MyTexture->SRGB;

	const FColor* FormatedImageData = static_cast<const FColor*>(MyTexture->PlatformData->Mips[0].BulkData.LockReadOnly());*/
	
	// filling the pixels with dummy data (4 boxes: red, green, blue and white)
	/*for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Landscape was generated %f and smoothed %f"), GetValueNoise(FVector(static_cast<float>((x - width / 2) * StepTexture), static_cast<float>((y - height / 2) * StepTexture), 0)), FMath::Clamp((GetValueNoise(FVector(static_cast<float>((x - width / 2.f) * StepTexture), static_cast<float>((y - height / 2.f) * StepTexture), 0)) / (131000.f)), -1.f, 1.0f));

			pixels[y * 4 * width + x * 4 + 0] = (uint8)(FMath::Clamp((GetValueNoise(FVector(static_cast<float>((x - width / 2.f) * StepTexture), static_cast<float>((y - height / 2.f) * StepTexture), 0)) / (height * StepTexture)), -1.f, 1.0f) * 63.f + 128);//(FormatedImageData[y * width + x].R + FormatedImageData[y * width + x].G + FormatedImageData[y * width + x].G) / 3;   // R
			pixels[y * 4 * width + x * 4 + 1] = (uint8)(FMath::Clamp((GetValueNoise(FVector(static_cast<float>((x - width / 2.f) * StepTexture), static_cast<float>((y - height / 2.f) * StepTexture), 0)) / (height * StepTexture)), -1.f, 1.0f) * 63.f + 128);//(FormatedImageData[y * width + x].R + FormatedImageData[y * width + x].G + FormatedImageData[y * width + x].G) / 3;   // G
			pixels[y * 4 * width + x * 4 + 2] = (uint8)(FMath::Clamp((GetValueNoise(FVector(static_cast<float>((x - width / 2.f) * StepTexture), static_cast<float>((y - height / 2.f) * StepTexture), 0)) / (height * StepTexture)), -1.f, 1.0f) * 63.f + 128);//(FormatedImageData[y * width + x].R + FormatedImageData[y * width + x].G + FormatedImageData[y * width + x].G) / 3;   // B
			pixels[y * 4 * width + x * 4 + 3] = 255;
		}
	}*/

	/*MyTexture->PlatformData->Mips[0].BulkData.Unlock();

	MyTexture->CompressionSettings = OldCompressionSettings;
	MyTexture->MipGenSettings = OldMipGenSettings;
	MyTexture->SRGB = OldSRGB;
	MyTexture->UpdateResource();*/

	
	// Create Package
	/*FString pathPackage = FString("/Game/MyTextures/");
	FString absolutePathPackage = FPaths::GameContentDir() + "/MyTextures/";

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

	UE_LOG(LogTemp, Log, TEXT("Texture created: %s"), &FileName);

	free(pixels);
	pixels = NULL;*/
//}

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
			LeafChildren->x = X;
			LeafChildren->y = Y;
			LeafChildren->z = Z;
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
	//If we have free chunks in our pool we'll use it
	//Else create new actor

	AVoxelChunk* chunkPool = PoolChunks->GetChunkFromPool();

	if (IsValid(chunkPool))
	{
		ChunkInit(chunkPool, chunkData);
		chunkPool->SetActorLocation(chunkData->position);
		chunkPool->SetActive(true);
	}
	else
	{
		chunkPool = PoolChunks->AddChunkToPool();

		ChunkInit(chunkPool, chunkData);

		chunkPool->SetActorLocation(chunkData->position);
		chunkPool->SetActive(true);
	}
	PutChunkOnGeneration(chunkPool);
}

void AVoxelLandscape::PutChunkOnGeneration(AVoxelChunk* Chunk)
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
			Chunk->GetActorLocation(),
			Chunk->transvoxelDirection
		);
		PoolThreads.Add(FreeTask);
	}
	FreeTask->StartBackgroundTask();

	TotalTasksCounter++;
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(0, 1.5f, FColor::Cyan, FString::Printf(TEXT("Total mesh tasks: %d"), TotalTasksCounter), false);
}

void AVoxelLandscape::ChunkInit(AVoxelChunk* chunk, TSharedPtr<FVoxelOctreeData> chunkData)
{
	//FVector actorLocation = GetActorLocation();
	FVector location = chunkData->position;

	if (chunk)
	{
		chunk->nodeID = chunkData->nodeID;
		chunk->transvoxelDirection = chunkData->transvoxelDirection;
		chunk->level = chunkData->level;
		chunk->radius = chunkData->radius;
		chunk->voxels = voxelsOneChunk;
		chunk->material = material;
		chunk->mesh->SetMaterial(0, material);
		chunk->Grid = chunkData->Grid;
		chunk->meshTree = meshTree;
		chunk->generatorLandscape = generatorLandscape;

		chunk->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepWorldTransform);
		//chunk->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		//chunk->SetActorLabel(FString::Printf(TEXT("%d, (%d, %d, %d)"), (int)chunkData->nodeID, chunkData->x, chunkData->y, chunkData->z));
		chunk->SetActorLabel(FString::Printf(TEXT("%d, (%p)"), (int)chunkData->nodeID, chunk));
		chunk->SetActorLocation(location);

		//chunk->isPool = false;
		chunk->CurrentOctree = chunkData;
		chunkData->chunk = chunk;
	}
}