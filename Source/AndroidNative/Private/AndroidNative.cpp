// Georgy Treshchev 2022.

#include "AndroidNative.h"

#include "AndroidNativeDefines.h"

#define LOCTEXT_NAMESPACE "FAndroidNativeModule"

void FAndroidNativeModule::StartupModule()
{
}

void FAndroidNativeModule::ShutdownModule()
{
}

DEFINE_LOG_CATEGORY(LogAndroidNative);

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAndroidNativeModule, AndroidNative)