// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoxelChunk.h"
#include "Octree/VoxelOctreeData.h"
#include "Async/Async.h"
//#include "MyCharacterThreads.h"

class AVoxelLandscape;
/**
 *
 */
class VOXELART_API VoxelManager : public FRunnable
{
public:
	VoxelManager(
		AVoxelLandscape* _World,
		APlayerController* _PlayerController,
		float _UpdatingOctreeRadius,
		int _MaximumLOD);

	//VoxelManager(int id = -1, APlayerController* controll = nullptr, float degreeSphere = 5000, int maxLevel = 2, float radMain = -1, AActor* landscape = nullptr);
	~VoxelManager();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();

	TArray<TSharedPtr<FVoxelOctreeData>> CheckOctreeWithoutExist(TSharedPtr<FVoxelOctreeData> chunk, int level);
	int CheckOctree(TSharedPtr<FVoxelOctreeData> chunk, int level);

	TArray<TSharedPtr<FVoxelOctreeData>> GetLeavesChunk(TSharedPtr<FVoxelOctreeData> chunk);

private:
	AVoxelLandscape* World;
	APlayerController* PlayerController;
	FChunksRenderInfo* chunksToChange;

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
};