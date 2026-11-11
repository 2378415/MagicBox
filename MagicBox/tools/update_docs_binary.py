import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ---------- protocol doc: append binary frame routing ----------
p = os.path.join(ROOT, '官方固件命令协议.md')
t = open(p, encoding='utf-8').read()
t += '''

---

## 10. 二进制帧路由（补充）

命名剩余函数时发现 UART0 的接收路径不止文本命令，`0x4200DB04` 是一个**首字节路由器** [观察]：

```c
void frame_router(uint8_t *buf, int len)
{
    uint8_t op = *buf++;
    if (op == 0xA2) return;                     // 心跳/忽略
    if (op == 0x2E) { cmd_dispatch(buf, len-1); return; }   // '.' → 文本命令
    if (op == 0xA1) { reply(&0xA1, 1); return; }            // ack
    if (op == 0xA4) { config_load(buf); return; }           // NVS 配置读取
    if (op == 0xA5 && len-1 >= 4) {                        // 写序列号
        SERIAL_SETUP(*(uint32_t*)buf); return;
    }
    frame_echo_hex(op, buf, len-1);             // 未知帧：按 "%02X " 回显
}
```

| 首字节 | 处理 | 证据 |
|---|---|---|
| `0x2E` `.` | 进入文本命令分发 `cmd_dispatch` | `0x4200DB04` 分支 |
| `0xA1` | 回 1 字节 `0xA1`（ack） | 同上 |
| `0xA2` | 直接返回（忽略） | 同上 |
| `0xA4` | `config_load`：读 NVS `storage/config/baud_rate` | `0x420130A4` |
| `0xA5` | 后随 4 字节 → `SERIAL_SETUP(value)`，写序列号 | 同上 |
| 其它 | `frame_echo_hex`：`"%02X "` 十六进制回显 | `0x4200DAD8` |

**推论**：文本帧实际是 `.` 前缀 + `km.xxx`，即完整线上格式为 `.km.left()\\r`。未知 opcode 只被回显、不会分发，所以 §2 的 13 个隐藏处理函数仍不受这条路由驱动，它们更可能由片间 UART1 或内部调用触发。
'''
open(p, 'w', encoding='utf-8').write(t)

# ---------- hidden protocol doc: reachability correction ----------
p2 = os.path.join(ROOT, '官方固件未公开协议.md')
t2 = open(p2, encoding='utf-8').read()
anchor = '1. 右片（USB Host 侧）经两片之间的 UART1 直接按 opcode 调用 [推断]；'
t2 = t2.replace(anchor, anchor + '\n')
t2 += '''

---

## 9. 可达性修正（补充）

后续命名时定位到 `0x4200DB04`（`frame_router`）：UART0 的首字节路由器。它只把 `0x2E`(.) 转发给文本分发器，把 `0xA1/0xA2/0xA4/0xA5` 用于 ack、忽略、读配置、写序列号，其余字节交给 `frame_echo_hex` 回显 —— **不会**把首字节当 opcode 送进 §2 的跳表。

因此上表 13 个处理函数在 UART0 文本/二进制帧上仍然不可达；能触发它们的只可能是片间 UART1 的私有帧或代码内部直接调用。这一条把原先“可能有二进制兜底”的猜测收敛为“已确认没有”。
'''
open(p2, 'w', encoding='utf-8').write(t2)

# ---------- README numbers ----------
p3 = os.path.join(ROOT, 'reversed', 'README.md')
t3 = open(p3, encoding='utf-8').read()
t3 = t3.replace('| 语义命名 | **56** 个（全部在左片：`cmd_*` 33、`hid_*` 9、`mouse_*` 9、`uart0_*` 5），另 17 个候选落在字符串/数据地址上已跳过；见 `docs/renames.md` |',
                '| 语义命名 | **62** 个（`cmd_*` 33、`hid_*` 9、`mouse_*` 9、`uart0_*` 5、`frame_*` 3、`hid_report_*` 2、`config_load`），另 17 个候选落在字符串/数据地址上已跳过；见 `docs/renames.md` |')
t3 = t3.replace('├── renames.md             ← 56 个语义命名及其依据',
                '├── renames.md             ← 62 个语义命名及其依据')
t3 = t3.replace('| 未命名 vendor 函数 | 33', '| 未命名 vendor 函数 | 29')
open(p3, 'w', encoding='utf-8').write(t3)
print('docs updated')
