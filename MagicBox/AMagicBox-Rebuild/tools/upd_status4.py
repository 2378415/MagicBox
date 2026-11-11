import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 2 次：19 例里 16 通过、2 失败（未移植 handler）、1 xpass；回滚整片逐字节一致 | `verification/report/` |',",
            "'| 烧录 + 回归（T2） | 已上机 3 次；最新一轮 **19 例全绿**（18 passed + 1 xpassed），UART0 与原生 USB 两条通路各跑一遍；回滚整片逐字节一致 | `verification/report/` |',")
open(p,"w",encoding="utf-8").write(t)
print("ok" if "全绿" in t else "pattern not found")
