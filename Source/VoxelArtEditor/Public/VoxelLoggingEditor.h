// Voxel Art Plugin ~ Copyright limit 2018

#pragma once

#include "CoreMinimal.h"

#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"


//TODO: Delegates for Editor module

class VOXELART_API FVoxelLoggingEditor
{
public:

	FVoxelLoggingEditor() {}

public:

	static void DialogMessage(const FText& Message, const FString& Verbosity);

	static void LogMessage(const FText& Message, const FString& Verbosity, float DurationTime = 0.4f);
};