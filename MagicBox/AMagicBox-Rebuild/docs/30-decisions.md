# 30-decisions：决策记录（每次“为什么这样做”都要留档）

> 格式：结论 → 理由 → 证据 → 何时推翻。

## D1 不重写 IDF / newlib / tinyusb

- **结论**：L1 库代码（≈2834 函数）直接链接 ESP-IDF v5.4.1。
- **理由**：重造库没有收益；且原固件的库函数就是 IDF 编出来的，重写只会引入差异。
- **证据**：app descriptor `idf=v5.4.1`；模块分布（freertos 686 / esp_system 253 …）。
- **推翻条件**：P0 基线一致率 < 90% 且无法通过 `sdkconfig` 修正（说明 IDF 版本或编译器不同）。

## D2 表与常量脚本导出，不手抄

- **结论**：43 条命令表、27 项 opcode 跳表由 `tools/extract_tables.py` 从镜像直读生成 C。
- **理由**：表里是绝对地址（字符串指针、代码指针），手抄必错且无法复核。
- **证据**：生成的表与旧仓库 `官方固件命令协议.md` §3 逐条一致（含 `version` 的 `len=7 argc=3`）。
- **推翻条件**：表结构改变（例如换固件版本）。

## D3 handler 统一签名 `(buf, len, dev, entry, arg, arglen)`

- **结论**：所有 `cmd_*` 用这一签名，返回 `void`。
- **理由**：`cmd_dispatch` 的 `a10..a15` 传参 + `cmd_key_state` 里 `hid_key_state_read(dev)`、
  `entry->len` 的用法共同确证；跳表 `callx8` 不检查原型，签名不一致会让 T3 崩。
- **证据**：旧仓库 `reconstruction_patterns.md` §1（本轮修正版）。
- **推翻条件**：发现某个 handler 用到第 7 个参数（走栈），则该函数单独按栈传参写。

## D4 opcode 用函数指针表，不用 switch

- **结论**：`makcu_opcode_table[27]` + `makcu_lookup`，与原始 `jx` 跳表同构。
- **理由**：结构同构 → T3 相似度高；且新增/替换 handler 不需要改分发器。
- **证据**：`0x3C03DF08` 是 27 项绝对地址表。
- **推翻条件**：无。

## D5 `DAT_/PTR_` 一律转具名符号

- **结论**：反编译里的 `DAT_42000xxx` / `PTR_FUN_xxx` 不保留裸地址，改成 `extern` 变量或回调指针。
- **理由**：裸地址把链接器当运行时，换 IDF 版本或改布局即崩。
- **证据**：旧仓库 `macros`：`DAT_42000E04`（提交请求）、`DAT_42000E88`（滚轮增量）等已归类。
- **推翻条件**：仅当某地址确实是 ROM 常量/外设寄存器（此时写成 `#define` 或 `REG_*`）。

## D6 数学库首版用 newlib

- **结论**：`sin/cos/floor/scalbn` 直接用 newlib，不搬固件里的 fdlibm 副本。
- **理由**：算法同源（`__kernel_cos`/`__kernel_sin` 系数位级一致），行为差异在 1 ulp 量级。
- **证据**：旧仓库报告 §14.1 的系数比对。
- **推翻条件**：Bezier 路径的 T3 相似度掉到 70% 以下，或真机轨迹可测差异 → 切本地副本。

## D7 不做 OTA / secure boot

- **结论**：分区表照抄（无 OTA），eFuse 只读。
- **理由**：原厂就是单 app 分区；安全启动/加密位全关。
- **证据**：分区表实测（nvs/phy_init/factory/coredump/storage）+ eFuse 读取记录。
- **推翻条件**：需要在线升级时另立分区方案（属于产品需求变化，不是重建）。

## D8 新工程只读引用旧仓库

- **结论**：`AMagicBox-Rebuild` 不复制 `reversed/src`，只复制表数据与常量，且带来源注释。
- **理由**：证据（逆向结论）与实现（重建代码）分离；旧仓库可继续演进而不污染实现。
- **证据**：`tools/extract_tables.py` 从旧仓库读名字映射、从官方镜像读数据。
- **推翻条件**：旧仓库要冻结删除时，把 `docs/` 与 `work/asm` 的必要子集归档进本工程。

## D9 隐藏 opcode：只实现已实证部分，2026-11-09 起副作用也有实测

- **结论**：13 个隐藏 opcode（`0x08`、`0x0D`–`0x18`）实现"回包 + 副作用"，全部有板上证据；
  原厂侧"未被任何文本命令触发"这一点不变，仍按"外部不可达"处理。
- **理由**：这些 opcode 只经 `jx` 跳表入口，没有文本命令；不注入就没有 T2 证据，而猜语义会让
  T3 与 T2 同时失真。
- **证据（原）**：单字节帧实测全部无回应 → 外部不可达；`cmd_map_entry`/`cmd_serial`/`cmd_nop`
  有实测或逐指令证据。
- **证据（2026-11-09 补充，report run-16）**：
  - 回包：`mx.<op> <args>` 逐条记录（`0x08` 回显传入行、`0x11` 回 `<name>\n<digit>`、
    `0x17` 三标志不满足回 `"0"`，其余回显）；
  - 副作用（新增 `mx.dd` / `mx.dp` 台架探针后可见）：`0x15` 只写 `desc[+0x163+idx]`、
    `0x16` 只写 `desc[+0x63+idx]`（两表互不串）；`0x18` 在 `desc[+0x369+idx]==0` 时**回显但不写**，
    present 放行后写 `desc[+0x269+idx]` 并把 `0x3FC99FA3` 取反（开→0、关→1）；
  - 回归已固化：`verification/regress/test_hidden_opcodes.py` 的 4 条副作用断言。
- **仍然属推断**：原厂这 13 个入口在**真实调用序列**里的用途（例如 `0x17` 的第三组标志
  `desc[+0x636]` 在重建里没有任何写入者，`cmd_dump_channels` 的命中分支因此不可达）。
- **推翻条件**：拿到原厂侧调用栈（openocd 断点 + 真实右片流量）后再改；
  注意 openocd 的 `monitor halt` 在 ESP32-S3 上会做一次核复位，不适合"改内存→跑命令→再读"的观测。

## D10 17 个兜底函数不强行反编译

- **结论**：15 个 IDF 内部函数靠链接库解决；`cmd_silent`/`cmd_channel_toggle` 按文档骨架重写。
- **理由**：填充补丁实验证明失败原因是 Ghidra 缺构造器（报告 §14.4），继续折腾无收益。
- **证据**：`known_gaps.md` 的负结果段落。
- **推翻条件**：换用支持该指令的反汇编器（如新版 binutils/SLEIGH 模块）。

## D11 本机 IDF 是“裁剪版”（缺 6 个子模块）

- **结论**：`components/{mqtt,protobuf-c,unity,spiffs,mbedtls,openthread}` 的子模块通过 codeload 补入；
  `.gitmodules` 里对应的 6 条被删除，`git submodule` 不再是这些目录的来源。
- **理由**：`git submodule update` 在本网络对 github.com:443 超时；codeload 可用。
  这 6 个组件都不在 MAKCU 两个 app 的依赖闭包里。
- **证据**：构建两个 app 均通过；`build_app.ps1` 记录环境。
- **推翻条件**：需要 USB Host + TLS/OTA 等功能时，恢复 `.gitmodules` 并从 codeload 重新解包。

## D12 本机对 IDF 打了两处兼容补丁

1. `tools/cmake/gdbinit.cmake`：`ESP_ROM_ELF_DIR` 为空时不再调用两参数 `file(TO_CMAKE_PATH)`
   （CMake ≥3.31 拒绝该形式；`esp-rom-elfs` 工具未安装）。
2. 环境层面：`cmake`/`ninja` 来自 pip，`xtensa-esp-elf` 用目录联接指到
   `D:\Apply\toolchains\xtensa-esp-elf`（版本 14.2.0_20241119，与 IDF 预期一致）。

- **证据**：`tools/build_app.ps1` 里的变量；两处补丁均在仓库内可复现。
- **推翻条件**：能正常 `idf_tools.py install` 时，删掉这两处补丁恢复原状。

## D13 P0 采用两级门槛（严格哈希 → 模糊匹配）

- **结论**：先用“归一化指令哈希完全相等”作严格门槛，结果 7/816（0.9%）不达标；
  下一版改成“同尺寸桶 + difflib 相似度 ≥0.9”的模糊匹配，并把 op 序列存进指纹。
- **理由**：严格哈希对指令调度/字面量池位置极其敏感，`sdkconfig` 任何差异都会让它归零；
  模糊匹配才反映“同一段源码”。
- **证据**：`lib_fingerprint.py compare-elf` 的输出；`diff_insn.py` 在单函数上已可用（自比 1.000）。
- **推翻条件**：把 `sdkconfig` 调到与原始一致后严格哈希自然回升，则可直接用它。

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

## D16 回归夹具必须自己清零设备状态

- **结论**：`verification/regress/conftest.py` 的 `device_ready` 先发一组 `lock_*(0)`、
  `buttons(0)`、`left(0)…ms2(0)`，再开始断言。
- **理由**：CH343 的 DTR/RTS 只接在 CH343 自己，没接 S3 的 EN/IO0 —— 既不能进下载模式
  （`esptool` 实测 `Failed to connect`），也不能靠脉冲复位应用，RAM 状态会跨轮次保留。
- **证据**：第四批第一次在 CH343 上跑时，`.km.lock_mx()` 返回 `1`（上一轮 `lock_mx(1)`
  的残留），两条断言失败；加清零后同一轮全绿。
- **推翻条件**：换一块 EN/IO0 有接线的底板，或改用原生 USB 复位（那条能复位）。

## D17 隐藏 opcode 只用台架夹具验证，发布固件不带

- **结论**：`app_left` 支持 `-DMB_DEBUG_OPCODE=ON`，此时控制口额外接受
  `mx.<两位hex opcode> <参数>` 并直接调用对应 handler；默认 OFF。
- **理由**：0x0D–0x18 没有文本命令、外部不可达，不注入就没有 T2 证据。
- **证据**：第五批用该夹具跑通 10 条隐藏 opcode 用例（`verification/report/2026-11-09-flash-run-5.md`）。
- **推翻条件**：若最终固件保留该入口，必须把它并入正式的调试协议并重新做安全评估。

## D18 T3 只用于“重编译保真”，不用于“重写正确性”

- **结论**：T3 门槛只对 P0 的库代码与本地重建的 libm 副本生效；手写 handler 记录分数但不设门槛。
- **理由**：第五批 8 支键盘 handler 的相似度 0.07–0.60，低的几支完全是因为原实现把整个
  解析器内联（106 条）而我们调用共享解析器（9 条），语义其实一致且已由 T2 逐字节验证。
- **证据**：`tools/t3_report.py` 输出；报告 §4。
- **推翻条件**：如果要求“逐函数可替换的二进制等价”，那就得改成“按原样内联”的写法，成本另计。

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

## D21 免按键台架闭环：`mx.dl` + UART0 上的 ROM 加载器

- **结论**：烧录/回滚不再需要按键。`mx.dl`（`RTC_CNTL_FORCE_DOWNLOAD_BOOT` + `esp_restart`）
  把芯片送进 ROM 下载模式，ROM banner 打印 `boot:0x2 (DOWNLOAD(USB/UART0))`——加载器**同时监听
  UART0**，而 UART0 就挂在常插的 CH343 上，于是 `esptool --port <CH343> --before no_reset`
  可以直接烧写。（2026-11-09 实测 CH343 是 **COM3**，`COM8` 已变成蓝牙串口，见 HANDOVER §6.1。）
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

## D24 克隆的配置描述符必须严格 34 字节（HID 类块 9 字节）

- **结论**：`build_config()` 只能输出 `9 + 9 + 9 + 7 = 34`，`wTotalLength` 与实际字节数必须相等；
  HID 类块里 `bcdHID` 之后只能是 `country(1) + bNumDescriptors(1) + type(1) + len(2)`。
- **理由**：主机按 `bLength` 走链。多一个 `0x00` 时设备仍按 `wTotalLength` 发 34 字节，
  主机在偏移 27 读到 `bLength = 0`，端点描述符被截断，USBPORT 直接以
  `USBD_STATUS_INVALID_PARAMETER (0x80000300)` 拒绝 `URB_SELECT_CONFIGURATION`。
- **证据**：USBHUB3 事件 43 的描述符 dump + 事件 93/91（run-14 §2）；修复后同一台主机
  `Set Configuration → HID opened`，`mx.dv` 的 `mnt` 从 0 变 1，Windows 出现
  `HID-compliant mouse`。
- **推翻条件**：无（这是 USB 规范约束）。回归守门：`verification/model/test_clone_descriptor.py`。

## D25 克隆激活时报告遵循克隆描述符的 Report ID 约定

- **结论**：`makcu_clone_t` 增加 `report_id`；为 0 时用 `tud_hid_report(0, raw, len)` 发裸报告
  （按 `report_len` 补 AC-pan 字节），只有内置复合描述符才用 ID 1/2；克隆激活时不发键盘报告。
- **理由**：克隆来的鼠标描述符通常没有 Report ID 项，若仍按 ID 1 发送，主机解析会整体错位一字节。
- **证据**：`k_report_4b` / `k_report_5b`（fixture A/B）都不含 `0x85`(Report ID) 项。
- **推翻条件**：克隆描述符里确实带 Report ID 时，把 `report_id` 填成实际值即可。

## D26 调试构建与回归构建分离

- **结论**：`-DMB_TUSB_DEBUG` 只用于定位枚举问题，**不能**用来跑回归；回归一律用清洁构建。
  为了让这个开关真正生效，`app_left/main/CMakeLists.txt` 用 `target_compile_definitions`
  把宏补到 `espressif__tinyusb` 与 `makcu_hiddev` 两个目标上。
- **理由**：TinyUSB 的 `TU_LOG` 走 `printf` → UART0，与控制口同一根线；每个 HID 传输都会打
  `Queue EP 81 with N bytes`，回包里因此混入日志，`km.` 前缀断言全崩（run-14 一次踩到 13 例假失败）。
- **证据**：run-14 §4.2；同一份代码换清洁构建后 75 passed + 1 xpassed。
- **推翻条件**：把控制口与日志分到两个物理口（例如日志走 USB-Serial-JTAG，控制走 UART0）。

## D27 分步步数不受轨迹环上限约束，守恒用 `mx.rt` 断言

- **结论**：`run_move()` 的步数取 `ceil(span/127)`（int16 全量程最多 259 步），
  `MAKCU_REPORT_TRACE`(16) 只决定轨迹环保留多少条；曲线控制点每次移动只取一次。
- **理由**：原实现把步数上限卡在轨迹环大小，超过 16×127 = 2032 计数的移动会被静默截断，
  `mx.rq` 只留 16 条也看不出来；控制点若每个采样点重抽，路径是抖动而不是弯曲。
- **证据**：`mx.rt` 前后差——`.km.move(10,0)` → +10，`.km.move(-30000,20000)` →
  -30000/+20000（run-14 §4.2）。
- **推翻条件**：无。

## D28 `0xA0` 是会话握手、`0xA2` 是上报透传（不是描述符通道）

- **结论**：`0xA0` 只做 EP0 会话的开始/结束（`len==1 && payload[0]==0x00` 开始，
  `0xFF` 或空负载结束，其它方向忽略）；`0xA2` 是 HID 上报透传，`payload=[ep,id,len,0,data…]`，
  左片按“会话 id 先到先得 + 长度非零”过滤后，把 `data` 原样交给上报写入端。
- **理由**：原先把 `0xA2` 猜成“描述符数据、要装进克隆仓库”，与反编译不符；按猜测实现会让
  D9 的“不实现未证实语义”失效，也会把透传通路堵死。
- **证据**：`reversed/src/left/idf_freertos/42013734_uart1_frame_parse.c`（pending 标志 +
  两条分支）与 `reversed/docs/uart1_link.md` §8；真机：`mx.ef` 0→1→0、`mx.ls` 的
  `ep0_starts/ends` 计数、`mx.ei` 回显注入字节；HID 构建下注入 4 字节报告让主机光标
  移动 +22px（report run-17 §3）。
- **仍然开着的**：① 端点字节在 `payload[4]` 还是 `payload[8]`（反编译比的是 `hdr[8]`，
  当前不做严过滤）；② EP0 **数据**注入需要 TinyUSB vendor 钩子，现在只有握手；
  ③ 右片 `0xA2` 发送端（`app_right`）未移植，两片真闭环还差这一步。
- **推翻条件**：逻辑分析仪抓到右片真实 `0xA2` 流量，或右片移植后联调出现不一致。

## D29 右片的应答构造抽成可移植组件，用左片交叉验证

- **结论**：`frame_forward`（`0x4200F6C4`）的应答字节放在 `components/makcu_right`
  （纯 C，只有 `makcu_link.h` 依赖），`app_right` 与左片夹具 `mx.rf` 都调用它。
- **理由**：本机只有一块板、且控制口在左片的 CH343 上，`app_right` 烧不进去；
  若把应答逻辑留在 `app_right/main` 里，就只能靠代码评审，无法在硬件上验证字节。
- **证据**：`mx.rf` 八种输入在板上打印的应答（`5aa00100ff` / `5aa3010000` / `5ab10000` …），
  以及 `verification/regress/test_right_frames.py` 9 例 + `verification/model/test_right_reply_model.py` 8 例。
- **顺带**：`app_right` 必须用 `set(COMPONENTS ...)` 白名单——`components/` 目录被两个 app 共享，
  而 `makcu_hiddev` 要求托管组件 `espressif__tinyusb`（只装在 `app_left`），
  不加白名单时 cmake 会在右片工程里报 “component 'espressif__tinyusb' could not be found”。
- **推翻条件**：右片可以独立烧写后，把 `mx.rf` 的交叉验证换成“两片联调直测”。

## D30 UART1 链路参数取自两份原厂镜像（引脚 + 5 Mbaud）

- **结论**：片间链路 左 TX=GPIO2 / RX=GPIO1，右 TX=GPIO1 / RX=GPIO2（交叉），**5,000,000 8N1**。
  左片 `components/makcu_link/include/makcu_link_bridge.h` 的默认值与 `app_right` 的
  `LINK_BAUD/LINK_TX/LINK_RX` 都已改成这组数，仍可用 `-DMAKCU_LINK_*` 覆盖。
- **理由**：之前是占位 17/18 + 921600，两个数都是猜的——自环能过（自己发自己收），
  但与右片永远通不了，这也解释了为什么“桥接已完成”却从未有过真实两片流量。
- **证据**：
  - 左 `uart_event_task`（0x420139E4）：`uart_set_pin(1, *0x42001254, *0x42001250, UART_PIN_NO_CHANGE)`，
    两个指针解出 2 与 1（TX=2、RX=1）；
  - 右 `FUN_4200F644`：`uart_set_pin(1, 1, 2, UART_PIN_NO_CHANGE)`（TX=1、RX=2，与左交叉）；
  - 波特率：左配置结构首字 `DAT_4200124C = 0x004C4B40` = 5,000,000；该常量在两份镜像里各出现一次。
- **副作用**：`uart_set_pin()` 不再用 `ESP_ERROR_CHECK`（引脚是板级接线，不是编程错误），
  失败只告警，控制台仍可用。
- **推翻条件**：逻辑分析仪实测这两根线（或板级接线图）与此不符时改回；换板/换版本必须重读常量。

## D31 透传注入：字节序 + 发送时机 + 门闸宣告（2026-11-09，已实测）

1. **报告字节序**：`makcu_report_t` 是 `{dx, dy, wheel, buttons}`，与 HID 描述符顺序
   `{buttons, x, y, wheel}` **不同**。注入时必须显式组包，绝不能整结构体直发
   （旧实现由此导致"报告到了主机但光标不动"，卡了三轮）。
2. **发送时机**：只在 `tud_hid_report_complete_cb()` 里补发下一条（端点刚释放）。
   `tud_hid_n_report()` 的 claim 在 `usbd_edpt_xfer()` 失败时不释放，且
   `tud_hid_busy()` 仍为 0 → 从别处抢发会造成永久泄漏（实测成功率 0.8%）。
3. **门闸宣告**：右片只在 `*DAT_42000d48 != 0` 时转发 `0xA2`，该标志由左片的
   `0xA3` 置位、设备掉线时清 0 → 左片必须上电宣告 + 周期补发（现为 2 s）。
4. **Windows 侧**：该 HID 设备默认被选择性挂起限流，会造成主机轮询间隔达上百毫秒；
   台架已全局与设备级关闭，现场部署时需一并处理。

## D32 透传报告格式与速度保真（2026-11-09，已实测）

1. **这颗鼠标发 12 位打包报告**，不是 8 位：
   ```
   byte0 = buttons
   byte1 = x[7:0]
   byte2 = x[11:8] | (y[3:0] << 4)
   byte3 = y[11:4]
   byte4 = wheel
   ```
   把 byte2 当 8 位 y 会让 y 正好放大 16 倍（实测逐条吻合），x 只读低字节则偏慢。
2. **12 位 → 8 位必须带余量**：超出 int8 的部分进残差，下一条补发，避免快速甩动丢距离。
3. **必须逐条转发，禁止攒包**：Windows 指针加速按单条报告的位移量分档，
   攒包会直接跳到高加速档，表现为"光标比手快"。只有端点忙时才允许走累加器。
4. 台架可用 `mx.du` 校验解码、`mx.fs` 标定分频、`mx.ss` 钉会话、`mx.hk` 隔离开关。

## D33 按键/滚轮字段 + 探针解析必须带长度（2026-11-09，已实测）

1. 12 位打包报告里 **`byte0` = 按钮字节、`byte4` = 滚轮**，与位移同一条路径转发；
   实测：6 次点击产生 12 条按键事件，滚轮方向与格数在 PC 上正确。
2. **自研文本协议的所有参数解析都必须以 `len` 为界**：命令缓冲区不保证 NUL 结尾，
   越界解析会把残留字节吃进数字（`mx.fs` 曾因此恒回 `8`，被 clamp 掩盖）。

## D34 克隆真实鼠标身份 + 12 位原字节直送（2026-11-09，已实测）

1. **原厂固件克隆的是"右片所接鼠标的身份"**：工厂固件运行时 PC 上出现 `30FA:0302`
   "USB Optical Mouse"，与把该鼠标直接插 PC 读到的一致 → 克隆目标由设备决定，不是固定值。
2. 12 位打包报告对应的描述符（5 键 + 3 填充 + X12 + Y12 + 滚轮8 = 5 字节）已重建，
   与链路实测字节逐位吻合，落在夹具 `MAKCU_CLONE_FIXTURE_REAL`（`30FA:0302`）。
3. **夹具与链路同构时必须原字节直送**（`makcu_hiddev_report_verbatim()`）：
   再做 12→8 转换只会丢精度。判断依据 `makcu_clone_wants_raw_report()`。
4. 构建默认改为 `-DMB_CLONE_FIXTURE=3`；台架可用 `mx.cl 1..3` 切换。
5. **已验证**：夹具 3 + 原字节直送下光标跟手、速度正常、按键滚轮正常
   （`hs 25870 ok / 0 failed`）。首次试跑失败是链路层 `hid=0`（右片未转发），
   与描述符无关；判断顺序必须是"先看 `hid`，再怀疑描述符"。
6. 本地判定主机是否接受某格式：`mx.ss 33` → `mx.lf a2 02330500 0010000000`（x=+16）
   → 光标应移动 ~14–16 px → `mx.ss 00` 复位（钉会话期间真实帧会被丢弃）。

## D35 `0xA1` = EP0 隧道，克隆身份应运行时读取（2026-11-09，已实测）

1. 右片 `frame_forward`：`0xA1`（载荷 ≥ 8 字节）走 EP0 隧道 —— 左片可以把一条 USB 控制请求
   发给真实鼠标并读回数据（`FUN_4200FC74` → `FUN_4200FC00` → `usb_xfer_submit`）。
2. 用 `mx.ln a1 <8 字节 setup 包>` 即可读设备/配置/报告描述符与字符串：
   `mx.ln a1 800600010000001200`、`800600020000002200`、`800600220000004000`。
3. 真实鼠标（30FA:0302）的报告是 **3 键 + 5 填充 + X12 + Y12 + 滚轮8**，
   逻辑下限 **-2048**，端点 **MPS=5 / bInterval=1**；夹具 REAL 已按读回字节逐字节固化。
4. **接收缓冲 `MAKCU_LINK_INJECT_MAX` 必须 ≥ 最大描述符长度**（曾因 32 把 64 字节报告
   描述符截半，误判为"设备只回一半"）。现为 64。

### D35 补充：自动克隆已实现（同一日）

`MB_CLONE_FIXTURE=99` 时上电先 `0xA0` 探测 → `0xA1` 读设备/配置/报告描述符与字符串 →
`makcu_clone_adopt()` → 再初始化 USB，失败回退到逐字节夹具。探针 `mx.as`（0/1/2）与
`mx.ac`（手动触发）可观测。踩到的坑：`0xA0` 探测即会话开始，必须成对关闭（含失败分支）；
`MAKCU_LINK_INJECT_MAX` 必须 ≥ 最大描述符长度。

## D36 复合设备（多 HID 接口）克隆：读取已通，枚举未通（2026-11-10）

1. **不是"每个鼠标一套配置"**：同一份固件靠自动克隆适配不同鼠标；差异在设备自己的报告格式
   （测试鼠标 12 位/5 字节，G3M PRO 16 位/7 字节、且是**两个 HID 接口的复合设备**）。
2. **报告描述符必须用 `bmRequestType=0x81`（接口接收者）** 请求；`0x80` 对单接口设备可以，
   对复合设备一律错误帧。
3. 复合设备按"找出鼠标接口 → 读出其报告描述符 → 裁剪成单接口配置"处理，隧道单帧上限需 ≥ 158 B
   （现为 192）。
4. **未解决**：裁剪出的单接口克隆在 Windows 上 `CM_PROB_FAILED_START`（`mnt=0`）。
   下一步用 USBPcap 抓一次失败枚举；重点怀疑 93 B 报告描述符里的 Feature 报告
   （`95 40 75 08 B1 02`）需要 `tud_hid_get_report_cb`，以及真正的多接口克隆
   （`CFG_TUD_HID=2` + 原样转发 66 B 配置 + 按 `0xA2` 的 `ep` 路由）。
5. 默认构建回到单接口夹具（`MB_CLONE_FIXTURE=3`），复合克隆代码保留在 `=99` 分支。

## D37 复合设备克隆：抓包定位的两个 bug 与遗留问题（2026-11-10）

1. **接口必须“命中即停”**：自动克隆遍历配置时，一旦某接口的报告描述符被判为鼠标，必须
   记住该接口偏移并 `break`；否则配置与报告描述符会来自不同接口，长度自相矛盾，主机报
   `CM_PROB_FAILED_START`（抓包可见 `GET_DESCRIPTOR(Report)` 声明的长度与实际返回不符）。
2. **直送必须按实际报告长度**（G3M 7 字节、30FA 5 字节），写死 5 会丢滚轮/pan。
3. **判“主机取没取走”用 `tud_hid_report_complete_cb` 计数**（探针 `mx.hq`）：
   `hs`（发送被接受）与 `hq`（传输完成）相等，才说明主机真的收了。
4. **根因（已解）**：`makcu_clone_wants_raw_report()` 判据当时只认内置 12 位夹具
   （`report_len == sizeof(k_report_12b)`），于是自动克隆出来的 G3M（93 字节描述符/7 字节报告）
   走了 int8 路径、发 4 字节报告，主机按 7 字节解析就丢弃。抓包里"我们的设备在发 4 字节"
   是决定性证据。判据已改为 `from_device || 内置夹具`，并在 `makcu_clone_adopt()` 置位。
   修复后注入 7 字节报告 X=+100 → 光标 Δx=151 ✓。
5. USBPcap 是类过滤驱动，**装完必须重启**才会挂到已有根集线器；抓包用
   `USBPcapCMD -d \\.\USBPcapN -A -o file.pcap`，分析用 `tshark -r file.pcap -V`。

## D38 双接口克隆首次尝试的失败模式（2026-11-10，已回退）

1. 侧键/宏确认走 **MI_01 的键盘报告**（`0x82`，8 字节，byte2/3 = keycode）与
   `0x81` 上的 **37 字节**厂商报告，不在 7 字节鼠标报告里。
2. 按 `CFG_TUD_HID=2` + 原样 66 字节配置 + `ep` 路由后，枚举正确（MI_00 鼠标 + MI_01 键盘/4 集合），
   但 `tud_hid_n_ready(0)` 几乎恒假（`hq 86 / injected 15258`）——**实例↔端点绑定不能用"描述符顺序"猜**。
3. 回退不彻底导致该 VID/PID/序列号族在主机侧留下失败态（`CM_PROB_FAILED_START`，换序列号也不解），
   最终换回夹具 1（`046D:C077`）恢复。
4. 下次要求：先探清实例↔EP 映射；用独立身份做实验；一次只加一个变量；失败要完整回退。

## D39 报告格式与身份解耦（夹具 4，2026-11-10，已实测）

1. 任意鼠标的**报告描述符**可以由一个**枚举稳定的身份**承载：夹具 4 = `046D:C077` +
   G3M PRO 的 93 字节报告描述符 + 7 字节原字节直送 → 实测注入 `X=+100` 光标 `Δx=110`、
   `hs 2750 ok / 0 failed`，用户确认速度正常。
2. 含义：**位移/按键/滚轮的正确性只取决于报告描述符与转发长度**，与 VID/PID 无关；
   只有在需要"像同一颗鼠标"时身份才重要（而 320F 族在本机曾被反复枚举挂死）。
3. 自动克隆（运行时读描述符）作为增强项单独推进，排障与交付优先用夹具锁定报告格式。
4. 台架：`mx.cl 1|2|3|4`（4 = G3M 报告布局）；回归新增 `test_fixture_g3m_report_layout`。

## D40 侧键走"标准鼠标键"路线（2026-11-10，已实测）

1. HECATE Connect 把侧键映射为 **鼠标4/鼠标5**（赋值码 `0x100800`/`0x101000`）后，
   侧键出现在 **MI_00 的 7 字节鼠标报告** byte0 的 bit3/bit4 → **单接口克隆即可透传**。
2. 实测：抓包 byte0 出现 `0x08`/`0x10`；盒子上 `mx.bo = 0x1B`，用户确认侧键正常。
3. 因此"完全透传"的优先级重排：先让用户在管理程序里把想要的键映射为**鼠标键**
   （零固件成本），只有必须保留**宏/键盘输出**时才做 MI_01 多接口克隆。
4. 代价：映射为鼠标键后该键上的宏失效。
