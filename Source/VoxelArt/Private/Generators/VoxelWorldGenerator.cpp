// Voxel Art Plugin © limit 2018

#include "Generators/VoxelWorldGenerator.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/VoxelTools.h"

DECLARE_CYCLE_STAT(TEXT("Voxel World ~ Generator Init ~ Heightmap"), STAT_GeneratorHeightmap, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel World ~ Generator Init ~ Colormap"), STAT_GeneratorColormap, STATGROUP_Voxel);


void UVoxelWorldGenerator::GeneratorInit()
{
	if (HeightmapTexture && World)
	{
		SCOPE_CYCLE_COUNTER(STAT_GeneratorHeightmap);

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
	}
	if (ColormapTexture && World)
	{
		SCOPE_CYCLE_COUNTER(STAT_GeneratorColormap);

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
	}
}


FORCEINLINE float UVoxelWorldGenerator::GetHeightmapData(float X, float Y, float Z) const
{
	float offset = 0.001f;
	float MapX = X + WidthHeightmap / 2.f;
	float MapY = Y + HeightHeightmap / 2.f;

	if (MapX > WidthHeightmap - 1 || MapX < 0) return 1.f;
	if (MapY > HeightHeightmap - 1 || MapY < 0) return 1.f;

	return Z - (TextureHeightMap[round(MapY) * WidthHeightmap + round(MapX)].R - 128.f) / 63.f * Multiply + offset;
}

FORCEINLINE FColor UVoxelWorldGenerator::GetColormapData(float X, float Y, float Z) const
{
	float MapX = X + WidthColormap / 2.f;
	float MapY = Y + HeightColormap / 2.f;

	if (MapX > WidthColormap - 1 || MapX < 0) return VOXEL_COLOR;
	if (MapY > HeightColormap - 1 || MapY < 0) return VOXEL_COLOR;

	return TextureColorMap[round(MapY) * WidthColormap + round(MapX)];
}

float UVoxelWorldGenerator::GetDensityMap(const FIntVector& CellPosition)
{
	float Value = 0.f;

	if (TextureHeightMap.Num() > 0)
	{
		Value = GetHeightmapData(CellPosition.X, CellPosition.Y, CellPosition.Z);
	}
	return Value;
}

FColor UVoxelWorldGenerator::GetColorMap(const FIntVector& CellPosition)
{
	FColor color = VOXEL_COLOR;

	if (TextureColorMap.Num() > 0)
	{
		color = GetColormapData(CellPosition.X, CellPosition.Y, CellPosition.Z);
	}
	return color;
}

float UVoxelWorldGenerator::FlatSDF(int A)
{
	float Value = 0.f;

	if (A >= 0)
	{
		Value = (-1) * UKismetMathLibrary::FMax(1.f, A);
	}
	else if (A < 0)
	{
		Value = (-1) * UKismetMathLibrary::FMin(-1.f, A);
	}
	return Value;
}


float UVoxelWorldGenerator::SphereSDF(int X, int Y, int Z, float Radius)
{
	float Value = 0.f;

	Value = Radius - FVector(X, Y, Z).Size();

	return -Value;
}

float UVoxelWorldGenerator::TorusSDF(int X, int Y, int Z, float Radius, float RadiusInside)
{
	float Value = 0.f;

	Value = (Radius - sqrt(X * X + Y * Y)) * (Radius - sqrt(X * X + Y * Y)) + Z * Z - RadiusInside * RadiusInside;

	return Value;
}

float UVoxelWorldGenerator::FractalNoise(int X, int Y, int Z, int Octaves, float Amplitude, float Frequency)
{
	float Value = 0.f;

	for (int i = 0; i < Octaves; i++)
	{
		Value += USimplexNoiseBPLibrary::SimplexNoise3D(X * Frequency, Y * Frequency, Z * Frequency) * Amplitude;
		Frequency *= 2.f;
		Amplitude *= 0.5f;
	}
	return Value;
}

float UVoxelWorldGenerator::ConeSDF(FVector p, FVector2D c, float h)
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

float UVoxelWorldGenerator::IQNoise(FVector p)
{
	float a = 0.0;
	
	return a;
}

float UVoxelWorldGenerator::SimplexNoise(int X, int Y, int Z)
{
	float value = 0.f;

	value = USimplexNoiseBPLibrary::SimplexNoise3D(X, Y, Z);

	return value;
}