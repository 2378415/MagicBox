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
