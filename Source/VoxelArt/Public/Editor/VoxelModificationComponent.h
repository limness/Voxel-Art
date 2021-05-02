// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VoxelWorld.h"
#include "Editor/VoxelModificationWorld.h"
#include "VoxelModificationComponent.generated.h"

/*
* Voxel Modif Component (not used now)
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VOXELART_API UVoxelModificationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVoxelModificationComponent();

public:

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Main")
	UVoxelModificationWorld* WorldModificator;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
