# 方案：自编右片固件（替代原厂 V3.7）

> 目标：用自编固件替代原厂右片固件，实现 USB host 侧功能对等，并新增**厂商通道下行**，
> 使 HECATE Connect 能在"鼠标插在盒子上"时读取与写入鼠标配置。
>
> 依据：2026-11-10 的实测与静态分析（见 `verification/plan-hecate-connect-proxy.md`）。
> 本文是**方案**；实现从 M1 开始，每个里程碑独立验收、独立回滚。

## 0. 为什么走这条路

| 维度 | 二进制补丁（已做到半途） | 自编右片固件（本方案） |
|---|---|---|
| 逆向量 | 需解出驱动 URB/pipe 结构（**尚未解出**，`0x3FC9FD64` 已排除） | 不需要；ESP-IDF 提供 `usb_host` |
| OUT 下行（管理程序的关键） | 手工填 URB 调 `usb_xfer_submit` | 一次 `usb_host_transfer_submit()` |
| 描述符读取 | 手工走 `0xA1` 隧道拼字段 | 官方 API 直接给原始描述符字节 |
| 每次改动代价 | 重算校验和 + 摘要、重刷（已破解但脆弱） | 正常编译 |
| 崩溃风险 | 补丁点被误触发可能死机 | 崩溃可见、可回滚 |
| 可维护性 | 反汇编补丁 | 正常 C 工程 |

## 1. 目标与验收标准

| # | 验收项 | 判定 |
|---|---|---|
| A1 | 插鼠标后 `mx.ln a0` = `00` | 枚举成功（等价原厂） |
| A2 | `mx.ls` 的 `hid/injected` 随鼠标移动增长；PC 光标跟手 | IN 转发正确 |
| A3 | `mx.ac` = `1:320f:706e:93`，`mx.dv` 显示 rep93 | EP0 隧道可读描述符 |
| A4 | `mx.lf a2 …` 注入 7 字节报告 → 光标按值移动 | 左片直送链路不受影响 |
| A5 | `mx.ln a5 05 02 00 aabb` 回 `rc=0`，鼠标收到该包 | **OUT 下行打通** |
| A6 | 拔插鼠标 10 次状态自恢复 | 热插拔健壮 |
| A7 | 既有回归 100 passed 不退化 | 无回归 |

## 2. 架构

```
右片 app_right
├── link 层        components/makcu_link      （已有：5 Mbaud、帧解析、发送）
├── 帧应答         components/makcu_right     （已有：0xA0/0xA1/0x1A/0xA3/0xA4/默认错误）
├── proto/dev      components/makcu_proto, makcu_dev（已有）
└── makcu_hidhost  ★ 本方案实现内容
    ├── host_core   usb_host_install + client 守护任务 + 设备状态机
    ├── ep0_tunnel  0xA1 → usb_host_transfer_submit_control
    ├── in_pump     各 IN 端点多 transfer 常驻 → 0xA2 帧
    └── out_pump    新 opcode → usb_host_transfer_submit（OUT）
```

**关键决策：不用 `usb_host_hid` 托管组件**，自己薄封装 `usb_host_lib`：

1. 左片克隆需要**原始**描述符字节（64 / 93 / 158 B），托管组件给的是解析后的结构；
2. 厂商 OUT 端点 `0x05` 托管组件不覆盖，反正要自己提交；
3. 报告必须 **1:1、无合并**转发，自己管理 transfer 队列最直接。

## 3. 接口契约（与左片对齐，不可改）

| 帧 | 方向 | 载荷 | 说明 |
|---|---|---|---|
| `0xA2` | 右→左 | `[ep][report…]` | IN 报告转发（左片按 `ep` 路由） |
| `0xA1` | 左→右 | 8 B USB setup 包 | EP0 控制传输；回 `0xA1` 帧带数据 |
| `0xA0` | 左→右 | `[00]` / `[FF]` | EP0 会话开始 / 结束（`FF` 必须无条件生效） |
| `0xA3` | 左→右 | `[00]` | A3 门闸（左片每 2 s 发，右片原样回） |
| `0x1A` | 左→右 | — | 快照；无设备回 `FF` |
| **`0xA5`（新增）** | 左→右 | `[ep][len:u16][data]` | **OUT 提交**；回 `[rc][ep][len]` |
| **`0xA6`（可选）** | 左→右 | `[iface][rid][len:u16][data]` | SET_REPORT 透传（若管理程序使用） |

帧格式沿用 `5A <cmd> <len:u16 LE> <payload>`，与左片 `makcu_link` 完全一致。

## 4. 里程碑

### M1 骨架与枚举（约 0.5 天）→ A1

- `usb_host_install()`：`intr_flags = ESP_INTR_FLAG_LEVEL1`，host 任务 4 KB / 优先级 5
- `usb_host_client_register()` 事件循环：
  - `USB_HOST_CLIENT_EVENT_NEW_DEV` → `usb_host_device_open` → 读设备描述符 + 活动配置
    → `usb_host_interface_claim(0)`、`(1)`
  - `USB_HOST_CLIENT_EVENT_DEV_GONE` → 清状态、重新武装
- 维护 `g_host`：`ready`（对应原厂 `DAT_42000d28+4`）、`session`（`*0x42000d2c`）、`ep0_dir`（`*0x42000d88`）
- `0xA0` 按原厂语义应答（会话开/关）
- **顺序要求**：`app_main` 里先装 host，再做 NVS/日志等（左片开机 1–2 s 内就会发起 `mx.ac`）

### M2 IN 报告转发（约 0.5 天）→ A2、A4

- 每个 IN 端点预挂 3 个 `usb_transfer_t`（双缓冲 + 1）
- 完成回调：组装 `0xA2`（`[ep][数据]`）压入链路发送队列 → **立即重提交**
- 带宽预算：1 kHz × 8 B ≈ 8 KB/s，链路 5 Mbaud ≈ 500 KB/s，余量约 60×
- **禁止合并报告**：Windows 指针加速按单报告幅度计算，合并会改变手感

### M3 EP0 隧道（约 0.5 天）→ A3

- `0xA1` 载荷（8 字节 setup）→ `usb_host_transfer_submit_control()`
- 数据长度：配置 66 B、报告描述符 158 B，单次可完成
  （`CONFIG_USB_HOST_CONTROL_TRANSFER_MAX_SIZE=256` 已开）
- 回帧 `0xA1` + 实际长度 + 数据；失败回 `5A A1 01 00 FF`
- **`0xA0 FF` 必须无条件关闭会话**（历史上 `mx.ef` 卡 1 就是漏了这条）

### M4 OUT 下行（约 0.5 天）→ A5 ★ 本方案核心价值

- `usb_host_transfer_submit()` 到 OUT 端点（`0x05`、64 B；端点地址取自活动配置）
- 链路新增 `0xA5`：`[ep][len16][data]` → 提交 → 完成回调回 `[rc][ep][len]`
- 部分设备需先 `SET_IDLE`/`SET_CONFIGURATION` 才接受 OUT：按需在打开端点后补发
- 行为验证：管理程序改 DPI/灯效 → 鼠标立即变化；或看 `0x82` 厂商回包内容变化

### M5 健壮性（约 1 天）→ A6、A7

- 掉线重枚举、枚举失败重试、端点重新武装
- 键盘/厂商接口（MI_01 的 `0x82` IN、`0x05` OUT）一并打开
- 短包/零长包处理、`DEV_GONE` 竞态
- 压测：1 kHz 连续移动 10 分钟，`mx.hs`/`mx.ls` 无失败累积

## 5. 风险与对策

| 风险 | 对策 |
|---|---|
| IDF host 在 1 kHz 端点抖动 | 多 transfer 常驻 + 完成即重提交；host 任务优先级 6–7 |
| 枚举时序与原厂不同 | 先装 host；左片有 8 s 等待窗口 + `mx.ac` 手动兜底 |
| EP0 隧道语义不一致 | 严格照 `app_right/main/app_main.c` 注释里逐条列出的应答格式实现 |
| OUT 端点被 STALL | 打开端点后补 `SET_IDLE`；失败时回 `rc≠0` 便于定位 |
| 刷坏右片 | `tools/flash_right.ps1`（默认出厂镜像）+ `hw_right_full_before_patch.bin`（4 MB 全片，sha256 `F4B3C2EC…`） |
| 自编固件不稳导致盒子不可用 | 左片夹具 4 构建随时可烧；可整体退回"补丁固件 + 夹具 4"的 2026-11-10 状态 |

## 6. 工作量

| 里程碑 | 估时 | 需要硬件 |
|---|---|---|
| M1 枚举骨架 | 0.5 d | 刷一次 |
| M2 IN 转发 | 0.5 d | 刷一次 |
| M3 EP0 隧道 | 0.5 d | 刷一次 |
| M4 OUT 下行 | 0.5 d | 刷一次 |
| M5 健壮性 | 1 d | 多次 |
| **合计** | **约 3 天** | 每次刷写需右侧口临时换线（中线常驻） |

## 7. 与现有工程的衔接

- 复用组件：`makcu_link`、`makcu_right`、`makcu_proto`、`makcu_dev`（与左片同一套源码）
- 新增实现：`components/makcu_hidhost`（当前是 stub；`app_right/CMakeLists.txt` 已列入 `COMPONENTS`，
  `sdkconfig` 里 `CONFIG_USB_HOST_*` 已配好）
- 构建：`powershell -File tools\build_app.ps1 -App app_right`
  （已实测：`makcu_right.bin` 216,768 B，分区余量 79%）
- 刷写/回滚：`powershell -File tools\flash_right.ps1 [-Image …] [-Backup]`（已实测）
- 台架命令不变：`mx.ln / mx.ac / mx.rs / mx.ls / mx.dv / mx.if / mx.bo` 全部沿用
  ⇒ 现有回归与工具链零改动

## 8. 开工顺序

1. **M1 + M2 一起做**（枚举 + IN 转发）——完成后自编固件即可实现当前已有的全部鼠标功能，
   这是"可用性基线"，必须先确认无回归；
2. **M3**（描述符隧道）——恢复左片自动克隆能力；
3. **M4**（OUT 下行）——HECATE Connect 可写配置的前提；
4. **M5** 收尾（健壮性 + 回归）。

> M4 完成后，2026-11-10 那套二进制补丁（blob / `0xA5` / pipe 表逆向）整套可以废弃，
> 不再需要解 `usb_xfer_submit` 的 URB/pipe 结构。


---

# 执行记录（2026-11-10）：M1–M4 全部达成

自编右片固件已在真机上跑通 **枚举 / IN 转发 / EP0 隧道 / OUT 提交** 四项，
`app_right/build/makcu_right.bin` 由 `tools/flash_right.ps1 -Offset 0x10000` 刷入
（**注意：app 镜像写 0x10000，不是 0x0**；0x0 是 bootloader+分区表，写错会导致不启动）。

## 验收结果（全部实测）

| # | 项目 | 实测 |
|---|---|---|
| A1 | 枚举 | `0x1C` 诊断帧：`attached=1 addr=1 vid=320F pid=706E itf=2`，`itf0 in=0x81`、`itf1 in=0x82 out=0x05` |
| A2 | IN 转发 | `submit_ok/complete/forwarded` 全部饱和；左片 `hs=hq=15675`；`mx.ei` 显示真实 7 字节报告 `00 00 00 ff ff 00 00`；注入 `X=+100` → 光标 `Δx=152` |
| A3 | EP0 隧道 | 直接测：`GET_DESCRIPTOR(device, 8/9/12/18)` 均正确回传（`1201000200000008…`）；`mx.ac` = `1:320f:706e:93` |
| A4 | 直送链路不变 | 夹具 4 下注入 `X=+100` → `Δx=151`；回归 **100 passed / 0 failed** |
| A5 | **OUT 提交** | `mx.ln a5 050200aabb` → 回 `00 05 02`（`rc=0, ep=5, len=2`） |

## 实现要点（踩过的坑，按出现顺序）

1. **USB-Serial-JTAG 控制台与 OTG host 抢占 PHY**：`CONFIG_ESP_CONSOLE_SECONDARY_USB_SERIAL_JTAG=y`
   时 `usb_host_install()` 拿不到 PHY，枚举直接为 0。必须
   `CONFIG_ESP_CONSOLE_SECONDARY_NONE=y` + `CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG_ENABLED=n`。
2. **0xA2 帧布局**：左片解析的是 **4 字节头 + 报告**
   （`payload[0]=ep, [1]=session, [2]=report_len, [3]=flag, [4..]=report`；
   `makcu_link_bridge.c` 里 `avail = f->len - 4`、`memcpy(..., &f->payload[4], n)`）。
   只发 `[ep][report]` 会让左片把按键字节当长度，转发出 1 字节垃圾。
3. **0xA0 的应答字节取 `ep0_dir`**（`dir = st->ep0_dir ? 00 : FF`），不是 `ready`。
   不置位 → 左片永远看到 `FF`（无设备），自动克隆连隧道都不发起。
4. **EP0 控制传输的缓冲区**：IDF 的 `usb_transfer_t` **没有** `setup_packet` 字段，
   setup 包放在 `data_buffer[0..7]`，`num_bytes = 8 + wLength`，完成后有效数据从 `data_buffer + 8` 开始、
   `actual_num_bytes` 含这 8 字节。
5. **app 镜像位置**：`makcu_right.bin` 是应用分区镜像 → 写 `0x10000`。

## 当前剩余

| 项 | 状态 |
|---|---|
| M5 健壮性（热插拔/1 kHz 压测/键盘接口） | 未做 |
| LEFT 侧双接口（把 PC 的 MI_01 OUT `0x05` 写转成 `0xA5`） | 未做（D38；这是 HECATE Connect 可写配置的最后一段） |
| 台架 `mx.ln` 的 payload 上限 32 字节 | 限制 64 字节厂商帧的测试，后续扩到 80 |

## 设备现状

- 右片：自编固件（M1–M4），鼠标功能正常、自动克隆正常、OUT 提交返回 `rc=0`；
- 左片：夹具 4（`046D:C077` + G3M 93 字节描述符），回归 100 passed；
- 回滚：`tools/flash_right.ps1`（默认刷出厂 `V3.7_RIGHT.bin` 到 0x0）或
  `tools/flash_right.ps1 -Image <原厂> -Offset 0x0`。
