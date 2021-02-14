// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class UVoxelChunkComponent;


class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{

public:

	uint64 NodeID = 0x00;
	uint8 TransitionSides = 0x00;

	int Level = 0;
	int Voxels = 16;

	float Size = 0.f;
	float Priority = 0.f;

	FVector Position = FVector(0.f, 0.f, 0.f);

	TArray<float> DensityMap = TArray <float>();

public:

	//Chunk itself
	UVoxelChunkComponent* Chunk = nullptr;

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>> ChildrenChunks;

public:
	FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, int _Level, float _Radius, FVector _Position);
	~FVoxelOctreeData();


public:

	void AddChildren();

	inline void DestroyChildren();

	inline bool HasChildren();

	inline void CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>> children);

	inline void GetVoxelDensity(FVector Position, float& Value);

	inline TWeakPtr<FVoxelOctreeData> GetParent();

	inline TArray<TSharedPtr<FVoxelOctreeData>> GetChildren();

	inline TWeakPtr<FVoxelOctreeData> GetChildByPosition(FVector Position);

	inline TWeakPtr<FVoxelOctreeData> GetLeaf(FVector Position);

	template<uint8 Direction>
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetNeighbor(int position);

	FORCEINLINE int PositionToIndices(FVector position);

	void TransferToLocal(FVector& Position);
};


class VOXELART_API FVoxelChunkRenderData
{

public:

	float priority = 0.f;
	FVector position = FVector(0.f, 0.f, 0.f);
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkRenderData();
	~FVoxelChunkRenderData();

};


USTRUCT(BlueprintType)
struct FChunksRenderInfo
{
	GENERATED_USTRUCT_BODY()

	//Chunks which has to be created
	TArray<TSharedPtr<FVoxelChunkRenderData>> ChunksCreation;

	//Chunks which has to be generated
	TArray<UVoxelChunkComponent*> ChunksGeneration;

	//Chunks which has to be removed
	TArray<UVoxelChunkComponent*> ChunksRemoving;
};