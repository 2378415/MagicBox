> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）

# 40-status：执行状态（本文件由 `tools/status.py` 生成）

## 构建（T1）

| app | 构建 | app.bin | elf |
|---|---|---:|---:|
| app_left | ✅ 成功 | 355040 B | 5294516 B |
| app_right | ✅ 成功 | 292624 B | 4637624 B |

原始镜像对照：LEFT 403,536 B / RIGHT 341,824 B。重建镜像体积不同属预期：厂商的 Bezier 浮点曲线（`0x4200EFEC`）用观测等价实现替代，且 IDF 版本/裁剪项与原厂构建不完全一致。尺寸取自最近一次清洁构建；`build/` 不入库，重跑本脚本前先 `tools/build_app.ps1`。

## 已完成

| 项 | 状态 | 产物 |
|---|---|---|
| 方案与事实基线 | 完成 | `docs/00-plan.md`、`docs/00-facts.md` |
| ESP-IDF v5.4.1 环境 | 完成（子模块用 codeload 补、CMake/Ninja 用 pip） | `tools/setup_idf.ps1`、`tools/fetch_idf_submodules.py` |
| 命令表 / opcode 表导出 | 完成：43 条命令 + 27 项 opcode，全部带 handler 名 | `tools/extract_tables.py` |
| 前缀匹配 `makcu_lookup` | 完成（语义同 `cmd_lookup`） | `components/makcu_proto/src/makcu_lookup.c` |
| 回执封装 `makcu_reply_format` | 完成（`km.` + 内容 + `\r\n>>> `） | `components/makcu_proto/src/makcu_reply.c` |
| UART1 帧层（构建 + 流式解析） | 完成 | `components/makcu_link/src/makcu_link.c` |
| 双 app 工程（可编可链） | 完成：`idf.py build` 两端都通过 | `app_left/`、`app_right/` |
| 分区表（LEFT 实测） | 完成 | `app_left/partitions.csv` |
| 指令相似度工具 | 完成：自比 1.000、异函数 0.364 | `tools/diff_insn.py` |
| 函数指纹 + P0 基线工具 | `tools/p0_baseline.py`（只读官方镜像）；`lib_fingerprint.py` 依赖旧反编译树，已随 2026-11-12 清理删除 |
| 协议回归夹具 | 完成（无硬件自动 skip） | `verification/regress/` |

## 进行中 / 阻塞

| 项 | 状态 | 说明 |
|---|---|---|
| P0 同构编译基准 | **未达标** | 严格指令哈希命中 7/816（0.9%）：`sdkconfig` 与原始构建仍有差异；下一步改成“同尺寸桶 + difflib 相似度”的模糊匹配，并把 op 序列存进指纹 |
| 命令协议层（P3 文本层） | **27/27 个 opcode 全部实现**（43 条文本命令 + 3 个跳表专用入口），回包与原厂逐字节一致；13 个隐藏 opcode 的副作用也实测闭环（`mx.dd`/`mx.dp`，report run-16） | `components/makcu_proto/handlers.def` |
| 副作用层（P4 运动） | **队列 + 分步 + 曲线完成**：int8 分步（ceil(span/127)，不再被轨迹环上限截断）、每步一次随机弯曲、残差摊分守恒，`mx.rq` 读轨迹 + `mx.rt` 读累计位移可断言“进多少出多少”；与原函数的差别是数值而非形状 | `components/makcu_mouse/` |
| 副作用层（P5 HID 上报） | **完成**：设备枚举为 HID 鼠标，光标位移已端到端验证；克隆激活时按克隆描述符的 Report ID 约定发送（无 ID 时发裸报告） | `components/makcu_hiddev/`、`tools/cursor_test.ps1` |
| 副作用层（P4 键盘） | **完成**：复合 HID（ID1 鼠标 / ID2 键盘），down/up/tap/type/批量/combo/state 全实现，`mx.rk` 可读回 8 字节报告 | `components/makcu_keyboard/` |
| 副作用层（P2 桥接） | **完成**：UART1 帧层 + `0xA0` EP0 会话状态机 + `0xA2` 上报透传（真机端到端：注入报告让主机光标移动）；EP0 **数据**注入、右片发送端、真实引脚仍待做 | `components/makcu_link/` |
| 副作用层（P5 克隆） | **描述符克隆完成**：仓库→回调→主机→驱动启动全通（`mnt=1`、主机侧 `VID_046D&PID_C077` + `HID-compliant mouse` 均正常）；EP0 隧道应答、序列号读写仍待做（`serial()` 仍恒回失败文案） | `components/makcu_clone/` |
| 烧录 + 回归（T2） | 报告 32 份；最近一轮 **119 passed / 0 failed**（95 上机 + 24 离线模型；清洁构建，`MB_TUSB_DEBUG` 构建会把日志混进回包、不能跑回归） | `verification/report/` |

## 已移植 handler

| opcode | handler | 说明 |
|---|---|---|
| 0x00 | `cmd_lock_param0` | 协议面已上机验证 |
| 0x01 | `cmd_lock_query` | 协议面已上机验证 |
| 0x02 | `cmd_lock_param2` | 协议面已上机验证 |
| 0x03 | `cmd_lock_axis` | 协议面已上机验证 |
| 0x04 | `cmd_button_press` | 协议面已上机验证 |
| 0x05 | `cmd_button_click` | 协议面已上机验证 |
| 0x06 | `cmd_move` | 协议面已上机验证 |
| 0x07 | `cmd_wheel` | 协议面已上机验证 |
| 0x08 | `cmd_nop` | 协议面已上机验证 |
| 0x09 | `cmd_version` | 协议面已上机验证 |
| 0x0a | `cmd_catch_set` | 协议面已上机验证 |
| 0x0b | `cmd_catch_query` | 协议面已上机验证 |
| 0x0c | `cmd_buttons` | 协议面已上机验证 |
| 0x0d | `cmd_key_down` | 协议面已上机验证 |
| 0x0e | `cmd_key_up` | 协议面已上机验证 |
| 0x0f | `cmd_key_tap` | 协议面已上机验证 |
| 0x10 | `cmd_set_string` | 协议面已上机验证 |
| 0x11 | `cmd_key_state` | 协议面已上机验证 |
| 0x12 | `cmd_keys_down` | 协议面已上机验证 |
| 0x13 | `cmd_keys_up` | 协议面已上机验证 |
| 0x14 | `cmd_keys_combo` | 协议面已上机验证 |
| 0x15 | `cmd_map_16` | 协议面已上机验证 |
| 0x16 | `cmd_map_entry` | 协议面已上机验证 |
| 0x17 | `cmd_dump_channels` | 协议面已上机验证 |
| 0x18 | `cmd_channel_toggle` | 协议面已上机验证 |
| 0x19 | `cmd_silent` | 协议面已上机验证 |
| 0x1a | `cmd_serial` | 协议面已上机验证 |

## 报告与记录

- [`2026-11-09-flash-run-10.md`](../verification/report/2026-11-09-flash-run-10.md)
- [`2026-11-09-flash-run-11.md`](../verification/report/2026-11-09-flash-run-11.md)
- [`2026-11-09-flash-run-12.md`](../verification/report/2026-11-09-flash-run-12.md)
- [`2026-11-09-flash-run-13.md`](../verification/report/2026-11-09-flash-run-13.md)
- [`2026-11-09-flash-run-14.md`](../verification/report/2026-11-09-flash-run-14.md)
- [`2026-11-09-flash-run-15.md`](../verification/report/2026-11-09-flash-run-15.md)
- [`2026-11-09-flash-run-16.md`](../verification/report/2026-11-09-flash-run-16.md)
- [`2026-11-09-flash-run-17.md`](../verification/report/2026-11-09-flash-run-17.md)
- [`2026-11-09-flash-run-18.md`](../verification/report/2026-11-09-flash-run-18.md)
- [`2026-11-09-flash-run-19.md`](../verification/report/2026-11-09-flash-run-19.md)
- [`2026-11-09-flash-run-2.md`](../verification/report/2026-11-09-flash-run-2.md)
- [`2026-11-09-flash-run-20.md`](../verification/report/2026-11-09-flash-run-20.md)
- [`2026-11-09-flash-run-21.md`](../verification/report/2026-11-09-flash-run-21.md)
- [`2026-11-09-flash-run-22.md`](../verification/report/2026-11-09-flash-run-22.md)
- [`2026-11-09-flash-run-23.md`](../verification/report/2026-11-09-flash-run-23.md)
- [`2026-11-09-flash-run-3.md`](../verification/report/2026-11-09-flash-run-3.md)
- [`2026-11-09-flash-run-4.md`](../verification/report/2026-11-09-flash-run-4.md)
- [`2026-11-09-flash-run-5.md`](../verification/report/2026-11-09-flash-run-5.md)
- [`2026-11-09-flash-run-6.md`](../verification/report/2026-11-09-flash-run-6.md)
- [`2026-11-09-flash-run-7.md`](../verification/report/2026-11-09-flash-run-7.md)
- [`2026-11-09-flash-run-8.md`](../verification/report/2026-11-09-flash-run-8.md)
- [`2026-11-09-flash-run-9.md`](../verification/report/2026-11-09-flash-run-9.md)
- [`2026-11-09-flash-run.md`](../verification/report/2026-11-09-flash-run.md)
- [`2026-11-10-button-events.md`](../verification/report/2026-11-10-button-events.md)
- [`2026-11-10-control-link-921600.md`](../verification/report/2026-11-10-control-link-921600.md)
- [`2026-11-10-flash-run-24.md`](../verification/report/2026-11-10-flash-run-24.md)
- [`2026-11-10-flash-run-25.md`](../verification/report/2026-11-10-flash-run-25.md)
- [`2026-11-10-patch-round.md`](../verification/report/2026-11-10-patch-round.md)
- [`2026-11-10-sumv.md`](../verification/report/2026-11-10-sumv.md)
- [`2026-11-11-px-gain.md`](../verification/report/2026-11-11-px-gain.md)
- [`2026-11-11-summary.md`](../verification/report/2026-11-11-summary.md)
- [`2026-11-12-button-event-channel-attempt.md`](../verification/report/2026-11-12-button-event-channel-attempt.md)

## 端口面（草稿清单，非待办）

`components/makcu_proto/handlers.def` 现为 **27/27 implemented**。下表是 2026-11-09 移植期留在`*_stub.c` 里的 `/* TODO */` 标记数，属历史草稿（真实待办见下节，勿据此判断进度）。

| 组件 | stub 里的 TODO 标记 |
|---|---:|
| makcu_board | 6 |
| makcu_clone | 0 |
| makcu_dev | 0 |
| makcu_hiddev | 4 |
| makcu_hidhost | 23 |
| makcu_keyboard | 11 |
| makcu_link | 0 |
| makcu_mouse | 18 |
| makcu_proto | 0 |
| makcu_right | 0 |
| makcu_sumv | 0 |

合计 62 处标记（11-09 口径；当时写作「待移植函数数」）。

## 下一步（按顺序）

1. 实现 `makcu_serial_read_hook`（序列号查询 / 恢复 / 写入三模式）——`serial()` 目前恒回失败文案；
2. 右片 UART1 真实引脚反查（当前占位 17/18），拿到后用 V3.7 配置替换并复测链路；
3. P0 基线改模糊匹配（同尺寸桶 + difflib ≥0.9 记命中），对齐 `sdkconfig` 使相似度可用作变更护栏；
4. 手感一致性：`0x4200EFEC` 浮点曲线需 USB 分析仪对照出厂轨迹；
5. 可选：补 HECATE Connect 在「鼠标插在盒子上」场景下的写配置回归（`verification/plan-hecate-connect-proxy.md`）。


---

## 2026-11-10 收官：右片自编固件 + 双接口 + 管理程序打通

> 手工维护区：`tools/status.py` 会把本文件原样附在自动生成内容之后，不会被覆盖。

### 本轮关闭
| 项目 | 结果 |
|---|---|
| 右片可烧性（原为阻塞项） | ✅ `tools/flash_right.ps1 -Offset 0x10000`，出厂镜像 `0x0` 可回滚 |
| 右片 USB host 栈 | ✅ 自编固件：枚举 / IN 转发 / EP0 隧道 / OUT 提交（transfer 池 + 逐槽自愈） |
| EP0 数据注入（`0xA0` 隧道） | ✅ `0xA1` + `0x1B/0x1D`，自动克隆走隧道 |
| 两片真联调 | ✅ 1 kHz 压测 31,555 帧 0 失败 |
| 双接口复合克隆 | ✅ `MB_DUAL_IF`，PC 侧 9 节点与真设备同构 |
| HECATE Connect 识别 + 读电量 + 改配置 | ✅ `ox = 169/169/169` |
| 插拔自愈 | ✅ 会话号重置 + transfer 释放 + 逐槽自愈 + 自动重枚举 |
| 身份自动化 | ✅ 别名族映射，`force=0 ovr=0 dev=320f:706e` |
| 序列号 | ✅ 每台唯一随机（NVS 持久） |
| 台架能力 | ✅ `mx.lfx`（自动 session 注入）、右片日志回传 `0x1F`（`[R]` 前缀） |

### 仍待办
1. ~~**P0 同构编译基准**~~ **已完成（2026-11-10）**：新工具 `tools/p0_baseline.py` 给出
   27 个 handler 的逐函数相似度（窗口判据），当前 **平均 0.357、7/27 接近（≥0.5）、0 个达 0.70**；
   报告见 `verification/p0_baseline.md`。后续价值是变更护栏；
2. ~~**13 个隐藏 opcode 的原厂调用序列**~~ **已改为可回归的行为轨迹**（2026-11-10）：
   `tools/trace_opcodes.py` 采集 42 步协议行为基线（`verification/opcode_trace.json`），
   支持 `--compare` 差分。仅剩 `catch` 的 `+0x168/+0x124` 不对称需 JTAG 最终确认；
3. **手感一致性**：`0x4200EFEC` 浮点曲线，需 USB 分析仪抓出厂轨迹对照；
4. 可选：`MB_FORCE_VIDPID` 现已冗余（别名策略覆盖），建议标注 deprecated。

## 2026-11-11 追加：按键优先 / AIM 接口族 / 光标标定

| 项 | 结果 | 证据 |
|---|---|---|
| 按键让路窗口 | `makcu_mouse_button_priority()` 置 2 ms 窗口（`MAKCU_BTN_GUARD_US = 2000`），窗口内引擎不提交运动报告 | `components/makcu_mouse/src/makcu_mouse.c:474` |
| 按键独立队列 | 按键报告走独立队列，满队列只累加 `btn_overflow`，**不覆盖已排队报告** | `components/makcu_hiddev/src/makcu_hiddev.c:100` |
| 按键去抖 / 消假洪泛 | 2026-11-12 修订：**不做 5 ms 合并/抵消**（旧实现依赖从未赋值的来源标记=死代码，且反向抵消会吞掉 <5 ms 的真实点击）；改为逐条直发，`0x3E` 的 `merged/cancel` 保留恒 0 | `components/makcu_hiddev/src/makcu_hiddev.c:100-112` |
| 按键队列抗压 | 深度 32 → **64**；满时先等空位（≤10 ms），等不到才计 `btn_overflow` —— 宁可晚一条不丢一条 | `components/makcu_hiddev/src/makcu_hiddev.c:97-104, 210-232` |
| 短按抗抖可调 | 释放守卫默认仍是 20 ms，台架 `mx.gd <0..50>` 运行期可改，**0 = 关闭**（"一个按键都不少"模式）；`mx.gd` 裸调用读当前值 | `app_left/main/app_main.c:824-828, 1006-1032, 1180-1216` |
| 按键仪表（2026-11-12 台架校准） | `0x3E` 扩到 16 B 并输出 `wire_chg`；直发路径补 `wire_btn_track()`；`0x42 LAST_HID` 改为每条鼠标报告都更新（`last_rep_track()`）。不带这三处，测试会把"没统计到"误判成"丢键" | `components/makcu_hiddev/src/makcu_hiddev.c`、`app_left/main/control_bin.c` |
| 按键专项测试 | 模型 46 例（含事件通道调度模型 5 例，无硬件）+ 真机 `test_button_integrity.py` 10 例 + `test_button_order.py` 2 例 + **`test_button_sumv_concurrency.py` 3 例（按键 × 二进制 SUMV 并发，70 次/秒零丢失）**；11-12 全量回归 **124 passed** | `verification/model/`、`verification/regress/test_button_*.py` |
| 按键 × SUMV 并发用例 | 70 次/秒（半周期 7143 µs）与 `0x36 SUMV`（12 ms 周期、mode 0/2）并发跑 700/150 点击；硬判据：边沿 = 2N、`direct_chg+queued_chg == wire_chg`、`btn_cmds == 2N`、`overflow == 0`、结束不卡键、SUMV 有位移 | `verification/regress/test_button_sumv_concurrency.py` |
| 按键审计探针 | `0x3E HID_STAT`（10 B）、`0x3F BTN_AUDIT`（12 B，`extra = max(0, out_chg − in_chg)`） | `docs/API-control-port.md` §3.x / §3.y |
| AIM 接口族 | `makcu_sumv_aim(dx,dy,max_ms,flags,dead_min)` + 12 B 状态；`0x40 AIM_RESET` 清累计、`0x41 EVT_RESET` 不再入环 | `components/makcu_sumv/include/makcu_sumv.h`、API §3.z |
| 光标增益 | 增益是**常数**（`px = 1.25 × counts`），无加速项；标定方法与数据见报告 | `verification/report/2026-11-11-px-gain.md`、`tools/px_cal.py` |
| 抖动排查 | 输出节拍器、重采样两套方案**已实现并证伪后移除**；保留 `mx.hz`/`mx.hi`/`mx.lh` 探针 | `docs/HANDOVER.md` §14.26 |

## 2026-11-12 晚：厂商通道重构（D47）

| 项 | 结果 | 代码 / 证据 |
|---|---|---|
| `mouse/` 新组件 | `mouse_vendor`（按 VID/PID 分发，零鼠标知识）+ `g3mpro`（协议集中、**零 I/O**）+ `vendor_chan`（通道，R1 走 legacy `0xA5`，预留 `0xB0/0xB1/0xB2`） | `mouse/**`、`docs/50-vendor-channel.md` |
| 根因 1：厂商 IN 被按键戳印 | 修复：戳印前用注入的过滤器判定，厂商帧永不被改写（DPI 不再显示 200） | `vf == vin` 成立 |
| 根因 2：`0xA5` 同步等应答 | 改一发即返回，回执由 `custom_hook` 异步记账（`osent/ofail`） | `vmax 108 ms` → 只见 30–40 ms 档 |
| 根因 3：实例 1 端点忙即丢帧 | 新增 `VEN_QD 8 × VEN_QLEN 64` 环形队列 + 完成回调续发 | `venq` 丢弃恒 0（修前 10 条丢） |
| 根因 4：短按抗抖改写厂商首字节 | 厂商帧走独立早退分支，不进抗抖/按键状态/12 位解码 | `in82==vin==vf`（修前差 8） |
| 根因 5：下行池满 + tick 量化 | 右片 16 深 OUT 队列 + 池空快路径 + `vout_task` prio 10；左片 `out_worker` prio 10 | `ofail 1 → 0` |
| 台架探针 | `mx.ox` 扩到 24 字段；新增 `mx.vd`（整帧校验和 + `ctl` 控制请求计数）；`mx.dl` 改回读确认（回 `km.dl`/`km.e`） | `docs/API-control-port.md` §6 |
| 刷机自动化 | `tools/flash_left_auto.ps1`：构建→`mx.dl`→刷→回读比对；启动用 `--after hard-reset` | 无需人工拔线 |
| 回归 | 真机 **124 passed**（3 min 43 s）+ 离线模型 46 passed；测试期间光标由 `conftest.py` 的 `CursorGuard` 钳在**屏幕右上角 240×140 安全区** | `verification/regress/conftest.py` |
| 撤回（勿重走） | ①`GET_REPORT` 返回缓存帧 ②右片补发 `SET_PROTOCOL/SET_IDLE` ③探测到变化自动重枚举 —— 三条都动不了接收器的推送行为 | `docs/50-vendor-channel.md` §10 |
| 已知限制 | 按鼠标**硬件 DPI 键** HECATE 不刷新（不是丢帧/不是解析错，是接收器行为）；按需求不做支持 | 同上 §11 |
