// Voxel Art Plugin © limit 2018

#include "VoxelListenersInterface.h"

IVoxelListenersInterface::FVoxelListenersDelegates FVoxelListenersDelegates::VoxelListenersDelegates;


void IVoxelListenersInterface::StartListeners(UObject* Self)
{
	if (VoxelDialogLogging.IsBound())
	{
		VoxelListenersDelegates.Broadcast(this, Self);
	}
}
