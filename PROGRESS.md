# 进度文档 — v0.5.0（2026-11-18）

> 本文件记录跨 `MagicBox/`（固件）与 `MagicBullet/`（App）两个工程的开发进度与版本节点。
> 上一个正式版本是 **v0.4.0**（2026-11-15，固件 D50）。本轮交付打 **v0.5.0** tag。

---

## 1. 本轮（v0.5.0）交付总览

| 主题 | 端 | 状态 |
|---|---|---|
| 屏幕常亮 + CPU 唤醒 + 前台服务 + 电池白名单（App 保活四层） | App | ✅ 已实施、真机安装、无崩溃 |
| 键鼠页 SUMV 按钮 2×2 重排（修拥挤/变形） | App | ✅ 已实施、真机验证等宽等高 |
| 按键事件订阅自愈：失联退订后心跳自动重订阅 | 固件 | ✅ 已实施、真机验证通过 |
| `km_evttx` 卡死看门狗重建 + 写串口超时 | 固件 | ✅ 已实施、真机验证不误触发 |
| 手机端 bit2 检测自动重订阅 + 退避重试（1/2/5 s） | App | ✅ 已实施、编译/单测通过 |
| Android SDK 补装 CMake 3.31.6 | 环境 | ✅ 已安装，完整 APK 可构建 |

---

## 2. 版本与回滚节点

| 版本 | 节点 | 固件 | App |
|---|---|---|---|
| v0.4.0 | 2026-11-15 | D50：sumv 轨迹起点 u32→int64 + 停滞判据；台架版 356,704 B | 未改（沿用 v0.3.0 APK） |
| **v0.5.0** | **2026-11-18** | 事件订阅自愈 + `km_evttx` 看门狗；台架版 **357,568 B**，回读 0 差异 | 保活四层 + SUMV 按钮重排 + bit2 退避重订阅；APK 94,114,110 B |

> 本轮已把 v0.5.0 台架版固件刷入左片（COM8 → 下载器 COM9，`0x10000`，整段回读 0 差异），
> 并把 v0.5.0 APK 通过无线调试（iQOO 15 `192.168.0.31:35559`）覆盖安装（配置已备份至
> `D:\Apply\mb_prefs_backup` 并写回，未丢数据）。右片固件本轮未改、未刷（沿用 v0.4.0 时的 292,624 B）。

---

## 3. 固件侧改动明细（`MagicBox/`）

| 文件 | 改动 |
|---|---|
| `app_left/main/btn_evt.c` / `.h` | 影子变量记住最后一次显式订阅意图；10 s 看门狗退订只清活跃态、留意图；心跳到达时自动重订阅（重入保护、边沿基准重置、pending 重建）；`btn_evt_stat_t` 增 `auto_resume`；`mx.ev` 探针追加 4 字段 |
| `app_left/main/app_main.c` | `km_evttx` 加进展戳 + `km_heal` 每秒监督 + 卡死删除重建 + 重建后补通知；创建失败不再谎称回退，交给看门狗；`control_write` 加 50 ms 有界等待（`pdMS_TO_TICKS(50)`，HZ=100） |
| `verification/plan-event-subscription-keepalive.md` | 自愈方案文档（新增，含根因/触发条件/时序/边界/交互流程） |

### 真机验证（左片台架，2026-11-18）
- `mx.ev` 由 11 字段扩为 **15 字段**：`enabled,mask,pending,cur,last_fwd,seq,count,overflow,auto_released,push,consume,auto_resume,rebuilds,tx_timeout,broken`。
- 订阅 `push=1` → 停心跳 12 s → 看门狗退订（`auto_released=1`）→ 发一次 `EVT_STAT` 心跳 → **自动恢复订阅**（`enabled=1, auto_resume=1, auto_released=0`）。
- 显式 `enable=0` 退订后，心跳不再复活订阅（意图已清）。
- 正常事件流下 `rebuilds=0 / tx_timeout=0`，看门狗不误触发。
- `mx.ac` 重克隆回 `km.1:320f:706e:93`；`mx.rr=3`（软复位）。

---

## 4. App 侧改动明细（`MagicBullet/`）

| 文件 | 改动 |
|---|---|
| `AndroidManifest.xml` | `WAKE_LOCK` / `FOREGROUND_SERVICE` / `FOREGROUND_SERVICE_SPECIAL_USE` / `POST_NOTIFICATIONS` / `REQUEST_IGNORE_BATTERY_OPTIMIZATIONS`；声明 `KeepAliveService`（`specialUse` + property） |
| `core/KeepAliveService.java`（新增） | 前台服务 + `PARTIAL_WAKE_LOCK`（30 min 兜底）+ 常驻通知 + `start/stop` 封装 |
| `res/drawable/ic_stat_keepalive.xml`（新增） | 通知单色小图标 |
| `MainActivity.java` | `FLAG_KEEP_SCREEN_ON`；`onStart/onStop/onDestroy` 启停服务；通知权限请求；电池白名单引导入口 |
| `core/AimConfig.java` | `keep_alive` 开关持久化（默认开）+ 导入导出 |
| `ui/aim/AimFragment.java` + `res/layout/fragment_aim.xml` | 瞄准页新增「保活」开关 + 「加入电池优化白名单」按钮 + 说明文案 |
| `res/layout/fragment_keys.xml` | 键鼠页 SUMV 按钮 4→2 行 2×2 网格，修拥挤/变形 |
| `core/HotkeyWatcher.java` | bit2 自动退订后重订阅加退避（1/2/5 s，最多 3 次）；成功后清零、退订清理状态；修 Runnable 自引用编译问题 |
| `res/values/strings.xml` | 保活相关字符串 |

### 真机验证（iQOO 15，无线调试）
- App 启动无崩溃；前台服务 `KeepAliveService` 运行中：`isForeground=true`，通知渠道 `magicbullet_keepalive` 已发常驻通知。
- 首装曾因前台服务类型 `connectedDevice` 在 targetSDK 35 下缺额外设备权限崩溃 → 改 `specialUse` + property 后修复。
- 键鼠页 4 个 SUMV 按钮实测各 592×165 px、两行等宽等高无重叠。
- 单测全绿；`assembleDebug` 完整构建通过。

---

## 5. 已知边界与待办（不阻塞本版本）

| 项 | 说明 |
|---|---|
| 控制口独占 | CH343 同一时刻只能接 PC（台架）或手机（OTG）一侧；本轮验证分别在两侧做，未做"手机心跳维持订阅"的端到端联调——需把 CH343 线从 PC 拔到手机 OTG 后再验 |
| `km_evttx` 卡死重建 | 已验证"正常路径不误触发"；主动杀任务触发重建的破坏性验证未做（风险高） |
| 手机端心跳线程 | 仍绑主线程 Handler（`HotkeyWatcher`），与推理线程解耦已满足主诉求；若后续出现主线程卡顿拖累心跳，再改独立 `HandlerThread` |
| 原厂脚本硬编码 | `MagicBox/tools/flash_*.ps1` 仍硬编码 `COM3` 与 `D:\JinPeng`，本机实际 `COM8` / `d:\Github`；本轮刷写按实际环境手工执行，脚本未改 |
| 右片 | 本轮未改未刷；如需回滚或重刷见根 README §6 |

---

## 6. 本轮构建产物

| 产物 | 字节 | 说明 |
|---|---:|---|
| `MagicBox/app_left/build/makcu_left.bin` | 357,568 | 左片台架版（含 `mx.*` + 自愈） |
| `MagicBox/app_right/build/makcu_right.bin` | 292,624 | 右片（本轮未改，沿用） |
| `MagicBullet/app/build/outputs/apk/debug/app-debug.apk` | 94,114,110 | App debug（保活 + 布局 + 重订阅） |

> 发布版固件（无 `mx.*`）与 Release 资产本轮**未重新打**；v0.5.0 tag 标记的是源码状态，
> 发布包更新可在下一次 Release 时按根 README §8 流程补做。
