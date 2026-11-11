import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/40-status.md"
t=open(p,encoding="utf-8").read()
t=t.replace("| 烧录 | **未完成**：烧录过程中台架设备从 USB 消失（COM9 与 VID_303A 同时消失），需重新接入后重跑 |",
"| 烧录 | **完成**：`idf.py -p COM9 flash` 成功，设备重枚举为 `COM11`（记录见 `verification/report/2026-11-09-flash-run.md`） |")
t=t.replace("| 回归 | 无硬件时 16 skipped；接入后执行见下 |",
"| 回归（T2） | **16 例：7 通过 / 8 失败（全部是未移植 handler，属预期）/ 1 xpass** |")
t=t.replace("""设备回来后的一条命令链：""","""回滚核对：`esptool read_flash` 回读整片与烧录前备份 **4,194,304/4,194,304 字节完全一致**，app 版本串回到 `1`。
设备已复原为原厂固件（详见 `verification/report/2026-11-09-flash-run.md`）。

烧录/验证/回滚命令链（下次照抄）：""")
open(p,"w",encoding="utf-8").write(t)
print("status updated")
