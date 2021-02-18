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

	//check(DensityOctant != nullptr);
	/*Create new branch for Density Map*/
	//DensityOctant->AddChildren();
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

void FVoxelOctreeDensity::SetVoxelDensity(AVoxelLandscape* World, FIntVector Position, float& Value)
{
	Value = 0.f;

	//World->SpawnBoxTest(this->Position, Size / 2.f, 35.f, FColor::Green);

	if (Depth != World->MaximumLOD)
	{
		check(!HasChildren());

		AddChildren();
		GetChildByPosition(Position)->SetVoxelDensity(World, Position, Value);
	}
	else
	{
		if (!HasOwnDensity())
		{
			SetDefaultDensityMap(World);
			OwnDensity = true;
		}
		else
		{
			UE_LOG(VoxelArt, Warning, TEXT("This octant already has Density. Just change it"));
		}
		World->SpawnBoxTest(World->GetTransform().TransformPosition((FVector)this->Position), Size / 2.f * 128.f, 35.f, FColor::Green);
	}
}

void FVoxelOctreeDensity::GetVoxelDensity(AVoxelLandscape* World, FIntVector Position, float& Value)
{
	Value = 0.f;

	if (HasOwnDensity())
	{
		auto GetIndex = [&](int X, int Y, int Z)
		{
			return X + Y * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT) + Z * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT) * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT);
		};

		TransferToLocal(World, Position);

		Value = DensityMap[GetIndex(Position.X, Position.Y, Position.Z)];

		//UE_LOG(VoxelArt, Log, TEXT("It has Own Density // Value %f Position %s"), Value, *Position.ToString());
	}
	else
	{
		Value = WorldGenerator->GetDensityMap(Position);

		//UE_LOG(VoxelArt, Log, TEXT("It has NOT Own Density // Value %f Position %s"), Value, *Position.ToString());
		//UE_LOG(VoxelArt, Error, TEXT("Value %f Position %s"), Value, *Position.ToString());
	}
}



void FVoxelOctreeDensity::SetDefaultDensityMap(AVoxelLandscape* World)
{
	auto GetIndex = [&](int X, int Y, int Z)
	{
		return X + Y * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT) + Z * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT) * (World->VoxelsPerChunk + 1 + NORMALS_SKIRT);
	};

	DensityMap.Init(-1.0, FMath::Pow((World->VoxelsPerChunk + 1 + NORMALS_SKIRT), 3));
	 
	for (int Z = 0; Z < World->VoxelsPerChunk + 1 + NORMALS_SKIRT; Z++)
	{
		for (int Y = 0; Y < World->VoxelsPerChunk + 1 + NORMALS_SKIRT; Y++)
		{
			for (int X = 0; X < World->VoxelsPerChunk + 1 + NORMALS_SKIRT; X++)
			{
				FIntVector DensityPosition = Position + FIntVector(1, 1, 1) * (Size >> 2);//(FIntVector)World->GetTransform().InverseTransformPosition(Position + Size / 2.f);
				DensityPosition = DensityPosition - FIntVector(X - NORMALS_SKIRT_HALF, Y - NORMALS_SKIRT_HALF, Z - NORMALS_SKIRT_HALF) * (1 << (World->MaximumLOD - Depth));

				/*AsyncTask(ENamedThreads::GameThread, [=]()
					{
						DrawDebugPoint(World->GetWorld(), World->GetTransform().TransformPosition((FVector)DensityPosition), 5, FColor::Red, false, 25);

					});*/
				DensityMap[GetIndex(X, Y, Z)] = WorldGenerator->GetDensityMap(DensityPosition);
			}
		}
	}
}

void FVoxelOctreeDensity::TransferToLocal(AVoxelLandscape* World, FIntVector& Position)
{
	//DrawDebugPoint(World->GetWorld(), Position, 5, FColor::Green, false, 15);
	//Position = Position - (FIntVector)World->GetTransform().InverseTransformPosition(this->Position + Size / 2.f);
}

FVoxelChunkData::FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, uint8 _Depth, FIntVector _Position, int _Size, int _Voxels, float _Priority)
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