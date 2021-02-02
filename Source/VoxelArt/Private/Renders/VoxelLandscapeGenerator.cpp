// Fill out your copyright notice in the Description page of Project Settings.

#include "Renders/VoxelLandscapeGenerator.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"

UVoxelLandscapeGenerator::UVoxelLandscapeGenerator(const class FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	if (HeightmapTexture && World)
	{
		FTexture2DMipMap* MyMipMap = &HeightmapTexture->PlatformData->Mips[0];

		WidthTexture = (int)MyMipMap->SizeX;
		HeightTexture = (int)MyMipMap->SizeY;

		HeightmapTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
		HeightmapTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
		HeightmapTexture->SRGB = false;
		HeightmapTexture->UpdateResource();

		TextureCompressionSettings OldCompressionSettings = HeightmapTexture->CompressionSettings; 
		TextureMipGenSettings OldMipGenSettings = HeightmapTexture->MipGenSettings; 
		bool OldSRGB = HeightmapTexture->SRGB;

		const FColor* FormatedImageData = static_cast<const FColor*>(HeightmapTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

		TextureMap.Init(FColor(0, 0, 0), WidthTexture * HeightTexture);

		for (int y = 0; y < HeightTexture; y++)
		{
			for (int x = 0; x < WidthTexture; x++)
			{
				TextureMap[y * WidthTexture + x] = FormatedImageData[y * WidthTexture + x];
			}
		}

		HeightmapTexture->PlatformData->Mips[0].BulkData.Unlock();

		HeightmapTexture->CompressionSettings = OldCompressionSettings;
		HeightmapTexture->MipGenSettings = OldMipGenSettings;
		HeightmapTexture->SRGB = OldSRGB;
		HeightmapTexture->UpdateResource();

		RadiusHeighestVoxel = World->radiusOfChunk / (float)World->voxelsOneChunk;

		for (int i = 0; i < World->maximumLOD; i++)
		{
 			RadiusHeighestVoxel = (float)(RadiusHeighestVoxel / 2.f);
		}
	}
}

FORCEINLINE float UVoxelLandscapeGenerator::GetHeightmapData(float X, float Y, float Z) const
{
	if (TextureMap.Num() < 1) return 0.f;
	if (round(X / RadiusHeighestVoxel) > WidthTexture - 1 || round(X / RadiusHeighestVoxel) < 0) return 0.f;
	if (round(Y / RadiusHeighestVoxel) > HeightTexture - 1 || round(Y / RadiusHeighestVoxel) < 0) return 0.f;

	return (TextureMap[round(Y / RadiusHeighestVoxel) * WidthTexture + round(X / RadiusHeighestVoxel)].R - 128.f) / 63.f * 100.f;
}

/*void UVoxelLandscapeGenerator::GetNoiseData(const float& X, const float& Y, const float& Z, float& noise)
{
	noise = 0.f;
}

void UVoxelLandscapeGenerator::GetColor(const FVector& POS, FLinearColor& color)
{
	color = FLinearColor(0.f, 0.f, 0.f);
}

float UVoxelLandscapeGenerator::GetNoiseData_Implementation(float Xxaf, float Ysdg, float ZwasfghJfwa)
{
	float noise = 450.f;

	return noise;
}

*/

/*void UVoxelLandscapeGenerator::GetColor(const FVector& POS, FLinearColor& color)
{
	color = FLinearColor(0.f, 0.f, 0.f);
}*/

void UVoxelLandscapeGenerator::SetColorMap_Implementation(const float& X, const float& Y, const float& Z, FColor& color)
{
	if (VectorDistanceAB(FVector(X, Y, Z), FVector(0, 0, 0)) > 60000.0f)
	{
		color = FColor(255, 18, 10);
	}
	else
	{
		color = FColor(128, 223, 255);
	}
	//color = FColor(121.f, 121.f, 121.f);
}

void UVoxelLandscapeGenerator::SetDensityMap_Implementation(const float& X, const float& Y, const float& Z, float& noise)
{
	//noise = SphereLandscape(X, Y, Z, 90000.f);
	//noise -= FractalNoise(X, Y, Z, 0, 5, 15000.f, 0.00001f);

	//noise = UKismetMathLibrary::FMin(noise, FlatLandscape(-X));
	noise = -(Z + 5000.f);
}

float UVoxelLandscapeGenerator::GetDensityMap(const FVector& CellPosition)
{
	float noise = -(CellPosition.Z - GetHeightmapData(CellPosition.X, CellPosition.Y, CellPosition.Z));
	//SetDensityMap_Implementation(CellPosition.X, CellPosition.Y, CellPosition.Z, noise);
	return noise;
}

FColor UVoxelLandscapeGenerator::GetColorMap(const FVector& CellPosition)
{
	FColor color = FColor(121.f, 121.f, 121.f);
	//SetColorMap(CellPosition.X, CellPosition.Y, CellPosition.Z, color);
	if (VectorDistanceAB(FVector(CellPosition.X, CellPosition.Y, CellPosition.Z), FVector(0, 0, 0)) > 60000.0f)
	{
		color = FColor(255, 18, 10);
	}
	else
	{
		color = FColor(128, 223, 255);
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

	//USimplexNoiseBPLibrary::setNoiseSeed(seed);

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

/*float iqTurbulence(float2 p, float seed, int octaves, float lacunarity = 2.0, float gain = 0.5)
{
	float sum = 0.5;
	float freq = 1.0, amp = 1.0;
	float2 dsum = float2(0, 0);
	for (int i = 0; i < octaves; i++)
	{
		FVector n = perlinNoisePseudoDeriv(p * freq, seed + i / 256.0);
		dsum += n.yz;
		sum += amp * n.X / (1 + dot(dsum, dsum));
		freq *= lacunarity;
		amp *= gain;
	}
	return sum;
}*/

float UVoxelLandscapeGenerator::IQNoise(FVector p)
{
	float a = 0.0;
	float b = 1.0;
	FVector d = FVector(0.f, 0.f, 0.f);

	for (int i = 0; i < 15; i++)
	{
	/*	FVector n = USimplexNoiseBPLibrary::SimplexNoise3D(p);
		d += n.yz;
		a += b * n.X / (1.0 + dot(d, d));
		b *= 0.5;
		p = m * p * 2.0;*/
	}
	return a;
}

float UVoxelLandscapeGenerator::SimplexNoise(float X, float Y, float Z, int seed)
{
	float value = 0.f;

	//USimplexNoiseBPLibrary::setNoiseSeed(seed);
	value = USimplexNoiseBPLibrary::SimplexNoise3D(X, Y, Z);

	return value;
}