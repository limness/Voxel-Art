
#include "VoxelLandscapeDetails.h"
#include "VoxelModuleInterface.h"
//#include "VoxelLandscape.h"

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
}

FReply IVoxelLandscapeDetails::CreateWorldInEditor()
{
    if (World.IsValid())
    {
        //UE_LOG(LogTemp, Warning, TEXT("Startup %d"), World->voxelsOneChunk);
        World->CreateVoxelWorld();
    }
    return FReply::Handled();
}