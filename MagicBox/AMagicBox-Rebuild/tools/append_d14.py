import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/30-decisions.md"
t=open(p,encoding="utf-8").read()
add = """
## D14 台架控制台同时挂 UART0 与 USB-Serial-JTAG

- **结论**：`app_left` 的控制协议在 UART0（生产接线，CH343）与芯片自带
  USB-Serial-JTAG 两个口上同时收发（`MB_CONTROL_USB_JTAG` 宏可关）。
- **理由**：本轮台架上 CH343 控制口不在，只有芯片原生 USB 可用；没有第二条通路
  就无法在烧录后读回包。
- **证据**：`app_left/main/app_main.c` 的 `control_write()` 与读循环；
  `idf.py -p COM9 flash` 走的也是这个口。
- **推翻条件**：最终固件（进入 P5 之后）应关掉这条旁路，只保留 UART0。

## D15 烧录/回滚流程

- **结论**：`tools/flash_left.ps1` 提供 backup / flash / verify / restore 四个动作；
  restore 用整片 4 MB 备份回写（bootloader + 分区表 + NVS + app 一起复原）。
- **证据**：本轮已生成 `work/hw_left_before_rebuild.bin`（4194304 B），
  与官方 `V3.2_LEFT.bin` 前 403536 字节 **逐字节一致**，app 版本串 `1`。
- **推翻条件**：换片/换盒后必须重新 backup。
"""
if "## D14" not in t:
    open(p,"a",encoding="utf-8").write(add); print("D14/D15 appended")
