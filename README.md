> **🚧 Currently in early development and unusable 🚧** (~10% done)

Reverse engineering effort of the PhysicsRig from Boneworks and porting it to Bonelab.

## Why?

1. The movement in Boneworks is better and more fun than Bonelab in a lot of ways:
   - Jumping while slightly crouched gives a small speed boost in the direction you're facing
   - This enables various types of "bunny hopping" movement techniques
   - Can run at full speed while crouching (if crouching in real life)
   - More agile and less floaty in general (more immediate acceleration, on ground and in air)
   - Smaller physical rig (can navigate tighter gaps without getting stuck and perform clips)
1. In addition to this, a faithful port of Boneworks movement will give a more authentic Boneworks experience in Labworks
1. Also I'm just kinda curious how the physics rig works

## How?

The Boneworks GameAssembly.dll is reverse engineered using [Ghidra](https://ghidra-sre.org/) and the scripts and output provided by [Il2CppDumper](https://github.com/Perfare/Il2CppDumper). The Ghidra archive and outputs from tools I'm using are included in this repo.

## File structure

Decompiled code is in the src directory. Each class has a folder containing the following files:

| Name          | Description                                                                                                 |
| ------------- | ----------------------------------------------------------------------------------------------------------- |
| ghidra/NAME.c | Automatically decompiled method code from Ghidra (with some manual variable renaming and data type fixing). |
| NAME.bw.cs    | Reverse engineered C# code based on the Ghidra decompilation.                                               |
| NAME.bl.cs    | Port of NAME.bw.cs to work in Bonelab and with its systems.                                                 |
