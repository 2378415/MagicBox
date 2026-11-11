import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

p = os.path.join(ROOT, 'reversed', 'docs', 'reconstruction_patterns.md')
t = open(p, encoding='utf-8').read()
t += '''

---

## 5. 样板三：`cmd_catch_set`（`0x4200DF58`，opcode 0x0A）

```c
/* catch_m*(  ：开启/关闭某个鼠标通道的抓取
 * a2=ctx  a3=reply_arg  a4=entry  a5=dev  a6=arg  a7=len
 * entry->target 位于表项 +0x0C，对应 1..5（左/右/中/侧1/侧2） */
void cmd_catch_set(ctx_t *ctx, int reply_arg, entry_t *entry, dev_t *dev,
                   const char *arg, int len)
{
    int target = entry->target;
    void *slot = *(void **)(ctx->tbl + 0x54 + target * 4);   /* ctx+0x210 指向的通道表 */

    if (len == 0 || slot == NULL) {          /* 未启用该通道：只回执 */
        uart0_reply(reply_arg, 0);
        return;
    }
    if (arg[0] != '0' && arg[0] != '1') {    /* 参数必须是 0/1 */
        uart0_reply(reply_arg, 0);
        return;
    }

    catch_set(dev, target, arg[0] == '1');   /* 0x4202D1AC */
    *dirty_flag = 1;                         /* 0x42000DAC，通知提交任务 */
    uart0_reply(reply_arg, 0);
}
```

要点：**先把“通道是否已启用”作为前置条件**（`ctx+0x210` 表的 `+0x54` 槽位为 NULL 就直接回执），这也是 `catch_ml(1)` 对未开启通道无效果的原因。

---

## 6. 样板四：`cmd_buttons`（`0x4200DDBC`，opcode 0x0C）

```c
void cmd_buttons(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry,
                 const char *arg, int len)
{
    bool is_query = (strncmp(entry->name, "buttons()", 9) == 0);

    if (len == 0 || is_query) {                 /* buttons()  → 查询当前模式 */
        if (dev != NULL) {
            int mode = buttons_get(dev);        /* 0x42010C64 */
            reply_status(entry->name, 9, mode); /* 0x4200DC18 */
        }
        return;
    }
    if (len == 1 && arg[0] == ')') {            /* buttons( ) 也按查询处理 */
        if (dev != NULL) reply_status(entry->name, 9, buttons_get(dev));
        return;
    }
    if (len == 2 && (arg[0] == '0' || arg[0] == '1') && arg[1] == ')') {
        buttons_set(dev, arg[0] == '1');        /* 0x42010C44 */
        uart0_reply(reply_arg, 0);
        return;
    }
    uart0_reply(reply_arg, 0);                  /* 其它参数：只回执 */
}
```

---

## 7. 样板五：`cmd_key_down`（`0x4200EC48`，opcode 0x0D）

```c
void cmd_key_down(ctx_t *ctx, int reply_arg, dev_t *dev, entry_t *entry,
                  const char *arg, int len)
{
    if (len == 0) return;

    int usage;
    if (arg[0] == '\\'') {                        /* 'A' 形式 */
        if (len < 3 || arg[len - 1] != '\\'') return;
        usage = char_to_usage(arg[1]);           /* 0x4202D2A0 */
    } else {                                     /* 十进制形式，允许空白与 +/- */
        usage = parse_usage(arg, len);           /* 内联解析，越界/无数字返回 0 */
    }

    if (usage == 0) return;                      /* 解析失败静默返回 */
    hid_key_down(dev, usage);                    /* 0x42010E70 */
    uart0_reply(reply_arg, 0);
}
```

`cmd_key_up`（`0x4200EB1C`）与之同构，只把 `hid_key_down` 换成 `hid_key_up`（`0x42010F00`）。

**共同点**：三个 handler 都是「前置校验 → 一次业务调用 → `uart0_reply`」，与 §1 的三段式完全一致；差别只在参数形式（`0/1`、`'c'`、十进制）。
'''
open(p, 'w', encoding='utf-8').write(t)
print('patterns updated')
