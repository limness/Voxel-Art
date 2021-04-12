
#pragma once

#include "SlateApplication.h"


class IDetailsView;
class AVoxelWorld;
class UVoxelEditorData;

class SVoxelEdModeWidget : public SCompoundWidget
{

public:

    SLATE_BEGIN_ARGS(SVoxelEdModeWidget) {}
    SLATE_END_ARGS();

    void Construct(const FArguments& InArgs);
    virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, float InDeltaTime);

    // Util Functions
    class FVoxelEdMode* GetEdMode() const;

    /** Set the objects to be displayed in the details panel */
    void SetDetailsObjects(const TArray<TWeakObjectPtr<>>& InObjects);

    /** The details view we do most of our work within */
    TSharedPtr<IDetailsView> DetailsView;

    FReply CreateWorldInEditor();

public:

    UVoxelEditorData* EditorTools;

    TSharedPtr<class SWidget> EditorObject;
    TSharedPtr<class SWidget> ErrorEditorObject;

    TWeakObjectPtr<UWorld> World;
};