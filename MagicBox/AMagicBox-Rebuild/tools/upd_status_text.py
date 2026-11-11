import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/40-status.md"
t=open(p,encoding="utf-8").read()
t=t.replace("| 厂商函数重写（P2–P5） | 未开始 | 端口清单见各组件 `*_stub.c` 的 TODO 段；`handlers.def` 控制哪些 handler 已实现 |",
"""| 厂商函数重写（P2–P5） | **已起步**：`cmd_version`(0x09)、`cmd_nop`(0x08)、`cmd_move`(0x06) 三支已实现并链入；其余 24 个仍在 `handlers.def` 标 todo | 见下节“本轮新增” |""")
t=t.replace("""## 端口面统计""","""## 本轮新增（第 1 步：三个 handler + 烧录）

| 项 | 结果 |
|---|---|
| `cmd_version`（0x4200DC6C） | 回 `km.MAKCU\\r\\n>>> `；`version` 与 `version()` 都命中（前缀匹配） |
| `cmd_nop`（0x4200DBA0，跳表专用入口） | 回显整行；确认它不是空 stub |
| `cmd_move`（0x4200E024） | 解析 1–5 个 int16（`,`/`)` 分隔、空格/制表符、`+/-`、钳位），`n<2` 静默，`n==5` 走扩展提交，3/4 参按第 3 值当档位；运动经 `makcu_mouse_move_hook` 间接调用（尚未移植，故只验证协议面） |
| 链接验证 | `nm` 确认三支在 IROM：`cmd_move@0x4200cf2c`、`cmd_nop@0x4200cfa0`、`cmd_version@0x4200cfb0` |
| 台架控制台 | UART0 与芯片原生 USB-Serial-JTAG 双路收发（决策 D14） |
| 烧录 | **未完成**：烧录过程中台架设备从 USB 消失（COM9 与 VID_303A 同时消失），需重新接入后重跑 |
| 备份 | 已取整片 4 MB：`work/hw_left_before_rebuild.bin`，与官方 `V3.2_LEFT.bin` 前 403536 字节逐字节一致（app 版本 `1`），可直接用于回滚 |
| 回归 | 无硬件时 16 skipped；接入后执行见下 |

设备回来后的一条命令链：

```powershell
pwsh -File tools\\flash_left.ps1 -Action flash     # 烧重建固件
python tools\\flash_verify.py --port COM9          # 期望：version / version-prefix / move-echo 三条 PASS
pwsh -File tools\\flash_left.ps1 -Action restore   # 回写原厂 4 MB
```

预期（部分重建）：
- `.km.version()` → `km.MAKCU\\r\\n>>> ` ✅
- `.km.version` → 同上 ✅
- `.km.move(10,5)` → `km.move(10,5)\\r\\n>>> ` ✅（不会真的移动，运动层还没移植）
- `.km.silent()` → 无回包 ✅（槽位为 NULL）
- `.km.serial()` → 无回包 ⚠️（未移植，正式回归里会 FAIL，属预期）

## 端口面统计""")
open(p,"w",encoding="utf-8").write(t)
print("status updated")
