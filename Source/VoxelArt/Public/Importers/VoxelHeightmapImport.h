// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "VoxelHeightmapImport.generated.h"

class AVoxelChunk;
class AVoxelLandscape;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew) //hidecategories = (Object)
class VOXELART_API UVoxelHeightmapImport : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, CallInEditor)
	void GenerateHeightmap();

	void ImportTexture();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Importer")
	AVoxelLandscape* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Importer")
	UTexture2D* TextureImage;

	int WidthTexture;
	int HeightTexture;

	TArray<FColor> TextureMap;

	TArray<float> DensityMap;

private:

	//void GenerateDensityMap(AVoxelChunk* chunk);
};
