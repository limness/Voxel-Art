
//#include "ToolExampleEditor/ToolExampleEditor.h"
//#include "ToolExampleEditor/IExampleModuleInterface.h"

#include "VoxelModuleInterface.h"

#include "TabManager.h"
#include "SDockTab.h"

class FVoxelTabToolBase : public IVoxelModuleListenerInterface, public TSharedFromThis< FVoxelTabToolBase >
{
public:
    // IPixelopusToolBase
    virtual void OnStartupModule() override
    {
        Initialize();
        FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabName, FOnSpawnTab::CreateRaw(this, &FVoxelTabToolBase::SpawnTab))
            .SetGroup(IVoxelModuleInterface::Get().GetMenuRoot())
            .SetDisplayName(TabDisplayName)
            .SetTooltipText(ToolTipText);
    };

    virtual void OnShutdownModule() override
    {
        FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabName);
    };

    /** Set the objects to be displayed in the details panel */
    void SetObjects(const TArray<TWeakObjectPtr<>>& InSelectedObjects, const TArray<FGuid>& InObjectBindings);

    // In this function set TabName/TabDisplayName/ToolTipText
    virtual void Initialize() {};
    virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) { return SNew(SDockTab); };

    virtual void MakeMenuEntry(FMenuBuilder& menuBuilder)
    {
        FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, TabName);
    };

protected:
    FName TabName;
    FText TabDisplayName;
    FText ToolTipText;
};