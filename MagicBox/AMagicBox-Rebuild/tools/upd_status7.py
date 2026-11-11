import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 副作用层（P2/P4/P5） | 未开始 | 运动队列、HID 报告写入、描述符/序列号、UART1 桥接任务；端口清单见各组件 `*_stub.c` |',",
"'| 副作用层（P4 运动） | **队列/请求层完成**：`move`/`wheel`/`silent` 已产生 HID 报告（`mx.rp` 可读回）；Bezier 引擎（0x4200EFEC）仍为分阶段实现 | `components/makcu_mouse/` |',\n            '| 副作用层（P2/P5） | 未开始 | HID 报告实际上报（`makcu_hiddev`）、描述符克隆/序列号、UART1 桥接任务 |',")
t=t.replace("'| 烧录 + 回归（T2） | 已上机 6 次；最新一轮 **45 例全绿**（44 passed + 1 xpassed，含 14 条隐藏 opcode 用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 7 次；最新一轮 **52 例全绿**（51 passed + 1 xpassed，含 14 条隐藏 opcode + 7 条报告内容用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',")
open(p,"w",encoding="utf-8").write(t)
print("status.py updated")
