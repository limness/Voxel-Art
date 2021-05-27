// Voxel Art Plugin 2021 ~ Copyright Limit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Editor/VoxelEditorData.h"
#include "Generators/VoxelWorldGenerator.h"
#include "Meshers/VoxelDefaultMesher.h"
#include "Octree/VoxelOctreeData.h"
#include "Octree/VoxelOctreeManager.h"
#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Save/VoxelSaveData.h"
#include "Save/VoxelSaveInterface.h"
#include "VoxelFoliageConfig.h"
#include "VoxelPlayerInterface.h"
#include "VoxelListenersInterface.h"
#include "VoxelChunkComponent.h"
#include "VoxelPoolComponent.h"
#include "VoxelWorld.generated.h"

namespace EVoxelDirection
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
}

UENUM()
enum RenderTexture
{
	WhiteBlack		UMETA(DisplayName = "WB"),
	RedGreenBlue	UMETA(DisplayName = "RGB")
};

UENUM()
enum ENormalsType
{
	NoNormals	UMETA(DisplayName = "No Normals"),
	Smoothed	UMETA(DisplayName = "Smoothed")
};

UENUM()
enum EColorsType
{
	NoColors	UMETA(DisplayName = "No Colors"),
	OwnColors	UMETA(DisplayName = "Own Color Map")
};

UENUM()
enum Meshers
{
	MarchingCubes	UMETA(DisplayName = "Marching Cubes"),
	SurfaceNets		UMETA(DisplayName = "Surface Nets (Experimental)"),
	Cubes			UMETA(DisplayName = "Cubes (Experimental)")
};

class FVoxelCollisionBox;

/*
* Voxel World Main class
*/
UCLASS(Blueprintable, HideCategories = ("Input", "Actor", "LOD"))
class VOXELART_API AVoxelWorld : public AActor, public IVoxelListenersInterface
{
	GENERATED_BODY()
	
public:	

	AVoxelWorld();

public:
	// ~ Begin AActor Interface

	/*Overridable native event for when play begins for this actor*/
	virtual void BeginPlay() override;

	/*Overridable function called whenever this actor is being removed from a level*/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/*
	*Called when this actor is explicitly being destroyed during gameplay or in the editor, 
	*not called during level streaming or gameplay ending
	*/
	virtual void Destroyed() override;

	/*Function called every frame on this Actor*/
	virtual void Tick(float DeltaTime) override;

	/*Called when an instance of this class is placed (in editor) or spawned*/
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR

	/*Called when a property on this object has been modified externally*/
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

	/*Called before the editor tries to begin PIE*/
	virtual void OnPreBeginPIE(bool bIsSimulating) override;

	/*Called as PIE ends*/
	virtual void OnEndPIE(bool bIsSimulating) override;

	/*Called as PIE ends*/
	virtual void OnPreExit() override;

	/*If true, actor is ticked*/
	virtual bool ShouldTickIfViewportsOnly() const override;

#endif

	// ~ End AActor Interface

public:

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Main")
	UVoxelWorldGenerator* WorldGenerator;

	UPROPERTY(EditAnywhere, Category = "Main")
	UVoxelSaveData* SaveFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	bool EnabledWorldInGame = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Main")
	bool bCreatedInEditor = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "1", ClampMax = "524288", UIMin = "1", UIMax = "524288"))
	int VoxelMin = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "32", ClampMax = "524288", UIMin = "32", UIMax = "524288"))
	int WorldSize = 4096;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main", meta = (ClampMin = "2", ClampMax = "32", UIMin = "2", UIMax = "32"))
	int VoxelsPerChunk = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Main")
	bool TransitionMesh = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"), Category = "Main")
	float TransitionSize = 0.25f;

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category = "Main")
	bool bWorldCreated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool EnabledLOD = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Max Player Velocity (in m/s)", Category = "Level of Detail")
	int MaxPlayerVelocity = 200;

	UPROPERTY(Transient)
	bool bEnableUpdateOctree = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	uint8 DrawingRange = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12"))
	int32 MinimumLOD = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12", EditCondition = bMaximumLOD))
	int32 MaximumLOD = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	TEnumAsByte<Meshers> MesherType;

	FVoxelDefaultMesher* MesherObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta = (ClampMin = "1", ClampMax = "4096", UIMin = "1", UIMax = "4096"))
	int32 ChunksPerFrame = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	TEnumAsByte<EColorsType> ColorsType = EColorsType::NoColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	TEnumAsByte<ENormalsType> NormalsType = ENormalsType::Smoothed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Config")
	UVoxelFoliageConfig* FoliageConfig;

	TArray<UHierarchicalInstancedStaticMeshComponent*> FoliageMeshComponents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	FString MapName = "DensityMapTexture";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	FString DirectoryName = "VoxelDensityMaps";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	int MapSize = 1024;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Export Preview Heightmap")
	TEnumAsByte<RenderTexture> RenderType;

	UFUNCTION(BlueprintCallable, Category = "Export Preview Heightmap")
	void CreateTextureDensityMap();

private:

	UPROPERTY(Transient)
	AVoxelPlayerInterface*				VoxelScenePlayer;

public:

	UPROPERTY(BlueprintReadOnly, Transient)
	TSubclassOf<AVoxelPlayerInterface>	VoxelScenePlayerClass;

	UPROPERTY(BlueprintReadOnly)
	USceneComponent*					WorldComponent;

public:

	void CreateVoxelWorld();
	void CreateVoxelWorldInEditor();
	void DestroyVoxelWorld();
	void SaveWorldUtility();

private:

	void UpdateChunks();
	void UpdateOctree();
	void InitializeWorld();
	void CreateChunk(FVoxelChunkData* ChunkData);
	void GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant);
	void ChunkInitialize(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData);

public:
	/*
	* Queues the chunk for generation.
	*
	* @return	ChunkData		Chunk Data for generation
	*/
	void PutChunkOnGeneration(FVoxelChunkData* ChunkData);

	/*
	* Add a chunk to the array that should apply the new mesh in the next frame.
	*
	* @param	Chunk		Chunk to apply mesh
	*/
	void AddChunkToUpdate(UVoxelChunkComponent* ChunkData);

	/*
	* Gets all octants of the Octree that intersect with the box
	*
	* @param	Box					Collision box
	* @param	CurrentOctree		Current octant to start (Use the Main octree of the world)
	* @return	OverlapingOctree	An array of received chunks
	*/
	void GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree);

public:	
	/*
	* Gets the existing player who controls the World Octree.
	* Do not use this to get an existing controller on scene, it's a separate actor.
	*
	* @return	VoxelPlayer		A pawn that rules the world Octree
	*/
	UFUNCTION(BlueprintCallable)
	FORCEINLINE AVoxelPlayerInterface* GetVoxelScenePlayer();
	
	/*
	* Transfer any position in voxel units.
	* Do not reuse this after the first transfering.
	*
	* @param	P				Float position in world units
	* @return	P				Integer position in voxels
	*/
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FIntVector TransferToVoxelWorld(FVector P);
	
	/*
	* Transfer voxel position in world units.
	* Do not reuse this after the first transfering.
	*
	* @param	P				Integer position in voxels
	* @return	P				Float position in world units
	*/
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FVector TransferToGameWorld(FIntVector P);

	/*
	* Get Index using size of the chunk, in other words we simulate 3D array using 1D.
	*
	* @param	P				Index 1, Index 2, Index 3
	* @return	Index			Index in 1D array from 3D
	*/
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int GetIndex(FIntVector P);
	
	/*
	* Spawn new Debug Box in the Game World. Use for any tests, for example to see the visible chunks.
	*
	* @param	Position		Position of the box
	* @param	Radius			Radius of the box
	* @param	Width			Border width of the box
	* @param	Color			Border color
	*/
	UFUNCTION(BlueprintCallable)
	void VoxelDebugBox(FVector Position, float Radius, float Width, FColor Color);

public:

	/*
	* Get the Voxel Value of density and color at the given world position.
	*
	* @param	OutOctant		Saved octant from the last integration
	* @param	Position		Local World Position
	* @return	Value			Density of the Position
	* @return	Color			Color of the Position
	*/
	void GetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float& Value, FColor& Color);

	/*
	* Set the Voxel Value of density and color at the given world position.
	*
	* @param	OutOctant		Saved octant from the last integration
	* @param	Position		Local World Position
	* @param	Density			New Position Density
	* @param	Color			New Position Color
	* @param	bSetDensity		Should the Density be set?
	* @param	bSetColor		Should the Color be set?
	*/
	void SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor);

public:

	//An array of all changes that must be made to the Octree with the next tick of the game.
	TQueue<TSharedPtr<FChunksRenderInfo>>	ChangesOctree;

	TArray<FVoxelChunkData*>				ChunksCreation;
	TSet<FVoxelChunkData*>					ChunksGeneration;
	TSet<FVoxelChunkData*>					ChunksRemoving;
	TArray<FVoxelChunkData*>				ChunksForceRemoving;

	TArray<FVoxelChunkData*>				TemporaryChunks;

	TSet<UVoxelChunkComponent*>					ChunksApplyUpdate;

public:

	TSharedPtr<FVoxelOctreeData>			MainOctree;
	VoxelOctreeManager*						OctreeManagerThread;
	VoxelOctreeNeighborsChecker*			OctreeNeighborsCheckerThread;
	FVoxelOctreeDensity*					OctreeDensity;
	UVoxelPoolComponent*					ChunkPoolComponent;

public:

	FQueuedThreadPool* ThreadPool;
	FQueuedThreadPool* ThreadFoliagePool;
	FThreadSafeCounter MesherWorkTasksCounter;

	FCriticalSection OctreeMutex;
	FCriticalSection ChunksApplyUpdateMutex;

	TArray<FAsyncTask<FVoxelMesherAsyncTask>*> PoolThreads;
	
public:

	double WorldGenerateTimeBegin;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool bStatsShowed = false;
	
	UPROPERTY(EditDefaultsOnly)
	bool bMaximumLOD = false;
};