// Georgy Treshchev 2024.

#pragma once

#include "Modules/ModuleManager.h"

class FAndroidNativeModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
