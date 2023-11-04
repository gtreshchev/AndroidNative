// Georgy Treshchev 2023.

#pragma once

#include "CoreMinimal.h"

#include "JavaConvert.h"

#include "Helpers/StaticNativeCaller.h"
#include "Helpers/SignatureHelper.h"
#include "CustomJavaTypes.h"

#include "AndroidNativeDefines.h"

/**
 * Helper for converting argument types from CPP to Java
 */
namespace ArgumentsConverter
{
	template <typename AnyType, TEnableIfNotCustomJavaArgument<AnyType> = true>
	ANDROIDNATIVE_API AnyType FORCEINLINE ConvertArgument(const AnyType& Object) { return Object; }

	template <typename AnyType, TEnableIfCustomJavaArgument<AnyType> = true>
	ANDROIDNATIVE_API jobject FORCEINLINE ConvertArgument(const AnyType& CustomObject) { return CustomObject.GetValue(); }

	ANDROIDNATIVE_API jboolean FORCEINLINE ConvertArgument(const bool Bool) { return AndroidNative_JavaConverter::ToJavaBool(Bool); }
	ANDROIDNATIVE_API jbooleanArray FORCEINLINE ConvertArgument(const TArray<bool>& BoolArray) { return AndroidNative_JavaConverter::ToJavaBoolArray(BoolArray); }

	ANDROIDNATIVE_API jbyte FORCEINLINE ConvertArgument(const uint8 Byte) { return AndroidNative_JavaConverter::ToJavaByte(Byte); }
	ANDROIDNATIVE_API jbyteArray FORCEINLINE ConvertArgument(const TArray<uint8>& ByteArray) { return AndroidNative_JavaConverter::ToJavaByteArray(ByteArray); }

	ANDROIDNATIVE_API jchar FORCEINLINE ConvertArgument(const UTF16CHAR Char) { return AndroidNative_JavaConverter::ToJavaChar(Char); }
	ANDROIDNATIVE_API jcharArray FORCEINLINE ConvertArgument(const TArray<UTF16CHAR>& CharArray) { return AndroidNative_JavaConverter::ToJavaCharArray(CharArray); }

	ANDROIDNATIVE_API jshort FORCEINLINE ConvertArgument(const short Short) { return AndroidNative_JavaConverter::ToJavaShort(Short); }
	ANDROIDNATIVE_API jshortArray FORCEINLINE ConvertArgument(const TArray<short>& ShortArray) { return AndroidNative_JavaConverter::ToJavaShortArray(ShortArray); }

	ANDROIDNATIVE_API jint FORCEINLINE ConvertArgument(const int32 Int) { return AndroidNative_JavaConverter::ToJavaInt(Int); }
	ANDROIDNATIVE_API jintArray FORCEINLINE ConvertArgument(const TArray<int32>& IntArray) { return AndroidNative_JavaConverter::ToJavaIntArray(IntArray); }

	ANDROIDNATIVE_API jlong FORCEINLINE ConvertArgument(const long Long) { return AndroidNative_JavaConverter::ToJavaLong(Long); }
	ANDROIDNATIVE_API jlongArray FORCEINLINE ConvertArgument(const TArray<long>& LongArray) { return AndroidNative_JavaConverter::ToJavaLongArray(LongArray); }

	ANDROIDNATIVE_API jfloat FORCEINLINE ConvertArgument(const float Float) { return AndroidNative_JavaConverter::ToJavaFloat(Float); }
	ANDROIDNATIVE_API jfloatArray FORCEINLINE ConvertArgument(const TArray<float>& FloatArray) { return AndroidNative_JavaConverter::ToJavaFloatArray(FloatArray); }

	ANDROIDNATIVE_API jdouble FORCEINLINE ConvertArgument(const double Double) { return AndroidNative_JavaConverter::ToJavaDouble(Double); }
	ANDROIDNATIVE_API jdoubleArray FORCEINLINE ConvertArgument(const TArray<double>& DoubleArray) { return AndroidNative_JavaConverter::ToJavaDoubleArray(DoubleArray); }

	ANDROIDNATIVE_API jstring FORCEINLINE ConvertArgument(const FString& String) { return AndroidNative_JavaConverter::ToJavaString(String); }
	ANDROIDNATIVE_API jstring FORCEINLINE ConvertArgument(const TCHAR* String) { return AndroidNative_JavaConverter::ToJavaString(String); }
	ANDROIDNATIVE_API jobjectArray FORCEINLINE ConvertArgument(const TArray<FString>& StringArray) { return AndroidNative_JavaConverter::ToJavaStringArray(StringArray); }
}

class ANDROIDNATIVE_API AndroidNativeUtils
{
public:
	/**
	 * Main function for calling Java Static Methods
	 */
	template <typename ReturnType, typename... Args>
	static ReturnType CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, Args ... args)
	{
		const FString MethodSignature{SignatureHelper::GetMethodSignature<ReturnType>(args...)};
		return StaticNativeCaller::CallJavaStaticMethod<ReturnType>(ClassName, MethodName, TCHAR_TO_ANSI(*MethodSignature), ArgumentsConverter::ConvertArgument(args)...);
	}
};
