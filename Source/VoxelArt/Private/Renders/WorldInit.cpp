// Fill out your copyright notice in the Description page of Project Settings.

#include "Renders/WorldInit.h"

WorldInit::WorldInit()
{
}

void WorldInit::GenerateLandscape()
{
	/*for (int i = 0; i < levelOfDetail + 1; i++)
	{
		chunkLevel.Add(FPositionChunk());
	}
	for (int idchunk = 0; idchunk < 1; idchunk++)
	{
		chunkLevel[0].positionCHUNK.Add(FPositionChunk2());

		for (int z = 0; z < 2; z++)
		{
			chunkLevel[0].positionCHUNK[idchunk].positionZ.Add(FPositionChunk3());

			for (int y = 0; y < 2; y++)
			{
				chunkLevel[0].positionCHUNK[idchunk].positionZ[z].positionY.Add(FPositionChunk4());

				for (int x = 0; x < 2; x++)
				{
					FChunkInQueue newChunk;
					newChunk.id = idchunk;
					newChunk.x = x;
					newChunk.y = y;
					newChunk.z = z;
					newChunk.level = 0;
					SpawnChunkQueueTest(newChunk);
				}
			}
		}
	}

	CheckLod(0);

	for (int level = 0; level < chunkLevel.Num(); level++)
	{
		for (int idchunk = 0; idchunk < chunkLevel[level].positionCHUNK.Num(); idchunk++)
		{
			for (int z = 0; z < chunkLevel[level].positionCHUNK[idchunk].positionZ.Num(); z++)
			{
				for (int y = 0; y < chunkLevel[level].positionCHUNK[idchunk].positionZ[z].positionY.Num(); y++)
				{
					for (int x = 0; x < chunkLevel[level].positionCHUNK[idchunk].positionZ[z].positionY[y].positionX.Num(); x++)
					{
						if (IsValid(chunkLevel[level].positionCHUNK[idchunk].positionZ[z].positionY[y].positionX[x]))
						{
							FChunkInQueue newChunk;
							newChunk.regenerate = true;
							newChunk.level = chunkLevel[level].positionCHUNK[idchunk].positionZ[z].positionY[y].positionX[x]->level;
							newChunk.thisChunk = chunkLevel[level].positionCHUNK[idchunk].positionZ[z].positionY[y].positionX[x];
							RendererCheckPositionThreadHandle->setStack(newChunk);
						}
					}
				}
			}
		}
	}
	RendererCheckPositionThreadHandle->ContinueThread();*/
}