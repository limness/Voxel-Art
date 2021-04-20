// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

class VOXELART_API IVoxelListenersInterface
{
public:

	/*FVoxelListenersDelegates& OnVoxelListenersDelegates()
	{
		return VoxelListenersDelegates;
	}*/

	virtual ~IVoxelLoggingInterface() = default;

public:

	DECLARE_MULTICAST_DELEGATE_TwoParams(FVoxelListenersDelegates, IVoxelListenersInterface*, UObject*);
	static FVoxelListenersDelegates VoxelListenersDelegates;

public:

	void StartListeners(UObject* Self);

public:

	virtual void OnPreBeginPIE(bool bIsSimulating)	{}
	virtual void OnEndPIE(bool bIsSimulating)		{}
	virtual void OnPreExit()						{}
};