// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelPlayerController.h"
#include "Helpers/VoxelTools.h"

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

void AVoxelPlayerController::ChangeChunk(AVoxelLandscape* World, FVector HitPosition, float Radius)
{
	int radius = FMath::CeilToInt(Radius);

	//World->SpawnBoxTest(HitPosition, 30.f, 25.f, FColor::Red);

	//FScopeLock Lock(&World->OctreeMutex);

	float CurrentValue = 0.f;
	//UVoxelChunkComponent* CurrentChunk = NULLPTR;

	if (World)
	{
		//if (EditorRemovePressed)
		{
			UE_LOG(VoxelArt, Warning, TEXT("Setting Value"));

			World->OctreeMutex.Lock();
			World->SetVoxelValue(World->TransferToVoxelWorld(HitPosition), CurrentValue);
			World->OctreeMutex.Unlock();
		}
		/*else
		{
			UE_LOG(VoxelArt, Log, TEXT("Getting Value"));

			World->OctreeMutex.Lock();
			World->GetVoxelValue(World->TransferToWorld(HitPosition), CurrentValue);
			World->OctreeMutex.Unlock();
		}*/
	}
	else
	{
		UE_LOG(VoxelArt, Error, TEXT("Controller ~ World is NULL"));

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