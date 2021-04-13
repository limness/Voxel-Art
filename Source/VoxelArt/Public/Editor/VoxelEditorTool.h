// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "VoxelEditorTool.generated.h"


class UVoxelEditorData;


UCLASS()
class VOXELART_API AVoxelEditorTool : public AActor
{
	GENERATED_BODY()

public:

	AVoxelEditorTool();

public:

	void ToolInitialize(UVoxelEditorData* Data, FVector ToolPosition);

public:

	TEnumAsByte<BrushType> CurrentTool;
	float CurrentRadius;

private:

	UStaticMesh* CubeToolMesh;
	UStaticMesh* SphereToolMesh;

private:

	UStaticMeshComponent* Marker;
	UMaterialInstanceDynamic* Material;

	UMaterial* MaterialPath;
};