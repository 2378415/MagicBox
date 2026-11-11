# 整改方案：身份 100% 自动克隆（去掉编译期 VID/PID 强制）

> 现状：`-DMB_FORCE_VIDPID=320f706e` 把 VID/PID 钉死，其余（配置 66B、两个报告描述符、厂商/产品字符串）已自动克隆。
> 目标：**去掉这个钉子**，身份完全来自鼠标，且开机自动克隆稳定成功。

---

## 1. 验收标准（先定义"改好了"）

| # | 判据 | 命令/证据 |
|---|---|---|
| V1 | 不带 `-DMB_FORCE_VIDPID` 构建，**连续 3 次冷启动**自动克隆成功 | `mx.as` 每次都是 `1` |
| V2 | 克隆出的 VID/PID == 鼠标真实值 == 右片 host 栈本地读到的值 | `mx.dv` 的 `dev[8..11]` == `mx.ln 1c` 的 vid/pid |
| V3 | 描述符来源可追溯、两次读取一致 | 新探针 `mx.vf` 显示 `mismatch=0` |
| V4 | 两个接口与报告描述符长度正确 | `mx.if` = `2 93:81:0 158:82:1` |
| V5 | HECATE Connect 正常识别（不需要任何人为补偿） | 打开即显示电量 |
| V6 | 回归不退化 | `pytest verification/regress` 100 passed |

---

## 2. 根因分析（为什么现在看起来"身份会变"）

实测抓到的异常值与正解差的是**单比特**：

| 读取值 | 正解 | 差异 |
|---|---|---|
| `0E8C:F0DB` | `320F:706E` | 多字节同时错 |
| `0ECC:F0DF` | `320F:706E` | 与上一次只差 bit6 / bit2 |

单比特级别的漂移**不可能是鼠标换身份**（同一只鼠标不会在两分钟内变 VID），是**读取被污染**。候选来源，按可能性排序：

1. **EP0 隧道的缓冲区与 1 kHz IN 传输共用内存池**
   `makcu_hidhost_control()` 每次 `usb_host_transfer_alloc(8+wLength)`，与报告流的 `IN_BUFFER_SIZE` 同源分配。
   描述符读发生在鼠标刚枚举、报告流刚起来的瞬间，缓冲可能被后续 IN 完成覆盖 → 读到半新半旧的数据。
2. **读取时机太早**：`0x1A` 显示 attached 后立刻读，设备内部描述符缓存可能还在刷新。
3. 隧道回帧解析错位（但错位会表现为整段偏移，与观察到的单比特不符，排除）

结论：**问题在传输时序/缓冲竞争，不在设备**。所以修的方向是"用更可信的来源 + 校验重试"，而不是继续钉死。

---

## 3. 方案 A（推荐终态）：描述符由右片本地读，链路新 opcode

### 3.1 依据
右片**已经**在 attach 时用 IDF host 栈读到权威副本（`makcu_hidhost.c` L110/L117）：

```c
usb_host_get_device_descriptor(dev, &ddesc);      // 18 字节，权威
usb_host_get_active_config_descriptor(dev, &cdesc); // wTotalLength 字节，权威
```

目前只用来解析接口，**没有对外暴露**。把它暴露出来，左片就不必再通过 control 隧道读这两份东西。

### 3.2 改动

| 文件 | 改动 |
|---|---|
| `components/makcu_hidhost/include/makcu_hidhost.h` | 新增 `int makcu_hidhost_raw_device(uint8_t out[18]);`、`int makcu_hidhost_raw_config(uint8_t *out, size_t cap);` |
| `components/makcu_hidhost/src/makcu_hidhost.c` | attach 时把 `ddesc`（18B）与 `cdesc` 的 `wTotalLength` 字节**复制进静态缓冲**；两个新 API 直接返回（不经过 USB） |
| `app_right/main/app_main.c` | 新 opcode：`0x1B` → 18 字节设备描述符（无设备回 `FF`）；`0x1D <offset:u16> <len:u8>` → 配置描述符的分片（避免单帧过大，`MAKCU_LINK_MAX_FIELD` 足够但分片更稳） |
| `app_left/main/app_main.c` | `autoclone_from_link()`：优先 `0x1B`/`0x1D` 取 device/config；**失败回退**现有 `0xA1` 隧道。报告描述符仍需 `0xA1`（IDF 不缓存 HID 报告描述符），但**长度以配置里 HID 描述符的 `wDescriptorLength` 为准**，读回长度不符则重试 |
| `app_left/CMakeLists.txt` + `main/CMakeLists.txt` | `MB_FORCE_VIDPID` 默认置空（保留为可选兜底）；文档标注"正常不需要" |

### 3.3 为什么这样最稳
- 描述符来自**右片 host 栈的解析结果**，不经过任何自定义隧道，没有缓冲区竞争；
- 报告描述符的长度由配置描述符自校验（`wDescriptorLength`），读错立刻能发现并重试；
- 保留 `0xA1` 回退路径，老固件/老右片不会失配。

---

## 4. 方案 B（先做这个，低改动、不刷右片）：隧道读加固

只改左片，30–60 分钟可验证是否为"够用的修复"。

| 改动 | 内容 |
|---|---|
| `tunnel_get_checked()` | 新增：读两次比对，不一致重试；最多 3 次；任一次成功即用 |
| 设备描述符校验 | `bLength==18`、`bDescriptorType==1`、`bMaxPacketSize0 ∈ {8,16,32,64}`、`bNumConfigurations>=1` |
| 配置描述符校验 | 返回长度 == `wTotalLength`；遍历描述符链自洽（`bLength>=2`、总长不越界、接口 `bNumEndpoints` 与实测端点数量一致）|
| 报告描述符校验 | 长度 == 对应接口 HID 描述符的 `wDescriptorLength`；不符重试 3 次，仍不符则该接口标记 invalid |
| 新探针 `mx.vf` | `dev_reads,dev_mismatch,cfg_reads,cfg_mismatch,rep_len_ok,rep_len_bad` |

B 做完就能回答一个关键问题：**异常读到底有多频繁**。若 `mismatch` 恒为 0，说明加固已足够，A 可作为后续优化；若仍有 mismatch，直接上 A。

---

## 5. 两方案对比

| | A（右片本地读） | B（隧道加固） |
|---|---|---|
| 改动面 | 右片 + 左片 | 仅左片 |
| 可靠性 | ★★★★★（绕过隧道） | ★★★★（靠重试+校验） |
| 是否要换线刷右片 | 是（1 次） | 否 |
| 向后兼容 | 保留 `0xA1` 回退 | 不变 |
| 估时 | 3–4 h（含刷写与 3 次冷启动验证） | 1–1.5 h |

**建议顺序：先 B，用 `mx.vf` 拿数据；若 mismatch > 0 或 V1 不稳定，再做 A。** 两者不冲突，A 可以建立在 B 的校验框架上（校验代码复用）。

---

## 6. 顺带要修的两处（都属于"去掉人为固定"的一部分）

### 6.1 `mx.vp` 的覆盖值要能持久（NVS）
现状：`mx.vp` 存在 RTC，**刷写即清**，而且旧固件布局的残留值还会被误当覆盖值（今天就踩了）。
改为存 **NVS**（`makcu_clone` 命名空间，键 `vid_ovr/pid_ovr`），并加 `mx.vp clear` 清除。
这样"现场兜底"是可选的、显式的，而不是默认行为。

### 6.2 序列号策略
这个鼠标**没有序列号**，我们现在填 `0000000000B1`。可选改进：用鼠标的 `iSerialNumber` 索引是否有效 + VID/PID + 配置 CRC 派生一个稳定串（如 `MB<vid><pid><crc16>`），
好处是换鼠标后 PC 侧是**新的实例**（不会复用旧缓存），坏处是每次克隆改变都会换实例。
建议：**默认保持 `0000000000B1`**（稳定、可预期），派生方案作为可选项，不做默认。

---

## 7. 改动清单（可直接照着改）

### B（第一步）
1. `app_left/main/app_main.c`
   - 新增 `static int tunnel_get_checked(uint8_t type, uint8_t index, uint16_t value, uint16_t length, uint8_t *out, size_t cap, int tries);`
   - `autoclone_from_link()` 三处调用改为 `_checked`，并加字段校验函数 `validate_device_desc()` / `validate_config_desc()` / `validate_report_len()`
   - 新增探针 `mx.vf`
2. `verification/regress/test_autoclone_validation.py`（新增）
   - 喂入被污染的 device/config 描述符样本（含今天真实抓到的 `0E8C:F0DB`），断言 `validate_*` 拒绝
   - 断言 `wDescriptorLength` 与报告描述符长度不一致时被拒
3. `docs/30-decisions.md` 新增 D42（"身份不再强制，改用校验+重试"）

### A（第二步，若需要）
4. `components/makcu_hidhost/include/makcu_hidhost.h`：`raw_device` / `raw_config`
5. `components/makcu_hidhost/src/makcu_hidhost.c`：attach 时缓存两份描述符
6. `app_right/main/app_main.c`：`0x1B`（device，18B）、`0x1D`（config 分片）
7. `app_left/main/app_main.c`：优先新 opcode，回退 `0xA1`
8. `docs/30-decisions.md` D42 补充；`docs/HANDOVER.md` 14.7 第 1 条改为"默认不强制"

---

## 8. 验收流程（照做即可）

```powershell
# 1) 不带强制身份构建（注意：没有 -DMB_FORCE_VIDPID）
powershell -File tools\build_app.ps1 -App app_left -Define `
  "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON"
powershell -File tools\flash_capture.ps1 -Port COM3 -Seconds 6

# 2) 冷启动 3 次（每次断电重开或 mx.rs 后等待 10 s）
mx.as      # 期望 1
mx.vf      # 期望 mismatch=0
mx.dv      # 期望 VID/PID == 鼠标真实值
mx.if      # 期望 2 93:81:0 158:82:1
mx.ln 1c   # 期望 vid/pid 与 mx.dv 一致

# 3) 打开 HECATE Connect，确认显示电量；改一次 DPI 确认生效
# 4) 回归
pytest verification\regress -q
```

---

## 9. 风险与回滚

| 风险 | 影响 | 处置 |
|---|---|---|
| 去掉强制后某只鼠标报非 `320F` 身份 | HECATE Connect 不认（忠实克隆的必然代价） | 现场用 `mx.vp <vidpid>` 临时覆盖（改为 NVS 持久）+ `mx.rs` |
| 隧道加固后仍偶发 mismatch | 开机克隆偶发失败 | 走方案 A |
| 改右片后右片异常 | 鼠标不动 | `tools\flash_right.ps1` 刷回出厂镜像（默认行为） |

回滚粒度：左片单次刷写即可回退；右片保留 bootloader 区不动（`work/right_boot_head.bin`），只刷 app 分区（`-Offset 0x10000`）。


---

# 执行记录（2026-11-10）：方案 A 已落地

## 做了什么

| 层 | 改动 |
|---|---|
| `components/makcu_hidhost` | attach 时把 IDF host 栈看到的**设备描述符(18B)**与**活动配置描述符(wTotalLength)**快照到静态缓冲；新增 `makcu_hidhost_raw_device()` / `makcu_hidhost_raw_config()`；detach 时清零 |
| `app_right` | 新 opcode：`0x1B` → 18 字节设备描述符（无设备回 `FF`）；`0x1D <off:u16><len:u8>` → 配置描述符分片，回 `<total:u16><off:u16><data…>`（可检出短读并重取） |
| `app_left` | `raw_device_get()` / `raw_config_get()` 优先用新 opcode（含 `bLength/bDescriptorType/wTotalLength/偏移回显` 校验），**失败回退** `0xA1` 隧道；新增探针 `mx.vs`（`1`=右片本地 / `2`=隧道 / `0`=失败） |
| `makcu_clone` | VID/PID 覆盖改为**NVS 持久化**（`makcu_clone_identity_override_load/save`），启动时在 autoclone 之前加载；`mx.vp clear` 清除 |
| 构建 | `MB_FORCE_VIDPID` **默认空**（缓存也需显式置空：`-DMB_FORCE_VIDPID=`） |

## 验收结果

| 判据 | 结果 |
|---|---|
| V1 无强制构建、开机自动克隆 | ✅ `as=1`（多次） |
| V2 克隆身份 == 右片本地读 | ✅ `mx.ac` == `mx.dv` == 本地读 |
| V3 描述符来源可追溯 | ✅ `mx.vs = 1,1`（右片本地，不再走隧道） |
| V4 接口与报告描述符 | ✅ `mx.if = 2 93:81:0 158:82:1` |
| 回归 | ✅ 100 passed / 0 failed |
| 厂商通道确认率 | ✅ `mx.ox = out=53, ok=53`（100%） |

## 重要发现：dongle 的身份本来就会变

实测盒子后端设备在两种接入方式下身份不同：

| 接入 | VID:PID | 备注 |
|---|---|---|
| 鼠标自带数据线（有线/充电） | `320F:706E` | PC 上 HECATE 的 INF 认这个 |
| **2.4G 接收器（dongle）** | `0E8C:F0DA`（还观测到 `F0DB`/`F0DF`，PID 低位会漂） | 无匹配 INF；PID 漂移会让 PC 反复新建实例 |

所以"忠实克隆"和"管理程序能识别"在 dongle 场景下**天然冲突**（这是设备侧事实，不是固件缺陷）。处置：

- 需要 HECATE 管理时：`mx.vp 320f706e`（一次性，写 NVS，**跨刷写保留**），要恢复忠实克隆用 `mx.vp clear`；
- 不需要管理程序时：什么都不做，克隆自动跟随 dongle 的真实身份（`force=0000`，`ovr=0000`）。


---

# 更正（2026-11-10）：dongle 身份并不漂移，此前的判断是错的

## 之前写错的结论
> "dongle 上报 `0E8C:F0DA`，PID 还会漂" —— **错**。

## 抓包实测（dongle 直插 PC）

```
GET_DESCRIPTOR(device) 回：
12 01 00 02 00 00 00 08 0f 32 6e 70 00 01 01 02 00 01
bMaxPacketSize0 = 0x08, VID = 0x320F, PID = 0x706E,
bcdDevice = 0x0100, iSerialNumber = 0, bNumConfigurations = 1
```

## 盒子侧本地读（`mx.ln 1b 00`，右片 host 栈）

```
12 01 00 02 00 00 00 08 0f 32 6e 70 00 01 01 02 00 01      ← 逐字节相同
```

结论：**设备就是 `320F:706E`，不存在身份漂移**。之前读到的 `0E8C:F0DA`
是"刚刷完右片、dongle 尚在重新枚举"时的**瞬时读数**，被误当成了稳定身份。

## 真正的缺陷：我们服务出去的是"模板 + 3 个字段"

| 字段 | 设备真实值 | 我们之前服务 | 后果 |
|---|---|---|---|
| `bMaxPacketSize0` | `0x08` | `0x40` | 与真设备不一致 |
| `iSerialNumber` | `0` | `3`（假序列号 `0000000000B1`） | PC 实例 ID 与真设备不同 |
| `bcdDevice` | `0x0100` | `0x0001` | 不一致 |

修法：`tud_descriptor_device_cb()` 改为**整份 18 字节照抄克隆内容**，
仅把 `bMaxPacketSize0` 覆盖成 `CFG_TUD_ENDPOINT0_SIZE`（我们的 EP0 硬件是 64，
若宣告 8 会导致 `SET_CONFIGURATION` 直接失败——实测 `mnt=0`）。

修复后（**零钉子**）：

```
mx.fv -> force=0000:0000 ovr=0000:0000 dev=0f326e70
mx.dv -> 12 01 00 02 00 00 00 40 0f 32 6e 70 00 01 01 02 00 01
         （与设备唯一差别就是 MPS0=0x40，受 EP0 硬件限制）
PC    -> USB\VID_320F&PID_706E\7&14516B5E&1&2   ← 无序列号形态，与真设备一致
        9 个节点全部 OK；回归 100 passed
```

## 所以"人为固定"这件事已经不需要了

`mx.vp` 仍保留为调试手段（NVS 持久），但**正常使用不需要它**：
开机自动克隆 → 身份 = 设备的真实身份 = `320F:706E`。

## 附：bMaxPacketSize0 的遗留限制
若要连 MPS0 也完全一致，需要把 `CFG_TUD_ENDPOINT0_SIZE` 设为 8 并重新验证枚举
（属于可选优化；当前 64 不影响功能）。
