// Voxel Art Plugin © limit 2018

#include "Save/VoxelSaveUtilities.h"
#include "Save/VoxelSaveData.h"
#include "VoxelLogInterface.h"
#include "VoxelWorld.h"

#include "AssetToolsModule.h"
#include "AssetRegistryModule.h"


UVoxelSaveData* IVoxelSaveUtilities::CreateVoxelStorageFile(AVoxelWorld* World)
{
	FString ObjectName = TEXT("WorldSave");

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	FString PackageName = FString(TEXT("/Game/VoxelSaves/"));
	AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

	UPackage* Package = CreatePackage(*PackageName);
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
		IVoxelLogInterface::LogMessage(INVTEXT("Voxel World has been successfully saved"), "Log");
		return NewSave;
	}
	else
	{
		IVoxelLogInterface::LogMessage(INVTEXT("Voxel World has not been saved"), "Error");
	}
	return nullptr;
}