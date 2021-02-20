// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXELART_SimplexNoiseBPLibrary_generated_h
#error "SimplexNoiseBPLibrary.generated.h already included, missing '#pragma once' in SimplexNoiseBPLibrary.h"
#endif
#define VOXELART_SimplexNoiseBPLibrary_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange2D(Z_Param_x,Z_Param_y,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange1D(Z_Param_x,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled2D(Z_Param_x,Z_Param_y,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled1D(Z_Param_x,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise3D(Z_Param_x,Z_Param_y,Z_Param_z); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise2D(Z_Param_x,Z_Param_y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise1D(Z_Param_x); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetNoiseSeed) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_newSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USimplexNoiseBPLibrary::setNoiseSeed(Z_Param_Out_newSeed); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange2D(Z_Param_x,Z_Param_y,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseInRange1D(Z_Param_x,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled2D(Z_Param_x,Z_Param_y,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoiseScaled1D(Z_Param_x,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise3D(Z_Param_x,Z_Param_y,Z_Param_z); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise2D(Z_Param_x,Z_Param_y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseBPLibrary::SimplexNoise1D(Z_Param_x); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetNoiseSeed) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_newSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USimplexNoiseBPLibrary::setNoiseSeed(Z_Param_Out_newSeed); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSimplexNoiseBPLibrary(); \
	friend struct Z_Construct_UClass_USimplexNoiseBPLibrary_Statics; \
public: \
	DECLARE_CLASS(USimplexNoiseBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(USimplexNoiseBPLibrary)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUSimplexNoiseBPLibrary(); \
	friend struct Z_Construct_UClass_USimplexNoiseBPLibrary_Statics; \
public: \
	DECLARE_CLASS(USimplexNoiseBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(USimplexNoiseBPLibrary)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimplexNoiseBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimplexNoiseBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimplexNoiseBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimplexNoiseBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USimplexNoiseBPLibrary(USimplexNoiseBPLibrary&&); \
	NO_API USimplexNoiseBPLibrary(const USimplexNoiseBPLibrary&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimplexNoiseBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USimplexNoiseBPLibrary(USimplexNoiseBPLibrary&&); \
	NO_API USimplexNoiseBPLibrary(const USimplexNoiseBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimplexNoiseBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimplexNoiseBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimplexNoiseBPLibrary)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_12_PROLOG
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SimplexNoiseBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Private_Noise_SimplexNoiseBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
