> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）

# 40-status：执行状态（本文件由 `tools/status.py` 生成）

## 构建（T1）

| app | 构建 | app.bin | elf |
|---|---|---:|---:|
| app_left | ✅ 成功 | 299872 B | 4949492 B |
| app_right | ✅ 成功 | 216768 B | 3979116 B |

原始镜像对照：LEFT 403,536 B / RIGHT 341,824 B（当前重建只含骨架与表，厂商代码尚未移植，所以远小于原镜像）。

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
| 函数指纹 + P0 基线工具 | 完成；严格哈希门槛未过（0.9%），需改模糊匹配 | `tools/lib_fingerprint.py` |
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
| 烧录 + 回归（T2） | 已上机 18 次；最新一轮 **119 passed / 0 failed**（95 上机 + 24 离线模型；清洁构建，`MB_TUSB_DEBUG` 构建会把日志混进回包、不能跑回归） | `verification/report/` |

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

## 上机记录

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
- [`2026-11-09-flash-run-3.md`](../verification/report/2026-11-09-flash-run-3.md)
- [`2026-11-09-flash-run-4.md`](../verification/report/2026-11-09-flash-run-4.md)
- [`2026-11-09-flash-run-5.md`](../verification/report/2026-11-09-flash-run-5.md)
- [`2026-11-09-flash-run-6.md`](../verification/report/2026-11-09-flash-run-6.md)
- [`2026-11-09-flash-run-7.md`](../verification/report/2026-11-09-flash-run-7.md)
- [`2026-11-09-flash-run-8.md`](../verification/report/2026-11-09-flash-run-8.md)
- [`2026-11-09-flash-run-9.md`](../verification/report/2026-11-09-flash-run-9.md)
- [`2026-11-09-flash-run.md`](../verification/report/2026-11-09-flash-run.md)

## 端口面统计

| 组件 | 待移植函数数 |
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

合计待移植：**0** 个 —— `handlers.def` 现为 **27/27 implemented**（2026-11-10 核档）。
早前记录的“62 个待移植函数”是旧口径，已作废。

## 下一步（按顺序）

1. 补 `0xA0` EP0 应答 + 把 `0xA2` 重组数据装进 clone 仓库（克隆完整闭环）；
2. 实现 `makcu_serial_read_hook`（序列号查询 / 恢复 / 写入三模式）；
3. 用右片（V3.7）配置反查 UART1 真实引脚，替换占位 17/18；
4. 把 P0 基线换成模糊匹配（同尺寸桶 + difflib ≥0.9 记命中），修正 `sdkconfig` 直到 ≥95%；
5. 想要“手感”与出厂一致，再啃 `0x4200EFEC` 的浮点曲线（需 USB 分析仪对照出厂轨迹）。

---

## 2026-11-10 收官：右片自编固件 + 双接口 + 管理程序打通

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
