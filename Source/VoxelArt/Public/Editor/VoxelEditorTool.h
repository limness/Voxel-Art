// Voxel Art Plugin 2021 ~ Copyright Limit

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

	TEnumAsByte<EBrushShape> CurrentTool;
	float CurrentRadius;

private:

	UStaticMesh* CubeToolMesh;
	UStaticMesh* SphereToolMesh;
	UStaticMesh* ConeToolMesh;
	UStaticMesh* TorusToolMesh;

private:

	UStaticMeshComponent* Marker;
	UMaterialInstanceDynamic* Material;

	UMaterial* MaterialPath;
};