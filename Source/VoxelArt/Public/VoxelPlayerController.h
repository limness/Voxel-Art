// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorld.h"
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

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

	virtual bool InputKey(FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad);

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
	TEnumAsByte<EditorType> EditorType = EditorType::Terrain;

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

	UVoxelEditorData* EditorData;

	UFUNCTION(BlueprintCallable)
	void ChangeWorld(AVoxelWorld* World, FVector HitPosition);
};
