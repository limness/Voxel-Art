// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "Helpers/VoxelTools.h"
#include "VoxelChunkComponent.generated.h"

<<<<<<< HEAD
class AVoxelWorld;
class UVoxelWorldGenerator;
class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMarchingCubesMesher;
=======

class AVoxelWorld;

class UVoxelWorldGenerator;

class FVoxelOctreeData;
class FVoxelChunkData;
class FVoxelMarchingCubesMesher;

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

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

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelWorldGenerator* WorldGenerator;
<<<<<<< HEAD
	UMaterialInterface* Material;
=======

	bool PoolActive = false;
	//bool HasOwnDensity =	false;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

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
