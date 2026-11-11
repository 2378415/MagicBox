# 纯软件待办（当前进度快照）

**软件部分已收尾**：本轮把 `excw` 阻塞的 153 个函数压到 17 个，补齐了 4 个
handler 的 C 重写、UART1 长度口径、以及 26 个 vendor 函数命名。
下面按「已完成」「仍开放」分开列，接手时先看第 2 节。

## 1. 本轮完成（2026-11-09，软件目标第 7 轮）

| 项 | 结果 | 产物 |
|---|---|---|
| `excw` 阻塞 153 函数 | 136 个恢复真实 C（LEFT 1428/1440、RIGHT 1624/1629） | `tools/patch_excw.py`、`tools/merge_patched.py` |
| 兜底块窗口越过函数尾 | 已修：在 `ill` 填充或下一个 `entry` 处截断（`0x4200E56C` 不再吞掉 `0x4200E624`） | `tools/fill_gaps.py` |
| 跳表专用隐藏函数 | 找回 2 个：`cmd_map_entry`（0x16）、`cmd_serial`（0x1A） | `reversed/manual/`、`tools/ghidra_scripts/MakeFuncs.java` |
| C 级重写 | `cmd_silent`、`cmd_map_entry`、`cmd_serial`、`cmd_key_state`；`cmd_move` 修正 3/4 参行为 | `docs/reconstruction_patterns.md` |
| UART1 长度口径 | 闭合：`+2` = 头后字节数，总长 = 字段 + 4 | `docs/uart1_link.md` §8/§9 |
| vendor 函数命名 | +45 → 共 119 个（含 26 个通道/软浮点辅助） | `docs/renames.md` |
| 动态验证 | `.km.silent(x,y)` 有回包、`silent()`/`silent(1)` 无回包 → 证明函数体可达；`.km.serial()` 回失败文案 → 跳表专用 handler 存在 | `docs/dynamic_tests.md` §10/§11 |
| 头文件语法抽查 | 26 个头文件按 `-fsyntax-only` 语义检查，仅剩反编译产物固有的类型歧义 | `docs/headers.md` §3 |

## 2. 仍开放（都不阻塞软件交付）

1. **`excw` 的真身**：厂商 LX7 指令，binutils/Ghidra 都译不出。只影响
   `cmd_silent`、`cmd_channel_toggle` 两个函数的逐指令精度（语义已由硬件实测与
   汇编骨架确定）。
2. **自定义 USB host 驱动的事件码枚举**：`usb_event_handler` 的分支结构已完整
   （正数=长度、-10=断连），只差把常量对到该驱动头文件。
3. **`usb_event_handler` 之外的 13 个 pcode 错误函数**：全部是 IDF 内部
   （freertos/heap 红黑树、分区表），阻塞点是 Ghidra 缺指令构造器；已试过
   填充补丁，失败数不变（报告 §14.4），决定不追。

## 2.1 A 组待办执行结果（2026-11-09 第二轮）

| 项 | 结果 | 产物 |
|---|---|---|
| A1 软浮点例程精确命名 | **完成**：靠 fdlibm 系数**位级比对**定为 `__kernel_cos` / `__kernel_sin` / `__ieee754_rem_pio2` / `__kernel_rem_pio2` / `__ieee754_cos` / `__ieee754_sin` / `__ieee754_floor` / `__ieee754_scalbn` / `__fixdfsi` | `tools/dump_consts.py`、报告 §14.1、`renames.md`（121 个命名） |
| A2 `usb_event_handler` 分派 | **结构闭合**：`param_2>=1` = 传输完成（长度=字节数，填 0xA2 后重挂）；`-10` = 断连（重建描述符 + `usb_xfer_submit`）；端点 `&0xf`/`&8`=IN、环形缓冲 `(i+1)&7`；事件码枚举仍待头文件 | 报告 §14.2 |
| A3 `cmd_channel_toggle` 索引 | **闭合**：`idx = parse_int_or_char(arg, arglen)`，0..255，`+0x369` 存在位、`+0x269` 启用位；顺带查明入口乱码来自 **2 字节零填充**导致的对齐漂移 | `reconstruction_patterns.md` §8、报告 §14.3 |
| A4 13 个 pcode 错误函数 | **负结果入档**：填充换 no-op 无效，阻塞点是 Ghidra 缺构造器；不造补丁 | `tools/patch_padding.py`、`known_gaps.md` |
| A5 源码树可编译化 | **不做**（重建整套 IDF 头文件工作量大且不产新结论）；只保证 26 个模块头 `-fsyntax-only` 通过 | 报告 §14.5、`headers.md` |

## 3. 复现命令

```powershell
# 1) 让 153 个函数可反编译：把 excw 换成同寄存器 no-op，另存镜像
python tools\patch_excw.py both
python tools\esp_to_elf.py work\V3.2_LEFT.nop.bin  work\V3.2_LEFT.nop.elf
python tools\esp_to_elf.py work\V3.7_RIGHT.nop.bin work\V3.7_RIGHT.nop.elf

# 2) 重新反编译（两个镜像各约 20 s）
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.2_LEFT.nop.elf `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_left
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.7_RIGHT.nop.elf `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_right

# 3) 合并回规范 dump（自动保留 17 个不可用函数 + 写 _gaps.txt）
python tools\merge_patched.py

# 4) 重建源码树、补兜底块、生成命名与索引文档
python tools\build_project.py
python tools\fill_gaps.py
python tools\make_renames_doc.py

# 5) 动态验证（CH343 控制口，115200）
python tools\flash\send_cmd.py ".km.version()" ".km.silent(0,0)" ".km.silent(1)"
```

## 4. 交接提示

- 官方镜像 `官方固件/*.bin` 未改动；补丁镜像只在 `work/*.nop.bin`。
- `reversed/raw_*/_gaps.txt` 是「仍需兜底块」的唯一清单，`fill_gaps.py` 只认它。
- 想回到完全未打补丁的版本：`git checkout -- reversed/` 后重跑
  `build_project.py` + `fill_gaps.py`（兜底块会回到 153 个）。
