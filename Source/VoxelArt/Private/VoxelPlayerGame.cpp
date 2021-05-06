// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerGame.h"
#include "Helpers/VoxelTools.h"
#include "VoxelWorld.h"

DECLARE_CYCLE_STAT(TEXT("Voxel Player Game ~ Tick"), STAT_Tick, STATGROUP_Voxel);

AVoxelPlayerGame::AVoxelPlayerGame()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AVoxelPlayerGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SCOPE_CYCLE_COUNTER(STAT_Tick);

	if (bEnabled && World)
	{
		if (APawn* WorldPawn = GetWorld()->GetFirstPlayerController()->GetPawn())
		{
			Velocity = WorldPawn->GetVelocity().Size();
			SetActorLocation(WorldPawn->GetActorLocation());
		}
	}
}

float AVoxelPlayerGame::GetVoxelVelocity()
{
	return Velocity;
}

void AVoxelPlayerGame::SetVoxelWorld(AVoxelWorld* _World)
{
	World = _World;
}