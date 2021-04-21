// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FVoxelArtModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
