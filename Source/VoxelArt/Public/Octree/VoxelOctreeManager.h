// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunk.h"
#include "Octree/VoxelOctreeData.h"
#include "Async/Async.h"


class AVoxelLandscape;

class VOXELART_API VoxelOctreeManager : public FRunnable
{
public:
	VoxelOctreeManager(AVoxelLandscape* _World, APlayerController* _PlayerController, uint8 _DrawingRange, int _MaximumLOD);
	~VoxelOctreeManager();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();

private:

	AVoxelLandscape* World;
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

	bool CheckOctree(TSharedPtr<FVoxelOctreeData> Octant);
};