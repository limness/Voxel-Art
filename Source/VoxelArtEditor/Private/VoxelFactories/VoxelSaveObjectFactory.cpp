// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelFactories/VoxelSaveObjectFactory.h"
#include "VoxelModuleInterface.h"
#include "Save/VoxelSaveData.h"

UVoxelSaveObjectFactory::UVoxelSaveObjectFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    SupportedClass = UVoxelSaveData::StaticClass();
    bCreateNew = true;
    bEditAfterNew = true;
}


UObject* UVoxelSaveObjectFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    UVoxelSaveData* NewFoliageConfig = NewObject<UVoxelSaveData>(InParent, Class, Name, Flags | RF_Transactional);
    return NewFoliageConfig;
}