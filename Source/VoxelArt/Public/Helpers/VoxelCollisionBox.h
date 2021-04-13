// Voxel Art Plugin © limit 2018

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
	int Size;
};