// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelPoolComponent.h"

// Sets default values for this component's properties
UVoxelPoolComponent::UVoxelPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVoxelPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
AVoxelChunk* UVoxelPoolComponent::AddChunkToPool()
{
	UWorld* const World = GetWorld();

	if (World) 
	{
		AVoxelChunk* PoolableActor = World->SpawnActor<AVoxelChunk>(AVoxelChunk::StaticClass(), FVector().ZeroVector, FRotator().ZeroRotator);

		PoolableActor->SetActive(false);

		PoolChunks.Add(PoolableActor);

		return PoolChunks[PoolChunks.Num() - 1];
	}
	return nullptr;
}

AVoxelChunk* UVoxelPoolComponent::GetChunkFromPool()
{
	for(int i = 0; i < PoolChunks.Num(); i++)
	{
		if (!PoolChunks[i]->IsActive())
		{
			return PoolChunks[i];
		}
	}
	/*if (PoolChunks.Num() > 0)
	{
		return PoolChunks.Pop();
	}*/
	/* pool is drained, no inactive objects found */
	return nullptr;
}
