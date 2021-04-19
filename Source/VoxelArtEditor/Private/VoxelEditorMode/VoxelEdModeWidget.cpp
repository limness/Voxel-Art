// Voxel Art Plugin © limit 2018

#include "VoxelEditorMode/VoxelEdModeWidget.h"
#include "VoxelEditorMode/VoxelEdMode.h"
#include "VoxelModuleInterface.h"
#include "EngineUtils.h"
#include "Editor/VoxelEditorData.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"

//#define LOCTEXT_NAMESPACE "PListEditor"

void SVoxelEdModeWidget::Construct(const FArguments& InArgs)
{
	TSharedPtr<SVerticalBox> ToolBarsVerticalBox;

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs(false, false, false, FDetailsViewArgs::HideNameArea);

	EditorTools = GetEdMode()->GetEditorData();

	DetailsView = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor").CreateDetailView(DetailsViewArgs);
	DetailsView->SetObject(EditorTools);

	World = GetEdMode()->GetWorld();

	bool bShowTools = false;

	if (World.IsValid())
	{
		for (auto* VoxelWorld : TActorRange<AVoxelWorld>(World.Get()))
		{
			bShowTools = true;

			if (!VoxelWorld->bWorldCreated)
			{
				VoxelWorld->CreateVoxelWorldInEditor();
			}
			// Do not show the tools if world is not created
			if (!VoxelWorld->bWorldCreated)
			{
				bShowTools = false;
			}
			break;
		}
		if (World->WorldType != EWorldType::Editor)
		{
			bShowTools = false;
		}
	}

	FString ErrorDescription =
		"No one Voxel World was found on the game scene\nPlease create the Voxel World manually through the editor panel and come back here again :)";

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
					//.BorderBackgroundColor(FLinearColor(0.0296f, 0.0296f, 0.0296f, 1.f)) // Dark Grey
					.BorderBackgroundColor(FLinearColor(0.122f, 0.138f, 0.491f, 1.f)) // Voxel Blue
					.BorderImage(FCoreStyle::Get().GetBrush("ErrorReporting.Box"))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(5.0f)
						//.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(IPluginManager::Get().FindPlugin(TEXT("VoxelArt"))->GetContentDir() / TEXT("EditorResources/Fonts/BebasNeue Book.otf"), 14))
								.Text(FText::FromString(TEXT("Voxel Art")))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(IPluginManager::Get().FindPlugin(TEXT("VoxelArt"))->GetContentDir() / TEXT("EditorResources/Fonts/BebasNeue Bold.otf"), 14))
								.Text(FText::FromString(TEXT("Editor")))
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(EditorObject, SVerticalBox)
					.Visibility(bShowTools ? EVisibility::Visible : EVisibility::Collapsed)
					+ SVerticalBox::Slot()
					[
						DetailsView.ToSharedRef()
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(ErrorEditorObject, SVerticalBox)
					.Visibility(bShowTools ? EVisibility::Collapsed : EVisibility::Visible)
					
					+ SVerticalBox::Slot()
					.Padding(10.f)
					[
						SNew(STextBlock)
						.AutoWrapText(true)
						.Justification(ETextJustify::Center)
						.ColorAndOpacity(FLinearColor::White)
						.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
						.Text(FText::FromString(ErrorDescription))
					]
				]
			]
        ];
}


void SVoxelEdModeWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, float InDeltaTime)
{
	bool bShowError = true;

	if(GEditor->bIsSimulatingInEditor || (GEditor->PlayWorld != NULL))
	{
		if (ErrorEditorObject->GetVisibility() == EVisibility::Collapsed)
		{
			ErrorEditorObject->SetVisibility(EVisibility::Visible);
		}
		if (EditorObject->GetVisibility() == EVisibility::Visible)
		{
			EditorObject->SetVisibility(EVisibility::Collapsed);
		}
		return;
	}
	if (World.IsValid())
	{
		for (auto* VoxelWorld : TActorRange<AVoxelWorld>(World.Get()))
		{
			if (ErrorEditorObject->GetVisibility() == EVisibility::Visible)
			{
				ErrorEditorObject->SetVisibility(EVisibility::Collapsed);
			}
			if (EditorObject->GetVisibility() == EVisibility::Collapsed)
			{
				EditorObject->SetVisibility(EVisibility::Visible);
			}
			if (!VoxelWorld->bWorldCreated)
			{
				bShowError = true;
			}
			else
			{
				bShowError = false;
			}
			break;
		}
	}
	if(bShowError)
	{
		if (ErrorEditorObject->GetVisibility() == EVisibility::Collapsed)
		{
			ErrorEditorObject->SetVisibility(EVisibility::Visible);
		}
		if (EditorObject->GetVisibility() == EVisibility::Visible)
		{
			EditorObject->SetVisibility(EVisibility::Collapsed);
		}
		return;
	}

	//if (DetailsView.Get() != nullptr)
	{
	//	UE_LOG(LogTemp, Warning, TEXT("EditorTools is not"));
	}
	//else
	{
		
		//	UE_LOG(LogTemp, Warning, TEXT("EditorTools it is"));
	}
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