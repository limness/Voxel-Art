// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelEditorMode/VoxelEdMode.h"
#include "VoxelEditorMode/VoxelEdModeToolkit.h"
#include "VoxelModuleInterface.h"
#include "Editor/UnrealEd/Public/Toolkits/ToolkitManager.h"
#include "ScopedTransaction.h"
#include "VoxelWorld.h"
#include "Editor/VoxelEditorData.h"
#include "Editor/VoxelEditorTool.h"
#include "Editor/VoxelModificationWorld.h"

const FEditorModeID FVoxelEdMode::EM_Example(TEXT("EM_Example"));

//#define LOCTEXT_NAMESPACE "PListEditor"

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
			
			switch (EditorData->BrushShape)
			{
			case EBrushShape::Sphere: { UVoxelModificationWorld::SpherePainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius); break; }
			case EBrushShape::Cube: { UVoxelModificationWorld::CubePainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius); break; }
			case EBrushShape::Torus: { UVoxelModificationWorld::TorusPainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius, EditorData->InnerRadius); break; }
			case EBrushShape::Cone: { UVoxelModificationWorld::ConePainter(EditorData, HitWorld, HitVoxelWorldPosition, EditorData->Radius, EditorData->Height, EditorData->Angle); break; }
			}
		}
	}
}

bool FVoxelEdMode::DisallowMouseDeltaTracking() const
{
	return EditorRemovePressed;
}
		
/*AsyncTask(ENamedThreads::GameThread, [=]()
	{

		DrawDebugPoint
		(
			World->GetWorld(),
			(FVector)DensityLocation,
			25.f,
			FColor::Red,
			false,
			25.f
		);
	});*/