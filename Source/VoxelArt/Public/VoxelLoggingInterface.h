// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Helpers/VoxelTools.h"
#include "Misc/UObjectToken.h"
#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"



//TODO: Delegates for Editor module

class VOXELART_API IVoxelLoggingInterface
{
public:

	/*FVoxelLoggingDelegates& OnVoxelLogging()
	{
		return VoxelLogging;
	}*/

	virtual ~IVoxelLoggingInterface() = default;

public:

	DECLARE_MULTICAST_DELEGATE_TwoParams(FVoxelDialogDelegates, const FText&, const FString&);
	static FVoxelDialogDelegates VoxelDialogLogging;

	DECLARE_MULTICAST_DELEGATE_ThreeParams(FVoxelMessageDelegates, const FText&, const FString&, float);
	static FVoxelMessageDelegates VoxelMessageLogging;

public:

	static void DialogMessage(const FText& Message, const FString& Verbosity);

	static void LogMessage(const FText& Message, const FString& Verbosity, float DurationTime = 0.4f);
};