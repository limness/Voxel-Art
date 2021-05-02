// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Stats/Stats.h"

#ifndef VOXELTOOLS_H
#define VOXELTOOLS_H


#define VOXEL_COLOR		FColor(143, 126, 255)

#define NORMALS			2
#define NORMAL			1

VOXELART_API DECLARE_LOG_CATEGORY_EXTERN(VoxelArt, Log, All);

DECLARE_STATS_GROUP(TEXT("Voxel"), STATGROUP_Voxel, STATCAT_Advanced);

#define VOXEL_LOG(FMT, ...) UE_LOG(VoxelArt, Log, (FMT), ##__VA_ARGS__)
#define VOXEL_WARNING(FMT, ...) UE_LOG(LogTemp, Warning, (FMT), ##__VA_ARGS__)
#define VOXEL_ERROR(FMT, ...) UE_LOG(LogTemp, Error, (FMT), ##__VA_ARGS__)

namespace VoxelTools
{
	const float VoxelOffset = 0.001f;
}

#endif VOXELTOOLS_H