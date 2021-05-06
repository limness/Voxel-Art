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

	return Value;
}

float FVoxelSDFUtilities::TorusSDF(int X, int Y, int Z, float Radius, float InnerRadius)
{
	float Value = 0.f;

	Value = FVector(FVector(X, Z, 0).Size() - Radius, Y, 0).Size() - InnerRadius - VoxelTools::VoxelOffset;

	return Value;
}

float FVoxelSDFUtilities::ConeSDF(int X, int Y, int Z, FVector2D Angle, float Height)
{
	float Value = 0.f;

	FVector q = Height * FVector(Angle.X / Angle.Y, -1.0, 0);

	FVector w = FVector(FVector(X, Z, 0).Size(), Y, 0);
	FVector a = w - q * FMath::Clamp<float>(FVector::DotProduct(w, q) / FVector::DotProduct(q, q), 0.0, 1.0);
	FVector b = w - q * FVector(FMath::Clamp<float>(w.X / q.X, 0.0, 1.0), 1.0, 0);

	float k = 0.f;

	if (q.Y == 0) { k = 0.f; }
	else if (q.Y > 0) { k = 1.f; }
	else { k = -1.f; }

	float d = UKismetMathLibrary::FMin(FVector::DotProduct(a, a), FVector::DotProduct(b, b));
	float sign = FMath::Max(k * (w.X * q.Y - w.Y * q.X), k * (w.Y - q.Y));

	if (sign == 0) { sign = 0.f; }
	else if (sign > 0) { sign = 1.f; }
	else { sign = -1.f; }

	Value = sqrt(d) * sign - VoxelTools::VoxelOffset;

	return Value;
}

float FVoxelSDFUtilities::BoxFrameSDF(int X, int Y, int Z, FVector b, float e)
{
	float Value = 0.f;

	X = FMath::Abs(X) - b.X;
	Y = FMath::Abs(Y) - b.Y;
	Z = FMath::Abs(Z) - b.Z;

	FVector q = FVector(FMath::Abs(X + e), FMath::Abs(Y + e), FMath::Abs(Z + e)) - e;
	/*
	Value = UKismetMathLibrary::FMin(UKismetMathLibrary::FMin(
		length(FMath::Max(FVector(X, q.Y, q.Z), 0.0)) + UKismetMathLibrary::FMin(FMath::Max(X, FMath::Max(q.Y, q.Z)), 0.0),
		length(FMath::Max(FVector(q.X, Y, q.Z), 0.0)) + UKismetMathLibrary::FMin(FMath::Max(q.X, FMath::Max(Y, q.Z)), 0.0)),
		length(FMath::Max(FVector(q.X, q.Y, Z), 0.0)) + UKismetMathLibrary::FMin(FMath::Max(q.X, FMath::Max(q.Y, Z)), 0.0));
		*/
	return Value;
}

/*
Octahedron

float sdOctahedron( vec3 p, float s)
{
  p = abs(p);
  return (p.x+p.y+p.z-s)*0.57735027;
}
*/