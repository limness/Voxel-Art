// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

class AVoxelWorld;
class UVoxelChunkComponent;
class UVoxelWorldGenerator;
/*
* Parent Voxel Octree Data
*/
class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{
public:
	FVoxelOctreeData(
		TWeakPtr<FVoxelOctreeData> _Parent,
		uint64 _NodeID,
		uint8 _Depth,
		float _Size,
		FIntVector _Position
	);
	~FVoxelOctreeData();

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> ChildrenChunks;

public:

	uint64 NodeID = 0x00;
	uint8 Depth = 0;
	int Size = 0;
	FIntVector Position = FIntVector(0, 0, 0);

public:

	FVoxelChunkData* Data = nullptr;

public:

	void AddChildren();

	FORCEINLINE bool HasChildren();
	FORCEINLINE void DestroyChildren();

	FORCEINLINE FIntVector GetMinimumCorner();
	FORCEINLINE FIntVector GetMaximumCorner();

	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetParent();
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetChildByPosition(FVector GlobalPosition);
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetLeaf(FVector GlobalPosition);
	FORCEINLINE TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> GetChildren();
};


/*
* Child Voxel Chunk Data
*/
class VOXELART_API FVoxelChunkData
{
public:

	FVoxelChunkData(
		TWeakPtr<FVoxelOctreeData> _CurrentOctree,
		uint8 _Depth,
		FIntVector _Position,
		int _Size,
		int _Voxels,
		int _Priority
	);
	~FVoxelChunkData();

public:

	UVoxelChunkComponent* Chunk = nullptr;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;

public:

	uint8 Depth = 0;
	uint8 TransitionSides = 0x00;

	FIntVector Position = FIntVector(0, 0, 0);

	int Size = 0;
	int Voxels = 32;
	int Priority = 0;
};

//using ArrayChildrenDensity = TArray<FVoxelOctreeDensity*, TFixedAllocator<8>>;

/*
* FVoxelOctreeDensity is needed to save info
* about the entire density of the world.
* We will then be able to store and load it.
*/
class VOXELART_API FVoxelOctreeDensity
{
public:

	FVoxelOctreeDensity(
		UVoxelWorldGenerator* _WorldGenerator,
		uint8 _Depth,
		int _Size,
		int _Voxels,
		FIntVector _Position
	);
	~FVoxelOctreeDensity() {}

public:

	UVoxelWorldGenerator* WorldGenerator;
	TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> ChildrenOctants;

public:

	uint8 Depth = 0;

	int Size = 0;
	int Voxels = 32;

	FIntVector		Position;
	TArray<float>	DensityMap;
	TArray<FColor>	ColorMap;

private:

	bool OwnDensity = false;
	bool OwnColor = false;

public:

	FORCEINLINE TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> GetChildren();

	FORCEINLINE void SetVoxelValue(AVoxelWorld* World, FIntVector P, float Density, FColor Color, bool bSetDensity, bool bSetColor);
	FORCEINLINE void GetVoxelDensity(AVoxelWorld* World, FIntVector P, float& Value, FColor& Color);

	FORCEINLINE bool HasChildren() { return ChildrenOctants.Num() == 8; }
	FORCEINLINE bool HasOwnDensity() { return OwnDensity; }
	FORCEINLINE bool HasOwnColor() { return OwnColor; }
	FORCEINLINE bool IsInside(FIntVector LocalPosition);

	FORCEINLINE FIntVector GetMinimumCorner();
	FORCEINLINE FIntVector GetMaximumCorner();
	FORCEINLINE FIntVector TransferToLocal(AVoxelWorld* World, FIntVector CurrentPosition);

	FVoxelOctreeDensity* GetLeaf(FIntVector LocalPosition);
	FVoxelOctreeDensity* GetChildByPosition(FIntVector LocalPosition);

public:

	void AddChildren();
	void SetDefaultMap(AVoxelWorld* World);
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