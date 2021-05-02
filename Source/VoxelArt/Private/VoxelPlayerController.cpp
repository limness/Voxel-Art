// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerController.h"
#include "Helpers/VoxelTools.h"
#include "Editor/VoxelModificationWorld.h"

#include "DrawDebugHelpers.h"


void AVoxelPlayerController::BeginPlay()
{
	Super::BeginPlay();

	EditorData = NewObject<UVoxelEditorData>(GetTransientPackage());
}

bool AVoxelPlayerController::InputKey(FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad)
{
	Super::InputKey(Key, Event, AmountDepressed, bGamepad);

	if (Event == IE_Pressed)
	{
		if (Key == EKeys::LeftMouseButton)
		{
			EditorRemovePressed = true;
			return true;
		}
		if (Key == EKeys::RightMouseButton)
		{
			EditorCreatePressed = true;
			return true;
		}
	}
	else if (Event == IE_Released)
	{
		if (Key == EKeys::LeftMouseButton)
		{
			EditorRemovePressed = false;
			return true;
		}
		if (Key == EKeys::RightMouseButton)
		{
			EditorCreatePressed = false;
			return true;
		}
	}
	return false;
}

void AVoxelPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EditorRemovePressed || EditorCreatePressed)
	{
		FHitResult MouseHitResult;

		if(GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, MouseHitResult))
		{
			if (MouseHitResult.bBlockingHit)
			{
				if (GEngine)
				{
					ChangeWorld(Cast<AVoxelWorld>(MouseHitResult.Component->GetOwner()), MouseHitResult.Location);
				}
			}
		}
		if (GetBrushSoftness() != EBrushSoftness::Smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

void AVoxelPlayerController::ChangeWorld(AVoxelWorld* World, FVector HitPosition)
{
	if (World)
	{
		FIntVector WorldPosition = World->TransferToVoxelWorld(HitPosition);

		switch (GetBrushShape())
		{
		case EBrushShape::Sphere:	{ UVoxelModificationWorld::SpherePainter(EditorData, World, WorldPosition, GetBrushRadius());		break; }
		case EBrushShape::Cube:		{ UVoxelModificationWorld::CubePainter(EditorData, World, WorldPosition, GetBrushRadius());			break; }
		case EBrushShape::Torus:	{ UVoxelModificationWorld::TorusPainter(EditorData, World, WorldPosition, GetBrushRadius(), 5.f);	break; }
		}
	}
}

void AVoxelPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AVoxelPlayerController::BeginDestroy()
{
	Super::BeginDestroy();
}

void AVoxelPlayerController::SetEditDig(bool Dig)
{
	EditorData->Dig = Dig;
}

bool AVoxelPlayerController::GetEditDig()
{
	return EditorData->Dig;
}

void AVoxelPlayerController::SetBrushShape(TEnumAsByte<EBrushShape> Shape)
{
	EditorData->BrushShape = Shape;
}

TEnumAsByte<EBrushShape> AVoxelPlayerController::GetBrushShape()
{
	return EditorData->BrushShape;
}

void AVoxelPlayerController::SetBrushSoftness(TEnumAsByte<EBrushSoftness> Softness)
{
	EditorData->BrushSoftness = Softness;
}

TEnumAsByte<EBrushSoftness> AVoxelPlayerController::GetBrushSoftness()
{
	return EditorData->BrushSoftness;
}

void AVoxelPlayerController::SetEditorType(TEnumAsByte<EEditorType> Type)
{
	EditorData->EditorType = Type;
}

TEnumAsByte<EEditorType> AVoxelPlayerController::GetEditorType()
{
	return EditorData->EditorType;
}

void AVoxelPlayerController::SetBrushRadius(float Radius)
{
	EditorData->Radius = Radius;
}

float AVoxelPlayerController::GetBrushRadius()
{
	return EditorData->Radius;
}

void AVoxelPlayerController::SetBrushColor(FColor Color)
{
	EditorData->BrushColor = Color;
}

FColor AVoxelPlayerController::GetBrushColor()
{
	return EditorData->BrushColor;
}

void AVoxelPlayerController::SetBrushStrength(float Strength)
{
	EditorData->Strength = Strength;
}

float AVoxelPlayerController::GetBrushStrength()
{
	return EditorData->Strength;
}