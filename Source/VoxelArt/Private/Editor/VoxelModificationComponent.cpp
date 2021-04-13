// Voxel Art Plugin © limit 2018


#include "Editor/VoxelModificationComponent.h"

// Sets default values for this component's properties
UVoxelModificationComponent::UVoxelModificationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVoxelModificationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UVoxelModificationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

/*void UVoxelModificationComponent::Modification(
	AVoxelLandscape* terrain,
	AVoxelChunk* chunkCenter,
	FVector position,
	float range)
{
	if (modificator != nullptr)
	{
		int intRange = 1;
		int normaldx = 0;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		TArray<AActor*> OverlapActors;

		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

		if (UKismetSystemLibrary::SphereOverlapActors(this, position, range, ObjectTypes, AVoxelChunk::StaticClass(), TArray<AActor*>(), OverlapActors))
		{
			for (AActor* OverlapActor : OverlapActors)
			{
				AVoxelChunk* chunk = Cast<AVoxelChunk>(OverlapActor);

				if (!chunk->isPool)
				{
					if (chunk->Grid.Num() > 0)
					{
						//range, chunkCenter, hitPosition - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, bool smooth
						float noise = 0.f;
						float strength = 0.f;
						bool smooth = false;

						//modificator->GetPainterData(positionNoise.X, positionNoise.Y, positionNoise.Z, noise, strength, smooth);

						//chunk->ChangeVoxel(range, chunkCenter, position - chunkCenter->GetActorLocation(), EditorRemovePressed ? editorSpeed : -editorSpeed, strength, sphereMinus);
//						chunk->ChangeVoxel(modificator, position, range, 10.f);
						chunk->GenerateVertexCube(true);
					}
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ VoxelCord Plugin : ModificatorComponent ] Error: Painter is empty, modificator can't be started"));
	}
}
*/