// Georgy Treshchev 2022.

#pragma once

#include "AndroidNativeDefines.h"

#include "JavaConvert.h"
#include "CustomJavaTypes.h"

/**
 * Helper in working with Java VM's signatures
 */
namespace SignatureHelper
{
	/** Get the signature for Void type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, void, const ANSICHAR*>
	GetTypeSignature() { return "V"; }

	/** Get the signature for Bool type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, bool, const ANSICHAR*>
	GetTypeSignature() { return "Z"; }

	/** Get the signature for Byte type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, uint8, const ANSICHAR*>
	GetTypeSignature() { return "B"; }

	/** Get the signature for Char type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, UTF16CHAR, const ANSICHAR*>
	GetTypeSignature() { return "C"; }

	/** Get the signature for Short type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, short, const ANSICHAR*>
	GetTypeSignature() { return "S"; }

	/** Get the signature for Int type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, int32, const ANSICHAR*>
	GetTypeSignature() { return "I"; }

	/** Get the signature for Long type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, long, const ANSICHAR*>
	GetTypeSignature() { return "J"; }

	/** Get the signature for Float type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, float, const ANSICHAR*>
	GetTypeSignature() { return "F"; }

	/** Get the signature for Double type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, double, const ANSICHAR*>
	GetTypeSignature() { return "D"; }

	/** Get the signature for Int type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, FString, const ANSICHAR*>
	GetTypeSignature() { return "Ljava/lang/String;"; }

	/** Get the signature for Object Array type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, jobjectArray, const ANSICHAR*>
	GetTypeSignature() { return "[Ljava/lang/Object;"; }

	/** Get the signature for Object type */
	template <typename PassedType>
	static FORCEINLINE TEnableIfSame<PassedType, jobject, const ANSICHAR*>
	GetTypeSignature() { return "Ljava/lang/Object;"; }

	/** Get the signature for the type contained in TArray */
	template <typename PassedType>
	static FORCEINLINE typename TEnableIf<TIsTArray<PassedType>::Value, const ANSICHAR*>::Type
	GetTypeSignature() { return TCHAR_TO_ANSI(*FString::Printf(TEXT("[%s"), *FString(GetTypeSignature<typename PassedType::ElementType>()))); }

	/**
	 * In case no arguments and type are specified
	 */
	static void GetTypeSignatures(FString&)
	{
	}

	/**
	 * Recursively get type signatures
	 */
	template <typename AnyType, TEnableIfNotCustomJavaArgument<AnyType> = true, typename... Args>
	static void GetTypeSignatures(FString& Signature, const AnyType&, const Args& ...Arguments)
	{
		Signature += GetTypeSignature<AnyType>();
		GetTypeSignatures(Signature, Arguments...);
	}

	/**
	 * Get type signature for custom java argument
	 */
	template <typename AnyType, TEnableIfCustomJavaArgument<AnyType> = true, typename... Args>
	static void	GetTypeSignatures(FString& Signature, const AnyType& CustomJavaArgument, const Args& ...Arguments)
	{
		Signature += CustomJavaArgument.GetSignature();
		GetTypeSignatures(Signature, Arguments...);
	}

	/**
	 * Get method signature in Java VM's representation
	 */
	template <typename MethodType, typename... Args>
	static FString GetMethodSignature(const Args& ...Arguments)
	{
		FString MethodSignature;

		{
			MethodSignature = "(";
			GetTypeSignatures(MethodSignature, Arguments...);
			MethodSignature += ")";
		}

		MethodSignature += GetTypeSignature<MethodType>();

		return MoveTemp(MethodSignature);
	}
};
