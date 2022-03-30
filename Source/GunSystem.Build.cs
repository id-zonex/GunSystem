// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GunSystem : ModuleRules
{
	public GunSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Slate", "SlateCore", "UnrealEd", "PropertyEditor"});
	}
}
