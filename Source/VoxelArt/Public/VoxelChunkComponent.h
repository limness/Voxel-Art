// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelFoliageConfig.h"
#include "VoxelChunkComponent.generated.h"

class AVoxelWorld;
class UVoxelWorldGenerator;
class FVoxelDefaultMesher;
class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMesherAsyncTask;
class FVoxelFoliageAsyncTask;
//struct FVoxelFoliageObject;

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

	//FThreadSafeBool MeshComplete;
	FThreadSafeBool FoliageComplete;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	FVoxelDefaultMesher* MesherObject;
	UMaterialInterface* Material;

	TArray<int32> FoliageObjects;

public:

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;

public:

	bool PoolActive = false;

public:

	bool IsPoolActive();
	void SetPoolActive(AVoxelWorld* World, bool activeStatus);

	FORCEINLINE FVector GetMinimumCorner();
	FORCEINLINE FVector GetMaximumCorner();
	FORCEINLINE bool IsInside(FVector LocalPosition);

	bool CreateMesh(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData);
	bool CreateFoliage(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData);

	void UpdateMesh();
	void UpdateFoliage(AVoxelWorld* World, TArray<FTransform> FoliagePositions);
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

	FVoxelFoliageAsyncTask(AVoxelWorld* _World, UVoxelChunkComponent* _Chunk, FVoxelFoliageObject _Foliage, FVoxelChunkData* _Data)
		: World(_World)
		, Chunk(_Chunk)
		, Foliage(_Foliage)
		, Data(_Data)
	{
	}

public:

	AVoxelWorld* World;
	UVoxelChunkComponent* Chunk;
	FVoxelFoliageObject Foliage;
	FVoxelChunkData* Data;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork();
};
