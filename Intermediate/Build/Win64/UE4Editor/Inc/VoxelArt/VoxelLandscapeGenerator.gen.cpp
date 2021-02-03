// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/Renders/VoxelLandscapeGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelLandscapeGenerator() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelLandscapeGenerator();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
// End Cross Module References
	static FName NAME_UVoxelLandscapeGenerator_SetColorMap = FName(TEXT("SetColorMap"));
	void UVoxelLandscapeGenerator::SetColorMap(float const& X, float const& Y, float const& Z, FColor& color)
	{
		VoxelLandscapeGenerator_eventSetColorMap_Parms Parms;
		Parms.X=X;
		Parms.Y=Y;
		Parms.Z=Z;
		Parms.color=color;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelLandscapeGenerator_SetColorMap),&Parms);
		color=Parms.color;
	}
	static FName NAME_UVoxelLandscapeGenerator_SetDensityMap = FName(TEXT("SetDensityMap"));
	void UVoxelLandscapeGenerator::SetDensityMap(float const& X, float const& Y, float const& Z, float& noise)
	{
		VoxelLandscapeGenerator_eventSetDensityMap_Parms Parms;
		Parms.X=X;
		Parms.Y=Y;
		Parms.Z=Z;
		Parms.noise=noise;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelLandscapeGenerator_SetDensityMap),&Parms);
		noise=Parms.noise;
	}
	void UVoxelLandscapeGenerator::StaticRegisterNativesUVoxelLandscapeGenerator()
	{
		UClass* Class = UVoxelLandscapeGenerator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Cone", &UVoxelLandscapeGenerator::execCone },
			{ "FlatLandscape", &UVoxelLandscapeGenerator::execFlatLandscape },
			{ "FractalNoise", &UVoxelLandscapeGenerator::execFractalNoise },
			{ "IQNoise", &UVoxelLandscapeGenerator::execIQNoise },
			{ "SetColorMap", &UVoxelLandscapeGenerator::execSetColorMap },
			{ "SetDensityMap", &UVoxelLandscapeGenerator::execSetDensityMap },
			{ "SimplexNoise", &UVoxelLandscapeGenerator::execSimplexNoise },
			{ "SphereLandscape", &UVoxelLandscapeGenerator::execSphereLandscape },
			{ "TorusLandscape", &UVoxelLandscapeGenerator::execTorusLandscape },
			{ "VectorDistanceAB", &UVoxelLandscapeGenerator::execVectorDistanceAB },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics
	{
		struct VoxelLandscapeGenerator_eventCone_Parms
		{
			FVector p;
			FVector2D c;
			float h;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_h;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_c;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_p;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventCone_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_h = { UE4CodeGen_Private::EPropertyClass::Float, "h", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventCone_Parms, h), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_c = { UE4CodeGen_Private::EPropertyClass::Struct, "c", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventCone_Parms, c), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_p = { UE4CodeGen_Private::EPropertyClass::Struct, "p", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventCone_Parms, p), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_h,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_c,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::NewProp_p,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "Cone", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04840401, sizeof(VoxelLandscapeGenerator_eventCone_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics
	{
		struct VoxelLandscapeGenerator_eventFlatLandscape_Parms
		{
			float A;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_A;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFlatLandscape_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::NewProp_A = { UE4CodeGen_Private::EPropertyClass::Float, "A", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFlatLandscape_Parms, A), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::NewProp_A,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "FlatLandscape", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VoxelLandscapeGenerator_eventFlatLandscape_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics
	{
		struct VoxelLandscapeGenerator_eventFractalNoise_Parms
		{
			float X;
			float Y;
			float Z;
			int32 seed;
			int32 octaves;
			float amplitude;
			float frequency;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_frequency;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_amplitude;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_octaves;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_seed;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_frequency = { UE4CodeGen_Private::EPropertyClass::Float, "frequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, frequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_amplitude = { UE4CodeGen_Private::EPropertyClass::Float, "amplitude", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, amplitude), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_octaves = { UE4CodeGen_Private::EPropertyClass::Int, "octaves", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, octaves), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_seed = { UE4CodeGen_Private::EPropertyClass::Int, "seed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, seed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventFractalNoise_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_frequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_amplitude,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_octaves,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_seed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_amplitude", "1.000000" },
		{ "CPP_Default_frequency", "0.003000" },
		{ "CPP_Default_octaves", "5" },
		{ "CPP_Default_seed", "0" },
		{ "CPP_Default_X", "0.000000" },
		{ "CPP_Default_Y", "0.000000" },
		{ "CPP_Default_Z", "0.000000" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "FractalNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VoxelLandscapeGenerator_eventFractalNoise_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics
	{
		struct VoxelLandscapeGenerator_eventIQNoise_Parms
		{
			FVector p;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_p;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventIQNoise_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::NewProp_p = { UE4CodeGen_Private::EPropertyClass::Struct, "p", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventIQNoise_Parms, p), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::NewProp_p,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "IQNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04840401, sizeof(VoxelLandscapeGenerator_eventIQNoise_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Z_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_color = { UE4CodeGen_Private::EPropertyClass::Struct, "color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetColorMap_Parms, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Z_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetColorMap_Parms, Z), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Z_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Z_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Y_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetColorMap_Parms, Y), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Y_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Y_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_X_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetColorMap_Parms, X), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_X_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_X_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Color Map" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "SetColorMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08C20C00, sizeof(VoxelLandscapeGenerator_eventSetColorMap_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_noise;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Z_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_noise = { UE4CodeGen_Private::EPropertyClass::Float, "noise", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetDensityMap_Parms, noise), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Z_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetDensityMap_Parms, Z), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Z_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Z_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Y_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetDensityMap_Parms, Y), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Y_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Y_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_X_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSetDensityMap_Parms, X), METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_X_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_X_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_noise,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Density Map" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "SetDensityMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(VoxelLandscapeGenerator_eventSetDensityMap_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics
	{
		struct VoxelLandscapeGenerator_eventSimplexNoise_Parms
		{
			float X;
			float Y;
			float Z;
			int32 seed;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_seed;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSimplexNoise_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_seed = { UE4CodeGen_Private::EPropertyClass::Int, "seed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSimplexNoise_Parms, seed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSimplexNoise_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSimplexNoise_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSimplexNoise_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_seed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "SimplexNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VoxelLandscapeGenerator_eventSimplexNoise_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics
	{
		struct VoxelLandscapeGenerator_eventSphereLandscape_Parms
		{
			float X;
			float Y;
			float Z;
			float radius;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSphereLandscape_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSphereLandscape_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSphereLandscape_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSphereLandscape_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventSphereLandscape_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_radius", "50.000000" },
		{ "CPP_Default_X", "0.000000" },
		{ "CPP_Default_Y", "0.000000" },
		{ "CPP_Default_Z", "0.000000" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "SphereLandscape", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VoxelLandscapeGenerator_eventSphereLandscape_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics
	{
		struct VoxelLandscapeGenerator_eventTorusLandscape_Parms
		{
			float X;
			float Y;
			float Z;
			float radius;
			float radiusInside;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusInside;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Z;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_radiusInside = { UE4CodeGen_Private::EPropertyClass::Float, "radiusInside", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, radiusInside), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventTorusLandscape_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_radiusInside,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "TorusLandscape", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VoxelLandscapeGenerator_eventTorusLandscape_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics
	{
		struct VoxelLandscapeGenerator_eventVectorDistanceAB_Parms
		{
			FVector A;
			FVector B;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_B;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_A;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventVectorDistanceAB_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_B = { UE4CodeGen_Private::EPropertyClass::Struct, "B", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventVectorDistanceAB_Parms, B), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_A = { UE4CodeGen_Private::EPropertyClass::Struct, "A", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscapeGenerator_eventVectorDistanceAB_Parms, A), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_B,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::NewProp_A,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelLandscapeGenerator, "VectorDistanceAB", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04840401, sizeof(VoxelLandscapeGenerator_eventVectorDistanceAB_Parms), Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister()
	{
		return UVoxelLandscapeGenerator::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelLandscapeGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Multiply_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Multiply;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeightmapTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HeightmapTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_Cone, "Cone" }, // 3787015747
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_FlatLandscape, "FlatLandscape" }, // 3164569653
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_FractalNoise, "FractalNoise" }, // 1547549849
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_IQNoise, "IQNoise" }, // 1465666336
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_SetColorMap, "SetColorMap" }, // 834148620
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_SetDensityMap, "SetDensityMap" }, // 2554003617
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_SimplexNoise, "SimplexNoise" }, // 3069397514
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_SphereLandscape, "SphereLandscape" }, // 857204035
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_TorusLandscape, "TorusLandscape" }, // 4293347551
		{ &Z_Construct_UFunction_UVoxelLandscapeGenerator_VectorDistanceAB, "VectorDistanceAB" }, // 784210992
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Renders/VoxelLandscapeGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_Multiply_MetaData[] = {
		{ "Category", "Import Own Heightmap" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_Multiply = { UE4CodeGen_Private::EPropertyClass::Float, "Multiply", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelLandscapeGenerator, Multiply), METADATA_PARAMS(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_Multiply_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_Multiply_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_HeightmapTexture_MetaData[] = {
		{ "Category", "Import Own Heightmap" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_HeightmapTexture = { UE4CodeGen_Private::EPropertyClass::Object, "HeightmapTexture", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelLandscapeGenerator, HeightmapTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_HeightmapTexture_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_HeightmapTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_World_MetaData[] = {
		{ "Category", "Import Own Heightmap" },
		{ "ModuleRelativePath", "Public/Renders/VoxelLandscapeGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelLandscapeGenerator, World), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_World_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_World_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_Multiply,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_HeightmapTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelLandscapeGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::ClassParams = {
		&UVoxelLandscapeGenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelLandscapeGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelLandscapeGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelLandscapeGenerator, 189136253);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelLandscapeGenerator(Z_Construct_UClass_UVoxelLandscapeGenerator, &UVoxelLandscapeGenerator::StaticClass, TEXT("/Script/VoxelArt"), TEXT("UVoxelLandscapeGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelLandscapeGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
