// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Octree/VoxelOctreeManager.h"
#include "Octree/VoxelOctreeData.h"
#include "Helpers/VoxelTools.h"
#include "VoxelWorld.h"

DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker"), STAT_Run, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Player Data"), STAT_PlayerData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Add Children"), STAT_AddChildren, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Destroy Children"), STAT_DestroyChildren, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Add Remove Data"), STAT_AddRemoveData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Add Create Data"), STAT_AddCreateData, STATGROUP_Voxel);
DECLARE_CYCLE_STAT(TEXT("Voxel Manager ~ Octree Checker ~ Add Remove Chunk"), STAT_AddRemoveChunk, STATGROUP_Voxel);


VoxelOctreeManager::VoxelOctreeManager(AVoxelWorld* _World, uint8 _DrawingRange, int _MaximumLOD)
	: World(_World)
	, DrawingRange(_DrawingRange)
	, MaximumLOD(_MaximumLOD)
{
	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("Voxel Octree Manager"), 0, TPri_BelowNormal);
}

VoxelOctreeManager::~VoxelOctreeManager()
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

bool VoxelOctreeManager::Init()
{
	UE_LOG(VoxelArt, Log, TEXT("Octree Manager init"));
	return true;
}

uint32 VoxelOctreeManager::Run()
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
			if (World->MaximumLOD > 0)
			{
				float PlayerVelocity = 0.f;

				if (World->GetVoxelScenePlayer())
				{
					SCOPE_CYCLE_COUNTER(STAT_PlayerData);

					PlayerPositionToWorld = World->TransferToVoxelWorld(World->GetVoxelScenePlayer()->GetActorLocation());
					PlayerVelocity = World->GetVoxelScenePlayer()->GetVoxelVelocity() / 100;
				}
				if (PlayerVelocity < World->MaxPlayerVelocity)
				{
					if (PlayerPositionToWorld != OldPlayerPositionToWorld)
					{
						OldPlayerPositionToWorld = PlayerPositionToWorld;

						SCOPE_CYCLE_COUNTER(STAT_Run);

						ChangesOctree = TSharedPtr<FChunksRenderInfo>(new FChunksRenderInfo());
						FScopeLock Lock(&World->OctreeMutex);

						{

							CheckOctree(World->MainOctree);

						//	CheckTemporaryOctants();
						}
						if (ChangesOctree->ChunksCreation.Num() > 0 || ChangesOctree->ChunksRemoving.Num() > 0)
						{
							World->ChangesOctree.Enqueue(ChangesOctree);
						}
						/*
						* After the first Octree update, we have to enable
						* the update in the game branch to then update the priority and update this
						*/
						if (!World->bEnableUpdateOctree)
						{
							World->bEnableUpdateOctree = true;
						}
						ChangesOctree.Reset();
					}
				}
			}
			FPlatformProcess::Sleep(0.01f);
		}
	}
	return 0;
}

void VoxelOctreeManager::PauseThread()
{
	m_Pause = true;
}

void VoxelOctreeManager::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelOctreeManager::Stop()
{
	m_Kill = true;
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelOctreeManager::EnsureCompletion()
{
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();

		if (ChangesOctree)
		{
			ChangesOctree->ChunksCreation.Empty();
			ChangesOctree->ChunksRemoving.Empty();

			ChangesOctree.Reset();
		}
	}
}

bool VoxelOctreeManager::IsThreadPaused()
{
	return (bool)m_Pause;
}

void VoxelOctreeManager::CheckTemporaryOctants()
{
	if (World->TemporaryOctantsTest.Num() > 0)
	{
	//	UE_LOG(LogTemp, Warning, TEXT("World->TemporaryOctantsTest.Num() %d"), World->TemporaryOctantsTest.Num());

		for (int32 Index = World->TemporaryOctantsTest.Num(); Index != 0; Index--)
		{
			auto& Octant = World->TemporaryOctantsTest[Index - 1];
			
			if (!IsValid(Octant->Chunk))
			{
				continue;
			}

			if (!Octant->Chunk->MeshComplete)
			{
				continue;
			}
			//AsyncTask(ENamedThreads::GameThread, [=]()
				//{
				///	World->VoxelDebugBox(World->TransferToGameWorld(Octant->Position), Octant->Size / 2 * World->VoxelMin, 250.f, FColor::Red);
				//});

			//if(Octant.I)
			float DistanceLODs = DrawingRange * Octant->Size * 2;
			float DistancePlayer = (PlayerPositionToWorld - Octant->Position).Size();

			// Add a check for LOD minimum in a case there are errors

			if (World->MinimumLOD < Octant->Depth + 1)
			{
				if (!(DistancePlayer - Octant->Size / 2 <= DistanceLODs/* / 2.f*/))
				{
					ChangesOctree->ChunksForceRemoving.Add(Octant);
					World->TemporaryOctantsTest.RemoveAt(Index - 1);
				}
			}
		}
	}
}

bool VoxelOctreeManager::CheckOctree(TSharedPtr<FVoxelOctreeData> Octant)
{
	float DistanceLODs = DrawingRange * Octant->Size; 
	float DistancePlayer = (PlayerPositionToWorld - Octant->Position).Size();

	if (!Octant->HasChildren())
	{
		if (World->MaximumLOD > Octant->Depth)
		{
			if (DistancePlayer <= DistanceLODs/* / 2.f*/)
			{
				/*Create new branch*/
				{
					SCOPE_CYCLE_COUNTER(STAT_AddChildren);

					//FScopeLock Lock(&World->OctreeMutex);
					Octant->AddChildren();
				}
				/*Remove old chunk*/
				{
					SCOPE_CYCLE_COUNTER(STAT_AddRemoveChunk);

					if (Octant->Data != nullptr)
					{
						if (Octant->Data->TemporaryChunk)
						{
							ChangesOctree->ChunksForceRemoving.Add(Octant->Data);
						}
						else
						{
							ChangesOctree->ChunksRemoving.Add(Octant->Data);
						}
						//FScopeLock Lock(&World->OctreeMutex);
						Octant->Data = nullptr;
					}
				}
				/*Create new chunks*/
				{
					SCOPE_CYCLE_COUNTER(STAT_AddCreateData);

					for (auto& Leaf : Octant->GetChildren())
					{
						if (!CheckOctree(Leaf))
						{
							ChangesOctree->ChunksCreation.Add(new FVoxelChunkData(Leaf, Leaf->Depth, Leaf->Position, Leaf->Size, World->VoxelsPerChunk, DistancePlayer));
						}
					}
				}
				return true;
			}
		}
	}
	else if (Octant->HasChildren())
	{
		if (World->MinimumLOD < Octant->Depth + 1)
		{
			if (!(DistancePlayer <= DistanceLODs/* / 2.f*/))
			{
				/*Create old chunk*/
				{
					SCOPE_CYCLE_COUNTER(STAT_AddRemoveData);

					ChangesOctree->ChunksCreation.Add(new FVoxelChunkData(Octant, Octant->Depth, Octant->Position, Octant->Size, World->VoxelsPerChunk, DistancePlayer));
				}
				/*Remove old chunks*/
				{
					SCOPE_CYCLE_COUNTER(STAT_AddRemoveChunk);

					for (auto& Leaf : GetLeavesChunk(Octant))
					{
						if (Leaf->Data != nullptr)
						{
							//FScopeLock Lock(&World->OctreeMutex);
							if (Leaf->Data->TemporaryChunk)
							{
								ChangesOctree->ChunksForceRemoving.Add(Leaf->Data);
							}
							else
							{
								ChangesOctree->ChunksRemoving.Add(Leaf->Data);
							}
							Octant->Data = nullptr;
						}
					}
				}
				/*Remove old branch*/
				{
					SCOPE_CYCLE_COUNTER(STAT_DestroyChildren);

					//FScopeLock Lock(&World->OctreeMutex);
					Octant->DestroyChildren();
				}
			}
			else
			{
				for (auto& ChildOctant : Octant->GetChildren())
				{
					CheckOctree(ChildOctant);
				}
			}
		}
	}
	return false;
}


TArray<TSharedPtr<FVoxelOctreeData>> VoxelOctreeManager::GetLeavesChunk(TSharedPtr<FVoxelOctreeData> chunk)
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