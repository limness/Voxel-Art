// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
//#include "VoxelBoundChunkData.h"
#include "Components/BoxComponent.h"
#include "Editor/VoxelModificationLandscape.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Async/Async.h"
//#include "MarchingCubes.h"
//#include "MyObject.h"
//#include "SimplexNoiseBPLibrary.h"
#include "ProceduralMeshComponent.h"
#include "VoxelChunk.generated.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

class FVoxelOctreeData;
class FVoxelLandscape;
class UVoxelLandscapeGenerator;

UCLASS()
class VOXELART_API AVoxelChunk : public AActor
{
	GENERATED_BODY()

public:
//	FAsyncTask<TerrainGenerationAsyncTask>* Task;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void GenerateDensityAndCreateMeshAsync();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface* material;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint64 nodeID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 transvoxelDirection = 0x00;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 x_chunk = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 y_chunk = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 z_chunk = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UProceduralMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UProceduralMeshComponent* mesh1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* CollisionMesh;

public:
	//AVoxelChunk(const class FObjectInitializer& ObjectInitializer);
	AVoxelChunk();

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	void SetActive(bool activeStatus);
	bool IsActive();
	bool Active;

	UPROPERTY(VisibleAnywhere)
	TArray <FVector> mesh_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Octree")
	int multiplyOctree = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size", Meta = (ExposeOnSpawn = true))
	float radius = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size", Meta = (ExposeOnSpawn = true))
	FString heightTest = "test";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	float radiusSphere = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	int voxels = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	int level = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
	bool hasOwnGrid = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float actave = 0.003f;

	//Chunk is pool
	bool isPool = false;

	//Chunk is pool
	bool isUpdating = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float period = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
	float period_two = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
	FLinearColor ground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
	FLinearColor grass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planet")
	bool half = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planet")
	bool update = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector positionChunk;

	UPROPERTY()
	FVector position[8];
	float infoNoise[8];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TArray<int> infoChunk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TArray<int> infoGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TArray<float> Grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
	bool generateSphere = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
	bool generateNoise = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
	bool generatePlane = false;

	TArray<FVector> VerticesTransition;
	TArray<int32> TrianglesTransition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) // , Meta = (MakeEditWidget = true) //EditDefaultsOnly
	TArray<FVector> Vertices;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<int32> Triangles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Normals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true)) // , Meta = (MakeEditWidget = true)
	TArray<FLinearColor> VertexColors;

	UPROPERTY()
	TArray<FProcMeshTangent> Tangents;

	UPROPERTY()
	TArray<FVector2D> TextureCoordinates;

	UFUNCTION(BlueprintCallable)
	void GenerateDensityMap();

	UFUNCTION(BlueprintCallable)
	void GenerateVertexCube(bool regenerate);

	bool IsUpdating = false;

	FVector GetGradient(int x, int y, int z);
	FVector GetGradient(FIntVector map);

	FLinearColor GetColor(FVector positionVoxel);

	UFUNCTION()
	void MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex);

	UFUNCTION(BlueprintCallable)
	bool ChangeVoxel(UVoxelModificationLandscape* modificator, 
		FVector positionCenterPoint,
		float range,
		float strength,
		bool smooth,
		bool dig,
		float smoothInsert);
	//bool ChangeVoxel(float range, AVoxelChunk* chunkCenter, FVector voxelCenter, float volume, float strength, bool smooth);

	UFUNCTION(BlueprintCallable)
	float GetVoxelSize();

	UFUNCTION(BlueprintCallable)
	float GetVoxelSizeHalf();

	UFUNCTION(BlueprintCallable)
	void UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols);

	UFUNCTION()
	FVector VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst);
	FVector VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value);

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius);

	template<uint8 Direction>
	FVector PositionToDirection(FVector directionPosition, float size);

	template<uint8 Direction>
	 float GetValue(float X, float Y, float size, int LOD);

	FORCEINLINE int PositionToIndices(FVector position);

	float GetValueSpawner(FVector positionGrid);

	float GetValueNoise(FVector positionGrid);

	float VoxelValueMin(float a, float b, float k);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	UStaticMesh* meshTree;

	TArray<UHierarchicalInstancedStaticMeshComponent*> FolliageComponents;
	
	UVoxelLandscapeGenerator* generatorLandscape;

	TArray<FVector> positionSide;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;

	//FCriticalSection ChunkDensityMutex;
	FCriticalSection ChunkMutex;

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
	}

	FORCEINLINE float GetDensity(int Index)
	{
	//	FScopeLock Lock(&ChunkMutex);
		return Grid[Index];
	}
};
