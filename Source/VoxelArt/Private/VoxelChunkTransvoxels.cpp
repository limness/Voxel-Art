
// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelChunkTransvoxels.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Helpers/Transvoxels.h"
#include "DrawDebugHelpers.h"

#define NORMALS 2 //2
#define NORMAL 1 //1

namespace EVoxelDirectionRender
{
	enum Direction : uint8
	{
		MinimumX = 0x01,
		MaximumX = 0x02,
		MinimumY = 0x04,
		MaximumY = 0x08,
		MinimumZ = 0x10,
		MaximumZ = 0x20
	};
}

AVoxelChunkTransvoxels::AVoxelChunkTransvoxels(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	FString string = "Voxel_" + FString::FromInt(x_chunk) + "_" + FString::FromInt(y_chunk) + "_" + FString::FromInt(z_chunk);
	FName name = FName(*string);
	RootComponent = mesh = ObjectInitializer.CreateDefaultSubobject<UProceduralMeshComponent>(this, TEXT("RootComponent"));

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("BVox"));
	CollisionMesh->bDynamicObstacle = true;
	CollisionMesh->SetupAttachment(RootComponent);
}

void AVoxelChunkTransvoxels::BeginPlay()
{
	Super::BeginPlay();

	CollisionMesh->SetBoxExtent(FVector(radius, radius, radius));
}

void AVoxelChunkTransvoxels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (anim)
	{
		yPos += speed;

		infoGrid.Empty();
		Vertices.Empty();
		Triangles.Empty();
		Normals.Empty();
		TextureCoordinates.Empty();
		VertexColors.Empty();
		Grid.Empty();
		positionSide.Empty();
		TestVertices.Empty();

		GenerateNoise();
		GenerateVertexCube(false);
	}
}


void AVoxelChunkTransvoxels::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	infoGrid.Empty();
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	TextureCoordinates.Empty();
	VertexColors.Empty();
	Grid.Empty();
	positionSide.Empty();
	TestVertices.Empty();

	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(radius / 2.f, radius / 2.f, radius / 2.f), FColor::Blue, false, 35.f, 35.f, 20.f);

	GenerateNoise();
	GenerateVertexCube(false);
}

void AVoxelChunkTransvoxels::GenerateNoise()
{
	//positionSide.Init(FVector(0, 0, 0), (voxels + 1) * (voxels + 1) * (voxels + 1));
	//Grid.Init(-1.f, (voxels + 1) * (voxels + 1) * (voxels + 1));
	positionSide.Init(FVector(0, 0, 0), (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS));
	Grid.Init(-1.0, (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS));

	float radiusVoxel = GetVoxelSize();

	for (int z = 0; z < voxels + 1 + NORMALS; z++)
	{
		for (int y = 0; y < voxels + 1 + NORMALS; y++)
		{
			for (int x = 0; x < voxels + 1 + NORMALS; x++)
			{
			/*	FVector positionNoise;

				positionNoise.X = x * radiusVoxel;
				positionNoise.Y = y * radiusVoxel;
				positionNoise.Z = z * radiusVoxel;
				positionNoise = positionNoise;

				Grid[x + y * (voxels + 1) + z * (voxels + 1) * (voxels + 1)] = GetValueNoise(positionNoise);*/
				FVector positionNoise;

				positionNoise.X = (x - NORMAL) * radiusVoxel - 0;
				positionNoise.Y = (y - NORMAL) * radiusVoxel - 0;
				positionNoise.Z = (z - NORMAL) * radiusVoxel - 0;
				positionNoise = positionNoise - (float)(radius / 2.f);

				Grid[x + y * (voxels + 1 + NORMALS) + z * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)] = GetValueNoise(positionNoise); //shouldbeMIN
			}
		}
	}
}

float AVoxelChunkTransvoxels::GetValueNoise(FVector positionGrid)
{
	float noise = 0.f;

	positionGrid = positionGrid + GetActorLocation(); // GetActorLocation() + FVector(0.f, yPos, 0.f);
	//TestVertices.Add(positionGrid);

	float position_noise = USimplexNoiseBPLibrary::SimplexNoise3D(positionGrid.X * actave, positionGrid.Y * actave, positionGrid.Z * actave) * period;

	if (positionGrid.Z >= 0)
	{
		noise = (-1) * UKismetMathLibrary::FMax(1.f, positionGrid.Z); //shouldbeMIN
	}
	else if (positionGrid.Z < 0)
	{
		noise = (-1) * UKismetMathLibrary::FMin(-1.f, positionGrid.Z); //shouldbeMAX
	}

	if (position_noise >= 0.f)
	{
		//	position_noise = radius; //shouldbeMIN
	}
	else if (position_noise < 0.f)
	{
		//	position_noise = -radius; //shouldbeMIN
	}

	//UE_LOG(LogTemp, Warning, TEXT("noise %f"), noise);

	return position_noise + noise;
}

void AVoxelChunkTransvoxels::GenerateVertexCube(bool regenerate)
{
	float isolevel = 0.f;
	int normalIndex = 0;

	FVector firstPoint, lastPoint;

	float radiusVoxel = GetVoxelSize();

	/*for (int z = 0; z < voxels + 0; z++)
	{
		for (int y = 0; y < voxels + 0; y++)
		{
			for (int x = 0; x < voxels + 0; x++)
			{
				for (int i = 0; i < 8; i++)
				{

					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = !(i / 4);

					uint8 localMinimumX = (uint8)(((x + X == 0) ? 1 : 0) << 0);
					uint8 localMaximumX = (uint8)(((x + X == voxels - 0) ? 1 : 0) << 1);

					uint8 localMinimumY = (uint8)(((y + Y == 0) ? 1 : 0) << 2);
					uint8 localMaximumY = (uint8)(((y + Y == voxels - 0) ? 1 : 0) << 3);

					uint8 localMinimumZ = (uint8)(((z + Z == 0) ? 1 : 0) << 4);
					uint8 localMaximumZ = (uint8)(((z + Z == voxels - 0) ? 1 : 0) << 5);

					int MinimumX = (((transvoxelDirection & EVoxelDirectionRender::MinimumX) == EVoxelDirectionRender::MinimumX) ? 1 : 0) * ((x + X == 0) ? 1 : 0);
					int MaximumX = (((transvoxelDirection & EVoxelDirectionRender::MaximumX) == EVoxelDirectionRender::MaximumX) ? 1 : 0) * ((x + X == voxels - 0) ? 1 : 0);

					int MinimumY = (((transvoxelDirection & EVoxelDirectionRender::MinimumY) == EVoxelDirectionRender::MinimumY) ? 1 : 0) * ((y + Y == 0) ? 1 : 0);
					int MaximumY = (((transvoxelDirection & EVoxelDirectionRender::MaximumY) == EVoxelDirectionRender::MaximumY) ? 1 : 0) * ((y + Y == voxels - 0) ? 1 : 0);

					int MinimumZ = (((transvoxelDirection & EVoxelDirectionRender::MinimumZ) == EVoxelDirectionRender::MinimumZ) ? 1 : 0) * ((z + Z == 0) ? 1 : 0);
					int MaximumZ = (((transvoxelDirection & EVoxelDirectionRender::MaximumZ) == EVoxelDirectionRender::MaximumZ) ? 1 : 0) * ((z + Z == voxels - 0) ? 1 : 0);

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

					float transitionX = 1 * transitionSize * (X == 1 ? -MaximumX : MinimumX);
					float transitionY = 1 * transitionSize * (Y == 1 ? -MaximumY : MinimumY);
					float transitionZ = 1 * transitionSize * (Z == 1 ? -MaximumZ : MinimumZ);

					infoNoise[i] = Grid[(x + X + NORMAL) + (y + Y + NORMAL) * (voxels + 1 + NORMALS) + (z + Z + NORMAL) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)];
					position[i] = FVector((x + X + NORMAL + transitionX) * radiusVoxel, (y + Y + NORMAL + transitionY) * radiusVoxel, (z + Z + NORMAL + transitionZ) * radiusVoxel) - (float)(radius / 2.f);

					positionSide[(x + X + NORMAL) + (y + Y + NORMAL) * (voxels + 1 + NORMALS) + (z + Z + NORMAL) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)] = position[i];
				}

				MarchingCubes(isolevel, (x + NORMAL) + (y + NORMAL) * (voxels + 1 + NORMALS) + (z + NORMAL)* (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS), x + NORMAL, y + NORMAL, z + NORMAL, normalIndex);

				normalIndex++;
			}
		}
	}*/

	for (int z = NORMAL; z < voxels + NORMAL; z++)
	{
		for (int y = NORMAL; y < voxels + NORMAL; y++)
		{
			for (int x = NORMAL; x < voxels + NORMAL; x++)
			{
				for (int i = 0; i < 8; i++)
				{

					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = !(i / 4);

					uint8 localMinimumX = (uint8)(((x + X - NORMAL == 0) ? 1 : 0) << 0);
					uint8 localMaximumX = (uint8)(((x + X - NORMAL == voxels - 0) ? 1 : 0) << 1);

					uint8 localMinimumY = (uint8)(((y + Y - NORMAL == 0) ? 1 : 0) << 2);
					uint8 localMaximumY = (uint8)(((y + Y - NORMAL == voxels - 0) ? 1 : 0) << 3);

					uint8 localMinimumZ = (uint8)(((z + Z - NORMAL == 0) ? 1 : 0) << 4);
					uint8 localMaximumZ = (uint8)(((z + Z - NORMAL == voxels - 0) ? 1 : 0) << 5);

					int MinimumX = (((transvoxelDirection & EVoxelDirectionRender::MinimumX) == EVoxelDirectionRender::MinimumX) ? 1 : 0) * ((x + X - NORMAL == 0) ? 1 : 0);
					int MaximumX = (((transvoxelDirection & EVoxelDirectionRender::MaximumX) == EVoxelDirectionRender::MaximumX) ? 1 : 0) * ((x + X - NORMAL == voxels - 0) ? 1 : 0);

					int MinimumY = (((transvoxelDirection & EVoxelDirectionRender::MinimumY) == EVoxelDirectionRender::MinimumY) ? 1 : 0) * ((y + Y - NORMAL == 0) ? 1 : 0);
					int MaximumY = (((transvoxelDirection & EVoxelDirectionRender::MaximumY) == EVoxelDirectionRender::MaximumY) ? 1 : 0) * ((y + Y - NORMAL == voxels - 0) ? 1 : 0);

					int MinimumZ = (((transvoxelDirection & EVoxelDirectionRender::MinimumZ) == EVoxelDirectionRender::MinimumZ) ? 1 : 0) * ((z + Z - NORMAL == 0) ? 1 : 0);
					int MaximumZ = (((transvoxelDirection & EVoxelDirectionRender::MaximumZ) == EVoxelDirectionRender::MaximumZ) ? 1 : 0) * ((z + Z - NORMAL == voxels - 0) ? 1 : 0);

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

					float transitionX = transitionSize * (X == 1 ? -MaximumX : MinimumX);
					float transitionY = transitionSize * (Y == 1 ? -MaximumY : MinimumY);
					float transitionZ = transitionSize * (Z == 1 ? -MaximumZ : MinimumZ);

					infoNoise[i] = Grid[(x + X) + (y + Y) * (voxels + 1 + NORMALS) + (z + Z) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)];
					position[i] = FVector((x + X + transitionX - NORMAL) * radiusVoxel, (y + Y + transitionY - NORMAL) * radiusVoxel, (z + Z + transitionZ - NORMAL) * radiusVoxel) - (float)(radius / 2.f);

					positionSide[(x + X) + (y + Y) * (voxels + 1 + NORMALS) + (z + Z) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)] = position[i];

					//UE_LOG(LogTemp, Warning, TEXT("1 cornerPosition %d"), (x + X) + (y + Y) * (voxels + 1 + NORMALS) + (z + Z) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS));
				}

				MarchingCubes(isolevel, x + (voxels + 1 + NORMALS) * y + (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS) * z, x, y, z, normalIndex);

				normalIndex++;
			}
		}
	}
	if (transvoxel)
	{
		if ((transvoxelDirection & EVoxelDirectionRender::MinimumX) == EVoxelDirectionRender::MinimumX) GeometryTransitionCubes<EVoxelDirectionRender::MinimumX>();
		if ((transvoxelDirection & EVoxelDirectionRender::MaximumX) == EVoxelDirectionRender::MaximumX) GeometryTransitionCubes<EVoxelDirectionRender::MaximumX>();

		if ((transvoxelDirection & EVoxelDirectionRender::MinimumY) == EVoxelDirectionRender::MinimumY) GeometryTransitionCubes<EVoxelDirectionRender::MinimumY>();
		if ((transvoxelDirection & EVoxelDirectionRender::MaximumY) == EVoxelDirectionRender::MaximumY) GeometryTransitionCubes<EVoxelDirectionRender::MaximumY>();

		if ((transvoxelDirection & EVoxelDirectionRender::MinimumZ) == EVoxelDirectionRender::MinimumZ) GeometryTransitionCubes<EVoxelDirectionRender::MinimumZ>();
		if ((transvoxelDirection & EVoxelDirectionRender::MaximumZ) == EVoxelDirectionRender::MaximumZ) GeometryTransitionCubes<EVoxelDirectionRender::MaximumZ>();

		positionSide.Empty();
	}
	if (!regenerate)
	{
		mesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TextureCoordinates, VertexColors, TArray<FProcMeshTangent>(), true);
		mesh->SetMaterial(0, material);
	}
	else
	{
		UpdateMesh(Vertices, Triangles, Normals, VertexColors);
	}
}

void AVoxelChunkTransvoxels::MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex)
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

	FVector normalsSum = FVector(0, 0, 0);

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
	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3) numTriangles++;

	FVector* triPoints = new FVector[numTriangles * 3];
	FVector* normals = new FVector[numTriangles * 3];

	FLinearColor flatColor = GetColor(position[4] + GetVoxelSizeHalf());

	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
	{
		Vertices.Add(vertList[triTable[cubeIndex][i]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(-normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal());
		//VertexColors.Add(FLinearColor::Gray);

		Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(-normList[triTable[cubeIndex][i + 1]].GetUnsafeNormal());
		//VertexColors.Add(FLinearColor::Gray);

		Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(-normList[triTable[cubeIndex][i + 2]].GetUnsafeNormal());
		//VertexColors.Add(FLinearColor::Gray);
	}
}

template<uint8 Direction>
void AVoxelChunkTransvoxels::GeometryTransitionCubes()
{
	float radiusVoxel = GetVoxelSize();
	float radiusHalf = GetVoxelSizeHalf();

	float cornerNoise[13];

	for (int x = 0; x < voxels + 0; x++)
	{
		for (int y = 0; y < voxels + 0; y++)
		{
			cornerNoise[0] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // 0 - 9
			cornerNoise[1] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f));
			cornerNoise[2] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // 2 - A
			cornerNoise[3] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f));
			cornerNoise[4] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f));
			cornerNoise[5] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f));
			cornerNoise[6] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // 6 - B
			cornerNoise[7] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f));
			cornerNoise[8] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // 8 - C

			cornerNoise[9] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // 9
			cornerNoise[10] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // A
			cornerNoise[11] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // B
			cornerNoise[12] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f)); // C

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

				cornerPosition[0] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 0 - 9
				cornerPosition[1] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[2] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 2 - A
				cornerPosition[3] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[4] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[5] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[6] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 6 - B
				cornerPosition[7] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[8] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 8 - C

				for (int i = 9; i < 13; i++)
				{
					int X = (i - 1) % 2;
					int Y = (i - 1) % 4 / 2;

					cornerPosition[i] = positionSide[
						(int)(PositionToDirection<Direction>(FVector(x + X + NORMAL, y + Y + NORMAL, NORMAL), voxels + valueSize).X) +
						(int)(PositionToDirection<Direction>(FVector(x + X + NORMAL, y + Y + NORMAL, NORMAL), voxels + valueSize).Y) * (voxels + 1 + NORMALS) +
						(int)(PositionToDirection<Direction>(FVector(x + X + NORMAL, y + Y + NORMAL, NORMAL), voxels + valueSize).Z) * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)];


					//UE_LOG(LogTemp, Warning, TEXT("cornerPosition s %s"), *cornerPosition[i].ToString());
				}


				const uint8 cellClass = Transvoxels::transitionCellClass[caseValue];
				const uint16* vertexData = Transvoxels::transitionVertexData[caseValue];
				Transvoxels::TransitionCellData cellData = Transvoxels::transitionCellData[cellClass & 0x7F];

				bool convertTriangles = ((cellClass >> 7) == 0);

				TArray<FVector> VerticesTransition;
				TArray<int32> TrianglesTransition;

				for (int i = 0; i < cellData.GetTriangleCount() * 3; i++)
				{
					const uint16& edgeCode = vertexData[i];

					uint8 indexPointA = (edgeCode >> 4) & 0x0F;
					uint8 indexPointB = edgeCode & 0x0F;

					FVector positionA = cornerPosition[indexPointA];
					FVector positionB = cornerPosition[indexPointB];

					float valueA = cornerNoise[indexPointA];
					float valueB = cornerNoise[indexPointB];

					FVector P = VertexInterpTransition(positionA, positionB, valueA, valueB, 0.f);

					uint8 indexEdge = (edgeCode >> 8) & 0x0F;

					VerticesTransition.Add(P);
				}

				if (convertTriangles)
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
					}
				}
				else
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
					}
				}

				// Add our transition cells to global variable of data

				for (int a = 0; a < VerticesTransition.Num(); a++)
				{
					Vertices.Add(VerticesTransition[a]);
				}

				for (int b = 0; b < TrianglesTransition.Num(); b++)
				{
					Triangles.Add(TrianglesTransition[b]);
				}
			}
		}
	}
}

template<uint8 Direction>
FVector AVoxelChunkTransvoxels::PositionToDirection(FVector directionPosition, float size)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector(size - directionPosition.Z, directionPosition.Y, directionPosition.X); }		//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, size - directionPosition.Z, directionPosition.Y); }		//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, size - directionPosition.Z); }		//0x20

	return directionPosition;
}

template<uint8 Direction>
FVector AVoxelChunkTransvoxels::MaskSidesByDirection(FVector directionPosition)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector((voxels + 0) - directionPosition.Z, directionPosition.Y, directionPosition.X); }	//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, (voxels + 0) - directionPosition.Z, directionPosition.Y); }	//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, (voxels + 0) - directionPosition.Z); }	//0x20

	return directionPosition;
}

FLinearColor AVoxelChunkTransvoxels::GetColor(FVector positionVoxel)
{
	FLinearColor colorLandscape = grass; //grass
	float distance = (sqrt(pow(positionVoxel.X + GetActorLocation().X, 2) + pow(positionVoxel.Y + GetActorLocation().Y, 2) + pow(positionVoxel.Z + GetActorLocation().Z, 2)));

	if (distance > 0 && distance <= 1500)
	{
		colorLandscape = FLinearColor(0.690f, 0.690f, 0.690f); //rocks
	}
	else if (distance > 1500 && distance <= radiusSphere - radiusSphere / 5.f)
	{
		colorLandscape = ground; //ground
	}
	return colorLandscape;
}

FVector AVoxelChunkTransvoxels::GetGradient(int x, int y, int z)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((x + 1), (y + 0), (z + 0)) - GetDensity((x - 1), (y - 0), (z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((x + 0), (y + 1), (z + 0)) - GetDensity((x - 0), (y - 1), (z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((x + 0), (y + 0), (z + 1)) - GetDensity((x - 0), (y - 0), (z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

float AVoxelChunkTransvoxels::GetDensity(int x, int y, int z)
{
	return Grid[x + y * (voxels + 1 + NORMALS) + z * (voxels + 1 + NORMALS) * (voxels + 1 + NORMALS)];
}


int AVoxelChunkTransvoxels::GetVoxelId(int posX, int posY, int posZ)
{
	//int lengthZY = positionZ[0].positionY.Num();
	//int lengthZYX = positionZ[0].positionY[0].positionX.Num();

	return 0;//lengthZY * lengthZYX * posZ + lengthZYX * posY + posX;
}

void AVoxelChunkTransvoxels::UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols)
{
	mesh->ClearMeshSection(0);

	if (Vert.Num() > 0)
	{
		mesh->CreateMeshSection_LinearColor(0, Vert, Tri, Norm, TArray<FVector2D>(), Cols, TArray<FProcMeshTangent>(), true);
	}
}

FVector AVoxelChunkTransvoxels::VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst)
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

FVector AVoxelChunkTransvoxels::VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value)
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

float AVoxelChunkTransvoxels::GetVoxelSize()
{
	return radius / (float)voxels;
}

float AVoxelChunkTransvoxels::GetVoxelSizeHalf()
{
	return radius / (float)voxels / 2.f;
}
