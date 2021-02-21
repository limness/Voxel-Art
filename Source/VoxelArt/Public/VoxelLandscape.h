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

class FVoxelCollisionBox;

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
	FVoxelOctreeDensity* OctreeDensity;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "0.0", ClampMax = "524288", UIMin = "0.0", UIMax = "524288"))
	int VoxelMin = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "0.0", ClampMax = "524288", UIMin = "0.0", UIMax = "524288"))
	int WorldSize = 32768;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "0", ClampMax = "32", UIMin = "0", UIMax = "32"))
	int VoxelsPerChunk = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Main")
	bool TransitionMesh = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"), Category = "Main")
	float TransitionSize = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Main")
	void CreateVoxelWorld();

	UFUNCTION(BlueprintCallable, Category = "Main")
	void DestroyVoxelWorld();

	UFUNCTION(BlueprintCallable, Category = "Main")
	void UpdateWorld();

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta = (ClampMin = "1", ClampMax = "4096", UIMin = "1", UIMax = "4096"))
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
	USceneComponent* WorldComponent;

private:

	void GenerateLandscape();
	void GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant);
	void SpawnChunk(FVoxelChunkData* ChunkData);
	void ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData);
	void SaveChunksBuffer(TArray<TSharedPtr<FVoxelOctreeData>> Chunks);
	void GetLeavesAndQueueToGeneration(TSharedPtr<FVoxelOctreeData> Octant);
	void UpdateOctree();

public:	

	FIntVector TransferToVoxelWorld(FVector P);
	FVector TransferToGameWorld(FIntVector P);

	FORCEINLINE int GetIndex(FIntVector P);

public:

	void GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree);

public:

	void GetVoxelValue(FIntVector Position, float& Value, FColor& Color);
	void SetVoxelValue(FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor);

	void PutChunkOnGeneration(FVoxelChunkData* ChunkData);

	void SpawnBoxTest(FVector location, float radius, float width, FColor color);

private:

	TArray<FVoxelChunkData*> ChunksCreation;
	TArray<FVoxelChunkData*> ChunksGeneration;
	TArray<FVoxelChunkData*> ChunksRemoving;

public:

	int TotalTasksCounter = 0;

	FQueuedThreadPool* ThreadPool;
	TArray<FAsyncTask<FMesherAsyncTask>*> PoolThreads;
	FThreadSafeCounter TaskWorkGlobalCounter;

	FCriticalSection OctreeMutex;
	FCriticalSection ChunksToCreationMutex;
};
