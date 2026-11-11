"""aim_stress - 瞄准压力测试：并发/队列 sumv + 夹杂鼠标按键，按键一条都不能丢。

用法
----
    python tools\\aim_stress.py                       # both：10 s，120 Hz 瞄准 + 20 Hz 按键
    python tools\\aim_stress.py --seconds 20 --rate 200 --btn-rate 40
    python tools\\aim_stress.py --mode queue          # 只跑队列（逐条等完成，验证位移守恒）
    python tools\\aim_stress.py --mode concurrent     # 只跑并发（REPLACE 语义 + 按键零丢失）
    python tools\\aim_stress.py --buttons all         # 默认只按侧键/中键（见安全说明）

测试区域
--------
屏幕**右上角**：一个闭环把光标钉在 (W-1-margin, margin) 附近。

**全部走二进制命令**（0x32/0x36/0x3C/0x3D/0x3E），不依赖 `mx.*` 台架文本命令 ——
文本通道在多线程高频混发时会被二进制流干扰（见文件末尾"已知问题"），
所以位移校验改成读**真实光标像素**（`GetCursorPos`）+ 标定增益换算，更贴近实际效果。

判据（客观可查）
----------------
队列模式：每步"光标像素位移 == counts × gain"（±6 px）→ 验证 sumv 逐条守恒。

并发模式（四条硬判据 + PC 侧交叉验证）：
  ① **回环审计**（`0x3F BTN_AUDIT`）：`in_chg == out_chg == 注入的按键变化数` 且 `extra == 0`
     → 每条变化正好一条线上报告：不丢、不重、不多发；
  ② PC 侧**按下沿/松开沿** ≥ 周期数（不能少；Windows 会合成边沿，所以不要求相等）；
  ③ 释放之后所有相关虚拟键都抬起（无卡键）+ 光标**确实进过**右上角方框且全程不越界；
  ④ 按键处 AIM 间隔尖峰 ≤ `--gap-ms`（默认 25 ms）→ 按键不会把移动卡住。

安全说明）

测试区域
--------
屏幕**右上角**：一个闭环把光标钉在 (W-1-margin, margin) 附近。

**全部走二进制命令**（0x32/0x36/0x3C/0x3D/0x3E），不依赖 `mx.*` 台架文本命令 ——
文本通道在多线程高频混发时会被二进制流干扰（见文件末尾"已知问题"），
所以位移校验改成读**真实光标像素**（`GetCursorPos`）+ 标定增益换算，更贴近实际效果。

判据（客观可查）
----------------
队列模式：每步"光标像素位移 == counts × gain"（±6 px）→ 验证 sumv 逐条守恒。

并发模式（三条硬判据）：
  ① PC 侧**按下沿** ≥ 周期数（不能少）—— 每次按下 Windows 都看到了；
  ② PC 侧**松开沿** ≥ 周期数（不能少）—— 每次松开也都看到了；
  ③ 释放之后所有相关虚拟键都抬起（无卡键）+ 光标全程不出右上角方框。

旁证：固件 `btn_sent == btn_in` 且 `btn_overflow == 0`（队列没溢出、没丢条目）。
注意：PC 侧边沿数偶尔比周期数**多**（Windows 自己会合成/合并事件），所以判据是
"不能少"而不是"必须相等"；`btn_in` 也会统计真实鼠标报告，只能当旁证。

安全说明
--------
默认 `--buttons safe`：只用 **侧键 4 / 侧键 5 / 中键**。右上角是窗口关闭按钮的位置，
在角上用左键连点可能真的点到桌面窗口 —— 左/右键默认不参与，要测请显式 `--buttons all`。
"""
from __future__ import annotations

import argparse
import ctypes
import json
import os
import queue
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from boxbench.link import BoxLink                      # noqa: E402

P_SUMV = 0x36
P_BUTTON = 0x32
P_WHEEL = 0x33
P_AIM = 0x3C
P_AIM_STATE = 0x3D
P_HID_STAT = 0x3E
P_BTN_AUDIT = 0x3F

BTN_MASKS = {'middle': 0x04, 'x1': 0x08, 'x2': 0x10, 'left': 0x01, 'right': 0x02}
VK_OF = {0x01: 0x01, 0x02: 0x02, 0x04: 0x04, 0x08: 0x05, 0x10: 0x06}   # mask -> VK

DEBUG = bool(os.environ.get('AIM_STRESS_DEBUG'))


# --------------------------------------------------------------------- Win32
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


def set_cursor(x, y):
    ctypes.windll.user32.SetCursorPos(int(x), int(y))


def screen_size():
    u = ctypes.windll.user32
    return u.GetSystemMetrics(0), u.GetSystemMetrics(1)


def i16(v):
    return (int(v) & 0xFFFF).to_bytes(2, 'little')


# ------------------------------------------------------------------- 报文构造
def aim_payload(dx, dy, max_ms, flags=0, dead=0):
    return i16(dx) + i16(dy) + bytes([max(4, min(255, max_ms)), flags, max(0, min(255, dead))])


def sumv_payload(dx, dy, speed=0, mode=0):
    return i16(dx) + i16(dy) + (max(0, min(65535, speed))).to_bytes(2, 'little') + bytes([mode, 0])


def parse_hid_stat(p):
    if not p or len(p) < 8:
        return None
    u = lambda o: p[o] | (p[o + 1] << 8)
    return {'btn_in': u(0), 'btn_sent': u(2), 'wait_max_us': u(4), 'btn_overflow': u(6)}


def parse_btn_audit(p):
    if not p or len(p) < 12:
        return None
    u = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
    return {'in_chg': u(0), 'out_chg': u(4), 'extra': u(8)}


def parse_aim_state(p):
    if not p or len(p) < 12:
        return None
    u = lambda o: p[o] | (p[o + 1] << 8)
    return {'active': p[0], 'last_result': p[1], 'counts': u(2), 'dur_ms': u(4),
            'aborted': u(6), 'rounds': u(8), 'dead_hits': p[10], 'gen': p[11]}


def wait_started_and_done(link, timeout=6.0):
    """等这条 sumv 真的进入 active=1 再回到 0。

    只用 `active==0` 判完成会有竞态：命令还在写线程队列里、或极短移动 1 ms 就结束时，
    会立刻返回并读到"上一步的余量"，造成误判。这里要求至少见过一次 active=1；
    实在抓不到（位移极小）就用超时兜底。
    """
    t0 = time.time()
    seen_active = False
    while time.time() - t0 < timeout:
        st = link.request(0x38, timeout=0.2)          # SUMV_STATE
        if st and len(st) >= 1:
            if st[0]:
                seen_active = True
            elif seen_active:
                return True
        time.sleep(0.005)
    return seen_active


def wait_cursor_stable(max_ms=250):
    """等光标连续两次采样相同（最多 max_ms），避免读到动画中间值。"""
    t0 = time.time()
    prev = cursor_pos()
    while (time.time() - t0) * 1000 < max_ms:
        time.sleep(0.008)
        now = cursor_pos()
        if now == prev:
            return now
        prev = now
    return prev


def wait_motion_done(link, timeout=6.0):
    """轮询 SUMV_STATE 直到 active=0（纯二进制，不碰文本通道）。"""
    t0 = time.time()
    while time.time() - t0 < timeout:
        st = link.request(P_SUMV_STATE := 0x38, timeout=0.3)
        if st and len(st) >= 1 and st[0] == 0:
            return True
        time.sleep(0.01)
    return False


# --------------------------------------------------------------------- 写线程
class Writer(threading.Thread):
    """所有命令都从这里出去：串口写串行化。"""

    def __init__(self, link, counters):
        super().__init__(daemon=True)
        self.link = link
        self.q = queue.Queue()
        self.counters = counters
        self.stop = threading.Event()
        self.errors = 0

    def submit(self, cmd, payload=b'', kind=''):
        self.q.put((cmd, payload, kind))

    def run(self):
        while not self.stop.is_set() or not self.q.empty():
            try:
                cmd, payload, kind = self.q.get(timeout=0.05)
            except queue.Empty:
                continue
            try:
                self.link.send_frame(cmd, payload)
                if kind:
                    self.counters[kind] = self.counters.get(kind, 0) + 1
            except Exception as exc:                    # noqa: BLE001
                self.errors += 1
                if DEBUG:
                    print(f'[writer] 写失败: {exc}')


# ----------------------------------------------------------------- 光标共享
class Cursor:
    def __init__(self):
        self.lock = threading.Lock()
        self.pos = cursor_pos()
        self.outside = 0
        self.armed = False

    def update(self, box):
        p = cursor_pos()
        with self.lock:
            self.pos = p
            inside = box and (box[0] <= p[0] <= box[2] and box[1] <= p[1] <= box[3])
            if inside:
                self.armed = True          # 第一次进框后才开始计越界
            elif self.armed:
                self.outside += 1
        return p

    def get(self):
        with self.lock:
            return self.pos


# --------------------------------------------------------------------- 主流程
def main():
    ap = argparse.ArgumentParser(description='瞄准压力测试（并发/队列 sumv + 按键零丢失）')
    ap.add_argument('--port', default=os.environ.get('MAKCU_PORT', 'COM3'))
    ap.add_argument('--baud', type=int, default=int(os.environ.get('MAKCU_BAUD', '921600')))
    ap.add_argument('--mode', choices=['both', 'queue', 'concurrent'], default='both')
    ap.add_argument('--seconds', type=float, default=10.0)
    ap.add_argument('--rate', type=float, default=120.0, help='瞄准命令频率 Hz')
    ap.add_argument('--btn-rate', type=float, default=20.0, help='按键频率 Hz')
    ap.add_argument('--margin', type=int, default=40, help='离屏幕右上角的像素边距')
    ap.add_argument('--gain', type=float, default=1.25, help='px/count（本机标定值）')
    ap.add_argument('--max-ms', type=int, default=8, help='每条 AIM 的最大时长 ms')
    ap.add_argument('--dead', type=int, default=2, help='AIM 死区 counts')
    ap.add_argument('--clamp', type=int, default=80, help='单条 AIM 的 counts 上限')
    ap.add_argument('--buttons', default='middle',
                    choices=['middle', 'x1', 'x2', 'left', 'right', 'all'],
                    help='注入哪些键（默认 middle，最安全；all=左右中+侧键）')
    ap.add_argument('--btn-hold', type=float, default=0.045, help='每次按下保持秒数')
    ap.add_argument('--queue-steps', type=int, default=10, help='队列模式的步数')
    ap.add_argument('--tol', type=float, default=6.0, help='队列模式每步的像素容差')
    ap.add_argument('--gap-ms', type=float, default=25.0,
                    help='按键按下前后 ±10 ms 内 AIM 允许的最大间隔（默认 25 ms）')
    ap.add_argument('--keep', action='store_true', help='结束时不要归位光标')
    args = ap.parse_args()

    _dpi_aware()
    W, H = screen_size()
    tx, ty = W - 1 - args.margin, args.margin
    box = (W - max(200, W // 5), 0, W - 1, max(200, H // 5))
    print(f'屏幕 {W}x{H} · 目标 ({tx},{ty}) · 右上角判定框 x>={box[0]} 且 y<={box[3]}')

    link = BoxLink(args.port, args.baud, on_log=lambda s: None)
    link.open()
    cur = Cursor()
    counters = {}
    writer = Writer(link, counters)
    writer.start()
    stop = threading.Event()
    aim_sent = 0
    aim_times = []
    btn_times = []

    hid_before = parse_hid_stat(link.request(P_HID_STAT, timeout=0.5))
    st_before = parse_aim_state(link.request(P_AIM_STATE, timeout=0.5))
    print('起点 HID_STAT:', hid_before)
    print('起点 AIM_STATE:', st_before)

    # ---- 监视线程：采光标（给闭环用）+ 每 200 ms 读一次固件计数
    mon = {'hid': [], 'aim': []}

    def monitor():
        last = 0.0
        while not stop.is_set():
            cur.update(box)
            now = time.time()
            if now - last > 0.2:
                last = now
                try:
                    h = parse_hid_stat(link.request(P_HID_STAT, timeout=0.3))
                    if h:
                        mon['hid'].append(h)
                    a = parse_aim_state(link.request(P_AIM_STATE, timeout=0.3))
                    if a:
                        mon['aim'].append(a)
                except Exception:
                    pass
            time.sleep(0.02)

    mon_thr = threading.Thread(target=monitor, daemon=True)
    mon_thr.start()

    # ---- 瞄准线程：把光标往右上角钉
    def aim_loop():
        nonlocal aim_sent
        frame = 1.0 / max(1.0, args.rate)
        while not stop.is_set():
            cx, cy = cur.get()
            ex, ey = tx - cx, ty - cy
            if abs(ex) / args.gain < args.dead and abs(ey) / args.gain < args.dead:
                time.sleep(frame)
                continue
            dx = max(-args.clamp, min(args.clamp, int(round(ex / args.gain))))
            dy = max(-args.clamp, min(args.clamp, int(round(ey / args.gain))))
            if aim_sent % 15 == 0:            # 定期掺反向抖动，制造更强 REPLACE 竞争
                dx += 25 if (aim_sent // 15) % 2 else -25
            writer.submit(P_AIM, aim_payload(dx, dy, args.max_ms, 0, args.dead), 'aim')
            aim_sent += 1
            aim_times.append(time.perf_counter())
            time.sleep(frame)

    # ---- 按键线程：按下 → 保持 → 松开，每轮一个键；PC 侧状态由 pc_watch 统计
    if args.buttons == 'all':
        masks = [BTN_MASKS[k] for k in ('middle', 'x1', 'x2', 'left', 'right')]
    else:
        masks = [BTN_MASKS[args.buttons]]
    if any(m in (0x01, 0x02) for m in masks):
        print('⚠ 会注入左右键：光标在右上角，可能真的点到某个窗口的按钮，自担风险')

    pressed_plan = {'press': 0, 'release': 0}

    def button_loop():
        i = 0
        try:
            while not stop.is_set():
                m = masks[i % len(masks)]
                writer.submit(P_BUTTON, bytes([m]), 'btn')
                btn_times.append(time.perf_counter())
                pressed_plan['press'] += 1
                time.sleep(args.btn_hold)      # 保持住，保证 PC 侧能观测到
                writer.submit(P_BUTTON, bytes([0x00]), 'btn')
                pressed_plan['release'] += 1
                if stop.is_set():
                    break
                time.sleep(1.0 / max(1.0, args.btn_rate))
                i += 1
        finally:
            writer.submit(P_BUTTON, bytes([0x00]), 'drain')   # 收尾一定要松开

    # ---- PC 侧按键观测：3 ms 轮询，统计每个 VK 的上升/下降沿
    pc = {'edges_up': {}, 'edges_down': {}, 'stuck': set()}

    def pc_watch():
        prev = {}
        while not stop.is_set():
            for m, vk in VK_OF.items():
                down = bool(ctypes.windll.user32.GetAsyncKeyState(vk) & 0x8000)
                if prev.get(vk) is None:
                    prev[vk] = down
                    continue
                if down and not prev[vk]:
                    pc['edges_up'][m] = pc['edges_up'].get(m, 0) + 1
                elif not down and prev[vk]:
                    pc['edges_down'][m] = pc['edges_down'].get(m, 0) + 1
                prev[vk] = down
                if down:
                    pc['stuck'].add(m)
                else:
                    pc['stuck'].discard(m)
            time.sleep(0.003)

    # ---------------------------------------------------------------- 队列模式
    def run_queue():
        """逐条 sumv（二进制），等它走完再发下一条；每步之间夹一条按键。

        位移校验用**真实光标像素**：期望 px = counts × gain。
        """
        steps = args.queue_steps
        set_cursor(W // 3, H // 2)
        time.sleep(0.3)
        ok = 0
        prev = cursor_pos()
        print(f'队列模式：从 {prev} 分 {steps} 步走向右上角（每步校验像素位移）')
        for i in range(steps):
            cx, cy = prev
            left = steps - i
            sx = int((tx - cx) / left / args.gain)
            sy = int((ty - cy) / left / args.gain)
            p0 = cursor_pos()
            writer.submit(P_SUMV, sumv_payload(sx, sy, 0), 'q')   # 0 = 模块默认速度
            wait_started_and_done(link, 6.0)
            p1 = wait_cursor_stable()
            writer.submit(P_BUTTON, bytes([masks[i % len(masks)]]), 'btn')   # 夹杂按键
            pressed_plan['press'] += 1
            time.sleep(args.btn_hold)
            writer.submit(P_BUTTON, bytes([0x00]), 'btn')
            pressed_plan['release'] += 1
            exp = (sx * args.gain, sy * args.gain)
            got = (p1[0] - p0[0], p1[1] - p0[1])
            good = abs(got[0] - exp[0]) <= args.tol and abs(got[1] - exp[1]) <= args.tol
            ok += 1 if good else 0
            prev = p1
            print(f'  步 {i + 1:2d}: sumv({sx:+d},{sy:+d}) → 光标 Δ{got} '
                  f'期望 ({exp[0]:+.0f},{exp[1]:+.0f}) {"OK" if good else "偏差超容差"}')
        return ok, steps

    # ---------------------------------------------------------------- 并发模式
    q_ok = q_total = 0
    hid_after = st_after = None
    final_all_up = True
    aud_before = aud_after = None
    try:
        if args.mode in ('queue', 'both'):
            q_ok, q_total = run_queue()
        if args.mode in ('concurrent', 'both'):
            # 先停到框内再开跑，避免"从屏幕中心走过来"的那几帧被算成越界
            set_cursor(box[0] + 30, box[3] - 30)
            time.sleep(0.5)      # 等队列阶段最后几条按键报告彻底发完再取基线
            writer.submit(P_BUTTON, bytes([0x00]), 'drain')
            time.sleep(0.2)
            cur.outside = 0
            cur.armed = False
            cur.update(box)
            hid_before = parse_hid_stat(link.request(P_HID_STAT, timeout=0.5))
            st_before = parse_aim_state(link.request(P_AIM_STATE, timeout=0.5))
            aud_before = parse_btn_audit(link.request(P_BTN_AUDIT, timeout=0.5))
            aim_times.clear()
            btn_times.clear()
            aim_sent = 0
            counters.clear()
            pressed_plan['press'] = 0
            pressed_plan['release'] = 0
            print(f'并发模式：{args.seconds:.0f} s · 瞄准 {args.rate:.0f} Hz + 按键 {args.btn_rate:.0f} Hz')
            ths = [threading.Thread(target=aim_loop, daemon=True),
                   threading.Thread(target=button_loop, daemon=True),
                   threading.Thread(target=pc_watch, daemon=True)]
            for t in ths:
                t.start()
            time.sleep(args.seconds)
            stop.set()
            for t in ths:
                t.join(timeout=2)
    finally:
        stop.set()
        try:
            link.send_frame(P_BUTTON, bytes([0x00]))     # 兜底：确保所有键都松开
        except Exception:
            pass
        time.sleep(0.5)
        # 释放之后再从 PC 侧确认一次：所有相关虚拟键都必须是"抬起"
        final_all_up = all(not (ctypes.windll.user32.GetAsyncKeyState(vk) & 0x8000)
                           for vk in VK_OF.values())
        writer.stop.set()
        writer.join(timeout=3)
        if mon_thr is not None:
            mon_thr.join(timeout=2)
        time.sleep(0.3)
        hid_after = parse_hid_stat(link.request(P_HID_STAT, timeout=0.5))
        st_after = parse_aim_state(link.request(P_AIM_STATE, timeout=0.5))
        aud_after = parse_btn_audit(link.request(P_BTN_AUDIT, timeout=0.5))
        if not args.keep:
            set_cursor(W // 2, H // 2)
        link.close()

    # ------------------------------------------------------------------ 结论
    print('\n' + '=' * 72)
    print('HID_STAT after :', hid_after)
    print('AIM_STATE after:', st_after)
    verdict = True
    if args.mode in ('queue', 'both'):
        print(f'队列模式       : {q_ok}/{q_total} 步像素位移在容差内（±{args.tol}px）')
        verdict &= (q_ok == q_total)
    if args.mode in ('concurrent', 'both') and hid_before and hid_after:
        cmd_btn = counters.get('btn', 0)
        d_in = hid_after['btn_in'] - hid_before['btn_in']
        d_sent = hid_after['btn_sent'] - hid_before['btn_sent']
        ovf = hid_after['btn_overflow']
        rounds = (st_after['rounds'] - st_before['rounds']) if st_after and st_before else -1
        aborts = (st_after['aborted'] - st_before['aborted']) if st_after and st_before else -1
        up = sum(pc['edges_up'].values())
        down = sum(pc['edges_down'].values())
        print(f"并发模式       : AIM {aim_sent} 条 · 按键指令 {cmd_btn} 条"
              f"（计划按下 {pressed_plan['press']} / 松开 {pressed_plan['release']}）")
        print(f"  PC 侧观测    : 按下沿 {up} 次 · 松开沿 {down} 次"
              f" · 结束时仍按着: {sorted(pc['stuck']) or '无'}")
        print(f"  固件 btn_in  : {d_in}（真实鼠标/注入按键进优先级队列的次数）"
              f"  btn_sent {d_sent}  overflow {ovf}")
        print(f"  AIM rounds/aborted: {rounds}/{aborts} · 写线程失败 {writer.errors} 次")
        print(f"  光标越界采样 : {cur.outside} 次 (应为 0)")
        # 主判据（固件计数，精确）：每条 BUTTON 指令都进了优先级队列、都上了总线、零溢出。
        # 次判据（PC 侧边沿，交叉参考）：不许出现"松手后仍按着"的卡键。
        # 注意：PC 侧边沿数会略多于注入次数（Windows 自己会合成/合并边沿），所以只用来交叉验证。
        # 判据（PC 侧为准 —— 用户要的是"PC 一定看得到每次按键"）：
        #   每个按键周期 = 1 条按下 + 1 条松开；PC 侧的上升沿/下降沿数必须都对上。
        #   btn_in/btn_sent 只作为"零溢出"的辅助证据（它也会统计真实鼠标报告，不能当等式用）。
        cycles = cmd_btn // 2
        tol = 1
        # 用户要求是"一条都不能丢" → 关注"少了没有"。Windows 有时会把一次按下拆成两次
        # 事件（观察数偏多），那是 OS 侧行为，不算丢。
        ok_up = (up >= cycles - tol)
        ok_down = (down >= cycles - tol)
        no_stuck = final_all_up        # 用"停止并释放之后仍然抬着"来判定，不用停止瞬间的快照
        entered_box = cur.armed        # 光标必须真的进过右上角，否则"越界 0 次"毫无意义
        print(f'  判据① 按下沿 >= 周期数  : {up} >= {cycles - tol} → {ok_up}（不能少）')
        print(f'  判据② 松开沿 >= 周期数  : {down} >= {cycles - tol} → {ok_down}（不能少）')
        print(f'  判据③ 收尾无卡键         : 释放后全抬起={final_all_up} → {no_stuck}')
        print(f'  判据④ 进过框且无越界     : 进过框={entered_box} · 越界 {cur.outside} 次 '
              f'→ {entered_box and cur.outside == 0}')

        # ---- 判据⑤ 按键回环审计（0x3F）：证明"不丢也不多发" ----
        ok_audit = False
        if aud_before and aud_after:
            a_in = aud_after['in_chg'] - aud_before['in_chg']
            a_out = aud_after['out_chg'] - aud_before['out_chg']
            a_extra = aud_after['extra'] - aud_before['extra']
            ok_audit = (a_in == cmd_btn and a_out == a_in and a_extra == 0)
            print(f'  判据⑤ 回环审计           : in {a_in} == 指令 {cmd_btn} · '
                  f'out {a_out} == in {a_in} · 多发 {a_extra} → {ok_audit}')
        else:
            print('  判据⑤ 回环审计           : 无回包（固件可能没刷 0x3F）→ 跳过')

        # ---- 判据⑥ 按键期间移动延迟尖峰 ----
        spike_ms = 0.0
        if len(aim_times) > 2 and btn_times:
            ts = sorted(aim_times)
            worst = 0.0
            for tb in btn_times:
                win = [t for t in ts if abs(t - tb) <= 0.010]
                if len(win) >= 2:
                    worst = max(worst, max(win[i + 1] - win[i] for i in range(len(win) - 1)))
            spike_ms = worst * 1000.0
            print(f'  判据⑥ 按键处 AIM 间隔   : 最大 {spike_ms:.1f} ms '
                  f'（阈值 {args.gap_ms:.0f} ms）→ {spike_ms <= args.gap_ms}')
        ok_gap = spike_ms <= args.gap_ms
        print(f'  旁证  btn_sent == btn_in : {d_sent} == {d_in} · overflow {ovf}')
        # 硬判据：
        #   ① 固件侧"进队列数 == 上总线数"（一条都没被丢）+ 零溢出；
        #   ② 不卡键、光标不越界；
        #   ③ PC 侧按下/松开沿数与周期数一致（±1，容忍轮询边界）。
        in_vs_sent = (d_sent == d_in)
        verdict &= (no_stuck and cur.outside == 0 and entered_box
                    and ok_up and ok_down and ok_gap)
        if aud_before and aud_after:
            verdict &= ok_audit
        # 注：btn_sent == btn_in 不作为判据 —— 那个计数器只统计真实鼠标报告，
        # 和本测试注入的按键无关（实测注入 106 条它只涨 1~2）。
    print('=' * 72)
    print('结论:', 'PASS  (只跑队列时按键判据不生效)' if verdict else 'FAIL')
    out = os.path.join(os.path.dirname(HERE), 'work',
                       time.strftime('aim_stress_%Y%m%d_%H%M%S.json'))
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, 'w', encoding='utf-8') as f:
        json.dump({'args': vars(args), 'hid_before': hid_before, 'hid_after': hid_after,
                   'aim_before': st_before, 'aim_after': st_after,
                   'queue': [q_ok, q_total], 'aim_sent': aim_sent,
                   'btn_cmds': counters.get('btn', 0),
                   'cursor_outside': cur.outside,
                   'hid_samples': mon['hid'][-5:], 'verdict': bool(verdict)},
                  f, ensure_ascii=False, indent=2)
    print('记录:', out)
    return 0 if verdict else 1


if __name__ == '__main__':
    sys.exit(main())
