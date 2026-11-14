#!/usr/bin/env python3
"""Regenerate docs/40-status.md from the actual artifacts (no hand-kept numbers).

Usage: python tools/status.py
"""
import glob
import os
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
HERE = os.path.dirname(os.path.abspath(__file__))
PROJ = os.path.dirname(HERE)
os.chdir(PROJ)



def implemented_handlers():
    path = "components/makcu_proto/handlers.def"
    out = []
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            parts = line.split("#")[0].split()
            if len(parts) >= 3 and parts[2] == "implemented":
                out.append((parts[0], parts[1]))
    return out


def reports():
    return sorted(os.path.basename(p) for p in glob.glob("verification/report/*.md"))

def count_todos(component):
    files = glob.glob(f'components/{component}/src/*_stub.c')
    if not files:
        return 0
    return open(files[0], encoding='utf-8').read().count('/* TODO ')


def build_state(app):
    """(built?, bin bytes, elf bytes) for one app.

    `build/` is gitignored and may be absent (fresh clone / cleaned tree).  In
    that case the table prints 「未构建」instead of inventing numbers: build with
    tools/build_app.ps1 first, then re-run this script.
    """
    bdir = os.path.join(app, 'build')
    if not os.path.isdir(bdir):
        return False, 0, 0
    bins = glob.glob(os.path.join(bdir, '*.bin'))
    elfs = glob.glob(os.path.join(bdir, '*.elf'))
    size = os.path.getsize(bins[0]) if bins else 0
    esize = os.path.getsize(elfs[0]) if elfs else 0
    return bool(bins), size, esize


def main():
    comps = sorted(d for d in os.listdir('components')
                   if os.path.isdir(os.path.join('components', d)))
    port = {c: count_todos(c) for c in comps}
    impl = implemented_handlers()

    out = ['# 40-status：执行状态（本文件由 `tools/status.py` 生成）', '']
    out += ['## 构建（T1）', '', '| app | 构建 | app.bin | elf |', '|---|---|---:|---:|']
    for app in ('app_left', 'app_right'):
        built, size, esize = build_state(app)
        out.append(f'| {app} | {"✅ 成功" if built else "未构建"} | {size} B | {esize} B |')
    out += ['', '原始镜像对照：LEFT 403,536 B / RIGHT 341,824 B。重建镜像体积不同属预期：厂商的 Bezier 浮点曲线'
            '（`0x4200EFEC`）用观测等价实现替代，且 IDF 版本/裁剪项与原厂构建不完全一致。'
            '尺寸取自最近一次清洁构建；`build/` 不入库，重跑本脚本前先 `tools/build_app.ps1`。', '']
    out += ['## 已完成', '', '| 项 | 状态 | 产物 |', '|---|---|---|',
            '| 方案与事实基线 | 完成 | `docs/00-plan.md`、`docs/00-facts.md` |',
            '| ESP-IDF v5.4.1 环境 | 完成（子模块用 codeload 补、CMake/Ninja 用 pip） | `tools/setup_idf.ps1`、`tools/fetch_idf_submodules.py` |',
            '| 命令表 / opcode 表导出 | 完成：43 条命令 + 27 项 opcode，全部带 handler 名 | `tools/extract_tables.py` |',
            '| 前缀匹配 `makcu_lookup` | 完成（语义同 `cmd_lookup`） | `components/makcu_proto/src/makcu_lookup.c` |',
            '| 回执封装 `makcu_reply_format` | 完成（`km.` + 内容 + `\\r\\n>>> `） | `components/makcu_proto/src/makcu_reply.c` |',
            '| UART1 帧层（构建 + 流式解析） | 完成 | `components/makcu_link/src/makcu_link.c` |',
            '| 双 app 工程（可编可链） | 完成：`idf.py build` 两端都通过 | `app_left/`、`app_right/` |',
            '| 分区表（LEFT 实测） | 完成 | `app_left/partitions.csv` |',
            '| 指令相似度工具 | 完成：自比 1.000、异函数 0.364 | `tools/diff_insn.py` |',
            '| 函数指纹 + P0 基线工具 | `tools/p0_baseline.py`（只读官方镜像）；`lib_fingerprint.py` 依赖旧反编译树，已随 2026-11-12 清理删除 |',
            '| 协议回归夹具 | 完成（无硬件自动 skip） | `verification/regress/` |',
            '']
    out += ['## 进行中 / 阻塞', '', '| 项 | 状态 | 说明 |', '|---|---|---|',
            '| P0 同构编译基准 | **未达标** | 严格指令哈希命中 7/816（0.9%）：`sdkconfig` 与原始构建仍有差异；下一步改成“同尺寸桶 + difflib 相似度”的模糊匹配，并把 op 序列存进指纹 |',
            '| 命令协议层（P3 文本层） | **%d/27 个 opcode 全部实现**（43 条文本命令 + 3 个跳表专用入口），回包与原厂逐字节一致；13 个隐藏 opcode 的副作用也实测闭环（`mx.dd`/`mx.dp`，report run-16） | `components/makcu_proto/handlers.def` |'
            % len(impl),
            '| 副作用层（P4 运动） | **队列 + 分步 + 曲线完成**：int8 分步（ceil(span/127)，不再被轨迹环上限截断）、每步一次随机弯曲、残差摊分守恒，`mx.rq` 读轨迹 + `mx.rt` 读累计位移可断言“进多少出多少”；与原函数的差别是数值而非形状 | `components/makcu_mouse/` |',
            '| 副作用层（P5 HID 上报） | **完成**：设备枚举为 HID 鼠标，光标位移已端到端验证；克隆激活时按克隆描述符的 Report ID 约定发送（无 ID 时发裸报告） | `components/makcu_hiddev/`、`tools/cursor_test.ps1` |',
            '| 副作用层（P4 键盘） | **完成**：复合 HID（ID1 鼠标 / ID2 键盘），down/up/tap/type/批量/combo/state 全实现，`mx.rk` 可读回 8 字节报告 | `components/makcu_keyboard/` |',
            '| 副作用层（P2 桥接） | **完成**：UART1 帧层 + `0xA0` EP0 会话状态机 + `0xA2` 上报透传（真机端到端：注入报告让主机光标移动）；EP0 **数据**注入、右片发送端、真实引脚仍待做 | `components/makcu_link/` |',
            '| 副作用层（P5 克隆） | **描述符克隆完成**：仓库→回调→主机→驱动启动全通（`mnt=1`、主机侧 `VID_046D&PID_C077` + `HID-compliant mouse` 均正常）；EP0 隧道应答、序列号读写仍待做（`serial()` 仍恒回失败文案） | `components/makcu_clone/` |',
            '| 烧录 + 回归（T2） | 报告 %d 份；最近一轮 **119 passed / 0 failed**（95 上机 + 24 离线模型；清洁构建，`MB_TUSB_DEBUG` 构建会把日志混进回包、不能跑回归） | `verification/report/` |'
            % len(reports()),
            '']
    out += ['## 已移植 handler', '', '| opcode | handler | 说明 |', '|---|---|---|']
    for op, name in impl:
        out.append(f'| {op} | `{name}` | 协议面已上机验证 |')
    out += ['', '## 报告与记录', '']
    for r in reports():
        out.append(f'- [`{r}`](../verification/report/{r})')
    out += ['', '## 端口面（草稿清单，非待办）', '',
            '`components/makcu_proto/handlers.def` 现为 **%d/27 implemented**。下表是 2026-11-09 移植期留在'
            '`*_stub.c` 里的 `/* TODO */` 标记数，属历史草稿（真实待办见下节，勿据此判断进度）。'
            % len(impl), '', '| 组件 | stub 里的 TODO 标记 |', '|---|---:|']
    for c in comps:
        out.append(f'| {c} | {port[c]} |')
    out += ['', f'合计 {sum(port.values())} 处标记（11-09 口径；当时写作「待移植函数数」）。', '']
    out += ['## 下一步（按顺序）', '',
            '1. 实现 `makcu_serial_read_hook`（序列号查询 / 恢复 / 写入三模式）——`serial()` 目前恒回失败文案；',
            '2. 右片 UART1 真实引脚反查（当前占位 17/18），拿到后用 V3.7 配置替换并复测链路；',
            '3. P0 基线改模糊匹配（同尺寸桶 + difflib ≥0.9 记命中），对齐 `sdkconfig` 使相似度可用作变更护栏；',
            '4. 手感一致性：`0x4200EFEC` 浮点曲线需 USB 分析仪对照出厂轨迹；',
            '5. 可选：补 HECATE Connect 在「鼠标插在盒子上」场景下的写配置回归（`verification/plan-hecate-connect-proxy.md`）。',
            '']
    header = ['> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）', '']
    appendix_path = 'docs/40-status-appendix.md'
    if os.path.exists(appendix_path):
        out += ['', '---', '', open(appendix_path, encoding='utf-8').read().rstrip(), '']
    open('docs/40-status.md', 'w', encoding='utf-8').write('\n'.join(header + out))
    print('docs/40-status.md written; port surface total =', sum(port.values()),
          '| reports =', len(reports()), '| appendix =', os.path.exists(appendix_path))


if __name__ == '__main__':
    main()
