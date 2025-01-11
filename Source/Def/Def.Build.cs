// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Def : ModuleRules
{
	public Def(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
		
		PublicIncludePaths.Add("Def");
	}
}
