// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Async/Async.h"

class AVoxelWorld;
class FVoxelOctreeData;
struct FChunksRenderInfo;

/*
* Voxel Octree Neighbors Checker class (Need to rewrite and destroy)
*/
class VOXELART_API VoxelOctreeNeighborsChecker : public FRunnable
{
public:

	VoxelOctreeNeighborsChecker(AVoxelWorld* _World);
	~VoxelOctreeNeighborsChecker();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();

private:

	TSharedPtr<FChunksRenderInfo> ChangesOctree;

private:

	AVoxelWorld* World;

	FVector PlayerPositionToWorld;

private:

	FRunnableThread* Thread;

	FCriticalSection m_mutex;
	FEvent* m_semaphore;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;

private:

	template<uint8 Direction>
	TArray<TWeakPtr<FVoxelOctreeData>> GetNodeNeighbors(int level, uint64 nodeID);

	template<uint8 Direction>
	TWeakPtr<FVoxelOctreeData> GetBiggestNeighbor(int level, uint64 nodeID);

	template<uint8 Direction>
	TArray<TWeakPtr<FVoxelOctreeData>> GetSmallerNeighbors(int level, int chunkLevel, uint64 chunkNodeID, TWeakPtr<FVoxelOctreeData> biggestNeighbor);

	template<uint8 Direction>
	uint8 GetLocalNeighbor(uint8 H, uint8 D, uint8 W);

	template<uint8 Direction>
	uint8 GetLocalNeighborInverse(uint8 H, uint8 D, uint8 W);

	template<uint8 Direction>
	uint8 GetSideNeighbor(uint8 H, uint8 D, uint8 W);

	TWeakPtr<FVoxelOctreeData> GetChunkByNodeID(int level, uint64 nodeID);

	TWeakPtr<FVoxelOctreeData> FindNodeByID(TWeakPtr<FVoxelOctreeData> chunk, int levelTo, int level, uint64 nodeID);

	bool CheckOctree(TSharedPtr<FVoxelOctreeData> Octant, int level);
};