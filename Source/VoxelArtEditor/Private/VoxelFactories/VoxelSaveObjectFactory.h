// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "UnrealEd.h"
#include "ActorFactories/ActorFactory.h"
#include "VoxelSaveObjectFactory.generated.h"

UCLASS()
class UVoxelSaveObjectFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

public:

    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};