// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelArt/Public/Octree/VoxelOctreeData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelOctreeData() {}
// Cross Module References
	VOXELART_API UScriptStruct* Z_Construct_UScriptStruct_FChunksRenderInfo();
	UPackage* Z_Construct_UPackage__Script_VoxelArt();
// End Cross Module References
class UScriptStruct* FChunksRenderInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VOXELART_API uint32 Get_Z_Construct_UScriptStruct_FChunksRenderInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FChunksRenderInfo, Z_Construct_UPackage__Script_VoxelArt(), TEXT("ChunksRenderInfo"), sizeof(FChunksRenderInfo), Get_Z_Construct_UScriptStruct_FChunksRenderInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FChunksRenderInfo(FChunksRenderInfo::StaticStruct, TEXT("/Script/VoxelArt"), TEXT("ChunksRenderInfo"), false, nullptr, nullptr);
static struct FScriptStruct_VoxelArt_StaticRegisterNativesFChunksRenderInfo
{
	FScriptStruct_VoxelArt_StaticRegisterNativesFChunksRenderInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ChunksRenderInfo")),new UScriptStruct::TCppStructOps<FChunksRenderInfo>);
	}
} ScriptStruct_VoxelArt_StaticRegisterNativesFChunksRenderInfo;
	struct Z_Construct_UScriptStruct_FChunksRenderInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Octree/VoxelOctreeData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChunksRenderInfo>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelArt,
		nullptr,
		&NewStructOps,
		"ChunksRenderInfo",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FChunksRenderInfo),
		alignof(FChunksRenderInfo),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FChunksRenderInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FChunksRenderInfo_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VoxelArt();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ChunksRenderInfo"), sizeof(FChunksRenderInfo), Get_Z_Construct_UScriptStruct_FChunksRenderInfo_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FChunksRenderInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FChunksRenderInfo_CRC() { return 1731919308U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
