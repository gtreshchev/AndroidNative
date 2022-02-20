// Georgy Treshchev 2022.

#include "JavaConvert.h"
#include "AndroidNativeDefines.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif

bool AndroidNative_JavaConverter::FromJavaBool(const jboolean JavaBool)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jboolean' to 'bool'"));

#if PLATFORM_ANDROID
	return static_cast<bool>(JavaBool);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return bool{};
#endif
}

TArray<bool> AndroidNative_JavaConverter::FromJavaBoolArray(const jbooleanArray& JavaBoolArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jbooleanArray' to 'TArray<bool>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<bool> BoolArray;

		const jboolean* JavaBoolArrayPtr{Env->GetBooleanArrayElements(JavaBoolArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaBoolArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			BoolArray.Add(FromJavaBool(JavaBoolArrayPtr[Index]));
		}

		return MoveTemp(BoolArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<bool>{};
}

jboolean AndroidNative_JavaConverter::ToJavaBool(const bool Bool)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'bool' to 'jboolean'"));

#if PLATFORM_ANDROID
	return static_cast<jboolean>(Bool);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jboolean{};
#endif
}

jbooleanArray AndroidNative_JavaConverter::ToJavaBoolArray(const TArray<bool>& BoolArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<bool>' to 'jbooleanArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jbooleanArray JavaBoolArray = Env->NewBooleanArray(BoolArray.Num());
		jboolean* JavaBoolArrayPtr{Env->GetBooleanArrayElements(JavaBoolArray, nullptr)};

		for (TArray<bool>::SizeType Index = 0; Index < BoolArray.Num(); ++Index)
		{
			JavaBoolArrayPtr[Index] = ToJavaBool(BoolArray[Index]);
		}

		return MoveTemp(JavaBoolArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jbooleanArray{};
}


uint8 AndroidNative_JavaConverter::FromJavaByte(const jbyte JavaByte)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jbyte' to 'uint8'"));
#if PLATFORM_ANDROID
	return static_cast<uint8>(JavaByte);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return uint8{};
#endif
}

TArray<uint8> AndroidNative_JavaConverter::FromJavaByteArray(const jbyteArray JavaByteArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jbyteArray' to 'TArray<uint8>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<uint8> ByteArray;

		const jbyte* JavaByteArrayPtr{Env->GetByteArrayElements(JavaByteArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaByteArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			ByteArray.Add(FromJavaByte(JavaByteArrayPtr[Index]));
		}

		return MoveTemp(ByteArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<uint8>{};
}

jbyte AndroidNative_JavaConverter::ToJavaByte(const uint8 Byte)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'uint8' to 'jbyte'"));

#if PLATFORM_ANDROID
	return static_cast<jbyte>(Byte);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jbyte{};
#endif
}

jbyteArray AndroidNative_JavaConverter::ToJavaByteArray(const TArray<uint8>& ByteArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<uint8>' to 'jbyteArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jbyteArray JavaByteArray = Env->NewByteArray(ByteArray.Num());
		jbyte* JavaByteArrayPtr{Env->GetByteArrayElements(JavaByteArray, nullptr)};

		for (TArray<uint8>::SizeType Index = 0; Index < ByteArray.Num(); ++Index)
		{
			JavaByteArrayPtr[Index] = ToJavaByte(ByteArray[Index]);
		}

		return MoveTemp(JavaByteArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jbyteArray{};
}

UTF16CHAR AndroidNative_JavaConverter::FromJavaChar(const jchar JavaChar)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jchar' to 'UTF16CHAR'"));

#if PLATFORM_ANDROID
	return static_cast<UTF16CHAR>(JavaChar);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return UTF16CHAR{};
#endif
}

TArray<UTF16CHAR> AndroidNative_JavaConverter::FromJavaCharArray(const jcharArray& JavaCharArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jcharArray' to 'TArray<UTF16CHAR>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<UTF16CHAR> CharArray;

		const jchar* JavaCharArrayPtr{Env->GetCharArrayElements(JavaCharArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaCharArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			CharArray.Add(FromJavaChar(JavaCharArrayPtr[Index]));
		}

		return MoveTemp(CharArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<UTF16CHAR>{};
}

jchar AndroidNative_JavaConverter::ToJavaChar(const UTF16CHAR Char)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'UTF16CHAR' to 'jchar'"));

#if PLATFORM_ANDROID
	return static_cast<jchar>(Char);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jchar{};
#endif
}

jcharArray AndroidNative_JavaConverter::ToJavaCharArray(const TArray<UTF16CHAR>& CharArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<UTF16CHAR>' to 'jcharArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jcharArray JavaCharArray{Env->NewCharArray(CharArray.Num())};
		jchar* JavaCharArrayPtr{Env->GetCharArrayElements(JavaCharArray, nullptr)};

		for (TArray<UTF16CHAR>::SizeType Index = 0; Index < CharArray.Num(); ++Index)
		{
			JavaCharArrayPtr[Index] = ToJavaChar(CharArray[Index]);
		}

		return MoveTemp(JavaCharArray);
	}

#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif
	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));

	return jcharArray{};
}

short AndroidNative_JavaConverter::FromJavaShort(const jshort JavaShort)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jshort' to 'short'"));

#if PLATFORM_ANDROID
	return static_cast<short>(JavaShort);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return short{};
#endif
}

TArray<short> AndroidNative_JavaConverter::FromJavaShortArray(const jshortArray& JavaShortArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jshortArray' to 'TArray<short>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<short> ShortArray;

		const jshort* JavaShortArrayPtr{Env->GetShortArrayElements(JavaShortArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaShortArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			ShortArray.Add(FromJavaShort(JavaShortArrayPtr[Index]));
		}

		return MoveTemp(ShortArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<short>{};
}

jshort AndroidNative_JavaConverter::ToJavaShort(const short Short)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'short' to 'jshort'"));

#if PLATFORM_ANDROID
	return static_cast<jshort>(Short);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jshort{};
#endif
}

jshortArray AndroidNative_JavaConverter::ToJavaShortArray(const TArray<short>& ShortArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<short>' to 'jshortArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jshortArray JavaShortArray{Env->NewShortArray(ShortArray.Num())};
		jshort* JavaShortArrayPtr{Env->GetShortArrayElements(JavaShortArray, nullptr)};

		for (TArray<short>::SizeType Index = 0; Index < ShortArray.Num(); ++Index)
		{
			JavaShortArrayPtr[Index] = ToJavaShort(ShortArray[Index]);
		}

		return MoveTemp(JavaShortArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jshortArray{};
}

int32 AndroidNative_JavaConverter::FromJavaInt(const jint JavaInt)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jint' to 'int32'"));

#if PLATFORM_ANDROID
	return static_cast<int32>(JavaInt);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return int32{};
#endif
}

TArray<int32> AndroidNative_JavaConverter::FromJavaIntArray(const jintArray& JavaIntArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jintArray' to 'TArray<int32>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<int32> IntArray;

		const jint* JavaIntArrayPtr{Env->GetIntArrayElements(JavaIntArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaIntArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			IntArray.Add(FromJavaInt(JavaIntArrayPtr[Index]));
		}

		return MoveTemp(IntArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<int32>{};
}

jint AndroidNative_JavaConverter::ToJavaInt(const int32 Int)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'int32' to 'jint'"));

#if PLATFORM_ANDROID
	return static_cast<jint>(Int);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jint{};
#endif
}

jintArray AndroidNative_JavaConverter::ToJavaIntArray(const TArray<int32>& IntArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<int32>' to 'jintArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jintArray JavaIntArray{Env->NewIntArray(IntArray.Num())};
		jint* JavaIntArrayPtr{Env->GetIntArrayElements(JavaIntArray, nullptr)};

		for (TArray<int32>::SizeType Index = 0; Index < IntArray.Num(); ++Index)
		{
			JavaIntArrayPtr[Index] = ToJavaInt(IntArray[Index]);
		}

		return MoveTemp(JavaIntArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jintArray{};
}

long AndroidNative_JavaConverter::FromJavaLong(const jlong JavaLong)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jlong' to 'long'"));

#if PLATFORM_ANDROID
	return static_cast<long>(JavaLong);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return long{};
#endif
}

TArray<long> AndroidNative_JavaConverter::FromJavaLongArray(const jlongArray& JavaLongArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jlongArray' to 'TArray<long>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<long> LongArray;

		const jlong* JavaLongArrayPtr{Env->GetLongArrayElements(JavaLongArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaLongArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			LongArray.Add(FromJavaLong(JavaLongArrayPtr[Index]));
		}

		return MoveTemp(LongArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<long>{};
}

jlong AndroidNative_JavaConverter::ToJavaLong(const long Long)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'long' to 'jlong'"));

#if PLATFORM_ANDROID
	return static_cast<jlong>(Long);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jlong{};
#endif
}

jlongArray AndroidNative_JavaConverter::ToJavaLongArray(const TArray<long>& LongArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<long>' to 'jlongArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jlongArray JavaLongArray{Env->NewLongArray(LongArray.Num())};
		jlong* JavaLongArrayPtr{Env->GetLongArrayElements(JavaLongArray, nullptr)};

		for (TArray<long>::SizeType Index = 0; Index < LongArray.Num(); ++Index)
		{
			JavaLongArrayPtr[Index] = ToJavaLong(LongArray[Index]);
		}

		return MoveTemp(JavaLongArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jlongArray{};
}

float AndroidNative_JavaConverter::FromJavaFloat(const jfloat JavaFloat)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jfloat' to 'float'"));

#if PLATFORM_ANDROID
	return static_cast<float>(JavaFloat);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return float{};
#endif
}

TArray<float> AndroidNative_JavaConverter::FromJavaFloatArray(const jfloatArray& JavaFloatArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jfloatArray' to 'TArray<float>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<float> FloatArray;

		const jfloat* JavaFloatArrayPtr{Env->GetFloatArrayElements(JavaFloatArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaFloatArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			FloatArray.Add(FromJavaFloat(JavaFloatArrayPtr[Index]));
		}

		return MoveTemp(FloatArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<float>{};
}

jfloat AndroidNative_JavaConverter::ToJavaFloat(const float Float)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'float' to 'jfloat'"));

#if PLATFORM_ANDROID
	return static_cast<jfloat>(Float);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jfloat{};
#endif
}

jfloatArray AndroidNative_JavaConverter::ToJavaFloatArray(const TArray<float>& FloatArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<float>' to 'jfloatArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jfloatArray JavaFloatArray{Env->NewFloatArray(FloatArray.Num())};
		jfloat* JavaFloatArrayPtr{Env->GetFloatArrayElements(JavaFloatArray, nullptr)};

		for (TArray<float>::SizeType Index = 0; Index < FloatArray.Num(); ++Index)
		{
			JavaFloatArrayPtr[Index] = ToJavaFloat(FloatArray[Index]);
		}

		return MoveTemp(JavaFloatArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jfloatArray{};
}

double AndroidNative_JavaConverter::FromJavaDouble(const jdouble JavaDouble)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jdouble' to 'double'"));

#if PLATFORM_ANDROID
	return static_cast<double>(JavaDouble);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return double{};
#endif
}

TArray<double> AndroidNative_JavaConverter::FromJavaDoubleArray(const jdoubleArray& JavaDoubleArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jdoubleArray' to 'TArray<double>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<double> DoubleArray;

		const jdouble* JavaDoubleArrayPtr{Env->GetDoubleArrayElements(JavaDoubleArray, nullptr)};
		const jsize ArrayLength{Env->GetArrayLength(JavaDoubleArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			DoubleArray.Add(FromJavaDouble(JavaDoubleArrayPtr[Index]));
		}

		return MoveTemp(DoubleArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<double>{};
}

jdouble AndroidNative_JavaConverter::ToJavaDouble(const double Double)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'double' to 'jdouble'"));

#if PLATFORM_ANDROID
	return static_cast<jdouble>(Double);
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
	return jdouble{};
#endif
}

jdoubleArray AndroidNative_JavaConverter::ToJavaDoubleArray(const TArray<double>& DoubleArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<double>' to 'jdoubleArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jdoubleArray JavaDoubleArray{Env->NewDoubleArray(DoubleArray.Num())};
		jdouble* JavaDoubleArrayPtr{Env->GetDoubleArrayElements(JavaDoubleArray, nullptr)};

		for (TArray<double>::SizeType Index = 0; Index < DoubleArray.Num(); ++Index)
		{
			JavaDoubleArrayPtr[Index] = ToJavaDouble(DoubleArray[Index]);
		}

		return MoveTemp(JavaDoubleArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jdoubleArray{};
}

FString AndroidNative_JavaConverter::FromJavaString(const jstring& JavaString)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jstring' to 'FString'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		const char* Characters{Env->GetStringUTFChars(JavaString, 0)};

		FString ReturnString(UTF8_TO_TCHAR(Characters));

		Env->ReleaseStringUTFChars(JavaString, Characters);

		return MoveTemp(ReturnString);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return FString{};
}

TArray<FString> AndroidNative_JavaConverter::FromJavaStringArray(const jobjectArray& JavaStringArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'jobjectArray' to 'TArray<FString>'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		TArray<FString> StringArray;

		const jsize ArrayLength{Env->GetArrayLength(JavaStringArray)};

		for (jsize Index = 0; Index < ArrayLength; ++Index)
		{
			const jstring& JavaString{static_cast<jstring>(Env->GetObjectArrayElement(JavaStringArray, Index))};

			StringArray.Add(FromJavaString(JavaString));
		}

		return MoveTemp(StringArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return TArray<FString>{};
}

jstring AndroidNative_JavaConverter::ToJavaString(const FString& String)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'FString' to 'jstring'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		const jstring& LocalJavaString{Env->NewStringUTF(TCHAR_TO_UTF8(*String))};
		const jstring& GlobalJavaString{static_cast<jstring>(Env->NewGlobalRef(LocalJavaString))};

		Env->DeleteLocalRef(LocalJavaString);

		return GlobalJavaString;
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));
#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jstring{};
}

jobjectArray AndroidNative_JavaConverter::ToJavaStringArray(const TArray<FString>& StringArray)
{
	UE_LOG(LogAndroidNative, Log, TEXT("Converting 'TArray<FString>' to 'jobjectArray'"));

#if PLATFORM_ANDROID
	if (JNIEnv* Env{FAndroidApplication::GetJavaEnv()})
	{
		jobjectArray JavaStringArray{Env->NewObjectArray(StringArray.Num(), FJavaWrapper::JavaStringClass, nullptr)};

		for (TArray<FString>::SizeType Index = 0; Index < StringArray.Num(); ++Index)
		{
			Env->SetObjectArrayElement(JavaStringArray, Index, ToJavaString(StringArray[Index]));
		}

		return MoveTemp(JavaStringArray);
	}

	UE_LOG(LogAndroidNative, Error, TEXT("Can't get Java Environment! Check if JavaVM is valid"));

#else
	UE_LOG(LogAndroidNative, Error, TEXT("The platform you are running on does not support Java types"));
#endif

	return jobjectArray{};
}
