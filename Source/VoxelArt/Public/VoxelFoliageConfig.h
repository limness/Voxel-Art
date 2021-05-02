// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "VoxelFoliageConfig.generated.h"

/*
* Voxel Foliage Config class
* Use this in any case when you want to edit World in real time
*/
UCLASS(BlueprintType)
class VOXELART_API UVoxelFoliageConfig : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int test = 0.f;
};
