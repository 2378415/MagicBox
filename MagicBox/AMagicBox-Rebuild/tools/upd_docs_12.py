import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/30-decisions.md"
t=open(p,encoding="utf-8").read()
if "## D21" not in t:
    t += """
## D21 免按键台架闭环：`mx.dl` + UART0 上的 ROM 加载器

- **结论**：烧录/回滚不再需要按键。`mx.dl`（`RTC_CNTL_FORCE_DOWNLOAD_BOOT` + `esp_restart`）
  把芯片送进 ROM 下载模式，ROM banner 打印 `boot:0x2 (DOWNLOAD(USB/UART0))`——加载器**同时监听
  UART0**，而 UART0 就挂在常插的 CH343（COM8）上，于是 `esptool --port COM8 --before no_reset`
  可以直接烧写。
- **理由**：之前每次迭代都要人按住 BOOT，成本高且易失败；HID 构建又没有 CDC 可用。
- **证据**：第十二批的回归烧录与回滚全程走 COM8，`cmp_restore.py` sha256 一致。
- **推翻条件**：若某版固件去掉 `mx.dl`（发布构建必须去掉，见 D17），手动 BOOT 仍是唯一入口。

## D22 `-Define` 必须按逗号拆回多个参数

- **结论**：`tools/build_app.ps1` 接收 `-Define "A,B"` 并拆成 `-DA -DB` 两个参数传给 idf.py。
- **理由**：经 `powershell -File` 调用时，数组被拼成 `"ON,-DMB_HID_DEVICE=OFF"`，CMake 将其当作
  单个 `-D`，导致 `MB_HID_DEVICE` 恒为缓存值 ON——多轮"控制台构建"其实是 HID 构建，
  这也是 CDC 一直不枚举的真正原因。
- **证据**：`CMakeCache.txt` 里曾出现 `MB_DEBUG_OPCODE:BOOL=ON,-DMB_HID_DEVICE=OFF`；
  修复后缓存干净，控制台构建立刻恢复 CDC。
- **推翻条件**：换掉构建包装脚本时重测该项。
"""
    open(p,"w",encoding="utf-8").write(t)

p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 11 次；最新一轮 **75 例全绿**（74 passed + 1 xpassed：协议/报告 54 + 键盘 7 + 曲线 2 + 离线模型 12）；回滚新鲜回读 sha256 一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 12 次；最新一轮 **79 例全绿**（78 passed + 1 xpassed：协议/报告 54 + 键盘 7 + 桥接 4 + 曲线 2 + 离线模型 12）；回滚新鲜回读 sha256 一致 | `verification/report/` |',")
t=t.replace("'| 副作用层（P2 桥接 / P5 克隆） | 未开始 | UART1 桥接任务、描述符克隆、序列号读写（`serial()` 仍恒回失败文案） |',",
"'| 副作用层（P2 桥接） | **完成**：UART1 帧层 + 桥接任务 + 按端点重组（`0xA0/0xA2/0xA3`）；EP0 应答、真实引脚仍待定 | `components/makcu_link/` |',\n            '| 副作用层（P5 克隆） | 未开始 | 描述符拼装 + EP0 隧道应答 + 序列号读写（`serial()` 仍恒回失败文案） |',")
open(p,"w",encoding="utf-8").write(t)
print("docs updated")
