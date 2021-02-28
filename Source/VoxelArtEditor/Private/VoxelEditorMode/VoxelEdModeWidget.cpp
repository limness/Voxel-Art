
#include "VoxelEdModeWidget.h"
#include "VoxelModuleInterface.h"
#include "VoxelEdMode.h"
#include "Editor/VoxelEditorData.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"

#define LOCTEXT_NAMESPACE "PListEditor"

void SVoxelEdModeWidget::Construct(const FArguments& InArgs)
{
	TSharedPtr<SVerticalBox> ToolBarsVerticalBox;

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs(false, false, false, FDetailsViewArgs::HideNameArea);

	EditorTools = GetEdMode()->GetEditorData();

	DetailsView = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor").CreateDetailView(DetailsViewArgs);
	DetailsView->SetObject(EditorTools);


    ChildSlot
        [
            SNew(SScrollBox)
            + SScrollBox::Slot()
            .VAlign(VAlign_Top)
            [
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(SBorder)
					.BorderBackgroundColor(FLinearColor(0.0296f, 0.0296f, 0.0296f, 1.f))
					.BorderImage(FCoreStyle::Get().GetBrush("ErrorReporting.Box"))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(15.0f)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("EditorResources/Fonts/BebasNeue Book.otf"), 14))
								.Text(FText::FromString(TEXT("Voxel Art")))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("EditorResources/Fonts/BebasNeue Bold.otf"), 14))
								.Text(FText::FromString(TEXT("Editor")))
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					DetailsView.ToSharedRef()
				]
			]
        ];
}

void SVoxelEdModeWidget::SetDetailsObjects(const TArray<TWeakObjectPtr<>>& InObjects)
{
	DetailsView->SetObjects(InObjects);
}

FVoxelEdMode* SVoxelEdModeWidget::GetEdMode() const
{
    return (FVoxelEdMode*)GLevelEditorModeTools().GetActiveMode(FVoxelEdMode::EM_Example);
}

FReply SVoxelEdModeWidget::CreateWorldInEditor()
{
    return FReply::Handled();
}