// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunkComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "VoxelPoolComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOXELART_API UVoxelPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVoxelPoolComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

//	UPROPERTY(Transient)
	TArray<UVoxelChunkComponent*> PoolChunks;

public:

	//Has our pool free actors or not
	UVoxelChunkComponent* AddChunkToPool();

	//Get our chunk from the pool
	//If chunks are exist in queue we get it
	UVoxelChunkComponent* GetChunkFromPool();
};
