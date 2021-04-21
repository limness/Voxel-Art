// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPoolComponent.h"
#include "Helpers/VoxelTools.h"
#include "VoxelChunkComponent.h"

DECLARE_CYCLE_STAT(TEXT("Voxel ~ Spawn Chunk ~ Getting from Pool"), STAT_GettingFromPool, STATGROUP_Voxel);


UVoxelPoolComponent::UVoxelPoolComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UVoxelPoolComponent::BeginPlay()
{
	Super::BeginPlay();
}

UVoxelChunkComponent* UVoxelPoolComponent::AddChunkToPool()
{
	UWorld* const World = GetWorld();

	if (World) 
	{
		FString name = FString::Printf(TEXT("%d"), PoolChunks.Num());
		UVoxelChunkComponent* PoolableChunk = NewObject<UVoxelChunkComponent>(this, *name);
		PoolableChunk->OnComponentCreated();
		PoolableChunk->RegisterComponent();
		PoolableChunk->SetPoolActive(false);

		PoolChunks.Add(PoolableChunk);

		return PoolChunks[PoolChunks.Num() - 1];
	}
	return nullptr;
}

UVoxelChunkComponent* UVoxelPoolComponent::GetChunkFromPool()
{
	SCOPE_CYCLE_COUNTER(STAT_GettingFromPool);

	if (FreeChunks.Num() > 0)
	{
		return FreeChunks.Pop();
	}
	return nullptr;
}
