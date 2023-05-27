// Georgy Treshchev 2023.

using UnrealBuildTool;

using System.IO;

public class AndroidNative : ModuleRules
{
	public AndroidNative(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDependencyModuleNames.Add("Launch");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "AndroidNative_UPL_Android.xml"));
		}

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Core"
			}
		);
	}
}