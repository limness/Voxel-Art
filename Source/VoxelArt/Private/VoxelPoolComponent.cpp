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
UVoxelChunkComponent* UVoxelPoolComponent::AddChunkToPool()
{
	UWorld* const World = GetWorld();

	if (World) 
	{
		FString name = FString::Printf(TEXT("%d"), PoolChunks.Num());
		UVoxelChunkComponent* PoolableChunk = NewObject<UVoxelChunkComponent>(this, *name);
		PoolableChunk->OnComponentCreated();
		PoolableChunk->RegisterComponent();
		if (PoolableChunk->bWantsInitializeComponent) PoolableChunk->InitializeComponent();
		PoolableChunk->SetPoolActive(false);

		PoolChunks.Add(PoolableChunk);

		return PoolChunks[PoolChunks.Num() - 1];
	}
	return nullptr;
}

UVoxelChunkComponent* UVoxelPoolComponent::GetChunkFromPool()
{
	for(int i = 0; i < PoolChunks.Num(); i++)
	{
		if (!PoolChunks[i]->IsPoolActive())
		{
			return PoolChunks[i];
		}
	}
	return nullptr;
}
