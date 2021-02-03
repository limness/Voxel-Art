// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Math/Vector2D.h"
#include "Engine/Texture2D.h"
#include "VoxelLandscapeGenerator.generated.h"

class AVoxelLandscape;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelLandscapeGenerator : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	virtual void PostLoad() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	AVoxelLandscape* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	UTexture2D* HeightmapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	float Multiply = 100.f;

private:

	float RadiusHeighestVoxel = 0.f;

	int WidthTexture;
	int HeightTexture;

	TArray<FColor> TextureMap;

	FORCEINLINE float GetHeightmapData(float X, float Y, float Z) const;

public:

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "Density Map"))
	void SetDensityMap(const float& X, const float& Y, const float& Z, float& noise);

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "Color Map"))
	void SetColorMap(const float& X, const float& Y, const float& Z, FColor& color);

	float GetDensityMap(const FVector& CellPosition);
	FColor GetColorMap(const FVector& CellPosition);

private:

	UFUNCTION(BlueprintCallable)
	float FlatLandscape(float A);

	UFUNCTION(BlueprintCallable)
	float SphereLandscape(float X = 0.f, float Y = 0.f, float Z = 0.f, float radius = 50.f);

	UFUNCTION(BlueprintCallable)
	float TorusLandscape(float X, float Y, float Z, float radius, float radiusInside);


private:

	UFUNCTION(BlueprintCallable)
	float FractalNoise(float X = 0.f, float Y = 0.f, float Z = 0.f, int seed = 0, int octaves = 5, float amplitude = 1.f, float frequency = 0.003f);

	UFUNCTION(BlueprintCallable)
	float IQNoise(FVector p);

	UFUNCTION(BlueprintCallable)
	float Cone(FVector p, FVector2D c, float h);

	UFUNCTION(BlueprintCallable)
	float SimplexNoise(float X, float Y, float Z, int seed);

private:

	UFUNCTION(BlueprintCallable)
	float VectorDistanceAB(FVector A, FVector B);
};
