// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

class AVoxelWorld;
class UVoxelSaveData;

/*
* Voxel Save Utilities class
*/
class VOXELART_API IVoxelSaveInterface
{
public:

	/*FVoxelLoggingDelegates& OnVoxelLogging()
	{
		return VoxelLogging;
	}*/

	virtual ~IVoxelSaveInterface() = default;

public:

	DECLARE_MULTICAST_DELEGATE_TwoParams(FVoxelSaveDelegates, AVoxelWorld*, UVoxelSaveData*&);
	static FVoxelSaveDelegates VoxelSaveDelegates;

public:

	static void CreateVoxelStorageFile(AVoxelWorld* World, UVoxelSaveData*& SaveFile);
};
