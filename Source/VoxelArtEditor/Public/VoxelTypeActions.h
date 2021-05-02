// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "AssetTypeActions_Base.h"

class UVoxelSaveData;
class UVoxelFoliageConfig;

class FVoxelSaveObject_AssetsTypeActions : public FAssetTypeActions_Base
{
public:

    FVoxelSaveObject_AssetsTypeActions(EAssetTypeCategories::Type InAssetCategory)
        : AssetCategory(InAssetCategory)
    {
    }

    // IAssetTypeActions interface

    virtual FText GetName() const override              { return FText::FromString("Voxel Save File"); }
    virtual FColor GetTypeColor() const override        { return FColor::Purple; }
    virtual UClass* GetSupportedClass() const override  { return UVoxelSaveData::StaticClass(); }
    virtual uint32 GetCategories() override             { return AssetCategory; }

    // End of IAssetTypeActions interface

private:

    EAssetTypeCategories::Type AssetCategory;
};


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


class FVoxelFoliageConfig_AssetsTypeActions : public FAssetTypeActions_Base
{
public:

    FVoxelFoliageConfig_AssetsTypeActions(EAssetTypeCategories::Type InAssetCategory)
        : AssetCategory(InAssetCategory)
    {
    }

    // IAssetTypeActions interface

    virtual FText GetName() const override              { return FText::FromString("Voxel Foliage Config"); }
    virtual FColor GetTypeColor() const override        { return FColor::Green; }
    virtual UClass* GetSupportedClass() const override  { return UVoxelFoliageConfig::StaticClass(); }
    virtual uint32 GetCategories() override             { return AssetCategory; }

    // virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) override;
     // End of IAssetTypeActions interface

private:

    EAssetTypeCategories::Type AssetCategory;
};