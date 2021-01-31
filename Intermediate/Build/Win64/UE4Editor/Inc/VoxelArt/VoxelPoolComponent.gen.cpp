// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/VoxelPoolComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelPoolComponent() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_UVoxelPoolComponent_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelPoolComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
// End Cross Module References
	void UVoxelPoolComponent::StaticRegisterNativesUVoxelPoolComponent()
	{
	}
	UClass* Z_Construct_UClass_UVoxelPoolComponent_NoRegister()
	{
		return UVoxelPoolComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelPoolComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelPoolComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelPoolComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "VoxelPoolComponent.h" },
		{ "ModuleRelativePath", "Public/VoxelPoolComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelPoolComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelPoolComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelPoolComponent_Statics::ClassParams = {
		&UVoxelPoolComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A4u,
		nullptr, 0,
		nullptr, 0,
		"Engine",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelPoolComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelPoolComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelPoolComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelPoolComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelPoolComponent, 608906374);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelPoolComponent(Z_Construct_UClass_UVoxelPoolComponent, &UVoxelPoolComponent::StaticClass, TEXT("/Script/VoxelArt"), TEXT("UVoxelPoolComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelPoolComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
