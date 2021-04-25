# Voxel-Art
__Voxel Art Plugin__ — This is a tool that allows you to create entire worlds that you can modify directly in game mode. Landscapes can be completely different shapes, flat, ribbed, planetary, dune, it all depends on your imagination. Voxels can be not only cubic, but also smoothed. Which allows you to unleash your full creative potential, as well as enjoy the speed and great functionality of the plugin.

All of you know the game of mancraft, and what fantastic things you can make inside this amazing game. The world itself inside of minecraft is made up of voxels - cubes, but the voxels themselves can have completely different shapes. The Voxel Art plugin gives you the opportunity to create your own game with completely bizarre shapes and landscapes, in totally different styles. And the smart multi-threading and generation optimisation allows you to exploit the full potential of your computer power.

`Unreal Engine Version 4.25-4.26`

### Features:

- Voxel Storage System
- Voxel Importer
- Voxel Splines
- Voxel Preview mode
- Voxel Multithreading
- Voxel Task prioritisation
- Any shapes for the world
- Realtime Editing

### Support:

- [My Twitter](https://twitter.com/limtosingular)
- [Discord channel](https://discord.gg/FX3zzNxPq3)

# Documentation
### Set up plugin:
- Create a new directive inside your main UE4 project and name it __Plugins__ (If there is no such directive)
- Place the plugin in new directive
- Start the project and confirm the pop-up window for creating new builds</br>![markdown logo](https://i.ibb.co/WgWhgvB/UE4-Editor-GBu-AHb5-Djl.png)
### Create new Voxel World:
As soon as the project starts, select the right area of the __Place__ __Actors__  editor and enter `Voxel World` in the search box
- Place the new `Voxel World component` on the scene
- To be able to edit the game world directly in the game. You must select a new class in the game mod as your primary controller. 
![markdown logo](https://i.imgur.com/bNZPSNK.png)
- Generate noise in a new file or use an existing one for the World Generator category
![markdown logo](http://i.piccy.info/i9/a77461b290bfca8c160e081c27d64330/1619034527/15583/1425940/222222222222222.png)
- You can click on the "Create World" button to preview the world</br>
![markdown logo](http://i.piccy.info/i9/db43b4b85db2db609ff1e9fb0396a7a9/1619034440/6065/1425940/111111111.png)
- You can manually change the size of the entire world, the amount of LOD detail, the size of each voxel, and the size of the chunk.
![markdown logo](https://i.imgur.com/JTCQCP8.png)

### Create custom Generator:
Generate noise in a new file or use an existing one for the World Generator category
By default, you can choose already ready-made examples of the generated landscape, which has been set up beforehand in the C++ class. 
- `Voxel World Generator`</br>
Default empty generator. Can be used for heightmap importing
- `Voxel World Flat Generator`</br>
Generates default flat world
- `Voxel World Planet Generator`</br>
Generates planet world using Fractal Noise + Sphere

#### Of course you can create your own noise for the world, for this you need the following:</br></br>
Create a new C++ class that inherits from the main Voxel World Generator class</br></br>
![markdown logo](https://i.ibb.co/4WV3bxg/28-db-Oye-Zk-Q.jpg)</br></br>
Name the class with any free name. The recommended name is `VoxelWorld[YourName]Generator`. And then select the VoxelArt module and the `VoxelArt/Public/Generators` directory, as shown below</br></br>
![markdown logo](https://i.ibb.co/prjT9ws/Za8ipu7-Jp-Eg.jpg)</br></br>
In the class that opens, you will need to redefine two methods</br>
- `Get Density Map` - this method defines the shape of your landscape (noise)
- `Get Color Map` - in charge of what color your landscape will be.
Do as shown below.</br></br>

> If the class was created without the U prefix, add it</br>
> Name this as **UVoxelWorld[YourName]Generator**</br>

`VoxelWorldMyNameGenerator.h`
```c++
#pragma once

#include "CoreMinimal.h"
#include "Generators/VoxelWorldGenerator.h"
#include "VoxelWorldMyNameGenerator.generated.h"

/**
*
*/
UCLASS()
class VOXELART_API UVoxelWorldMyNameGenerator : public UVoxelWorldGenerator
{
  GENERATED_BODY()

private:

  virtual float GetDensityMap(const FIntVector& CellPosition);
  virtual FColor GetColorMap(const FIntVector& CellPosition);
};
```
You must also add a VoxelTools directive to the cpp file header in order to use special plugin tools (Such as: logging, ready-made colors, etc.). For the example I used a formula to display a flat world (More examples in the Generators file)</br>

> If the editor gives an error like "The file was not found in the directory</br>
> Add **#include "Generators/VoxelWorld[YourName]Generator.h"** instead of **#include "VoxelWorld[YourName]Generator.h"**</br>
> (Provided the class was created exactly in the Generators directory)</br>

`VoxelWorldMyNameGenerator.cpp`
```c++
#include "Generators/VoxelWorldMyNameGenerator.h"
#include "Helpers/VoxelTools.h"

float UVoxelWorldMyNameGenerator::GetDensityMap(const FIntVector& CellPosition)
{
  Super::GetDensityMap(CellPosition);

  float Value = CellPosition.Z + Height + VoxelTools::VoxelOffset;
  return Value;
}

FColor UVoxelWorldMyNameGenerator::GetColorMap(const FIntVector& CellPosition)
{
  Super::GetColorMap(CellPosition);
  
  return VOXEL_COLOR;
}
```

Once you compile the finished class. Select a new generator class in the Voxel World properties. If you have done everything correctly, the new generator class should appear in the corresponding window in the Voxel World properties. Select it and click **Play** or create a preview of the world by clicking **Create World**</br></br>
![markdown logo](https://i.ibb.co/56ywMWw/Nq-Zeez6xf-Jk.jpg)

### Editing the world in editor mode
The plugin allows you to pre-edit and modify the world as you see fit (and then save it to a separate file if you need it). 
To do this, go to category `Modes -> Voxel Art Editor Mode`

# Screenshots
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_tLjSZZYAlk.1619035360.png)
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_VeoRefedaj.1619035380.png)
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_PcToZuxbrT.1619035406.png)
