import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
p = os.path.join(ROOT, 'reversed', 'docs', 'uart1_link.md')
t = open(p, encoding='utf-8').read()
t += '''

---

## 7. 0xA2 帧的写入侧证据（补上缺口）

`0x4200FF10`（USB 事件处理，无直接调用者，说明是回调注册）里找到 0xA2 构造：

```c
frame[0] = 0x5A;
frame[1] = 0xA2;
frame[4] = *(uint8_t *)((int)client + 0x8F);      /* payload[0] = 端点/接口号 */
frame[5] = id;                                     /* payload[1] = 会话/队列 id */
frame[6] = (uint8_t)len;                           /* payload[2] = 负载长度 */
frame[7] = 0;                                      /* payload[3] = 0 */
*(uint16_t *)(frame + 2) = ((uint16_t)len & 0xff) + 4;  /* 头部长度字段 */
queue_send(...);
```

与左片 `0x42013734` 的过滤条件一一对应：

| 偏移 | 写入值 | 左片用途 | 结论 |
|---|---|---|---|
| `+4` | `client+0x8F` 端点号 | 与描述符 `+0x62` / `+0x1d5` 比较 | **端点地址**（EP number） |
| `+5` | `id` | 与全局 `DAT_42001208` 比较 | **会话/队列 id** |
| `+6` | 负载长度 | 非零才继续 | **长度**（不是“有效位”） |
| `+7` | 0 | — | 填充 |

这样 UART1 的两种帧都有写入侧证据了：`0xA0`（EP0 隧道，1 字节方向）与 `0xA2`（HID 上报，端点号 + id + 长度）。

唯一仍需动态确认的是：`+2` 处的长度字段在 0xA2 分支写的是 `len+4`，而发送端又按 `该值+4` 计算总长 —— 说明这一字段可能包含 4 字节头，实际总长 = 字段值 + 4 仍需抓包核对。
'''
open(p, 'w', encoding='utf-8').write(t)

p2 = os.path.join(ROOT, '官方固件逆向分析报告.md')
t2 = open(p2, encoding='utf-8').read()
t2 += '''

### 12.14 0xA2 帧写入侧闭合

`0x4200FF10`（USB 事件回调）里找到 0xA2 构造，负载字段与左片过滤条件完全对应：`payload[0]=端点号`（`client+0x8F`，对应描述符 `+0x62/+0x1d5`）、`payload[1]=会话 id`、`payload[2]=长度`、`payload[3]=0`。至此 UART1 两种帧（0xA0 EP0 隧道、0xA2 HID 上报）都有写入侧与读取侧证据，仅剩长度字段的口径需要抓包核对。
'''
open(p2, 'w', encoding='utf-8').write(t2)
print('updated')
