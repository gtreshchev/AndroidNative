// Georgy Treshchev 2022.

#pragma once

#include "CoreMinimal.h"
#include "Templates/UnrealTypeTraits.h"

#include "Logging/LogCategory.h"
#include "Logging/LogMacros.h"
#include "Logging/LogVerbosity.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAndroidNative, Log, All);

/**
 * Convenient approach for "overloading" functions by return type with the same arguments. Achieved thanks to SFINAE.
 */
template <typename FirstSameType, typename SecondSameType, typename Result>
using TEnableIfSame = typename TEnableIf<TIsSame<FirstSameType, SecondSameType>::Value, Result>::Type;