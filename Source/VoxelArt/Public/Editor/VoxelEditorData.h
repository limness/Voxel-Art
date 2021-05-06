// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Helpers/VoxelTools.h"
#include "VoxelEditorData.generated.h"

UENUM()
enum EBrushShape
{
	Sphere		UMETA(DisplayName = "Sphere"),
	Cube		UMETA(DisplayName = "Cube"),
	Torus		UMETA(DisplayName = "Torus"),
	Cone		UMETA(DisplayName = "Cone")
};

UENUM()
enum EEditorType
{
	TerrainEdit	UMETA(DisplayName = "Terrain"),
	ColorEdit	UMETA(DisplayName = "Color")
};

UENUM()
enum EBrushSoftness
{
	Smooth	UMETA(DisplayName = "Smooth"),
	Insert	UMETA(DisplayName = "Insert"),
	Flat	UMETA(DisplayName = "Flat")
};

UENUM()
enum ECopyingPasting
{
	Copying	UMETA(DisplayName = "Copying"),
	Pasting	UMETA(DisplayName = "Pasting")
};


USTRUCT(BlueprintType)
struct VOXELART_API FVoxelInfo
{
	GENERATED_BODY()

	UPROPERTY()
	FIntVector Position = FIntVector(0, 0, 0);

	UPROPERTY()
	float Value = 0.f;

	UPROPERTY()
	FColor Color = VOXEL_COLOR;

	FVoxelInfo() {}

	FVoxelInfo(FIntVector InPosition, float InValue, FColor InColor) 
		: Position(InPosition)
		, Value(InValue)
		, Color(InColor)
	{
	}
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
	TEnumAsByte<EEditorType> EditorType = EEditorType::TerrainEdit;

	UPROPERTY(EditAnywhere, Category = "Tools", meta = (DisplayName = "Softness"))
	TEnumAsByte<EBrushSoftness> BrushSoftness = EBrushSoftness::Insert;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Brush Dig"))
	bool Dig = true;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Brush Strength"))
	float Strength = 10.f;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Max Distance"))
	float MaxDictance = 256.f;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (DisplayName = "Color"))
	FColor BrushColor = VOXEL_COLOR;

	UPROPERTY(EditAnywhere, Category = "Shape Settings", meta = (DisplayName = "Brush Shape"))
	TEnumAsByte<EBrushShape> BrushShape = EBrushShape::Sphere;

	UPROPERTY(EditAnywhere, Category = "Shape Settings", meta = (DisplayName = "Radius"))
	float Radius = 10.f;

	UPROPERTY(EditAnywhere, Category = "Shape Settings", meta = (DisplayName = "Torus Inner Radius"))
	float InnerRadius = 5.f;

	UPROPERTY(EditAnywhere, Category = "Shape Settings", meta = (DisplayName = "Cone Height"))
	float Height = 30.f;

	UPROPERTY(EditAnywhere, Category = "Shape Settings", meta = (DisplayName = "Cone Angle"))
	FVector2D Angle = FVector2D(15, 20);

	UPROPERTY(EditAnywhere, Category = "Copying & pasting", meta = (DisplayName = "Copy Past On"))
	bool CopyPastOn = false;

	UPROPERTY(EditAnywhere, Category = "Copying & pasting", meta = (DisplayName = "Type"))
	TEnumAsByte<ECopyingPasting> CopyingPasting = ECopyingPasting::Copying;

	UPROPERTY(EditAnywhere, Category = "Copying & pasting", meta = (DisplayName = "Copy Radius"))
	float CopyRadius = 15.f;

	UPROPERTY(VisibleAnywhere, Category = "Copying & pasting")
	FIntVector CenterCopy;

	UPROPERTY(EditAnywhere, Category = "Copying & pasting")
	FIntVector PastOffset = FIntVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "Copying & pasting")
	FIntVector CornerMin = FIntVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "Copying & pasting")
	FIntVector CornerMax = FIntVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "Copying & pasting")
	TArray<FVoxelInfo> CopiedDensity;

	void ClearCopiedData();
};
