// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Meshers/VoxelDefaultMesher.h"
#include "VoxelWorld.h"

class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Voxel Cubes Mesher class (not completed)
*/
class VOXELART_API FVoxelCubesMesher : public FVoxelDefaultMesher
{
public:

	FVoxelCubesMesher(AVoxelWorld* _World, FVoxelChunkData* _Data);
	virtual ~FVoxelCubesMesher() = default;

public:

	TArray<int> VerticesIndeсes;

public:

	virtual void GenerateMesh();

public:

	void GeneratePlane();

	FVector GetInterp(FVector p1, FVector p2, float d1, float d2);

	UPROPERTY(EditDefaultsOnly)
	TArray<FVector> deltas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FVector> normalsAverage;

private:

	int edges[12][2] = {
		{0,4}, {1,5}, {2,6}, {3,7},	// x-axis 
		{0,2}, {1,3}, {4,6}, {5,7},	// y-axis
		{0,1}, {2,3}, {4,5}, {6,7}	// z-axis
	};

private:

	FORCEINLINE int GetVerticesIndeces(int x, int y, int z)
	{
		return VerticesIndeсes[x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
	}
};