# 交接文档 — AMagicBox-Rebuild（MAKCU 鼠标盒子固件重建）

> 更新：2026-11-10 晚。旧版（2026-11-09）完整存档见 `docs/HANDOVER-2026-11-09-archive.md`。
> 本文只写**当前状态与怎么用**；每一轮的执行细节在 `verification/plan-*.md` 里。

## 1. 一句话现状

**盒子可用**：鼠标插右侧口 → PC 上出现与真鼠标**同构的复合设备**（`320F:706E`，5 个 HID 集合），
移动/按键/滚轮正常，**拔插自愈**，官方管理程序 **HECATE Connect 能识别并读写配置**（读数/改 DPI 均验证）。
两颗芯片**都是自编固件**，回归 **100 passed / 0 failed**。

| 验收项 | 数据 |
|---|---|
| 报告转发 | `mx.ds` 累计 3,885+，**队列丢弃 0** |
| 左片每条报告耗时 | p50 **10 µs** / p99 30 µs |
| 右片每条转发耗时 | p50 **60 µs** / p99 60 µs / max 67 µs |
| 厂商通道 | `mx.ox` out/ok/in82 全部相等，`ack=00` |
| 身份 | `mx.fv` force=0 ovr=0 dev=`320f:706e`（零人工固定，见 §14.11） |
| 回归 | 100 passed / 0 failed |

## 2. 系统架构与数据通路

```
物理鼠标 ──USB──▶ 右片 ESP32-S3（USB **host**）
                   ├─ makcu_hidhost：枚举 / IN 端点武装 / EP0 控制传输 / OUT 提交 / 描述符快照
                   └─ 上行：每条报告封成 0xA2 帧  ──UART1 5 Mbaud──▶ 左片
                     下行：0xA1 EP0 隧道(8B setup)、0xA5 OUT 提交、0x1B/0x1D 原始描述符
                           0x1C host 状态、0x1E 插拔通知、0x1F 日志、0x21 延迟查询
左片 ESP32-S3（USB **device**）
 ├─ makcu_link_bridge：解析 0xA2 → 报告 sink；会话号采纳/重置；0xA1 隧道请求
 ├─ makcu_clone：克隆描述符（设备/配置/报告/字符串 + 身份别名映射 + 唯一序列号）
 ├─ makcu_hiddev：TinyUSB HID（实例0=鼠标，实例1=键盘/厂商通道）+ **报告队列**
 └─ 上行：按 instance 发到 PC 的 EP0x81 / EP0x82
PC ⇄ HECATE Connect：厂商通道 EP 0x03(OUT) ↔ 0x82(IN)，原样 64 字节
```

链路帧格式：`5A <cmd> <len:u16 LE> <payload…>`。**0xA2 = 4 字节头 + 报告**：
`[0]=ep [1]=session [2]=report_len [3]=flag [4..]=报告`。

## 3. 目录地图

| 路径 | 内容 |
|---|---|
| `app_left/main/app_main.c` | 左片主逻辑：台架命令 `mx.*`、自动克隆、报告转发、插拔处理、OUT 转发队列、自愈任务 |
| `app_right/main/app_main.c` | 右片主逻辑：链路帧分发、`0xA2` 转发、EP0 隧道、`0x1B/0x1D` 描述符、`0x1C` 状态、`0xA5` OUT、`0x1E` 通知、`0x1F` 日志回传 |
| `components/makcu_hidhost/` | **自编右片的核心**：USB host 栈 + IN 武装/逐槽自愈 + EP0 控制 + OUT transfer 池 + 延迟直方图 |
| `components/makcu_link/` | 双片链路：编解码、解析器、桥接（会话、报告 sink、自定义钩子） |
| `components/makcu_clone/` | 克隆结构：描述符存储、身份覆盖、**身份别名策略**、每台唯一序列号 |
| `components/makcu_hiddev/` | 左片 USB device：TinyUSB、报告/键盘发送、**报告队列**、OUT 钩子 |
| `components/makcu_proto/` | 27 个协议 handler + 43 条文本命令表 |
| `components/makcu_{mouse,keyboard,board,dev,right}/` | 运动/键盘/板级/设备上下文/右片共享状态 |
| `tools/` | 见 §7（大量历史一次性脚本可忽略，只保留脚本清单里那批） |
| `verification/regress/` | 7 个测试文件 / 54 个 test 函数 → 100 用例（靠台架 COM3） |
| `verification/plan-*.md` | 四份方案的**完整执行记录**（右片固件 / HECATE 代理 / 身份整改 / 性能优化） |
| `docs/30-decisions.md` | 决策 D1–D40 |
| `docs/40-status.md` | 状态与待办 |

## 4. 已完成模块（当前）

| 模块 | 状态 |
|---|---|
| 命令协议层（27 handler，含 0x08、0x0D–0x18 隐藏 opcode） | ✅ 全部 implemented |
| 运动 / 键盘 / 按键 | ✅ |
| 左片 HID（单/双接口，`MB_DUAL_IF`） | ✅ 复合拓扑与真设备同构 |
| 片间链路（5 Mbaud，块读） | ✅ |
| 克隆（自动 + 身份别名 + 唯一序列号） | ✅ 零人工固定 |
| **右片 USB host（自编固件）** | ✅ 枚举 / IN 转发 / EP0 隧道 / OUT 提交 |
| **厂商通道双向代理**（HECATE） | ✅ 读写配置验证通过 |
| **插拔自愈**（会话重置 + transfer 释放 + 逐槽自愈 + 自动重克隆） | ✅ |

## 5. 环境与构建

```powershell
# 左片（device 侧，日常台架构建）
powershell -File tools\build_app.ps1 -App app_left -Define `
  "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"

# 右片（host 侧，自编固件）
powershell -File tools\build_app.ps1 -App app_right
```

要点：
- `MB_DEBUG_OPCODE=ON` 才有 `mx.*` 台架命令（出货构建必须关）；
- `MB_CLONE_FIXTURE=99` = 开机自动克隆 + 失败保留上次克隆；
- `MB_DUAL_IF=ON` = 双 HID 接口（HECATE 需要）；
- **`MB_FORCE_VIDPID` 已废弃**（身份别名策略取代），不要再用；
- 工具链：`D:\esp-tools`（xtensa-esp-elf 14.2.0），首次用 `tools\setup_idf_local.ps1`。

## 6. 刷写与回滚

```powershell
# 左片（COM3，内部走 mx.dl 进下载模式，不需要换线）
powershell -File tools\flash_capture.ps1 -Port COM3 -Seconds 6

# 右片：右侧口换成数据线（VID_303A&PID_1001 / COM10），然后
powershell -File tools\flash_right.ps1 -Image app_right\build\makcu_right.bin -Offset 0x10000
#   ⚠ app 镜像写 0x10000；整片出厂镜像写 0x0（默认）
#   ⚠ 刷完芯片停在 ROM 下载模式：USB-Serial-JTAG 的 hard reset 在本板不生效
#     （实测 esptool 报 "Hard resetting via RTS pin" 后 `--before no_reset chip_id`
#      仍能同步，右片 UART1 一言不发）。必须**拔掉数据线、插回鼠标**给板子断电重启，
#      然后 `mx.ls` 的 rx_bytes 要开始增长、`mx.hi` 要能应答。

# 右片回滚出厂 V3.7
powershell -File tools\flash_right.ps1
```

**出厂备份（不要删）**：`work/hw_left_before_rebuild.bin`（4 MB 左片）、
`work/hw_right_full_before_patch.bin`（4 MB 右片）、`work/right_boot_head.bin`（右片 bootloader 区）。

## 7. 台架脚本（`tools/`）

**日常用**：`build_app.ps1`、`flash_capture.ps1`（左片）、`flash_right.ps1`（右片 app/整片）、
`reflash.ps1`（回滚）、`rd_right.ps1`（右片内存读）、`clone_check.ps1`、`cursor_test.ps1`、
`watch_link.ps1`、`watch_session.ps1`、`hid_isolation.ps1`、`read_hid_descriptors.ps1`。

**分析用**：`diff_insn.py`（指令级相似度）、**`p0_baseline.py`**（P0 基准报告）、
**`trace_opcodes.py`**（协议行为轨迹 + `--compare` 差分）、
**`trace_motion.py`**（`mx.mt` 运动追踪 → 人工轨迹符合性分析 + `verification/motion_analysis.md`）、
**`link_probe.py`**（控制口 921600 二进制通道：`--ping` 量 RTT、`--plan` 下运动计划、
`--sumv dx dy --speed N` 走拟人化移动、`--sumv-stop` 中止、`--evt MASK [--evt-selftest]` 订阅看事件、`--all` 全查）。

**`aim_move.py`**（防撞边闭环到位：读 `GetCursorPos` → `counts = px / 1.25` → 夹到剩余空间 →
发一段 `sumv` → 再读光标修正；`--to x,y` / `--by dx,dy`，典型 1–2 轮收敛到 ≤2 px）。

**`px_cal.py`**（光标增益标定：`mode.bit7` 让每报告正好带 `max_report` counts，扫出
`px/count` 曲线 + 撞边检测；只测量，不改固件也不改系统设置）。

**`aim_stress.py`**（**瞄准压力测试**：并发/队列 `sumv` + 夹杂鼠标按键，判定"按键一条都不能丢"。
`--mode both|queue|concurrent`，默认把光标钉在**屏幕右上角**；
判据 = PC 侧按下/松开沿**不少** + 释放后无卡键 + 光标不越界 + 固件零溢出；
队列模式每步按"光标像素 == counts × 1.25"校验守恒。详见 §14.25）。

**`dt_hist.py`**（**转发节奏直方图**：读 `mx.lh` 的 256 桶间隔直方图 + 打印 `mx.hz` 速率，
ASCII 输出（`--cn` 转中文），用于判断"报告到达是否均匀"。固件 1/4 采样 → 1 kHz 名义 4 ms。
配套探针 `mx.hz`（左片速率）/`mx.hi`（右片 u32 精确计数）/`mx.lh`。详见 §14.26）。

**桌面快捷方式**：桌面上已有 `MagicBox 台架工具.lnk`，指向 `pythonw.exe tools\boxbench_gui.py`
（无黑框）+ 自定义图标 `tools/boxbench.ico`。重装系统/换机器时用 `tools\make_shortcut.ps1`
一键重建；GUI 闪退看不到原因时用 `tools\boxbench.cmd`（带控制台）启动。

**`boxbench_gui.py`**（**Windows 桌面台架 GUI**，Tkinter + Pillow，无其它第三方依赖）：
`python tools\boxbench_gui.py` 开界面；`--selftest` 无界面自检（链路 + 轨迹 + 指标 + 导图）；
`--suite smoke` 无头冒烟（连通 / 克隆 / 守恒 / 手感 / 事件）。配套 `tools/boxbench/{link,plots}.py`。

其余大量 `fix_*.py / upd_*.py / wire_*.py` 是历史一次性改动脚本，不必再跑。

## 8. 测试体系

```powershell
$env:MAKCU_PORT='COM3'
python -m pytest verification\regress -q      # 109 passed（需要盒子在线）
```

| 模块 | 覆盖 |
|---|---|
| `test_protocol.py` / `test_hidden_opcodes.py` | 文本协议 + 隐藏 opcode |
| `test_mouse_reports.py` | 真实报告解析、位移守恒、曲线 |
| `test_clone_descriptors.py` | 描述符克隆与出厂夹具 |
| `test_link_bridge.py` | UART1 桥 / 0xA2 注入（**计数断言要先 `mx.hk 0` 隔离**真实鼠标流） |
| `test_keyboard_reports.py` / `test_right_frames.py` | 键盘报告 / 右片帧 |
| **`test_sumv_opcode.py`** | **`0x36 SUMV` / `0x37 STOP` / `0x38 STATE`（9 条）**：位移守恒、`active` 可观测、stop 计 aborted、REPLACE 截断旧轨迹、D=0 被拒绝、斜向两轴、speed→时长、恒速档。断言口径用 `mx.rt` 累计 counts，不受光标位置与系统加速影响 |

- 全部是**硬件在环**测试：通过 `mx.*` 台架命令驱动真实固件；
- 出货构建（无 `MB_DEBUG_OPCODE`）下，测试会自动 skip；
- 新增的两个**离线**工具不依赖硬件：`tools/p0_baseline.py`、`tools/trace_opcodes.py --compare`。

**克隆状态的三个护栏（2026-11-11，缺一个就会出现"随机 2 个用例失败"）**

| 位置 | 做什么 |
|---|---|
| `conftest.py` 的 `ensure_real_clone_at_start`（session 级） | 开跑前确认 `mx.if` 是 `2 …`；不是就 `mx.rs` 重启，仍不行再 `mx.ac`（立即重克隆，不重启），最多 3 轮 |
| `conftest.py` 的 `restore_real_clone`（模块级） | 每个模块结束检查一次，同上 |
| `test_clone_descriptors.py` 的模块收尾 fixture | 本模块故意装出厂夹具，结束时**自己** `mx.ac` 换回真实克隆 |
| `test_link_bridge.py` 的 `ensure_real_clone()` | 每个 0xA2 注入用例**自带前置**：健康时一次 `mx.if` 就返回，不健康时才 `mx.ac` |

**0xA2 注入类用例的计数断言必须做台架隔离**：真实鼠标每秒几百帧 0xA2 会同时抬高
`injected/dropped` 计数，严格等式会随机失败。做法：`mx.hk 0`（隔离，0xA2 不进 HID 路径）
→ 读计数 → `mx.lf a2 …` → 再读 → `finally: mx.hk 1`（**恢复**，后续用例要用）。
注意方向：`mx.hk 1` = 启用 sink（正常转发），`mx.hk 0` = 隔离。

> 连跑 3 次单模块 13 passed、连跑 2 次全量 100 passed；从"故意装夹具"的坏状态起跑也能
> 自动恢复到 100 passed。

## 9. 关键决策

完整见 `docs/30-decisions.md`（D1–D40）。与当前状态最相关的：

- **D30** 链路引脚/波特率（左 TX=GPIO2/RX=GPIO1，右 TX=GPIO1/RX=GPIO2，5 Mbaud 交叉）；
- **D37/D38** 双 HID 接口克隆（厂商通道必须存在，且**厂商 OUT 端点必须用 0x03**，S3 没有 OUT EP5）；
- **D40** 优先"把想要的键映射成鼠标键"，而不是做多接口宏；
- 2026-11-10 新增：身份别名策略、唯一序列号、插拔自愈、报告队列（详见 §14/§15）。

## 10. 已知问题与剩余工作

### 10.1 无阻塞项
以前的两个阻塞（右片可烧性、右片 host 栈未移植）**都已解决**。

### 10.2 剩余（都不影响使用）
| 项 | 说明 |
|---|---|
| 手感曲线（`0x4200EFEC` 浮点） | 我们目前是**直通**，原厂有曲线/加速处理。要一致需 USB 分析仪抓出厂轨迹（用户已决定不做） |
| 右片转发 60 µs/条的优化（方案 P0-3） | 去掉 1 KB 栈数组 + 两把锁 + 一次拷贝可降到 10–15 µs；对 1 kHz 鼠标无实际意义 |
| P2-12 发送路径单点化 | 纯重构，会动已验证正常的热路径，等真有第二个发送者再做 |
| 权限/清理 | 台架反复刷写会积累 Windows phantom 设备，收尾时按 §14.15 清一次 |

### 10.3 容易踩的坑（都踩过）
见 §14.7「关键设计约束」——**改代码前必读**。

## 11. 交接检查清单

- [ ] 能按 §5 构建出左片（台架）、右片两个固件
- [ ] 能按 §6 刷左片（不换线）和右片（换数据线），并能回滚出厂
- [ ] 能按 §14.4 四条命令自检（`mx.fv/mx.vs/mx.if/mx.dv`）
- [ ] 能跑通回归（`MAKCU_PORT=COM3`，100 passed）
- [ ] 知道 `mx.*` 只存在于台架构建，出货必须关 `MB_DEBUG_OPCODE`
- [ ] 知道右片没有独立控制台，日志经 `0x1F` 回传到 COM3 的 `[R]` 前缀
- [ ] 知道 1 kHz 下**绝不能合并报告**（会毁掉时间精度）
- [ ] 知道遇"鼠标偏慢"先看 `mx.ds` 的第二个字段（队列丢弃），再看 `mx.lat`

## 12. 想改什么 → 改哪里（速查）

| 想做的事 | 改这里 |
|---|---|
| 加/改协议命令（文本命令） | `components/makcu_proto/src/cmd_*.c` + `makcu_cmd_table.c` |
| 改鼠标报告转发逻辑 | `app_left/main/app_main.c` 的 `link_report_to_mouse()` |
| 改"端点忙怎么办"（丢/排队） | `components/makcu_hiddev/src/makcu_hiddev.c` 的 `rep_push/rep_drain_one` |
| 改右片 USB host 行为（枚举/IN/OUT/EP0） | `components/makcu_hidhost/src/makcu_hidhost.c` |
| 改链路帧处理 / 会话号 / 报告 sink | `components/makcu_link/src/makcu_link_bridge.c` |
| 改克隆身份策略（别名表）/ 序列号 | `components/makcu_clone/src/makcu_clone.c` |
| 改右片帧应答 / 新 opcode | `app_right/main/app_main.c` 的 `forward()` |
| 改拟人化移动（sumv：速度/曲线/抖动/屏蔽） | `components/makcu_sumv/src/makcu_sumv.c` + `app_main.c` 的 `link_report_to_mouse()` |
| 改台架命令 `mx.*` | `app_left/main/app_main.c` 的命令解析链 |
| 新增一个探针 | 同上，并在 `docs/HANDOVER.md §14.6` 登记 |

## 13. 参考索引

| 文档 | 内容 |
|---|---|
| `verification/plan-right-firmware.md` | 自编右片固件方案 + M1–M5 |
| `verification/plan-hecate-connect-proxy.md` | HECATE 双向代理（9 轮执行记录，含全部根因） |
| `verification/plan-identity-autoclone.md` | 身份自动克隆整改 + dongle 双身份真相 |
| `verification/plan-perf-optimization.md` | 性能评审 + 执行记录 + `mx.lat` 实测 |
| **`docs/API-control-port.md`** | **控制口接口文档**：文本协议 47 条命令 + 二进制通道（CRC8/seq/8 条命令）+ sumv + `mx.*` 探针 + 故障对照，写给写上位机的人 |
| `docs/30-decisions.md` | 决策 D1–D40 |
| `docs/40-status.md` | 状态、待办、收官记录 |
| `docs/00-facts.md` / `10-abi.md` / `20-types.md` | 逆向得到的事实、ABI、类型布局 |
| `verification/p0_baseline.md` | 27 个 handler 与原厂的逐函数相似度 |
| `verification/opcode_trace.json` | 42 步协议行为基线（可 `--compare` 回归） |

## 14. 开机流程：双接口克隆 + HECATE Connect（2026-11-10 定稿）

> 目标状态：鼠标插在盒子右侧 host 口，PC 上出现与真鼠标**同构的复合设备**
> （`VID_320F&PID_706E`，MI_00 鼠标 + MI_01 键盘/厂商 5 个集合），
> 管理程序 HECATE Connect 能识别、读电量、改 DPI/按键并生效。
> 实测写入确认率 **100%**（`mx.ox` 的 `ok/out`）。

### 14.1 接线

| 线 | 作用 | 常驻？ |
|---|---|---|
| 左线（左片原生 USB） | PC 看到的"克隆鼠标" | ✅ 常驻 |
| 中线（CH343 → COM3） | 台架控制台 `mx.*` | ✅ 常驻 |
| 右侧口 | **平时插鼠标**；刷右片时临时换成数据线（`VID_303A&PID_1001`） | 二选一 |

### 14.2 固件

```powershell
# 左片（device 侧）：autoclone + 双接口（身份由别名策略自动收敛，不要加 MB_FORCE_VIDPID）
powershell -File tools\build_app.ps1 -App app_left -Define `
  "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"

# 右片（host 侧）：自编固件（枚举 + IN 转发 + EP0 隧道 + OUT 提交）
powershell -File tools\build_app.ps1 -App app_right
```

> 2026-11-10 更正：`-DMB_FORCE_VIDPID` 已废弃（CMake 会告警），身份靠
> `makcu_clone_apply_id_policy()` 自动收敛；加上它只会让 `mx.fv` 的 `force` 变成
> `320f:706e`，与 §14.9「零人工固定」的验收口径冲突。

### 14.3 刷写

```powershell
# 左片（COM3，内部走 mx.dl 进下载模式，不用换线）
powershell -File tools\flash_capture.ps1 -Port COM3 -Seconds 6

# 右片：右侧口换数据线，然后
powershell -File tools\flash_right.ps1 -Image app_right\build\makcu_right.bin -Offset 0x10000
#   - app 镜像写 0x10000；整片出厂镜像写 0x0（默认）
#   - 加 -Backup 会先做 4 MB 全片回读

# 右片回滚出厂
powershell -File tools\flash_right.ps1            # 默认就是 原厂 V3.7 → 0x0
```

### 14.4 开机自检（30 秒）

```
mx.fv     -> force=0000:0000 ovr=0000:0000 dev=0f326e70     # 别名策略生效（未固定任何身份）
mx.if     -> 2 93:81:0 158:82:1                              # 两个接口描述符
mx.dv     -> mnt=1 + 配置 0x42=66B（2 接口、MI_01 的 OUT 已改为 0x03）
mx.hi     -> att=1 addr=2 id=320f:706e itf=2 ep=81:00,82:05 gate=1 ok/fail/done/fwd=…
```

> `mx.ln 1c` 只会回“写出 4 字节”，**不打印右片的回答**（1 kHz 的 `0xA2` 立刻把 `mx.lr`
> 覆盖掉）。要看右片 host 状态用 `mx.hi`（它走 `makcu_link_request` 按命令号取回包）。
> `ep=81:00,82:05` 里的 `05` 是**鼠标真实的厂商 OUT**，PC 侧我们看到的是被改成 `0x03` 的那个。

PC 侧应看到 `USB\VID_320F&PID_706E` 复合设备 + MI_00/MI_01 + 5 个集合，全部 OK。
**四项都对了再打开 HECATE Connect**（它只在启动/设备到达时探测）。

### 14.5 常见故障对照

| 现象 | 原因 | 处理 |
|---|---|---|
| `mx.fv` 的 `dev` 不是 `0f326e70` | ① 设备上报的 id 不在别名表里；② autoclone 没拿到描述符 | ① 看 `mx.fv` 的 `ovr/force` 是否为空（应全 0）；② `mx.ac` 后重查，仍不对就把该 id 加进 `k_id_alias[]`（`makcu_clone.c`）；不要再用 `MB_FORCE_VIDPID` |
| `mx.if` = `1 …` 或 `0 …` | autoclone 失败 | `mx.ac` → `mx.rs`（`mx.as` 应为 1） |
| PC 上没有 320F 节点 | 身份不对 / 枚举失败 | `mx.vp 320f706e` + `mx.rs`；必要时清掉失败节点 |
| app 显示"未侦测到设备" | ① 身份不符；② MI_01 OUT 没接住（曾因 EP0x05 在 S3 上不存在→改 0x03）；③ 回执竞态 | 依次查 `mx.fv` / `mx.ox` 的 `out`（应 >0）/ `ok`（应 == `out`） |
| `mx.ox` 里 `out>0` 但 `ok=0` | 右片未回执 | 查 `mx.ln a5 050200aabb` 是否回 `000502`；右片固件是否自编版 |
| 鼠标完全不动 | 克隆/枚举问题 | 注入自检 `mx.lf a2 02330700 00640000000000`（会话需 `mx.ss 33`） |

### 14.6 探针速查（都只在 `MB_DEBUG_OPCODE` 构建里）

| 探针 | 输出 |
|---|---|
| `mx.fv` | 编译期强制身份 / 运行时覆盖 / 当前服务出去的四个字节 |
| `mx.ox` | `out,ok,in82,ack,<dropped>,<last OUT 8B>,in82=<last IN 8B>` |
| `mx.xt` | 手动触发 HID OUT 回调自检（`out/ok/tdr`） |
| `mx.if` | 克隆捕获的接口（`2 93:81:0 158:82:1` = 复合） |
| `mx.hi` | **读回右片 `0x1C` host 状态**（`att/addr/id/itf/ep/gate/ok/fail/done/fwd`；`ep` 里 `82:05` 的 05 是鼠标真实厂商 OUT） |
| `mx.mt` | 运动追踪环：`mx.mt on/off/clr` 开关与清零，`mx.mt d` 冻结并 dump 3072 条 `(t_us,ep,len,报告hex)`；配合 `tools/trace_motion.py` 做人工轨迹分析 |
| `mx.rb` | 从**当前服务的描述符**推出的输入报告字节数（`bytes=7 desc=93 rid=0`）；`hs` 涨了但光标不动时先看它 —— 报告比描述符短会被主机静默丢弃 |
| `mx.ln 1c` | 只回“写出几字节”，回答本身不打印（用 `mx.hi`） |
| `mx.bo` | 见过的按键位 OR（侧键位 0x08 / 0x10） |
| `mx.ei` | 最后一条直送的报告字节 |
| `mx.hs` / `mx.hq` | 发送被接受 / 传输完成次数 |

### 14.7 关键设计约束（改代码前必读）

1. **ESP32-S3 没有 OUT 端点 5**：克隆配置里厂商 OUT 必须用低号（现为 `0x03`），
   否则 TinyUSB 的 `hidd_init` 会在 open 时中止（症状：IN 正常、OUT 永不完成）。
2. **0xA2 帧是 4 字节头 + 报告**：`[ep][session][report_len][flag][report…]`。
3. **厂商实例转发不带 Report ID**（64B 报告 + ID 会变 65B 撞 64B MPS）。
4. **`makcu_link_request` 用专用待收缓冲**（不能依赖"最后一帧"，1 kHz 报告会覆盖它）。
5. **右片异步 OUT 用 transfer 池**，禁止在完成回调里 `usb_host_transfer_free()` 自身。
6. **app 镜像写 `0x10000`**，整片镜像写 `0x0`。
7. **控制口是 921600**（2026-11-10 起，见 §14.20）；刷完左片后所有工具默认值都已跟上，
   只有 ROM 下载器的开机横幅仍是 115200（用 921600 读它是乱码，属正常）。
8. **`CONFIG_FREERTOS_HZ=100`**，所以 `pdMS_TO_TICKS(5) == 0`：
   任何"等 5 ms"的写法都会变成**忙等**（实测把 `km_uart0` 变成自旋任务、IDLE0 饿死、任务看门狗每 5 s 报一次）。
   要用事件队列 + `portMAX_DELAY`，或至少 `pdMS_TO_TICKS(20)`（=2 tick）。

### 14.8 M5 健壮性实测（2026-11-10）

| 项 | 方法 | 结果 |
|---|---|---|
| **热插拔** | 鼠标从右侧口拔下 → 3 s → 插回 → 移动 | ✅ 右片自动重枚举：`ls` 的 `rx` 从 2 恢复到 106 并持续增长 |
| **1 kHz 压测** | 持续快速移动 35 s | ✅ `mx.ds` = **31,555 发送 / 0 失败**（≈900 帧/秒） |
| **64 字节厂商帧** | 台架 `mx.ln a5 054000 04aa00aa…` | ✅ 鼠标回 `0xA2 ep=0x82`、64 字节 `04 aa 00 aa … ff`，与真设备一致 |
| **台架能力** | `mx.ln`/`mx.lf` payload 上限 | 32 → **96 字节**（hexbuf 224），可测单条 64 字节厂商帧 |

> 对比历史最差记录：同款 1 kHz 场景曾出现 11,837 次注入只有 58 次真正发出（EP claim 泄漏）。
> 现在双接口路径 `verbatim_ep` 计数 0 失败。

### 14.9 身份策略（2026-11-10 定稿）

**默认不钉任何身份**——克隆完全跟随设备（`mx.fv` 显示 `force=0000 ovr=0000`），
描述符由右片本地 host 栈提供（`mx.vs = 1,1`），不受 1 kHz 报告流干扰。

只有在"设备的物理身份没有匹配 INF"时才需要临时钉住（**仅当次运行有效**）：

```
mx.vp 320f706e     # 钉成 G3M 身份；RAM-only，重启/重新刷写后失效
mx.vp clear        # 恢复忠实克隆
mx.fv              # force=<编译期> ovr=<运行时> dev=<当前服务出去的字节>
```

> 2026-11-10 更正：`makcu_clone_identity_override_load()` 每次开机把 `vid_ovr/pid_ovr`
> 清零（`makcu_clone.c`），所以 `mx.vp` **不写 NVS、也不跨断电保留**，它只是排障时的一次性开关。
> 要长期改变身份，应该改 `k_id_alias[]`，不是靠 `mx.vp`。

**注意（2026-11-10 更正）**：早前"dongle 上报 `0E8C:F0DA`、PID 会漂"的判断是错的。
抓包与 `mx.ln 1b` 双向验证表明设备始终是 `320F:706E`；那次 `0E8C` 是
刚刷完右片、dongle 尚在重新枚举时的瞬时读数。现在设备描述符**整份 18 字节照抄**
（仅 `bMaxPacketSize0` 跟随我们的 EP0=64），因此**正常使用不需要钉任何身份**。

### 14.10 插拔失效的根因与修复（2026-11-10 定稿）

**症状**：盒子通电后鼠标正常，但只要拔插一次右侧鼠标就不再响应，HECATE Connect 也不再显示电量；
手动拔插一次左侧数据线（或 `mx.rs`）才恢复。原厂固件也有同样毛病。

**根因（三层，按重要性）**

| # | 问题 | 说明 |
|---|---|---|
| 1 | **报告会话号只采纳一次** | `0xA2` 报告里的 session = 右片的 USB 设备地址。桥接层启动时采纳一次，右侧插拔后地址变了（如 3 → 5），之后**每一条报告都被判会话不匹配而丢弃**。这就是"必须重启左片才恢复"的真正原因 |
| 2 | **IN 端点武装泄漏** | `arm_in_endpoints()` 每次 attach 新分配 6 个 transfer 却从不释放，反复插拔后 DMA 池耗尽 → 静默不武装 |
| 3 | **失败后永久解除武装** | 提交失败把槽置 `armed=false` 后没人再管它（只在"全部未武装"时才自愈） |

**修复**

1. `makcu_link_reset_session()`：收到"设备回来"通知时清掉采纳的 session，让下一条报告重新采纳；
2. `disarm_in_endpoints()` 真正 `usb_host_transfer_free()` 释放 transfer；
3. `ensure_armed()`：每 300 ms 逐槽检查，任何未武装的槽重新提交（部分失败也能自愈）；
4. 右片状态变化经 `0x1E` 通知左片，左片据此 `tud_disconnect()/tud_connect()` 重新枚举，
   让主机侧 HID 状态跟着设备走（等价于手动拔插左线）。

**实测（30 秒采样，全程不碰左片）**

```
[6s]  device gone: disconnected from the host     ds 冻结 4724
[12s] device back: re-enumerating on the host
[15s] ds=7981   [18s] ds=11833   [21s] ds=15895   [24s] ds=17905   ← 自动恢复
```

之后用户确认：**移动手机光标跟手、HECATE Connect 显示电量**。

### 14.11 身份：零人工固定（别名映射）

设备（G3M PRO 的 2.4G 接收器）在不同状态会报出多个 id：`0E8C:F0Dx / 0ECC:F0Dx / 06CC:F0Dx / 068C:F0Dx`
（互为单比特翻转，PC 上没有对应 INF）。`makcu_clone_apply_id_policy()` 用别名表把这一族
统一映射到 `320F:706E`（厂商 ID，PC 有 INF），**不需要任何人工固定**：

```
mx.fv -> force=0000:0000 ovr=0000:0000 dev=0f326e70    ← 无强制、无覆盖
mx.vs -> 2,2                                           ← 设备/配置描述符都走 EP0 隧道
连续 3 次冷启动：身份完全一致
```

> 补充：`0x1B/0x1D`（右片本地读描述符）曾出现缓存/DMA 一致性导致的单比特污染，
> 因此设备与配置描述符改为**隧道优先**，本地读仅作回退。

### 14.12 台架注入的坑

`mx.lf a2 <session> 0700 <7字节>` 的 `session` **必须等于右片当前设备地址**
（`mx.ln 1c` 的第 2 个字节）。地址会随插拔变化，填固定值会被桥接层当会话不匹配丢弃——
排查时容易被误判成"报告通路坏了"。

### 14.13 验收结论（2026-11-10 收尾）

用户实测确认，以下三项**全部通过**：

| 项目 | 结果 | 关键实现 |
|---|---|---|
| 鼠标跟手（含插拔后） | ✅ | 会话号重置 + transfer 释放 + 逐槽自愈 + 自动重枚举 |
| 拔插右侧鼠标后自动恢复 | ✅ | 30 秒采样：`device gone` → `device back` → `ds` 从 4724 自动涨到 17905 |
| **HECATE Connect 显示电量** | ✅ | `ox = out=99, ok=99, in82=99, ack=00`（厂商通道 100% 成功） |
| 身份零人工固定 | ✅ | `fv = force=0000:0000 ovr=0000:0000 dev=0f326e70` |
| 回归 | ✅ | 100 passed / 0 failed |

**注**：设备在不同状态下会上报 `0E8C / 0ECC / 06CC / 068C : F0Dx` 等一组 id（互为单比特翻转，
PC 无对应 INF）。`makcu_clone_apply_id_policy()` 会把这些**连同残留的覆盖值**一起收敛到
`320F:706E`，所以即使 NVS 里留有旧覆盖也不影响（实测 `ovr=0e8c:f0de` 时 `dev` 仍是 `0f326e70`）。

**开机自检（照 14.4）四条命令应看到**：

```
mx.fv  -> force=0000:0000 ovr=0000:0000 dev=0f326e70
mx.vs  -> 2,2
mx.if  -> 2 93:81:0 158:82:1
mx.dv  -> mnt=1 + 配置 66 字节（2 接口，MI_01 OUT = 0x03）
```

### 14.14 序列号策略（每台唯一，2026-11-10）

真鼠标**没有**序列号（`iSerialNumber = 0`），所以序列号是我们自己的。原先写死
`0000000000B1`，问题是：**所有盒子在主机眼里是同一个设备** —— 两台机器插同一台电脑会互相顶掉，
而且会复用调试时留下的旧设备实例（今天的"电量不显示"就吃过这个亏）。

现在改为**每台唯一、持久不变**：

```
首次上电: 序列号 = "MB" + MAC[4..5] 两位hex + esp_random() 8位hex   → 12 字符
          写入 NVS（命名空间 makcu_clone，键 serial）
之后:     永远用这一个（跨重启、跨刷写都不变）
```

实测：

```
mx.sn   -> MBE87C6C6B372
重启后  -> MBE87C6C6B372                    （不变）
PC 实例 -> USB\VID_320F&PID_706E\MBE87C6C6B372
ox      -> out=33, ok=33, in82=33, ack=00   （管理程序照常工作）
回归    -> 100 passed
```

要点：

- 长度仍是 12 字符，与原来一致，不影响 INF/描述符预期；
- 为什么不用设备描述符里的 `iSerialNumber = 0`：照抄会造出全新主机实例、且实测输入路径失效，
  所以仍保留模板的 3 号串，但内容改为本机唯一随机串；
- 想换新身份（例如给 PC 一个全新实例）：`mx.vp clear` 不会动它，需要清 NVS 的 `serial` 键
  （或用台架命令扩展）。

### 14.15 清理测试残留的设备实例

台架反复刷写/换序列号会在 Windows 里积累大量 phantom 设备节点（实测一次测试留下 153 个）。
它们通常无害，但会让"管理程序认不到设备"这类排查变脏，收尾时清一次：

```powershell
$ids = 'VID_320F&PID_706E|VID_0E8C|VID_0ECC|VID_06CC|VID_068C'
$all  = Get-PnpDevice | Where-Object { $_.InstanceId -match $ids }
$live = Get-PnpDevice -PresentOnly | Where-Object { $_.InstanceId -match $ids }
$keep = @{}; foreach ($d in $live) { $keep[$d.InstanceId] = $true }
foreach ($d in ($all | Where-Object { -not $keep.ContainsKey($_.InstanceId) })) {
    & pnputil /remove-device "$($d.InstanceId)" 2>&1 | Out-Null
}
Get-PnpDevice | Where-Object { $_.InstanceId -match $ids } | Select Status,Class,FriendlyName,InstanceId
```

要点：

- **只删不在场的**（`-PresentOnly` 之外的那些），当前在用的实例必须保留；
- 删除后设备树应正好剩 9 个节点（1 父 + MI_00/MI_01 + 5 个 HID 集合 + 1 鼠标）；
- 不需要重启，但管理程序建议重开一次以刷新设备句柄。

### 14.16 右片日志回传（2026-11-10）

右片没有可用控制台（USB-Serial-JTAG 与 host 栈抢同一个 PHY），之前排障只能看计数器猜。
现在右片日志经 `0x1F` 帧回传，左片打印在 COM3 上，前缀 `[R]`：

```
[R] I hidhost: attached 320f:706e addr=2 itfs=2
[R] I hidhost: armed IN 0x81 with 3 transfers
[R] E USB HOST: Enqueue URB error: ESP_ERR_INVALID_STATE     ← 拔下瞬间，正常
```

实现要点（三个坑都踩过）：

1. **必须在链路 UART 初始化之后安装钩子**（`esp_log_set_vprintf`），否则日志写向未初始化的串口；
2. **不能从日志钩子里直接写 UART** —— 会和 1 kHz 报告帧互相打断、两边都变乱码。
   改为**环形缓冲（8×160B）+ 链路任务在帧间隙串行发出**；
3. **右片 sdkconfig 的日志级别原本是 WARN（2）**，`ESP_LOGI` 在编译期就被裁掉，
   所以钩子装了也什么都收不到。已改为 `INFO`（`MAXIMUM=DEBUG`），代价是镜像 +7.6 KB。

### 14.17 台架命令：`mx.lfx`（自动 session 注入）

原 `mx.lf` 需要手填 session（= 右片当前设备地址），填错就被桥接层当会话不匹配丢弃 ——
排查时极易误判成"报告通路坏了"。新命令自动填充：

```
mx.lfx 00640000000000     ->  sent,<session>,7
```

（`session` 由 `makcu_link_session()` 提供；注：报告字段是 16 位小端，写 `0064` 表示 X=0x6400，
写 `6400` 才是 X=100。）

**用完必须补一条 `mx.lb0`**：注入走的是 UART1 内部 loopback（`makcu_link_send_loopback()`），
而 loopback 打开后不会自动关闭 —— 不补 `mx.lb0` 的话，右片的真实报告进不来，症状是
"注入成功但鼠标不动了"，很容易被误判成报告通路故障。

### 14.18 P0 基准（2026-11-10 落地）：`tools/p0_baseline.py`

旧的 P0 指标是"严格指令哈希命中 7/816（0.9%）"，这个数字没有信息量。新工具回答的是
**"每个 handler 与原厂有多接近"**：

```powershell
python tools/p0_baseline.py          # -> verification/p0_baseline.md / .json
```

方法：原厂侧按"到下一个 handler 的地址间隔"切区间并反汇编；我们侧从 `makcu_left.elf`
按符号取同一函数；两边都用 `diff_insn.normalise()` 归一（助记符 + 操作数形状，
地址/立即数/标签折叠），再用 difflib 求比值。因为间隔区间常含尾随函数，额外给出
**滑动窗最佳匹配**（`ratio(win)`），这是主判据。

实测（2026-11-10，官方 V3.2_LEFT.bin vs 当前 ELF）：

| 指标 | 值 |
|---|---|
| 计分 handler | 27 |
| 等价（ratio ≥ 0.70） | 0（0%） |
| **接近（ratio ≥ 0.50）** | **7（25.9%）** |
| 平均相似度（窗口） | **0.357** |
| 指令条数吻合（±25%） | 8（29.6%） |
| 最高分 | `cmd_set_string` 0.60、`cmd_keys_down` 0.56、`cmd_keys_up` 0.56、`cmd_key_tap` 0.52 |

解读：我们是从**反编译伪代码重写**的，不是原源码编译，所以 0.3–0.6 是正常范围；
0.70 作为"结构等价"门槛目前无人达标，0.50 档（7 个）才是可对比的基线。
下一步若要把分数拉高，只能逐函数对着反汇编改（收益递减）；它的主要价值是**变更护栏**
——以后改任何 handler，跑一次就知道有没有偏离。

### 14.19 协议行为轨迹基线（2026-11-10）：`tools/trace_opcodes.py`

用于回答"隐藏 opcode 的语义是否与原厂一致"，做法是**行为对照**而不是 JTAG 单步
（可重复、可回归、不需要把盒子下线）：

```powershell
python tools/trace_opcodes.py --port COM3                     # 采集基线
python tools/trace_opcodes.py --port COM3 --compare verification/opcode_trace.json   # 差分
```

脚本按协议线格式 `'.' + 'km.' + 命令 + '\r'` 驱动 **42 步**，覆盖：version / buttons /
按键 press·click / move / wheel / lock 全家 / catch 全家 / silent / serial，
并在最后做状态回读（`mx.bo`、`mx.ei`、`mx.ds`、`mx.fv`）。自比对实测 `trace matches`。

基线里两个**值得记住的观测**：

- `lock_mx(1)` 之后 `lock_mx()` 返回 **1** —— 锁定状态确实可读回；
- `catch_ml(1)` 之后 `catch_ml()` 仍返回 **0** —— 与源码注释记录的
  "`catch_set` 写 `+0x168`、`catch_query` 读 `+0x124`"不对称一致，
  属于**已知语义**，不是缺陷；如需最终确认仍需 JTAG 单步（唯一遗留的 JTAG 项）。

想拿到原厂侧的轨迹：刷官方 `V3.2_LEFT.bin` → 跑同一脚本 → 刷回当前固件 → `--compare`。
这是一次性操作（左右各约 2 分钟），需要时再做。

### 14.20 控制口 921600 + 二进制快速通道（2026-11-10，面向 Android/外部主机）

控制口（中线 CH343 → COM3）已从 115200 提到 **921600**，并新增一套**二进制 fast path**
（`app_left/main/control_bin.c`）。文本协议 `.km.xxx()` 原样保留，两者共用同一根线、同一个动作层。

**帧格式**（小端）

```
5A <cmd> <seq> <len u16> <payload> <crc8>      crc8: poly 0x07，覆盖 cmd..payload
```

| cmd | 名称 | payload | 回包 |
|---|---|---|---|
| `0x31` | `MOTION_PLAN` | `dx i16, dy i16, dur_ms u16, mode u8, flags u8` | 无 |
| `0x32` | `BUTTON` | `mask u8` | 无 |
| `0x33` | `WHEEL` | `delta i8` | 无 |
| `0x34` | `QUERY` | `what u8`（0=计数 1=能力 2=上条计划） | 有 |
| `0x35` | `PING` | `counter u32` | 有（回 counter + 设备时钟 + 计划数） |

**语义**：交互路径 fire-and-forget（不回包、不重传）；丢包只能靠 `QUERY 0` 的
`crc_err / len_err / seq_gaps` 看。`dur_ms=0` 表示由盒子自己按目标速度定时长（P3 落地后生效，
现在 `QUERY 1` 的 `plan_engine=0` 表示走旧的 127 分块引擎）。

**实测（2026-11-10 18:00）**

```
PING x200   : lost 0   p50 1.10 ms   p99 1.18 ms        ← 之前是 20 ms，见下面两个坑
MOTION_PLAN : dx=200 → mx.rt 精确 +200，submit_us 330
BUTTON/WHEEL: mx.bo / mx.rt 都能读回
回归        : 100 passed（MAKCU_BAUD 默认已改 921600）
```

**这轮踩到的两个坑（都已修）**

1. `uart_read_bytes(buf, 1024, 20ms)` 会**等满长度或超时**才返回 —— 一条 12 字节的回包
   永远填不满 1024，于是每条回复晚 20 ms。改成"事件队列告诉你来多少，就按 `ev.size`
   用 0 超时读多少"。
2. `pdMS_TO_TICKS(5)` 在 100 Hz tick 下等于 **0**，用它等队列 = 忙等 → `km_uart0`
   自旋、IDLE0 饿死、任务看门狗每 5 s 打印一次（日志还会混进协议流，把回归里
   "逐字节比对"的用例全打翻）。改用 `portMAX_DELAY` 阻塞在事件队列上。

**台架工具**：`python tools/link_probe.py --ping 200 / --plan 300 0 / --all`
（同时量 RTT、查计数、验证 `mx.rt` 守恒）。

### 14.21 sumv：拟人化相对移动（1000 Hz，2026-11-10 落地）

`sumv` 是**重建扩展**（原厂没有）：一条命令 = 一条带人味的相对移动轨迹。

```
.km.sumv(dx,dy)                 默认 speed=400 counts/s，拟人层全开
.km.sumv(dx,dy,speed)           越大越快
.km.sumv(dx,dy,speed,mode)      bit0 固定时长 · bit1 手颤 · bit2 子运动 · bit5 关粘滞 · bit6 拟人模式
                                （bit3 过冲 2026-11-11 移除、bit4 微停顿 2026-11-10 移除；默认 mode=0x00 = 瞄准模式）
.km.sumv(dx,dy,speed,mode,dur)  dur 仅在 bit0 置位时生效
.km.sumv()                      -> sumv()\n<0|1|2>
.km.sumv_stop()                 -> 立刻停在当前位置
```

二进制（控制口 fast path）：`0x36 SUMV`（dx i16, dy i16, speed u16, mode u8, seed u8
[, dur u16]）· `0x37 SUMV_STOP` · `0x38 SUMV_STATE`（回 active/samples/aborted/rounds/
muted/btn_fwd/speed_eff/remain_ms）。**全部 fire-and-forget**，只有 STATE 回包。

**速度参数**：`T_ms = clamp(1000·D/speed, 40, 5000)`，`D = round(hypot(dx,dy))`，
`speed ∈ [50, 8000]`，默认 400；被 clamp 时 `speed_eff` 回报实际值。

**执行期间的屏蔽**（`link_report_to_mouse()` 里的一跳）：

| 输入 | 行为 |
|---|---|
| 真实鼠标 X/Y | 丢弃（`muted++`） |
| 真实鼠标按键/滚轮 | **透传**，且只在 `(buttons,wheel,pan)` 变化时才发（否则 540–900 条/秒的零位移报告会吃光 1000 槽/s 的端点） |
| `.km.move` / `MOTION_PLAN` | 拒绝（`move_hook_guarded`） |
| `.km.wheel` / `WHEEL` | 照常 |
| 再次 `sumv` | REPLACE，剩余位移丢弃（`aborted++`） |

**引擎**：`esp_timer` 1000 µs → 专用任务（prio 13）→ 三次贝塞尔（两个控制点各带
±span/12 随机垂直偏移 + 沿路径 ±10% 抖动）→ 弧长 LUT + min-jerk → 亚计数 DDA → 每样本 0–2 counts。

**注（2026-11-10 移除"微停顿"）**：原来有 20% 概率插 40–120 ms 停顿，观感像卡一下/掉帧，
用户要求去掉。现在 `total_samples == T_ms` 恒成立（实测连跑 5 次，每次正好 1000 样本、
`mx.rt` 每次 +600），mode bit4 保留但无效。

**注（2026-11-11 开机 autoclone 加重试，修掉"回归跑一半成片失败"）**：右片刚上电时常常还没
枚举到鼠标，单次探测失败就退回 4 字节夹具 → 真实鼠标 7 字节报告被当 12-bit 解 → `mx.rq/mx.rt`
全是垃圾，回归里表现为"某几个 trace 断言成片失败"（`mx.if` 变 0、`mx.rb` 变 bytes=4）。
现在开机探测失败会**最多重试 10 次 × 300 ms**（约 3 s）再退回夹具。刷入后连跑回归：
**100 passed**（跑完 `mx.if` 仍可能变 0，那是 clone 用例故意留的夹具，不影响测试结果）。

**注（2026-11-11 瞄准专用优化）**：为闭环瞄准补了六件事 ——

| 项 | 内容 |
|---|---|
| `0x3C AIM` | 按时长下发的瞄准入口：`dx,dy,max_ms,flags[,dead_min]`，内部折算 speed 并走**恒速剖面** |
| `0x3D AIM_STATE` | 12 B：`active, last_result(1 启动/2 替换/3 拒/4 死区/5 故障/6 超限), counts, 耗时, aborted, rounds, dead_hits, gen` |
| 死区 | 残差 ≤ `dead_min`（默认 2 counts ≈ 2.5 px）直接回"已到位"，不发报告 |
| `dur_ms` 生效 | 显式时长不再被 `mr` 地板抬高（实测 600 counts / 8 ms → 7 ms 走完） |
| 首样本立即发 | `start()` 里 `xTaskNotifyGive`，首样本延迟从 ≤1 ms 降到 ~0.2 ms |
| 收尾平滑 | 补齐改"每 ms 最多一发"（极速档最大报告间隔 1011 µs，不再 1 ms 内连发 8 条） |
| 竞态 | 加轨迹代数 `s_gen`：采样时若被 REPLACE，算出的样本直接丢弃，不污染新轨迹 |
| 建失败回滚 | 新请求建路径失败时回滚旧轨迹继续跑，不再"停在半路" |
| 看门狗 | 超过 `total_samples + 500 ms` 仍在跑 → 强制停、`last_result=5` |

**注（2026-11-11 每报告上限自动跟随速度）**：固定 `max_report=12` 等于给速度钉了 12,000 counts/s
的顶，请求 20,000/60,000 全被 `t_floor` 夹回去（实测 60,000 仍是 49 ms、`speed_eff=12,000`）。现在：

```
mr_eff = 12 + (speed - 11000)/1000     // speed <= 11000 时 = 12
mr_eff = clamp(mr_eff, 12, 120)        // 极速 bit7 直接用 120
t_floor = ceil(D / mr_eff)             // 最低 4 ms
```

`mr ≈ speed/1000 + 1` → `t_floor ≤ 1000·D/speed` 恒成立 → **`speed` 变成字面速度**。
**二进制协议不扩**（2026-11-11 决定）：`0x36` 不加 mr 字节、`0x38` 保持 29 B，
上位机用 `speed_eff / 1000` 反推每跳 counts（撞 floor 时该式精确）；
`mx.mv` 的固定模式降级为台架排障用，生产路径只用 `speed` 表达意图。
实测（D=600，Σ 全精确）：11,000→52 ms、12,000→49 ms、20,000→29 ms、40,000→14 ms、**60,000→9 ms**；
固定 `mr=12` 时 60,000 仍被夹到 49 ms（保留的旧行为）。`mx.mv` 打印
`speed,auto|fixed,mr=<有效值>,cap=1000×mr`，`mx.mv <speed> 0` 切回自动。

**注（2026-11-11 速度上限放开 + `mx.mv`）**：原来 `speed` 钳在 8000、时长下限 40 ms，短距离
根本到不了标称速度。现在：

- `speed` 钳位 `[50, 65535]`（u16 字段上限）；
- **时长下限改成自适应**：`T_floor = ceil(D / max_report)`，最低 4 ms ——
  这既是"每报告不超过 `max_report` counts"，也定义了真正的速度天花板 **1000 × max_report**；
- 新增 `max_report`（8–120，出厂 **60**）、`bit7` **极速**（`T` 直接取 floor）、台架命令
  `mx.mv [speed [max_report]]`（读/写默认值，打印 `cap=1000×max_report`）；
- 收尾补齐改**循环**：极速档缺口可能 >127，单发补不完（实测曾短 57/358 counts）。

实测（2026-11-11，Σ 全部精确）：

| 请求 | max_report | 时长 | speed_eff | 样本 |
|---|---|---|---|---|
| 2000 极速 | 60 | 33 ms | 58,823 | 34 |
| 2000 极速 | 120 | 16 ms | 117,647 | 51 |
| 8000 极速 | 120 | 66 ms | 119,402 | 118 |
| 300 极速 | 120 | 3 ms | 75,000 | 4（下限 4 ms） |
| 2000 普通 speed=400 | 60 | 4997 ms | 400 | 2002 |

**注（2026-11-11 新增"瞄准模式"，默认）**：`sumv` 默认从"拟人"切到 **FPS 拉枪线手感**——
速度剖面改成**按距离分档的梯形**（`D≤10` 单发、`D≤60` 恒速+纯直线、`61–300` 进6%/出10%、
`301–800` 8%/12%、`>800` 10%/15%），路径法向偏移从 `span/12` 收到 `span/60`（弧高 ≈1.25%，不再是
8%），**手颤与子运动默认关闭**，粘滞收尾只在 `D ≥ 600` 且强度减半。实测（speed=2000）：

| 距离 | 总时长 | 起步 0–5% | 尾段 95–100% | Σ / 过程最大 |
|---|---|---|---|---|
| 30 | 38 ms | 1 ms（2.6%） | 1 ms（2.6%） | 30 / 30 |
| 300 | 149 ms | 11 ms（7.4%） | 14 ms（9.4%） | 300 / 300 |
| 2000 | 999 ms | 93 ms（9.3%） | 117 ms（11.7%） | 2000 / 2000 |
| 300（`0x40` 拟人） | 147 ms | 26 ms（17.7%） | 28 ms（19.0%） | 300 / 300 |

对比改造前（min-jerk）：起步/尾段各占全程 **≈20%** —— 这就是"开局一顿、收尾爬"的来源。
`bit6 = 拟人模式` 可随时切回旧观感（min-jerk + 手颤 + 子运动 + 大弧 + 全强度粘滞）。

**注（2026-11-11 移除"过冲回拉" + 新增"粘滞收尾"）**：原实现把终点延长 2–3% 再在最后 20% 进度
拉回来；现在**路径终点就是请求值**，过程累计位移永不超过请求（实测 dx=2000：`Σ=2000`、
过程最大值 `=2000`）。取而代之的是更"贴地"的做法：**最后 5% 进度把位置-时间压低**
（`SUMV_TAIL_A = 560` Q16，bump 在 u=1 归零 → 终点仍精确），实测 97.5% 处晚 **+93 ms**
（该段速度约 −18%），bit5 可关。

**实测（2026-11-10 18:35，speed=400 / dx=800）**

```
mx.sv  : 0,2000,0,1,0,0,400,0        样本 2000、正常走完 1 次、speed_eff 400
mx.rt  : -15279 -> -14479            +800，精确守恒
单报告  : |dx|+|dy| p50=1  p90=1  max=2
节拍    : dt p50 1991 µs（400 counts/s ⇒ 每 2.5 ms 一个 count）
二进制  : SUMV(400,-300,speed=400) -> remain 1250 ms 递减，samples 1000/s 增长
```

**这轮踩的两个 bug（都已修）**

1. `minjerk_q16()` 内层三项量纲写错（`6t²` 写成了 `6`），t→1 时内层变负、曲线尾部来回甩，
   注入变成 ±127 的震荡 —— 现象是 trace 里全是 127 一块、每 1 ms 一跳；
2. `makcu_mouse_pump()` 会抢走 `run_move()` 的 pending，把一次 3 步的移动拆成 pump 步 +
   剩余步（回归 `test_two_axis_split_sums` 偶发失败的真因）；现在 `run_move` 期间 `s_moving`
   置位，pump 直接返回。

**已知遗留**：刷写/复位后偶发克隆退回 4 字节 Logitech fixture（`mx.as=1` 但 `mx.if=0`、
`dev=6d0477c0`），此时真实鼠标改走 mouse 层、sumv 屏蔽的语义会错位；`mx.rs` 重启即恢复
（见 §14.7 第 7 条）。后续应把"`if_count==0` 视为 autoclone 失败"做进自愈。

### 14.22 按键事件（默认穿透，可选吃掉）

**2026-11-11 语义变更**：默认从"订阅即消费"改成 **默认穿透** —— 订阅只产生事件，
按键本身照常转发给 PC。想吃掉必须显式传 `consume=1`：

| 位置 | 变化 |
|---|---|
| `0x39 EVT_CTL` | payload 增加第 4 字节 `consume`（缺省 0 = 穿透；1 = 吃掉） |
| `0x38 EVT_STAT` | `flags` bit3 = consume（长度仍 12 B） |
| `.km.evt` | `evt(1[,mask[,consume]])` |
| `mx.ev` | 末尾追加 `consume` 字段 |
| 工具 | GUI 加"吃掉这些点击"勾选（默认关）；`link_probe.py` 加 `--evt-consume` |

实测（注入 0x08 后立刻读 `mx.ev`）：

```
吃掉模式：cur=08 last_fwd=00   ← PC 看不到
穿透模式：cur=08 last_fwd=08   ← 照常转发
两者都产生事件（seq 递增）
```

原有固件**没有任何按键事件通道**（控制口是纯请求-响应，只能轮询 `.km.buttons()`）。现在有了：

| 命令 | 说明 |
|---|---|
| `0x39 EVT_CTL` | `enable u8, mask u8, push u8` —— **订阅即消费**：被订阅的键从转发给 PC 的报告里抹掉 |
| `0x3A EVT_READ` | `count u8`（≤7）→ `[count][n×8B]`，也是心跳 |
| `0x3B EVT_STAT` | 状态/计数，也是心跳 |
| `0xE1 EVT_PUSH` | 异步段（0xE0–0xEF），设备主动推：`t_us u32, seq u16, mask u8, edge u8` |
| `.km.evt(1[,mask])` / `.km.evt(0)` / `.km.evt()` | 文本侧订阅/取消/查询（opcode 0x1D） |

事件源**只有真实鼠标**；滚轮与移动永不产生事件；`.km.left(1)` / `BUTTON` 也不产生（只影响 PC）。

**关键边界**：订阅瞬间已按住的键继续透传到松开（否则 PC 卡按下）；10 s 无心跳自动恢复全透传；
事件环 32 条、溢出覆盖 + `overflow` 计数、`seq` 不回绕。

**实测（2026-11-10 19:40）**

```
订阅 mask=8（侧键4）→ mx.ev: 1,08,00,00,00,…          pending=0
注入按下 btn=0x08   → cur=08  last_fwd=00  seq=1       ← 被吃掉，PC 看不到
注入松开 btn=0x00   → cur=00  last_fwd=00  seq=2
EVT_READ            → 2 条：(t,seq,mask,edge)=(…,0,08,08) (…,1,00,08)
未订阅键 0x01       → last_fwd=01（照常转发），无事件
0xE1 推送           → 每次边沿各 1 帧，字段与 READ 一致
11.5 s 不心跳        → enabled=0 auto_released=1，注入恢复透传
回归                → 100 passed
```

台架判据 `mx.ev` 的第 5 个字段 `last_fwd` 就是"PC 到底看到了什么"。

### 14.23 台架 GUI：boxbench（2026-11-11）

```powershell
python tools\boxbench_gui.py                 # 开界面（默认 COM3 @921600）
python tools\boxbench_gui.py --port COM5
python tools\boxbench_gui.py --selftest      # 不开界面：链路+轨迹+指标+导图 自检
python tools\boxbench_gui.py --suite smoke   # 无头冒烟，退出码可给 CI 用
```

**依赖**：Tkinter（Python 自带）、Pillow（导 PNG）、pyserial。

**界面四区**

| 区 | 内容 |
|---|---|
| 顶部 | 端口/波特率下拉、DTR/RTS、连接、状态灯 |
| 左 | 状态（2 s 刷新：`mx.if/mx.rb`、sumv、事件、`mx.ds`）+ sumv 控制（dx/dy/speed 滑块、拟人/手颤/子运动、发送并抓轨迹、停止）+ 按键事件订阅（掩码、订阅/读一次） |
| 右 | 轨迹（Canvas：XY + 速度曲线，指标文本，导 PNG / 重抓）· 事件（seq/mask/edge/t_us）· 日志（收发/事件分色） |
| 底 | 连通性、延迟 ×100、克隆健康、守恒、跑回归 |

**"发送并抓轨迹"流水线**（一键）：`mx.mt clr` → `mx.mt on` → `SUMV(0x36)` → 轮询 `SUMV_STATE`
到 `active=0` → `mx.mt d`（冻结环）→ 解 `ep=0x00` 样本 → 指标 → 画图。

指标口径与 `verification/report/2026-11-10-sumv.md` 一致：起步 0–5% 占比、尾段 95–100% 占比、
Σ 守恒、过程最大投影（越界会标 ⚠）、单报告 p50/p90、dt p50/p90、`dy≠0` 行数。

**桌面启动方式**

| 方式 | 用途 |
|---|---|
| 桌面 `MagicBox 台架工具` | 日常用（`pythonw`，无黑框，带图标） |
| `tools\boxbench.cmd` | 排障用（带控制台，能看到 Python 报错） |
| `python tools\boxbench_gui.py` | 命令行启动，可加 `--port COM5 --no-autoconnect` |
| `powershell -File tools\make_shortcut.ps1` | 重建桌面快捷方式（`-Name` 换名、`-NoIcon` 不设图标） |

> 串口独占：已开着一个 boxbench 时再双击快捷方式，新实例连不上，日志会提示
> "端口被占用：可能已经有一个 boxbench 在跑"。

**必须知道的五点**

1. **串口独占**：点"跑回归"会自动断开串口，跑完**不**自动重连（手动点"连接"）；
2. **`mx.mt d` 会冻结轨迹环**：下次"发送并抓轨迹"前会自动 `clr/on`；单独"重抓轨迹"拿的是上次冻结内容；
3. **`mx.*` 只在台架构建存在**：出货固件上状态显示 `?`、轨迹与测试按钮不可用，短信令与 PING 仍可用；
4. **PING 的 RTT 取决于 reader 读法**：`serial.read(512)` 会等满 512 字节或超时（实测把 1.1 ms 拖成 60 ms），
   本工具用 `in_waiting` 轮询 → 实测 **p50 1.07 ms**；
5. **速度曲线用 10 ms 滑动窗口**：逐报告算会在 1/2 ms 交替间隔上产生梳齿，看不出梯形剖面。

**实测（2026-11-11 09:25，selftest + smoke）**

```
PING x20         : p50 1074 us  max 1513 us
sumv(300,0,2000) : 样本 144 · 149 ms · Σ=(300,0) 精确 · 过程最大 300 · 起步 7.4% · 尾段 9.4%
sumv(500,0,2000) : 样本 237 · 249 ms · Σ=(500,0) 精确 · 起步 8.4% · 尾段 10.4%
冒烟结果         : PASS            导图：work/boxbench_selftest.png
```

### 14.24 光标增益：为什么"速度越大越偏"（2026-11-11 标定）

**工具**：`python tools\px_cal.py --no-confirm --reps 3`（只测量）。报告见
`verification/report/2026-11-11-px-gain.md`，曲线图 `work/px_gain.png`。

**本机环境**：屏幕 2560×1600；`MouseSpeed=0`（"提高指针精确度"**已关闭**）；
`MouseThreshold1/2=0`；`MouseSensitivity=10`；缩放 125%。

**结论一：增益是常数，没有加速项**

| 每报告 counts | 9 | 18 | 44 | 63 | 103 |
|---|---|---|---|---|---|
| gain (px/count) | 1.2500 | 1.2500 | 1.2500 | 1.2500 | 1.2500 |

`= 1.0 logical px × 1.25 缩放`。所以：
- **S1（改系统设置关 EPP）不需要做**——本来就是关的；**打开 EPP 才会引入非线性，别动**；
- **S3（固件增益表）不需要做**——乘一个常数 1.25 即可，换机器/缩放要重标；
- **S2（瞄准档 max_report=12）对精度没有帮助**（9 counts 与 103 counts 增益一致），只影响观感。

**结论二：偏移的真正来源是"屏幕边界钳位"**

从 x=200 起跑，`sumv` 一次走完：

| 请求 counts | 线性预期 | 实测位移 | 判定 |
|---|---|---|---|
| 400 | 500 px | 500 | ✓ |
| 1500 | 1875 px | 1875 | ✓ |
| 1900 | 2375 px | **2359** | ✗ 停在 x=2559 |
| 2200 | 2750 px | **2359** | ✗ |
| 3000 | 3750 px | **2359** | ✗ |

**撞边后多发的 counts 被 OS 吃掉、永不回补**。位移越大/速度越快 → 越容易顶边 → 少走的像素越多，
看起来就是"速度越大坐标偏得越厉害"，而且和每报告大小**无关**。

**已落地（2026-11-11 10:40）**

- `tools/aim_move.py`：防撞边闭环。实测 `--by 300,-120` → 1 px（825 ms）、`--to 400,300` → 0 px、
  `--by 3000,0`（超屏）→ **主动夹到 2558**、1 px（没有多发 counts）；
- `max_report` 出厂值 `60 → 12`（瞄准档，cap=12,000 counts/s），台架 `mx.mv` 可随时改；
- boxbench 轨迹页现在同时显示「Σ counts / 实际光标位移 / 实测增益 / 撞边标记」——
  一次 200 counts 的移动实测 `+249 px → 1.25 px/count`，和标定一致。

**后续可做（待拍板）：

1. 客户端按 `px = counts × 1.25` 换算（本机）；要"按像素说话"就反过来除；
2. **防撞边**：下发前 `GetCursorPos`，把 `dx` 夹到"到边剩余空间 / 1.25"；要点式到位就分 2–3 段，
   每段读完光标再修正，撞边立刻停；
3. boxbench 轨迹页把「Σ counts / 实际像素位移 / 撞边标记」并排显示。

### 14.25 瞄准压力测试 `aim_stress.py`：并发 sumv + 按键零丢失（2026-11-11）

```powershell
python tools\aim_stress.py                                    # both：队列 10 步 + 并发 10 s
python tools\aim_stress.py --mode queue --queue-steps 10       # 只验队列守恒
python tools\aim_stress.py --mode concurrent --seconds 20 --rate 200 --btn-rate 20
```

跑之前先关掉 boxbench（串口独占）。

**线程分工（并发是怎么造出来的）**

| 线程 | 做什么 |
|---|---|
| 瞄准线程（默认 120–200 Hz） | 读光标 → 算到右上角的残差 → 发 `0x3C AIM(counts, max_ms)`；每 15 条掺一次反向抖动，制造大量 REPLACE |
| 按键线程 | `0x32 BUTTON` 按 → 保持 45 ms → 松，循环；默认**中键**（右上角是关闭按钮的位置，左右键默认不碰） |
| PC 观察线程 | 3 ms 轮询 `GetAsyncKeyState`，统计每个键的按下/松开沿 |
| 监视线程 | 200 ms 读 `0x3E HID_STAT` / `0x3D AIM_STATE` |
| 写线程 | **所有命令单一出口**，串口写串行化（顺带给 `link.py` 的 `next_seq` 补了锁） |

> **"按键与移动是并发吗"**：逻辑上**是并发的**——两个线程同时往队列里压 `AIM` 和 `BUTTON`，
> 时间上是重叠的（实测 5 s 窗口内 AIM ~950 条、按键 53 个周期同时发生）。
> 物理上是**串行发送**（一条 UART，写线程按入队顺序发），但在**固件 HID 层按键优先**：
> 按键报告走单槽 `s_urg`，发送侧先看它再看运动 FIFO（见 API 文档 §3.x `0x3E`），
> 所以即使 AIM 在 1 kHz 灌流，按键也不会被压后或挤掉。
> 想测"完全不并发、一条一走"的对照，用 `--mode queue`（按键在两次移动之间插入）。

**判据（客观，非人工）**

1. **按键回环审计**（`0x3F BTN_AUDIT`，2026-11-11 加）：`in_chg == out_chg == 注入的按键变化数`
   且 `extra == 0` —— 每条变化**正好**对应一条线上报告：**不丢、不重、不多发**；
2. PC 侧**按下沿 ≥ 周期数**、**松开沿 ≥ 周期数**（不能少，Windows 会合成边沿所以不要求相等）；
3. 释放之后所有键都抬起（无卡键）+ 光标**确实进过**右上角方框且全程不越界；
4. 按键处 AIM 间隔尖峰 ≤ `--gap-ms`（默认 25 ms）—— 证明按键**不会把移动卡住**。

> `0x3E HID_STAT` 的 `btn_in/btn_sent` 只统计真实鼠标报告，注入按键进不去，所以以前没法证明
> "没多发"；补了 `0x3F` 之后这一半也闭合了。队列模式另外用"光标像素 == counts × 1.25（±6 px）"
> 校验每步守恒。

**实测（重载连跑三轮 + 接线审计后，全 PASS）**

| 场景 | AIM | 按键指令 | 回环审计 | PC 侧 | AIM 间隔尖峰 |
|---|---|---|---|---|---|
| 200 Hz / max-ms 40 / btn 20 Hz | 1145 | 126 | `in 126 = out 126, extra 0` | 65 按 / 65 松 | 5.6 ms |
| 150 Hz / max-ms 20 / btn 12 Hz | 114 | 94 | `in 94 = out 94, extra 0` | 47 / 47 | 7.1 ms |
| 150 Hz / max-ms 20 / btn 12 Hz | 416 | 108 | `in = out, extra 0` | 60 / 60 | 7.2 ms |

**踩过的三个坑（已写进脚本注释）**

1. **文本命令在二进制高频混发时会静默**：`mx.rt` / `mx.mv` 连续 5 次无回包、`rx` 不再增长。
   于是工具改成**全二进制**，位移校验改用 `GetCursorPos`；`link.py` 的 reader 也不再因解析
   异常而死掉（新增 `rx_error`）。
2. **`0x32` / `.km.left()` 注入的按键不计入 `btn_in`**（该计数统计真实鼠标报告）→ 因此补了
   `0x3F BTN_AUDIT` 专门审计注入按键。
3. **停止瞬间必然"按着"**：判定要用"释放后 `GetAsyncKeyState` 全抬起"，不能用停止时的快照。

### 14.26 光标抖动排查：已证伪的两个方案 + 保留的探针（2026-11-11）

**现象**：鼠标经盒子透传时视觉上有抖动（尤其慢速平移），直插 PC 没有。

**第一步先把"丢帧"排除掉**（右片 `0x1C` 帧的 u16 计数一直是 65535 饱和，什么都看不出，
所以先做了两件事）：

| 改动 | 说明 |
|---|---|
| 右片 `makcu_hidhost_stats32()` + `0x1C` 帧 20 → **36 B** | 尾部追加 `ok/fail/done/fwd` 的 **u32**，不再饱和 |
| 左片 `mx.hi` 的 `rp[32]` → `rp[40]` | 32 B 会把 36 B 的回包截断（`ex=u16` 就是这个原因） |
| 新增 `mx.hz` | 左片侧精确速率：`dt/frames/s chunks/s inj/s drop B/s` |
| 新增 `mx.lh` | 转发报告间隔直方图（**16 桶/页 × 16 页**，每桶 100 µs） |

**结论 1：盒子不丢帧、不合并，是严格 1:1 透传**

鼠标移动中连续采样（`done` = 右片读到，`fwd` = 右片转发，`frames` = 左片收到）：

| 采样 | done/s | fwd/s | 左片 frames/s |
|---|---|---|---|
| 1 | 1005 | 1005 | 962 |
| 2 | 834 | 834 | 828 |
| 3 | 511 | 511 | 516 |
| 4 | 406 | 406 | 399 |
| 5 | 654 | 654 | 654 |
| 6 | 915 | 915 | 921 |
| 7 | 644 | 644 | 640 |
| 8 | 146 | 146 | 147 |

累计 `done = fwd = 21677`，**一条不差**。之前看到的 `frames=453/s` 不是盒子丢速，而是
**那一刻鼠标本身就只发那么多** —— 无线鼠标的报告率随移动速度变（146–1005/s）。

**结论 2：抖动来自鼠标自身的成簇节奏**

`mx.lh` 在鼠标移动中实测（1/4 采样，1 kHz 名义 4 ms）：

```
200–300 µs   49.8%      ← 一半的间隔挤在一起
7500–7700    15.0%      ← 然后是 7.6 ms 空档
8600–8800    15.0%      ← 再来 8.7 ms
尾巴一直到 25600 µs
```

无线鼠标只在"有位移"时以 1 kHz 发，且不与 USB 帧对齐 → 成簇 + 空档。盒子多了一级队列
（32 深、完成回调驱动），把"成簇"进一步变成"有时一帧 2 条、有时整帧空着"；Windows 的
指针加速按 `每帧 delta ÷ 帧间隔` 算倍率，于是视觉上忽快忽慢。

**已证伪的方案（都实现过、上机过，不要再走一遍）**

| 方案 | 做法 | 结果 |
|---|---|---|
| **A 输出节拍器** | `makcu_hiddev.c` 加 900 µs 最小发送间隔，未到时隙就入队 | **手感更差**：门限只在"完成回调"和"到达"两个时机生效，没有独立的 1 kHz 定时器兜底，被跳过时队列要等下一次到达 → 反而造出空档 |
| **B 重采样平滑** | `mx.sm <cap>`：把一条大 delta 拆成几条，残留由 1 kHz 尾巴任务补 | 数据上正确（注入 `dx=20`：cap=0/2/4/10 总位移都是 20 px，到位 7/15/11/8 ms），但**用户看后不要**；已完整移除 |

两套代码都已删除（含命令、尾巴任务、verbatim 钩子），当前固件 verbatim 就是
**"来了就发"**：端点空就立刻发，端点忙就入队，完成回调里继续排空。

**还留着的东西（诊断用，别删）**

| 探针 / 工具 | 用途 |
|---|---|
| `mx.hz` | 左片精确速率（判"喂没喂满"的第一把尺子） |
| `mx.hi` | 右片状态 + u32 精确计数 + 速率（`ex=ok` 表示走的是 36 B 新帧） |
| `mx.lh <page>` | 转发间隔直方图，16 桶/页 × 16 页 |
| `tools/dt_hist.py` | 读 `mx.lh` 画直方图 + 打印 `mx.hz`，ASCII 输出（防 GBK 控制台乱码），`--cn` 转中文 |
| `mx.lf a2 81330700 <7B>` | 注入一条 7 字节报告（**ep 必须写 0x81**，写 0x02 不会动光标；会话要 `mx.ss 33` 固定） |

**两个台架坑（写死在这里，省得下次再撞）**

1. `mx.lh 0` 之类带参数的探针，`line` **不是 NUL 结尾**，必须按 `len` 有界扫描；
   用 `while (*a == ' ')` 会读到残留字节（当年 `mx.mt` 同款坑）。
2. 文本回包会串行：`mx.ss 00` 的 `auto` 可能晚到，读到的是上一条的回复 —— 要循环取到
   "含 `frames=` 的那一行"为止。

## 15. 性能现状（2026-11-10 实测）
| 指标 | 值 | 说明 |
|---|---|---|
| 左片每条报告耗时 | p50 **10 µs** / p99 30 µs | ≈0.5% CPU @500 条/秒 |
| 右片每条转发耗时 | p50 **60 µs** / p99 60 µs / max 67 µs | ≈3% CPU，是当前最大的单项开销 |
| 报告到达间隔 | ≈2 ms（≈500 条/秒） | 由**鼠标回报率**决定，不是盒子限制 |
| 队列丢弃 | **0** | 队列深度 32 |
| 链路带宽占用 | 15 KB/s ÷ 500 KB/s ≈ **3%** | 所以提高波特率/改帧格式都无收益 |

**历史根因（重要）**：曾经"鼠标明显偏慢"，根因不是带宽/波特率/协议，而是
`makcu_hiddev_report_verbatim_ep()` 里的 `if (!tud_hid_n_ready()) return;` ——
1 kHz 下端点几乎总是忙，每条被拒的报告连同它的**相对位移**被永久丢弃（位移是累加的，丢多少就慢多少）。
修复：端点忙/挂起时入队，由 `tud_hid_report_complete_cb` 逐个排空，**绝不合并**。
实测注入 200 条：修复前 70 条送达，修复后 **200/200**。

## 16. 2026-11-10 变更时间线（便于追溯）

| 阶段 | 内容 |
|---|---|
| 上午 | 右片补丁方案（blob/pipe 表）走不通 → 转为**自编右片固件**，M1–M4 达成（枚举 / IN 转发 / EP0 隧道 / OUT 提交） |
| 中午 | 双接口复合克隆（`MB_DUAL_IF`）+ 厂商 OUT 端点 0x05→**0x03**；HECATE 首次识别 |
| 下午 | 插拔失效根因（**会话号只采纳一次**）→ `makcu_link_reset_session()`；身份别名策略 + 唯一序列号；右片日志回传（`0x1F`） |
| 傍晚 | 性能整改：报告队列（关键）、块读、优先级、TX 环、`mx.lat` 探针；P0 基准与行为轨迹工具 |
| 深夜（补丁轮） | 交接收尾：右片 `0x1C` 应答栈越界（`payload[12]`→`[20]`）、`makcu_link_request()` 加互斥（控制台/OUT 队列/自愈三方并发）、文档三处过时说明更正（`MB_FORCE_VIDPID` / `mx.vp` 非持久 / `mx.lfx` 后需 `mx.lb0`） |

每步的详细根因、证据与验证都在 `verification/plan-*.md` 里，按时间顺序排列。

## 待推进方案

- `verification/plan-hecate-connect-proxy.md`：让 HECATE Connect 在"鼠标插在盒子上"时也能识别与
  设置鼠标的方案（身份 + 复合拓扑 + 厂商 IN 转发 + 厂商 OUT 下行；含判定点与工作量）。

- `verification/plan-right-firmware.md`：**自编右片固件方案**（替代原厂 V3.7；M1 枚举 → M2 IN 转发
  → M3 EP0 隧道 → M4 OUT 下行 → M5 健壮性；含接口契约、风险与工作量）。优先于二进制补丁路线。
