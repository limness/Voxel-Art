// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Octree/VoxelOctreeData.h"


class AVoxelLandscape;

class VOXELART_API VoxelRender : public FRunnable
{

public:

	VoxelRender(AVoxelLandscape* _World);
	~VoxelRender();

private:

	AVoxelLandscape* World;

public:

	/*Thread interface*/
	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	bool IsThreadPaused();
	/*Thread interface*/

private:

	/*Thread interface*/
	FRunnableThread* Thread;

	FCriticalSection m_mutex;
	FEvent* m_semaphore;

	int m_chunkCount;
	int m_amount;

	bool g_stop = false;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;
	/*Thread interface*/
};
