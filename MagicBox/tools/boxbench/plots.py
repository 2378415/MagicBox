"""轨迹解码、指标计算、Tk 绘制、PNG 导出。

`mx.mt` 转储里的注入样本是 ep=0x00、len=4：`btn, dx, dy, wheel`（都是 int8）。
指标口径与 `verification/report/2026-11-10-sumv.md` 一致：
    起步占比 = 走完 5% 距离所花时间 / 总时长
    尾段占比 = 走完最后 5% 距离所花时间 / 总时长
    过程最大 = 累计位移在请求方向上的投影最大值（应等于请求长度，超过即有冲过头）
"""
from __future__ import annotations

import math

FONT_CANDIDATES = (
    r'C:\Windows\Fonts\msyh.ttc',
    r'C:\Windows\Fonts\msyhbd.ttc',
    r'C:\Windows\Fonts\simhei.ttf',
)


def decode_injected(entries):
    """[(t_us, ep, len, hex)] → [(t_us, dx, dy)]；只取注入路径（ep=0x00, len=4）。"""
    out = []
    for t, ep, ln, hx in entries:
        if ep != 0x00 or ln < 4:
            continue
        try:
            b = bytes.fromhex(hx)
        except ValueError:
            continue
        if len(b) < 3:
            continue
        s8 = lambda v: v - 256 if v >= 128 else v
        out.append((t, s8(b[1]), s8(b[2])))
    return out


def _pct(vals, q):
    if not vals:
        return 0.0
    s = sorted(vals)
    k = min(len(s) - 1, max(0, int(q * (len(s) - 1))))
    return float(s[k])


def metrics(samples, req_dx: int, req_dy: int):
    """算一组手感指标。samples = [(t_us, dx, dy)]。"""
    if not samples:
        return {'ok': False, 'why': '没有注入样本（是不是没开 mx.mt？）'}

    t0 = samples[0][0]
    dur_ms = max(1e-6, (samples[-1][0] - t0) / 1000.0)
    req_len = math.hypot(req_dx, req_dy) or 1.0
    ux, uy = req_dx / req_len, req_dy / req_len

    cx = cy = 0
    proj = []                              # (t_ms, 累计投影)
    mags = []
    dy_hits = 0
    dts = []
    prev_t = None
    for t, dx, dy in samples:
        cx += dx
        cy += dy
        proj.append(((t - t0) / 1000.0, cx * ux + cy * uy))
        mags.append(abs(dx) + abs(dy))
        if dy:
            dy_hits += 1
        if prev_t is not None and t > prev_t:
            dts.append(t - prev_t)
        prev_t = t

    def t_at(frac):
        target = req_len * frac
        for tm, p in proj:
            if p >= target:
                return tm
        return dur_ms

    start5 = t_at(0.05)
    tail5 = dur_ms - t_at(0.95)
    return {
        'ok': True,
        'n': len(samples),
        'dur_ms': dur_ms,
        'sum_dx': cx,
        'sum_dy': cy,
        'req_dx': req_dx,
        'req_dy': req_dy,
        'exact': (cx == req_dx and cy == req_dy),
        'proj_max': max(p for _, p in proj),
        'req_len': req_len,
        'start5_ms': start5,
        'tail5_ms': tail5,
        'start5_pct': 100.0 * start5 / dur_ms,
        'tail5_pct': 100.0 * tail5 / dur_ms,
        'rate': len(samples) / (dur_ms / 1000.0),
        'mag_p50': _pct(mags, 0.5),
        'mag_p90': _pct(mags, 0.9),
        'mag_max': max(mags),
        'dy_rows': dy_hits,
        'dt_p50': _pct(dts, 0.5),
        'dt_p90': _pct(dts, 0.9),
        't0': t0,
    }


def _smooth(vals, k=5):
    if len(vals) < k:
        return vals
    out = []
    for i in range(len(vals)):
        lo, hi = max(0, i - k // 2), min(len(vals), i + k // 2 + 1)
        out.append(sum(vals[lo:hi]) / (hi - lo))
    return out


def velocity_series(samples, t0, window_us=10000):
    """按 10 ms 滑动窗口算速度（counts/s）：窗口里的位移 / 窗口时长。

    不逐报告算，是因为报告间隔会在 1/2 ms 之间交替（亚计数 DDA 只在凑够 1 count
    时才发），逐报告算出来是一排梳齿，看不出梯形剖面。
    """
    if not samples:
        return [], []
    cum = [0.0]
    for i in range(1, len(samples)):
        _, dx, dy = samples[i]
        cum.append(cum[-1] + math.hypot(dx, dy))
    ts, vs = [], []
    j = 0
    for i, (t, _, _) in enumerate(samples):
        while j < i and t - samples[j][0] > window_us:
            j += 1
        dt = (t - samples[j][0]) or 1
        ts.append((t - t0) / 1000.0)
        vs.append((cum[i] - cum[j]) * 1e6 / dt)
    return ts, vs


def xy_mapper(xs, ys, x0, x1, y0, y1, pad=0.06):
    """返回 (span, minx, miny, fn)，两轴共用同一 span 并各自居中。"""
    span_x = max(xs) - min(xs)
    span_y = max(ys) - min(ys)
    span = max(span_x, span_y, 1.0) * (1.0 + 2 * pad)
    cx = (max(xs) + min(xs)) / 2.0
    cy = (max(ys) + min(ys)) / 2.0
    def fn(x, y):
        px = (x0 + x1) / 2.0 + (x - cx) / span * (x1 - x0)
        py = (y0 + y1) / 2.0 - (y - cy) / span * (y1 - y0) * -1.0
        return px, py
    return span, fn


def xy_series(samples):
    xs, ys = [0], [0]
    cx = cy = 0
    for _, dx, dy in samples:
        cx += dx
        cy += dy
        xs.append(cx)
        ys.append(cy)
    return xs, ys


def summary_lines(m):
    if not m.get('ok'):
        return [m.get('why', '无数据')]
    flag = '[OK]' if m['exact'] else '[MISMATCH]'
    over = '' if m['proj_max'] <= m['req_len'] + 0.5 else '  ⚠ 过程越界'
    return [
        f"样本 {m['n']} · 时长 {m['dur_ms']:.0f} ms · 速率 {m['rate']:.0f}/s",
        f"Σ=({m['sum_dx']},{m['sum_dy']}) 请求=({m['req_dx']},{m['req_dy']}) {flag}",
        f"过程最大投影 {m['proj_max']:.0f} / 请求 {m['req_len']:.0f}{over}",
        f"起步 0–5% {m['start5_ms']:.0f} ms ({m['start5_pct']:.1f}%) · "
        f"尾段 95–100% {m['tail5_ms']:.0f} ms ({m['tail5_pct']:.1f}%)",
        f"单报告 |dx|+|dy|: p50 {m['mag_p50']:.0f} / p90 {m['mag_p90']:.0f} / max {m['mag_max']:.0f}",
        f"dt: p50 {m['dt_p50']:.0f} µs / p90 {m['dt_p90']:.0f} µs · dy≠0 {m['dy_rows']} 行",
    ]


# ------------------------------------------------------------------ Tk 绘制
def draw_tk(canvas, samples, m, size=(760, 380)):
    """在 Tk Canvas 上画 XY 轨迹 + 速度曲线（两块并排）。"""
    c = canvas
    c.delete('all')
    W, H = size
    c.configure(width=W, height=H, bg='#111418')
    if not m.get('ok'):
        c.create_text(W // 2, H // 2, text=m.get('why', '无数据'), fill='#8899aa')
        return

    half = W // 2
    pad = 28
    # ---- 左：XY 轨迹（同一比例、各自居中：纯 X 移动是一条居中的水平线）
    xs, ys = xy_series(samples)
    _, to_xy = xy_mapper(xs, ys, pad, half - pad, pad, H - pad)

    c.create_rectangle(pad, pad, half - pad, H - pad, outline='#2a323a')
    pts = []
    for x, y in zip(xs, ys):
        pts += list(to_xy(x, y))
    if len(pts) >= 4:
        c.create_line(*pts, fill='#4fc3f7', width=2, smooth=False)
    ax, ay = to_xy(0, 0)
    bx, by = to_xy(m['req_dx'], m['req_dy'])
    c.create_oval(ax - 3, ay - 3, ax + 3, ay + 3, outline='#888', fill='#444')
    c.create_oval(bx - 4, by - 4, bx + 4, by + 4, outline='#ffd54f', width=2)
    c.create_text(pad + 4, pad - 12, text='XY 轨迹（灰=起点 黄=目标）', anchor='w', fill='#c8d2dc')

    # ---- 右：速度曲线（每报告位移 / dt，5 点平滑）
    vx, vy = velocity_series(samples, m['t0'])
    c.create_rectangle(half + pad, pad, W - pad, H - pad, outline='#2a323a')
    if vy:
        vmax = max(vy) or 1
        tmax = vx[-1] or 1
        pts = []
        for t, v in zip(vx, vy):
            px = half + pad + t / tmax * (half - 2 * pad)
            py = H - pad - v / vmax * (H - 2 * pad)
            pts += [px, py]
        if len(pts) >= 4:
            c.create_line(*pts, fill='#81c784', width=2)
        c.create_text(half + pad + 4, pad - 12,
                      text=f'速度曲线（峰值 {vmax:.0f} counts/s）', anchor='w', fill='#c8d2dc')


# ---------------------------------------------------------------- PNG 导出
def export_png(path, samples, m, title='sumv 轨迹', meta=None):
    from PIL import Image, ImageDraw, ImageFont

    W, H = 1200, 760
    img = Image.new('RGB', (W, H), (17, 20, 24))
    d = ImageDraw.Draw(img)

    font = None
    for fp in FONT_CANDIDATES:
        try:
            font = ImageFont.truetype(fp, 16)
            font_small = ImageFont.truetype(fp, 14)
            font_big = ImageFont.truetype(fp, 20)
            break
        except Exception:
            continue
    if font is None:
        font = ImageFont.load_default()
        font_small = font_big = font

    d.text((24, 16), title, fill=(230, 236, 241), font=font_big)
    y = 48
    if meta:
        for line in meta:
            d.text((24, y), line, fill=(150, 165, 180), font=font_small)
            y += 20
    y += 6
    for line in summary_lines(m):
        d.text((24, y), line, fill=(200, 212, 224), font=font)
        y += 22

    top = y + 26
    pad = 30
    half = (W - 3 * pad) // 2
    box_h = H - top - pad
    left = (pad, top, pad + half, top + box_h)
    right = (W - pad - half, top, W - pad, top + box_h)
    d.rectangle(left, outline=(42, 50, 58))
    d.rectangle(right, outline=(42, 50, 58))
    d.text((left[0] + 6, top - 20), 'XY 轨迹（灰=起点 黄=目标）', fill=(160, 175, 190), font=font_small)
    d.text((right[0] + 6, top - 20), '速度曲线', fill=(160, 175, 190), font=font_small)

    if not m.get('ok'):
        d.text((pad + 10, top + 10), m.get('why', '无数据'), fill=(200, 120, 120), font=font)
        img.save(path)
        return path

    # XY（同一比例、各自居中）
    xs, ys = xy_series(samples)
    ix0, iy0, ix1, iy1 = left
    _, to_xy = xy_mapper(xs, ys, ix0 + pad * 0.5, ix1 - pad * 0.5,
                         iy0 + pad * 0.5, iy1 - pad * 0.5)
    pts = [to_xy(x, yy) for x, yy in zip(xs, ys)]
    if len(pts) >= 2:
        d.line(pts, fill=(79, 195, 247), width=2)
    sx, sy = to_xy(0, 0)
    tx, ty = to_xy(m['req_dx'], m['req_dy'])
    d.ellipse((sx - 4, sy - 4, sx + 4, sy + 4), outline=(140, 150, 160), fill=(70, 76, 84))
    d.ellipse((tx - 5, ty - 5, tx + 5, ty + 5), outline=(255, 213, 79), width=2)

    # 速度（平滑）
    vx, vy = velocity_series(samples, m['t0'])
    jx0, jy0, jx1, jy1 = right
    if vy:
        vmax = max(vy) or 1
        tmax = vx[-1] or 1
        pts = [(jx0 + (t / tmax) * (jx1 - jx0 - 8) + 4,
                jy1 - 4 - (v / vmax) * (jy1 - jy0 - 8)) for t, v in zip(vx, vy)]
        if len(pts) >= 2:
            d.line(pts, fill=(129, 199, 132), width=2)
        d.text((jx1 - 160, jy0 + 6), f'峰值 {vmax:.0f} counts/s', fill=(150, 170, 150), font=font_small)

    img.save(path)
    return path
