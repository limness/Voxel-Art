// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelMarchingCubesMesher.h"
#include "Helpers/MarchingCubes.h"

VoxelMarchingCubesMesher::VoxelMarchingCubesMesher(
	UVoxelLandscapeGenerator* _GeneratorLandscape,
	int _Voxels,
	int _LevelOctree,
	int _Radius,
	FVector _WorldLocation,
	uint8 _TransvoxelDirection,
	TArray<float> _DensityMap)
{
	GeneratorLandscape = _GeneratorLandscape;
	Voxels = _Voxels;
	LevelOctree = _LevelOctree;
	Radius = _Radius;
	WorldLocation = _WorldLocation;
	TransvoxelDirection = _TransvoxelDirection;
	DensityMap = _DensityMap;
}

VoxelMarchingCubesMesher::~VoxelMarchingCubesMesher()
{
}

void VoxelMarchingCubesMesher::GenerateMarchingCubesMesh(/*
	TArray<FVector>& Vertices,
	TArray<int32>& Triangles,
	TArray<FVector>& Normals,
	TArray<FLinearColor>& VertexColors,
	TArray<FProcMeshTangent>& Tangents,
	TArray<FVector2D>& TextureCoordinates*/)
{
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	TextureCoordinates.Empty();
	VertexColors.Empty();

	positionSide.Init(FVector(0, 0, 0), (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT));

	int isolevel = 0;
	int normalIndex = 0;

	float radiusVoxel = GetVoxelSize();

	FVector firstPoint, lastPoint;

	for (int z = NORMALS_SKIRT_HALF; z < Voxels + NORMALS_SKIRT_HALF; z++)
	{
		for (int y = NORMALS_SKIRT_HALF; y < Voxels + NORMALS_SKIRT_HALF; y++)
		{
			for (int x = NORMALS_SKIRT_HALF; x < Voxels + NORMALS_SKIRT_HALF; x++)
			{
				for (int i = 0; i < 8; i++)
				{
					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = !(i / 4);

					uint8 localMinimumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 0);
					uint8 localMaximumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0) << 1);

					uint8 localMinimumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 2);
					uint8 localMaximumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0) << 3);

					uint8 localMinimumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 4);
					uint8 localMaximumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0) << 5);

					int MinimumX = (((TransvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumX = (((TransvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0);

					int MinimumY = (((TransvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumY = (((TransvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0);

					int MinimumZ = (((TransvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumZ = (((TransvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == Voxels - 0) ? 1 : 0);

					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] minx %d %d %d"), MinimumX, MinimumY, MinimumZ);

					if (((localMinimumX || localMaximumX) & (localMinimumY || localMaximumY)) |
						((localMinimumY || localMaximumY) & (localMinimumZ || localMaximumZ)) |
						((localMinimumZ || localMaximumZ) & (localMinimumX || localMaximumX)))
					{
						uint8 maskSidesVertex = (localMaximumX | localMinimumX) | (localMaximumY | localMinimumY) | (localMaximumZ | localMinimumZ);

						if ((TransvoxelDirection & maskSidesVertex) == maskSidesVertex)
						{
							//we don't need change anything
						}
						else
						{
							MinimumX = 0;
							MinimumY = 0;
							MinimumZ = 0;

							MaximumX = 0;
							MaximumY = 0;
							MaximumZ = 0;
						}
					}


					float transitionX = 0.25f * (X == 1 ? -MaximumX : MinimumX);
					float transitionY = 0.25f * (Y == 1 ? -MaximumY : MinimumY);
					float transitionZ = 0.25f * (Z == 1 ? -MaximumZ : MinimumZ);

					infoNoise[i] = DensityMap[(x + X) + (y + Y) * (Voxels + 1 + NORMALS_SKIRT) + (z + Z) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)];
					position[i] = FVector((x + X + transitionX - NORMALS_SKIRT_HALF) * radiusVoxel, (y + Y + transitionY - NORMALS_SKIRT_HALF) * radiusVoxel, (z + Z + transitionZ - NORMALS_SKIRT_HALF) * radiusVoxel) - (float)(Radius / 2.f);

					positionSide[(x + X) + (y + Y) * (Voxels + 1 + NORMALS_SKIRT) + (z + Z) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)] = position[i];
				}

				MarchingCubes(isolevel, x + y * (Voxels + 1 + NORMALS_SKIRT) + z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT), x, y, z, normalIndex);

				normalIndex++;
			}
		}
	}
	if (true)
	{
		if ((TransvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) GeometryTransitionCubes<EVoxelDirection::MinimumX>(Radius);
		if ((TransvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) GeometryTransitionCubes<EVoxelDirection::MaximumX>(Radius);

		if ((TransvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) GeometryTransitionCubes<EVoxelDirection::MinimumY>(Radius);
		if ((TransvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) GeometryTransitionCubes<EVoxelDirection::MaximumY>(Radius);

		if ((TransvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) GeometryTransitionCubes<EVoxelDirection::MinimumZ>(Radius);
		if ((TransvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) GeometryTransitionCubes<EVoxelDirection::MaximumZ>(Radius);
	}
	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelLandscape ] Inside _DensityMap %d Location %s radius %f voxels %d"), DensityMap.Num(), *WorldLocation.ToString(), Radius, Voxels);

	positionSide.Empty();
	/*
	AsyncTask(ENamedThreads::GameThread, [this]()
		{
			UpdateMesh(Vertices, Triangles, Normals, VertexColors);
		});*/
}

void VoxelMarchingCubesMesher::MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex)
{
	int cubeIndex = 0;

	FVector vertList[12];
	FVector normList[12];

	if (infoNoise[0] < isolevel) cubeIndex |= 1;
	if (infoNoise[1] < isolevel) cubeIndex |= 2;
	if (infoNoise[2] < isolevel) cubeIndex |= 4;
	if (infoNoise[3] < isolevel) cubeIndex |= 8;
	if (infoNoise[4] < isolevel) cubeIndex |= 16;
	if (infoNoise[5] < isolevel) cubeIndex |= 32;
	if (infoNoise[6] < isolevel) cubeIndex |= 64;
	if (infoNoise[7] < isolevel) cubeIndex |= 128;

	if (edgeTable[cubeIndex] == 0) return;

	if (edgeTable[cubeIndex] & 1)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 0, z + 1);

		vertList[0] = VertexInterp(position[0], position[1], normalOne, normalTwo, infoNoise[0], infoNoise[1], 0, normList[0]);
	}
	if (edgeTable[cubeIndex] & 2)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 1, z + 1);

		vertList[1] = VertexInterp(position[1], position[2], normalOne, normalTwo, infoNoise[1], infoNoise[2], 0, normList[1]);
	}
	if (edgeTable[cubeIndex] & 4)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 1, z + 1);

		vertList[2] = VertexInterp(position[2], position[3], normalOne, normalTwo, infoNoise[2], infoNoise[3], 0, normList[2]);
	}
	if (edgeTable[cubeIndex] & 8)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 0, z + 1);

		vertList[3] = VertexInterp(position[3], position[0], normalOne, normalTwo, infoNoise[3], infoNoise[0], 0, normList[3]);
	}
	if (edgeTable[cubeIndex] & 16)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 0);
		normalTwo = GetGradient(x + 1, y + 0, z + 0);

		vertList[4] = VertexInterp(position[4], position[5], normalOne, normalTwo, infoNoise[4], infoNoise[5], 0, normList[4]);
	}
	if (edgeTable[cubeIndex] & 32)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 0);
		normalTwo = GetGradient(x + 1, y + 1, z + 0);

		vertList[5] = VertexInterp(position[5], position[6], normalOne, normalTwo, infoNoise[5], infoNoise[6], 0, normList[5]);
	}
	if (edgeTable[cubeIndex] & 64)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 0);
		normalTwo = GetGradient(x + 0, y + 1, z + 0);

		vertList[6] = VertexInterp(position[6], position[7], normalOne, normalTwo, infoNoise[6], infoNoise[7], 0, normList[6]);
	}
	if (edgeTable[cubeIndex] & 128)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 0);
		normalTwo = GetGradient(x + 0, y + 0, z + 0);

		vertList[7] = VertexInterp(position[7], position[4], normalOne, normalTwo, infoNoise[7], infoNoise[4], 0, normList[7]);
	}
	if (edgeTable[cubeIndex] & 256)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 1);
		normalTwo = GetGradient(x + 0, y + 0, z + 0);

		vertList[8] = VertexInterp(position[0], position[4], normalOne, normalTwo, infoNoise[0], infoNoise[4], 0, normList[8]);
	}
	if (edgeTable[cubeIndex] & 512)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 0, z + 0);

		vertList[9] = VertexInterp(position[1], position[5], normalOne, normalTwo, infoNoise[1], infoNoise[5], 0, normList[9]);
	}
	if (edgeTable[cubeIndex] & 1024)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 1);
		normalTwo = GetGradient(x + 1, y + 1, z + 0);

		vertList[10] = VertexInterp(position[2], position[6], normalOne, normalTwo, infoNoise[2], infoNoise[6], 0, normList[10]);
	}
	if (edgeTable[cubeIndex] & 2048)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 1, z + 0);

		vertList[11] = VertexInterp(position[3], position[7], normalOne, normalTwo, infoNoise[3], infoNoise[7], 0, normList[11]);
	}
	//

	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
	{
		Vertices.Add(vertList[triTable[cubeIndex][i]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(-normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 0]] + WorldLocation));

		Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(-normList[triTable[cubeIndex][i + 1]].GetUnsafeNormal());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 1]] + WorldLocation));// - (1 * radius) / 2.0f));

		Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
		Triangles.Add(Triangles.Num());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 2]] + WorldLocation));// - (1 * radius) / 2.0f));
		Normals.Add(-normList[triTable[cubeIndex][i + 2]].GetUnsafeNormal());

		/*AsyncTask(ENamedThreads::GameThread, [=]()
			{
				if (GetValueSpawner((
					vertList[triTable[cubeIndex][i + 0]] +
					vertList[triTable[cubeIndex][i + 1]] +
					vertList[triTable[cubeIndex][i + 2]]) / 3.f) > 5000.f)
				{
					UHierarchicalInstancedStaticMeshComponent* HierarchicalInstancedStaticMeshComponent = NewObject<UHierarchicalInstancedStaticMeshComponent>(this, NAME_None, RF_Transient);

					HierarchicalInstancedStaticMeshComponent->RegisterComponent();
					HierarchicalInstancedStaticMeshComponent->SetStaticMesh(meshTree);


					FTransform DesiredTransform;// = this->GetComponentTransform();
					DesiredTransform.SetScale3D(FVector(3.f, 3.f, 3.f));
					DesiredTransform.SetRotation(FQuat(FRotator(FMath::RandRange(-60.f, 60.f), FMath::RandRange(-60.f, 60.f), 0.f)));
					DesiredTransform.SetLocation((
						vertList[triTable[cubeIndex][i + 0]] +
						vertList[triTable[cubeIndex][i + 1]] +
						vertList[triTable[cubeIndex][i + 2]]) / 3.f);

					static FName NoCollision(TEXT("NoCollision"));
					HierarchicalInstancedStaticMeshComponent->SetCollisionProfileName(NoCollision);
					HierarchicalInstancedStaticMeshComponent->bDisableCollision = true;
					HierarchicalInstancedStaticMeshComponent->bAffectDistanceFieldLighting = false;
					HierarchicalInstancedStaticMeshComponent->bCastStaticShadow = false;

					HierarchicalInstancedStaticMeshComponent->AddInstance(DesiredTransform);
					HierarchicalInstancedStaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

					//DrawDebugBox(GetWorld(), WorldLocation + (
					//	vertList[triTable[cubeIndex][i + 0]] +
					//	vertList[triTable[cubeIndex][i + 1]] +
					//	vertList[triTable[cubeIndex][i + 2]]) / 3.f, FVector(40.f, 40.f, 320.f), FColor::Green, false, 33.f, 33.f, 92.f);
				}
			});*/
	}
}


template<uint8 Direction>
void VoxelMarchingCubesMesher::GeometryTransitionCubes(float radius)
{
	float radiusVoxel = GetVoxelSize();
	float radiusHalf = GetVoxelSizeHalf();

	float cornerNoise[13];

	for (int x = 0; x < Voxels; x++)
	{
		for (int y = 0; y < Voxels; y++)
		{
			cornerNoise[0] = GetValue<Direction>((x + 0), (y + 0), Voxels, LevelOctree / 2.f);		// 0 - 9
			cornerNoise[1] = GetValue<Direction>((x + 0.5f), (y + 0), Voxels, LevelOctree / 2.f);		// 1
			cornerNoise[2] = GetValue<Direction>((x + 1.f), (y + 0), Voxels, LevelOctree / 2.f);		// 2 - A
			cornerNoise[3] = GetValue<Direction>((x + 0), (y + 0.5f), Voxels, LevelOctree / 2.f);		// 3
			cornerNoise[4] = GetValue<Direction>((x + 0.5f), (y + 0.5f), Voxels, LevelOctree / 2.f);	// 4
			cornerNoise[5] = GetValue<Direction>((x + 1.f), (y + 0.5f), Voxels, LevelOctree / 2.f);	// 5
			cornerNoise[6] = GetValue<Direction>((x + 0), (y + 1.f), Voxels, LevelOctree / 2.f);		// 6 - B
			cornerNoise[7] = GetValue<Direction>((x + 0.5f), (y + 1.f), Voxels, LevelOctree / 2.f);	// 7
			cornerNoise[8] = GetValue<Direction>((x + 1.f), (y + 1.f), Voxels, LevelOctree / 2.f);	// 8 - C

			cornerNoise[9] = GetValue<Direction>((x + 0), (y + 0), Voxels, LevelOctree);				// 9
			cornerNoise[10] = GetValue<Direction>((x + 1.f), (y + 0), Voxels, LevelOctree);			// A
			cornerNoise[11] = GetValue<Direction>((x + 0), (y + 1.f), Voxels, LevelOctree);			// B
			cornerNoise[12] = GetValue<Direction>((x + 1.f), (y + 1.f), Voxels, LevelOctree);			// C

			uint32 caseValue =
				((cornerNoise[0] < 0.f) << 0)
				| ((cornerNoise[1] < 0.f) << 1)
				| ((cornerNoise[2] < 0.f) << 2)
				| ((cornerNoise[5] < 0.f) << 3)
				| ((cornerNoise[8] < 0.f) << 4)
				| ((cornerNoise[7] < 0.f) << 5)
				| ((cornerNoise[6] < 0.f) << 6)
				| ((cornerNoise[3] < 0.f) << 7)
				| ((cornerNoise[4] < 0.f) << 8);

			if (caseValue != 0 && caseValue != 511)
			{
				FVector cornerPosition[13];
				FVector normals[13];

				cornerPosition[0] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 0 - 9
				normals[0] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[1] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[1] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[2] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 2 - A
				normals[2] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[3] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[3] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[4] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[4] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[5] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[5] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[6] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 6 - B
				normals[6] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[7] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[7] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				cornerPosition[8] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 8 - C
				normals[8] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));

				for (uint32 i = 9; i < 13; i++)
				{
					const int X = (i - 1) % 2;
					const int Y = (i - 1) % 4 / 2;

					cornerPosition[i] = positionSide[
						(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), Voxels + 2).X) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), Voxels + 2).Y) * (Voxels + 1 + NORMALS_SKIRT) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), Voxels + 2).Z) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)];

					normals[i] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), Voxels + 2));
				}


				const uint8 cellClass = Transvoxels::transitionCellClass[caseValue];
				const uint16* vertexData = Transvoxels::transitionVertexData[caseValue];
				Transvoxels::TransitionCellData cellData = Transvoxels::transitionCellData[cellClass & 0x7F];

				bool convertTriangles = ((cellClass >> 7) == 0);

				TArray<FVector> _VerticesTransition;
				TArray<FVector> _NormalsTransition;
				TArray<int32> _TrianglesTransition;

				for (int i = 0; i < cellData.GetTriangleCount() * 3; i++)
				{
					const uint16& edgeCode = vertexData[i];

					uint8 indexPointA = (edgeCode >> 4) & 0x0F;
					uint8 indexPointB = edgeCode & 0x0F;

					FVector positionA = cornerPosition[indexPointA];
					FVector positionB = cornerPosition[indexPointB];

					float valueA = cornerNoise[indexPointA];
					float valueB = cornerNoise[indexPointB];

					FVector normalOne = normals[indexPointA];
					FVector normalTwo = normals[indexPointB];

					FVector N = FVector(0.f, 0.f, 0.f);
					FVector P = VertexInterp(positionA, positionB, normalOne, normalTwo, valueA, valueB, 0, N);

					//uint8 indexEdge = (edgeCode >> 8) & 0x0F;
					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelChunk ] normal %s"), *N.ToString());

					_NormalsTransition.Add(-N.GetUnsafeNormal());
					_VerticesTransition.Add(P);
				}

				if (convertTriangles)
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
					}
				}
				else
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
					}
				}
				// Add our transition cells to global variable of data

				for (int a = 0; a < _VerticesTransition.Num(); a++)
				{
					Vertices.Add(_VerticesTransition[a]);
					VertexColors.Add(GeneratorLandscape->GetColorMap(_VerticesTransition[a] + WorldLocation));
				}

				for (int j = 0; j < _NormalsTransition.Num(); j++)
				{
					Normals.Add(_NormalsTransition[j]);
				}

				for (int b = 0; b < _TrianglesTransition.Num(); b++)
				{
					Triangles.Add(_TrianglesTransition[b]);
				}

				VerticesTransition.Empty();
				TrianglesTransition.Empty();
			}
		}
	}
}
//#include "Misc/ScopeTryLock.h"
template<uint8 Direction>
float VoxelMarchingCubesMesher::GetValue(float X, float Y, float size, int LOD)
{
	FVector GlobalPosition = PositionToDirection<Direction>(FVector(X, Y, 0), size);
	float value = 0.f;

	//if (FMath::Fmod(GlobalPosition.X, 1.f) == 0 && FMath::Fmod(GlobalPosition.Y, 1.f) == 0 && FMath::Fmod(GlobalPosition.Z, 1.f) == 0)
	if (LOD == LevelOctree)
	{
		value = DensityMap[PositionToIndices(GlobalPosition)];
	}
	else
	{
		value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(Radius / 2.f));
	}
	/*if (true) {}
	else
	{
		TWeakPtr<FVoxelOctreeData> chunkNeihbor = nullptr;

		if ((Direction >> 0) & 0x01 || (Direction >> 3) & 0x01 || (Direction >> 4) & 0x01)
		{
			chunkNeihbor = CurrentOctree.Pin()->GetNeighbor<Direction>((X / 0.5 >= Voxels) + 2 * (Y / 0.5 >= Voxels));
		}
		else
		{
			chunkNeihbor = CurrentOctree.Pin()->GetNeighbor<Direction>((Y / 0.5 >= Voxels) + 2 * (X / 0.5 >= Voxels));
		}
		if (chunkNeihbor.IsValid())
		{
			if (chunkNeihbor.Pin()->chunk->DensityMap.Num() > 0)
			{
				FScopeTryLock ScopeTryLock(&chunkNeihbor.Pin()->chunk->ChunkMutex);
				if (ScopeTryLock.IsLocked())
				{
					GlobalPosition = FVector(
						GlobalPosition.X / 0.5 >= Voxels ? GlobalPosition.X / 0.5 - Voxels : GlobalPosition.X / 0.5,
						GlobalPosition.Y / 0.5 >= Voxels ? GlobalPosition.Y / 0.5 - Voxels : GlobalPosition.Y / 0.5,
						GlobalPosition.Z / 0.5 >= Voxels ? GlobalPosition.Z / 0.5 - Voxels : GlobalPosition.Z / 0.5
					);

					if ((Direction >> 0) & 0x01) { GlobalPosition.X = Voxels; } //0x01
					if ((Direction >> 1) & 0x01) { GlobalPosition.X = 0.f; } //0x02
					if ((Direction >> 2) & 0x01) { GlobalPosition.Y = Voxels; } //0x04
					if ((Direction >> 3) & 0x01) { GlobalPosition.Y = 0.f; } //0x08
					if ((Direction >> 4) & 0x01) { GlobalPosition.Z = Voxels; } //0x10
					if ((Direction >> 5) & 0x01) { GlobalPosition.Z = 0.f; } //0x20

					value = chunkNeihbor.Pin()->chunk->GetDensity(PositionToIndices(GlobalPosition));
				}
				else
				{
					value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(Radius / 2.f));
				}
			}
			else
			{
				value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(Radius / 2.f));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelChunk ] Error: neighbor empty"));
		}
	}*/
	return value;
}

FORCEINLINE int VoxelMarchingCubesMesher::PositionToIndices(FVector position)
{
	return ((int)position.X + NORMALS_SKIRT_HALF) +
		((int)position.Y + NORMALS_SKIRT_HALF) * (Voxels + 1 + NORMALS_SKIRT) +
		((int)position.Z + NORMALS_SKIRT_HALF) * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT);
}

template<uint8 Direction>
FVector VoxelMarchingCubesMesher::PositionToDirection(FVector directionPosition, float size)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector(size - directionPosition.Z, directionPosition.Y, directionPosition.X); }		//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, size - directionPosition.Z, directionPosition.Y); }		//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, size - directionPosition.Z); }		//0x20

	return directionPosition;
}

FVector VoxelMarchingCubesMesher::GetGradient(int x, int y, int z)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((x + 1), (y + 0), (z + 0)) - GetDensity((x - 1), (y - 0), (z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((x + 0), (y + 1), (z + 0)) - GetDensity((x - 0), (y - 1), (z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((x + 0), (y + 0), (z + 1)) - GetDensity((x - 0), (y - 0), (z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

FVector VoxelMarchingCubesMesher::GetGradient(FIntVector map)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((map.X + 1), (map.Y + 0), (map.Z + 0)) - GetDensity((map.X - 1), (map.Y - 0), (map.Z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((map.X + 0), (map.Y + 1), (map.Z + 0)) - GetDensity((map.X - 0), (map.Y - 1), (map.Z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((map.X + 0), (map.Y + 0), (map.Z + 1)) - GetDensity((map.X - 0), (map.Y - 0), (map.Z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float VoxelMarchingCubesMesher::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

/*void VoxelMarchingCubesMesher::UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols)
{
	//Remove default DensityMap
	mesh->ClearMeshSection(0);

	//Remove transition DensityMap
	//mesh->ClearMeshSection(1);

	if (Vert.Num() > 0)
	{
		for (int a = 0; a < VerticesTransition.Num(); a++)
		{
			//	Vert.Add(VerticesTransition[a]);
		}

		for (int b = 0; b < TrianglesTransition.Num(); b++)
		{
			//	Tri.Add(TrianglesTransition[b]);
		}
		//Norm
		mesh->CreateMeshSection_LinearColor(0, Vert, Tri, TArray<FVector>(), TArray<FVector2D>(), Cols, TArray<FProcMeshTangent>(), true);
		mesh->SetMaterial(0, material);
	}
	if (VerticesTransition.Num() > 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelChunk ] create transit %d %d"), VerticesTransition.Num(), TrianglesTransition.Num());

		//mesh->CreateMeshSection_LinearColor(1, VerticesTransition, TrianglesTransition, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
		//mesh->SetMaterial(1, material);
	}
}*/

FVector VoxelMarchingCubesMesher::VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst)
{
	float mu;
	FVector P;

	if (FMath::Abs(Value - P1Val) < 0.00001)
		return P1;

	if (FMath::Abs(Value - P2Val) < 0.00001)
		return P2;

	if (FMath::Abs(P1Val - P2Val) < 0.00001)
		return P1;

	mu = (Value - P1Val) / (P2Val - P1Val);

	P.X = P1.X + mu * (P2.X - P1.X);
	P.Y = P1.Y + mu * (P2.Y - P1.Y);
	P.Z = P1.Z + mu * (P2.Z - P1.Z);

	normalInst.X = N1.X + mu * (N2.X - N1.X);
	normalInst.Y = N1.Y + mu * (N2.Y - N1.Y);
	normalInst.Z = N1.Z + mu * (N2.Z - N1.Z);

	return P;
}

FVector VoxelMarchingCubesMesher::VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value)
{
	float mu;
	FVector P;

	if (FMath::Abs(Value - P1Val) < 0.00001)
		return P1;

	if (FMath::Abs(Value - P2Val) < 0.00001)
		return P2;

	if (FMath::Abs(P1Val - P2Val) < 0.00001)
		return P1;

	mu = (Value - P1Val) / (P2Val - P1Val);

	P = P1 + mu * (P2 - P1);

	return P;
}

float VoxelMarchingCubesMesher::GetVoxelSize()
{
	return Radius / (float)Voxels;
}

float VoxelMarchingCubesMesher::GetVoxelSizeHalf()
{
	return Radius / (float)Voxels / 2.f;
}