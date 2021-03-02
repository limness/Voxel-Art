// Voxel Art Plugin © limit 2018


#include "VoxelPoolComponent.h"
#include "Helpers/VoxelTools.h"

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
		//if (PoolableChunk->bWantsInitializeComponent) PoolableChunk->InitializeComponent();
		PoolableChunk->SetPoolActive(false);

		//FreeChunks.Add(PoolableChunk);
		PoolChunks.Add(PoolableChunk);

		return PoolChunks[PoolChunks.Num() - 1];
	}
	return nullptr;
}

UVoxelChunkComponent* UVoxelPoolComponent::GetChunkFromPool()
{
	{
		SCOPE_CYCLE_COUNTER(STAT_GettingFromPool);

		if (FreeChunks.Num() > 0)
		{
			return FreeChunks.Pop();
		}
		//if()
		/*for (int i = 0; i < PoolChunks.Num(); i++)
		{
			if (!PoolChunks[i]->IsPoolActive())
			{
				return PoolChunks[i];
			}
		}*/
	}
	return nullptr;
}
