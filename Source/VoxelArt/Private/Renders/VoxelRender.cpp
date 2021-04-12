// Voxel Art Plugin © limit 2018

#include "Renders/VoxelRender.h"
#include "VoxelWorld.h"
#include "Async/ParallelFor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/DateTime.h"

VoxelRender::VoxelRender(AVoxelWorld* _World) : World(_World)
{
	m_Kill = false;
	m_Pause = false;

	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT(""), 0, TPri_BelowNormal);
}

VoxelRender::~VoxelRender()
{
	if (m_semaphore)
	{
		FGenericPlatformProcess::ReturnSynchEventToPool(m_semaphore);
		m_semaphore = nullptr;
	}

	if (Thread)
	{
		delete Thread;
		Thread = nullptr;
	}
}

bool VoxelRender::Init()
{
	return true;
}

uint32 VoxelRender::Run()
{
	FPlatformProcess::Sleep(0.03);

	while (!m_Kill)
	{
		if (m_Pause)
		{
			m_semaphore->Wait();

			if (m_Kill)
			{
				return 0;
			}
		}
		else
		{
			if (!g_stop)
			{
				g_stop = true;
			}
			FPlatformProcess::Sleep(0.5);
		}
	}

	return 0;
}

void VoxelRender::PauseThread()
{
	m_Pause = true;
}

void VoxelRender::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelRender::Stop()
{
	m_Kill = true;
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelRender::EnsureCompletion()
{
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();
	}
}

bool VoxelRender::IsThreadPaused()
{
	return (bool)m_Pause;
}