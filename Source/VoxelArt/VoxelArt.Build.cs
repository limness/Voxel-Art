// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VoxelArt : ModuleRules
{
	public VoxelArt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		//PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//	bEnforceIWYU = true;
		//bLegacyPublicIncludePaths = false;


		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"RHI",
			"RenderCore",
		//	"ShaderCore",
			"ProceduralMeshComponent",
			"UnrealEd"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore"
		});

		/*if(Target.Type == TargetRules.TargetType.Editor)
        {
			PublicDependencyModuleNames.Add("UnrealEd");
        }*/
		DynamicallyLoadedModuleNames.AddRange(new string[]
		{
		});
	}
}
