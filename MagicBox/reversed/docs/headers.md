# Headers

`include/re_types.h` provides the width-ambiguous type stubs used by the
decompiler output (`undefined1/2/4/8`, `undefined`, `longlong`, `byte`,
`ushort`, `uint`, `code`, plus `<stdbool.h>` for the `bool` returns Ghidra
produces).

`include/re_<image>_<module>.h` holds one prototype per function in that
module plus `extern undefined4` declarations for the `DAT_`/`PTR_` globals
the module touches. They are generated from the decompiled bodies, so a
prototype is only as accurate as Ghidra's parameter recovery.

## 1. 生成方式

`tools/build_project.py::make_headers()` 按模块聚合函数入口与名字，再从
`reversed/raw_<side>/<entry>_<name>.c` 里还原原型。反编译产物不是声明，
所以做了三件事：

1. 返回类型可能单独占一行（`undefined4` + 换行 + `FUN_xxx(...)`），取上一行；
2. 参数表可能跨行，按括号配对后压成一行；
3. 若只找到调用点或解析不完整，退化为 `void name(void);`。

## 2. 语法检查（2026-11-09）

用官方工具链真编译头文件（不链接、不看语义，只看声明是否自洽）：

```powershell
$gcc = 'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp32s3-elf-gcc.exe'
foreach ($h in Get-ChildItem reversed\include\*.h) {
    & $gcc -fsyntax-only -std=c99 -I reversed\include -xc $h.FullName
}
```

| 轮次 | 失败头文件 | 原因 |
|---|---:|---|
| 首次 | 16 / 27 | `bool` 未定义、`undefined`/`longlong` 缺 typedef、返回类型独占一行被漏掉 |
| 补 typedef | 11 / 27 | 只剩“返回类型在上一行”这一类 |
| 修原型解析 | **0 / 27** | — |

结论：26 个模块头 + `re_types.h` 全部通过 `-fsyntax-only`。这**不等于**
源码树可编译：`src/*.c` 是反编译输出，没有原始头文件依赖、类型与链接信息。

## 3. 参数可信度

| 现象 | 影响 | 依据 |
|---|---|---|
| 参数个数可能偏少 | 有些原型只列出被用到的前几个参数 | Ghidra 按调用点恢复 |
| 返回类型宽度不确定 | `undefined4` 可能实际是 `int`/指针 | 宽度推断 |
| 同一函数在不同调用点签名不同 | 跳表调用（`callx8`）绕过原型检查 | `cmd_*` handler 走跳表 |
| 手工重建的 2 个函数 | 原型由反汇编手写，比生成版更可靠 | `reversed/manual/` |
