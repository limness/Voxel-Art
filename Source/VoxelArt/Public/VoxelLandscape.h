// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelChunk.h"
#include "VoxelChunkComponent.h"
#include "VoxelPoolComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "Editor/VoxelEditorData.h"

#include "Renders/VoxelRender.h"
#include "Renders/VoxelLandscapeGenerator.h"

#include "Octree/VoxelOctreeManager.h"
#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Octree/VoxelOctreeData.h"

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

	VoxelRender* RenderThread;
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
	UVoxelLandscapeGenerator* GeneratorLandscape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	bool EnabledWorldInGame = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Main")
	bool bSaveDensityInGame = true;

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

	int32 TimeForWorldGenerate = 0;
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
	void RemoveOctreeDensityLeaves(FVoxelOctreeDensity* Octant);

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


UCLASS()
class VOXELART_API AVoxelEditorTool : public AActor
{
	GENERATED_BODY()

public:

	AVoxelEditorTool() 
	{
		Marker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EditorTool"));
		RootComponent = Marker;

		auto CubeTool = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
		auto SphereTool = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
		auto MaterialTool = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/MVoxel_Tool.MVoxel_Tool'"));

		if (CubeTool.Succeeded())
		{
			CubeToolMesh = CubeTool.Object;
		}
		if (SphereTool.Succeeded())
		{
			SphereToolMesh = SphereTool.Object;
		}
		if (MaterialTool.Object)
		{
			MaterialPath = MaterialTool.Object;
		}
		Marker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Marker->SetStaticMesh(SphereToolMesh);
	}

	void ToolInitialize(UVoxelEditorData* Data, FVector ToolPosition)
	{
		if (!Material)
		{
			Material = UMaterialInstanceDynamic::Create(MaterialPath, this);
			Marker->SetMaterial(0, Material);
		}
		if (CurrentTool != Data->BrushType)
		{
			switch (Data->BrushType)
			{
			case BrushType::Cube: { Marker->SetStaticMesh(CubeToolMesh); break;  }
			case BrushType::Sphere: { Marker->SetStaticMesh(SphereToolMesh); break; }
			}
			CurrentTool = Data->BrushType;
		}
		Marker->SetWorldLocation(ToolPosition);
		Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->Radius * 2.f);
	}

public:

	TEnumAsByte<BrushType> CurrentTool;
	float CurrentRadius;

private:

	UStaticMesh* CubeToolMesh;
	UStaticMesh* SphereToolMesh;

private:

	UStaticMeshComponent* Marker;
	UMaterialInstanceDynamic* Material;

	UMaterial* MaterialPath;
};