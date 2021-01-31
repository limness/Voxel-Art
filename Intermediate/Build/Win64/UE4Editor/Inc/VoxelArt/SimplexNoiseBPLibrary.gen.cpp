// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Private/Noise/SimplexNoiseBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimplexNoiseBPLibrary() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_USimplexNoiseBPLibrary_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_USimplexNoiseBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D();
	VOXELART_API UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D();
// End Cross Module References
	void USimplexNoiseBPLibrary::StaticRegisterNativesUSimplexNoiseBPLibrary()
	{
		UClass* Class = USimplexNoiseBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "setNoiseSeed", &USimplexNoiseBPLibrary::execsetNoiseSeed },
			{ "SimplexNoise1D", &USimplexNoiseBPLibrary::execSimplexNoise1D },
			{ "SimplexNoise2D", &USimplexNoiseBPLibrary::execSimplexNoise2D },
			{ "SimplexNoise3D", &USimplexNoiseBPLibrary::execSimplexNoise3D },
			{ "SimplexNoise4D", &USimplexNoiseBPLibrary::execSimplexNoise4D },
			{ "SimplexNoiseInRange1D", &USimplexNoiseBPLibrary::execSimplexNoiseInRange1D },
			{ "SimplexNoiseInRange2D", &USimplexNoiseBPLibrary::execSimplexNoiseInRange2D },
			{ "SimplexNoiseInRange3D", &USimplexNoiseBPLibrary::execSimplexNoiseInRange3D },
			{ "SimplexNoiseInRange4D", &USimplexNoiseBPLibrary::execSimplexNoiseInRange4D },
			{ "SimplexNoiseScaled1D", &USimplexNoiseBPLibrary::execSimplexNoiseScaled1D },
			{ "SimplexNoiseScaled2D", &USimplexNoiseBPLibrary::execSimplexNoiseScaled2D },
			{ "SimplexNoiseScaled3D", &USimplexNoiseBPLibrary::execSimplexNoiseScaled3D },
			{ "SimplexNoiseScaled4D", &USimplexNoiseBPLibrary::execSimplexNoiseScaled4D },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics
	{
		struct SimplexNoiseBPLibrary_eventsetNoiseSeed_Parms
		{
			int32 newSeed;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_newSeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_newSeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::NewProp_newSeed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::NewProp_newSeed = { UE4CodeGen_Private::EPropertyClass::Int, "newSeed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventsetNoiseSeed_Parms, newSeed), METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::NewProp_newSeed_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::NewProp_newSeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::NewProp_newSeed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "setNoiseSeed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(SimplexNoiseBPLibrary_eventsetNoiseSeed_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoise1D_Parms
		{
			float x;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise1D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise1D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoise1D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoise1D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoise2D_Parms
		{
			float x;
			float y;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise2D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise2D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise2D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoise2D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoise2D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms
		{
			float x;
			float y;
			float z;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoise3D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoise3D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_w;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_w = { UE4CodeGen_Private::EPropertyClass::Float, "w", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms, w), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_w,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoise4D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoise4D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms
		{
			float x;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMax;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMin;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_rangeMax = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMax", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms, rangeMax), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_rangeMin = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMin", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms, rangeMin), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_rangeMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_rangeMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
		{ "ToolTip", "Return value in Range between two float numbers\nReturn Value is scaled by difference between rangeMin & rangeMax value" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseInRange1D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseInRange1D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms
		{
			float x;
			float y;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMax;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMin;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_rangeMax = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMax", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms, rangeMax), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_rangeMin = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMin", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms, rangeMin), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_rangeMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_rangeMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseInRange2D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseInRange2D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms
		{
			float x;
			float y;
			float z;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMax;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMin;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_rangeMax = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMax", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, rangeMax), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_rangeMin = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMin", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, rangeMin), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_rangeMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_rangeMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseInRange3D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseInRange3D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMax;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeMin;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_w;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_rangeMax = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMax", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, rangeMax), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_rangeMin = { UE4CodeGen_Private::EPropertyClass::Float, "rangeMin", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, rangeMin), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_w = { UE4CodeGen_Private::EPropertyClass::Float, "w", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, w), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_rangeMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_rangeMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_w,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseInRange4D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseInRange4D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseScaled1D_Parms
		{
			float x;
			float s;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_s;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled1D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_s = { UE4CodeGen_Private::EPropertyClass::Float, "s", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled1D_Parms, s), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled1D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_s,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
		{ "ToolTip", "Scaled by float value" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseScaled1D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseScaled1D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms
		{
			float x;
			float y;
			float s;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_s;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_s = { UE4CodeGen_Private::EPropertyClass::Float, "s", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms, s), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_s,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseScaled2D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseScaled2D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms
		{
			float x;
			float y;
			float z;
			float s;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_s;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_s = { UE4CodeGen_Private::EPropertyClass::Float, "s", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms, s), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_s,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseScaled3D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseScaled3D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics
	{
		struct SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float s;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_s;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_w;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_s = { UE4CodeGen_Private::EPropertyClass::Float, "s", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, s), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_w = { UE4CodeGen_Private::EPropertyClass::Float, "w", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, w), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Float, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Float, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Float, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_s,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_w,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::NewProp_x,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SimplexNoise" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimplexNoiseBPLibrary, "SimplexNoiseScaled4D", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SimplexNoiseBPLibrary_eventSimplexNoiseScaled4D_Parms), Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USimplexNoiseBPLibrary_NoRegister()
	{
		return USimplexNoiseBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USimplexNoiseBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_setNoiseSeed, "setNoiseSeed" }, // 2155961628
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise1D, "SimplexNoise1D" }, // 200560923
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise2D, "SimplexNoise2D" }, // 3371335413
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise3D, "SimplexNoise3D" }, // 2185070079
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoise4D, "SimplexNoise4D" }, // 2144225624
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange1D, "SimplexNoiseInRange1D" }, // 691807997
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange2D, "SimplexNoiseInRange2D" }, // 85658267
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange3D, "SimplexNoiseInRange3D" }, // 2222509410
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseInRange4D, "SimplexNoiseInRange4D" }, // 4090234107
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled1D, "SimplexNoiseScaled1D" }, // 3299911515
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled2D, "SimplexNoiseScaled2D" }, // 2217959519
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled3D, "SimplexNoiseScaled3D" }, // 1384193956
		{ &Z_Construct_UFunction_USimplexNoiseBPLibrary_SimplexNoiseScaled4D, "SimplexNoiseScaled4D" }, // 3700601050
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Noise/SimplexNoiseBPLibrary.h" },
		{ "ModuleRelativePath", "Private/Noise/SimplexNoiseBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimplexNoiseBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::ClassParams = {
		&USimplexNoiseBPLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USimplexNoiseBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USimplexNoiseBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USimplexNoiseBPLibrary, 610799167);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USimplexNoiseBPLibrary(Z_Construct_UClass_USimplexNoiseBPLibrary, &USimplexNoiseBPLibrary::StaticClass, TEXT("/Script/VoxelArt"), TEXT("USimplexNoiseBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USimplexNoiseBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
