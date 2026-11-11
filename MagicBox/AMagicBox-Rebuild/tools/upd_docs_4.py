import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
# status: 回归数字改成最新一轮，并写入 CH343 不能复位的测试约束
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 3 次；最新一轮 **19 例全绿**（18 passed + 1 xpassed），UART0 与原生 USB 两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 4 次；最新一轮 **26 例全绿**（25 passed + 1 xpassed），UART0 与原生 USB 两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',")
open(p,"w",encoding="utf-8").write(t)

# decisions: D16 测试约束（CH343 不能复位 → 需要清零命令）
p="docs/30-decisions.md"
t=open(p,encoding="utf-8").read()
if "## D16" not in t:
    t += """
## D16 回归夹具必须自己清零设备状态

- **结论**：`verification/regress/conftest.py` 的 `device_ready` 先发一组 `lock_*(0)`、
  `buttons(0)`、`left(0)…ms2(0)`，再开始断言。
- **理由**：CH343 的 DTR/RTS 只接在 CH343 自己，没接 S3 的 EN/IO0 —— 既不能进下载模式
  （`esptool` 实测 `Failed to connect`），也不能靠脉冲复位应用，RAM 状态会跨轮次保留。
- **证据**：第四批第一次在 CH343 上跑时，`.km.lock_mx()` 返回 `1`（上一轮 `lock_mx(1)`
  的残留），两条断言失败；加清零后同一轮全绿。
- **推翻条件**：换一块 EN/IO0 有接线的底板，或改用原生 USB 复位（那条能复位）。
"""
open(p,"w",encoding="utf-8").write(t)
print("docs updated")
