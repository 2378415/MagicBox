# MagicBox

MAKCU 鼠标盒（双 ESP32-S3：左片 V3.2 设备侧 / 右片 V3.7 主机侧）的**固件逆向与分析**工作区。
本仓库不含产品源码，全部内容来自官方镜像的静态反编译 + 真机测试。

## 交付物

| 文件 | 内容 |
|---|---|
| [官方固件命令协议.md](<官方固件命令协议.md>) | 43 条文本命令表、opcode 跳表、`move(`/`wheel(`/`silent(`/`serial(`/`map_entry` 的完整语义、二进制帧路由 |
| [官方固件未公开协议.md](<官方固件未公开协议.md>) | 13 个无文本入口的隐藏 opcode handler（键盘注入、映射、通道表）及其可达性结论 |
| [官方固件逆向分析报告.md](<官方固件逆向分析报告.md>) | 总报告：固件结构、模块划分、7 轮分析迭代与结论 |
| [reversed/README.md](reversed/README.md) | 反编译源码树说明（3071 个函数、17 个兜底汇编、119 个命名） |
| [reversed/docs/reading_paths.md](reversed/docs/reading_paths.md) | 五条主线阅读路径 |
| [reversed/docs/reconstruction_patterns.md](reversed/docs/reconstruction_patterns.md) | 9 个 C 级重写样板（含调用约定修正） |
| [reversed/docs/uart1_link.md](reversed/docs/uart1_link.md) | 片间 UART1 帧格式与长度口径清算 |
| [reversed/docs/open_questions.md](reversed/docs/open_questions.md) | 未闭合问题（6 项中 4 项已闭合） |
| [reversed/docs/dynamic_tests.md](reversed/docs/dynamic_tests.md) | 真机测试记录（含 `silent(x,y)` 回执验证） |
| [reversed/docs/next_steps.md](reversed/docs/next_steps.md) | 进度快照 + 一键复现命令 |

## 目录

```
官方固件/          V3.2_LEFT.bin、V3.7_RIGHT.bin、串口烧录工具
reversed/          Ghidra 反编译产物：src/ 源码树、include/ 头、docs/ 文档、manual/ 手工重建
work/              中间产物：镜像切段、ELF、反编译 dump、补丁镜像（可删）
tools/             Ghidra 脚本与 Python 工具链（反编译/补丁/校验/命名/发命令）
ghidra-projects/   Ghidra 工程
backups/           历史备份
```

## 关键工具

| 工具 | 用途 |
|---|---|
| `tools/patch_excw.py` | 把 812 处 `excw` 换成同寄存器 no-op，另存镜像，让 136 个函数可反编译 |
| `tools/merge_patched.py` | 补丁版 dump 合并回规范 dump，写 `_gaps.txt`，拒绝误折叠的守卫函数 |
| `tools/build_project.py` | 聚类 + 生成源码树/头文件/索引文档 |
| `tools/fill_gaps.py` | 给剩余 17 个函数生成对齐反汇编兜底块（窗口在 `ill`/下一个 `entry` 处截断） |
| `tools/verify_excw.py` / `find_excw.py` / `sweep_unknown_op.py` | 校验补丁只动 `excw`、统计分布、扫描未译码指令 |
| `tools/ghidra_scripts/MakeFuncs.java` | 给跳表专用入口补建函数并导出 C |
| `tools/flash/send_cmd.py` | 通过 CH343 控制口发命令（自动 DTR/RTS 复位） |

## 快速复现

```powershell
python tools\patch_excw.py both
python tools\esp_to_elf.py work\V3.2_LEFT.nop.bin  work\V3.2_LEFT.nop.elf
python tools\esp_to_elf.py work\V3.7_RIGHT.nop.bin work\V3.7_RIGHT.nop.elf
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.2_LEFT.nop.elf  -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_left
analyzeHeadless work\ghidra-nop makcu_nop -import work\V3.7_RIGHT.nop.elf -scriptPath tools\ghidra_scripts -postScript DumpAll.java work\raw_nop_right
python tools\merge_patched.py
python tools\build_project.py
python tools\fill_gaps.py
python tools\make_renames_doc.py
```

## 状态

- 函数：3071（LEFT 1440 / RIGHT 1629 + 2 个手工重建的跳表入口）
- 仍需汇编兜底：17（上一轮 153）
- 语义命名：119
- 头文件：26 个模块头全部通过 `-fsyntax-only`
- 已闭合问题：`cmd_silent` 语义、UART1 长度口径、0xA2 分派缺口、隐藏 opcode 可达性、隐藏 handler 找回
