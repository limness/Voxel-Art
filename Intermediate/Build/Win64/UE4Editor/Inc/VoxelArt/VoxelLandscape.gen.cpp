// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/VoxelLandscape.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelLandscape() {}
// Cross Module References
	VOXELART_API UEnum* Z_Construct_UEnum_VoxelArt_RenderTexture();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelLandscape();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_UpdateWorld();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	static UEnum* RenderTexture_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VoxelArt_RenderTexture, Z_Construct_UPackage__Script_VoxelArt(), TEXT("RenderTexture"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_RenderTexture(RenderTexture_StaticEnum, TEXT("/Script/VoxelArt"), TEXT("RenderTexture"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VoxelArt_RenderTexture_CRC() { return 3274260962U; }
	UEnum* Z_Construct_UEnum_VoxelArt_RenderTexture()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelArt();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("RenderTexture"), 0, Get_Z_Construct_UEnum_VoxelArt_RenderTexture_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "WhiteBlack", (int64)WhiteBlack },
				{ "RedGreenBlue", (int64)RedGreenBlue },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
				{ "RedGreenBlue.DisplayName", "RGB" },
				{ "WhiteBlack.DisplayName", "WB" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VoxelArt,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"RenderTexture",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::Regular,
				"RenderTexture",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AVoxelLandscape::StaticRegisterNativesAVoxelLandscape()
	{
		UClass* Class = AVoxelLandscape::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateTextureDensityMap", &AVoxelLandscape::execCreateTextureDensityMap },
			{ "CreateVoxelWorld", &AVoxelLandscape::execCreateVoxelWorld },
			{ "DestroyVoxelWorld", &AVoxelLandscape::execDestroyVoxelWorld },
			{ "UpdateWorld", &AVoxelLandscape::execUpdateWorld },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "CreateTextureDensityMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "CreateVoxelWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "DestroyVoxelWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "UpdateWorld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_UpdateWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_UpdateWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVoxelLandscape_NoRegister()
	{
		return AVoxelLandscape::StaticClass();
	}
	struct Z_Construct_UClass_AVoxelLandscape_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RenderType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_RenderType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DirectoryName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DirectoryName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratorDensity_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratorDensity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshTree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshTree;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NormalsSmoothing_MetaData[];
#endif
		static void NewProp_NormalsSmoothing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_NormalsSmoothing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexSubdivision_MetaData[];
#endif
		static void NewProp_VertexSubdivision_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_VertexSubdivision;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunksPerFrame_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ChunksPerFrame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaximumLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimumLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinimumLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawingRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DrawingRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnabledLOD_MetaData[];
#endif
		static void NewProp_EnabledLOD_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnabledLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TerrainCreated_MetaData[];
#endif
		static void NewProp_TerrainCreated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TerrainCreated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TransitionSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionMesh_MetaData[];
#endif
		static void NewProp_TransitionMesh_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TransitionMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelsPerChunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_VoxelsPerChunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WorldSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelMin_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_VoxelMin;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnabledWorldInGame_MetaData[];
#endif
		static void NewProp_EnabledWorldInGame_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnabledWorldInGame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratorLandscape_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GeneratorLandscape;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelLandscape_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelLandscape_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap, "CreateTextureDensityMap" }, // 2744335584
		{ &Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld, "CreateVoxelWorld" }, // 474152906
		{ &Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld, "DestroyVoxelWorld" }, // 1493059625
		{ &Z_Construct_UFunction_AVoxelLandscape_UpdateWorld, "UpdateWorld" }, // 985876392
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelLandscape.h" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldComponent_MetaData[] = {
		{ "Category", "VoxelLandscape" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldComponent = { UE4CodeGen_Private::EPropertyClass::Object, "WorldComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001000000009001d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, WorldComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType_MetaData[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType = { UE4CodeGen_Private::EPropertyClass::Byte, "RenderType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, RenderType), Z_Construct_UEnum_VoxelArt_RenderTexture, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize_MetaData[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize = { UE4CodeGen_Private::EPropertyClass::Int, "MapSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, MapSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName_MetaData[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName = { UE4CodeGen_Private::EPropertyClass::Str, "DirectoryName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, DirectoryName), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName_MetaData[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName = { UE4CodeGen_Private::EPropertyClass::Str, "MapName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, MapName), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity_MetaData[] = {
		{ "Category", "Export Preview Heightmap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratorDensity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001200000008000d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, GeneratorDensity), Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MeshTree_MetaData[] = {
		{ "Category", "Foliage" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MeshTree = { UE4CodeGen_Private::EPropertyClass::Object, "MeshTree", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, MeshTree), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MeshTree_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MeshTree_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing_MetaData[] = {
		{ "Category", "Rendering" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->NormalsSmoothing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing = { UE4CodeGen_Private::EPropertyClass::Bool, "NormalsSmoothing", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision_MetaData[] = {
		{ "Category", "Rendering" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->VertexSubdivision = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision = { UE4CodeGen_Private::EPropertyClass::Bool, "VertexSubdivision", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData[] = {
		{ "Category", "Rendering" },
		{ "ClampMax", "2048" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "2048" },
		{ "UIMin", "1" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame = { UE4CodeGen_Private::EPropertyClass::Int, "ChunksPerFrame", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, ChunksPerFrame), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MaximumLOD_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ClampMax", "15" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "15" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MaximumLOD = { UE4CodeGen_Private::EPropertyClass::Int, "MaximumLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, MaximumLOD), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MaximumLOD_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MaximumLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MinimumLOD_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ClampMax", "15" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "15" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MinimumLOD = { UE4CodeGen_Private::EPropertyClass::Int, "MinimumLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, MinimumLOD), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MinimumLOD_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MinimumLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DrawingRange_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DrawingRange = { UE4CodeGen_Private::EPropertyClass::Byte, "DrawingRange", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, DrawingRange), nullptr, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DrawingRange_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DrawingRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->EnabledLOD = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD = { UE4CodeGen_Private::EPropertyClass::Bool, "EnabledLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData[] = {
		{ "Category", "VoxelLandscape" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->TerrainCreated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated = { UE4CodeGen_Private::EPropertyClass::Bool, "TerrainCreated", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionSize_MetaData[] = {
		{ "Category", "Main" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionSize = { UE4CodeGen_Private::EPropertyClass::Float, "TransitionSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, TransitionSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh_MetaData[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->TransitionMesh = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh = { UE4CodeGen_Private::EPropertyClass::Bool, "TransitionMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_Material = { UE4CodeGen_Private::EPropertyClass::Object, "Material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_Material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelsPerChunk_MetaData[] = {
		{ "Category", "Main" },
		{ "ClampMax", "32" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "32" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelsPerChunk = { UE4CodeGen_Private::EPropertyClass::Int, "VoxelsPerChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, VoxelsPerChunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelsPerChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelsPerChunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldSize_MetaData[] = {
		{ "Category", "Main" },
		{ "ClampMax", "524288" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "524288" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldSize = { UE4CodeGen_Private::EPropertyClass::Int, "WorldSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, WorldSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelMin_MetaData[] = {
		{ "Category", "Main" },
		{ "ClampMax", "524288" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
		{ "UIMax", "524288" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelMin = { UE4CodeGen_Private::EPropertyClass::Int, "VoxelMin", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, VoxelMin), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelMin_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelMin_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame_MetaData[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->EnabledWorldInGame = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame = { UE4CodeGen_Private::EPropertyClass::Bool, "EnabledWorldInGame", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorLandscape_MetaData[] = {
		{ "Category", "Main" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorLandscape = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratorLandscape", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001200000008000d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, GeneratorLandscape), Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorLandscape_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorLandscape_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelLandscape_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MeshTree,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_NormalsSmoothing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VertexSubdivision,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MaximumLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MinimumLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DrawingRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelsPerChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_WorldSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_VoxelMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_EnabledWorldInGame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorLandscape,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoxelLandscape_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoxelLandscape>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVoxelLandscape_Statics::ClassParams = {
		&AVoxelLandscape::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVoxelLandscape_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoxelLandscape()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVoxelLandscape_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelLandscape, 3404956196);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelLandscape(Z_Construct_UClass_AVoxelLandscape, &AVoxelLandscape::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelLandscape"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelLandscape);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
