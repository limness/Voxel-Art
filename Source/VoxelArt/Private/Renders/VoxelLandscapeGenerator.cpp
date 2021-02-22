// Fill out your copyright notice in the Description page of Project Settings.

#include "Renders/VoxelLandscapeGenerator.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"

UVoxelLandscapeGenerator::UVoxelLandscapeGenerator(const class FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
}

void UVoxelLandscapeGenerator::GeneratorInit()
{
	if (HeightmapTexture && World)
	{
		FTexture2DMipMap* MyMipMap = &HeightmapTexture->PlatformData->Mips[0];

		WidthHeightmap = (int)MyMipMap->SizeX;
		HeightHeightmap = (int)MyMipMap->SizeY;

		HeightmapTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
		HeightmapTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
		HeightmapTexture->SRGB = false;
		HeightmapTexture->UpdateResource();

		TextureCompressionSettings OldCompressionSettings = HeightmapTexture->CompressionSettings;
		TextureMipGenSettings OldMipGenSettings = HeightmapTexture->MipGenSettings;
		bool OldSRGB = HeightmapTexture->SRGB;

		const FColor* FormatedImageData = static_cast<const FColor*>(HeightmapTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

		TextureHeightMap.Empty();
		TextureHeightMap.Init(FColor(0, 0, 0), WidthHeightmap * HeightHeightmap);

		for (int y = 0; y < HeightHeightmap; y++)
		{
			for (int x = 0; x < WidthHeightmap; x++)
			{
				TextureHeightMap[y * WidthHeightmap + x] = FormatedImageData[y * WidthHeightmap + x];
			}
		}

		HeightmapTexture->PlatformData->Mips[0].BulkData.Unlock();

		HeightmapTexture->CompressionSettings = OldCompressionSettings;
		HeightmapTexture->MipGenSettings = OldMipGenSettings;
		HeightmapTexture->SRGB = OldSRGB;
		HeightmapTexture->UpdateResource();

	/*	RadiusHeighestVoxel = World->WorldSize / (float)World->VoxelsPerChunk;

		for (int i = 0; i < World->MaximumLOD; i++)
		{
			RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
		} */
	}
	if (ColormapTexture && World)
	{
		FTexture2DMipMap* MyMipMap = &ColormapTexture->PlatformData->Mips[0];

		WidthColormap = (int)MyMipMap->SizeX;
		HeightColormap = (int)MyMipMap->SizeY;

		ColormapTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
		ColormapTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
		ColormapTexture->SRGB = false;
		ColormapTexture->UpdateResource();

		TextureCompressionSettings OldCompressionSettings = ColormapTexture->CompressionSettings;
		TextureMipGenSettings OldMipGenSettings = ColormapTexture->MipGenSettings;
		bool OldSRGB = ColormapTexture->SRGB;

		const FColor* FormatedImageData = static_cast<const FColor*>(ColormapTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

		TextureColorMap.Empty();
		TextureColorMap.Init(FColor(0, 0, 0), WidthColormap * HeightColormap);

		for (int y = 0; y < HeightColormap; y++)
		{
			for (int x = 0; x < WidthColormap; x++)
			{
				TextureColorMap[y * WidthColormap + x] = FormatedImageData[y * WidthColormap + x];
			}
		}

		ColormapTexture->PlatformData->Mips[0].BulkData.Unlock();

		ColormapTexture->CompressionSettings = OldCompressionSettings;
		ColormapTexture->MipGenSettings = OldMipGenSettings;
		ColormapTexture->SRGB = OldSRGB;
		ColormapTexture->UpdateResource();
/*
		RadiusHeighestVoxel = World->WorldSize / (float)World->VoxelsPerChunk;

		for (int i = 0; i < World->MaximumLOD; i++)
		{
			RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
		}*/
	}
}


FORCEINLINE float UVoxelLandscapeGenerator::GetHeightmapData(float X, float Y, float Z) const
{
	float offset = 0.001f;
	float MapX = X + WidthHeightmap / 2.f;
	float MapY = Y + HeightHeightmap / 2.f;

	if (MapX > WidthHeightmap - 1 || MapX < 0) return 1.f;
	if (MapY > HeightHeightmap - 1 || MapY < 0) return 1.f;

	return Z - (TextureHeightMap[round(MapY) * WidthHeightmap + round(MapX)].R - 128.f) / 63.f * Multiply + offset;
}

FORCEINLINE FColor UVoxelLandscapeGenerator::GetColormapData(float X, float Y, float Z) const
{
	float MapX = X + WidthColormap / 2.f;
	float MapY = Y + HeightColormap / 2.f;

	if (MapX > WidthColormap - 1 || MapX < 0) return FColor(121.f, 121.f, 121.f);
	if (MapY > HeightColormap - 1 || MapY < 0) return FColor(121.f, 121.f, 121.f);

	return TextureColorMap[round(MapY) * WidthColormap + round(MapX)];
}

float UVoxelLandscapeGenerator::GetDensityMap(const FIntVector& CellPosition)
{
	float offset = 0.001f;
	return TextureHeightMap.Num() > 0 ? GetHeightmapData(CellPosition.X, CellPosition.Y, CellPosition.Z) : ((CellPosition.Z + Height) + offset);
}

FColor UVoxelLandscapeGenerator::GetColorMap(const FIntVector& CellPosition)
{
	FColor color = FColor(77.f, 77.f, 77.f);

	if (TextureColorMap.Num() > 0)
	{
		color = GetColormapData(CellPosition.X, CellPosition.Y, CellPosition.Z);
	}
	return color;
}

float UVoxelLandscapeGenerator::FlatLandscape(float A)
{
	float value = 0.f;

	if (A >= 0.f)
	{
		value = (-1) * UKismetMathLibrary::FMax(1.f, A);
	}
	else if (A < 0.f)
	{
		value = (-1) * UKismetMathLibrary::FMin(-1.f, A);
	}
	return value;
}


float UVoxelLandscapeGenerator::SphereLandscape(float X, float Y, float Z, float radius)
{
	float value = 0.f;

	value = radius - sqrt(X * X + Y * Y + Z * Z);

	return value;
}

float UVoxelLandscapeGenerator::TorusLandscape(float X, float Y, float Z, float radius, float radiusInside)
{
	float value = 0.f;

	value = (radius - sqrt(X * X + Y * Y)) * (radius - sqrt(X * X + Y * Y)) + Z * Z - radiusInside * radiusInside;

	return value;
}

float UVoxelLandscapeGenerator::VectorDistanceAB(FVector A, FVector B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2) + pow(A.Z - B.Z, 2));
}

float UVoxelLandscapeGenerator::FractalNoise(float X, float Y, float Z, int seed, int octaves, float amplitude, float frequency)
{
	float value = 0.f;

	for (int i = 0; i < octaves; i++)
	{
		value += USimplexNoiseBPLibrary::SimplexNoise3D(X * frequency, Y * frequency, Z * frequency) * amplitude;
		frequency *= 2.f;
		amplitude *= 0.5f;
	}

	return value;
}

float UVoxelLandscapeGenerator::Cone(FVector p, FVector2D c, float h)
{
	FVector2D q = h * FVector2D(c.X, -c.Y) / c.Y;

	float length = sqrt(p.X * p.X + p.Z * p.Z);

	FVector2D w = FVector2D(length, p.Y);

	FVector2D a = w - q * UKismetMathLibrary::Clamp(FVector2D::DotProduct(w, q) / FVector2D::DotProduct(q, q), 0.0, 1.0);
	FVector2D b = w - q * FVector2D(UKismetMathLibrary::Clamp(w.X / q.X, 0.0, 1.0), 1.0);

	float k = FMath::Sign(q.Y);
	float d = FMath::Min(FVector2D::DotProduct(a, a), FVector2D::DotProduct(b, b));
	float s = FMath::Max(k * (w.X * q.Y - w.Y * q.X), k * (w.Y - q.Y));

	return sqrt(d) * FMath::Sign(s);
}

float UVoxelLandscapeGenerator::IQNoise(FVector p)
{
	float a = 0.0;
	
	return a;
}

float UVoxelLandscapeGenerator::SimplexNoise(float X, float Y, float Z, int seed)
{
	float value = 0.f;

	//USimplexNoiseBPLibrary::setNoiseSeed(seed);
	value = USimplexNoiseBPLibrary::SimplexNoise3D(X, Y, Z);

	return value;
}