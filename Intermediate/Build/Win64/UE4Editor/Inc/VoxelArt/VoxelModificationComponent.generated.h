// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AVoxelLandscape;
class AVoxelChunk;
struct FVector;
#ifdef VOXELART_VoxelModificationComponent_generated_h
#error "VoxelModificationComponent.generated.h already included, missing '#pragma once' in VoxelModificationComponent.h"
#endif
#define VOXELART_VoxelModificationComponent_generated_h

#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execModification) \
	{ \
		P_GET_OBJECT(AVoxelLandscape,Z_Param_terrain); \
		P_GET_OBJECT(AVoxelChunk,Z_Param_chunkCenter); \
		P_GET_STRUCT(FVector,Z_Param_position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Modification(Z_Param_terrain,Z_Param_chunkCenter,Z_Param_position,Z_Param_range); \
		P_NATIVE_END; \
	}


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execModification) \
	{ \
		P_GET_OBJECT(AVoxelLandscape,Z_Param_terrain); \
		P_GET_OBJECT(AVoxelChunk,Z_Param_chunkCenter); \
		P_GET_STRUCT(FVector,Z_Param_position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Modification(Z_Param_terrain,Z_Param_chunkCenter,Z_Param_position,Z_Param_range); \
		P_NATIVE_END; \
	}


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelModificationComponent(); \
	friend struct Z_Construct_UClass_UVoxelModificationComponent_Statics; \
public: \
	DECLARE_CLASS(UVoxelModificationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelModificationComponent)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelModificationComponent(); \
	friend struct Z_Construct_UClass_UVoxelModificationComponent_Statics; \
public: \
	DECLARE_CLASS(UVoxelModificationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelModificationComponent)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelModificationComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelModificationComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelModificationComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelModificationComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelModificationComponent(UVoxelModificationComponent&&); \
	NO_API UVoxelModificationComponent(const UVoxelModificationComponent&); \
public:


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelModificationComponent(UVoxelModificationComponent&&); \
	NO_API UVoxelModificationComponent(const UVoxelModificationComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelModificationComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelModificationComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVoxelModificationComponent)


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_PRIVATE_PROPERTY_OFFSET
#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_13_PROLOG
#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_RPC_WRAPPERS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_INCLASS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_INCLASS_NO_PURE_DECLS \
	Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Voxel_Plugins_Voxel_Art_Source_VoxelArt_Public_Editor_VoxelModificationComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
