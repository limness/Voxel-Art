// Voxel Art Plugin © limit 2018

#pragma once

#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Docking/SDockableTab.h"
#include "Widgets/Docking/SDockTabStack.h"
#include "Framework/Application/SlateApplication.h"

class VoxelTabTool;

class FVoxelTabToolPanel : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(FVoxelTabToolPanel)
    {}
    SLATE_ARGUMENT(TWeakPtr<class FVoxelTabTool>, Tool)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

protected:
    TWeakPtr<FVoxelTabTool> tool;
};