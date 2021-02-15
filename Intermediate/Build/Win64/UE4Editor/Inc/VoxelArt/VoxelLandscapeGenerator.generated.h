// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FVector2D;
#ifdef VOXELART_VoxelLandscapeGenerator_generated_h
#error "VoxelLandscapeGenerator.generated.h already included, missing '#pragma once' in VoxelLandscapeGenerator.h"
#endif
#define VOXELART_VoxelLandscapeGenerator_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execVectorDistanceAB) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_A); \
		P_GET_STRUCT(FVector,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->VectorDistanceAB(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_seed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SimplexNoise(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_seed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCone) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_p); \
		P_GET_STRUCT(FVector2D,Z_Param_c); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_h); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->Cone(Z_Param_p,Z_Param_c,Z_Param_h); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIQNoise) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_p); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->IQNoise(Z_Param_p); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFractalNoise) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_seed); \
		P_GET_PROPERTY(UIntProperty,Z_Param_octaves); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_amplitude); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_frequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->FractalNoise(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_seed,Z_Param_octaves,Z_Param_amplitude,Z_Param_frequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTorusLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radiusInside); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->TorusLandscape(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius,Z_Param_radiusInside); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSphereLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SphereLandscape(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFlatLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->FlatLandscape(Z_Param_A); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execVectorDistanceAB) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_A); \
		P_GET_STRUCT(FVector,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->VectorDistanceAB(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_seed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SimplexNoise(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_seed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCone) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_p); \
		P_GET_STRUCT(FVector2D,Z_Param_c); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_h); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->Cone(Z_Param_p,Z_Param_c,Z_Param_h); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIQNoise) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_p); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->IQNoise(Z_Param_p); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFractalNoise) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UIntProperty,Z_Param_seed); \
		P_GET_PROPERTY(UIntProperty,Z_Param_octaves); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_amplitude); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_frequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->FractalNoise(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_seed,Z_Param_octaves,Z_Param_amplitude,Z_Param_frequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTorusLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radiusInside); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->TorusLandscape(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius,Z_Param_radiusInside); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSphereLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SphereLandscape(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFlatLandscape) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->FlatLandscape(Z_Param_A); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelLandscapeGenerator(); \
	friend struct Z_Construct_UClass_UVoxelLandscapeGenerator_Statics; \
public: \
	DECLARE_CLASS(UVoxelLandscapeGenerator, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelLandscapeGenerator)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelLandscapeGenerator(); \
	friend struct Z_Construct_UClass_UVoxelLandscapeGenerator_Statics; \
public: \
	DECLARE_CLASS(UVoxelLandscapeGenerator, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelLandscapeGenerator)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelLandscapeGenerator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelLandscapeGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelLandscapeGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelLandscapeGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelLandscapeGenerator(UVoxelLandscapeGenerator&&); \
	NO_API UVoxelLandscapeGenerator(const UVoxelLandscapeGenerator&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelLandscapeGenerator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelLandscapeGenerator(UVoxelLandscapeGenerator&&); \
	NO_API UVoxelLandscapeGenerator(const UVoxelLandscapeGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelLandscapeGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelLandscapeGenerator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelLandscapeGenerator)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_13_PROLOG
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h_16_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class VoxelLandscapeGenerator."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Renders_VoxelLandscapeGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
