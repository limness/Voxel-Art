// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "VoxelHeightmapImport.generated.h"

class AVoxelWorld;

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
	AVoxelWorld* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Importer")
	UTexture2D* TextureImage;

	int WidthTexture;
	int HeightTexture;

	TArray<FColor> TextureMap;

	TArray<float> DensityMap;

private:

	//void GenerateDensityMap(AVoxelChunk* chunk);
};
