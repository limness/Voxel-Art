// Voxel Art Plugin © limit 2018

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

	UE_LOG(VoxelArt, Error, TEXT("Ticks"));

	if (bEnabled && World)
	{
		UE_LOG(VoxelArt, Error, TEXT("World is not wrong"));

		if (APawn* WorldPawn = GetWorld()->GetFirstPlayerController()->GetPawn())
		{
			UE_LOG(VoxelArt, Error, TEXT("Changes pos on %s"), *WorldPawn->GetActorLocation().ToString());
			SetActorLocation(WorldPawn->GetActorLocation());
			UE_LOG(VoxelArt, Error, TEXT("nOW pos on %s"), *GetActorLocation().ToString());
		}
	}
}

void AVoxelPlayerGame::SetVoxelWorld(AVoxelWorld* _World)
{
	World = _World;
}