// Georgy Treshchev 2024.

#pragma once

#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

#include "Templates/UnrealTypeTraits.h"
#if UE_VERSION_NEWER_THAN(5, 2, 0)
#include <type_traits>
#endif

#include "Logging/LogCategory.h"
#include "Logging/LogMacros.h"
#include "Logging/LogVerbosity.h"

ANDROIDNATIVE_API DECLARE_LOG_CATEGORY_EXTERN(LogAndroidNative, Log, All);

/**
 * Convenient approach for "overloading" functions by return type with the same arguments. Achieved thanks to SFINAE.
 */
template <typename FirstSameType, typename SecondSameType, typename Result>
using TEnableIfSame =
#if UE_VERSION_NEWER_THAN(5, 2, 0)
	typename TEnableIf<std::is_same<FirstSameType, SecondSameType>::value, Result>::Type;
#else
	typename TEnableIf<TIsSame<FirstSameType, SecondSameType>::Value, Result>::Type;
#endif