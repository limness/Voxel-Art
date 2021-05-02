// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelPlayerInterface.generated.h"

class AVoxelWorld;

UCLASS(Abstract)
class VOXELART_API AVoxelPlayerInterface : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelPlayerInterface();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void SetVoxelWorld(AVoxelWorld* _World);
};
