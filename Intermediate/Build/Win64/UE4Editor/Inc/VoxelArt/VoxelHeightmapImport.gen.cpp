// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/Importers/VoxelHeightmapImport.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelHeightmapImport() {}
// Cross Module References
	VOXELART_API UClass* Z_Construct_UClass_UVoxelHeightmapImport_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelHeightmapImport();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UFunction* Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
// End Cross Module References
	void UVoxelHeightmapImport::StaticRegisterNativesUVoxelHeightmapImport()
	{
		UClass* Class = UVoxelHeightmapImport::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateHeightmap", &UVoxelHeightmapImport::execGenerateHeightmap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/Importers/VoxelHeightmapImport.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVoxelHeightmapImport, "GenerateHeightmap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVoxelHeightmapImport_NoRegister()
	{
		return UVoxelHeightmapImport::StaticClass();
	}
	struct Z_Construct_UClass_UVoxelHeightmapImport_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextureImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TextureImage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVoxelHeightmapImport_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVoxelHeightmapImport_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVoxelHeightmapImport_GenerateHeightmap, "GenerateHeightmap" }, // 3046632938
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapImport_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Importers/VoxelHeightmapImport.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Importers/VoxelHeightmapImport.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_TextureImage_MetaData[] = {
		{ "Category", "Importer" },
		{ "ModuleRelativePath", "Public/Importers/VoxelHeightmapImport.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_TextureImage = { UE4CodeGen_Private::EPropertyClass::Object, "TextureImage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapImport, TextureImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_TextureImage_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_TextureImage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_World_MetaData[] = {
		{ "Category", "Importer" },
		{ "ModuleRelativePath", "Public/Importers/VoxelHeightmapImport.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UVoxelHeightmapImport, World), Z_Construct_UClass_AVoxelLandscape_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_World_MetaData, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_World_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVoxelHeightmapImport_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_TextureImage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVoxelHeightmapImport_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVoxelHeightmapImport_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVoxelHeightmapImport>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVoxelHeightmapImport_Statics::ClassParams = {
		&UVoxelHeightmapImport::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001010A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UVoxelHeightmapImport_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapImport_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVoxelHeightmapImport_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVoxelHeightmapImport_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVoxelHeightmapImport()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVoxelHeightmapImport_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVoxelHeightmapImport, 4058733653);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVoxelHeightmapImport(Z_Construct_UClass_UVoxelHeightmapImport, &UVoxelHeightmapImport::StaticClass, TEXT("/Script/VoxelArt"), TEXT("UVoxelHeightmapImport"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVoxelHeightmapImport);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
