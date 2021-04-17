// Voxel Art Plugin © limit 2018

#include "VoxelLogInterface.h"

#define LOCTEXT_NAMESPACE "VoxelLog"

void IVoxelLogInterface::DialogMessage(const FText& Message, const FString& Verbosity)
{
	FMessageDialog::Open(EAppMsgType::Ok, FText::Format(INVTEXT("{0}"), Message));
}

void IVoxelLogInterface::LogMessage(const FText& Message, const FString& Verbosity, float DurationTime)
{
	FNotificationInfo Info(FText::Format(INVTEXT("{0}{1}"), 
		(Verbosity == "Error") ? FText::FromString("Error: ") : FText::FromString(""), 
		Message));

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
		UE_LOG(VoxelArt, Error, TEXT("%s"), *Message.ToString());
	}
	else
	{
		UE_LOG(VoxelArt, Log, TEXT("%s"), *Message.ToString());
	}
}

#undef LOCTEXT_NAMESPACE