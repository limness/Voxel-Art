// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Helpers/FastNoise.h"
#include "Math/Vector2D.h"
#include "Engine/Texture2D.h"
#include "VoxelWorldGenerator.generated.h"

class AVoxelWorld;

/*
* Default class of the World Generator
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldGenerator : public UObject
{
	GENERATED_BODY()

public:

	void GeneratorInit();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Density")
	float Height = 40.f;

	FastNoise* NoiseObject = nullptr;

public:

	// ~ Begin Import Texture Interface

	//It is necessary to specify in any case, when the import occurs, otherwise it does not work.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	AVoxelWorld* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	UTexture2D* HeightmapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	UTexture2D* ColormapTexture;

	// The multiplication value of the resulting value. The value calculated based 
	// on the pixels of the imported texture may be too small or too large. 
	// That's why I introduced this parameter, which allows you to manually adjust the output density
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Import Own Heightmap")
	float Multiply = 100.f;

	// ~ End Import Texture Interface

protected:

	// ~ Begin Import Texture Interface

	float RadiusHeighestVoxel = 0.f;

	int WidthHeightmap;
	int HeightHeightmap;

	int WidthColormap;
	int HeightColormap;

	TArray<FColor> TextureHeightMap;
	TArray<FColor> TextureColorMap;

	/*
	* Get Density using texture
	*
	* @param	X, Y, Z		Position of your position
	* @return	Density		Density of the Image at the position
	*/
	FORCEINLINE float GetHeightmapData(float X, float Y, float Z) const;

	/*
	* Get Color using texture
	*
	* @param	X, Y, Z		Position of your position
	* @return	Color		Color of the Texture at the position
	*/
	FORCEINLINE FColor GetColormapData(float X, float Y, float Z) const;

	// ~ End Import Texture Interface

public:

	/*
	* Get Density at position
	*
	* @param	CellPosition	Position of your position
	* @return	Density			Density of the World at the position
	*/
	virtual float GetDensityMap(const FIntVector& CellPosition);

	/*
	* Get Color at position
	*
	* @param	CellPosition	Position of your position
	* @return	Color			Color of the World at the position
	*/
	virtual FColor GetColorMap(const FIntVector& CellPosition);

protected:

	/*
	* Fractal Noise
	*
	* @param	X, Y, Z			Position of your position
	* @param	Octaves			Number of octaves in the noise
	* @param	Amplitude		Amplitude of the noise
	* @param	Frequency		Frequency of the noise
	* @return	Density			Density of the World at the position
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	float FractalNoise(int X = 0, int Y = 0, int Z = 0, int Octaves = 3, float Amplitude = 50.f, float Frequency = 0.003f);

	/*
	* 3D Simplex Noise
	*
	* @param	X, Y, Z			Position of your position
	* @return	Density			Density of the World at the position
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	float SimplexNoise(int X, int Y, int Z, float Frequency = 1.f);

	/*
	* Doesn't work.
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	float IQNoise(FVector p);
};