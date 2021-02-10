// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelOctreeData.h"
#include "DrawDebugHelpers.h"

FVoxelOctreeData::FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, int _Level, float _Radius, FVector _Position)
	: ParentChunk(_Parent)
	, nodeID(_NodeID)
	, level(_Level)
	, radius(_Radius)
	, position(_Position)
{
	chunk = nullptr;
	ParentChunk.Reset();

	//land->SpawnBoxTest(it->position, it->radius / 2.f, 2500.f, FColor::Red);
	//DrawDebugBox(GetWorld(), location, FVector(radius, radius, radius), color, false, 13.f, 5, width);
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
}

//FORCEINLINE void FVoxelOctreeData::GetLeavesOnPosition(FVector Position)
//{
	
//}

void FVoxelOctreeData::AddChildren()
{
	float P = radius / 4.f;

	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 0, level + 1, radius / 2.f, position + FVector(-P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 1, level + 1, radius / 2.f, position + FVector(+P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 2, level + 1, radius / 2.f, position + FVector(-P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 3, level + 1, radius / 2.f, position + FVector(+P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 4, level + 1, radius / 2.f, position + FVector(-P, +P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 5, level + 1, radius / 2.f, position + FVector(+P, +P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 6, level + 1, radius / 2.f, position + FVector(-P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 7, level + 1, radius / 2.f, position + FVector(+P, -P, +P))));

	//UE_LOG(LogTemp, Log, TEXT("[ Voxel Art Plugin ] Added 8 children"));
	//for (auto& Leaf : GetChildren())
	//{
	//	bool GetExistLeafFromHash = World->SavedChunks.RemoveAndCopyValue(Leaf->nodeID, Leaf);
	//}
}

TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetLeaf(FVector Position)
{
	if (!HasChildren())
	{
		return AsShared();
	}
	else
	{
	//	return ChildrenChunks[0]->GetLeaf();
	}
	return AsShared();
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