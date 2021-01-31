// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/VoxelModificationLandscape.h"
#include "Noise/SimplexNoiseBPLibrary.h"

float UVoxelModificationLandscape::SpherePainter(float X, float Y, float Z, float radius)
{
	float value = 0.f;

	value = radius - sqrt(X * X + Y * Y + Z * Z);

	return value;
}

float UVoxelModificationLandscape::BangPainter(float X, float Y, float Z, float radius, int octaves, float amplitude, float frequency)
{
	float value = 0.f;
	float valuefractal = 0.f;

	value = radius - sqrt(X * X + Y * Y + Z * Z);

	for (int i = 0; i < octaves; i++)
	{
		valuefractal += USimplexNoiseBPLibrary::SimplexNoise3D(X * frequency, Y * frequency, Z * frequency) * amplitude;
		frequency *= 2.f;
		amplitude *= 0.5f;
	}

	return value + valuefractal;
}