// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Generators/VoxelWorldFlatGenerator.h"
#include "Helpers/VoxelTools.h"


float UVoxelWorldFlatGenerator::GetDensityMap(const FIntVector& CellPosition)
{
	Super::GetDensityMap(CellPosition);

	/*
	* 
	* @param Cell.Z		Says that the density of the entire world will change 
	*					relative to the change in world coordinate Z. 
	*					Thus we get positive real numbers >= 0 Z and <= 0 Z
	* 
	* @param Height		Determines how high up your world 
	*					will be in relation to the zero coordinates of the World
	* 
	* @param Offset		Required for every noise where there is a probability 
	*					of having numbers that are a multiple of the voxel size.
	*					For example: a noise has a value of 128.f or 256.f (with a voxel size of 128.f)
	*					In this way we avoid incorrect calculation of normals
	*
	*/

	float Value = CellPosition.Z + Height + VoxelTools::VoxelOffset;

	return Value;
}

FColor UVoxelWorldFlatGenerator::GetColorMap(const FIntVector& CellPosition)
{
	Super::GetColorMap(CellPosition);

	return VOXEL_COLOR;
}