// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerEditor.h"
#include "Components/CapsuleComponent.h"
#include "Helpers/VoxelTools.h"

DECLARE_CYCLE_STAT(TEXT("Voxel Player Editor ~ Tick"), STAT_Tick, STATGROUP_Voxel);

AVoxelPlayerEditor::AVoxelPlayerEditor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AVoxelPlayerEditor::Destroyed()
{
}

void AVoxelPlayerEditor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SCOPE_CYCLE_COUNTER(STAT_Tick);
	/*if (VoxelScenePlayer)
	{
		UE_LOG(VoxelArt, Error, TEXT("Player is already exist"));
	}*/
	if (bEnabled && GEditor)
	{
		FEditorViewportClient* EditorViewportClient = nullptr;

		if (FViewport* Viewport = GEditor->GetActiveViewport())
		{
			if (FViewportClient* CurrentClient = Viewport->GetClient())
			{
				for (FEditorViewportClient* Client : GEditor->GetAllViewportClients())
				{
					if (Client == CurrentClient)
					{
						Velocity = (GetActorLocation() - Client->GetViewLocation()).Size() / DeltaTime;
						SetActorLocation(Client->GetViewLocation());
						break;
					}
				}
			}
		}
	}
}

float AVoxelPlayerEditor::GetVoxelVelocity()
{
	return Velocity;
}

bool AVoxelPlayerEditor::ShouldTickIfViewportsOnly() const
{
	return true;
}