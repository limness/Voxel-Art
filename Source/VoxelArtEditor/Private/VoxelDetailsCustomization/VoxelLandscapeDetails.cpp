
#include "VoxelLandscapeDetails.h"
#include "VoxelModuleInterface.h"
#include "Helpers/VoxelTools.h"

TSharedRef<IDetailCustomization> IVoxelLandscapeDetails::MakeInstance()
{
    return MakeShareable(new IVoxelLandscapeDetails);
}

void IVoxelLandscapeDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
    TArray<TWeakObjectPtr<UObject>> Objects;
    DetailLayout.GetObjectsBeingCustomized(Objects);
    if (Objects.Num() != 1)
    {
        return;
    }

    World = (AVoxelLandscape*)Objects[0].Get();

    // hide original property
   // DetailLayout.HideProperty(DetailLayout.GetProperty(GET_MEMBER_NAME_CHECKED(AVoxelLandscape, &AVoxelLandscape::CreateVoxelWorld)));
   // DetailLayout.HideProperty(DetailLayout.GetProperty(GET_MEMBER_NAME_CHECKED(AVoxelLandscape, bOption2)));

    // add custom widget to "Options" category
    IDetailCategoryBuilder& OptionsCategory = DetailLayout.EditCategory("Main", FText::FromString(""), ECategoryPriority::Important);
   
  //  auto& Builder = static_cast<FDetailCategoryImpl&>(DetailLayout.EditCategory(Name, NewNameText));
  //  Builder.SortCategories
   //     OptionsCategory.Sort
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
            .OnClicked(this, &IVoxelLandscapeDetails::CreateWorldInEditor)
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
            .OnClicked(this, &IVoxelLandscapeDetails::UpdateWorldInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Update World")))
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
            .OnClicked(this, &IVoxelLandscapeDetails::DestroyWorldInEditor)
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
            .OnClicked(this, &IVoxelLandscapeDetails::CreateWorldInEditor)
            [
                SNew(STextBlock)
                .Font(IDetailLayoutBuilder::GetDetailFont())
                .Text(FText::FromString(TEXT("Create texture")))
            ]
        ];
}

FReply IVoxelLandscapeDetails::CreateWorldInEditor()
{
    if (World.IsValid())
    {
        World->CreateVoxelWorld();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}

FReply IVoxelLandscapeDetails::DestroyWorldInEditor()
{
    if (World.IsValid())
    {
        World->DestroyVoxelWorld();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}

FReply IVoxelLandscapeDetails::UpdateWorldInEditor()
{
    if (World.IsValid())
    {
        World->UpdateWorld();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
    }
    return FReply::Handled();
}