// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXELART_VoxelModificationLandscape_generated_h
#error "VoxelModificationLandscape.generated.h already included, missing '#pragma once' in VoxelModificationLandscape.h"
#endif
#define VOXELART_VoxelModificationLandscape_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBangPainter) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UIntProperty,Z_Param_octaves); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_amplitude); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_frequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->BangPainter(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius,Z_Param_octaves,Z_Param_amplitude,Z_Param_frequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpherePainter) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SpherePainter(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBangPainter) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_GET_PROPERTY(UIntProperty,Z_Param_octaves); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_amplitude); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_frequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->BangPainter(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius,Z_Param_octaves,Z_Param_amplitude,Z_Param_frequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpherePainter) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_radius); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->SpherePainter(Z_Param_X,Z_Param_Y,Z_Param_Z,Z_Param_radius); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_EVENT_PARMS \
	struct VoxelModificationLandscape_eventGetPainterData_Parms \
	{ \
		float X; \
		float Y; \
		float Z; \
		float noise; \
		float strength; \
		bool dig; \
		bool smooth; \
	};


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_CALLBACK_WRAPPERS
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVoxelModificationLandscape(); \
	friend struct Z_Construct_UClass_UVoxelModificationLandscape_Statics; \
public: \
	DECLARE_CLASS(UVoxelModificationLandscape, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelModificationLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUVoxelModificationLandscape(); \
	friend struct Z_Construct_UClass_UVoxelModificationLandscape_Statics; \
public: \
	DECLARE_CLASS(UVoxelModificationLandscape, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(UVoxelModificationLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelModificationLandscape(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelModificationLandscape) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelModificationLandscape); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelModificationLandscape); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelModificationLandscape(UVoxelModificationLandscape&&); \
	NO_API UVoxelModificationLandscape(const UVoxelModificationLandscape&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVoxelModificationLandscape(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVoxelModificationLandscape(UVoxelModificationLandscape&&); \
	NO_API UVoxelModificationLandscape(const UVoxelModificationLandscape&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVoxelModificationLandscape); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVoxelModificationLandscape); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVoxelModificationLandscape)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_12_PROLOG \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_EVENT_PARMS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_CALLBACK_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_CALLBACK_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_Editor_VoxelModificationLandscape_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
