// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelOctreeData.h"
#include "Helpers/VoxelTools.h"
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

void FVoxelOctreeData::DestroyChildren()
{
	for (auto& it : GetChildren())
	{
		it.Reset();
	}
	ChildrenChunks.Empty();
	ChildrenChunks.Reset();
}

bool FVoxelOctreeData::HasChildren()
{
	return !!(ChildrenChunks.Num());
}

TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetParent()
{
	check((ParentChunk != nullptr));

	return ParentChunk;
}

TArray<TSharedPtr<FVoxelOctreeData>> FVoxelOctreeData::GetChildren()
{
	return ChildrenChunks;
}

void FVoxelOctreeData::CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>> children)
{
	for (auto& it : children)
	{
		ChildrenChunks.Add(it);
	}
}

void FVoxelOctreeData::AddChildren()
{
	float P = radius / 4.f;

	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 0, level + 1, radius / 2.f, position + FVector(-P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 1, level + 1, radius / 2.f, position + FVector(+P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 2, level + 1, radius / 2.f, position + FVector(-P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 3, level + 1, radius / 2.f, position + FVector(+P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 4, level + 1, radius / 2.f, position + FVector(-P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 5, level + 1, radius / 2.f, position + FVector(+P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 6, level + 1, radius / 2.f, position + FVector(-P, +P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (nodeID << 3) | 7, level + 1, radius / 2.f, position + FVector(+P, +P, +P))));

	//UE_LOG(LogTemp, Log, TEXT("[ Voxel Art Plugin ] Added 8 children"));
	//for (auto& Leaf : GetChildren())
	//{
	//	bool GetExistLeafFromHash = World->SavedChunks.RemoveAndCopyValue(Leaf->nodeID, Leaf);
	//}
}

void FVoxelOctreeData::GetVoxelValue(FVector Position, float& Value)
{
	FIntVector PosInt = FIntVector(FMath::RoundToInt(Position.X), FMath::RoundToInt(Position.Y), FMath::RoundToInt(Position.Z));

	//TransferToLocal(Position);

	UE_LOG(VoxelArt, Log, TEXT("Local Position Voxel %s"), *PosInt.ToString());

	Value = 0.f;
}

void FVoxelOctreeData::TransferToLocal(FVector& Position)
{
	Position = Position - position + radius / 2.f;
}

TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetLeaf(FVector Position)
{
	if (!HasChildren())
	{
		return AsShared();
	}
	else
	{
		return GetChildByPosition(Position).Pin()->GetLeaf(Position);
	}
	return AsShared();
}

//0 1 0
//1 1 0
//0 0 0
//1 0 0

//0 1 1
//1 1 1
//0 0 1
//1 0 1

TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetChildByPosition(FVector Position)
{
	check(HasChildren());

	return ChildrenChunks[(Position.X > position.X) + (Position.Y > position.Y) * 2 + (Position.Z > position.Z) * 4];
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