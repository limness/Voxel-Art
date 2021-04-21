// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "VoxelHeightmapImport.generated.h"

class AVoxelWorld;
class AVoxelWorldGenerator;

/**
 * Heightmap Utilities class
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelHeightmapImport : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, CallInEditor)
	static void ExportHeightmap(AVoxelWorld* World, UVoxelWorldGenerator* WorldGenerator);

public:

	//TODO: Transfer all variables for texture data from Voxel World class to here
};
