Project created with Ghidra 11.0:

- New project -> Import GameAssembly.dll
- Auto analyze (default settings)
- Parse C source -> add il2cpp.h from il2cppdumper
- Run il2cppdumper ghidra_with_structs.py script

The project includes some manual changes like variable/method renaming and data type fixing.
