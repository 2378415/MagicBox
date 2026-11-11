import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
# decisions: D19 HID 设备、D20 恢复通道
p="docs/30-decisions.md"
t=open(p,encoding="utf-8").read()
if "## D19" not in t:
    t += """
## D19 USB HID 设备用托管组件 + 自己初始化 PHY

- **结论**：`espressif/tinyusb`（托管组件）负责设备栈，`makcu_hiddev` 自己初始化 PHY、
  提供描述符与 `tud_task()` 任务，组件用 `WHOLE_ARCHIVE` 保证回调不被归档顺序丢掉。
- **理由**：IDF 5.4 已把 TinyUSB 移出核心组件，托管版本不带 ESP32-S3 板级层；
  枚举所需的 PHY 配置只有三行，照它自带 BSP 的做法即可。
- **证据**：主机枚举为 `HID-compliant mouse`（VID 303A / PID 4004），
  `tools/cursor_test.ps1` 量到真实光标位移（第八批报告 §2/§3）。
- **推翻条件**：需要 CDC+HID 复合设备时，必须改成 USB-Serial-JTAG 之外的总线方案
  （两者共用 D+/D-，不能并存）。

## D20 台架自恢复通道 `mx.dl`

- **结论**：`MB_DEBUG_OPCODE=ON` 时接受 `mx.dl`：置 `RTC_CNTL_FORCE_DOWNLOAD_BOOT` 并重启，
  芯片回到 ROM 下载模式，原生 USB 重新成为可烧录的串口。
- **理由**：HID 构建在原生 USB 上没有控制台，否则回滚只能靠手按 BOOT。
- **证据**：第八批用该命令从 HID 固件回滚成功，回读整片逐字节一致。
- **推翻条件**：发布固件不得带该命令（同 D17）。
"""
    open(p,"w",encoding="utf-8").write(t)

# status
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 副作用层（P2/P5） | 未开始 | HID 报告实际上报（`makcu_hiddev`）、描述符克隆/序列号、UART1 桥接任务 |',",
"'| 副作用层（P5 HID 上报） | **完成**：设备枚举为 HID 鼠标，光标位移已端到端验证；描述符克隆/序列号仍未移植 | `components/makcu_hiddev/`、`tools/cursor_test.ps1` |',\n            '| 副作用层（P2 桥接 / P5 克隆） | 未开始 | UART1 桥接任务、描述符克隆、序列号读写 |',")
open(p,"w",encoding="utf-8").write(t)
print("docs updated")
