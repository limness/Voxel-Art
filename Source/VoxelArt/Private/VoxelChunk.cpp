// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelChunk.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"

#include "DrawDebugHelpers.h"

AVoxelChunk::AVoxelChunk()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("RootComponent"));

	mesh->bCastShadowAsTwoSided = true;
	mesh->bUseAsyncCooking = true;
	mesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	mesh->Mobility = EComponentMobility::Movable;

//	mesh->SetupAttachment(RootComponent);
	//CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("BVox"));
	//CollisionMesh->bDynamicObstacle = true;
	//CollisionMesh->SetupAttachment(RootComponent);

	//meshTree = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	//StaticMesh. = static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));

//	SetActorEnableCollision(false);
}

void AVoxelChunk::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

	//CollisionMesh->SetBoxExtent(FVector(radius, radius, radius));
}

void AVoxelChunk::BeginDestroy()
{
	Super::BeginDestroy();

	//if (Task)
	//{
	//	Task->Cancel();
	//}
}

void AVoxelChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AVoxelChunk::IsActive() 
{
	return Active;
}

void AVoxelChunk::SetActive(bool activeStatus) 
{
	Active = activeStatus;
	if (!activeStatus)
	{
		mesh->ClearMeshSection(0);
	}
	SetActorHiddenInGame(!activeStatus);
}

void AVoxelChunk::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

/*
	UHierarchicalInstancedStaticMeshComponent* HierarchicalInstancedStaticMeshComponent = NewObject<UHierarchicalInstancedStaticMeshComponent>(this, NAME_None, RF_Transient);

	HierarchicalInstancedStaticMeshComponent->OnComponentCreated();
	HierarchicalInstancedStaticMeshComponent->RegisterComponent();*/
/*
	for (auto it : FolliageComponents)
	{
		it->SetStaticMesh(StaticMesh.Object);
	}*/
}

void AVoxelChunk::GenerateDensityAndCreateMeshAsync()
{
//	Task = new FAsyncTask<TerrainGenerationAsyncTask>(this);

//	Task->StartBackgroundTask();
}

#include "Noise/SimplexNoiseBPLibrary.h"
#include "Async/ParallelFor.h"

float AVoxelChunk::GetValueSpawner(FVector positionGrid)
{
	float noise = 0.f;

	//positionGrid += GetActorLocation();

	float value = 0.f;
	float frequency = 0.00003f;
	float amplitude = 8000.f;

	value = USimplexNoiseBPLibrary::SimplexNoise2D(positionGrid.X * frequency, positionGrid.Y * frequency) * amplitude;

	return value;
}

float AVoxelChunk::GetValueNoise(FVector positionGrid)
{
	float noise = 0.f;
	
	positionGrid += GetActorLocation();
	
/*	float value = 0.f;
	float frequency = 0.00003f;
	float amplitude = 8000.f;*/

	//value = USimplexNoiseBPLibrary::SimplexNoise3D(positionGrid.X * frequency, positionGrid.Y * frequency, positionGrid.Z * frequency) * amplitude;

	//value = radius - sqrt(positionGrid.X * positionGrid.X + positionGrid.Y * positionGrid.Y + positionGrid.Z * positionGrid.Z);
	/*float value = 0.f;
	float frequency = 0.00001f;
	float amplitude = 8000.f;

	for (int i = 0; i < 5; i++)
	{
		value += USimplexNoiseBPLibrary::SimplexNoise3D(positionGrid.X * frequency, positionGrid.Y * frequency, positionGrid.Z * frequency) * amplitude;
		frequency *= 3.75f;
		amplitude *= 0.25f;
	}

	noise = positionGrid.Z - value;*/

	//float hard_floor = (positionGrid.Z + 5000.f);
	//noise = hard_floor - USimplexNoiseBPLibrary::SimplexNoise2D(positionGrid.X * frequency, positionGrid.Y * frequency) * amplitude;

	//noise = FMath::Clamp(value, positionGrid.Z - 5000.f, positionGrid.Z + 5000.f);
	//noise = FMath::Clamp(value, 200000.f - (float)sqrt(positionGrid.X * positionGrid.X + positionGrid.Y * positionGrid.Y + positionGrid.Z * positionGrid.Z) - 5000.f,
	//							200000.f - (float)sqrt(positionGrid.X * positionGrid.X + positionGrid.Y * positionGrid.Y + positionGrid.Z * positionGrid.Z) + 5000.f);

	/*if (positionGrid.Z >= 0.f)
	{
		if (positionGrid.Z < 20000.f)
		{
			noise = -VoxelValueMin(-(-1) * UKismetMathLibrary::FMax(1.f, positionGrid.Z), -value, 3000.f);
		}
		else
		{
			noise = (-1) * UKismetMathLibrary::FMax(1.f, positionGrid.Z);
		}
	}
	else if (positionGrid.Z < 0.f)
	{
		noise = (-1) * UKismetMathLibrary::FMin(-1.f, positionGrid.Z);
	}*/

	//if (positionGrid.Z >= 0.f)
	{
	//	noise = (-1) * UKismetMathLibrary::FMax(1.f, positionGrid.Z + 9000.f);
	}
	//else if (positionGrid.Z < 0.f)
	{
	//	noise = (-1) * UKismetMathLibrary::FMin(-1.f, positionGrid.Z + 9000.f);
	}

	return  generatorLandscape->GetDensityMap(FVector(positionGrid.X, positionGrid.Y, positionGrid.Z));//-(positionGrid.Z + 5000.f);
}

void AVoxelChunk::GenerateDensityMap()
{
	FScopeLock Lock(&ChunkMutex);

	Grid.Empty();
	Grid.Init(-1.0, (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT));

	float radiusVoxel = GetVoxelSize();

	for (int z = 0; z < voxels + 1 + NORMALS_SKIRT; z++)
	{
		for (int y = 0; y < voxels + 1 + NORMALS_SKIRT; y++)
		{
			for (int x = 0; x < voxels + 1 + NORMALS_SKIRT; x++)
			{
				FVector positionNoise;

				positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise = positionNoise - (float)(radius / 2.f);

				Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = generatorLandscape->GetDensityMap(FVector(positionNoise.X, positionNoise.Y, positionNoise.Z) + GetActorLocation());//GetValueNoise(positionNoise);//-(positionNoise.Z - value);

			}
		}
	}
}

void AVoxelChunk::GenerateVertexCube(bool regenerate)
{
	FScopeLock Lock(&ChunkMutex);

	infoGrid.Empty();
	Vertices.Empty();
	Triangles.Empty();
	VerticesTransition.Empty();
	TrianglesTransition.Empty();
	Normals.Empty();
	TextureCoordinates.Empty();
	VertexColors.Empty();

	positionSide.Init(FVector(0, 0, 0), (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT));

	int isolevel = 0;
	int normalIndex = 0;

	float radiusVoxel = GetVoxelSize();

	FVector firstPoint, lastPoint;

	for (int z = NORMALS_SKIRT_HALF; z < voxels + NORMALS_SKIRT_HALF; z++)
	{
		for (int y = NORMALS_SKIRT_HALF; y < voxels + NORMALS_SKIRT_HALF; y++)
		{
			for (int x = NORMALS_SKIRT_HALF; x < voxels + NORMALS_SKIRT_HALF; x++)
			{
				for (int i = 0; i < 8; i++)
				{
					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = !(i / 4);

					uint8 localMinimumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 0);
					uint8 localMaximumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 1);

					uint8 localMinimumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 2);
					uint8 localMaximumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 3);

					uint8 localMinimumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 4);
					uint8 localMaximumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 5);

					int MinimumX = (((transvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumX = (((transvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					int MinimumY = (((transvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumY = (((transvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					int MinimumZ = (((transvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumZ = (((transvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] minx %d %d %d"), MinimumX, MinimumY, MinimumZ);

					if (((localMinimumX || localMaximumX) & (localMinimumY || localMaximumY)) |
						((localMinimumY || localMaximumY) & (localMinimumZ || localMaximumZ)) |
						((localMinimumZ || localMaximumZ) & (localMinimumX || localMaximumX)))
					{
						uint8 maskSidesVertex = (localMaximumX | localMinimumX) | (localMaximumY | localMinimumY) | (localMaximumZ | localMinimumZ);

						if ((transvoxelDirection & maskSidesVertex) == maskSidesVertex)
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
					
					infoNoise[i] = Grid[(x + X) + (y + Y) * (voxels + 1 + NORMALS_SKIRT) + (z + Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
					position[i] = FVector((x + X + transitionX - NORMALS_SKIRT_HALF) * radiusVoxel, (y + Y + transitionY - NORMALS_SKIRT_HALF) * radiusVoxel, (z + Z + transitionZ - NORMALS_SKIRT_HALF) * radiusVoxel) - (float)(radius / 2.f);

					positionSide[(x + X) + (y + Y) * (voxels + 1 + NORMALS_SKIRT) + (z + Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = position[i];
				}

				MarchingCubes(isolevel, x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT), x, y, z, normalIndex);

				normalIndex++;
			}
		}
	}

	//int timeBefore = FDateTime::Now().GetTicks();
	if (true)
	{
		if ((transvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) GeometryTransitionCubes<EVoxelDirection::MinimumX>(radius);
		if ((transvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) GeometryTransitionCubes<EVoxelDirection::MaximumX>(radius);

		if ((transvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) GeometryTransitionCubes<EVoxelDirection::MinimumY>(radius);
		if ((transvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) GeometryTransitionCubes<EVoxelDirection::MaximumY>(radius);

		if ((transvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) GeometryTransitionCubes<EVoxelDirection::MinimumZ>(radius);
		if ((transvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) GeometryTransitionCubes<EVoxelDirection::MaximumZ>(radius);
	}
	//int timeAfter = FDateTime::Now().GetTicks();

	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] Mesh transvoxels %d ms"), timeAfter - timeBefore);

	positionSide.Empty();

/*	AsyncTask(ENamedThreads::GameThread, [this]()
		{
			UpdateMesh(Vertices, Triangles, Normals, VertexColors);
		});*/
}

void AVoxelChunk::MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex)
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

	int numTriangles = 0;

	/*FLinearColor flatColor = generatorLandscape->GetColorMap(FVector(
		(position[4] + GetVoxelSizeHalf()).X, 
		(position[4] + GetVoxelSizeHalf()).Y,
		(position[4] + GetVoxelSizeHalf()).Z) + GetActorLocation());//generatorLandscape->GetColorsMap(positionNoise.X, positionNoise.Y, positionNoise.Z);//GetColor(position[4] + GetVoxelSizeHalf());
		*/
	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3) 
	{
		Vertices.Add(vertList[triTable[cubeIndex][i]]);
		Triangles.Add(Triangles.Num());
		//VertexColors.Add(flatColor);
		Normals.Add(-normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal());
		VertexColors.Add(generatorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 0]] + GetActorLocation()));

		Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
		Triangles.Add(Triangles.Num());
		//VertexColors.Add(flatColor);
		Normals.Add(-normList[triTable[cubeIndex][i + 1]].GetUnsafeNormal());
		VertexColors.Add(generatorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 1]] + GetActorLocation()));// - (1 * radius) / 2.0f));

		Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
		Triangles.Add(Triangles.Num());
		//VertexColors.Add(flatColor);
		VertexColors.Add(generatorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 2]] + GetActorLocation()));// - (1 * radius) / 2.0f));
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

					//DrawDebugBox(GetWorld(), GetActorLocation() + (
					//	vertList[triTable[cubeIndex][i + 0]] +
					//	vertList[triTable[cubeIndex][i + 1]] +
					//	vertList[triTable[cubeIndex][i + 2]]) / 3.f, FVector(40.f, 40.f, 320.f), FColor::Green, false, 33.f, 33.f, 92.f);
				}
			});*/
	}
}


template<uint8 Direction>
void AVoxelChunk::GeometryTransitionCubes(float radius)
{
	float radiusVoxel = GetVoxelSize();
	float radiusHalf = GetVoxelSizeHalf();

	float cornerNoise[13];

	for (int x = 0; x < voxels; x++)
	{
		for (int y = 0; y < voxels; y++)
		{
			cornerNoise[0] = GetValue<Direction>((x + 0), (y + 0), voxels, level / 2.f);		// 0 - 9
			cornerNoise[1] = GetValue<Direction>((x + 0.5f), (y + 0), voxels, level / 2.f);		// 1
			cornerNoise[2] = GetValue<Direction>((x + 1.f), (y + 0), voxels, level / 2.f);		// 2 - A
			cornerNoise[3] = GetValue<Direction>((x + 0), (y + 0.5f), voxels, level / 2.f);		// 3
			cornerNoise[4] = GetValue<Direction>((x + 0.5f), (y + 0.5f), voxels, level / 2.f);	// 4
			cornerNoise[5] = GetValue<Direction>((x + 1.f), (y + 0.5f), voxels, level / 2.f);	// 5
			cornerNoise[6] = GetValue<Direction>((x + 0), (y + 1.f), voxels, level / 2.f);		// 6 - B
			cornerNoise[7] = GetValue<Direction>((x + 0.5f), (y + 1.f), voxels, level / 2.f);	// 7
			cornerNoise[8] = GetValue<Direction>((x + 1.f), (y + 1.f), voxels, level / 2.f);	// 8 - C

			cornerNoise[9] = GetValue<Direction>((x + 0), (y + 0), voxels, level);				// 9
			cornerNoise[10] = GetValue<Direction>((x + 1.f), (y + 0), voxels, level);			// A
			cornerNoise[11] = GetValue<Direction>((x + 0), (y + 1.f), voxels, level);			// B
			cornerNoise[12] = GetValue<Direction>((x + 1.f), (y + 1.f), voxels, level);			// C

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
				normals[0] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[1] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[1] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[2] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 2 - A
				normals[2] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 0 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[3] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[3] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[4] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[4] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[5] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[5] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[6] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 6 - B
				normals[6] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[7] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				normals[7] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 0 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
				cornerPosition[8] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 8 - C
				normals[8] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + 1 + NORMALS_SKIRT_HALF, y + 1 + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));

				for (uint32 i = 9; i < 13; i++)
				{
					const int X = (i - 1) % 2;
					const int Y = (i - 1) % 4 / 2;

					cornerPosition[i] = positionSide[
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).X) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).Y) * (voxels + 1 + NORMALS_SKIRT) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];

					normals[i] = GetGradient((FIntVector)PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, 0 + NORMALS_SKIRT_HALF), voxels + 2));
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
					VertexColors.Add(GetColor(_VerticesTransition[a] + GetActorLocation())); //generatorLandscape->GetColorMap(_VerticesTransition[a] + GetActorLocation())
				}

				for (int j = 0; j < _NormalsTransition.Num(); j++)
				{
					Normals.Add(_NormalsTransition[j]);
				}

				for (int b = 0; b < _TrianglesTransition.Num(); b++)
				{
					Triangles.Add(_TrianglesTransition[b]);
				} 
			}
		}
	}
}
#include "Misc/ScopeTryLock.h"
template<uint8 Direction>
float AVoxelChunk::GetValue(float X, float Y, float size, int LOD)
{
	FVector GlobalPosition = PositionToDirection<Direction>(FVector(X, Y, 0), size);
	float value = 0.f;

	//if (FMath::Fmod(GlobalPosition.X, 1.f) == 0 && FMath::Fmod(GlobalPosition.Y, 1.f) == 0 && FMath::Fmod(GlobalPosition.Z, 1.f) == 0)
	if (LOD == level)
	{
		value = Grid[PositionToIndices(GlobalPosition)];
	}
	else
	{
		value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(radius / 2.f));
	}
	/*if (true) {}
	else
	{
		TWeakPtr<FVoxelOctreeData> chunkNeihbor = nullptr;

		if ((Direction >> 0) & 0x01 || (Direction >> 3) & 0x01 || (Direction >> 4) & 0x01)
		{
			chunkNeihbor = CurrentOctree.Pin()->GetNeighbor<Direction>((X / 0.5 >= voxels) + 2 * (Y / 0.5 >= voxels));
		}
		else
		{
			chunkNeihbor = CurrentOctree.Pin()->GetNeighbor<Direction>((Y / 0.5 >= voxels) + 2 * (X / 0.5 >= voxels));
		}
		if (chunkNeihbor.IsValid())
		{
			if (chunkNeihbor.Pin()->Chunk->DensityMap.Num() > 0)
			{
				FScopeTryLock ScopeTryLock(&chunkNeihbor.Pin()->chunk->ChunkMutex);
				if (ScopeTryLock.IsLocked())
				{
					GlobalPosition = FVector(
						GlobalPosition.X / 0.5 >= voxels ? GlobalPosition.X / 0.5 - voxels : GlobalPosition.X / 0.5,
						GlobalPosition.Y / 0.5 >= voxels ? GlobalPosition.Y / 0.5 - voxels : GlobalPosition.Y / 0.5,
						GlobalPosition.Z / 0.5 >= voxels ? GlobalPosition.Z / 0.5 - voxels : GlobalPosition.Z / 0.5
					);

					if ((Direction >> 0) & 0x01) { GlobalPosition.X = voxels; } //0x01
					if ((Direction >> 1) & 0x01) { GlobalPosition.X = 0.f; } //0x02
					if ((Direction >> 2) & 0x01) { GlobalPosition.Y = voxels; } //0x04
					if ((Direction >> 3) & 0x01) { GlobalPosition.Y = 0.f; } //0x08
					if ((Direction >> 4) & 0x01) { GlobalPosition.Z = voxels; } //0x10
					if ((Direction >> 5) & 0x01) { GlobalPosition.Z = 0.f; } //0x20

					value = chunkNeihbor.Pin()->chunk->GetDensity(PositionToIndices(GlobalPosition));
				}
				else
				{
					value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(radius / 2.f));
				}
			}
			else
			{
				value = GetValueNoise(GlobalPosition * GetVoxelSize() - (float)(radius / 2.f));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelChunk ] Error: neighbor empty"));
		}
	}*/
	return value;
}

FORCEINLINE int AVoxelChunk::PositionToIndices(FVector position)
{
	return ((int)position.X + NORMALS_SKIRT_HALF) +
			((int)position.Y + NORMALS_SKIRT_HALF) * (voxels + 1 + NORMALS_SKIRT) +
			((int)position.Z + NORMALS_SKIRT_HALF) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT);
}

template<uint8 Direction>
FVector AVoxelChunk::PositionToDirection(FVector directionPosition, float size)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector(size - directionPosition.Z, directionPosition.Y, directionPosition.X); }		//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, size - directionPosition.Z, directionPosition.Y); }		//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, size - directionPosition.Z); }		//0x20

	return directionPosition;
}

FLinearColor AVoxelChunk::GetColor(FVector positionVoxel)
{
	FLinearColor colorLandscape = grass; //grass
	float distance = GetValueSpawner(positionVoxel);//(sqrt(pow(positionVoxel.X + GetActorLocation().X, 2) + pow(positionVoxel.Y + GetActorLocation().Y, 2) + pow(positionVoxel.Z + GetActorLocation().Z, 2)));

	if (distance > 0 && distance <= 1500)
	{
		colorLandscape = FColor::Red;//FLinearColor(0.690f, 0.690f, 0.690f); //rocks
	}
	else if (distance > 1500 && distance <= radiusSphere - radiusSphere / 5.f)
	{
		colorLandscape = FColor::Blue; //ground
	}
	return FLinearColor(positionVoxel.GetUnsafeNormal());
}

FVector AVoxelChunk::GetGradient(int x, int y, int z)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((x + 1), (y + 0), (z + 0)) - GetDensity((x - 1), (y - 0), (z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((x + 0), (y + 1), (z + 0)) - GetDensity((x - 0), (y - 1), (z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((x + 0), (y + 0), (z + 1)) - GetDensity((x - 0), (y - 0), (z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

FVector AVoxelChunk::GetGradient(FIntVector map)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((map.X + 1), (map.Y + 0), (map.Z + 0)) - GetDensity((map.X - 1), (map.Y - 0), (map.Z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((map.X + 0), (map.Y + 1), (map.Z + 0)) - GetDensity((map.X - 0), (map.Y - 1), (map.Z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((map.X + 0), (map.Y + 0), (map.Z + 1)) - GetDensity((map.X - 0), (map.Y - 0), (map.Z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

bool AVoxelChunk::ChangeVoxel(UVoxelModificationLandscape* modificator, 
	FVector positionCenterPoint, 
	float range, 
	float strength,
	bool smooth,
	bool dig,
	float smoothInsert)
{
	//float strength = 0.5f;
	//bool smooth = true;
	//bool dig = true;
	//float range = 800.f;

	float radiusVoxel = GetVoxelSize();

	for (int z = 0; z < voxels + 1 + NORMALS_SKIRT; z++)
	{
		for (int y = 0; y < voxels + 1 + NORMALS_SKIRT; y++)
		{
			for (int x = 0; x < voxels + 1 + NORMALS_SKIRT; x++)
			{
				FVector positionNoise;

				positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
				positionNoise = positionNoise - (float)(radius / 2.f);

				positionNoise += GetActorLocation() - positionCenterPoint;
				//positionNoise += GetActorLocation() - chunkCenter->GetActorLocation();
				//positionNoise -= voxelCenter;

				float calculateRadius = range - sqrt(pow(positionNoise.X, 2) + pow(positionNoise.Y, 2) + pow(positionNoise.Z, 2));

				//float calculateRadius = 0.f;
				//modificator->GetPainterData(positionNoise.X, positionNoise.Y, positionNoise.Z, calculateRadius, strength, dig, smooth);

				float volume = dig ? -1.f : 1.f;

				if (volume < 0)
				{
					if (smooth)
					{
						if (UKismetMathLibrary::FMin(-1.f, calculateRadius * volume) != -1.f)
						{
							Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] += UKismetMathLibrary::FMin(-1.f, calculateRadius * volume) * strength;
							hasOwnGrid = true;
						}
					}
					else
					{
						//if (sqrt(pow(positionNoise.X, 2) + pow(positionNoise.Y, 2) + pow(positionNoise.Z, 2)) <= range + GetVoxelSize()) // + GetVoxelSize()
						{
							Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = VoxelValueMin(Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)], calculateRadius * volume, smoothInsert);//calculateRadius
							hasOwnGrid = true;
						}
					}
				}
				else
				{
					if (smooth)
					{
						if (UKismetMathLibrary::FMax(1.f, calculateRadius * volume) != 1.f)
						{
							Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] += UKismetMathLibrary::FMax(1.f, calculateRadius * volume) * strength;
							hasOwnGrid = true;
						}
					}
					else
					{
						//if (sqrt(pow(positionNoise.X, 2) + pow(positionNoise.Y, 2) + pow(positionNoise.Z, 2)) <= range + GetVoxelSize()) // + GetVoxelSize()
						{
							Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = -VoxelValueMin(-Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)], -calculateRadius * volume, smoothInsert); //calculateRadius
							hasOwnGrid = true;
						}
					}
				}
			}
		}
	}
	return true;
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float AVoxelChunk::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

void AVoxelChunk::UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols)
{
	//Remove default grid
	mesh->ClearMeshSection(0);
	
	//Remove transition grid
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
		//TArray<FVector>()
		mesh->CreateMeshSection_LinearColor(0, Vert, Tri, Norm, TArray<FVector2D>(), Cols, TArray<FProcMeshTangent>(), true);
		mesh->SetMaterial(0, material);
	}
	if (VerticesTransition.Num() > 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelChunk ] create transit %d %d"), VerticesTransition.Num(), TrianglesTransition.Num());

		//mesh->CreateMeshSection_LinearColor(1, VerticesTransition, TrianglesTransition, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
		//mesh->SetMaterial(1, material);
	}
}

FVector AVoxelChunk::VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst)
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

FVector AVoxelChunk::VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value)
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

float AVoxelChunk::GetVoxelSize()
{
	return radius / (float)voxels;
}

float AVoxelChunk::GetVoxelSizeHalf()
{
	return radius / (float)voxels / 2.f;
}