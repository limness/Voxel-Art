// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelTools.h"
#include "VoxelEditorData.generated.h"

UENUM()
enum BrushType
{
	Sphere	UMETA(DisplayName = "Sphere"),
	Cube	UMETA(DisplayName = "Cube")
};

UENUM()
enum EditorType
{
	TerrainEdit	UMETA(DisplayName = "Terrain"),
	ColorEdit	UMETA(DisplayName = "Color")
};

UENUM()
enum BrushSoftness
{
	Smooth	UMETA(DisplayName = "Smooth"),
	Insert	UMETA(DisplayName = "Insert"),
	Flat	UMETA(DisplayName = "Flat")
};

/*
* Voxel Editor Data class
*/
UCLASS(Blueprintable, BlueprintType)
class VOXELART_API UVoxelEditorData : public UObject
{
	GENERATED_BODY()

public:

	UVoxelEditorData(const FObjectInitializer& ObjectInitializer) {}
	~UVoxelEditorData() {}

public:

	UPROPERTY(EditAnywhere, Category = "Tools", meta = (DisplayName = "Edit"))
	TEnumAsByte<EditorType> EditorType = EditorType::TerrainEdit;

	UPROPERTY(EditAnywhere, Category = "Tools", meta = (DisplayName = "Brush Type"))
	TEnumAsByte<BrushType> BrushType = BrushType::Sphere;

	UPROPERTY(EditAnywhere, Category = "Tools", meta = (DisplayName = "Softness"))
	TEnumAsByte<BrushSoftness> BrushSoftness = BrushSoftness::Insert;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Brush Dig"))
	bool Dig = true;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Radius"))
	float Radius = 10.f;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Brush Strength"))
	float Strength = 10.f;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Max Distance"))
	float MaxDictance = 256.f;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Color"))
	FColor BrushColor = VOXEL_COLOR;
};
