Generated with command:

```bat
..\Il2CppDumper.exe "C:\Program Files (x86)\Steam\steamapps\common\BONEWORKS\BONEWORKS\GameAssembly.dll" "C:\Program Files (x86)\Steam\steamapps\common\BONEWORKS\BONEWORKS\BONEWORKS_Data\il2cpp_data\Metadata\global-metadata.dat" ".\il2cppdumper\output"
```

`il2cpp.h` fixed with command:

```bat
node .\il2cppdumper\il2cpp_header_fixer.mjs
```

Requires [Node.js](https://nodejs.org/) to be installed.

This fix was required because I noticed that the Ghidra decompilation fields were all wrong. Looking at the assembly the offsets matched the offsets in `dump.cs` but not the ones in the types imported from `il2cpp.h` which only included 16 bytes of data before the fields in objects (instead of 24). This script adds an extra 8 bytes before fields to every object in `il2cpp.h`. I'm not sure if this is a bug in Il2CppDumper or if I just did something wrong.
