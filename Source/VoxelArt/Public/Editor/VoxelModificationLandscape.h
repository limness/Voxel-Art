// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VoxelModificationLandscape.generated.h"


class AVoxelLandscape;

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
	static void SpherePainter(AVoxelLandscape* World, FIntVector Position, float Radius);

	UFUNCTION(BlueprintCallable)
	static void CubePainter(AVoxelLandscape* World, FIntVector Position, float Radius);

	UFUNCTION(BlueprintCallable)
	float BangPainter(int X, int Y, int Z, float Radius, int octaves, float amplitude, float frequency);

private:

	static void UpdateOverlapOctants(AVoxelLandscape* World, FIntVector Position, int Size);
};
