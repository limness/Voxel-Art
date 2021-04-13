// Voxel Art Plugin © limit 2018

#pragma once

#include "CoreMinimal.h"
#include "VoxelOctreeData.generated.h"

<<<<<<< HEAD
class AVoxelWorld;
class UVoxelChunkComponent;
class UVoxelWorldGenerator;
=======

class AVoxelWorld;
class UVoxelChunkComponent;
class UVoxelWorldGenerator;

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

/*
* Parent Voxel Octree Data
*/
class VOXELART_API FVoxelOctreeData : public TSharedFromThis<FVoxelOctreeData>
{
public:
	FVoxelOctreeData(
		TWeakPtr<FVoxelOctreeData> _Parent,
		uint64 _NodeID,
		uint8 _Depth, float
		_Radius, FIntVector
		_Position
	);
	~FVoxelOctreeData();

public:

	uint64 NodeID = 0x00;
	uint8 Depth = 0;
	int Size = 0;
	FIntVector Position = FIntVector(0, 0, 0);

public:

	FVoxelChunkData* Data = nullptr;

public:

	TWeakPtr<FVoxelOctreeData> ParentChunk;
	TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> ChildrenChunks;

public:

	void AddChildren();

	FORCEINLINE bool HasChildren();
	FORCEINLINE void DestroyChildren();
	FORCEINLINE void CreateChildren(TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> children);

	FORCEINLINE FIntVector GetMinimumCorner();
	FORCEINLINE FIntVector GetMaximumCorner();

	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetParent();
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetChildByPosition(FVector Position);
	FORCEINLINE TWeakPtr<FVoxelOctreeData> GetLeaf(FVector Position);
	FORCEINLINE TArray<TSharedPtr<FVoxelOctreeData>, TFixedAllocator<8>> GetChildren();
};


/*
* Child Voxel Chunk Data
*/
class VOXELART_API FVoxelChunkData
{
public:

<<<<<<< HEAD
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

=======
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
	int Voxels = 32;
	int Size = 0;
	int Priority = 0;

	uint8 Depth = 0;
	uint8 TransitionSides = 0x00;

	FIntVector Position = FIntVector(0, 0, 0);

public:

<<<<<<< HEAD
=======
//	TArray<float> DensityMap;
//	TArray<FColor> ColorMap;

public:

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d
	UVoxelChunkComponent* Chunk = nullptr;
	TWeakPtr<FVoxelOctreeData> CurrentOctree;
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

	uint8 Depth = 0;

	int Size = 0;
	int Voxels = 32;

<<<<<<< HEAD
	FIntVector		Position;
	TArray<float>	DensityMap;
	TArray<FColor>	ColorMap;
=======
	FIntVector Position;
	TArray<float> DensityMap;
	TArray<FColor> ColorMap;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

private:

	bool OwnDensity = false;
	bool OwnColor = false;

public:

	UVoxelWorldGenerator* WorldGenerator;
	TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> ChildrenOctants;

public:

	FORCEINLINE TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> GetChildren();

<<<<<<< HEAD
	FORCEINLINE void SetVoxelValue(AVoxelWorld* World, FIntVector P, float Density, FColor Color, bool bSetDensity, bool bSetColor);
	FORCEINLINE void GetVoxelDensity(AVoxelWorld* World, FIntVector P, float& Value, FColor& Color);
=======
	inline TArray<FVoxelOctreeDensity*, TFixedAllocator<8>> GetChildren();
	inline bool HasChildren() { return ChildrenOctants.Num() == 8; }
	inline void SetVoxelValue(AVoxelWorld* World, FIntVector P, float Density, FColor Color, bool bSetDensity, bool bSetColor);
	inline void GetVoxelDensity(AVoxelWorld* World, FIntVector P, float& Value, FColor& Color);
	inline bool HasOwnDensity() { return OwnDensity; }
	inline bool HasOwnColor() { return OwnColor; }
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

	FORCEINLINE bool HasChildren() { return ChildrenOctants.Num() == 8; }
	FORCEINLINE bool HasOwnDensity() { return OwnDensity; }
	FORCEINLINE bool HasOwnColor() { return OwnColor; }
	FORCEINLINE bool IsInside(FIntVector Position);

	FORCEINLINE FIntVector GetMinimumCorner();
	FORCEINLINE FIntVector GetMaximumCorner();
	FORCEINLINE FIntVector TransferToLocal(AVoxelWorld* World, FIntVector Position);

<<<<<<< HEAD
public:
=======
	FIntVector TransferToLocal(AVoxelWorld* World, FIntVector Position);
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

	FVoxelOctreeDensity* GetLeaf(FIntVector Position);
	FVoxelOctreeDensity* GetChildByPosition(FIntVector Position);

<<<<<<< HEAD
public:
=======
	void SetDefaultMap(AVoxelWorld* World);

public:
	FVoxelOctreeDensity(UVoxelWorldGenerator* _WorldGenerator, uint8 _Depth, int _Size, int _Voxels, FIntVector _Position);
	~FVoxelOctreeDensity() {}
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d

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