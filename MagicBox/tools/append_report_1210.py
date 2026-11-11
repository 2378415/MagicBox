import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
p = os.path.join(ROOT, '官方固件逆向分析报告.md')
t = open(p, encoding='utf-8').read()
t += '''

### 12.10 二进制帧路由与兜底块注释化

**（1）发现 UART0 的首字节路由器** `0x4200DB04`（命名 `frame_router`）：

| 首字节 | 去向 |
|---|---|
| `0x2E` `.` | 文本命令分发 `cmd_dispatch`，即线上真实文本帧是 `.km.left()\\r` |
| `0xA1` | 回 1 字节 ack |
| `0xA2` | 忽略 |
| `0xA4` | `config_load` 读 NVS（storage/config/baud_rate） |
| `0xA5` + 4 字节 | `SERIAL_SETUP` 写序列号 |
| 其它 | `frame_echo_hex` 用 `"%02X "` 回显，**不分发** |

这条把未公开 opcode 的可达性收敛了：UART0 不会把首字节当 opcode 送进跳表，13 个隐藏处理函数只能由片间 UART1 或内部调用触发。

**（2）语义命名增至 62 个**：新增 `frame_router`、`uart_rx_frame`、`frame_echo_hex`、`config_load`、`hid_report_get_bits`、`hid_report_set_bits`。剩余未命名 vendor 函数 29 个，主要是 libgcc 软浮点例程（`4201EBE8`/`4201ED60`/`4201EECC`/`4201F2D8`，操作 `undefined8`/`CONCAT44`）与 IDF 计时辅助（`40376788`/`4037679C`），无强证据前保持 `FUN_` 名。

**（3）153 个兜底块注释化**：objdump 反汇编现在逐行带符号与字符串注释，例如

```
4200e192:  call8  0x4200f744   ; mouse_submit_ext
4200e1a1:  call8  0x42010bc4   ; mouse_move
4200e1ab:  call8  0x420143e8   ; uart0_reply
```

阅读 `halt_baddata` 函数时不必再手工查地址表。
'''
open(p, 'w', encoding='utf-8').write(t)
print('report updated')
