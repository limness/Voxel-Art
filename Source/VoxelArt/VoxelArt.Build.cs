// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VoxelArt : ModuleRules
{
	public VoxelArt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"RHI", 
			"RenderCore", 
			"ShaderCore", 
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

		PublicIncludePaths.AddRange(new string[] 
		{
		});


		PrivateIncludePaths.AddRange(new string[] 
		{
		});

		DynamicallyLoadedModuleNames.AddRange(new string[]
		{
		});
	}
}
