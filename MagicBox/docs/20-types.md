# 20-types：需要先定下来的数据结构

所有偏移都来自旧仓库的反编译与反汇编，括号里是证据函数。

## 1. 命令表项（LEFT）

```c
typedef struct {              // 0x14 字节，43 项，基址 0x3C03DF74
    const char *name;         // +0x00  字面量，含尾部 "(" 或 "()"
    uint32_t    len;          // +0x04  前缀比较长度
    uint32_t    argc;         // +0x08  期望参数个数（handler 用法反推）
    uint32_t    target;       // +0x0C  1..5 按键/轴编号，0 表示无
    uint32_t    opcode;       // +0x10  跳表下标 0x00..0x1A
} makcu_cmd_t;
```

由 `tools/extract_tables.py` 从镜像导出到 `components/makcu_proto/src/makcu_cmd_table.c`。

## 2. 设备上下文 `dev_t`（LEFT）

只列**已被代码证实的字段**，未证实的保持 TODO：

| 偏移 | 类型 | 含义 | 证据 |
|---|---|---|---|
| `+0x210` | `uint32_t *` | 通道子表基址 | `lock_set`/`axis_slot_set`/`catch_set` 判空 |
| ↳ `+0x54 + target*4` | `uint32_t` | 通道启用槽（target 1..5） | `channel_slot_set`（0x4200F9C4） |
| ↳ `+0x9C + target*4` | `uint32_t` | 轴向槽（target 1..16） | `axis_slot_set`（0x4200FA50） |
| ↳ `+0x168 + target*4` | `uint32_t` | catch 槽 | `catch_set`（0x4202D1AC） |
| `+0x214` | `uint8_t *` | 描述符/大表基址 | `cmd_channel_toggle`、`cmd_dump_channels` |
| ↳ `+0x269 + idx` | `uint8_t` | 启用位（256 项） | `cmd_channel_toggle` 写 |
| ↳ `+0x369 + idx` | `uint8_t` | 存在位（256 项） | `cmd_channel_toggle` 读 |
| ↳ `+0x636 + idx` | `uint8_t` | 第三组标志（256 项） | `cmd_dump_channels` 读 |

## 3. 全局标志与邮箱（LEFT）

| 地址/全局 | 含义 | 证据 |
|---|---|---|
| `0x3FC99FA3` | "配置已变更/需要重发" | `cmd_channel_toggle` 写 0/1 |
| `DAT_42000DAC` | dirty 标志 | `cmd_catch_set`、`cmd_lock_param0` |
| `DAT_42000E88` | 待提交的滚轮增量（`int16`） | `wheel_submit` |
| `DAT_42000E04` | 提交请求标志 | `wheel_submit`/`channel_slot_set` |
| `DAT_42000E08` | 提交任务句柄 | `xTaskGenericNotify` 目标 |
| `DAT_42000E8C` | buttons 模式字节 | `buttons_get/set` |

## 4. 传输/URB 结构（RIGHT，`usb_event_handler` 视角）

`param_1` 是传输描述符，字段按下标访问（`int *`，每项 4B）：

| 下标 | 含义 |
|---|---|
| `[1]` | 数据缓冲指针；`+2` = 端点地址字节（`&0x0F` 端点号，`&0x08` = IN），`+4` 低 16 位 = `wMaxPacketSize`，`+6` = 包大小位 |
| `[5]` | 总线号/设备地址快照 |
| `[6]` | 缓冲指针副本 |
| `[8]` | 已传字节数 |
| `[9]` | 本次接收数据指针（`buf + 8`） |
| `[10]` | 包大小 |
| `[0x11]` | 完成回调（`PTR_FUN_42000d74`） |
| `[0x12]` | 回调上下文（= 自身指针） |

发送端的状态表：`DAT_42000D68 + ep*0x24`（每端点 8 个缓冲 × 9 word），
环形下标在 `+0x20`，用 `(i+1)&7` 轮转。

## 5. NVS 键（从字符串与调用点还原）

| 分区 | 键 | 用途 |
|---|---|---|
| `storage` | `config/baud_rate` | 控制口波特率（`config_load` 0x420130A4） |
| `nvs` | 其余未知 | TODO：P0 用 `nvs_partition_gen` 读原厂 `nvs` 分区 dump |

## 6. 待确认（不要凭猜写进代码）

1. `dev_t` 的其余字段（USB 描述符状态、报告缓冲）——需要 T3 对照逐个落定；
2. `+0x636` 第三组标志的语义（只知被 `cmd_dump_channels` 读）；
3. UART1 `0xB1` 的用途（无处理分支，只回纯头帧）。
