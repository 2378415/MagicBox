# AMagicBox-Rebuild

从官方镜像重建两片 MAKCU 固件的**可编译源码**：`app_left`（V3.2 设备侧）+ `app_right`（V3.7 主机侧），ESP-IDF v5.4.1 / esp32s3。
逆向产物在 `../`（`reversed/` 源码树、`tools/` 流水线、`官方固件/`），本工程只读引用，不复制反编译源码。

> 上位机侧（Android）见 [../../MagicBullet/README.md](../../MagicBullet/README.md)；仓库总览见 [../../README.md](../../README.md)。

## 目录

```text
app_left/                 左片：控制口 + HID 设备侧 + sumv/AIM + 按键事件
  main/app_main.c         初始化、控制口读循环、autoclone 护栏
  main/control_bin.c/.h   二进制快速通道（5A cmd seq len crc8）、0x31–0x45/0xE1
  main/btn_evt.c/.h       按键事件环（32 条）、边沿算法、pending、10 s 失联看门狗
  main/btn_trace.c/.h     按键字节变化历史（供 0x42/0x44 回读）
app_right/                右片：USB Host 抓真鼠标报告 → UART1 转发（纯桥）
components/               11 个组件，见下
docs/                     00-facts / 00-plan / 10-abi / 20-types / 30-decisions / 40-status / API-control-port / HANDOVER
tools/                    构建、刷写、台架与诊断脚本
verification/             regress(pytest 夹具) / model(纯模型单测) / report(逐轮上机记录)
```

## 组件

| 组件 | 职责 |
|---|---|
| `makcu_proto` | 文本协议：**49 条命令**（43 原厂 + `sumv`/`evt` 扩展）、前缀匹配、回包封装、30 项 opcode 跳表（`handlers.def` 驱动） |
| `makcu_dev` | 设备上下文：按键/轴/通道/映射槽位，偏移与原厂对齐 |
| `makcu_mouse` | 运动引擎与转发：位移累计、1 kHz 注入、按键优先专用队列、让路窗口、按键回环审计 |
| `makcu_sumv` | 轨迹执行器：三次贝塞尔 + 弧长参数化、DDA、`AIM` 专用入口、死区、看门狗 |
| `makcu_hiddev` | 设备侧 TinyUSB HID：鼠标 7 字节报告、键盘复合报告、按键队列统计（`0x3E/0x3F`） |
| `makcu_hidhost` | 主机侧 USB Host：枚举真鼠标、抓输入报告、控制传输、延迟直方图 |
| `makcu_clone` | 描述符克隆与身份策略：VID/PID 别名、接口/报告描述符采纳、序列号 |
| `makcu_link` | 片间 UART1：`5A cmd len:u16 payload` 成帧、流式解析、EP0 隧道、分块回放 |
| `makcu_right` | 右片帧语义：快照 / 配置 / 错误帧组装与回复 |
| `makcu_keyboard` | 键盘注入（原厂隐藏 API）：down/up/tap/type/批量/combo/state |
| `makcu_board` | 板级端口占位（仅导出端口面计数） |

## 控制口

物理层：左片 UART0 经中线 CH343 出到 PC/手机，**921600 8N1**，无流控，DTR/RTS 不要拉高。

| 接口 | 形态 |
|---|---|
| 文本 | `.km.xxx(...)\r` → `km.<content>\r\n>>> `；未知命令不回包；49 条命令按按键/锁定/捕获/移动/查询分族 |
| 二进制 | `5A cmd seq len:u16 payload crc8(poly 0x07)`；回包 `cmd\|0x80`，`seq` 回带 |
| 二进制命令 | `0x31` MOTION_PLAN · `0x32` BUTTON · `0x33` WHEEL · `0x34` QUERY · `0x35` PING · `0x36` SUMV · `0x37` SUMV_STOP · `0x38` SUMV_STATE · `0x39` EVT_CTL · `0x3A` EVT_READ · `0x3B` EVT_STAT · `0x3C` AIM · `0x3D` AIM_STATE · `0x3E` HID_STAT · `0x3F` BTN_AUDIT · `0x40` AIM_RESET · `0x41` EVT_RESET · `0x42` LAST_HID · `0x44` BTN_LOG · `0x45` BTN_CNT · `0xE1` EVT_PUSH（异步段 0xE0–0xEF） |
| 台架 | `mx.*`（仅 `MB_DEBUG_OPCODE` 构建）：`mx.sv/ev/mv/hz/lh/hi/rb/if/fv/rq/rp/rt/dv/ox/hs/hv/as/ac/rs/hk/ls/dl …` |

字段级表格、实测延迟（文本 p50 1.10 ms）、`sumv`/`AIM` 参数与安全阀、故障对照，全部在 **[docs/API-control-port.md](docs/API-control-port.md)**（774 行）。

### 关键语义（容易踩的）

- 按键事件**默认穿透**：订阅只上报边沿，按键照常给 PC；要“吃掉”必须 `0x39` 第 4 字节 `consume=1`，判据看 `EVT_STAT.last_fwd`；
- 订阅期需要心跳（`0x3A/0x3B/0x35`），10 s 无心跳自动退订并恢复全透传（`flags` bit2）；
- `sumv` 执行期盒子独占运动权：真实鼠标 X/Y 丢弃，按键/滚轮透传，`.km.move` 被拒，新 `sumv` 为 REPLACE；
- `AIM` 按时长预算走恒速剖面，`dead_min`（默认 2 counts）内判到位不发报告，结果码见 `AIM_STATE.last_result`（1 启动/2 替换/3 拒绝/4 死区/5 看门狗/6 超限）；
- 台架命令是 `mx.xxx`，**不要**写成 `.km.mx.xxx`（控制口先剥 `.km.` 前缀，剩下才会被当台架命令）。

## 构建与刷写

```powershell
.\tools\build_app.ps1 -App app_left              # 或 app_right；-Clean 先删 build
.\tools\build_app.ps1 -App app_left -Action "-p COM8 flash"

.\tools\flash_left.ps1 -Action backup            # 整片读 4 MB 备份
.\tools\flash_left.ps1 -Action flash             # 编译 + 刷
.\tools\flash_left.ps1 -Action verify            # 回读校验
.\tools\flash_left.ps1 -Action restore           # 还原原厂镜像
```

分区表取自 LEFT 实测（`app_left/partitions.csv`）：`nvs 0x9000/24K`、`phy_init 0xF000/4K`、`factory 0x10000/1M`、`coredump 0x110000/64K`、`storage 0x120000/128K`，**无 OTA 分区**。

刷写前提：中线 CH343 从手机拔回 PC；若旧 GUI 进程（pythonw）还握着串口会 `PermissionError`，先结束它；免按键进下载模式用台架命令 `mx.dl`（仅 `MB_DEBUG_OPCODE` 构建，发布固件不含，见 `docs/30-decisions.md` D20/D21）。

## 环境

```powershell
.\tools\setup_idf.ps1        # 拉 IDF v5.4.1、补子模块、装最小工具集
```

| 项 | 值 |
|---|---|
| ESP-IDF | v5.4.1 @ `D:\esp-idf`（`ESP_IDF_VERSION=5.4.1`） |
| 工具链 | `xtensa-esp-elf` esp-14.2.0_20241119 @ `D:\esp-tools\tools\…\bin` |
| Python | IDF venv `D:\esp-tools\python_env\idf5.4_py3.11_env` |
| CMake / Ninja | pip 安装；**CMake 必须 < 4**（IDF 5.4 用到 4.0 删除的 `file(TO_CMAKE_PATH)` 两参形式） |
| 其他变量 | `ESP_ROM_ELF_DIR=D:\esp-idf\components\esp_rom\esp32s3`、`IDF_SKIP_CHECK_SUBMODULES=1` |
| esptool | `python -m esptool --chip esp32s3 --baud 921600` |

这套环境是手工拼的，全部收敛在 `tools/build_app.ps1` 里；**不要绕过它直接跑 `idf.py`**（少了这些变量会在 cmake 阶段失败）。

## 验证

| 层 | 工具 | 说明 |
|---|---|---|
| T1 编译 | `tools/build_app.ps1` | 两个 app 各编一次 |
| T1' 语法 | `xtensa-esp32s3-elf-gcc -fsyntax-only` | 组件源码全部通过 |
| T2 协议 | `python -m pytest verification\regress -q` | 需真机（`MAKCU_PORT`，默认 COM8）；`MAKCU_SKIP_HW=1` 只收集；9 个文件 65 条用例 |
| T3 相似度 | `python tools\diff_insn.py …` | 自比 1.000、异函数 0.364 |
| P0 基线 | `python tools\lib_fingerprint.py compare` | 需 IDF `.map`；严格哈希未达标（0.9%），改模糊匹配中 |

```powershell
python -m pytest verification\regress -q
$env:MAKCU_SKIP_HW='1'; python -m pytest verification\regress -q --collect-only
python tools\status.py                       # 重新生成 docs/40-status.md（需先构建出 build/*.bin）
python tools\aim_stress.py                   # 瞄准压力：并发 AIM + 按键，判据见 HANDOVER §14
python tools\link_probe.py --all             # PING/QUERY/SUMV/EVT 一次性探针
```

最近一轮上机记录见 `verification/report/`（最新两份：`2026-11-11-px-gain.md`、`2026-11-10-sumv.md`，回归 **100 passed**）。`docs/40-status.md` 是 `tools/status.py` 的生成物，本轮仓库清理删掉了 `build/` 与 `../work/`，需要先重新构建再生成。

## 边界

- 不重写 ESP-IDF / newlib / tinyusb（约 2,834 个函数），直接链接官方库；
- 未实测的行为不实现：13 个隐藏 opcode 只做已证实部分，`serial()` 在克隆未就绪时仍回失败文案；
- 不做 OTA / secure boot（原厂分区表无 OTA，eFuse 只读）；
- `components/makcu_hiddev/src/makcu_hiddev_stub.c`、`makcu_hidhost/src/makcu_hidhost_stub.c` 是**待移植函数地址清单**，未参与编译（不在任何 CMake SRCS 中）；
- `reversed/` 是反编译重建，不可直接编译；本工程的 `-fsyntax-only` 与 T3 相似度才是它和原厂的对照手段。

## 文档

| 主题 | 文档 |
|---|---|
| 控制口协议（对外接口） | [docs/API-control-port.md](docs/API-control-port.md) |
| 交接：现状 / 操作手册 / 坑位 | [docs/HANDOVER.md](docs/HANDOVER.md) |
| 事实基线（镜像身份、分区、实测行为） | [docs/00-facts.md](docs/00-facts.md) |
| 方案 / ABI / 类型 / 决策 | [docs/00-plan.md](docs/00-plan.md)、[docs/10-abi.md](docs/10-abi.md)、[docs/20-types.md](docs/20-types.md)、[docs/30-decisions.md](docs/30-decisions.md) |
| 执行状态（自动生成） | [docs/40-status.md](docs/40-status.md) |
| 逐轮上机与验证 | [verification/README.md](verification/README.md)、`verification/report/` |
| 原厂协议与隐藏 opcode | [../官方固件命令协议.md](../官方固件命令协议.md)、[../官方固件未公开协议.md](../官方固件未公开协议.md) |
