# MagicBullet

Android 端通过 USB 采集卡预览 PC 画面，后续接入 YOLO 检测的工程。

当前版本是 **UVC 预览 Demo**：把海备思 CA1331 / UHC10（MS2130）采集卡接上 iQOO 15，App 请求 USB 权限并直接预览 1080p 画面，暂时不做推理。

## Demo 功能

- 自动枚举 UVC 采集卡；
- 请求 USB 权限；
- 优先尝试 `1920x1080 @ 60fps YUY2`；
- 失败时自动回退：1080p30 YUY2 → 1080p60 MJPEG → 720p60 YUY2 → 720p30 YUY2 → 640x480；
- 16:9 等比预览，不拉伸；
- 显示当前设备、分辨率、帧率、格式；
- “重新扫描”按钮；
- 插拔采集卡自动关闭/重开。

## 构建

环境：JDK 17、Android SDK（compileSdk 35）、Gradle 8.13。

```powershell
.\gradlew.bat :app:assembleDebug
```

APK：

```text
app\build\outputs\apk\debug\app-debug.apk
```

安装：

```powershell
adb install -r app\build\outputs\apk\debug\app-debug.apk
```

## 使用

1. R9000P 的 HDMI 输出设为 `1920x1080 60Hz`，关闭 HDR；
2. 采集卡 HDMI IN 接 PC，USB OUT 接 iQOO 15；
3. 需要边充边采时，把 PD 充电器接到采集卡的 PD 口；
4. 打开 App，允许 USB 权限；
5. 画面出现后，顶部会显示当前格式，例如：

```text
1920x1080 @ 60fps YUY2
```

如果显示的是 `MJPEG`，说明 UVC 协商没有拿到 YUY2，需要检查 USB 链路是否跑在 5Gbps。

## 排查

| 现象 | 检查 |
|---|---|
| 一直“未发现 USB 设备” | OTG 是否开启；换 USB 3.0 全功能线；换 USB-C 口 |
| 有设备但没有 UVC 接口 | 采集卡是否被系统识别为视频设备；换一个 UVC App 交叉验证 |
| 权限弹窗不出现 | 重新插拔；在系统设置里清除该 USB 设备的默认权限后重试 |
| 黑屏但权限已给 | HDCP 内容会黑屏；确认 PC 输出的是非加密桌面；确认 1080p60 |
| 只有 MJPEG | USB 链路可能降到 2.0；检查线材/Hub/PD 直通 |
| 画面卡顿/花屏 | 先降 720p60 或 1080p30；检查供电和散热 |
| App 启动崩溃 | 可能是 native 库 16KB page size 不兼容，见下 |

### 16KB page size 提醒

`libuvc` 使用的是仓库内预编译 `.so`（4KB 对齐）。如果 iQOO 15 的系统内核启用 16KB page size，加载 `libUVCCamera.so` 可能失败。届时需要用 NDK 重新编译 libuvc/libusb，链接参数加：

```text
-Wl,-z,max-page-size=16384
```

当前 Demo 先按 4KB 设备验证；如果真机报 `dlopen failed`，再处理。

## 代码结构

```text
app/                       Demo App（Java）
  MainActivity.java        USB 权限、UVCCamera 打开、预览、回退
  AspectRatioSurfaceView   16:9 预览容器
libuvc/                    vendored UVC 库（来自 AndroidUSBCamera / saki4510t）
  src/main/java/...        USBMonitor、UVCCamera
  src/main/jniLibs/...     预编译 arm64-v8a .so
docs/
  Android采集卡YOLO低延迟方案.md
```

## 下一步

1. 真机验证 1080p60 YUY2 是否能稳定预览；
2. 记录实际分辨率和帧率；
3. 接入 LiteRT/TFLite，先用 COCO 模型跑通“帧 → 推理 → 画框”；
4. 再替换自定义模型，最后做 60fps/GPU/QNN 优化。

## 说明

- `libuvc` 来自 [AndroidUSBCamera](https://github.com/jiangdongguo/AndroidUSBCamera)，Apache License 2.0；
- 当前只做预览，不包含 YOLO 模型和推理代码；
- 完整的低延迟方案见 [docs/Android采集卡YOLO低延迟方案.md](docs/Android采集卡YOLO低延迟方案.md)。
