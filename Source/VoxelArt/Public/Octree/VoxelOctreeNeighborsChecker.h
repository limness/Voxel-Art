// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunk.h"
#include "Octree/VoxelOctreeData.h"
#include "Async/Async.h"

class AVoxelLandscape;

class VOXELART_API VoxelOctreeNeighborsChecker : public FRunnable
{

public:

	VoxelOctreeNeighborsChecker(AVoxelLandscape* _World);
	~VoxelOctreeNeighborsChecker();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();

private:

	//TArray<UVoxelChunkComponent*> ChunksGeneration;
	TSharedPtr<FChunksRenderInfo> ChangesOctree;

private:

	AVoxelLandscape* World;

	FVector PlayerPositionToWorld;

private:

	FRunnableThread* Thread;

	FCriticalSection m_mutex;
	FEvent* m_semaphore;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;

private:

	template<uint8 Direction>
	TArray<uint64> GetNodeNeighbors(int level, uint64 nodeID);

	template<uint8 Direction>
	TSharedPtr<FVoxelOctreeData> GetBiggestNeighbor(int level, uint64 nodeID);

	template<uint8 Direction>
	TArray<uint64> GetSmallerNeighbors(int level, int chunkLevel, uint64 chunkNodeID, TSharedPtr<FVoxelOctreeData> NeighborChild);

	template<uint8 Direction>
	uint8 GetLocalNeighbor(uint8 H, uint8 D, uint8 W);

	template<uint8 Direction>
	uint8 GetLocalNeighborInverse(uint8 H, uint8 D, uint8 W);

	template<uint8 Direction>
	uint8 GetSideNeighbor(uint8 H, uint8 D, uint8 W);

	TSharedPtr<FVoxelOctreeData> GetOctantByNodeID(int level, uint64 nodeID);

	TSharedPtr<FVoxelOctreeData> GetDefaultOctantByNodeID(TSharedPtr<FVoxelOctreeData> chunk, int levelTo, int level, uint64 nodeID);

	bool CheckOctree(TSharedPtr<FVoxelOctreeData> Octant, int level);
};