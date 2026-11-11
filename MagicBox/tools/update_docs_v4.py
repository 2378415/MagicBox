import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

p = os.path.join(ROOT, 'reversed', 'README.md')
t = open(p, encoding='utf-8').read()
t = t.replace('| 语义命名 | **62** 个（`cmd_*` 33、`hid_*` 9、`mouse_*` 9、`uart0_*` 5、`frame_*` 3、`hid_report_*` 2、`config_load`），另 17 个候选落在字符串/数据地址上已跳过；见 `docs/renames.md` |',
              '| 语义命名 | **72** 个（`cmd_*` 33、`frame_*/bridge_*` 7、`hid_*` 9、`mouse_*` 9、`uart0_*/uart1_*` 6 等），另 17 个候选落在字符串/数据地址上已跳过；见 `docs/renames.md` |')
t = t.replace('├── renames.md             ← 62 个语义命名及其依据',
              '├── renames.md             ← 72 个语义命名及其依据')
open(p, 'w', encoding='utf-8').write(t)

p2 = os.path.join(ROOT, '官方固件逆向分析报告.md')
t2 = open(p2, encoding='utf-8').read()
t2 += '''

### 12.13 片间链路函数命名 + 帧格式落图

把 UART1 链路上定位到的函数全部落名（源码树与 Ghidra 同步，命名总数 62 → 72）：

| 地址 | 名称 | 作用 |
|---|---|---|
| `0x420100FC` | `bridge_init` | 建 8 队列、8×8 缓冲、8 个 `hid_uart` 任务 |
| `0x4200FE68` | `hid_uart_task` | 取包 → 按 `*(u16*)(pkt+2)+4` 计算长度发送 |
| `0x4200F6B0` | `uart1_write` | `uart_write_bytes(UART_NUM_1, …)` |
| `0x420102A8` | `frame_build_ep0` | 构造 `5A A0 01 <dir>` 帧 |
| `0x4200FAC0` | `frame_ep0_dir` | 0xA0 的 len=1 与方向字节 |
| `0x4200FAE0` | `frame_a3_flag` | 0xA3 的 len=1、flag=0 |
| `0x4200F6C4` | `frame_forward` | 按源帧 `+1` 命令改写头并转发 |
| `0x42010244` | `bridge_release` | 释放/复位一个桥接槽位 |
| `0x42013734`（左） | `uart1_frame_parse` | 解析 `5A` 帧，EP0 隧道与 0xA2 分支 |
| `0x42013884`（左） | `uart_events` | UART1 事件循环 |

于是整条链路可以顺着函数名读完：`bridge_init` → `hid_uart_task` → `uart1_write` → 左片 `uart_events` → `uart1_frame_parse` → `usbd_ep0`。
'''
open(p2, 'w', encoding='utf-8').write(t2)
print('updated')
