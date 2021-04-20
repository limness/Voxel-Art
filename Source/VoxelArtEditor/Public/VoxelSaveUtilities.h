// Voxel Art Plugin © limit 2018

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
