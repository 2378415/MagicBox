# 反编译缺口的 C 级重写（样板）

Ghidra 在 153 个函数上中断，源码树里只留下 `halt_baddata()` + 逐条汇编。
现在这 153 个里 **136 个已经能正常反编译**（见 `docs/known_gaps.md` 与
`tools/patch_excw.py` 的方法说明），只剩 17 个仍用 objdump 兜底块。

本文给出：一次调用约定修正、`cmd_move` 的完整还原、以及四个此前无 C 的
handler 的重写（`cmd_silent`、`cmd_map_entry`、`cmd_serial`、`cmd_key_state`）。

---

## 0. 为什么 153 个函数只有汇编：`excw`

两片固件里散布着 812 处三字节指令，binutils 把它译成 `excw`（exception
wait，无架构副作用），Ghidra 的 Xtensa 模块把它当**控制流终止**，于是函数
体被截断、只剩兜底汇编。

处理办法（`tools/patch_excw.py`）：

1. 用对齐到**函数入口**的反汇编找出这些指令的真实地址（不是线性扫描，
   否则数据区里会出现伪命中）；
2. 把它们替换成 `and aN, aN, aN`（同一寄存器的真 no-op），另存
   `work/*.nop.bin`，官方镜像不动；
3. 用 `tools/esp_to_elf.py` 重建 ELF，Ghidra headless 重新反编译；
4. 结果：LEFT 1440 个函数里 1428 个、RIGHT 1629 个里 1624 个得到真实 C。

**一个必须记住的例外**：当 `excw` 落在**前置校验**里时，把它当 no-op 会让
常量折叠把整个函数体判成不可达（`cmd_silent`、`cmd_channel_toggle` 就是
这样，反编译结果只剩 `return;`）。硬件测试证明函数体确实会执行
（`.km.silent(0,0)` 有回包），所以这两个函数仍保留汇编兜底块，C 重写见
§3、§8。这两个三字节指令在本工具链里没有可用译码，逐位编码扫描
（`tools/sweep_unknown_op.py`，2236 个候选）也没找到对应助记符。

---

## 1. 通用结构（协议处理函数）

从 43 条命令的处理函数归纳，`cmd_*` 基本都是三段式：

```c
void cmd_xxx(buf, len, dev, entry, arg, arglen)
{
    /* ① 前置校验：dev / 内部表指针为空直接返回（多数分支连回执都不发） */
    if (!dev || !dev->tbl) return;          /* 或 uart0_reply(...) 后返回 */

    /* ② 参数解析：',' / ')' 切分，'c' 或十进制 → int16 */
    int n = parse_args(arg, arglen, vals);

    /* ③ 业务调用：按参数个数/取值分流到 mouse/hid 通道写入函数 */
    if (valid) do_something(dev, vals, n);

    /* ④ 回执：uart0_reply(buf, len, 0) —— 回显整行 + ">>> " */
    uart0_reply(buf, len, 0);
}
```

### 调用约定（已修正）

早先文档写成 `a2=ctx, a3=reply_arg, a4=entry, a5=dev`，与调用点不符。
`cmd_dispatch`（`0x4200EF18`）的实际传参是：

```c
handler(buf, len, dev, entry, buf + skip, len - skip);
/*        a2   a3   a4    a5     a6        a7        */
```

依据：`0x4200EF9D`–`0x4200EFA9` 的寄存器准备（`a10=buf, a11=len, a13=entry,
a14=buf+skip, a15=len-skip`，`a12` 因 `excw` 未解出）、以及
`cmd_key_state` 里 `hid_key_state_read(dev)` 与 `entry->len`（`+4`）的用法。
`uart0_reply(a2, a3, 0)` 的回执签名也由此确定：**回显整行命令 + `>>> `**。

---

## 2. 样板一：`cmd_move`（`0x4200E024`，opcode 0x06）：完整还原

```c
/* 解析器：最多 5 个 int16，','/')' 分隔，跳过空格与制表符，接受 +/-，钳位 int16 */
static int parse_move_args(const char *buf, int len, int16_t v[5])
{
    int i = 0, n = 0;
    while (i < len && n < 5) {
        if (buf[i] == ',' || buf[i] == ')') { i++; continue; }
        while (i < len && (buf[i] == ' ' || buf[i] == '\t')) i++;
        int neg = 0;
        if (i < len && (buf[i] == '-' || buf[i] == '+')) { neg = (buf[i] == '-'); i++; }
        int32_t val = 0; int seen = 0;
        while (i < len && buf[i] >= '0' && buf[i] <= '9') {
            val = val * 10 + (buf[i] - '0'); seen = 1; i++;
        }
        if (!seen) break;
        if (val < -32768) val = -32768;
        if (val >  32767) val =  32767;
        v[n++] = (int16_t)(neg ? -val : val);
    }
    return n;
}

void cmd_move(buf, len, dev, entry, arg, arglen)
{
    int16_t v[5] = {0};
    int n = parse_move_args(arg, arglen, v);

    if (n < 2) {                         /* 0x4200E178：少于 2 个值直接静默返回 */
        return;                          /* 注意：连回执都没有 */
    }
    uint32_t mode = 1;
    if (n == 2) {
        mode = 1;
    } else {
        mode = (uint16_t)v[2];           /* 第 3 个值当档位/时间参数 */
        if (n == 5) {
            mouse_submit_ext(dev, v[0], v[1], v[2], v[3], v[4]);  /* 0x4200F744 */
            goto reply;
        }
        if (mode < 2) mode = 1;
    }
    mouse_move(dev, v[0], v[1], mode);   /* 0x42010BC4 */
reply:
    uart0_reply(buf, len, 0);            /* 0x4200E1A4 */
}
```

**与上一版的差异**：旧文档写「3/4 个参数不动作」，实际是**照常移动**，只是
档位取第 3 个值（`<2` 时按 1）。实测 `.km.move(1,2,3)` 会回显——当时的测试
没有观测鼠标是否移动，所以这条一直没被发现。

`uart0_reply(buf, len, 0)` 也解释了实测回包为什么是
`km.move(10,5)\r\n>>> `：`uart0_reply` 把整行原样回显，再补 `>>> `。

---

## 3. 样板二：`cmd_silent`（`0x4200E1B0`，opcode 0x19）

`silent(` 是**「静默移动」**：参数语义与 `cmd_move` 相同，但**参数不足 2 个
时不发回执**，所以 `silent()`、`silent(0)`、`silent(1)` 都是零回应。

```c
void cmd_silent(buf, len, dev, entry, arg, arglen)
{
    if (dev == 0) return;                 /* 0x4200E1BF beqz a4 */

    /* 0x4200E1C4 的三字节指令本工具链无法译码（objdump 显示 excw）。
       硬件实测：2 个参数时走得到回执，所以这里不是"恒返回"。 */

    int16_t v[5] = {0};
    int n = parse_move_args(arg, arglen, v);      /* 与 cmd_move 同一套循环 */

    if (n < 2) return;                    /* 静默：无回显、无提示符 */

    if (n == 2) {
        pulse_move(dev, v[0], v[1]);      /* 0x42010D3C：移动 → 等待 → 反向移动 */
    } else {
        uint32_t mode = (uint16_t)v[2];
        if (n == 5) {
            mouse_submit_ext(dev, v[0], v[1], v[2], v[3], v[4]);
        } else {
            if (mode < 2) mode = 1;
            mouse_move(dev, v[0], v[1], mode);
        }
    }
    uart0_reply(buf, len, 0);             /* 0x4200E352 */
}
```

`pulse_move`（`0x42010D3C`）是本 handler 独有的动作：

```c
void pulse_move(dev, int16_t dx, int16_t dy)
{
    mouse_submit_x(dev,  dx,  dy, 1);      /* 0x4200F770 */
    xSemaphoreTake(sem, portMAX_DELAY);
    vTaskDelay(1);
    mouse_submit_x(dev, -dx, -dy, 0);      /* 回到原位 */
    xSemaphoreTake(sem, portMAX_DELAY);
}
```

实测证据见 `docs/dynamic_tests.md` §8：`silent(0,0)` 回包 `km.silent(0,0)\r\n>>> `，
`silent()` / `silent(0)` / `silent(1)` 零回包。

---

## 4. 样板三：`cmd_map_entry`（`0x4200E624`，opcode 0x16）

这个地址**只有跳表引用**（`0x3C03DF08` 的第 0x16 项），没有 `call8` 调用点，
所以 Ghidra 从未在那里建函数——旧版源码树直接漏掉了它。重写：

```c
/* "<index>,<value>" 形式写映射表项，两个值都必须非零 */
void cmd_map_entry(buf, len, dev, entry, arg, arglen)
{
    if (arglen == 0) return;                       /* 0x4200E627 */
    int32_t first = parse_int_or_char(arg, arglen); /* 0x4200E62E -> 0x4200E458 */

    int i = 0;
    while (i < arglen && arg[i] != ',') i++;        /* 0x4200E639 循环 */
    if (i == 0 || i >= arglen) return;              /* 0x4200E649 */

    int32_t second = parse_int_or_char(arg + i + 1, arglen - 1 - i);  /* 0x4200E655 */
    if (first == 0 || second == 0) return;          /* 0x4200E65A / 0x4200E65C */

    map_entry_write(dev, first, second);            /* 0x4200E662 -> 0x4202D4DC */
    uart0_reply(buf, len, 0);                       /* 0x4200E66B */
}
```

与 opcode 0x15（`cmd_map_16`，`0x4200EA04`）的区别：0x15 的第二个值用
内联数字解析（只取一位十进制），0x16 走完整的 `parse_int_or_char`
（支持 `'c'` 字符形式）。

---

## 5. 样板四：`cmd_serial`（`0x4200DC84`，opcode 0x1A）

同样是**只被跳表引用**的隐藏函数（Ghidra 没建函数）。它是序列号伪装接口：

```c
void cmd_serial(buf, len, dev, entry, arg, arglen)
{
    if (arglen == 0 || (arglen == 1 && arg[0] == ')')) {     /* km.serial() 查询 */
        uint32_t n = 0; byte info[36]; char text[20], line[64];
        if (!serial_read(0, 0, text, 0x15, &n, info)) {      /* 0x42010C84 */
            uart0_reply("Mouse does not have a serial numberber", 0x24, 0);
            return;
        }
        if (info[0] == 0xFF)      snprintf(line, 64, "Mouse does not have a serial numberber");
        else if (info[0] < 2)     snprintf(line, 64, "%s Serial : %s",
                                          info[0] ? "Spoofed" : "Original", text);
        else                      snprintf(line, 64, "Unknown indicator 0x%02X", info[0]);
        uart0_reply(line, strlen(line), 0);
        return;
    }
    if (arglen == 2 && arg[0] == '0' && arg[1] == ')') {     /* km.serial(0) 恢复原厂 */
        ok = serial_read(1, 0, 0, 0, 0, 0);
    } else {                                                 /* km.serial("<串>") 写入 */
        int n = arglen; if (arg[arglen - 1] == ')') n--;
        if (n > 0x14) n = 0x14;
        memcpy(line, arg, n); line[n] = 0;
        ok = serial_read(2, line, 0, 0, 0, 0);
    }
    uart0_reply(ok ? buf : "Mouse does not have a serial numberber", ok ? len : 0x24, 0);
}
```

`serial_read`（`0x42010C84`）三个模式参数：`0` 读、`1` 恢复原厂、`2` 写伪装值。

---

## 6. 样板五：`cmd_key_state`（`0x4200ED74`，opcode 0x11）

Ghidra 本来就能反编译它，但语义此前没写进文档。它按 usage id 查询按键当前
是否按下，并把结果拼成 `"\n<digit>"` 追加到回执里：

```c
void cmd_key_state(buf, len, dev, entry, arg, arglen)
{
    if (arglen == 0) return;

    uint32_t usage;
    if (arg[0] == '\'') {                 /* 'A' 形式 */
        if (arglen < 3 || arg[arglen - 1] != '\'') return;
        usage = char_to_usage(arg[1]);    /* 0x4202D2A0 */
        goto lookup;
    }
    usage = parse_usage_inline(arg, arglen);   /* 空白/+/-/十进制，越界→0 */
    if (usage == 0) return;

lookup:
    if (usage == 0) return;
    char digit = hid_key_state_read(dev, usage);      /* 0x4201100C，返回 0/1 */
    int n = entry->len;                                /* entry +0x04 */
    if (n + 2 < 0x21) {
        memcpy(out, buf, n);                           /* 回显命令名 */
        out[n]     = '\n';
        out[n + 1] = digit + '0';
        uart0_reply(out, n + 2, 0);
    }
}
```

这解释了回包形状 `km.buttons()\n0\r\n>>> `：`\n<状态>` 由 handler 拼好，
`uart0_reply` 负责前面的回显与后面的 `>>> `。

---

## 7. 样板六：`lock_*` 四兄弟（opcode 0x00–0x03）

四个 handler 覆盖「查询 / 设置」×「轴 / 通道」两维：

```c
/* 0x4200DE40  lock_m*()：查询锁定状态 */
void cmd_lock_query(buf, len, dev, entry)
{
    if (!dev) return;
    uint8_t st = lock_status_get(dev, 1, entry->target);   /* 0x4202D1C8 */
    uart0_reply(buf, len, st);                              /* 状态字节进 +2 */
}

/* 0x4200DE60  lock_mx()/lock_my()：查询轴向参数 */
void cmd_lock_axis(buf, len, dev, entry)
{
    if (!dev) return;
    uint8_t v = lock_axis_get(dev, entry->target);          /* 0x4202D240 */
    uart0_reply(buf, len, v);
}

/* 0x4200DECC  lock_m*(：设置开关；'0' 还会连带清 catch */
void cmd_lock_param0(buf, len, dev, entry, arg, arglen)
{
    if (arglen == 0) return;
    char c = arg[0];
    lock_set(dev, entry->target, c == '1');                 /* 0x42010BA8 */
    if (c != '1') {
        catch_set(dev, entry->target, 0);                   /* 0x4202D1AC */
        dirty_flag = 0;
    }
    uart0_reply(buf, len, 0);
}

/* 0x4200DF08  lock_mx( / lock_my(：设置轴向参数 */
void cmd_lock_param2(buf, len, dev, entry, arg, arglen)
{
    if (arglen == 0) return;
    lock_axis_set(dev, entry->target, arg[0] == '1');       /* 0x42010B8C */
    uart0_reply(buf, len, 0);
}
```

新增的命名把这条链补全了：

| 地址 | 名字 | 作用 |
|---|---|---|
| `0x4202D1C8` | `lock_status_get` | 24 位状态：bit0 通道存在、bit8 catch、bit16 lock |
| `0x4202D240` | `lock_axis_get` | `+0x9C`/`+0x9D` 轴锁标志 |
| `0x4202D1AC` | `catch_set` | 写 `+0x168` 抓取槽 |
| `0x4200F9C4` | `channel_slot_set` | 自旋锁内写 `+0x54` 通道槽 |
| `0x4200FA50` | `axis_slot_set` | 自旋锁内写 `+0x9C` 轴槽并唤醒提交任务 |
| `0x42010B8C` / `0x42010BA8` | `lock_axis_set` / `lock_set` | dev 判空包装 |

---

## 8. `cmd_channel_toggle`（`0x4200E56C`，opcode 0x18）：骨架 + 两个已定位的表

原因同 §0 的例外：入口 3 字节未知指令让补丁版反编译把函数体判成不可达。
用**不同对齐起点**重反汇编后，`0x4200E59E` 起的真实代码可以逐条读出，
索引来源已确定（`parse_int_or_char`）：

```c
void cmd_channel_toggle(buf, len, dev, entry, arg, arglen)
{
    if (!dev) { uart0_reply(buf, len, 0); return; }          /* 0x4200E57E-0x4200E597 */
    if (!dev->tbl) { uart0_reply(buf, len, 0); return; }     /* 0x4200E589 l32i a4,0x214 */

    int idx = parse_int_or_char(arg, arglen);                /* 0x4200E59E-0x4200E5A4 */
    if (idx > 0xFF) { uart0_reply(buf, len, 0); return; }    /* 0x4200E5A7-0x4200E5AA */
    if (dev->tbl[idx + 0x369] == 0) {                        /* 0x4200E5B8 l8ui */
        uart0_reply(buf, len, 0);                            /* 0x4200E5BB */
        return;
    }
    const char *comma = memchr(arg, ',', arglen);            /* 0x4200E5C9 loop */
    if (!comma || (comma - arg) == 0 || (comma - arg) >= arglen - 1) {
        uart0_reply(buf, len, 0);
        return;
    }
    char flag = comma[1];                                    /* 0x4200E5E2 */
    dev->tbl[idx + 0x269] = (flag == '1');                   /* 0x4200E5F4 s8i */
    if (flag == '1') *(volatile uint8_t *)0x3FC99FA3 = 0;    /* 0x4200E5FF */
    else             *(volatile uint8_t *)0x3FC99FA3 = 1;    /* 0x4200E611 */
    uart0_reply(buf, len, 0);
}
```

`+0x269` / `+0x369` 这对表与 `cmd_dump_channels`（`0x4200DBB0`，遍历 256 项、同样读
这两处）一致；`0x3FC99FA3` 是"有变更/需要重发"的全局标志。

**对齐陷阱**：`0x4200E59C` 有两个 `00 00` 填充字节，两种反汇编器都会把
`0x4200E59C` 起当成一条 3 字节指令，于是从 `0x4200E59E` 开始整段乱码。
从 `0x4200E59E` 重新起头就恢复正常。遇到函数中段乱码，先试 ±1/±2 重对齐。

---

## 9. 这类函数的阅读顺序

1. 先看末尾：一定有一个 `call8 uart0_reply`，那是统一出口；
2. 再看中间：`call8` 到 `mouse_*` / `hid_*` / `map_entry_write` 的那条，就是业务主干；
3. 剩下的分支基本是参数校验（长度、索引范围、`'0'/'1'` 判断）；
4. 遇到 `l32r aN, 0x... (0xVALUE)`：`VALUE` 是字符串地址就是错误文案，是代码地址就是回调。
