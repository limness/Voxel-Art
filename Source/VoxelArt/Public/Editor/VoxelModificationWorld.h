// Voxel Art Plugin 2021 ~ Copyright Limit

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
	static void TorusPainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius, float InnerRadius);

	UFUNCTION(BlueprintCallable)
	static void ConePainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius, float Height, FVector2D Angle);

	UFUNCTION(BlueprintCallable)
	static void CopyPainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position, float Radius);

	UFUNCTION(BlueprintCallable)
	static void PastPainter(UVoxelEditorData* Data, AVoxelWorld* World, FIntVector Position);

	UFUNCTION(BlueprintCallable)
	float BangPainter(int X, int Y, int Z, float Radius, int octaves, float amplitude, float frequency);

private:

	static void UpdateOverlapOctants(AVoxelWorld* World, FIntVector Position, FIntVector Size);
};
