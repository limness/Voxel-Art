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
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VOXELART_API UFunction* Z_Construct_UFunction_AVoxelLandscape_UpdateOctree();
	VOXELART_API UClass* Z_Construct_UClass_AVoxelChunk_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	VOXELART_API UClass* Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
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
	uint32 Get_Z_Construct_UEnum_VoxelArt_RenderTexture_CRC() { return 2451854205U; }
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
				{ "RedGreenBlack", (int64)RedGreenBlack },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
				{ "RedGreenBlack.DisplayName", "RGB" },
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
			{ "GenerateLandscape", &AVoxelLandscape::execGenerateLandscape },
			{ "SpawnBoxTest", &AVoxelLandscape::execSpawnBoxTest },
			{ "UpdateOctree", &AVoxelLandscape::execUpdateOctree },
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
		{ "CallInEditor", "true" },
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
		{ "CallInEditor", "true" },
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
		{ "CallInEditor", "true" },
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
	struct Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "GenerateLandscape", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics
	{
		struct VoxelLandscape_eventSpawnBoxTest_Parms
		{
			FVector location;
			float radius;
			float width;
			FColor color;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_color;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_width;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_location;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_color = { UE4CodeGen_Private::EPropertyClass::Struct, "color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscape_eventSpawnBoxTest_Parms, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_width = { UE4CodeGen_Private::EPropertyClass::Float, "width", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscape_eventSpawnBoxTest_Parms, width), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_radius = { UE4CodeGen_Private::EPropertyClass::Float, "radius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscape_eventSpawnBoxTest_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_location = { UE4CodeGen_Private::EPropertyClass::Struct, "location", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VoxelLandscape_eventSpawnBoxTest_Parms, location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::NewProp_location,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "SpawnBoxTest", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04840401, sizeof(VoxelLandscape_eventSpawnBoxTest_Parms), Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVoxelLandscape, "UpdateOctree", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVoxelLandscape_UpdateOctree()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVoxelLandscape_UpdateOctree_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_kost_MetaData[];
#endif
		static void NewProp_kost_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_kost;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chungz_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_chungz;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_chungz_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_meshTree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_meshTree;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radiusSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_period_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_period;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_actave_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_actave;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_grass_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_grass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ground_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ground;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_normalsSmoothing_MetaData[];
#endif
		static void NewProp_normalsSmoothing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_normalsSmoothing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_vertexSubdivision_MetaData[];
#endif
		static void NewProp_vertexSubdivision_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_vertexSubdivision;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunksPerFrame_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ChunksPerFrame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_distanceRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_distanceRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maximumLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_maximumLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_minimumLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_minimumLOD;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LODWorking_MetaData[];
#endif
		static void NewProp_LODWorking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LODWorking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_voxelsOneChunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_voxelsOneChunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radiusOfChunk_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusOfChunk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_work_MetaData[];
#endif
		static void NewProp_work_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_work;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_moveBit_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_moveBit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_nodeID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_nodeID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transitionSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_transitionSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionWorking_MetaData[];
#endif
		static void NewProp_TransitionWorking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TransitionWorking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_generatorLandscape_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_generatorLandscape;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TerrainCreated_MetaData[];
#endif
		static void NewProp_TerrainCreated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TerrainCreated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TerrainRendering_MetaData[];
#endif
		static void NewProp_TerrainRendering_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TerrainRendering;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoxelLandscape_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVoxelLandscape_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVoxelLandscape_CreateTextureDensityMap, "CreateTextureDensityMap" }, // 2299629249
		{ &Z_Construct_UFunction_AVoxelLandscape_CreateVoxelWorld, "CreateVoxelWorld" }, // 3986220376
		{ &Z_Construct_UFunction_AVoxelLandscape_DestroyVoxelWorld, "DestroyVoxelWorld" }, // 1880527
		{ &Z_Construct_UFunction_AVoxelLandscape_GenerateLandscape, "GenerateLandscape" }, // 3877668133
		{ &Z_Construct_UFunction_AVoxelLandscape_SpawnBoxTest, "SpawnBoxTest" }, // 4119755179
		{ &Z_Construct_UFunction_AVoxelLandscape_UpdateOctree, "UpdateOctree" }, // 2746986071
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoxelLandscape.h" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->kost = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost = { UE4CodeGen_Private::EPropertyClass::Bool, "kost", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz_MetaData[] = {
		{ "Category", "VoxelLandscape" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz = { UE4CodeGen_Private::EPropertyClass::Array, "chungz", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010015, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, chungz), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "chungz", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AVoxelChunk_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_material_MetaData[] = {
		{ "Category", "VoxelLandscape" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_material = { UE4CodeGen_Private::EPropertyClass::Object, "material", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_material_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "VoxelLandscape" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_SceneComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SceneComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001000000009001d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_SceneComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_SceneComponent_MetaData)) };
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
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Importer\")\nint StepTexture;" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity = { UE4CodeGen_Private::EPropertyClass::Object, "GeneratorDensity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001200000008000d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, GeneratorDensity), Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_meshTree_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_meshTree = { UE4CodeGen_Private::EPropertyClass::Object, "meshTree", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, meshTree), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_meshTree_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_meshTree_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusSphere_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusSphere = { UE4CodeGen_Private::EPropertyClass::Float, "radiusSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, radiusSphere), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_period_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_period = { UE4CodeGen_Private::EPropertyClass::Float, "period", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, period), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_period_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_period_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_actave_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_actave = { UE4CodeGen_Private::EPropertyClass::Float, "actave", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, actave), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_actave_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_actave_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_grass_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_grass = { UE4CodeGen_Private::EPropertyClass::Struct, "grass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, grass), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_grass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_grass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ground_MetaData[] = {
		{ "Category", "Layes" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ground = { UE4CodeGen_Private::EPropertyClass::Struct, "ground", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, ground), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ground_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ground_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->normalsSmoothing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing = { UE4CodeGen_Private::EPropertyClass::Bool, "normalsSmoothing", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->vertexSubdivision = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision = { UE4CodeGen_Private::EPropertyClass::Bool, "vertexSubdivision", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame = { UE4CodeGen_Private::EPropertyClass::Int, "ChunksPerFrame", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, ChunksPerFrame), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_distanceRadius_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_distanceRadius = { UE4CodeGen_Private::EPropertyClass::Float, "distanceRadius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, distanceRadius), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_distanceRadius_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_distanceRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_maximumLOD_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_maximumLOD = { UE4CodeGen_Private::EPropertyClass::Int, "maximumLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, maximumLOD), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_maximumLOD_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_maximumLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_minimumLOD_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_minimumLOD = { UE4CodeGen_Private::EPropertyClass::Int, "minimumLOD", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, minimumLOD), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_minimumLOD_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_minimumLOD_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->LODWorking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking = { UE4CodeGen_Private::EPropertyClass::Bool, "LODWorking", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_voxelsOneChunk_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_voxelsOneChunk = { UE4CodeGen_Private::EPropertyClass::Int, "voxelsOneChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, voxelsOneChunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_voxelsOneChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_voxelsOneChunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusOfChunk_MetaData[] = {
		{ "Category", "Size" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusOfChunk = { UE4CodeGen_Private::EPropertyClass::Float, "radiusOfChunk", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, radiusOfChunk), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusOfChunk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusOfChunk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work_MetaData[] = {
		{ "Category", "NeighborTest" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->work = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work = { UE4CodeGen_Private::EPropertyClass::Bool, "work", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_moveBit_MetaData[] = {
		{ "Category", "NeighborTest" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_moveBit = { UE4CodeGen_Private::EPropertyClass::Byte, "moveBit", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, moveBit), nullptr, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_moveBit_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_moveBit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_nodeID_MetaData[] = {
		{ "Category", "NeighborTest" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_nodeID = { UE4CodeGen_Private::EPropertyClass::Int, "nodeID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, nodeID), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_nodeID_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_nodeID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_transitionSize_MetaData[] = {
		{ "Category", "Transition Mesh" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_transitionSize = { UE4CodeGen_Private::EPropertyClass::Float, "transitionSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, transitionSize), METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_transitionSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_transitionSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking_MetaData[] = {
		{ "Category", "Level of Detail" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->TransitionWorking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking = { UE4CodeGen_Private::EPropertyClass::Bool, "TransitionWorking", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_generatorLandscape_MetaData[] = {
		{ "Category", "Main" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_generatorLandscape = { UE4CodeGen_Private::EPropertyClass::Object, "generatorLandscape", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x001200000008000d, 1, nullptr, STRUCT_OFFSET(AVoxelLandscape, generatorLandscape), Z_Construct_UClass_UVoxelLandscapeGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_generatorLandscape_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_generatorLandscape_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->TerrainCreated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated = { UE4CodeGen_Private::EPropertyClass::Bool, "TerrainCreated", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000010015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering_MetaData[] = {
		{ "Category", "Main" },
		{ "ModuleRelativePath", "Public/VoxelLandscape.h" },
	};
#endif
	void Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering_SetBit(void* Obj)
	{
		((AVoxelLandscape*)Obj)->TerrainRendering = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering = { UE4CodeGen_Private::EPropertyClass::Bool, "TerrainRendering", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AVoxelLandscape), &Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering_SetBit, METADATA_PARAMS(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVoxelLandscape_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_kost,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_chungz_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_SceneComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_RenderType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_DirectoryName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_MapName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_GeneratorDensity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_meshTree,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_period,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_actave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_grass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ground,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_normalsSmoothing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_vertexSubdivision,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_ChunksPerFrame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_distanceRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_maximumLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_minimumLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_LODWorking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_voxelsOneChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_radiusOfChunk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_work,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_moveBit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_nodeID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_transitionSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TransitionWorking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_generatorLandscape,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainCreated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVoxelLandscape_Statics::NewProp_TerrainRendering,
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
	IMPLEMENT_CLASS(AVoxelLandscape, 3070769214);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelLandscape(Z_Construct_UClass_AVoxelLandscape, &AVoxelLandscape::StaticClass, TEXT("/Script/VoxelArt"), TEXT("AVoxelLandscape"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelLandscape);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
