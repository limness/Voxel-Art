
// Fill out your copyright notice in the Description page of Project Settings.

#include "Octree/VoxelManager.h"
#include "VoxelLandscape.h"

#include "Editor.h"
#include "EditorViewportClient.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

VoxelManager::VoxelManager(AVoxelLandscape* _World, APlayerController* _PlayerController, float _UpdatingOctreeRadius, int _MaximumLOD) 
	: World(_World)
	, PlayerController(_PlayerController)
	, UpdatingOctreeRadius(_UpdatingOctreeRadius)
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
	UE_LOG(LogTemp, Warning, TEXT("[ Voxel Art Plugin : Octree Manager init ]"));
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
			if (World->maximumLOD > 0)
			{
				chunksToChange = new FChunksRenderInfo();
				{
					FScopeLock Lock(&World->OctreeMutex);
					CheckOctree(World->MainOctree, 0);
				}
				if (chunksToChange->ChunksCreation.Num() > 0 ||
					chunksToChange->ChunksRemoving.Num() > 0 ||
					chunksToChange->LeavesCreation.Num() > 0 ||
					chunksToChange->LeavesDestroying.Num() > 0)
				{
					for (auto& it : chunksToChange->ChunksCreation)
					{
						World->ChunksCreationGroup.Enqueue(it);
					}
					for (auto& it : chunksToChange->ChunksRemoving)
					{
						World->ChunksRemovingGroup.Enqueue(it);
					}
				}
				//chunksToChange = nullptr;
				//delete chunksToChange;
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
	if (chunksToChange)
	{
		chunksToChange->LeavesCreation.Empty();
		chunksToChange->LeavesDestroying.Empty();
		chunksToChange->ChunksCreation.Empty();
		chunksToChange->ChunksRemoving.Empty();

		chunksToChange = nullptr;
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

int VoxelManager::CheckOctree(TSharedPtr<FVoxelOctreeData> chunk, int level)
{
	float distanceLODs = UpdatingOctreeRadius;
	float radiusChunk = chunk->radius;

	for (int LevelSize = 0; LevelSize < level; LevelSize++)
	{
		distanceLODs = (float)(distanceLODs / 2.f);
	}
	if (!chunk->cUpdating)
	{
		if (!chunk->HasChildren())
		{
			float distancePlayer = sqrt(
				pow(PlayerPositionToWorld.X - chunk->position.X, 2) +
				pow(PlayerPositionToWorld.Y - chunk->position.Y, 2) +
				pow(PlayerPositionToWorld.Z - chunk->position.Z, 2)
			);

			if (distancePlayer <= distanceLODs / 2.f)
			{
				for (int i = 0; i < 8; i++)
				{
					int X = i % 2;
					int Y = i % 4 / 2;
					int Z = i / 4;

					float radiusChild = (float)(radiusChunk / 2.f);
					FVector positionChunkLittle = FVector(
						X * radiusChild + chunk->position.X - radiusChild / 2.f,
						Y * radiusChild + chunk->position.Y - radiusChild / 2.f,
						Z * radiusChild + chunk->position.Z - radiusChild / 2.f
					);

					TSharedPtr<FVoxelOctreeData> ChildLeaf(new FVoxelOctreeData());
					bool GetExistLeafFromHash = World->SavedChunks.RemoveAndCopyValue((chunk->nodeID << 3) | i, ChildLeaf);

					if (!GetExistLeafFromHash)
					{
						ChildLeaf->nodeID = (chunk->nodeID << 3) | i;
						ChildLeaf->ParentChunk = chunk;
						ChildLeaf->priority = distancePlayer;
						ChildLeaf->position = positionChunkLittle;
						ChildLeaf->transvoxelDirection = 0x00;
						ChildLeaf->level = level + 1;
						ChildLeaf->radius = radiusChild;
					}
					else
					{
						ChildLeaf->ParentChunk = chunk;
					}

					if (World->maximumLOD > level + 1)
					{
						TArray<TSharedPtr<FVoxelOctreeData>> candidates = CheckOctreeWithoutExist(ChildLeaf, level + 1);
						ChildLeaf->CreateChildren(candidates);
					}
					TArray<TSharedPtr<FVoxelOctreeData>> ChunksToGeneration = GetLeavesChunk(ChildLeaf);

					for (auto it : ChunksToGeneration)
					{
						TSharedPtr<FVoxelChunkRenderData> ChunkCreation(new FVoxelChunkRenderData());
						ChunkCreation->CurrentOctree = it;
						ChunkCreation->level = it->level;
						ChunkCreation->nodeID = it->nodeID;
						ChunkCreation->position = it->position;
						ChunkCreation->priority = it->priority;
						ChunkCreation->radius = it->radius;
						ChunkCreation->transvoxelDirection = it->transvoxelDirection;

						chunksToChange->ChunksCreation.Add(ChunkCreation);
					}
					//chunksToChange->LeavesCreation.Add(chunkLittle);
					chunk->ChildrenChunks.Add(ChildLeaf);
				}

				if (IsValid(chunk->chunk))
				{
					if (chunk->chunk->Active == true)
					{
						chunksToChange->ChunksRemoving.Add(chunk->chunk);
						chunk->chunk = nullptr;
					}
				}
			}
		}
		else if (chunk->HasChildren())
		{
			if (World->minimumLOD < level + 1)
			{
				int farFromPlayer = 0;

				for (int i = 0; i < 8; i++)
				{
					if (!chunk->ChildrenChunks[i]->HasChildren())
					{
						//if (chunk->ChildrenChunks[i]->cUpdating == false)
						{
							float distancePlayer = sqrt(
								pow(PlayerPositionToWorld.X - chunk->ChildrenChunks[i]->position.X, 2) +
								pow(PlayerPositionToWorld.Y - chunk->ChildrenChunks[i]->position.Y, 2) +
								pow(PlayerPositionToWorld.Z - chunk->ChildrenChunks[i]->position.Z, 2)
							);

							if (!(distancePlayer <= distanceLODs / 2.f))
							{
								farFromPlayer += 1;
							}
						}
					}
				}

				if (farFromPlayer == 8)
				{
				//	chunk->cUpdating = true;

					TSharedPtr<FVoxelChunkRenderData> ChunkCreation(new FVoxelChunkRenderData());
					ChunkCreation->CurrentOctree = chunk;
					ChunkCreation->level = chunk->level;
					ChunkCreation->nodeID = chunk->nodeID;
					ChunkCreation->position = chunk->position;
					ChunkCreation->priority = chunk->priority;
					ChunkCreation->radius = chunk->radius;
					ChunkCreation->transvoxelDirection = chunk->transvoxelDirection;

					for (auto it : GetLeavesChunk(chunk))
					{
						if (IsValid(it->chunk))
						{
							if (it->chunk->Active == true)
							{
								chunksToChange->ChunksRemoving.Add(it->chunk);
								it->chunk = nullptr;
							}
						}
					}

					//chunksToChange->LeavesDestroying.Add(chunk);
					chunk->DestroyChildren();

					chunksToChange->ChunksCreation.Add(ChunkCreation);
				}
				else
				{
				//	chunk->cUpdating = false;
				}
			}
			//if (!chunk->cUpdating)
			{
				if (World->maximumLOD > level + 1)
				{
					for (auto child : chunk->GetChildren())
					{
						CheckOctree(child, level + 1);
					}
				}
			}
		}
	}
	return 0;
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

TArray<TSharedPtr<FVoxelOctreeData>> VoxelManager::CheckOctreeWithoutExist(TSharedPtr<FVoxelOctreeData> chunk, int level)
{
	TArray<TSharedPtr<FVoxelOctreeData>> chunkCandidates;

	float distanceLODs = UpdatingOctreeRadius;
	float radiusChunk = chunk->radius;
	float distancePlayer = sqrt(
		pow(PlayerPositionToWorld.X - chunk->position.X, 2) +
		pow(PlayerPositionToWorld.Y - chunk->position.Y, 2) +
		pow(PlayerPositionToWorld.Z - chunk->position.Z, 2)
	);

	for (int LevelSize = 0; LevelSize < level; LevelSize++)
	{
		distanceLODs = (float)(distanceLODs / 2.f);
	}

	if (distancePlayer <= distanceLODs / 2.f)
	{
		for (int i = 0; i < 8; i++)
		{
			int X = i % 2;
			int Y = i % 4 / 2;
			int Z = i / 4;

			float radiusChild = (float)(radiusChunk / 2.f);

			FVector positionChunkLittle = FVector(
				X * radiusChild + chunk->position.X - radiusChild / 2.f,
				Y * radiusChild + chunk->position.Y - radiusChild / 2.f,
				Z * radiusChild + chunk->position.Z - radiusChild / 2.f
			);

			TSharedPtr<FVoxelOctreeData> chunkLittle(new FVoxelOctreeData());
			bool GettingHash = World->SavedChunks.RemoveAndCopyValue((chunk->nodeID << 3) | i, chunkLittle);

			if(!GettingHash)
			{
				chunkLittle->nodeID = (chunk->nodeID << 3) | i;
				chunkLittle->ParentChunk = chunk;
				chunkLittle->priority = distancePlayer;
				chunkLittle->position = positionChunkLittle;
				chunkLittle->transvoxelDirection = 0x00;
				chunkLittle->level = level + 1;
				chunkLittle->radius = radiusChild;
			}
			else
			{
				chunkLittle->ParentChunk = chunk;
			}
			if (World->maximumLOD > level + 1)
			{
				TArray<TSharedPtr<FVoxelOctreeData>> candidates = CheckOctreeWithoutExist(chunkLittle, level + 1);
				chunkLittle->CreateChildren(candidates);
			}
			chunkCandidates.Add(chunkLittle);
		}
	}
	return chunkCandidates;
}