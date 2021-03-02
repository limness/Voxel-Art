using UnrealBuildTool;

public class VoxelArtEditor : ModuleRules
{
    public VoxelArtEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PublicDependencyModuleNames.AddRange(new string[] { "VoxelArt" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Projects" });

        PublicIncludePaths.AddRange(
            new string[]
            {
           //     "VoxelArtEditor/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "VoxelArtEditor/Private"
            });

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "Engine",
                "CoreUObject",
                "InputCore",
                "LevelEditor",
                "Slate",
                "EditorStyle",
                "AssetTools",
                "EditorWidgets",
                "UnrealEd",
                "BlueprintGraph",
                "AnimGraph",
                "ComponentVisualizers"
        }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "AppFramework",
                "SlateCore",
                "AnimGraph",
                "UnrealEd",
                "KismetWidgets",
                "MainFrame",
                "PropertyEditor",
                "ComponentVisualizers"
            }
            );
    }
}