// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

class FVoxelSDFUtilities
{
public:

	/*
	* A point in a three-dimensional coordinate system, which must be flat.
	* So you can, for example, make some part of a sphere flat by applying one of the cords
	* to this formula (X, Y, Z). See example in file: VoxelWorldGenerators
	*
	* @param	A			The point in a three-dimensional coordinate (X, Y, Z, -X, -Y, -Z)
	* @return	Density		Density of the flat at the position
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	static float FlatSDF(int A);

	/*
	* Density sphere formula
	*
	* @param	X, Y, Z		Position of your position
	* @param	Radius		Radius of your sphere
	* @return	Density		Density of the sphere at the position
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	static float SphereSDF(int X = 0, int Y = 0, int Z = 0, float Radius = 50.f);

	/*
	* Torus sphere formula
	*
	* @param	X, Y, Z			Position of your position
	* @param	Radius			Radius of your torus outside
	* @param	RadiusInside	Radius of your sphere inside
	* @return	Density			Density of the torus at the position
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	static float TorusSDF(int X = 0, int Y = 0, int Z = 0, float Radius = 30.f, float InnerRadius = 25.f);

	/*
	* Doesn't work.
	*/
	UFUNCTION(BlueprintCallable, Category = "Voxel SDF")
	static float ConeSDF(int X, int Y, int Z, FVector2D c, float Height);
};