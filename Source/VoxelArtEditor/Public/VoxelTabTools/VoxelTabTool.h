// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

//#include "VoxelTabToolBase.h"
//class FVoxelTabToolPanel;

class FVoxelTabTool : public FVoxelTabToolBase
{
public:

    virtual ~FVoxelTabTool() {}
    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;
    virtual void Initialize() override;
    virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) override;
};
