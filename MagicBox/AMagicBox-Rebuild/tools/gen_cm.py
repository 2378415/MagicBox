# 生成各组件与 app 的 CMakeLists / 骨架
import os, io, sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")

comps = {
 "makcu_link": ("makcu_link", "UART1 5A 帧构建/解析（纯 C）", []),
 "makcu_mouse": ("makcu_mouse", "鼠标提交队列、Bezier、锁/抓取", ["makcu_proto"]),
 "makcu_keyboard": ("makcu_keyboard", "HID usage 写入、批量、组合、点按", ["makcu_proto"]),
 "makcu_hiddev": ("makcu_hiddev", "LEFT: 描述符克隆、序列号伪装", ["makcu_proto"]),
 "makcu_hidhost": ("makcu_hidhost", "RIGHT: USB host 枚举、0xA2 上报", ["makcu_proto","makcu_link"]),
 "makcu_board": ("makcu_board", "LED / eFuse / coredump / NVS 键", []),
}
for d,(name,desc,reqs) in comps.items():
    os.makedirs(f"components/{d}/src", exist_ok=True)
    os.makedirs(f"components/{d}/include", exist_ok=True)
    srcs = [f"src/{f}" for f in (os.listdir(f"components/{d}/src") if os.path.isdir(f"components/{d}/src") else []) if f.endswith(".c")]
    if not srcs:
        srcs = [f"src/{name}_stub.c"]
    req = ", ".join(f'"{r}"' for r in reqs) if reqs else ""
    with open(f"components/{d}/CMakeLists.txt","w",encoding="utf-8") as fh:
        fh.write("idf_component_register(\n")
        fh.write('    SRCS ' + " ".join(f'"{s}"' for s in srcs) + "\n")
        fh.write('    INCLUDE_DIRS "include"\n')
        fh.write(f"    REQUIRES {req}\n" if req else "")
        fh.write(")\n")
print("component CMakeLists written")
