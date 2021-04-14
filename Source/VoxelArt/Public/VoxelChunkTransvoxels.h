// Voxel Art Plugin © limit 2018

#pragma once

#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Helpers/VoxelProceduralMeshComponent.h"
#include "VoxelChunkTransvoxels.generated.h"


UCLASS()
class VOXELART_API AVoxelChunkTransvoxels : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface* material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 x_chunk = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 y_chunk = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 z_chunk = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UVoxelProceduralMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UVoxelProceduralMeshComponent* mesh1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* CollisionMesh;

public:
	AVoxelChunkTransvoxels(const class FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere)
		TArray <FVector> mesh_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		uint8 transvoxelDirection = 0x00;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		bool anim = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		float speed = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		float yPos = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		bool transvoxel = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Octree")
		int multiplyOctree = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size", Meta = (ExposeOnSpawn = true))
		float radius = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		float radiusSphere = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		int voxels = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		int multiply = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		float multiplyMinus = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		float transitionSize = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		int level = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Size")
		int valueSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
		float actave = 0.0004f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
		float period = 400.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise")
		float period_two = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
		FLinearColor ground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layes")
		FLinearColor grass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planet")
		bool half = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planet")
		bool update = true;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	//	TArray <FPositionVoxelChunkStruct> positionZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		FVector positionChunk;

	UPROPERTY()
		FVector position[8];


	float infoNoise[8];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<int> infoChunk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<int> infoGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<float> Grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<FVector> positionSide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
		bool generateSphere = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
		bool generateNoise = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generate")
		bool generatePlane = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true)) // , Meta = (MakeEditWidget = true) //EditDefaultsOnly
		TArray<FVector> TestVertices;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TArray<int32> TestTriangles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) // , Meta = (MakeEditWidget = true) //EditDefaultsOnly
		TArray<FVector> Vertices;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TArray<int32> Triangles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> Normals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true)) // , Meta = (MakeEditWidget = true)
		TArray<FLinearColor> VertexColors;

	UPROPERTY()
		TArray<FVoxelProcMeshTangent> Tangents;

	UPROPERTY()
		TArray<FVector2D> TextureCoordinates;

	UFUNCTION(BlueprintCallable)
		void GenerateVertexCube(bool regenerate);

	float GetDensity(int x, int y, int z);

	FVector GetGradient(int x, int y, int z);

	FLinearColor GetColor(FVector positionVoxel);

	//UFUNCTION()
	void GenerateNoise();

	template<uint8 Direction>
	void GeometryTransitionCubes();

	template<uint8 Direction>
	FVector PositionToDirection(FVector directionPosition, float size);

	template<uint8 Direction>
	FVector MaskSidesByDirection(FVector directionPosition);

	UFUNCTION()
		void MarchingCubes(int isolevel, int indexGrid, int x, int y, int z, int normalIndex);

	UFUNCTION(BlueprintCallable)
		int GetVoxelId(int posX, int posY, int posZ);

	UFUNCTION(BlueprintCallable)
		float GetVoxelSize();

	UFUNCTION(BlueprintCallable)
		float GetVoxelSizeHalf();

	UFUNCTION(BlueprintCallable)
		void UpdateMesh(TArray<FVector> Vert, TArray<int32> Tri, TArray<FVector> Norm, TArray<FLinearColor> Cols);

	UFUNCTION()
		float GetValueNoise(FVector positionGrid);

	UFUNCTION()
		FVector VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value);

	UFUNCTION()
		FVector VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst);
};