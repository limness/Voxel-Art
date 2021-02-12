
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
	float distanceLODs = DrawingRange * Octant->radius; 
	float DistancePlayer = (PlayerPositionToWorld - Octant->position).Size();

	if (!Octant->HasChildren())
	{
		if (World->MaximumLOD > Octant->level)
		{
			if (DistancePlayer <= distanceLODs / 2.f)
			{
				Octant->AddChildren();

				if (IsValid(Octant->chunk))
				{
					ChangesOctree->ChunksRemoving.Add(Octant->chunk);
					Octant->chunk = nullptr;
				}
				for (auto& Leaf : Octant->GetChildren())
				{
					bool IsDivided = CheckOctree(Leaf);

					if (!IsDivided)
					{
						TSharedPtr<FVoxelChunkRenderData> ChunkCreation(new FVoxelChunkRenderData());
						ChunkCreation->CurrentOctree = Leaf;
						ChunkCreation->position = Leaf->position;
						ChunkCreation->priority = DistancePlayer;
						ChangesOctree->ChunksCreation.Add(ChunkCreation);
					}
				}
				return true;
			}
		}
	}
	else if (Octant->HasChildren())
	{
		if (!(DistancePlayer <= distanceLODs / 2.f) && World->MinimumLOD < Octant->level + 1)
		{
			TSharedPtr<FVoxelChunkRenderData> ChunkCreation(new FVoxelChunkRenderData());
			ChunkCreation->CurrentOctree = Octant;
			ChunkCreation->position = Octant->position;
			ChunkCreation->priority = Octant->priority;
			ChangesOctree->ChunksCreation.Add(ChunkCreation);

			for (auto& Leaf : GetLeavesChunk(Octant))
			{
				if (IsValid(Leaf->chunk))
				{
					ChangesOctree->ChunksRemoving.Add(Leaf->chunk);
					Leaf->chunk = nullptr;
				}
			}
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