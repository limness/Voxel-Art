// Voxel Art Plugin © limit 2018

#pragma once

#include "Toolkits/BaseToolkit.h"
#include "VoxelEdMode.h"
#include "VoxelEdModeWidget.h"

class FExampleEdModeToolkit : public FModeToolkit
{
public:
    FExampleEdModeToolkit()
    {
        SAssignNew(VoxelEdModeWidget, SVoxelEdModeWidget);
    }

    /** IToolkit interface */
    virtual FName GetToolkitFName() const override { return FName("VoxelEdMode"); }
    virtual FText GetBaseToolkitName() const override { return NSLOCTEXT("BuilderModeToolkit", "DisplayName", "Builder"); }
    virtual class FEdMode* GetEditorMode() const override { return GLevelEditorModeTools().GetActiveMode(FVoxelEdMode::EM_Example); }
    virtual TSharedPtr<class SWidget> GetInlineContent() const override { return VoxelEdModeWidget; }

private:
    TSharedPtr<SVoxelEdModeWidget> VoxelEdModeWidget;
};
