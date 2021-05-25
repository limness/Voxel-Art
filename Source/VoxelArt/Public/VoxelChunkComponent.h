// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelChunkComponent.generated.h"

class AVoxelWorld;
class UVoxelWorldGenerator;
class FVoxelDefaultMesher;
class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMesherAsyncTask;
class FVoxelFoliageAsyncTask;

/*
* Voxel Chunk Component class
*/
UCLASS()
class VOXELART_API UVoxelChunkComponent : public UVoxelProceduralMeshComponent
{
	GENERATED_BODY()

public:

	UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer);

public:

	FAsyncTask<FVoxelMesherAsyncTask>* MesherTask;
	TArray<FAsyncTask<FVoxelFoliageAsyncTask>*> FoliageTasks;

	FThreadSafeBool MeshComplete;
	FThreadSafeBool FoliageComplete;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	FVoxelDefaultMesher* MesherObject;
	UMaterialInterface* Material;

	//TArray<>

public:

	bool PoolActive = false;

public:

	bool IsPoolActive();
	void SetPoolActive(bool activeStatus);

	FORCEINLINE FVector GetMinimumCorner();
	FORCEINLINE FVector GetMaximumCorner();
	FORCEINLINE bool IsInside(FVector LocalPosition);

	bool CreateMesh(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData);
	bool CreateFoliage(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData);

	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);
	void UpdateFoliage(AVoxelWorld* World, TArray<FVector> FoliagePositions);
};


/*
* Voxel Chunk Async Mesher class
*/
class FVoxelMesherAsyncTask : public FNonAbandonableTask
{
public:

	FVoxelMesherAsyncTask(AVoxelWorld* _World, UVoxelChunkComponent* _Chunk, FVoxelChunkData* _Data, FVoxelDefaultMesher* _MesherObject)
		: World(_World)
		, Chunk(_Chunk)
		, Data(_Data)
		, MesherObject(_MesherObject)
	{
	}

public:

	AVoxelWorld* World;
	UVoxelChunkComponent* Chunk;
	FVoxelChunkData* Data;
	FVoxelDefaultMesher* MesherObject;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	
	void DoWork();
};



/*
* Voxel Chunk Async Foliage class
*/
class FVoxelFoliageAsyncTask : public FNonAbandonableTask
{
public:

	FVoxelFoliageAsyncTask(AVoxelWorld* _World, UVoxelChunkComponent* _Chunk, FVoxelChunkData* _Data)
		: World(_World)
		, Chunk(_Chunk)
		, Data(_Data)
	{
	}

public:

	AVoxelWorld* World;
	UVoxelChunkComponent* Chunk;
	FVoxelChunkData* Data;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork();
};
