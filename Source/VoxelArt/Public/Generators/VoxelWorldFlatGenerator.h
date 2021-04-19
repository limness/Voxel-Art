// Voxel Art Plugin ~ Copyright limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Generators/VoxelWorldGenerator.h"
#include "VoxelWorldFlatGenerator.generated.h"

class AVoxelWorld;

/*
* Voxel Generator Class
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldFlatGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

private:

	/*
	* Get Density at position
	*
	* @param	CellPosition: Position of your position
	* @return	Density of the World at the position
	*/
	virtual float GetDensityMap(const FIntVector& CellPosition);

	/*
	 * Get Color at position
	 *
	 * @param	CellPosition: Position of your position
	 * @return	Color of the World at the position
	 */

	virtual FColor GetColorMap(const FIntVector& CellPosition);
};
