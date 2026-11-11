import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 厂商函数重写（P2–P5） | 已移植 22 支（见下节），其余 5 个仍是 todo | `components/makcu_proto/handlers.def` |',",
"'| 命令协议层 | **27/27 个 opcode 全部实现**（43 条文本命令 + 3 个跳表专用入口） | `components/makcu_proto/handlers.def` |',")
t=t.replace("'| 烧录 + 回归（T2） | 已上机 5 次；最新一轮 **38 例全绿**（37 passed + 1 xpassed，含 10 条隐藏 opcode 用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 6 次；最新一轮 **45 例全绿**（44 passed + 1 xpassed，含 14 条隐藏 opcode 用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',")
t=t.replace("""            '| 厂商函数重写（P2–P5） | 未开始""","""            '| 厂商函数重写（P2–P5） | 协议层完成""")
# 端口面：副作用层仍是待办
t=t.replace("其中 6 个 handler 已移植（见上节），其余 21 个在 `handlers.def` 里标为 todo。",
            "其中 27 个 handler 已全部移植；剩下的是各组件里 `*_stub.c` 列出的副作用函数（运动队列、HID 写入、描述符克隆、桥接任务）。")
open(p,"w",encoding="utf-8").write(t)
print("status.py updated")
