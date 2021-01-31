// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VoxelChunk.h"
#include "VoxelLandscape.h"
#include "Editor/VoxelModificationLandscape.h"
#include "VoxelModificationComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VOXELART_API UVoxelModificationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVoxelModificationComponent();

public:

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Main")
	UVoxelModificationLandscape* modificator;

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
	UFUNCTION(BlueprintCallable)
	void Modification(AVoxelLandscape* terrain,
		AVoxelChunk* chunkCenter,
		FVector position,
		float range);
};
