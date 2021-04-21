// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"


namespace FVoxelLoggingEditor
{
	void DialogMessage(const FText& Message, const FString& Verbosity);
	void LogMessage(const FText& Message, const FString& Verbosity, float DurationTime = 0.4f);
};