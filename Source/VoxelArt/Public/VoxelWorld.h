// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelChunkComponent.h"
#include "VoxelPoolComponent.h"
#include "Editor/VoxelEditorData.h"
#include "Generators/VoxelWorldGenerator.h"
#include "Octree/VoxelOctreeManager.h"
#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Octree/VoxelOctreeData.h"
#include "Save/VoxelSaveData.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "VoxelWorld.generated.h"

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

UENUM()
enum Meshers
{
	Cubes			UMETA(DisplayName = "Cubes"),
	MarchingCubes	UMETA(DisplayName = "Marching Cubes"),
	SurfaceNets		UMETA(DisplayName = "Surface Nets")
};

class FVoxelCollisionBox;

UCLASS(Blueprintable, HideCategories = ("Input", "Actor", "LOD"))
class VOXELART_API AVoxelWorld : public AActor
{
	GENERATED_BODY()
	
public:	

	AVoxelWorld();

public:

#if WITH_EDITOR
	void OnPreBeginPIE(bool bIsSimulating);
	void OnEndPIE(bool bIsSimulating);
#endif

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

public:

#if WITH_EDITOR
	virtual bool ShouldTickIfViewportsOnly() const override;
#endif

public:

	VoxelOctreeManager* OctreeManagerThread;
	VoxelOctreeNeighborsChecker* OctreeNeighborsCheckerThread;

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
	UVoxelWorldGenerator* WorldGenerator;

	UPROPERTY(EditAnywhere, Category = "Main")
	UVoxelSaveData* SaveFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	bool EnabledWorldInGame = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Main")
	bool bCreatedInEditor = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "1", ClampMax = "524288", UIMin = "1", UIMax = "524288"))
	int VoxelMin = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "32", ClampMax = "524288", UIMin = "32", UIMax = "524288"))
	int WorldSize = 4096;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "2", ClampMax = "32", UIMin = "2", UIMax = "32"))
	int VoxelsPerChunk = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Main")
	bool TransitionMesh = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"), Category = "Main")
	float TransitionSize = 0.25f;

public:

	void CreateVoxelWorld();
	void CreateVoxelWorldInEditor();
	void DestroyVoxelWorld();
	void UpdateWorld();
	void SaveWorldUtility();
	UVoxelSaveData* SaveWorldToFile();

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bWorldCreated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool EnabledLOD = true;

	UPROPERTY()
	bool bEnableUpdateOctree = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	uint8 DrawingRange = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12"))
	int32 MinimumLOD = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12", EditCondition = bMaximumLOD))
	int32 MaximumLOD = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	TEnumAsByte<Meshers> MesherType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta = (ClampMin = "1", ClampMax = "4096", UIMin = "1", UIMax = "4096"))
	int32 ChunksPerFrame = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool VertexSubdivision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool NormalsSmoothing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	UStaticMesh* MeshTree;

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

	int32 TimeForWorldGenerate = 0;

	bool bStatsShowed = false;

	UPROPERTY(EditDefaultsOnly)
	bool bMaximumLOD = false;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* WorldComponent;

private:

	void GenerateLandscape();
	void GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant);
	void SpawnChunk(FVoxelChunkData* ChunkData);
	void ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData);
	void GetLeavesAndQueueToGeneration(TSharedPtr<FVoxelOctreeData> Octant);
	FEditorViewportClient* GetEditorViewportClient();
	void UpdateOctree();

public:	

	UFUNCTION(BlueprintCallable)
	FIntVector TransferToVoxelWorld(FVector P);

	UFUNCTION(BlueprintCallable)
	FVector TransferToGameWorld(FIntVector P);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int GetIndex(FIntVector P);

public:

	void GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree);

public:

	void GetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float& Value, FColor& Color);
	void SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor);

	void PutChunkOnGeneration(FVoxelChunkData* ChunkData);

	UFUNCTION(BlueprintCallable)
	void VoxelDebugBox(FVector Position, float Radius, float Width, FColor Color);

private:

	TArray<FVoxelChunkData*> ChunksCreation;
	TArray<FVoxelChunkData*> ChunksGeneration;
	TArray<FVoxelChunkData*> ChunksRemoving;

public:

	float TimeToCallGarbageCollection = 0.f;

	int TotalTasksCounter = 0;

	FQueuedThreadPool* ThreadPool;
	TArray<FAsyncTask<FMesherAsyncTask>*> PoolThreads;
	FThreadSafeCounter TaskWorkGlobalCounter;

	FCriticalSection OctreeMutex;
	FCriticalSection ChunksToCreationMutex;
};