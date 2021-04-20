// Voxel Art Plugin © limit 2018

#include "Importers/VoxelHeightmapImport.h"
#include "Generators/VoxelWorldGenerator.h"
#include "VoxelLoggingInterface.h"
#include "VoxelWorld.h"


void UVoxelHeightmapImport::ExportHeightmap(AVoxelWorld* World, UVoxelWorldGenerator* WorldGenerator)
{
	if (WorldGenerator)
	{
		IVoxelLoggingInterface::LogMessage(INVTEXT("This feature will be working again soon! :)"), "Log");
		/*FString FileName = World->MapName;
		int width = World->MapSize;
		int height = World->MapSize;
		uint8* pixels = (uint8*)malloc(width * height * 4);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				uint8 PixelColorWB = (uint8)(FMath::Clamp(WorldGenerator->GetDensityMap(FIntVector(
					(x - width / 2) * World->VoxelMin,
					(y - height / 2) * World->VoxelMin,
					0)
				), -1.f, 1.0f) * 63.f + 128);

				if (PixelColorWB == 191 && World->RenderType == RenderTexture::RedGreenBlue)
				{
					FColor PixelColorRGB = WorldGenerator->GetColorMap(FIntVector(
						(x - width / 2) * World->VoxelMin,
						(y - height / 2) * World->VoxelMin,
						0)
					);

					pixels[y * 4 * width + x * 4 + 0] = PixelColorRGB.R; // R
					pixels[y * 4 * width + x * 4 + 1] = PixelColorRGB.G; // G
					pixels[y * 4 * width + x * 4 + 2] = PixelColorRGB.B; // B
					pixels[y * 4 * width + x * 4 + 3] = PixelColorRGB.A; // A
				}
				else
				{
					pixels[y * 4 * width + x * 4 + 0] = PixelColorWB; // R
					pixels[y * 4 * width + x * 4 + 1] = PixelColorWB; // G
					pixels[y * 4 * width + x * 4 + 2] = PixelColorWB; // B
					pixels[y * 4 * width + x * 4 + 3] = 255;
				}
			}
		}*/

		// Create Package

		//FString ObjectName = TEXT("WorldSave");

		//IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		//FString PackageName = FString("/Game/");
		//FString PackageName = FString(TEXT("/Game/"));
		///AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);
		//FString absolutePathPackage = FPaths::ProjectContentDir() + "/" + World->DirectoryName + "/";

		//FPackageName::RegisterMountPoint(*PackageName, *absolutePathPackage);
		/*
#if ENGINE_MINOR_VERSION < 26
		UPackage* Package = CreatePackage(nullptr, *PackageName);
#else
		UPackage* Package = CreatePackage(*PackageName);
#endif*/

		//FName TextureName = MakeUniqueObjectName(Package, UTexture2D::StaticClass(), FName(*FileName));
		//UTexture2D* Texture = UTexture2D::CreateTransient(width, height);//NewObject<UTexture2D>(Package, TextureName, RF_Public | RF_Standalone); // 
		//Texture->UpdateResource();
		// Texture Settings
		/*Texture->PlatformData = new FTexturePlatformData();
		Texture->PlatformData->SizeX = width;
		Texture->PlatformData->SizeY = height;
		Texture->PlatformData->PixelFormat = PF_R8G8B8A8;*/

		// Passing the pixels information to the texture
		//FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
		//Mip.SizeX = width;
		//Mip.SizeY = height;
		/*
		Mip.BulkData.Lock(LOCK_READ_WRITE);
		uint8* TextureData = (uint8*)Mip.BulkData.Realloc(sizeof(uint8) * height * width * 4);
		FMemory::Memcpy(TextureData, pixels, sizeof(uint8) * height * width * 4);
		Mip.BulkData.Unlock();*/

		// Updating Texture & mark it as unsaved
	//	Texture->AddToRoot();
	//	Texture->UpdateResource();
		//Package->MarkPackageDirty();


		/*FString ObjectName = TEXT("DensitySave");

		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		FString PackageName = FString(TEXT("/Game/VoxelSaves/Textures/"));
		AssetTools.CreateUniqueAssetName(PackageName, ObjectName, PackageName, ObjectName);

#if ENGINE_MINOR_VERSION < 26
		UPackage* Package = CreatePackage(nullptr, *PackageName);
#else
		UPackage* Package = CreatePackage(*PackageName);
#endif

		UPackage* OuterPack = Package->GetOutermost();
		Package->FullyLoad();

		//UVoxelSaveData* NewSave = NewObject<UVoxelSaveData>(OuterPack, *ObjectName, RF_Public | RF_Standalone);
		UTexture2D* NewSave = UTexture2D::CreateTransient(width, height);
		//NewSave->SetVoxelWorld(World);
		//NewSave->SaveData();


		NewSave->CompressionSettings = TC_Grayscale;
		NewSave->SRGB = false;
		NewSave->Filter = TF_Nearest;

		FTexture2DMipMap& Mip = NewSave->PlatformData->Mips[0];
		{
			Mip.BulkData.Lock(LOCK_READ_WRITE);
			uint8* TextureData = (uint8*)Mip.BulkData.Realloc(sizeof(uint8) * height * width * 4);
			FMemory::Memcpy(TextureData, pixels, sizeof(uint8)* height* width * 4);
			Mip.BulkData.Unlock();
		}
		NewSave->UpdateResource();


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
			IVoxelLoggingInterface::LogMessage(INVTEXT("Density Map Texture was created! Check your directory to find it"), "Log");
			//IVoxelLoggingInterface::LogMessage(INVTEXT("Voxel World has been successfully saved"), "Log");
			//SaveFile = NewSave;
		}
		else
		{
			IVoxelLoggingInterface::LogMessage(INVTEXT("Density Map Texture was not created!"), "Error");
		//	IVoxelLoggingInterface::LogMessage(INVTEXT("Voxel World has not been saved"), "Error");
		}
	//	free(pixels);
	//	pixels = NULL;*/

	}
	else
	{
		IVoxelLoggingInterface::LogMessage(INVTEXT("No World Generator! (Select: Voxel World->Main->World Generator)"), "Error");
	}
}
