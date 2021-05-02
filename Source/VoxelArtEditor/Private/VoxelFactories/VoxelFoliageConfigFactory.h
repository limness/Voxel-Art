// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "UnrealEd.h"
#include "ActorFactories/ActorFactory.h"
#include "VoxelFoliageConfigFactory.generated.h"

UCLASS()
class UVoxelFoliageConfigFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

public:

    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};