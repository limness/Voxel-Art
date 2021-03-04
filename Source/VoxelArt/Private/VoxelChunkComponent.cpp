// Voxel Art Plugin © limit 2018

#include "VoxelChunkComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelLandscape.h"
#include "Meshers/VoxelMarchingCubesMesher.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "DrawDebugHelpers.h"


UVoxelChunkComponent::UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UVoxelChunkComponent::IsPoolActive()
{
	return Active;
}

void UVoxelChunkComponent::SetPoolActive(bool activeStatus)
{
	Active = activeStatus;
	if (!activeStatus)
	{
		ClearAllMeshSections();
		SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	else
	{
		SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	ToggleVisibility(!activeStatus);
}

void UVoxelChunkComponent::UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors)
{
	//ClearMeshSection(0);

	if (Vertices.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), Colors, TArray<FVoxelProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}
}

void FMesherAsyncTask::DoWork()
{
	auto GetIndex = [&](int X, int Y, int Z)
	{
		return X + Y * (Data->Voxels + 1 + NORMALS) + Z * (Data->Voxels + 1 + NORMALS) * (Data->Voxels + 1 + NORMALS);
	};
	Data->DensityMap.Init(-1.0, FMath::Pow((Data->Voxels + 1 + NORMALS), 3));
	Data->ColorMap.Init(FColor(77.f, 77.f, 77.f), FMath::Pow((Data->Voxels + 1 + NORMALS), 3));

	int VoxelSteps = (Data->Size / Data->Voxels);

	FVoxelOctreeDensity* OutOctant = nullptr;

	for (int Z = 0; Z < Data->Voxels + 1 + NORMALS; Z++)
	{
		for (int Y = 0; Y < Data->Voxels + 1 + NORMALS; Y++)
		{
			for (int X = 0; X < Data->Voxels + 1 + NORMALS; X++)
			{
				FIntVector DensityLocation = Data->Position - FIntVector(1, 1, 1) * (Data->Size >> 1);
				DensityLocation = DensityLocation + (FIntVector(X, Y, Z) - FIntVector(1, 1, 1) * NORMAL) * VoxelSteps;

				float Value = -1.f;
				FColor Color = FColor(77.f, 7.f, 77.f);

				World->GetVoxelValue(OutOctant, DensityLocation, Value, Color);

				Data->DensityMap[GetIndex(X, Y, Z)] = Value;
				Data->ColorMap[GetIndex(X, Y, Z)] = Color;
			}
		}
	}
	
	FVoxelMarchingCubesMesher mesher = FVoxelMarchingCubesMesher(World, Data);
	mesher.GenerateMarchingCubesMesh();
	
	TArray<FVector> Vertices = mesher.Vertices;
	TArray<int32> Triangles = mesher.Triangles;
	TArray<FVector> Normals = mesher.Normals;
	TArray<FLinearColor> VertexColors = mesher.VertexColors;

	AsyncTask(ENamedThreads::GameThread, [=]()
		{
			/*One more check active before we will create mesh*/
			if (Data->Chunk->Active == true)
			{
				Data->Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
			}
		});

	Data->DensityMap.Empty();
	Data->ColorMap.Empty();

	World->TaskWorkGlobalCounter.Decrement();
}