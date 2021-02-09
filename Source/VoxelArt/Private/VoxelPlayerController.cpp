// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelPlayerController.h"

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

		if(this->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, MouseHitResult))
		{
			if (MouseHitResult.bBlockingHit)
			{
				if (GEngine)
				{
					ChangeChunk(nullptr, nullptr, MouseHitResult.Location, rangeEdit);
				}
			}
		}
		if (!smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

void AVoxelPlayerController::ChangeChunk(
	AVoxelLandscape* terrain,
	AVoxelChunk* chunkCenter,
	FVector position,
	float range)
{
	int radius = FMath::CeilToInt(range);
	//float radiusVoxel = GetVoxelSize();

	for (int z = -radius; z <= radius; z++)
	{
		for (int y = -radius; y <= radius; y++)
		{
			for (int x = -radius; x <= radius; x++)
			{
				FVector Position = FVector(x, y, z);
				float SphereRadius = range - Position.Size();

				World->SetVoxelValue(Position, SphereRadius);
			}
		}
	}

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