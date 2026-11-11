"""px_cal - 光标增益标定（只测量，不改系统设置、不改固件）

原理
----
盒子这边 counts 是精确的（Σ 守恒），偏移发生在 Windows 把 HID 报告换算成像素这一步：
每条报告的 delta 越大，指针加速曲线给的倍率越高。所以"增益"是
    gain(每报告 counts) = 实际像素位移 / 发出的 counts
本工具用 `mode.bit7`（极速：时长 = ceil(D / max_report)）让**每条报告正好带 max_report
counts**，于是可以直接扫出 gain 随每报告 counts 的曲线。

用法
----
    python tools/px_cal.py                     # 默认扫 8..120，每档 3 次
    python tools/px_cal.py --reps 5 --dx 500
    python tools/px_cal.py --mr 8,12,16,60,120 --plot work/px_gain.png

注意
----
* 会**真的移动你的光标**（每次都会先 SetCursorPos 归位），跑的时候别操作鼠标；
* 串口独占：跑之前先把 boxbench GUI 关掉；
* 屏幕边上会被 OS 钳位，本工具检测到贴边会把该档标成 invalid。
"""
from __future__ import annotations

import argparse
import ctypes
import json
import os
import statistics
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from boxbench.link import BoxLink, P_SUMV          # noqa: E402

M_MAX_SPEED = 0x80


# ------------------------------------------------------------------ Win32
def _dpi_aware():
    try:
        ctypes.windll.shcore.SetProcessDpiAwareness(2)      # per-monitor
    except Exception:
        try:
            ctypes.windll.user32.SetProcessDPIAware()
        except Exception:
            pass


class POINT(ctypes.Structure):
    _fields_ = [('x', ctypes.c_long), ('y', ctypes.c_long)]


def cursor_pos():
    p = POINT()
    ctypes.windll.user32.GetCursorPos(ctypes.byref(p))
    return int(p.x), int(p.y)


def set_cursor(x, y):
    ctypes.windll.user32.SetCursorPos(int(x), int(y))
    time.sleep(0.04)


def screen_size():
    u = ctypes.windll.user32
    return u.GetSystemMetrics(0), u.GetSystemMetrics(1)


def pointer_settings():
    """只读：判断"提高指针精确度"是否开启（MouseSpeed=0 → 关闭）。"""
    try:
        import winreg
        with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r'Control Panel\Mouse') as k:
            val = {}
            for name in ('MouseSpeed', 'MouseThreshold1', 'MouseThreshold2',
                         'MouseSensitivity', 'SmoothMouseXCurve', 'SmoothMouseYCurve'):
                try:
                    val[name] = winreg.QueryValueEx(k, name)[0]
                except OSError:
                    pass
            epp = str(val.get('MouseSpeed', '?')).strip() not in ('0', '')
            return {'epp_on': epp, **{k: v for k, v in val.items()
                                      if not k.startswith('Smooth')}}
    except Exception as exc:                     # noqa: BLE001
        return {'error': str(exc)}


# ------------------------------------------------------------------ 测量
def one_shot(link, dx, dy, speed, mode, max_report, park, screen, settle=0.18):
    """归位 → 发一条 sumv → 读回光标位移。返回 dict。"""
    link.text_request(f'mx.mv {speed} {max_report}', timeout=0.4)
    link.text_request('mx.mt clr', timeout=0.4)
    link.text_request('mx.mt on', timeout=0.4)
    set_cursor(*park)
    p0 = cursor_pos()
    link.send_frame(P_SUMV,
                    (dx & 0xFFFF).to_bytes(2, 'little', signed=True)
                    + (dy & 0xFFFF).to_bytes(2, 'little', signed=True)
                    + (speed & 0xFFFF).to_bytes(2, 'little')
                    + bytes([mode, 0]))
    st = link.wait_motion_done(12.0)
    time.sleep(settle)
    p1 = cursor_pos()
    sw, sh = screen
    hit_edge = (p1[0] <= 0 or p1[0] >= sw - 1 or p1[1] <= 0 or p1[1] >= sh - 1)
    ents = link.dump_motion()
    inj = [(t, ep, ln, hx) for t, ep, ln, hx in ents if ep == 0]
    counts = 0
    mags = []
    for t, ep, ln, hx in inj:
        try:
            b = bytes.fromhex(hx)
        except ValueError:
            continue
        if len(b) < 3:
            continue
        s8 = lambda v: v - 256 if v >= 128 else v
        counts += s8(b[1])
        mags.append(abs(s8(b[1])) + abs(s8(b[2])))
    actual_counts = counts if counts else dx
    return {
        'dx': dx, 'speed': speed, 'mode': mode, 'max_report': max_report,
        'samples': st['samples'] if st else None,
        'dur_ms': (st and None) or None,
        'reports': len(inj),
        'per_report': (statistics.median(mags) if mags else None),
        'per_report_max': (max(mags) if mags else None),
        'counts_sent': actual_counts,
        'px': p1[0] - p0[0],
        'px_y': p1[1] - p0[1],
        'gain': (p1[0] - p0[0]) / actual_counts if actual_counts else None,
        'hit_edge': hit_edge,
    }


def press_enter(prompt):
    try:
        input(prompt)
    except EOFError:
        pass


def main():
    ap = argparse.ArgumentParser(description='光标增益标定（只测量）')
    ap.add_argument('--port', default=os.environ.get('MAKCU_PORT', 'COM3'))
    ap.add_argument('--baud', type=int, default=int(os.environ.get('MAKCU_BAUD', '921600')))
    ap.add_argument('--dx', type=int, default=400, help='每次移动的 counts（默认 400）')
    ap.add_argument('--dy', type=int, default=0)
    ap.add_argument('--reps', type=int, default=3, help='每档重复次数（取中位数）')
    ap.add_argument('--mr', default='8,12,16,20,30,40,60,80,100,120',
                    help='每报告 counts 档位（逗号分隔）')
    ap.add_argument('--plot', default=os.path.join(os.path.dirname(HERE), 'work', 'px_gain.png'))
    ap.add_argument('--csv', default=os.path.join(os.path.dirname(HERE), 'work', 'px_gain.csv'))
    ap.add_argument('--no-confirm', action='store_true', help='不等待人工确认')
    args = ap.parse_args()

    _dpi_aware()
    screen = screen_size()
    ps = pointer_settings()
    print('=' * 72)
    print(f'屏幕           : {screen[0]} x {screen[1]}')
    print(f'指针设置(只读) : {ps}')
    print(f'每次位移       : {args.dx} counts  重复 {args.reps} 次')
    print('=' * 72)
    if not args.no_confirm:
        press_enter('这会移动你的光标（每次先归位）。回车开始，Ctrl+C 取消… ')

    link = BoxLink(args.port, args.baud, on_log=lambda s: None)
    link.open()
    rows = []
    sw, sh = screen
    park = (min(300, sw // 4), sh // 2)          # 左边留 300，右边留出余量
    try:
        # 0) 慢速基线：每报告 ~1 count
        speed_slow = 1000
        base = []
        for _ in range(args.reps):
            r = one_shot(link, args.dx, args.dy, speed_slow, 0x00, 1, park, screen)
            if not r['hit_edge'] and r['gain']:
                base.append(r['gain'])
        g_slow = statistics.median(base) if base else None
        print(f'\n[基线] speed={speed_slow}（每报告 1 count）→ gain = {g_slow:.4f} px/count'
              if g_slow else '\n[基线] 失败')

        # 1) 扫每报告 counts（极速档，per-report ≈ max_report）
        mrs = [int(x) for x in args.mr.split(',') if x.strip()]
        print('\n每报告  |  样本  | 中位 per-report |  Σ counts |  像素  | gain(px/count) | 相对基线')
        print('-' * 92)
        for mr in mrs:
            gains, info = [], None
            for _ in range(args.reps):
                r = one_shot(link, args.dx, args.dy, 400, M_MAX_SPEED, mr, park, screen)
                info = r
                if not r['hit_edge'] and r['gain']:
                    gains.append(r['gain'])
            if not gains:
                print(f'{mr:7d} | (贴边/无效，跳过)')
                continue
            g = statistics.median(gains)
            rel = (g / g_slow) if g_slow else None
            print(f'{mr:7d} | {info["samples"]!s:>6} | {info["per_report"]!s:>15} | '
                  f'{info["counts_sent"]!s:>9} | {info["px"]:>6} | {g:14.4f} | '
                  f'{(f"{rel:.2f}×" if rel else "-"):>8}')
            rows.append({'max_report': mr, 'gain': g, 'relative': rel,
                         'samples': info['samples'], 'per_report': info['per_report'],
                         'px': info['px'], 'counts': info['counts_sent']})

        # 2) 固定 max_report=60 时，距离是否影响增益（可加性检查）
        print('\n距离检查（max_report=60，极速）')
        print('-' * 92)
        for dx in (200, 400, 800):
            gains = []
            for _ in range(args.reps):
                r = one_shot(link, dx, 0, 400, M_MAX_SPEED, 60, park, screen)
                if not r['hit_edge'] and r['gain']:
                    gains.append(r['gain'])
            if gains:
                g = statistics.median(gains)
                print(f'D={dx:5d} counts → gain {g:.4f} px/count  '
                      f'(相对基线 {(g / g_slow):.2f}×)' if g_slow else f'D={dx} gain {g:.4f}')
                rows.append({'max_report': 60, 'dx': dx, 'gain': g})
    finally:
        link.close()

    os.makedirs(os.path.dirname(args.csv), exist_ok=True)
    with open(args.csv, 'w', encoding='utf-8') as f:
        f.write('max_report,dx,gain,relative,samples,per_report,px,counts\n')
        for r in rows:
            f.write(f'{r.get("max_report")},{r.get("dx", args.dx)},{r["gain"]:.5f},'
                    f'{r.get("relative") or ""},{r.get("samples") or ""},'
                    f'{r.get("per_report") or ""},{r.get("px") or ""},{r.get("counts") or ""}\n')
    print(f'\nCSV  -> {args.csv}')

    # 3) 画图
    pts = [(r['per_report'] or r['max_report'], r['gain']) for r in rows
           if r.get('dx', args.dx) == args.dx and r.get('per_report')]
    if pts:
        try:
            from PIL import Image, ImageDraw, ImageFont
            W, H, pad = 900, 520, 60
            img = Image.new('RGB', (W, H), (17, 20, 24))
            d = ImageDraw.Draw(img)
            font = ImageFont.load_default()
            try:
                font = ImageFont.truetype(r'C:\Windows\Fonts\msyh.ttc', 14)
                fontb = ImageFont.truetype(r'C:\Windows\Fonts\msyh.ttc', 18)
            except Exception:
                fontb = font
            d.text((20, 14), 'Windows 指针增益曲线（只测量）', fill=(230, 236, 241), font=fontb)
            d.text((20, 40), f'屏幕 {screen[0]}x{screen[1]} · EPP={"on" if ps.get("epp_on") else "off"}'
                             f' · D={args.dx} counts · 基线 {g_slow:.4f} px/count'
                   if g_slow else '增益曲线', fill=(150, 165, 180), font=font)
            xs = [p[0] for p in pts]
            ys = [p[1] for p in pts]
            x0, x1 = 0, max(xs) * 1.1
            y0, y1 = 0, max(ys) * 1.15
            def tx(v): return pad + (v - x0) / (x1 - x0) * (W - 2 * pad)
            def ty(v): return H - pad - (v - y0) / (y1 - y0) * (H - 2 * pad - 60)
            d.line([(pad, H - pad), (W - pad, H - pad)], fill=(70, 80, 90))
            d.line([(pad, pad + 40), (pad, H - pad)], fill=(70, 80, 90))
            if g_slow:
                d.line([(pad, ty(g_slow)), (W - pad, ty(g_slow))], fill=(120, 90, 60), width=1)
                d.text((W - 170, ty(g_slow) - 16), f'基线 {g_slow:.3f}', fill=(190, 150, 100), font=font)
            d.line([(tx(x), ty(y)) for x, y in pts], fill=(79, 195, 247), width=2)
            for x, y in pts:
                d.ellipse((tx(x) - 3, ty(y) - 3, tx(x) + 3, ty(y) + 3), fill=(255, 213, 79))
            d.text((pad, H - pad + 8), '每报告 counts', fill=(150, 165, 180), font=font)
            d.text((pad + 4, pad + 24), 'px/count', fill=(150, 165, 180), font=font)
            img.save(args.plot)
            print(f'图表 -> {args.plot}')
        except Exception as exc:                 # noqa: BLE001
            print(f'[warn] 画图失败: {exc}')

    print('\n结论提示：')
    if g_slow:
        for r in rows:
            if r.get('dx', args.dx) == args.dx and r.get('relative'):
                print(f"  每报告 {r['per_report']:>4} counts → {r['gain']:.4f} px/count "
                      f"（{r['relative']:.2f}× 基线）")
    return 0


if __name__ == '__main__':
    sys.exit(main())
