// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Generators/VoxelWorldGenerator.h"
#include "VoxelWorldHillsGenerator.generated.h"

class AVoxelWorld;

/*
* Voxel World Main class
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldHillsGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Density")
	int Octaves = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Density")
	float Amplitude = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Density")
	float Frequency = 0.003f;

private:

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
};
