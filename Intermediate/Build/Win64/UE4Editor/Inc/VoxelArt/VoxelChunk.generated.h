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
class UVoxelModificationLandscape;
#ifdef VOXELART_VoxelChunk_generated_h
#error "VoxelChunk.generated.h already included, missing '#pragma once' in VoxelChunk.h"
#endif
#define VOXELART_VoxelChunk_generated_h

#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_RPC_WRAPPERS \
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
	DECLARE_FUNCTION(execChangeVoxel) \
	{ \
		P_GET_OBJECT(UVoxelModificationLandscape,Z_Param_modificator); \
		P_GET_STRUCT(FVector,Z_Param_positionCenterPoint); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_strength); \
		P_GET_UBOOL(Z_Param_smooth); \
		P_GET_UBOOL(Z_Param_dig); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_smoothInsert); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ChangeVoxel(Z_Param_modificator,Z_Param_positionCenterPoint,Z_Param_range,Z_Param_strength,Z_Param_smooth,Z_Param_dig,Z_Param_smoothInsert); \
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
	} \
 \
	DECLARE_FUNCTION(execGenerateDensityMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateDensityMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateDensityAndCreateMeshAsync) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateDensityAndCreateMeshAsync(); \
		P_NATIVE_END; \
	}


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
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
	DECLARE_FUNCTION(execChangeVoxel) \
	{ \
		P_GET_OBJECT(UVoxelModificationLandscape,Z_Param_modificator); \
		P_GET_STRUCT(FVector,Z_Param_positionCenterPoint); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_strength); \
		P_GET_UBOOL(Z_Param_smooth); \
		P_GET_UBOOL(Z_Param_dig); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_smoothInsert); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ChangeVoxel(Z_Param_modificator,Z_Param_positionCenterPoint,Z_Param_range,Z_Param_strength,Z_Param_smooth,Z_Param_dig,Z_Param_smoothInsert); \
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
	} \
 \
	DECLARE_FUNCTION(execGenerateDensityMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateDensityMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateDensityAndCreateMeshAsync) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateDensityAndCreateMeshAsync(); \
		P_NATIVE_END; \
	}


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelChunk(); \
	friend struct Z_Construct_UClass_AVoxelChunk_Statics; \
public: \
	DECLARE_CLASS(AVoxelChunk, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelChunk)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelChunk(); \
	friend struct Z_Construct_UClass_AVoxelChunk_Statics; \
public: \
	DECLARE_CLASS(AVoxelChunk, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelChunk)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelChunk(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelChunk) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelChunk); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelChunk); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelChunk(AVoxelChunk&&); \
	NO_API AVoxelChunk(const AVoxelChunk&); \
public:


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelChunk(AVoxelChunk&&); \
	NO_API AVoxelChunk(const AVoxelChunk&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelChunk); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelChunk); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelChunk)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_PRIVATE_PROPERTY_OFFSET
#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_28_PROLOG
#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_PRIVATE_PROPERTY_OFFSET \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_RPC_WRAPPERS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_INCLASS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_PRIVATE_PROPERTY_OFFSET \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_INCLASS_NO_PURE_DECLS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_VoxelChunk_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
