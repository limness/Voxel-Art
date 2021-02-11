// Fill out your copyright notice in the Description page of Project Settings.

#include "Renders/VoxelLandscapeGenerator.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"

UVoxelLandscapeGenerator::UVoxelLandscapeGenerator(const class FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
}

//void UVoxelLandscapeGenerator::PostLoad()
void UVoxelLandscapeGenerator::GeneratorInit()
{
//	Super::PostLoad();

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

		RadiusHeighestVoxel = World->WorldRadius / (float)World->VoxelsPerChunk;

		for (int i = 0; i < World->MaximumLOD; i++)
		{
			RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
		}
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

		RadiusHeighestVoxel = World->WorldRadius / (float)World->VoxelsPerChunk;

		for (int i = 0; i < World->MaximumLOD; i++)
		{
			RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
		}
	}
}


FORCEINLINE float UVoxelLandscapeGenerator::GetHeightmapData(float X, float Y, float Z) const
{
	X += WidthHeightmap / 2.f * RadiusHeighestVoxel;
	Y += HeightHeightmap / 2.f * RadiusHeighestVoxel;

	if (round(X / RadiusHeighestVoxel) > WidthHeightmap - 1 || round(X / RadiusHeighestVoxel) < 0) return -1.f;
	if (round(Y / RadiusHeighestVoxel) > HeightHeightmap - 1 || round(Y / RadiusHeighestVoxel) < 0) return -1.f;
	
	return -(Z - (TextureHeightMap[round(Y / RadiusHeighestVoxel) * WidthHeightmap + round(X / RadiusHeighestVoxel)].R - 128.f) / 63.f * Multiply);
}

FORCEINLINE FColor UVoxelLandscapeGenerator::GetColormapData(float X, float Y, float Z) const
{
	X += WidthColormap / 2.f * RadiusHeighestVoxel;
	Y += HeightColormap / 2.f * RadiusHeighestVoxel;

	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : GetColormapData ] Error: 2 neighbor empty"));

	if (round(X / RadiusHeighestVoxel) > WidthColormap - 1 || round(X / RadiusHeighestVoxel) < 0) return FColor(121.f, 121.f, 121.f);
	if (round(Y / RadiusHeighestVoxel) > HeightColormap - 1 || round(Y / RadiusHeighestVoxel) < 0) return FColor(121.f, 121.f, 121.f);


	return TextureColorMap[round(Y / RadiusHeighestVoxel) * WidthColormap + round(X / RadiusHeighestVoxel)];
}

float UVoxelLandscapeGenerator::GetDensityMap(const FVector& CellPosition)
{
	float noise = 0.f;
	noise = TextureHeightMap.Num() > 0 ? GetHeightmapData(CellPosition.X, CellPosition.Y, CellPosition.Z) : -(CellPosition.Z + 5000.f);
	return noise;
}

FColor UVoxelLandscapeGenerator::GetColorMap(const FVector& CellPosition)
{
	FColor color = FColor(121.f, 121.f, 121.f);

	if (TextureColorMap.Num() > 0)
	{
		color = GetColormapData(CellPosition.X, CellPosition.Y, CellPosition.Z);
	}
	else
	{
		if (VectorDistanceAB(FVector(CellPosition.X, CellPosition.Y, CellPosition.Z), FVector(0, 0, 0)) > 60000.0f)
		{
			color = FColor(255, 18, 10);
		}
		else
		{
			color = FColor(128, 223, 255);
		}
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