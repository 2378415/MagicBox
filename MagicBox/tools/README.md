# tools/ 速查

> 38 个脚本 + `boxbench/` 子包。日常只需要「构建 / 刷写」两组；其余是台架与分析工具。
> 所有脚本都从仓库根跑：`powershell -File tools\<脚本>` 或 `python tools\<脚本>`。

## 1. 构建

| 脚本 | 用途 |
|---|---|
| `build_app.ps1` | **唯一构建入口**。`-App app_left\|app_right`、`-Clean`、`-Define "-DMB_DEBUG_OPCODE=ON,..."`。内部设好 `IDF_PATH` / `IDF_TOOLS_PATH` / xtensa PATH |
| `setup_idf.ps1` / `setup_idf_local.ps1` | 新机器装 IDF v5.4.1 与 xtensa 工具链（一次性） |
| `fetch_idf_submodules.py` | 用 codeload 补 IDF 子模块（GitHub 被墙时） |
| `fix_idf_gitmodules.py` | 修 IDF 的 `.gitmodules`（配合 `IDF_SKIP_CHECK_SUBMODULES=1`） |

## 2. 刷写与回滚

| 脚本 | 用途 |
|---|---|
| `flash_capture.ps1` | 左片：走 `mx.dl` 进下载模式，顺便抓串口日志；默认 6 s |
| `flash_left_auto.ps1` | **左片全自动**（2026-11-12 新增）：构建 → `mx.dl` → 等 `VID_303A&PID_0009` → 写 `0x10000` → 整段回读比对；`-NoBuild` 只刷现有产物。**不需要人工拔线** |
| `flash_left.ps1` | 左片：`-Action build\|flash\|backup\|verify\|restore` |
| `flash_right.ps1` | 右片：默认刷**出厂整片**（`官方固件/V3.7_RIGHT.bin` @0x0）；app 镜像用 `-Offset 0x10000` |
| `reflash.ps1` | 左片回滚 + 回读 + `work/cmp_restore.py` 逐字节比对 |
| `finish_cycle.ps1` | 一轮收尾：构建 → 刷写 → 回读 → 比对 → 日志 |
| `rd_right.ps1` | 右片内存读（不刷写） |
| `flash_verify.py` | 读回校验（`flash_left.ps1 -Action verify` 调用） |
| `recover_download.py` | 卡在 ROM 下载模式时的恢复 |

## 3. 台架 / 光标

| 脚本 | 用途 |
|---|---|
| `boxbench_gui.py` | Windows 桌面台架 GUI（Tkinter）；`--selftest` 无界面自检、`--suite smoke` 冒烟 |
| `boxbench.cmd` / `boxbench.ico` / `boxbench/` | GUI 启动器 / 图标 / `link.py`+`plots.py` 支撑包 |
| `link_probe.py` | 控制口 921600 二进制通道：`--ping`、`--plan`、`--sumv`、`--evt`、`--all` |
| `aim_move.py` | 防撞边闭环到位：读光标 → `counts = px / 1.25` → 发 `sumv` → 再读修正（`--to x,y` / `--by dx,dy`） |
| `aim_stress.py` | 瞄准压力测试：并发/队列 `sumv` 夹按键，判「按键一条不丢 + 无卡键 + 不越界」 |
| `px_cal.py` | 光标增益标定（只测量，不改系统设置） |
| `dt_hist.py` | 读 `mx.lh` 转发间隔直方图 + `mx.hz` 速率（ASCII，`--cn` 中文） |
| `cursor_test.ps1` / `clone_check.ps1` / `hid_isolation.ps1` / `read_hid_descriptors.ps1` | 光标位移测试 / 克隆状态检查 / HID 隔离 / 描述符导出 |
| `watch_link.ps1` / `watch_session.ps1` / `btn_monitor.ps1` | 串口长跑观察（链路帧 / 会话号 / 按键事件） |
| `trace_motion.py` | `mx.mt` 轨迹 → 人工符合性分析（生成 `verification/motion_analysis.md`） |
| `trace_opcodes.py` | 42 步协议行为基线采集 + `--compare` 差分（`verification/opcode_trace.json`） |
| `verify_buttons_usb.py` | **PC 侧按键真值校验**：USBPcap 抓 HID 输入（ep 0x81）→ 注入 N 次点击 → 与固件 `0x3E wire_chg` 对账；`--inject bin` 用二进制 `0x32 BUTTON`（App 真实路径，高倍率必用），`--sumv/--binary-sumv` 叠加 AIM 负载 |
| `probe_control.py` / `trace_probe.py` / `tusb_debug.py` / `btn_monitor.ps1` | 控制口连通性、探针开关、TinyUSB 调试级别 |
| `make_shortcut.ps1` | 重建桌面快捷方式（重装系统/换机器后） |

## 4. 分析 / 文档

| 脚本 | 用途 |
|---|---|
| `status.py` | **重写 `docs/40-status.md`**：尺寸取 build、报告清单取 `verification/report`，末尾附 `docs/40-status-appendix.md` |
| `diff_insn.py` | 指令级相似度（自比应为 1.000），只读官方镜像 |
| `p0_baseline.py` | P0 基线：27 handler 与原厂逐函数相似度（`verification/p0_baseline.md`） |
| `extract_tables.py` | 从官方镜像导出命令表 / opcode 表；语义名现在来自 `components/makcu_proto/handlers.def` |

## 5. 约定

- 台架脚本都用 `D:\JinPeng\MagicBox\work\` 作运行目录（出厂备份、回读、日志）；
- 串口默认 `COM3`（左片 CH343）/ `COM10`（右片 USB-Serial-JTAG），可用 `-Port` 或 `MAKCU_PORT` 覆盖；
- 只有 `MB_DEBUG_OPCODE=ON` 的构建才有 `mx.*` 台架命令，出货构建必须关；
- 新增脚本请归入上面四类之一，并在本文件登记一行。
