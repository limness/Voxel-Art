// Voxel Art Plugin ~ Copyright limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Helpers/VoxelTools.h"
#include "Misc/UObjectToken.h"
#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"

DECLARE_MULTICAST_DELEGATE_ThreeParams(FVoxelLoggingDelegates, const FText&, const FString&, float);


//TODO: Delegates for Editor module

class VOXELART_API IVoxelLoggingInterface
{
public:

	FVoxelLoggingDelegates& OnVoxelLogging()
	{
		return VoxelLogging;
	}

	virtual ~IVoxelLogInterface() = default;

private:

	FVoxelLoggingDelegates VoxelLogging;

public:

	static void DialogMessage(const FText& Message, const FString& Verbosity)
	{
		VoxelLogging.Broadcast(Message, Verbosity, 0.f);
	}
	static void LogMessage(const FText& Message, const FString& Verbosity, float DurationTime = 0.4f)
	{
		VoxelLogging.Broadcast(Message, Verbosity, DurationTime);
	}
};