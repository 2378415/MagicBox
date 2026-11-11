# MagicBox

采集卡 + MAKCU 鼠标盒子（双 ESP32-S3）的**固件逆向重建**与**手机端 AI 瞄准**工程。

盒子对外是 PC 眼里的普通鼠标/键盘（描述符从真鼠标克隆），对内由手机 App 通过采集卡看 PC 画面、跑 YOLO 检测目标，再经控制口把相对位移下发给盒子，由盒子以 HID 报告的形式注入。

```
                PC（游戏画面）
                     │ HDMI 1920x1080@60
              ┌──────▼───────┐
              │  UVC 采集卡  │  MS2130（345F:2132）
              └──────┬───────┘
                     │ USB 3.x（YUY2 1080p60）
              ┌──────▼───────────────────────────┐
              │  手机 iQOO 15 / Android 16        │
              │  MagicBullet：UVC→YOLO/QNN→AIM    │
              └──────┬───────────────────────────┘
                     │ USB（CH343 1A86:55D3，921600 8N1）
        ┌────────────▼─────────────┐   UART1 片间链路   ┌──────────────────┐
        │ 左片 V3.2（设备侧 HID）  │◄──────────────────►│ 右片 V3.7（主机侧）│
        │ 对 PC 呈现鼠标/键盘      │  5A cmd len payload │ USB Host 接口     │
        └────────────┬─────────────┘                     └────────┬─────────┘
                     │ USB HID（7 字节报告，描述符克隆）           │ USB
                     └──────────────► PC ◄───────────────────────┘
                                       真实鼠标（可选，透传/被屏蔽）
```

- **左片 V3.2**：设备侧。克隆真鼠标描述符对 PC 呈现 HID，执行 `sumv`/`AIM` 轨迹，转发或屏蔽真实鼠标输入。
- **右片 V3.7**：主机侧。作 USB Host 接真实鼠标，抓报告经 UART1 送给左片。
- **CH343 中线**：接左片 UART0，就是**控制口**（PC 或手机接其一，串口独占）。
- 本仓库只含源码、文档与构建必需二进制；清理明细见 [CLEANUP.md](CLEANUP.md)。
- 预编译产物见 Release：[v0.1.0](https://github.com/2378415/MagicBox/releases/tag/v0.1.0)（左/右片固件 + 引导与分区表 + MagicBullet debug APK + SHA256SUMS）。

---

## 1. 仓库结构

```text
MagicBox/                              逆向工作区（只读事实 + 重建产物）
├── 官方固件/
│   ├── V3.2_LEFT.bin                  403,536 B  左片原厂镜像（唯一事实来源）
│   ├── V3.7_RIGHT.bin                 341,824 B  右片原厂镜像
│   ├── *.strings.json                 字符串 → 虚拟地址（tools 生成）
│   └── *.xref.json                    代码 → 字面量 → 字符串（tools 生成）
├── 官方固件命令协议.md                  43 条原厂文本命令、opcode 跳表、二进制帧路由
├── 官方固件未公开协议.md                13 个无文本入口的隐藏 opcode 与可达性结论
├── 官方固件逆向分析报告.md              总报告：分区、模块划分、迭代结论
├── reversed/                          Ghidra 反编译产物（不可编译，导航用）
│   ├── src/                           3,071 个函数，每函数一个 <地址>_<名字>.c
│   ├── include/                       26 个模块头 re_<image>_<module>.h
│   ├── docs/                          reading_paths / function_index / uart1_link / known_gaps …
│   ├── manual/                        手工重建的跳表入口
│   ├── raw_left/ raw_right/           Ghidra dump JSON（build_project.py 的输入）
│   └── CMakeLists.txt                 仅源码枚举，明确不产固件
├── tools/                             重建流水线
│   ├── patch_excw.py                  812 处 excw → 同寄存器 no-op（另存 .nop.bin）
│   ├── esp_to_elf.py                  ESP32 段表 → 六段 ELF
│   ├── ghidra_scripts/DumpAll.java    headless 批量反编译
│   ├── merge_patched.py               补丁 dump 合并回主 dump
│   ├── build_project.py               聚类 + 生成源码树/头/索引文档
│   ├── fill_gaps.py / make_renames_doc.py
│   ├── verify_excw.py / find_excw.py  补丁只动 excw 的校验与统计
│   └── flash/send_cmd.py              经 CH343 发命令
├── backups/probe/                     真机读回的 boot/partition/app 切片
└── AMagicBox-Rebuild/                 固件重建工程（ESP-IDF，可编译、可刷写）
    ├── app_left/                      左片应用 + 控制口（main/）
    ├── app_right/                     右片应用（纯转发）
    ├── components/                    11 个组件（见 §2.1）
    ├── docs/                          API-control-port.md、HANDOVER.md、00-facts … 40-status
    ├── tools/                         构建/刷写/台架脚本（build_app.ps1、diff_insn.py、lib_fingerprint.py、aim_stress.py、aim_move.py、link_probe.py、px_cal.py、boxbench）
    └── verification/                  三层验证：regress(pytest)、model、report

MagicBullet/                           Android 端（com.magicbullet.capture）
├── app/src/main/
│   ├── java/com/magicbullet/capture/
│   │   ├── MainActivity.java          导航 + 生命周期
│   │   ├── core/                      采集/推理/瞄准/控制口（见 §3.1）
│   │   ├── core/post/                 后处理：Geometry / Nms / Postprocess
│   │   ├── ui/{preview,yolo,aim,keys,calib,placeholder}/
│   │   └── widget/                    AimRectView、DetectionOverlayView、CalibView、RoiPickerView …
│   ├── cpp/                           letterbox.cpp、postprocess.cpp（libmbpre.so）
│   ├── assets/yolov8n_int8_qdq.onnx   内置模型（ModelStore.BUILTIN_ASSET）
│   └── res/                           布局与字符串（瞄准页 fragment_aim.xml 41 KB）
├── app/src/test/java/…/core/          12 个测试类（115 条 @Test）
├── libuvc/                            vendored UVC 库（AndroidUSBCamera / saki4510t，Apache-2.0）
├── models/                            ort-qnn-v79.aar（构建硬引用）、imported/m.onnx、量化脚本
├── docs/                              Android采集卡YOLO低延迟方案.md、瞄准模块.md、测试/瞄准模块测试方案.md
└── gradle/wrapper                     Gradle 8.13（腾讯镜像）
```

---

## 2. 固件侧：`AMagicBox-Rebuild`

### 2.1 组件划分（`components/`）

| 组件 | 职责 | 关键接口 |
|---|---|---|
| `makcu_proto` | 文本协议：49 条命令表、前缀匹配、回包格式、opcode 分派、`handlers.def` 生成的跳表 | `makcu_lookup()`、`makcu_reply_status()`、`cmd_*.c`（17 个 handler 文件） |
| `makcu_dev` | 设备上下文：按键/轴/通道/映射槽位（与固件偏移对齐） | `makcu_buttons_set/get()`、`makcu_axis_slot()`、`makcu_map_write()` |
| `makcu_mouse` | 运动引擎与转发：位移累计、1 kHz 注入、按键优先队列、让路窗口、审计 | `makcu_mouse_submit_delta()`、`makcu_mouse_button_priority()`、`makcu_mouse_forward()` |
| `makcu_sumv` | 拟人化/瞄准轨迹执行器：三次贝塞尔 + 弧长参数化、DDA、`AIM` 入口、看门狗 | `makcu_sumv_start()`、`makcu_sumv_aim()`、`makcu_sumv_aim_state()` |
| `makcu_hiddev` | 设备侧 TinyUSB HID：报告发送、按键专用队列、`0x3E/0x3F` 统计、键盘报告 | `makcu_hiddev_report()`、`makcu_hiddev_button_stats()`、`makcu_hiddev_btn_history()` |
| `makcu_hidhost` | 主机侧 USB Host：枚举真鼠标、抓输入报告、控制传输、延迟直方图 | `makcu_hidhost_info()`、`makcu_hidhost_raw_device()`、`makcu_hidhost_stats32()` |
| `makcu_clone` | 描述符克隆与身份策略：VID/PID 别名、序列号、报告描述符采纳 | `makcu_clone_adopt()`、`makcu_clone_apply_id_policy()`、`makcu_clone_serial_get()` |
| `makcu_link` | 片间 UART1：`5A cmd len:u16 payload` 成帧、流式解析、EP0 隧道、分块回放 | `makcu_link_build()`、`makcu_link_parser_feed()`、`makcu_link_send()` |
| `makcu_right` | 右片帧语义：快照/配置/错误帧的组装与回复 | `makcu_right_reply()` |
| `makcu_keyboard` | 键盘注入（隐藏 API） | `makcu_keyboard_init()` |
| `makcu_board` | 板级端口占位（仅导出 `makcu_board_port_surface`） | — |

`app_left/main/`：`app_main.c`（初始化 + 控制口读循环 + autoclone 护栏）、`control_bin.c`（二进制快速通道与 CRC8）、`btn_evt.c`（按键事件环、边沿算法、pending、10 s 失联看门狗）、`btn_trace.c`（按键追踪日志）。
`app_right/main/`：`app_main.c`（UART1 解析 → EP0/A3/快照/配置分派）。

### 2.2 文本协议（人 / 台架用）

```
发送   "." "km." <cmd+args> "\r"             "." 与 "km." 均可省略
回包   "km." <content> "\r\n>>> "            三种形态：回显整行 / 名称+状态字节 / 纯内容
```

| 类别 | 命令 |
|---|---|
| 按键 | `.km.left(1)` `.km.right(1)` `.km.middle(1)` `.km.front(1)` `.km.ms1(1)` `.km.ms2(1)`；`()` 形式为查询 |
| 轴/键锁定 | `.km.lock_mx(1)` `.km.lock_my(1)` `.km.lock_ml(1)` `.km.lock_mr(1)` `.km.lock_mm(1)` `.km.lock_ms1(1)` `.km.lock_ms2(1)` |
| 通道捕获 | `.km.catch_ml(1)` … `.km.catch_ms2(1)` |
| 移动/滚轮 | `.km.move(dx,dy)`、`.km.move(dx,dy,mode)`、`.km.wheel(delta)`、`.km.silent(dx,dy)` |
| 其它 | `.km.buttons([n])`、`.km.version`、`.km.serial()` |
| 重建版扩展 | `.km.sumv(dx,dy[,speed[,mode[,dur_ms]]])`、`.km.sumv()`、`.km.sumv_stop()`、`.km.evt(1[,mask[,consume]])`、`.km.evt(0)`、`.km.evt()` |
| 台架（仅 `MB_DEBUG_OPCODE`） | `mx.fv/if/rb/hi/hz/lh/sv/ev/mv/mt/rt/rq/rp/dv/ox/hs/hv/as/ac/rs/hk/ls` |

> 未知命令**不回包**；`mx.*` 不要加 `.km.` 前缀（控制口先剥 `.km.`，剩下的才是台架命令）。

### 2.3 二进制协议（交互用，RTT 实测 1.1 ms）

```
+0  5A            magic（只在文本行首才能开帧）
+1  cmd
+2  seq           回包原样带回
+3  len (u16 LE)  payload ≤ 64
+5  payload[len]
+5+len  crc8      poly 0x07，覆盖 cmd..payload
回包：cmd | 0x80，seq 一致
```

| cmd | 名称 | payload / 回包 | 用途 |
|---|---|---|---|
| `0x31` | MOTION_PLAN | `dx i16, dy i16, dur_ms u16, mode u8, flags u8` | 老引擎相对移动 |
| `0x32` | BUTTON | `mask u8`（1 左 2 右 4 中 8 侧后 16 侧前） | 按键位图 |
| `0x33` | WHEEL | `delta i8` | 滚轮 |
| `0x34` | QUERY | `what u8` → 18/12/18 B | 计数 / 能力 / 上条计划 |
| `0x35` | PING | `counter u32` → 12 B | RTT 与时钟 |
| `0x36` | SUMV | `dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]` | 拟人化相对移动 |
| `0x37` | SUMV_STOP | — | 立即停 |
| `0x38` | SUMV_STATE | → 29 B | 状态与计数 |
| `0x39` | EVT_CTL | `enable u8, mask u8, push u8 [, consume u8]` | 订阅按键（缺省**穿透**） |
| `0x3A` | EVT_READ | `count u8`(≤7) → `1 + n×8 B` | 批量取事件 / 心跳 |
| `0x3B` | EVT_STAT | → 12 B（`last_fwd`、`flags` bit0..3） | 通道状态 / 心跳 |
| `0x3C` | AIM | `dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]` | **瞄准专用**：必须 `max_ms` 内走完 |
| `0x3D` | AIM_STATE | → 12 B（`active`、`last_result 1..6`、`rounds`、`aborted`、`gen`） | 闭环判据 |
| `0x3E` | HID_STAT | → 10 B（`btn_in/btn_sent/wait_max_us/overflow/flood`） | 按键队列统计 |
| `0x3F` | BTN_AUDIT | → 12 B（`in_chg/out_chg/extra`） | 按键回环审计，正常 `extra=0` |
| `0x40` | AIM_RESET | — | 清 `AIM_STATE` 累计量 |
| `0x41` | EVT_RESET | — | 清事件环与统计 |
| `0x42` | LAST_HID | → 10 B（`rid,len,8B`） | 上一条 HID 报告 |
| `0x44` | BTN_LOG | 请求 `since u16` → `total u16,count u8,count×8B` | 按键字节变化历史 |
| `0x45` | BTN_CNT | → 16 B（`link_frames/btn_nonzero/fwd_drop/swallowed`） | 诊断计数 |
| `0xE1` | EVT_PUSH | `t_us u32, seq u16, mask u8, edge u8` | 设备主动推（异步段 `0xE0–0xEF`） |

运动类命令全部 fire-and-forget，可靠性靠 `seq` 缺口与 CRC 计数观察（`QUERY what=0`）。

### 2.4 按键事件通道语义（2026-11-11 起默认穿透）

- 订阅 `mask` 内的键：产生边沿事件，**同时照常转发给 PC**；`consume=1` 才把该位从转发报告里抹掉。
- 移动、滚轮永不产生事件；盒子自己发的按键也不产生事件。
- 判据看 `EVT_STAT.last_fwd`：穿透 → 跟随 `cur`；吃掉 → `cur` 有值而 `last_fwd` 保持 `0x00`。
- 客户端 10 s 无心跳 → 自动退订恢复全透传（`flags` bit2）。
- 事件环 32 条，溢出覆盖最旧，`seq` 不回绕；推模式只走异步通道，环只服务 `EVT_READ`。

### 2.5 `sumv` / `AIM` 执行器

| 项 | 值 |
|---|---|
| 采样 | 1000 Hz（`esp_timer`），`total_samples == T_ms` |
| 时长 | `D = round(hypot(dx,dy))`，`T = clamp(1000·D/speed, 40, 5000)` ms |
| 每报告上限 | `mr = clamp(12 + (speed-11000)/1000, 12, 120)`，极速用 120 |
| 路径 | 三次贝塞尔按弧长参数化；瞄准模式法向 ±span/60，拟人模式 ±span/12 + 抖动 |
| 速度剖面 | `D≤10` 单发；`≤60` 恒速；`61–300/301–800/>800` 梯形（进 6–10%、出 10–15%）；`bit6` 走 min-jerk |
| 模式位 | `bit0` 固定时长 · `bit1` 手颤 · `bit2` 子运动 · `bit5` 关粘滞 · `bit6` 拟人 · `bit7` 极速 |
| 闭环入口 | `0x3C AIM(dx,dy,max_ms,flags[,dead_min])` + `0x3D AIM_STATE`；`dead_min` 默认 2 counts 内判到位（result=4） |
| 屏蔽语义 | 执行期真实鼠标 X/Y 丢弃、按键/滚轮透传、`.km.move` 被拒、新 `sumv` 为 REPLACE |
| counts↔px | 本机常数 **1.25 px/count**（125% 缩放、无指针加速） |

> 完整语义、实测表与故障对照见 [docs/API-control-port.md](MagicBox/AMagicBox-Rebuild/docs/API-control-port.md)（774 行，11 节）。

---

## 3. App 侧：`MagicBullet`

### 3.1 分层与数据流

```
UVC 帧 ──► FrameSnapshot ──► Preprocess(native letterbox) ──► YoloDetector(QNN/ORT CPU)
                                                                    │
                        Postprocess/NMS ◄── 输出张量 ────────────────┘
                                │
                        TargetTracker（聚类/粘滞/头部锚点 AimPick）
                                │
                        AimController（残差 → counts，自适应增益，限幅）
                                │
                        ControlPort（0x3C AIM / 0x3A EVT_READ / 0x3D 轮询）
                                │
                          CH343 → 盒子
```

| 类 | 文件 | 职责 |
|---|---|---|
| `ControlPort` | `core/ControlPort.java` | USB 串口（CH343 自定义驱动 + 921600）、帧编解码、CRC、`sumv/aim/evt/hidStat/btnAudit/aimReset`、日志落盘 |
| `UvcSession` / `UsbPermissionFlow` | `core/` | 采集卡枚举、权限、格式协商（1080p60 YUY2 → 逐级回退）、`Surface` 绑定 |
| `YoloDetector` / `YoloConfig` / `YoloSettings` / `ModelStore` / `QnnRuntime` | `core/` | 推理后端（QNN HTP / ONNX Runtime CPU）、模型导入与 profile、上下文缓存 |
| `YoloPreprocess` / `YoloPostprocess` / `core/post/*` | `core/`, `cpp/` | letterbox、解码、NMS（native 与 Java 双实现互为校验） |
| `TargetTracker` / `AimPick` / `Detection` | `core/` | 目标聚类、粘滞、帧间跳变剔除、头部锚点（居中优先 + 下沿 bias） |
| `AimController` / `AimMath` | `core/` | 闭环控制：残差→counts、自校准增益、死区/单帧限幅自学习、断流看门狗 |
| `AimConfig` / `AimRect` / `RoiConfig` | `core/` | 参数持久化（`aim_config` + `aim_schema` 版本迁移）、画面矩形、ROI |
| `HotkeyWatcher` / `HotkeyGate` / `HotkeyEdge` | `core/` | 音量键/鼠标侧键热键（EVT 订阅）、150 ms 去抖、多键位图边沿判定 |
| `PipelineStats` / `Labels` / `ModelProfile` | `core/` | 帧耗时与吞吐统计、类别名、模型 profile |
| `PreviewFragment` / `AimFragment` / `YoloFragment` / `KeyboardMouseFragment` / `AimCalibActivity` | `ui/` | 四个 Tab + 横屏放大校准页 |
| `AimRectView` / `DetectionOverlayView` / `CalibView` / `RoiPickerView` / `AspectRatioFrameLayout` | `widget/` | 锁定框、预测点、准心、矩形拖拽、等比容器 |

### 3.2 默认参数（`AimConfig`，键名即 SharedPreferences 键）

| 键 | 默认 | 含义 |
|---|---|---|
| `aim_schema` | 10 | 配置版本，旧版自动迁移 |
| `speed` | 1200 | counts/s（老路径 `0x36` 用；瞄准走 `max_ms`） |
| `max_ms` | 10 | 每发 AIM 的时长预算 |
| `mode` | `0x00` | `0x40` 拟人、`0x80` 极速 |
| `px_per_count` | 1.25 | 标定增益 |
| `max_step_counts` | 200 | 单发相对限幅（自学习可调，手填为上界） |
| `lead_ms` | 30 | 前馈提前量 |
| `hotkey` / `hotkey_consume` / `hold` | `0x02` / false / false | 热键位图（右/侧后/侧前可组合）、默认穿透、按下切换 |
| `stable_frames` / `track_min` / `switch_frames` | 3 / 3 / 3 | 锁定确认帧数、最小轨迹帧、换目标确认帧数 |
| `deadzone` / `auto_deadzone` | 4 px / true | 死区及其自学习 |
| `auto_gain` / `auto_maxstep` | true / true | 增益与单帧限幅自学习 |
| `gain_adapt_hip` / `gain_adapt_ads` / `ads_bucket` | — | 腰射/开镜分桶增益 |
| `head_anchor_bias` / `prefer_centered_head` / `center_tolerance` | 1.0 / true / 0.03 | 头部锚点（下沿）、居中优先、容差 |
| `stick_target` / `size_gate` / `size_reach` / `size_delta` / `size_ema` | true / 1.12 / — | 目标粘滞与尺寸过滤 |
| `rect_x/y/w/h` / `aim_offset_x/y` | — | 瞄准矩形（归一化）与准心偏移 |
| `session_clamp` / `release_stop` / `turbo` / `volume_key` / `show_pred` / `labels` | — | 会话位移钳位、松手停、极速、音量键、预测点、类别名 |

配置文件落在应用私有目录的 `shared_prefs/aim_config.xml`，可用 `adb shell run-as com.magicbullet.capture cat …` 查看。

### 3.3 测试

- 单测：`app/src/test/**` 12 个类、**115 条 `@Test`**（`AimMath*`、`AimPick*`、`AimRect`、`HotkeyEdge`、`HotkeyGate`、`TargetTracker`、`FrameSnapshot`、`RoiConfig`、`YoloSettings`、`Postprocess`）。
- 台架/真机用例清单与判定方式见 [docs/测试/瞄准模块测试方案.md](MagicBullet/docs/测试/瞄准模块测试方案.md)（PT-01…/FT-01…，含 `control.log` 拉取命令）。

```powershell
cd MagicBullet
.\gradlew.bat :app:testDebugUnitTest      # 回归门槛：全绿
.\gradlew.bat :app:assembleDebug          # APK → app\build\outputs\apk\debug\
```

---

## 4. 接口速查：谁跟谁说话

| 链路 | 物理层 | 协议 | 定义位置 |
|---|---|---|---|
| 手机 ↔ 左片控制口 | CH343 USB-Serial，**921600 8N1**，DTR/RTS 不拉高 | 文本 `.km.*` + 二进制 `0x31–0x45 / 0xE1`，`5A cmd seq len crc8` | `docs/API-control-port.md`、`app_left/main/control_bin.h`、`MagicBullet/.../ControlPort.java` |
| 左片 ↔ 右片 | 片间 UART1（板载） | `5A cmd len:u16 payload`（EP0 隧道 / A2 报告 / A3 标志 / 快照 / 配置） | `components/makcu_link/`、`reversed/docs/uart1_link.md` |
| 右片 → 真鼠标 | USB Host | HID 输入报告（含 `0xA2` 转发路径） | `components/makcu_hidhost/` |
| 左片 → PC | USB Device（TinyUSB） | HID 鼠标 7 字节报告 + 键盘报告，描述符克隆真机 | `components/makcu_hiddev/`、`usb_descriptors.c` |
| 采集卡 → App | USB Video Class | UVC YUY2/MJPEG | `libuvc/` |
| App 内部 | JNI | `libmbpre.so`（letterbox + postprocess） | `app/src/main/cpp/` |

上位机集成检查清单（12 条，含 CRC 自检、首条命令重试、心跳、独占串口）见协议文档 §10。

---

## 5. 开发环境

### 5.1 固件（ESP-IDF）

| 项 | 值 |
|---|---|
| ESP-IDF | **v5.4.1**，`D:\esp-idf`（`tools/setup_idf.ps1` 可一键复现） |
| 工具链 | `xtensa-esp-elf` **esp-14.2.0_20241119**，`D:\esp-tools\tools\xtensa-esp-elf\…\bin` |
| Python | IDF 自建 venv `D:\esp-tools\python_env\idf5.4_py3.11_env` |
| CMake / Ninja | pip 安装，**CMake 必须 < 4**（IDF 5.4 用了 4.0 删除的 `file(TO_CMAKE_PATH)` 两参形式） |
| 额外环境变量 | `ESP_IDF_VERSION=5.4.1`、`ESP_ROM_ELF_DIR=D:\esp-idf\components\esp_rom\esp32s3`、`IDF_SKIP_CHECK_SUBMODULES=1` |
| esptool | 5.6.0（`python -m esptool --chip esp32s3`） |
| 目标 | `esp32s3`，flash 大小 2 MB / dio / 80 MHz（刷写按 `partitions.csv`） |

`tools/build_app.ps1` 就是为这套手工环境写的封装：它固定上述环境变量后再调 `idf.py`，**不要绕过它直接跑 `idf.py`**。

### 5.2 App（Android）

| 项 | 值 |
|---|---|
| JDK / Java 语言级 | 17 |
| Android Gradle Plugin | 8.8.2 |
| Gradle | 8.13（`distributionUrl` 指腾讯镜像） |
| compileSdk / targetSdk / minSdk | 35 / 35 / 28 |
| NDK / CMake | 外部构建 `3.31.6`，`-DANDROID_STL=c++_static`，`abiFilters arm64-v8a` |
| 依赖 | `androidx.appcompat 1.7.0`、`fragment 1.8.5`、`material 1.12.0`、`files("models/ort-qnn-v79.aar")`、`com.qualcomm.qti:qnn-runtime:2.42.0`、`project(':libuvc')` |
| `local.properties` | 需本地写 `sdk.dir=…`（已 gitignore） |

### 5.3 硬件

| 项 | 值 |
|---|---|
| 手机 | iQOO 15 / V2505A / Android 16（Snapdragon 8 Elite，QNN `htp_arch=79`） |
| 采集卡 | 海备思 CA1331 / UHC10（MS2130，`345F:2132`），1080p60 YUY2 |
| 控制口桥 | CH343（`1A86:55D3`），与采集卡同挂一个 Hub |
| 盒子 | 左片 V3.2（设备侧）+ 右片 V3.7（主机侧），中线 CH343 既当控制口也当 ROM 下载口 |
| PC 显示 | 2560×1600 面板、缩放 125%（DPI-unaware 进程看到 2048×1280）、**关闭“提高指针精确度”**（否则 counts↔px 不是常数 1.25） |

---

## 6. 构建与刷写

```powershell
# 固件
cd MagicBox\AMagicBox-Rebuild
.\tools\build_app.ps1 -App app_left            # 或 app_right；-Clean 先删 build
.\tools\build_app.ps1 -App app_left -Action "-p COM8 flash"     # 直接刷
.\tools\flash_left.ps1 -Action backup          # 先整片读 4 MB 备份
.\tools\flash_left.ps1 -Action flash           # 编译 + 刷
.\tools\flash_left.ps1 -Action verify          # 回读校验
.\tools\flash_left.ps1 -Action restore         # 一键还原原厂镜像

# App
cd MagicBullet
.\gradlew.bat :app:assembleDebug
adb install -r app\build\outputs\apk\debug\app-debug.apk
```

注意事项：刷写前把中线 CH343 **从手机拔回 PC**；若上一个 GUI 实例（pythonw）还握着串口，会 `PermissionError`，先结束它；进下载模式用台架命令 `mx.dl`。

---

## 7. 验证与回归口径

| 层 | 工具 | 现在能跑吗 | 说明 |
|---|---|---|---|
| T1 编译 | `idf.py build`（经 `build_app.ps1`） | 需 IDF 环境 | 两个 app 各编一次 |
| T1' 语法 | `xtensa-esp32s3-elf-gcc -fsyntax-only` | 能 | 组件源码全部通过 |
| T2 协议 | `pytest verification/regress` | 需真机（`MAKCU_PORT`，默认 COM8） | 无硬件时 `MAKCU_SKIP_HW=1` 只收集；9 个文件 65 条用例 |
| T3 相似度 | `AMagicBox-Rebuild/tools/diff_insn.py` | 能 | 自比 1.000，`cmd_move` vs `cmd_wheel` 0.364 |
| P0 基线 | `AMagicBox-Rebuild/tools/lib_fingerprint.py compare` | 需 IDF `.map` | 偏差 ≥5% 才允许开始移植 |
| App 单测 | `gradlew :app:testDebugUnitTest` | 能 | 115 条 `@Test` |

```powershell
cd MagicBox\AMagicBox-Rebuild
python -m pytest verification\regress -q                     # 真机（端口由 MAKCU_PORT 指定）
$env:MAKCU_SKIP_HW='1'; python -m pytest verification\regress -q --collect-only
python tools\aim_stress.py                                   # 瞄准压力：并发 AIM + 按键，判据见 HANDOVER §14
python tools\link_probe.py --all                             # PING/QUERY/SUMV/EVT 一次性探针
```

---

## 8. 逆向工作区（`MagicBox/` 根）

从官方镜像到可读源码树的最小复现链：

```powershell
python tools\patch_excw.py both                                  # 812 处 excw → no-op，另存 work\*.nop.bin
python tools\esp_to_elf.py work\V3.2_LEFT.nop.bin work\V3.2_LEFT.nop.elf
analyzeHeadless <ghidra> makcu_nop -import work\V3.2_LEFT.nop.elf `
    -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_left
python tools\merge_patched.py                                    # 合并补丁 dump
python tools\build_project.py                                    # 聚类 + 生成 reversed/src|include|docs
python tools\fill_gaps.py                                        # 17 个兜底函数生成对齐汇编块
python tools\make_renames_doc.py
```

> `work/`（中间产物，约 700 MB）与 `tools/rizin/`（反汇编器）已按 [CLEANUP.md](CLEANUP.md) 清理出库；需要时按上面命令重建，或从 `D:\JinPeng\MagicBox` 复制。`reversed/` 是反编译重建，**不可直接编译**，`CMakeLists.txt` 只做源码枚举。

---

## 9. 常见坑

| 现象 | 原因 / 处理 |
|---|---|
| 发命令没回包 | 未知命令不回包；确认波特率 921600；首条命令重试 2–3 次（设备上电约 1 s 才应答） |
| 二进制帧全被丢 | CRC 算法（poly 0x07，覆盖 `cmd..payload`）或 `len` 字段错 |
| 光标不动 | `mx.rb` 的 `bytes` 与服务描述符不符（应为 `bytes=7 desc=93`）→ 主机静默丢弃 |
| 移动比请求少 | 撞到屏幕边界后多发的 counts 被系统吃掉，不回补 → 用 `AMagicBox-Rebuild/tools/aim_move.py` 闭环到位 |
| 一顿一顿 | 用了 `.km.move`（127 分块）而不是 `sumv`/`AIM` |
| 热键点进游戏 | `EVT_CTL` 缺 `consume` 语义搞反：默认**穿透**，要吃掉必须 `consume=1` |
| 盒子 10 s 后自己退订 | 订阅期没发心跳（`EVT_READ`/`EVT_STAT`/`PING`），属设计行为 |
| `.km.lfx …` 无反应 | 台架命令是 `mx.xxx`，`mx.lfx` 才有效 |
| PC 与手机同时连控制口 | 串口独占，必须中间转发 |
| App 启动崩溃 `dlopen failed` | `libuvc` 预编译 `.so` 为 4 KB 对齐，16 KB page size 内核需用 NDK 重编并加 `-Wl,-z,max-page-size=16384` |
| 校准差 25% | DPI-unaware 进程看到的是逻辑像素；写标定工具先 `SetProcessDpiAwareness(2)` |

---

## 10. 文档索引

| 主题 | 文档 |
|---|---|
| 固件工程（组件 / 控制口 / 构建刷写） | [MagicBox/AMagicBox-Rebuild/README.md](MagicBox/AMagicBox-Rebuild/README.md) |
| App 工程（功能 / 参数 / 排查） | [MagicBullet/README.md](MagicBullet/README.md) |
| 控制口协议（最能看的一篇） | [MagicBox/AMagicBox-Rebuild/docs/API-control-port.md](MagicBox/AMagicBox-Rebuild/docs/API-control-port.md) |
| 固件交接与逐轮状态 | [HANDOVER.md](MagicBox/AMagicBox-Rebuild/docs/HANDOVER.md)、[40-status.md](MagicBox/AMagicBox-Rebuild/docs/40-status.md)、[30-decisions.md](MagicBox/AMagicBox-Rebuild/docs/30-decisions.md) |
| 原厂协议与隐藏 opcode | [官方固件命令协议.md](MagicBox/官方固件命令协议.md)、[官方固件未公开协议.md](MagicBox/官方固件未公开协议.md) |
| 逆向总报告 / 阅读路径 | [官方固件逆向分析报告.md](MagicBox/官方固件逆向分析报告.md)、[reversed/docs/reading_paths.md](MagicBox/reversed/docs/reading_paths.md) |
| 片间 UART1 | [reversed/docs/uart1_link.md](MagicBox/reversed/docs/uart1_link.md) |
| App 低延迟方案 / 瞄准模块 | [Android采集卡YOLO低延迟方案.md](MagicBullet/docs/Android采集卡YOLO低延迟方案.md)、[瞄准模块.md](MagicBullet/docs/瞄准模块.md) |
| App 测试方案 | [测试/瞄准模块测试方案.md](MagicBullet/docs/测试/瞄准模块测试方案.md) |
| 仓库清理记录 | [CLEANUP.md](CLEANUP.md) |

---

## 11. 许可

本仓库根目录 [LICENSE](LICENSE) 适用于自有代码；`MagicBullet/libuvc` 来自 [AndroidUSBCamera](https://github.com/jiangdongguo/AndroidUSBCamera)（Apache License 2.0），其子目录保留原许可声明；`models/ort-qnn-v79.aar` 为基于 ONNX Runtime 1.29.0 的自编译产物，遵循其原许可（MIT）。
