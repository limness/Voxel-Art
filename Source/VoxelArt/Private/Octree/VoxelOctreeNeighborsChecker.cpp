// Voxel Art Plugin 2021 ~ Copyright Limit

#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Octree/VoxelOctreeData.h"
#include "Helpers/VoxelTools.h"
#include "VoxelWorld.h"

namespace DirectionOctree
{
	// Up or Down 
	// Sourth or North 
	// West or East

	enum DirectionNode : uint8
	{
		W = 0x00,
		S = 0x00,
		D = 0x00,

		E = 0x01,
		N = 0x01,
		U = 0x01
	};

	enum DirectionNeighbors : uint8
	{
		FaceW = 0,
		FaceS = 1,
		FaceD = 2,
		FaceE = 3,
		FaceN = 4,
		FaceU = 5
	};
}

VoxelOctreeNeighborsChecker::VoxelOctreeNeighborsChecker(AVoxelWorld* _World)
	: World(_World)
{
	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("Voxel Octree Nehighbors Checker"), 0, TPri_BelowNormal);
}

VoxelOctreeNeighborsChecker::~VoxelOctreeNeighborsChecker()
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

bool VoxelOctreeNeighborsChecker::Init()
{
	UE_LOG(VoxelArt, Log, TEXT("Octree Neighbors Checker init"));
	return true;
}

uint32 VoxelOctreeNeighborsChecker::Run()
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
			ChangesOctree = TSharedPtr<FChunksRenderInfo>(new FChunksRenderInfo());
			{
				FScopeLock Lock(&World->OctreeMutex);
				CheckOctree(World->MainOctree, 0);
			}
			if (ChangesOctree->ChunksGeneration.Num() > 0)
			{
			//	World->ChangesOctree.Enqueue(ChangesOctree);
			}
			//ChangesOctree->ChunksGeneration.Empty();
			ChangesOctree.Reset();

			FPlatformProcess::Sleep(0.05f);
		}
	}
	return 0;
}

void VoxelOctreeNeighborsChecker::PauseThread()
{
	m_Pause = true;
}

void VoxelOctreeNeighborsChecker::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelOctreeNeighborsChecker::Stop()
{
	m_Kill = true;
	m_Pause = false;

	if (m_semaphore)
	{
		m_semaphore->Trigger();
	}
}

void VoxelOctreeNeighborsChecker::EnsureCompletion()
{
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();

		if (ChangesOctree)
		{
			ChangesOctree->ChunksGeneration.Empty();
			ChangesOctree.Reset();
		}
	}
}

bool VoxelOctreeNeighborsChecker::IsThreadPaused()
{
	return (bool)m_Pause;
}

template<uint8 Direction>
TWeakPtr<FVoxelOctreeData> VoxelOctreeNeighborsChecker::GetBiggestNeighbor(int level, uint64 nodeID)
{
	TWeakPtr<FVoxelOctreeData> candidateNeighbor = nullptr;

	//get last two bits of ID
	uint8 DirectionNode = (uint8)(nodeID << 5) >> 5;

	//get height of our node (Up or Down)
	uint8 H = (uint8)(DirectionNode << 5) >> 7;

	//get deph of our node (Sourth or North)
	uint8 D = (uint8)(DirectionNode << 6) >> 7;

	//get width of our node (West or East)
	uint8 W = (uint8)(DirectionNode << 7) >> 7;

	//set our side using H D W
	uint8 side = GetSideNeighbor<Direction>(H, D, W);

	//Direction / 3 transfer
	//our global direction to local

	if (side == Direction / 3)
	{
		//If our chunk is on North DirectionNode
		//then we should look for neighbors on the node above
		if (level - 1 >= 1)
		{
			candidateNeighbor = GetBiggestNeighbor<Direction>(level - 1, nodeID >> 3);
		}
	}
	else if (side == (uint8)(!(Direction / 3)))
	{
		uint64 chunkNeighborNodeID = ((nodeID >> 3) << 3) | GetLocalNeighbor<Direction>(H, D, W);

		candidateNeighbor = GetChunkByNodeID(level, chunkNeighborNodeID);
	}

	return candidateNeighbor;
}


template<uint8 Direction>
TArray<TWeakPtr<FVoxelOctreeData>> VoxelOctreeNeighborsChecker::GetSmallerNeighbors(int level, int chunkLevel, uint64 chunkNodeID, TWeakPtr<FVoxelOctreeData> biggestNeighbor)
{
	TArray<TWeakPtr<FVoxelOctreeData>> candidates;

	//	if (!biggestNeighbor.Pin()->cUpdating)
	{
		if (biggestNeighbor.Pin()->ChildrenChunks.Num() == 8 && level <= chunkLevel)
		{
			if (level >= chunkLevel)
			{
				for (int i = 0; i < 8; i++)
				{
					//get height of our node (Up or Down)
					uint8 W = (uint8)(i % 2);

					//get deph of our node (Sourth or North)
					uint8 D = (uint8)(i % 4 / 2);

					//get width of our node (West or East)
					uint8 H = (uint8)(i / 4);

					//set our side using H D W
					uint8 side = GetSideNeighbor<Direction>(H, D, W);

					if (side == (uint8)(!(Direction / 3)))
					{
						//go to the next chunks
						TArray<TWeakPtr<FVoxelOctreeData>> candidatesSmaller = GetSmallerNeighbors<Direction>(level + 1, chunkLevel, chunkNodeID, biggestNeighbor.Pin()->ChildrenChunks[i]);

						//after we got candidates on level Down
						//we need add these to our main Array

						for (auto it : candidatesSmaller)
						{
							candidates.Add(it);
						}
					}
				}
			}
			else
			{
				//getting nodeID of biggest chunk where is our chunk
				//but we need to get nodeID of chunk which is level Down

				uint64 privateNodeID = chunkNodeID >> ((chunkLevel - 1 - level) * 3);

				//transfer our global location to local
				//and we got our index of chunk that has to check in the next iteration

				uint8 DirectionNode = (uint8)(privateNodeID << 5) >> 5;

				//get height of our node (Up or Down)
				uint8 H = (uint8)(DirectionNode << 5) >> 7;

				//get deph of our node (Sourth or North)
				uint8 D = (uint8)(DirectionNode << 6) >> 7;

				//get width of our node (West or East)
				uint8 W = (uint8)(DirectionNode << 7) >> 7;

				//get index using inverse
				uint8 indexSmallerChunk = GetLocalNeighborInverse<Direction>(H, D, W);

				//go to the next chunks
				TArray<TWeakPtr<FVoxelOctreeData>> candidatesSmaller = GetSmallerNeighbors<Direction>(level + 1, chunkLevel, chunkNodeID, biggestNeighbor.Pin()->ChildrenChunks[indexSmallerChunk]);

				//after we got candidates on level Down
				//we need add these to our main Array

				//m_mutex.Lock();
				for (auto it : candidatesSmaller)
				{
					candidates.Add(it);
				}
			}
		}
		else
		{
			//our chunks hasn't little chunks
			//it means we should add it to our array of candidates

			candidates.Add(biggestNeighbor);
		}
	}
	return candidates;
}

TWeakPtr<FVoxelOctreeData> VoxelOctreeNeighborsChecker::GetChunkByNodeID(int level, uint64 nodeID)
{
	return FindNodeByID((World->MainOctree), level, 0, nodeID);
}

TWeakPtr<FVoxelOctreeData> VoxelOctreeNeighborsChecker::FindNodeByID(TWeakPtr<FVoxelOctreeData> chunk, int levelTo, int level, uint64 nodeID)
{
	TWeakPtr<FVoxelOctreeData> candidate = nullptr;

	if (nodeID == chunk.Pin()->NodeID)
	{
		candidate = chunk;
	}
	else
	{
		if (chunk.Pin()->HasChildren())
		{
			if (level + 1 <= World->MaximumLOD)
			{
				for (auto& child : chunk.Pin()->GetChildren())
				{
					uint64 privateNodeID = nodeID >> ((levelTo - 1 - level) * 3);

					if (privateNodeID == child->NodeID) //here
					{
						candidate = FindNodeByID(child, levelTo, level + 1, nodeID);
					}
					if (candidate.IsValid())
					{
						break;
					}
				}
			}
		}
	}
	return candidate;
}

template<uint8 Direction>
TArray<TWeakPtr<FVoxelOctreeData>> VoxelOctreeNeighborsChecker::GetNodeNeighbors(int level, uint64 nodeID)
{
	TArray<TWeakPtr<FVoxelOctreeData>> smallerNeighbors;
	TWeakPtr<FVoxelOctreeData> biggerNeighbor = GetBiggestNeighbor<Direction>(level, nodeID);

	if (biggerNeighbor.Pin().IsValid())
	{
		//if (!biggerNeighbor.Pin()->cUpdating)
		{
			smallerNeighbors = GetSmallerNeighbors<Direction>(biggerNeighbor.Pin()->Depth, level, nodeID, biggerNeighbor);
		}
	}
	return smallerNeighbors;
}

bool VoxelOctreeNeighborsChecker::CheckOctree(TSharedPtr<FVoxelOctreeData> Octant, int level)
{
	if (!Octant->HasChildren())
	{
		if (Octant->Data != nullptr)
		{
			if (IsValid(Octant->Data->Chunk) && Octant->Data->Chunk->IsPoolActive())
			{
				{
					uint8 TransitionSides = 0x00;
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceN = GetNodeNeighbors<DirectionOctree::FaceN>(Octant->Depth, Octant->NodeID);
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceS = GetNodeNeighbors<DirectionOctree::FaceS>(Octant->Depth, Octant->NodeID);
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceE = GetNodeNeighbors<DirectionOctree::FaceE>(Octant->Depth, Octant->NodeID);
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceW = GetNodeNeighbors<DirectionOctree::FaceW>(Octant->Depth, Octant->NodeID);
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceD = GetNodeNeighbors<DirectionOctree::FaceD>(Octant->Depth, Octant->NodeID);
					TArray<TWeakPtr<FVoxelOctreeData>> candidateNeighborFaceU = GetNodeNeighbors<DirectionOctree::FaceU>(Octant->Depth, Octant->NodeID);

					TransitionSides = ((uint8)(candidateNeighborFaceN.Num() > 1) << 3) |
						((uint8)(candidateNeighborFaceS.Num() > 1) << 2) |
						((uint8)(candidateNeighborFaceE.Num() > 1) << 1) |
						((uint8)(candidateNeighborFaceW.Num() > 1) << 0) |
						((uint8)(candidateNeighborFaceD.Num() > 1) << 4) |
						((uint8)(candidateNeighborFaceU.Num() > 1) << 5);

					if (Octant->Data->TransitionSides != TransitionSides)
					//if(false)
					{
						Octant->Data->TransitionSides = TransitionSides;

						ChangesOctree->ChunksGeneration.Add(Octant->Data);
					}
				}
			}
		}
	}
	else if (Octant->HasChildren())
	{
		if (level + 1 <= World->MaximumLOD)
		{
			for (auto& ChildOctant : Octant->GetChildren())
			{
				CheckOctree(ChildOctant, level + 1); // here
			}
		}
	}
	return true;
}

template<uint8 Direction>
uint8 VoxelOctreeNeighborsChecker::GetLocalNeighbor(uint8 H, uint8 D, uint8 W)
{
	switch (Direction)
	{
	case DirectionOctree::FaceU: { H = DirectionOctree::U; break; }
	case DirectionOctree::FaceD: { H = DirectionOctree::D; break; }
	case DirectionOctree::FaceN: { D = DirectionOctree::N; break; }
	case DirectionOctree::FaceS: { D = DirectionOctree::S; break; }
	case DirectionOctree::FaceW: { W = DirectionOctree::W; break; }
	case DirectionOctree::FaceE: { W = DirectionOctree::E; break; }
	default: { break; }
	}

	return (uint8)((H << 2) | (D << 1) | (W << 0));
}

template<uint8 Direction>
uint8 VoxelOctreeNeighborsChecker::GetLocalNeighborInverse(uint8 H, uint8 D, uint8 W)
{
	switch (Direction)
	{
	case DirectionOctree::FaceU: { H = DirectionOctree::D; break; }
	case DirectionOctree::FaceD: { H = DirectionOctree::U; break; }
	case DirectionOctree::FaceN: { D = DirectionOctree::S; break; }
	case DirectionOctree::FaceS: { D = DirectionOctree::N; break; }
	case DirectionOctree::FaceW: { W = DirectionOctree::E; break; }
	case DirectionOctree::FaceE: { W = DirectionOctree::W; break; }
	default: { break; }
	}

	return (uint8)((H << 2) | (D << 1) | (W << 0));
}

template<uint8 Direction>
uint8 VoxelOctreeNeighborsChecker::GetSideNeighbor(uint8 H, uint8 D, uint8 W)
{
	uint8 side = 0x00;

	switch (Direction)
	{
	case DirectionOctree::FaceU: { side = H; break; }
	case DirectionOctree::FaceD: { side = H; break; }
	case DirectionOctree::FaceN: { side = D; break; }
	case DirectionOctree::FaceS: { side = D; break; }
	case DirectionOctree::FaceW: { side = W; break; }
	case DirectionOctree::FaceE: { side = W; break; }
	default: { break; }
	}
	return side;
}