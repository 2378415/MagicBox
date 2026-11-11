# 00-facts：事实基线（都带来源，不含推断）

## 1. 镜像与身份

| 项 | LEFT（V3.2） | RIGHT（V3.7） | 来源 |
|---|---|---|---|
| 文件 | `官方固件/V3.2_LEFT.bin` 403,536 B | `官方固件/V3.7_RIGHT.bin` 341,824 B | 文件 |
| app 版本串 | `1` | `7d19c5c-dirty` | app descriptor @0x10020 |
| 工程名 | `project-name` | `project-name` | 同上 |
| 编译时间 | `May  4 2025 15:00:57` | `Sep  1 2025 06:15:45` | 同上 |
| IDF 版本 | `v5.4.1` | `v5.4.1-dirty` | 同上 |
| 芯片 | ESP32-S3（Xtensa LX7） | 同 | 段布局 + eFuse 记录 |

app descriptor 结构（两片一致）：`magic=0xABCD5432`，之后 `version[32] project[32] time[16] date[16] idf_ver[32]`。

## 2. 分区表（LEFT，实测自 4MB 回读）

`work/hw_left_readback.bin` 偏移 0x8000：

| 名称 | 类型 | 偏移 | 大小 |
|---|---|---|---|
| `nvs` | data/nvs (0x01/0x02) | 0x009000 | 24K |
| `phy_init` | data/phy (0x01/0x01) | 0x00F000 | 4K |
| `factory` | app/factory (0x00/0x00) | 0x010000 | 1024K |
| `coredump` | data/coredump (0x01/0x03) | 0x110000 | 64K |
| `storage` | data/nvs (0x01/0x02) | 0x120000 | 128K |

- **无 OTA 分区**；`storage` 是第二个 NVS 分区（对应固件里 `storage/config/baud_rate` 键）。
- RIGHT 侧分区表未采集（只回读了前 128KB），标为待测（P0）。

## 3. 代码规模（旧仓库 `reversed/`）

| 指标 | 值 |
|---|---|
| 函数 | 3072（LEFT 1443 / RIGHT 1629；含 3 个手工重建的跳表专用入口） |
| 仍用汇编兜底 | 17（15 个 IDF 内部 + `cmd_silent`、`cmd_channel_toggle`） |
| 语义命名 | 121 |
| 模块分布 | LEFT：freertos 686 / esp_system 253 / gpio 135 / nvs 119 / uart 85 / spi 26 / heap 28 / usb 10 / protocol 36 / mouse 18 / keyboard 11 / hid 4 / uart 16 / crash 4 / led 1 / efuse 1 |
| | RIGHT：freertos 610 / esp_system 499 / heap 290 / spi 84 / usb 67 / uart 55 / hid 23 / newlib 1 |

## 4. 已确证的数据结构（LEFT）

| 地址/偏移 | 内容 | 证据 |
|---|---|---|
| 命令表 `0x3C03DF74` | 43 × 20 B：`name,len,argc,target,opcode` | `tools/extract_tables.py` 与协议文档逐条一致 |
| opcode 跳表 `0x3C03DF08` | 27 项绝对地址（0x00–0x1A） | 同上 |
| `dev+0x210` | 通道子表（`+0x54` 按键槽 / `+0x9C` 轴向槽 / `+0x168` catch 槽） | `lock_set`/`axis_slot_set`/`catch_set` |
| `dev+0x214` | 描述符/大表基址（`+0x269` 启用位、`+0x369` 存在位、`+0x636` 标志） | `cmd_channel_toggle`/`cmd_dump_channels` |
| `0x3FC99FA3` | 「需要重发」全局标志 | `cmd_channel_toggle` 写 |
| 跳表专用入口 | `0x4200E624` `cmd_map_entry`、`0x4200DC84` `cmd_serial`、`0x4200DBA0` `cmd_nop` | 手工重建 + 实测 `.km.serial()` |

## 5. 已实测的行为

| 项 | 结果 | 来源 |
|---|---|---|
| 文本帧 | `'.' + km.xxx` + `\r`，115200 8N1 | `dynamic_tests.md` |
| 回执封装 | `"km." + 内容 + "\r\n>>> "` | `uart0_reply` 反编译 + `.km.serial()` 实测 |
| `<2` 参数的 `silent(` | 零回包 | `dynamic_tests.md` §10 |
| `.km.serial()` | `km.Mouse does not have a serial number\n\r\n>>> ` | 实测 §11 |
| 单字节帧（`0x08`/`0x0D–0x18`/`0xA1`/`0xA2`/`0xA4`） | 全部无回应（判为不完整帧丢弃） | 实测 |
| UART1 帧 | `5A <cmd> <len:u16> <payload>`，总长 = 字段 + 4 | `uart1_link.md` §8 |
| UART1 接线 | 左 TX=**GPIO2** / RX=**GPIO1**；右 TX=**GPIO1** / RX=**GPIO2**（交叉）；**5,000,000 8N1** | 左 `uart_event_task` 0x420139E4 的 `uart_set_pin(1,*0x42001254,*0x42001250)` （解出 2/1）与右 `FUN_4200F644` 的 `uart_set_pin(1,1,2)`；波特率取左配置字 `DAT_4200124C`=5000000 |

## 6. 环境

| 项 | 值 |
|---|---|
| 工具链 | `xtensa-esp-elf 14.2.0`：`D:\esp-tools\tools\xtensa-esp-elf\esp-14.2.0_20241119`（旧台架机器在 `D:\Apply\toolchains`，`tools/*.py` 两处都会自动探测） |
| Ghidra | 12.2（`D:\Apply\Ghidra`，需 JDK 21；`ghidra-projects/makcu.gpr`） |
| ESP-IDF | v5.4.1（`D:\esp-idf`，gitee 镜像 + codeload 子模块） |
| 调试器 | `openocd-esp32 0.12.0` + `xtensa-esp-elf-gdb 14.2`；内置 USB-JTAG 实测可用（仅控制台构建，tap `0x120034e5`） |
| 控制口 | CH343，运行期 115200（2026-11-09 实测为 **COM3**） |
