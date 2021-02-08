// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunk.h"
#include "Octree/VoxelOctreeData.h"
#include "Async/Async.h"


class AVoxelLandscape;

class VOXELART_API VoxelManager : public FRunnable
{
public:
	VoxelManager(AVoxelLandscape* _World, APlayerController* _PlayerController, float _UpdatingOctreeRadius, int _MaximumLOD);
	~VoxelManager();

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

	FVector PlayerPositionToWorld;

	float UpdatingOctreeRadius = 5000;
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

	TArray<TSharedPtr<FVoxelOctreeData>> CheckOctreeWithoutExist(TSharedPtr<FVoxelOctreeData> chunk, int level);
	TArray<TSharedPtr<FVoxelOctreeData>> GetLeavesChunk(TSharedPtr<FVoxelOctreeData> chunk);

	int CheckOctree(TSharedPtr<FVoxelOctreeData> chunk, int level);
};