// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Meshers/VoxelMarchingCubesMesher.h"
#include "VoxelChunkComponent.generated.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1


class FVoxelOctreeData;
class AVoxelLandscape;
class UVoxelLandscapeGenerator;

UCLASS()
class VOXELART_API UVoxelChunkComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
	
public:

	uint64 NodeID = 0;

	TWeakPtr<FVoxelOctreeData> CurrentOctree;
	UVoxelLandscapeGenerator* GeneratorLandscape;
	FCriticalSection ChunkMutex;

public:

	UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer);
	~UVoxelChunkComponent();

	void Initialize(FIntPoint, UMaterialInterface*);

	bool Active = false;
	bool hasOwnGrid = false;
	bool isPool = false;

public:

	bool IsActive();
	void SetActive(bool activeStatus);

public:

	float VoxelValueMin(float a, float b, float k);

	void UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors);

public:

	UMaterialInterface* Material;

	//AVoxelLandscape* Worldd;
};

class FMesherAsyncTask : public FNonAbandonableTask
{
	UVoxelChunkComponent* VoxelChunkComponent;
	AVoxelLandscape* World;
	/*
	int Voxels;
	int LevelOctree;
	int Radius;
	FVector WorldLocation;
	uint8 TransvoxelDirection;

	TArray<float> DensityMap;

public:

	FMesherAsyncTask(
		AVoxelLandscape* World,
		UVoxelChunkComponent* InComponent,
		int Voxels,
		int LevelOctree,
		int Radius,
		FVector WorldLocation,
		uint8 TransvoxelDirection)
	{
		this->VoxelChunkComponent = InComponent;
		this->World = World;

		this->Voxels = Voxels;
		this->LevelOctree = LevelOctree;
		this->Radius = Radius;
		this->WorldLocation = WorldLocation;
		this->TransvoxelDirection = TransvoxelDirection;
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TerrainGenerationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	void SetActor(UVoxelChunkComponent* InActor)
	{
		VoxelChunkComponent = InActor;
	}

	void DoWork()
	{
		{
			DensityMap.Init(-1.0, (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT));

			float radiusVoxel = Radius / (float)Voxels;

			for (int z = 0; z < Voxels + 1 + NORMALS_SKIRT; z++)
			{
				for (int y = 0; y < Voxels + 1 + NORMALS_SKIRT; y++)
				{
					for (int x = 0; x < Voxels + 1 + NORMALS_SKIRT; x++)
					{
						FVector positionNoise;

						positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel;
						positionNoise = positionNoise - (float)(Radius / 2.f);

						DensityMap[x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)] = World->GeneratorLandscape->GetDensityMap(FVector(positionNoise.X, positionNoise.Y, positionNoise.Z) + WorldLocation);//GetValueNoise(positionNoise);//-(positionNoise.Z - value);
					}
				}
			}
		}
		VoxelMarchingCubesMesher* mesher = new VoxelMarchingCubesMesher(
			World->GeneratorLandscape,
			Voxels,
			LevelOctree,
			Radius,
			WorldLocation,
			TransvoxelDirection,
			DensityMap
		);
		mesher->GenerateMarchingCubesMesh();

		TArray<FVector> Vertices = mesher->Vertices;
		TArray<int32> Triangles = mesher->Triangles;
		TArray<FVector> Normals = mesher->Normals;
		TArray<FLinearColor> VertexColors = mesher->VertexColors;

		AsyncTask(ENamedThreads::GameThread, [=]()
			{
				VoxelChunkComponent->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
			});

		delete mesher;
		mesher = nullptr;
	}*/
};
