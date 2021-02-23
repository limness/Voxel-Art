// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelOctreeData.h"
#include "Helpers/VoxelTools.h"
#include "Renders/VoxelLandscapeGenerator.h"
#include "VoxelLandscape.h"
#include "DrawDebugHelpers.h"

FVoxelOctreeData::FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, uint8 _Depth, float _Radius, FIntVector _Position)
	: ParentChunk(_Parent)
	, NodeID(_NodeID)
	, Depth(_Depth)
	, Size(_Radius)
	, Position(_Position)
	, Data(nullptr)
{
}

FVoxelOctreeData::~FVoxelOctreeData()
{
	ParentChunk.Reset();
	ChildrenChunks.Reset();
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
	return ChildrenChunks.Num() == 8;
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

FIntVector FVoxelOctreeData::GetMinimumCorner()
{
	return this->Position - FIntVector(1, 1, 1) * this->Size / 2;
}

FIntVector FVoxelOctreeData::GetMaximumCorner()
{
	return this->Position + FIntVector(1, 1, 1) * this->Size / 2;
}

void FVoxelOctreeData::AddChildren()
{
	int P = Size >> 2;

	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 0, Depth + 1, Size >> 1, Position + FIntVector(-P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 1, Depth + 1, Size >> 1, Position + FIntVector(+P, -P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 2, Depth + 1, Size >> 1, Position + FIntVector(-P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 3, Depth + 1, Size >> 1, Position + FIntVector(+P, +P, -P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 4, Depth + 1, Size >> 1, Position + FIntVector(-P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 5, Depth + 1, Size >> 1, Position + FIntVector(+P, -P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 6, Depth + 1, Size >> 1, Position + FIntVector(-P, +P, +P))));
	ChildrenChunks.Add(TSharedPtr<FVoxelOctreeData>(new FVoxelOctreeData(AsShared(), (NodeID << 3) | 7, Depth + 1, Size >> 1, Position + FIntVector(+P, +P, +P))));
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

TWeakPtr<FVoxelOctreeData> FVoxelOctreeData::GetChildByPosition(FVector Position)
{
	check(HasChildren());

	return ChildrenChunks[(Position.X > this->Position.X) + (Position.Y > this->Position.Y) * 2 + (Position.Z > this->Position.Z) * 4];
}


FVoxelOctreeDensity::FVoxelOctreeDensity(UVoxelLandscapeGenerator* _WorldGenerator, uint8 _Depth, int _Size, FIntVector _Position)
	: WorldGenerator(_WorldGenerator)
	, Depth(_Depth)
	, Size(_Size)
	, Position(_Position)
{

}

void FVoxelOctreeDensity::AddChildren()
{
	int P = Size >> 2;

	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(-P, -P, -P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(+P, -P, -P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(-P, +P, -P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(+P, +P, -P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(-P, -P, +P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(+P, -P, +P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(-P, +P, +P)));
	ChildrenOctants.Add(new FVoxelOctreeDensity(WorldGenerator, Depth + 1, Size >> 1, Position + FIntVector(+P, +P, +P)));
}

FVoxelOctreeDensity* FVoxelOctreeDensity::GetLeaf(FIntVector Position)
{
	if (!HasChildren())
	{
		return this;
	}
	else
	{
		return GetChildByPosition(Position)->GetLeaf(Position);
	}
	return this;
}

FVoxelOctreeDensity* FVoxelOctreeDensity::GetChildByPosition(FIntVector Position)
{
	check(HasChildren());

	return ChildrenOctants[(Position.X > this->Position.X) + (Position.Y > this->Position.Y) * 2 + (Position.Z > this->Position.Z) * 4];
}

#include "Kismet/KismetMathLibrary.h"

void FVoxelOctreeDensity::SetVoxelValue(AVoxelLandscape* World, FIntVector P, float Density, FColor Color, bool bSetDensity, bool bSetColor)
{
	if (Depth == World->MaximumLOD)
	{
		if (!HasOwnDensity())
		{
			SetDefaultMap(World);
			OwnDensity = true;
			OwnColor = true;
		}
		FIntVector LP = TransferToLocal(World, P);


		if (bSetDensity)
		{
		//	UE_LOG(VoxelArt, Log, TEXT("Inside true changed %s before %f now %f"), *LP.ToString(), DensityMap[World->GetIndex(LP + FIntVector(1, 1, 1) * NORMAL)], Density);

			DensityMap[World->GetIndex(LP + FIntVector(1, 1, 1) * NORMAL)] = UKismetMathLibrary::FMax(DensityMap[World->GetIndex(LP + FIntVector(1, 1, 1) * NORMAL)], Density);

		//	UE_LOG(VoxelArt, Log, TEXT("Final %f"), DensityMap[World->GetIndex(LP + FIntVector(1, 1, 1) * NORMAL)]);
		}
		if (bSetColor)
		{
			ColorMap[World->GetIndex(LP + FIntVector(1, 1, 1) * NORMAL)] = Color;
		}
	}
	else
	{
		check(!HasChildren());

		AddChildren();
		GetChildByPosition(P)->SetVoxelValue(World, P, Density, Color, bSetDensity, bSetColor);
	}
}

void FVoxelOctreeDensity::GetVoxelDensity(AVoxelLandscape* World, FIntVector P, float& Value, FColor& Color)
{
	Value = 0.f;
	Color = FColor(77.f, 77.f, 77.f);

	if (HasOwnDensity())
	{
		Value = DensityMap[World->GetIndex(TransferToLocal(World, P) + FIntVector(1, 1, 1) * NORMAL)];
	}
	else
	{
		Value = WorldGenerator->GetDensityMap(P);
	}
	if (HasOwnColor())
	{
		Color = ColorMap[World->GetIndex(TransferToLocal(World, P) + FIntVector(1, 1, 1) * NORMAL)];
	}
	else
	{
		Color = WorldGenerator->GetColorMap(P);
	}
}

void FVoxelOctreeDensity::SetDefaultMap(AVoxelLandscape* World)
{
	DensityMap.Init(-1.0, FMath::Pow(World->VoxelsPerChunk + 1 + NORMALS, 3));
	ColorMap.Init(FColor(77.f, 77.f, 77.f), FMath::Pow(World->VoxelsPerChunk + 1 + NORMALS, 3));

	int VoxelSteps = (Size / World->VoxelsPerChunk);

	for (int Z = 0; Z < World->VoxelsPerChunk + 1 + NORMALS; Z++)
	{
		for (int Y = 0; Y < World->VoxelsPerChunk + 1 + NORMALS; Y++)
		{
			for (int X = 0; X < World->VoxelsPerChunk + 1 + NORMALS; X++)
			{
				FIntVector DensityLocation = Position - FIntVector(1, 1, 1) * (Size >> 1);
				DensityLocation = DensityLocation + (FIntVector(X, Y, Z) - FIntVector(1, 1, 1) * NORMAL) * VoxelSteps;

				float Value = -1.f;
				FColor Color = FColor(77.f, 77.f, 77.f);

				World->GetVoxelValue(DensityLocation, Value, Color);

				DensityMap[World->GetIndex(FIntVector(X, Y, Z))] = Value;
				ColorMap[World->GetIndex(FIntVector(X, Y, Z))] = Color;
			}
		}
	}
}

FIntVector FVoxelOctreeDensity::TransferToLocal(AVoxelLandscape* World, FIntVector Position)
{
	return Position - this->Position + FIntVector(1, 1, 1) * Size / 2;
}

FVoxelChunkData::FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, uint8 _Depth, FIntVector _Position, int _Size, int _Voxels, int _Priority)
	: CurrentOctree(_CurrentOctree)
	, Depth(_Depth)
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