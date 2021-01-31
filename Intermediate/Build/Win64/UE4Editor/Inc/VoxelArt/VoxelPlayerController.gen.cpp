// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/VoxelPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPlayerController() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_AVoxelPlayerController_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunk_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
// End Cross Module References
	void AVoxelPlayerController::StaticRegisterNativesAVoxelPlayerController()
	{
		UClass* Class = AVoxelPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeChunk", &AVoxelPlayerController::execChangeChunk },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics
	{
		struct VoxelPlayerController_eventChangeChunk_Parms
		{
			AVoxelLandscape* terrain;
			AVoxelChunk* chunkCenter;
			FVector position;
			float range;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_range;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_position;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_chunkCenter;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_terrain;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_range = { UE4CodeGen_Private::EPropertyClass::Float, "range", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeChunk_Parms, range), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_position = { UE4CodeGen_Private::EPropertyClass::Struct, "position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeChunk_Parms, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_chunkCenter = { UE4CodeGen_Private::EPropertyClass::Object, "chunkCenter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeChunk_Parms, chunkCenter), Z_Construct_UClass_AVoxelChunk_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_terrain = { UE4CodeGen_Private::EPropertyClass::Object, "terrain", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeChunk_Parms, terrain), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_range,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_chunkCenter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::NewProp_terrain,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelPlayerController, "ChangeChunk", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelPlayerController_eventChangeChunk_Parms), Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelPlayerController_NoRegister()
	{
		return AVoxelPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_smoothInsert_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_smoothInsert;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dictance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_dictance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_strength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_strength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_smooth_MetaData[];
#endif
		static void NewProp_smooth_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_smooth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_editorSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_editorSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rangeEdit_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeEdit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rangeEditMax_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rangeEditMax;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_positionVoxelZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_positionVoxelZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_positionVoxelY_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_positionVoxelY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_positionVoxelX_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_positionVoxelX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorCreatePressed_MetaData[];
#endif
		static void NewProp_EditorCreatePressed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EditorCreatePressed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorRemovePressed_MetaData[];
#endif
		static void NewProp_EditorRemovePressed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EditorRemovePressed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelPlayerController_ChangeChunk, "ChangeChunk" }, // 1494268869
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "VoxelPlayerController.h" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smoothInsert_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smoothInsert = { UE4CodeGen_Private::EPropertyClass::Float, "smoothInsert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, smoothInsert), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smoothInsert_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smoothInsert_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_dictance_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_dictance = { UE4CodeGen_Private::EPropertyClass::Float, "dictance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, dictance), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_dictance_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_dictance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_strength_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_strength = { UE4CodeGen_Private::EPropertyClass::Float, "strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, strength), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_strength_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_strength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth_SetBit(void* Obj)
	{
		((AVoxelPlayerController*)Obj)->smooth = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth = { UE4CodeGen_Private::EPropertyClass::Bool, "smooth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_editorSpeed_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_editorSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "editorSpeed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, editorSpeed), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_editorSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_editorSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEdit_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEdit = { UE4CodeGen_Private::EPropertyClass::Float, "rangeEdit", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, rangeEdit), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEdit_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEdit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEditMax_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEditMax = { UE4CodeGen_Private::EPropertyClass::Float, "rangeEditMax", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, rangeEditMax), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEditMax_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEditMax_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelZ_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelZ = { UE4CodeGen_Private::EPropertyClass::Int, "positionVoxelZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, positionVoxelZ), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelZ_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelY_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelY = { UE4CodeGen_Private::EPropertyClass::Int, "positionVoxelY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, positionVoxelY), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelY_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelX_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelX = { UE4CodeGen_Private::EPropertyClass::Int, "positionVoxelX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, positionVoxelX), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelX_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_SetBit(void* Obj)
	{
		((AVoxelPlayerController*)Obj)->EditorCreatePressed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed = { UE4CodeGen_Private::EPropertyClass::Bool, "EditorCreatePressed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_MetaData[] = {
		{ "Category", "VoxelPlayerController" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_SetBit(void* Obj)
	{
		((AVoxelPlayerController*)Obj)->EditorRemovePressed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed = { UE4CodeGen_Private::EPropertyClass::Bool, "EditorRemovePressed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smoothInsert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_dictance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_smooth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_editorSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEdit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_rangeEditMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_positionVoxelX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelPlayerController_Statics::ClassParams = {
		&AVoxelPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelPlayerController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelPlayerController, 69683629);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPlayerController(Z_Construct_UClass_AVoxelPlayerController, &AVoxelPlayerController::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
