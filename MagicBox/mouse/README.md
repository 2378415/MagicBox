# mouse/ — 厂商通道（HECATE / G3M PRO）

盒子把三方搅在一起的东西拆成三块：**通道**负责搬、**驱动**负责懂、**上层**只做接线。

```
mouse/
├── include/mouse_vendor.h   统一驱动接口（零鼠标知识，上层只认这个）
├── include/g3mpro.h         G3M PRO 协议事实（帧布局、命令表、时限）
├── include/vendor_chan.h    0xB0/0xB1/0xB2 专用通道 API
└── src/
    ├── mouse_vendor.c       按克隆身份挑驱动；不匹配 = 纯透传
    ├── g3mpro.c             ★ G3M PRO 全部协议知识，不做任何 I/O
    └── vendor_chan.c        通道：搬运 + 统计（R2 起加队列/ACK）
```

## 硬规矩（都是踩过的坑）

1. **`g3mpro.c` 不碰 I/O。** 只做判定、记账、节流、应答期望。任何"等 ack"都不许出现在这里。
2. **通道不许抢 `makcu_link_set_custom_hook` 的单槽。** 它归 `app_main` 的 0x1E/0x1F。厂商通道只用
   `makcu_link_add_custom_hook(0xB0, 0xB2, …)` 注册自己的区间；重叠加会返回 false。
3. **`makcu_hiddev` 不许出现协议判断。** 厂商帧判定通过 `makcu_hiddev_set_ven_filter()` 注入，
   由驱动回答"是不是厂商帧"。
4. **超时一律按 tick 算。** `CONFIG_FREERTOS_HZ=100` ⇒ `vTaskDelay(1)` 是 10 ms。
5. **一次只改一层。** R1（本目录首个版本）不改变任何线路行为，只是把知识搬了家；
   打开 `MB_VENDOR_CHANNEL` 才走 0xB0。

## 链路帧（UART1，5 Mbaud，与 0xA2 完全并列）

| 帧 | 方向 | 载荷 |
|---|---|---|
| `0xB0` | 左→右 | `<seq:u8><ep:u8><len:u16><data…>` 主机 OUT 下行 |
| `0xB1` | 右→左 | `<seq:u8><ep:u8><len:u16><data…>` 设备 IN 上行（`MAKCU_LINK_B1` 的正式用途）|
| `0xB2` | 右→左 | `<seq:u8><rc:u8>` 受理 ACK，`rc=0` |

## G3M PRO 事实（`g3mpro.h` 里都有常量）

| 项 | 值 |
|---|---|
| 身份 | `320F:706E`，接收器族 `0E8C/0ECC/06CC/068C:F0Dx`（别名映射后统一） |
| 厂商帧 | **64 B 且 `[0]==0x04`**，OUT/IN 同款，IN 尾部常带 `ff` |
| 端点 | 主机侧 IN `0x82` / OUT `0x03`；设备侧 IN `0x82` / OUT `0x05` |
| 心跳 | `04 aa 00 aa 00 00 00 00 ff`，约 1.2 s 一次，不等应答 |
| 配置写最小间隔 | **40 ms**（回放实测 30 ms 丢 5–9%，40 ms 零丢） |
| 命令表 | `AA` 电量/心跳、`02` 配置读、`1B/1D/1F/20` 信息读、`35` DPI 写、`37` 提交、`56/7F/90` 轮询 |
| DPI 流程 | `READ(02) → WRITE(35) → COMMIT(37) → 回读(02)` |

## 台架探针

`mx.ox` 前缀字段不变，追加：

```
...,drv=g3mpro,vf=<hiddev 判定命中>,vout=<OUT 帧>,vin=<IN 帧>,vdup=<重复帧>,vdpi=<状态机>,vch=<tx/fail/rx>
```

## 已知限制（2026-11-12 定论，不做支持）

**按鼠标上的硬件 DPI 键，HECATE Connect 的显示不会跟着变。**

实测证据（左片整帧取样，`mx.vd` 比对 64 字节）：

| 观察 | 结果 |
|---|---|
| 按键后 EP0x82 是否出现主动帧 | 没有；OUT:IN 始终 1:1 |
| 心跳 `0xaa` 回包内容 | 64 字节**完全不变**（校验和一致） |
| HECATE 是否重新读（`0x02`/`0x1d`） | 按键后不再发，`ctl` 计数只有周期性 SET_REPORT |
| 控制端点 GET_REPORT | HECATE **从不使用**（`ctl` 里只有 `S1/rid0/ty2/len64`） |
| 接收器直插电脑时 | 会同步（说明是接收器在 PC 侧才会推送） |

尝试过并已撤回的三条路：①GET_REPORT 返回缓存帧；②右片补发 `SET_PROTOCOL/SET_IDLE`；
③盒子探测到状态变化后自动重枚举 USB。三条都改变不了接收器的推送行为。

**唯一有效的手段是让设备重新枚举**（手工拔插左侧数据线后 HECATE 会立刻读到新值）。
按需求这是一个可以接受的限制：把 DPI 改成在 HECATE 里点（那条路径已完全正常、快速）。

## 阶段

| 阶段 | 内容 | 行为变化 |
|---|---|---|
| **R1**（本次） | 组件 + 协议集中 + 回调注入 + 区间钩子 | 无（仍走 0xA5） |
| R2 | `MB_VENDOR_CHANNEL=1`：`0xB0` + `0xB2` ACK，右片同步实现 | 通道切换 |
| R3 | 右片 OUT 队列（16 深 + 池满重试） | 消除"池满丢 OUT" |
| R4 | DPI 状态机接管（按上表时序注入、失败重试） | 修正 DPI 显示/切换 |
