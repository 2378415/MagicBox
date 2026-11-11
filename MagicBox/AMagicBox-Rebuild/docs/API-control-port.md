# 控制口接口文档（MagicBox / MAKCU 重建固件）

> 适用固件：2026-11-10 及以后（控制口 **921600**，含二进制快速通道与 `sumv`）。
> 面向对象：写上位机的人（Android / PC / 脚本）。
> 硬件：盒子中线的 CH343 → 电脑/手机 USB-Serial，为 **UART0**；与盒子内部片间 UART1 无关。

---

## 0. 快速上手（30 秒）

```python
import serial, time
s = serial.Serial('COM3', 921600, timeout=0.2)
s.dtr = False; s.rts = False          # 见 §1.3
time.sleep(0.5)                        # 设备刚上电时控制台要 ~1 s 才就绪
s.write(b'.km.version()\r')            # 文本命令
print(s.read(s.in_waiting))            # b'km.MAKCU\r\n>>> '
```

监听按键（默认**穿透**：事件照报、按键照常给 PC；想看被吃掉的效果发 `consume=1`）：

```python
s.write(frame(0x39, 1, bytes([1, 0x08, 1, 0])))   # 订阅侧键4，开推送，穿透
s.write(frame(0x39, 1, bytes([1, 0x08, 1, 1])))   # 同上但"吃掉"（PC 看不到）
# 之后循环读：cmd == 0xE1 的帧就是事件（见 §5.7）
```

- 文本协议：给人和台架用，可读、有回显。
- 二进制协议：给交互用，零回执、单帧 9–18 字节，RTT 实测 **1.1 ms**。
- 两者**可以在同一根线上混用**，帧头不同（文本以 `.`/`k` 开头，二进制以 `0x5A` 开头）。

---

## 1. 物理层与链路

### 1.1 参数

| 项 | 值 |
|---|---|
| 端口 | 中线 CH343（Windows 显示 `USB-Enhanced-SERIAL CH343 (COMx)`） |
| 波特率 | **921600**（2026-11-10 之前是 115200，见 §8 兼容性） |
| 数据格式 | 8N1，无流控 |
| 建议读超时 | 50–200 ms（交互场景别用长超时，见 §1.4） |
| 单帧上限 | 文本行 256 B；二进制 payload 64 B |

### 1.2 与日志共用一条线

`ESP_LOG` 也从 UART0 出来。正常运行时没有周期日志，但**出错/看门狗**会打印，形如
`E (12345) task_wdt: ...`。上位机解析时应：文本行按 `km.` 前缀识别；二进制帧按 `0x5A` + CRC 校验，
校验失败的字节直接丢弃。

### 1.3 DTR / RTS

打开端口时不要拉高 DTR（部分工具默认拉高，会把设备打进复位），建议显式：

```python
s.dtr = False; s.rts = False
```

刚打开端口/刚上电后的 **0.5–1.5 秒**内设备可能还在初始化（USB 枚举 + 自动克隆），
建议首条命令带重试（2–3 次，间隔 200 ms）。

### 1.4 延迟基线（实测，2026-11-10，PC + CH343）

| 操作 | 时间 |
|---|---|
| 文本命令 `km.version()` RTT | p50 **1.10 ms** / p99 1.18 ms |
| 二进制 `PING` RTT | p50 **1.10 ms** / p99 1.27 ms |
| 16 B 文本命令线上时间 @921600 | 0.17 ms |
| 14 B 二进制运动计划线上时间 | 0.15 ms |
| 一次 `sumv` 的"命令→首个 LED 可见移动" | ≤ 1 个 HID 帧（1 ms）+ 串口 1 帧（1 ms） |

> 关键教训：不要在请求后"等 20 ms 再读"。设备侧的旧实现会等满接收缓冲，那个 20 ms 是历史包袱，
> 现在已修复；上位机侧只要**不等回包**就不会被拖慢。

---

## 2. 文本协议

### 2.1 帧格式

```
发送：  "."  "km."  <command+args>  "\r"            其中 "." 与 "km." 可省略
回包：  "km." <content> "\r\n>>> "
```

- 终止符：`\r` 或 `\n`（任一）。
- 超长行（>255 B）被丢弃并重新同步。
- **未知命令不回包**（不会报错）——所以"发完没反应"要先核对命令名拼写。

### 2.2 回包形态（三种）

| 形态 | 例子 | 适用 |
|---|---|---|
| 回显整行 | `.km.move(10,5)` → `km..km.move(10,5)\r\n>>> ` | 动作类（move/wheel/silent/sumv/按键按下） |
| `名称\n<状态字节>` | `.km.buttons()` → `km.buttons()\n0\r\n>>> ` | 查询类（buttons/left/lock_*/catch_*/sumv()） |
| 内容 | `.km.version()` → `km.MAKCU\r\n>>> ` | version / serial |

### 2.3 命令一览（49 条）

**按键**（`1` 按下 / 其它释放，回显）

```
.km.left(1)   .km.right(1)   .km.middle(1)   .km.front(1)   .km.ms1(1)   .km.ms2(1)
```

**按键查询/点击计数**（回 `名称\n<状态>`）

```
.km.left()  .km.right()  .km.middle()  .km.front()  .km.ms1()  .km.ms2()
```

**轴锁定**（`lock_m*(1)` 锁 / `lock_m*(0)` 解锁）

```
.km.lock_mx(1)  .km.lock_my(1)                          X/Y 轴
.km.lock_ml(1)  .km.lock_mr(1)  .km.lock_mm(1)          左/右/中键
.km.lock_ms1(1) .km.lock_ms2(1)                        侧键
查询：.km.lock_mx()  .km.lock_ml()  …（回 名称\n<状态>）
```

**通道捕获（catch）**

```
.km.catch_ml(1)  .km.catch_mr(1)  .km.catch_mm(1)  .km.catch_ms1(1)  .km.catch_ms2(1)
查询：.km.catch_ml() …（回 名称\n<0|1>）
```

**移动 / 滚轮**

```
.km.move(dx,dy)                 分步相对移动（老引擎，无速度参数，见 §5.1）
.km.move(dx,dy,mode)            mode 在老引擎里被忽略
.km.move(v0,v1,v2,v3,v4)        扩展形式
.km.wheel(delta)                int8 滚轮增量
```

**其它**

```
.km.buttons()            查询按键位图（回 名称\n<值>）
.km.buttons(n)           设置按键位图
.km.version              回 "MAKCU"
.km.silent(dx,dy)        脉冲：先 (dx,dy) 再反向
.km.serial()             序列号（真鼠标没有 → 失败文案）
```

**扩展（重建版新增，原厂没有）**

```
.km.sumv(dx,dy[,speed[,mode[,dur_ms]]])   拟人化相对移动，见 §5
.km.sumv()                                查询是否在跑：sumv()\n<0|1|2>
.km.sumv_stop()                           立即停在当前位置

.km.evt(1[,mask[,consume]])               订阅按键（**默认穿透**，见 §5.7）；mask 十进制；第 3 参 1=吃掉
.km.evt(0)                                取消订阅
.km.evt()                                 查询：evt()\n<mask>
```

---

## 3. 二进制协议（推荐用于交互）

### 3.1 帧格式（小端）

```
+0   0x5A                    magic
+1   cmd                     命令字
+2   seq                     序号，回包原样带回；用于测 RTT / 统计丢包
+3   len (u16 LE)            payload 长度（≤64）
+5   payload[len]
+5+len  crc8                 poly 0x07，覆盖 cmd..payload（即整帧去掉 magic 与 crc）
```

回包：`cmd | 0x80`，`seq` 与请求一致。

```c
uint8_t crc8(const uint8_t *p, size_t n) {
    uint8_t c = 0;
    for (size_t i = 0; i < n; i++) {
        c ^= p[i];
        for (int b = 0; b < 8; b++) c = (c & 0x80) ? (uint8_t)((c << 1) ^ 0x07) : (uint8_t)(c << 1);
    }
    return c;
}
```


### 3.x `0x3E HID_STAT`：按键优先级统计（2026-11-11 新增）

请求：`0x3E`，payload 空。回包 `0xBE`，**10 字节**（老固件 8 字节，多出的 2 字节请按长度忽略）：

| 偏移 | 字段 | 含义 |
|---|---|---|
| 0–1 | `btn_in` | 按键报告进入优先级队列的次数 |
| 2–3 | `btn_sent` | 真正上了 USB 总线的次数（`in == sent` 表示一条没丢） |
| 4–5 | `wait_max_us` | 入队 → 上总线的最大延迟（µs） |
| 6–7 | `btn_overflow` | 按键队列满而没接下的次数（正常恒为 0；旧报告永不因新报告到达被挤掉）|
| 8–9 | `flood` | 1 秒内按键字节变化 > 50 次的窗口数（2026-11-11 新增，**正常恒为 0**；非 0 = 按键字节洪泛）|

配套的固件行为（2026-11-11 最终版）：

- 按键报告**永不进入运动 FIFO**，走 **32 深专用队列**，按到达顺序逐条发送；旧报告**绝不**因为新报告到达而被挤掉或丢弃；
- 发送侧先看按键队列、再看运动 FIFO —— 这就是"按键优先于移动"的实现，**不再**为按键去丢运动报告；
- `makcu_mouse_button_priority()` 生效后 2 ms 内引擎不提交运动报告（让路窗口 `MAKCU_BTN_GUARD_US`）；
- 队列满（正常不会发生：32 ms 内人手无法产生 32 次不同按键变化）只计数 `btn_overflow`，不覆盖已排队的报告。

实测（10 s 压力：AIM 约 1600 条 + 按键 128 条）：`btn_in=128 / btn_sent=128`（**0 丢失**）、
`wait_max_us ≈ 221`、`motion_dropped ≈ 205`（每次按键顺带清掉 1–2 条陈旧运动，闭环会补）。

### 3.y `0x3F BTN_AUDIT`：按键回环审计（2026-11-11 新增）

请求 `0x3F`，payload 空。回包 `0xBF`，12 字节：`in_chg` 由 mouse 层统计请求变化，`out_chg` 改为 **hiddev 上线级**统计（只有它看得见透传路径），`extra = max(0, out_chg − in_chg)`。

| 偏移 | 字段 | 含义 |
|---|---|---|
| 0–3 | `in_chg` | `makcu_mouse_set_buttons()` 真正**改变按键字节**的次数（= 注入/命令请求的"变化"数） |
| 4–7 | `out_chg` | 真正**发出去**的报告里按键字节发生变化的次数 |
| 8–11 | `extra` | `max(0, out_chg − in_chg)` —— 真正"凭空多发"的次数（2026-11-11 改为上线级口径）|

**判据**：正常终态 `in_chg == out_chg` 且 `extra == 0`。
这一条补上了 `0x3E HID_STAT` 的盲区——后者只统计真实鼠标报告，注入的按键进不了它的计数，
所以"有没有多发"以前查不出来。

实测（连跑 200 Hz AIM 重载 6 s，注入 126 条按键变化）：

```
in_chg 126 == 指令 126 · out_chg 126 == in_chg 126 · extra 0
→ 每条按键变化正好对应一条线上报告：不丢、不重、不多
```


### 3.z `0x40 AIM_RESET` / `0x41 EVT_RESET`（2026-11-11 新增）

两个 fire-and-forget 命令，无 payload、无回包：

| cmd | 名称 | 作用 |
|---|---|---|
| `0x40` | `AIM_RESET` | 清空 `AIM_STATE` 的累计量：`rounds`、`aborted`、`dead_hits`、`last_result`（置 0 = 无结果）、`last_counts`、`last_dur_ms`，以及会话累计位移 |
| `0x41` | `EVT_RESET` | 清空事件环与统计：`seq`、`count`、`overflow` |

背景：
- `makcu_sumv_aim_reset()` 原本**没有调用点**，`rounds/aborted` 会一路累加到 u16 饱和，`last_result` 也会永久粘住（界面一直显示上次的历史）；
- 事件环在**推模式**下曾经也被写入，而没人读环 → 环常年满、`overflow` 一直涨，看起来像"在丢事件"。现在推模式只走异步通道，环只服务于 `EVT_READ` 轮询。

实测（刷后直连 COM3）：

```
AIM 流量 30 发 → 0x3D: result=1 rounds=30
0x40          → 0x3D: result=0 rounds=0 aborted=0 dead=0
0x3B: seq=0 pending=0 overflow=0（推模式下环不再增长）
```
### 3.2 解析注意

- `0x5A` 只有在**文本行首**才会开帧，所以文本命令里的字符 `Z` 不会被误判；
- payload 超 64 → 丢帧并计 `len_err`；CRC 错 → 丢帧并计 `crc_err`（**不会回错误帧**）；
- 文本与二进制混发时，按字节流处理即可：遇到 `0x5A` 且当前不在文本行内 → 二进制解析。

### 3.3 命令表

| cmd | 名称 | payload | 回包 | 用途 |
|---|---|---|---|---|
| `0x31` | `MOTION_PLAN` | `dx i16, dy i16, dur_ms u16, mode u8, flags u8` | 无 | 老引擎的相对移动（无拟人化、无速度参数） |
| `0x32` | `BUTTON` | `mask u8` | 无 | 按键位图（1=左 2=右 4=中 8=侧4 16=侧5） |
| `0x33` | `WHEEL` | `delta i8` | 无 | 滚轮 |
| `0x34` | `QUERY` | `what u8` | 有 | 0=计数 1=能力 2=上条计划 |
| `0x35` | `PING` | `counter u32` | 有 | 往返延迟测量 |
| `0x36` | `SUMV` | `dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]` | 无 | **拟人化相对移动（推荐）** |
| `0x37` | `SUMV_STOP` | — | 无 | 立即停止 sumv |
| `0x38` | `SUMV_STATE` | — | 有 | sumv 状态与计数 |
| `0x39` | `EVT_CTL` | `enable u8, mask u8, push u8 [, consume u8]` | 无 | 订阅按键。**第 4 字节缺省 0 = 穿透**，`1` = 吃掉（见 §5.7） |
| `0x3A` | `EVT_READ` | `count u8`（≤7） | 有 | 批量取事件（也是心跳） |
| `0x3B` | `EVT_STAT` | — | 有 | 事件通道状态（也是心跳） |
| `0x3C` | `AIM` | `dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]` | — | **瞄准专用**：这一发必须在 `max_ms` 内走完（见 §5.8） |
| `0x3D` | `AIM_STATE` | — | 有 | 12 B：`active, last_result, last_counts(u16), last_dur_ms(u16), aborted(u16), rounds(u16), dead_hits, gen` |
| `0x3E` | `HID_STAT` | — | 有 | 8 B：`btn_in(u16), btn_sent(u16), wait_max_us(u16), btn_overflow(u16)`（见 §3.x） |
| `0x3F` | `BTN_AUDIT` | — | 有 | 12 B：`in_chg(u32), out_chg(u32), extra(u32)` —— **按键回环审计**（见 §3.y） |
| `0x40` | `AIM_RESET` | — | 无 | 清空 `AIM_STATE` 累计量（见 §3.z） |
| `0x41` | `EVT_RESET` | — | 无 | 清空事件环与统计（见 §3.z） |
| `0xE1` | `EVT_PUSH` | `t_us u32, seq u16, mask u8, edge u8` | — | **设备主动推**（异步段 0xE0–0xEF） |

交互命令全部 **fire-and-forget**（不回包、不重传）。可靠性只能靠 `seq` 缺口 + CRC 计数观察。

### 3.4 回包内容

**`QUERY what=0`（18 B）**

| 偏移 | 类型 | 含义 |
|---|---|---|
| 0 | u32 | 收到且 CRC 正确的帧数 |
| 4 | u32 | CRC 错误数 |
| 8 | u32 | 长度非法数 |
| 12 | u32 | seq 缺口计数 |
| 16 | u8 | 最后一次 seq |
| 17 | u8 | 协议版本（当前 1） |

**`QUERY what=1`（12 B）**：`proto u8, max_payload u8, plan_engine u8, rsv u8, clock_us u32`

**`QUERY what=2`（18 B）**：`dx i16, dy i16, dur_ms u16, recv_us u32, submit_us u32, plans u32`

**`PING`（12 B）**：`counter u32, clock_us u32, plans u16, last_seq u8, rsv u8`
（`counter` 原样回显，用收到时间 − 发送时间得到 RTT。）

**`EVT_READ`（1 + n×8 B，n ≤ 7）**：`count u8` + `count` 条事件记录（布局见 §5.7.2）。

**`EVT_STAT`（12 B）**

| 偏移 | 类型 | 含义 |
|---|---|---|
| 0 | u16 | 下一条事件序号 |
| 2 | u8 | 环里未读条数 |
| 3 | u32 | 溢出（被覆盖）条数 |
| 7 | u8 | 订阅掩码 |
| 8 | u8 | pending（订阅时已按住、仍透传的位） |
| 9 | u8 | 最近一次真实按键位图 |
| 10 | u8 | **最近一次真正发给 PC 的按键字节**（判定"吃掉"是否生效） |
| 11 | u8 | flags：bit0 enabled · bit1 push · bit2 auto_released |

**`SUMV_STATE`（29 B）**

| 偏移 | 类型 | 含义 |
|---|---|---|
| 0 | u8 | 是否在跑 |
| 1 | u32 | 累计样本数 |
| 5 | u32 | 被 REPLACE / stop 打断次数 |
| 9 | u32 | 正常走完次数 |
| 13 | u32 | 屏蔽期间丢弃的真实鼠标位移报告数 |
| 17 | u32 | 屏蔽期间透传的按键/滚轮报告数 |
| 21 | u32 | 上一条轨迹被 clamp 后的实际速度（counts/s） |
| 25 | u32 | 当前轨迹剩余样本（ms） |

### 3.5 示例（Python）

```python
MAGIC, REPLY = 0x5A, 0x80

def crc8(data):
    c = 0
    for b in data:
        c ^= b
        for _ in range(8):
            c = ((c << 1) ^ 0x07) & 0xFF if (c & 0x80) else ((c << 1) & 0xFF)
    return c

def frame(cmd, seq, payload=b''):
    body = bytes([cmd, seq, len(payload) & 0xFF, len(payload) >> 8]) + payload
    return bytes([MAGIC]) + body + bytes([crc8(body)])

def sumv(ser, dx, dy, speed=0, mode=0x0E, seed=0):
    payload = (dx.to_bytes(2, 'little', signed=True)
               + dy.to_bytes(2, 'little', signed=True)
               + speed.to_bytes(2, 'little') + bytes([mode, seed]))
    ser.write(frame(0x36, 0x10, payload))       # 14 B，0.15 ms 上线
```

### 3.6 示例（Android / Kotlin，usb-serial-for-android）

```kotlin
fun sumv(port: UsbSerialPort, dx: Short, dy: Short, speed: Short, mode: Byte = 0x0E) {
    val p = ByteArray(8)
    p[0] = (dx.toInt() and 0xFF).toByte(); p[1] = (dx.toInt() shr 8).toByte()
    p[2] = (dy.toInt() and 0xFF).toByte(); p[3] = (dy.toInt() shr 8).toByte()
    p[4] = (speed.toInt() and 0xFF).toByte(); p[5] = (speed.toInt() shr 8).toByte()
    p[6] = mode; p[7] = 0
    val f = buildFrame(0x36, seq++, p)          // buildFrame 同 §3.5
    port.write(f, 200)                          // 200 ms 超时；不要等待回包
}
```

> Android 侧要点：
> 1. 必须**批量写**（一次 write 多帧），因为一次 USB bulk 传输占一个 1 ms 帧；
> 2. 不要用 `read(timeout)` 当节拍，回包异步收；
> 3. CH34x 驱动请确认支持 921600（多数支持 921600/1M/2M）。

---

## 4. 屏蔽语义（`sumv` 运行时）

`sumv` 执行期间，盒子**独占运动权**：

| 输入 | 行为 |
|---|---|
| 真实鼠标 X/Y | 丢弃（`SUMV_STATE.muted` 计数） |
| 真实鼠标 左右键/侧键 | **透传**（状态变化立刻发） |
| 真实鼠标 滚轮 | **透传** |
| `.km.move` / `MOTION_PLAN` | **被拒**（不执行、不回错误） |
| `.km.wheel` / `WHEEL` | 正常执行 |
| 再次 `sumv` / `SUMV` | **REPLACE**：旧轨迹立即丢弃，新轨迹从当前点开始（剩余位移不补） |

> 为什么按键/滚轮要"变化才发"：真实鼠标动起来是 540–900 条/秒，若每条都零位移转发会占满
> 1000 槽/s 的端点时隙，把 sumv 的 1 kHz 采样挤掉。

---

## 5. `sumv`：拟人化相对移动

### 5.1 它和 `.km.move` 的区别

`.km.move(dx,dy)` 没有速度参数：步数 = `ceil(max(|dx|,|dy|)/127)`、每步间隔 1 个 tick（10 ms），
等效速度约 13,000–16,000 counts/s（比人手快 ~30 倍），且距离越大越快。
`sumv` 有显式速度参数、1000 Hz 采样、带曲线与随机化。

### 5.2 参数

```
dx, dy   i16          相对位移（设备 counts，见 §5.6 换算）
speed    u16          counts/s，0 = 模块默认（出厂 400，台架可 mx.mv 改）
                     请求值夹到 [50, 65535]（u16）
                     实际上限 = 1000 × mr_eff（mr_eff 默认自动跟速度走：
                       mr = 12 + (speed-11000)/1000，夹到 [12,120]；最大 120 → 120,000）
                     想要"能多快就多快"用 mode.bit7（时长直接取 ceil(D/max_report)）
mode     u8           见下表
seed     u8           0 = 随机；非 0 = 可复现（同一 seed 轨迹一致）
dur_ms   u16          仅 mode.bit0 置位时生效（固定时长，调试用）
```

**mode 位**

| 位 | 含义 | 默认 |
|---|---|---|
| bit0 | 固定时长（用 `dur_ms`） | 关 |
| bit1 | 手颤 8–11 Hz（**仅拟人模式有效**） | 关 |
| bit2 | 子运动 1–3 个速度峰（**仅拟人模式有效**，且 `max(\|dx\|,\|dy\|)` > 600） | 关 |
| bit3 | ~~过冲回拉~~（**2026-11-11 已移除**；终点精确落在请求处） | — |
| bit4 | ~~微停顿~~（**2026-11-10 已移除**） | — |
| bit5 | 关闭"粘滞收尾"（**仅拟人模式有效**） | 关 |
| **bit6** | **拟人模式**：min-jerk + 手颤 + 子运动 + 大弧度（±span/12）+ 粘滞 | **关** |
| **bit7** | **极速**：时长直接取 `ceil(D / max_report)`，每样本正好 `max_report` counts（摸到 `1000×max_report` 上限） | **关** |

**默认 `mode = 0x00` → 瞄准模式（FPS 拉枪线）**：梯形速度剖面 + 1% 浅弧、无手颤/子运动。

> 历史值兼容：老客户端传 `0x06 / 0x0E / 0x1E` 时，因为 bit6=0，`bit1/bit2/bit5` **被忽略** →
> 自动落到"不抖"的瞄准手感。想要回 2026-11-11 之前的观感传 `0x40`（bit6）。

### 5.3 时长与速度

```
D       = round(hypot(dx, dy))                       // 路径长度（counts）
T_ms    = clamp(1000 * D / speed, 40, 5000)
speed_eff = 1000 * D / T_ms                          // 被 clamp 时看这个
```

| speed | 手感 | 2000 counts | 100 counts |
|---|---|---|---|
| 80 | 逐像素挪 | 5000 ms（截断，实际 400） | 1250 ms |
| 200 | 精确瞄准 | 5000 ms（截断，实际 400） | 500 ms |
| **400（默认）** | 日常 | 5000 ms | 250 ms |
| 800 | 干脆一挥 | 2500 ms | 125 ms |
| 2000 | 快速甩 | 1000 ms | 50 ms |
| 8000 | 近乎瞬移 | 250 ms | 40 ms（下限） |

### 5.4 输出特征（实测）

| 指标 | 值 |
|---|---|
| 采样 | 1000 Hz（`esp_timer` 1000 µs），`total_samples == T_ms` 恒成立 |
| 单报告位移 | speed=400 时 `|dx|+|dy|` p50 = 1、p90 = 1、max = 2 counts |
| 守恒 | Σ 发出的 counts 精确等于请求（REPLACE 打断除外） |
| 路径 | 三次贝塞尔，按弧长参数化。**瞄准模式**法向偏移 `±span/60`（弧高 ≈1.25%）、无沿路抖动；**拟人模式**保持 `±span/12` + `±10%` 抖动 |
| 终点 | **精确落在请求值**，无过冲：过程累计位移永不超过请求 |
| 速度剖面（瞄准模式） | 按距离分档：`D≤10` 单发；`D≤60` 恒速 + 纯直线；`61–300` 梯形（进 6% / 出 10%）；`301–800`（8% / 12%）；`>800`（10% / 15%） |
| 速度剖面（拟人模式） | min-jerk `6t⁵−15t⁴+10t³` |
| 收尾 | **瞄准模式**：`D ≥ 600` 才保留粘滞且强度减半，短距离完全不粘；**拟人模式**：全强度（尾段 ≈ −18%） |

**每报告上限 `mr`（自动模式，2026-11-11）**

```
mr_eff = 12 + (speed - 11000)/1000      // speed <= 11000 时就是 12
mr_eff = clamp(mr_eff, 12, 120)         // 极速 bit7 直接用 120
t_floor = ceil(D / mr_eff)              // 最低 4 ms
```

因为 `mr ≈ speed/1000 + 1`，`t_floor ≤ 1000·D/speed` 恒成立 →
**`speed` 就是字面速度**，不会再被 12,000 夹住。

**上位机不需要新字段就能知道"这一发每跳多大"**（`SUMV_STATE` 保持 29 B 不变）：

```
每报告 counts ≈ speed_eff / 1000         // 撞到 floor 时 t_ms == t_floor，该式精确
每报告 像素   ≈ speed_eff / 1000 × 1.25  // 1.25 px/count 为本机标定值
```

例：发 `speed=60000` → 回 `speed_eff=60000` → 60 counts ≈ 75 px/跳；
发 `speed=65535` 但回 `speed_eff=60000` → mr 已被夹到 66（`t_floor` 生效）。

**上位机只需要用 `speed` 表达意图**（没有"固定每报告 12"这种档位）：

| 场景 | speed | 自动得到的 mr | 每跳 | D=600 的时长 |
|---|---|---|---|---|
| 瞄准闭环每帧修正（10–200 counts） | 4,000–8,000 | 12 | 15 px | 75–150 ms |
| 瞄准大甩（300–800 counts） | 12,000–20,000 | 12–21 | 15–26 px | 30–50 ms |
| 走位 / 转身（1,000+ counts） | 40,000–60,000 | 41–61 | 51–76 px | 10–15 ms |
| 能多快就多快 | `mode.bit7` | **120** | 150 px | 5 ms |

> `每报告 12 counts` 与 `speed > 12,000` **在 1 kHz 采样下不可兼得**（每报告 = speed/1000），
> 所以不提供"高速度 + 小跳变"的组合；要细腻就选低 speed。

**实测（D=600，自动 mr，Σ 全精确）**

| speed | 实测时长 | 报告数 | 每报告 max | speed_eff | 每跳像素 |
|---|---|---|---|---|---|
| 11,000 | 52 ms | 53 | 13 | 11,111 | 16 |
| 12,000 | 49 ms | 50 | 14 | 12,000 | 18 |
| 20,000 | 29 ms | 30 | 23 | 20,000 | 29 |
| 40,000 | 14 ms | 15 | 45 | 40,000 | 56 |
| 60,000 | **9 ms** | 10 | 67 | 60,000 | 84 |
| 60,000（固定 mr=12，台架对照） | 49 ms | 50 | 14 | 12,000 ← 旧 floor | 18 |

**实测（speed=2000，瞄准模式）**

| 距离 | 总时长 | 起步 0–5% | 尾段 95–100% | Σ / 过程最大 |
|---|---|---|---|---|
| 30 | 38 ms | 1 ms（2.6%） | 1 ms（2.6%） | 30 / 30 |
| 300 | 149 ms | 11 ms（7.4%） | 14 ms（9.4%） | 300 / 300 |
| 2000 | 999 ms | 93 ms（9.3%） | 117 ms（11.7%） | 2000 / 2000 |
| 300（`0x40` 拟人） | 147 ms | 26 ms（17.7%） | 28 ms（19.0%） | 300 / 300 |

> **counts 与像素**：标定结论（`verification/report/2026-11-11-px-gain.md`）——本机增益是**常数
> `1.25 px/count`**（= 1.0 logical × 125% 缩放，且"提高指针精确度"已关闭，没有加速项）。
> 所以 `px = counts × 1.25`。**"速度越大越偏"的真因是屏幕边界钳位**：撞边后多发的 counts
> 被系统吃掉且不回补。要精确到位用 `tools/aim_move.py`（读光标 → 夹到剩余空间 → 分段闭环）。

**极速档实测（`mode.bit7`，2026-11-11）**

| 请求 | `max_report` | 实际时长 | `speed_eff` | 样本 | Σ |
|---|---|---|---|---|---|
| 2000 | 60 | 33 ms | 58,823 | 34 | 2000 ✓ |
| 2000 | 120 | 16 ms | 117,647 | 51 | 2000 ✓ |
| 8000 | 120 | 66 ms | 119,402 | 118 | 8000 ✓ |
| 300 | 120 | 3 ms | 75,000 | 4（时长下限 4 ms） | 300 ✓ |

### 5.5 状态机与安全阀

```
IDLE --sumv()--> RUNNING --(走完 | SUMV_STOP | 看门狗 | HID 卸载)--> IDLE
RUNNING --新 sumv()--> REPLACE（aborted++，剩余丢弃）
```

| 阀 | 规则 |
|---|---|
| 时长 | `T_ms ≤ 5000` |
| 看门狗 | 连续 200 ms 一帧都发不出去 → 自动停止并恢复透传 |
| 卸载 | HID 卸载时强制停止 |
| 人工 | `SUMV_STOP` / `.km.sumv_stop()` / 重启 |

### 5.6 counts ↔ 像素

取决于 PC 的指针速度与加速度设置，实测两种极端：

| 场景 | 换算 |
|---|---|
| 大量小步长（speed=400，每次 0–2 counts） | ≈ **0.575 px/count** |
| 一步大跳变（一次 ≥200 counts） | ≈ 1.6–2.0 px/count |

→ 想精确落到某个像素位置，请**闭环**：读光标位置 → 按实测比例换算 → 发 sumv → 复查。
（`tools/link_probe.py` 里的台架用例就是这么做的。）

---

### 5.7 按键事件（默认穿透，可选吃掉）

#### 5.7.1 语义

```
订阅 mask 内的键（1=左 2=右 4=中 8=侧4 16=侧5）：
  ① 真实鼠标按下/松开 → 控制口收到一条边沿事件；
  ② 按键本身**照常转发给 PC**（默认 = 穿透）；
     —— 只有 EVT_CTL 第 4 字节 = 1（"吃掉"）才把这些位从转发报告里抹掉，PC 看不到。
mask 之外的键：照常透传给 PC，不产生事件。
移动、滚轮：永不产生事件，也不改变转发行为。
盒子自己发出的按键（.km.left(1) / BUTTON 帧）：不产生事件。
```

> **2026-11-11 语义变更**：默认从"订阅即消费"改成 **默认穿透**。
> 老代码（`EVT_CTL` 只发 3 字节）现在拿到的是穿透；想吃掉必须显式发 `consume=1`。
> 判定证据看 `EVT_STAT.last_fwd`：穿透 → 按下时 `last_fwd` 跟着 `cur` 变；
> 吃掉 → `cur` 有值而 `last_fwd` 保持 0。（实测：吃掉模式注入 0x08 → `cur=08, last_fwd=00`；
> 穿透模式同一注入 → `cur=08, last_fwd=08`。）

#### 5.7.2 事件记录（8 B，EVT_READ 与 EVT_PUSH 同一布局）

| 偏移 | 类型 | 含义 |
|---|---|---|
| 0 | u32 | `t_us`，设备时钟（用 PING 的 `clock_us` 换算） |
| 4 | u16 | `seq`，单调递增，溢出/丢失可算 |
| 6 | u8 | `mask`，该时刻真实鼠标的完整按键位图 |
| 7 | u8 | `edge`，本次变化的位 |

#### 5.7.3 使用流程

```
1) 0x39 EVT_CTL: enable=1, mask=8, push=1 [, consume=0|1]
                              → 订阅侧键4 + 开推送（默认穿透；consume=1 才有吃掉）
2) 循环读：cmd 落在 0xE0–0xEF → 事件；其余 → 回包
3) 每 1–2 s 发 0x3B EVT_STAT（或 0x3A EVT_READ、PING）当心跳
4) 退出前 0x39 enable=0（或依赖 10 s 失联自动恢复）
```

#### 5.7.4 边界规则（都实测过）

| 场景 | 行为 |
|---|---|
| 订阅瞬间某个键已按住 | 只对"吃掉"模式有意义：该键**继续透传到松开**（否则 PC 会卡在按下），下一次按下才被吃；穿透模式无此概念（`pending` 恒 0） |
| 客户端 10 s 无心跳 | 自动取消订阅、恢复全透传，`EVT_STAT.flags` 的 bit2（auto_released）置位 |
| 事件环满（32 条） | 覆盖最旧，`EVT_STAT.overflow` 增；`seq` 不回绕，缺口可算 |
| 重启/拔插 | 订阅不持久化，回到全透传 |
| 文本侧 | `.km.evt(1[,mask[,consume]])` 订阅（默认穿透；第 3 参 1 = 吃掉；只入环，**不做文本推送**）、`.km.evt(0)` 取消、`.km.evt()` 查询；事件本身用二进制 `EVT_READ` 取 |

#### 5.7.5 台架判据 `mx.ev`

```
enabled,mask,pending,cur,last_fwd,seq,count,overflow,auto_released,push,consume
```
- `last_fwd` 是**最近一次真正发给 PC 的按键字节** —— 订阅后按被订阅的键，这个值应保持 0x00
  （即"PC 看不到"），取消订阅后应变回该位。

### 5.8 `AIM`：瞄准专用入口（推荐闭环用这个）

`sumv` 需要客户端懂 `speed`/`mr`/counts；瞄准其实只想说"朝这个方向走这么多，越快越好"。

```
0x3C AIM   payload: dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]    无回包
0x3D AIM_STATE → 12 B
```

| 参数 | 含义 |
|---|---|
| `max_ms` | 这一发**必须**在多少毫秒内走完（4–255，0 = 8）。内部折算 speed 并走**恒速剖面**（无加减速段，最小延迟）。注意：显式时长**不再被 `mr` 地板抬高**（2026-11-11 起） |
| `flags` | bit0 = 打开会话累计位移钳位（绝对值 > 4000 counts 就拒绝）；bit1 = 极速（等价 `sumv` 的 bit7） |
| `dead_min` | 切比雪夫残差 **≤** 它就算到位（默认 2 counts ≈ 2.5 px），不发任何报告，结果码 4 |

`AIM_STATE` 12 B：

| 偏移 | 类型 | 含义 |
|---|---|---|
| 0 | u8 | `active` |
| 1 | u8 | `last_result`：1 已启动/已到位 · 2 被替换 · 3 拒绝 · 4 死区 · 5 看门狗故障 · 6 超限 |
| 2 | u16 | 最后一次请求的 counts（切比雪夫长度） |
| 4 | u16 | 最后一次实际耗时 ms |
| 6 | u16 | `aborted`（被 REPLACE / 停止的次数） |
| 8 | u16 | `rounds`（正常走完次数） |
| 10 | u8 | `dead_hits`（因死区跳过的累计次数，饱和 255） |
| 11 | u8 | 轨迹代数低 8 位（每次 REPLACE +1，可用来配对） |

**实测（2026-11-11）**

| 请求 | 实测 | 说明 |
|---|---|---|
| `sumv(600,0,dur_ms=8)` | 7 ms / 8 报告 / Σ=600 | `dur_ms` 现在真的生效（以前被 mr=12 抬到 50 ms） |
| `AIM(300, max_ms=8)` | 7 ms / 8 报告 / Σ=300 | `AIM_STATE` = `00 01 2c 01 08 00 00 00 02 00 00 02` |
| `AIM(2)` | **0 报告**，`last_result=4` | 死区，光标不动 |
| `AIM(60, max_ms=4)` | 3 ms / 4 报告 / Σ=60 | |
| 极速 `sumv(2000, mr=120)` | 16 ms / 17 报告 / 最大间隔 **1011 µs** | 收尾改成"每 ms 最多补一发"，不再 1 ms 内连发 8 条 |

**闭环用法（每帧一条）**

```
读目标 → 残差 px → counts = px / 1.25 → AIM(counts, max_ms=帧间隔×0.8)
松手 / 丢目标 → SUMV_STOP（不要发 AIM(0,0)：那只会回"已到位"，不会打断正在跑的轨迹）
判断状态 → 读 AIM_STATE 的 last_result / active，不要只看命令发出去
```

## 6. 台架探针 `mx.*`（仅 `MB_DEBUG_OPCODE` 构建）

出货固件**没有**这些命令；台架抓包/排障时用。文本格式，直接发 `mx.xxx\r`。

> ⚠️ **不要写成 `.km.mx.xxx`**：控制口会先把 `.km.` 前缀剥掉、剩下的 `mx.xxx` 才被当作台架命令。
> 写成 `.km.lfx …` 会被当未知命令**静默丢弃**（本轮排查按键事件时就栽在这上面）。

| 命令 | 输出 |
|---|---|
| `mx.fv` | `force=<编译期> ovr=<运行时> dev=<当前服务的 VID/PID 字节>` |
| `mx.if` | `接口数` + 每接口 `报告描述符长度:IN端点:ReportID` |
| `mx.rb` | 当前服务的**输入报告字节数**（`bytes=7 desc=93 rid=0`）；与描述符不符时注入会被主机丢弃 |
| `mx.hi` | 右片 host 状态：`att/addr/id/itf/ep/gate/ok/fail/done/fwd …`。2026-11-11 起右片 `0x1C` 帧加长到 **36 B**，尾部追加 `ok/fail/done/fwd` 的 **u32**（原来 u16 满 65535 就饱和），回包末尾打印 `rate(ok/done/fwd)=…/s dt=…ms ex=ok|u16`；`ex=ok` 表示用的是精确计数 |
| `mx.hz` | **左片侧精确速率**（u32 计数）：`dt=<ms> frames=<n>/s chunks=<n>/s inj=<n>/s drop=<n> B=<n>/s`。连读两次即得窗口速率；`frames/s` = 右片实际喂过来的报告率 |
| `mx.lh <page 0..15>` | **转发报告间隔直方图**（每桶 100 µs × 256 桶）：输出 `idx:count;idx:count;…`，每页 16 桶。`mx.lat` 的 p50/p99 就是这张图算出来的；注意固件只做 **1/4 采样**，1 kHz 输入的名义间隔是 4 ms |
| `mx.sv` | sumv：`active,samples,aborted,rounds,muted,forwarded,speed_eff,remain_ms` |
| `mx.ev` | 按键事件通道：`enabled,mask,pending,cur,last_fwd,seq,count,overflow,auto_released,push` |
| `mx.mv [speed [max_report]]` | sumv 运行时默认值。读 → `speed,auto\|fixed,mr=<有效值>,cap=1000×mr`；写 → `<speed> <mr>`，**`mr=0` = 自动**（出厂自动）。**固定模式仅供台架排障**，生产路径请让 `speed` 决定一切 |
| `mx.mt` | 运动追踪环：`mx.mt on/off/clr`、`mx.mt d` 转储 3072 条 `(t_us,ep,len,hex)` |
| `mx.rt` | 累计位移 `dx,dy,wheel`（守恒断言用） |
| `mx.rq` / `mx.rp` | 最近 16 条报告 / 最后一条报告（hex） |
| `mx.dv` | 设备描述符 + 配置描述符原始 hex + mount 状态 |
| `mx.ox` | 厂商通道 `out,ok,in82,ack,drop` + 最后 8 字节 |
| `mx.hs` / `mx.hv` | HID 发送计数（ok/busy/fail/mount、队列 enqueue/sent/drop） |
| `mx.as` / `mx.ac` / `mx.rs` | 自动克隆状态 / 立即重克隆 / 重启 |
| `mx.hk <0\|1>` | **0xA2 进不进 HID 路径**：`1` = 启用 sink（正常转发）；`0` = 隔离（0xA2 不进 HID，台架做计数断言时用，用完记得 `mx.hk 1` 恢复） |
| `mx.ls` | 片间链路计数（frames/injected/dropped/rx_bytes …） |

---

## 7. 故障对照

| 现象 | 原因 | 处理 |
|---|---|---|
| 发命令无任何回包 | 未知命令 / 波特率不对 / 首条命令太早 | 核对 §2.3；确认 921600；首条命令重试 2–3 次 |
| 二进制帧一律被丢 | CRC 算法或长度字段不对 | 用 §3.1 的 CRC 自检：`crc8([0x35,0x00,0x04,0x00,...])` |
| `SUM`/`MOTION` 发出但光标不动 | 服务的报告长度与描述符不符（`mx.rb` 与 `mx.rd` 对不上）→ 主机静默丢弃 | `mx.rb` 应为 `bytes=7 desc=93`（7 字节布局）；不对就 `mx.rs` |
| 光标动但比请求少很多 | Windows 指针速度折扣（§5.6） | 闭环换算，或提高 speed 后重测 |
| 输出一顿一顿的 | 用了 `.km.move`（127 分块）而不是 `sumv` | 换 `sumv` |
| `mx.hi` 的 `fail` 一直涨 | 右片提交失败（端点/权限） | 看 `mx.ox` 的 `ok==out`、`mx.hs` |

---

## 8. 兼容性与变更

> 逐条变更见文末 **§11 变更记录**。

**老上位机**：如果只发文本命令，把波特率改成 921600 即可，其余不变。
**2026-11-11 决定：不为 per-command `mr` 扩协议。** `0x36 SUMV` 的 payload 保持
`dx i16 | dy i16 | speed u16 | mode u8 | seed u8 [| dur_ms u16]`（不追加 mr 字节）；
`0x38 SUMV_STATE` 保持 29 B（不追加 `mr_eff`）。理由：`mr` 完全由 `speed` 推导，
上位机用 `speed_eff / 1000` 即可反推每跳大小。将来真要"单条指令钉 mr"，在 payload
末尾追加一字节即可（长度门控，老客户端不受影响）。

**新固件对老命令**：49 条文本命令全部兼容；opcode 表从 27 项扩到 **30 项**（`0x1B` sumv / `0x1C` sumv_stop / `0x1D` evt 为扩展，
`mx.<hex>` 直接调 opcode 的台架用法受影响，出货不受影响）。

---

## 9. 参考实现

| 文件 | 内容 |
|---|---|
| `app_left/main/control_bin.c` | 二进制帧解析、CRC8、8 条命令 |
| `app_left/main/control_bin.h` | 命令字定义、payload 上限 |
| `components/makcu_proto/src/makcu_cmd_table.c` | 49 条文本命令表（43 原厂 + sumv/evt 扩展） |
| `components/makcu_sumv/src/makcu_sumv.c` | sumv 引擎（1000 Hz、贝塞尔、DDA） |
| `app_left/main/btn_evt.c` / `.h` | 按键事件环、边沿算法、pending 规则、失联看门狗 |
| `components/makcu_proto/src/cmd_evt.c` | `.km.evt` 文本命令（opcode 0x1D） |
| `tools/link_probe.py` | 现成的 Python 探针：`--ping` / `--query` / `--plan` / `--sumv` / `--evt MASK [--evt-selftest]` / `--aim DX DY` / `--aim-state` / `--all` |
| `tools/aim_stress.py` | **瞄准压力测试**：并发/队列 `AIM|SUMV` + 夹杂按键，右上角闭环；判据 = PC 侧按下/松开沿不少 + 无卡键 + 不越界 + 零溢出（详见 HANDOVER §14.25） |

---

## 10. 上位机集成检查清单

按顺序过一遍，能挡掉 90% 的坑：

- [ ] 波特率 **921600**，8N1，无流控；打开端口后 `dtr=False, rts=False`
- [ ] 首条命令**带重试**（2–3 次，间隔 200 ms）——设备刚上电要 ~1 s 才应答
- [ ] 用 `PING` 量一次 RTT（应 ≈1.1 ms）；> 5 ms 说明上位机在读的节奏上有问题
- [ ] 二进制帧的 CRC 用 poly 0x07、覆盖 `cmd..payload`；错帧直接丢，不要重传
- [ ] 运动命令**不要等回包**（fire-and-forget），回包只用于 `QUERY/PING/EVT_READ/EVT_STAT/SUMV_STATE`
- [ ] 事件帧识别：`cmd` 落在 `0xE0–0xEF` 就是异步帧，别去找对应的请求
- [ ] 订阅按键前先确认 `EVT_STAT.last_fwd` 会随"被订阅键按下"保持 0x00（否则说明没吃到）
- [ ] 订阅期间至少要发心跳（`EVT_READ`/`EVT_STAT`/`PING`），否则 10 s 后自动恢复透传
- [ ] 退出前发 `EVT_CTL enable=0`（或者让心跳停掉，交给自动恢复）
- [ ] 一次移动失败/没动，先查 `mx.rb` 的 `bytes` 与服务描述符是否一致（台架构建才有）
- [ ] 台架命令是 `mx.xxx`，**不要**加 `.km.` 前缀
- [ ] 串口独占：PC 与安卓同时监听需要中间转发，不能同时打开同一个口

---

## 11. 变更记录

| 日期 | 内容 |
|---|---|
| 2026-11-10 18:00 | 控制口 115200 → 921600；二进制通道 `0x31–0x35`；RTT 20 ms → 1.1 ms |
| 2026-11-10 18:30 | `sumv` 拟人化移动（`0x36–0x38` + `.km.sumv`），1000 Hz、speed 参数 |
| 2026-11-10 19:10 | 移除 sumv 微停顿（mode bit4 失效），默认 mode `0x1E → 0x0E` |
| 2026-11-10 19:40 | 按键事件通道（`0x39/0x3A/0x3B` + 异步 `0xE1` + `.km.evt`）：订阅即消费 |
| 2026-11-10 19:50 | 开机 autoclone 护栏（接口数为 0 判失败并重试）；`EVT_READ`/`EVT_PUSH` 记录顺序统一 |
| 2026-11-11 09:00 | 移除 sumv **过冲回拉**（bit3 失效），新增**粘滞收尾**（bit5 可关）；默认 mode `0x0E → 0x06` |
| 2026-11-11 09:30 | 新增**瞄准模式**（FPS 拉枪线，默认）：梯形剖面按距离分档、浅弧 1%、手颤/子运动默认关、粘滞只在长距离减半；`bit6` = 拟人模式；默认 mode `0x06 → 0x00` |
| 2026-11-11 10:00 | 速度上限：`speed` 钳位 `8000 → 65535`；时长下限 `40 ms →` 自适应 `ceil(D/max_report)`（最低 4 ms）；新增 `max_report`（8–120，出厂 60）、`bit7` 极速、台架命令 `mx.mv`；收尾补齐改循环（极速档缺口可 >127） |
| 2026-11-11 10:40 | `max_report` 出厂值 `60 → 12`（瞄准档，11,000–12,000 counts/s 量级）；新增 `tools/aim_move.py`（防撞边闭环到位）、`tools/px_cal.py`（增益标定）；GUI 显示实际像素与撞边标记 |
| 2026-11-11 11:00 | `max_report` 改为**自动跟速度**：`mr = 12 + (speed−11000)/1000`（夹 12–120），`mx.mv` 的 `mr=0` = 自动；固定模式保留 |
| 2026-11-11 12:40 | 瞄准专用优化：新增 `0x3C AIM` / `0x3D AIM_STATE`（按时长、死区、会话钳位）；`dur_ms` 不再被 `mr` 地板抬高；首样本立即发送；收尾补发改为每 ms 最多一发；加轨迹代数（消 REPLACE 竞态）与看门狗 |
| 2026-11-11 18:4x | 修按键假洪泛：透传路径同步 `s_buttons`（S1）、审计改上线级（S2）、按键队列 1 ms 去重 + `flood` 计数（S3）、`0x42` 扩到 18 B 带 8 条字节历史（S4）；`0x3E` 8→10 B |\n| 2026-11-11 16:58 | **修注入全丢**：`makcu_mouse_emit_now()` 的让路窗口用 `(int32_t)(deadline - now)` 且 deadline 初值 0，开机 35.8–71.6 min 区间会判成"窗口未结束" → 所有注入被丢弃（SUMV/AIM 都不动）；改为 int64 截止时刻 + `!= 0` 判定 |\n| 2026-11-11 16:20 | 新增 `0x40 AIM_RESET` / `0x41 EVT_RESET`；推模式下事件不再入环（修掉 overflow 虚高） |
| 2026-11-11 15:55 | **抖动排查配套**：新增 `0x3F BTN_AUDIT`（按键回环审计，见 §3.y）、`mx.hz`（左片精确速率）、`mx.lh`（转发间隔直方图）；右片 `0x1C` 帧 20 → **36 B**（追加 u32 计数，原来 u16 饱和在 65535）；`mx.hi` 改为优先显示 u32 精确值。结论见 HANDOVER §14.26：**不丢帧，抖动来自无线鼠标自身的成簇节奏** |
| 2026-11-11 12:00 | 按键事件改成**默认穿透**：`EVT_CTL` 新增第 4 字节 `consume`（缺省 0=穿透，1=吃掉）；`EVT_STAT.flags` bit3 = consume；文本 `.km.evt(1,mask[,consume])` |
| 2026-11-11 11:15 | **决定不扩二进制协议**：`0x36` 不加 mr 字节、`0x38` 保持 29 B；上位机用 `speed_eff / 1000` 反推每跳；`mx.mv` 固定模式降级为台架排障用 |
