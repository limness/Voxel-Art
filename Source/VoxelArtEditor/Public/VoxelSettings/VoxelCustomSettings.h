
#pragma once
#include "VoxelCustomSettings.generated.h"

//UCLASS(config = EditorUserSettings, defaultconfig)

//UCLASS(config = EditorUserSettings, defaultconfig)
UCLASS(config = MySettings)
class UVoxelCustomSettings : public UObject
{
    GENERATED_BODY()

public:
        UPROPERTY(EditAnywhere, config)
        bool bWelcomeShowed = false;
};