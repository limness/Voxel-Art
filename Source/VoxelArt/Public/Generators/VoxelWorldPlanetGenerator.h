// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "VoxelWorldPlanetGenerator.generated.h"

<<<<<<< HEAD
class AVoxelWorld;

/*
* Voxel World Main class
*/
=======

class AVoxelWorld;


>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldPlanetGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

private:

	/*
<<<<<<< HEAD
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
=======
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

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
};
