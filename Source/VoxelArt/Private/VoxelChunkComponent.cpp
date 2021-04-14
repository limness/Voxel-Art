// Voxel Art Plugin © limit 2018

#include "VoxelChunkComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelWorld.h"

#include "Meshers/VoxelMarchingCubesMesher.h"
#include "Meshers/VoxelSurfaceNetsMesher.h"
#include "Meshers/VoxelCubesMesher.h"

#include "Noise/SimplexNoiseBPLibrary.h"
#include "DrawDebugHelpers.h"


/*UVoxelChunkComponent::UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}*/

bool UVoxelChunkComponent::IsPoolActive()
{
	return PoolActive;
}

void UVoxelChunkComponent::SetPoolActive(bool activeStatus)
{
	PoolActive = activeStatus;
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
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), Colors, TArray<FProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}
}

void FMesherAsyncTask::DoWork()
{
	TArray<float> DensityMap;
	TArray<FColor> ColorMap;

	auto GetIndex = [&](int X, int Y, int Z)
	{
		return X + Y * (Data->Voxels + 1 + NORMALS) + Z * (Data->Voxels + 1 + NORMALS) * (Data->Voxels + 1 + NORMALS);
	};
	DensityMap.Init(-1.0, FMath::Pow(Data->Voxels + 1 + NORMALS, 3));
	ColorMap.Init(VOXEL_COLOR, FMath::Pow(Data->Voxels + 1 + NORMALS, 3));

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
				FColor Color = VOXEL_COLOR;

				World->GetVoxelValue(OutOctant, DensityLocation, Value, Color);

				DensityMap[GetIndex(X, Y, Z)] = Value;
				ColorMap[GetIndex(X, Y, Z)] = Color;
			}
		}
	}
	
	if (World->MesherType == Meshers::MarchingCubes)
	{
		FVoxelMarchingCubesMesher mesher = FVoxelMarchingCubesMesher(World, Data, DensityMap, ColorMap);
		mesher.GenerateMesh();

		TArray<FVector> Vertices = mesher.Vertices;
		TArray<int32> Triangles = mesher.Triangles;
		TArray<FVector> Normals = mesher.Normals;
		TArray<FLinearColor> VertexColors = mesher.VertexColors;

		AsyncTask(ENamedThreads::GameThread, [=]()
			{
				/*One more check active before we will create mesh*/
				if (Data->Chunk->IsPoolActive())
				{
					Data->Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
				}
			});
	}
	else if (World->MesherType == Meshers::SurfaceNets)
	{
		FVoxelSurfaceNetsMesher mesher = FVoxelSurfaceNetsMesher(World, Data, DensityMap, ColorMap);
		mesher.GenerateMesh();

		TArray<FVector> Vertices = mesher.Vertices;
		TArray<int32> Triangles = mesher.Triangles;
		TArray<FVector> Normals = mesher.Normals;
		TArray<FLinearColor> VertexColors = mesher.VertexColors;

		AsyncTask(ENamedThreads::GameThread, [=]()
			{
				/*One more check active before we will create mesh*/
				if (Data->Chunk->IsPoolActive())
				{
				//	UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
					Data->Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
				}
			});
	}
	else if (World->MesherType == Meshers::Cubes)
	{
		FVoxelCubesMesher mesher = FVoxelCubesMesher(World, Data, DensityMap, ColorMap);
		mesher.GenerateMesh();

		TArray<FVector> Vertices = mesher.Vertices;
		TArray<int32> Triangles = mesher.Triangles;
		TArray<FVector> Normals = mesher.Normals;
		TArray<FLinearColor> VertexColors = mesher.VertexColors;

		AsyncTask(ENamedThreads::GameThread, [=]()
			{
				/*One more check active before we will create mesh*/
				if (Data->Chunk->IsPoolActive())
				{
					//UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
					Data->Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
				}
			});
	}
	World->TaskWorkGlobalCounter.Decrement();
}