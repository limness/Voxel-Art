// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelChunkComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Helpers/MarchingCubes.h"
#include "Noise/SimplexNoiseBPLibrary.h"
#include "DrawDebugHelpers.h"

UVoxelChunkComponent::UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bUseAsyncCooking = true;
}

UVoxelChunkComponent::~UVoxelChunkComponent()
{
}


void UVoxelChunkComponent::Initialize(FIntPoint inPos, UMaterialInterface* material)
{

}

bool UVoxelChunkComponent::IsActive()
{
	return Active;
}

void UVoxelChunkComponent::SetActive(bool activeStatus)
{
	Active = activeStatus;
	if (!activeStatus)
	{
		ClearMeshSection(0);
		SetCollisionEnabled(ECollisionEnabled::NoCollision); //QueryAndPhysics
	}
	else
	{
		SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //QueryAndPhysics
	}
	ToggleVisibility(!activeStatus);
}

//Thanks to
//https://www.iquilezles.org/www/articles/smin/smin.htm

float UVoxelChunkComponent::VoxelValueMin(float a, float b, float k)
{
	float h = FMath::Clamp((b - a + k) / (2.f * k), 0.0f, 1.0f);
	return a * h + b * (1 - h) - k * h * (1.0 - h);
}

void UVoxelChunkComponent::UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors)
{
	ClearMeshSection(0);

	if (Vertices.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), Colors, TArray<FProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}
}