# 交接文档 — MagicBox（MAKCU 双芯片鼠标盒子 · 固件重建）

> 更新：**2026-11-14**。上一版（2026-11-13，1183 行）存档为
> [`HANDOVER-2026-11-13-archive.md`](HANDOVER-2026-11-13-archive.md)；更早的 2026-11-09 版已随旧仓库清理。
> 本文只写**当前状态与怎么用**；每一轮的执行细节在 `verification/report/` 与各 `plan-*.md` 里。
> 历史上"调试记录"类内容（§14 全部小节）原样保留在本文末尾，锚点不变。

---

## 1. 一句话现状

**盒子可用，且三条数据通路都已定型并发过验收**：

| 通路 | 现状 | 判据 / 证据 |
|---|---|---|
| **鼠标透传**（右片 → 左片 → PC） | 正常，拔插自愈 | `mx.ls` ≈ 570 帧/s；`mx.hi` `fail=0`；报告 p50 10 µs / p99 30 µs |
| **厂商通道**（HECATE / G3M PRO） | 识别、读配置、改 DPI 都**不再卡** | `mx.ox`：`out==vin==vf`、`ofail=0`、`venq` 丢弃 0、`vp50 ≈ 31–39 ms`（D47） |
| **按键事件**（0x39 订阅 → 0x3A/0x3B 环 或 0xE1 推送） | 订阅**不吞**物理点击；通知延迟 **≈0.12 ms** | D48：并发 1000 边沿/秒时 `wire_chg == head_seq == evsent`，`evdrop=0` |

两颗芯片**都是自编固件**：真机回归 **128 passed / 0 failed**，离线模型 **46 passed**，合计 **174 例**。

| 镜像 | 尺寸 |
|---|---|
| 左片（台架版，带 `mx.*`） | **355,040 B** |
| 左片（发布版，无台架命令） | **338,528 B** |
| 右片（USB host 侧） | **292,624 B** |

---

## 2. 系统架构与数据通路

```
物理鼠标 ──USB──▶ 右片 ESP32-S3（host）──UART1 5 Mbaud──▶ 左片 ESP32-S3（device）──USB──▶ PC
                  makcu_hidhost / app_right                makcu_hiddev / app_left
```

链路帧固定为 `5A <cmd> <len:u16 LE> <payload…>`（UART1，TX/RX 交叉：左 TX GPIO2 / 左 RX GPIO1，5,000,000 8N1）。

三条通路各自的链路指令：

| 通路 | 右→左 | 说明 |
|---|---|---|
| 鼠标报告 | `0xA2` | 7 字节 G3M 报告（buttons + X16 + Y16 + wheel + pan） |
| 键盘报告 | `0xA2`（EP 0x82 区分） | 与鼠标同一条目，按端点区分 |
| 厂商帧（HECATE） | `0xA2`（EP 0x82，64 B，首字节 `0x04`） | 走**独立早退分支**，绝不进鼠标路径（R1.3） |
| 事件上行 | — | `0xE1` 是**左→PC**（控制口）的异步事件帧，不走片间链路 |
| 预留 | `0xB0/0xB1/0xB2` | R2 专用厂商通道（`vendor_chan.h` 已定义，默认 OFF） |

PC 侧看到的设备：`320F:706E`，**2 个 HID 接口**
—— `93` 字节报告描述符的鼠标（IN `0x81`）+ `158` 字节描述符的键盘/厂商（IN `0x82`、OUT `0x05`）。

> ⚠️ S3 上没有 OUT EP5，厂商 OUT 必须用 **`0x05`**（设备侧）/ 右片侧 `0x03`（host 侧）。

### 2.1 按键的两条"身份"链路（改代码前必须分清）

```
真实报告 ─┬─ 厂商帧(64B/0x04) ──▶ 早退分支（绝不戳印）
          └─ 鼠标报告 ──▶ btn_evt_filter（订阅/消费）──▶ 短按抗抖 ──▶ hiddev
                                    │                              │
                             事件入环/推送 0xE1          s_wire_btn_last 单一真源
                                                          （出队/引擎/主持位窗口都按它对齐）
```

- **事件订阅是纯观察者**：穿透模式（默认）下 `fwd == raw`，报告一个字节都不改。
- **`0x32` 注入会开"主持位窗口"**：窗口内只保护**被注入按住的那些键位**（D48 P1-1）；
  同键位由注入主持（连点/扳机的必要条件），物理点击请用其它键位。

---

## 3. 目录地图

```
app_left/          左片（USB device）：控制口、协议分发(0x31–0x45)、HID 上报、克隆、sumv
app_right/         右片（USB host）：枚举鼠标、0xA2 转发、EP0 隧道、下行 OUT 队列
components/        makcu_{proto,link,clone,hiddev,hidhost,mouse*,keyboard,board,dev,right,sumv}
mouse/             ★ 厂商通道（HECATE / G3M PRO）：mouse_vendor 分发 + g3mpro 协议 + vendor_chan
docs/              HANDOVER(本文) / 50-vendor-channel / API-control-port / FEATURES / 40-status / 30-decisions
tools/             构建、刷写、台架、瞄准、追踪、状态汇总脚本（见 §7）
verification/      model/(46 例离线) regress/(128 例真机) report/(按日报告) plan-*.md
官方固件/           原厂镜像 V3.2_LEFT.bin、V3.7_RIGHT.bin（回滚用，勿删）
work/              出厂备份镜像 + 回读比对中间产物
```

> `components/makcu_mouse` 是**运动引擎**（sumv/按键提交层）；`mouse/` 是**厂商通道**，两者不同名不同责。

---

## 4. 已交付模块（当前）

| 模块 | 职责 | 关键文件 |
|---|---|---|
| `makcu_proto` | 文本命令 27/27 + 二进制 0x31–0x45 | `handlers.def`、`cmd_*.c` |
| `makcu_link` | 片间帧层、`0xA0` 会话、`0xA2` 透传、`0xA5` OUT、自定义 hook 区间 | `makcu_link_bridge.c` |
| `makcu_hiddev` | TinyUSB HID（实例0 鼠标 / 实例1 键盘+厂商）、按键真源 `s_wire_btn_last`、URG 队列、厂商队列 | `makcu_hiddev.c` |
| `makcu_hidhost` | 右片主机侧：枚举、报告推送、OUT 提交（16 深队列 + 快路径） | `makcu_hidhost.c` |
| `makcu_clone` | 描述符克隆 + 身份别名 + 每台唯一序列号 | `makcu_clone.c` |
| `makcu_mouse` | 提交层：`s_buttons`、2 ms 让路窗口、短按合并、AIM/sumv 入口 | `makcu_mouse.c` |
| `makcu_sumv` | 1000 Hz 拟人移动（速度/时长/模式 + AIM 族） | `makcu_sumv.c` |
| **`mouse/`** | **厂商通道**：`g3mpro`（协议、零 I/O）+ `mouse_vendor`（按 VID/PID 分发）+ `vendor_chan`（R1 走 `0xA5`，R2 预留 `0xB0–0xB2`） | `mouse/src/*.c` |
| `app_left/main/btn_evt.c` | 按键事件：订阅 mask / 消费 / 环 32 深 / 推送 / 10 s 心跳看门狗 | `btn_evt.c` |
| `app_left/main/control_bin.c` | 二进制快速通道 + 事件推送队列（64 深）+ `evsent/evlat/evdrop` 对账 | `control_bin.c` |
| `app_left/main/app_main.c` | 初始化、通路装配、台架命令 `mx.*`、控制任务、事件发送任务 `km_evttx` | `app_main.c` |

---

## 5. 环境与构建

| 项 | 值 |
|---|---|
| IDF | **ESP-IDF v5.4.1**（`D:\esp-idf`）、工具链 `D:\esp-tools`（xtensa-esp-elf 14.2.0） |
| 目标 | ESP32-S3（两块：左 V3.2 板 / 右 V3.7 板） |
| `CONFIG_FREERTOS_HZ` | **100** ⇒ `vTaskDelay(1)` = **10 ms**（所有 tick 相关的时间换算都按这个） |

```powershell
# 台架版（带 mx.* 台架命令，日常调试用）
powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"
# 发布版（不带 mx.*）
powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=OFF,-DMB_HID_DEVICE=ON,-DMB_DUAL_IF=ON,-DMB_CLONE_FIXTURE="
# 右片
powershell -File tools\build_app.ps1 -App app_right
```

任务优先级（改动时别乱调，事件延迟就靠这条序关系）：

| 任务 | prio | 职责 |
|---|---|---|
| `usb_lib` / `usb_cli` | 12 / 11 | TinyUSB 内核 / 类驱动 |
| **`km_evttx`** | **11** | 按键事件发送（通知唤醒、立即抢占）→ 0xE1 |
| `km_outq` / `km_vout` / `km_uart0` | 10 | OUT 提交 / 厂商下行 / 控制口 |
| `km_link` | 9 | 片间链路接收（热路径，只入队不写串口） |
| `km_uart1` / `km_heal` | 8 / 4 | UART1 收 / 自愈 |

---

## 6. 刷写与回滚

```powershell
# 左片全自动（推荐）：构建 → mx.dl 进下载器 → 写 0x10000 → 整段回读比对
powershell -File tools\flash_left_auto.ps1
powershell -File tools\flash_left_auto.ps1 -NoBuild        # 只刷现有 build 产物
# 右片（右侧口换数据线：VID_303A&PID_1001 / COM10）
powershell -File tools\flash_right.ps1 -Image app_right\build\makcu_right.bin -Offset 0x10000
powershell -File tools\flash_right.ps1                      # 回滚出厂整片
# 左片回滚出厂 + 回读比对
powershell -File tools\reflash.ps1 -Port COM3
```

**刷完必须做两件事**（都踩过）：

1. 若芯片停在 ROM 下载器：`esptool --chip esp32s3 --port COM4 --before no-reset --after hard-reset read-mac`
   能直接启动；`--after hard-reset` 若打印 "Hard resetting with a watchdog…" 则**不生效**，
   此时拔插左侧数据线（3–5 s）即可。
2. **发一次 `mx.ac` 重克隆**（应回 `km.1:320f:706e:93`）。刚刷完时克隆还是台架夹具，
   此时跑回归会出现 **9 skipped**。

**故障恢复**：CH343（`VID_1A86&PID_55D3`）掉线/`PermissionError(13)` 时
`pnputil /restart-device "USB\VID_1A86&PID_55D3\5C98113502"`；节点整体消失需拔插。

> 出厂备份（不要删）：`work/hw_left_before_rebuild.bin`、`work/hw_right_full_before_patch.bin`、
> `work/right_boot_head.bin`、`官方固件/V3.2_LEFT.bin`、`官方固件/V3.7_RIGHT.bin`。

---

## 7. 台架脚本（`tools/`）

| 分组 | 脚本 | 用途 |
|---|---|---|
| 构建 | `build_app.ps1` | 唯一构建入口（`-App` / `-Clean` / `-Define`） |
| | `setup_idf.ps1`、`setup_idf_local.ps1`、`fetch_idf_submodules.py`、`fix_idf_gitmodules.py` | 新机器装环境 |
| 刷写 | **`flash_left_auto.ps1`** | 左片全自动（构建→`mx.dl`→刷→回读比对），**不需要拔线** |
| | `flash_left.ps1`、`flash_capture.ps1`、`reflash.ps1`、`flash_verify.py`、`finish_cycle.ps1` | 左片分步 / 抓日志 / 回滚 |
| | `flash_right.ps1`、`rd_right.ps1`、`recover_download.py` | 右片刷写 / 内存读 / 卡下载器恢复 |
| 台架 | `boxbench_gui.py`（+`boxbench.cmd`、`boxbench/`） | Windows 图形台架（Tkinter），`--selftest`/`--suite smoke` |
| | `link_probe.py`、`probe_control.py`、`status.py`、`p0_baseline.py`、`trace_opcodes.py` | 协议探测 / 状态汇总 / 基线 / 轨迹 |
| | `trace_motion.py`、`dt_hist.py`、`diff_insn.py` | 运动追踪 / 间隔直方图 / 指令对比 |
| 瞄准 | `aim_move.py`、`aim_stress.py`、`px_cal.py` | 到位闭环 / 并发压力 / 增益标定 |
| 验证 | `verify_buttons_usb.py`、`clone_check.ps1`、`hid_isolation.ps1`、`btn_monitor.ps1`、`tusb_debug.py`、`watch_*.ps1` | 按键环回 / 克隆检查 / 隔离 / 监视 |

---

## 8. 测试体系

```powershell
# 离线模型（无需硬件，秒级）
python -m pytest verification/model -q          # 46 passed
# 真机回归（盒子 + 中线 COM3）
$env:MAKCU_PORT='COM3'; python -m pytest verification/regress -q    # 128 passed，约 4 min
```

| 层 | 内容 | 现状 |
|---|---|---|
| T1 编译 | 双 app `idf.py build` | ✅ |
| T1' 语法 | `xtensa-esp32s3-elf-gcc -fsyntax-only` | ✅ 全部组件 |
| T2 模型 | 6 个模型文件：`test_step_engine` / `test_bezier_path` / `test_clone_descriptor` / `test_right_reply_model` / `test_button_queue_model` / `test_button_event_channel` | **46 passed** |
| T3 真机 | 12 个用例文件（+`conftest.py`）：协议 / 运动报告 / 键盘 / 按键完整性 / 按键顺序 / 按键×SUMV 并发 / **按键事件×点击** / 克隆描述符 / 隐藏 opcode / 右片帧 / 链路桥 / SUMV opcode | **128 passed** |

**光标约束**：`verification/regress/conftest.py` 里有 `CursorGuard`（20 ms 守护 + autouse 归位），
整个测试会话把主机光标钳在**屏幕右上角 240×140 安全区**内；它只动光标、不碰设备计数，
所以 `mx.rt`/`mx.rq`/`wire_chg` 之类断言不受影响。

**两条易碎断言的正确写法**（血泪）：

- "有没有丢按键"看 `0x3E.wire_chg`（上线字节真变化次数）与 `0x45` 的 `direct_chg+queued_chg`，
  不要看 `btn_in/btn_sent`（端点空闲时根本不入队，恒为 0）。
- "事件有没有丢"看 `head_seq == mx.ox.evsent`（生成 == 发出），**不要用 PC 抓串口计数**
  ——GIL/驱动缓冲会让它数到 330 或 0，而固件侧稳定 400。

---

## 9. 关键决策（D1–D48，详见 `docs/30-decisions.md`）

| 编号 | 一句话 |
|---|---|
| D29–D35 | 右片应答组件化、UART1 参数取自原厂镜像、透传注入字节序/时机、报告格式保真、克隆真实身份 |
| D36–D39 | 复合设备克隆（双 HID 接口）的两次失败模式与最终解；报告格式与身份解耦 |
| D40 | 侧键走标准鼠标键位 |
| **D41** | 按键优先：2 ms 让路窗口，允许丢弃积压运动 |
| **D42** | 按键走独立 URG 队列：满队列只计数不覆盖 + 5 ms 合并/抵消 |
| D43 | AIM 专用接口族（`0x3C/0x3D/0x40`） |
| D44 | 光标增益按常数 1.25 counts/px 建模，不做加速补偿 |
| D45 | 抖动不靠固件重整节拍，只保留观测探针（两套方案已证伪） |
| **D46** | 按键"永不丢失"的三条硬约束 |
| **D47** | 厂商通道独立化（`mouse/`）+ 五个根因修复；HECATE 不再卡（`vp50 31–39 ms`） |
| **D48** | 按键事件订阅不得吞掉物理点击；事件通知延迟 **6–8 ms → 0.12 ms**；并发零丢失 |

---

## 10. 已知问题与限制（都不影响使用）

| 项 | 现状 | 说明 / 缓解 |
|---|---|---|
| **按鼠标硬件 DPI 键，HECATE 显示不刷新** | 不做 | 接收器不推送该变化；三条修法（GET_REPORT 缓存、右片补发 SET_PROTOCOL/SET_IDLE、自动重枚举）试过并撤回。拔插左侧线（重枚举）后 HECATE 会刷新 |
| 超过 **1000 边沿/秒**时点击会少 1% | 物理上限 | HID 端点 1 kHz；此速率下事件侧仍零丢失（`head_seq == evsent`） |
| 同一键位同时被 `0x32` 注入与物理按下 | 设计如此 | 注入期间该键位由注入主持（连点/扳机必需）；物理点击请用其它键位 |
| 事件队列 64 深 | 上限 ≈6400 事件/秒 | 超过会丢事件并计 `evdrop`（正常恒 0） |
| CH343 掉线（`Problem 43`） | 可恢复 | `pnputil /restart-device`；节点消失需拔插 |
| USJ `watchdog reset` 无法启动 app | 已知 | 用 `--after hard-reset`（打印 "RTS pin" 才有效）或拔插 |
| 右片 HID 推送 gate | 关闭 | 早期"推模式"造成右片客户端任务冻结（死锁），功能已回退，`mx.hi` 的 `gate=0` 表示未启用 |
| `build/` 不入库 | — | 重跑 `tools/status.py` 前先构建 |

---

## 11. 交接检查清单

- [ ] 能构建两个 app（`tools/build_app.ps1`，台架 + 发布两套 `-Define`）
- [ ] 能刷左片（`tools/flash_left_auto.ps1`）与右片（`flash_right.ps1 -Offset 0x10000`）
- [ ] 刷完会做两件事：必要时 hard-reset/拔插 + **`mx.ac` 重克隆**
- [ ] 能跑通回归（`MAKCU_PORT=COM3`，**128 passed**；离线模型 46 passed）
- [ ] 会看四个探针：`mx.hi`（右片）、`mx.ls`（链路）、`mx.ox`（厂商+事件）、`0x3E/0x45`（按键）
- [ ] 知道 `CONFIG_FREERTOS_HZ=100` ⇒ `vTaskDelay(1)` = 10 ms
- [ ] 知道"按键字节单一真源 `s_wire_btn_last`"与"主持位窗口只保护注入位"
- [ ] 知道事件帧**不许**在 `km_link` 热路径直接写串口（会死锁）

---

## 12. 想改什么 → 改哪里（速查）

| 想改 | 改这里 | 注意 |
|---|---|---|
| 厂商（HECATE/G3M）协议字段 | `mouse/src/g3mpro.c` | 该文件**零 I/O**，只做编解码 |
| 厂商通道传输方式 | `mouse/src/vendor_chan.c` | R1 走 legacy `0xA5`；R2 切 `0xB0–0xB2` 见 `docs/50-vendor-channel.md` §12 |
| 鼠标/键盘识别分发 | `mouse/src/mouse_vendor.c` | 按 VID/PID 表 |
| 按键事件语义（穿透/消费、mask） | `app_left/main/btn_evt.c` | `consume` 只影响 `mask` 内的位 |
| 事件推送帧与队列 | `app_left/main/control_bin.c` | `CB_EVT_QD=64`；`evsent/evlat/evdrop` 在这里 |
| 事件发送任务 | `app_left/main/app_main.c`（`evt_tx_task`） | prio 11，通知唤醒；**不要**把 UART 写挪回 `km_link` |
| 按键真源/戳印/URG 队列 | `components/makcu_hiddev/src/makcu_hiddev.c` | `s_wire_btn_last`、`rep_push`、`rep_drain_one`、`passthrough` |
| 主持位窗口 | 同上（`btn_hold_bits`）+ `control_bin.c` 的 `0x32` | 只保护注入按住的位 |
| 短按抗抖 | `app_main.c`（`s_release_guard_ms`，`mx.gd`） | 默认 20 ms；`0` = 关 |
| 运动引擎/让路窗口 | `components/makcu_mouse/src/makcu_mouse.c` | `s_btn_guard_until_us`（2 ms） |
| sumv / AIM 参数 | `components/makcu_sumv/**`、`mx.mv` | `speed` 决定一切 |
| 右片下行（OUT）队列 | `app_right/main/app_main.c`、`makcu_hidhost.c` | 16 深 + 池空快路径 |
| 控制口协议/新增命令 | `components/makcu_proto/**`、`docs/API-control-port.md` | 老客户端按长度兼容 |
| 加台架探针 | `app_main.c`（`mx.*` 分支） | 台架命令**必须**以 `mx.` 开头（`.km.` 前缀会被剥掉） |

---

## 13. 参考索引

| 文档 | 用途 |
|---|---|
| [`docs/50-vendor-channel.md`](50-vendor-channel.md) | **厂商通道权威文档**：架构、五个根因、探针判据、刷机运维、撤回记录、已知限制 |
| [`docs/API-control-port.md`](API-control-port.md) | 控制口协议面（文本 + 二进制 0x31–0x45 + `mx.*` 探针 + 故障对照 + 变更记录） |
| [`docs/30-decisions.md`](30-decisions.md) | D1–D48 决策（结论/理由/证据/代码/有意不做/推翻条件） |
| [`docs/40-status.md`](40-status.md) | 由 `tools/status.py` 生成的执行状态（构建、用例、协议面统计） |
| [`docs/40-status-appendix.md`](40-status-appendix.md) | 手工维护区（按轮次小结） |
| [`docs/FEATURES.md`](FEATURES.md) | 现有功能清单（面向"有什么能力"） |
| [`docs/00-facts.md`](00-facts.md) / [`00-plan.md`](00-plan.md) / [`10-abi.md`](10-abi.md) / [`20-types.md`](20-types.md) | 事实基线 / 计划 / ABI / 类型 |
| [`verification/README.md`](../verification/README.md) | 三层验证怎么跑（含光标守卫说明） |
| `verification/report/` | 按日实测报告（含 2026-11-12 按键事件通道尝试） |
| [`HANDOVER-2026-11-13-archive.md`](HANDOVER-2026-11-13-archive.md) | 上一版交接文档（历史细节全在里面） |

---

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

> **按键不丢的上限（2026-11-12 定档，写死在这里）**
> - **保证：≤75 次/秒点击**（二进制 `0x32` 注入 + AIM 1 kHz 并发，真实设备在环）：
>   70 次/秒（700 点击 @7143 µs）**2/2 轮 1400/1400 PASS**；75 次/秒（750 @6667 µs）**2/2 轮 1500/1500 PASS**；
>   65 / 80 次/秒档最多差 **1 个边沿**（1299/1300、1599/1600，≈0.08%，方向不固定，属边界效应）。
> - 提升来自"注入主持权窗口"：`0x32 BUTTON` 时置 200 ms 主持权，窗口内透传报告的按键位对齐到
>   `s_wire_btn_last`（运动字节原样），线上只保留一个按键状态源 → 修掉了 65 次/秒整批 1.2% 的丢失。
> - 台架 `mx.lf` 文本注入在 33 次/秒时只有 118/120：差额是控制口行解析 + 环回丢的那 1~2 帧，
>   **不是固件丢键** —— 高倍率测试必须用 `--inject bin`。
> - 复核命令：
>   `python tools\verify_buttons_usb.py --clicks 750 --gap-us 6667 --inject bin --binary-sumv --sumv-period-ms 12`
>   期望 `wire_chg +1500` 且 PC 边沿 1500。
> - 压力跑完再跑回归前先 `mx.rs` 重启一次：URG/FIFO 里残留的积压会让 `wait_max` 涨到 40 ms、
>   T2 出现 +4 边沿（假阳性）。
> - **80 次/秒的边界（2026-11-12 14:1x 取证）**：800 点击 @6250 µs 实测 **1599/1600、1599/1600、1600/1600**（±1，≈0.06%）。
>   `0x45` 拆分计数显示 `direct+queued` 一轮 1601、一轮 1599，且与 `wire_chg` 恒等 →
>   是"同一个变化被算多/算少一次"的竞态（注入事件与运动/透传报告同一毫秒交错），不是整批丢。
>   已加固：① 持权窗口内 `s_buttons` 同步成线上状态；② `0x32` 改用 `makcu_mouse_emit_event()` 强制立即上线。
>   要彻底消掉这 ±1 只能回到单写者事件通道（push 只入队 + 完成回调/drain 发送）——该方向两次上机挂机，需 JTAG 日志，暂不做。
> - 想再往上推必须先改发送架构（push 只入队，由完成回调/独立 drain 任务发送），**禁止**在任务上下文
>   直接调 `tud_hid_n_report()`——2026-11-12 这么干过一次，设备复位循环、控制台卡死，救砖流程见本文件末尾。

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
| `mx.gd <0..50>` | 短按抗抖（真实鼠标释放守卫）窗口，单位 ms；**0 = 关闭**（一个按键都不少，代价是微动抖动可能表现为两次点击）。回显生效值，写 NVS 之外不持久 |
| `mx.gd`（无参数） | 只回显当前窗口值 |

> **2026-11-12 排障记录：改了 HID 发送路径导致控制台任务卡死时怎么救**
> 症状：HID 侧克隆设备仍正常枚举，但 `km.MAKCU` 不再应答、`mx.dl` 进不了下载模式。
> 救法：**拔线 → 按住 BOOT(IO0) → 插线 → 松手**，芯片停在 ROM 下载器（UART0/COM8 或 USB-JTAG/COM9），
> `esptool --chip esp32s3 --port COM8 --baud 921600 --before no_reset write_flash …` 刷回；
> 若刷完仍停在 bootloader，用 **COM9** 执行 `esptool … --before no_reset --after hard_reset flash_id`
> 触发 watchdog 复位（COM8 的 RTS 复位在这种情况下不生效）。

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
| 回归 | ✅ | **124 passed / 0 failed**（2026-11-12 口径；离线模型 46 passed） |

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
**124 passed**（跑完 `mx.if` 仍可能变 0，那是 clone 用例故意留的夹具，不影响测试结果；此段为 2026-11-10 记录，当时是 100 例）。

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
冒烟结果         : PASS            （导图 `work/boxbench_selftest.png` 已随 2026-11-12 仓库清理删除）
```

### 14.24 光标增益：为什么"速度越大越偏"（2026-11-11 标定）

**工具**：`python tools\px_cal.py --no-confirm --reps 3`（只测量）。报告见
`verification/report/2026-11-11-px-gain.md`（曲线图 `work/px_gain.png` 已随 2026-11-12 清理删除）。

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

## 15. 性能与延迟现状（2026-11-14 实测）

| 指标 | 数值 | 探针 |
|---|---|---|
| 左片报告转发率 | ≈ **570 帧/s** | `mx.ls` |
| 单条报告耗时 | p50 **10 µs** / p99 30 µs | `mx.lat`、`mx.h` |
| 右片 host 提交 | `ok` 增长、**`fail=0`** | `mx.hi` |
| 厂商通道往返 | **`vp50 31–39 ms`**，`vmax` 只见 30–40 ms 档 | `mx.ox` 的 `vp50/vp99/vmax` |
| 厂商下行 | `ofail=0`、`venq` 丢弃 0、`out==vin==vf` | `mx.ox` |
| **按键事件延迟**（边沿→写串口） | 50/200/500 次点击每秒：**平均 117–121 µs，最差 ≤169 µs** | `mx.ox` 的 `evlat` |
| 事件投递可靠性 | 1000 边沿/秒：`wire_chg == head_seq == evsent`，`evdrop=0` | `0x3E` + `mx.ev` + `mx.ox` |
| 按键永不丢失 | 70 次/秒 × 10 s、200 边沿/秒 × 数秒：边沿 2N 全达 | `0x3E`/`0x45`/`wire_chg` |

---

## 16. 时间线（便于追溯）

| 日期 | 节点 |
|---|---|
| 2026-11-09 | 逆向→重建工程定型：片间链路、协议面、克隆骨架 |
| 2026-11-10 | 双 HID 接口克隆打通（D37/D38）、身份零人工固定、控制口 921600 + 二进制通道、sumv 落地 |
| 2026-11-11 | 按键优先/独立队列（D41/D42）、AIM 族（D43）、光标增益标定（D44）、抖动证伪（D45） |
| 2026-11-12 | 按键"永不丢失"三约束（D46）；**厂商通道独立化 + 五根因（D47）**；`mx.vd`/`mx.ox` 扩展；`flash_left_auto.ps1`；174→ 回归扩到 124 例 |
| 2026-11-13 | 订阅×点击冲突修复（D48 P1）：主持位窗口按位、退订回灌、事件推送离开热路径；并发零丢失验收；事件队列 8→64 |
| **2026-11-14** | **事件通知延迟 6–8 ms → 0.12 ms**（`km_evttx` + task notification）；全量 **128 + 46 = 174 例**全绿；本文重写 |

---

## 待推进（都不阻塞交付）

1. **R2 专用厂商通道**：`0xB0/0xB1/0xB2` 与 `0xA2` 并列、独立队列，摆脱 legacy `0xA5`（方案见 `50-vendor-channel.md` §12）。
2. **`vp50` 再压**：31–39 ms → 目标 ~10 ms 档（需拆右片下行与左片等待的耦合）。
3. **同键位注入与物理点击的仲裁**：若确实需要"注入期间物理点击也生效"，需引入按键级所有权表（当前有意不做）。
4. **HECATE DPI 键同步**：按需求**不做**；若将来改需求，先读 `50-vendor-channel.md` §11 的三条已撤回方案，别再走一遍。
