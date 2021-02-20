// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelCollisionBox.h"
/*#include "Helpers/VoxelTools.h"
#include "Renders/VoxelLandscapeGenerator.h"
#include "VoxelLandscape.h"*/
#include "VoxelLandscape.h"
#include "VoxelOctreeData.h"
#include "DrawDebugHelpers.h"

FVoxelCollisionBox::FVoxelCollisionBox(AVoxelLandscape* _World, FIntVector _Position, int _Size)
	: Position(_Position)
	, Size(_Size)
	, World(_World)
{
	World->SpawnBoxTest(World->TransferToGameWorld(Position), Size / 2 * World->VoxelMin, 30.f, FColor::Red);
}

FVoxelCollisionBox::~FVoxelCollisionBox()
{
}
 
FIntVector FVoxelCollisionBox::GetMinimumCorner()
{
	return this->Position - FIntVector(1, 1, 1) * Size / 2;
}

FIntVector FVoxelCollisionBox::GetMaximumCorner()
{
	return this->Position + FIntVector(1, 1, 1) * Size / 2;
}

bool FVoxelCollisionBox::IsInside(TSharedPtr<FVoxelOctreeData> CurrentOctant)
{
	bool CorenerX = GetMinimumCorner().X >= CurrentOctant->GetMinimumCorner().X && GetMaximumCorner().X <= CurrentOctant->GetMaximumCorner().X;
	bool CorenerY = GetMinimumCorner().Y >= CurrentOctant->GetMinimumCorner().Y && GetMaximumCorner().Y <= CurrentOctant->GetMaximumCorner().Y;
	bool CorenerZ = GetMinimumCorner().Z >= CurrentOctant->GetMinimumCorner().Z && GetMaximumCorner().Z <= CurrentOctant->GetMaximumCorner().Z;
	
	return CorenerX && CorenerY && CorenerZ;
}

bool FVoxelCollisionBox::BoxOverlapOctree(TSharedPtr<FVoxelOctreeData> CurrentOctant)
{
	//DrawDebugPoint(World->GetWorld(), World->TransferToGameWorld(GetMaximumCorner()), 30, FColor::Red, false, 25);
//	DrawDebugPoint(World->GetWorld(), World->TransferToGameWorld(GetMinimumCorner()), 30, FColor::Red, false, 25);

	/*if (IsInside(CurrentOctant))
	{
		return true;
	}*/
	int CorenerX = 0;
	int CorenerY = 0;
	int CorenerZ = 0;

	if (GetMinimumCorner().X > CurrentOctant->GetMaximumCorner().X || GetMaximumCorner().X > CurrentOctant->GetMinimumCorner().X)
	{
		CorenerX = 1;
	}
	if (GetMinimumCorner().Y > CurrentOctant->GetMaximumCorner().Y || GetMaximumCorner().Y > CurrentOctant->GetMinimumCorner().Y)
	{
		CorenerY = 1; 
	}
	/*if (CurrentOctant->GetMinimumCorner().Z > GetMaximumCorner().Z || CurrentOctant->GetMaximumCorner().Z > GetMinimumCorner().Z)
	{
		CorenerZ = true;
	}*/
	return CorenerX + CorenerY == 2;
}