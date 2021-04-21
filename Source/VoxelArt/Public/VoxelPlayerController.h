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

#if WITH_EDITOR
	/*Called when a property on this object has been modified externally*/
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);
#endif

	/*Handles a key press*/
	virtual bool InputKey(FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad);

	// ~ End AActor Interface

public:

	UFUNCTION(BlueprintCallable)
	void ChangeWorld(AVoxelWorld* World, FVector HitPosition);

public:

	UVoxelEditorData* EditorData;

public:

	UPROPERTY(EditDefaultsOnly)
	bool EditorRemovePressed = false;

	UPROPERTY(EditDefaultsOnly)
	bool EditorCreatePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	TEnumAsByte<BrushType> BrushType = BrushType::Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	TEnumAsByte<BrushSoftness> BrushSoftness = BrushSoftness::Insert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	TEnumAsByte<EditorType> EditorType = EditorType::TerrainEdit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	bool Dig = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	float Radius = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editor ~ Settings")
	FColor Color = FColor(0.17f, 0.07f,	1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	float Strength = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Editor ~ Settings")
	float MaxDictance = 256.f;
};
