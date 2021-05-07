// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Editor/VoxelEditorTool.h"
#include "Editor/VoxelEditorData.h"
#include "Helpers/VoxelTools.h"

#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
//#include "Interfaces/IPluginManager.h"
//#include "Materials/MaterialInstanceDynamic.h"


AVoxelEditorTool::AVoxelEditorTool()
{
	Marker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EditorTool"));
	RootComponent = Marker;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>	CubeTool(TEXT("/Engine/BasicShapes/Cube"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>	SphereTool(TEXT("/Engine/BasicShapes/Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>	ConeTool(TEXT("/Engine/BasicShapes/Cone"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>	TorusTool(TEXT("/VoxelArt/EditorTools/Torus"));

	static ConstructorHelpers::FObjectFinder<UMaterial>		MaterialTool(TEXT("/VoxelArt/EditorMaterials/MVoxel_Tool"));

	if (CubeTool.Succeeded())
	{
		CubeToolMesh = CubeTool.Object;
	}
	if (SphereTool.Succeeded())
	{
		SphereToolMesh = SphereTool.Object;
	}
	if (ConeTool.Succeeded())
	{
		ConeToolMesh = ConeTool.Object;
	}
	if (TorusTool.Succeeded())
	{
		TorusToolMesh = TorusTool.Object;
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
	if (Material == nullptr)
	{
		Material = UMaterialInstanceDynamic::Create(MaterialPath, this);
		Marker->SetMaterial(0, Material);
	}
	if (Data->CopyPastOn)
	{
		CurrentTool = EBrushShape::Cube;

		Marker->SetStaticMesh(CubeToolMesh);
		Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->CopyRadius * 2.f);
		Marker->SetWorldLocation(ToolPosition);
		return;
	}
	if (CurrentTool != Data->BrushShape)
	{
		switch (Data->BrushShape)
		{
			case EBrushShape::Cube:		{ Marker->SetStaticMesh(CubeToolMesh);		break; }
			case EBrushShape::Sphere:	{ Marker->SetStaticMesh(SphereToolMesh);	break; }
			case EBrushShape::Cone:		{ Marker->SetStaticMesh(ConeToolMesh);		break; }
			case EBrushShape::Torus:	{ Marker->SetStaticMesh(TorusToolMesh);		break; }
		}
		CurrentTool = Data->BrushShape;
	}
	{
		switch (Data->BrushShape)
		{
			case EBrushShape::Cube: 
			{
				Marker->SetWorldRotation(FQuat(FRotator(0.f, 0.f, 0.f)));
				Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->Radius * 2.f);
				break;  
			}
			case EBrushShape::Sphere: 
			{
				Marker->SetWorldRotation(FQuat(FRotator(0.f, 0.f, 0.f)));
				Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->Radius * 2.f);
				break; 
			}
			case EBrushShape::Cone: 
			{
				Marker->SetWorldRotation(FQuat(FRotator(0.f, 0.f, 0.f)));
				Marker->SetWorldScale3D(FVector(Data->Angle.X, Data->Angle.Y, Data->Height) * 1.28f * 2.f);
				break; 
			}
			case EBrushShape::Torus: 
			{
				Marker->SetWorldRotation(FQuat(FRotator(90.f, 0.f, 90.f)));
				Marker->SetWorldScale3D(FVector(1, 1, 1) * 1.28f * Data->Radius * 2.f);
				break; 
			}
		}
	}
	Marker->SetWorldLocation(ToolPosition);
}