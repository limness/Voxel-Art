// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VoxelModificationWorld.generated.h"

class AVoxelWorld;
class UVoxelEditorData;

/*
* Main Voxel Modif class
*/
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class VOXELART_API UVoxelModificationWorld : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void GetPainterData(const float& X, const float& Y, const float& Z, float& noise, float& strength, bool& dig, bool& smooth);

public:

	UFUNCTION(BlueprintCallable)
	static void SpherePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius);

	UFUNCTION(BlueprintCallable)
	static void CubePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius);

	UFUNCTION(BlueprintCallable)
	float BangPainter(int X, int Y, int Z, float Radius, int octaves, float amplitude, float frequency);

private:

	static void UpdateOverlapOctants(AVoxelWorld* World, FIntVector Position, int Size);
};
