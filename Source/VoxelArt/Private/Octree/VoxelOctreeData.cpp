// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelOctreeData.h"
#include "Helpers/VoxelTools.h"
#include "DrawDebugHelpers.h"

FVoxelOctreeData::FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, int _Depth, float _Radius, FVector _Position)
	: ParentChunk(_Parent)
	, NodeID(_NodeID)
	, Depth(_Depth)
	, Size(_Radius)
	, Position(_Position)
{
}

FVoxelOctreeData::~FVoxelOctreeData()
{
	ParentChunk.Reset();
	ChildrenChunks.Reset();

	/*if (Data != nullptr)
	{
		delete Data;
		Data = nullptr;
	}*/
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
	float P = Size / 4.f;

	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 0, Depth + 1, Size / 2.f, Position + FVector(-P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 1, Depth + 1, Size / 2.f, Position + FVector(+P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 2, Depth + 1, Size / 2.f, Position + FVector(-P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 3, Depth + 1, Size / 2.f, Position + FVector(+P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 4, Depth + 1, Size / 2.f, Position + FVector(-P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 5, Depth + 1, Size / 2.f, Position + FVector(+P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 6, Depth + 1, Size / 2.f, Position + FVector(-P, +P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 7, Depth + 1, Size / 2.f, Position + FVector(+P, +P, +P))));

	//UE_LOG(VoxelArt, Error, TEXT("Size %f"), (radius / 2.f) / 16.f);
	//UE_LOG(LogTemp, Log, TEXT("[ Voxel Art Plugin ] Added 8 children"));
	//for (auto& Leaf : GetChildren())
	//{
	//	bool GetExistLeafFromHash = World->SavedChunks.RemoveAndCopyValue(Leaf->nodeID, Leaf);
	//}
}

void FVoxelOctreeData::GetVoxelDensity(FVector Position, float& Value)
{
//	TransferToLocal(Position);

	FIntVector PositionInt = FIntVector(Position.X, Position.Y, Position.Z);

	//TransferToLocal(PositionInt);

	Value = 0.f;

//	if(LIKELY(chunk && chunk->DensityMap.Num() > 0))
	{
		//Value = chunk->DensityMap[PositionInt.X + PositionInt.Y * (Voxels + 1 + NORMALS_SKIRT) + PositionInt.Z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT)];
/*
		if (PositionInt.X + PositionInt.Y * (Voxels + 1 + NORMALS_SKIRT) + PositionInt.Z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT) >= chunk->DensityMap.Num())
		{
			UE_LOG(VoxelArt, Error, TEXT("Level %d Value %s Our Num %d Num %d"), 
				level,
				*PositionInt.ToString(),
				PositionInt.X + PositionInt.Y * (Voxels + 1 + NORMALS_SKIRT) + PositionInt.Z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT),
				chunk->DensityMap.Num());
		}
		else
		{
			UE_LOG(VoxelArt, Log, TEXT("Level %d Value %s Our Num %d Num %d"),
				level,
				*PositionInt.ToString(),
				PositionInt.X + PositionInt.Y * (Voxels + 1 + NORMALS_SKIRT) + PositionInt.Z * (Voxels + 1 + NORMALS_SKIRT) * (Voxels + 1 + NORMALS_SKIRT),
				chunk->DensityMap.Num());
		} */
	}
}

void FVoxelOctreeData::TransferToLocal(FVector& Position)
{
	//Position = Position - position;
}

FORCEINLINE int FVoxelOctreeData::PositionToIndices(FVector position)
{
	return
		(position.X + NORMALS_SKIRT_HALF) +
		(position.Y + NORMALS_SKIRT_HALF) * (Data->Voxels + 1 + NORMALS_SKIRT) +
		(position.Z + NORMALS_SKIRT_HALF) * (Data->Voxels + 1 + NORMALS_SKIRT) * (Data->Voxels + 1 + NORMALS_SKIRT);
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

	return ChildrenChunks[(Position.X > this->Position.X) + (Position.Y > this->Position.Y) * 2 + (Position.Z > this->Position.Z) * 4];
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

FVoxelChunkData::FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, FVector _Position, float _Size, int _Voxels, float _Priority)
	: CurrentOctree(_CurrentOctree)
	, Position(_Position)
	, Size(_Size)
	, Voxels(_Voxels)
	, Priority(_Priority)
{
}

FVoxelChunkData::~FVoxelChunkData()
{
	//Chunk = nullptr;
}