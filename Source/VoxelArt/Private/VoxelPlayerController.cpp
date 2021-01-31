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
		//FHitResult OutHit;
		//FVector Start = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
		//FVector End = (UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation() + UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorForwardVector() * dictance);
		//FCollisionQueryParams CollisionParams;

		FHitResult MouseHitResult;

		//this->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, MouseHitResult);

	//	FVector MouseWorld, MouseDir;

	//	this->DeprojectMousePositionToWorld(MouseWorld, MouseDir);

		//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : ModificatorComponent ] Error: Painter is empty, modificator can't be started"));

		//if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_WorldStatic, CollisionParams))
		if(this->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, MouseHitResult))
		{
			if (MouseHitResult.bBlockingHit)
			{
				if (GEngine)
				{
				//	if (OutHit.GetActor() != NULL)
					{
					//	if (UKismetSystemLibrary::GetDisplayName(OutHit.GetActor()->GetClass()) == "VoxelChunk")
						{

						//	AVoxelChunk* chunk = Cast<AVoxelChunk>(OutHit.GetActor());
						//	AVoxelLandscape* terrain = Cast<AVoxelLandscape>(chunk->GetAttachParentActor());
						//	DrawDebugBox(GetWorld(), MouseHitResult.Location, FVector(10.f, 10.f, 10.f), FColor::Red, false, 13.f, 13.f, 12.f);

							//ChangeChunk(terrain, chunk, OutHit.Location, rangeEdit, EditorRemovePressed ? editorSpeed : -editorSpeed, smooth);
							ChangeChunk(nullptr, nullptr, MouseHitResult.Location, rangeEdit);
						}
					}
				}
			}
		}
		if (!smooth)
		{
			EditorRemovePressed ? EditorRemovePressed = false : EditorCreatePressed = false;
		}
	}
}

/*void AVoxelPlayerController::ChangeChunk(
	AVoxelLandscape* terrain,
	AVoxelChunk* chunkCenter,
	FVector hitPosition,
	float range,
	float volume,
	bool sphereMinus)
{
	int intRange = 1;
	int normaldx = 0;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> OverlapActors;

	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	if (UKismetSystemLibrary::SphereOverlapActors(this, hitPosition, range, ObjectTypes, AVoxelChunk::StaticClass(), TArray<AActor*>(), OverlapActors))
	{
		for (AActor* OverlapActor : OverlapActors)
		{
			AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

			if (chunk->Grid.Num() > 0)
			{
				//range, chunkCenter, hitPosition - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, bool smooth

				//chunk->ChangeVoxel(range, chunkCenter, hitPosition - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, sphereMinus);
				chunk->GenerateVertexCube(true);
			}
		}
	}
}*/

#include "DrawDebugHelpers.h"

void AVoxelPlayerController::ChangeChunk(
	AVoxelLandscape* terrain,
	AVoxelChunk* chunkCenter,
	FVector position,
	float range)
{
	//if (modificator != nullptr)
	if (true)
	{
		int intRange = 1;
		int normaldx = 0;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		TArray<AActor*> OverlapActors;

		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	//	DrawDebugBox(GetWorld(), position, FVector(10.f, 10.f, 10.f), FColor::Red, false, 13.f, 13.f, 12.f);

	//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : ModificatorComponent ] Log: pos %s"), *position.ToString());

		if (UKismetSystemLibrary::SphereOverlapActors(this, position, rangeEditMax, ObjectTypes, AVoxelChunk::StaticClass(), TArray<AActor*>(), OverlapActors))
		{
			for (AActor* OverlapActor : OverlapActors)
			{
				AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

				if (chunk->Grid.Num() > 0)
				{
					//range, chunkCenter, hitPosition - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, bool smooth
					float noise = 0.f;
				//	float strength = 0.f;
				//	bool smooth = false;

					//modificator->GetPainterData(positionNoise.X, positionNoise.Y, positionNoise.Z, noise, strength, smooth);

					//chunk->ChangeVoxel(range, chunkCenter, position - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, sphereMinus);
					//chunk->ChangeVoxel(nullptr /*here is modificator*/, position, range, smoothInsert);
					chunk->ChangeVoxel(nullptr, position, range, strength, smooth, EditorRemovePressed, smoothInsert);
					//chunk->GenerateVertexCube(true);
				}
			}

			/*
			We must first generate noise on all the chunks asynchronously
			So that when we update the transition mesh we have fresh data
			*/
			for (AActor* OverlapActor : OverlapActors)
			{
				AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

				if (chunk->Grid.Num() > 0)
				{
					chunk->GenerateVertexCube(true);
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : ModificatorComponent ] Error: Painter is empty, modificator can't be started"));
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