// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/Editor/VoxelModificationLandscape.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelModificationLandscape() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationLandscape_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationLandscape();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter();
// End Cross Module References
	static FName NAME_UVoxelModificationLandscape_GetPainterData = FName(TEXT("GetPainterData"));
	void UVoxelModificationLandscape::GetPainterData(float const& X, float const& Y, float const& Z, float& noise, float& strength, bool& dig, bool& smooth)
	{
		VoxelModificationLandscape_eventGetPainterData_Parms Parms;
		Parms.X=X;
		Parms.Y=Y;
		Parms.Z=Z;
		Parms.noise=noise;
		Parms.strength=strength;
		Parms.dig=dig ? true : false;
		Parms.smooth=smooth ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVoxelModificationLandscape_GetPainterData),&Parms);
		noise=Parms.noise;
		strength=Parms.strength;
		dig=Parms.dig;
		smooth=Parms.smooth;
	}
	void UVoxelModificationLandscape::StaticRegisterNativesUVoxelModificationLandscape()
	{
		UClass* Class = UVoxelModificationLandscape::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BangPainter", &UVoxelModificationLandscape::execBangPainter },
			{ "SpherePainter", &UVoxelModificationLandscape::execSpherePainter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics
	{
		struct VoxelModificationLandscape_eventBangPainter_Parms
		{
			float X;
			float Y;
			float Z;
			float radius;
			int32 octaves;
			float amplitude;
			float frequency;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_frequency;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_amplitude;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_octaves;
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_frequency = { UE4CodeGen_Private::EPropertyClass::Float, "frequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, frequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_amplitude = { UE4CodeGen_Private::EPropertyClass::Float, "amplitude", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, amplitude), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_octaves = { UE4CodeGen_Private::EPropertyClass::Int, "octaves", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, octaves), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventBangPainter_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_frequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_amplitude,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_octaves,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelModificationLandscape, "BangPainter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelModificationLandscape_eventBangPainter_Parms), Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics
	{
		static void NewProp_smooth_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_smooth;
		static void NewProp_dig_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_dig;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_strength;
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
	void Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_smooth_SetBit(void* Obj)
	{
		((VoxelModificationLandscape_eventGetPainterData_Parms*)Obj)->smooth = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_smooth = { UE4CodeGen_Private::EPropertyClass::Bool, "smooth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelModificationLandscape_eventGetPainterData_Parms), &Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_smooth_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_dig_SetBit(void* Obj)
	{
		((VoxelModificationLandscape_eventGetPainterData_Parms*)Obj)->dig = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_dig = { UE4CodeGen_Private::EPropertyClass::Bool, "dig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelModificationLandscape_eventGetPainterData_Parms), &Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_dig_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_strength = { UE4CodeGen_Private::EPropertyClass::Float, "strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventGetPainterData_Parms, strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_noise = { UE4CodeGen_Private::EPropertyClass::Float, "noise", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventGetPainterData_Parms, noise), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Z_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventGetPainterData_Parms, Z), METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Z_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Z_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Y_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventGetPainterData_Parms, Y), METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Y_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Y_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_X_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventGetPainterData_Parms, X), METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_X_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_X_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_smooth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_dig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_noise,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Nice Cock" },
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelModificationLandscape, "GetPainterData", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(VoxelModificationLandscape_eventGetPainterData_Parms), Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics
	{
		struct VoxelModificationLandscape_eventSpherePainter_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventSpherePainter_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventSpherePainter_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_Z = { UE4CodeGen_Private::EPropertyClass::Float, "Z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventSpherePainter_Parms, Z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventSpherePainter_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationLandscape_eventSpherePainter_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_Z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::NewProp_X,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelModificationLandscape, "SpherePainter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelModificationLandscape_eventSpherePainter_Parms), Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelModificationLandscape_NoRegister()
	{
		return UVoxelModificationLandscape::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelModificationLandscape_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelModificationLandscape_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelModificationLandscape_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelModificationLandscape_BangPainter, "BangPainter" }, // 187035146
		{ &Z_Construct_UFunction_UVoxelModificationLandscape_GetPainterData, "GetPainterData" }, // 798970545
		{ &Z_Construct_UFunction_UVoxelModificationLandscape_SpherePainter, "SpherePainter" }, // 4088038979
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelModificationLandscape_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Editor/VoxelModificationLandscape.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationLandscape.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelModificationLandscape_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelModificationLandscape>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelModificationLandscape_Statics::ClassParams = {
		&UVoxelModificationLandscape::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelModificationLandscape_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelModificationLandscape_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelModificationLandscape()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelModificationLandscape_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelModificationLandscape, 3238167118);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelModificationLandscape(Z_Construct_UClass_UVoxelModificationLandscape, &UVoxelModificationLandscape::StaticClass, TEXT("/Script/VoxelArt"), TEXT("UVoxelModificationLandscape"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelModificationLandscape);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
