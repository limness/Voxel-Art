// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"

class VOXELART_API IVoxelListenersInterface
{
public:

	/*FVoxelListenersDelegates& OnVoxelListenersDelegates()
	{
		return VoxelListenersDelegates;
	}*/

	virtual ~IVoxelListenersInterface() = default;

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