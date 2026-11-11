import glob
srcs = sorted("src/" + p.split("\\")[-1].split("/")[-1] for p in glob.glob("components/makcu_proto/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"', "    REQUIRES makcu_dev", ")"]
open("components/makcu_proto/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
print("cmake updated:", len(srcs), "sources")
