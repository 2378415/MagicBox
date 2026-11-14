# verification：三层验证

| 层 | 工具 | 现在能跑吗 | 说明 |
|---|---|---|---|
| T1 编译 | `idf.py build`（`tools/setup_idf.ps1`） | 需要 IDF | 两个 app 各编一次 |
| T1' 语法 | `xtensa-esp32s3-elf-gcc -fsyntax-only` | **能** | 组件源码全部通过（见 `docs/40-status.md`） || T2 协议 | `pytest verification/regress` | 需要真机（COM8） | 无硬件时 `MAKCU_SKIP_HW=1` 只收集 |
| T3 相似度 | `tools/diff_insn.py`（逐函数） | **能** | 原始侧自比 1.000；`cmd_move` vs `cmd_wheel` = 0.364 |
| P0 基线 | `tools/p0_baseline.py` | **能** | 只读 `官方固件/V3.2_LEFT.bin`；`lib_fingerprint.py` 依赖旧反编译树，已于 2026-11-12 删除 |

> 2026-11-12：旧仓库（`reversed/`、`work/`、Ghidra 工程、逆向工具链）已整体清理。本文里凡引用
> `reversed/docs/*.md`、`dynamic_tests.md`、`lib_fingerprint.py` 的地方均属历史溯源，不影响当前可跑的用例与命令。

## 目录

```
verification/
├── fingerprints/          # 函数指纹（历史遗留，生成工具 lib_fingerprint.py 已随旧仓库于 2026-11-12 删除）
│   ├── left.json
│   └── right.json
└── regress/               # pytest 夹具 + 协议用例
    ├── conftest.py        # 串口连接、DTR/RTS 复位、回包收集
    └── test_protocol.py   # 用例全部来自 dynamic_tests.md 的实测
```

## 用法

```powershell
# 1) 单个函数的相似度（T3）
python tools\diff_insn.py --image-a "D:\JinPeng\MagicBox\官方固件\V3.2_LEFT.bin" `
    --a 0x4200e024 --size-a 0x80 --b 0x4200e024 --size-b 0x80 --verbose

# 2) P0 基线（只读官方镜像）
python tools\p0_baseline.py

# 3) 协议回归（真机）
python -m pytest verification\regress -q

# 4) 协议回归（无硬件，仅检查用例/夹具可用）
$env:MAKCU_SKIP_HW='1'; python -m pytest verification\regress -q --collect-only
```

## 用例来源

`dynamic_tests.md` 里每条实测都对应一个断言：

| 实测 | 用例 |
|---|---|
| `.km.version()` → `km.MAKCU\r\n>>> ` | `test_echo_replies[version]` |
| `.km.version`（无括号）也生效 | `test_echo_replies[version-nobracket]` |
| `.km.silent()` / `(0)` / `(1)` 零回包 | `test_no_reply` |
| `.km.silent(0,0)` 有回包 | `test_echo_replies[silent-2args]` |
| `.km.serial()` → `km.Mouse does not have a serial number…` | `test_serial_query` |
| `.km.foobar()` 零回应 | `test_no_reply[foobar]` |
| 单字节帧被丢 | `test_hidden_opcode_not_reachable`（xfail，属推断） |

## 怎么跑

```powershell
# 离线模型（无需硬件，秒级）
python -m pytest verification/model -q          # 46 passed

# 真机回归（需要盒子 + 中线 COM3）
$env:MAKCU_PORT='COM3'; python -m pytest verification/regress -q   # 128 passed，约 4 min
```

**光标约束（2026-11-12）**：`verification/regress/conftest.py` 里有一个 session 级 `CursorGuard`
守护线程（20 ms 周期）+ 两个 autouse fixture：整个测试会话期间，主机光标被钳在
**屏幕右上角 240×140 的安全区**（距上/右边各 24 px）内，每个用例前后各归位一次。
原因：`test_mouse_reports` 会注入 `±30000 counts`（≈259 条报告）、`test_button_sumv_concurrency`
会连续点 700 次，没有守护时光标会满屏飞。守护**只动主机光标**，不碰设备侧计数，
所以 `mx.rt` / `mx.rq` / `wire_chg` 这类断言不受影响。

## 报告

每次跑完把 `pytest -q` 输出与 `diff_insn` 的分数写进 `docs/40-status.md`
（由 `tools/status.py` 汇总产物；分数表可后续并入脚本）。
