// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"


class AVoxelWorld;
class UVoxelChunkComponent;
class UVoxelWorldGenerator;


class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{
public:

	uint64 NodeID = 0x00;
	uint8 Depth = 0;

	int Size = 0;

	FIntVector Position = FIntVector(0, 0, 0);

public:

	FVoxelChunkData* Data = nullptr;
//	FVoxelOctreeDensity* DensityOctant = nullptr;

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> ChildrenChunks;

public:
	FVoxelOctreeData(TWeakPtr<FVoxelOctreeData> _Parent, uint64 _NodeID, uint8 _Depth, float _Radius, FIntVector _Position);
	~FVoxelOctreeData();


public:

	void AddChildren();

	inline void DestroyChildren();
	inline bool HasChildren();
	inline void CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> children);

	inline FIntVector GetMinimumCorner();
	inline FIntVector GetMaximumCorner();

	inline TWeakPtr<FVoxelOctreeData> GetParent();
	inline TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> GetChildren();
	inline TWeakPtr<FVoxelOctreeData> GetChildByPosition(FVector Position);
	inline TWeakPtr<FVoxelOctreeData> GetLeaf(FVector Position);
};


class VOXELART_API FVoxelChunkData
{
public:

	int Voxels = 32;
	int Size = 0;
	int Priority = 0;

	uint8 Depth = 0;
	uint8 TransitionSides = 0x00;

	FIntVector Position = FIntVector(0, 0, 0);

public:

//	TArray<float> DensityMap;
//	TArray<FColor> ColorMap;

public:

	UVoxelChunkComponent* Chunk = nullptr;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:
	FVoxelChunkData(TWeakPtr<FVoxelOctreeData> _CurrentOctree, uint8 _Depth, FIntVector _Position, int _Size, int _Voxels, int _Priority);
	~FVoxelChunkData();

};


/*
* FVoxelOctreeDensity is needed to save info
* about the entire density of the world.
* We will then be able to store and load it.
*/

class VOXELART_API FVoxelOctreeDensity
{
public:

	uint8 Depth = 0;

	int Size = 0;
	int Voxels = 32;

	FIntVector Position;
	TArray<float> DensityMap;
	TArray<FColor> ColorMap;

private:

	bool OwnDensity = false;
	bool OwnColor = false;

public:

	UVoxelWorldGenerator* WorldGenerator;
	TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> ChildrenOctants;

public:

	void AddChildren();

	inline TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> GetChildren();
	inline bool HasChildren() { return ChildrenOctants.Num() == 8; }
	inline void SetVoxelValue(AVoxelWorld* World, FIntVector P, float Density, FColor Color, bool bSetDensity, bool bSetColor);
	inline void GetVoxelDensity(AVoxelWorld* World, FIntVector P, float& Value, FColor& Color);
	inline bool HasOwnDensity() { return OwnDensity; }
	inline bool HasOwnColor() { return OwnColor; }

	bool IsInside(FIntVector Position);

	inline FIntVector GetMinimumCorner();
	inline FIntVector GetMaximumCorner();

	FIntVector TransferToLocal(AVoxelWorld* World, FIntVector Position);

	FVoxelOctreeDensity* GetLeaf(FIntVector Position);
	FVoxelOctreeDensity* GetChildByPosition(FIntVector Position);

	void SetDefaultMap(AVoxelWorld* World);

public:
	FVoxelOctreeDensity(UVoxelWorldGenerator* _WorldGenerator, uint8 _Depth, int _Size, int _Voxels, FIntVector _Position);
	~FVoxelOctreeDensity() {}

};


USTRUCT(BlueprintType)
struct FChunksRenderInfo
{
	GENERATED_USTRUCT_BODY()

	//Chunks which has to be created
	TArray<FVoxelChunkData*> ChunksCreation;

	//Chunks which has to be generated
	TArray<FVoxelChunkData*> ChunksGeneration;

	//Chunks which has to be removed
	TArray<FVoxelChunkData*> ChunksRemoving;
};