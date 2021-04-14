﻿// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"

class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Voxel Cubes Mesher class (not completed)
*/
class VOXELART_API FVoxelCubesMesher
{
public:

	FVoxelCubesMesher(
		AVoxelWorld* _World, 
		FVoxelChunkData* _Data, 
		TArray<float> _DensityMap,
		TArray<FColor> _ColorMap
	);
	~FVoxelCubesMesher();

public:

	AVoxelWorld* World;
	UVoxelWorldGenerator* WorldGenerator;

	int Voxels;
	int Size;
	int Depth;

	FIntVector Position;
	uint8 TransitionSides;
	TArray<float> DensityMap;
	TArray<FColor> ColorMap;
	TArray<int> VerticesIndeсes;

public:

	void GenerateMesh();
	void GeneratePlane();

	FVector GetGradient(FVector pos);
	FVector GetInterp(FVector p1, FVector p2, float d1, float d2);

	UPROPERTY(EditDefaultsOnly)
	TArray<FVector> GridGrad;

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

public:

	TArray<FVector>					Vertices;
	TArray<int32>					Triangles;
	TArray<FVector>					Normals;
	TArray<FLinearColor>			VertexColors;
	TArray<FVoxelProcMeshTangent>	Tangents;
	TArray<FVector2D>				TextureCoordinates;
	TArray<FVector>					VerticesTransition;
	TArray<int32>					TrianglesTransition;

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