#pragma once

#include "AndroidNativeDefines.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif

#include "JavaConvert.h"

namespace StaticNativeCaller
{
	/**
     * Call java static method with no return type
     */
	template <typename PassedReturnType>
	TEnableIfSame<void, PassedReturnType, void>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Void static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			Env->CallStaticVoidMethodV(Class, Method, Args);
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return;
		}
		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif
	}

	/**
	 * Call java static method with Bool return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<bool, PassedReturnType, bool>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Boolean static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			bool Result{AndroidNative_JavaConverter::FromJavaBool(Env->CallStaticBooleanMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return bool{};
	}

	/**
	 * Call java static method with TArray<bool> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<bool>, PassedReturnType, TArray<bool>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Boolean Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<bool> Result{AndroidNative_JavaConverter::FromJavaBoolArray(static_cast<jbooleanArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<bool>{};
	}

	/**
	 * Call java static method with Uint8 return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<uint8, PassedReturnType, uint8>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Byte static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			uint8 Result{AndroidNative_JavaConverter::FromJavaByte(Env->CallStaticByteMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return uint8{};
	}

	/**
	 * Call java static method with TArray<uint8> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<uint8>, PassedReturnType, TArray<uint8>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Byte Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<uint8> Result{AndroidNative_JavaConverter::FromJavaByteArray(static_cast<jbyteArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<uint8>{};
	}

	/**
	 * Call java static method with UTF16CHAR return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<UTF16CHAR, PassedReturnType, UTF16CHAR>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Char static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			UTF16CHAR Result{AndroidNative_JavaConverter::FromJavaChar(Env->CallStaticCharMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return UTF16CHAR{};
	}

	/**
	 * Call java static method with TArray<UTF16CHAR> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<UTF16CHAR>, PassedReturnType, TArray<UTF16CHAR>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Char Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<UTF16CHAR> Result{AndroidNative_JavaConverter::FromJavaCharArray(static_cast<jcharArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<UTF16CHAR>{};
	}

	/**
	 * Call java static method with short return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<short, PassedReturnType, short>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Short static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			short Result{AndroidNative_JavaConverter::FromJavaShort(Env->CallStaticShortMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return short{};
	}

	/**
	 * Call java static method with TArray<short> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<short>, PassedReturnType, TArray<short>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Short Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<short> Result{AndroidNative_JavaConverter::FromJavaShortArray(static_cast<jshortArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<short>{};
	}

	/**
	 * Call java static method with Int32 return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<int32, PassedReturnType, int32>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Int static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			int32 Result{AndroidNative_JavaConverter::FromJavaInt(Env->CallStaticIntMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return int32{};
	}

	/**
	 * Call java static method with TArray<int32> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<int32>, PassedReturnType, TArray<int32>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Int Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<int32> Result{AndroidNative_JavaConverter::FromJavaIntArray(static_cast<jintArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<int32>{};
	}

	/**
	 * Call java static method with Long return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<long, PassedReturnType, long>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Long static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			long Result{AndroidNative_JavaConverter::FromJavaLong(Env->CallStaticLongMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return long{};
	}

	/**
	 * Call java static method with TArray<long> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<long>, PassedReturnType, TArray<long>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Long Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<long> Result{AndroidNative_JavaConverter::FromJavaLongArray(static_cast<jlongArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<long>{};
	}

	/**
	 * Call java static method with Float return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<float, PassedReturnType, float>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Float static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			float Result{AndroidNative_JavaConverter::FromJavaFloat(Env->CallStaticFloatMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return float{};
	}

	/**
	 * Call java static method with TArray<float> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<float>, PassedReturnType, TArray<float>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Float Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<float> Result{AndroidNative_JavaConverter::FromJavaFloatArray(static_cast<jfloatArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<float>{};
	}

	/**
	 * Call java static method with Double return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<double, PassedReturnType, double>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Double static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			double Result{AndroidNative_JavaConverter::FromJavaDouble(Env->CallStaticDoubleMethodV(Class, Method, Args))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return Result;
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return double{};
	}

	/**
	 * Call java static method with TArray<double> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<double>, PassedReturnType, TArray<double>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java Double Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<double> Result{AndroidNative_JavaConverter::FromJavaDoubleArray(static_cast<jdoubleArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<double>{};
	}

	/**
	 * Call java static method with FString return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<FString, PassedReturnType, FString>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java String static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			FString Result{AndroidNative_JavaConverter::FromJavaString(static_cast<jstring>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return FString{};
	}

	/**
	 * Call java static method with TArray<FString> return type
	 */
	template <typename PassedReturnType>
	TEnableIfSame<TArray<FString>, PassedReturnType, TArray<FString>>
	static CallJavaStaticMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...)
	{
		UE_LOG(LogAndroidNative, Log, TEXT("Calling java String Array static method. ClassName: '%s', MethodName: '%s', MethodSignature: '%s'"), *FString(ClassName), *FString(MethodName), *FString(MethodSignature));

#if PLATFORM_ANDROID
		if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
		{
			const jclass& Class{FAndroidApplication::FindJavaClass(ClassName)};
			const jmethodID& Method{FJavaWrapper::FindStaticMethod(Env, Class, MethodName, MethodSignature, false)};

			va_list Args;
			va_start(Args, MethodSignature);
			TArray<FString> Result{AndroidNative_JavaConverter::FromJavaStringArray(static_cast<jobjectArray>(Env->CallStaticObjectMethodV(Class, Method, Args)))};
			va_end(Args);

			Env->DeleteLocalRef(Class);

			return MoveTemp(Result);
		}

		UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
		UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support calling Java methods"));
#endif

		return TArray<FString>{};
	}
};
