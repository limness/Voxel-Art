// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class UVoxelChunkComponent;

/**
 * 
 */
class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{

public:

	//Node ID
	uint64 nodeID = 0x00;

	//Level of detalization
	int level = 0;

	int Voxels = 16;

	//Radius of chunkd
	float radius = 0.f;

	//Set up the priority
	float priority = 0.f;

	//Position of chunk
	FVector position = FVector(0.f, 0.f, 0.f);

public:

	//Transvoxel info for sides
	uint8 transvoxelDirection = 0x00;

	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceN;
	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceS;
	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceE;
	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceW;
	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceD;
	TArray<TWeakPtr<FVoxelOctreeData>> neighborFaceU;

public:
	//We can update this chunk from another thread
	//For update mesh or respawn this.
	//So we need check the chunk before moves
	bool cUpdating = false;

	//Checker of nehighbors updating
	bool cUpdatingNeighbors = false;

	//Hide our actor instead remove
	bool cVisible = true;

	//If our should be juse updated
	bool cShouldBeUpdated = false;

public:
	UVoxelChunkComponent* World = nullptr;

	//Actor of chunk
	UVoxelChunkComponent* chunk = nullptr;

public:
	//Vertices mesh
	TArray <FVector> Vertices = TArray <FVector>();

	//Triangles mesh
	TArray <int32> Triangles = TArray <int32>();

	//Normals mesh
	TArray <FVector> Normals = TArray <FVector>();

	//Colors mesh
	TArray <FLinearColor> Colors = TArray <FLinearColor>();

	//Grids mesh
	TArray<float> Grid = TArray <float>();

public:
	//Parent chunk
	//If a chunk is the first from the Octree, there is no parent
	TWeakPtr<FVoxelOctreeData> ParentChunk;

	//Childs of chunk, if they exist
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