"""aim_move - 防撞边 + 常数换算的"走到指定像素坐标"

为什么需要它
------------
标定结论（`verification/report/2026-11-11-px-gain.md`）：
  * 本机增益是**常数** `1.25 px/count`（= 1.0 logical × 125% 缩放），没有加速项；
  * "速度越大越偏"的真因是**屏幕边界钳位** —— 撞边后多发的 counts 被 OS 吃掉且不回补。

所以到位这件事必须在**下发前**算好，不能指望"多退少补"：

  1. 读当前光标（`GetCursorPos`）；
  2. `counts = round(px / gain)`，并把**目标夹到屏幕内**、把这一发**夹到不越界**；
  3. 发一段 `sumv`，等它走完，再读一次光标；
  4. 残差 > 容差就再来一段（默认最多 8 轮，通常 1–2 轮收敛）。

用法
----
    python tools/aim_move.py --by 300,-120              # 相对移动 300px, -120px
    python tools/aim_move.py --to 1280,800              # 移动到绝对坐标
    python tools/aim_move.py --to 1280,800 --tol 1 --iters 5
    python tools/aim_move.py --by 2000,0                # 会主动夹到屏幕边（不丢 counts）

参数
----
    --gain        px/count（默认 1.25；换机器/缩放请先跑 tools/px_cal.py 重标）
    --max-report  每报告 counts（默认 12）
    --speed       counts/s（0 = 盒子默认；极速档用 --max-speed）
"""
from __future__ import annotations

import argparse
import ctypes
import os
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from boxbench.link import BoxLink, P_SUMV     # noqa: E402

M_MAX_SPEED = 0x80


def _dpi_aware():
    try:
        ctypes.windll.shcore.SetProcessDpiAwareness(2)
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


def screen_size():
    u = ctypes.windll.user32
    return u.GetSystemMetrics(0), u.GetSystemMetrics(1)


def clampf(v, lo, hi):
    return lo if v < lo else (hi if v > hi else v)


def i16_bytes(v):
    """int16 按位打包（负值不能用 signed=True 直接转，会 OverflowError）。"""
    return (int(v) & 0xFFFF).to_bytes(2, 'little')


def send_move(link, cx, cy, max_report, speed, max_speed):
    link.send_frame(P_SUMV,
                    i16_bytes(cx) + i16_bytes(cy)
                    + (max(0, min(65535, int(speed))) & 0xFFFF).to_bytes(2, 'little')
                    + bytes([M_MAX_SPEED if max_speed else 0, 0]))
    return link.wait_motion_done(15.0)


def main():
    ap = argparse.ArgumentParser(description='走到指定像素坐标（防撞边 + 常数据换算）')
    ap.add_argument('--port', default=os.environ.get('MAKCU_PORT', 'COM3'))
    ap.add_argument('--baud', type=int, default=int(os.environ.get('MAKCU_BAUD', '921600')))
    ap.add_argument('--to', help='绝对目标 "x,y"（像素）')
    ap.add_argument('--by', help='相对位移 "dx,dy"（像素）')
    ap.add_argument('--gain', type=float, default=1.25, help='px/count（默认 1.25，本机标定值）')
    ap.add_argument('--max-report', type=int, default=12, help='每报告 counts（默认 12）')
    ap.add_argument('--speed', type=int, default=0, help='counts/s，0 = 盒子默认')
    ap.add_argument('--max-speed', action='store_true', help='极速档（bit7）')
    ap.add_argument('--tol', type=float, default=2.0, help='容差 px（默认 2）')
    ap.add_argument('--iters', type=int, default=8, help='最多几轮修正（默认 8）')
    ap.add_argument('--verbose', action='store_true')
    args = ap.parse_args()

    if not args.to and not args.by:
        ap.error('--to 或 --by 必须给一个')

    _dpi_aware()
    sw, sh = screen_size()
    x0, y0 = cursor_pos()
    if args.to:
        tx, ty = (int(v) for v in args.to.split(','))
    else:
        dx, dy = (int(v) for v in args.by.split(','))
        tx, ty = x0 + dx, y0 + dy
    tx = clampf(tx, 0, sw - 1)
    ty = clampf(ty, 0, sh - 1)
    print(f'屏幕 {sw}x{sh} · 起点 ({x0},{y0}) · 目标 ({tx},{ty}) · 增益 {args.gain} px/count'
          f' · 每报告 {args.max_report}')

    link = BoxLink(args.port, args.baud, on_log=lambda s: None)
    link.open()
    link.text_request(f'mx.mv {args.speed or 400} {max(8, min(120, args.max_report))}', timeout=0.4)
    t0 = time.time()
    cur = (x0, y0)
    err = None
    try:
        for i in range(1, args.iters + 1):
            err_x = tx - cur[0]
            err_y = ty - cur[1]
            err = max(abs(err_x), abs(err_y))
            if err <= args.tol:
                print(f'  轮 {i}: 已达容差（误差 {err} px）')
                break
            # 像素 → counts，并把这一发夹到"不越界"
            cx = round(err_x / args.gain)
            cy = round(err_y / args.gain)
            # 不越界：本发最多走到屏幕边（留 1 px 余量）
            max_cx = round((sw - 1 - cur[0]) / args.gain) if err_x > 0 else round((0 - cur[0]) / args.gain)
            max_cy = round((sh - 1 - cur[1]) / args.gain) if err_y > 0 else round((0 - cur[1]) / args.gain)
            cx = int(clampf(cx, min(0, max_cx), max(0, max_cx)))
            cy = int(clampf(cy, min(0, max_cy), max(0, max_cy)))
            cx = int(clampf(cx, -32767, 32767))
            cy = int(clampf(cy, -32767, 32767))
            if cx == 0 and cy == 0:
                print('  [warn] 已到屏幕边界，无法继续靠近')
                break
            st = send_move(link, cx, cy, args.max_report, args.speed, args.max_speed)
            time.sleep(0.12)
            cur = cursor_pos()
            if args.verbose:
                print(f'  轮 {i}: 发 ({cx},{cy}) counts → 光标 ({cur[0]},{cur[1]}) '
                      f'· 残差 ({tx - cur[0]},{ty - cur[1]}) px · state={st}')
            else:
                print(f'  轮 {i}: ({cx:+d},{cy:+d}) counts → ({cur[0]},{cur[1]}) '
                      f'残差 {max(abs(tx - cur[0]), abs(ty - cur[1]))} px')
    finally:
        link.close()

    err = max(abs(tx - cur[0]), abs(ty - cur[1]))
    ok = err <= args.tol
    print(f'结果: {"PASS" if ok else "MISS"} · 终点 ({cur[0]},{cur[1]}) · 目标 ({tx},{ty}) · '
          f'误差 {err} px · 用时 {(time.time() - t0) * 1000:.0f} ms')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
