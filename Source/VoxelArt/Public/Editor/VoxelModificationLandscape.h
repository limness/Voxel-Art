// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VoxelModificationLandscape.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew) //hidecategories = (Object)
class VOXELART_API UVoxelModificationLandscape : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Nice Cock"))
	void GetPainterData(const float& X, const float& Y, const float& Z, float& noise, float& strength, bool& dig, bool& smooth);

public:

	UFUNCTION(BlueprintCallable)
	float SpherePainter(float X, float Y, float Z, float radius);

	UFUNCTION(BlueprintCallable)
	float BangPainter(float X, float Y, float Z, float radius, int octaves, float amplitude, float frequency);

};
