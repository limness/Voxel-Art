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

	bool Active = false;
	bool hasOwnGrid = false;
	bool isPool = false;

public:

	bool IsActive();
	void SetActive(bool activeStatus);

public:

	float VoxelValueMin(float a, float b, float k);

	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);

public:

	UMaterialInterface* material;
};
