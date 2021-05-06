// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerInterface.h"

// Sets default values
AVoxelPlayerInterface::AVoxelPlayerInterface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoxelPlayerInterface::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVoxelPlayerInterface::SetVoxelWorld(AVoxelWorld* _World)
{
	// Override from example classes
}

float AVoxelPlayerInterface::GetVoxelVelocity()
{
	// Override from example classes
	return 0.f;
}
