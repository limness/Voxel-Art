// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FLinearColor;
#ifdef VOXELART_VoxelChunkTransvoxels_generated_h
#error "VoxelChunkTransvoxels.generated.h already included, missing '#pragma once' in VoxelChunkTransvoxels.h"
#endif
#define VOXELART_VoxelChunkTransvoxels_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execVertexInterp) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_P1); \
		P_GET_STRUCT(FVector,Z_Param_P2); \
		P_GET_STRUCT(FVector,Z_Param_N1); \
		P_GET_STRUCT(FVector,Z_Param_N2); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P1Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P2Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_normalInst); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->VertexInterp(Z_Param_P1,Z_Param_P2,Z_Param_N1,Z_Param_N2,Z_Param_P1Val,Z_Param_P2Val,Z_Param_Value,Z_Param_Out_normalInst); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execVertexInterpTransition) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_P1); \
		P_GET_STRUCT(FVector,Z_Param_P2); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P1Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P2Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->VertexInterpTransition(Z_Param_P1,Z_Param_P2,Z_Param_P1Val,Z_Param_P2Val,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValueNoise) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_positionGrid); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetValueNoise(Z_Param_positionGrid); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateMesh) \
	{ \
		P_GET_TARRAY(FVector,Z_Param_Vert); \
		P_GET_TARRAY(int32,Z_Param_Tri); \
		P_GET_TARRAY(FVector,Z_Param_Norm); \
		P_GET_TARRAY(FLinearColor,Z_Param_Cols); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateMesh(Z_Param_Vert,Z_Param_Tri,Z_Param_Norm,Z_Param_Cols); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSizeHalf) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSizeHalf(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelId) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_posX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_posY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_posZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVoxelId(Z_Param_posX,Z_Param_posY,Z_Param_posZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMarchingCubes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_isolevel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_indexGrid); \
		P_GET_PROPERTY(UIntProperty,Z_Param_x); \
		P_GET_PROPERTY(UIntProperty,Z_Param_y); \
		P_GET_PROPERTY(UIntProperty,Z_Param_z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_normalIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MarchingCubes(Z_Param_isolevel,Z_Param_indexGrid,Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_normalIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateVertexCube) \
	{ \
		P_GET_UBOOL(Z_Param_regenerate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateVertexCube(Z_Param_regenerate); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execVertexInterp) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_P1); \
		P_GET_STRUCT(FVector,Z_Param_P2); \
		P_GET_STRUCT(FVector,Z_Param_N1); \
		P_GET_STRUCT(FVector,Z_Param_N2); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P1Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P2Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_normalInst); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->VertexInterp(Z_Param_P1,Z_Param_P2,Z_Param_N1,Z_Param_N2,Z_Param_P1Val,Z_Param_P2Val,Z_Param_Value,Z_Param_Out_normalInst); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execVertexInterpTransition) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_P1); \
		P_GET_STRUCT(FVector,Z_Param_P2); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P1Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_P2Val); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->VertexInterpTransition(Z_Param_P1,Z_Param_P2,Z_Param_P1Val,Z_Param_P2Val,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValueNoise) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_positionGrid); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetValueNoise(Z_Param_positionGrid); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateMesh) \
	{ \
		P_GET_TARRAY(FVector,Z_Param_Vert); \
		P_GET_TARRAY(int32,Z_Param_Tri); \
		P_GET_TARRAY(FVector,Z_Param_Norm); \
		P_GET_TARRAY(FLinearColor,Z_Param_Cols); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateMesh(Z_Param_Vert,Z_Param_Tri,Z_Param_Norm,Z_Param_Cols); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSizeHalf) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSizeHalf(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetVoxelSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVoxelId) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_posX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_posY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_posZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVoxelId(Z_Param_posX,Z_Param_posY,Z_Param_posZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMarchingCubes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_isolevel); \
		P_GET_PROPERTY(UIntProperty,Z_Param_indexGrid); \
		P_GET_PROPERTY(UIntProperty,Z_Param_x); \
		P_GET_PROPERTY(UIntProperty,Z_Param_y); \
		P_GET_PROPERTY(UIntProperty,Z_Param_z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_normalIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MarchingCubes(Z_Param_isolevel,Z_Param_indexGrid,Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_normalIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateVertexCube) \
	{ \
		P_GET_UBOOL(Z_Param_regenerate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateVertexCube(Z_Param_regenerate); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelChunkTransvoxels(); \
	friend struct Z_Construct_UClass_AVoxelChunkTransvoxels_Statics; \
public: \
	DECLARE_CLASS(AVoxelChunkTransvoxels, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelChunkTransvoxels)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelChunkTransvoxels(); \
	friend struct Z_Construct_UClass_AVoxelChunkTransvoxels_Statics; \
public: \
	DECLARE_CLASS(AVoxelChunkTransvoxels, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelChunkTransvoxels)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelChunkTransvoxels(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelChunkTransvoxels) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelChunkTransvoxels); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelChunkTransvoxels); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelChunkTransvoxels(AVoxelChunkTransvoxels&&); \
	NO_API AVoxelChunkTransvoxels(const AVoxelChunkTransvoxels&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelChunkTransvoxels(AVoxelChunkTransvoxels&&); \
	NO_API AVoxelChunkTransvoxels(const AVoxelChunkTransvoxels&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelChunkTransvoxels); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelChunkTransvoxels); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelChunkTransvoxels)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_15_PROLOG
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelChunkTransvoxels_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
