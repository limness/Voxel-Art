// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelProceduralMeshComponent.h"

class AVoxelWorld;
class FVoxelChunkData;

/*
* Marching Cubes Mesher class
*/
class VOXELART_API FVoxelDefaultMesher
{
public:

	FVoxelDefaultMesher(AVoxelWorld* _World, FVoxelChunkData* _Data);
	virtual ~FVoxelDefaultMesher();

protected:

	AVoxelWorld* World;
	UVoxelWorldGenerator* WorldGenerator;

	int Voxels;
	int Size;
	int VoxelSteps;

	FIntVector Position;

	TArray<float> DensityMap;
	TArray<FColor> ColorMap;

protected:

	float isolevel = 0.f;

public:

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FVoxelProcMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;

protected:

	virtual FVector GetGradient(int x, int y, int z);
	virtual FVector GetGradient(FIntVector map);

	virtual float GetDensity(int x, int y, int z);

public:

	void GenerateDensityMap();

	virtual void GenerateMesh()	{}
};