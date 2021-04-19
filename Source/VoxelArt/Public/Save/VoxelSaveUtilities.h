// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

class AVoxelWorld;
class UVoxelSaveData;

/*
* Voxel Save Utilities class
*/
class VOXELART_API IVoxelSaveUtilities
{
public:

#if WITH_EDITOR
	static UVoxelSaveData* CreateVoxelStorageFile(AVoxelWorld* World);
#endif
};
