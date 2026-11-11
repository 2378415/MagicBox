# MagicBullet

Android 端：**UVC 采集卡看 PC 画面 → YOLO 检测目标 → 通过控制口下发瞄准位移**给 MAKCU 盒子（`com.magicbullet.capture`）。
盒子再以 HID 报告的形式注入，对 PC 而言就是一只普通鼠标。

> 上层总览与硬件拓扑见 [../README.md](../README.md)；固件侧与协议见 [../MagicBox/AMagicBox-Rebuild/docs/API-control-port.md](../MagicBox/AMagicBox-Rebuild/docs/API-control-port.md)。

## 功能

| Tab | 能力 |
|---|---|
| 预览 | UVC 采集（1080p60 YUY2 优先，逐级回退到 720p/480p、MJPEG）、等比显示、检测框叠加、锁定框与预测点、插拔自动重连 |
| YOLO | 模型导入与切换（内置 + 自定义 profile）、后端选择（QNN HTP / ONNX Runtime CPU）、输入尺寸/anchor/类别配置、逐阶段耗时统计 |
| 键鼠 | 盒子侧按键注入、按键事件订阅与统计（`0x3E/0x3F`）、HID 报告回读（`0x42`） |
| 瞄准 | 瞄准矩形与准心编辑（含横屏放大校准页）、热键多选、闭环参数、自校准/自学习开关、状态卡（AIM_STATE / HID_STAT / BTN_AUDIT） |

竖屏锁定、单 Activity + 4 个 Fragment；USB/UVC 会话挂在 Activity 上，换 Tab 不重连。

## 数据流

```
UVC 帧 ─► FrameSnapshot ─► letterbox(libmbpre.so) ─► YoloDetector(QNN / ORT CPU)
                                                            │
        Postprocess（native + Java 双实现互校）◄── 输出张量 ──┘
                        │
        TargetTracker（聚类 / 粘滞 / 跳变剔除）→ AimPick（头部锚点：居中优先 + 下沿 bias）
                        │
        AimController（残差 px → counts、自适应增益、死区与单发限幅、断流看门狗）
                        │
        ControlPort（0x3C AIM / 0x3D 轮询 / 0x39 EVT_CTL）──► CH343 ──► 盒子
```

## 环境与构建

| 项 | 值 |
|---|---|
| JDK / 语言级 | 17 |
| AGP / Gradle | 8.8.2 / 8.13（`distributionUrl` 指腾讯镜像） |
| compileSdk / targetSdk / minSdk | 35 / 35 / 28 |
| NDK 外部构建 | CMake `3.31.6`，`-DANDROID_STL=c++_static`，`abiFilters arm64-v8a` |
| 关键依赖 | `models/ort-qnn-v79.aar`（自编译 ORT 1.29.0 + QNN v79）、`com.qualcomm.qti:qnn-runtime:2.42.0`、`project(':libuvc')` |
| `local.properties` | 需本地写 `sdk.dir=…`（已 gitignore） |

```powershell
.\gradlew.bat :app:assembleDebug        # APK → app\build\outputs\apk\debug\app-debug.apk
.\gradlew.bat :app:testDebugUnitTest    # 单测
adb install -r app\build\outputs\apk\debug\app-debug.apk
```

## 使用

1. PC HDMI 输出设 `1920x1080 60Hz`、关闭 HDR；采集卡 HDMI IN 接 PC，USB OUT 接手机（可同时接 PD 边充边采）；
2. 中线 CH343 接手机（与采集卡同挂 Hub），盒子上电后控制口在 App 内枚举；
3. 打开 App 允许 USB 权限，预览页显示格式（如 `1920x1080 @ 60fps YUY2`；显示 MJPEG 说明链路降到 2.0 或协商失败）；
4. YOLO 页选后端与模型（内置 `yolov8n_int8_qdq.onnx`，也可导入自定义 8 类 e2e 模型）；
5. 瞄准页框定瞄准矩形、设热键（右键 0x02 / 侧后 0x08 / 侧前 0x10 可组合），布防后热键切换瞄准；
6. 现场排查取日志：`adb shell run-as com.magicbullet.capture cat cache/control.log`（256 KB 滚动，与页面日志同源）。

## 参数（`AimConfig`，SharedPreferences 键即表内键名，`aim_schema` 当前 10，旧版自动迁移）

| 键 | 默认 | 含义 |
|---|---|---|
| `speed` / `max_ms` | 1200 / 10 | 老路径 `0x36` 速度；瞄准每发时长预算 |
| `mode` | `0x00` | `0x40` 拟人 / `0x80` 极速 |
| `px_per_count` | 1.25 | 本机标定增益（125% 缩放、无指针加速） |
| `max_step_counts` | 200 | 单发相对限幅（自学习可调，手填为上界） |
| `lead_ms` | 30 | 前馈提前量 |
| `hotkey` / `hotkey_consume` / `hold` | `0x02` / false / false | 热键位图、默认穿透（不吞键）、按下切换 |
| `stable_frames` / `track_min` / `switch_frames` | 3 / 3 / 3 | 锁定确认、最小轨迹、换目标确认 |
| `deadzone` / `auto_deadzone` | 4 px / true | 死区与自学习 |
| `auto_gain` / `auto_maxstep` | true / true | 增益与单发限幅自学习 |
| `head_anchor_bias` / `prefer_centered_head` / `center_tolerance` | 1.0 / true / 0.03 | 头部锚点（下沿）、居中优先、容差 |
| `stick_target` / `size_gate` | true / 1.12 | 目标粘滞与尺寸过滤 |
| `session_clamp` / `release_stop` / `turbo` | — | 会话位移钳位、松手停、极速 |

## 代码结构

```text
app/src/main/java/com/magicbullet/capture/
├── MainActivity.java              单 Activity 外壳：底部导航 + 四 Fragment + USB 会话宿主
├── core/
│   ├── ControlPort.java           CH343 串口（921600）、帧编解码+CRC8、0x31–0x45/0xE1、日志落盘
│   ├── UvcSession.java / UsbPermissionFlow.java / UvcSessionHost.java
│   ├── YoloDetector.java / YoloConfig.java / YoloSettings.java / YoloPreprocess.java / YoloPostprocess.java
│   ├── ModelStore.java / ModelProfile.java / QnnRuntime.java / QnnContextCache.java / Labels.java
│   ├── TargetTracker.java / AimPick.java / Detection.java
│   ├── AimController.java / AimMath.java / AimConfig.java / AimRect.java / RoiConfig.java
│   ├── HotkeyWatcher.java / HotkeyGate.java / HotkeyEdge.java
│   ├── FrameSnapshot.java / PipelineStats.java / DummyDetector.java
│   └── post/                      Geometry、Nms、Postprocess
├── ui/{preview,yolo,aim,keys,calib,placeholder}/
└── widget/                        AimRectView、DetectionOverlayView、CalibView、RoiPickerView、AspectRatioFrameLayout
app/src/main/cpp/                  letterbox.cpp、postprocess.cpp（libmbpre.so）
app/src/main/assets/               yolov8n_int8_qdq.onnx（内置模型）
app/src/test/                      12 个测试类、115 条 @Test
libuvc/                            vendored UVC 库（AndroidUSBCamera / saki4510t，Apache-2.0）
models/                            ort-qnn-v79.aar（构建硬引用）、imported/m.onnx、量化脚本
docs/                              低延迟方案、瞄准模块、测试方案
```

## 控制口交互（摘要）

| cmd | 用途 |
|---|---|
| `0x39 EVT_CTL` | 订阅按键（`push=1` 异步推；第 4 字节 `consume` 缺省 0 = 穿透） |
| `0x3A EVT_READ` / `0x3B EVT_STAT` | 取事件 / 通道状态（同时是心跳，10 s 不发会被自动退订） |
| `0x3C AIM` | 每帧一发：`dx i16, dy i16, max_ms u8, flags u8[, dead_min u8]` |
| `0x3D AIM_STATE` | 轮询闭环结果：`active / last_result(1–6) / rounds / aborted / gen` |
| `0x36–0x38` | 老的 `sumv` 路径（速度制），瞄准已改用 `AIM` |
| `0x3E / 0x3F / 0x42` | 按键队列统计 / 按键回环审计 / 上一条 HID 报告 |
| `0x40 / 0x41` | 清 `AIM_STATE` 累计量 / 清事件环 |

帧格式 `5A cmd seq len:u16 payload crc8`，回包 `cmd | 0x80`；运动类 fire-and-forget。完整字段表见固件侧协议文档。

## 测试

- 单测：`app/src/test/**` **12 个类 / 115 条 `@Test`**（`AimMath`、`AimMath2`、`AimMathTune`、`AimPick`、`AimRect`、`HotkeyEdge`、`HotkeyGate`、`TargetTracker`、`FrameSnapshot`、`RoiConfig`、`YoloSettings`、`Postprocess`）。
- 台架 PT-01…与真机 FT-01…清单、判定方式、`control.log` 拉取命令：见 [docs/测试/瞄准模块测试方案.md](docs/测试/瞄准模块测试方案.md)（v1.0 记录 79/79，当前源码已扩到 115 条）。
- 回归门槛：任何改动先 `:app:testDebugUnitTest` 全绿；瞄准改动补 FT-01/07/09/13，热键改动补 FT-02/03/05/06。

## 排查

| 现象 | 检查 |
|---|---|
| 一直“未发现 USB 设备” | OTG 是否开启；换 USB 3.0 全功能线/口 |
| 权限弹窗不出现 | 重新插拔；清除该 USB 设备的默认权限 |
| 黑屏但权限已给 | HDCP 内容黑屏；确认 PC 输出非加密桌面、1080p60 |
| 只有 MJPEG | 链路可能降到 USB 2.0；查线材/Hub/PD 直通 |
| 画面卡顿/花屏 | 降 720p60 或 1080p30；查供电与散热 |
| 显示“控制口未连接” | 中线 CH343 是否在手机上（PC 与手机不能同时占用同一串口） |
| 热键点进游戏 | 热键已改成默认**穿透**；要盒子吃掉必须 `consume=1` |
| 盒子 10 s 后不再报按键 | 心跳断了，App 会自动重订阅并在日志留痕 |
| 瞄准不动 / 有发无位移 | 看 `AIM_STATE.last_result`：3 拒绝、4 死区、5 看门狗、6 超限；再看 `0x3F extra` 是否为 0 |
| 瞄准偏 / 差 25% | `px_per_count` 标定；DPI-unaware 进程看到的是逻辑像素，标定工具需 `SetProcessDpiAwareness(2)` |
| App 启动崩溃 `dlopen failed` | `libuvc` 预编译 `.so` 为 4 KB 对齐；16 KB page size 内核需重编并加 `-Wl,-z,max-page-size=16384` |

## 说明

- `libuvc` 来自 [AndroidUSBCamera](https://github.com/jiangdongguo/AndroidUSBCamera)，Apache License 2.0，子目录保留原声明；
- `models/ort-qnn-v79.aar` 是基于 ONNX Runtime 1.29.0 的自编译产物（加了 `QNN_HTP_DEVICE_ARCH_V79`），遵循 MIT；
- 构建产物、研究草稿（`.research/`）、本地依赖解包与训练权重不入库，见 [../CLEANUP.md](../CLEANUP.md)。
