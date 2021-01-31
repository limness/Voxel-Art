// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelOctreeData.h"

FVoxelOctreeData::FVoxelOctreeData()
{
	chunk = nullptr;
	ParentChunk.Reset();
	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Log: Init"));
}

FVoxelOctreeData::~FVoxelOctreeData()
{
	chunk = nullptr;

	ParentChunk.Reset();
	ChildrenChunks.Reset();

	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	Colors.Empty();
	Grid.Empty();
	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Log: De-Init"));
}

template<uint8 Direction>
FORCEINLINE TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetNeighbor(int position)
{
	TWeakPtr<FVoxelOctreeData> neighbor = nullptr;

	if ((Direction >> 0) & 0x01) { neighbor = neighborFaceW[position]; }	//0x01
	if ((Direction >> 1) & 0x01) { neighbor = neighborFaceE[position]; }	//0x02
	if ((Direction >> 2) & 0x01) { neighbor = neighborFaceS[position]; }	//0x04
	if ((Direction >> 3) & 0x01) { neighbor = neighborFaceN[position]; }	//0x08
	if ((Direction >> 4) & 0x01) { neighbor = neighborFaceD[position]; }	//0x10
	if ((Direction >> 5) & 0x01) { neighbor = neighborFaceU[position]; }	//0x20

	return neighbor;
}

FVoxelChunkRenderData::FVoxelChunkRenderData()
{
	CurrentOctree.Reset();
}

FVoxelChunkRenderData::~FVoxelChunkRenderData()
{
	CurrentOctree.Reset();
}