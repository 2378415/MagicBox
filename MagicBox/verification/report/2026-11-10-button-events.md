# 按键事件通道（订阅即消费）

> 2026-11-10 19:20–19:50 实施并上机验证。用户决策：**滚轮不推 / 只听真实鼠标 / 订阅谁就吃掉谁**。

## 1. 语义

```
订阅 mask（1=左 2=右 4=中 8=侧4 16=侧5）内的键：
  ① 真实鼠标按下/松开 → 控制口收到一条边沿事件
  ② 这些位从转发给 PC 的 HID 报告里被抹掉 → PC 完全看不到这次点击
mask 之外的键：照常透传，不产生事件
移动 / 滚轮：永不产生事件，也永不改变转发行为
盒子自己发出的按键（.km.left(1) / BUTTON 帧）：不产生事件
```

## 2. 接口

| cmd | 名称 | payload | 回包 |
|---|---|---|---|
| `0x39` | `EVT_CTL` | `enable u8, mask u8, push u8` | 无 |
| `0x3A` | `EVT_READ` | `count u8`（≤7） | `count u8` + `n × 8B` |
| `0x3B` | `EVT_STAT` | — | 12 B（见下） |
| `0xE1` | `EVT_PUSH` | `t_us u32, seq u16, mask u8, edge u8` | 设备主动推（异步段 0xE0–0xEF） |
| `.km.evt(1[,mask])` / `.km.evt(0)` / `.km.evt()` | 文本 | 订阅 / 取消 / 查询 | 回显 / `evt()\n<mask>` |

`EVT_STAT` 回包：`head_seq u16, count u8, overflow u32, mask u8, pending u8, cur u8,
last_fwd u8, flags u8`（bit0 enabled、bit1 push、bit2 auto_released）。

**事件记录 8 B**（READ 与 PUSH 同一布局）：`t_us u32 | seq u16 | mask u8 | edge u8`。

## 3. 关键边界（都已实测）

| 场景 | 行为 |
|---|---|
| 订阅瞬间某键已按住 | 该键继续透传到松开（避免 PC 卡按下），**下一次按下**才被消费 |
| 10 s 无心跳 | 自动取消订阅、恢复全透传，`flags.bit2` 置位 |
| 事件环满（32 条） | 覆盖最旧 + `overflow++`；`seq` 不回绕 |
| 重启 / 拔插 | 订阅不持久化 |
| 文本侧 | `.km.evt` 只做"订阅 + 消费 + 入环"，**不做文本事件推送**；事件用二进制 `EVT_READ`/`EVT_PUSH` 取 |

## 4. 实测（2026-11-10 19:45，`tools/link_probe.py --evt 0x08 --evt-selftest`）

```
订阅 mask=0x08（侧键4），push=1
  EVT  seq=0  t_us=11605117  mask=0x08  edge=0x08      ← 按下（被吃掉）
  EVT  seq=1  t_us=12005041  mask=0x00  edge=0x08      ← 松开
  STAT seq=2  count=2  overflow=0  mask=0x08  pending=0  cur=0  last_fwd=0x00  flags=0x03
```

`last_fwd=0x00` 就是"PC 侧什么都没看到"的直接证据；未订阅的左键注入后 `last_fwd=0x01`（照常转发）。
`mx.ev` 同内容可读。11.5 s 不发心跳 → `enabled=0 auto_released=1`，注入恢复透传（已实测）。

## 5. 文件清单

| 文件 | 内容 |
|---|---|
| `app_left/main/btn_evt.c/.h` | **新增**：事件环（32）、seq/overflow、边沿算法、pending 规则、失联看门狗、`last_fwd` 观测 |
| `app_left/main/control_bin.{c,h}` | `0x39/0x3A/0x3B` + `0xE1` 推送（`build_frame` 泛化，回包才加 `|0x80`） |
| `app_left/main/app_main.c` | 两处转发分支接 `btn_evt_filter()`（sumv 屏蔽分支 + 正常 verbatim 分支，后者需要改写信封副本）；`mx.ev` 探针；`btn_evt_init()` 与 hook 装配 |
| `components/makcu_proto/src/cmd_evt.c` + `makcu_evt_hooks.{h,c}` | **新增**：`.km.evt` 文本命令（opcode 0x1D，表 29→30） |
| `tools/link_probe.py` | `--evt MASK [--evt-seconds N] [--evt-selftest]`：订阅 + 打印事件 + 心跳 + 取消 |
| `docs/API-control-port.md` | 新增 §5.7 按键事件、命令表 4 行、`mx.ev` 探针、版本表 |
| `docs/HANDOVER.md` | §14.22 |

## 6. 这一轮踩到的三个坑

1. **`.km.lfx` 是无效写法**：控制口会把 `.km.` 前缀剥掉，台架命令必须以 `mx.` 开头（`mx.lfx ...`）。
   探针里写错前缀导致"订阅了却收不到事件"，排查了一轮。
2. **`EVT_READ` 与 `EVT_PUSH` 的记录顺序不一致**：结构体是 `t_us` 在前，而推送帧一开始按 `seq` 在前构造
   → 上位机要写两套解码。现在统一成 `t_us, seq, mask, edge`。
3. **`heal_task` 的"每 5 s 自查 if_count"把回归打翻了**：残 clone 自查触发重克隆 + `tud_disconnect/connect`，
   控制台日志插进协议流、HID 重新枚举，逐字节比对的用例直接失败（`W … re-enumerated with the new clone`
   出现在回包里）。已回退为"只在设备出现通知时检查"，残 clone 靠开机那一层兜底。

顺带修掉三个**易碎断言**：`test_large_move_is_split_and_sums_exactly`、`test_two_axis_split_sums`、
`test_curved_path_bows` 原来是"只看 trace 末 N 条求和"，16 条环形里混进别流量就偶发失败；
改成用 `mx.rt` 累计位移断言守恒 + 用 trace 断言单步不超 int8。

## 7. 回归

```
100 passed in 132.77s
```

## 8. 未做 / 建议

| 项 | 说明 |
|---|---|
| 真鼠标人工验收 | 需要人在订阅期间按侧键：PC 侧应完全无反应、控制口收到两条事件（本轮用 `mx.lfx` 注入等价验证） |
| 文本事件推送 | 目前文本侧只能订阅 + 入环；若要 `km.evt(...)` 行推送，需要在推送回调里再走一条文本写 |
| 残 clone 兜底 | 目前靠开机重试 + `mx.rs`；若要更稳，可做一个"低优先级、只在空闲时（无报告流量 2 s）才重克隆"的自愈任务 |
