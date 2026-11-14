# 2026-11-10 补丁轮：交接复核后的三项修正

> 触发：交接复核（读 `docs/HANDOVER.md` + 全量源码）发现 1 个栈越界、1 个并发缺口、5 处过时说明。
> 本轮只做**不动热路径**的修正，构建 + 上机 + 回归全部复核。

## 1. 改动

| # | 文件 | 改动 | 理由 |
|---|---|---|---|
| 1 | `app_right/main/app_main.c:202` | `uint8_t payload[12]` → `payload[20]` | `host_info_frame()` 一直写到 `payload[19]`（16 位计数器扩容时数组没跟着长），每次 `mx.ln 1c` 越界写 8 字节栈 |
| 2 | `components/makcu_link/src/makcu_link_bridge.c` | `makcu_link_request()` 加互斥（`s_req_lock`，init 里创建，带优先级继承） | 请求状态是单槽，`km_uart0`（`mx.hi/mx.lat/mx.ac`）、`km_outq`（`0xA5`）、`km_heal`（克隆校验）三方并发会互相吃掉回包 → 表现为超时，但右片其实答了 |
| 3 | `app_left/main/app_main.c` | 新增台架探针 `mx.hi` | 原来没有任何命令能**读回**右片 `0x1C`：`mx.ln` 只回写出字节数，`mx.lr` 立刻被 1 kHz 的 `0xA2` 覆盖 |
| 4 | `tools/build_app.ps1` | 导出 `IDF_SKIP_CHECK_SUBMODULES=1` | 本网络无法 clone github/gitee 子模块，任何一次重新 configure 都会在编译前失败（`esp32-bt-lib`） |
| 5 | `docs/HANDOVER.md` | §14.2/14.4/14.5/14.9/14.6/14.17/§16 | `MB_FORCE_VIDPID` 已废弃、`mx.vp` 是 RAM-only、`mx.lfx` 后必须 `mx.lb0`、`mx.ln 1c` 不回显、时间线补本轮 |

## 2. 构建

```
makcu_left.bin   320,976 B  (0x4e5d0, 69% 余量)
makcu_right.bin  292,048 B  (0x474d0, 72% 余量)
```

新增告警：无。仍存在的旧告警（本轮未动）：
`app_main.c:366 mouse_iface set but not used`、`app_main.c:637/638 vid/pid unused`。

## 3. 刷写与自检（左片已刷，右片待换数据线）

```
tools\flash_capture.ps1 -Port COM3 -Seconds 5      -> 写 320,976 B，Hash verified
```

刷后 30 秒自检（实测）：

```
mx.fv   -> force=0000:0000 ovr=0000:0000 dev=0f326e70
mx.vs   -> 2,2
mx.if   -> 2 93:81:0 158:82:1
mx.dv   -> init=1 mnt=1 … 0x42=66B 复合配置（MI_01 OUT = 0x03），rep93
mx.sn   -> MBE87C6C6B372                 （跨刷写不变：NVS 生效）
mx.ds   -> 55,0                          （右片转发计数, 队列丢弃 0）
mx.hi   -> att=1 addr=2 id=320f:706e itf=2 ep=81:00,82:05 gate=1 ok=64016 fail=4 done=64006 fwd=64004
```

`mx.hi` 的两个额外信息：

- `ep=81:00,82:05`：接口 0 只有 IN；接口 1 的 **OUT 是 0x05**（鼠标真实端点），
  与左片 `patch_out_endpoint()` 把它改成 `0x03` 供 PC 侧使用、`out_to_right()` 固定写 `0x05`
  的代码互相印证；
- `fail=4`：右片 submit 失败计数，全部来自 attach 瞬时（自愈后不再增长）。

## 4. 回归

```
$env:MAKCU_PORT='COM3'; python -m pytest verification\regress -q
100 passed in 125.41s
```

## 5. 右片刷写（2026-11-10 16:44）
```
right chip on COM10
Wrote 292048 bytes at 0x00010000 in 2.1 s (1119 kbit/s)   Hash of data verified.
readback (first 64 KB) differs in 0 bytes
```

**但刷完芯片停在 ROM 下载模式，app 没跑起来**（新发现）：

| 检查 | 结果 |
|---|---|
| `esptool --before no_reset chip_id` | 仍能同步（"Staying in bootloader"）→ 芯片在下载模式 |
| `--after hard_reset` / `--no-stub` 再试 | 打印 "Hard resetting via RTS pin" 但无效 |
| `--after soft_reset` | ESP32-S3 不支持（仅 ESP8266） |
| 左片 `mx.ls` | `rx_bytes = 14`（只有本机 loopback 自检那 14 字节），右片一言不发 |
| 左片 `mx.lb` 自检 | 正常（frames/注入/rx_bytes 都涨）→ 左片 UART1 功能完好，问题在右片 |

结论：**本板 USB-Serial-JTAG 的 hard reset 是空操作**，刷完必须靠拔数据线/断电重启。
历史上之所以没暴露，是因为每次刷完都会立刻把鼠标插回右侧口 —— 那一下就完成了断电重启。

附带确认：左片也在这期间重启过一次（`mx.as` 变成 2、`mx.ds` 归零、`mx.if=0`、
`mx.fv dev=fa300203` 回退 fixture），说明右侧口换线会让整块板子断电，与上面的结论一致。
把鼠标插回右侧口后应为 `as=1`、`if=2`、`dev=0f326e70`。

已把这条约束写进 `tools/flash_right.ps1` 的收尾提示和 `docs/HANDOVER.md §14.3`。

## 6. 换回鼠标后的验收（2026-11-10 16:52，全部通过）

拔数据线、鼠标插回右侧口（= 整板断电重启），30 秒后实测：

```
mx.as   -> 1                                       开机自动克隆成功
mx.vs   -> 2,2                                     设备/配置描述符走隧道
mx.if   -> 2 93:81:0 158:82:1                      复合两接口
mx.fv   -> force=0000:0000 ovr=0000:0000 dev=0f326e70
mx.sn   -> MBE87C6C6B372                           跨刷写不变
mx.hi   -> att=1 addr=1 id=320f:706e itf=2 ep=81:00,82:05 gate=1 ok=12009 fail=0 done=12003 fwd=12003
mx.ls   -> 12086,21,2,19,12006,23,36,2,0,12006,0,182499     右片活着（rx_bytes 18 万+）
mx.ds   -> 12006,0 -> 12522,0 -> 14034,0           持续增长、队列丢弃 0
mx.lat  -> int=100/25600us, proc=10/40us, r=60/60/67us
mx.ox   -> 21,21,21, ack=00, dropped 0             厂商通道 100%（out==ok==in82）
mx.hv   -> 0,0,0,0,0,1；mx.hr -> 0,1,0,1           已 mount、未 suspend、ready
```

对照 §5 的旧状态，本轮四个修正点全部闭环：

1. **`payload[20]`**：`mx.hi` 连续多次读回完整 20 字节（`fwd` 字段有值即证明第 18–19 字节没被
   栈越界污染掉），右片 submit **`fail=0`**（旧固件 attach 后固定出现 4）；
2. **互斥**：`mx.hi` / `mx.lat` / `mx.ox` 在报告流满载（>300 条/秒）下连续调用无一次超时；
3. **`mx.hi` 探针**：这是右片 host 状态第一次能被读回，`ep=82:05` 还顺带证实了鼠标真实
   厂商 OUT 是 `0x05`（PC 侧被改成 `0x03`）；
4. **`mx.ls` 的 `dropped=0`**：链路零丢帧。

### 6.1 HECATE Connect + 晃动鼠标（2026-11-10 16:58，用户实测）

```
mx.ox  -> 41,41,41, ack=00, dropped=0    last OUT 0420001a06000000 == in82 0420001a06000000
mx.ds  -> 35983,0 -> 39260,0 -> 43762,0  5 s 增 4502 条 ≈ 900 帧/秒，队列丢弃 0
mx.lat -> proc=10/40us（左片）  r=60/60/67us（右片转发）
mx.hi  -> ok=37294 fail=0 done=37288 fwd=37288     37k 条报告零 submit 失败
mx.ls  -> 36644,...,injected=36496,dropped=0,rx_bytes=551433
mx.bo  -> 0x07                           三个主键位都到过
```

- HECATE Connect **显示电量**（厂商通道 41 帧，out == ok == in82，`ack=00`，回包与真实设备一致）；
- 拖动时 **≈900 帧/秒、0 丢帧、0 提交失败**，与 §15 的历史基线一致；
- 前两项（电量 + 跟手）与 2026-11-10 早前的验收结论相同，本轮的改动没有回归。

> 仪表噪声提醒：`mx.bw` 的第 2/3 个字段（wheel 事件/累加）是按 5 字节 12-bit 布局算的；
> G3M PRO 的 7 字节报告里 `data[4]` 是 Y 的高字节，所以这两个数在 G3M 上没有意义
> （本轮读到 10420 / -9890）。要看真实报告用 `mx.ei` 的原始字节，别看 `mx.bw`。

## 7. 未完成（都不阻塞）
| 裸 `mx.dl` 之后的 coredump 报错 | `E esp_core_dump_flash: Core dump data check failed` 是分区里没有有效 core dump 时的固定噪声，不影响启动 |
| 手感曲线（`0x4200EFEC`） | 仍需 USB 分析仪抓出厂轨迹（用户已决定不做） |

## 8. 后补：控制口注入的鼠标移动原本完全不动（2026-11-10 17:20–17:45）

**现象**：`.km.move(200,0)` 回显正常、`mx.hs` 计数增长、`mnt=1`，但**光标一个像素都没动**。
对照组 `mx.lfx 00c80000000000`（同样的 200 counts，走 verbatim 直通 7 字节）让光标移动了 314 px。

**根因（三层）**

| # | 问题 | 证据 |
|---|---|---|
| 1 | `makcu_hiddev_report()` 固定发 **4 字节** `{btn,dx,dy,wheel}`，而当时服务的 G3M 描述符是 **7 字节**（btn5+pad3, X16, Y16, wheel, pan）。报告比描述符短 → 主机静默丢弃 | `mx.rd 0` = 93 字节描述符；verbatim 7 字节能动、4 字节不能 |
| 2 | 补的"按描述符推算报告长度"解析器把 **Report Count(0x9) 当成 local item**，它实际是 global → 算出 0 bit → 仍走 4 字节分支 | 新增 `mx.rb` 探针直接读出 `bytes` 暴露 |
| 3 | 即使改成 7 字节，走 `hid_send()`（`tud_hid_ready` + 互斥 + `tud_hid_report`）仍被主机丢弃；改走**已验证的 verbatim 发送器** `makcu_hiddev_report_verbatim_ep()` 后立刻生效 | 改前 `.km.move(200,0)` → 0 px；改后 → +401 px（含系统加速） |

**修复**（`components/makcu_hiddev/src/makcu_hiddev.c`）

- 新增 `report_bytes_from_desc()`：按 HID 描述符累加 Input 项的 `Report Size × Report Count` 得到报告字节数（Report Count 按 global 处理）；
- `makcu_hiddev_report()` 按 `bytes>=7 / ==5 / 其它` 分别编码 16-bit / 12-bit / int8 布局；
- 三条发送路径统一改调 `makcu_hiddev_report_verbatim_ep(ep_in, ...)`，与透传共用同一发送器（端点忙时入队而不是丢帧）；
- 新增探针 `mx.rb` 把推导结果读出来（`bytes=7 desc=93 rid=0`）。

**验证**

```
改前  .km.move(200,0)      -> 光标 0 px（hs ok=3）
改后  .km.move(200,0)      -> +401 px
      .km.move(0,150)      -> +362 px
      慢速右扫 90x40@55ms  -> 5.0 s 内 x 从 0 到 2047（屏幕 2048 宽）
回归  MAKCU_PORT=COM3 pytest verification\regress -> 100 passed
```

**顺手发现的新隐患（未修，已记录）**：刷写/复位后偶尔出现 `mx.as=1` 但 `mx.if=0`、
克隆退回 4 字节 Logitech fixture（`dev=6d0477c0`）；主机仍按开机时读到的 7 字节描述符工作，
于是注入再次静默失效。复发时 `mx.rs` 重启即可（实测 `if` 回到 `2 93:81:0 158:82:1`、`rb=7`）。
建议后续加两道护栏：① `MB_DUAL_IF` 构建下 autoclone 捕获到 0 个接口时视为失败并交给自愈任务重试；
② 任何 re-clone（含 `mx.ac`）之后自动 `tud_disconnect/connect` 重新枚举，让主机描述符与内部克隆对齐。
