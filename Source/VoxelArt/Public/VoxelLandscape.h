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
	RedGreenBlue	UMETA(DisplayName = "RGB")
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
	TQueue<TSharedPtr<FChunksRenderInfo>> ChangesOctree;
	TMap<uint64, TSharedPtr<FVoxelOctreeData>> SavedChunks;

private:

	UVoxelPoolComponent* PoolChunks;
	TArray<UVoxelChunkComponent*> ChunkComponents;

public:

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Main")
	UVoxelLandscapeGenerator* GeneratorLandscape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	bool EnabledWorldInGame = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "0.0", ClampMax = "5000000.0", UIMin = "0.0", UIMax = "5000000.0"))
	float WorldRadius = 500000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "0", ClampMax = "32", UIMin = "0", UIMax = "32"))
	int VoxelsPerChunk = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	UMaterialInterface* material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Main")
	bool TransitionMesh = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"), Category = "Main")
	float TransitionSize = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Main")
	void CreateVoxelWorld();

	UFUNCTION(BlueprintCallable, Category = "Main")
	void DestroyVoxelWorld();

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool TerrainCreated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool EnabledLOD = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	uint8 DrawingRange = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "15", UIMin = "0", UIMax = "15"))
	int32 MinimumLOD = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "15", UIMin = "0", UIMax = "15"))
	int32 MaximumLOD = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta = (ClampMin = "1", ClampMax = "2048", UIMin = "1", UIMax = "2048"))
	int32 ChunksPerFrame = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool VertexSubdivision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool NormalsSmoothing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	UStaticMesh* MeshTree;

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

	UFUNCTION(BlueprintCallable, Category = "Export Preview Heightmap")
	void CreateTextureDensityMap();

private:

	int TimeForWorldGenerate = 0;
	bool StatsShowed = false;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* SceneComponent;

private:

	void GenerateLandscape();
	void GenerateOctree(TSharedPtr<FVoxelOctreeData> Octan);
	void SpawnChunk(TSharedPtr<FVoxelOctreeData> chunkData);
	void ChunkInit(UVoxelChunkComponent* chunk, TSharedPtr<FVoxelOctreeData> chunkData);
	void SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks);
	void PutChunkOnGeneration(UVoxelChunkComponent* Chunk);
	void UpdateOctree();

public:

	void GetVoxelValue(FVector Position, float& Value);
	FORCEINLINE void SetVoxelValue(FVector Position, float& Value) const;

	void SpawnBoxTest(FVector location, float radius, float width, FColor color);

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

								DensityMap[x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)] = World->GeneratorLandscape->GetDensityMap(FVector(positionNoise.X, positionNoise.Y, positionNoise.Z) + WorldLocation);//GetValueNoise(positionNoise);//-(positionNoise.Z - value);
							}
						}
					}
				}
				VoxelMarchingCubesMesher* mesher = new VoxelMarchingCubesMesher(
					World->GeneratorLandscape,
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
