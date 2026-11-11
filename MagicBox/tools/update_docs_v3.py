import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ---------- part 1: lock family samples ----------
p = os.path.join(ROOT, 'reversed', 'docs', 'reconstruction_patterns.md')
t = open(p, encoding='utf-8').read()
t += '''

---

## 8. 样板六：`lock_*` 四兄弟（opcode 0x00–0x03）

四个 handler 覆盖「查询 / 设置」×「轴 / 通道」两维：

```c
/* 0x4200DE40  lock_m*()：查询锁定状态 */
void cmd_lock_query(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry)
{
    if (!dev) return;
    uint8_t st = lock_get(dev, 1, entry->target);       /* 0x4202D1C8 */
    reply_status(entry->name, entry->len, st);          /* 0x4200DC18 */
}

/* 0x4200DE60  lock_mx()/lock_my()：查询轴向参数 */
void cmd_lock_axis(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry)
{
    if (!dev) return;
    uint8_t v = lock_axis_get(dev, entry->target);      /* 0x4202D240（target 1/2） */
    reply_status(entry->name, entry->len, v);
}

/* 0x4200DECC  lock_m*(：设置开关；'0' 还会连带清 catch */
void cmd_lock_param0(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry,
                     const char *arg, int len)
{
    if (len == 0) return;
    char c = arg[0];
    lock_set(dev, entry->target, c == '1');             /* 0x42010BA8 → 0x4200F9C4 */
    if (c != '1') {
        catch_set(dev, entry->target, 0);               /* 0x4202D1AC */
        *dirty_flag = 0;                                /* 0x42000DAC */
    }
    uart0_reply(reply_arg, 0);
}

/* 0x4200DF08  lock_mx( / lock_my(：设置轴向参数 */
void cmd_lock_param2(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry,
                     const char *arg, int len)
{
    if (len == 0) return;
    lock_axis_set(dev, entry->target, arg[0] == '1');   /* 0x42010C08：
                                                           target 1 → 0x4200F9F8
                                                           target 2 → 0x4200FA24 */
    uart0_reply(reply_arg, 0);
}
```

**为什么分四个 opcode**：`()` 形式只查询、`(` 形式才写；而 `mx/my`（轴）与 `ml/mr/mm/ms1/ms2`（按键）走的是不同子表（`ctx+0x210` 的 `+0x54` 与 `+0x9C` 两处偏移）。这解释了命令表里同一 target 出现两次 `()` 与 `(` 的成对条目。
'''
open(p, 'w', encoding='utf-8').write(t)

# ---------- part 2: resolve the UART1 header ----------
p2 = os.path.join(ROOT, 'reversed', 'docs', 'uart1_link.md')
t2 = open(p2, encoding='utf-8').read()
t2 += '''

---

## 6. 头部字段已定位（写入侧证据）

在右片找到三个**帧构造器**，头部写法完全一致：

```c
/* 0x420102A8：0xA0 控制传输请求 */
buf[0] = 0x5A;                    // 'Z' 魔数
buf[1] = 0xA0;                    // 命令
*(uint16_t *)(buf + 2) = 1;       // 负载长度 = 1
buf[4] = (param ? 0x00 : 0xFF);   // 负载第 0 字节 = 方向/标志
xQueueSend(queue[0], &buf, 0);
```

```c
/* 0x4200FAC0：0xA0 的填充助手 */
*(uint16_t *)(frame + 2) = 1;                  // 长度 1
frame[4] = (FUN_42010364() == 0) ? 0xFF : 0x00; // 方向
```

```c
/* 0x4200FAE0：0xA3 帧 */
*(uint16_t *)(frame + 2) = 1;
frame[4] = 0;
```

```c
/* 0x4200F6C4：通用转发，按源帧的 +1 命令字节分派 */
out[0] = 0x5A;
out[1] = src[1];
/* 0xA0 → 4200FAC0；0xA1 → 短帧置 len=1/flag=0xFF，长帧 → 4200FC74；0xA3 → 4200FAE0 */
```

### 修正后的头部布局

| 偏移 | 含义 | 证据 |
|---|---|---|
| `+0` | **魔数 `0x5A`（'Z'）** | 三个构造器一致 |
| `+1` | **命令字节**：`0xA0` EP0 隧道、`0xA1`、`0xA2` 数据/事件、`0xA3` | 构造器 + 左片 `42013734` 分支 |
| `+2..3` | **u16 负载长度**（不是类型） | 构造器统一写 `1`，发送侧按 `长度+4` 计算总长 |
| `+4` 起 | **负载**（不是头部第 5 字节） | 左片读到的 `+4/+5/+6/+8` 实际是 `payload[0..4]` |

由此推翻上一版的两处“不一致”：

1. 长度 `+2` 恒为长度；左片 `0xA0` 分支里的 `==1` 实际是**负载长度为 1**（1 字节的 EP0 请求），不是“类型=1”；
2. 右片按 `长度+4` 发送、左片读到 `+8`：因为 `+8` 是 `payload[4]`，属于负载，不是头部溢出。

### 各命令的负载语义

| 命令 | 负载长度 | 负载内容 |
|---|---|---|
| `0xA0` | 1 | `payload[0]` = 方向：`0x00` 发起 EP0 IN，`0xFF` 另一方向（`4200FAC0`） |
| `0xA3` | 1 | `payload[0]` = 0（`4200FAE0`） |
| `0xA1` | 1（短帧） | `payload[0]` = `0xFF` |
| `0xA2` | ≥5 | 左片按 `payload[1]`(会话 id)、`payload[2]`(有效位)、`payload[4]`(端点/report id) 做过滤 |

至此 UART1 的帧格式已完整：**`5A <cmd> <len:u16> <payload…>`**。
'''
open(p2, 'w', encoding='utf-8').write(t2)
print('docs updated')
