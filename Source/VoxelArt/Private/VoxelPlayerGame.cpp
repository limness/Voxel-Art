// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerGame.h"
#include "VoxelWorld.h"

AVoxelPlayerGame::AVoxelPlayerGame()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AVoxelPlayerGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnabled && World)
	{
		if (APawn* WorldPawn = GetWorld()->GetFirstPlayerController()->GetPawn())
		{
			SetActorLocation(WorldPawn->GetActorLocation());
		}
	}
}

void AVoxelPlayerGame::SetVoxelWorld(AVoxelWorld* _World)
{
	World = _World;
}