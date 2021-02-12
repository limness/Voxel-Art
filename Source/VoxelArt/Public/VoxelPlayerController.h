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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EditorRemovePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EditorCreatePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int positionVoxelX = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int positionVoxelY = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int positionVoxelZ = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rangeEditMax = 1200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rangeEdit = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float editorSpeed = -1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool smooth = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float strength = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float dictance = 5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float smoothInsert = 10.f;

	UFUNCTION(BlueprintCallable)
	void ChangeChunk(AVoxelLandscape* World, FVector HitPosition, float Radius);
	//void ChangeChunk(AVoxelLandscape* terrain, AVoxelChunk* chunkCenter, FVector hitPosition, float range, float volume, bool sphereMinus);

};
