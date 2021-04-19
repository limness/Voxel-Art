// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelChunkComponent.generated.h"

class AVoxelWorld;
class UVoxelWorldGenerator;
class FVoxelOctreeData;
class FVoxelChunkData;

/*
* Voxel Chunk Component class
*/
UCLASS()
class VOXELART_API UVoxelChunkComponent : public UVoxelProceduralMeshComponent
{
	GENERATED_BODY()

public:

//	UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer);

public:

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelWorldGenerator* WorldGenerator;
	UMaterialInterface* Material;

public:

	bool PoolActive = false;

public:

	bool IsPoolActive();
	void SetPoolActive(bool activeStatus);
	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);
};


/*
* Voxel Chunk Async Mesher class
*/
class FMesherAsyncTask : public FNonAbandonableTask
{
public:

	FMesherAsyncTask(AVoxelWorld* _World, FVoxelChunkData* _Data) 
		: World(_World)
		, Data(_Data)
	{
	}

private:

	AVoxelWorld* World;
	FVoxelChunkData* Data;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	
	void DoWork();
};
