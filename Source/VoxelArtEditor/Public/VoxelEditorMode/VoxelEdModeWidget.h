
#pragma once

#include "SlateApplication.h"


class IDetailsView;
class UVoxelEditorData;

class SVoxelEdModeWidget : public SCompoundWidget
{

public:

    SLATE_BEGIN_ARGS(SVoxelEdModeWidget) {}
    SLATE_END_ARGS();

    void Construct(const FArguments& InArgs);

    // Util Functions
    class FVoxelEdMode* GetEdMode() const;

    /** Set the objects to be displayed in the details panel */
    void SetDetailsObjects(const TArray<TWeakObjectPtr<>>& InObjects);

    /** The details view we do most of our work within */
    TSharedPtr<IDetailsView> DetailsView;

    FReply CreateWorldInEditor();

public:

    UVoxelEditorData* EditorTools;
};