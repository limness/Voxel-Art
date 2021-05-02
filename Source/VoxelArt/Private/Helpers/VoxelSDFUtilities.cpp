// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Helpers/VoxelSDFUtilities.h"

float FVoxelSDFUtilities::FlatSDF(int A)
{
	float Value = 0.f;

	if (A >= 0)
	{
		Value = (-1) * UKismetMathLibrary::FMax(1.f, A);
	}
	else if (A < 0)
	{
		Value = (-1) * UKismetMathLibrary::FMin(-1.f, A);
	}
	return Value;
}


float FVoxelSDFUtilities::SphereSDF(int X, int Y, int Z, float Radius)
{
	float Value = 0.f;

	Value = Radius - VoxelTools::VoxelOffset - FVector(X, Y, Z).Size();

	return -Value;
}

float FVoxelSDFUtilities::TorusSDF(int X, int Y, int Z, float Radius, float InnerRadius)
{
	float Value = 0.f;

	//Value = (Radius - sqrt(X * X + Y * Y)) * (Radius - sqrt(X * X + Y * Y)) + Z * Z - RadiusInside * RadiusInside;
	Value = FVector(FVector(X, Z, 0).Size() - Radius, Y, 0).Size() - InnerRadius - VoxelTools::VoxelOffset;

	return Value;
}

float FVoxelSDFUtilities::ConeSDF(int X, int Y, int Z, FVector2D c, float Height)
{
	float Value = 0.f;

	FVector q = Height * FVector(c.X / c.Y, -1.0, 0);

	FVector w = FVector(FVector(X, Z, 0).Size(), Y, 0);
	FVector a = w - q * FMath::Clamp<float>(FVector::DotProduct(w, q) / FVector::DotProduct(q, q), 0.0, 1.0); //
	FVector b = w - q * FVector(FMath::Clamp<float>(w.X / q.X, 0.0, 1.0), 1.0, 0);

	float k = q.Y >= 0.f ? 1.f : -1.f;
	float d = UKismetMathLibrary::FMin(FVector::DotProduct(a, a), FVector::DotProduct(b, b));
	float sign = FMath::Max(k * (w.X * q.Y - w.Y * q.X), k * (w.Y - q.Y)) >= 0.f ? 1.f : -1.f;

	Value = sqrt(d) * sign - VoxelTools::VoxelOffset;

	return Value;
}
/*
float FVoxelSDFUtilities::BoxFrameSDF(FVector p, FVector2D c, float h)
{
	p = abs(p) - b;
	vec3 q = abs(p + e) - e;
	return min(min(
		length(max(vec3(p.x, q.y, q.z), 0.0)) + min(max(p.x, max(q.y, q.z)), 0.0),
		length(max(vec3(q.x, p.y, q.z), 0.0)) + min(max(q.x, max(p.y, q.z)), 0.0)),
		length(max(vec3(q.x, q.y, p.z), 0.0)) + min(max(q.x, max(q.y, p.z)), 0.0));

	return 0.f;
}*/

/*
Octahedron

float sdOctahedron( vec3 p, float s)
{
  p = abs(p);
  return (p.x+p.y+p.z-s)*0.57735027;
}
*/