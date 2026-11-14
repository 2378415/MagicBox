# 00 方案：MagicBox-Rebuild（可编译固件重建）

> **口径：立项期（2026-11-09）**。本文是当时的方案与验收判据，保留作溯源；进度与遗留以
> [40-status.md](40-status.md) 为准，事实以 [00-facts.md](00-facts.md) 为准。文中「62 个待移植函数」等
> 数字属当时口径，现为 `handlers.def` 27/27 implemented——不要据此判断当前进度。

目标：在独立工程里重写两片固件（LEFT V3.2 设备侧 / RIGHT V3.7 主机侧）的**厂商逻辑**，
链接官方 ESP-IDF，产出可编译、可烧录、行为等价的源码。

本文件是执行依据；进度与阻塞写在 `40-status.md`，事实基线写在 `00-facts.md`。

---

## 0. 验收判据

| 档 | 判据 | 备注 |
|---|---|---|
| **T1 可编译可启动** | `idf.py build` 通过；烧录后 USB 枚举、`.km.version()` 回 `km.MAKCU`、提示符 `>>> ` 正常 | 先跑通链路 |
| **T2 协议等价** | 43 条文本命令 + 27 项 opcode + UART1 帧 + 序列号查询/伪装 + HID 描述符克隆 + 按钮/锁/抓取状态机全部通过回归夹具 | 产品行为判据 |
| **T3 指令级相似度** | **仅适用于“同一份源码重新编译”的对象（P0 库代码、本地重建的 libm 副本）**：归一化指令 diff ≥ 90%。手写重实现的 handler 不设此门槛（实测 0.07–0.60，差异来自内联决策而非语义），改为记录分数 + T2 逐字节 | 见第五批报告 §4：T3 衡量的是重编译保真度，不是重写正确性 |

**不追求**整镜像字节一致；**不实现**未观测到的猜测语义（13 个隐藏 opcode 的用途仍属推断，
只实现已实证的行为）。

---

## 1. 三层切分

| 层 | 规模 | 处理 |
|---|---|---|
| L1 库代码 | ≈2834（LEFT 1350 / RIGHT 1484） | 不重写，链接 ESP-IDF v5.4.1 / newlib / tinyusb |
| L2 厂商代码 | 候选 ≈237（LEFT 92 / RIGHT 145）→ 剔除误分类后 ≈120–160 | 重写成惯用 C |
| L3 数据/表/常量 | 命令表 43 条、opcode 跳表 27 项、通道表、NVS 键、HID 描述符、曲线常量 | 脚本导出（`tools/extract_tables.py`），不手抄 |

关键手段：**同构编译基准**。锁死 IDF v5.4.1 + `xtensa-esp-elf 14.2.0` + 复原 `sdkconfig`，
先重建只含 IDF 的骨架 app，把 IDF 函数产物与原始镜像逐函数比对；一致率 ≥95% 才进入
厂商代码重写，否则先修环境。

---

## 2. 阶段计划

| 阶段 | 内容 | 退出判据 | 人日 |
|---|---|---|---|
| P0 环境基准 | IDF v5.4.1 + 工具链锁版；`sdkconfig` 复原；分区表照抄 | 骨架 app 编/烧通过；IDF 函数重编译一致率 ≥95% | 3 |
| P1 骨架 + 数据导出 | 双 app 工程；表导出；`makcu_lookup` 前缀匹配；回执封装 | 生成的表与镜像逐字节一致；`.km.foobar()` 零回应 | 5 |
| P2 RIGHT 桥接 | `hid_uart` 任务、8×8 环形缓冲、`frame_forward` 分支、0xA2/0xA0 构造 | UART1 回环可用；长度口径与文档一致 | 10 |
| P3 LEFT 协议层 | 35 个 handler（含 3 个跳表专用）+ 回执格式 | T2 文本命令 100% 通过 | 12 |
| P4 LEFT 动作层 | `mouse_submit`/`pulse_move`、wheel、HID 报告、批量/组合键、锁/抓取表 | 位移/按键真机验证 | 12 |
| P5 克隆与序列号 | 描述符解析/克隆、`serial_read` 三模式、eFuse 只读 | 克隆设备被对端识别；`serial()` 文案一致 | 8 |
| P6 验证收尾 | T1/T2/T3 全量；`diff_insn` 报告；烧录/回滚脚本 | 三档达标 + 报告归档 | 8 |

合计 ≈58 人日（单人半职约 9–11 周）；只做 LEFT 可压到 ≈6 周。

---

## 3. 项目结构

```
<仓库根>/
├── docs/                    00 方案 / 00-facts 事实 / 10-abi / 20-types / 30-decisions / 40-status
├── components/
│   ├── makcu_proto/         命令表、opcode 表、前缀匹配、回执封装（纯 C）
│   ├── makcu_link/          UART1 5A 帧构建/解析（纯 C，可离线单测）
│   ├── makcu_mouse/         提交队列、Bezier、锁/抓取
│   ├── makcu_keyboard/      usage 写入、批量、组合、点按
│   ├── makcu_hiddev/        LEFT：描述符克隆、序列号伪装
│   ├── makcu_hidhost/       RIGHT：USB host 枚举、0xA2 上报
│   └── makcu_board/         LED、eFuse、coredump、NVS 键
├── app_left/                idf 工程（LEFT）
├── app_right/               idf 工程（RIGHT）
├── partitions_left.csv      照抄实测分区表
├── tools/                   extract_tables / diff_insn / p0_baseline / setup_idf
└── verification/regress/    pytest：串口夹具 + 协议用例
```

> 2026-11-12 两件事：① `lib_fingerprint.py` / `t3_report.py` 等依赖旧反编译树的工具已随旧仓库删除；
> ② 原 `AMagicBox-Rebuild/` 目录已整体上移至仓库根（本文件其余章节里的 `reversed/`、`work/` 属写作时的历史引用）。

---

## 4. 关键决策

| # | 决策 | 理由 |
|---|---|---|
| D1 | 不重写 IDF/newlib/tinyusb | 重造库零收益；用同构基准证明“库不是我该写的” |
| D2 | 表数据脚本导出而非手抄 | 43 条命令表 / 27 项跳表 / 通道表都含绝对地址，手抄必错 |
| D3 | handler 统一签名 `(buf,len,dev,entry,arg,arglen)` | 由 `cmd_dispatch` 的 a10..a15 传参与 `cmd_key_state` 用法确证 |
| D4 | 27 项 opcode 用函数指针表，不用 switch | 与原始 `jx` 跳表同构，T3 相似度天然高 |
| D5 | `DAT_/PTR_` 一律转具名全局或回调指针 | 保留裸地址等于把链接器当运行时 |
| D6 | 数学库：首版用 newlib `sin/cos/floor/scalbn` | 与原始 fdlibm 副本算法同源；若 Bezier 路径 T3 掉分再切本地副本 |
| D7 | 不实现 OTA / secure boot | 原厂分区表无 OTA，eFuse 全只读 |
| D8 | 只 READ 引用旧仓库（pin commit） | 证据与重建分离，避免双向污染 |

---

## 5. 17 个兜底函数的处置

| 类别 | 数量 | 处置 |
|---|---|---|
| IDF 内部（freertos/heap/分区表） | 15 | 不进重建范围，链接 IDF；P0 基线会证明它们是库函数 |
| `cmd_silent`（0x4200E1B0） | 1 | 按实测语义重写；`excw` 三字节列入 openocd 单步待验 |
| `cmd_channel_toggle`（0x4200E56C） | 1 | 按已解析骨架重写（`idx = parse_int_or_char`、`+0x369/+0x269`、`0x3FC99FA3`） |

---

## 6. 验证体系

| 级别 | 手段 | 频率 |
|---|---|---|
| V0 | `idf.py build` / `idf.py size` | 每次提交 |
| V1 | 链接后符号表对比（厂商函数齐不齐、栈用量、map 差） | 每次提交 |
| V2 | `tools/t3_report.py`（基于 `diff_insn`）归一化指令 diff，**软信号** | 每批合入 |
| V3 | `pytest` 协议回归（串口夹具，用例来自 `dynamic_tests.md`） | 每次烧录 |
| V4 | 逻辑分析仪抓 UART1、USB 抓包看描述符、对端鼠标位移 | 里程碑 |

---

## 7. 风险

| # | 风险 | 缓解 |
|---|---|---|
| R1 | `sdkconfig` 复原不到位 → 基线一致率不足 | P0 硬门槛；按 uart/freertos/heap 三组二分 |
| R2 | `excw` 语义未知 | openocd 单步；行为以 T2 为准 |
| R3 | HID 描述符克隆依赖真实设备 | V4 抓包；保留“原样透传描述符”降级路径 |
| R4 | 结构体/表布局推错 | 表尺寸以 256 项硬约束 + 运行时断言 |
| R5 | newlib 数学与 fdlibm 副本有微小差 | D6 的 B 方案（本地副本）随时可切 |
| R6 | RIGHT 侧两种 USB 栈混用 | P2 先做纯帧桥接，再接 host |
| R7 | 任务优先级/栈复原错 | 从 `xTaskCreate` 立即数逐个抄；24h 压力跑 |
