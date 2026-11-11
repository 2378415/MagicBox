import glob
for comp, reqs in (("makcu_proto", []), ("makcu_mouse", ["makcu_proto"])):
    srcs = sorted("src/" + p.split("\\")[-1].split("/")[-1] for p in glob.glob(f"components/{comp}/src/*.c"))
    lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
             '    INCLUDE_DIRS "include"']
    if reqs:
        lines.append("    REQUIRES " + " ".join(reqs))
    lines.append(")")
    open(f"components/{comp}/CMakeLists.txt", "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(comp, srcs)
