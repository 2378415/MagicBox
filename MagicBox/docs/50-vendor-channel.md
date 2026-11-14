# 50-vendor-channel：厂商通道（HECATE / G3M PRO）架构与修复记录

> 适用固件：2026-11-12 及之后（左片 `app_left` bench 构建 353,904 B、右片 `app_right` 292,624 B）
> 面向对象：改固件的人、写上位机的人、以及以后遇到"HECATE 卡/DPI 不对"的人
> 事实来源：本机实测（台架 `COM3` 计数器、整帧取样 `mx.vd`、逐次上机验证），不含推断

---

## 1. 一屏结论

1. **厂商通道已经从"混在鼠标报告链路里"抽成独立模块** `mouse/`：协议知识全部在 `mouse/src/g3mpro.c`，
   `app_main.c` 只做搬运与记账，`makcu_hiddev` 里不再出现任何"64 字节 / 首字节 0x04"之类判断。
2. **三个真实根因已修**（都有计数器证据，见 §5）：厂商帧被按键戳印（DPI 显示 200）、
   厂商 IN 端点忙时直接丢弃（答复蒸发→HECATE 等超时）、`0xA5` 同步等应答（卡好几秒）。
3. **实测状态**：鼠标运动 570 帧/s、右片 `fail=0`；厂商通道 `out==vin==vf`、`ofail=0`、
   队列丢弃 0；单次厂商往返 `vp50 ≈ 31–39 ms`（直连基线 6.6 ms）。
4. **已知限制一条**：按鼠标上的**硬件 DPI 键**，HECATE 显示不刷新（接收器不经盒子推送该变化）。
   三条修法都试过并已撤回，按需求不做支持，见 §11。

---

## 2. 目标与非目标

| | 内容 |
|---|---|
| 目标 | ① 厂商协议知识集中在单一模块；② 厂商 IN/OUT 不再与 1 kHz 运动报告争抢、不再丢帧；③ DPI 读/写/显示正确且快速；④ 每一步都有计数器可验证 |
| 非目标 | ① 不解析/改写 64 字节厂商载荷（纯透传，`plan-hecate-connect-proxy` 既有结论）；② 不动运动/按键通道语义；③ 不实现"硬件 DPI 键 → HECATE 同步"（见 §11） |

**硬不变量**（改动时不得破坏）：

1. `0xA2` 运动/按键链路语义零改动；
2. `makcu_link_set_custom_hook()` 的单槽归 `app_main` 的 `0x1E/0x1F`，厂商模块**只能**用区间钩子；
3. `makcu_hiddev` 不出现协议判断，厂商帧判定通过 `makcu_hiddev_set_ven_filter()` 注入；
4. 所有超时/延时按 tick 计算（`CONFIG_FREERTOS_HZ=100` ⇒ `vTaskDelay(1)` = **10 ms**）。

---

## 3. 架构与数据流

```
PC（HECATE Connect）
 │  ① 控制端点 SET_REPORT(Output, rid=0, 64B)  ← 实测 HECATE 的配置/轮询全走这条，不用 GET_REPORT
 │  ② 中断 IN  0x82（64B 厂商答复）
 ▼
左片 ESP32-S3（USB device，克隆设备 320F:706E）
 ├── makcu_hiddev        TinyUSB；实例 0 = 鼠标 / 实例 1 = 键盘+厂商
 ├── mouse/              ★ 本次新增：mouse_vendor（分发）+ g3mpro（协议）+ vendor_chan（通道）
 ├── app_main            搬运 + 记账 + 台架探针（不含协议知识）
 ├── makcu_link_bridge   UART1 帧层 + 区间钩子数组
 └── makcu_clone         描述符克隆（决定 inst 与 report id）
        │  UART1 5 Mbaud
        ▼
右片 ESP32-S3（USB host）
 ├── makcu_hidhost       枚举 / IN 武装 / EP0 控制 / OUT 提交
 └── app_main            0xA5 OUT 提交队列（16 深）+ 快路径
        │
        ▼
G3M PRO 接收器（320F:706E，端点 81:00 / 82:05）
```

三条互相独立的路径：

| 路径 | 方向 | 落点 | 队列 |
|---|---|---|---|
| 运动/按键 | 右→左→PC | `0xA2` → `link_report_to_mouse()` → `report_verbatim_ep(0x81)` | `REP_QD 32 × REP_QLEN 8` + 按键专用 `URG_MAX 64` |
| 厂商下行 | PC→右→鼠标 | `tud_hid_set_report_cb` → `out_to_right()` → `vchan_out()` → `0xA5` → `makcu_hidhost_out_async(ep=0x05)` | 左 `OUTQ_DEPTH 6 × OUTQ_MAX 80`；右 `VOUT_QD 16 × VOUT_MAX 64` |
| 厂商上行 | 鼠标→右→PC | `0xA2(ep=0x82)` → **厂商早退分支** → `ven_push(inst=1)` → EP0x82 | `makcu_hiddev` 的 `VEN_QD 8 × VEN_QLEN 64` |

---

## 4. `mouse/` 组件接口契约

| 文件 | 职责 | 关键 API |
|---|---|---|
| `mouse/include/mouse_vendor.h` | 驱动表（**零鼠标知识**） | `mouse_vendor_init(vid,pid)` / `mouse_vendor_current()` / `mouse_vendor_is_vendor_frame()`（记账用，64B） / `mouse_vendor_is_vendor_port()`（路由用，任意长度） / `mouse_vendor_on_host_out/on_dev_in()` |
| `mouse/include/g3mpro.h` | G3M PRO 协议常量与时限 | `G3M_VEN_LEN 64`、`G3M_VEN_RID 0x04`、`G3M_EP_OUT_DEV 0x05`、`G3M_MIN_WRITE_GAP_MS 40`、`G3M_ACK_WAIT_MS 20`、`G3M_RESEND_MAX 2`、命令字 `0xAA/0x02/0x1B/0x1D/0x1F/0x20/0x35/0x37/0x56/0x7F/0x90` |
| `mouse/src/g3mpro.c` | 协议实现，**不做任何 I/O** | `g3mpro_is_vendor_frame()` `g3mpro_is_vendor_port()` `g3mpro_expects_reply()` `g3mpro_min_gap_ms()` `g3mpro_latency()` `g3mpro_dump_distinct()` |
| `mouse/include/vendor_chan.h` | 通道（R1 走 legacy 0xA5；R2 预留 `0xB0/0xB1/0xB2`） | `vchan_set_legacy_tx()` `vchan_set_in_sink()` `vchan_out(ep,d,n,wait_ack_ms)` `vchan_on_dev_in()` `vchan_on_frame()` `vchan_stats()` |
| `mouse/CMakeLists.txt` | 组件注册 | `REQUIRES makcu_link esp_timer` |

**契约约束**

1. `g3mpro_*` 是**同步纯函数**：只看帧、记账、节流、算延迟；任何"等应答"都不许出现在这里
   （历史上 `app_main` 内的同步 `0xA5` 等待就是这么把整条链路拖成秒级的）。
2. 通道与协议分离：`vendor_chan.c` 只负责搬运 + 统计，协议事实（40 ms 写间隔等）来自 `g3mpro.h`。
3. 上层（`app_main`）只认 `mouse_vendor.h` 的驱动表；未匹配（vid/pid=0 或不在别名族）时
   全部入口退化为"不记账、纯透传"，与迁移前行为一致。

**接线位置**（`app_left/main/app_main.c`）

| 行 | 内容 |
|---|---|
| 2589 | `xTaskCreate(heal_task, "km_heal", …, 4, …)` |
| 2595 | `xTaskCreate(out_worker, "km_outq", …, **10**, …)`（高于 1 kHz 报表流） |
| 2607–2609 | `mouse_vendor_init(vid,pid)` / `vchan_set_legacy_tx(legacy_out_send)` / `vchan_set_in_sink(vendor_in_sink)` |
| 2613 | `makcu_hiddev_set_ven_filter(mouse_vendor_is_vendor_frame)` |
| 2614 | `makcu_link_add_custom_hook(VCHAN_OUT, VCHAN_ACK, vchan_on_frame)`（区间 `0xB0..0xB2`） |
| 2626 | `xTaskCreate(control_port_task, "km_uart0", …, 10, …)` |

---

## 5. 五个根因与修复（都有实测数据）

| # | 现象 | 机制 | 修复位置 | 证据（修复前→后） |
|---|---|---|---|---|
| 1 | HECATE 里 DPI 显示 **200**（默认值） | `makcu_hiddev_passthrough()` 对**所有**报告做"按键主持权戳印"，厂商帧 `byte0=0x04` 被改成 `0x00`（`0x04 & ~0x1F`）→ 报告 ID 消失 → 主机错位一字节解析 | `components/makcu_hiddev/src/makcu_hiddev.c`：戳印前用注入的过滤器判定，厂商帧**永不被戳印** | `vf` 比 `vin` 少 8 帧（`in82=254/vin=254/vf=246`）→ 修复后 `vf==vin` |
| 2 | 卡好几秒 / 偶发未响应 | `out_worker()` 用 `makcu_link_request(0xA5, …, 600 ms)` 同步等回执，而该函数以 `vTaskDelay(1)` 轮询、tick=10 ms ⇒ 每条 OUT 至少压 10 ms，一次 DPI 切换十几~几十帧 | `app_main.c`：改 `makcu_link_send(0xA5, …)` **一发即返回**，回执改在 `custom_hook` 异步记账（`osent/ofail`） | `vmax 108 ms`、`vdup 88/254` → 修复后 `ofail=0`、`vdup` 比例大幅下降 |
| 3 | 答复凭空消失，HECATE 等超时重发 | 实例 1（EP0x82）在端点忙时**直接丢弃**（`s_ep_failed++`），没有队列 | `makcu_hiddev.c`：新增 `VEN_QD 8 × VEN_QLEN 64` 环形队列，完成回调 `tud_hid_report_complete_cb` 里续发 | `vf 251 / vin 261`（10 条丢）→ `venq=0/0/0/0`（一条没丢） |
| 4 | DPI 又变 200（第二处改写点） | `link_report_to_mouse()` 的**短按抗抖**对任何报告都改写 `byte0`（`fwd_buf[0] = (0x04 & ~0x1F) | btn`），且污染 `s_mute_btn/s_last_buttons/s_btn_or` | `app_main.c`：厂商帧走**独立早退分支**（记账 + 原样转发 + `return`），不进抗抖/按键状态/12 位解码任何一条路径 | `in82=254 / vin=254 / vf=246`（8 条被改写）→ 三分支计数全等 |
| 5 | 下行偶发丢一帧（`ofail=1`）；往返 31 ms 呈 10 ms 阶梯 | 右片 `makcu_hidhost_out_async()` 只有 3 个 DMA 槽，第 4 帧被拒；左右两侧厂商任务优先级低于 1 kHz 报表流，交接按 tick 轮转 | 右片 `app_main`：16 深 OUT 队列 + `vout_task`(prio 10) + **池有空槽就地提交**；左片 `out_worker` 提到 prio 10 | `ofail 1 → 0`；`vp50 31–39 ms`（量化窗口缩小，剩余为 UART1 上请求/应答排队） |

> **踩过的坑（务必不要重犯）**
> - 把"HID 补发请求"（`SET_PROTOCOL/SET_IDLE`）放在 `device_attached()` 里**同步**执行 → 该回调本身
>   跑在 host client 任务里，同步等控制传输的回调 = 自己等自己 → 右片事件任务死锁 → **鼠标完全不动**。
>   凡是要发控制传输，必须在独立任务里做。
> - 任何"在报告路径上等应答"的写法都会把秒级延迟带回来；厂商路径只允许异步发送。

---

## 6. 线程与优先级（实测配置）

| 任务 | 优先级 | 职责 | 备注 |
|---|---|---|---|
| `usb_lib`（右） | 12 | ESP-IDF USB host 库任务 | 不可下压 |
| `usb_cli`（右） | 11 | host client 事件 | 枚举/attach/detach |
| `km_outq`（左） | **10** | 消费 `OUTQ`，发 `0xA5` | 高于报表流，避免 tick 轮转 |
| `km_uart0`（左） | 10 | 控制口（台架命令） | |
| `km_vout`（右） | **10** | 消费 `VOUT_QD`，池满 2 ms 重试 ≤200 ms | |
| `km_link`（左） | 9 | UART1 收帧 + `0xA2` 分发 | 单任务逐字节 feed |
| `km_uart1`（右） | 8 | UART1 收帧 + 分发 | |
| `km_heal`（左） | 4 | 重克隆/自愈 | 非周期轮询 |

---

## 7. 台架探针手册

### 7.1 `mx.ox`（主探针，前缀 5 字段保持历史兼容）

```
<out>,<ok>,<in82>,ack=<rc>,<dropped>,<最后一条 OUT 前 8 字节>,
in82=<最后一条 0x82 前 8 字节>,
drv=<驱动名>,vf=,vout=,vin=,vdup=,vdpi=,vch=<tx>/<fail>/<rx>,
osent=,ofail=,
venq=<入队>/<发出>/<丢弃>/<深度>,
v82=<厂商端口帧>/<非 64B>/<最近非 64B 长度>,
vl=/va=/vmax=/vp50=/vp99=（µs）,
v82h=<最近非 64B 帧前 8 字节>,b81=<保留位次数>/<异常长度次数>/<长度>/<前 8 字节>
```

| 字段 | 判据 |
|---|---|
| `vf == vin` | 厂商 IN 一条没在盒子里被改写/丢弃（根因 1/4 的守门指标） |
| `venq` 第 3 项 = 0 | 实例 1 队列没有丢帧（根因 3 的守门指标） |
| `ofail = 0` | 下行没有被右片拒收（根因 5 的守门指标） |
| `vp50 / vp99 / vmax` | 单次厂商往返延迟；直连基线 p50 6.6 / p90 9.0 / max 19.6 ms |
| `vdup` | 连续重复帧数；异常高说明 HECATE 在重发（答复没到） |
| `vdpi` | 被动 DPI 状态机（`3` = 看见 `0x35` 写；正常静止为 `0`/`7`） |
| `b81` 第 1 项 | 0x81 上"保留位被用上"的帧数，正常恒 0 |

### 7.2 `mx.vd`（整帧取样器，不需要 USBPcap）

输出最近 8 条**互不相同**的厂商 OUT / IN 帧（cmd + 前 8 字节 + **整帧 64B 校验和** + 命中次数），
外加 `ctl=` 控制请求计数（`G/S + 实例 + report_id + type + len × 次数`）：

```
OUT: [aa]04aa00aa00000000$7850 x13  [1d]…$3e46 x1  …
IN : [aa]04aa00aa00000000$0471 x13  [1d]…$3c67 x1  …
ctl=71: S1:rid0/ty2/len64x71
```

判读：同一 cmd 出现**两组不同校验和**＝设备状态变了；`ctl` 只出现 `S1/ty2/len64` ＝ HECATE 只发
控制端点 SET_REPORT（实测从不发 GET_REPORT）。

### 7.3 其它相关命令

| 命令 | 用途 |
|---|---|
| `mx.hr` | `ready_fail, ready, suspended, mounted` |
| `mx.hi` | 右片 host 状态（`att/addr/id/itf/ep/gate/ok/fail/done/fwd`） |
| `mx.ls` | UART1 链路统计（frames / rx_bytes 必须持续增长） |
| `mx.gd [0..50]` | 真实鼠标短按抗抖窗口（默认 20 ms，0 = 关闭；仅影响 0x81 路径） |
| `mx.dl` | 重启进 ROM 下载器（回 `km.dl` 表示置位成功，`km.e` 表示写不进） |

---

## 8. 构建、刷机与运维

### 8.1 构建

```powershell
# 左片（台架构建：带 mx.* 命令、双接口、开机自动克隆）
powershell -File tools\build_app.ps1 -App app_left -Define `
  "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"

# 右片
powershell -File tools\build_app.ps1 -App app_right
```

- `MB_VENDOR_CHANNEL=ON` 预留给 R2（切 `0xB0/0xB1/0xB2` 专用通道），当前默认 OFF = 走 legacy `0xA5`。
- 出货构建必须关 `MB_DEBUG_OPCODE`。

### 8.2 刷左片（**全自动**，不需要人工拔线）

```powershell
powershell -File tools\flash_left_auto.ps1              # 构建 + 刷 + 回读校验
powershell -File tools\flash_left_auto.ps1 -NoBuild     # 直接刷现有 build 产物
```

流程：`mx.dl`（固件内置"强制下载模式"）→ 等 `VID_303A&PID_0009`（左片原生 USB 下载器）→
`write_flash 0x10000` → 整段回读逐字节比对 → 提示断电。**启动**用
`esptool --port COM4 --before no-reset --after hard-reset read-mac`（本板实测可用，
比 USB-Serial-JTAG 的 `watchdog_reset` 可靠）。

### 8.3 刷右片（需把右侧口鼠标换成数据线）

```powershell
# 右侧口插数据线 → 出现 VID_303A&PID_1001 / COM10
python -m esptool --chip esp32s3 --port COM10 --baud 921600 `
  --before no-reset --after no-reset write_flash 0x10000 app_right\build\makcu_right.bin
# 刷完必须换回鼠标（那一插就是断电重启），右片才会离开 ROM 下载器
```

### 8.4 一个已知环境坑：CH343 会掉总线

盒子每次断电重启后，中线 CH343 常常掉出 USB 总线（`VID_0000&PID_0002`，Problem 43 = 取不到描述符），
表现就是 `COM3` 打不开（`PermissionError 13`）。**先试软件恢复**：

```powershell
pnputil /restart-device "USB\VID_1A86&PID_55D3\5C98113502"   # 多数情况下一次就好
```

失败（设备节点完全消失）才需要人工拔插中线。

---

## 9. 验收判据（可量化，替代"手感"）

| 项 | 判据 | 本轮实测 |
|---|---|---|
| 运动链路 | `mx.ls` 的 `frames`/`rx_bytes` 持续增长；`mx.hi fail=0` | 570 帧/s，`fail=0` |
| 厂商上下行一致性 | `out == vin == vf`，`ofail == 0`，`venq` 丢弃 = 0 | 99/99/99，全零 |
| 延迟 | `vp50 ≤ 40 ms`（当前）、目标 ≤10 ms | 31–39 ms |
| DPI 显示 | HECATE 显示真实档位（非 200/96/384） | 正常 |
| DPI 切换 | 点一次 ≤ 数百 ms 内生效，无"未响应" | 正常 |
| 身份 | `mx.fv` → `force=0000:0000 ovr=0000:0000 dev=0f326e70` | 正常 |
| 回归 | `verification/regress` 全绿（需 pytest 环境） | 本轮以台架计数替代 |

---

## 10. 撤回记录（试过但无效，勿重走）

| 方案 | 目的 | 结果 |
|---|---|---|
| `GET_REPORT` 返回缓存的厂商 IN 帧 | 让 HECATE 通过控制端点取到状态 | 无效：`ctl` 证明 HECATE **从不发 GET_REPORT**（只有 `S1/ty2/len64`），已回滚为空实现 |
| 右片补发 `SET_PROTOCOL(Report)` + `SET_IDLE(0)` | 让接收器进入"变化即报" | 无效（且第一版放在 `device_attached()` 同步执行导致死锁、鼠标不动，已改为独立任务后仍无效），已全部删除，`makcu_hidhost.c` 回到 HEAD 原样 |
| 盒子探测到状态变化后自动重枚举 USB | 模拟"设备到达"骗 HECATE 重读 | 未验证到收益即按需求撤回（探针 + `mx.rn` + `g3mpro_last_out_frame` 全部删除） |

**结论**：接收器不会经由盒子把"DPI 被硬件键改了"这件事告诉主机；实测其心跳回包 64 字节恒定、
无任何主动帧、HECATE 也不重读。唯一有效手段是让设备重新枚举（拔插左侧线后 HECATE 立刻读到新值）。

---

## 11. 已知限制

**按鼠标硬件 DPI 键 → HECATE 显示不刷新**（详细数据见 §10 与 `mouse/README.md`）。

- 不是丢帧：`out == vin == vf`、`ofail=0`、`venq` 丢弃 0；
- 不是解析错：整帧校验和证明内容没被改动；
- 是接收器行为：直插电脑才推送。按需求**不做支持**；改 DPI 请在 HECATE 里操作（该路径完全正常）。

---

## 12. 后续可做

1. **压 `vp50` 到 10 ms 量级**：剩余延迟来自 `0xA5` 请求/应答在 UART1 上与 1 kHz 报表流排队；
   方向是把厂商请求也做成"发送即忘 + 异步匹配"（右片已具备快路径与高优先级）。
2. **R2 专用通道 `0xB0/0xB1/0xB2`**（`vendor_chan.h` 已定义、`0xB1` 在 `makcu_link.h` 早有占位）：
   左→右 `0xB0`、右→左 `0xB1`、受理 ACK `0xB2`，与 `0xA2` 完全并列、独立队列；
   打开 `MB_VENDOR_CHANNEL=ON` 即切换。
3. **出货构建**：`MB_DEBUG_OPCODE=OFF`，`mouse/README.md` 的已知限制一并交付。

---

## 13. 本轮文件改动清单

| 文件 | 性质 | 说明 |
|---|---|---|
| `mouse/**`（8 个文件） | 新增 | 组件：协议集中 + 通道 + 分发 + README |
| `tools/flash_left_auto.ps1` | 新增 | 左片全自动刷写/校验 |
| `app_left/main/app_main.c` | 修改 | 厂商早退分支、legacy 传输、记账、`mx.ox`/`mx.vd` 扩展、`mx.dl` 修正 |
| `app_left/CMakeLists.txt`、`app_left/main/CMakeLists.txt` | 修改 | 组件目录、`REQUIRES mouse`、`MB_VENDOR_CHANNEL` 开关 |
| `app_right/main/app_main.c` | 修改 | 16 深 OUT 队列 + 快路径 + `vout_task`(prio 10) |
| `components/makcu_hiddev/**` | 修改 | `set_ven_filter`、8×64 厂商 IN 队列、戳印只作用于鼠标、`ctl` 计数 |
| `components/makcu_link/**` | 修改 | 区间钩子数组 `add_custom_hook`（不再抢单槽） |
| `docs/50-vendor-channel.md` | 新增 | 本文 |

镜像尺寸：左片 bench **353,904 B**（HEAD 基线 348,512 B）、右片 **292,624 B**（HEAD 基线同值，右片本次只加了队列）。
