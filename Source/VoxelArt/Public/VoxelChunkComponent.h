// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "VoxelChunkComponent.generated.h"


#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

class FVoxelOctreeData;
class FVoxelLandscape;
class UVoxelLandscapeGenerator;

UCLASS()
class VOXELART_API UVoxelChunkComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
	
public:

	uint64 nodeID = 0;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelLandscapeGenerator* generatorLandscape;
	FCriticalSection ChunkMutex;

public:

	UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer);
	~UVoxelChunkComponent();

	void Initialize(FIntPoint, UMaterialInterface*);

	float radius = 100;
	int voxels = 12;
	int level = 0;

	bool Active = false;
	bool hasOwnGrid = false;
	bool isPool = false;

	uint8 transvoxelDirection = 0x00;

	TArray<float> DensityMap;
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;

public:

	bool IsActive();
	void SetActive(bool activeStatus);

public:

	bool ChangeVoxel(
		FVector positionCenterPoint,
		float range,
		float strength,
		bool smooth,
		bool dig,
		float smoothInsert);

	float GetVoxelSize();
	float GetVoxelSizeHalf();
	float VoxelValueMin(float a, float b, float k);

	void UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols);

public:

	UMaterialInterface* material;

	class UBoxComponent* CollisionMesh;

public:

	template<uint8 Direction>
	FVector PositionToDirection(FVector directionPosition, float size);

	FORCEINLINE int PositionToIndices(FVector position);

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
	}
	FORCEINLINE float GetDensity(int Index)
	{
		return DensityMap[Index];
	}
};
