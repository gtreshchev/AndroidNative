// Georgy Treshchev 2023.

#pragma once

#include "CoreMinimal.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#else
typedef uint8_t  jboolean;
typedef int8_t   jbyte;
typedef uint16_t jchar;
typedef int16_t  jshort;
typedef int32_t  jint;
typedef int64_t  jlong;
typedef float    jfloat;
typedef double   jdouble;

class _jobject {};
class _jclass : public _jobject {};
class _jstring : public _jobject {};
class _jarray : public _jobject {};
class _jobjectArray : public _jarray {};
class _jbooleanArray : public _jarray {};
class _jbyteArray : public _jarray {};
class _jcharArray : public _jarray {};
class _jshortArray : public _jarray {};
class _jintArray : public _jarray {};
class _jlongArray : public _jarray {};
class _jfloatArray : public _jarray {};
class _jdoubleArray : public _jarray {};
class _jthrowable : public _jobject {};

typedef _jobject*       jobject;
typedef _jclass*        jclass;
typedef _jstring*       jstring;
typedef _jarray*        jarray;
typedef _jobjectArray*  jobjectArray;
typedef _jbooleanArray* jbooleanArray;
typedef _jbyteArray*    jbyteArray;
typedef _jcharArray*    jcharArray;
typedef _jshortArray*   jshortArray;
typedef _jintArray*     jintArray;
typedef _jlongArray*    jlongArray;
typedef _jfloatArray*   jfloatArray;
typedef _jdoubleArray*  jdoubleArray;
typedef _jthrowable*    jthrowable;
typedef _jobject*       jweak;

namespace FJavaWrapper
{
	ANDROIDNATIVE_API jobject GameActivityThis;
}
#endif

/**
 * Java Converter. Converts C++ to Java types and vice versa
 */
namespace AndroidNative_JavaConverter
{
	/** Convert jboolean to bool */
	ANDROIDNATIVE_API bool FromJavaBool(const jboolean JavaBool);

	/** Convert jbooleanArray to TArray<bool> */
	ANDROIDNATIVE_API TArray<bool> FromJavaBoolArray(const jbooleanArray& JavaBoolArray);

	/** Convert bool to jboolean */
	ANDROIDNATIVE_API jboolean ToJavaBool(const bool Bool);

	/** Convert TArray<bool> to jbooleanArray */
	ANDROIDNATIVE_API jbooleanArray ToJavaBoolArray(const TArray<bool>& BoolArray);


	/** Convert jbyte to uint8 */
	ANDROIDNATIVE_API uint8 FromJavaByte(const jbyte JavaByte);

	/** Convert jbyteArray to TArray<uint8> */
	ANDROIDNATIVE_API TArray<uint8> FromJavaByteArray(const jbyteArray JavaByteArray);

	/** Convert uint8 to jbyte */
	ANDROIDNATIVE_API jbyte ToJavaByte(const uint8 Byte);

	/** Convert TArray<uint8> to jbyteArray */
	ANDROIDNATIVE_API jbyteArray ToJavaByteArray(const TArray<uint8>& ByteArray);


	/** Convert jchar to UTF16CHAR */
	ANDROIDNATIVE_API UTF16CHAR FromJavaChar(const jchar JavaChar);

	/** Convert jcharArray to TArray<UTF16CHAR> */
	ANDROIDNATIVE_API TArray<UTF16CHAR> FromJavaCharArray(const jcharArray& JavaCharArray);

	/** Convert UTF16CHAR to jchar */
	ANDROIDNATIVE_API jchar ToJavaChar(const UTF16CHAR Char);

	/** Convert TArray<UTF16CHAR> to jcharArray */
	ANDROIDNATIVE_API jcharArray ToJavaCharArray(const TArray<UTF16CHAR>& CharArray);


	/** Convert jshort to short */
	ANDROIDNATIVE_API short FromJavaShort(const jshort JavaShort);

	/** Convert jshortArray to TArray<short> */
	ANDROIDNATIVE_API TArray<short> FromJavaShortArray(const jshortArray& JavaShortArray);

	/** Convert short to jshort */
	ANDROIDNATIVE_API jshort ToJavaShort(const short Short);

	/** Convert TArray<short> to jshortArray */
	ANDROIDNATIVE_API jshortArray ToJavaShortArray(const TArray<short>& ShortArray);


	/** Convert jint to int32 */
	ANDROIDNATIVE_API int32 FromJavaInt(const jint JavaInt);

	/** Convert jintArray to TArray<int32> */
	ANDROIDNATIVE_API TArray<int32> FromJavaIntArray(const jintArray& JavaIntArray);

	/** Convert int32 to jint */
	ANDROIDNATIVE_API jint ToJavaInt(const int32 Int);

	/** Convert TArray<int32> to jintArray */
	ANDROIDNATIVE_API jintArray ToJavaIntArray(const TArray<int32>& IntArray);


	/** Convert jlong to long */
	ANDROIDNATIVE_API long FromJavaLong(const jlong JavaLong);

	/** Convert jlongArray to TArray<long> */
	ANDROIDNATIVE_API TArray<long> FromJavaLongArray(const jlongArray& JavaLongArray);

	/** Convert long to jlong */
	ANDROIDNATIVE_API jlong ToJavaLong(const long Long);

	/** Convert TArray<long> to jlongArray */
	ANDROIDNATIVE_API jlongArray ToJavaLongArray(const TArray<long>& LongArray);


	/** Convert jfloat to float */
	ANDROIDNATIVE_API float FromJavaFloat(const jfloat JavaFloat);

	/** Convert jfloatArray to TArray<float> */
	ANDROIDNATIVE_API TArray<float> FromJavaFloatArray(const jfloatArray& JavaFloatArray);

	/** Convert float to jfloat */
	ANDROIDNATIVE_API jfloat ToJavaFloat(const float Float);

	/** Convert TArray<float> to jfloatArray */
	ANDROIDNATIVE_API jfloatArray ToJavaFloatArray(const TArray<float>& FloatArray);
	

	/** Convert jdouble to double */
	ANDROIDNATIVE_API double FromJavaDouble(const jdouble JavaDouble);

	/** Convert jdoubleArray to TArray<double> */
	ANDROIDNATIVE_API TArray<double> FromJavaDoubleArray(const jdoubleArray& JavaDoubleArray);

	/** Convert double to jdouble */
	ANDROIDNATIVE_API jdouble ToJavaDouble(const double Double);

	/** Convert TArray<double> to jdoubleArray */
	ANDROIDNATIVE_API jdoubleArray ToJavaDoubleArray(const TArray<double>& DoubleArray);


	/** Convert jstring to FString */
	ANDROIDNATIVE_API FString FromJavaString(const jstring& JavaString);

	/** Convert jobjectArray to TArray<FString> */
	ANDROIDNATIVE_API TArray<FString> FromJavaStringArray(const jobjectArray& JavaStringArray);

	/** Convert FString to jstring */
	ANDROIDNATIVE_API jstring ToJavaString(const FString& String);

	/** Convert TCHAR* to jstring */
	ANDROIDNATIVE_API jstring FORCEINLINE ToJavaString(const TCHAR* String)
	{
		return ToJavaString(FString(String));
	}

	/** Convert TArray<FString> to jobjectArray */
	ANDROIDNATIVE_API jobjectArray ToJavaStringArray(const TArray<FString>& StringArray);
}
