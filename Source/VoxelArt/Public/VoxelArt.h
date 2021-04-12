// Voxel Art Plugin © limit 2018

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
