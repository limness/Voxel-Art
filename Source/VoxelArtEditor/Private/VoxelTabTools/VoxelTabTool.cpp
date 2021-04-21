// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelTabTools/VoxelTabTool.h"
#include "VoxelTabTools/VoxelTabToolPanel.h"
#include "VoxelSettings/VoxelCustomSettings.h"
#include "VoxelModuleInterface.h"

void FVoxelTabTool::OnStartupModule()
{
    FVoxelTabToolBase::OnStartupModule();

    UVoxelCustomSettings* VoxelCustomMutableSettings = GetMutableDefault<UVoxelCustomSettings>();

    if (VoxelCustomMutableSettings && !VoxelCustomMutableSettings->bWelcomeShowed)
    {
        TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();


#if ENGINE_MINOR_VERSION < 26
        tm->InvokeTab(TabName);

        VoxelCustomMutableSettings->bWelcomeShowed = true;
        VoxelCustomMutableSettings->SaveConfig();
#else
        if (tm->TryInvokeTab(TabName))
        {
            VoxelCustomMutableSettings->bWelcomeShowed = true;
            VoxelCustomMutableSettings->SaveConfig();
        }
#endif
    }
}

void FVoxelTabTool::OnShutdownModule()
{
    FVoxelTabToolBase::OnShutdownModule();

    TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
    tm->UnregisterTabSpawner(TabName);
}

void FVoxelTabTool::Initialize()
{
    TabName = "VoxelWelcome";
    TabDisplayName = FText::FromString("Welcome - Voxel Art Plugin");
    ToolTipText = FText::FromString("Voxel Window");
}

TSharedRef<SDockTab> FVoxelTabTool::SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
{
    TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(FVoxelTabToolPanel)
            .Tool(SharedThis(this))
        ];

    return SpawnedTab;
}