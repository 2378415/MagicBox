# 交接文档 — AMagicBox-Rebuild（MAKCU 左片固件重建）

> 更新：2026-11-09 19:53（Asia/Shanghai，`verification/report/2026-11-09-flash-run-14.md`）
> 适用范围：`D:\JinPeng\MagicBox\AMagicBox-Rebuild` 整个项目
> 阅读顺序建议：本文 §1→§4 足够接手，§5 以后是操作手册与坑位清单

---

## 1. 一句话现状

**协议层已 100% 重建并逐字节对拍通过；HID 鼠标 + 键盘 + 运动（分步/曲线）已能真实驱动主机；片间 UART1 桥接已通（自环验证）；描述符克隆已完整闭环——主机侧 `VID_046D&PID_C077` 与 `HID-compliant mouse` 均为 OK，设备侧 `mnt=1`。板子在线（CH343 = COM3）。**

| 模块 | 状态 | 证据 |
|---|---|---|
| 命令协议层（43 条文本命令 / 27 个 opcode） | ✅ 完成（13 个隐藏 opcode 已实测闭环） | 回归全绿；隐藏 opcode 的回包 + 副作用见 report run-16 |
| 运动（提交队列 + int8 分步 + 贝塞尔弯曲） | ✅ 完成（数值非逐位） | `test_mouse_reports.py` + `mx.rt` 守恒断言 + `tools/cursor_test.ps1` |
| HID 上报（复合设备：ID1 鼠标 / ID2 键盘） | ✅ 完成 | Windows 枚举 `HID-compliant mouse` + `HID Keyboard Device` |
| 键盘输出（down/up/tap/type/批量/combo/state） | ✅ 完成 | `test_keyboard_reports.py` 7 例 |
| 片间 UART1 桥接（`0xA0`/`0xA2`/`0xA3`） | ✅ 帧层 + `0xA0` 会话状态机 + `0xA2` 上报透传（真机端到端） | `test_link_bridge.py` 10 例；report run-17 |
| **右片（host 侧）** | ⚠️ 帧应答完成（`0xA0/0xA1/0xA3/0x1A/0xA4/0xB1` + 错误帧），USB host 栈未移植 | `components/makcu_right/`、`app_right/`；`mx.rf` 交叉验证 9 例；report run-18 |
| 描述符克隆（P5） | ✅ 枚举闭环（本轮打通） | `mx.dv` → `mnt=1`；主机 `046D:C077` + `HID-compliant mouse` OK；SET_CONFIGURATION 通过、`HID opened` |
| 序列号读写 | ❌ 空实现 | `makcu_serial_read_hook` 未接，`serial()` 恒回失败文案 |
| P0 同构编译基准 | ❌ 未达标 | 严格指令哈希 7/816 = 0.9% |

---

| **端到端透传（真鼠标 → PC 光标）** | ✅ 完成（2026-11-09 实测） | `hid=injected` 1:1、`hs 0 failed`；位移/按键/滚轮用户实测正常；report run-21~23 |
| **克隆身份（运行时自动）** | ✅ 完成（2026-11-09 实测） | 上电经 `0xA1` EP0 隧道读真鼠标描述符再枚举；`mx.as=1`、PC 侧身份与真鼠标一致；report run-23 §6 |

## 2. 项目定位

从**静态逆向**（Ghidra + 手工重建）出发，重写 MAKCU 鼠标盒**左片（V3.2 设备侧）**固件，使其：

1. 对外协议与出厂固件**逐字节一致**；
2. 内部实现可用 ESP-IDF v5.4.1 正常编译、烧录、运行；
3. 每个厂商函数都有"原始地址 ↔ 重建函数"的对应关系，可追溯、可回归。

逆向工程本体在 `D:\JinPeng\MagicBox\reversed\`（3072 个函数，17 个兜底汇编，121 个已命名），
本仓库是**独立的新工程**，不依赖逆向目录即可编译（只有验证脚本会去读它）。

---

## 3. 目录地图

```
AMagicBox-Rebuild/
├─ docs/                    设计文档（先看这三个）
│   ├─ 00-plan.md           目标、分层策略（L1/L2/L3）、验证分级 T1/T2/T3/P0
│   ├─ 00-facts.md          从镜像/硬件测到的硬事实（地址、分区、版本串…）
│   ├─ 10-abi.md            handler ABI（窗口调用、参数顺序、回包封装）
│   ├─ 20-types.md          数据结构与偏移（dev/tbl/desc 布局）
│   ├─ 30-decisions.md      决策记录 D1–D23（含被推翻的假设）
│   ├─ 40-status.md         **自动生成**的执行状态（由 tools/status.py 产出）
│   └─ HANDOVER.md          本文
├─ components/
│   ├─ makcu_proto/         命令协议层：命令表、opcode 表、解析、回包、27 个 handler
│   ├─ makcu_dev/           设备上下文（tbl/desc 偏移、槽位、通道/轴/映射表读写）
│   ├─ makcu_mouse/         提交队列 + 分步 + 曲线 + 报告环形 trace
│   ├─ makcu_keyboard/      6KRO 键盘状态机 + 8 字节报告
│   ├─ makcu_hiddev/        TinyUSB 设备栈 + 复合描述符 + 报告发送（带互斥）
│   ├─ makcu_clone/         克隆身份仓库（RTC no-init 保存）
│   ├─ makcu_link/          片间帧层（5A 帧）+ UART1 桥接任务
│   ├─ makcu_hidhost/       空壳（左片不用，占位）
│   └─ makcu_board/         板级占位
├─ app_left/                左片应用（app_main.c 是入口，含台架夹具命令）
│   ├─ main/app_main.c      控制台、帧分发、debug 夹具（mx.*）
│   └─ managed_components/  espressif__tinyusb（托管组件，勿手改）
├─ verification/
│   ├─ regress/             pytest 上机回归（79 + 4 例）
│   ├─ model/               离线模型测试（分步引擎、曲线路径）
│   └─ report/              每次上机记录 + 原始日志
└─ tools/                   构建/烧录/验证脚本（见 §7；含历史一次性补丁脚本）
```

逆向工程侧参考：`reversed/docs/uart1_link.md`（帧格式定稿）、`reversed/docs/known_gaps.md`、
`reversed/symbol_names.py`（121 个命名）、`tools/diff_insn.py`（指令相似度）。

---

## 4. 已完成的模块与关键实现

### 4.1 命令协议层（`makcu_proto`）

- 27 个 opcode 全部实现（含 3 个只在跳表里的入口 `cmd_map_entry` / `cmd_serial` / `cmd_nop`）；
- 命令表 43 行由 `tools/extract_tables.py` 从镜像 `0x3C03DF74` 导出，opcode 跳表在 `0x3C03DF08`；
- 回包统一走 `makcu_reply_*`，`buttons(` 系列归一成 `buttons()`（复刻 `cmd_reply_status`）；
- `handlers.def` 是唯一真相：每行 `opcode 名字 implemented|todo`，改完跑 `tools/extract_tables.py` 重新生成 `makcu_cmd.h`。

### 4.2 运动（`makcu_mouse`）

- 复刻 `mouse_submit_default` / `wheel_submit` / `pulse_move` 的 pending 状态与任务唤醒；
- int8 报告上限按 `127` 分步，最大余数/余量摊分保证**步进之和 == 请求值**；
- 曲线：二次贝塞尔，控制点 = 中点 + 垂直偏移（`±span/8` 随机），`span<8` 保持直线；
- `mx.rq` 读回最近 16 份报告（按时间序），主机会话里可断言"怎么拆的"。

> 与原厂的差别是**数值**（原函数用随机旋转角 + 双精度 cos/sin 缓动，690 条指令，Ghidra 反编译中途 `halt_baddata`），
> 形状等价、逐位不等价。要逐位一致必须啃下 `0x4200EFEC` 的浮点数学。

### 4.3 HID（`makcu_hiddev` + `makcu_keyboard`）

- 复合 HID：Report ID 1 = 鼠标（buttons/dx/dy/wheel），ID 2 = 键盘（modifiers + 6 usages）；
- 报告发送**加锁**（鼠标任务与键盘路径共享同一端点）；
- 引脚冲突：ESP32-S3 的 USB-Serial-JTAG 与 OTG **共用 D+/D-**，所以 `MB_HID_DEVICE=1` 时自动关闭 JTAG 控制台，控制口只剩 UART0/CH343。

### 4.4 片间链路（`makcu_link`）

- 帧格式 `5A <cmd> <len:u16> <payload>`（`reversed/docs/uart1_link.md` §6 定稿）；
- `0xA0` EP0 隧道（计数+方向）、`0xA2` HID 数据块（按端点重组）、`0xA3` 单字节；
- 台架用 `uart_set_loop_back()` 自环验证整链（构帧→线上→解析→派发→重组）；
- **引脚是占位**：`MAKCU_LINK_TX=17 / RX=18`，真实引脚未恢复，可用 `-D` 覆盖。

### 4.5 克隆（`makcu_clone`）

- 身份仓库：`device[18]` + `config[128]` + `report[128]` + `report_id` + 三字符串，存 **RTC no-init**（跨软复位保留）；
- 四个描述符回调优先返回克隆值；配置块必须在运行时生成（HID 类块里带着报告描述符长度）；
- **描述符是逐字节敏感的**：`build_config()` 必须严格是 `9+9+9+7 = 34`，HID 类块只能是 9 字节。
  多一个字节（曾经多一个 `0x00`）→ 主机按 `bLength` 走链时在偏移 27 遇到 `bLength=0` → 找不到端点 →
  `URB_SELECT_CONFIGURATION` 返回 `USBD_STATUS_INVALID_PARAMETER` → Windows `Problem 10`、`mnt=0`。
  `verification/model/test_clone_descriptor.py` 现在专门守这条；
- 报告发送遵循克隆描述符的 Report ID 约定：`report_id == 0`（克隆鼠标常见）时发裸报告，
  内置复合描述符才用 ID 1/2（克隆激活时不发键盘报告）；
- 台架：`mx.cl` / `mx.cl 2` / `mx.cc`，`-DMB_CLONE_FIXTURE=1` 可开机即克隆；
- `mx.dv` 打印交还主机的原始字节 + `init/mnt` 标志，是排查枚举问题的第一手证据。

---

## 5. 环境与构建

| 项 | 值 |
|---|---|
| IDF | `D:\esp-idf`（gitee 镜像 v5.4.1 + codeload 补子模块，见 D11） |
| 工具链 | `D:\esp-tools`（xtensa-esp-elf 14.2.0 / python 环境 `idf5.4_py3.11_env`） |
| `ESP_IDF_VERSION` | `5.4.1`（必须显式设置） |
| CMake | **必须 <4**（4.x 移除了两参 `file(TO_CMAKE_PATH)`）→ `pip install "cmake<4"` |
| 托管组件 | `app_left/main/idf_component.yml` 依赖 `espressif/tinyusb`，已下载到 `managed_components/` |

**从零装机（换机/重装时用这个，不要在空机上直接跑 build_app.ps1）**：

```powershell
pwsh -File tools\setup_idf_local.ps1          # gitee 源码 + codeload 子模块 + 工具链 + venv
```

装完还有四个必须知道的前提（本轮全踩过，报告 run-14 §1）：

1. `D:\esp-tools\espidf.constraints.v5.4.txt` 要存在（venv 手工建时不会生成），否则 cmake 报
   “forgotten to run the install scripts”；
2. `idf-component-manager` 必须是 **2.x**（`pip install "idf-component-manager<3"`）；3.x 拒收
   IDF 传来的 `--interface_version 3`；
3. 构建前置 `$env:IDF_SKIP_CHECK_SUBMODULES='1'`，否则 IDF 的 `git_submodules.cmake` 会去 gitee
   拉子模块并 FATAL；
4. 2026-11-09 起本仓库的 `makcu_board` / `makcu_hidhost` 各有一个占位头文件——`INCLUDE_DIRS`
   指向不存在的目录会让 CMake 直接失败。

**外部工具清单（2026-11-09 实测已装/仍缺）**：

| 类别 | 工具 | 状态 | 用途 |
|---|---|---|---|
| 构建 | ESP-IDF v5.4.1 + `xtensa-esp-elf 14.2.0` + `cmake<4` + `ninja` | ✅ 已装 | 编译 |
| 构建 | `ccache 4.10.2` | ✅ 已装（`build_app.ps1` 里 `CCACHE_ENABLE=0`，要提速自行改） | 增量编译加速 |
| 烧录 | `esptool 5.6`（在 IDF venv 里） | ✅ | `reflash.ps1` / `flash_capture.ps1` |
| 回归 | 系统 Python 3.11 + `pytest` + `pyserial` | ✅ | `verification/` |
| 调试 | `openocd-esp32 0.12.0`、`xtensa-esp-elf-gdb`、`esp-rom-elfs` | ✅ 已装，**JTAG 已实测打通**（report run-15） | JTAG 单步（验 `excw`、隐藏 opcode、EP0/UART1 时序） |
| 逆向 | Ghidra 12.2（`D:\Apply\Ghidra`）+ JDK 21（`D:\Apply\Java\ms-21.0.9`，`JAVA_HOME` 已写入用户环境） | ✅ 已装（headless 已验证） | 静态分析、`0x4200EFEC` 逐位保真 |
| 网络 | `github.com` 直连不通 | ✅ 有替代 | IDF 源码走 gitee；工具链走 `dl.espressif.com/github_assets`；Ghidra 走 v2rayN 代理 `127.0.0.1:10809` |
| **硬件** | **USB 协议分析仪** | ❌ 缺 | 抓出厂固件的鼠标报告序列 → 唯一能验证 Bezier 逐位一致的证据源 |
| **硬件** | **逻辑分析仪** | ❌ 缺 | 抓 RIGHT↔LEFT 的 UART1 真实引脚与帧时序（现引脚是占位 17/18） |
| 硬件 | JTAG 探针 | 不需要 | ESP32-S3 自带 USB-JTAG；**仅控制台构建（`-DMB_HID_DEVICE=OFF`）可用**（HID 构建里 OTG 占了 D+/D−） |

**JTAG 用法（已实测，report run-15）**：

```powershell
# 1) 控制台构建 + 烧录
powershell -File tools\build_app.ps1 -App app_left -Clean -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=OFF"
powershell -File tools\flash_capture.ps1 -Port COM3 -Seconds 3

# 2) 连 openocd（Windows 需先给 &MI_02 补设备接口 GUID，见 run-15 §2）
D:\esp-tools\tools\openocd-esp32\v0.12.0-esp32-20241016\openocd-esp32\bin\openocd.exe `
  -s <...>\share\openocd\scripts -f board/esp32s3-builtin.cfg -c "init"

# 3) gdb
xtensa-esp32s3-elf-gdb app_left\build\makcu_left.elf
  (gdb) target remote :3333
  (gdb) monitor halt
  (gdb) print s_dev.buttons_mode
  (gdb) monitor reset run        # 收尾必须让核跑起来再 detach
  (gdb) detach
```

> 收尾别漏：`detach` 前不 `reset run`，核停在 halt，串口和 `mx.dl` 都不再响应（板子看起来“死”）。

> T3 工具（`tools/diff_insn.py`、`t3_report.py`、`lib_fingerprint.py`）原先写死
> `D:\Apply\toolchains\...\objdump.exe`，换机后必挂；2026-11-09 起改为自动探测
> （`MAKCU_TOOLCHAIN_BIN` → 旧路径 → `D:\esp-tools\tools\xtensa-esp-elf\<ver>\...`）。

构建命令（**唯一推荐入口**）：

```powershell
# 控制台构建（HID 关闭，USB-Serial-JTAG 可用；日常迭代用它）
powershell -NoProfile -ExecutionPolicy Bypass -File tools\build_app.ps1 `
    -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=OFF"

# HID 构建（复合鼠标+键盘）
powershell -NoProfile -ExecutionPolicy Bypass -File tools\build_app.ps1 `
    -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON"

# 开机即克隆身份（台架）
powershell -NoProfile -ExecutionPolicy Bypass -File tools\build_app.ps1 -App app_left -Clean `
    -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=1"
```

构建选项（`app_left/CMakeLists.txt`）：

| 选项 | 默认 | 作用 |
|---|---|---|
| `MB_HID_DEVICE` | ON | 枚举为 USB HID；开启后关闭 JTAG 控制台（共用 D+/D-） |
| `MB_DEBUG_OPCODE` | OFF | 暴露 `mx.*` 台架命令（**发布固件必须 OFF**，见 D17） |
| `MB_CLONE_FIXTURE` | 空 | 开机装载克隆身份 1 或 2（台架） |
| `MB_TUSB_DEBUG` | 空 | TinyUSB 日志级别（1/2/3），排查枚举问题用。**该构建不能跑回归**（日志会串进回包，见 §10.3）；本轮已把它真正传给 TinyUSB 库（`app_left/main/CMakeLists.txt` 用 `target_compile_definitions`，原先只在 `main` 目录作用域生效、日志恒为空） |

> **坑（已修，别回退）**：`-Define` 必须按逗号拆回多个参数。经 `powershell -File` 调用时数组会被拼成
> `"ON,-DMB_HID_DEVICE=OFF"`，CMake 当成一个 `-D`，导致 `MB_HID_DEVICE` 恒为缓存值 —— 这也是"CDC 一直不枚举、
> 每次都要按 BOOT"的真正原因（D22）。

---

> **烧录后必须重新插拔右片的鼠标**（2026-11-09 实测，踩了多轮）：每次烧录/复位左片，
> 右片（原厂固件，未改动）会把已插着的鼠标丢掉并置 `state=ff`，且不会自动重新枚举；
> 必须把鼠标拔下等 2 秒再插回，`mx.ln a0` 回到 `00` 后链路才会有 `0xA2`。
> 判断方法：`mx.ls` 里 `hid` 一直不涨，而 `frames` 每 2 秒 +1（那是 A3 心跳的回包）。

## 6. 烧录与回滚

### 6.1 免按键流程（推荐，已验证）

芯片进入 ROM 下载模式后，ROM 加载器**同时监听 UART0**，而 UART0 挂在常插的 CH343（COM8）上：

```powershell
# 烧当前构建
powershell -NoProfile -ExecutionPolicy Bypass -File tools\reflash.ps1 -Port COM3

# 回写原厂镜像并回读校验
powershell -NoProfile -ExecutionPolicy Bypass -File tools\reflash.ps1 -Port COM3 -Restore

# 烧 + 立刻抓启动/枚举日志（TinyUSB 调试构建用这个）
powershell -NoProfile -ExecutionPolicy Bypass -File tools\flash_capture.ps1 -Port COM3 -Seconds 12
```

`reflash.ps1` / `flash_capture.ps1` 做的事：通过 CH343 发 `mx.dl`（`RTC_CNTL_FORCE_DOWNLOAD_BOOT`
+ `esp_restart`）→ 校验 ROM banner（`boot:0x2 (DOWNLOAD(USB/UART0))`）→ `esptool --port <Port>
--before no_reset write_flash`。

> **端口别写错**：2026-11-09 实测 CH343 是 **COM3**（`USB\VID_1A86&PID_55D3`），
> 而 `COM8` 现在是系统里的一个**蓝牙串口**。`MAKCU_PORT` / `-Port` 一律传 COM3。

> 前提：**板上跑的是带 `mx.dl` 的构建**。如果板上是原厂固件，仍需按住 BOOT 插一次原生 USB。

### 6.2 原厂固件备份（最高优先级）

| 文件 | 大小 | sha256（前 16） |
|---|---|---|
| `D:\JinPeng\MagicBox\work\hw_left_before_rebuild.bin` | 4,194,304 | `dbd29844f5c3a3af` |

恢复后必须回读对比（`work/cmp_restore.py`），历史所有批次都是 **100.0000% 逐字节一致**才算收工。

### 6.3 手工兜底

```
按住 BOOT(IO0) → 插原生 USB（或按住 BOOT 点 RESET）→ 松手
esptool --chip esp32s3 --port COM9 --before no_reset write_flash ...
```

---

## 7. 台架脚本清单（`tools/`）

**正式工具**（会用、要维护）：

| 脚本 | 用途 |
|---|---|
| `setup_idf_local.ps1` | **换机/重装用**：gitee 拉 IDF v5.4.1、codeload 补子模块、下 xtensa 工具链、建 venv |
| `build_app.ps1` | 构建包装（设置 IDF 环境变量、`-Define` 拆分、`-Clean`） |
| `reflash.ps1` | 免按键烧录 / `-Restore` 回滚并回读校验 |
| `flash_capture.ps1` | 免按键烧录 + 立刻抓启动日志（枚举问题专用） |
| `run_bench_cycle.ps1` | 一轮完整流程（烧录→回归→光标→回滚），有 `-WithHid` |
| `finish_cycle.ps1` | 只烧现有构建 + 回归 + 回滚 |
| `extract_tables.py` | 从镜像导出命令表/跳表，生成 `makcu_cmd.h` |
| `status.py` | 生成 `docs/40-status.md` |
| `t3_report.py` / `diff_insn.py` | 重建函数 vs 原始地址的指令相似度（软信号） |
| `cursor_test.ps1` | 端到端光标位移测量（`GetCursorPos` 前后差） |
| `hid_isolation.ps1` | 鼠标/键盘互不干扰验证（滚轮不得移动光标） |
| `clone_check.ps1` | 克隆身份的主机侧枚举观察 |
| `recover_download.py` | 通过 COM8 发 `mx.dl` 并等下载口 |
| `trace_probe.py` | 现场探针：发命令并打印 `mx.rq` 轨迹 |
| `lib_fingerprint.py` / `flash_verify.py` | 库指纹对比 / 冒烟验证 |

**历史一次性脚本**：`fix_*.py`、`wire_*.py`、`add_*.py`、`upd_*.py`、`regen_cmake*.py`、`clone_*.py`（除 `clone_check.ps1`）、
`patch_*.py`、`dbg_link.py`、`peek_log.py`、`hid_init_flag.py`、`tusb_debug.py` —— 都是当轮打补丁/接线用的，
**保留只为可追溯，不要当工具用**。可整批移到 `tools/adhoc/`（未做，怕破坏报告里的引用）。

---

## 8. 测试体系

三层，全部可重复执行：

| 层 | 位置 | 数量 | 依赖 |
|---|---|---|---|
| 离线模型 | `verification/model/` | 16 | 纯 Python，验证分步/曲线守恒 + 克隆描述符走链 |
| 上机回归 | `verification/regress/` | 76（75 passed + 1 xpassed） | 需板子在线，`MAKCU_PORT` 指向控制口 |
| 指令相似度 | `tools/t3_report.py` | 27 handler | 需 `reversed/` 与构建 ELF |

```powershell
$env:MAKCU_PORT='COM3'; $env:MAKCU_SKIP_HW='0'
python -m pytest verification\regress verification\model -q
```

> 注意 1：跑 pytest 要用**系统 Python**（`D:\Apply\Python311`，本轮已 `pip install pytest pyserial`）；
> 烧录用的是 IDF venv 的 python（带 esptool）。
> 注意 2：**必须用清洁构建**（不带 `-DMB_TUSB_DEBUG`）跑回归，否则 TinyUSB 日志会串进回包。

**台架夹具命令**（`MB_DEBUG_OPCODE=ON` 时可用，发布固件必须关闭）：

| 命令 | 作用 |
|---|---|
| `mx.<hex opcode> <args>` | 直接调用任意 opcode 的 handler（覆盖 13 个不可达的隐藏 opcode） |
| `mx.09` | 夹具活性探针（等价 `cmd_version`） |
| `mx.rp` / `mx.rq` | 最后一份 / 最近 16 份鼠标报告（hex） |
| `mx.rt` | 开机以来累计位移 `dx,dy,wheel`（守恒断言用：进 5000 必须出 5000） |
| `mx.rk` | 键盘报告环形缓冲（8 字节/份） |
| `mx.dd` | 四张描述符表 + resend 标志（`w`=desc[+0x63]、`w16`=desc[+0x163]、`en`=+0x269、`pr`=+0x369、`th`=+0x636、`rs`）——**线上看不见的写入**靠它取证 |
| `mx.dp <idx>` | 测试专用：置 `pr[idx]`（present 位），用于触发 `0x18` 的写入分支 |
| `mx.lb` / `mx.lb0` / `mx.ls` / `mx.dc <ep>` | UART1 自环发帧 / 关自环 / 计数（**12 项**：frames, ep0_requests, ep0_in, ep0_out, hid_chunks, a3, unknown, ep0_starts, ep0_ends, injected, dropped, **rx_bytes**）/ 端点重组内容 |
| `mx.lf <cmd hex> <payload hex>` | 构造任意 UART1 帧走自环（验证解析 + 派发 + 注入） |
| `mx.rf <cmd hex> [payload hex]` | **不看右片也能测右片**：打印右片对某帧的应答字节（`components/makcu_right` 同一份代码） |
| `mx.ln <cmd hex> [payload hex]` | 与 `mx.lf` 同构帧，但**真发到线上**（关自环）——右片存在性探测 |
| `mx.lr` | UART1 最后一帧：`cmd=<xx> len=<n> data=<hex>`（抓真实 `0xA2` 用） |
| `mx.du <hex>` | 用注入路径同一份解码函数解一条原始报告，回 `dx,dy,wheel`（12 位打包格式的判据） |
| `mx.fs <n>` | 转发分频（1=全转）；`tools\set_fs.ps1 -N n` 一键切换 |
| `mx.ss <hex>` | 钉住 0xA2 会话 id（`00` 回自动），让用例与现场真实流量解耦 |
| `mx.hk <0\|1>` | 注入钩子开关，测试期间隔离真实鼠标流量 |
| `mx.bw` | 按键/滚轮计数：`btn_events, wheel_events, wheel_sum, last_buttons` |
| `mx.hb <0\|1>` | 关/开 2 秒 `0xA3` 心跳（时序敏感的用例用它确定化） |
| `mx.as` | 开机自动克隆结果：`0`=未跑 `1`=成功 `2`=回退夹具 |
| `mx.ac` | 手动触发一次自动克隆，回 `ok:vid:pid:报告描述符长度` |
| `mx.ln a1 <setup>` | 直接驱动 EP0 隧道（如 `800600010000001200` 读设备描述符） |
| `mx.cl <1\|2\|3\|4>` | 切换克隆夹具：1=`046D:C077`(4B)、2=`046D:C52F`(5B)、3=`30FA:0302`+12 位(5B)、4=**`046D:C077` + G3M PRO 的 93 字节报告描述符(7B, 16 位, 已验证)** |
| `tools\read_hid_descriptors.ps1` | 枚举 PC 上 HID 设备的 VID/PID/产品名与报告能力 |
| `tools\watch_session.ps1` | **一次会话四量同录**：`state`（右片有无设备）/`frames`/`hid`/`injected`/`hs`（ok,busy,failed）；判"右片停发"还是"左片发不出"只需看这一行 |
| `tools\watch_link.ps1` | 实时轮询 `mx.ls` 并打印增量；`-ProbeRight` 改为轮询右片的设备状态（`0xA0` 方向字节：`00`=有设备 / `ff`=没有） |
| `mx.ei` / `mx.ef` / `mx.lz` | 最后一次 `0xA2` 注入的字节 / EP0 会话是否打开 / 清空重组缓冲 |
| `mx.cl[ 1|2]` / `mx.cc` / `mx.dv` | 装载克隆身份 / 清除 / 打印交还主机的描述符字节 |
| `mx.dl` | 进 ROM 下载模式（免按键烧录的关键） |

---

## 9. 关键决策（完整见 `docs/30-decisions.md` D1–D23）

挑选接手必须知道的：

- **D1–D6**：分层策略（L1 库代码直接链接 IDF，L2 厂商代码重写，L3 表/常量用脚本导出）；handler ABI；
- **D11/D12**：本地 IDF 已改动（裁剪后又从 codeload 恢复 6 个组件、`.gitmodules` 去掉对应项、`gdbinit.cmake` 加了空 `ESP_ROM_ELF_DIR` 保护）；
- **D16**：CH343 的 DTR/RTS **没接** EN/IO0 —— 不能下载、也不能靠脉冲复位；回归夹具必须自己发清零命令；
- **D17**：`mx.*` 夹具与 `mx.dl` **只用于台架**，发布固件必须 OFF；
- **D18**：T3 指令相似度只对"同源码重编译"有意义，手写 handler 不设门槛（实测 0.07–0.60，差异来自内联）；
- **D21**：免按键闭环 = `mx.dl` + UART0 上的 ROM 加载器（当前 CH343 = COM3）；
- **D22**：`-Define` 必须按逗号拆分（否则"控制台构建"其实是 HID 构建）；
- **D23**：运行时 `tud_disconnect/connect` 与 `esp_restart()` 都不会让主机重新枚举 → 克隆改为"写 RTC 仓库，下一次真实复位生效"；
- **D24**：克隆的配置描述符必须严格 34 字节（HID 类块 9 字节）——本轮枚举失败的根因；
- **D25**：克隆激活时报告遵循克隆描述符的 Report ID 约定（无 ID 时发裸报告）；
- **D26**：调试构建（`MB_TUSB_DEBUG`）与回归构建分离，日志会串进回包；
- **D27**：分步步数不受轨迹环上限约束，守恒用 `mx.rt` 断言。

---

## 10. 已知问题与风险

### 10.1 阻塞（硬件/环境）

- **板子在线**：CH343 = `USB\VID_1A86&PID_55D3` → **COM3**；原生 USB 上跑着克隆身份
  `USB\VID_046D&PID_C077\000000000001` + `HID-compliant mouse`，两者状态都是 OK。
  （`COM8` 现在是蓝牙串口，别再当控制口用。）
- COM8 在长时间反复开合后出现过一次 `Incorrect function`（驱动实例损坏）——拔插 CH343 那根即可恢复；换到 COM3 后没再复现。

### 10.2 待完成（代码）

| 项 | 说明 | 建议入口 |
|---|---|---|
| EP0 **数据**注入 | `0xA0` 的会话握手已实现（`mx.ef` 可观察）；把隧道里的字节真正灌进控制传输需要 TinyUSB vendor 钩子（`tud_control_xfer` 只能在控制回调里调用） | `components/makcu_link/src/makcu_link_bridge.c`、`components/makcu_hiddev/` |
| `0xA2` 端点字节位置 | 反编译比的是 `hdr[8]`（数据首字节）与描述符 `+0x62`；`payload[4]` 与 `payload[8]` 两种解读都自洽，需右片真实流量或逻辑分析仪定夺（当前不做过严过滤） | `reversed/docs/uart1_link.md` §8 |
| 右片发送端 | `0xA2` 构造在右片 `0x4200FF10`；`app_right` 的**帧应答**已完成（run-18），但 USB host 栈（`makcu_hidhost` 23 函数）未移植，`ready/session` 恒 0，`0x1A/0xA4/0xA0` 的“正常”分支还走不到 | `app_right/main/app_main.c`、`components/makcu_hidhost/` |
| 右片可烧性 | 本机只有左片的 CH343 控制口，`app_right` 只能 build（T1）不能烧；真联调需要第二块板或右片控制口 | 硬件 |
| 序列号读写 | `makcu_serial_read_hook` 空实现 → `serial()` 恒回失败文案 | `components/makcu_proto/src/cmd_serial.c` |
| UART1 真机联调 | 参数已定（左 TX=GPIO2/RX=GPIO1、右交叉、5 Mbaud，见 D30），但**还没有真实两片流量**：右片要能烧/能跑，且真鼠标插在右片的 host 口 | `components/makcu_link/`、`app_right/` |
| Bezier 逐位保真 | 现为观测等价（形状对、数值不同） | `0x4200EFEC`（690 条指令，含 cos/sin/__fixdfsi） |
| P0 同构编译基准 | 严格指令哈希 7/816；计划改成"同尺寸桶 + difflib" | `verification/fingerprints/`、`tools/lib_fingerprint.py` |

### 10.3 容易踩的坑（都踩过一遍）

1. `excw`（3 字节未知指令）让 153 个函数反编译失败 → 用 `and aN,aN,aN` 补丁后降到 17 个；
2. 函数中间的 `00 00` / `00 00 00` 填充会让线性反汇编错位 → 需要 ±1/±2 重新对齐；
3. `-Define` 拼接 bug（D22）会把 HID 选项带进"控制台构建"；
4. `uart_set_loop_back()` 必须在 `uart_wait_tx_done()` 之后再关，否则帧丢在 FIFO 里；
5. 克隆的配置描述符 `wTotalLength` 必须含 HID 类块（9+9+9+7=34）——**而且 HID 类块必须真的只有
   9 字节**。多一个 `0x00` 就会让主机在偏移 27 读到 `bLength=0`，端点描述符被截断，
   `SELECT_CONFIGURATION` 直接 `INVALID_PARAMETER`（Windows `Problem 10`、`mnt=0`）。
   run-13 的"描述符自洽"结论就是这么误判的：`mx.dv` 只打印了 `config_len` 字节，看起来没问题；
6. 应用内软复位不会重新枚 USB；换描述符只能靠真实复位/插拔（D23）；RTC no-init 里的克隆会被
   烧录/断电清掉，`MB_CLONE_FIXTURE=1` 才能在每次开机自证；
   **注意**：跑完 `verification/regress` 后克隆是"清掉"状态——`test_clone_survives_a_move` 末尾会发
   `mx.cc`，而下一次真实复位才会重新装载 fixture。想恢复"主机看到 046D:C077"，重烧一次即可；
7. `MB_TUSB_DEBUG` 打开的构建**不能跑回归**：TinyUSB 把每个传输都打在 UART0，回包里混进
   `Queue EP 81 with N bytes`，`km.` 前缀断言全崩（本轮 13 例假失败）；
8. 测量光标的脚本要等队列排空，否则会把上一轮的大位移算进来（曾误判成"竞态"）；另外 Windows
   的"提高指针精确度"会让 `GetCursorPos` 的位移不等于报告值——守恒用 `mx.rt` 断言，别用光标坐标；
9. **JTAG 收尾**：gdb 里 `monitor halt` 后直接 `detach`，核会停在 halt，串口不再应答、`mx.dl` 也收不到
   （板子看起来"死"）。必须先 `monitor reset run` 再 `detach`；
10. **从 ROM 下载模式出来**：`esptool --after hard_reset` 靠 RTS 拉 EN，而 RTS 没接（D16）→ 烧完芯片
    仍停在下载模式（UART0 不答文本命令、USB 只有 `303A:1001` CDC）。用 JTAG `monitor reset run`
    或先让应用跑起来再走 `mx.dl`；
11. **CH343 会挂死**：多次开合/JTAG 会话后 COM3 在但无数据，`pnputil /restart-device
    "USB\VID_1A86&PID_55D3\5C98113502"` 立刻恢复；
12. **Windows 上 USB-JTAG 需要接口注册**：`&MI_02` 绑了 WinUSB 还不够，
    `DeviceClasses\{a5dcbf10-…}` 下必须有 `&MI_02` 的实例，否则 openocd 报
    `libusb_open() failed with LIBUSB_ERROR_NOT_FOUND`（修法与验证见 report run-15 §2）；
13. 烧录 header 写 2MB、芯片 4MB 时 bootloader 打一行 size warning，不影响运行；
    想消掉就传 `--flash_size detect`。

---

## 11. 下一步建议（按性价比排序）

1. **右片 USB host 栈**（`makcu_hidhost` 23 个函数 + `0xA2` 构造 `0x4200FF10`）：
   帧应答已经通了（run-18），host 栈一起来 `ready/session` 才有值，`0xA2` 透传才能用真鼠标闭环；
   **但先要解决右片可烧性**（第二块板 / 右片控制口）；
2. 用 JTAG 断点/单步实测 13 个隐藏 opcode 的原厂调用序列（调试器已通，见 run-15/16）；
3. EP0 数据注入：给 HID 请求加 vendor 钩子，让 `0xA0` 隧道能真正承载控制传输；
4. 实现 `makcu_serial_read_hook`（序列号三模式：查询/恢复/写入）；
5. 两片真联调：引脚/波特率已从镜像解出（D30），把右片弄上线后看 `mx.ls` 是否收到真实 `0xA2`；
6. P0 基线换成模糊匹配（同尺寸桶 + difflib ≥0.9），把 `sdkconfig` 调到 ≥95%；
7. 想要"手感"与出厂一致，再回头啃 `0x4200EFEC` 的浮点曲线（需要 USB 分析仪抓出厂轨迹做对照）。

---

## 12. 交接检查清单

- [ ] 能否复现一次 `build_app.ps1` 构建（控制台 + HID 各一次；空机先跑 `setup_idf_local.ps1`）
- [ ] 能否用 `reflash.ps1 -Restore` 把原厂镜像写回并回读校验一致
- [ ] 能否跑通 `pytest verification\regress verification\model`（清洁构建，`MAKCU_PORT=COM3`）
- [ ] 是否知道 `mx.*` 夹具只能出现在台架构建里
- [ ] 是否知道 `-DMB_TUSB_DEBUG` 的构建会把日志混进回包、不能跑回归
- [ ] 是否知道克隆描述符必须严格 34 字节（`verification/model/test_clone_descriptor.py`）
- [ ] 是否知道 `work/hw_left_before_rebuild.bin` 是唯一的原厂备份（务必再复制一份到别处）
- [ ] 是否读过 `docs/30-decisions.md` 的 D16/D17/D21/D22/D23

---

## 13. 参考索引

- 计划与验证分级：`docs/00-plan.md`
- 逆向事实：`docs/00-facts.md`、`reversed/docs/uart1_link.md`、`reversed/docs/known_gaps.md`
- 每次上机记录：`verification/report/2026-11-09-flash-run*.md`（1→19，按时间；
  **第十四批**：描述符克隆闭环、分步守恒、构建环境重建；**第十五批**：JTAG/openocd 打通；
  **第十六批**：13 个隐藏 opcode 的副作用实测闭环；**第十七批**：`0xA2` 上报透传 + `0xA0` 会话状态机；**第十八批**：右片 `frame_forward` 应答侧 + `mx.rf` 交叉验证；**第十九批**：UART1 真实引脚/波特率解出（D30）+ 首轮被动监听）
- 自动状态：`docs/40-status.md`（`python tools/status.py` 重新生成）
- 逆向工程树：`D:\JinPeng\MagicBox\reversed\`（3072 函数 / 17 兜底 / 121 命名）

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
# 左片（device 侧）：autoclone + 双接口 + 固定身份
powershell -File tools\build_app.ps1 -App app_left -Define `
  "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON,-DMB_FORCE_VIDPID=320f706e"

# 右片（host 侧）：自编固件（枚举 + IN 转发 + EP0 隧道 + OUT 提交）
powershell -File tools\build_app.ps1 -App app_right
```

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
mx.fv     -> force=320f:706e ovr=320f:706e dev=0f326e70     # 身份固定生效
mx.if     -> 2 93:81:0 158:82:1                              # 两个接口描述符
mx.dv     -> mnt=1 + 配置 0x42=66B（2 接口、MI_01 的 OUT 已改为 0x03）
mx.ln 1c  -> attached=1 vid=320f pid=706e itf=2 …            # 右片 host 状态
```

PC 侧应看到 `USB\VID_320F&PID_706E` 复合设备 + MI_00/MI_01 + 5 个集合，全部 OK。
**四项都对了再打开 HECATE Connect**（它只在启动/设备到达时探测）。

### 14.5 常见故障对照

| 现象 | 原因 | 处理 |
|---|---|---|
| `mx.fv` 的 `dev` 不是 `0f326e70` | RTC 残留覆盖（旧布局） | 已在 `adopt()` 里让编译期身份最终生效；确认构建带 `-DMB_FORCE_VIDPID` |
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
| `mx.ln 1c` | 右片 host 状态 + 计数（attached/vid/pid/itf/端点/门闸/提交/完成/转发） |
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

只有在"设备的物理身份没有匹配 INF"时才需要一次性钉住：

```
mx.vp 320f706e     # 钉成 G3M 身份；写 NVS，跨刷写/断电保留
mx.vp clear        # 恢复忠实克隆
mx.fv              # force=<编译期> ovr=<运行时> dev=<当前服务出去的字节>
```

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

## 待推进方案

- `verification/plan-hecate-connect-proxy.md`：让 HECATE Connect 在"鼠标插在盒子上"时也能识别与
  设置鼠标的方案（身份 + 复合拓扑 + 厂商 IN 转发 + 厂商 OUT 下行；含判定点与工作量）。

- `verification/plan-right-firmware.md`：**自编右片固件方案**（替代原厂 V3.7；M1 枚举 → M2 IN 转发
  → M3 EP0 隧道 → M4 OUT 下行 → M5 健壮性；含接口契约、风险与工作量）。优先于二进制补丁路线。
