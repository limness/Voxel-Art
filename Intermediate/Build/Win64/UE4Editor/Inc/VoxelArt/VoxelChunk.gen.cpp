// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/VoxelChunk.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelChunk() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunk_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunk();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_ChangeVoxel();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationLandscape_NoRegister();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_GetVoxelSize();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_MarchingCubes();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_UpdateMesh();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelChunk_VertexInterp();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void AVoxelChunk::StaticRegisterNativesAVoxelChunk()
	{
		UClass* Class = AVoxelChunk::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeVoxel", &AVoxelChunk::execChangeVoxel },
			{ "GenerateDensityAndCreateMeshAsync", &AVoxelChunk::execGenerateDensityAndCreateMeshAsync },
			{ "GenerateDensityMap", &AVoxelChunk::execGenerateDensityMap },
			{ "GenerateVertexCube", &AVoxelChunk::execGenerateVertexCube },
			{ "GetVoxelSize", &AVoxelChunk::execGetVoxelSize },
			{ "GetVoxelSizeHalf", &AVoxelChunk::execGetVoxelSizeHalf },
			{ "MarchingCubes", &AVoxelChunk::execMarchingCubes },
			{ "UpdateMesh", &AVoxelChunk::execUpdateMesh },
			{ "VertexInterp", &AVoxelChunk::execVertexInterp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics
	{
		struct VoxelChunk_eventChangeVoxel_Parms
		{
			UVoxelModificationLandscape* modificator;
			FVector positionCenterPoint;
			float range;
			float strength;
			bool smooth;
			bool dig;
			float smoothInsert;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_smoothInsert;
		static void NewProp_dig_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_dig;
		static void NewProp_smooth_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_smooth;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_strength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_range;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_positionCenterPoint;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_modificator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VoxelChunk_eventChangeVoxel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelChunk_eventChangeVoxel_Parms), &Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smoothInsert = { UE4CodeGen_Private::EPropertyClass::Float, "smoothInsert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventChangeVoxel_Parms, smoothInsert), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_dig_SetBit(void* Obj)
	{
		((VoxelChunk_eventChangeVoxel_Parms*)Obj)->dig = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_dig = { UE4CodeGen_Private::EPropertyClass::Bool, "dig", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelChunk_eventChangeVoxel_Parms), &Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_dig_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smooth_SetBit(void* Obj)
	{
		((VoxelChunk_eventChangeVoxel_Parms*)Obj)->smooth = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smooth = { UE4CodeGen_Private::EPropertyClass::Bool, "smooth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelChunk_eventChangeVoxel_Parms), &Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smooth_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_strength = { UE4CodeGen_Private::EPropertyClass::Float, "strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventChangeVoxel_Parms, strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_range = { UE4CodeGen_Private::EPropertyClass::Float, "range", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventChangeVoxel_Parms, range), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_positionCenterPoint = { UE4CodeGen_Private::EPropertyClass::Struct, "positionCenterPoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventChangeVoxel_Parms, positionCenterPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_modificator = { UE4CodeGen_Private::EPropertyClass::Object, "modificator", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventChangeVoxel_Parms, modificator), Z_Construct_UClass_UVoxelModificationLandscape_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smoothInsert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_dig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_smooth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_range,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_positionCenterPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::NewProp_modificator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "ChangeVoxel", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelChunk_eventChangeVoxel_Parms), Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_ChangeVoxel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_ChangeVoxel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voxel" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
		{ "ToolTip", "FAsyncTask<TerrainGenerationAsyncTask>* Task;" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "GenerateDensityAndCreateMeshAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "GenerateDensityMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics
	{
		struct VoxelChunk_eventGenerateVertexCube_Parms
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
	void Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::NewProp_regenerate_SetBit(void* Obj)
	{
		((VoxelChunk_eventGenerateVertexCube_Parms*)Obj)->regenerate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::NewProp_regenerate = { UE4CodeGen_Private::EPropertyClass::Bool, "regenerate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VoxelChunk_eventGenerateVertexCube_Parms), &Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::NewProp_regenerate_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::NewProp_regenerate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "GenerateVertexCube", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunk_eventGenerateVertexCube_Parms), Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics
	{
		struct VoxelChunk_eventGetVoxelSize_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventGetVoxelSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
		{ "ToolTip", "bool ChangeVoxel(float range, AVoxelChunk* chunkCenter, FVector voxelCenter, float volume, float strength, bool smooth);" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "GetVoxelSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunk_eventGetVoxelSize_Parms), Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_GetVoxelSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_GetVoxelSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics
	{
		struct VoxelChunk_eventGetVoxelSizeHalf_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventGetVoxelSizeHalf_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "GetVoxelSizeHalf", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunk_eventGetVoxelSizeHalf_Parms), Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics
	{
		struct VoxelChunk_eventMarchingCubes_Parms
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
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_normalIndex = { UE4CodeGen_Private::EPropertyClass::Int, "normalIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, normalIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_z = { UE4CodeGen_Private::EPropertyClass::Int, "z", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_y = { UE4CodeGen_Private::EPropertyClass::Int, "y", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_x = { UE4CodeGen_Private::EPropertyClass::Int, "x", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_indexGrid = { UE4CodeGen_Private::EPropertyClass::Int, "indexGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, indexGrid), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_isolevel = { UE4CodeGen_Private::EPropertyClass::Int, "isolevel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventMarchingCubes_Parms, isolevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_normalIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_z,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_x,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_indexGrid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::NewProp_isolevel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "MarchingCubes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(VoxelChunk_eventMarchingCubes_Parms), Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_MarchingCubes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_MarchingCubes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics
	{
		struct VoxelChunk_eventUpdateMesh_Parms
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
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Cols = { UE4CodeGen_Private::EPropertyClass::Array, "Cols", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventUpdateMesh_Parms, Cols), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Cols_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Cols", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Norm = { UE4CodeGen_Private::EPropertyClass::Array, "Norm", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventUpdateMesh_Parms, Norm), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Norm_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Norm", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Tri = { UE4CodeGen_Private::EPropertyClass::Array, "Tri", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventUpdateMesh_Parms, Tri), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Tri_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Tri", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Vert = { UE4CodeGen_Private::EPropertyClass::Array, "Vert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventUpdateMesh_Parms, Vert), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Vert_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Vert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Cols,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Cols_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Norm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Norm_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Tri,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Tri_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Vert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::NewProp_Vert_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "UpdateMesh", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VoxelChunk_eventUpdateMesh_Parms), Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_UpdateMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_UpdateMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics
	{
		struct VoxelChunk_eventVertexInterp_Parms
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
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_normalInst = { UE4CodeGen_Private::EPropertyClass::Struct, "normalInst", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, normalInst), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P2Val = { UE4CodeGen_Private::EPropertyClass::Float, "P2Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, P2Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P1Val = { UE4CodeGen_Private::EPropertyClass::Float, "P1Val", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, P1Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_N2 = { UE4CodeGen_Private::EPropertyClass::Struct, "N2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, N2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_N1 = { UE4CodeGen_Private::EPropertyClass::Struct, "N1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, N1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P2 = { UE4CodeGen_Private::EPropertyClass::Struct, "P2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, P2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P1 = { UE4CodeGen_Private::EPropertyClass::Struct, "P1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelChunk_eventVertexInterp_Parms, P1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_normalInst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P2Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P1Val,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_N2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_N1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::NewProp_P1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelChunk, "VertexInterp", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00C20401, sizeof(VoxelChunk_eventVertexInterp_Parms), Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelChunk_VertexInterp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelChunk_VertexInterp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelChunk_NoRegister()
	{
		return AVoxelChunk::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelChunk_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_meshTree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_meshTree;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hasOwnGrid_MetaData[];
#endif
		static void NewProp_hasOwnGrid_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_hasOwnGrid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_level_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_level;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_voxels_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_voxels;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radiusSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_heightTest_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_heightTest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_multiplyOctree_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_multiplyOctree;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transvoxelDirection_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_transvoxelDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelChunk_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelChunk_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelChunk_ChangeVoxel, "ChangeVoxel" }, // 3640184235
		{ &Z_Construct_UFunction_AVoxelChunk_GenerateDensityAndCreateMeshAsync, "GenerateDensityAndCreateMeshAsync" }, // 2820138915
		{ &Z_Construct_UFunction_AVoxelChunk_GenerateDensityMap, "GenerateDensityMap" }, // 1602329750
		{ &Z_Construct_UFunction_AVoxelChunk_GenerateVertexCube, "GenerateVertexCube" }, // 3993780097
		{ &Z_Construct_UFunction_AVoxelChunk_GetVoxelSize, "GetVoxelSize" }, // 1791592725
		{ &Z_Construct_UFunction_AVoxelChunk_GetVoxelSizeHalf, "GetVoxelSizeHalf" }, // 3970629345
		{ &Z_Construct_UFunction_AVoxelChunk_MarchingCubes, "MarchingCubes" }, // 3609041762
		{ &Z_Construct_UFunction_AVoxelChunk_UpdateMesh, "UpdateMesh" }, // 2862592162
		{ &Z_Construct_UFunction_AVoxelChunk_VertexInterp, "VertexInterp" }, // 3539165239
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelChunk.h" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_meshTree_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_meshTree = { UE4CodeGen_Private::EPropertyClass::Object, "meshTree", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, meshTree), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_meshTree_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_meshTree_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates = { UE4CodeGen_Private::EPropertyClass::Array, "TextureCoordinates", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, TextureCoordinates), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TextureCoordinates", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents = { UE4CodeGen_Private::EPropertyClass::Array, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, Tangents), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
		{ "ToolTip", ", Meta = (MakeEditWidget = true)" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors = { UE4CodeGen_Private::EPropertyClass::Array, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, VertexColors), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals = { UE4CodeGen_Private::EPropertyClass::Array, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, Normals), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles = { UE4CodeGen_Private::EPropertyClass::Array, "Triangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, Triangles), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Triangles", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
		{ "ToolTip", ", Meta = (MakeEditWidget = true) EditDefaultsOnly" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices = { UE4CodeGen_Private::EPropertyClass::Array, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, Vertices), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->generatePlane = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane = { UE4CodeGen_Private::EPropertyClass::Bool, "generatePlane", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->generateNoise = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise = { UE4CodeGen_Private::EPropertyClass::Bool, "generateNoise", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere_MetaData[] = {
		{ "Category", "Generate" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->generateSphere = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere = { UE4CodeGen_Private::EPropertyClass::Bool, "generateSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid = { UE4CodeGen_Private::EPropertyClass::Array, "Grid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, Grid), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "Grid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid = { UE4CodeGen_Private::EPropertyClass::Array, "infoGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, infoGrid), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "infoGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk = { UE4CodeGen_Private::EPropertyClass::Array, "infoChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, infoChunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "infoChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_position_MetaData[] = {
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_position = { UE4CodeGen_Private::EPropertyClass::Struct, "position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, CPP_ARRAY_DIM(position, AVoxelChunk), nullptr, STRUCT_OFFSET(AVoxelChunk, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_position_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_position_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_positionChunk_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_positionChunk = { UE4CodeGen_Private::EPropertyClass::Struct, "positionChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, positionChunk), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_positionChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_positionChunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->update = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update = { UE4CodeGen_Private::EPropertyClass::Bool, "update", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->half = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half = { UE4CodeGen_Private::EPropertyClass::Bool, "half", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_grass_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_grass = { UE4CodeGen_Private::EPropertyClass::Struct, "grass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, grass), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_grass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_grass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_ground_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_ground = { UE4CodeGen_Private::EPropertyClass::Struct, "ground", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, ground), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_ground_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_ground_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_two_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_two = { UE4CodeGen_Private::EPropertyClass::Float, "period_two", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, period_two), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_two_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_two_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period = { UE4CodeGen_Private::EPropertyClass::Float, "period", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, period), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_actave_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_actave = { UE4CodeGen_Private::EPropertyClass::Float, "actave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, actave), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_actave_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_actave_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid_SetBit(void* Obj)
	{
		((AVoxelChunk*)Obj)->hasOwnGrid = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid = { UE4CodeGen_Private::EPropertyClass::Bool, "hasOwnGrid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelChunk), &Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_level_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_level = { UE4CodeGen_Private::EPropertyClass::Int, "level", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, level), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_level_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_level_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_voxels_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_voxels = { UE4CodeGen_Private::EPropertyClass::Int, "voxels", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, voxels), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_voxels_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_voxels_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radiusSphere_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radiusSphere = { UE4CodeGen_Private::EPropertyClass::Float, "radiusSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, radiusSphere), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radiusSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radiusSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_heightTest_MetaData[] = {
		{ "Category", "Size" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_heightTest = { UE4CodeGen_Private::EPropertyClass::Str, "heightTest", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, heightTest), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_heightTest_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_heightTest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radius_MetaData[] = {
		{ "Category", "Size" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, radius), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radius_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_multiplyOctree_MetaData[] = {
		{ "Category", "Octree" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_multiplyOctree = { UE4CodeGen_Private::EPropertyClass::Int, "multiplyOctree", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, multiplyOctree), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_multiplyOctree_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_multiplyOctree_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id = { UE4CodeGen_Private::EPropertyClass::Array, "mesh_id", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020001, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, mesh_id), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "mesh_id", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000020000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_CollisionMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_CollisionMesh = { UE4CodeGen_Private::EPropertyClass::Object, "CollisionMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, CollisionMesh), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_CollisionMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_CollisionMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh1_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh1 = { UE4CodeGen_Private::EPropertyClass::Object, "mesh1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, mesh1), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh1_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh = { UE4CodeGen_Private::EPropertyClass::Object, "mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_z_chunk_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_z_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "z_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, z_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_z_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_z_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_y_chunk_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_y_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "y_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, y_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_y_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_y_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_x_chunk_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_x_chunk = { UE4CodeGen_Private::EPropertyClass::Int, "x_chunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0011000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, x_chunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_x_chunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_x_chunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_transvoxelDirection_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_transvoxelDirection = { UE4CodeGen_Private::EPropertyClass::Byte, "transvoxelDirection", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, transvoxelDirection), nullptr, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_transvoxelDirection_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_transvoxelDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelChunk_Statics::NewProp_material_MetaData[] = {
		{ "Category", "VoxelChunk" },
		{ "ModuleRelativePath", "Public/VoxelChunk.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelChunk_Statics::NewProp_material = { UE4CodeGen_Private::EPropertyClass::Object, "material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelChunk, material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::NewProp_material_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelChunk_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_meshTree,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_TextureCoordinates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Tangents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_VertexColors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Triangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generatePlane,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateNoise,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_generateSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_Grid_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoGrid_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_infoChunk_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_positionChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_update,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_half,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_grass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_ground,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period_two,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_period,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_actave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_hasOwnGrid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_level,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_voxels,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radiusSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_heightTest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_multiplyOctree,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh_id_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_CollisionMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_z_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_y_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_x_chunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_transvoxelDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelChunk_Statics::NewProp_material,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelChunk_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelChunk>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelChunk_Statics::ClassParams = {
		&AVoxelChunk::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelChunk_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelChunk_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelChunk_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelChunk()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelChunk_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelChunk, 2005775277);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelChunk(Z_Construct_UClass_AVoxelChunk, &AVoxelChunk::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelChunk"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelChunk);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
