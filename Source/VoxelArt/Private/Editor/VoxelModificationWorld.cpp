// Voxel Art Plugin 2021 ~ Copyright Limit


#include "Editor/VoxelModificationWorld.h"
#include "Editor/VoxelEditorData.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

//#include "Noise/SimplexNoiseBPLibrary.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelSDFUtilities.h"
#include "Helpers/VoxelCollisionBox.h"
#include "VoxelWorld.h"

using namespace VoxelTools;


void UVoxelModificationWorld::SpherePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);

	FVoxelOctreeDensity* OutOctant = nullptr;

	World->OctreeMutex.Lock();

	bool TerrainEdit = Data->EditorType == EEditorType::TerrainEdit;
	bool ColorEdit = Data->EditorType == EEditorType::ColorEdit;

	if (Data->CopyPastOn && Data->CopyingPasting == ECopyingPasting::Pasting)
	{
		for (auto& VoxelCopied : Data->CopiedDensity)
		{
			World->SetVoxelValue(OutOctant, VoxelCopied.Position, VoxelCopied.Value, VoxelCopied.Color, true, true);
		}
		return;
	}
	for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
	{
		for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
		{
			for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
			{
				float SphereSDF = FVoxelSDFUtilities::SphereSDF(X, Y, Z, Radius);// Radius - VoxelOffset - FVector(X, Y, Z).Size();

				//if (SphereSDF >= -2)
				if(Data->CopyPastOn)
				{
					if (Data->CopyingPasting == ECopyingPasting::Copying)
					{
						float OutValue = 0.f;
						FColor OutColor = FColor(77.f, 77.f, 77.f);
						World->GetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, OutValue, OutColor);

						Data->CopiedDensity.Add(FVoxelInfo(FIntVector(X, Y, Z) + Position, OutValue, OutColor));
					}
				}
				else
				{
					float OutValue = 0.f;
					FColor OutColor = FColor(77.f, 77.f, 77.f);
					World->GetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, OutValue, OutColor);

					float Value = 0.f;
					{
						if (TerrainEdit)
						{
							if (Data->BrushSoftness == EBrushSoftness::Smooth)
							{
							}
							else if (Data->BrushSoftness == EBrushSoftness::Insert)
							{
								Value = Data->Dig ? UKismetMathLibrary::FMax(OutValue, SphereSDF) : UKismetMathLibrary::FMin(OutValue, -SphereSDF);
							}
						}
					}
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, Data->BrushColor, TerrainEdit, ColorEdit);
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, VoxelsRadius * 2);
	World->OctreeMutex.Unlock();
}

void UVoxelModificationWorld::CubePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius)
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

				if (Data->EditorType == EEditorType::TerrainEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
				}
				else if (Data->EditorType == EEditorType::ColorEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, -1.f, Data->BrushColor, false, true);
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, (VoxelsRadius + 1) * 2);
	World->OctreeMutex.Unlock();
}

void UVoxelModificationWorld::TorusPainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius, float InnerRadius)
{
	int VoxelsRadius = FMath::CeilToInt(Radius + InnerRadius);

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

				float TorusSDF = FVoxelSDFUtilities::TorusSDF(X, Y, Z, Radius, InnerRadius);
				float Value = UKismetMathLibrary::FMin(OutValue, TorusSDF);

				if (Data->EditorType == EEditorType::TerrainEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
				}
				else if (Data->EditorType == EEditorType::ColorEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, -1.f, Data->BrushColor, false, true);
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, (VoxelsRadius + 1) * 2);
	World->OctreeMutex.Unlock();
}

void UVoxelModificationWorld::ConePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius, float Height, FVector2D Angle)
{
	int VoxelsRadius = FMath::CeilToInt(Radius + Height);

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

				float TorusSDF = FVoxelSDFUtilities::ConeSDF(X, Y, Z, Angle, Height);//FVoxelSDFUtilities::TorusSDF(X, Y, Z, Radius, InnerRadius);
				float Value = UKismetMathLibrary::FMin(OutValue, TorusSDF);

				if (Data->EditorType == EEditorType::TerrainEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, Value, FColor(77.f, 77.f, 77.f), true, false);
				}
				else if (Data->EditorType == EEditorType::ColorEdit)
				{
					World->SetVoxelValue(OutOctant, FIntVector(X, Y, Z) + Position, -1.f, Data->BrushColor, false, true);
				}
			}
		}
	}
	UpdateOverlapOctants(World, Position, (VoxelsRadius + 1) * 2);
	World->OctreeMutex.Unlock();
}

float UVoxelModificationWorld::BangPainter(int X, int Y, int Z, float Radius, int octaves, float amplitude, float frequency)
{
	float value = 0.f;
	float valuefractal = 0.f;
	
	// TODO: Tranfer to Fast Noise
	/*
	value = Radius - sqrt(X * X + Y * Y + Z * Z);

	for (int i = 0; i < octaves; i++)
	{
		valuefractal += USimplexNoiseBPLibrary::SimplexNoise3D(X * frequency, Y * frequency, Z * frequency) * amplitude;
		frequency *= 2.f;
		amplitude *= 0.5f;
	}
	*/
	return value + valuefractal;
}

void UVoxelModificationWorld::UpdateOverlapOctants(AVoxelWorld* World, FIntVector Position, int Size)
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