// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

#include "AssetToolsModule.h"
#include "AssetRegistryModule.h"

class AVoxelWorld;
class UVoxelSaveData;

/*
* Voxel Save Utilities class
*/
namespace FVoxelSaveUtilities
{
	static void CreateVoxelStorageFile(AVoxelWorld* World, UVoxelSaveData*& SaveFile);
};
