// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"
#include "Editor/VoxelEditorData.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "VoxelPlayerController.generated.h"

/*
* Voxel Player Controller class
* Use this in any case when you want to edit World in real time
*/
UCLASS()
class VOXELART_API AVoxelPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// ~ Begin AActor Interface

	/*Called before destroying the object*/
	virtual void BeginDestroy() override;

	/*Function called every frame on this Actor*/
	virtual void Tick(float DeltaTime) override;

	/*Overridable native event for when play begins for this actor*/
	virtual void BeginPlay() override;

	/*Overridable function called whenever this actor is being removed from a level*/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/*Handles a key press*/
	virtual bool InputKey(FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad);

	// ~ End AActor Interface

public:

	UFUNCTION(BlueprintCallable)
	void ChangeWorld(AVoxelWorld* World, FVector HitPosition);

public:

	UVoxelEditorData* EditorData;

public:

	bool EditorRemovePressed = false;
	bool EditorCreatePressed = false;

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetEditDig(bool Dig);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	bool GetEditDig();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetBrushShape(TEnumAsByte<EBrushShape> Shape);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	TEnumAsByte<EBrushShape> GetBrushShape();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetBrushSoftness(TEnumAsByte<EBrushSoftness> Softness);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	TEnumAsByte<EBrushSoftness> GetBrushSoftness();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetEditorType(TEnumAsByte<EEditorType> Type);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	TEnumAsByte<EEditorType> GetEditorType();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetBrushRadius(float Radius = 10.f);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	float GetBrushRadius();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetBrushColor(FColor Color);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	FColor GetBrushColor();

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	void SetBrushStrength(float Strength = 10.f);

	UFUNCTION(BlueprintCallable, Category = "Editor ~ Settings")
	float GetBrushStrength();
};
