// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "Helpers/VoxelTools.h"
#include "VoxelChunkComponent.generated.h"


class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMarchingCubesMesher;
class AVoxelLandscape;

UCLASS()
class VOXELART_API UVoxelChunkComponent : public UVoxelProceduralMeshComponent
{
	GENERATED_BODY()

public:

	UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer);

public:

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelLandscapeGenerator* GeneratorLandscape;

	bool Active =		false;
	bool hasOwnGrid =	false;
	bool isPool =		false;

public:

	bool IsPoolActive();
	void SetPoolActive(bool activeStatus);

public:

	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);

public:

	UMaterialInterface* Material;
};


class FMesherAsyncTask : public FNonAbandonableTask
{
public:

	FMesherAsyncTask(AVoxelLandscape* _World, FVoxelChunkData* _Data) 
		: World(_World)
		, Data(_Data)
	{
	}

private:

	AVoxelLandscape* World;
	FVoxelChunkData* Data;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	
	void DoWork();
};
