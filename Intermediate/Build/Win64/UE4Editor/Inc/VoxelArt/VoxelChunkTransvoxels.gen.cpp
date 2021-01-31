// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/VoxelChunkTransvoxels.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelChunkTransvoxels() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunkTransvoxels_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunkTransvoxels();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void AVoxelChunkTransvoxels::StaticRegisterNativesAVoxelChunkTransvoxels()
	{
		UClass* Class = AVoxelChunkTransvoxels::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateVertexCube", &AVoxelChunkTransvoxels::execGenerateVertexCube },
			{ "GetValueNoise", &AVoxelChunkTransvoxels::execGetValueNoise },
			{ "GetVoxelId", &AVoxelChunkTransvoxels::execGetVoxelId },
			{ "GetVoxelSize", &AVoxelChunkTransvoxels::execGetVoxelSize },
			{ "GetVoxelSizeHalf", &AVoxelChunkTransvoxels::execGetVoxelSizeHalf },
			{ "MarchingCubes", &AVoxelChunkTransvoxels::execMarchingCubes },
			{ "UpdateMesh", &AVoxelChunkTransvoxels::execUpdateMesh },
			{ "VertexInterp", &AVoxelChunkTransvoxels::execVertexInterp },
			{ "VertexInterpTransition", &AVoxelChunkTransvoxels::execVertexInterpTransition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics
	{
		struct VoxelChunkTransvoxels_eventGenerateVertexCube_Parms
		{
			bool regenerate;
		};
		static void NewProp_regenerate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_regenerate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::NewProp_regenerate_SetBit(void* Obj)
	{
		((VoxelChunkTransvoxels_eventGenerateVertexCube_Parms*)Obj)->regenerate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::NewProp_regenerate = { UE4CodeGen_Private::EPropertyClass::Bool, "regenerate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelChunkTransvoxels_eventGenerateVertexCube_Parms), &Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::NewProp_regenerate_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::NewProp_regenerate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "GenerateVertexCube", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunkTransvoxels_eventGenerateVertexCube_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics
	{
		struct VoxelChunkTransvoxels_eventGetValueNoise_Parms
		{
			FVector positionGrid;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_positionGrid;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetValueNoise_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::NewProp_positionGrid = { UE4CodeGen_Private::EPropertyClass::Struct, "positionGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetValueNoise_Parms, positionGrid), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::NewProp_positionGrid,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "GetValueNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00820401, sizeof(VoxelChunkTransvoxels_eventGetValueNoise_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics
	{
		struct VoxelChunkTransvoxels_eventGetVoxelId_Parms
		{
			int32 posX;
			int32 posY;
			int32 posZ;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_posZ;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_posY;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_posX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelId_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posZ = { UE4CodeGen_Private::EPropertyClass::Int, "posZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelId_Parms, posZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posY = { UE4CodeGen_Private::EPropertyClass::Int, "posY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelId_Parms, posY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posX = { UE4CodeGen_Private::EPropertyClass::Int, "posX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelId_Parms, posX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::NewProp_posX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "GetVoxelId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunkTransvoxels_eventGetVoxelId_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics
	{
		struct VoxelChunkTransvoxels_eventGetVoxelSize_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "GetVoxelSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunkTransvoxels_eventGetVoxelSize_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics
	{
		struct VoxelChunkTransvoxels_eventGetVoxelSizeHalf_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventGetVoxelSizeHalf_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "GetVoxelSizeHalf", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunkTransvoxels_eventGetVoxelSizeHalf_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics
	{
		struct VoxelChunkTransvoxels_eventMarchingCubes_Parms
		{
			int32 isolevel;
			int32 indexGrid;
			int32 x;
			int32 y;
			int32 z;
			int32 normalIndex;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_normalIndex;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_indexGrid;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_isolevel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_normalIndex = { UE4CodeGen_Private::EPropertyClass::Int, "normalIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, normalIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Int, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Int, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Int, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_indexGrid = { UE4CodeGen_Private::EPropertyClass::Int, "indexGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, indexGrid), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_isolevel = { UE4CodeGen_Private::EPropertyClass::Int, "isolevel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventMarchingCubes_Parms, isolevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_normalIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_x,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_indexGrid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::NewProp_isolevel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "MarchingCubes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(VoxelChunkTransvoxels_eventMarchingCubes_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics
	{
		struct VoxelChunkTransvoxels_eventUpdateMesh_Parms
		{
			TArray<FVector> Vert;
			TArray<int32> Tri;
			TArray<FVector> Norm;
			TArray<FLinearColor> Cols;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cols;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Cols_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Norm;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Norm_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tri;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Tri_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vert;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vert_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Cols = { UE4CodeGen_Private::EPropertyClass::Array, "Cols", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventUpdateMesh_Parms, Cols), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Cols_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Cols", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Norm = { UE4CodeGen_Private::EPropertyClass::Array, "Norm", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventUpdateMesh_Parms, Norm), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Norm_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Norm", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Tri = { UE4CodeGen_Private::EPropertyClass::Array, "Tri", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventUpdateMesh_Parms, Tri), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Tri_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Tri", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Vert = { UE4CodeGen_Private::EPropertyClass::Array, "Vert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventUpdateMesh_Parms, Vert), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Vert_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Vert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Cols,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Cols_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Norm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Norm_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Tri,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Tri_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Vert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::NewProp_Vert_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "UpdateMesh", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunkTransvoxels_eventUpdateMesh_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics
	{
		struct VoxelChunkTransvoxels_eventVertexInterp_Parms
		{
			FVector P1;
			FVector P2;
			FVector N1;
			FVector N2;
			float P1Val;
			float P2Val;
			float Value;
			FVector normalInst;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_normalInst;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_P2Val;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_P1Val;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_N2;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_N1;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_P2;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_P1;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_normalInst = { UE4CodeGen_Private::EPropertyClass::Struct, "normalInst", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, normalInst), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P2Val = { UE4CodeGen_Private::EPropertyClass::Float, "P2Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, P2Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P1Val = { UE4CodeGen_Private::EPropertyClass::Float, "P1Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, P1Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_N2 = { UE4CodeGen_Private::EPropertyClass::Struct, "N2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, N2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_N1 = { UE4CodeGen_Private::EPropertyClass::Struct, "N1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, N1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P2 = { UE4CodeGen_Private::EPropertyClass::Struct, "P2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, P2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P1 = { UE4CodeGen_Private::EPropertyClass::Struct, "P1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterp_Parms, P1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_normalInst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P2Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P1Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_N2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_N1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::NewProp_P1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "VertexInterp", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00C20401, sizeof(VoxelChunkTransvoxels_eventVertexInterp_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics
	{
		struct VoxelChunkTransvoxels_eventVertexInterpTransition_Parms
		{
			FVector P1;
			FVector P2;
			float P1Val;
			float P2Val;
			float Value;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_P2Val;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_P1Val;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_P2;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_P1;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P2Val = { UE4CodeGen_Private::EPropertyClass::Float, "P2Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, P2Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P1Val = { UE4CodeGen_Private::EPropertyClass::Float, "P1Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, P1Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P2 = { UE4CodeGen_Private::EPropertyClass::Struct, "P2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, P2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P1 = { UE4CodeGen_Private::EPropertyClass::Struct, "P1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms, P1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P2Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P1Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::NewProp_P1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunkTransvoxels, "VertexInterpTransition", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00820401, sizeof(VoxelChunkTransvoxels_eventVertexInterpTransition_Parms), Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelChunkTransvoxels_NoRegister()
	{
		return AVoxelChunkTransvoxels::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelChunkTransvoxels_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextureCoordinates_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TextureCoordinates;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TextureCoordinates_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tangents;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Triangles;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TestTriangles_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TestTriangles;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TestTriangles_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TestVertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TestVertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TestVertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_generatePlane_MetaData[];
#endif
		static void NewProp_generatePlane_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_generatePlane;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_generateNoise_MetaData[];
#endif
		static void NewProp_generateNoise_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_generateNoise;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_generateSphere_MetaData[];
#endif
		static void NewProp_generateSphere_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_generateSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_positionSide_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_positionSide;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_positionSide_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Grid_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Grid;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Grid_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoGrid_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_infoGrid;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_infoGrid_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoChunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_infoChunk;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_infoChunk_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_position_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_position;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_positionChunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_positionChunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_update_MetaData[];
#endif
		static void NewProp_update_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_update;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_half_MetaData[];
#endif
		static void NewProp_half_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_half;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_grass_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_grass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ground_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ground;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_period_two_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_period_two;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_period_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_period;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_actave_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_actave;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_valueSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_valueSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_level_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_level;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transitionSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_transitionSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_multiplyMinus_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_multiplyMinus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_multiply_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_multiply;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_voxels_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_voxels;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radiusSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_multiplyOctree_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_multiplyOctree;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transvoxel_MetaData[];
#endif
		static void NewProp_transvoxel_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_transvoxel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_yPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_yPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_anim_MetaData[];
#endif
		static void NewProp_anim_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_anim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transvoxelDirection_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_transvoxelDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mesh_id_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_mesh_id;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_mesh_id_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mesh1_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mesh1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_z_chunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_z_chunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_y_chunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_y_chunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_x_chunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_x_chunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_GenerateVertexCube, "GenerateVertexCube" }, // 3430094218
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_GetValueNoise, "GetValueNoise" }, // 2344093257
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelId, "GetVoxelId" }, // 1143615281
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSize, "GetVoxelSize" }, // 216179296
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_GetVoxelSizeHalf, "GetVoxelSizeHalf" }, // 2080645141
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_MarchingCubes, "MarchingCubes" }, // 3929774966
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_UpdateMesh, "UpdateMesh" }, // 303409604
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterp, "VertexInterp" }, // 820933980
		{ &Z_Construct_UFunction_AVoxelChunkTransvoxels_VertexInterpTransition, "VertexInterpTransition" }, // 204707955
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelChunkTransvoxels.h" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates = { UE4CodeGen_Private::EPropertyClass::Array, "TextureCoordinates", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, TextureCoordinates), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TextureCoordinates", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents = { UE4CodeGen_Private::EPropertyClass::Array, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, Tangents), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
		{ "ToolTip", ", Meta = (MakeEditWidget = true)" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors = { UE4CodeGen_Private::EPropertyClass::Array, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, VertexColors), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals = { UE4CodeGen_Private::EPropertyClass::Array, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, Normals), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles = { UE4CodeGen_Private::EPropertyClass::Array, "Triangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, Triangles), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Triangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
		{ "ToolTip", ", Meta = (MakeEditWidget = true) EditDefaultsOnly" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices = { UE4CodeGen_Private::EPropertyClass::Array, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, Vertices), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles = { UE4CodeGen_Private::EPropertyClass::Array, "TestTriangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, TestTriangles), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TestTriangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
		{ "ToolTip", ", Meta = (MakeEditWidget = true) EditDefaultsOnly" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices = { UE4CodeGen_Private::EPropertyClass::Array, "TestVertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, TestVertices), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TestVertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->generatePlane = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane = { UE4CodeGen_Private::EPropertyClass::Bool, "generatePlane", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->generateNoise = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise = { UE4CodeGen_Private::EPropertyClass::Bool, "generateNoise", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->generateSphere = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere = { UE4CodeGen_Private::EPropertyClass::Bool, "generateSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide = { UE4CodeGen_Private::EPropertyClass::Array, "positionSide", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, positionSide), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "positionSide", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid = { UE4CodeGen_Private::EPropertyClass::Array, "Grid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, Grid), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "Grid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid = { UE4CodeGen_Private::EPropertyClass::Array, "infoGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, infoGrid), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "infoGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk = { UE4CodeGen_Private::EPropertyClass::Array, "infoChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, infoChunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "infoChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_position_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_position = { UE4CodeGen_Private::EPropertyClass::Struct, "position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, CPP_ARRAY_DIM(position, AVoxelChunkTransvoxels), nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_position_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_position_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionChunk_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Grid\")\n       TArray <FPositionVoxelChunkStruct> positionZ;" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionChunk = { UE4CodeGen_Private::EPropertyClass::Struct, "positionChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, positionChunk), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionChunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->update = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update = { UE4CodeGen_Private::EPropertyClass::Bool, "update", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->half = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half = { UE4CodeGen_Private::EPropertyClass::Bool, "half", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_grass_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_grass = { UE4CodeGen_Private::EPropertyClass::Struct, "grass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, grass), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_grass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_grass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_ground_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_ground = { UE4CodeGen_Private::EPropertyClass::Struct, "ground", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, ground), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_ground_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_ground_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_two_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_two = { UE4CodeGen_Private::EPropertyClass::Float, "period_two", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, period_two), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_two_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_two_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period = { UE4CodeGen_Private::EPropertyClass::Float, "period", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, period), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_actave_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_actave = { UE4CodeGen_Private::EPropertyClass::Float, "actave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, actave), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_actave_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_actave_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_valueSize_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_valueSize = { UE4CodeGen_Private::EPropertyClass::Int, "valueSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, valueSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_valueSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_valueSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_level_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_level = { UE4CodeGen_Private::EPropertyClass::Int, "level", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, level), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_level_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_level_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transitionSize_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transitionSize = { UE4CodeGen_Private::EPropertyClass::Float, "transitionSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, transitionSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transitionSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transitionSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyMinus_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyMinus = { UE4CodeGen_Private::EPropertyClass::Float, "multiplyMinus", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, multiplyMinus), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyMinus_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyMinus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiply_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiply = { UE4CodeGen_Private::EPropertyClass::Int, "multiply", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, multiply), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiply_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiply_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_voxels_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_voxels = { UE4CodeGen_Private::EPropertyClass::Int, "voxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, voxels), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_voxels_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_voxels_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radiusSphere_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radiusSphere = { UE4CodeGen_Private::EPropertyClass::Float, "radiusSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, radiusSphere), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radiusSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radiusSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radius_MetaData[] = {
		{ "Category", "Size" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, radius), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radius_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyOctree_MetaData[] = {
		{ "Category", "Octree" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyOctree = { UE4CodeGen_Private::EPropertyClass::Int, "multiplyOctree", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, multiplyOctree), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyOctree_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyOctree_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->transvoxel = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel = { UE4CodeGen_Private::EPropertyClass::Bool, "transvoxel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_yPos_MetaData[] = {
		{ "Category", "Anim" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_yPos = { UE4CodeGen_Private::EPropertyClass::Float, "yPos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, yPos), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_yPos_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_yPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Anim" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_speed = { UE4CodeGen_Private::EPropertyClass::Float, "speed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, speed), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_speed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim_MetaData[] = {
		{ "Category", "Anim" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim_SetBit(void* Obj)
	{
		((AVoxelChunkTransvoxels*)Obj)->anim = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim = { UE4CodeGen_Private::EPropertyClass::Bool, "anim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunkTransvoxels), &Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxelDirection_MetaData[] = {
		{ "Category", "Anim" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxelDirection = { UE4CodeGen_Private::EPropertyClass::Byte, "transvoxelDirection", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, transvoxelDirection), nullptr, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxelDirection_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxelDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id = { UE4CodeGen_Private::EPropertyClass::Array, "mesh_id", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020001, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, mesh_id), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "mesh_id", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000020000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_CollisionMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_CollisionMesh = { UE4CodeGen_Private::EPropertyClass::Object, "CollisionMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, CollisionMesh), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_CollisionMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_CollisionMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh1_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh1 = { UE4CodeGen_Private::EPropertyClass::Object, "mesh1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, mesh1), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh1_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh = { UE4CodeGen_Private::EPropertyClass::Object, "mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_z_chunk_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_z_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "z_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, z_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_z_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_z_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_y_chunk_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_y_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "y_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, y_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_y_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_y_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_x_chunk_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_x_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "x_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, x_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_x_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_x_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_material_MetaData[] = {
		{ "Category", "VoxelChunkTransvoxels" },
		{ "ModuleRelativePath", "Public/VoxelChunkTransvoxels.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_material = { UE4CodeGen_Private::EPropertyClass::Object, "material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunkTransvoxels, material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_material_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TextureCoordinates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Tangents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_VertexColors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Triangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestTriangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_TestVertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generatePlane,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateNoise,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_generateSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionSide_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_Grid_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoGrid_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_infoChunk_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_positionChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_update,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_half,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_grass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_ground,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period_two,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_period,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_actave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_valueSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_level,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transitionSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyMinus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiply,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_voxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radiusSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_multiplyOctree,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_yPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_anim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_transvoxelDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh_id_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_CollisionMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_z_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_y_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_x_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::NewProp_material,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelChunkTransvoxels>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::ClassParams = {
		&AVoxelChunkTransvoxels::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelChunkTransvoxels()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelChunkTransvoxels_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelChunkTransvoxels, 3461273259);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelChunkTransvoxels(Z_Construct_UClass_AVoxelChunkTransvoxels, &AVoxelChunkTransvoxels::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelChunkTransvoxels"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelChunkTransvoxels);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
