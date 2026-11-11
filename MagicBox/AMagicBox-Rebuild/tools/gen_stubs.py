import os, io, sys, glob
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
OLD = os.path.dirname(os.path.dirname(os.path.abspath(".")))  # will fix below
OLD = r"D:\JinPeng\MagicBox\reversed\src"

def functions(side, module):
    out=[]
    for p in sorted(glob.glob(os.path.join(OLD, side, module, "*.c"))):
        fn=os.path.basename(p)
        if fn.startswith("_"): continue
        entry,_,name = fn[:-2].partition("_")
        out.append((entry,name))
    return out

specs = {
  ("makcu_mouse","left"):  ["mouse"],
  ("makcu_keyboard","left"): ["keyboard"],
  ("makcu_hiddev","left"): ["hid"],
  ("makcu_board","left"): ["led","efuse","crash"],
  ("makcu_hidhost","right"): ["hid"],
}
for (comp,side),mods in specs.items():
    rows=[]
    for m in mods:
        rows += functions(side,m)
    src=f"components/{comp}/src/{comp}_stub.c"
    with open(src,"w",encoding="utf-8") as fh:
        fh.write(f"/* {comp}: port surface from the reversed {'LEFT' if side=='left' else 'RIGHT'} image.\n"
                 f" *\n"
                 f" * Generated list only - each row is a function that still has to be rewritten\n"
                 f" * here.  Keep the entry address in the comment: tools/diff_insn.py compares the\n"
                 f" * rebuilt function against the original at that address (T3).\n"
                 f" *\n"
                 f" * entry     name\n")
        for e,n in rows:
            fh.write(f" * {e}  {n}\n")
        fh.write(" */\n\n#include <stddef.h>\n\n")
        for e,n in rows:
            fh.write(f"/* TODO {e}  {n} */\n")
        fh.write(f"\nconst unsigned {comp}_port_surface = {len(rows)};\n")
    print(comp, len(rows), "functions listed")
