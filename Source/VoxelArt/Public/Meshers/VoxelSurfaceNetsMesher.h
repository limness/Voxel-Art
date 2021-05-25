// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Meshers/VoxelDefaultMesher.h"
#include "VoxelWorld.h"

class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Voxel Surface Nets Mesher class
*/
class VOXELART_API FVoxelSurfaceNetsMesher : public FVoxelDefaultMesher
{
public:

	FVoxelSurfaceNetsMesher(AVoxelWorld* _World, FVoxelChunkData* _Data);
	virtual ~FVoxelSurfaceNetsMesher() = default;

public:

	virtual void GenerateMesh();
	void GeneratePlane();

	FVector GetInterp(FVector p1, FVector p2, float d1, float d2);


	FIntVector Position;
	TArray<int> VerticesIndeсes;

public:

	UPROPERTY(EditDefaultsOnly)
	TArray<FVector> GridGrad;

	UPROPERTY(EditDefaultsOnly)
	TArray<FVector> deltas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FVector> normalsAverage;

private:

	int dirs[3][3] = {
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 }
	};

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