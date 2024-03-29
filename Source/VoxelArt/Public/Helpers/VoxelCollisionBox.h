// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

class FVoxelOctreeData;
class AVoxelWorld;

/*
* Voxel Collision Box class
*/
class VOXELART_API FVoxelCollisionBox
{
public:
	FVoxelCollisionBox(AVoxelWorld* _World, FIntVector _Position, int _Size);
	FVoxelCollisionBox(AVoxelWorld* _World, FIntVector _Position, FIntVector _Size);
	~FVoxelCollisionBox();

public:

	FIntVector GetMinimumCorner();
	FIntVector GetMaximumCorner();

public:

	bool IsInside(TSharedPtr<FVoxelOctreeData> CurrentOctant);
	bool BoxOverlapOctree(TSharedPtr<FVoxelOctreeData> CurrentOctant);

public:

	AVoxelWorld* World;
	FIntVector Position;
	FIntVector Size;
};