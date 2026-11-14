# MAKCU 双芯片盒子 · 现有功能文档

> 版本：2026-11-12（左片台架固件 355,040 B / 发布版 337,664 B，右片 292,624 B；真机回归 **128 passed**，离线模型 **46 passed**，合计 174 例全绿）
> 范围：只描述**当前已实现且可验证**的功能。历史改造与失败尝试见 `docs/30-decisions.md` D46
> 与 `verification/report/2026-11-12-button-event-channel-attempt.md`。

---

## 1. 系统架构

| 角色 | 芯片 | 职责 |
|---|---|---|
| 左片 | ESP32-S3（USB Device 侧） | 对 PC 呈现克隆鼠标/键盘；接收右片透传报告；执行 SUMV 引擎；控制口协议 + 诊断 |
| 右片 | ESP32-S3（USB Host 侧） | 接真实鼠标/键盘，解析 HID 报告，经 UART1 送给左片 |
| 左↔右 | UART1，**5,000,000 8N1**（TX/RX 交叉：左 TX=GPIO2、RX=GPIO1） | 自定义成帧：7 字节鼠标报告、键盘报告、厂商帧 |

- 左片对 PC 呈现的是**克隆真实鼠标的描述符**（复合接口：鼠标 0x81 / 键盘+厂商 0x82）；
- 出货构建不带 `MB_DEBUG_OPCODE`（台架命令不可用）；测试构建加 `-DMB_DEBUG_OPCODE=ON`。
- **发布版（2026-11-12 实测）**：`app_left\build\makcu_left.bin` = 337664 B（台架版 353904 B），
  不含任何 `mx.*` 台架命令；构建参数、刷写与回刷流程见 `docs/HANDOVER.md` §5.1。

---

## 2. 控制口协议

### 2.1 文本口（App 主用）

- 波特率 **921600**（CH343 → COMx），命令以 `\r` 结尾，回包形如 `km.<内容>\r\n>>> `
- 命名空间：`.km.*`（App 协议）、`mx.*`（台架/诊断，仅测试构建）
- 命令族：
  - 设备信息：`.km.version()`、`.km.catch()`（`+0x168` 写 / `+0x124` 读语义仍在核对）
  - 移动：`.km.move(dx,dy)`、`.km.moveext(...)`、`.km.wheel(n)`、`mx.rt`（累计位移回读）
  - 按键：`.km.left/right/middle/front/ms1/ms2`、`.km.buttons(mask)`、`.km.lock_*`
  - 会话/通道：`.km.switch(...)`、`mx.ss <hh>`（固定会话号）

### 2.2 二进制口（高倍率/低延迟）

帧格式：`5A <cmd> <seq> <len_lo> <len_hi> <payload…> <crc8>`；`crc8 = poly 0x07`，覆盖 `cmd..payload`（不含 `5A` 与 CRC 自身）。回包 `cmd|0x80`，`seq` 匹配。

| opcode | 名称 | 载荷 / 回包 | 说明 |
|---|---|---|---|
| `0x32` | BUTTON | `mask u8`（bit0 左 / bit1 右 / bit2 中 / 0x08、0x10 侧键） | **强制立即上线**，不受释放守卫窗口影响 |
| `0x36` | SUMV | `dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]` | 瞄准引擎（恒速/队列） |
| `0x37` | SUMV_STOP | — | 中止并保留已走部分 |
| `0x38` | SUMV_STATE | 回 **29 B** | `active, samples, aborted, rounds, muted, fwd, speed_eff, remain` |
| `0x3E` | HID_STAT | 回 **16 B** | `in, sent, wait, overflow, flood, merged, cancel, wire_chg` |
| `0x3F` | BTN_AUDIT | 回 **12 B** | `in_chg, out_chg, extra` |
| `0x40` | AIM_RESET | — | 清累计 |
| `0x41` | EVT_RESET | — | 清事件环 |
| `0x42` | LAST_HID | 回 **20 B** | 最近一条报告原始字节、`hist[8]`、`stamped` |
| `0x44` | BTN_LOG | 变量 | 按键轨迹（`t_us, seq, mask, edge`） |
| `0x45` | BTN_CNT | 回 **54 B** | 见 §5.3 |

---

## 3. 鼠标功能

| 功能 | 状态 | 说明 |
|---|---|---|
| 相对移动 / 绝对脉冲 | 已实现 | 位移守恒，`mx.rt` 回读累计 counts |
| 滚轮 / 横向 pan | 已实现 | 7 字节克隆布局下原样转发 |
| 六键（左右中、前、侧 1/2） | 已实现 | 掩码 `0x01/0x02/0x04/0x08/0x10` |
| 曲线 / 步进切分 | 已实现 | 单报告 ≤127 counts，自动分段且守恒 |
| 键盘报告 | 已实现 | 左片第二接口（0x82）转发 |
| 厂商自定义帧 | 已实现 | 0x82 上 OUT/IN 透传（键鼠 SDK） |

---

## 4. SUMV 瞄准引擎

- 模式：`mode 0`（恒速直走）、`mode 1`（队列逐条）、`mode 2`（队列合并 / REPLACE 语义）；
- `speed` = counts/s，`dur_ms` 可选；`0x37` 中止保留已走位移并计 `aborted`；
- 状态可观测：`active / samples / aborted / rounds / muted / fwd / speed_eff / remain`；
- 与按键并发：**70 次/秒点击 + 12 ms 周期 SUMV 零丢失**（mode 0 与 mode 2 均验证）。

---

## 5. 按键完整性机制

### 5.1 数据通路

```
真实鼠标 → 右片 → UART1 → 左片 link sink(0xA2)
                                ├─ 透传：makcu_hiddev_passthrough() → 直发 / 排队
                                └─ 引擎：makcu_mouse → makcu_hiddev_report() → 同一条发送路径
0x32 BUTTON → makcu_mouse_emit_event() → 零位移报告（立即上线）
```

### 5.2 关键机制

| 机制 | 作用 |
|---|---|
| 独立 URG 按键队列（深 64，满时等空位 ≤10 ms） | 运动 FIFO 挤不掉按键 |
| 出队改写（方案 A） | 队列里"按下前"的旧报告出队时把 byte0 低 5 位改成最新线上状态，避免状态倒回 |
| 运动报告按键位戳印 | 引擎报告在发送时对齐 `s_wire_btn_last`，不制造/不吞掉边沿 |
| `0x32` 强制立即上线 | 显式注入不是物理抖动候选，绕开 2 ms 让路窗口 |
| 注入主持权窗口（200 ms） | 注入期间透传报告按键位对齐线上状态（运动字节原样），线上只保留一个状态源 |
| 释放守卫 `mx.gd <0..50>` | 默认 20 ms 抗微动抖动；`0 = 关闭`（零丢失模式）；裸调用读当前值 |
| 会话固定 `mx.ss` | 台架注入必须匹配会话号，否则帧被忽略 |

### 5.3 `0x45 BTN_CNT`（54 B）字段

| 偏移 | 字段 | 含义 |
|---|---|---|
| 0 / 4 / 8 / 12 | `frames / nonzero / fwd_drop / swallowed` | 链路帧数、非零按键帧、转发丢弃、抗抖吞掉 |
| 16 / 17 | `last_ep / last_len` | 最后一帧的端点与长度 |
| 18..25 | `last_frame[8]` | 最后一帧原始字节 |
| 26 / 30 / 34 / 38 | `btn_same / fwd_reports / rx_ovf / lf_drop` | 重复帧、转发报告数、控制口溢出、环回失败 |
| 42 / 46 | `direct_chg / queued_chg` | 直发 / 队列两条路径各自"引入的按键变化" |
| 50 | `btn_cmds` | 收到的 `0x32` 帧数 |

**零丢失硬判据**：`direct_chg + queued_chg == wire_chg == 2 × 点击次数`，且 `btn_cmds == 2 × 点击次数`。

---

## 6. 设备克隆

| 功能 | 命令 | 说明 |
|---|---|---|
| 克隆真实鼠标描述符 | 上电自动 / `mx.ac`（立即重克隆） | 抓右片侧真实设备后按原描述符服务 |
| 读克隆状态 | `mx.if`（接口表）、`mx.rb`（报告字节数） | `2 93:81:0 158:82:1` = 复合健康态 |
| 出厂夹具 | `mx.cl <n>` | 测试用的 4 字节描述符夹具（用完需恢复） |
| 重启重克隆 | `mx.rs` | 深恢复手段 |

---

## 7. 台架/诊断命令（仅 `MB_DEBUG_OPCODE` 构建）

| 命令 | 功能 |
|---|---|
| `mx.hk 0/1` | 0xA2 是否进 HID 路径（计数类断言前需 `mx.hk 0` 隔离真实鼠标流量） |
| `mx.ss <hh>` | 固定/查看会话号 |
| `mx.lf a2 <hdr> <payload>` / `mx.lfx` | 环回注入一帧（高倍率下会丢帧，仅台架） |
| `mx.dl` | 进入 ROM 下载模式（刷机）；回 `km.dl` = 标志置位成功、`km.e` = 写不进 |
| `mx.gd [0..50]` | 真实鼠标短按抗抖窗口（ms，默认 20，0 = 关闭） |
| `mx.vd` | 厂商帧整帧取样：最近 8 条互不相同的 OUT/IN + 整帧校验和，末尾 `ctl=` 控制请求计数 |
| `mx.ox` | 厂商通道主探针（2026-11-12 扩到 24 字段：`drv/vf/vout/vin/vdup/vdpi/vch/osent/ofail/venq/v82/vl/va/vmax/vp50/vp99/v82h/b81`） |
| `mx.hs / mx.hz / mx.ei / mx.bo / mx.xt / mx.fv / mx.ln / mx.hi / mx.mt / mx.rt` | HID 统计、节拍、最后直送报告、按键位 OR、OUT 回调、自检、固件身份、原始写出、右片 host 状态、运动追踪环、累计位移 |
| `mx.mt on/off/clr/d` | 运动追踪环录制 / dump（配合 `tools/trace_motion.py`） |

---

## 8. 测试与工具

| 类别 | 内容 |
|---|---|
| 硬件回归 `verification/regress` | **124 例**：文本/隐藏 opcode 协议、真实报告解析、克隆描述符、链路桥、键盘与右片帧、SUMV 9 例、按键完整性 T1–T10、按键顺序 2 例、**按键 × SUMV 并发 3 例（70 次/秒零丢失）** |
| 离线模型 `verification/model` | **46 例**：贝塞尔路径、按键队列模型、按钮事件通道调度模型、克隆描述符、右片回复、步进引擎 |
| PC 侧真值校验 | `tools/verify_buttons_usb.py`：USBPcap 抓 PC 侧边沿 ↔ 固件 `wire_chg` 对账；`--inject bin`（0x32 二进制注入）、`--gap-us`（精确速率）、`--binary-sumv`（并发负载） |
| 压力 / 轨迹 / 标定 | `tools/aim_stress.py`、`tools/trace_motion.py`、`tools/px_cal.py`（增益 1.25 px/count）、`tools/p0_baseline.py`、`tools/trace_opcodes.py` |
| 报告 | `verification/report/`：像素增益标定、按键事件通道尝试与边界扫描（65/70/75/80 档） |

---

## 9. 能力边界（实测）

| 项目 | 结论 |
|---|---|
| 按键不丢 | **≤75 次/秒点击（含 AIM 1 kHz 并发）严格 0 误差**（70 / 75 档多轮 PASS） |
| 80 次/秒 | ±1 边沿（≈0.06%），属注入事件与运动/透传报告同毫秒的竞态 |
| 人手 / 连点宏（≤20 次/秒） | 余量 4–7 倍，完全无感 |
| 台架 `mx.lf` 文本注入 | 33 次/秒即掉 1–2 帧（控制口行解析 + 环回），**高倍率必须用 `--inject bin`** |
| 复位 / 救砖 | BOOT+插线 → COM8 刷写 → COM9 watchdog 复位（COM8 的 RTS 复位在本板常不生效） |

---

## 10. 已知限制与未完成项

1. **单写者事件通道未落地**：两次上机启动即挂（`km_btn` 任务，栈 3072 / 4096 均复现），需 JTAG panic 日志才能继续；
2. **80 次/秒 ±1** 只能靠上述重构消除，当前不做；
3. `catch` 的 `+0x168` 写 / `+0x124` 读不对称，待 JTAG 最终确认；
4. 注入主持权窗口（200 ms）期间，物理点击的按键位会让位于注入状态（运动不受影响）——"单一状态源"的代价，窗口大小可调；
5. `0x45` 长度随固件演进（26 → 34 → 42 → 50 → 54 B），老客户端应按长度取前缀字段。

---

## 11. 相关文档

| 文档 | 内容 |
|---|---|
| `docs/HANDOVER.md` | 交接总览、探针速查、上限口径、救砖流程 |
| `docs/API-control-port.md` | 控制口协议逐字段说明 |
| `docs/30-decisions.md` | 设计决策（含 D46 按键链路与边界） |
| `docs/40-status-appendix.md` | 状态附录（功能 → 代码落点） |
| `verification/report/2026-11-12-button-event-channel-attempt.md` | 事件通道尝试、边界扫描、主持权窗口修复 |
