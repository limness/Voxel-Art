// Voxel Art Plugin © limit 2018

#pragma once

#include "VoxelTabToolBase.h"

class FVoxelEdModeTool : public FVoxelTabToolBase
{

public:

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    virtual ~FVoxelEdModeTool() {}

private:

    static TSharedPtr< class FSlateStyleSet > StyleSet;

    void RegisterStyleSet();
    void UnregisterStyleSet();

    void RegisterEditorMode();
    void UnregisterEditorMode();
};
