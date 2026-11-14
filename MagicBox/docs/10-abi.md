# 10-abi：调用约定与协议边界（重建时最容易错的地方）

## 1. 帧进入 device 之前

```
UART0 (115200 8N1)
  └─ frame_router(0x4200DB04)      首字节分流
       '.'(0x2E)  → cmd_dispatch(0x4200EF18)
       0xA1 ack / 0xA2 ignore / 0xA4 config / 0xA5 serial
       其它       → frame_echo_hex（"%02X " 回显）
```

文本帧格式：`.` + `km.` + 命令 + `(`…`)` + `\r`。
**实测**：`.km.version()`、`.km.version` 都生效 → 命令表是**前缀匹配**。

## 2. 交给 handler 的字符串

`cmd_dispatch` 先用 `cmd_lookup` 命中表项并返回 `skip = entry->len`，然后用
`handler(buf, len, dev, entry, buf + skip, len - skip)` 调处理函数，其中 `buf`
**已去掉前导 `km.`**（否则 `uart0_reply` 会重复前缀）。三条证据：

1. `uart0_reply` 自身拼 `"km." + 内容 + "\r\n>>> "`；
2. `.km.move(10,5)` 的回包是 `km.move(10,5)\r\n>>> `，没有出现 `km.km.`；
3. `cmd_key_state` 用 `entry->name`（= `buttons()`，不含 `km.`）拼状态再回执，
   实测回包 `km.buttons()\n0\r\n>>> ` 与之一致。

## 3. handler 签名（窗口化 ABI）

```
a2 = buf     指向（已去前缀的）命令文本
a3 = len     buf 长度
a4 = dev     设备上下文（判空后多数 handler 直接静默返回）
a5 = entry   命中的命令表项指针（entry->len 在 +0x04）
a6 = arg     buf + entry->len（参数起点）
a7 = arglen  len - entry->len
```

跳表调用是 `callx8`，因此参数**不经过 C 原型检查**：重建时必须统一签名，否则
T3 的调用序列对不上。返回类型统一 `void`（原 handler 均无返回值使用）。

## 4. 回执

| 形式 | 输出 |
|---|---|
| `uart0_reply(content, len, 0)` | `"km." + content + "\r\n>>> "`，长度上限 0x259（601）字节 |
| 带状态字节的查询 | handler 先拼 `"<name>\n<digit>"` 再交给 `uart0_reply` |
| 未知命令 | 不输出任何字节 |
| 参数不足 | 多数不输出（例：`silent()`、`silent(0)`、`silent(1)`） |

## 5. 片间 UART1（RIGHT↔LEFT）

```
5A <cmd> <len:u16 LE> <payload[len]>
总线上长度 = len + 4；len = 0 也是合法帧（纯头）
```

- 命令：`0xA0` EP0 隧道（len=1，方向字节）、`0xA1`、`0xA2` HID 上报（payload = `ep,id,len,0,data…`，故 len 字段 = 4+数据长）、`0xA3`、`0x1A` 快照、`0xA4` 配置、`0xB1` 无处理。
- 方向不对称：`0xA2` 只右→左；右片的 `frame_forward` 没有 `0xA2` 分支是设计使然。

## 6. 重建时的硬约束

1. handler 6 参顺序不可改；>6 参的函数（`mouse_submit_ext` 等）按 Xtensa 栈传参写；
2. 回执必须走同一个封装函数，不要在 handler 里直接 `printf`；
3. 参数解析要沿用原语义：`,`/`)` 分隔、跳过 `0x20`/`0x09`、接受 `+`/`-`、结果钳到 int16；
4. `silent(`/`move(` 的 `<2` 参数分支是「静默返回」，不能顺手加回执。
