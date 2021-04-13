// Voxel Art Plugin � limit 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelChunkComponent.h"
#include "VoxelPoolComponent.h"
#include "Editor/VoxelEditorData.h"
#include "Generators/VoxelWorldGenerator.h"
#include "Octree/VoxelOctreeManager.h"
#include "Octree/VoxelOctreeNeighborsChecker.h"
#include "Octree/VoxelOctreeData.h"
#include "Save/VoxelSaveData.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
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
enum Meshers
{
	Cubes			UMETA(DisplayName = "Cubes"),
	MarchingCubes	UMETA(DisplayName = "Marching Cubes"),
	SurfaceNets		UMETA(DisplayName = "Surface Nets")
};

class FVoxelCollisionBox;

/*
* Voxel World Main class
*/
UCLASS(Blueprintable, HideCategories = ("Input", "Actor", "LOD"))
class VOXELART_API AVoxelWorld : public AActor
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
<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h

	/*Called when a property on this object has been modified externally*/
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

#if WITH_EDITOR

	/*Called before the editor tries to begin PIE*/
	void OnPreBeginPIE(bool bIsSimulating);
=======

	/*Called when a property on this object has been modified externally*/
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

#if WITH_EDITOR

	/*Called before the editor tries to begin PIE*/
	void OnPreBeginPIE(bool bIsSimulating);

	/*Called as PIE ends*/
	void OnEndPIE(bool bIsSimulating);

	/*If true, actor is ticked*/
	virtual bool ShouldTickIfViewportsOnly() const override;

#endif

	// ~ End AActor Interface

public:

	VoxelOctreeManager*				OctreeManagerThread;
	VoxelOctreeNeighborsChecker*	OctreeNeighborsCheckerThread;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h

	/*Called as PIE ends*/
	void OnEndPIE(bool bIsSimulating);

<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h
	/*If true, actor is ticked*/
	virtual bool ShouldTickIfViewportsOnly() const override;
=======
	TSharedPtr<FVoxelOctreeData>	MainOctree;
	FVoxelOctreeDensity*			OctreeDensity;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h

#endif

<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h
	// ~ End AActor Interface
=======
	UVoxelPoolComponent*			PoolChunks;
	TArray<UVoxelChunkComponent*>	ChunkComponents;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h

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

<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h
=======
public:

	void CreateVoxelWorld();
	void CreateVoxelWorldInEditor();
	void DestroyVoxelWorld();
	void UpdateWorld();
	void SaveWorldUtility();
	UVoxelSaveData* SaveWorldToFile();

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h
public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bWorldCreated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	bool EnabledLOD = true;

	UPROPERTY()
	bool bEnableUpdateOctree = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail")
	uint8 DrawingRange = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12"))
	int32 MinimumLOD = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level of Detail", meta = (ClampMin = "0", ClampMax = "12", UIMin = "0", UIMax = "12", EditCondition = bMaximumLOD))
	int32 MaximumLOD = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	TEnumAsByte<Meshers> MesherType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta = (ClampMin = "1", ClampMax = "4096", UIMin = "1", UIMax = "4096"))
	int32 ChunksPerFrame = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool VertexSubdivision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool NormalsSmoothing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	UStaticMesh* MeshTree;

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

<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h
=======
private:

	int32 TimeForWorldGenerate = 0;

	bool bStatsShowed = false;

>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USceneComponent* WorldComponent;

public:

	void CreateVoxelWorld();
	void CreateVoxelWorldInEditor();
	void DestroyVoxelWorld();
	void UpdateWorld();
	void SaveWorldUtility();
	UVoxelSaveData* SaveWorldToFile();

private:

	void GenerateLandscape();
	void GenerateOctree(TSharedPtr<FVoxelOctreeData> Octant);
	void SpawnChunk(FVoxelChunkData* ChunkData);
	void ChunkInit(UVoxelChunkComponent* Chunk, FVoxelChunkData* ChunkData);
	void PutChunkOnGeneration(FVoxelChunkData* ChunkData);
	void GetLeavesAndQueueToGeneration(TSharedPtr<FVoxelOctreeData> Octant);
	void GetOverlapingOctree(FVoxelCollisionBox Box, TSharedPtr<FVoxelOctreeData> CurrentOctree, TArray<TSharedPtr<FVoxelOctreeData>>& OverlapingOctree);
	FEditorViewportClient* GetEditorViewportClient();
	void UpdateOctree();

public:	

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FIntVector TransferToVoxelWorld(FVector P);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FVector TransferToGameWorld(FIntVector P);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int GetIndex(FIntVector P);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void VoxelDebugBox(FVector Position, float Radius, float Width, FColor Color);

public:

	/*
	* Get the Voxel Value of density and color at the given world position
	*
	* @param	OutOctant		Saved octant from the last integration
	* @param	Position		Local World Position
	* @return	Value			Density of the Position
	* @return	Color			Color of the Position
	*/
	void GetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float& Value, FColor& Color);
<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h

	/*
	* Set the Voxel Value of density and color at the given world position
	*
	* @param	OutOctant		Saved octant from the last integration
	* @param	Position		Local World Position
	* @param	Density			New Position Density
	* @param	Color			New Position Color
	* @param	bSetDensity		Should the Density be set?
	* @param	bSetColor		Should the Color be set?
	*/
	void SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor);

private:

	//An array of all changes that must be made to the Octree with the next tick of the game
	TQueue<TSharedPtr<FChunksRenderInfo>>	ChangesOctree;

	TArray<FVoxelChunkData*>				ChunksCreation;
	TArray<FVoxelChunkData*>				ChunksGeneration;
	TArray<FVoxelChunkData*>				ChunksRemoving;

public:

	VoxelOctreeManager*						OctreeManagerThread;
	VoxelOctreeNeighborsChecker*			OctreeNeighborsCheckerThread;

public:

	TSharedPtr<FVoxelOctreeData>			MainOctree;
	FVoxelOctreeDensity*					OctreeDensity;

private:

	UVoxelPoolComponent*					PoolChunks;
	TArray<UVoxelChunkComponent*>			ChunkComponents;
=======

	/*
	* Set the Voxel Value of density and color at the given world position
	*
	* @param	OutOctant		Saved octant from the last integration
	* @param	Position		Local World Position
	* @param	Density			New Position Density
	* @param	Color			New Position Color
	* @param	bSetDensity		Should the Density be set?
	* @param	bSetColor		Should the Color be set?
	*/
	void SetVoxelValue(FVoxelOctreeDensity*& OutOctant, FIntVector Position, float Density, FColor Color, bool bSetDensity, bool bSetColor);

private:

	//An array of all changes that must be made to the Octree with the next tick of the game
	TQueue<TSharedPtr<FChunksRenderInfo>>	ChangesOctree;

	TArray<FVoxelChunkData*>				ChunksCreation;
	TArray<FVoxelChunkData*>				ChunksGeneration;
	TArray<FVoxelChunkData*>				ChunksRemoving;
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h

public:

	float TimeToCallGarbageCollection = 0.f;
	int TotalTasksCounter = 0;

	FQueuedThreadPool* ThreadPool;
	FThreadSafeCounter TaskWorkGlobalCounter;

	FCriticalSection OctreeMutex;
	FCriticalSection ChunksToCreationMutex;

	TArray<FAsyncTask<FMesherAsyncTask>*> PoolThreads;
<<<<<<< HEAD:Source/VoxelArt/Public/VoxelWorld.h
	
private:

	int32 TimeForWorldGenerate = 0;

	bool bStatsShowed = false;
	
	UPROPERTY(EditDefaultsOnly)
	bool bMaximumLOD = false;
=======
>>>>>>> a2345974b4b7176ad71078f0c17d0c65937f892d:Source/VoxelArt/Public/VoxelLandscape.h
};