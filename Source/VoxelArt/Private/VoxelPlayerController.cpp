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
					ChangeChunk(Cast<AVoxelLandscape>(MouseHitResult.Component->GetOwner()), MouseHitResult.Location, rangeEdit);
				}
			}
		}
		if (!smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

#include "DrawDebugHelpers.h"

void AVoxelPlayerController::ChangeChunk(AVoxelLandscape* World, FVector HitPosition, float Radius)
{
	int radius = FMath::CeilToInt(Radius);
	float CurrentValue = 0.f;

	if (World)
	{
		//if (EditorRemovePressed)
		{
			World->OctreeMutex.Lock();

			for (int Z = -15; Z <= 15; Z++)
			{
				for (int Y = -15; Y <= 15; Y++)
				{
					for (int X = -15; X <= 15; X++)
					{
						FVector PositionVoxel = FVector(X, Y, Z);
						float ValueSphere = 14.5f - PositionVoxel.Size();
						World->SetVoxelValue((FIntVector)PositionVoxel + World->TransferToVoxelWorld(HitPosition), ValueSphere);
						//DrawDebugPoint(World->GetWorld(), World->TransferToGameWorld(PositionVoxel), 10, FColor::Red, false, 25);
					}
				}
			}
			FVoxelCollisionBox Box = FVoxelCollisionBox(World, World->TransferToVoxelWorld(HitPosition), 35);
			TArray<TSharedPtr<FVoxelOctreeData>> OverlapOctants;

			World->GetOverlapingOctree(Box, World->MainOctree, OverlapOctants);

			for (auto& Octant : OverlapOctants)
			{
				if (Octant->Data != nullptr)
				{
					if (IsValid(Octant->Data->Chunk))
					{
						World->PutChunkOnGeneration(Octant->Data);
						//World->ChunksGeneration.Add(Octant->Data);
					}
				}
			}

			World->OctreeMutex.Unlock();
		}
	}
/*
	for (int z = -radius; z <= radius; z++)
	{
		for (int y = -radius; y <= radius; y++)
		{
			for (int x = -radius; x <= radius; x++)
			{
				FVector Position = HitPosition + FVector(x, y, z);
				float SphereRadius = Radius - Position.Size();

				float CurrentValue = 0.f;
				World->GetVoxelValue(Position, CurrentValue);
			}
		}
	}*/

/*	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> OverlapActors;

	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	if (UKismetSystemLibrary::SphereOverlapActors(this, position, rangeEditMax, ObjectTypes, AVoxelChunk::StaticClass(), TArray<AActor*>(), OverlapActors))
	{
		for (AActor* OverlapActor : OverlapActors)
		{
			AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

			if (chunk->Grid.Num() > 0)
			{
				chunk->ChangeVoxel(nullptr, position, range, strength, smooth, EditorRemovePressed, smoothInsert);
			}
		}*/

		/*
		We must first generate noise on all the chunks asynchronously
		So that when we update the transition mesh we have fresh data
		*/
/*		for (AActor* OverlapActor : OverlapActors)
		{
			AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

			if (chunk->Grid.Num() > 0)
			{
				chunk->GenerateVertexCube(true);
			}
		}
	}*/
}

void AVoxelPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AVoxelPlayerController::BeginDestroy()
{
	Super::BeginDestroy();
}