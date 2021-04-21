// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelListenersInterface.h"

IVoxelListenersInterface::FVoxelListenersDelegates IVoxelListenersInterface::VoxelListenersDelegates;


void IVoxelListenersInterface::StartListeners(UObject* Self)
{
	if (VoxelListenersDelegates.IsBound())
	{
		VoxelListenersDelegates.Broadcast(this, Self);
	}
}
