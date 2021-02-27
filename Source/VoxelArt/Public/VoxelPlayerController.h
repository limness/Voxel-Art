// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelLandscape.h"
#include "Editor/VoxelEditorData.h"

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
	TEnumAsByte<BrushType> BrushType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	TEnumAsByte<BrushSoftness> BrushSoftness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	TEnumAsByte<EditorType> EditorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	bool Dig = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float Radius = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	FColor Color = FColor(77.f, 77.f, 77.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	float Strength = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	float MaxDictance = 5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	float SmoothInsert = 10.f;

	UVoxelEditorData* EditorData;

	UFUNCTION(BlueprintCallable)
	void ChangeWorld(AVoxelLandscape* World, FVector HitPosition);
};
