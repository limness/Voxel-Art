// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Helpers/VoxelTools.h"
#include "VoxelChunkComponent.generated.h"


class FVoxelOctreeData;
class FVoxelChunkData;
class AVoxelLandscape;
class FVoxelMarchingCubesMesher;
//class UVoxelLandscapeGenerator;

UCLASS()
class VOXELART_API UVoxelChunkComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
	
public:

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelLandscapeGenerator* GeneratorLandscape;
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

	UMaterialInterface* Material;

	//AVoxelLandscape* Worldd;
};

class FMesherAsyncTask : public FNonAbandonableTask
{
public:

	AVoxelLandscape* World;
	FVoxelChunkData* Data;
	
public:

	FMesherAsyncTask(
		AVoxelLandscape* World,
		FVoxelChunkData* Data)
	{
		this->World = World;
		this->Data = Data;
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	
	void DoWork();
};
