﻿// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Meshers/VoxelCubesMesher.h"
#include "DrawDebugHelpers.h"


FVoxelCubesMesher::FVoxelCubesMesher(AVoxelWorld* _World, FVoxelChunkData* _Data)
	: FVoxelDefaultMesher(_World, _Data)
{
}

FVector FVoxelCubesMesher::GetInterp(FVector p1, FVector p2, float d1, float d2)
{
	return p1 + (-d1) * (p2 - p1) / (d2 - d1);
}

void FVoxelCubesMesher::GenerateMesh()
{
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	VerticesIndeсes.Empty();

	VerticesIndeсes.Init(-1, FMath::Pow(Voxels + 1 + NORMALS, 3));

	int idx = 0;

	int VoxelSize = (Size / Voxels) * World->VoxelMin;

	for (int z = NORMAL; z < Voxels + NORMAL; z++)
	{
		for (int y = NORMAL; y < Voxels + NORMAL; y++)
		{
			for (int x = NORMAL; x < Voxels + NORMAL; x++)
			{
				int corners = 0;
				{
					for (int i = 0; i < 8; i++)
					{
						if (GetDensity(x + i % 2, y + i % 4 / 2, z + i / 4) < 0)
						{
							corners |= 1 << i;
						}
					}
					if (corners == 0 || corners == 255)
					{
						continue;
					}
				}

				int edgeCount = 0;
				//FVector average_normal = FVector(0, 0, 0);
				FVector average_pos = FVector(0, 0, 0);

				for (int i = 0; i < 12; i++)
				{
					int c1 = edges[i][0];
					int c2 = edges[i][1];

					int m1 = (corners >> c1) & 1;
					int m2 = (corners >> c2) & 1;

					if (m1 == m2)
					{
						continue;
					}
/*
					float d1 = GetDensity(x + c1 % 2, y + c1 % 4 / 2, z + c1 / 4);
					float d2 = GetDensity(x + c2 % 2, y + c2 % 4 / 2, z + c2 / 4);

					FVector p1 = FVector(x + (float)(c1 % 2), y + (float)(c1 % 4 / 2), z + (float)(c1 / 4)) - NORMAL;
					FVector p2 = FVector(x + (float)(c2 % 2), y + (float)(c2 % 4 / 2), z + (float)(c2 / 4)) - NORMAL;

					p1 = p1 - World->VoxelsPerChunk / 2;
					p1 = p1 * VoxelSize;

					p2 = p2 - World->VoxelsPerChunk / 2;
					p2 = p2 * VoxelSize;

					//average_normal	+= (p2 - p1).GetUnsafeNormal() * (d2 - d1);
					average_pos += GetInterp(p1, p2, d1, d2);*/

					edgeCount++;
				}
				if (edgeCount != 0)
				{
					//FVector posnew = average_pos / (float)1;  

					FVector p1 = FVector(x, y, z) - NORMAL;

					p1 = p1 - World->VoxelsPerChunk / 2;
					p1 = p1 * VoxelSize;

					//DrawDebugPoint(World->GetWorld(), posnew, 5.f, FColor::Red, false, 25.f, 10.f);

					Vertices.Add(p1);
					//Normals.Add(-average_normal.GetUnsafeNormal());

					VerticesIndeсes[x + z * (Voxels + 1 + NORMALS) * (Voxels + 1 + NORMALS) + y * (Voxels + 1 + NORMALS)] = idx;
				}
				idx++;
			}
		}
	}
	GeneratePlane();
}

void FVoxelCubesMesher::GeneratePlane()
{
	int idx = 0;

	for (int z = NORMAL; z < Voxels + 1; z++)
	{
		for (int y = NORMAL; y < Voxels + 1; y++)
		{
			for (int x = NORMAL; x < Voxels + 1; x++)
			{
				int v1 = GetVerticesIndeces(x, y, z);

				if (v1 == -1) continue;

				if (true)
				{
					int v2 = GetVerticesIndeces(x + 1, y + 0, z + 0);
					int v3 = GetVerticesIndeces(x + 0, y + 0, z + 1);
					int v4 = GetVerticesIndeces(x + 1, y + 0, z + 1);

					if (v2 == -1 || v3 == -1 || v4 == -1)
					{

					}
					else
					{
						if (GetDensity(x + 1, y + 0, z + 1) > 0)
						{
							Triangles.Add(v3);
							Triangles.Add(v2);
							Triangles.Add(v1);

							Triangles.Add(v2);
							Triangles.Add(v3);
							Triangles.Add(v4);
						}
						else
						{
							Triangles.Add(v1);
							Triangles.Add(v2);
							Triangles.Add(v3);

							Triangles.Add(v4);
							Triangles.Add(v3);
							Triangles.Add(v2);
						}
					}
				}
				if (true)
				{
					int v2 = GetVerticesIndeces(x + 1, y + 0, z + 0);
					int v3 = GetVerticesIndeces(x + 0, y + 1, z + 0);
					int v4 = GetVerticesIndeces(x + 1, y + 1, z + 0);

					if (v2 == -1 || v3 == -1 || v4 == -1)
					{

					}
					else
					{
						if (GetDensity(x + 1, y + 1, z + 0) < 0)
						{
							Triangles.Add(v3);
							Triangles.Add(v2);
							Triangles.Add(v1);

							Triangles.Add(v2);
							Triangles.Add(v3);
							Triangles.Add(v4);
						}
						else
						{
							Triangles.Add(v1);
							Triangles.Add(v2);
							Triangles.Add(v3);

							Triangles.Add(v4);
							Triangles.Add(v3);
							Triangles.Add(v2);
						}
					}
				}
				if (true)
				{
					int v2 = GetVerticesIndeces(x + 0, y + 1, z + 0);
					int v3 = GetVerticesIndeces(x + 0, y + 0, z + 1);
					int v4 = GetVerticesIndeces(x + 0, y + 1, z + 1);

					if (v2 == -1 || v3 == -1 || v4 == -1)
					{

					}
					else
					{
						if (GetDensity(x + 0, y + 1, z + 1) < 0)
						{
							Triangles.Add(v3);
							Triangles.Add(v2);
							Triangles.Add(v1);

							Triangles.Add(v2);
							Triangles.Add(v3);
							Triangles.Add(v4);
						}
						else
						{
							Triangles.Add(v1);
							Triangles.Add(v2);
							Triangles.Add(v3);

							Triangles.Add(v4);
							Triangles.Add(v3);
							Triangles.Add(v2);
						}
					}
				}
			}
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
}