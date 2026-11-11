import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 10 次；最新一轮 **68 例全绿**（67 passed + 1 xpassed：协议/报告 54 + 曲线 2 + 离线模型 12）；回滚新鲜回读 sha256 一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 11 次；最新一轮 **75 例全绿**（74 passed + 1 xpassed：协议/报告 54 + 键盘 7 + 曲线 2 + 离线模型 12）；回滚新鲜回读 sha256 一致 | `verification/report/` |',")
t=t.replace("'| 副作用层（P2 桥接 / P5 克隆） | 未开始 | UART1 桥接任务、描述符克隆、序列号读写 |',",
"'| 副作用层（P4 键盘） | **完成**：复合 HID（ID1 鼠标 / ID2 键盘），down/up/tap/type/批量/combo/state 全实现，`mx.rk` 可读回 8 字节报告 | `components/makcu_keyboard/` |',\n            '| 副作用层（P2 桥接 / P5 克隆） | 未开始 | UART1 桥接任务、描述符克隆、序列号读写（`serial()` 仍恒回失败文案） |',")
open(p,"w",encoding="utf-8").write(t)
print("status updated")
