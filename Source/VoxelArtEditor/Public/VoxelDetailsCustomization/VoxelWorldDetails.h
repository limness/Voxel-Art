
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "Input/Reply.h"

#include "VoxelWorld.h"

class IVoxelWorldDetails : public IDetailCustomization
{
public:

    /** Makes a new instance of this detail layout class for a specific detail view requesting it */
    static TSharedRef<IDetailCustomization> MakeInstance();

    /** IDetailCustomization interface */
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

protected:

    FReply CreateWorldInEditor();
    FReply SaveWorldInEditor();
    FReply DestroyWorldInEditor();

    FReply CreateTextureInEditor();

private:

    TWeakObjectPtr<AVoxelWorld> World;
};
