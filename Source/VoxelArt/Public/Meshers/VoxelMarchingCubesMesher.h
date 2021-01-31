// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "VoxelLandscape.h"
//#include "VoxelMarchingCubesMesher.generated.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

class UVoxelLandscapeGenerator;

/**
 * 
 */
//UCLASS()
class VOXELART_API VoxelMarchingCubesMesher
{
public:
	VoxelMarchingCubesMesher(
		int _Voxels,
		int _LevelOctree,
		int _Radius,
		FVector _WorldLocation,
		uint8 _TransvoxelDirection,
		TArray<float> _DensityMap);
	~VoxelMarchingCubesMesher();

private:

	int Voxels;
	int LevelOctree;
	float Radius;

	FVector WorldLocation;
	uint8 TransvoxelDirection;
	TArray<float> DensityMap;

private:

	FVector position[8];
	float infoNoise[8];

public:

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;

	TArray<FVector> VerticesTransition;
	TArray<int32> TrianglesTransition;

public:

	//void GenerateDensityMap();

	void GenerateMarchingCubesMesh(/*
		TArray<FVector>& Vertices,
		TArray<int32>& Triangles,
		TArray<FVector>& Normals,
		TArray<FLinearColor>& VertexColors,
		TArray<FProcMeshTangent>& Tangents,
		TArray<FVector2D>& TextureCoordinates*/);

	void MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex);

	FVector GetGradient(int x, int y, int z);
	FVector GetGradient(FIntVector map);

	float GetVoxelSize();
	float GetVoxelSizeHalf();

	FVector VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst);
	FVector VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value);

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius);

	template<uint8 Direction>
	FVector PositionToDirection(FVector directionPosition, float size);

	template<uint8 Direction>
	float GetValue(float X, float Y, float size, int LOD);

	FORCEINLINE int PositionToIndices(FVector position);

	float VoxelValueMin(float a, float b, float k);

	UVoxelLandscapeGenerator* generatorLandscape;

	TArray<FVector> positionSide;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return DensityMap[x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)];
	}

	FORCEINLINE float GetValueNoise(FVector positionGrid)
	{
		float noise = 0.f;

		positionGrid += WorldLocation;

		return generatorLandscape->GetDensityMap(FVector(positionGrid.X, positionGrid.Y, positionGrid.Z));//-(positionGrid.Z + 5000.f);
	}
	/*FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
	}

	FORCEINLINE float GetDensity(int Index)
	{
		//	FScopeLock Lock(&ChunkMutex);
		return Grid[Index];
	}*/
};
