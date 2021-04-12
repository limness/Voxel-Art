// Voxel Art Plugin © limit 2018

#include "VoxelWorldPlanetGenerator.h"
#include "Helpers/VoxelTools.h"


float UVoxelWorldPlanetGenerator::GetDensityMap(const FIntVector& CellPosition)
{
	Super::GetDensityMap(CellPosition);

	/*
	*
	* @param Cell.Z		Says that the density of the entire world will change
	*					relative to the change in world coordinate Z.
	*					Thus we get positive real numbers >= 0 Z and <= 0 Z
	*
	* @param Offset		Required for every noise where there is a probability
	*					of having numbers that are a multiple of the voxel size.
	*					For example: a noise has a value of 128.f or 256.f (with a voxel size of 128.f)
	*					In this way we avoid incorrect calculation of normals
	*
	*/

	float Value = SphereSDF(CellPosition.X, CellPosition.Y, CellPosition.Z, 1526.f) + VoxelTools::Offset;

	Value += FractalNoise(CellPosition.X, CellPosition.Y, CellPosition.Z);

	return Value;
}

FColor UVoxelWorldPlanetGenerator::GetColorMap(const FIntVector& CellPosition)
{
	Super::GetColorMap(CellPosition);

	return VOXEL_COLOR;
}