import glob
# makcu_proto sources + declare dependency on makcu_dev
srcs = sorted("src/" + p.split("\\")[-1].split("/")[-1] for p in glob.glob("components/makcu_proto/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"', "    REQUIRES makcu_dev", ")"]
open("components/makcu_proto/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
# makcu_dev component
srcs = sorted("src/" + p.split("\\")[-1].split("/")[-1] for p in glob.glob("components/makcu_dev/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"', ")"]
open("components/makcu_dev/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
print(open("components/makcu_proto/CMakeLists.txt").read())
print(open("components/makcu_dev/CMakeLists.txt").read())
