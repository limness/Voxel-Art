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
	VOXELART_API UEnum* Z_Construct_UEnum_VoxelArt_EditorType();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelPlayerController_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
// End Cross Module References
	static UEnum* EditorType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VoxelArt_EditorType, Z_Construct_UPackage__Script_VoxelArt(), TEXT("EditorType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EditorType(EditorType_StaticEnum, TEXT("/Script/VoxelArt"), TEXT("EditorType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VoxelArt_EditorType_CRC() { return 489943530U; }
	UEnum* Z_Construct_UEnum_VoxelArt_EditorType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelArt();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EditorType"), 0, Get_Z_Construct_UEnum_VoxelArt_EditorType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Terrain", (int64)Terrain },
				{ "Color", (int64)Color },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Color.DisplayName", "Color" },
				{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
				{ "Terrain.DisplayName", "Terrain" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VoxelArt,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EditorType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::Regular,
				"EditorType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AVoxelPlayerController::StaticRegisterNativesAVoxelPlayerController()
	{
		UClass* Class = AVoxelPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeWorldColor", &AVoxelPlayerController::execChangeWorldColor },
			{ "ChangeWorldTerrain", &AVoxelPlayerController::execChangeWorldTerrain },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics
	{
		struct VoxelPlayerController_eventChangeWorldColor_Parms
		{
			AVoxelLandscape* World;
			FVector HitPosition;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitPosition;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::NewProp_HitPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "HitPosition", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeWorldColor_Parms, HitPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeWorldColor_Parms, World), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::NewProp_HitPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelPlayerController, "ChangeWorldColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelPlayerController_eventChangeWorldColor_Parms), Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics
	{
		struct VoxelPlayerController_eventChangeWorldTerrain_Parms
		{
			AVoxelLandscape* World;
			FVector HitPosition;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitPosition;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::NewProp_HitPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "HitPosition", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeWorldTerrain_Parms, HitPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelPlayerController_eventChangeWorldTerrain_Parms, World), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::NewProp_HitPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::NewProp_World,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelPlayerController, "ChangeWorldTerrain", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelPlayerController_eventChangeWorldTerrain_Parms), Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RenderType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_RenderType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SmoothInsert_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SmoothInsert;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxDictance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxDictance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Strength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Strength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Smooth_MetaData[];
#endif
		static void NewProp_Smooth_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Smooth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
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
		{ &Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldColor, "ChangeWorldColor" }, // 3959160302
		{ &Z_Construct_UFunction_AVoxelPlayerController_ChangeWorldTerrain, "ChangeWorldTerrain" }, // 3766210165
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "VoxelPlayerController.h" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_RenderType_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_RenderType = { UE4CodeGen_Private::EPropertyClass::Byte, "RenderType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, RenderType), Z_Construct_UEnum_VoxelArt_EditorType, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_RenderType_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_RenderType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_SmoothInsert_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_SmoothInsert = { UE4CodeGen_Private::EPropertyClass::Float, "SmoothInsert", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, SmoothInsert), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_SmoothInsert_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_SmoothInsert_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_MaxDictance_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_MaxDictance = { UE4CodeGen_Private::EPropertyClass::Float, "MaxDictance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, MaxDictance), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_MaxDictance_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_MaxDictance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Strength_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Strength = { UE4CodeGen_Private::EPropertyClass::Float, "Strength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, Strength), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Strength_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Strength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth_SetBit(void* Obj)
	{
		((AVoxelPlayerController*)Obj)->Smooth = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth = { UE4CodeGen_Private::EPropertyClass::Bool, "Smooth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Editor ~ Settings" },
		{ "ModuleRelativePath", "Public/VoxelPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Radius = { UE4CodeGen_Private::EPropertyClass::Float, "Radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelPlayerController, Radius), METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Radius_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Radius_MetaData)) };
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
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed = { UE4CodeGen_Private::EPropertyClass::Bool, "EditorCreatePressed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorCreatePressed_MetaData)) };
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
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed = { UE4CodeGen_Private::EPropertyClass::Bool, "EditorRemovePressed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelPlayerController), &Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_EditorRemovePressed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_RenderType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_SmoothInsert,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_MaxDictance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Smooth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelPlayerController_Statics::NewProp_Radius,
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
	IMPLEMENT_CLASS(AVoxelPlayerController, 1156171746);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelPlayerController(Z_Construct_UClass_AVoxelPlayerController, &AVoxelPlayerController::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
