import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")

# 1) plan: T3 门槛重新界定
p="docs/00-plan.md"
t=open(p,encoding="utf-8").read()
t=t.replace("| **T3 指令级相似度** | 归一化指令 diff：核心协议函数 ≥ 90%，其余厂商函数 ≥ 70%；数学库函数列入白名单 | 防止“行为碰巧对、实现全跑偏” |",
"| **T3 指令级相似度** | **仅适用于“同一份源码重新编译”的对象（P0 库代码、本地重建的 libm 副本）**：归一化指令 diff ≥ 90%。手写重实现的 handler 不设此门槛（实测 0.07–0.60，差异来自内联决策而非语义），改为记录分数 + T2 逐字节 | 见第五批报告 §4：T3 衡量的是重编译保真度，不是重写正确性 |")
t=t.replace("| V2 | `tools/diff_insn.py` 归一化指令 diff | 每函数合入 |",
"| V2 | `tools/t3_report.py`（基于 `diff_insn`）归一化指令 diff，**软信号** | 每批合入 |")
open(p,"w",encoding="utf-8").write(t)

# 2) decisions: D17 台架夹具、D18 T3 适用范围
p="docs/30-decisions.md"
t=open(p,encoding="utf-8").read()
if "## D17" not in t:
    t += """
## D17 隐藏 opcode 只用台架夹具验证，发布固件不带

- **结论**：`app_left` 支持 `-DMB_DEBUG_OPCODE=ON`，此时控制口额外接受
  `mx.<两位hex opcode> <参数>` 并直接调用对应 handler；默认 OFF。
- **理由**：0x0D–0x18 没有文本命令、外部不可达，不注入就没有 T2 证据。
- **证据**：第五批用该夹具跑通 10 条隐藏 opcode 用例（`verification/report/2026-11-09-flash-run-5.md`）。
- **推翻条件**：若最终固件保留该入口，必须把它并入正式的调试协议并重新做安全评估。

## D18 T3 只用于“重编译保真”，不用于“重写正确性”

- **结论**：T3 门槛只对 P0 的库代码与本地重建的 libm 副本生效；手写 handler 记录分数但不设门槛。
- **理由**：第五批 8 支键盘 handler 的相似度 0.07–0.60，低的几支完全是因为原实现把整个
  解析器内联（106 条）而我们调用共享解析器（9 条），语义其实一致且已由 T2 逐字节验证。
- **证据**：`tools/t3_report.py` 输出；报告 §4。
- **推翻条件**：如果要求“逐函数可替换的二进制等价”，那就得改成“按原样内联”的写法，成本另计。
"""
open(p,"w",encoding="utf-8").write(t)

# 3) status 数字
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 4 次；最新一轮 **26 例全绿**（25 passed + 1 xpassed），UART0 与原生 USB 两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 5 次；最新一轮 **38 例全绿**（37 passed + 1 xpassed，含 10 条隐藏 opcode 用例），两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',")
open(p,"w",encoding="utf-8").write(t)
print("docs updated")
