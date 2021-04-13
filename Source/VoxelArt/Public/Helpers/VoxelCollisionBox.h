// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

<<<<<<< HEAD
=======

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
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
<<<<<<< HEAD
=======

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
	FIntVector Position;
	int Size;
};