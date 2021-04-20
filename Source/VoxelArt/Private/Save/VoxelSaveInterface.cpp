// Voxel Art Plugin © limit 2018

#include "Save/VoxelSaveInterface.h"

IVoxelSaveInterface::FVoxelSaveDelegates IVoxelSaveInterface::VoxelSaveDelegates;


void IVoxelSaveInterface::CreateVoxelStorageFile(AVoxelWorld* World, UVoxelSaveData*& SaveFile)
{
	if (VoxelSaveDelegates.IsBound())
	{
		VoxelSaveDelegates.Broadcast(World, SaveFile);
	}
}