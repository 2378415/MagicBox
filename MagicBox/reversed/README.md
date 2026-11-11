# MAKCU 固件逆向工程源码树

由两片官方固件（`V3.2_LEFT.bin` / `V3.7_RIGHT.bin`）经 **Ghidra headless 反编译**自动重建的可读源码树。

> 这不是原始源码，而是**反编译产物**：函数体是 Ghidra 输出的 C 伪代码，变量名多为 `param_1/uVar1`，类型是 `undefined4` 一类宽度推断类型。用途是阅读、比对与移植参考，**不能直接编译**。分析结论见 `../官方固件逆向分析报告.md`、`../官方固件命令协议.md`、`../官方固件未公开协议.md`。

---

## 1. 结构

```
reversed/
├── README.md                  ← 本文件
├── CMakeLists.txt             ← 导航脚手架（列举源码，不产生固件）
├── include/
│   ├── re_types.h             ← undefined/undefined1..8、longlong、bool 等类型桩
│   └── re_<image>_<module>.h  ← 26 个模块头（原型 + DAT_/PTR_ extern）
├── manual/                    ← 手工重建（Ghidra 建不出函数的跳表入口）
│   └── left/protocol/         ← cmd_map_entry(0x16)、cmd_serial(0x1A)
├── src/
│   ├── left/                  ← V3.2_LEFT（设备侧：命令协议、HID 设备、鼠标提交）
│   │   ├── protocol/    35    ← 命令表、分发器、13 个隐藏 opcode 处理函数
│   │   ├── mouse/       18    ← MouseCommitTask、Bezier 平滑、提交队列
│   │   ├── keyboard/    11    ← HID usage 写入/清除/点按/组合键
│   │   ├── hid/          4    ← 描述符解析、序列号伪装
│   │   ├── uart/        16    ← UART0 初始化、帧消费、回执
│   │   ├── led/ efuse/ crash/
│   │   └── idf_*/             ← ESP-IDF 组件（freertos 686、esp_system 253、uart 85…）
│   └── right/                 ← V3.7_RIGHT（主机侧：USB Host、HID 解析、UART 转发）
│       ├── hid/ usb/ uart/ led/
│       └── idf_*/
└── docs/
    ├── reading_paths.md       ← 五条主线阅读路径（先读这个）
    ├── function_index.md      ← 3071 个函数全量索引
    ├── module_map.md          ← 模块 × 函数数
    ├── renames.md             ← 121 个语义命名及其依据
    ├── call_graph.md          ← 最常被调用函数 + 跨模块调用矩阵
    ├── reconstruction_patterns.md ← 9 个 C 级重写样板
    ├── uart1_link.md          ← 片间 UART1 帧格式 + 长度口径清算
    ├── open_questions.md      ← 未闭合问题清单（6 项，4 项已闭合）
    ├── known_gaps.md          ← 17 个反编译缺口 + 已补的 objdump 块
    ├── headers.md             ← 头文件说明 + -fsyntax-only 结果
    ├── dynamic_tests.md       ← 真机测试记录
    └── next_steps.md          ← 进度快照 + 复现命令
```

命名规则：`src/<image>/<module>/<entry>_<name>.c`，`entry` 是镜像内虚拟地址（如 `4200e024`）。

---

## 2. 规模

| 指标 | 值 |
|---|---|
| 函数总数 | **3071**（LEFT 1440 / RIGHT 1629，含 2 个手工重建的跳表入口） |
| C 文件 | 3071 + 模块 `_README.md` |
| 代码行 | 约 10.8 万行 |
| 反编译失败需兜底汇编 | **17 / 3071**（上一轮是 153） |
| 解锁方式 | `tools/patch_excw.py` 把 812 处 `excw` 换成同寄存器 no-op 后重反编译 |
| 模块头文件 | 26 + `re_types.h`，全部通过 `-fsyntax-only` |
| 未归类函数 | 0 |
| 语义命名 | **121** 个（`cmd_*` 34、`mouse_*`/`hid_*`/`uart*` 若干、软浮点与计时辅助 以及 libm/libgcc 的 `__kernel_cos`/`__kernel_sin`/`__ieee754_rem_pio2`/`__ieee754_sin`/`__ieee754_cos`/`__ieee754_floor`/`__ieee754_scalbn`/`__fixdfsi`），见 `docs/renames.md` |
| 已命名函数（含 IDF 自带符号串） | 537 |

---

## 3. 怎么读

1. 先读 `docs/reading_paths.md`：五条主线（命令链路、鼠标提交、HID、隐藏键盘 API、eFuse）。
2. 想看模块规模：`docs/module_map.md`；想按名字找函数：`docs/function_index.md`。
3. 追一条命令：`src/left/protocol/4200eec4_cmd_lookup.c`（查表）→ `4200ef18_cmd_dispatch.c`（opcode 跳表）→ handler。
4. 想看「一个 handler 到底怎么写」：`docs/reconstruction_patterns.md` 有 9 个手写样板（`cmd_move`、`cmd_silent`、`cmd_map_entry`、`cmd_serial`、`cmd_key_state`、`lock_*` 等）。
5. 遇到 `halt_baddata()`：同一文件末尾有 `objdump fallback` 块，带 `L_xxxxxxxx:` 基本块标签、调用目标符号名与字符串常量注释；窗口已在 `ill` 填充或下一个 `entry` 处截断，不会越到下一个函数。
6. 头文件在 `include/`，每个模块一份原型表，可直接对照调用点。

**命名约定**

- `FUN_4200xxxx`：未命名函数，地址即身份；
- `PTR_s_left___42000db8`：指向字符串的指针字面量；
- `DAT_42000c68`：全局数据/函数指针槽；
- `param_N`：按 Xtensa 调用约定推断的参数（a2 起）。文本命令 handler 的真实
  签名是 `(buf, len, dev, entry, arg, arglen)`（见 `reconstruction_patterns.md` §1）。

---

## 4. 已知偏差

| 现象 | 原因 | 处理 |
|---|---|---|
| 17 个函数只有汇编 | Ghidra 仍报 pcode 错误，或 `excw` 落在前置校验导致误折叠 | 补 objdump 兜底块，清单在 `raw_*/_gaps.txt` |
| `undefined4` / `uVar1` | 反编译无类型信息 | 结合调用点判断，或回 Ghidra 工程改类型 |
| 模块归属 | 种子 + 标签传播 + 地址邻近的启发式 | 跨模块调用（protocol→mouse）属正常 |
| 无 `#include` 依赖 | 反编译不产出头文件关系 | 文件可读、不可编译 |
| 参数个数可能不准 | Ghidra 参数恢复基于调用点 | 以函数体实际使用为准 |
| `manual/` 下 2 个文件 | Ghidra 没有对应函数 | 手写 C + 反汇编依据，随 `build_project.py` 并入 |

---

## 5. 重建流程（可复现）

```powershell
# 1) 反编译全部函数 + 导出调用图（每片约 20 秒）
analyzeHeadless <proj> makcu -process V3.2_LEFT_app.elf -noanalysis `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java reversed\raw_left
analyzeHeadless <proj> makcu -process V3.7_RIGHT_app.elf -noanalysis `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java reversed\raw_right

# 2) 聚类 + 生成源码树 + 头文件 + 文档
python tools\build_project.py

# 3) 给剩下的 17 个函数补 objdump 反汇编
python tools\fill_gaps.py

# 4) 命名文档
python tools\make_renames_doc.py
```

### 5.1 让 136 个函数从“只有汇编”变成“可读 C”

```powershell
python tools\patch_excw.py both              # 生成 work/*.nop.bin（官方镜像不动）
python tools\esp_to_elf.py work\V3.2_LEFT.nop.bin  work\V3.2_LEFT.nop.elf
python tools\esp_to_elf.py work\V3.7_RIGHT.nop.bin work\V3.7_RIGHT.nop.elf
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.2_LEFT.nop.elf `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_left
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.7_RIGHT.nop.elf `
  -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_right
python tools\merge_patched.py                # 合并回 raw_*/，写 _gaps.txt
python tools\build_project.py; python tools\fill_gaps.py
```

`merge_patched.py` 会拒绝两类结果：仍然 `decompile failed` 的函数，以及
「只剩 `return;` + 大量 unreachable」的守卫折叠（`cmd_silent`、
`cmd_channel_toggle`），后者保留汇编兜底。

原始数据保留在 `reversed/raw_left`、`reversed/raw_right`（每函数一个 `.c` + `_index.csv` + `_edges.csv` + `_gaps.txt`），可重跑或换聚类算法。


