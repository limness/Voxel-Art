// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Editor/VoxelEditorData.h"

void UVoxelEditorData::ClearCopiedData()
{
	CopiedDensity.Empty();

	CenterCopy =	FIntVector(0, 0, 0);
	CornerMin =		FIntVector(0, 0, 0);
	CornerMax =		FIntVector(0, 0, 0);

	CopyingPasting = ECopyingPasting::Copying;
}
