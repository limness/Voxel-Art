// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelLoggingEditor.h"
#include "Helpers/VoxelTools.h"


void FVoxelLoggingEditor::DialogMessage(const FText& Message, const FString& Verbosity)
{
	FMessageDialog::Open(EAppMsgType::Ok, FText::Format(INVTEXT("{0}"), Message));
}

void FVoxelLoggingEditor::LogMessage(const FText& Message, const FString& Verbosity, float DurationTime)
{
	FString InfoTag = "";
	InfoTag = (Verbosity == "Error")	? "Error: "		: InfoTag;
	InfoTag = (Verbosity == "Warning")	? "Warning: "	: InfoTag;

	FNotificationInfo Info(FText::Format(INVTEXT("{0}{1}"), FText::FromString(InfoTag), Message));
	Info.FadeInDuration = 0.2f;
	Info.FadeOutDuration = DurationTime;
	Info.ExpireDuration = 4.f;
	Info.bUseThrobber = false;
	Info.bUseSuccessFailIcons = true;
	Info.bUseLargeFont = true;
	Info.bFireAndForget = false;
	Info.bAllowThrottleWhenFrameRateIsLow = false;

	auto NotificationItem = FSlateNotificationManager::Get().AddNotification(Info);
	NotificationItem->SetCompletionState(SNotificationItem::CS_Success);
	NotificationItem->ExpireAndFadeout();

	if (Verbosity == "Error")
	{
		VOXEL_ERROR(TEXT("%s"), *Message.ToString());
	}
	else if (Verbosity == "Warning")
	{
		VOXEL_WARNING(TEXT("%s"), *Message.ToString());
	}
	else
	{
		VOXEL_LOG(TEXT("%s"), *Message.ToString());
	}
}
