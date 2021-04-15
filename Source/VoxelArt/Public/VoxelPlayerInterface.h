// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelPlayerInterface.generated.h"

UCLASS()
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
