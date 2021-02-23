// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/VoxelModificationLandscape.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"
#include "VoxelLandscape.h"

using namespace VoxelTools;

void UVoxelModificationLandscape::SpherePainter(AVoxelLandscape* World, FIntVector Position, float Radius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);

	World->OctreeMutex.Lock();
	for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
	{
		for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
		{
			for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
			{
				FVector PositionVoxel = FVector(X, Y, Z);
				float Value = Radius - Offset - PositionVoxel.Size();

				//UE_LOG(VoxelArt, Log, TEXT("changed %s"), *((FIntVector)PositionVoxel + Position).ToString());

				World->SetVoxelValue((FIntVector)PositionVoxel + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
			}
		}
	}
	UpdateOverlapOctants(World, Position, VoxelsRadius * 2);
	World->OctreeMutex.Unlock();
}

void UVoxelModificationLandscape::CubePainter(AVoxelLandscape* World, FIntVector Position, float Radius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);

	World->OctreeMutex.Lock();
	for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
	{
		for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
		{
			for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
			{
				FVector PositionVoxel = FVector(X, Y, Z);
				float Value = 1.f - Offset;
				World->SetVoxelValue((FIntVector)PositionVoxel + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
			}
		}
	}
	UpdateOverlapOctants(World, Position, VoxelsRadius * 2);
	World->OctreeMutex.Unlock();
}

float UVoxelModificationLandscape::BangPainter(int X, int Y, int Z, float Radius, int octaves, float amplitude, float frequency)
{
	float value = 0.f;
	float valuefractal = 0.f;

	value = Radius - sqrt(X * X + Y * Y + Z * Z);

	for (int i = 0; i < octaves; i++)
	{
		valuefractal += USimplexNoiseBPLibrary::SimplexNoise3D(X * frequency, Y * frequency, Z * frequency) * amplitude;
		frequency *= 2.f;
		amplitude *= 0.5f;
	}

	return value + valuefractal;
}

void UVoxelModificationLandscape::UpdateOverlapOctants(AVoxelLandscape* World, FIntVector Position, int Size)
{
	FVoxelCollisionBox Box = FVoxelCollisionBox(World, Position, Size);
	TArray<TSharedPtr<FVoxelOctreeData>> OverlapOctants;

	World->GetOverlapingOctree(Box, World->MainOctree, OverlapOctants);

	for (auto& Octant : OverlapOctants)
	{
		if (Octant->Data != nullptr)
		{
			if (IsValid(Octant->Data->Chunk))
			{
				World->PutChunkOnGeneration(Octant->Data);
			}
		}
	}
}