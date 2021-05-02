// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelModuleInterface.h"
#include "Developer/Settings/Public/ISettingsContainer.h"
#include "VoxelSettings/VoxelCustomSettings.h"
#include "VoxelDetailsCustomization/VoxelWorldDetails.h"
#include "VoxelEditorMode/VoxelEdModeTool.h"
#include "ISettingsModule.h"
#include "IPlacementModeModule.h"

#include "VoxelFactories/VoxelWorldFactory.h"
#include "VoxelTabTools/VoxelTabTool.h"
#include "VoxelSaveUtilities.h"
#include "VoxelEditorListeners.h"
#include "VoxelLoggingEditor.h"
#include "VoxelTypeActions.h"

#include "Save/VoxelSaveInterface.h"
#include "VoxelFoliageConfig.h"
#include "VoxelListenersInterface.h"
#include "VoxelLoggingInterface.h"
#include "VoxelWorld.h"

IMPLEMENT_GAME_MODULE(IVoxelModuleInterface, VoxelArtEditor);


#define LOCTEXT_NAMESPACE "IVoxelModuleInterface"

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

TSharedRef<FWorkspaceItem> IVoxelModuleInterface::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

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
    // register placeable types:
    {
        FPlacementCategoryInfo Info(LOCTEXT("Voxel Art", "Voxel Art"), "VoxelArt", TEXT("PMVoxelArt"), 30);
        IPlacementModeModule::Get().RegisterPlacementCategory(Info);
        IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShared<FPlaceableItem>(GetMutableDefault<UVoxelWorldFactory>(), FAssetData(AVoxelWorld::StaticClass())));
    }
    // register custom types:
    {
        IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
        EAssetTypeCategories::Type VoxelCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Voxel Art")), FText::FromString("Voxel Art"));

        TSharedPtr<IAssetTypeActions> VoxelSaveObjectAction = MakeShareable(new FVoxelSaveObject_AssetsTypeActions(VoxelCategory));
        TSharedPtr<IAssetTypeActions> VoxelFoliageConfigAction = MakeShareable(new FVoxelFoliageConfig_AssetsTypeActions(VoxelCategory));

        AssetTools.RegisterAssetTypeActions(VoxelSaveObjectAction.ToSharedRef());
        AssetTools.RegisterAssetTypeActions(VoxelFoliageConfigAction.ToSharedRef());

        CreatedAssetTypeActions.Add(VoxelSaveObjectAction);
        CreatedAssetTypeActions.Add(VoxelFoliageConfigAction);
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

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* Delegates startup */

    IVoxelSaveInterface::VoxelSaveDelegates.AddStatic(&FVoxelSaveUtilities::CreateVoxelStorageFile);

    IVoxelLoggingInterface::VoxelDialogLogging.AddStatic(&FVoxelLoggingEditor::DialogMessage);
    IVoxelLoggingInterface::VoxelMessageLogging.AddStatic(&FVoxelLoggingEditor::LogMessage);

    IVoxelListenersInterface::VoxelListenersDelegates.AddStatic(&FVoxelEditorListeners::StartListeners);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

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
    {
        IPlacementModeModule::Get().UnregisterPlacementCategory("VoxelArt");
    }
    // Unregister all the asset types that we registered
    if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
    {
        IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
        for (int32 i = 0; i < CreatedAssetTypeActions.Num(); ++i)
        {
            AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[i].ToSharedRef());
        }
    }
    CreatedAssetTypeActions.Empty();

    /////////////////////////////
    /////////////////////////////

	UE_LOG(LogTemp, Log, TEXT("Shutdown Voxel Art Editor Module()"));
}

#undef LOCTEXT_NAMESPACE