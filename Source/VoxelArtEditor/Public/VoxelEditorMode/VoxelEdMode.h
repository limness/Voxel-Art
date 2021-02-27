
#pragma once

#include "EdMode.h"
#include "EditorModes.h"


class UVoxelEditorData;
class AVoxelLandscape;

class FVoxelEdMode : public FEdMode
{
public:

    const static FEditorModeID EM_Example;

    virtual void Enter() override;
    virtual void Exit() override;

private:

    bool EditorRemovePressed = false;
    bool EditorCreatePressed = false;

    FIntVector HitWorldPosition;
    AVoxelLandscape* HitWorld;

protected:

    virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;

    virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;

    virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;

    virtual bool DisallowMouseDeltaTracking() const override;

private:

    UVoxelEditorData* EditorData;

public:

    UVoxelEditorData* GetEditorData() { return EditorData; }
};

