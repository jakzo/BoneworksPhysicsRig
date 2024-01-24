import fs from "fs/promises";

const contents = await fs.readFile("il2cpp.h", "utf8");
const fixedContents = contents.replace(
  /(^\s*struct\s+\w+\s*\{\n.+\bklass;\n.+\bmonitor;)(\n.+?Fields)/gm,
  "$1\n\tvoid *_unknown;$2"
);
await fs.rename("il2cpp.h", "il2cpp.original.h");
await fs.writeFile("il2cpp.h", fixedContents);
