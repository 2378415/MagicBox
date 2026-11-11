import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# hidden-protocol doc: extend the reachability section
p = os.path.join(ROOT, '官方固件未公开协议.md')
t = open(p, encoding='utf-8').read()
t += '''

### 9.1 片间 UART1 也不是入口

右片 → 左片的 UART1 帧由 `hid_uart_task`（`0x4200FE68`）发出，长度取自头部 `+2` 的 16 位字段（总长 = 长度 + 4）；左片 `uart_events`（`0x42013884`）只把 `hdr[1] == 0xA0` 的帧交给 `FUN_42013734` 做 USB EP0 隧道（`usbd_ep0`），**不经过 `cmd_dispatch`**。

结论：UART0 与 UART1 两条链路都不分发这 13 个 opcode，它们目前只能视为遗留代码或为其他硬件变体保留。详见 `reversed/docs/uart1_link.md`。
'''
open(p, 'w', encoding='utf-8').write(t)

# README: add the two new docs
p2 = os.path.join(ROOT, 'reversed', 'README.md')
t2 = open(p2, encoding='utf-8').read()
t2 = t2.replace('    ├── call_graph.md          ← 最常被调用函数 + 跨模块调用矩阵',
                '    ├── call_graph.md          ← 最常被调用函数 + 跨模块调用矩阵\n'
                '    ├── reconstruction_patterns.md ← 缺口函数的 C 级重写样板\n'
                '    ├── uart1_link.md          ← 片间 UART1 帧格式（4 字节头 + EP0 隧道）')
open(p2, 'w', encoding='utf-8').write(t2)

# report: new section
p3 = os.path.join(ROOT, '官方固件逆向分析报告.md')
t3 = open(p3, encoding='utf-8').read()
t3 += '''

### 12.11 片间链路与 C 级重写样板

**（1）UART1 片间帧解出**：

- 右片 `hid_uart_task`（`0x4200FE68`）从队列取包，按 `*(uint16_t*)(pkt+2) + 4` 计算总长，经 `uart_write_bytes(UART_NUM_1, ...)` 发出 → **帧 = 4 字节头 + 负载，头的 `+2` 是 16 位负载长度**；
- 左片 `uart_event_task`（`0x420139E4`）安装 UART1 并起 `uart_events` / `hid_data_processing` / `hid_parse_task`；
- 左片 `FUN_42013734` 只处理 `hdr[1] == 0xA0` 的帧，按 `hdr+2` 的类型位调用 `usbd_ep0` 完成 **USB 控制传输隧道**，其余忽略。

因此 UART1 也不分发隐藏 opcode：13 个隐藏处理函数在两条外部链路上都不可达，判定为遗留/变体保留（需上机断点才能最终确认）。

**（2）缺口函数 C 级重写样板**：`reversed/docs/reconstruction_patterns.md` 给出 `cmd_move` 的完整重写（解析 5 个 int16、`n==2` 走 `mouse_move`、`n==5` 走 `mouse_submit_ext` 且第 3 参限 1..1024、统一回执）与 `cmd_channel_toggle` 的部分重写（标出 3 处未确认字段）。

**（3）兜底块对齐修复**：此前 objdump 是整段线性反汇编，遇到数据字节会漂移，导致部分函数块起点错位。现在改为**按函数入口单独反汇编**（153 次 `--start-address`），`cmd_channel_toggle` 的首行已正确回到 `4200e56c: entry a1, 48`。
'''
open(p3, 'w', encoding='utf-8').write(t3)
print('updated')
