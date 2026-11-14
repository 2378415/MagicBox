# MagicBox

采集卡 + MAKCU 鼠标盒子（双 ESP32-S3）的**固件重建**与**手机端 AI 瞄准**双工程仓库。

盒子在 PC 眼里就是一只与真鼠标同构的复合 HID 设备（描述符克隆自真机，`320F:706E`，两个 HID 接口）；手机 App 通过 HDMI 采集卡看 PC 画面、跑 YOLO 选目标，再把「相对位移」经 CH343 控制口下发给盒子，由盒子以 HID 报告注入。

```
              PC（游戏画面 1080p60）
                     │ HDMI
              ┌──────▼───────┐
              │  UVC 采集卡  │  MS2130（345F:2132）
              └──────┬───────┘
                     │ USB 3.x（YUY2 1080p60，实测 59.4 fps）
              ┌──────▼───────────────────────────┐
              │  手机 iQOO 15 / Android 16        │
              │  MagicBullet：采集 → YOLO/QNN → 瞄准闭环 │
              └──────┬───────────────────────────┘
                     │ USB（CH343 1A86:55D3，921600 8N1）
        ┌────────────▼─────────────┐  UART1 5 Mbaud  ┌──────────────────┐
        │ 左片 V3.2（USB device）  │◄───────────────►│ 右片 V3.7（host）│
        │ 对 PC 呈现克隆鼠标/键盘  │ 5A cmd len payload│ 接真实鼠标/键盘  │
        └────────────┬─────────────┘                 └────────┬─────────┘
                     │ USB HID（93 B 描述符，报告 7 字节）      │ USB
                     └──────────────► PC ◄────────────────────┘
                                       真实鼠标（可透传）
```

三条数据通路都已定型并发过真机验收（2026-11-14）：

| 通路 | 现状 | 判据 / 探针 |
|---|---|---|
| **鼠标透传**（右片 → 左片 → PC） | 正常，拔插自愈 | 转发 ≈570 帧/s；单条 p50 10 µs / p99 30 µs；右片 `fail=0` |
| **厂商通道**（HECATE / G3M PRO） | 识别、读配置、改 DPI 都不卡 | `out==vin==vf`、`ofail=0`、`venq` 丢弃 0、`vp50` 31–39 ms（D47） |
| **按键事件**（订阅 → 环 / 推送） | 订阅**不吞**物理点击 | 通知延迟 **117–121 µs（≈0.12 ms）**；1000 边沿/秒零丢失（D48） |

真机回归 **128 passed**，离线模型 **46 passed**，合计 **174 例**全绿。

---

## 1. 目录地图

```text
MagicBox/                            固件工程（ESP-IDF，可直接编译、可刷写、可回滚）
├── app_left/                        左片 ESP32-S3（USB device）：控制口、0x31–0x45 分发、HID 上报、克隆、sumv
├── app_right/                       右片 ESP32-S3（USB host）：枚举鼠标、0xA2 转发、EP0 隧道、下行 OUT 队列
├── components/                      11 个 makcu_* 组件（见 §2.2）
├── mouse/                           ★ 厂商通道（HECATE / G3M PRO）：mouse_vendor 分发 + g3mpro 协议 + vendor_chan
├── docs/                            HANDOVER（接手必读）/ API-control-port / 50-vendor-channel / FEATURES / 40-status / 30-decisions …
├── tools/                           构建、刷写、台架、瞄准、状态汇总脚本（41 个，见 tools/README.md）
├── verification/                    model/(6 文件 46 例) regress/(13 文件 128 例) report/(32 份上机报告) plan-*.md(4 份)
├── 官方固件/                        V3.2_LEFT.bin 403,536 B、V3.7_RIGHT.bin 341,824 B（唯一事实来源 + 回滚用，勿删）
└── work/                            出厂备份镜像与回读比对中间产物（不入库）

MagicBullet/                         Android 端（com.magicbullet.capture，v0.1）
├── app/src/main/java/…/capture/     43 个 Java 文件 / 约 10,100 行：MainActivity + core/(31) + ui/(4 Tab + 校准页) + widget/
├── app/src/main/cpp/                letterbox.cpp、postprocess.cpp（libmbpre.so）
├── app/src/main/assets/             yolov8n_int8_qdq.onnx（ModelStore.BUILTIN_ASSET）
├── app/src/test/                    12 个测试类、118 条 @Test
├── libuvc/                          vendored UVC 库（AndroidUSBCamera / saki4510t，Apache-2.0，源码编译）
├── models/                          ort-qnn-v79.aar（build.gradle 硬引用）、imported/m.onnx、量化脚本
├── docs/                            HANDOFF（接手必读）/ 瞄准模块.md / Android采集卡YOLO低延迟方案.md / 测试/瞄准模块测试方案.md
└── gradle/wrapper                   Gradle 8.13（腾讯镜像）

README.md                            本文件（两工程汇总入口）
CLEANUP.md                           2026-11-11 仓库瘦身记录（历史路径以当时为准）
LICENSE                              自有代码许可
```

> 2026-11-12 起本仓库**只保留可编译的固件工程**：早期的反向工程树（`reversed/` 3,071 函数）、Ghidra 工程、原厂协议逆向文档、`tools/rizin/` 已整体清理，`AMagicBox-Rebuild/` 这一层目录也已取消（内容就是现在的 `MagicBox/`）。

---

## 2. 盒子侧：`MagicBox/`

### 2.1 硬件与链路

| 项 | 值 |
|---|---|
| 左片 | ESP32-S3，USB **device** 侧；对 PC 呈现复合 HID（鼠标 IN `0x81` + 键盘/厂商 IN `0x82`、OUT `0x05`） |
| 右片 | ESP32-S3，USB **host** 侧；接真实鼠标/键盘，抓输入报告 |
| 片间 | UART1 **5,000,000 8N1**（左 TX=GPIO2 / 左 RX=GPIO1，交叉），帧 `5A <cmd> <len:u16 LE> <payload…>` |
| 控制口 | CH343（`1A86:55D3`），**921600 8N1**，`dtr/rts=false`；PC 与手机串口**独占**，只能接一侧 |
| 目标 / Flash | `esp32s3`，2 MB / dio / 80 MHz；分区表见 `app_left/partitions.csv`（app @ `0x10000`，1 MB 分区） |
| FreeRTOS | `CONFIG_FREERTOS_HZ=100` ⇒ `vTaskDelay(1)` = **10 ms**（所有 tick 换算按此） |

### 2.2 组件（`components/` 11 个 + `mouse/` 3 个）

| 组件 | 职责 | 关键接口 |
|---|---|---|
| `makcu_proto` | 文本命令 **27/27 opcode 全实现**（43 条命令 + 3 个跳表专用入口），回包与原厂逐字节一致 | `handlers.def`、`cmd_*.c` |
| `makcu_link` | 片间帧层：`0xA0` 会话状态机、`0xA2` 报告透传、`0xA5` OUT、`0xB0–0xB2` 自定义 hook 区间 | `makcu_link_bridge.c` |
| `makcu_hiddev` | TinyUSB HID（实例 0 鼠标 / 实例 1 键盘+厂商）、按键真源 `s_wire_btn_last`、URG 队列、厂商队列 | `makcu_hiddev.c` |
| `makcu_hidhost` | 右片主机侧：枚举、报告推送、OUT 提交（16 深队列 + 池空快路径） | `makcu_hidhost.c` |
| `makcu_clone` | 描述符克隆 + 身份别名策略 + 每台唯一序列号（NVS 持久） | `makcu_clone.c` |
| `makcu_mouse` | 运动引擎/提交层：位移守恒分步、2 ms 让路窗口、AIM/sumv 入口 | `makcu_mouse.c` |
| `makcu_sumv` | 1000 Hz 拟人移动：三次贝塞尔 + 弧长参数化、速度剖面、AIM 族 | `makcu_sumv.c` |
| `makcu_keyboard` | 键盘注入（复合 HID 第二接口） | `makcu_keyboard.c` |
| `makcu_dev` / `makcu_right` / `makcu_board` | 设备上下文（按键/轴/映射槽位）/ 右片帧语义 / 板级占位 | — |
| **`mouse/`** | **厂商通道**：`g3mpro`（协议零 I/O）+ `mouse_vendor`（VID/PID 分发）+ `vendor_chan`（R1 走 `0xA5`，R2 预留 `0xB0`） | `mouse/README.md` |
| `app_left/main/` | `app_main.c`（装配 + `mx.*` 台架命令 + 控制任务 + 事件发送任务 `km_evttx`）、`control_bin.c`（二进制通道 + 事件推送队列 64 深）、`btn_evt.c`（订阅/消费/环 32 深/10 s 心跳看门狗） | — |

### 2.3 控制口协议

**文本口**（人 / 台架）

```
发送   "." "km." <cmd+args> "\r"             "." 与 "km." 均可省略
回包   "km." <content> "\r\n>>> "            三种形态：回显整行 / 名称+状态字节 / 纯内容
```

| 类别 | 命令 |
|---|---|
| 按键 | `.km.left(1)` `.km.right(1)` `.km.middle(1)` `.km.front(1)` `.km.ms1(1)` `.km.ms2(1)`；`()` 形式为查询 |
| 锁定/捕获 | `.km.lock_mx(1)` … `.km.lock_ms2(1)`、`.km.catch_ml(1)` … |
| 移动 | `.km.move(dx,dy)`、`.km.move(dx,dy,mode)`、`.km.wheel(delta)`、`.km.silent(dx,dy)` |
| 其它 | `.km.buttons([n])`、`.km.version`、`.km.serial()` |
| 重建版扩展 | `.km.sumv(dx,dy[,speed[,mode[,dur_ms]]])`、`.km.sumv()`、`.km.sumv_stop()`、`.km.evt(1[,mask[,consume]])`、`.km.evt(0)`、`.km.evt()` |
| 台架（仅 `MB_DEBUG_OPCODE`） | `mx.fv/if/rb/hi/hz/lh/sv/ev/mv/mt/rt/rq/rp/dv/ox/hs/hv/as/ac/rs/hk/ls/lat/gd/vd/dl` |

> 未知命令**不回包**；`mx.*` 不要加 `.km.` 前缀（控制口先剥 `.km.`，剩下的才是台架命令）。

**二进制口**（交互用，真机 RTT 实测 1.1 ms）

```
+0  5A            magic（只在文本行首才能开帧）
+1  cmd
+2  seq           回包原样带回
+3  len (u16 LE)  payload ≤ 64
+5  payload[len]
+5+len  crc8      poly 0x07，覆盖 cmd..payload
回包：cmd | 0x80，seq 一致
```

| cmd | 名称 | 载荷 / 回包 | 用途 |
|---|---|---|---|
| `0x31` | MOTION_PLAN | `dx i16, dy i16, dur_ms u16, mode u8, flags u8` | 老引擎相对移动 |
| `0x32` | BUTTON | `mask u8`（1 左 2 右 4 中 8 侧后 16 侧前） | 按键位图，**强制立即上线** |
| `0x33` | WHEEL | `delta i8` | 滚轮 |
| `0x34` | QUERY | `what u8` → 计数 / 能力 / 上条计划 | 诊断 |
| `0x35` | PING | `counter u32` → 12 B | RTT 与时钟 |
| `0x36` | SUMV | `dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]` | 拟人化相对移动 |
| `0x37` | SUMV_STOP | — | 中止并保留已走部分 |
| `0x38` | SUMV_STATE | → 29 B | `active/samples/aborted/rounds/muted/fwd/speed_eff/remain` |
| `0x39` | EVT_CTL | `enable u8, mask u8, push u8 [, consume u8]` | 订阅按键（缺省**穿透**） |
| `0x3A` | EVT_READ | `count u8`(≤7) → `1 + n×8 B` | 批量取事件 / 心跳 |
| `0x3B` | EVT_STAT | → 12 B（`last_fwd`、flags bit0..3） | 通道状态 / 心跳 |
| `0x3C` | AIM | `dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]` | **瞄准专用**：必须 `max_ms` 内走完 |
| `0x3D` | AIM_STATE | → 12 B（`active`、`last_result 1..6`、`rounds`、`aborted`、`gen`） | 闭环判据 |
| `0x3E` | HID_STAT | → 16 B（`in/sent/wait/overflow/flood/merged/cancel/wire_chg`） | 按键队列统计与上线字节真变化数 |
| `0x3F` | BTN_AUDIT | → 12 B（`in_chg/out_chg/extra`） | 按键回环审计，正常 `extra=0` |
| `0x40` | AIM_RESET | — | 清 `AIM_STATE` 累计量 |
| `0x41` | EVT_RESET | — | 清事件环与统计 |
| `0x42` | LAST_HID | → 20 B（`rid,len,8B,hist[8],stamped`） | 上一条 HID 报告 |
| `0x44` | BTN_LOG | `since u16` → `total,count,count×8B` | 按键字节变化历史 |
| `0x45` | BTN_CNT | → 54 B（`link_frames/btn_nonzero/fwd_drop/swallowed/…/direct_chg/queued_chg/btn_cmds`） | 诊断计数 |
| `0xE1` | EVT_PUSH | `t_us u32, seq u16, mask u8, edge u8` | 设备主动推（异步段 `0xE0–0xEF`） |

运动类命令全部 fire-and-forget，可靠性靠 `seq` 缺口与 CRC 计数观察。逐字段说明见 [`MagicBox/docs/API-control-port.md`](MagicBox/docs/API-control-port.md)。

### 2.4 按键事件通道（D46 / D48）

- 订阅 `mask` 内的键：产生边沿事件，**同时照常转发给 PC**；`consume=1` 才把该位从转发报告里抹掉。
- `0x32` 注入会开「主持位窗口」：窗口内只保护**被注入按住的键位**（连点/扳机的必要条件）；同键位物理点击请换键位。
- 移动、滚轮永不产生事件；盒子自己发的按键也不产生事件。
- 判据：`EVT_STAT.last_fwd` 跟随 `cur` = 穿透；`cur` 有值而 `last_fwd=0` = 吃掉。
- 客户端 10 s 无心跳 → 自动退订恢复全透传（`flags` bit2）。
- 事件环 32 条、推送队列 64 深；`0xE1` 由独立任务 `km_evttx`（prio 11，task notification）发出，**不在 `km_link` 热路径写串口**（会死锁）—— 这就是 6–8 ms → 0.12 ms 的来源。
- 零丢失硬判据：`direct_chg + queued_chg == wire_chg == 2 × 点击次数`，且 `btn_cmds == 2 × 点击次数`。

### 2.5 `sumv` / `AIM` 执行器

| 项 | 值 |
|---|---|
| 采样 | 1000 Hz（`esp_timer`），`total_samples == T_ms` |
| 时长 | `D = round(hypot(dx,dy))`，`T = clamp(1000·D/speed, 40, 5000)` ms |
| 每报告上限 | `mr = clamp(12 + (speed-11000)/1000, 12, 120)`，极速用 120 |
| 路径 | 三次贝塞尔按弧长参数化；瞄准模式法向 ±span/60，拟人模式 ±span/12 + 抖动 |
| 速度剖面 | `D≤10` 单发；`≤60` 恒速；`61–300/301–800/>800` 梯形（进 6–10%、出 10–15%）；`bit6` 走 min-jerk |
| 模式位 | `bit0` 固定时长 · `bit1` 手颤 · `bit2` 子运动 · `bit5` 关粘滞 · `bit6` 拟人 · `bit7` 极速 |
| 闭环入口 | `0x3C AIM(dx,dy,max_ms,flags[,dead_min])` + `0x3D AIM_STATE`；`dead_min` 默认 2 counts 判到位（result=4） |
| 屏蔽语义 | 执行期真实鼠标 X/Y 丢弃、按键/滚轮透传、`.km.move` 被拒、新轨迹为 REPLACE |
| counts↔px | 本机常数 **1.25 px/count**（125% 缩放、无指针加速；D44） |

### 2.6 厂商通道 `mouse/`（D47）

`mouse_vendor`（按 VID/PID 挑驱动，零鼠标知识）+ `g3mpro`（**零 I/O**，帧布局/命令表/时限）+ `vendor_chan`（搬运与统计）。

| 项 | 值 |
|---|---|
| 身份 | 设备侧 `320F:706E`；接收器族 `0E8C/0ECC/06CC/068C:F0Dx`（别名映射后统一） |
| 厂商帧 | **64 B 且 `[0]==0x04`**，OUT/IN 同款；端点：主机侧 IN `0x82`/OUT `0x03`，设备侧 IN `0x82`/OUT **`0x05`**（S3 上没有 OUT EP5） |
| 心跳 | `04 aa 00 aa 00 00 00 00 ff`，约 1.2 s 一次，不等应答 |
| 配置写间隔 | 最小 **40 ms**（30 ms 丢 5–9%，40 ms 零丢） |
| DPI 流程 | `READ(02) → WRITE(35) → COMMIT(37) → 回读(02)` |
| 修掉的五个根因 | ①厂商 IN 被按键戳印 ②`0xA5` 同步等应答 ③实例 1 端点忙即丢帧 ④短按抗抖改写厂商首字节 ⑤下行池满 + tick 量化 |

五个根因、探针判据、三条已撤回方案与运维记录见 [`MagicBox/docs/50-vendor-channel.md`](MagicBox/docs/50-vendor-channel.md) 与 [`MagicBox/mouse/README.md`](MagicBox/mouse/README.md)。

### 2.7 性能实测（2026-11-14）

| 指标 | 数值 | 探针 |
|---|---|---|
| 左片报告转发率 | ≈ **570 帧/s** | `mx.ls` |
| 单条报告耗时 | p50 **10 µs** / p99 30 µs | `mx.lat`、`mx.h` |
| 右片 host 提交 | `ok` 增长、**`fail=0`** | `mx.hi` |
| 厂商往返 | `vp50` **31–39 ms**，`vmax` 只见 30–40 ms 档 | `mx.ox` |
| **按键事件延迟** | 50/200/500 次每秒：平均 **117–121 µs**，最差 ≤169 µs | `mx.ox` 的 `evlat` |
| 事件可靠性 | 1000 边沿/秒：`wire_chg == head_seq == evsent`，`evdrop=0` | `0x3E` + `mx.ev` + `mx.ox` |

---

## 3. App 侧：`MagicBullet/`

### 3.1 分层与数据流

```
UVC 帧 ─► FrameSnapshot ─► Preprocess(native letterbox) ─► YoloDetector(QNN HTP / ORT CPU)
                                                                    │
                    Postprocess/NMS ◄── 输出张量 ────────────────────┘
                            │
                    TargetTracker（头/体聚类、跳变剔除、尺寸 EMA）
                            │
                    AimPick（框大优先 + 换人三件套）→ AimController（残差→counts，自适应增益，限幅）
                            │
                    ControlPort（0x3C AIM / 0x3A EVT_READ / 0x3D 轮询 / 0x39 订阅）
                            │
                      CH343 → 左片
```

实测：采集 59.4 fps（1080p60 YUY2）、推理 6 ms（QNN HTP）、帧→结果 6–9 ms；端到端大头是采集卡 30–40 ms。

| 类 | 职责 |
|---|---|
| `ControlPort` | CH343 自定义驱动 + 921600、帧编解码 + CRC8、全部 opcode、链路断开重连、日志落盘 |
| `UvcSession` / `UvcSessionHost` / `UsbPermissionFlow` | 采集卡枚举、权限、格式协商（1080p60 YUY2 → 逐级回退）、跨 Tab 存活 |
| `YoloDetector` / `YoloPreprocess` / `YoloPostprocess` / `QnnRuntime` / `QnnContextCache` / `ModelStore` | 推理后端与模型管理、letterbox、解码与 NMS（native `libmbpre.so` 与 Java 双实现互为校验） |
| `TargetTracker` / `AimPick` / `Detection` | 头/体聚类、锚点、选敌多层排序、抢锁双门槛 + 三帧确认 |
| `AimController` / `AimMath` | 闭环：残差 px → counts、死区（4 px，可自适应 ≤12）、80% 硬限幅、单帧上限自学习 |
| `AimConfig` / `AimRect` / `RoiConfig` | 参数持久化（`aim_config`，**schema 11** 含历史迁移）、瞄准矩形、ROI |
| `HotkeyWatcher` / `HotkeyGate` / `HotkeyEdge` | 热键（EVT 订阅 + 1 Hz 心跳）、多键位图上升沿、**20 ms** 去抖（仅「按一下切换」模式） |
| `ui/preview` `ui/yolo` `ui/aim` `ui/keys` + `ui/calib` | 四个 Tab（预览 / Yolo / 键鼠 / 瞄准）+ 横屏放大校准页 |
| `widget/*` | 锁定框、预测点、准心、矩形拖拽、等比容器 |

### 3.2 默认参数（`AimConfig`，键名即 SharedPreferences 键）

| 键 | 默认 | 含义 |
|---|---|---|
| `aim_schema` | 11 | 配置版本，旧版自动迁移 |
| `speed` / `max_ms` | 1200 / 10 | 老路径 `0x36` 的 counts/s；瞄准每发时长预算 ms |
| `mode` | `0x00` | `0x40` 拟人、`0x80` 极速 |
| `px_per_count` / `max_step_counts` | 1.25 / 200 | 标定增益；单发相对限幅（自学习可调） |
| `deadzone` / `auto_deadzone` | 4 px / 开 | 死区及其自学习 |
| `stable_frames` / `switch_frames` | 3 / 3 | 锁定确认帧数、换目标确认帧数 |
| `hotkey` / `hold` / `hotkey_consume` | `0x02` / 关 / 关 | 热键位图（右/侧后可组合）、按住生效、默认**穿透** |
| `head_anchor_bias` / `prefer_centered_head` / `center_tolerance` | 1.0（下巴）/ 开 / 1% | 头部锚点与居中优先 |
| `size_gate` / `size_delta` / `size_ema` | 1.12 / 1% / 30% | 反抢锁三件套的尺寸门槛、绝对差、EMA |
| `session_clamp` / `turbo` / `release_stop` / `volume_key` | 关 / 关 / 开 / 开 | 会话钳位、极速、松手停、音量键触发 |

配置落在 `shared_prefs/aim_config.xml`（`adb shell run-as com.magicbullet.capture cat …`），页尾「保存配置」整页生效，高级区支持导出/导入 `aim_config.json`。

### 3.3 测试

- 单测：`app/src/test/**` **12 个类 / 118 条 `@Test`**（`AimPick`(31)、`TargetTracker`(12)、`AimMath*`、`HotkeyGate`(11)、`HotkeyEdge`、`AimRect`、`RoiConfig`、`FrameSnapshot`、`YoloSettings`、`Postprocess`）。
- 台架/真机台账（PT-xx / FT-xx 与 `control.log` 拉取命令）见 [`MagicBullet/docs/测试/瞄准模块测试方案.md`](MagicBullet/docs/测试/瞄准模块测试方案.md)。

### 3.4 已知风险（App 侧，详见 `docs/HANDOFF.md` §9）

| 编号 | 问题 | 影响 |
|---|---|---|
| R-1 | `sendFrame` 持锁同步 `bulkTransfer`（超时 200 ms）且在推理线程上 | USB 抖动时整条闭环卡 200 ms |
| R-2/R-4 | 无「轨迹飞行中抑制」、无收尾微调律 | 过冲后可能反向对撞；精度天花板 = 死区 |
| R-3 | 瞄点无时间平滑（只对框尺寸做 EMA） | 检测框抖动直接印到落点 |
| R-5 | SUMV 与 AIM 共用同一条「当前轨迹」通道 | 键鼠页发 SUMV 时被 AIM 帧 REPLACE |
| R-7 | 去抖窗口 20 ms 已贴近机械抖动下限 | 抖得厉害的鼠标可能「一次点击切两次」 |

---

## 4. 接口速查

| 链路 | 物理层 | 协议 | 定义位置 |
|---|---|---|---|
| 手机 ↔ 左片控制口 | CH343 USB-Serial，**921600 8N1** | 文本 `.km.*` + 二进制 `0x31–0x45 / 0xE1`，`5A cmd seq len crc8` | [`API-control-port.md`](MagicBox/docs/API-control-port.md)、`app_left/main/control_bin.h`、`ControlPort.java` |
| 左片 ↔ 右片 | 片间 UART1，**5 Mbaud** | `5A cmd len:u16 payload`（`0xA0/0xA2/0xA5`，预留 `0xB0–0xB2`） | `components/makcu_link/`、`mouse/README.md` |
| 右片 → 真鼠标 | USB Host | HID 输入报告 + EP0 隧道 + OUT 提交 | `components/makcu_hidhost/` |
| 左片 → PC | USB Device（TinyUSB） | 93 B 描述符鼠标（报告 7 B）+ 158 B 键盘/厂商接口 | `components/makcu_hiddev/` |
| 采集卡 → App | USB Video Class | UVC YUY2 / MJPEG | `MagicBullet/libuvc/` |
| App 内部 | JNI | `libmbpre.so`（letterbox + postprocess） | `app/src/main/cpp/` |

上位机集成检查清单（12 条：CRC 自检、首条命令重试、心跳、独占串口）见协议文档 §10。

---

## 5. 开发环境

| 侧 | 项 | 值 |
|---|---|---|
| 固件 | ESP-IDF | **v5.4.1**（`D:\esp-idf`），工具链 `xtensa-esp-elf` **14.2.0_20241119**（`D:\esp-tools`），Python venv `idf5.4_py3.11_env` |
| 固件 | 额外变量 | `ESP_IDF_VERSION=5.4.1`、`ESP_ROM_ELF_DIR=D:\esp-idf\components\esp_rom\esp32s3`、`IDF_SKIP_CHECK_SUBMODULES=1`；CMake 必须 **< 4** |
| App | JDK / 语言级 | 本机 JDK **21**（`D:\Apply\Java\ms-21.0.9`，不在 PATH，构建时设 `JAVA_HOME`）；源码 `sourceCompatibility 17` |
| App | 构建栈 | Gradle **8.13**（腾讯镜像）、AGP 8.8.2、`compileSdk 35` / `targetSdk 35` / `minSdk 28`、`abiFilters arm64-v8a`、`versionName 0.1` |
| App | 依赖 | `androidx.appcompat 1.7.0`、`fragment 1.8.5`、`material 1.12.0`、`files("models/ort-qnn-v79.aar")`、`com.qualcomm.qti:qnn-runtime:2.42.0`、`project(':libuvc')` |
| 硬件 | 手机 / 采集卡 / 桥 | iQOO 15（V2505A，Android 16，SD 8 Elite，QNN `htp_arch=79`）/ 海备思 CA1331·UHC10（MS2130）/ CH343 |
| 硬件 | PC 显示 | 2560×1600、缩放 125%（DPI-unaware 进程看到 2048×1280）、**关闭「提高指针精确度」**（否则 counts↔px 不是常数 1.25） |

`MagicBox/tools/build_app.ps1` 已把上述 IDF 变量固定，**不要绕过它直接跑 `idf.py`**。

---

## 6. 构建 / 刷写 / 安装

```powershell
# ===== 固件 =====
cd MagicBox
# 发布版（不带 mx.* 台架命令；本仓库 Release 里就是这个）
powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=OFF,-DMB_HID_DEVICE=ON,-DMB_DUAL_IF=ON,-DMB_CLONE_FIXTURE="
# 台架版（带 mx.* 台架命令，日常调试/跑回归用）
powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"
# 右片（USB host 侧）
powershell -File tools\build_app.ps1 -App app_right
# 产物：app_left\build\makcu_left.bin、app_right\build\makcu_right.bin

# ===== 刷写 / 回滚（左片不需要拔线） =====
powershell -File tools\flash_left_auto.ps1                 # 构建 → mx.dl 进下载器 → 写 0x10000 → 整段回读比对
powershell -File tools\flash_left_auto.ps1 -NoBuild        # 只刷现有 build 产物
powershell -File tools\flash_right.ps1 -Image app_right\build\makcu_right.bin -Offset 0x10000
powershell -File tools\flash_right.ps1                     # 右片回滚出厂整片
powershell -File tools\reflash.ps1 -Port COM3              # 左片回滚出厂 + 回读比对

# ===== App =====
cd ..\MagicBullet
$env:JAVA_HOME='D:\Apply\Java\ms-21.0.9'
.\gradlew.bat :app:testDebugUnitTest      # 118 项单测
.\gradlew.bat :app:assembleDebug          # → app\build\outputs\apk\debug\app-debug.apk（≈94 MB，含模型与 ORT）
adb install -r app\build\outputs\apk\debug\app-debug.apk
```

刷完左片**必须做两件事**：①若芯片停在 ROM 下载器，用 `esptool --port COM4 --before no-reset --after hard-reset read-mac` 拉起（不生效就拔插一次）；②发一次 `mx.ac` 重克隆（应回 `km.1:320f:706e:93`），否则回归会 9 skipped。

CH343 掉线（`Problem 43` / `PermissionError(13)`）：`pnputil /restart-device "USB\VID_1A86&PID_55D3\5C98113502"`；节点消失需拔插。

---

## 7. 验证口径

| 层 | 工具 | 现在能跑吗 | 说明 |
|---|---|---|---|
| T1 编译 | `tools\build_app.ps1` 双 app | ✅ 需 IDF 环境 | 本次发布即由此构建 |
| T1' 语法 | `xtensa-esp32s3-elf-gcc -fsyntax-only` | ✅ | 全部组件 |
| T2 离线模型 | `python -m pytest verification/model -q` | ✅ 无需硬件 | 6 文件 **46 passed**（步进引擎、贝塞尔、克隆描述符、右片回复、按键队列模型、事件通道调度） |
| T3 真机回归 | `MAKCU_PORT=COM3 python -m pytest verification/regress -q` | 需台架 | 13 文件 **128 passed**（≈4 min；含按键完整性/顺序、按键×SUMV 并发、按键事件×点击、链路桥、隐藏 opcode） |
| T3' 无硬件 | `MAKCU_SKIP_HW=1 … --collect-only` | ✅ | 只收集不执行 |
| App 单测 | `gradlew :app:testDebugUnitTest` | ✅ | **118 项** |

```powershell
cd MagicBox
python -m pytest verification\model -q
$env:MAKCU_PORT='COM3'; python -m pytest verification\regress -q
python tools\aim_stress.py        # 并发 AIM + 按键压力（判据见 HANDOVER §14.25）
python tools\link_probe.py --all  # PING/QUERY/SUMV/EVT 一次性探针
```

`verification/regress/conftest.py` 里的 `CursorGuard` 会把整个测试会话的主机光标钳在屏幕右上角 240×140 安全区（只动光标、不碰设备计数）。

---

## 8. 发布产物

最新：[`v0.2.0`](https://github.com/2378415/MagicBox/releases/tag/v0.2.0)　首次发布：[`v0.1.0`](https://github.com/2378415/MagicBox/releases/tag/v0.1.0)

| 资产 | 字节 | 内容 |
|---|---:|---|
| `makcu_left.bin` | 338,544 | 左片**发布版**固件（无 `mx.*` 台架命令） |
| `makcu_left-bench.bin` | 见 Release | 左片**台架版**固件（含 `mx.*` 探针，跑回归用） |
| `makcu_right.bin` | 292,624 | 右片固件（USB host 侧） |
| `bootloader-left.bin` / `bootloader-right.bin` | 18,912 | ESP32-S3 二级引导 |
| `partition-table-left.bin` / `partition-table-right.bin` | 3,072 | 分区表 |
| `MagicBullet-0.1-debug.apk` | 93,904,529 | App debug 包（含内置模型与 ORT/QNN） |
| `SHA256SUMS.txt` | — | 全部资产校验和 |

刷写地址与参数：

```
esptool --chip esp32s3 -b 921600 --flash_mode dio --flash_size 2MB --flash_freq 80m \
  write_flash 0x0 bootloader-*.bin 0x8000 partition-table-*.bin 0x10000 makcu_*.bin
```

原厂镜像对照：LEFT 403,536 B / RIGHT 341,824 B。重建镜像体积不同属预期（浮点贝塞尔曲线用观测等价实现替代，IDF 版本与裁剪项也与原厂构建不完全一致）。

---

## 9. 已知限制与待推进（都不阻塞交付）

| 项 | 现状 |
|---|---|
| 按鼠标**硬件 DPI 键**，HECATE Connect 显示不刷新 | **不做**：接收器不推送该变化，三条修法（GET_REPORT 缓存、右片补发 SET_PROTOCOL/SET_IDLE、自动重枚举）试过并撤回；拔插左侧线后即刷新 |
| 超过 **1000 边沿/秒** 点击会少约 1% | HID 端点物理上限（1 kHz）；事件侧仍零丢失 |
| 同键位同时被 `0x32` 注入与物理按下 | 设计如此：注入期间该键位由注入主持（连点/扳机必需） |
| 右片 HID 推送 gate | 关闭（早期推模式导致右片任务死锁，已回退，`mx.hi` 的 `gate=0`） |
| 待推进 | R2 专用厂商通道（`0xB0–0xB2`）、`vp50` 再压到 ~10 ms、同键位所有权表、App 侧控制口写入异步化（解 R-1）、收尾微调律（解 R-4） |
| `MagicBullet/README.md` 仍是「UVC 预览 Demo」口径 | 已被 `MagicBullet/docs/HANDOFF.md` 取代，以 HANDOFF 为准 |

---

## 10. 文档索引

| 主题 | 文档 |
|---|---|
| 固件接手必读（现状/架构/构建刷写/测试/坑位） | [`MagicBox/docs/HANDOVER.md`](MagicBox/docs/HANDOVER.md)（1,182 行；§14 为历史运行手册） |
| 固件文档导航与权威边界 | [`MagicBox/docs/README.md`](MagicBox/docs/README.md) |
| 控制口协议（最能看的一篇） | [`MagicBox/docs/API-control-port.md`](MagicBox/docs/API-control-port.md) |
| 厂商通道（HECATE / G3M PRO） | [`MagicBox/docs/50-vendor-channel.md`](MagicBox/docs/50-vendor-channel.md)、[`MagicBox/mouse/README.md`](MagicBox/mouse/README.md) |
| 现有功能清单 / 执行状态 / 决策 D1–D48 | [`FEATURES.md`](MagicBox/docs/FEATURES.md)、[`40-status.md`](MagicBox/docs/40-status.md)、[`30-decisions.md`](MagicBox/docs/30-decisions.md) |
| 事实基线 / 计划 / ABI / 结构 | [`00-facts.md`](MagicBox/docs/00-facts.md)、[`00-plan.md`](MagicBox/docs/00-plan.md)、[`10-abi.md`](MagicBox/docs/10-abi.md)、[`20-types.md`](MagicBox/docs/20-types.md) |
| 三层验证怎么跑 / 台架脚本 | [`MagicBox/verification/README.md`](MagicBox/verification/README.md)、[`MagicBox/tools/README.md`](MagicBox/tools/README.md) |
| App 接手必读 | [`MagicBullet/docs/HANDOFF.md`](MagicBullet/docs/HANDOFF.md) |
| App 瞄准模块主文档（设计与迭代史） | [`MagicBullet/docs/瞄准模块.md`](MagicBullet/docs/瞄准模块.md) |
| App 低延迟方案 / 测试方案 | [`Android采集卡YOLO低延迟方案.md`](MagicBullet/docs/Android采集卡YOLO低延迟方案.md)、[`测试/瞄准模块测试方案.md`](MagicBullet/docs/测试/瞄准模块测试方案.md) |
| 仓库瘦身记录 | [`CLEANUP.md`](CLEANUP.md) |

---

## 11. 常见坑

| 现象 | 原因 / 处理 |
|---|---|
| 发命令没回包 | 未知命令不回包；确认 921600；首条命令重试 2–3 次（上电约 1 s 才应答） |
| 二进制帧全被丢 | CRC（poly 0x07，覆盖 `cmd..payload`）或 `len` 字段错；`5A` 只能在文本行首开帧 |
| 光标不动 | `mx.rb` 的 `bytes` 与服务描述符不符（应为 `bytes=7 desc=93`）→ 主机静默丢弃 |
| 移动比请求少 | 撞到屏幕边界后多发的 counts 被系统吃掉，不回补 → 用 `tools/aim_move.py` 闭环到位 |
| 一顿一顿 | 用了 `.km.move`（127 分块）而不是 `sumv`/`AIM` |
| 热键点进游戏 | `EVT_CTL` 缺 `consume`：默认**穿透**，要吃掉必须 `consume=1` |
| 盒子 10 s 后自己退订 | 订阅期没发心跳（`EVT_READ`/`EVT_STAT`/`PING`），属设计行为 |
| `mx.*` 无反应 | 用的是发布版固件（`MB_DEBUG_OPCODE=OFF`），台架命令只在台架版里 |
| PC 与手机同时连控制口 | 串口独占，必须中间转发 |
| 构建报 `CMakeCache.txt … different than the directory` | 仓库目录搬过家（原 `D:\JinPeng`）→ 删掉 `app_left/build`、`app_right/build` 重新构建 |
| `gradlew` 报 `JAVA_HOME is set to an invalid directory` | `cmd` 里 `set JAVA_HOME=…` 后面带空格；用 `set "JAVA_HOME=D:\Apply\Java\ms-21.0.9"` |
| 校准差 25% | DPI-unaware 进程看到的是逻辑像素；标定工具先 `SetProcessDpiAwareness(2)` |
| App 启动崩溃 `dlopen failed` | `libuvc` 预编译 `.so` 为 4 KB 对齐，16 KB page size 内核需用 NDK 重编并加 `-Wl,-z,max-page-size=16384` |

---

## 12. 许可

根目录 [LICENSE](LICENSE) 适用于自有代码；`MagicBullet/libuvc` 来自 [AndroidUSBCamera](https://github.com/jiangdongguo/AndroidUSBCamera)（Apache-2.0，子目录保留原声明）；`MagicBullet/models/ort-qnn-v79.aar` 为基于 ONNX Runtime 1.29.0 的自编译产物（MIT）；`MagicBox/docs` 中对原厂固件的行为分析属互操作研究记录。
