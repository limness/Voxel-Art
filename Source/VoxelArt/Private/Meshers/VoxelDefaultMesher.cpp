// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Meshers/VoxelDefaultMesher.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelWorld.h"


FVoxelDefaultMesher::FVoxelDefaultMesher(AVoxelWorld* _World, FVoxelChunkData* _Data)
	: World(_World)
	, WorldGenerator(_World->WorldGenerator)
	, Voxels(_Data->Voxels)
	, Size(_Data->Size)
	, Position(_Data->Position)
{
	VoxelSteps = (Size / Voxels);
}

FVoxelDefaultMesher::~FVoxelDefaultMesher()
{
}

FVector FVoxelDefaultMesher::GetGradient(int x, int y, int z)
{
	float d = 0.01f;

	FVector average_normal;

	average_normal.X = (GetDensity(x + 1, y + 0, z + 0) - GetDensity(x - 1, y - 0, z - 0)) / 2 / d;
	average_normal.Y = (GetDensity(x + 0, y + 1, z + 0) - GetDensity(x - 0, y - 1, z - 0)) / 2 / d;
	average_normal.Z = (GetDensity(x + 0, y + 0, z + 1) - GetDensity(x - 0, y - 0, z - 1)) / 2 / d;

	return average_normal;
}

FVector FVoxelDefaultMesher::GetGradient(FIntVector map)
{
	float d = 0.01f;

	FVector average_normal;

	average_normal.X = (GetDensity((map.X + 1), (map.Y + 0), (map.Z + 0)) - GetDensity((map.X - 1), (map.Y - 0), (map.Z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((map.X + 0), (map.Y + 1), (map.Z + 0)) - GetDensity((map.X - 0), (map.Y - 1), (map.Z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((map.X + 0), (map.Y + 0), (map.Z + 1)) - GetDensity((map.X - 0), (map.Y - 0), (map.Z - 1))) / 2 / d;

	return average_normal;
}

float FVoxelDefaultMesher::GetDensity(int x, int y, int z)
{
	return DensityMap[x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
}

void FVoxelDefaultMesher::GenerateDensityMap()
{
	auto GetIndex = [&](int X, int Y, int Z)
	{
		return X + Y * (Voxels + 1 + NORMALS) + Z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS);
	};
	DensityMap.Init(-1.0, FMath::Pow(Voxels + 1 + NORMALS, 3));
	ColorMap.Init(VOXEL_COLOR, FMath::Pow(Voxels + 1 + NORMALS, 3));

	FVoxelOctreeDensity* OutOctant = nullptr;

	for (int Z = 0; Z < Voxels + 1 + NORMALS; Z++)
	{
		for (int Y = 0; Y < Voxels + 1 + NORMALS; Y++)
		{
			for (int X = 0; X < Voxels + 1 + NORMALS; X++)
			{
				FIntVector DensityLocation = Position - FIntVector(1, 1, 1) * (Size >> 1);
				DensityLocation = DensityLocation + (FIntVector(X, Y, Z) - FIntVector(1, 1, 1) * NORMAL) * VoxelSteps;

				float Value = -1.f;
				FColor Color = VOXEL_COLOR;

				World->GetVoxelValue(OutOctant, DensityLocation, Value, Color);

				//UE_LOG(LogTemp, Error, TEXT("VoxelSteps %d Value %f"), VoxelSteps, Value);

				DensityMap[GetIndex(X, Y, Z)] = Value;
				ColorMap[GetIndex(X, Y, Z)] = Color;
			}
		}
	}
}