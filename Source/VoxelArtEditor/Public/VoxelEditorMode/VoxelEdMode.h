// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "EditorModes.h"
#include "EdMode.h"
#include "GameFramework/Actor.h"

class AVoxelWorld;
class AVoxelEditorTool;
class UVoxelEditorData;

class FVoxelEdMode : public FEdMode
{
public:

    const static FEditorModeID EM_Example;

    FVoxelEdMode();

    virtual void Enter() override;
    virtual void Exit() override;

private:

    bool EditorRemovePressed = false;
    bool EditorCreatePressed = false;

    FVector HitWorldPosition;
    AVoxelWorld* HitWorld;

protected:

    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

    virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;

    virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;

    virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;

    virtual bool CapturedMouseMove(FEditorViewportClient* InViewportClient, FViewport* InViewport, int32 InMouseX, int32 InMouseY) override;

    virtual bool IsSelectionAllowed(AActor* InActor, bool bInSelection) const override;

    virtual bool DisallowMouseDeltaTracking() const override;

private:

    UVoxelEditorData* EditorData;
    AVoxelEditorTool* EditorTool;

public:

    UVoxelEditorData* GetEditorData() { return EditorData; }
};
