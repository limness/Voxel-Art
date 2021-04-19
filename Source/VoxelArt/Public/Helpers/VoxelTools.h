// Voxel Art Plugin ~ Copyright limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Stats/Stats.h"

#ifndef VOXELTOOLS_H
#define VOXELTOOLS_H


#define VOXEL_COLOR		FColor(143, 126, 255)

#define NORMALS			2
#define NORMAL			1


DECLARE_LOG_CATEGORY_EXTERN(VoxelArt, Log, All);

DECLARE_STATS_GROUP(TEXT("Voxel"), STATGROUP_Voxel, STATCAT_Advanced);

namespace VoxelTools
{
	const float VoxelOffset = 0.001f;
}

#endif VOXELTOOLS_H