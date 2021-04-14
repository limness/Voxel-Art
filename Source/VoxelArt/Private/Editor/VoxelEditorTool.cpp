// Voxel Art Plugin © limit 2018

#include "Editor/VoxelEditorTool.h"
#include "Editor/VoxelEditorData.h"
#include "UObject/ConstructorHelpers.h"

AVoxelEditorTool::AVoxelEditorTool()
{
	Marker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EditorTool"));
	RootComponent = Marker;

	auto CubeTool = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	auto SphereTool = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	auto MaterialTool = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/VoxelArt/EditorMaterials/MVoxel_Tool.MVoxel_Tool'"));

	if (CubeTool.Succeeded())
	{
		CubeToolMesh = CubeTool.Object;
	}
	if (SphereTool.Succeeded())
	{
		SphereToolMesh = SphereTool.Object;
	}
	if (MaterialTool.Object)
	{
		MaterialPath = MaterialTool.Object;
	}
	Marker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Marker->SetStaticMesh(SphereToolMesh);
}

void AVoxelEditorTool::ToolInitialize(UVoxelEditorData* Data, FVector ToolPosition)
{
	if (!Material)
	{
		Material = UMaterialInstanceDynamic::Create(MaterialPath, this);
		Marker->SetMaterial(0, Material);
	}
	if (CurrentTool != Data->BrushType)
	{
		switch (Data->BrushType)
		{
		case BrushType::Cube: { Marker->SetStaticMesh(CubeToolMesh); break;  }
		case BrushType::Sphere: { Marker->SetStaticMesh(SphereToolMesh); break; }
		}
		CurrentTool = Data->BrushType;
	}
	Marker->SetWorldLocation(ToolPosition);
	Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->Radius * 2.f);
}