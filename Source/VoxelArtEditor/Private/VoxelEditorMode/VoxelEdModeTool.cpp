
//#include "ToolExampleEditor/ToolExampleEditor.h"
#include "VoxelEdModeTool.h"
#include "VoxelModuleInterface.h"
#include "VoxelEdMode.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)

TSharedPtr< FSlateStyleSet > FVoxelEdModeTool::StyleSet = nullptr;

void FVoxelEdModeTool::OnStartupModule()
{
    RegisterStyleSet();
    RegisterEditorMode();
}

void FVoxelEdModeTool::OnShutdownModule()
{
    UnregisterStyleSet();
    UnregisterEditorMode();
}

void FVoxelEdModeTool::RegisterStyleSet()
{
    // Const icon sizes
    const FVector2D Icon20x20(20.0f, 20.0f);
    const FVector2D Icon40x40(40.0f, 40.0f);

    // Only register once
    if (StyleSet.IsValid())
    {
        return;
    }

    StyleSet = MakeShareable(new FSlateStyleSet("ExampleEdModeToolStyle"));
    StyleSet->SetContentRoot(FPaths::GameContentDir() / TEXT("/EditorResources"));
    StyleSet->SetCoreContentRoot(FPaths::GameContentDir() / TEXT("/EditorResources"));

    // Spline editor
    {
        StyleSet->Set("VoxelEdMode", new IMAGE_BRUSH(TEXT("IconEditorMode"), Icon40x40));
        StyleSet->Set("VoxelEdMode.Small", new IMAGE_BRUSH(TEXT("IconEditorMode"), Icon20x20));
    }

    FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
}

void FVoxelEdModeTool::UnregisterStyleSet()
{
    if (StyleSet.IsValid())
    {
        FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
        ensure(StyleSet.IsUnique());
        StyleSet.Reset();
    }
}

void FVoxelEdModeTool::RegisterEditorMode()
{
    FEditorModeRegistry::Get().RegisterMode<FVoxelEdMode>(
        FVoxelEdMode::EM_Example,
        FText::FromString("Example Fuk it Mode"),
        FSlateIcon(StyleSet->GetStyleSetName(), "VoxelEdMode", "VoxelEdMode.Small"),
        true, 500
        );
}

void FVoxelEdModeTool::UnregisterEditorMode()
{
    FEditorModeRegistry::Get().UnregisterMode(FVoxelEdMode::EM_Example);
}

#undef IMAGE_BRUSH