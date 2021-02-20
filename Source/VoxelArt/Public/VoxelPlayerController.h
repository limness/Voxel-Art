// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunk.h"
#include "VoxelLandscape.h"

#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/PlayerController.h"
#include "VoxelPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VOXELART_API AVoxelPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginDestroy() override;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual bool InputKey(FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad);

public:

	UPROPERTY(EditDefaultsOnly)
	bool EditorRemovePressed = false;

	UPROPERTY(EditDefaultsOnly)
	bool EditorCreatePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float Radius = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	bool Smooth = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float Strength = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float MaxDictance = 5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float SmoothInsert = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	bool ColorEditor = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	FColor Color = FColor(77.f, 77.f, 77.f);

	UFUNCTION(BlueprintCallable)
	void ChangeWorld(AVoxelLandscape* World, FVector HitPosition, float Radius);

};
