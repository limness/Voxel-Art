// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Generators/VoxelWorldGenerator.h"
#include "VoxelWorldPlanetGenerator.generated.h"

class AVoxelWorld;

/*
* Voxel World Main class
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldPlanetGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

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
