// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelPlayerInterface.h"
#include "Editor.h"
#include "EditorViewportClient.h"
#include "VoxelPlayerEditor.generated.h"

UCLASS(Blueprintable, HideCategories = ("Rendering", "Collision", "Input", "Actor", "LOD"))
class AVoxelPlayerEditor : public AVoxelPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVoxelPlayerEditor();

public:
	// ~ Begin AActor Interface

	/* Called every frame */
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed() override;

	virtual float GetVoxelVelocity();

#if WITH_EDITOR

	/*If true, actor is ticked*/
	virtual bool ShouldTickIfViewportsOnly() const override;

#endif

	// ~ End AActor Interface

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	bool bEnabled = true;

	float Velocity = 0.f;
};