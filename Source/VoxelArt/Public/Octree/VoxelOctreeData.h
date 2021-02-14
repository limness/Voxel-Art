// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class UVoxelChunkComponent;


class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{

public:

	uint64 NodeID = 0x00;
	uint8 Depth = 0;

	float Size = 0.f;

	FVector Position = FVector(0.f, 0.f, 0.f);

public:

	FVoxelChunkData* Data = nullptr;

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>> ChildrenChunks;

public:
	FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, int _Depth, float _Radius, FVector _Position);
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


class VOXELART_API FVoxelChunkData
{

public:

	int Voxels = 16;

	float Size = 0.f;
	float Priority = 0.f;

	uint8 TransitionSides = 0x00;

	FVector Position = FVector(0.f, 0.f, 0.f);

public:

	TArray<float> DensityMap = TArray <float>();

public:

	UVoxelChunkComponent* Chunk = nullptr;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, FVector _Position, float _Size, int _Voxels, float _Priority);
	~FVoxelChunkData();

};

/*class VOXELART_API FVoxelChunkRenderData
{

public:

	float priority = 0.f;
	FVector position = FVector(0.f, 0.f, 0.f);
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkRenderData();
	~FVoxelChunkRenderData();

};*/


USTRUCT(BlueprintType)
struct FChunksRenderInfo
{
	GENERATED_USTRUCT_BODY()

	//Chunks which has to be created
	TArray<FVoxelChunkData*> ChunksCreation;

	//Chunks which has to be generated
	TArray<FVoxelChunkData*> ChunksGeneration;

	//Chunks which has to be removed
	TArray<UVoxelChunkComponent*> ChunksRemoving;
};