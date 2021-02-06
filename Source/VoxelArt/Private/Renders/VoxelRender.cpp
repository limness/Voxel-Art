
#include "Renders/VoxelRender.h"
#include "VoxelLandscape.h"
#include "Async/ParallelFor.h"
#include "Helpers/MarchingCubes.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/DateTime.h"

#define NORMALS_SKIRT 2
#define NORMALS_SKIRT_HALF 1

/*namespace EVoxelDirection
{
	enum Direction : uint8
	{
		MinimumX = 0x01,
		MaximumX = 0x02,
		MinimumY = 0x04,
		MaximumY = 0x08,
		MinimumZ = 0x10,
		MaximumZ = 0x20
	};
}*/

VoxelRender::VoxelRender(AActor* World, UVoxelLandscapeGenerator* GeneratorLandscape) :
	VoxelLand(World),
	Generator(GeneratorLandscape)
{
	m_Kill = false;
	m_Pause = false;

	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("RNGThread" + 1), 0, TPri_BelowNormal);

	// VoxelLandscapeGenerator* generator = Cast<UVoxelLandscapeGenerator>(generatorLandscape);
	// static_cast<UVoxelLandscapeGenerator*>(GeneratorLandscape);

	//if (Generator != nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] Log: generators's var is %f"), Generator->testvalT);
	//}
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

			AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

			if (land->MaximumLOD > 0)
			{
				//FScopeLock Lock(&land->GlobalMutex);


				
				/*CheckLod((land->chunksBuffer), 0);

				if (chunksToChange->ChunksGeneration.Num() > 0)
				{
					chunksToChange->ChunksGeneration.Sort([](const FVoxelOctreeData& A, const FVoxelOctreeData& B)
						{
							return A.priority < B.priority;
						});

					land->chunksRegenerate.Add((chunksToChange));
				}*/
			}
			/*TArray<FChunksRenderInfo*> renderArray;

			while (chunksInQueue.Peek(renderArray))
			{
				chunksInQueue.Dequeue(renderArray);

				AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

				for (auto renderInfo : renderArray)
				{
					for (auto it : renderInfo->ChunksGeneration)
					{
						//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] Time start: %d ms"), FDateTime::Now().GetTicks());

						Grid.Empty();
						Grid.Init(-1.0, (land->voxelsOneChunk + 1 + NORMALS_SKIRT) * (land->voxelsOneChunk + 1 + NORMALS_SKIRT) * (land->voxelsOneChunk + 1 + NORMALS_SKIRT));

						positionSide.Empty();
						positionSide.Init(FVector(0, 0, 0), (land->voxelsOneChunk + 1 + NORMALS_SKIRT) * (land->voxelsOneChunk + 1 + NORMALS_SKIRT) * (land->voxelsOneChunk + 1 + NORMALS_SKIRT));

						GenerateNoiseOnGrid(it->radius, it, -9999, -9999, -9999);

						//int timeBefore = FDateTime::Now().GetTicks();
						GenerateVertexCube(it->radius, it, true);
						//int timeNow = FDateTime::Now().GetTicks();

						//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] 1 Inside Time for generate: cubes %d ms"), timeNow - timeBefore);

						if (true) //chunkInitialize->level == land->maximumLOD 
						{
							it->Grid = Grid;
						}
						it->Vertices = Vertices;
						it->Triangles = Triangles;
						it->Colors = VertexColors;
						it->Normals = Normals;

						//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] Time gen: %d ms"), timeNow - timeBefore);

						//land->chunkInQueue.Enqueue(it);

					}
					land->chunkInQueue.Enqueue(renderInfo);
				}
			}*/
			FPlatformProcess::Sleep(0.5);
		}
	}

	return 0;
}

void VoxelRender::PauseThread()
{
	m_Pause = true;
}

void VoxelRender::setEnqueueChunk(TArray<FChunksRenderInfo*> chunkSet)
{
	chunksInQueue.Enqueue(chunkSet);
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

void VoxelRender::GenerateVertexCube(float radius, FVoxelOctreeData* chunkSpawn, bool regenerate)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	int voxels = land->voxelsOneChunk * 1;
	int level = chunkSpawn->level;

	int isolevel = 0;
	int normalIndex = 0;

	float radiusVoxel = GetVoxelSize(radius);

	uint8 transvoxelDirection = chunkSpawn->transvoxelDirection;

	FVector firstPoint, lastPoint;

	//ParallelFor(voxels + NORMALS_SKIRT_HALF, [&](int32 Idx)
	//{
	//	const int32 z = NORMALS_SKIRT_HALF + Idx;
	for (int z = NORMALS_SKIRT_HALF; z < voxels + NORMALS_SKIRT_HALF; z++)
	{
		for (int y = NORMALS_SKIRT_HALF; y < voxels + NORMALS_SKIRT_HALF; y++)
		{
			for (int x = NORMALS_SKIRT_HALF; x < voxels + NORMALS_SKIRT_HALF; x++)
			{
				//int timeNowOne = FDateTime::Now().GetTicks();

			//	int timeNow = FDateTime::Now().GetTicks();
				for (int i = 0; i < 8; i++)
				//if(false)
				{
					int X = (i + 1) % 4 / 2; //inverse tri
					int Y = i % 4 / 2;
					int Z = !(i / 4);

					/*	uint8 localMinimumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 0);
					uint8 localMaximumX = (uint8)(((x + X - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 1);

					uint8 localMinimumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 2);
					uint8 localMaximumY = (uint8)(((y + Y - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 3);

					uint8 localMinimumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0) << 4);
					uint8 localMaximumZ = (uint8)(((z + Z - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0) << 5);

					int MinimumX = (((transvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumX = (((transvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) ? 1 : 0) * ((x + X - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					int MinimumY = (((transvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumY = (((transvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) ? 1 : 0) * ((y + Y - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					int MinimumZ = (((transvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == 0) ? 1 : 0);
					int MaximumZ = (((transvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) ? 1 : 0) * ((z + Z - NORMALS_SKIRT_HALF == voxels - 0) ? 1 : 0);

					//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] minx %d %d %d"), MinimumX, MinimumY, MinimumZ);

					if (((localMinimumX || localMaximumX) & (localMinimumY || localMaximumY)) |
						((localMinimumY || localMaximumY) & (localMinimumZ || localMaximumZ)) |
						((localMinimumZ || localMaximumZ) & (localMinimumX || localMaximumX)))
					{
						uint8 maskSidesVertex = (localMaximumX | localMinimumX) | (localMaximumY | localMinimumY) | (localMaximumZ | localMinimumZ);

						if ((transvoxelDirection & maskSidesVertex) == maskSidesVertex)
						{
							//we don't need change anything
						}
						else
						{
							MinimumX = 0;
							MinimumY = 0;
							MinimumZ = 0;

							MaximumX = 0;
							MaximumY = 0;
							MaximumZ = 0;
						}
					}


					float transitionX = land->transitionSize * (X == 1 ? -MaximumX : MinimumX);
					float transitionY = land->transitionSize * (Y == 1 ? -MaximumY : MinimumY);
					float transitionZ = land->transitionSize * (Z == 1 ? -MaximumZ : MinimumZ);*/

					infoNoise[i] = Grid[(x + X) + (y + Y) * (voxels + 1 + NORMALS_SKIRT) + (z + Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];
					position[i] = FVector((x + X + 0 - NORMALS_SKIRT_HALF) * radiusVoxel, (y + Y + 0 - NORMALS_SKIRT_HALF) * radiusVoxel, (z + Z + 0 - NORMALS_SKIRT_HALF) * radiusVoxel) - (float)(radius / 2.f);

				//	positionSide[(x + X) + (y + Y) * (voxels + 1 + NORMALS_SKIRT) + (z + Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = position[i];
				}
			
				MarchingCubes(level, radius, isolevel, x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT), x, y, z, normalIndex, true);

				normalIndex++;
			}
		}
	//});
	}

	//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Checker Neighbors ] GenerateVertexCube transvoxelDirection %d"), transvoxelDirection);
	//int timeNow = FDateTime::Now().GetTicks();
	/*if (true)
	{
		if ((transvoxelDirection & EVoxelDirection::MinimumX) == EVoxelDirection::MinimumX) GeometryTransitionCubes<EVoxelDirection::MinimumX>(radius, chunkSpawn);
		if ((transvoxelDirection & EVoxelDirection::MaximumX) == EVoxelDirection::MaximumX) GeometryTransitionCubes<EVoxelDirection::MaximumX>(radius, chunkSpawn);

		if ((transvoxelDirection & EVoxelDirection::MinimumY) == EVoxelDirection::MinimumY) GeometryTransitionCubes<EVoxelDirection::MinimumY>(radius, chunkSpawn);
		if ((transvoxelDirection & EVoxelDirection::MaximumY) == EVoxelDirection::MaximumY) GeometryTransitionCubes<EVoxelDirection::MaximumY>(radius, chunkSpawn);

		if ((transvoxelDirection & EVoxelDirection::MinimumZ) == EVoxelDirection::MinimumZ) GeometryTransitionCubes<EVoxelDirection::MinimumZ>(radius, chunkSpawn);
		if ((transvoxelDirection & EVoxelDirection::MaximumZ) == EVoxelDirection::MaximumZ) GeometryTransitionCubes<EVoxelDirection::MaximumZ>(radius, chunkSpawn);

		positionSide.Empty();
	}
	positionSide.Empty();*/
	//int timeAfter = FDateTime::Now().GetTicks();
}

#include "Noise/SimplexNoiseBPLibrary.h"

void VoxelRender::GenerateNoiseOnGrid(float radiusOfChunk, FVoxelOctreeData* chunkSpawn, int x_little, int y_little, int z_little)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	int voxels = land->voxelsOneChunk;
	float radius = radiusOfChunk;

//	positionZ.Empty();
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	VertexColors.Empty();

	float radiusVoxel = GetVoxelSize(radius);

	//for (int z = 0; z < voxels + 1 + NORMALS_SKIRT; z++)
	//{
	ParallelFor(voxels + 1 + NORMALS_SKIRT, [&](int32 z)
		{
			for (int y = 0; y < voxels + 1 + NORMALS_SKIRT; y++)
			{
				for (int x = 0; x < voxels + 1 + NORMALS_SKIRT; x++)
				{
					FVector positionNoise;

					positionNoise.X = (x - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
					positionNoise.Y = (y - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
					positionNoise.Z = (z - NORMALS_SKIRT_HALF) * radiusVoxel - 0;
					positionNoise = positionNoise - (float)(radius / 2.f);

					// position of Chunk
					location = chunkSpawn->position;

					//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = GetValueNoise(positionNoise, chunkSpawn);

					//float noise = 0.f;

					// position of Land
					//positionNoise += chunkSpawn->position;
					//positionNoise -= land->GetActorLocation();

					//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = 200000.f - sqrt(positionNoise.X * positionNoise.X + positionNoise.Y * positionNoise.Y + positionNoise.Z * positionNoise.Z);

					//float value = 0.f;
					//float frequency = 0.00001f;
					//float amplitude = 8000.f;

					//USimplexNoiseBPLibrary::setNoiseSeed(seed);
/*
					for (int i = 0; i < 4; i++)
					{
						value += USimplexNoiseBPLibrary::SimplexNoise3D(positionNoise.X * frequency, positionNoise.Y * frequency, positionNoise.Z * frequency) * amplitude;
						frequency *= 3.75f;
						amplitude *= 0.25f;
					}*/
					Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = GetValueNoise(positionNoise, chunkSpawn);//-(positionNoise.Z - value);

					//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = -radius;
					//if (positionNoise.Z >= 0.f)
					//{
						//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = (-1) * UKismetMathLibrary::FMax(1.f, positionNoise.Z);
					//}
					//else if (positionNoise.Z < 0.f)
					//{
						//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = (-1) * UKismetMathLibrary::FMin(-1.f, positionNoise.Z);
					//}
					//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = noise;

					//if (Generator != nullptr)
					//{
						//float noise = 0.f;

					//	Generator->GetNoiseData(positionNoise.X, positionNoise.Y, positionNoise.Z, noise);

						//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = noise; //shouldbeMIN
					//}
				}
			}
		});
}

float VoxelRender::fbmNoise(FVector positionGrid, float H)
{
	float t = 0.0;
	
	for (int i = 0; i < 4; i++)
	{
		float frequency = 0.00001f * pow(3.75f, float(i));
		float amplitude = 8000.f * pow(0.25f, float(i));
		//t += a * noise(f * x);
		t += USimplexNoiseBPLibrary::SimplexNoise3D(positionGrid.X * frequency, positionGrid.Y * frequency, positionGrid.Z * frequency) * amplitude;
	}
	return t;
}

/*float VoxelRender::iqTurbulence(FVector2D p, float seed, int octaves, float lacunarity = 2.0, float gain = 0.5)
{
	float sum = 0.5;
	float freq = 1.0, amp = 1.0;

	FVector2D dsum = FVector2D(0, 0);

	for (int i = 0; i < octaves; i++)
	{
		FVector2D ds = FVector2D(p * freq);
		//FVector n = USimplexNoiseBPLibrary::SimplexNoise2D(ds.Y, ds.Y); //, seed + i / 256.0
		//dsum.X += n.Y;
	//	dsum.Y += n.Z;
	//	sum += amp * n.X / (1 + FVector::DotProduct(FVector(dsum.X, dsum.Y, 0), FVector(dsum.X, dsum.Y, 0)));
		freq *= lacunarity;
		amp *= gain;
	}
	return sum;
}*/

float VoxelRender::pattern(FVector p, float H)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	FVector q = FVector(fbmNoise(p + FVector(0.0, 0.0, 0.0), H), fbmNoise(p + FVector(5.2, 1.3, 0.0), H), H);

	return fbmNoise(p + 4.0 * q, H);
}

float VoxelRender::GetValueNoise(FVector positionGrid, FVoxelOctreeData* chunkSpawn)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	float noise = 0.f;

	// position of Land
	positionGrid += chunkSpawn->position;
	positionGrid -= land->GetActorLocation();

	//	float noise = 0.f;

		/*if (positionGrid.Z >= 0.f)
		{
			noise = (-1) * UKismetMathLibrary::FMax(1.f, positionGrid.Z);
		}
		else if (positionGrid.Z < 0.f)
		{
			noise = (-1) * UKismetMathLibrary::FMin(-1.f, positionGrid.Z);
		}*/

	float value = 0.f;
	float frequency = 0.00001f;
	float amplitude = 8000.f;


	for (int i = 0; i < 4; i++)
	{
		value += USimplexNoiseBPLibrary::SimplexNoise3D(positionGrid.X * frequency, positionGrid.Y * frequency, positionGrid.Z * frequency) * amplitude;
		frequency *= 3.75f;
		amplitude *= 0.25f;
	}
	//Grid[x + y * (voxels + 1 + NORMALS_SKIRT) + z * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)] = -(positionNoise.Z - value);

	//if (land->generatorLandscape != nullptr)
	//{
	//	land->generatorLandscape->GetNoiseData(positionGrid.X, positionGrid.Y, positionGrid.Z, noise);
	//}

	return -(positionGrid.Z - value);
}

void VoxelRender::MarchingCubes(int level, float radius, int isolevel, int indexGrid, int x, int y, int z, int normalIndex, bool regenerate)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	float rad = radius;

	int cubeIndex = 0;

	FVector vertList[12];
	FVector normList[12];

	if (infoNoise[0] < isolevel) cubeIndex |= 1;
	if (infoNoise[1] < isolevel) cubeIndex |= 2;
	if (infoNoise[2] < isolevel) cubeIndex |= 4;
	if (infoNoise[3] < isolevel) cubeIndex |= 8;
	if (infoNoise[4] < isolevel) cubeIndex |= 16;
	if (infoNoise[5] < isolevel) cubeIndex |= 32;
	if (infoNoise[6] < isolevel) cubeIndex |= 64;
	if (infoNoise[7] < isolevel) cubeIndex |= 128;

	/*
	0 // 0 0 1   
	1 // 1 0 1   
	2 // 1 1 1  
	3 // 0 1 1   
	4 // 0 0 0                                                                                                                                                                           
	5 // 1 0 0                                                                                                                                                                           
	6 // 1 1 0                                                                                                                                                                           
	7 // 0 1 0                                                                                                                                                                           
	Hello World  
	*/
	if (edgeTable[cubeIndex] == 0) return;

	if (edgeTable[cubeIndex] & 1)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 0, z + 1);

		vertList[0] = VertexInterp(position[0], position[1], normalOne, normalTwo, infoNoise[0], infoNoise[1], 0, normList[0]);
	}
	if (edgeTable[cubeIndex] & 2)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 1, z + 1);

		vertList[1] = VertexInterp(position[1], position[2], normalOne, normalTwo, infoNoise[1], infoNoise[2], 0, normList[1]);
	}
	if (edgeTable[cubeIndex] & 4)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 1, z + 1);

		vertList[2] = VertexInterp(position[2], position[3], normalOne, normalTwo, infoNoise[2], infoNoise[3], 0, normList[2]);
	}
	if (edgeTable[cubeIndex] & 8)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 0, z + 1);

		vertList[3] = VertexInterp(position[3], position[0], normalOne, normalTwo, infoNoise[3], infoNoise[0], 0, normList[3]);
	}
	if (edgeTable[cubeIndex] & 16)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 0);
		normalTwo = GetGradient(x + 1, y + 0, z + 0);

		vertList[4] = VertexInterp(position[4], position[5], normalOne, normalTwo, infoNoise[4], infoNoise[5], 0, normList[4]);
	}
	if (edgeTable[cubeIndex] & 32)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 0);
		normalTwo = GetGradient(x + 1, y + 1, z + 0);

		vertList[5] = VertexInterp(position[5], position[6], normalOne, normalTwo, infoNoise[5], infoNoise[6], 0, normList[5]);
	}
	if (edgeTable[cubeIndex] & 64)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 0);
		normalTwo = GetGradient(x + 0, y + 1, z + 0);

		vertList[6] = VertexInterp(position[6], position[7], normalOne, normalTwo, infoNoise[6], infoNoise[7], 0, normList[6]);
	}
	if (edgeTable[cubeIndex] & 128)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 0);
		normalTwo = GetGradient(x + 0, y + 0, z + 0);

		vertList[7] = VertexInterp(position[7], position[4], normalOne, normalTwo, infoNoise[7], infoNoise[4], 0, normList[7]);
	}
	if (edgeTable[cubeIndex] & 256)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 0, z + 1);
		normalTwo = GetGradient(x + 0, y + 0, z + 0);

		vertList[8] = VertexInterp(position[0], position[4], normalOne, normalTwo, infoNoise[0], infoNoise[4], 0, normList[8]);
	}
	if (edgeTable[cubeIndex] & 512)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 0, z + 1);
		normalTwo = GetGradient(x + 1, y + 0, z + 0);

		vertList[9] = VertexInterp(position[1], position[5], normalOne, normalTwo, infoNoise[1], infoNoise[5], 0, normList[9]);
	}
	if (edgeTable[cubeIndex] & 1024)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 1, y + 1, z + 1);
		normalTwo = GetGradient(x + 1, y + 1, z + 0);

		vertList[10] = VertexInterp(position[2], position[6], normalOne, normalTwo, infoNoise[2], infoNoise[6], 0, normList[10]);
	}
	if (edgeTable[cubeIndex] & 2048)
	{
		FVector normalOne, normalTwo;

		normalOne = GetGradient(x + 0, y + 1, z + 1);
		normalTwo = GetGradient(x + 0, y + 1, z + 0);

		vertList[11] = VertexInterp(position[3], position[7], normalOne, normalTwo, infoNoise[3], infoNoise[7], 0, normList[11]);
	}


	//FLinearColor flatColor = FLinearColor(0.f, 0.f, 0.f);

	//Generator->GetColor(location + position[4] + GetVoxelSizeHalf(radius), flatColor);
	//
	for (int i = 0; triTable[cubeIndex][i] != -1; i += 3) {

		Vertices.Add(vertList[triTable[cubeIndex][i]]);
		Triangles.Add(Triangles.Num());

		if (land->normalsSmoothing)
			Normals.Add(-normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal());
		else
			Normals.Add(-((normList[triTable[cubeIndex][i + 0]] + normList[triTable[cubeIndex][i + 1]] + normList[triTable[cubeIndex][i + 2]]) / 3.f).GetUnsafeNormal());
		//UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : Renderer ] gen: %f"), -normList[triTable[cubeIndex][i + 0]].GetUnsafeNormal().X);
		//if (land->vertexSubdivision)
		//	VertexColors.Add(flatColor);
		//else
		//	VertexColors.Add(Generator->GetColor(location + (vertList[triTable[cubeIndex][i + 0]] - (1 * radius) / 2.0f)));

		Vertices.Add(vertList[triTable[cubeIndex][i + 1]]);
		Triangles.Add(Triangles.Num());

		if (land->normalsSmoothing)
			Normals.Add(-normList[triTable[cubeIndex][i + 1]].GetUnsafeNormal());
		else
			Normals.Add(-((normList[triTable[cubeIndex][i + 0]] + normList[triTable[cubeIndex][i + 1]] + normList[triTable[cubeIndex][i + 2]]) / 3.f).GetUnsafeNormal());

		//if (land->vertexSubdivision)
		//	VertexColors.Add(flatColor);
		//else
		//	VertexColors.Add(Generator->GetColor(location + (vertList[triTable[cubeIndex][i + 1]] - (1 * radius) / 2.0f)));

		Vertices.Add(vertList[triTable[cubeIndex][i + 2]]);
		Triangles.Add(Triangles.Num());

		if (land->normalsSmoothing)
			Normals.Add(-normList[triTable[cubeIndex][i + 2]].GetUnsafeNormal());
		else
			Normals.Add(-((normList[triTable[cubeIndex][i + 0]] + normList[triTable[cubeIndex][i + 1]] + normList[triTable[cubeIndex][i + 2]]) / 3.f).GetUnsafeNormal());

		//if (land->vertexSubdivision)
		//	VertexColors.Add(flatColor);
		//else
		//	VertexColors.Add(Generator->GetColor(location + (vertList[triTable[cubeIndex][i + 2]] - (1 * radius) / 2.0f)));
	}
}

template<uint8 Direction>
void VoxelRender::GeometryTransitionCubes(float radius, FVoxelOctreeData* chunkSpawn)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	int voxels = land->voxelsOneChunk;

	float radiusVoxel = GetVoxelSize(radius);
	float radiusHalf = GetVoxelSizeHalf(radius);

	float cornerNoise[13];

	for (int x = 0; x < voxels + 0; x++)
	{
		for (int y = 0; y < voxels + 0; y++)
		{
			cornerNoise[0] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // 0 - 9
			cornerNoise[1] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn);
			cornerNoise[2] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // 2 - A
			cornerNoise[3] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn);
			cornerNoise[4] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn);
			cornerNoise[5] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn);
			cornerNoise[6] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // 6 - B
			cornerNoise[7] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn);
			cornerNoise[8] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // 8 - C

			cornerNoise[9] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // 9
			cornerNoise[10] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // A
			cornerNoise[11] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // B
			cornerNoise[12] = GetValueNoise(PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f), chunkSpawn); // C
			
			uint32 caseValue =
				((cornerNoise[0] < 0.f) << 0)
				| ((cornerNoise[1] < 0.f) << 1)
				| ((cornerNoise[2] < 0.f) << 2)
				| ((cornerNoise[5] < 0.f) << 3)
				| ((cornerNoise[8] < 0.f) << 4)
				| ((cornerNoise[7] < 0.f) << 5)
				| ((cornerNoise[6] < 0.f) << 6)
				| ((cornerNoise[3] < 0.f) << 7)
				| ((cornerNoise[4] < 0.f) << 8);

			if (caseValue != 0 && caseValue != 511)
			//if(true)
			{
				FVector cornerPosition[13];

				cornerPosition[0] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 0 - 9
				cornerPosition[1] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[2] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 2 - A
				cornerPosition[3] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[4] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[5] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 0.5f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[6] = PositionToDirection<Direction>(FVector(x + 0.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 6 - B
				cornerPosition[7] = PositionToDirection<Direction>(FVector(x + 0.5f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f);
				cornerPosition[8] = PositionToDirection<Direction>(FVector(x + 1.0f, y + 1.0f, 0) * radiusVoxel, radius) - (float)(radius / 2.f); // 8 - C

				for (int i = 9; i < 13; i++)
				{
					int X = (i - 1) % 2;
					int Y = (i - 1) % 4 / 2;

					cornerPosition[i] = positionSide[
						(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).X) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).Y) * (voxels + 1 + NORMALS_SKIRT) +
							(int)(PositionToDirection<Direction>(FVector(x + X + NORMALS_SKIRT_HALF, y + Y + NORMALS_SKIRT_HALF, NORMALS_SKIRT_HALF), voxels + 2).Z) * (voxels + 1 + NORMALS_SKIRT) * (voxels + 1 + NORMALS_SKIRT)];


					//UE_LOG(LogTemp, Warning, TEXT("cornerPosition s %s"), *cornerPosition[i].ToString());
				}


				const uint8 cellClass = Transvoxels::transitionCellClass[caseValue];
				const uint16* vertexData = Transvoxels::transitionVertexData[caseValue];
				Transvoxels::TransitionCellData cellData = Transvoxels::transitionCellData[cellClass & 0x7F];

				bool convertTriangles = ((cellClass >> 7) == 0);

				TArray<FVector> VerticesTransition;
				TArray<int32> TrianglesTransition;

				for (int i = 0; i < cellData.GetTriangleCount() * 3; i++)
				{
					const uint16& edgeCode = vertexData[i];

					uint8 indexPointA = (edgeCode >> 4) & 0x0F;
					uint8 indexPointB = edgeCode & 0x0F;

					FVector positionA = cornerPosition[indexPointA];
					FVector positionB = cornerPosition[indexPointB];

					float valueA = cornerNoise[indexPointA];
					float valueB = cornerNoise[indexPointB];

					FVector P = VertexInterpTransition(positionA, positionB, valueA, valueB, 0.f);

					uint8 indexEdge = (edgeCode >> 8) & 0x0F;

					VerticesTransition.Add(P);
				}

				if (convertTriangles)
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
					}
				}
				else
				{
					for (int i = 0; i < cellData.GetTriangleCount(); i++)
					{
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 2]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 1]);
						TrianglesTransition.Add(Triangles.Num() + cellData.vertexIndex[i * 3 + 0]);
					}
				}

				// Add our transition cells to global variable of data

				for (int a = 0; a < VerticesTransition.Num(); a++)
				{
					Vertices.Add(VerticesTransition[a]);
				}

				for (int b = 0; b < TrianglesTransition.Num(); b++)
				{
					Triangles.Add(TrianglesTransition[b]);
				}
			}
		}
	}
}

template<uint8 Direction>
FVector VoxelRender::PositionToDirection(FVector directionPosition, float size)
{
	if ((Direction >> 0) & 0x01) { directionPosition = FVector(directionPosition.Z, directionPosition.X, directionPosition.Y); }			//0x01
	if ((Direction >> 1) & 0x01) { directionPosition = FVector(size - directionPosition.Z, directionPosition.Y, directionPosition.X); }		//0x02
	if ((Direction >> 2) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.Z, directionPosition.X); }			//0x04
	if ((Direction >> 3) & 0x01) { directionPosition = FVector(directionPosition.X, size - directionPosition.Z, directionPosition.Y); }		//0x08
	if ((Direction >> 4) & 0x01) { directionPosition = FVector(directionPosition.X, directionPosition.Y, directionPosition.Z); }			//0x10
	if ((Direction >> 5) & 0x01) { directionPosition = FVector(directionPosition.Y, directionPosition.X, size - directionPosition.Z); }		//0x20

	return directionPosition;
}


FVector VoxelRender::GetGradient(int x, int y, int z)
{
	float d = 100.f;

	FVector average_normal;

	average_normal.X = (GetDensity((x + 1), (y + 0), (z + 0)) - GetDensity((x - 1), (y - 0), (z - 0))) / 2 / d;
	average_normal.Y = (GetDensity((x + 0), (y + 1), (z + 0)) - GetDensity((x - 0), (y - 1), (z - 0))) / 2 / d;
	average_normal.Z = (GetDensity((x + 0), (y + 0), (z + 1)) - GetDensity((x - 0), (y - 0), (z - 1))) / 2 / d;

	average_normal.Normalize();
	return average_normal;
}

float VoxelRender::GetDensity(int x, int y, int z)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);

	//if (x < 0 || y < 0 || z < 0 || x > land->voxelsOneChunk - 1 || y > land->voxelsOneChunk - 1 || z > land->voxelsOneChunk - 1)
	//	return 0.f;
	//else
	return Grid[x + y * (land->voxelsOneChunk + 1 + NORMALS_SKIRT) + z * (land->voxelsOneChunk + 1 + NORMALS_SKIRT) * (land->voxelsOneChunk + 1 + NORMALS_SKIRT)];
}

FLinearColor VoxelRender::GetColor(FVector positionVoxel)
{
	FLinearColor colorLandscape = FLinearColor(0.690f, 0.690f, 0.690f); //grass
	/*FLinearColor colorLandscape = grass; //grass
	float distance = (sqrt(pow(positionVoxel.X + location.X, 2) + pow(positionVoxel.Y + location.Y, 2) + pow(positionVoxel.Z + location.Z, 2)));

	if (distance > 0 && distance <= 1500)
	{
		colorLandscape = FLinearColor(0.690f, 0.690f, 0.690f); //rocks
	}
	else if (distance > 1500 && distance <= radiusSphere - radiusSphere / 5.f)
	{
		colorLandscape = ground; //ground
	}*/
	return colorLandscape;
}

FVector VoxelRender::VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst)
{
	float mu;
	FVector P;

	if (FMath::Abs(Value - P1Val) < 0.00001)
		return P1;

	if (FMath::Abs(Value - P2Val) < 0.00001)
		return P2;

	if (FMath::Abs(P1Val - P2Val) < 0.00001)
		return P1;

	mu = (Value - P1Val) / (P2Val - P1Val);

	P.X = P1.X + mu * (P2.X - P1.X);
	P.Y = P1.Y + mu * (P2.Y - P1.Y);
	P.Z = P1.Z + mu * (P2.Z - P1.Z);

	normalInst.X = N1.X + mu * (N2.X - N1.X);
	normalInst.Y = N1.Y + mu * (N2.Y - N1.Y);
	normalInst.Z = N1.Z + mu * (N2.Z - N1.Z);

	return P;
}

FVector VoxelRender::VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value)
{
	float mu;
	FVector P;

	if (FMath::Abs(Value - P1Val) < 0.00001)
		return P1;

	if (FMath::Abs(Value - P2Val) < 0.00001)
		return P2;

	if (FMath::Abs(P1Val - P2Val) < 0.00001)
		return P1;

	mu = (Value - P1Val) / (P2Val - P1Val);

	P = P1 + mu * (P2 - P1);

	return P;
}

float VoxelRender::GetVoxelSize(float radius)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);
	return radius / (float)land->voxelsOneChunk;
}

float VoxelRender::GetVoxelSizeHalf(float radius)
{
	AVoxelLandscape* land = Cast<AVoxelLandscape>(VoxelLand);
	return radius / (float)land->voxelsOneChunk / 2.f;
}