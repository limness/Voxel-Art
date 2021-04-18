// Voxel Art Plugin © limit 2018

#include "Save/VoxelSaveData.h"
#include "Helpers/VoxelTools.h"
#include "Octree/VoxelOctreeData.h"
#include "VoxelWorld.h"

void UVoxelSaveData::Init()
{
}

void UVoxelSaveData::SetVoxelWorld(AVoxelWorld* _World)
{
	World = _World;
}

void UVoxelSaveData::SaveData()
{
	if (World)
	{
		{
			SavedOctants.Empty();

			WorldSize =			World->WorldSize;
			WorldDepth =		World->MaximumLOD;
			WorldVoxels =		World->VoxelsPerChunk;
			WorldVoxelSize =	World->VoxelMin;
		}
		{
			World->OctreeMutex.Lock();

			TArray<FVoxelOctreeDensity*> OctreeDensityLeaves;
			GetOctreeDensityLeaves(OctreeDensityLeaves, World->OctreeDensity);

			for (auto& Octant : OctreeDensityLeaves)
			{
				FVoxelSaveOctant		SaveOctant;
				SaveOctant.Depth = Octant->Depth;
				SaveOctant.Size = Octant->Size;
				SaveOctant.Position = Octant->Position;
				SaveOctant.DensityMap = Octant->DensityMap;
				SaveOctant.ColorMap = Octant->ColorMap;

				SavedOctants.Add(SaveOctant);
			}
			World->OctreeMutex.Unlock();

			bDataSaved = true;
		}
		UE_LOG(VoxelArt, Log, TEXT("World was saved!"));
	}
}

void UVoxelSaveData::LoadSavedData()
{
	if (World)
	{
		if (bDataSaved)
		{
			if (WorldSize != World->WorldSize)
			{
				UE_LOG(VoxelArt, Error, TEXT(
					"The World Size of the saved world does not match the current World Size\n\
					It should be: %d. Change the parameter manually before the next load. The world cannot be loaded at this time"
				), WorldSize);
				return;
			}
			if (WorldDepth != World->MaximumLOD)
			{
				UE_LOG(VoxelArt, Error, TEXT(
					"The World Maximum LOD of the saved world does not match the current Maximum LOD\n\
					It should be: %d. Change the parameter manually before the next load. The world cannot be loaded at this time"
				), WorldDepth);

				/*
				FMessageLog("PIE").Error(LOCTEXT("World", "So"));

				FMessageDialog::Open(EAppMsgType::Ok, INVTEXT(
					"The World Maximum LOD of the saved world does not match the current Maximum LOD\n\
					It should be: 0. Change the parameter manually before the next load. The world cannot be loaded at this time"
				));*/

				return;
			}
			if(WorldVoxels != World->VoxelsPerChunk)
			{
				UE_LOG(VoxelArt, Error, TEXT(
					"The Voxels Per One Chunk of the saved world does not match the current one\n\
					It should be: %d. Change the parameter manually before the next load. The world cannot be loaded at this time"
				), WorldVoxels);
				return;
			}
			if (WorldVoxelSize != World->VoxelMin)
			{
				UE_LOG(VoxelArt, Error, TEXT(
					"The Voxel Minimum of the saved world does not match the current Voxel Minimum\n\
					It should be: %f. Change the parameter manually before the next load. The world cannot be loaded at this time"
				), WorldVoxelSize);
				return;
			}

			for (auto& SavedOctant : SavedOctants)
			{
				check (SavedOctant.DensityMap.Num() != 0);

				FVoxelOctreeDensity* OutOctant = nullptr;

				for (int Z = 1; Z < WorldVoxels + 1; Z++)
				{
					for (int Y = 1; Y < WorldVoxels + 1; Y++)
					{
						for (int X = 1; X < WorldVoxels + 1; X++)
						{
							int HalfSize = WorldVoxels >> 1;
							int Index = World->GetIndex(FIntVector(X + NORMAL, Y + NORMAL, Z + NORMAL));
							FIntVector Position = SavedOctant.Position + FIntVector(X - HalfSize, Y - HalfSize, Z - HalfSize);

							World->SetVoxelValue(OutOctant, Position, SavedOctant.DensityMap[Index], SavedOctant.ColorMap[Index], true, true);
						}
					}
				}
			}
			UE_LOG(VoxelArt, Log, TEXT("World was loaded!"));
		}
		else
		{
			UE_LOG(VoxelArt, Error, TEXT("No data to load!"));
		}
	}
	else
	{
		UE_LOG(VoxelArt, Error, TEXT("Invalid Voxel World! Can't be loaded!"));
	}
}

void UVoxelSaveData::GetOctreeDensityLeaves(TArray<FVoxelOctreeDensity*>& OctreeDensityLeaves, FVoxelOctreeDensity* CurrentOctant)
{
	if (!CurrentOctant->HasChildren())
	{
		if(CurrentOctant->HasOwnDensity() || CurrentOctant->HasOwnColor())
		{
			OctreeDensityLeaves.Add(CurrentOctant);
		}
	}
	else
	{
		for (auto& ChildOctant : CurrentOctant->GetChildren())
		{
			GetOctreeDensityLeaves(OctreeDensityLeaves, ChildOctant);
		}
	}
}