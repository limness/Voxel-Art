// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelChunkComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "DrawDebugHelpers.h"

UVoxelChunkComponent::UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bUseAsyncCooking = true;
}

UVoxelChunkComponent::~UVoxelChunkComponent()
{
}


void UVoxelChunkComponent::Initialize(FIntPoint inPos, UMaterialInterface* material)
{

}

bool UVoxelChunkComponent::IsActive()
{
	return Active;
}

void UVoxelChunkComponent::SetActive(bool activeStatus)
{
	Active = activeStatus;
	if (!activeStatus)
	{
		ClearMeshSection(0);
	}
	ToggleVisibility(!activeStatus);
}

bool UVoxelChunkComponent::ChangeVoxel(
	FVector positionCenterPoint,
	float range,
	float strength,
	bool smooth,
	bool dig,
	float smoothInsert)
{
	float radiusVoxel = GetVoxelSize();

	for (int z = 0; z < voxels + 1 + NORMALS_SKIRT; z++)
	{
		for (int y = 0; y < voxels + 1 + NORMALS_SKIRT; y++)
		{
			for (int x = 0; x < voxels + 1 + NORMALS_SKIRT; x++)
			{
				FVector positionNoise;

				positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel;
				positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel;
				positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel;
				positionNoise = positionNoise - (float)(radius / 2.f);
				positionNoise += GetComponentLocation() - positionCenterPoint;

				float calculateRadius = range - sqrt(pow(positionNoise.X, 2) + pow(positionNoise.Y, 2) + pow(positionNoise.Z, 2));
				float volume = dig ? -1.f : 1.f;

				if (volume < 0)
				{
					if (smooth)
					{
						if (UKismetMathLibrary::FMin(-1.f, calculateRadius * volume) != -1.f)
						{
							DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] += UKismetMathLibrary::FMin(-1.f, calculateRadius * volume) * strength;
						}
					}
					else
					{
						DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = VoxelValueMin(DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)], calculateRadius * volume, smoothInsert);//calculateRadius
					}
				}
				else
				{
					if (smooth)
					{
						if (UKismetMathLibrary::FMax(1.f, calculateRadius * volume) != 1.f)
						{
							DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] += UKismetMathLibrary::FMax(1.f, calculateRadius * volume) * strength;
						}
					}
					else
					{
						DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = -VoxelValueMin(-DensityMap[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)], -calculateRadius * volume, smoothInsert); //calculateRadius
					}
				}
			}
		}
	}
	return true;
}

FORCEINLINE int UVoxelChunkComponent::PositionToIndices(FVector position)
{
	return
		((int)position.X + NORMALS_SKIRT_HALF) +
		((int)position.Y + NORMALS_SKIRT_HALF) * (voxels + 1 + NORMALS_SKIRT) +
		((int)position.Z + NORMALS_SKIRT_HALF) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT);
}

template<uint8 Direction>
FVector UVoxelChunkComponent::PositionToDirection(FVector directionPosition, float size)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector(size - directionPosition.Z, directionPosition.Y, directionPosition.X); }		//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, size - directionPosition.Z, directionPosition.Y); }		//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, size - directionPosition.Z); }		//0x20

	return directionPosition;
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float UVoxelChunkComponent::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

void UVoxelChunkComponent::UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols)
{
	ClearMeshSection(0);

	if (Vert.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vert, Tri, Norm, TArray<FVector2D>(), Cols, TArray<FProcMeshTangent>(), true);
		SetMaterial(0, material);
	}
}

float UVoxelChunkComponent::GetVoxelSize()
{
	return radius / (float)voxels;
}

float UVoxelChunkComponent::GetVoxelSizeHalf()
{
	return radius / (float)voxels / 2.f;
}