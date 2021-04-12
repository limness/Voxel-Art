// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

#define VOXEL_COLOR		FColor(143, 126, 255)

#define NORMALS			2
#define NORMAL			1


DECLARE_STATS_GROUP(TEXT("Voxel"), STATGROUP_Voxel, STATCAT_Advanced);

DECLARE_LOG_CATEGORY_EXTERN(VoxelArt, Log, All);

namespace VoxelTools
{
	const float Offset = 0.001f;
}