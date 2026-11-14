# MagicBullet 交接文档

> 生成时间：2026-11-14 23:1x（Asia/Shanghai）
> 仓库：`D:\JinPeng\MagicBullet`　分支：`main`
> HEAD：`4193441 lqb`（其前 `d75d48c` 为 merge，`66190b6` 为整批提交）
> **未提交改动**：`core/HotkeyGate.java`、`core/HotkeyGateTest.java`（去抖窗口 150→50→**20 ms**）
> 设备：iQOO 15（V2505A / PD2505），App `com.magicbullet.capture` v0.1
> 配套固件仓库：`D:\JinPeng\MagicBox\AMagicBox-Rebuild`（左片 `makcu_left.bin`，347,776 B）

---

## 1. 这个项目做什么

手机接 USB 采集卡抓 PC 的 HDMI 画面 → 手机端跑 YOLO（ONNX Runtime + QNN HTP）→ 从检测框里选一个目标 → 通过 CH343 串口把「鼠标相对位移」发给鼠标盒子 → 盒子注入 PC，形成闭环自瞄。

四个页面（底部 Tab）：**预览 / Yolo / 键鼠 / 瞄准**。

| 指标 | 实测值（2026-11-10/11） |
|---|---|
| 采集帧率 | 59.4 fps（1080p60 YUY2） |
| 推理耗时 | 6 ms（QNN HTP） |
| 帧→结果 | 6–9 ms |
| 端到端目标 | 尽量 ≤100 ms（卡内 30–40 ms 是最大头） |

---

## 2. 硬件与链路

```
R9000P HDMI 1080p60 ──> 海备思 CA1331 / UHC10 (MS2130) 采集卡 ──USB──> iQOO 15
                                                                        │
                                    App: 采集 → YOLO → 选敌 → 控制口 921600
                                                                        │
iQOO 15 ──USB(OTG)──> CH343 控制口 ──UART──> MagicBox 左片 ──USB──> PC（鼠标 HID 注入）
```

- **采集卡**：UVC，要求 PC 侧输出 1080p60、关闭 HDR；App 优先 `1920x1080@60 YUY2`，失败自动回退 1080p30 → 1080p60 MJPEG → 720p60 → 720p30 → 640x480。
- **控制口**：CH343，921600 8N1，`dtr/rts=false`；帧格式 `len + cmd + payload + checksum`。
- **盒子**：左右两片（右片收真实鼠标 + 左片出 HID）。固件版本以「文件字节数」区分，例如 346,896 / 347,776 B。
- **同时占用冲突**：PC 与手机不能同时打开同一个控制口，联调前 CH343 要拔到手机侧。

---

## 3. 构建 / 安装 / 运行

```powershell
# 环境：JDK 17+、Android SDK（compileSdk 35 / build-tools 35）、Gradle 8.13（wrapper 已换腾讯镜像）
.\gradlew.bat :app:testDebugUnitTest        # 单测 118 项
.\gradlew.bat :app:assembleDebug            # 产物 app\build\outputs\apk\debug\app-debug.apk（约 99 MB，含模型与 ORT）
adb install -r app\build\outputs\apk\debug\app-debug.apk
adb shell am start -n com.magicbullet.capture/.MainActivity
```

- `local.properties` 指向 `D:/Dev/AndroidSDK`；`ANDROID_HOME` / `JAVA_HOME` 已设为用户级环境变量。
- 无线调试：`adb connect <手机IP>:<端口>`（端口每次开关都变；也可 `adb mdns services` 找 `_adb-tls-connect`）。
- 只有 `arm64-v8a`。

**常用调试命令**

```powershell
# 读配置（debug 包可用 run-as）
adb shell "run-as com.magicbullet.capture cat /data/data/com.magicbullet.capture/shared_prefs/aim_config.xml"
# 定位控件坐标（避免盲点）
adb shell uiautomator dump /sdcard/u.xml; adb shell cat /sdcard/u.xml
# 截图
adb shell screencap -p /sdcard/a.png; adb pull /sdcard/a.png .
```

---

## 4. 代码地图

`app/src/main/java/com/magicbullet/capture/` 共 43 个文件 / 约 10,100 行。

### core（28 个，全部业务逻辑，无 Android UI 依赖或仅依赖 Context）

| 文件 | 职责 |
|---|---|
| `AimConfig` | 全部瞄准参数 + SharedPreferences 持久化 + **schema 迁移（当前 11）** |
| `AimRect` | 归一化瞄准矩形（准心 = 矩形中心） |
| `AimController` | 瞄准闭环：选敌 → 残差 → 死区 → 增益 → counts → `0x3C AIM`；粘滞/换人确认；自校准增益；统计 |
| `AimMath` | 纯函数：自校准增益、单发限幅 80%、死区自适应、单帧上限、P90 百分位 |
| `AimPick` | 纯函数：瞄点纵向 anchor、`isCentred`、选敌多层排序、`shouldTakeOver` 抢锁双门槛 |
| `TargetTracker` | 头/体聚类 → 跨帧匹配（56 px / 40 px 跳变上限）→ 速度最小二乘 + EMA；`headSize`/`bodySize`/`sizeProxy`（尺寸 EMA α=0.30） |
| `HotkeyGate` | 热键去抖（**20 ms**，仅"按一下切换"模式） |
| `HotkeyEdge` / `HotkeyWatcher` | 多选热键位图上升沿判定、1 Hz 心跳、释放补发、学习按键 |
| `ControlPort` | CH343 控制口：帧打包、全部 opcode、0x3C AIM、EVT 订阅、链路断开重连、日志 |
| `UvcSession` / `UvcSessionHost` | USB 权限与 UVC 生命周期（跨 Tab 存活），自动重扫 |
| `UsbPermissionFlow` | USB 授权流程 |
| `YoloDetector` / `YoloPreprocess` / `YoloPostprocess` / `YoloConfig` / `YoloSettings` | 检测全链路（ORT/QNN） |
| `QnnRuntime` / `QnnContextCache` | QNN HTP 后端与 context 缓存 |
| `ModelStore` / `ModelProfile` / `Labels` | 模型文件与类别管理 |
| `FrameSnapshot` / `Detection` / `PipelineStats` | 帧快照、检测结果、管线统计 |
| `RoiConfig` / `Postprocess`（post 目录） | ROI 裁剪与后处理（NMS 等） |
| `DummyDetector` | 无模型时的假检测 |

### widget / ui

| 文件 | 职责 |
|---|---|
| `widget/AimRectView` | 预览页拖动/缩放瞄准矩形 |
| `widget/DetectionOverlayView` | 锁定框、预测点绘制 |
| `widget/CalibView` + `ui/calib/AimCalibActivity` | 横屏放大校准准心 |
| `ui/aim/AimFragment` | 瞄准页（参数、布防、热键、统计、日志、导入导出、页尾「保存配置」） |
| `ui/preview/PreviewFragment` | 预览页，喂检测结果给 AimController |
| `ui/keys/KeyboardMouseFragment` | 键鼠页（手动 SUMV、三档 mode、0x38/0x42 诊断） |
| `ui/yolo/YoloFragment` | 模型与阈值配置 |
| `MainActivity` | Tab 容器 + 矩形编辑入口 + 音量键触发 |

---

## 5. 关键机制

### 5.1 采集与推理

帧在采集回调线程转 RGBX → NEON 预处理 → 提交推理线程池 → `mAim.onDetections(...)`（**注意：瞄准的全部计算与串口写都在这个推理线程上同步执行**）。

### 5.2 目标跟踪与选敌（当前 schema 11）

`TargetTracker`：body 为基准，按"头在身体上半部且重叠 ≥50%"把头粘到身体上；孤立的头也作为候选；每帧最近邻匹配（`MATCH_RADIUS_PX=56`，单帧跳变 >40 px 视为新目标；`STALE_NS=300 ms` 淘汰）。

`AimPick.pick` 的排序（在 `rect.contains` 预筛之后）：

```
① |ax − 准心x| ≤ reach（sizeReach × frameW，默认 15%）→ 才有资格
② headSize 最大（并列带 1%）
③ 并列 → bodySize 最大（并列带 1%）
④ 并列 → 横向偏离最小（"最正"）
⑤ 并列 → y 最大（最下面）
⑥ 资格内无 head → 距离最近（non-head 加 12 px 惩罚）
```

- 瞄点：`ay = head.top + (head.bottom − head.top) × headAnchorBias`（默认 **1.0 = 下巴**；`bias` 被 clamp 到 0~1，**想再往下只能靠「准心偏移 Y」**）。
- 粘滞：`mStickId` 锁定后优先；抢锁需 `shouldTakeOver`（相对 `sizeGate=1.12` **且** 绝对 `sizeDelta=0.01`）+ **连续 `switchFrames=3` 帧确认**；框内无目标连续 3 帧才清锁。

### 5.3 瞄准闭环（`0x3C AIM`）

```
残差 px = 瞄点 + aimOffset − 准心
error < deadzone(4 px，可选自适应 ≤12)         → 停手（并 0x37 停轨迹）
frames < stableFrames(3)                       → 只看不动
counts = min(残差 × 1/pxPerCount × gain,  残差 × 1/pxPerCount × 0.8)   ← 0.8 是硬限幅
单帧 counts 上限 = 自适应(max(框高×1.6, 跳变P90×1.5)×countsPerPx, 80, min(手填200,400))
发送 0x3C(dx, dy, max_ms=10, flags, dead_min=死区×countsPerPx)
```

**注意两个与直觉相反的点**

1. `gain > 0.8` 无意义——`limitToError` 会把每发截到残差的 80%；
2. 不过冲的安全边界是 `真实px/count ÷ pxPerCount ≤ 1.25`。`pxPerCount=1.0` 时边界就收到 1.25，轻微过冲属正常。

### 5.4 热键通道

`EVT` 推送（`0xE1`）+ 1 Hz `EVT_STAT`；只有「无人按住 → 有人按住」的上升沿报 down，全部松开才报 up；`EVT_STAT.cur == 0` 时补发释放。

`HotkeyGate` 只作用于「按一下切换」模式（「按住生效」不走门）：

```
距上次被接受的按下 < 20 ms        → 忽略（重复报告/抖动）
上次按下后见过释放，且距释放 < 20 ms → 忽略（触点回弹）
```

被忽略累计计数在状态行显示（第 1、6、11… 次），**每次布防清零**。

### 5.5 控制口 opcode（`ControlPort`）

| opcode | 名称 | 载荷 |
|---|---|---|
| `0x31/0x32/0x33` | MOTION / BUTTON / WHEEL | 直接位移/按键/滚轮 |
| `0x36` | **SUMV** | `dx i16, dy i16, speed u16(counts/s), mode u8, seed u8 [, dur_ms u16]` |
| `0x37` | SUMV_STOP | 无 |
| `0x38` | SUMV_STATE | 返回 `running/samples/aborted/rounds/muted…` |
| `0x39/0x3A/0x3B` | EVT_CTL / EVT_READ / EVT_STAT | 热键订阅与状态 |
| `0x3C` | **AIM** | `dx i16, dy i16, max_ms u8, flags u8, dead_min u8`（flags: bit0 会话钳位、bit1 极速） |
| `0x3D` | AIM_STATE | 每发结果（rounds/死区/替换/超限） |
| `0x3E/0x3F/0x44` | HID_STAT / BTN_AUDIT / BTN_LOG | 诊断计数与按键轨迹 |
| `0x40/0x41` | AIM_RESET / EVT_RESET | 复位累计 |
| `0x42` | LAST_HID | 上一条 HID 报告（排查按钮字节/位移） |
| `0xE1` | EVT_PUSH | 按键事件推送 |

**SUMV 的关键语义**（固件 `API-control-port.md` §5.3）：`D = hypot(dx,dy)`，`T_ms = clamp(1000·D/speed, 40, 5000)`。speed=400 时 200 counts 需要 **500 ms**，这期间任何新轨迹（AIM 每帧 / 0x37 / 再发一条）都会 REPLACE 掉它 → 表现为“只动一点点”。

---

## 6. 参数与默认值（`AimConfig`）

| 分组 | 参数 | 默认 | UI 位置 |
|---|---|---|---|
| 目标与闭环 | 死区 px / 增益 / 单帧上限 counts / px-count | 4 / 0.60 / 200 / 1.25 | 目标与闭环卡片 |
| | 参与类别 / 会话钳位 / 极速档 | `head,body` / 关 / 关 | 同上 |
| 高级 | 稳定帧 / 最小轨迹帧 / 准心偏移 X,Y | 3 / 3 / 0,0 | 高级区 |
| | 自适应死区 / 自学习单帧上限 / 开镜增益桶 | 开 / 开 / 关 | 高级区 |
| 选敌 | 居中优先 / 居中容差 / 头部锚点 | 开 / 1.0% / 1.0 | 高级区 |
| | 选近优先 / 选敌横向范围 / 换人门槛 | 开 / 15% / 12% | 高级区 |
| | 换人最小差 / 换人确认帧 / 尺寸平滑 | 1.0% / 3 / 30% | 高级区 |
| 热键 | 掩码 / 按住生效 / 吞掉热键 / 音量键 | `0x02`(右键) / 关 / 关(穿透) / 开 | 热键卡片 |
| 其它 | 瞄准速度 max_ms / 自动学习增益 / 松手停止 | 10 ms / 开 / 开 | 目标与闭环 / 高级 |

- 页尾有「**保存配置（应用整页参数）**」按钮；高级区有「导出/导入配置」（`aim_config.json`）。
- **schema 迁移史**：2（AIM 化，px/count 1.25、max_ms 由 speed 反推）→ 3（热键改右键切换、会话钳位关）→ 4（`max_ms` 地板 4 ms 修复）→ 5（三帧稳定、单发上限 200）→ 6（死区/上限自学习默认开）→ 7（下巴锚点 1.0 + 居中优先）→ 8（居中容差 ±1%）→ 9（选近优先：框大）→ 10（选敌横向范围 15%）→ 11（反抢锁三件套：门槛 12% + 绝对差 + 确认帧 + 尺寸 EMA）。

---

## 7. 测试与验证

### 单测（JVM，无设备）

`app/src/test/` 12 个类，**118 项全绿**：

| 类 | 覆盖 |
|---|---|
| `AimPickTest`（31） | 瞄点 anchor、居中容差、选近/框大、头体并列、抢锁双门槛、边界无缝 |
| `TargetTrackerTest`（12） | 头体聚类、锚点 bias、速度估计、尺寸 EMA、`headSize`/`bodySize`/`sizeProxy` 三值 |
| `AimMathTest / AimMathTest2 / AimMathTuneTest` | 增益自校准、限幅、死区/上限自学习 |
| `AimRectTest / RoiConfigTest / FrameSnapshotTest` | 几何与 ROI |
| `HotkeyGateTest`（11） | 去抖窗口边界（10/20/25/60/90 ms） |
| `HotkeyEdgeTest` | 多选位图上升沿 |
| `YoloSettingsTest / PostprocessTest` | 阈值与 NMS |

```powershell
.\gradlew.bat :app:testDebugUnitTest
# 结果：app\build\test-results\testDebugUnitTest\*.xml
```

### 台架 / 真机

`docs/测试/瞄准模块测试方案.md`（10.5 KB）为测试方案台账。实用手法：

- 预览页看锁定框与目标读数 `head 0.87 · 420 px/s · h0.09 b0.30`；
- 瞄准页状态行：`自动 死区 x.xpx 上限 yc`、`自校准增益 0.xx（实测响应 0.xx）`、`粘滞 x%（换人 N）`；
- 运行日志：`→ AIM dx,dy counts · 残差 … px`、`过冲（残差翻向…）`、`热键切换 → 瞄准 ON/OFF`、`已忽略重复按下（累计 N 次）`；
- 键鼠页：`读状态`(0x38) 看 samples/aborted，`读上条报告`(0x42) 看单条 HID 位移。

---

## 8. 设备当前状态（2026-11-13 23:56 读取）

```
aim_schema=11  gain=0.4  deadzone=1.0  auto_deadzone=关  auto_gain=开
px_per_count=1.25  hotkey=0x12（右键+侧前键）  session_clamp=关  turbo=关
```

> 用户会直接在手机上改这些值；交接时**以设备实际值为准**，文档默认值仅是代码 default。
> 如需恢复出厂默认：把 `aim_config.xml` 替换为全默认值文件后 `am force-stop` 再启动（本会话留下过 `build/aim_config_default.xml`、`build/aim_config_current.xml` 两份备份）。

---

## 9. 已知问题与风险

| 编号 | 问题 | 影响 | 位置 |
|---|---|---|---|
| R-1 | `sendFrame` 持锁同步 `bulkTransfer`，超时 **200 ms**，且在推理线程上执行 | USB 抖动时整条闭环卡 200 ms（"卡一下才回拉"） | `ControlPort.sendFrame` |
| R-2 | 没有"轨迹飞行中抑制" | 上一发未走完又发下一发，过冲后可能连续反向对撞 | `AimController.onDetections` |
| R-3 | 瞄点位置无时间平滑（只对框尺寸做了 EMA） | 检测框抖动直接印到落点 | `TargetTracker` |
| R-4 | 无"收尾微调律"，只有比例控制 + 固定 80% 限幅 | 精度天花板 = 死区；想又快又准只能牺牲一头 | `AimMath.limitToError` |
| R-5 | SUMV 与 AIM 共用同一条"当前轨迹"通道 | 键鼠页发 SUMV 时若有 AIM 帧在跑，SUMV 被 REPLACE（speed=400 时窗口长达 500 ms，极易被打断） | 固件 |
| R-6 | `headAnchorBias` 被 clamp 到 1.0 | 想瞄到框底以下（脖子）只能用「准心偏移 Y」 | `AimPick.anchorY` |
| R-7 | 去抖窗口 20 ms 已贴近机械抖动下限 | 抖得厉害的鼠标可能重现"一次点击切两次" | `HotkeyGate` |
| R-8 | **`README.md` 已过时**（还写着"UVC 预览 Demo，暂不做推理"） | 新人会被误导 | 仓库根 |
| R-9 | 会话钳位（`sessionClamp`）若打开，累计超 4000 counts 后固件每发拒绝 | 打一会儿突然不动 | `AimConfig` + 固件 |
| R-10 | `mStickSwitches` 统计口径 | 现在只统计真换人（已修正），但历史界面上"粘滞率"含义变了 | `AimController` |

---

## 10. 待办候选（按收益排序）

1. **控制口写改为异步**：独立写线程 + 深度 1 覆盖队列，`WRITE_TIMEOUT_MS` 降到 20–30 ms（解 R-1）。
2. **收尾微调律**：残差 ≤25 px 时按 1~3 counts 微步 + `max_ms` 降到 4~6（解 R-4，同时能提精度不提速度）。
3. **瞄点位置 EMA**（解 R-3），α 可与尺寸平滑共用。
4. **热键去抖窗口配置化**（解 R-7，20/50/150 ms 可选）。
5. **键鼠页加 AIM 发送入口**（counts + max_ms），用于对比 SUMV 手感（缓解 R-5 的现场困扰）。
6. **重写 README**（解 R-8），把当前四页功能、构建、链路写清楚。
7. 提交未提交的 `HotkeyGate` 20 ms 改动。

---

## 11. 文档索引

| 文档 | 内容 |
|---|---|
| `docs/瞄准模块.md`（38.6 KB） | 主文档：AIM 版设计与历次迭代（§1 参数、§7 键鼠页、§8 代码位置、§9 验收、§25.x 选敌四轮 + 反抢锁） |
| `docs/测试/瞄准模块测试方案.md`（10.5 KB） | 测试方案与缺陷台账 |
| `docs/Android采集卡YOLO低延迟方案.md`（11.3 KB） | 采集/推理低延迟方案（含采集卡选型与管线） |
| 固件 `D:\JinPeng\MagicBox\AMagicBox-Rebuild\docs\API-control-port.md` | 控制口协议权威文档（SUMV/AIM 语义、mode 位、时长与速度） |

---

## 12. 交接要点（三句话）

1. 闭环能用，瓶颈在**采集链路延迟**和**控制口同步写**，不在推理（6 ms）；
2. 选敌规则改过四轮，最终形态是「框大优先 + 换人三件套」，**改这块务必先读 `AimPick` / `AimController.pick()` 的注释和 `AimPickTest`**；
3. 任何"速度/精度"体感问题，先分清楚是 **counts 偏大（过冲）** 还是 **轨迹窗口太长（被打断）**——两者的修法完全相反。
