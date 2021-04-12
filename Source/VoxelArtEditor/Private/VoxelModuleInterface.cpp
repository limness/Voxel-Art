
#include "VoxelModuleInterface.h"
#include "VoxelWorldDetails.h"
#include "VoxelEdModeTool.h"

#include "ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsContainer.h"
#include "VoxelSettings/VoxelCustomSettings.h"

#include "VoxelWorld.h"
#include "VoxelTabTool.h"

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
        FText::FromString("Open Voxel Art Help Menu"),
        FNewMenuDelegate::CreateRaw(this, &IVoxelModuleInterface::FillPulldownMenu),
        "Voxel Art",
        FName(TEXT("Unable menu"))
    );
}

void IVoxelModuleInterface::FillPulldownMenu(FMenuBuilder& menuBuilder)
{
    menuBuilder.BeginSection("Unable", FText::FromString("Unable"));
    menuBuilder.AddMenuSeparator(FName("Section_2"));
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
        PropertyModule.RegisterCustomClassLayout(AVoxelWorld::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&IVoxelWorldDetails::MakeInstance));
    }
    // register settings:
    {
        ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
        if (SettingsModule)
        {
            TSharedPtr<ISettingsContainer> ProjectSettingsContainer = SettingsModule->GetContainer("Project");
            ProjectSettingsContainer->DescribeCategory("VoxelCtegory", FText::FromString("Voxel Art Category"), FText::FromString("Voxel Art settings here"));

            SettingsModule->RegisterSettings("Project", "VoxelCategory", "VoxelSettings",
                FText::FromString("Voxel Art Settings"),
                FText::FromString("Configure Voxel Art Settings"),
                GetMutableDefault<UVoxelCustomSettings>()
            );
        }
    }

    ModuleListeners.Add(MakeShareable(new FVoxelEdModeTool));
    ModuleListeners.Add(MakeShareable(new FVoxelTabTool));

    for (int32 i = 0; i < ModuleListeners.Num(); ++i)
    {
        ModuleListeners[i]->OnStartupModule();
    }

	UE_LOG(LogTemp, Log, TEXT("Startup Voxel Art Editor Module()"));
}

void IVoxelModuleInterface::ShutdownModule()
{
    ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->UnregisterSettings("Project", "UnableCategory", "VoxelSettings");
    }

	UE_LOG(LogTemp, Log, TEXT("Shutdown Voxel Art Editor Module()"));
}

#undef LOCTEXT_NAMESPACE