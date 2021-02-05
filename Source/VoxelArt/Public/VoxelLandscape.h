// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelChunk.h"
#include "VoxelChunkComponent.h"
#include "Renders/VoxelRender.h"
#include "Renders/VoxelLandscapeGenerator.h"
#include "Octree/VoxelManager.h"
#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Octree/VoxelOctreeData.h"
#include "Meshers/VoxelMarchingCubesMesher.h"
#include "VoxelPoolComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "VoxelLandscape.generated.h"


namespace EVoxelDirection
{
	enum Direction : uint8
	{
		MinimumX = 0x01,
		MaximumX = 0x02,
		MinimumY = 0x04,
		MaximumY = 0x08,
		MinimumZ = 0x10,
		MaximumZ = 0x20
	};
}

UENUM()
enum RenderTexture
{
	WhiteBlack		UMETA(DisplayName = "WB"),
	RedGreenBlack	UMETA(DisplayName = "RGB")
};

UCLASS()
class VOXELART_API AVoxelLandscape : public AActor
{
	GENERATED_BODY()
	
public:	

	AVoxelLandscape();

protected:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;

public:

#if WITH_EDITOR
	virtual bool ShouldTickIfViewportsOnly() const override;
#endif

public:
	VoxelRender* RendererCheckPositionThreadHandle;
	VoxelManager* ManagerCheckPositionThreadHandle;

	VoxelOctreeNeighborsChecker* OctreeNeighborsChecker;

public:

	TSharedPtr<FVoxelOctreeData> MainOctree;
	TMap<uint64, TSharedPtr<FVoxelOctreeData>> SavedChunks;

private:

	UVoxelPoolComponent* PoolChunks;
	TArray<UVoxelChunkComponent*> ChunkComponents;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	bool TerrainRendering = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main")
	bool TerrainCreated = false;

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Main")
	UVoxelLandscapeGenerator *generatorLandscape;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Main")
	void CreateVoxelWorld();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Main")
	void DestroyVoxelWorld();


public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool TransitionWorking = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transition Mesh")
	float transitionSize = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NeighborTest")
	int nodeID = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NeighborTest")
	uint8 moveBit = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NeighborTest")
	bool work = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	float radiusOfChunk = 500000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	int voxelsOneChunk = 9;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool LODWorking = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	int32 minimumLOD = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	int32 maximumLOD = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	float distanceRadius = 2000000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	int32 ChunksPerFrame = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	bool vertexSubdivision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	bool normalsSmoothing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
	FLinearColor ground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
	FLinearColor grass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float actave = 0.003f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float period = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float radiusSphere = 5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	UStaticMesh* meshTree;

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	UVoxelLandscapeGenerator *GeneratorDensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	FString MapName = "DensityMapTexture";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	FString DirectoryName = "VoxelDensityMaps";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	int MapSize = 1024;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	TEnumAsByte<RenderTexture> RenderType;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Export Preview Heightmap")
	void CreateTextureDensityMap();

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* material;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	bool kost = false;

private:

	UFUNCTION(BlueprintCallable)
	void GenerateLandscape();

	void GenerateOctree(TSharedPtr<FVoxelOctreeData> leaf, uint32 level);

	void SpawnChunk(TSharedPtr<FVoxelOctreeData> chunkData);

	void ChunkInit(UVoxelChunkComponent* chunk, TSharedPtr<FVoxelOctreeData> chunkData);

	UFUNCTION(BlueprintCallable)
	void SpawnBoxTest(FVector location, float radius, float width, FColor color);
	
	void SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks);

	void PutChunkOnGeneration(UVoxelChunkComponent* Chunk);

	UFUNCTION()
	void UpdateOctree();

public:

	TQueue<TSharedPtr<FVoxelChunkRenderData>> ChunksCreationGroup;
	TQueue<UVoxelChunkComponent*> ChunksGenerationGroup;
	TQueue<UVoxelChunkComponent*> ChunksRemovingGroup;

private:

	TArray<TSharedPtr<FVoxelChunkRenderData>> ChunksCreation;
	TArray<UVoxelChunkComponent*> ChunksRemoving;
	TArray<UVoxelChunkComponent*> ChunksGeneration;

public:

	int TotalTasksCounter = 0;

	friend class TerrainGenerationAsyncTask;
	class TerrainGenerationAsyncTask : public FNonAbandonableTask
	{
		UVoxelChunkComponent* VoxelChunkComponent;
		FThreadSafeBool isActive;
		AVoxelLandscape* World;

		int Voxels;
		int LevelOctree;
		int Radius;
		FVector WorldLocation;
		uint8 TransvoxelDirection;

		TArray<float> DensityMap;

	public:

		TerrainGenerationAsyncTask(
			AVoxelLandscape* World,
			UVoxelChunkComponent* InComponent,
			bool isActive, 
			int Voxels,
			int LevelOctree,
			int Radius,
			FVector WorldLocation,
			uint8 TransvoxelDirection)
		{
			this->VoxelChunkComponent = InComponent;
			this->isActive = isActive;
			this->World = World;

			this->Voxels = Voxels;
			this->LevelOctree = LevelOctree;
			this->Radius = Radius;
			this->WorldLocation = WorldLocation;
			this->TransvoxelDirection = TransvoxelDirection;
		}

		FORCEINLINE TStatId GetStatId() const
		{
			RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
		}

		void SetActor(UVoxelChunkComponent* InActor)
		{
			VoxelChunkComponent = InActor;
		}

		void SetActive(bool Active)
		{
			isActive = Active;
		}

		bool GetActive()
		{
			return isActive;
		}

		void DoWork()
		{
			//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelLandscape ] Async started"));

			//FPlatformProcess::Sleep(0.03f);
			{

				/*if (VoxelTerrainActor->Grid.Num() == 0)
				{
					//World->GenerateDensityMap(VoxelTerrainActor);
					VoxelTerrainActor->GenerateDensityMap();
				}
				else
				{
					VoxelTerrainActor->hasOwnGrid = true;
				}*/

				//void AVoxelChunk::GenerateDensityMap()
				{
					DensityMap.Init(-1.0, (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT));

					float radiusVoxel = Radius / (float)Voxels;

					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Voxel Async Generator ] radiusVoxel %f"), radiusVoxel);

					for (int z = 0; z < Voxels + 1 + NORMALS_SKIRT; z++)
					{
						for (int y = 0; y < Voxels + 1 + NORMALS_SKIRT; y++)
						{
							for (int x = 0; x < Voxels + 1 + NORMALS_SKIRT; x++)
							{
								FVector positionNoise;

								positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel;
								positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel;
								positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel;
								positionNoise = positionNoise - (float)(Radius / 2.f);

								DensityMap[x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)] = World->generatorLandscape->GetDensityMap(FVector(positionNoise.X, positionNoise.Y, positionNoise.Z) + WorldLocation);//GetValueNoise(positionNoise);//-(positionNoise.Z - value);
							}
						}
					}
				}
				VoxelMarchingCubesMesher* mesher = new VoxelMarchingCubesMesher(
					Voxels,
					LevelOctree,
					Radius,
					WorldLocation,
					TransvoxelDirection,
					DensityMap
				);
				mesher->GenerateMarchingCubesMesh();
				//VoxelTerrainActor->Grid = DensityMap;
				//VoxelTerrainActor->GenerateVertexCube(false);

				TArray<FVector> Vertices = mesher->Vertices;
				TArray<int32> Triangles = mesher->Triangles;
				TArray<FVector> Normals = mesher->Normals;
				TArray<FLinearColor> VertexColors = mesher->VertexColors;
				
				AsyncTask(ENamedThreads::GameThread, [=]()
					{
						VoxelChunkComponent->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
					});


				delete mesher;
				mesher = nullptr;
			}
			isActive = false;
		}

	private:

	};

	TArray<FAsyncTask<TerrainGenerationAsyncTask>*> PoolThreads;
	FThreadSafeCounter TaskWorkGlobalCounter;

	FCriticalSection OctreeMutex;
	FCriticalSection ChunksToCreationMutex;
};
