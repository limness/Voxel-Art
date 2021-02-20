// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "VoxelCollisionBox.generated.h"

/*class AVoxelLandscape;
class UVoxelChunkComponent;
class UVoxelLandscapeGenerator;*/
class FVoxelOctreeData;
class AVoxelLandscape;

class VOXELART_API FVoxelCollisionBox
{
public:
	FVoxelCollisionBox(AVoxelLandscape* _World, FIntVector _Position, int _Size);
	~FVoxelCollisionBox();

public:

	FIntVector GetMinimumCorner();
	FIntVector GetMaximumCorner();

public:

	bool IsInside(TSharedPtr<FVoxelOctreeData> CurrentOctant);
	bool BoxOverlapOctree(TSharedPtr<FVoxelOctreeData> CurrentOctant);

public:

	FIntVector Position;
	int Size;

	AVoxelLandscape* World;
};