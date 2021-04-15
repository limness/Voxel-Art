// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

class VOXELART_API IVoxelDelegatesInterface
{
public:

	DECLARE_MULTICAST_DELEGATE_TwoParams(FStartupDelegates, IVoxelDelegatesInterface*, UObject*);
	static FStartupDelegates BindStartupDelegates;

	void StartupDelegates(UObject* Self)
	{
		BindStartupDelegates.Broadcast(this, Self);
	}

	virtual ~IVoxelDelegatesInterface() = default;

	virtual void OnPreBeginPIE(bool bIsSimulating) {}

	virtual void OnEndPIE(bool bIsSimulating) {}
};