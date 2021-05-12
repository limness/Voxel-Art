// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelChunkComponent.generated.h"

class AVoxelWorld;
class UVoxelWorldGenerator;
class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMesherAsyncTask;

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
	FThreadSafeBool MeshComplete;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	//UVoxelWorldGenerator* WorldGenerator;
	UMaterialInterface* Material;

public:

	bool PoolActive = false;

public:

	bool IsPoolActive();
	void SetPoolActive(bool activeStatus);
	bool CreateMesh(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData);
	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);
};


/*
* Voxel Chunk Async Mesher class
*/
class FVoxelMesherAsyncTask : public FNonAbandonableTask
{
public:

	FVoxelMesherAsyncTask(AVoxelWorld* _World, UVoxelChunkComponent* _Chunk, FVoxelChunkData* _Data)
		: World(_World)
		, Chunk(_Chunk)
		, Data(_Data)
	{
	}

public:

	AVoxelWorld* World;
	FVoxelChunkData* Data;

	UVoxelChunkComponent* Chunk;

public:

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	
	void DoWork();
};
