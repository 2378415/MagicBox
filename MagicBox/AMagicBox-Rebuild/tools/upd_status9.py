import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 7 次；最新一轮 **52 例全绿**（51 passed + 1 xpassed，含 14 条隐藏 opcode + 7 条报告内容用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 9 次；最新一轮 **61 例全绿**（60 passed + 1 xpassed：协议 52 + 分步轨迹 4 + 离线模型 5）；回滚新鲜回读 sha256 一致 | `verification/report/` |',")
t=t.replace("'| 副作用层（P4 运动） | **队列/请求层完成**：`move`/`wheel`/`silent` 已产生 HID 报告（`mx.rp` 可读回）；Bezier 引擎（0x4200EFEC）仍为分阶段实现 | `components/makcu_mouse/` |',",
"'| 副作用层（P4 运动） | **队列 + 分步引擎完成**：按 int8 上限分步、最大余数法守恒、步间 `vTaskDelay(1)`、`mx.rq` 可读回整串轨迹；Bezier 的旋转/缓动数学仍未移植 | `components/makcu_mouse/` |',")
open(p,"w",encoding="utf-8").write(t)
print("status updated")
