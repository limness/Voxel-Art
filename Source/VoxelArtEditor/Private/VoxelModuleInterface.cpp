
#include "VoxelModuleInterface.h"
#include "VoxelLandscapeDetails.h"

#include "VoxelLandscape.h"

//#include "CustomAssetEditorModule.h"

IMPLEMENT_GAME_MODULE(IVoxelModuleInterface, VoxelArtEditor);

#define LOCTEXT_NAMESPACE "IVoxelModuleInterface"


TSharedRef<FWorkspaceItem> IVoxelModuleInterface::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));


void IVoxelModuleInterface::AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList, EExtensionHook::Position position)
{
    MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void IVoxelModuleInterface::MakePulldownMenu(FMenuBarBuilder& menuBuilder)
{
    menuBuilder.AddPullDownMenu(
        FText::FromString("Voxel Art"),
        FText::FromString("Open the Voxel Art help menu"),
        FNewMenuDelegate::CreateRaw(this, &IVoxelModuleInterface::FillPulldownMenu),
        "Voxel Art",
        FName(TEXT("ExampleMenu"))
    );
}

void IVoxelModuleInterface::FillPulldownMenu(FMenuBuilder& menuBuilder)
{
    menuBuilder.BeginSection("ExampleSection", FText::FromString("No sections yet"));
    menuBuilder.AddMenuSeparator(FName("Section_1"));
    menuBuilder.EndSection();
}

void IVoxelModuleInterface::StartupModule()
{
    if (!IsRunningCommandlet())
    {
        FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
        LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
        MenuExtender = MakeShareable(new FExtender);
        MenuExtender->AddMenuBarExtension("Help", EExtensionHook::After, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &IVoxelModuleInterface::MakePulldownMenu));
        LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
    }

    {
        static FName PropertyEditor("PropertyEditor");
        FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);
        PropertyModule.RegisterCustomClassLayout(AVoxelLandscape::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&IVoxelLandscapeDetails::MakeInstance));
    }

	UE_LOG(LogTemp, Warning, TEXT("Startup Voxel Editor Module()"));
}

void IVoxelModuleInterface::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Shutdown Voxel Editor Module()"));
}

#undef LOCTEXT_NAMESPACE