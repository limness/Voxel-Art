// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class AVoxelLandscape;
class UVoxelChunkComponent;
class UVoxelLandscapeGenerator;


class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{
public:

	uint64 NodeID = 0x00;
	uint8 Depth = 0;

	int Size = 0;

	FIntVector Position = FIntVector(0, 0, 0);

public:

	FVoxelChunkData* Data = nullptr;
//	FVoxelOctreeDensity* DensityOctant = nullptr;

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>> ChildrenChunks;

public:
	FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, uint8 _Depth, float _Radius, FIntVector _Position);
	~FVoxelOctreeData();


public:

	void AddChildren();

	inline void DestroyChildren();

	inline bool HasChildren();

	inline void CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>> children);

	inline FIntVector GetMinimumCorner();

	inline FIntVector GetMaximumCorner();

	inline TWeakPtr<FVoxelOctreeData> GetParent();

	inline TArray<TSharedPtr<FVoxelOctreeData>> GetChildren();

	inline TWeakPtr<FVoxelOctreeData> GetChildByPosition(FVector Position);

	inline TWeakPtr<FVoxelOctreeData> GetLeaf(FVector Position);
};

class VOXELART_API FVoxelChunkData
{
public:

	int Voxels = 16;

	int Size = 0;
	float Priority = 0.f;

	uint8 Depth = 0;
	uint8 TransitionSides = 0x00;

	FIntVector Position = FIntVector(0, 0, 0);

public:

	TArray<float> DensityMap = TArray <float>();
	//FVoxelOctreeDensity* DensityOctant = nullptr;

public:

	UVoxelChunkComponent* Chunk = nullptr;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, uint8 _Depth, FIntVector _Position, int _Size, int _Voxels, float _Priority);
	~FVoxelChunkData();

};


/*
* FVoxelOctreeDensity is needed to save info
* about the entire density of the world.
* We will then be able to store and load it.
*/

class VOXELART_API FVoxelOctreeDensity
{
public:

	uint8 Depth = 0;

	int Size = 0;
	FIntVector Position = FIntVector(0, 0, 0);
	TArray<float> DensityMap = TArray <float>();

private:

	bool OwnDensity = false;

public:

	UVoxelLandscapeGenerator* WorldGenerator;
	TArray<FVoxelOctreeDensity*> ChildrenOctants;

public:

	void AddChildren();

	inline bool HasChildren() { return ChildrenOctants.Num() == 8; };

	inline void SetVoxelDensity(AVoxelLandscape* World, FIntVector P, float Value);

	inline void GetVoxelDensity(AVoxelLandscape* World, FIntVector P, float& Value);

	void TransferToLocal(AVoxelLandscape* World, FIntVector& Position);

	inline bool HasOwnDensity() { return OwnDensity; }

	FVoxelOctreeDensity* GetLeaf(FIntVector Position);

	FVoxelOctreeDensity* GetChildByPosition(FIntVector Position);

	void SetDefaultDensityMap(AVoxelLandscape* World);

public:
	FVoxelOctreeDensity(UVoxelLandscapeGenerator* _WorldGenerator, uint8 _Depth, int _Size, FIntVector _Position);
	~FVoxelOctreeDensity() {}

};


USTRUCT(BlueprintType)
struct FChunksRenderInfo
{
	GENERATED_USTRUCT_BODY()

	//Chunks which has to be created
	TArray<FVoxelChunkData*> ChunksCreation;

	//Chunks which has to be generated
	TArray<FVoxelChunkData*> ChunksGeneration;

	//Chunks which has to be removed
	TArray<FVoxelChunkData*> ChunksRemoving;
};