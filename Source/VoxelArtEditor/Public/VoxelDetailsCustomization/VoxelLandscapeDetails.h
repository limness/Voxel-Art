
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "Input/Reply.h"

#include "VoxelLandscape.h"

class IVoxelLandscapeDetails : public IDetailCustomization
{
public:

    /** Makes a new instance of this detail layout class for a specific detail view requesting it */
    static TSharedRef<IDetailCustomization> MakeInstance();

    /** IDetailCustomization interface */
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

protected:
    // widget functions
   // ECheckBoxState IsModeRadioChecked(AVoxelLandscape* actor, int optionIndex) const;
   // void OnModeRadioChanged(ECheckBoxState CheckType, AVoxelLandscape* actor, int optionIndex);

    FReply CreateWorldInEditor();
    FReply DestroyWorldInEditor();
    FReply UpdateWorldInEditor();

private:

    TWeakObjectPtr<AVoxelLandscape> World;
};
