Project created with Ghidra 11.0:

- New project -> Import GameAssembly.dll
- Auto analyze (default settings)
- Fix il2cppdumper output file il2cpp.h using my script
  - `node ./fix_il2cpp_header.mjs` (requires node.js to be installed)
- Parse C source -> add il2cpp.h from il2cppdumper
- Run il2cppdumper ghidra_with_structs.py script
