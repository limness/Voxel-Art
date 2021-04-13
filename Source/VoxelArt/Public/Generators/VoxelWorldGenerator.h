// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Math/Vector2D.h"
#include "Engine/Texture2D.h"
#include "VoxelWorldGenerator.generated.h"


class AVoxelWorld;


UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldGenerator : public UObject
{
	GENERATED_BODY()

public:

	void GeneratorInit();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Density")
	float Height = 0.f;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	AVoxelWorld* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	UTexture2D* HeightmapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	UTexture2D* ColormapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	float Multiply = 100.f;

protected:

	float RadiusHeighestVoxel = 0.f;

	int WidthHeightmap;
	int HeightHeightmap;

	int WidthColormap;
	int HeightColormap;

	TArray<FColor> TextureHeightMap;
	TArray<FColor> TextureColorMap;

	FORCEINLINE float GetHeightmapData(float X, float Y, float Z) const;
	FORCEINLINE FColor GetColormapData(float X, float Y, float Z) const;

public:

	/*
	 * Get Density at position
	 * @param	CellPosition: Position of your position
	 * @return	Density of the World at the position 
	 */

	virtual float GetDensityMap(const FIntVector& CellPosition);

	/*
	 * Get Color at position
	 * @param	CellPosition: Position of your position
	 * @return	Color of the World at the position
	 */

	virtual FColor GetColorMap(const FIntVector& CellPosition);

protected:

	UFUNCTION(BlueprintCallable)
	float FlatSDF(int A);

	UFUNCTION(BlueprintCallable)
	float SphereSDF(int X = 0, int Y = 0, int Z = 0, float Radius = 50.f);

	UFUNCTION(BlueprintCallable)
	float TorusSDF(int X = 0, int Y = 0, int Z = 0, float Radius = 77.f, float RadiusInside = 37.f);


protected:

	UFUNCTION(BlueprintCallable)
	float FractalNoise(int X = 0, int Y = 0, int Z = 0, int Octaves = 3, float Amplitude = 50.f, float Frequency = 0.003f);

	UFUNCTION(BlueprintCallable)
	float IQNoise(FVector p);

	UFUNCTION(BlueprintCallable)
	float Cone(FVector p, FVector2D c, float h);

	UFUNCTION(BlueprintCallable)
	float SimplexNoise(int X, int Y, int Z);

protected:

	UFUNCTION(BlueprintCallable)
	float VectorDistanceAB(FVector A, FVector B);
};
