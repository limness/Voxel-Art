// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelEditorData.generated.h"


UENUM()
enum EditorType
{
	Terrain	UMETA(DisplayName = "Terrain"),
	Color	UMETA(DisplayName = "Color")
};

UENUM()
enum BrushSoftness
{
	Smooth	UMETA(DisplayName = "Smooth"),
	Insert	UMETA(DisplayName = "Insert"),
	Flat	UMETA(DisplayName = "Flat")
};

USTRUCT()
struct VOXELART_API FVoxelEditorData
{
	GENERATED_BODY()

	TEnumAsByte<EditorType> EditorType;
	TEnumAsByte<BrushSoftness> BrushSoftness;

	bool Dig = true;

	float Radius = 10.f;
	float Strength = 10.f;
	float MaxDictance = 256.f;

	FColor Color = FColor(77.f, 77.f, 77.f);
};