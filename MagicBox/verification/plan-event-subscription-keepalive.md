# plan：按键事件订阅保活 / 自愈（固件 + 手机端）

> 状态：**已实施**（2026-11-18）。本文是指南，落地细节见各源文件注释。
> 动机：长跑实测/代码审计发现"订阅过但事件突然停"且不会自己恢复；D50 的 u32 回绕
> 不在事件路径，但订阅看门狗与发送任务两个真实故障点没有局部自愈。

---

## 1. 现状根因（代码审计结论，非文档口径）

| 场景 | 现象 | 根因（位置） | 自愈 |
|---|---|---|---|
| `push=1` 后上位机只收 `0xE1`、不发心跳 | ~10 s 后事件停，按键恢复透传 | `btn_evt.c:188` `evt_watchdog()` 10 s 无心跳 → `btn_evt_ctl(false,...)`；`flags bit2=1` | 透传恢复，**订阅不恢复** |
| `km_evttx` 创建失败 | `evsent` 不涨、`evdrop` 涨至满 | `app_main.c:2714` else 分支只打日志；`app_main.c:2652` 控制任务已不泵送 | 无 |
| `km_evttx` 卡在 `uart_write_bytes` | 同上 | `app_main.c:2665` `portMAX_DELAY` + `control_write()` 无超时 | 无 |
| `seq` u16 回绕 / `EVT_RESET` 清零 | 每 65536 事件归零 | `btn_evt.c:93,106` | 上位机按 u16 模判缺口即可 |
| D50 式 71 min 回绕 | 未复现 | 事件看门狗 `s_last_hb_us` 是 int64（`btn_evt.c:32`） | 不适用 |

设计原则：**订阅决策权归手机端**；固件只记住最后意图、在客户端确实回来时恢复，
永不擅自替显式退订的客户端重新订阅。

---

## 2. 固件侧整改

### 2.1 记住订阅意图（自动重订阅基础）
- `btn_evt.c` 新增影子变量 `s_want_enabled/mask/push/consume`，仅由显式
  `EVT_CTL(enable=1,...)` 写入；`enable=0` 清空。
- 10 s 看门狗超时只清活跃订阅、置 `auto_released`，**保留**影子变量。
- 区分两种"未订阅"：`auto_released=1`（失联可恢复）vs `enabled=0 && auto_released=0`
  （显式退订，不可恢复）。

### 2.2 自动重订阅
- 触发：`s_auto_released && s_want_enabled` 且收到任一合法心跳
  （`EVT_CTL/EVT_READ/EVT_STAT/PING(len>=4)`，均已有 `btn_evt_heartbeat()`）。
- 动作：`btn_evt_heartbeat()` 内除更新时间戳外，用影子参数调 `btn_evt_ctl(true,...)`；
  该函数第 78 行 `s_prev_watched = cur & mask` 以当前按键状态为边沿基准（防假边沿），
  第 72 行重建 `pending`（防 consume 模式卡按下）。
- 时序：心跳到达即恢复（毫秒级）；看门狗周期 1 s、超时 10 s 保持不变（9 次容错）。
- 可观测：`auto_resume_cnt` 计入 `EVT_STAT` 与 `mx.ev`。

### 2.3 任务看门狗与重建
- `evt_tx_task` 维护 `s_evt_tx_last_progress_us`（有进展时更新）与 `s_evt_tx_alive`。
- 复用 `km_heal`（prio 4）每 1 s 检查：`cb_evt_pending() && now-last_progress>3s`
  连续 2 次 → 判定卡死。
- 重建：`vTaskDelete(evt_tx)` → `xTaskCreate(evt_tx_task, prio 11)` →
  `cb_set_wake_task(new)` → `xTaskNotifyGive(new)` 补发积压；失败按 1/2/5 s 退避，
  最多 3 次，之后置 `s_evt_tx_broken` 停重试（防风暴）。
- `control_write()` 加 `uart_wait_tx_done(..., pdMS_TO_TICKS(5))`（=50 ms，HZ=100）
  超时则丢帧计 `tx_timeout`，使任务不可能永久阻塞在写里。
- 创建失败分支不再谎称"退回控制任务泵送"，交给看门狗重建。

### 2.4 固件自愈能力表
| 能力 | 触发 | 恢复 | 观测 |
|---|---|---|---|
| 10s 失联退订（已有） | 10 s 无心跳 | 恢复全透传，保留意图 | `flags bit2=1` |
| 失联后自动重订阅（新） | bit2=1 + 心跳 | 影子参数重订阅 | `auto_resume_cnt` |
| 任务卡死重建（新） | 待发且 >3 s 无进展 ×2 | 删除/重建 + 补通知 | `rebuild_cnt`、`tx_timeout` |
| 队列满自愈（已有） | 64 深满 | 丢新事件，压力解除后恢复 | `evdrop` |

---

## 3. 手机端整改

### 3.1 周期心跳
| 参数 | 取值 |
|---|---|
| 命令 | `0x3B EVT_STAT`（回包带 flags，保活+检测二合一）；备选 `0x35 PING` |
| 间隔 | 1000 ms（可在 1000–2000 ms 配置，默认 1 s） |
| 线程 | `ControlPort` 内独立 `ScheduledExecutorService`，与推理线程解耦 |
| 启停 | 订阅成功启动；`enable=0`/断链停止 |
| 容错 | 单帧无回包不动作；连续 3 次无回包 → 走已有重连流程 |

`PING` 回包 uptime 须按 `low32 | (rp[11]<<32)` 组装（D50），勿只读低 32 位。

### 3.2 检测 bit2 自动重订阅
- 每次 `0x3B` 回包解析 `rp[11]`：`if ((flags & 0x04) && !(flags & 0x01))` → 触发。
- 重发 `0x39` payload `[1][mask][1][consume]`；mask/consume 取最后一次成功订阅值。
- 重试：检测当帧立即发 → 下一周期查 flags；失败按 1/2/5 s 退避，3 次后走重连并 UI 提示。
- 防重入：`mResubscribing` 标志；重订阅幂等（固件侧重发只是重置边沿基准）。

### 3.3 边界
| 场景 | 处理 |
|---|---|
| 息屏/后台被冻结 >10 s | 固件退订保安全；手机恢复后 bit2 检测 + 固件心跳恢复，双路径幂等 |
| 控制口被 PC 独占 | 心跳无回包 → 3 次后提示，不盲目重订阅 |
| `0x39` 被 CRC 丢 | 下周期重发（幂等） |
| `seq` 回绕 / `0x41` 清零 | 按 u16 模判缺口，不误判重订阅 |
| 重建期间 | 无感；短暂 `evdrop` 不触发重订阅 |

---

## 4. 交互流程

```
订阅：手机 0x39(1,mask,push=1,consume) → 固件记意图+激活+刷心跳 → 手机起 1s 心跳
正常：每 1s 手机 0x3B → 固件 flags(bit2=0)+刷新心跳；边沿 → 0xE1 → 手机统计 seq
失联：心跳停 >10s → 固件退订、透传、bit2=1、留意图
      手机恢复 → 0x3B 触发固件自动重订阅 + 手机检测 bit2 补发 0x39（幂等）
      下个心跳 flags bit2=0/enabled=1 → 双向确认
卡死：待发且 >3s 无进展 ×2 → km_heal 重建 km_evttx + 补通知 → 积压补发
退订：手机 0x39(enable=0) → 固件清意图、不自动恢复、手机停心跳
```

职责边界：固件记住意图 + 心跳恢复 + 任务重建，永不擅自替显式退订者订阅；
手机持续心跳 + bit2 检测 + 退避重订阅 + 失败上报。

---

## 5. 改动文件与验证

| 端 | 文件 | 改动 |
|---|---|---|
| 固件 | `app_left/main/btn_evt.h/.c` | 影子变量、heartbeat 升级、auto_resume_cnt、诊断字段 |
| 固件 | `app_left/main/control_bin.c/.h` | EVT_STAT 暴露新计数、EVT_CTL enable=0 清意图 |
| 固件 | `app_left/main/app_main.c` | tx 看门狗重建、创建失败修正、写超时、mx.ev 增字段 |
| 手机 | `core/ControlPort.java` | 1s 心跳、flags bit2 解析、0x39 重订阅、退避重试 |
| 手机 | `core/AimConfig.java` | 记住最后订阅 mask/consume（如无现成字段） |

验证：
- 固件 `idf.py build` 双端通过；真机 `mx.ev` 见新字段。
- 手机单测全绿；真机：停心跳 12 s 后恢复 → 自动重订阅；杀 `km_evttx` → 自动重建。
- 长跑 ≥30 min 无事件停摆。
