// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "Async/Async.h"

class AVoxelWorld;
class FVoxelOctreeData;
struct FChunksRenderInfo;

/*
* Voxel Octree Manager class
*/
class VOXELART_API VoxelOctreeManager : public FRunnable
{
public:

	VoxelOctreeManager(AVoxelWorld* _World, uint8 _DrawingRange, int _MaximumLOD);
	~VoxelOctreeManager();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();

private:

	AVoxelWorld* World;
	TSharedPtr<FChunksRenderInfo> ChangesOctree;

	FIntVector PlayerPositionToWorld;
	FIntVector OldPlayerPositionToWorld;

	uint8 DrawingRange = 5;
	int MaximumLOD = 8;

private:

	FVoxelOctreeData* OctreeCopy;

private:

	FRunnableThread* Thread;

	FCriticalSection m_mutex;
	FEvent * m_semaphore;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;

private:

	TArray<TSharedPtr<FVoxelOctreeData>> GetLeavesChunk(TSharedPtr<FVoxelOctreeData> chunk);

	bool CheckOctree(TSharedPtr<FVoxelOctreeData> Octant);
};