using UnrealBuildTool;

public class VoxelArtEditor : ModuleRules
{
    public VoxelArtEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        // PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PublicDependencyModuleNames.AddRange(new string[] { "VoxelArt" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(
            new string[]
            {
                "TutorialEditor/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "TutorialEditor/Private"
            });
    }
}