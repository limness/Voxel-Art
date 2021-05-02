// Voxel Art Plugin 2021 ~ Copyright Limit

#include "VoxelTypeActions.h"
#include "Helpers/VoxelTools.h"
//#include "VoxelCustomAssets/VoxelCustomGraph.h"
//#include "VoxelWorld.h"


/*void FVoxelTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	VOXEL_LOG(TEXT("Asset was opened"));

	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		UVoxelTestData* PropData = Cast<UVoxelTestData>(*ObjIt);
		if (PropData)
		{
			TSharedRef<FVoxelCustomGraph> NewCustEditor(new FVoxelCustomGraph());

			NewCustEditor->InitCustAssetEditor(Mode, EditWithinLevelEditor, PropData);
		}
	}
}*/