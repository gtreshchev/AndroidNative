// Georgy Treshchev 2023.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"

#include "AndroidNativeLibrary.generated.h"

/**
 * Basic information about the device
 */
USTRUCT(BlueprintType, Category = "Android Native Library|Stuctures")
struct FBaseDeviceInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString UniqueID;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString OSVersion;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	int32 SDKVersion = -1;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString Brand;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString Model;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString Product;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString Language;

	UPROPERTY(BlueprintReadWrite, Category = "Android Native Library|Stuctures")
	FString LanguageCode;
};

/**
 * Android themes
 */
UENUM(BlueprintType, Category = "Android Native Library|Enumerators")
enum class EAndroidTheme : uint8
{
	Undefined,
	Light,
	Dark
};

/**
 * Library for interacting with android device
 */
UCLASS(BlueprintType, Category = "Android Native Library")
class ANDROIDNATIVE_API UAndroidNativeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	/**
	 * Start NSD Service on defined port with "NdiNsdService" name and "_ndi._tcp." type.
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Services|NSD")
	static void EnableNsdService(int32 InPort);
	
	/**
	 * Check if the internet is available at the moment
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static bool IsInternetAvailable();

	/**
	 * Retrieve the device's location, requires "android.permission.ACCESS_FINE_LOCATION" and "android.permission.INTERNET" permissions
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FString GetGeoLocation();

	/**
	 * Obtain basic information about the device
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FBaseDeviceInfo GetBaseDeviceInfo();

	/**
	 * Get the folder path for storing temporary files on the device ("storage/emulated/0/Android/data/data/%APP_PACKAGE_NAME%/")
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FString GetExternalPath();

	/**
	 * Retrieve the current system theme used in the device
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static EAndroidTheme GetCurrentSystemTheme();
};