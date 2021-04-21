// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelWorld.h"


class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Marching Cubes Mesher class
*/
class VOXELART_API FVoxelMarchingCubesMesher
{
public:

	FVoxelMarchingCubesMesher(AVoxelWorld* _World, FVoxelChunkData* _Data, TArray<float> _DensityMap, TArray<FColor> _ColorMap);
	~FVoxelMarchingCubesMesher();

private:

	AVoxelWorld* World;
	UVoxelWorldGenerator* WorldGenerator;

	int Voxels;
	int Size;
	int VoxelSteps;

	FIntVector Position;
	uint8 TransitionSides;

	TArray<float> DensityMap;
	TArray<FColor> ColorMap;
	TArray<FVector> positionSide;

private:

	FVector NormalsInfo[8];
	FVector PositionInfo[8];
	float DensityInfo[8];
	FColor ColorInfo[8];

	float isolevel = 0.f;

public:

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FVoxelProcMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;

	TArray<FVector> VerticesTransition;
	TArray<int32> TrianglesTransition;

public:

	FVector GetGradient(int x, int y, int z);
	FVector GetGradient(FIntVector map);

	void GenerateMesh();
	void MarchingCubes(int x, int y, int z);
	void ValueInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, FColor C1, FColor C2, FVector& Vertex, FVector& Normal, FColor& Color);

	FORCEINLINE int PositionToIndices(FIntVector P);
	FORCEINLINE float GetDensity(int x, int y, int z);

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