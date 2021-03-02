// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/VoxelModificationLandscape.h"
#include "Editor/VoxelEditorData.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

#include "Noise/SimplexNoiseBPLibrary.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"
#include "VoxelLandscape.h"

using namespace VoxelTools;


void UVoxelModificationLandscape::SpherePainter(UVoxelEditorData* Data, AVoxelLandscape* World, FIntVector Position, float Radius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);

	FVoxelOctreeDensity* OutOctant = nullptr;

	World->OctreeMutex.Lock();
	for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
	{
		for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
		{
			for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
			{
				float SphereSDF = Radius - Offset - FVector(X, Y, Z).Size();

				if (SphereSDF >= -1)
				{
					float OutValue = 0.f;
					FColor OutColor = FColor(77.f, 77.f, 77.f);
					World->GetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, OutValue, OutColor);

					float Value = 0.f;

					if (Data->BrushSoftness == BrushSoftness::Smooth)
					{
						Value = OutValue + (Data->Dig ? UKismetMathLibrary::FMax(1.f, SphereSDF) : UKismetMathLibrary::FMin(-1.f, SphereSDF));
					}
					else if (Data->BrushSoftness == BrushSoftness::Insert)
					{
						Value = Data->Dig ? UKismetMathLibrary::FMax(OutValue, SphereSDF) : UKismetMathLibrary::FMin(OutValue, -SphereSDF);
					}
					if (Data->EditorType == EditorType::Terrain)
					{
						World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
					}
					else if (Data->EditorType == EditorType::Color)
					{
						World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, -1.f, Data->BrushColor, false, true);
					}
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, VoxelsRadius * 2);
	World->OctreeMutex.Unlock();
}

void UVoxelModificationLandscape::CubePainter(UVoxelEditorData* Data, AVoxelLandscape* World, FIntVector Position, float Radius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);

	FVoxelOctreeDensity* OutOctant = nullptr;

	World->OctreeMutex.Lock();
	for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
	{
		for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
		{
			for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
			{
				float OutValue = 0.f;
				FColor OutColor = FColor(77.f, 77.f, 77.f);
				World->GetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, OutValue, OutColor);

				float Value = Data->Dig ? UKismetMathLibrary::FMax(OutValue, 1.f) : UKismetMathLibrary::FMin(OutValue, -1.f);

				if (Data->EditorType == EditorType::Terrain)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
				}
				else if (Data->EditorType == EditorType::Color)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, -1.f, Data->BrushColor, false, true);
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, (VoxelsRadius + 1) * 2);
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