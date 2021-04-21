// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"

class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Voxel Surface Nets Mesher class
*/
class VOXELART_API FVoxelSurfaceNetsMesher
{
public:

	FVoxelSurfaceNetsMesher(AVoxelWorld* _World, FVoxelChunkData* _Data, TArray<float> _DensityMap, TArray<FColor> _ColorMap);
	~FVoxelSurfaceNetsMesher();

public:

	void GenerateMesh();
	void GeneratePlane();

	FVector GetGradient(FVector pos);
	FVector GetInterp(FVector p1, FVector p2, float d1, float d2);

public:

	AVoxelWorld* World;
	UVoxelWorldGenerator* WorldGenerator;

private:

	int Voxels;
	int Depth;
	int Size;

	FIntVector Position;
	uint8 TransitionSides;
	TArray<float> DensityMap;
	TArray<FColor> ColorMap;
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

public:

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FVoxelProcMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;

	TArray<FVector> VerticesTransition;
	TArray<int32> TrianglesTransition;

private:

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return DensityMap[x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
	}

	FORCEINLINE int GetVerticesIndeces(int x, int y, int z)
	{
		return VerticesIndeсes[x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
	}
};