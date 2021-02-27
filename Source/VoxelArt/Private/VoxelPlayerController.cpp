// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelPlayerController.h"
#include "Helpers/VoxelTools.h"
#include "Editor/VoxelModificationLandscape.h"

#include "DrawDebugHelpers.h"

void AVoxelPlayerController::BeginPlay()
{
	Super::BeginPlay();

	EditorData = NewObject<UVoxelEditorData>(GetTransientPackage());

	EditorData->EditorType = EditorType;
	EditorData->BrushSoftness = BrushSoftness;
	EditorData->Dig = Dig;
	EditorData->Radius = Radius;
	EditorData->Strength = Strength;
	EditorData->Color = Color;
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
					ChangeWorld(Cast<AVoxelLandscape>(MouseHitResult.Component->GetOwner()), MouseHitResult.Location);
				}
			}
		}
		if (BrushSoftness != BrushSoftness::Smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

void AVoxelPlayerController::ChangeWorld(AVoxelLandscape* World, FVector HitPosition)
{
	if (World)
	{
		FIntVector WorldPosition = World->TransferToVoxelWorld(HitPosition);

		switch (BrushType)
		{
		case BrushType::Sphere: { UVoxelModificationLandscape::SpherePainter(EditorData, World, WorldPosition, Radius); break; }
		case BrushType::Cube: { UVoxelModificationLandscape::CubePainter(EditorData, World, WorldPosition, Radius); break; }
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