// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Meshers/VoxelDefaultMesher.h"
#include "VoxelWorld.h"


class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Marching Cubes Mesher class
*/
class VOXELART_API FVoxelMarchingCubesMesher : public FVoxelDefaultMesher
{
public:

	FVoxelMarchingCubesMesher(AVoxelWorld* _World, FVoxelChunkData* _Data);
	virtual ~FVoxelMarchingCubesMesher() = default;

private:

	uint8 TransitionSides;

	TArray<FVector> positionSide;

private:

	FVector NormalsInfo[8];
	FVector PositionInfo[8];
	float DensityInfo[8];
	FColor ColorInfo[8];

public:

	TArray<FVector> VerticesTransition;
	TArray<int32> TrianglesTransition;

public:

	virtual void GenerateMesh();

public:

	void MarchingCubes(int x, int y, int z);
	void ValueInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, FColor C1, FColor C2, FVector& Vertex, FVector& Normal, FColor& Color);

	FORCEINLINE int PositionToIndices(FIntVector P);

private:

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius);

	template<uint8 Direction>
	FIntVector TransferToDirection(FIntVector P, int Size);

	template<uint8 Direction>
	float GetValue(FVoxelOctreeDensity* OutOctant, FColor& Color, int X, int Y, int Size, int Steps, bool CurrentOctree);

	template<uint8 Direction>
	FVector GetPosition(int X, int Y, int Size, int Steps);
};