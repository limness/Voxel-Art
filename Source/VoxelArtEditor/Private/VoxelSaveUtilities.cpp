// Voxel Art Plugin © limit 2018

#include "VoxelSaveUtilities.h"
#include "Save/VoxelSaveData.h"
#include "VoxelLoggingInterface.h"
#include "VoxelWorld.h"


void FVoxelSaveUtilities::CreateVoxelStorageFile(AVoxelWorld* World, UVoxelSaveData*& SaveFile)
{
	FString ObjectName = TEXT("WorldSave");

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	FString PackageName = FString(TEXT("/Game/VoxelSaves/"));
	AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

#if ENGINE_MINOR_VERSION < 26
	UPackage* Package = CreatePackage(nullptr, *PackageName);
#else
	UPackage* Package = CreatePackage(*PackageName);
#endif

	UPackage* OuterPack = Package->GetOutermost();
	Package->FullyLoad();

	UVoxelSaveData* NewSave = NewObject<UVoxelSaveData>(OuterPack, *ObjectName, RF_Public | RF_Standalone);

	NewSave->SetVoxelWorld(World);
	NewSave->SaveData();

	FAssetRegistryModule::AssetCreated(NewSave);

	NewSave->MarkPackageDirty();
	NewSave->PostEditChange();
	NewSave->AddToRoot();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	bool bSaveSuccess = UPackage::SavePackage(
		Package,
		NewSave,
		EObjectFlags::RF_Public | EObjectFlags::RF_Standalone,
		*PackageFileName,
		GError, nullptr, true, true, SAVE_NoError);

	if (bSaveSuccess)
	{
		IVoxelLoggingInterface::LogMessage(INVTEXT("Voxel World has been successfully saved"), "Log");
		SaveFile = NewSave;
	}
	else
	{
		IVoxelLoggingInterface::LogMessage(INVTEXT("Voxel World has not been saved"), "Error");
	}
}