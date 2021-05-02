// Voxel Art Plugin 2021 ~ Copyright Limit

using System.IO;
using UnrealBuildTool;

public class VoxelArtEditor : ModuleRules
{
    public VoxelArtEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;
        bLegacyPublicIncludePaths = false;

        PublicDependencyModuleNames.AddRange(new string[] { "VoxelArt" });
        PrivateDependencyModuleNames.AddRange(new string[] { "Projects" });

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "Engine",
                "CoreUObject",
                "InputCore",
                "LevelEditor",
                "Slate",
                "UnrealEd",
                "EditorStyle",
                "AssetTools",
                "EditorWidgets",
                "BlueprintGraph",
                "AnimGraph",
                "ComponentVisualizers",
                "AssetRegistry",
                "PlacementMode",
               // "VoxelArtGraph",
               // "VoxelArtGraphEditor"
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