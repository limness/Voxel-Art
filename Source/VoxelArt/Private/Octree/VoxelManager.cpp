
// Fill out your copyright notice in the Description page of Project Settings.

#include "Octree/VoxelManager.h"
#include "VoxelLandscape.h"
#include "Helpers/VoxelTools.h"

#include "Editor.h"
#include "EditorViewportClient.h"

DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker"), STAT_Run, STATGROUP_Voxel);


VoxelManager::VoxelManager(AVoxelLandscape* _World, APlayerController* _PlayerController, uint8 _DrawingRange, int _MaximumLOD)
	: World(_World)
	, PlayerController(_PlayerController)
	, DrawingRange(_DrawingRange)
	, MaximumLOD(_MaximumLOD)
{
	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("CheckPosition"), 0, TPri_BelowNormal);
}

VoxelManager::~VoxelManager()
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

bool VoxelManager::Init()
{
	UE_LOG(VoxelArt, Log, TEXT("Octree Manager init"));
	return true;
}

uint32 VoxelManager::Run()
{
	FPlatformProcess::Sleep(0.03);

	FViewport* activeViewport = GEditor->GetActiveViewport();
	FEditorViewportClient* editorViewClient = (activeViewport != nullptr) ? (FEditorViewportClient*)activeViewport->GetClient() : nullptr;

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
#if WITH_EDITOR
			if (World->GetWorld() && (World->GetWorld()->WorldType == EWorldType::Editor || World->GetWorld()->WorldType == EWorldType::EditorPreview))
			{
				if (editorViewClient)
				{
					PlayerPositionToWorld = editorViewClient->GetViewLocation() - World->GetActorLocation();
				}
			}
			else
			{
				if (PlayerController->GetPawn() != nullptr)
				{
					PlayerPositionToWorld = PlayerController->GetPawn()->GetActorLocation() - World->GetActorLocation();
				}
			}
#endif
			if (PlayerPositionToWorld != OldPlayerPositionToWorld)
			{
				OldPlayerPositionToWorld = PlayerPositionToWorld;

				if (World->MaximumLOD > 0)
				{
					SCOPE_CYCLE_COUNTER(STAT_Run);

					ChangesOctree = TSharedPtr<FChunksRenderInfo>(new FChunksRenderInfo());
					{
						FScopeLock Lock(&World->OctreeMutex);
						CheckOctree(World->MainOctree);
					}
					if (ChangesOctree->ChunksCreation.Num() > 0 || ChangesOctree->ChunksRemoving.Num() > 0)
					{
						World->ChangesOctree.Enqueue(ChangesOctree);
					}
					ChangesOctree.Reset();
				}
			}
			FPlatformProcess::Sleep(0.01);
		}
	}
	return 0;
}

void VoxelManager::PauseThread()
{
	m_Pause = true;
}

void VoxelManager::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelManager::Stop()
{
	m_Kill = true;
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelManager::EnsureCompletion()
{
	if (ChangesOctree)
	{
		ChangesOctree->ChunksCreation.Empty();
		ChangesOctree->ChunksRemoving.Empty();

		ChangesOctree = nullptr;
	}
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();
	}
}

bool VoxelManager::IsThreadPaused()
{
	return (bool)m_Pause;
}

bool VoxelManager::CheckOctree(TSharedPtr<FVoxelOctreeData> Octant)
{
	float DistanceLODs = DrawingRange * Octant->Size; 
	float DistancePlayer = (PlayerPositionToWorld - Octant->Position).Size();

	if (!Octant->HasChildren())
	{
		if (World->MaximumLOD > Octant->Depth)
		{
			if (DistancePlayer <= DistanceLODs / 2.f)
			{
				/*Create new branch*/
				Octant->AddChildren();

				/*Remove old chunk*/
				if (Octant->Data != nullptr)
				{
					ChangesOctree->ChunksRemoving.Add(Octant->Data->Chunk);

					delete Octant->Data;
					Octant->Data = nullptr;
				}
				/*Create new chunks*/
				for (auto& Leaf : Octant->GetChildren())
				{
					if (!CheckOctree(Leaf))
					{
						ChangesOctree->ChunksCreation.Add(new FVoxelChunkData(Leaf, Leaf->Position, Leaf->Size, World->VoxelsPerChunk, DistancePlayer));
					}
				}
				return true;
			}
		}
	}
	else if (Octant->HasChildren())
	{
		if (!(DistancePlayer <= DistanceLODs / 2.f) && World->MinimumLOD < Octant->Depth + 1) 
		{
			/*Create old chunk*/
			ChangesOctree->ChunksCreation.Add(new FVoxelChunkData(Octant, Octant->Position, Octant->Size, World->VoxelsPerChunk, DistancePlayer));

			/*Remove old chunks*/
			for (auto& Leaf : GetLeavesChunk(Octant))
			{
				if (Leaf->Data != nullptr)
				{
					ChangesOctree->ChunksRemoving.Add(Leaf->Data->Chunk);

					delete Octant->Data;
					Octant->Data = nullptr;
				}
			}
			/*Remove old branch*/
			Octant->DestroyChildren();
		}
		else
		{
			for (auto& ChildOctant : Octant->GetChildren())
			{
				CheckOctree(ChildOctant);
			}
		}
	}
	return false;
}


TArray<TSharedPtr<FVoxelOctreeData>> VoxelManager::GetLeavesChunk(TSharedPtr<FVoxelOctreeData> chunk)
{
	TArray<TSharedPtr<FVoxelOctreeData>> candidates;
	{
		if (!chunk->HasChildren())
		{
			candidates.Add(chunk);
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				TArray <TSharedPtr<FVoxelOctreeData>> candidatesSmaller = GetLeavesChunk(chunk->ChildrenChunks[i]);

				for (auto it : candidatesSmaller)
				{
					candidates.Add(it);
				}
			}
		}
	}
	return candidates;
}