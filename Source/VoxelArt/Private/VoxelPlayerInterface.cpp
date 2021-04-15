// Voxel Art Plugin © limit 2018


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

// Called every frame
void AVoxelPlayerInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

