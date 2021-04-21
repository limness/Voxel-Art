// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelPlayerInterface.h"
#include "VoxelPlayerGame.generated.h"

UCLASS(Blueprintable, HideCategories = ("Rendering", "Collision", "Input", "Actor", "LOD"))
class AVoxelPlayerGame : public AVoxelPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVoxelPlayerGame();

private:
	// ~ Begin AActor Interface

	/* Called every frame */
	virtual void Tick(float DeltaTime) override;

	// ~ End AActor Interface

public:

	virtual void SetVoxelWorld(AVoxelWorld* _World);

private:

	AVoxelWorld* World;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	bool bEnabled = true;
};