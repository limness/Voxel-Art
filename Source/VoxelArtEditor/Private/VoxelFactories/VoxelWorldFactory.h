// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "UnrealEd.h"
#include "ActorFactories/ActorFactory.h"
#include "VoxelWorldFactory.generated.h"

UCLASS()
class VOXELARTEDITOR_API UVoxelWorldFactory : public UActorFactory
{
    GENERATED_BODY()

public:

    UVoxelWorldFactory();

    //~ Begin UActorFactory Interface
    void PostSpawnActor(UObject* Asset, AActor* NewActor) override;
    //~ End UActorFactory Interface
   // virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};