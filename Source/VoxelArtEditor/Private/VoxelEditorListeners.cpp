// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelEditorListeners.h"

void FVoxelEditorListeners::StartListeners(IVoxelListenersInterface* Interface, UObject* Object)
{
    if (!FCoreDelegates::OnPreExit.IsBoundToObject(Object))
    {
        FCoreDelegates::OnPreExit.AddWeakLambda(Object, [=]() 
            { 
                Interface->OnPreExit(); 
            });
    }
    if (!FEditorDelegates::EndPIE.IsBoundToObject(Object))
    {
        FEditorDelegates::EndPIE.AddWeakLambda(Object, [=](bool bIsSimulating)
            {  
                Interface->OnEndPIE(bIsSimulating); 
            });
    }
    if (!FEditorDelegates::PreBeginPIE.IsBoundToObject(Object))
    {
        FEditorDelegates::PreBeginPIE.AddWeakLambda(Object, [=](bool bIsSimulating)
            {  
                Interface->OnPreBeginPIE(bIsSimulating); 
            });
    }
}