// Georgy Treshchev 2022.

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
	int32 SDKVersion;

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
 * Android theme
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
	 * Check if the internet is available at the moment
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static bool IsInternetAvailable();

	/**
	 * Should have android.permission.ACCESS_FINE_LOCATION and android.permission.INTERNET permissions
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FString GetGeoLocation();

	/**
	 * Get base information about the device
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FBaseDeviceInfo GetBaseDeviceInfo();

	/**
	 * Get a folder to store files in device ("storage/emulated/0/Android/data/data/%APP_PACKAGE_NAME%/")
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static FString GetExternalPath();

	/**
	 * Get the system theme currently used in device
	 */
	UFUNCTION(BlueprintCallable, Category = "Android Native Library|Basic")
	static EAndroidTheme GetCurrentSystemTheme();
};
