// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelFactories/VoxelFoliageConfigFactory.h"
#include "VoxelModuleInterface.h"
#include "VoxelFoliageConfig.h"

UVoxelFoliageConfigFactory::UVoxelFoliageConfigFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    SupportedClass = UVoxelFoliageConfig::StaticClass();
    bCreateNew = true;
    bEditAfterNew = true;
}


UObject* UVoxelFoliageConfigFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    UVoxelFoliageConfig* NewFoliageConfig = NewObject<UVoxelFoliageConfig>(InParent, Class, Name, Flags | RF_Transactional);
    return NewFoliageConfig;
}