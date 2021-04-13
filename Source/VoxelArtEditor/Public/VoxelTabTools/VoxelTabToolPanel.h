#pragma once

#include "SDockTab.h"
#include "SDockableTab.h"
#include "SDockTabStack.h"
#include "SlateApplication.h"

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