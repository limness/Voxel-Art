// Voxel Art Plugin © limit 2018

#include "VoxelLoggingInterface.h"

IVoxelLoggingInterface::FVoxelDialogDelegates IVoxelLoggingInterface::VoxelDialogLogging;
IVoxelLoggingInterface::FVoxelMessageDelegates IVoxelLoggingInterface::VoxelMessageLogging;


void IVoxelLoggingInterface::DialogMessage(const FText& Message, const FString& Verbosity)
{
	if (VoxelDialogLogging.IsBound())
	{
		VoxelDialogLogging.Broadcast(Message, Verbosity);
	}
}
void IVoxelLoggingInterface::LogMessage(const FText& Message, const FString& Verbosity, float DurationTime)
{
	if (VoxelMessageLogging.IsBound())
	{
		VoxelMessageLogging.Broadcast(Message, Verbosity, DurationTime);
	}
}