// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelSaveData.generated.h"

class AVoxelWorld;
class FVoxelOctreeDensity;

/*
* Voxel Save Data in memory class
*/
USTRUCT(BlueprintType)
struct VOXELART_API FVoxelSaveOctant
{
	GENERATED_BODY()

	UPROPERTY()
	uint8 Depth = 0;

	UPROPERTY()
	int Size = 0;

	UPROPERTY()
	FIntVector Position;

	UPROPERTY()
	TArray<float> DensityMap;

	UPROPERTY()
	TArray<FColor> ColorMap;
};

UCLASS(Blueprintable)
class VOXELART_API UVoxelSaveData : public UObject
{
	GENERATED_BODY()

public:

	void SaveData();
	void LoadSavedData();
	void GetOctreeDensityLeaves(TArray<FVoxelOctreeDensity*>& OctreeDensityLeaves, FVoxelOctreeDensity* CurrentOctant);
	void Init();
	void SetVoxelWorld(AVoxelWorld* _World);

	bool IsDataSaved() { return bDataSaved; }

private:

	AVoxelWorld* World;

	UPROPERTY(VisibleAnywhere, Category = "Voxel Art ~ Save")
	TArray<FVoxelSaveOctant> SavedOctants;

	UPROPERTY(VisibleAnywhere, Category = "Voxel Art ~ Save")
	int WorldSize = 4096;

	UPROPERTY(VisibleAnywhere, Category = "Voxel Art ~ Save")
	uint8 WorldDepth = 0;

	UPROPERTY(VisibleAnywhere, Category = "Voxel Art ~ Save")
	int WorldVoxels = 16;

	UPROPERTY(VisibleAnywhere, Category = "Voxel Art ~ Save")
	float WorldVoxelSize = 128.f;

	UPROPERTY()
	bool bDataSaved = false;
};
