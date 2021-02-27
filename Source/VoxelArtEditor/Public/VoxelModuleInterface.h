
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "ModuleManager.h"
#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"

class IVoxelModuleListenerInterface
{
public:
    virtual void OnStartupModule() {};
    virtual void OnShutdownModule() {};
};

class IVoxelModuleInterface : public IModuleInterface
{

public:

    // Begin IModuleInterface implementation
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    // End IModuleInterface implementation

    static inline IVoxelModuleInterface& Get()
    {
        return FModuleManager::LoadModuleChecked< IVoxelModuleInterface >("VoxelArtEditor");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("VoxelArtEditor");
    }

    TArray<TSharedRef<IVoxelModuleListenerInterface>> ModuleListeners;

public:
    void AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before);
    TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };

protected:
    TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
    TSharedPtr<FExtender> MenuExtender;

    static TSharedRef<FWorkspaceItem> MenuRoot;

    void MakePulldownMenu(FMenuBarBuilder& menuBuilder);
    void FillPulldownMenu(FMenuBuilder& menuBuilder);

};


/*class IVoxelModuleListenerInterface
{
public:
    virtual void OnStartupModule() {};
    virtual void OnShutdownModule() {};
};

class IVoxelModuleInterface : public IModuleInterface
{
public:
    void StartupModule() override
    {
        if (!IsRunningCommandlet())
        {
            AddModuleListeners();
            for (int32 i = 0; i < ModuleListeners.Num(); ++i)
            {
                ModuleListeners[i]->OnStartupModule();
            }
        }
    }

    void ShutdownModule() override
    {
        for (int32 i = 0; i < ModuleListeners.Num(); ++i)
        {
            ModuleListeners[i]->OnShutdownModule();
        }
    }

    virtual void AddModuleListeners() {};

protected:
    TArray<TSharedRef<IVoxelModuleListenerInterface>> ModuleListeners;
};
*/
