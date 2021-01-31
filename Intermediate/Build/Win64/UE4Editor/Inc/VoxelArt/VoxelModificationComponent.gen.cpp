// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/Editor/VoxelModificationComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelModificationComponent() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationComponent_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelModificationComponent_Modification();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunk_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelModificationLandscape_NoRegister();
// End Cross Module References
	void UVoxelModificationComponent::StaticRegisterNativesUVoxelModificationComponent()
	{
		UClass* Class = UVoxelModificationComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Modification", &UVoxelModificationComponent::execModification },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics
	{
		struct VoxelModificationComponent_eventModification_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_range = { UE4CodeGen_Private::EPropertyClass::Float, "range", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationComponent_eventModification_Parms, range), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_position = { UE4CodeGen_Private::EPropertyClass::Struct, "position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationComponent_eventModification_Parms, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_chunkCenter = { UE4CodeGen_Private::EPropertyClass::Object, "chunkCenter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationComponent_eventModification_Parms, chunkCenter), Z_Construct_UClass_AVoxelChunk_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_terrain = { UE4CodeGen_Private::EPropertyClass::Object, "terrain", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelModificationComponent_eventModification_Parms, terrain), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_range,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_chunkCenter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::NewProp_terrain,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelModificationComponent, "Modification", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(VoxelModificationComponent_eventModification_Parms), Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelModificationComponent_Modification()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelModificationComponent_Modification_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelModificationComponent_NoRegister()
	{
		return UVoxelModificationComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelModificationComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_modificator_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_modificator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelModificationComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelModificationComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelModificationComponent_Modification, "Modification" }, // 1988454527
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelModificationComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Editor/VoxelModificationComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelModificationComponent_Statics::NewProp_modificator_MetaData[] = {
		{ "Category", "Main" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Editor/VoxelModificationComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelModificationComponent_Statics::NewProp_modificator = { UE4CodeGen_Private::EPropertyClass::Object, "modificator", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001200000008000d, 1, nullptr, STRUCT_OFFSET(UVoxelModificationComponent, modificator), Z_Construct_UClass_UVoxelModificationLandscape_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelModificationComponent_Statics::NewProp_modificator_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelModificationComponent_Statics::NewProp_modificator_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelModificationComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelModificationComponent_Statics::NewProp_modificator,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelModificationComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelModificationComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelModificationComponent_Statics::ClassParams = {
		&UVoxelModificationComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A4u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelModificationComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelModificationComponent_Statics::PropPointers),
		"Engine",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelModificationComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelModificationComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelModificationComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelModificationComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelModificationComponent, 773223690);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelModificationComponent(Z_Construct_UClass_UVoxelModificationComponent, &UVoxelModificationComponent::StaticClass, TEXT("/Script/VoxelArt"), TEXT("UVoxelModificationComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelModificationComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
