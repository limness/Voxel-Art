// Voxel Art Plugin © limit 2018

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

/*
* Voxel Editor Data class
*/
UCLASS()
class VOXELART_API UVoxelEditorData : public UObject
{
	GENERATED_BODY()

public:

	UVoxelEditorData(const FObjectInitializer& ObjectInitializer) {}
	~UVoxelEditorData() {}

public:

	UPROPERTY(EditAnywhere, Category = "Tools", meta = (DisplayName = "Editor Type"))
	TEnumAsByte<EditorType> EditorType = EditorType::Terrain;

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
