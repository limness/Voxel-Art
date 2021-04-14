// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"

class VOXELART_API IVoxelDelegatesInterface
{
public:
//#if WITH_EDITOR
	DECLARE_MULTICAST_DELEGATE_TwoParams(FBindEditorDelegates, IVoxelDelegatesInterface*, UObject*);
	static FBindEditorDelegates BindEditorDelegatesDelegate;

	void BindEditorDelegates(UObject* Self)
	{
		BindEditorDelegatesDelegate.Broadcast(this, Self);
	}

	virtual ~IVoxelDelegatesInterface() = default;

	virtual void OnPreBeginPIE(bool bIsSimulating) {}

	virtual void OnEndPIE(bool bIsSimulating) {}
//#endif
};