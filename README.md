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
- Generate noise in a new file or use an existing one for the World Generator category
![markdown logo](http://i.piccy.info/i9/a77461b290bfca8c160e081c27d64330/1619034527/15583/1425940/222222222222222.png)
- You can click on the "Create World" button to preview the world</br>
![markdown logo](http://i.piccy.info/i9/db43b4b85db2db609ff1e9fb0396a7a9/1619034440/6065/1425940/111111111.png)

You can manually change the size of the entire world, the amount of LOD detail, the size of each voxel, and the size of the chunk.
![markdown logo](https://i.imgur.com/JTCQCP8.png)

### Generate custom landscape:
Generate noise in a new file or use an existing one for the World Generator category
By default, you can choose already ready-made examples of the generated landscape, which has been set up beforehand in the C++ class. 
- `Voxel World Generator`</br>
Default empty generator. Can be used for heightmap importing
- `Voxel World Flat Generator`</br>
Generates default flat world
- `Voxel World Planet Generator`</br>
Generates planet world using Fractal Noise + Sphere

Of course you can create your own noise for the world, for this you need the following:
- Create a new C++ class that inherits from the main Voxel World Generator class
![markdown logo](https://i.ibb.co/HzCwKPJ/UE4-Editor-Gf58bdp1s9.png)
- Name the class with any free name. The recommended name is `Voxel World [Your Name] Generator`
- In the class that opens, you will see a window with two methods. The method you are interested in at the moment is `Get Density Map`. This method is responsible for what kind of shape your world will have. I opened a ready-made Voxel World Planet Generator class as an example. That generates first a regular sphere and then adds some fractal noise. 
![markdown logo](https://i.ibb.co/6rmhCxr/devenv-Iug-NT7-Itc-S.png)
- Once you compile the finished class. Select a new generator class in the Voxel World properties
- If you have done everything correctly, the new generator class should appear in the corresponding window in the Voxel World properties. Select it and click **Play** or create a preview of the world by clicking **Create World**
![markdown logo](https://i.ibb.co/18fZLSz/UE4-Editor-ae-Jv-N8fp2-G.png)

# Screenshots
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_tLjSZZYAlk.1619035360.png)
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_VeoRefedaj.1619035380.png)
![markdown logo](http://ipic.su/img/img7/fs/UE4Editor_PcToZuxbrT.1619035406.png)
