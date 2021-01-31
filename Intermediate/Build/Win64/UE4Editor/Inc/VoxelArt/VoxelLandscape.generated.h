// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FColor;
#ifdef VOXELART_VoxelLandscape_generated_h
#error "VoxelLandscape.generated.h already included, missing '#pragma once' in VoxelLandscape.h"
#endif
#define VOXELART_VoxelLandscape_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateOctree) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateOctree(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnBoxTest) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_width); \
		P_GET_STRUCT(FColor,Z_Param_color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SpawnBoxTest(Z_Param_location,Z_Param_radius,Z_Param_width,Z_Param_color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateLandscape) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateLandscape(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateTextureDensityMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateTextureDensityMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DestroyVoxelWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateVoxelWorld(); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateOctree) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateOctree(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnBoxTest) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_width); \
		P_GET_STRUCT(FColor,Z_Param_color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SpawnBoxTest(Z_Param_location,Z_Param_radius,Z_Param_width,Z_Param_color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateLandscape) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateLandscape(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateTextureDensityMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateTextureDensityMap(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DestroyVoxelWorld(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateVoxelWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CreateVoxelWorld(); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelLandscape(); \
	friend struct Z_Construct_UClass_AVoxelLandscape_Statics; \
public: \
	DECLARE_CLASS(AVoxelLandscape, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelLandscape(); \
	friend struct Z_Construct_UClass_AVoxelLandscape_Statics; \
public: \
	DECLARE_CLASS(AVoxelLandscape, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelLandscape(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelLandscape) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelLandscape); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelLandscape); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelLandscape(AVoxelLandscape&&); \
	NO_API AVoxelLandscape(const AVoxelLandscape&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelLandscape(AVoxelLandscape&&); \
	NO_API AVoxelLandscape(const AVoxelLandscape&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelLandscape); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelLandscape); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_40_PROLOG
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h_43_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelLandscape_h


#define FOREACH_ENUM_RENDERTEXTURE(op) \
	op(WhiteBlack) \
	op(RedGreenBlack) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
