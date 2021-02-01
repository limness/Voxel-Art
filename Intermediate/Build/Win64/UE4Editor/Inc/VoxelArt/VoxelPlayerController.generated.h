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
#ifdef VOXELART_VoxelPlayerController_generated_h
#error "VoxelPlayerController.generated.h already included, missing '#pragma once' in VoxelPlayerController.h"
#endif
#define VOXELART_VoxelPlayerController_generated_h

#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execChangeChunk) \
	{ \
		P_GET_OBJECT(AVoxelLandscape,Z_Param_terrain); \
		P_GET_OBJECT(AVoxelChunk,Z_Param_chunkCenter); \
		P_GET_STRUCT(FVector,Z_Param_position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ChangeChunk(Z_Param_terrain,Z_Param_chunkCenter,Z_Param_position,Z_Param_range); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execChangeChunk) \
	{ \
		P_GET_OBJECT(AVoxelLandscape,Z_Param_terrain); \
		P_GET_OBJECT(AVoxelChunk,Z_Param_chunkCenter); \
		P_GET_STRUCT(FVector,Z_Param_position); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_range); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ChangeChunk(Z_Param_terrain,Z_Param_chunkCenter,Z_Param_position,Z_Param_range); \
		P_NATIVE_END; \
	}


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelPlayerController(); \
	friend struct Z_Construct_UClass_AVoxelPlayerController_Statics; \
public: \
	DECLARE_CLASS(AVoxelPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelPlayerController)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelPlayerController(); \
	friend struct Z_Construct_UClass_AVoxelPlayerController_Statics; \
public: \
	DECLARE_CLASS(AVoxelPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VoxelArt"), NO_API) \
	DECLARE_SERIALIZER(AVoxelPlayerController)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelPlayerController(AVoxelPlayerController&&); \
	NO_API AVoxelPlayerController(const AVoxelPlayerController&); \
public:


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelPlayerController(AVoxelPlayerController&&); \
	NO_API AVoxelPlayerController(const AVoxelPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelPlayerController)


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_PRIVATE_PROPERTY_OFFSET
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_18_PROLOG
#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_RPC_WRAPPERS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_INCLASS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_PRIVATE_PROPERTY_OFFSET \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_INCLASS_NO_PURE_DECLS \
	TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestPlugin_Plugins_VoxelArt_Source_VoxelArt_Public_VoxelPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS