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

void UVoxelChunkComponent::SetPoolActive(AVoxelWorld* World, bool activeStatus)
{
	PoolActive = activeStatus;

	if (!activeStatus)
	{
		if (MesherTask)
		{
			MesherTask->EnsureCompletion();
			delete MesherTask;
			MesherTask = nullptr;
		}
		for (auto& FoliageTask : FoliageTasks)
		{
		//	FoliageTask->EnsureCompletion();
			//delete FoliageTask;
			//FoliageTask = nullptr;
		}
		FoliageTasks.Empty();

		if (MesherObject)
		{
			delete MesherObject;
			MesherObject = nullptr;
		}
		//for (auto& ObjectIndex : FoliageObjects)
		{
			/*if (World->FoliageMeshComponents[0]->RemoveInstance(ObjectIndex))
			{

			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("not success remove"));
			}*/
		}
		FoliageObjects.Empty();

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
	if (MesherTask)
	{
		MesherTask->EnsureCompletion();
		delete MesherTask;
		MesherTask = nullptr;
	}

	World->MesherWorkTasksCounter.Increment();

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
			//World->VoxelDebugBox(World->TransferToGameWorld(ChunkData->Position), ChunkData->Size / 2 * World->VoxelMin, 100.f, FColor::Red);

			FAsyncTask<FVoxelFoliageAsyncTask>* FoliageTask = new FAsyncTask<FVoxelFoliageAsyncTask>(World, this, ChunkData);
			FoliageTask->StartBackgroundTask(/*ThreadPool*/);

			FoliageTasks.Add(FoliageTask);
		}
	}

	return true;
}

void UVoxelChunkComponent::UpdateMesh()
{ 
	//ClearMeshSection(0);

	if (Vertices.Num() > 0)
	{
		CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, TArray<FVector2D>(), VertexColors, TArray<FVoxelProcMeshTangent>(), true);
		SetMaterial(0, Material);
	}

	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	VertexColors.Empty();
	//Chunk->CreateFoliage(World, nullptr, Data);
}
/*
void UVoxelChunkComponent::ShouldFoliageBeCreated()
{
	//ClearMeshSection(0);
}*/

void UVoxelChunkComponent::UpdateFoliage(AVoxelWorld* World, TArray<FTransform> FoliagePositions)
{
	for (auto& Transform : FoliagePositions)
	{
		FoliageObjects.Add(World->FoliageMeshComponents[0]->AddInstance(Transform));
	}
}

void FVoxelMesherAsyncTask::DoWork()
{
	check(IsValid(Chunk));
	check(MesherObject != nullptr);

	//UE_LOG(LogTemp, Warning, TEXT("Start DoWork Chunk %p"), Chunk);

	MesherObject->TransitionSides = Data->TransitionSides;

	MesherObject->GenerateDensityMap();
	MesherObject->GenerateMesh();

	Chunk->Vertices =		MesherObject->Vertices;
	Chunk->Triangles =		MesherObject->Triangles;
	Chunk->Normals =		MesherObject->Normals;
	Chunk->VertexColors =	MesherObject->VertexColors;

	//UE_LOG(LogTemp, Warning, TEXT("End use %p"), MesherObject);

	//check(IsValid(Chunk));
	//UE_LOG(LogTemp, Warning, TEXT("End DoWork Chunk %p"), Chunk);

	World->AddChunkToUpdate(Chunk);
	//Chunk->MeshComplete = true;
	/*AsyncTask(ENamedThreads::GameThread, [=]()
		{
			check(IsValid(Chunk));
		//	UE_LOG(LogTemp, Warning, TEXT("From mesher Vertices %d Triangles %d Normals %d"), Vertices.Num(), Triangles.Num(), Normals.Num());
			/*One more check active before we will create mesh*/
	/*		if (Chunk->IsPoolActive())
			{
				Chunk->UpdateMesh(Vertices, Triangles, Normals, VertexColors); 

				//World->ChunksFoliageCreation.Add(Data);
				Chunk->CreateFoliage(World, nullptr, Data);
			}
			Chunk->MeshComplete = true;
			World->TaskWorkGlobalCounter.Decrement();
		});*/
	
//	UE_LOG(LogTemp, Warning, TEXT("Task is done %p"), Data->Chunk);
}


void FVoxelFoliageAsyncTask::DoWork()
{
	check(World->FoliageConfig != nullptr);

	TArray<FTransform> FoliagePositions;

	float FoliageSteps = Data->Size / World->VoxelsPerChunk * World->VoxelMin;//World->FoliageConfig->FoliageObject[0].Steps;
	int32 FoliageCount = World->VoxelsPerChunk;//(16 * (World->MaximumLOD - Data->Depth + 1)) / FoliageSteps;

	//UE_LOG(LogTemp, Warning, TEXT("GetComponentLocation %s"), *Chunk->GetComponentLocation().ToString());

	for (int32 X = 0; X < FoliageCount; X++)
	{
		for (int32 Y = 0; Y < FoliageCount; Y++)
		{
			FTransform NewFoliage;
			FIntVector VoxelPosition = FIntVector(X, Y, 0) + Data->Position - FIntVector(1, 1, 1) * Data->Size;

			if (VoxelPosition.X % World->FoliageConfig->FoliageObject[0].Steps != 0) continue;
			if (VoxelPosition.Y % World->FoliageConfig->FoliageObject[0].Steps != 0) continue;
			if (World->FoliageConfig->FoliageObject[0].Random && !FMath::RandBool()) continue;

			////////////////////////////
			////////////////////////////

			FVector Start = FVector(X, Y, World->VoxelsPerChunk) * FoliageSteps + Chunk->GetComponentLocation() - Data->Size / 2 * World->VoxelMin;/*- Data->Size / 2 * World->VoxelMin*///;
			FVector End = FVector(X, Y, 0) * FoliageSteps + Chunk->GetComponentLocation() - Data->Size / 2 * World->VoxelMin;

			float Range = World->FoliageConfig->FoliageObject[0].RangeSpawn * World->VoxelMin * World->FoliageConfig->FoliageObject[0].Steps;

			Start += FVector(FMath::RandRange(-Range, Range), FMath::RandRange(-Range, Range), 0);
			End += FVector(FMath::RandRange(-Range, Range), FMath::RandRange(-Range, Range), 0);

			////////////////////////////
			////////////////////////////

			TArray<FHitResult> MouseHitResults; 

			if (World->GetWorld()->LineTraceMultiByChannel(MouseHitResults, Start, End, ECC_Visibility))
			{
				for (auto& Hit : MouseHitResults)
				{
					check(IsValid(Chunk));

					//if(Chunk->CurrentOctree.Pin()->IsInside(World->TransferToVoxelWorld(Hit.ImpactPoint)))
					{
						if (World->FoliageConfig->FoliageObject[0].RandomRotation)
						{
							NewFoliage.SetRotation(FQuat(FRotator(FMath::RandRange(0, 360), FMath::RandRange(0, 360), FMath::RandRange(0, 360))));
						}
						NewFoliage.SetLocation((FVector)World->TransferToVoxelWorld(Hit.ImpactPoint));
						NewFoliage.SetScale3D(FVector::OneVector / 128.f);
						FoliagePositions.Add(NewFoliage/*Hit.ImpactPoint*/);
					}
				}
			}
		}
	}
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