# MagicBox 固件工程

MAKCU 鼠标盒子（双 ESP32-S3：左片 V3.2 设备侧 / 右片 V3.7 主机侧）的自编固件工程——可编译、可刷写、可回滚。
2026-11-12 起仓库只保留这一套工程：早期固件逆向（反编译树、Ghidra 工程、逆向工具链、原厂协议文档）已整体清理。

## 目录

```
app_left/           左片 ESP32-S3（USB device）：控制口、协议分发、HID 上报、克隆
app_right/          右片 ESP32-S3（USB host）：枚举鼠标、0xA2 上报转发、EP0 隧道
components/         makcu_{proto,link,clone,hiddev,hidhost,keyboard,board,dev,right,sumv}
mouse/              ★ 厂商通道（HECATE / G3M PRO）：mouse_vendor 分发 + g3mpro 协议 + vendor_chan 通道
docs/               HANDOVER（接手必读）/ 50-vendor-channel / 40-status / API-control-port / 00-facts / 30-decisions
tools/              构建、刷写、台架与验证脚本
verification/       回归用例（regress/）、上机报告（report/）、方案记录（plan-*.md）
官方固件/           两个原厂镜像 V3.2_LEFT.bin、V3.7_RIGHT.bin（回滚用，勿删）
work/               运行目录：出厂备份镜像 + reflash 回读比对脚本
```

## 构建

```powershell
# 左片（台架构建，带 mx.* 调试命令）
powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"
# 右片（USB host 侧）
powershell -File tools\build_app.ps1 -App app_right
```

依赖都在仓库外：`D:\esp-idf`（v5.4.1）、`D:\esp-tools`（xtensa-esp-elf 14.2.0 + python_env）。

## 刷写 / 回滚

```powershell
# 左片全自动：构建 → mx.dl 进下载器 → 写 0x10000 → 整段回读比对 → 提示（不用拔线）
powershell -File tools\flash_left_auto.ps1
powershell -File tools\flash_left_auto.ps1 -NoBuild      # 直接刷现有 build 产物
# 左片（COM3，内部走 mx.dl 进下载模式，顺便抓日志）
powershell -File tools\flash_capture.ps1 -Port COM3 -Seconds 6
# 右片：右侧口换数据线（VID_303A&PID_1001 / COM10），app 镜像写 0x10000
powershell -File tools\flash_right.ps1 -Image app_right\build\makcu_right.bin -Offset 0x10000
# 右片回滚出厂
powershell -File tools\flash_right.ps1
# 左片回滚 + 回读比对
powershell -File tools\reflash.ps1 -Port COM3
```

> 刷完左片若它停在 ROM 下载器，可用 `esptool --port COM4 --before no-reset --after hard-reset read-mac` 直接启动（本板实测有效，不需要拔线）。

**出厂备份（不要删）**：`work/hw_left_before_rebuild.bin`、`work/hw_right_full_before_patch.bin`、`work/right_boot_head.bin`。

## 状态

| 项 | 现状 |
|---|---|
| 命令协议层 | 27/27 handler 全部 implemented，`components/makcu_proto/handlers.def` |
| 双 app 工程 | `idf.py build` 双端通过（`tools/build_app.ps1`）：左片台架 **355,040 B** / 发布版 **337,664 B**，右片 **292,624 B** |
| 片间链路 | UART1 帧层 + `0xA0` 会话状态机 + `0xA2` 上报透传，真机单板验证 |
| 克隆 / 身份 | 描述符克隆 + 身份别名策略 + 每台唯一序列号；EP0 数据注入与序列号读写仍待做 |
| 厂商通道 | HECATE 识别/读写正常快速：`mx.ox` 的 `out==vin==vf`、`ofail=0`、队列丢弃 0、`vp50 ≈ 31–39 ms`（见 [docs/50-vendor-channel.md](docs/50-vendor-channel.md)）；按键事件订阅 × 物理点击并发实测零丢失（≤1000 边沿/秒），事件通知延迟 **~0.12 ms**（见 D48） |
| 回归 | 真机 **128 passed / 0 failed**（≈4 min，需台架 COM3）+ 离线模型 **46 passed**，合计 174 例（刷机后先 `mx.ac` 重克隆再跑，否则 9 skipped）；无硬件用 `MAKCU_SKIP_HW=1` 只收集 |
| 已知限制 | 按鼠标**硬件 DPI 键**，HECATE 显示不刷新（接收器不推送该变化；三条修法已试并撤回，按需求不做） |

细节与踩坑：[docs/HANDOVER.md](docs/HANDOVER.md)；状态与待办：[docs/40-status.md](docs/40-status.md)；
协议面：[docs/API-control-port.md](docs/API-control-port.md)。

## 工具

- **构建/刷写**：`build_app.ps1`、`flash_capture.ps1`、`flash_right.ps1`、`reflash.ps1`、`rd_right.ps1`、`recover_download.py`
- **台架**：`boxbench_gui.py`（桌面 GUI，`--selftest` 无界面自检）、`link_probe.py`（控制口 921600 二进制通道）、`aim_move.py`、`aim_stress.py`、`px_cal.py`、`dt_hist.py`、`watch_*.ps1`
- **分析**：`diff_insn.py`（指令相似度）、`p0_baseline.py`（P0 基线，只读官方镜像）、`trace_opcodes.py`、`trace_motion.py`、`extract_tables.py`
- **文档**：`status.py` 生成 `docs/40-status.md`

## 验证

```powershell
$env:MAKCU_SKIP_HW='1'; python -m pytest verification\regress -q --collect-only   # 无硬件
$env:MAKCU_PORT='COM3'; python -m pytest verification\regress -q                  # 台架
```

## 边界

- 不重写 ESP-IDF / newlib / tinyusb，直接链接官方库；
- 未实测的行为不实现（13 个隐藏 opcode 只做已证实的部分）；
- 不做 OTA / secure boot（原厂分区表无 OTA，eFuse 全只读）；
- `MB_FORCE_VIDPID` 已废弃，身份靠别名策略。
