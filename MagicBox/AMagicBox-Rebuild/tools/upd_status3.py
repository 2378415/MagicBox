import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/40-status.md"
t=open(p,encoding="utf-8").read()
t=t.replace("| 厂商函数重写（P2–P5） | **已起步**：`cmd_version`(0x09)、`cmd_nop`(0x08)、`cmd_move`(0x06) 三支已实现并链入；其余 24 个仍在 `handlers.def` 标 todo | 见下节“本轮新增” |",
"| 厂商函数重写（P2–P5） | **已移植 6 支**：`cmd_version`(0x09)、`cmd_nop`(0x08)、`cmd_move`(0x06)、`cmd_button_click`(0x05)、`cmd_buttons`(0x0C)、`cmd_catch_set`(0x0A)；其余 21 个仍为 todo | 见下节“本轮新增” |")
t=t.replace("| 回归（T2） | **16 例：7 通过 / 8 失败（全部是未移植 handler，属预期）/ 1 xpass** |",
"| 回归（T2） | **19 例：16 通过 / 2 失败（`silent(0,0)`、`serial()` 未移植，属预期）/ 1 xpass** |")
t=t.replace("| 烧录 | **完成**：`idf.py -p COM9 flash` 成功，设备重枚举为 `COM11`（记录见 `verification/report/2026-11-09-flash-run.md`） |",
"| 烧录 | **完成 2 次**：第一批 3 支、第二批 3 支；记录见 `verification/report/2026-11-09-flash-run{,-2}.md` |")
open(p,"w",encoding="utf-8").write(t)
print("status updated")
