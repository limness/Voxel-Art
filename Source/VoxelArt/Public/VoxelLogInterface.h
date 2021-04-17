// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Helpers/VoxelTools.h"
#include "Misc/UObjectToken.h"
#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"

class VOXELART_API IVoxelLogInterface
{
public:

	//TODO: Delegates for Editor module

/*	DECLARE_MULTICAST_DELEGATE_TwoParams(FStartupDelegates, IVoxelLogInterface*, UObject*);
	static FStartupDelegates BindStartupDelegates;

	void StartupDelegates(UObject* Self)
	{
		BindStartupDelegates.Broadcast(this, Self);
	} */

	virtual ~IVoxelLogInterface() = default;

public:

	static void DialogMessage(const FText& Message, const FString& Verbosity);

	static void LogMessage(const FText& Message, const FString& Verbosity, float DurationTime = 0.4f);
};