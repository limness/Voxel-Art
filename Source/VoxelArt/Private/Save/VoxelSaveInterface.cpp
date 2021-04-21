// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Save/VoxelSaveInterface.h"

IVoxelSaveInterface::FVoxelSaveDelegates IVoxelSaveInterface::VoxelSaveDelegates;


void IVoxelSaveInterface::CreateVoxelStorageFile(AVoxelWorld* World, UVoxelSaveData*& SaveFile)
{
	if (VoxelSaveDelegates.IsBound())
	{
		VoxelSaveDelegates.Broadcast(World, SaveFile);
	}
}