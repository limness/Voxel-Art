// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Helpers/VoxelCollisionBox.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelWorld.h"
#include "DrawDebugHelpers.h"

FVoxelCollisionBox::FVoxelCollisionBox(AVoxelWorld* _World, FIntVector _Position, int _Size)
	: World(_World)
	, Position(_Position)
	, Size(FIntVector(_Size, _Size, _Size))
{
}

FVoxelCollisionBox::FVoxelCollisionBox(AVoxelWorld* _World, FIntVector _Position, FIntVector _Size)
	: World(_World)
	, Position(_Position)
	, Size(_Size)
{
//	World->SpawnBoxTest(World->TransferToGameWorld(Position), Size / 2 * World->VoxelMin, 30.f, FColor::Green);
}

FVoxelCollisionBox::~FVoxelCollisionBox()
{
}
 
FIntVector FVoxelCollisionBox::GetMinimumCorner()
{
	return this->Position - Size / 2;
}

FIntVector FVoxelCollisionBox::GetMaximumCorner()
{
	return this->Position + Size / 2;
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
	/*if (IsInside(CurrentOctant))
	{
		return true;
	}*/
	int CorenerX = 0;
	int CorenerY = 0;
	int CorenerZ = 0;

	if ((GetMinimumCorner().X > CurrentOctant->GetMaximumCorner().X) ^ (GetMaximumCorner().X > CurrentOctant->GetMinimumCorner().X))
	{
		CorenerX = 1;
	}
	if ((GetMinimumCorner().Y > CurrentOctant->GetMaximumCorner().Y) ^ (GetMaximumCorner().Y > CurrentOctant->GetMinimumCorner().Y))
	{
		CorenerY = 1; 
	}
	if ((GetMinimumCorner().Z > CurrentOctant->GetMaximumCorner().Z) ^ (GetMaximumCorner().Z > CurrentOctant->GetMinimumCorner().Z))
	{
		CorenerZ = 1;
	}
	return CorenerX + CorenerY + CorenerZ == 3;
}