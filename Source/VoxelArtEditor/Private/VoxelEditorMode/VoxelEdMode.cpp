

#include "VoxelEdMode.h"
#include "VoxelModuleInterface.h"
#include "Editor/UnrealEd/Public/Toolkits/ToolkitManager.h"
#include "ScopedTransaction.h"
#include "VoxelEdModeToolkit.h"

#include "VoxelLandscape.h"
#include "Editor/VoxelEditorData.h"
#include "Editor/VoxelModificationLandscape.h"


const FEditorModeID FVoxelEdMode::EM_Example(TEXT("EM_Example"));

#define LOCTEXT_NAMESPACE "PListEditor"


void FVoxelEdMode::Enter()
{
    FEdMode::Enter();

	EditorData = NewObject<UVoxelEditorData>(GetTransientPackage(), *LOCTEXT("SettingsName", "EmpexEdMode Settings").ToString());

	FActorSpawnParameters SpawnParams;
	SpawnParams.ObjectFlags = RF_Transient;

	EditorTool = GetWorld()->SpawnActor<AVoxelEditorTool>(AVoxelEditorTool::StaticClass(), SpawnParams);

    if (!Toolkit.IsValid())
    {
        Toolkit = MakeShareable(new FExampleEdModeToolkit);
        Toolkit->Init(Owner->GetToolkitHost());
    }
}

void FVoxelEdMode::Exit()
{
    FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
    Toolkit.Reset();

	EditorTool->Destroy();

    FEdMode::Exit();
}

bool FVoxelEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	if (Event == IE_Pressed)
	{
		if (Key == EKeys::LeftMouseButton)
		{
			EditorRemovePressed = true;
			//return true;
		}
		if (Key == EKeys::RightMouseButton)
		{
			EditorCreatePressed = true;
		}
	}
	else if (Event == IE_Released)
	{
		if (Key == EKeys::LeftMouseButton)
		{
			EditorRemovePressed = false;
		}
		if (Key == EKeys::RightMouseButton)
		{
			EditorCreatePressed = false;
		}
	}
	return false;
}

bool FVoxelEdMode::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y)
{
	//if (EditorCreatePressed)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamilyContext::ConstructionValues(ViewportClient->Viewport, ViewportClient->GetScene(), ViewportClient->EngineShowFlags).SetRealtimeUpdate(ViewportClient->IsRealtime()));
		FSceneView* SceneView = ViewportClient->CalcSceneView(&ViewFamily);
		FViewportCursorLocation MouseViewportRay(SceneView, ViewportClient, x, y);

		FVector Start = MouseViewportRay.GetOrigin();
		FVector End = MouseViewportRay.GetDirection() * WORLD_MAX + Start;

		TArray<FHitResult> MouseHitResults;

		if (GetWorld()->LineTraceMultiByChannel(MouseHitResults, Start, End, ECC_Visibility))
		{
			for (auto& Hit : MouseHitResults)
			{
				HitWorld = Cast<AVoxelLandscape>(Hit.Component->GetOwner());

				if (HitWorld)
				{
					HitWorldPosition = HitWorld->TransferToVoxelWorld(Hit.ImpactPoint);
					EditorTool->Marker->SetWorldLocation(Hit.ImpactPoint);
					EditorTool->Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * EditorData->Radius * 2.f);
				}
			}
		}
	}
    return EditorCreatePressed;
}

void FVoxelEdMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	if (EditorRemovePressed)
	{
		if (HitWorld)
		{
			switch (EditorData->BrushType)
			{
			case BrushType::Sphere: { UVoxelModificationLandscape::SpherePainter(EditorData, HitWorld, HitWorldPosition, EditorData->Radius); break; }
			case BrushType::Cube: { UVoxelModificationLandscape::CubePainter(EditorData, HitWorld, HitWorldPosition, EditorData->Radius); break; }
			}
		}
	}
}

bool FVoxelEdMode::DisallowMouseDeltaTracking() const
{
	return false;
}

/*
DrawDebugPoint
(
	GetWorld(),
	Hit.ImpactPoint,
	15.f,
	FColor::Red,
	false,
	5.f
);
*/