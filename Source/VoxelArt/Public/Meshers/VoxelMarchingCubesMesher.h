// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "VoxelLandscape.h"
//#include "VoxelMarchingCubesMesher.generated.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

class AVoxelLandscape;
class UVoxelLandscapeGenerator;

/**
 * 
 */
//UCLASS()
class VOXELART_API FVoxelMarchingCubesMesher
{
public:
	FVoxelMarchingCubesMesher(AVoxelLandscape* _World, FVoxelChunkData* _Data);
	~FVoxelMarchingCubesMesher();

private:

	int Voxels;
	int Depth;
	int Size;

	FIntVector Position;
	uint8 TransitionSides;
	TArray<float> DensityMap;

private:

	FVector position[8];
	float infoNoise[8];

	float isolevel = 0.f;

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

	void GenerateMarchingCubesMesh();

	void MarchingCubes(int indexGrid, int x, int y, int z, int normalIndex);

	FVector GetGradient(int x, int y, int z);
	FVector GetGradient(FIntVector map);

	float GetVoxelSize();
	float GetVoxelSizeHalf();

	FVector VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst);
	FVector VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value);

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius);

	template<uint8 Direction>
	FIntVector TransferToDirection(FIntVector DirectionPosition, float Size);

	template<uint8 Direction>
	float GetValue(int X, int Y, int Size, int Steps, bool CurrentOctree);

	template<uint8 Direction>
	FVector GetPosition(int X, int Y, int Size, int Steps);

	FORCEINLINE int PositionToIndices(FIntVector position);

	float VoxelValueMin(float a, float b, float k);
	
	AVoxelLandscape* World;
	UVoxelLandscapeGenerator* GeneratorLandscape;

	TArray<FVector> positionSide;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return DensityMap[x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)];
	}

	FORCEINLINE float GetValueNoise(FVector positionGrid)
	{
		FVector GlobalLocation = FVector::OneVector;//World->GetTransform().InverseTransformPosition(positionGrid + Position);

		FIntVector P = FIntVector(FMath::RoundToInt(GlobalLocation.X), FMath::RoundToInt(GlobalLocation.Y), FMath::RoundToInt(GlobalLocation.Z));

		return GeneratorLandscape->GetDensityMap(P);
	}
};
