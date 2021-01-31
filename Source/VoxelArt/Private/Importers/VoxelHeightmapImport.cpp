// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelHeightmapImport.h"


//void UVoxelHeightmapImport::GenerateDensityMap(AVoxelChunk* chunk)
//{
	/*
	chunk->Grid.Empty();
	chunk->Grid.Init(-1.0, pow((chunk->voxels + 1 + NORMALS_SKIRT), 3));

	float radiusHeighestVoxel = radiusOfChunk / (float)voxelsOneChunk;

	for (int i = 0; i < maximumLOD; i++)
	{
		radiusHeighestVoxel = (float)(radiusHeighestVoxel / 2.f);
	}

	float radiusVoxel = chunk->GetVoxelSize();

	for (int z = 0; z < chunk->voxels + 1 + NORMALS_SKIRT; z++)
	{
		for (int y = 0; y < chunk->voxels + 1 + NORMALS_SKIRT; y++)
		{
			for (int x = 0; x < chunk->voxels + 1 + NORMALS_SKIRT; x++)
			{
				FVector positionNoise;

				positionNoise.X = ((x - NORMALS_SKIRT_HALF) * radiusVoxel);
				positionNoise.Y = ((y - NORMALS_SKIRT_HALF) * radiusVoxel);
				positionNoise.Z = ((z - NORMALS_SKIRT_HALF) * radiusVoxel);
				positionNoise = positionNoise - (float)(chunk->radius / 2.f);
				positionNoise += chunk->GetActorLocation();
				//positionNoise = positionNoise + radiusOfChunk / 2.f;

				positionNoise.X += radiusOfChunk / 2.f;
				positionNoise.Y += radiusOfChunk / 2.f;
				//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Landscape was generated %f %f"), round(positionNoise.X / radiusHeighestVoxel), round(positionNoise.Y / radiusHeighestVoxel));

				if (round(positionNoise.X / radiusHeighestVoxel) > WidthTexture - 1 || round(positionNoise.X / radiusHeighestVoxel) < 0) continue;
				if (round(positionNoise.Y / radiusHeighestVoxel) > HeightTexture - 1 || round(positionNoise.Y / radiusHeighestVoxel) < 0) continue;

				DensityMap[x + y * (chunk->voxels + 1 + NORMALS_SKIRT) + z * (chunk->voxels + 1 + NORMALS_SKIRT) * (chunk->voxels + 1 + NORMALS_SKIRT)] = -(positionNoise.Z -
					(TextureMap[round(positionNoise.Y / radiusHeighestVoxel) * WidthTexture + round(positionNoise.X / radiusHeighestVoxel)].R - 128.f) / 63.f * 100.f);//-(positionNoise.Z - value);

			}
		}
	}*/

//}


void UVoxelHeightmapImport::ImportTexture()
{
	FTexture2DMipMap* MyMipMap = &TextureImage->PlatformData->Mips[0];
	FByteBulkData* RawImageData = &MyMipMap->BulkData;

	WidthTexture = (int)MyMipMap->SizeX;
	HeightTexture = (int)MyMipMap->SizeY;

	TextureImage->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	TextureImage->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	TextureImage->SRGB = false;
	TextureImage->UpdateResource();

	TextureCompressionSettings OldCompressionSettings = TextureImage->CompressionSettings; TextureMipGenSettings OldMipGenSettings = TextureImage->MipGenSettings; bool OldSRGB = TextureImage->SRGB;

	const FColor* FormatedImageData = static_cast<const FColor*>(TextureImage->PlatformData->Mips[0].BulkData.LockReadOnly());

	TextureMap.Empty();
	TextureMap.Init(FColor(0, 0, 0), WidthTexture * HeightTexture);

	for (int y = 0; y < HeightTexture; y++)
	{
		for (int x = 0; x < WidthTexture; x++)
		{
			TextureMap[y * WidthTexture + x] = FormatedImageData[y * WidthTexture + x];
		}
	}//);


	TextureImage->PlatformData->Mips[0].BulkData.Unlock();

	TextureImage->CompressionSettings = OldCompressionSettings;
	TextureImage->MipGenSettings = OldMipGenSettings;
	TextureImage->SRGB = OldSRGB;
	TextureImage->UpdateResource();
}

void UVoxelHeightmapImport::GenerateHeightmap()
{
	ImportTexture();
}
