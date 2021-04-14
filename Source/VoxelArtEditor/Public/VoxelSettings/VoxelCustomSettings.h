// Voxel Art Plugin © limit 2018

#pragma once
#include "VoxelCustomSettings.generated.h"

UCLASS(config = MySettings)
class UVoxelCustomSettings : public UObject
{
    GENERATED_BODY()

public:
        UPROPERTY(EditAnywhere, config)
        bool bWelcomeShowed = false;
};