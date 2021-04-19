// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VoxelPoolComponent.generated.h"

class UVoxelChunkComponent;

/*
* Voxel Main Pool Component class
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOXELART_API UVoxelPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UVoxelPoolComponent();

protected:

	// ~ Begin UActorComponent Interface

	/*Overridable native event for when play begins for this component*/
	virtual void BeginPlay() override;

	// ~ End UActorComponent Interface

public:

	TArray<UVoxelChunkComponent*> PoolChunks;

	//Need to make time low for search of free chunk less
	TArray<UVoxelChunkComponent*> FreeChunks;

public:

	// Has our pool free actors or not
	UVoxelChunkComponent* AddChunkToPool();

	// Get our chunk from the pool
	// If chunk is exist in queue we get it
	UVoxelChunkComponent* GetChunkFromPool();
};
