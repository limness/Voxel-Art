// Voxel Art Plugin 2021 ~ Copyright Limit

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