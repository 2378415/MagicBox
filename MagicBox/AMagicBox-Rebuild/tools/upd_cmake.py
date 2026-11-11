import io,sys,os,glob
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
# 1) makcu_proto CMakeLists: add new sources
srcs = sorted("src/" + os.path.basename(p) for p in glob.glob("components/makcu_proto/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"', ")"]
open("components/makcu_proto/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
print(open("components/makcu_proto/CMakeLists.txt").read())

# 2) makcu_mouse CMakeLists: add cmd_move.c
srcs = sorted("src/" + os.path.basename(p) for p in glob.glob("components/makcu_mouse/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"', "    REQUIRES makcu_proto", ")"]
open("components/makcu_mouse/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
print(open("components/makcu_mouse/CMakeLists.txt").read())
