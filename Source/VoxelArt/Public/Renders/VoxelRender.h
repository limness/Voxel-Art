// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "VoxelLandscapeGenerator.h"
#include "Octree/VoxelOctreeData.h"

class VOXELART_API VoxelRender : public FRunnable
{

public:
	VoxelRender(AActor* World = nullptr, UVoxelLandscapeGenerator* GeneratorLandscape = nullptr);
	~VoxelRender();

	void EnsureCompletion();
	void PauseThread();
	void ContinueThread();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

	void GenerateVertexCube(float radius, FVoxelOctreeData* chunkSpawn, bool regenerate);
	void MarchingCubes(int level, float radius, int isolevel, int indexGrid, int x, int y, int z, int normalIndex, bool regenerate);
	FVector VertexInterp(FVector P1, FVector P2, FVector N1, FVector N2, float P1Val, float P2Val, float Value, FVector& normalInst);
	FVector VertexInterpTransition(FVector P1, FVector P2, float P1Val, float P2Val, float Value);
	float GetVoxelSize(float radius);
	float GetVoxelSizeHalf(float radius);
	void GenerateNoiseOnGrid(float radiusOfChunk, FVoxelOctreeData* chunkSpawn, int x_little, int y_little, int z_little);
	void setEnqueueChunk(TArray<FChunksRenderInfo*> chunkSet);

	float fbmNoise(FVector positionGrid, float H);
	float pattern(FVector p, float H);

	int stat_compile = -1;

	FLinearColor GetColor(FVector positionVoxel);
	float GetDensity(int x, int y, int z);
	FVector GetGradient(int x, int y, int z);

	bool IsThreadPaused();

private:
	//Thread to run the worker FRunnable on
	FRunnableThread* Thread;

	FCriticalSection m_mutex;
	FEvent * m_semaphore;

	int m_chunkCount;
	int m_amount;
	int m_MinInt;
	int m_MaxInt;
	int m_MaxValue;

	bool g_stop = false;

	FThreadSafeBool m_Kill;
	FThreadSafeBool m_Pause;

	FVector position[8];
	FVector location;

	float infoNoise[8];
	int totalMsForGenerate = 0;

	TArray<float> Grid;

	TArray<FVector> positionSide;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;

	AActor *VoxelLand;
	UVoxelLandscapeGenerator *Generator;

	TArray <FVoxelOctreeData> queueChunks;

	TQueue <TArray<FChunksRenderInfo*>, EQueueMode::Mpsc> chunksInQueue;

	float GetValueNoise(FVector positionGrid, FVoxelOctreeData* chunkSpawn);

	template<uint8 Direction>
	void GeometryTransitionCubes(float radius, FVoxelOctreeData* chunkSpawn);

	template<uint8 Direction>
	FVector PositionToDirection(FVector directionPosition, float size);
};
