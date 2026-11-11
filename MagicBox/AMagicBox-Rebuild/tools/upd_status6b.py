import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 厂商函数重写（P2–P5） | 已移植 27 支（见下节），其余 0 个仍是 todo | `components/makcu_proto/handlers.def` |',",
"'| 命令协议层（P3 文本层） | **27/27 个 opcode 全部实现**（43 条文本命令 + 3 个跳表专用入口），逐字节与原厂一致 | `components/makcu_proto/handlers.def` |',")
t=t.replace("""            '| 厂商函数重写（P2–P5） | 未开始 | 端口清单见各组件 `*_stub.c` 的 TODO 段；`handlers.def` 控制哪些 handler 已实现 |',
""","""            '| 副作用层（P2/P4/P5） | 未开始 | 运动队列、HID 报告写入、描述符克隆、UART1 桥接任务；端口清单见各组件 `*_stub.c` 的 TODO 段 |',
""")
open(p,"w",encoding="utf-8").write(t)
print("ok")
