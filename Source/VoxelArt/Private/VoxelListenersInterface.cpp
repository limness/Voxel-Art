// Voxel Art Plugin © limit 2018

#include "VoxelListenersInterface.h"

IVoxelListenersInterface::FVoxelListenersDelegates IVoxelListenersInterface::VoxelListenersDelegates;


void IVoxelListenersInterface::StartListeners(UObject* Self)
{
	if (VoxelListenersDelegates.IsBound())
	{
		VoxelListenersDelegates.Broadcast(this, Self);
	}
}
