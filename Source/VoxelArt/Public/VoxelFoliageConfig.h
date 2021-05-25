// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelFoliageConfig.generated.h"


UENUM()
enum EFoliageSpawnerType
{
	FlatWorld	UMETA(DisplayName = "Flat World")
};

USTRUCT(BlueprintType)
struct VOXELART_API FVoxelFoliageObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"), DisplayName = "Interval (in voxels)")
	int Steps = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"), DisplayName = "Radius (in chunks)")
	int DrawingRadius = 4;

	//TODO: Make priority system
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"), DisplayName = "Priority")
	int Priority = 0;

	FVoxelFoliageObject()
	{
	}
};

/*
* Voxel Foliage Config class
* Use this in any case when you want to edit World in real time
*/
UCLASS(BlueprintType)
class VOXELART_API UVoxelFoliageConfig : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage ~ Main")
	TEnumAsByte<EFoliageSpawnerType> SpawnerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage ~ Objects")
	TArray<FVoxelFoliageObject> FoliageObject;
};