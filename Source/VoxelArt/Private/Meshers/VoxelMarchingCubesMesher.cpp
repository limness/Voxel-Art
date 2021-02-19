// Fill out your copyright notice in the Description page of Project Settings.


#include "Meshers/VoxelMarchingCubesMesher.h"
#include "VoxelLandscape.h"
#include "Helpers/MarchingCubes.h"

FVoxelMarchingCubesMesher::FVoxelMarchingCubesMesher(AVoxelLandscape* _World, FVoxelChunkData* _Data)
	: World(_World)
	, GeneratorLandscape(_World->GeneratorLandscape)
	, Voxels(_Data->Voxels)
	, Size(_Data->Size)
	, Position(_Data->Position)
	, TransitionSides(_Data->TransitionSides)
	, DensityMap(_Data->DensityMap)
{
}

FVoxelMarchingCubesMesher::~FVoxelMarchingCubesMesher()
{
}


//Voxels << Depth = Size World

#include "DrawDebugHelpers.h"

void FVoxelMarchingCubesMesher::GenerateMarchingCubesMesh()
{
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	TextureCoordinates.Empty();
	VertexColors.Empty();

	positionSide.Init(FVector(0, 0, 0), (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS));

	int normalIndex = 0;

	int VoxelSize = (Size / Voxels) * World->VoxelMin;//World->VoxelMin * (1 << (World->MaximumLOD - Depth));//GetVoxelSize();
	//int SizeVoxel = (1 << (World->MaximumLOD - Depth));

	FVector firstPoint, lastPoint;

	for (int z = NORMAL; z < Voxels + NORMAL; z++)
	{
		for (int y = NORMAL; y < Voxels + NORMAL; y++)
		{
			for (int x = NORMAL; x < Voxels + NORMAL; x++)
			{
				for (int i = 0; i < 8; i++)
				{
					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = (i / 4);

					uint8 localMinimumX = (uint8)((x + X - NORMAL == 0) << 0);
					uint8 localMaximumX = (uint8)((x + X - NORMAL == Voxels - 0) << 1);

					uint8 localMinimumY = (uint8)((y + Y - NORMAL == 0) << 2);
					uint8 localMaximumY = (uint8)((y + Y - NORMAL == Voxels - 0) << 3);

					uint8 localMinimumZ = (uint8)((z + Z - NORMAL == 0) << 4);
					uint8 localMaximumZ = (uint8)((z + Z - NORMAL == Voxels - 0) << 5);

					int MinimumX = ((TransitionSides & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) * (x + X - NORMAL == 0);
					int MaximumX = ((TransitionSides & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) * (x + X - NORMAL == Voxels - 0);

					int MinimumY = ((TransitionSides & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) * (y + Y - NORMAL == 0);
					int MaximumY = ((TransitionSides & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) * (y + Y - NORMAL == Voxels - 0);

					int MinimumZ = ((TransitionSides & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) * (z + Z - NORMAL == 0);
					int MaximumZ = ((TransitionSides & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) * (z + Z - NORMAL == Voxels - 0);

					if (((localMinimumX || localMaximumX) & (localMinimumY || localMaximumY)) |
						((localMinimumY || localMaximumY) & (localMinimumZ || localMaximumZ)) |
						((localMinimumZ || localMaximumZ) & (localMinimumX || localMaximumX)))
					{
						uint8 maskSidesVertex = (localMaximumX | localMinimumX) | (localMaximumY | localMinimumY) | (localMaximumZ | localMinimumZ);

						if ((TransitionSides & maskSidesVertex) != maskSidesVertex)
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
					
					FVector PositionGrid = FVector(x + X + transitionX, y + Y + transitionY, z + Z + transitionZ) - NORMAL;
					PositionGrid = PositionGrid - World->VoxelsPerChunk / 2;
					PositionGrid = PositionGrid * VoxelSize;

					infoNoise[i] = DensityMap[(x + X) + (y + Y) * (Voxels + 1 + NORMALS) + (z + Z) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
					position[i] = PositionGrid;

					positionSide[(x + X) + (y + Y) * (Voxels + 1 + NORMALS) + (z + Z) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)] = position[i];
				}

				MarchingCubes(x + y * (Voxels + 1 + NORMALS) + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS), x, y, z, normalIndex);

				normalIndex++;
			}
		}
	}
	if ((TransitionSides & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) GeometryTransitionCubes<EVoxelDirection::MinimumX>(Size);
	if ((TransitionSides & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) GeometryTransitionCubes<EVoxelDirection::MaximumX>(Size);
	if ((TransitionSides & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) GeometryTransitionCubes<EVoxelDirection::MinimumY>(Size);
	if ((TransitionSides & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) GeometryTransitionCubes<EVoxelDirection::MaximumY>(Size);
	if ((TransitionSides & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) GeometryTransitionCubes<EVoxelDirection::MinimumZ>(Size);
	if ((TransitionSides & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) GeometryTransitionCubes<EVoxelDirection::MaximumZ>(Size);

	positionSide.Empty();
}

void FVoxelMarchingCubesMesher::MarchingCubes(int indexGrid, int x, int y, int z, int normalIndex)
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
	FVector PositionGameWorld = World->TransferToGameWorld(Position);

	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
	{
		Vertices.Add(vertList[triTable[cubeIndex][i]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(normList[triTable[cubeIndex][i + 0]].GetSafeNormal());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 0]] + PositionGameWorld));

		Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
		Triangles.Add(Triangles.Num());
		Normals.Add(normList[triTable[cubeIndex][i + 1]].GetSafeNormal());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 1]] + PositionGameWorld));

		Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
		Triangles.Add(Triangles.Num());
		VertexColors.Add(GeneratorLandscape->GetColorMap(vertList[triTable[cubeIndex][i + 2]] + PositionGameWorld));
		Normals.Add(normList[triTable[cubeIndex][i + 2]].GetSafeNormal());
	}
}


template<uint8 Direction>
void FVoxelMarchingCubesMesher::GeometryTransitionCubes(float radius)
{
	float radiusVoxel = GetVoxelSize();
	float radiusHalf = GetVoxelSizeHalf();

	FVector PositionGameWorld = World->TransferToGameWorld(Position);

	float cornerNoise[13];

	int VoxelSteps = (Size / Voxels);

	for (int x = 0; x < Voxels; x++)
	{
		for (int y = 0; y < Voxels; y++)
		{
			cornerNoise[0] = GetValue<Direction>(x * 2 + 0, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 0 - 9
			cornerNoise[1] = GetValue<Direction>(x * 2 + 1, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 1
			cornerNoise[2] = GetValue<Direction>(x * 2 + 2, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 2 - A
			cornerNoise[3] = GetValue<Direction>(x * 2 + 0, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 3
			cornerNoise[4] = GetValue<Direction>(x * 2 + 1, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 4
			cornerNoise[5] = GetValue<Direction>(x * 2 + 2, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 5
			cornerNoise[6] = GetValue<Direction>(x * 2 + 0, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 6 - B
			cornerNoise[7] = GetValue<Direction>(x * 2 + 1, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 7
			cornerNoise[8] = GetValue<Direction>(x * 2 + 2, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 8 - C

			cornerNoise[9] =  GetValue<Direction>(x + 0, y + 0, Voxels + 0, VoxelSteps, true);	// 9
			cornerNoise[10] = GetValue<Direction>(x + 1, y + 0, Voxels + 0, VoxelSteps, true);	// A
			cornerNoise[11] = GetValue<Direction>(x + 0, y + 1, Voxels + 0, VoxelSteps, true);	// B
			cornerNoise[12] = GetValue<Direction>(x + 1, y + 1, Voxels + 0, VoxelSteps, true);	// C

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

				cornerPosition[0] = GetPosition<Direction>(x * 2 + 0, y * 2 + 0, Size, VoxelSteps >> 1);	// 0 - 9
				cornerPosition[1] = GetPosition<Direction>(x * 2 + 1, y * 2 + 0, Size, VoxelSteps >> 1);	// 1
				cornerPosition[2] = GetPosition<Direction>(x * 2 + 2, y * 2 + 0, Size, VoxelSteps >> 1);	// 2 - A
				cornerPosition[3] = GetPosition<Direction>(x * 2 + 0, y * 2 + 1, Size, VoxelSteps >> 1);	// 3
				cornerPosition[4] = GetPosition<Direction>(x * 2 + 1, y * 2 + 1, Size, VoxelSteps >> 1);	// 4
				cornerPosition[5] = GetPosition<Direction>(x * 2 + 2, y * 2 + 1, Size, VoxelSteps >> 1);	// 5
				cornerPosition[6] = GetPosition<Direction>(x * 2 + 0, y * 2 + 2, Size, VoxelSteps >> 1);	// 6 - B
				cornerPosition[7] = GetPosition<Direction>(x * 2 + 1, y * 2 + 2, Size, VoxelSteps >> 1);	// 7
				cornerPosition[8] = GetPosition<Direction>(x * 2 + 2, y * 2 + 2, Size, VoxelSteps >> 1);	// 8 - C

				normals[0] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[1] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[2] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[3] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[4] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[5] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[6] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[7] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				normals[8] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));

				for (uint32 i = 9; i < 13; i++)
				{
					const int X = (i - 1) % 2;
					const int Y = (i - 1) % 4 / 2;

					FIntVector P = TransferToDirection<Direction>(FIntVector(x + X + NORMAL, y + Y + NORMAL, NORMAL), Voxels + 2);
					cornerPosition[i] = positionSide[P.X + P.Y * (Voxels + 1 + NORMALS) + P.Z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];
					normals[i] = GetGradient(TransferToDirection<Direction>(FIntVector(x + X + NORMAL, y + Y + NORMAL, 0 + NORMAL), Voxels + 2));
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

					_NormalsTransition.Add(N.GetSafeNormal());
					_VerticesTransition.Add(P);
				}

				if (convertTriangles)
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
					}
				}
				else
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						_TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
					}
				}

				/*Add our transition cells to global variable of data*/

				for (int a = 0; a < _VerticesTransition.Num(); a++)
				{
					Vertices.Add(_VerticesTransition[a]);
					VertexColors.Add(GeneratorLandscape->GetColorMap(_VerticesTransition[a] + PositionGameWorld));
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

template<uint8 Direction>
float FVoxelMarchingCubesMesher::GetValue(int X, int Y, int Size, int Steps, bool CurrentOctree)
{
	float Value = 0.f;

	if(CurrentOctree)
	{
		FIntVector LocalPosition = TransferToDirection<Direction>(FIntVector(X, Y, 0), Size);

		Value = DensityMap[PositionToIndices(LocalPosition)];
	}
	else
	{
		FIntVector GlobalPosition = TransferToDirection<Direction>(FIntVector(X, Y, 0) * Steps, Size) - FIntVector(1, 1, 1) * (Size >> 1) + Position;

		World->GetVoxelValue(GlobalPosition, Value);
	}
	return Value;
}

template<uint8 Direction>
FVector FVoxelMarchingCubesMesher::GetPosition(int X, int Y, int Size, int Steps)
{
	FIntVector GlobalPosition = TransferToDirection<Direction>(FIntVector(X * Steps, Y * Steps, 0), Size) - FIntVector(1, 1, 1) * (Size >> 1);

	return World->TransferToGameWorld(GlobalPosition);
}

FORCEINLINE int FVoxelMarchingCubesMesher::PositionToIndices(FIntVector Position)
{
	return 
		(Position.X + NORMAL) +
		(Position.Y + NORMAL) * (Voxels + 1 + NORMALS) +
		(Position.Z + NORMAL) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS);
}

template<uint8 Direction>
FIntVector FVoxelMarchingCubesMesher::TransferToDirection(FIntVector DirectionPosition, float Size)
{
	if ((Direction >> 0) & 0x01) { DirectionPosition = FIntVector(DirectionPosition.Z, DirectionPosition.X, DirectionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { DirectionPosition = FIntVector(Size - DirectionPosition.Z, DirectionPosition.Y, DirectionPosition.X); }	//0x02
	if ((Direction >> 2) & 0x01) { DirectionPosition = FIntVector(DirectionPosition.Y, DirectionPosition.Z, DirectionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { DirectionPosition = FIntVector(DirectionPosition.X, Size - DirectionPosition.Z, DirectionPosition.Y); }	//0x08
	if ((Direction >> 4) & 0x01) { DirectionPosition = FIntVector(DirectionPosition.X, DirectionPosition.Y, DirectionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { DirectionPosition = FIntVector(DirectionPosition.Y, DirectionPosition.X, Size - DirectionPosition.Z); }	//0x20

	return DirectionPosition;
}

FVector FVoxelMarchingCubesMesher::GetGradient(int x, int y, int z)
{
	float d = 0.01f;

	FVector average_normal;

	average_normal.X = (GetDensity(x + 1, y + 0, z + 0) - GetDensity(x - 1, y - 0, z - 0)) / 2 / d;
	average_normal.Y = (GetDensity(x + 0, y + 1, z + 0) - GetDensity(x - 0, y - 1, z - 0)) / 2 / d;
	average_normal.Z = (GetDensity(x + 0, y + 0, z + 1) - GetDensity(x - 0, y - 0, z - 1)) / 2 / d;

	return average_normal;
}

FVector FVoxelMarchingCubesMesher::GetGradient(FIntVector map)
{
	float d = 0.01f;

	FVector average_normal;

	average_normal.X = (GetDensity((map.X + 1), (map.Y + 0), (map.Z + 0)) - GetDensity((map.X - 1), (map.Y - 0), (map.Z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((map.X + 0), (map.Y + 1), (map.Z + 0)) - GetDensity((map.X - 0), (map.Y - 1), (map.Z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((map.X + 0), (map.Y + 0), (map.Z + 1)) - GetDensity((map.X - 0), (map.Y - 0), (map.Z - 1))) / 2 / d;

	return average_normal;
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float FVoxelMarchingCubesMesher::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

FVector FVoxelMarchingCubesMesher::VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst)
{
	float mu;
	FVector P;

	if (FMath::Abs(isolevel - P1Val) < 0.00001)
		return P1;

	if (FMath::Abs(isolevel - P2Val) < 0.00001)
		return P2;

	if (FMath::Abs(P1Val - P2Val) < 0.00001)
		return P1;

	mu = (isolevel - P1Val) / (P2Val - P1Val);

	P.X = P1.X + mu * (P2.X - P1.X);
	P.Y = P1.Y + mu * (P2.Y - P1.Y);
	P.Z = P1.Z + mu * (P2.Z - P1.Z);

	normalInst.X = N1.X + mu * (N2.X - N1.X);
	normalInst.Y = N1.Y + mu * (N2.Y - N1.Y);
	normalInst.Z = N1.Z + mu * (N2.Z - N1.Z);

	return P;
}

FVector FVoxelMarchingCubesMesher::VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value)
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

float FVoxelMarchingCubesMesher::GetVoxelSize()
{
	return Size / (float)Voxels;
}

float FVoxelMarchingCubesMesher::GetVoxelSizeHalf()
{
	return Size / (float)Voxels / 2.f;
}