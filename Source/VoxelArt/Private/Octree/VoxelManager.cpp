
// Fill out your copyright notice in the Description page of Project Settings.

#include "Octree/VoxelManager.h"

#include "Editor.h"
#include "EditorViewportClient.h"

#include "VoxelLandscape.h"
//#include "VOXELENGINE421.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

VoxelManager::VoxelManager(
	AVoxelLandscape* _World,
	APlayerController* _PlayerController, 
	float _UpdatingOctreeRadius,
	int _MaximumLOD)
{
	World = _World;
	PlayerController = _PlayerController;
	UpdatingOctreeRadius = _UpdatingOctreeRadius;
	MaximumLOD = _MaximumLOD;

	if (OctreeCopy == nullptr)
	{

	}
	m_Kill = false;
	m_Pause = false;

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
	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Octree Manager init ]"));
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
			if (World->GetWorld()->WorldType == EWorldType::Editor || World->GetWorld()->WorldType == EWorldType::EditorPreview)
			{
				if (editorViewClient)
				{
					if (PlayerPositionToWorld != editorViewClient->GetViewLocation() - World->GetActorLocation())
					{
						PlayerPositionToWorld = editorViewClient->GetViewLocation() - World->GetActorLocation();
					}
					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Log: Generate Voxel World from Editor inside Voxel Manager %s"), *PlayerPositionToWorld.ToString());
				}
			}
			else
			{
			//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] Error: Generate Voxel World from game inside Voxel Manager"));

				if (PlayerController->GetPawn() != nullptr)
				{
					if (PlayerPositionToWorld != PlayerController->GetPawn()->GetActorLocation() - World->GetActorLocation())
					{
						PlayerPositionToWorld = PlayerController->GetPawn()->GetActorLocation() - World->GetActorLocation();
					}
				}
			}
#endif
			
			if (World->maximumLOD > 0)
			{
				FScopeLock Lock(&World->GlobalMutex);

				for (auto& chunk : World->ChunksCreation)
				{
					float distancePlayer = sqrt(
						pow(PlayerPositionToWorld.X - chunk->position.X, 2) +
						pow(PlayerPositionToWorld.Y - chunk->position.Y, 2) +
						pow(PlayerPositionToWorld.Z - chunk->position.Z, 2)
					);
					chunk->priority = distancePlayer;
				}
				World->ChunksCreation.Sort([](const TSharedPtr<FVoxelChunkRenderData> A, const TSharedPtr<FVoxelChunkRenderData> B)
					{
						return A->priority > B->priority;
					});

				chunksToChange = new FChunksRenderInfo();

				CheckOctree(World->chunksBuffer, 0);

				if (chunksToChange->ChunksCreation.Num() > 0 ||
					chunksToChange->ChunksRemoving.Num() > 0 ||
					chunksToChange->LeavesCreation.Num() > 0 ||
					chunksToChange->LeavesDestroying.Num() > 0 ||
					chunksToChange->ChunksGeneration.Num() > 0)
				{
					if (World->ChunksToRecomputeOctree.Num() > 0)
					{
						FChunksRenderInfo* renderInfo = World->ChunksToRecomputeOctree.Pop();

						renderInfo->LeavesCreation.Empty();
						renderInfo->LeavesDestroying.Empty();
						renderInfo->ChunksCreation.Empty();
						renderInfo->ChunksRemoving.Empty();
					}
				//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : LODManager ] Send data"));

					chunksToChange->ChunksCreation.Sort([](const TSharedPtr<FVoxelChunkRenderData> A, const TSharedPtr<FVoxelChunkRenderData> B)
						{
							return A->priority > B->priority;
						});
					World->ChunksToRecomputeOctree.Add(chunksToChange);
				}
			}
			FPlatformProcess::Sleep(0.11);
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

#include "DrawDebugHelpers.h"

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
				//Set the status "Updating" 
				//So our chunk doesn't get disturbed
				chunk->cUpdating = true;

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

					//FVoxelOctreeData* chunkLittle(new FVoxelOctreeData());
					//FVoxelOctreeData* chunkLittle = land->SavedChunks.FindAndRemoveChecked((chunk->nodeID << 3) | i);//(new FVoxelOctreeData());

					TSharedPtr<FVoxelOctreeData> chunkLittle(new FVoxelOctreeData());//(new FVoxelOctreeData());
					bool GettingHash = World->SavedChunks.RemoveAndCopyValue((chunk->nodeID << 3) | i, chunkLittle);

					if (!GettingHash)
					{
						chunkLittle->nodeID = (chunk->nodeID << 3) | i;
						chunkLittle->ParentChunk = chunk;
						chunkLittle->priority = distancePlayer;
						chunkLittle->position = positionChunkLittle;
						chunkLittle->x = X;
						chunkLittle->y = Y;
						chunkLittle->z = Z;
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
					TArray<TSharedPtr<FVoxelOctreeData>> ChunksToGeneration = GetLeavesChunk(chunkLittle);

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

						//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin ] creating node %d removing %p chunk from node %d"), it->nodeID, chunk->chunk, chunk->nodeID);

					//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : LODManager ] hasn't children chunk creation leaf %p %d"), it.Get(), it->nodeID);

					//	chunk->ChunksShouldBeRemovedCounter += 1;
					//	ChunkCreation->ChunksShouldBeRemoved.Add(chunk->chunk);

						chunksToChange->ChunksCreation.Add(ChunkCreation);
						//chunksToChange->ChunksGeneration.Add(it);
					}
					chunksToChange->LeavesCreation.Add(chunkLittle);
				}

				if (IsValid(chunk->chunk))
				{
					if (chunk->chunk->Active == true)
					{
						chunksToChange->ChunksRemoving.Add(chunk->chunk);
						chunk->chunk = nullptr;
					}
				}

			//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : LODManager ] hasn't removing %p %d"), chunk->chunk, chunk->nodeID);
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
						if (chunk->ChildrenChunks[i]->cUpdating == false)
						{
							//FVector positionChunk = chunk->ChildrenChunks[i]->position;

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
					chunk->cUpdating = true;
					//chunk->kostyl = true;

					TArray<TSharedPtr<FVoxelOctreeData>> ChunksToGeneration = GetLeavesChunk(chunk);
						
					/*bool GridIsExist = false;

						
					if(GridIsExist)
					{
						int voxels = land->voxelsOneChunk;

						chunk->Grid.Init(-1.0, (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT));

						uint32 Index = 0;

						for (auto it : ChunksToGeneration)
						{
							int X = Index % 2;
							int Y = Index % 4 / 2;
							int Z = Index / 4;

							if (it->chunk != nullptr)
							{
								for (int ZChildren = NORMALS_SKIRT_HALF, ZParent = NORMALS_SKIRT_HALF + Z * voxels / 2; ZChildren < voxels + 1 + NORMALS_SKIRT_HALF; ZChildren += 2, ZParent++)
								{
									for (int YChildren = NORMALS_SKIRT_HALF, YParent = NORMALS_SKIRT_HALF + Y * voxels / 2; YChildren < voxels + 1 + NORMALS_SKIRT_HALF; YChildren += 2, YParent++)
									{
										for (int XChildren = NORMALS_SKIRT_HALF, XParent = NORMALS_SKIRT_HALF + X * voxels / 2; XChildren < voxels + 1 + NORMALS_SKIRT_HALF; XChildren += 2, XParent++)
										{
											chunk->Grid[XParent + YParent * (voxels + 1 + NORMALS_SKIRT) + ZParent * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] =
												it->chunk->Grid[XChildren + YChildren * (voxels + 1 + NORMALS_SKIRT) + ZChildren * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
										}
									}
								}
							}
							Index++;
						}
					}*/

					TSharedPtr<FVoxelChunkRenderData> ChunkCreation(new FVoxelChunkRenderData());
					ChunkCreation->CurrentOctree = chunk;
					ChunkCreation->level = chunk->level;
					ChunkCreation->nodeID = chunk->nodeID;
					ChunkCreation->position = chunk->position;
					ChunkCreation->priority = chunk->priority;
					ChunkCreation->radius = chunk->radius;
					ChunkCreation->transvoxelDirection = chunk->transvoxelDirection;

					for (auto it : ChunksToGeneration)
					{
					/*	if (it->chunk != nullptr)
						{
							if (it->chunk->hasOwnGrid)
							{
								GridIsExist = true;
							}
						}*/
						if (IsValid(it->chunk))
						{
							if (it->chunk->Active == true)
							{
								chunksToChange->ChunksRemoving.Add(it->chunk);
								it->chunk = nullptr;
							}
						}
						//		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : LODManager ] leaf %p has removing %p %d"), it.Get(), it->chunk, it->nodeID);
					}

					chunksToChange->LeavesDestroying.Add(chunk);
					chunksToChange->ChunksCreation.Add(ChunkCreation);


				//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : LODManager ] has children chunk creation leaf %p %d"), chunk.Get(), chunk->nodeID);
					//chunksToChange->ChunksGeneration.Add(chunk);
				}
				else
				{
					chunk->cUpdating = false;
				}
			}
			if (!chunk->cUpdating)
			{
				if (World->maximumLOD > level + 1)
				{
					for (int i = 0; i < 8; i++)
						//for (auto child : chunk->GetChildren())
					{
						CheckOctree(chunk->ChildrenChunks[i], level + 1);
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
				//if(chunk->ChildrenChunks[i])
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
				chunkLittle->x = X;
				chunkLittle->y = Y;
				chunkLittle->z = Z;
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