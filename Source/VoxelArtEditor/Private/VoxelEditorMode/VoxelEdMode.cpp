// Voxel Art Plugin © limit 2018

#include "VoxelEdMode.h"
#include "VoxelModuleInterface.h"
#include "Editor/UnrealEd/Public/Toolkits/ToolkitManager.h"
#include "ScopedTransaction.h"
#include "VoxelEdModeToolkit.h"

#include "VoxelWorld.h"
#include "Editor/VoxelEditorData.h"
#include "Editor/VoxelEditorTool.h"
#include "Editor/VoxelModificationWorld.h"
<<<<<<< HEAD
=======

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

const FEditorModeID FVoxelEdMode::EM_Example(TEXT("EM_Example"));

#define LOCTEXT_NAMESPACE "PListEditor"

FVoxelEdMode::FVoxelEdMode()
{
	EditorData = NewObject<UVoxelEditorData>(GetTransientPackage(), TEXT("VoxelArtEditor"), RF_Transactional);
}

FVoxelEdMode::FVoxelEdMode()
{
	EditorData = NewObject<UVoxelEditorData>(GetTransientPackage(), TEXT("VoxelArtEditor"), RF_Transactional);
}

void FVoxelEdMode::Enter()
{
    FEdMode::Enter();

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

void FVoxelEdMode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdMode::AddReferencedObjects(Collector);
	Collector.AddReferencedObject(EditorData);
}


bool FVoxelEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	if (Event == IE_Pressed)
	{
		if (Key == EKeys::LeftMouseButton)
		{
			EditorRemovePressed = true;
		//	return true;
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

bool FVoxelEdMode::IsSelectionAllowed(AActor* InActor, bool bInSelection) const
{
	return EditorRemovePressed; 
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
				HitWorld = Cast<AVoxelWorld>(Hit.Component->GetOwner());

				if (HitWorld)
				{
					HitWorldPosition = Hit.ImpactPoint;
				}
			}
		}
		if (HitWorld)
		{
			EditorTool->ToolInitialize(EditorData, HitWorldPosition);
		}
	}
    return EditorRemovePressed;
}

bool FVoxelEdMode::CapturedMouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 MouseX, int32 MouseY)
{
	return MouseMove(ViewportClient, Viewport, MouseX, MouseY);
}

void FVoxelEdMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	if (EditorRemovePressed)
	{
		if (HitWorld)
		{
			FIntVector HitVoxelWorldPosition = HitWorld->TransferToVoxelWorld(HitWorldPosition);

			//UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %s"), *HitVoxelWorldPosition.ToString());
			
			switch (EditorData->BrushType)
			{
			case BrushType::Sphere: { UVoxelModificationWorld::SpherePainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius); break; }
			case BrushType::Cube: { UVoxelModificationWorld::CubePainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius); break; }
			}
		}
	}
}

bool FVoxelEdMode::DisallowMouseDeltaTracking() const
{
	return EditorRemovePressed;
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