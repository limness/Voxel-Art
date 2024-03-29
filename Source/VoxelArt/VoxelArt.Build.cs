// Voxel Art Plugin 2021 ~ Copyright Limit

using UnrealBuildTool;
using System.IO;

public class VoxelArt : ModuleRules
{
	public VoxelArt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;


		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"RHI",
			"RenderCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore"
		});

		DynamicallyLoadedModuleNames.AddRange(new string[]
		{
		});
	}
}
