// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"

class UVoxelWorldGenerator;
class FVoxelOctreeDensity;

/*
* Voxel Marching Cubes Mesher
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
	int Depth;

	FIntVector		Position;
	uint8			TransitionSides;
	TArray<float>	DensityMap;
	TArray<FColor>	ColorMap;

private:

	FVector		NormalsInfo[8];
	FVector		PositionInfo[8];
	float		DensityInfo[8];
	FColor		ColorInfo[8];
	float		isolevel = 0.f;

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

	TArray<FVector> positionSide;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:

	void GenerateMesh();
	void MarchingCubes(int x, int y, int z);

	FVector GetGradient(int x, int y, int z);
	FVector GetGradient(FIntVector map);

	float GetVoxelSize();
	float GetVoxelSizeHalf();
	float VoxelValueMin(float a, float b, float k);

	void ValueInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, FColor C1, FColor C2, FVector& Vertex, FVector& Normal, FColor& Color);

private:

	FORCEINLINE int PositionToIndices(FIntVector LocalPosition)
	{
		return (LocalPosition.X + NORMAL) + (LocalPosition.Y + NORMAL) * (Voxels + 1 + NORMALS) + (LocalPosition.Z + NORMAL) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS);
	}

	FORCEINLINE float GetDensity(int x, int y, int z)
	{
		return DensityMap[x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
	}

	FORCEINLINE float GetValueNoise(FVector positionGrid)
	{
		FVector GlobalLocation = FVector::OneVector;

		FIntVector P = FIntVector(FMath::RoundToInt(GlobalLocation.X), FMath::RoundToInt(GlobalLocation.Y), FMath::RoundToInt(GlobalLocation.Z));

		return WorldGenerator->GetDensityMap(P);
	}

private:

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius);

	template<uint8 Direction>
	FIntVector TransferToDirection(FIntVector DirectionPosition, float Size);

	template<uint8 Direction>
	float GetValue(FVoxelOctreeDensity* OutOctant, FColor& Color, int X, int Y, int Size, int Steps, bool CurrentOctree);

	template<uint8 Direction>
	FVector GetPosition(int X, int Y, int Size, int Steps);
};
