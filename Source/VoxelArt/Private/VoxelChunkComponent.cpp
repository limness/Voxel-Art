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
	auto GetIndex = [&](int X, int Y, int Z)
	{
		return X + Y * (Data->Voxels + 1 + NORMALS_SKIRT) + Z * (Data->Voxels + 1 + NORMALS_SKIRT) * (Data->Voxels + 1 + NORMALS_SKIRT);
	};
	Data->DensityMap.Init(-1.0, FMath::Pow((Data->Voxels + 1 + NORMALS_SKIRT), 3));

	int VoxelSteps = (Data->Size / Data->Voxels);//(1 << (World->MaximumLOD - Data->Depth));

	for (int Z = 0; Z < Data->Voxels + 1 + NORMALS_SKIRT; Z++)
	{
		for (int Y = 0; Y < Data->Voxels + 1 + NORMALS_SKIRT; Y++)
		{
			for (int X = 0; X < Data->Voxels + 1 + NORMALS_SKIRT; X++)
			{
				FIntVector DensityLocation = Data->Position - FIntVector(1, 1, 1) * (Data->Size >> 1);
				DensityLocation = DensityLocation + (FIntVector(X, Y, Z) - FIntVector(1, 1, 1) * NORMALS_SKIRT_HALF) * VoxelSteps;
				/*FVector DensityLocation = (FVector(X, Y, Z) - NORMALS_SKIRT_HALF) * SizeVoxel;
				DensityLocation = DensityLocation - (float)(Data->Size / 2.f);
				DensityLocation = DensityLocation + Data->Position;*/
				//FVector GlobalLocation = World->GetTransform().InverseTransformPosition(DensityLocation);
					
				//FIntVector P = FIntVector(FMath::RoundToInt(GlobalLocation.X), FMath::RoundToInt(GlobalLocation.Y), FMath::RoundToInt(GlobalLocation.Z));

/*
				AsyncTask(ENamedThreads::GameThread, [=]()
					{
						DrawDebugPoint(World->GetWorld(), ((FVector)DensityLocation), 30, FColor::Red, false, 25);

					});*/
				float Value = -1.f;
				World->GetVoxelValue(DensityLocation, Value);

				//UE_LOG(VoxelArt, Error, TEXT("%s // %f"), *DensityLocation.ToString(), Value);

				Data->DensityMap[GetIndex(X, Y, Z)] = Value;//World->GeneratorLandscape->GetDensityMap(P);
			}
		}
	}

	FVoxelMarchingCubesMesher* mesher = new FVoxelMarchingCubesMesher(World, Data);
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