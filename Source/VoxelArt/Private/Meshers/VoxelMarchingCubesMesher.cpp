// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Meshers/VoxelMarchingCubesMesher.h"
#include "Helpers/MarchingCubes.h"
#include "Helpers/Transvoxels.h"


FVoxelMarchingCubesMesher::FVoxelMarchingCubesMesher(AVoxelWorld* _World, FVoxelChunkData* _Data)
	: FVoxelDefaultMesher(_World, _Data)
	, TransitionSides(_Data->TransitionSides)
{
}

void FVoxelMarchingCubesMesher::GenerateMesh()
{
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	TextureCoordinates.Empty();
	VertexColors.Empty();

	positionSide.Init(FVector(0, 0, 0), (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS));

	FVector firstPoint, lastPoint;

	for (int z = NORMAL; z < Voxels + NORMAL; z++)
	{
		for (int y = NORMAL; y < Voxels + NORMAL; y++)
		{
			for (int x = NORMAL; x < Voxels + NORMAL; x++)
			{
				for (int i = 0; i < 8; i++)
				{
					int X = (i + 1) % 4 / 2;
					int Y = i % 4 / 2;
					int Z = (i / 4);

					uint8 localMinimumX = (uint8)((x + X - NORMAL == 0) << 0);
					uint8 localMinimumY = (uint8)((y + Y - NORMAL == 0) << 2);
					uint8 localMinimumZ = (uint8)((z + Z - NORMAL == 0) << 4);

					uint8 localMaximumY = (uint8)((y + Y - NORMAL == Voxels - 0) << 3);
					uint8 localMaximumX = (uint8)((x + X - NORMAL == Voxels - 0) << 1);
					uint8 localMaximumZ = (uint8)((z + Z - NORMAL == Voxels - 0) << 5);

					int MinimumX = ((TransitionSides & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) * (x + X - NORMAL == 0);
					int MinimumY = ((TransitionSides & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) * (y + Y - NORMAL == 0);
					int MinimumZ = ((TransitionSides & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) * (z + Z - NORMAL == 0);

					int MaximumX = ((TransitionSides & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) * (x + X - NORMAL == Voxels - 0);
					int MaximumY = ((TransitionSides & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) * (y + Y - NORMAL == Voxels - 0);
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
					PositionGrid = PositionGrid * VoxelSteps * World->VoxelMin;

					PositionInfo[i] = PositionGrid;
					NormalsInfo[i] = World->NormalsType == ENormalsType::Smoothed ? GetGradient(x + X, y + Y, z + Z) : FVector::ZeroVector;
					DensityInfo[i] = DensityMap[World->GetIndex(FIntVector(x + X, y + Y, z + Z))];
					ColorInfo[i] = ColorMap[World->GetIndex(FIntVector(x + X, y + Y, z + Z))];

					positionSide[(x + X) + (y + Y) * (Voxels + 1 + NORMALS) + (z + Z) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)] = PositionInfo[i];
				}

				MarchingCubes(x, y, z);
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

void FVoxelMarchingCubesMesher::MarchingCubes(int X, int Y, int Z)
{
	int cubeIndex = 0;

	FVector vertList[12];
	FVector normList[12];
	FColor colList[12];

	if (DensityInfo[0] < isolevel) cubeIndex |= 1;
	if (DensityInfo[1] < isolevel) cubeIndex |= 2;
	if (DensityInfo[2] < isolevel) cubeIndex |= 4;
	if (DensityInfo[3] < isolevel) cubeIndex |= 8;
	if (DensityInfo[4] < isolevel) cubeIndex |= 16;
	if (DensityInfo[5] < isolevel) cubeIndex |= 32;
	if (DensityInfo[6] < isolevel) cubeIndex |= 64;
	if (DensityInfo[7] < isolevel) cubeIndex |= 128;

	if (edgeTable[cubeIndex] == 0) return;

	if (edgeTable[cubeIndex] & 1)
	{
		ValueInterp(PositionInfo[0], PositionInfo[1], NormalsInfo[0], NormalsInfo[1], DensityInfo[0], DensityInfo[1], ColorInfo[0], ColorInfo[1], vertList[0], normList[0], colList[0]);
	}
	if (edgeTable[cubeIndex] & 2)
	{
		ValueInterp(PositionInfo[1], PositionInfo[2], NormalsInfo[1], NormalsInfo[2], DensityInfo[1], DensityInfo[2], ColorInfo[1], ColorInfo[2], vertList[1], normList[1], colList[1]);
	}
	if (edgeTable[cubeIndex] & 4)
	{
		ValueInterp(PositionInfo[2], PositionInfo[3], NormalsInfo[2], NormalsInfo[3], DensityInfo[2], DensityInfo[3], ColorInfo[2], ColorInfo[3], vertList[2], normList[2], colList[2]);
	}
	if (edgeTable[cubeIndex] & 8)
	{
		ValueInterp(PositionInfo[3], PositionInfo[0], NormalsInfo[3], NormalsInfo[0], DensityInfo[3], DensityInfo[0], ColorInfo[3], ColorInfo[0], vertList[3], normList[3], colList[3]);
	}
	if (edgeTable[cubeIndex] & 16)
	{
		ValueInterp(PositionInfo[4], PositionInfo[5], NormalsInfo[4], NormalsInfo[5], DensityInfo[4], DensityInfo[5], ColorInfo[4], ColorInfo[5], vertList[4], normList[4], colList[4]);
	}
	if (edgeTable[cubeIndex] & 32)
	{
		ValueInterp(PositionInfo[5], PositionInfo[6], NormalsInfo[5], NormalsInfo[6], DensityInfo[5], DensityInfo[6], ColorInfo[5], ColorInfo[6], vertList[5], normList[5], colList[5]);
	}
	if (edgeTable[cubeIndex] & 64)
	{
		ValueInterp(PositionInfo[6], PositionInfo[7], NormalsInfo[6], NormalsInfo[7], DensityInfo[6], DensityInfo[7], ColorInfo[6], ColorInfo[7], vertList[6], normList[6], colList[6]);
	}
	if (edgeTable[cubeIndex] & 128)
	{
		ValueInterp(PositionInfo[7], PositionInfo[4], NormalsInfo[7], NormalsInfo[4], DensityInfo[7], DensityInfo[4], ColorInfo[7], ColorInfo[4], vertList[7], normList[7], colList[7]);
	}
	if (edgeTable[cubeIndex] & 256)
	{
		ValueInterp(PositionInfo[0], PositionInfo[4], NormalsInfo[0], NormalsInfo[4], DensityInfo[0], DensityInfo[4], ColorInfo[0], ColorInfo[4], vertList[8], normList[8], colList[8]);
	}
	if (edgeTable[cubeIndex] & 512)
	{
		ValueInterp(PositionInfo[1], PositionInfo[5], NormalsInfo[1], NormalsInfo[5], DensityInfo[1], DensityInfo[5], ColorInfo[1], ColorInfo[5], vertList[9], normList[9], colList[9]);
	}
	if (edgeTable[cubeIndex] & 1024)
	{
		ValueInterp(PositionInfo[2], PositionInfo[6], NormalsInfo[2], NormalsInfo[6], DensityInfo[2], DensityInfo[6], ColorInfo[2], ColorInfo[6], vertList[10], normList[10], colList[10]);
	}
	if (edgeTable[cubeIndex] & 2048)
	{
		ValueInterp(PositionInfo[3], PositionInfo[7], NormalsInfo[3], NormalsInfo[7], DensityInfo[3], DensityInfo[7], ColorInfo[3], ColorInfo[7], vertList[11], normList[11], colList[11]);
	}
	//
	{
		for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
		{
			Vertices.Add(vertList[triTable[cubeIndex][i]]);
			Triangles.Add(Triangles.Num());

			Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
			Triangles.Add(Triangles.Num());

			Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
			Triangles.Add(Triangles.Num());
		}
	}
	if (World->NormalsType == ENormalsType::Smoothed)
	{
		for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
		{
			Normals.Add(normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal());
			Normals.Add(normList[triTable[cubeIndex][i + 1]].GetUnsafeNormal());
			Normals.Add(normList[triTable[cubeIndex][i + 2]].GetUnsafeNormal());
		}
	}
	if (World->ColorsType == EColorsType::OwnColors)
	{
		for (int i = 0; triTable[cubeIndex][i] != -1; i += 3)
		{
			VertexColors.Add(colList[triTable[cubeIndex][i + 0]]);
			VertexColors.Add(colList[triTable[cubeIndex][i + 1]]);
			VertexColors.Add(colList[triTable[cubeIndex][i + 2]]);
		}
	}
}


template<uint8 Direction>
void FVoxelMarchingCubesMesher::GeometryTransitionCubes(float radius)
{
	FColor CornerColor[13];
	float CornerNoise[13];

	FVoxelOctreeDensity* OutOctant = nullptr;

	for (int x = 0; x < Voxels; x++)
	{
		for (int y = 0; y < Voxels; y++)
		{
			CornerNoise[0] = GetValue<Direction>(OutOctant, CornerColor[0], x * 2 + 0, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 0 - 9
			CornerNoise[1] = GetValue<Direction>(OutOctant, CornerColor[1], x * 2 + 1, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 1
			CornerNoise[2] = GetValue<Direction>(OutOctant, CornerColor[2], x * 2 + 2, y * 2 + 0, Size, VoxelSteps >> 1, false);	// 2 - A
			CornerNoise[3] = GetValue<Direction>(OutOctant, CornerColor[3], x * 2 + 0, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 3
			CornerNoise[4] = GetValue<Direction>(OutOctant, CornerColor[4], x * 2 + 1, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 4
			CornerNoise[5] = GetValue<Direction>(OutOctant, CornerColor[5], x * 2 + 2, y * 2 + 1, Size, VoxelSteps >> 1, false);	// 5
			CornerNoise[6] = GetValue<Direction>(OutOctant, CornerColor[6], x * 2 + 0, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 6 - B
			CornerNoise[7] = GetValue<Direction>(OutOctant, CornerColor[7], x * 2 + 1, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 7
			CornerNoise[8] = GetValue<Direction>(OutOctant, CornerColor[8], x * 2 + 2, y * 2 + 2, Size, VoxelSteps >> 1, false);	// 8 - C

			CornerNoise[9] = GetValue<Direction>(OutOctant, CornerColor[9], x + 0, y + 0, Voxels + 0, VoxelSteps, true);	// 9
			CornerNoise[10] = GetValue<Direction>(OutOctant, CornerColor[10], x + 1, y + 0, Voxels + 0, VoxelSteps, true);	// A
			CornerNoise[11] = GetValue<Direction>(OutOctant, CornerColor[11], x + 0, y + 1, Voxels + 0, VoxelSteps, true);	// B
			CornerNoise[12] = GetValue<Direction>(OutOctant, CornerColor[12], x + 1, y + 1, Voxels + 0, VoxelSteps, true);	// C

			uint32 caseValue =
				((CornerNoise[0] < 0.f) << 0)
				| ((CornerNoise[1] < 0.f) << 1)
				| ((CornerNoise[2] < 0.f) << 2)
				| ((CornerNoise[5] < 0.f) << 3)
				| ((CornerNoise[8] < 0.f) << 4)
				| ((CornerNoise[7] < 0.f) << 5)
				| ((CornerNoise[6] < 0.f) << 6)
				| ((CornerNoise[3] < 0.f) << 7)
				| ((CornerNoise[4] < 0.f) << 8);

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

				if (World->NormalsType == ENormalsType::Smoothed)
				{
					normals[0] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[1] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[2] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 0 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[3] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[4] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[5] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[6] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[7] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 0 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
					normals[8] = GetGradient(TransferToDirection<Direction>(FIntVector(x + 1 + NORMAL, y + 1 + NORMAL, 0 + NORMAL), Voxels + 2));
				}
				for (uint32 i = 9; i < 13; i++)
				{
					const int X = (i - 1) % 2;
					const int Y = (i - 1) % 4 / 2;

					FIntVector P =		TransferToDirection<Direction>(FIntVector(x + X + NORMAL, y + Y + NORMAL, NORMAL), Voxels + 2);
					cornerPosition[i] = positionSide[P.X + P.Y * (Voxels + 1 + NORMALS) + P.Z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS)];

					if (World->NormalsType == ENormalsType::Smoothed)
					{
						normals[i] = GetGradient(TransferToDirection<Direction>(FIntVector(x + X + NORMAL, y + Y + NORMAL, 0 + NORMAL), Voxels + 2));
					}
				}

				
				const uint8 cellClass = Transvoxels::transitionCellClass[caseValue];
				const uint16* vertexData = Transvoxels::transitionVertexData[caseValue];
				Transvoxels::TransitionCellData cellData = Transvoxels::transitionCellData[cellClass & 0x7F];

				bool convertTriangles = ((cellClass >> 7) == 0);

				TArray<FVector> _VerticesTransition;
				TArray<FVector> _NormalsTransition;
				TArray<int32> _TrianglesTransition;
				TArray<FColor> _ColorsTransition;

				for (int i = 0; i < cellData.GetTriangleCount() * 3; i++)
				{
					const uint16& edgeCode = vertexData[i];

					uint8 indexPointA = (edgeCode >> 4) & 0x0F;
					uint8 indexPointB = edgeCode & 0x0F;

					FVector positionA = cornerPosition[indexPointA];
					FVector positionB = cornerPosition[indexPointB];

					float valueA = CornerNoise[indexPointA];
					float valueB = CornerNoise[indexPointB];

					FVector normalOne = normals[indexPointA];
					FVector normalTwo = normals[indexPointB];

					FColor colorOne = CornerColor[indexPointA];
					FColor colorTwo = CornerColor[indexPointB];

					FVector N = FVector(0.f, 0.f, 0.f);
					FVector P = FVector(0.f, 0.f, 0.f);
					FColor C = FColor(77.f, 77.f, 77.f);

					ValueInterp(positionA, positionB, normalOne, normalTwo, valueA, valueB, colorOne, colorTwo, P, N, C);

					_NormalsTransition.Add(N.GetSafeNormal());
					_VerticesTransition.Add(P);
					_ColorsTransition.Add(C);
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
				}
				for (int b = 0; b < _TrianglesTransition.Num(); b++)
				{
					Triangles.Add(_TrianglesTransition[b]);
				}
				if (World->ColorsType == EColorsType::OwnColors)
				{
					for (int a = 0; a < _VerticesTransition.Num(); a++)
					{
						VertexColors.Add(_ColorsTransition[a]);
					}
				}
				if (World->NormalsType == ENormalsType::Smoothed)
				{
					for (int j = 0; j < _NormalsTransition.Num(); j++)
					{
						Normals.Add(_NormalsTransition[j]);
					}
				}
			}
		}
	}
}

template<uint8 Direction>
float FVoxelMarchingCubesMesher::GetValue(FVoxelOctreeDensity* OutOctant, FColor& Color, int X, int Y, int Size, int Steps, bool CurrentOctree)
{
	float Value = 0.f;

	if (CurrentOctree)
	{
		FIntVector LocalPosition = TransferToDirection<Direction>(FIntVector(X, Y, 0), Size);

		Value = DensityMap[PositionToIndices(LocalPosition)];
		Color = ColorMap[PositionToIndices(LocalPosition)];
	}
	else
	{
		FIntVector GlobalPosition = TransferToDirection<Direction>(FIntVector(X, Y, 0) * Steps, Size) - FIntVector(1, 1, 1) * (Size >> 1) + Position;

		World->GetVoxelValue(OutOctant, GlobalPosition, Value, Color);
	}
	return Value;
}

template<uint8 Direction>
FVector FVoxelMarchingCubesMesher::GetPosition(int X, int Y, int Size, int Steps)
{
	FVector GlobalPosition = (FVector)TransferToDirection<Direction>(FIntVector(X * Steps, Y * Steps, 0), Size) - (Size >> 1);

	return GlobalPosition * World->VoxelMin;
}

template<uint8 Direction>
FIntVector FVoxelMarchingCubesMesher::TransferToDirection(FIntVector P, int Size)
{
	if ((Direction >> 0) & 0x01) { P = FIntVector(P.Z, P.X, P.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { P = FIntVector(Size - P.Z, P.Y, P.X); }	//0x02
	if ((Direction >> 2) & 0x01) { P = FIntVector(P.Y, P.Z, P.X); }			//0x04
	if ((Direction >> 3) & 0x01) { P = FIntVector(P.X, Size - P.Z, P.Y); }	//0x08
	if ((Direction >> 4) & 0x01) { P = FIntVector(P.X, P.Y, P.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { P = FIntVector(P.Y, P.X, Size - P.Z); }	//0x20

	return P;
}

void FVoxelMarchingCubesMesher::ValueInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, FColor C1, FColor C2, FVector& Vertex, FVector& Normal, FColor& Color)
{
	if (FMath::Abs(isolevel - P1Val) < 0.00001)
	{
		Vertex = P1;
		return;
	}
	if (FMath::Abs(isolevel - P2Val) < 0.00001)
	{
		Vertex = P2;
		return;
	}
	if (FMath::Abs(P1Val - P2Val) < 0.00001)
	{
		Vertex = P1;
		return;
	}

	float mu = (isolevel - P1Val) / (P2Val - P1Val);

	Vertex.X = P1.X + mu * (P2.X - P1.X);
	Vertex.Y = P1.Y + mu * (P2.Y - P1.Y);
	Vertex.Z = P1.Z + mu * (P2.Z - P1.Z);

	if (World->NormalsType == ENormalsType::Smoothed)
	{
		Normal.X = N1.X + mu * (N2.X - N1.X);
		Normal.Y = N1.Y + mu * (N2.Y - N1.Y);
		Normal.Z = N1.Z + mu * (N2.Z - N1.Z);
	}
	if (World->ColorsType == EColorsType::OwnColors)
	{
		Color.A = C1.A + mu * (C2.A - C1.A);
		Color.B = C1.B + mu * (C2.B - C1.B);
		Color.R = C1.R + mu * (C2.R - C1.R);
		Color.G = C1.G + mu * (C2.G - C1.G);
	}
}

int FVoxelMarchingCubesMesher::PositionToIndices(FIntVector P)
{
	return (P.X + NORMAL) + (P.Y + NORMAL) * (Voxels + 1 + NORMALS) + (P.Z + NORMAL) * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS);
}