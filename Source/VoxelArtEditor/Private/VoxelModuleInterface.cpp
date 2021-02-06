
#include "VoxelModuleInterface.h"

//#include "CustomAssetEditorModule.h"

IMPLEMENT_GAME_MODULE(IVoxelModuleInterface, VoxelArtEditor);

#define LOCTEXT_NAMESPACE "IVoxelModuleInterface"

void IVoxelModuleInterface::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("StartupModule() called"));
}

void IVoxelModuleInterface::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("ShutdownModule() called"));
}

#undef LOCTEXT_NAMESPACE