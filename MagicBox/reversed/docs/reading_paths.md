# 阅读路径（五条主线）

按这五条线走一遍，就能把两片固件的主要行为读完。每条线给出「起点函数 → 调用链 → 落盘文件」。

---

## 1. 串口命令链路（左片最核心）

文本帧 `km.left()\r` 从 CH343 进来后的完整路径：

| 步骤 | 地址 | 文件 |
|---|---|---|
| 初始化 UART、建 4 个任务 | `0x420142A0` | `src/left/uart/420142a0_uart0_in.c` |
| 帧消费任务（取帧、去前缀） | `0x42014393`（字符串） | `src/left/uart/` |
| 命令表查表 `strncmp(name,len)` | `0x4200EEC4` | `src/left/protocol/4200eec4_FUN_4200eec4.c` |
| opcode 跳表 `jx` | `0x4200EF18` | `src/left/protocol/4200ef18_FUN_4200ef18.c` |
| 各命令处理函数 | `0x4200DB**`–`0x4200ED**` | `src/left/protocol/` |
| 回执 | `0x420143E8` | `src/left/uart/420143e8_FUN_420143e8.c` |

命令表在 `0x3C03DF74`（43×20 字节），跳表在 `0x3C03DF08`（27 项），见 `官方固件命令协议.md`。

**注意**：`4200e024`（`move(`）与 `4200e56c`（0x18）等函数 Ghidra 反编译失败，文件末尾附了 objdump 反汇编块，直接读汇编即可。

---

## 2. 鼠标提交链路

| 步骤 | 地址 | 说明 |
|---|---|---|
| 创建提交任务/定时器 | `0x4200F83C` | `initialize_mouse_commit_task` |
| 任务主体 | `0x4200F848` | `MouseCommitTask` |
| 贝塞尔平滑定时器 | `0x4200F873` | `BezierTimer` |
| 单次提交汇合点 | `0x4200EFEC` | 两条移动路径都落到这里 |
| 2 参移动入口 | `0x42010BC4` → `0x42010B60` | 标准 `move(x,y)` |
| 5 参扩展入口 | `0x4200F744` | `move(x,y,z,w,v)`，第 3 参限 1..1024 |
| 滚轮 | `0x42010BEC` → `0x4200F96C` | `wheel(d)`，值域 int8 |

目录：`src/left/mouse/`。

---

## 3. HID 设备侧（描述符克隆与序列号）

| 步骤 | 地址 | 说明 |
|---|---|---|
| 描述符解析任务 | `0x42013AE2` / `0x42013AF9` | `hid_data_processing` / `hid_parse_task` |
| 报文缓冲 | `0x4201455C` | `hid_data` |
| 帧提交 | `0x420145B5` | `CommitFrame` |
| 序列号装配 | `0x4201423C` | `SERIAL_SETUP` |
| 伪装开关 | 字符串 `Original`/`Spoofed` | `0x3C036518`/`0x3C03650C` |

目录：`src/left/hid/`。

---

## 4. 隐藏键盘 API（无文本命令，只有 opcode）

| opcode | 地址 | 能力 |
|---|---|---|
| 0x0D / 0x0E | `0x4200EC48` / `0x4200EB1C` | 单键按下 / 释放 |
| 0x0F | `0x4200E9D0` | 点按（带延时范围） |
| 0x10 | `0x4200DE80` | 字符串逐字符输入（≤63 字节） |
| 0x12 / 0x13 / 0x14 | `0x4200E6F0` / `0x4200E718` / `0x4200E998` | 批量按下 / 释放 / 组合键 |
| 0x16 | `0x4200E624` | 写映射表项（跳表专用入口，手工重建） |
| 0x17 | `0x4200DBB0` | 导出通道表 |
| 0x18 | `0x4200E56C` | 通道开关位写入（入口被 `excw` 打断，仅汇编兜底） |
| 0x19 | `0x4200E1B0` | `silent(` 静默移动：`<2` 参零回执，2 参走脉冲移动 |
| 0x1A | `0x4200DC84` | `serial(` 序列号查询 / 恢复 / 伪装（跳表专用入口，手工重建） |

底层写入函数在 `src/left/keyboard/`：`hid_key_down 0x42010E70`、`hid_key_up 0x42010F00`、`tap 0x42010F8C`、`type_string 0x42010FDC`。

详见 `官方固件未公开协议.md`。

---

## 5. eFuse 与崩溃转储（不可逆操作区）

| 步骤 | 地址 | 说明 |
|---|---|---|
| eFuse 烧写入口 | `0x42011188` / `0x420111A5` | `USB_PHY_SEL`、`UART_PRINT_CONTROL` |
| 崩溃转储 | `0x42012B50` | `crash_dump`，写入 coredump 分区 `0x110000` |

目录：`src/left/efuse/`、`src/left/crash/`。

---

## 建议的读法

1. 先读 `docs/module_map.md`，确认模块规模；
2. 沿着第 1 条线读 protocol 模块（33 个函数，一小时内可通读）；
3. 再用 `docs/function_index.md` 按地址跳转到调用者/被调用者；
4. 遇到 `halt_baddata()` 就看文件末尾的 objdump 块；
5. 需要精确语义时，对照 `官方固件命令协议.md` / `官方固件未公开协议.md`。
