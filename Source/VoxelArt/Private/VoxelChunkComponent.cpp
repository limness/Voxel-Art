// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelChunkComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelLandscape.h"
#include "Meshers/VoxelMarchingCubesMesher.h"
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
		SetCollisionEnabled(ECollisionEnabled::NoCollision); //QueryAndPhysics
	}
	else
	{
		SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //QueryAndPhysics
	}
	ToggleVisibility(!activeStatus);
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float UVoxelChunkComponent::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

void UVoxelChunkComponent::UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors)
{
	ClearMeshSection(0);

	if (Vertices.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), Colors, TArray<FProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}
}

void FMesherAsyncTask::DoWork()
{
	{
		{
			Data->DensityMap.Init(-1.0, (Data->Voxels + 1 + NORMALS_SKIRT) * (Data->Voxels + 1 + NORMALS_SKIRT) * (Data->Voxels + 1 + NORMALS_SKIRT));

			float radiusVoxel = Data->Size / (float)Data->Voxels;

			for (int z = 0; z < Data->Voxels + 1 + NORMALS_SKIRT; z++)
			{
				for (int y = 0; y < Data->Voxels + 1 + NORMALS_SKIRT; y++)
				{
					for (int x = 0; x < Data->Voxels + 1 + NORMALS_SKIRT; x++)
					{
						FVector positionNoise;

						positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise = positionNoise - (float)(Data->Size / 2.f);

						//UE_LOG(VoxelArt, Log, TEXT("Octree Neighbors Checker init %d"), World->VoxelsPerChunk);
						Data->DensityMap[x + y * (Data->Voxels + 1 + NORMALS_SKIRT) + z * (Data->Voxels + 1 + NORMALS_SKIRT) * (Data->Voxels + 1 + NORMALS_SKIRT)] = World->GeneratorLandscape->GetDensityMap(FVector(positionNoise.X, positionNoise.Y, positionNoise.Z) + Data->Position);//GetValueNoise(positionNoise);//-(positionNoise.Z - value);
					}
				}
			}
		}
		FVoxelMarchingCubesMesher* mesher = new FVoxelMarchingCubesMesher(World->GeneratorLandscape, Data);
		mesher->GenerateMarchingCubesMesh();

		TArray<FVector> Vertices = mesher->Vertices;
		TArray<int32> Triangles = mesher->Triangles;
		TArray<FVector> Normals = mesher->Normals;
		TArray<FLinearColor> VertexColors = mesher->VertexColors;

		AsyncTask(ENamedThreads::GameThread, [=]()
			{
				/*One more check active before we will create mesh*/
				if (Data->Chunk->Active == true)
				{
					Data->Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
				}
			});


		World->TaskWorkGlobalCounter.Decrement();

		delete mesher;
		mesher = nullptr;
	}
}