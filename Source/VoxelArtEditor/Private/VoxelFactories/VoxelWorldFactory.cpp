// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelFactories/VoxelWorldFactory.h"
#include "VoxelModuleInterface.h"
#include "Save/VoxelSaveData.h"
#include "VoxelWorld.h"

UVoxelWorldFactory::UVoxelWorldFactory()
{
    DisplayName = NSLOCTEXT("Item", "Item", "Voxel World");
    NewActorClass = AVoxelWorld::StaticClass();
   // bCreateNew = true;
   // bEditAfterNew = true;
}

void UVoxelWorldFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	AVoxelWorld* VoxelWorld = CastChecked<AVoxelWorld>(NewActor);
  //  VoxelWorld->CreateVoxelWorldInEditor();
}
/*
UObject* UVoxelWorldFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    AVoxelWorld* NewWorld = NewObject<AVoxelWorld>(InParent, Class, Name, Flags | RF_Transactional);
    return NewWorld;
}*/