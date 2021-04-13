// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "VoxelWorldFlatGenerator.generated.h"

<<<<<<< HEAD
class AVoxelWorld;

/*
* Voxel Generator Class
*/
=======

class AVoxelWorld;


>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelWorldFlatGenerator : public UVoxelWorldGenerator
{
	GENERATED_BODY()

private:

	/*
	 * Get Density at position
<<<<<<< HEAD
	 *
	 * @param	CellPosition: Position of your position
	 * @return	Density of the World at the position
	 */
=======
	 * @param	CellPosition: Position of your position
	 * @return	Density of the World at the position
	 */

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
	virtual float GetDensityMap(const FIntVector& CellPosition);

	/*
	 * Get Color at position
<<<<<<< HEAD
	 *
	 * @param	CellPosition: Position of your position
	 * @return	Color of the World at the position
	 */
	virtual FColor GetColorMap(const FIntVector& CellPosition);
=======
	 * @param	CellPosition: Position of your position
	 * @return	Color of the World at the position
	 */

	virtual FColor GetColorMap(const FIntVector& CellPosition);

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
};
