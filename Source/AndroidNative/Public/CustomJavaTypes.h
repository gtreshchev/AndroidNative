// Georgy Treshchev 2023.

#pragma once

#include "CoreMinimal.h"
#include "JavaConvert.h"

/**
 * Used when a custom Java object needs to be passed as an argument with a custom signature
 */
ANDROIDNATIVE_API struct FCustomJavaArgument
{
	FCustomJavaArgument(jobject Value, FString Signature)
		: Value(Value), Signature(Signature)
	{
	}

	const jobject& GetValue() const
	{
		return Value;
	}

	const FString& GetSignature() const
	{
		return Signature;
	}

protected:
	jobject Value;
	FString Signature;
};

/**
 * Used to pass game activity
 */
ANDROIDNATIVE_API struct FAndroidGameActivity : FCustomJavaArgument
{
	/** Use this constructor if you want to use the default game activity */
	FAndroidGameActivity()
		: FCustomJavaArgument(FJavaWrapper::GameActivityThis, "Landroid/app/Activity;")
	{
	}

	/** Use this constructor if you have a custom game activity */
	FAndroidGameActivity(jobject CustomGameActivity)
		: FCustomJavaArgument(CustomGameActivity, "Landroid/app/Activity;")
	{
	}
};

/**
 * Check if the type matches the custom java type. All child classes are also accepted
 */
template <typename AnyType>
using TIsCustomJavaArgument = TIsDerivedFrom<AnyType, FCustomJavaArgument>;

/**
 * Enable if the type is a custom Java argument
 */
template <typename AnyType>
using TEnableIfCustomJavaArgument = typename TEnableIf<TIsCustomJavaArgument<AnyType>::Value, bool>::Type;

/**
 * Enable if the type is not a custom Java argument
 */
template <typename AnyType>
using TEnableIfNotCustomJavaArgument = typename TEnableIf<!TIsCustomJavaArgument<AnyType>::Value, bool>::Type;