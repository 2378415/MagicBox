# Decompilation gaps and their disassembly fallback

Two causes remain after the `excw` workaround (see `patch_excw.py` in the
repository root tooling): Ghidra still reports a pcode/construct error on
these function bodies, or the body decompiles into a guard fold that the
hardware disproves (`excw` is not a no-op when it sits in a guard). Each
affected file ends with an `objdump fallback` block produced by
disassembling from the exact function entry, cut at `ill` padding or at the
next `entry` prologue so it never swallows the next function.

Tried and rejected: replacing the zero alignment padding in front of each
failing address with an equal-length no-op (`tools/patch_padding.py`) leaves
the failure count unchanged — the remaining errors are missing instruction
constructors in the Xtensa module, not alignment drift.

Filled: 17  |  still missing: 0

| image | module | entry | instructions |
|---|---|---|---:|
| left | idf_esp_system | `0x40378870` | 153 |
| left | idf_esp_system | `0x42018ab8` | 161 |
| left | idf_freertos | `0x40375ee8` | 188 |
| left | idf_freertos | `0x42003048` | 72 |
| left | idf_freertos | `0x420106bc` | 298 |
| left | idf_freertos | `0x4201add4` | 107 |
| left | idf_freertos | `0x42020c30` | 199 |
| left | idf_freertos | `0x42023c70` | 199 |
| left | idf_freertos | `0x42026e28` | 199 |
| left | idf_freertos | `0x4202ab58` | 199 |
| left | protocol | `0x4200e1b0` | 169 |
| left | protocol | `0x4200e56c` | 69 |
| right | idf_esp_system | `0x40377f28` | 101 |
| right | idf_freertos | `0x420181c0` | 199 |
| right | idf_freertos | `0x4201b200` | 199 |
| right | idf_freertos | `0x4202206c` | 199 |
| right | idf_heap | `0x4201e3b8` | 199 |
