// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class AVoxelChunk;

/**
 * 
 */
class VOXELART_API FVoxelOctreeData
{

public:
	int x = 0;
	int y = 0;
	int z = 0;

	//Set up the kostyl
	float priority = 0.f;

	//Set up the kostyl
	bool kostyl = false;

	//Node ID
	uint64 nodeID = 0x00;

	//Level of detalization
	int level = 0;

	//Radius of chunkd
	float radius = 0.f;

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

	int ChunksShouldBeRemovedCounter;

	TArray<TSharedPtr<FVoxelOctreeData>> ChunksShouldBeRemoved;

public:
	//Parent chunk
	//If a chunk is the first from the Octree, there is no parent
	TWeakPtr<FVoxelOctreeData> ParentChunk;

	//Childs of chunk, if they exist
	TArray<TSharedPtr<FVoxelOctreeData>> ChildrenChunks;

public:
	FVoxelOctreeData();
	~FVoxelOctreeData();


public:
	inline void DestroyChildren()
	{
		//check(HasChildren());

	//	FScopeLock Lock(&Mutex);

		for (auto& it : GetChildren())
		{
			//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : VoxelOctreeData ] removing from %p %d octree %p %d"), this, this->nodeID, it.Get(), it->nodeID);
			it.Reset();
		}
		ChildrenChunks.Empty();
		ChildrenChunks.Reset();
	}

	inline bool HasChildren()
	{
		return !!(ChildrenChunks.Num());
	}

	inline TWeakPtr<FVoxelOctreeData> GetParent()
	{
		check((ParentChunk != nullptr));

		return ParentChunk;
	}

	inline TArray<TSharedPtr<FVoxelOctreeData>> GetChildren()
	{
	//	check(HasChildren());

		return ChildrenChunks;
	}

	inline void CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>> children)
	{
	//	FScopeLock Lock(&Mutex);

		for (auto& it : children)
		{
			ChildrenChunks.Add(it);
		}
	}

	template<uint8 Direction>
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetNeighbor(int position);
//private:
	//Critical section
	//FCriticalSection Mutex;
};


class VOXELART_API FVoxelChunkRenderData
{

public:

	float priority = 0.f;

	//Node ID
	uint64 nodeID = 0x00;

	//Level of detalization
	int level = 0;

	//Radius of chunkd
	float radius = 0.f;

	//Position of chunk
	FVector position = FVector(0.f, 0.f, 0.f);

	//Transvoxel info for sides
	uint8 transvoxelDirection = 0x00;

public:

	TArray<float> DensityMap = TArray <float>();

public:

	int ChunksShouldBeRemovedCounter;

	TArray<AVoxelChunk*> ChunksShouldBeRemoved;

public:

	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkRenderData();
	~FVoxelChunkRenderData();

};


USTRUCT(BlueprintType)
struct FChunksRenderInfo
{
	GENERATED_USTRUCT_BODY()

	//Leaves which has to be created
	TArray<TSharedPtr<FVoxelOctreeData>> LeavesCreation;

	//Leaves which has to be destroyd
	TArray<TSharedPtr<FVoxelOctreeData>> LeavesDestroying;

	//Chunks which has to be created
	TArray<TSharedPtr<FVoxelChunkRenderData>> ChunksCreation;

	//Chunks which has to be generated
	TArray<TWeakPtr<FVoxelOctreeData>> ChunksGeneration;

	//Chunks which has to be removed
	TArray<UVoxelChunkComponent*> ChunksRemoving;
};