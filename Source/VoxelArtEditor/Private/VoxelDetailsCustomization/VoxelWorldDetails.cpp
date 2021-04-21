// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelDetailsCustomization/VoxelWorldDetails.h"
#include "VoxelModuleInterface.h"
#include "VoxelPlayerEditor.h"
#include "Helpers/VoxelTools.h"

TSharedRef<IDetailCustomization> IVoxelWorldDetails::MakeInstance()
{
    return MakeShareable(new IVoxelWorldDetails);
}

void IVoxelWorldDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
    TArray<TWeakObjectPtr<UObject>> Objects;
    DetailLayout.GetObjectsBeingCustomized(Objects);
    if (Objects.Num() != 1)
    {
        return;
    }

    World = (AVoxelWorld*)Objects[0].Get();

    IDetailCategoryBuilder& OptionsCategory = DetailLayout.EditCategory("Main", FText::FromString(""), ECategoryPriority::Important);

    OptionsCategory.AddCustomRow(FText::FromString(TEXT("")))
        .NameContent()
        [
            SNew(STextBlock)
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .Text(FText::FromString(TEXT("World Preview")))
        ]
        .ValueContent()
        .MaxDesiredWidth(125.f)
        .MinDesiredWidth(125.f)
        [
            SNew(SButton)
            .ContentPadding(2)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .OnClicked(this, &IVoxelWorldDetails::CreateWorldInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Create World")))
            ]
        ];

    OptionsCategory.AddCustomRow(FText::FromString(TEXT("")))
        .NameContent()
        [
            SNew(STextBlock)
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .Text(FText::FromString(TEXT("")))
        ]
        .ValueContent()
        .MaxDesiredWidth(125.f)
        .MinDesiredWidth(125.f)
        [
            SNew(SButton)
            .ContentPadding(2)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .OnClicked(this, &IVoxelWorldDetails::SaveWorldInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Save World")))
            ]
        ];
    OptionsCategory.AddCustomRow(FText::FromString(TEXT("")))
        .NameContent()
        [
            SNew(STextBlock)
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .Text(FText::FromString(TEXT("")))
        ]
        .ValueContent()
        .MaxDesiredWidth(125.f)
        .MinDesiredWidth(125.f)
        [
            SNew(SButton)
            .ContentPadding(2)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .OnClicked(this, &IVoxelWorldDetails::DestroyWorldInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Destroy World")))
            ]
        ];

    DetailLayout.EditCategory("Export Preview Heightmap")
        .AddCustomRow(FText::FromString(TEXT("")))
        .NameContent()
        [
            SNew(STextBlock)
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .Text(FText::FromString(TEXT("Preview Density Map")))
        ]
        .ValueContent()
        .MaxDesiredWidth(125.f)
        .MinDesiredWidth(125.f)
        [
            SNew(SButton)
            .ContentPadding(2)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .OnClicked(this, &IVoxelWorldDetails::CreateTextureInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Create texture")))
            ]
        ];
}

FReply IVoxelWorldDetails::CreateWorldInEditor()
{
    if (World.IsValid())
    {
        World->VoxelScenePlayerClass = AVoxelPlayerEditor::StaticClass();
        World->CreateVoxelWorldInEditor();

        // Check if the world was successfully created
        if (World->bWorldCreated)
        {
            World->bCreatedInEditor = true;
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}

FReply IVoxelWorldDetails::DestroyWorldInEditor()
{
    if (World.IsValid())
    {
        World->DestroyVoxelWorld();

        // Check if the world was successfully destroyed
        if (!World->bWorldCreated)
        {
            World->bCreatedInEditor = false;
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}

FReply IVoxelWorldDetails::SaveWorldInEditor()
{
    if (World.IsValid())
    {
        World->SaveWorldUtility();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}

FReply IVoxelWorldDetails::CreateTextureInEditor()
{
    if (World.IsValid())
    {
        World->CreateTextureDensityMap();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}