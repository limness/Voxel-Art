// Voxel Art Plugin © limit 2018

#include "VoxelTabTools/VoxelTabToolPanel.h"
#include "VoxelTabTools/VoxelTabTool.h"
#include "VoxelModuleInterface.h"

//#define LOCTEXT_NAMESPACE "SStandardSlateWidget"

void FVoxelTabToolPanel::Construct(const FArguments& InArgs)
{
    tool = InArgs._Tool;
    if (tool.IsValid())
    {
    }

	FString ImagePath = IPluginManager::Get().FindPlugin(TEXT("VoxelArt"))->GetContentDir() / TEXT("EditorResources/IconEditorMode.png");
	FName BrushName = FName(*ImagePath);

	FString Description = 
		"This is a tool that allows you to create entire worlds that you can modify directly in game mode.\
		Landscapes can be completely different shapes, flat, ribbed, planetary, dune, it all depends on your imagination.";
	
	FString GetStarted = 
		"1. Move the new Voxel World component into the editor place\n\
		2. Go to the gamemode section and select Voxel Controller as the main controller\n\
		4. Select the desired world size in the Voxel World component tab\n\
		5. Select the required voxel size\n\
		6. Select the material\n\
		7. Select the world noise generator\n\
		9. Press the Start button\n\n\
		For any other questions, tweet or join our discord channel below\n\
		Enjoy!";

	FString AboutPlugin = "Plugin Version: 0.22\nTwitter: twitter.com/limtosingular\nDiscord channel: discord.gg/FX3zzNxPq3";

    ChildSlot
        [
            SNew(SScrollBox)
            + SScrollBox::Slot()
            //.VAlign(VAlign_Top)
            [
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
					//	SNew(SBorder)
						SNew(SOverlay)
						+ SOverlay::Slot()
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Center)
						[
							SNew(SBox)
							.WidthOverride(128)
							.HeightOverride(128)
							[
								SNew(SCanvas)
								+ SCanvas::Slot()
								.Size(FVector2D(128, 128))
								[
									SNew(SImage)
									.Image(new FSlateImageBrush(BrushName, FVector2D(128, 128)))
								]
							]
						]
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SOverlay)
						+ SOverlay::Slot()
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Top)
							.HAlign(HAlign_Center)
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(IPluginManager::Get().FindPlugin(TEXT("VoxelArt"))->GetContentDir() / TEXT("EditorResources/Fonts/BebasNeue Bold.otf"), 24))
								.Text(FText::FromString(TEXT("Voxel Art Free")))
							]
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Top)
							.HAlign(HAlign_Center)
							.Padding(2.f)
							[
								SNew(STextBlock)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(IPluginManager::Get().FindPlugin(TEXT("VoxelArt"))->GetContentDir() / TEXT("EditorResources/Fonts/BebasNeue Book.otf"), 14))
								.Text(FText::FromString(TEXT("Plugin")))
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Center)
						.Padding(2.f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.MaxWidth(516)
							[
								SNew(STextBlock)
								.AutoWrapText(true)
								.Justification(ETextJustify::Center)
								.Text(FText::FromString(Description))
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.Padding(20.f)
				[
					SNew(SHeader)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.AutoWrapText(true)
							.Justification(ETextJustify::Center)
							.Text(FText::FromString(TEXT("Get started")))
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Center)
						.Padding(2.f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.MaxWidth(1024)
							[
								SNew(STextBlock)
								.AutoWrapText(true)
								.Justification(ETextJustify::Center)
								.Text(FText::FromString(GetStarted))
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.Padding(20.f)
				[
					SNew(SHeader)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.AutoWrapText(true)
							.Justification(ETextJustify::Center)
							.Text(FText::FromString(TEXT("About Plugin")))
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Center)
						.Padding(2.f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.MaxWidth(516)
							[
								SNew(STextBlock)
								.AutoWrapText(true)
								.Justification(ETextJustify::Center)
								.Text(FText::FromString(AboutPlugin))
							]
						]
					]
				]
			]
        ];
}
