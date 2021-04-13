// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Octree/VoxelOctreeData.h"

class AVoxelWorld;

<<<<<<< HEAD
/*
* Voxel Render class (Not used now)
*/
=======
class AVoxelWorld;

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
class VOXELART_API VoxelRender : public FRunnable
{

public:

	VoxelRender(AVoxelWorld* _World);
	~VoxelRender();

private:

	AVoxelWorld* World;

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

	bool g_stop = false;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;
	/*Thread interface*/
};
