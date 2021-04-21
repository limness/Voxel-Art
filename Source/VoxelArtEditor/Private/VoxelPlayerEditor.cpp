// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelPlayerEditor.h"
#include "Components/CapsuleComponent.h"

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
						SetActorLocation(Client->GetViewLocation());
						break;
					}
				}
			}
		}
	}
}

bool AVoxelPlayerEditor::ShouldTickIfViewportsOnly() const
{
	return true;
}