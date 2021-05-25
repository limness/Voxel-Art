// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelChunkComponent.h"
#include "Helpers/VoxelTools.h"
#include "Meshers/VoxelMarchingCubesMesher.h"
#include "Meshers/VoxelSurfaceNetsMesher.h"
#include "Meshers/VoxelCubesMesher.h"
#include "Octree/VoxelOctreeData.h"
#include "Engine/World.h"
#include "VoxelWorld.h"


UVoxelChunkComponent::UVoxelChunkComponent(const class FObjectInitializer& ObjectInitializer)
{
	bUseAsyncCooking = false;
}

bool UVoxelChunkComponent::IsPoolActive()
{
	return PoolActive;
}

void UVoxelChunkComponent::SetPoolActive(bool activeStatus)
{
	PoolActive = activeStatus;

	if (!activeStatus)
	{
		if (MesherTask)
		{
			MesherTask->EnsureCompletion();
			delete MesherTask;
			MesherTask = nullptr;

			MeshComplete = false;
		}
		/*for (auto& FoliageTask : FoliageTasks)
		{
			FoliageTask->EnsureCompletion();
			delete FoliageTask;
			FoliageTask = nullptr;
		}*/
		if (MesherObject)
		{
			delete MesherObject;
			MesherObject = nullptr;
		}
		ClearAllMeshSections();
		SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	else
	{
		SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	ToggleVisibility(!activeStatus);
}

bool UVoxelChunkComponent::CreateMesh(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData)
{
	MesherTask = new FAsyncTask<FVoxelMesherAsyncTask>(World, this, ChunkData, MesherObject);
	MesherTask->StartBackgroundTask(/*ThreadPool*/);

	return true;
}

bool UVoxelChunkComponent::CreateFoliage(AVoxelWorld* World, FQueuedThreadPool* ThreadPool, FVoxelChunkData* ChunkData)
{
	if (!World->FoliageConfig)
	{
		return false;
	}

	if (FoliageComplete)
	{
		return false;
	}

	if (!World->GetVoxelScenePlayer())
	{
		return false;
	}

	float DistanceBetweenPlayerAndChunk = (GetComponentLocation() - World->GetVoxelScenePlayer()->GetActorLocation()).Size() / World->VoxelMin;

	for (auto& Object : World->FoliageConfig->FoliageObject)
	{
		if (DistanceBetweenPlayerAndChunk / World->VoxelsPerChunk <= Object.DrawingRadius)
		{
			FAsyncTask<FVoxelFoliageAsyncTask>* FoliageTask = new FAsyncTask<FVoxelFoliageAsyncTask>(World, this, ChunkData);
			FoliageTask->StartBackgroundTask(/*ThreadPool*/);

			FoliageTasks.Add(FoliageTask);
		}
	}

	return true;
}

void UVoxelChunkComponent::UpdateMesh(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector> Normals, TArray<FLinearColor> Colors)
{ 
	//ClearMeshSection(0);

	if (Vertices.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), Colors, TArray<FVoxelProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}
	//Chunk->CreateFoliage(World, nullptr, Data);
}
/*
void UVoxelChunkComponent::ShouldFoliageBeCreated()
{
	//ClearMeshSection(0);
}*/

void UVoxelChunkComponent::UpdateFoliage(AVoxelWorld* World, TArray<FVector> FoliagePositions)
{
	for (auto& Position : FoliagePositions)
	{
		FTransform Transform;
		Transform.SetLocation(Position);

		World->FoliageMeshComponents[0]->AddInstance(Transform);
	}
}

void FVoxelMesherAsyncTask::DoWork()
{
	check(MesherObject != nullptr);

	MesherObject->GenerateDensityMap();
	MesherObject->GenerateMesh();

	TArray<FVector> Vertices =				MesherObject->Vertices;
	TArray<int32> Triangles =				MesherObject->Triangles;
	TArray<FVector> Normals =				MesherObject->Normals;
	TArray<FLinearColor> VertexColors =		MesherObject->VertexColors;

	AsyncTask(ENamedThreads::GameThread, [=]()
		{
		//	UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
			/*One more check active before we will create mesh*/
			if (Chunk->IsPoolActive())
			{
				Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors); 

				//World->ChunksFoliageCreation.Add(Data);
				//Chunk->CreateFoliage(World, nullptr, Data);
			}
		});

	Chunk->MeshComplete = true;
	World->TaskWorkGlobalCounter.Decrement();
	
//	UE_LOG(LogTemp, Warning, TEXT("Task is done %p"), Data->Chunk);
}


void FVoxelFoliageAsyncTask::DoWork()
{
	check(World->FoliageConfig != nullptr);

	TArray<FVector> FoliagePositions;

	int32 FoliageSteps = World->FoliageConfig->FoliageObject[0].Steps * World->VoxelMin;
	int32 FoliageCount = 16;//(16 * (World->MaximumLOD - Data->Depth + 1)) / FoliageSteps;

	for (int32 X = 0; X < FoliageCount; X++)
	{
		for (int32 Y = 0; Y < FoliageCount; Y++)
		{
			FVector Start = FVector(X, Y, Data->Size / 2) * FoliageSteps + Chunk->GetComponentLocation() - Data->Size / 2 * World->VoxelMin;
			FVector End = FVector(X, Y, -Data->Size / 2) * FoliageSteps + Chunk->GetComponentLocation() - Data->Size / 2 * World->VoxelMin;

			/*const FTraceHandle Handle = World->GetWorld()->AsyncLineTraceByChannel(
				EAsyncTraceType::Single,
				Start,
				End,
				ECC_Visibility);*/

			TArray<FHitResult> MouseHitResults; 

			if (World->GetWorld()->LineTraceMultiByChannel(MouseHitResults, Start, End, ECC_Visibility))
			{
				for (auto& Hit : MouseHitResults)
				{
				//	FoliagePositions.Add(Hit.ImpactPoint);
				//	if (Hit.Component == Chunk)
					if(Chunk->CurrentOctree.Pin()->IsInside(World->TransferToVoxelWorld(Hit.ImpactPoint)))
					{
						FoliagePositions.Add(Hit.ImpactPoint);
					}

				/*	if (HitWorld)
					{
						HitWorldPosition = Hit.ImpactPoint;
					}*/
				}
			}
		}
	}

	//TArray<FHitResult> MouseHitResults;
	/*
	if (GetWorld()->LineTraceMultiByChannel(MouseHitResults, Start, End, ECC_Visibility))
	{
		for (auto& Hit : MouseHitResults)
		{
			HitWorld = Cast<AVoxelWorld>(Hit.Component->GetOwner());

			if (HitWorld)
			{
				HitWorldPosition = Hit.ImpactPoint;
			}
		}
	}
	if (HitWorld)
	{
		EditorTool->ToolInitialize(EditorData, HitWorldPosition);
	}*/


	//FoliagePositions.Add(Chunk->GetComponentLocation());

	AsyncTask(ENamedThreads::GameThread, [=]()
		{
			//	UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
				/*One more check active before we will create mesh*/
			if (Chunk->IsPoolActive())
			{
				Chunk->UpdateFoliage(World, FoliagePositions);
			//	Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors);
			}
		});

	Chunk->FoliageComplete = true;
}