// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "Octree/VoxelOctreeData.h"
#include "Async/Async.h"

class AVoxelLandscape;

/*
* Voxel Octree Manager class
*/
class VOXELART_API VoxelOctreeManager : public FRunnable
{
public:
	VoxelOctreeManager(AVoxelWorld* _World, APlayerController* _PlayerController, uint8 _DrawingRange, int _MaximumLOD);
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
	APlayerController* PlayerController;
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

	FEditorViewportClient* GetEditorViewportClient();

	bool CheckOctree(TSharedPtr<FVoxelOctreeData> Octant);
};