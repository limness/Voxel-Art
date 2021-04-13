// Voxel Art Plugin © limit 2018

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

//public:
	//UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Nice Cock"))
	//void GetPainterData(const float& X, const float& Y, const float& Z, float& noise, bool& smooth);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/*UFUNCTION(BlueprintCallable)
	void Modification(
		AVoxelWorld* terrain,
		AVoxelChunk* chunkCenter,
		FVector position,
		float range
	);*/
};
