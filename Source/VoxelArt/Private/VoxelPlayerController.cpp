// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelPlayerController.h"
#include "Helpers/VoxelTools.h"
#include "Helpers/VoxelCollisionBox.h"

void AVoxelPlayerController::BeginPlay()
{
	Super::BeginPlay();
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

		if(this->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, MouseHitResult))
		{
			if (MouseHitResult.bBlockingHit)
			{
				if (GEngine)
				{
					if (RenderType == EditorType::Color)
					{
						ChangeWorldColor(Cast<AVoxelLandscape>(MouseHitResult.Component->GetOwner()), MouseHitResult.Location);
					}
					else if (RenderType == EditorType::Terrain)
					{
						ChangeWorldTerrain(Cast<AVoxelLandscape>(MouseHitResult.Component->GetOwner()), MouseHitResult.Location);
					}
				}
			}
		}
		if (!Smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

#include "DrawDebugHelpers.h"

void AVoxelPlayerController::ChangeWorldTerrain(AVoxelLandscape* World, FVector HitPosition)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);
	float CurrentValue = 0.f;

	if (World)
	{
		//if (EditorRemovePressed)
		{
			World->OctreeMutex.Lock();

			for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
			{
				for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
				{
					for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
					{
						FVector PositionVoxel = FVector(X, Y, Z);
						float offset = 0.001f;
						float ValueSphere = Radius - offset - PositionVoxel.Size();
						World->SetVoxelValue((FIntVector)PositionVoxel + World->TransferToVoxelWorld(HitPosition), ValueSphere, FColor(77.f, 77.f, 77.f), true, false);

						//DrawDebugPoint(World->GetWorld(), World->TransferToGameWorld((FIntVector)PositionVoxel + World->TransferToVoxelWorld(HitPosition)), 30, FColor::Red, false, 25);
					}
				}
			}
			FVoxelCollisionBox Box = FVoxelCollisionBox(World, World->TransferToVoxelWorld(HitPosition), VoxelsRadius * 2);
			TArray<TSharedPtr<FVoxelOctreeData>> OverlapOctants;
			
			World->GetOverlapingOctree(Box, World->MainOctree, OverlapOctants);

			for (auto& Octant : OverlapOctants)
			{
				if (Octant->Data != nullptr)
				{
					if (IsValid(Octant->Data->Chunk))
					{
						World->PutChunkOnGeneration(Octant->Data);
					}
				}
			}

			World->OctreeMutex.Unlock();
		}
	}
}

void AVoxelPlayerController::ChangeWorldColor(AVoxelLandscape* World, FVector HitPosition)
{
	int VoxelsRadius = FMath::CeilToInt(Radius);
	float CurrentValue = 0.f;

	if (World)
	{
		//if (EditorRemovePressed)
		{
			World->OctreeMutex.Lock();

			for (int Z = -VoxelsRadius; Z <= VoxelsRadius; Z++)
			{
				for (int Y = -VoxelsRadius; Y <= VoxelsRadius; Y++)
				{
					for (int X = -VoxelsRadius; X <= VoxelsRadius; X++)
					{
						FVector PositionVoxel = FVector(X, Y, Z);
						float offset = 0.001f;
						float ValueSphere = Radius - offset - PositionVoxel.Size();
						//float ValueSphere = Radius - offset - PositionVoxel.Size();

						if (ValueSphere >= 0)
						{
							World->SetVoxelValue((FIntVector)PositionVoxel + World->TransferToVoxelWorld(HitPosition), 0, Color, false, true);
						}
					}
				}
			}
			FVoxelCollisionBox Box = FVoxelCollisionBox(World, World->TransferToVoxelWorld(HitPosition), VoxelsRadius * 2);
			TArray<TSharedPtr<FVoxelOctreeData>> OverlapOctants;

			World->GetOverlapingOctree(Box, World->MainOctree, OverlapOctants);

			for (auto& Octant : OverlapOctants)
			{
				if (Octant->Data != nullptr)
				{
					if (IsValid(Octant->Data->Chunk))
					{
						World->PutChunkOnGeneration(Octant->Data);
					}
				}
			}

			World->OctreeMutex.Unlock();
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