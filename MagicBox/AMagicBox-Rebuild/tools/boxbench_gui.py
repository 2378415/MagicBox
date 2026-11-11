"""boxbench_gui - MagicBox 控制口台架工具（Windows 桌面版，Tkinter）

用法：
    python tools/boxbench_gui.py                      # 开界面（默认 COM3 @921600）
    python tools/boxbench_gui.py --port COM5
    python tools/boxbench_gui.py --selftest           # 不开界面，跑一遍链路+轨迹+导出自检
    python tools/boxbench_gui.py --suite smoke        # 无头冒烟（连通/克隆/守恒/手感/事件）

界面分区：连接条 / 左侧状态+sumv 控制 / 右侧「轨迹·事件·日志」/ 底部测试按钮。
所有串口访问在后台线程，主线程只做界面刷新。
"""
from __future__ import annotations

import argparse
import os
import queue
import statistics
import subprocess
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from boxbench import plots                                  # noqa: E402
from boxbench.link import (BoxLink, P_EVT_CTL, P_EVT_READ, P_PING,  # noqa: E402
                           P_SUMV, P_SUMV_STOP, P_SUMV_STATE)

DEFAULT_PORT = os.environ.get('MAKCU_PORT', 'COM3')
DEFAULT_BAUD = int(os.environ.get('MAKCU_BAUD', '921600'))


# --------------------------------------------------------------------- 自检
def run_selftest(port, baud):
    print(f'== 自检 {port} @{baud} ==')
    link = BoxLink(port, baud, on_log=lambda s: print(' ', s))
    link.open()
    ok = True
    try:
        v = link.text_request('.km.version()')
        print('version      :', v)
        ok &= (v == 'km.MAKCU')
        dts = []
        for i in range(20):
            t0 = time.perf_counter()
            r = link.request(P_PING, i.to_bytes(4, 'little'))
            if r is None:
                ok = False
                continue
            dts.append((time.perf_counter() - t0) * 1e6)
        if dts:
            dts.sort()
            print(f'ping x{len(dts):<3}   : p50 {statistics.median(dts):.0f} us  '
                  f'max {dts[-1]:.0f} us')
        print('clone        :', link.text_request('mx.if'), '|', link.text_request('mx.rb'))
        link.text_request('mx.mt clr')
        link.text_request('mx.mt on')
        print('sumv start   :', link.text_request('.km.sumv(300,0,2000)'))
        st = link.wait_motion_done(6.0)
        print('sumv state   :', st)
        ok &= bool(st and st['rounds'] >= 1)
        time.sleep(0.2)
        entries = link.dump_motion()
        samples = plots.decode_injected(entries)
        m = plots.metrics(samples, 300, 0)
        for line in plots.summary_lines(m):
            print('  ', line)
        ok &= bool(m.get('ok')) and m['exact']
        out = os.path.join(os.path.dirname(HERE), 'work', 'boxbench_selftest.png')
        os.makedirs(os.path.dirname(out), exist_ok=True)
        plots.export_png(out, samples, m, title='boxbench 自检：sumv(300,0,2000)',
                         meta=[f'port {port} @{baud}'])
        print('png          :', out)
    finally:
        link.close()
    print('== 自检', 'PASS' if ok else 'FAIL', '==')
    return 0 if ok else 1


# ------------------------------------------------------------------- 主界面
class App:
    def __init__(self, root, port, baud, autoconnect=True):
        import tkinter as tk
        from tkinter import ttk
        self.tk, self.ttk = tk, ttk
        self.root = root
        self.port, self.baud = port, baud
        self.link: BoxLink | None = None
        self.uiq: queue.Queue = queue.Queue()
        self.subscribed = False
        self.busy = False

        root.title('MagicBox 台架工具 · boxbench')
        root.geometry('1200x780')
        root.configure(bg='#0e1114')

        self._build_conn()
        self._build_tests(root)          # 先占住底部，保证永远可见
        body = ttk.Frame(root)
        body.pack(fill='both', expand=True, padx=8, pady=6)
        left = ttk.Frame(body, width=300)
        left.pack(side='left', fill='y')
        left.pack_propagate(False)
        self._build_status(left)
        self._build_sumv(left)
        right = ttk.Frame(body)
        right.pack(side='left', fill='both', expand=True, padx=(8, 0))
        self._build_tabs(right)

        root.after(30, self._pump)
        root.after(1500, self._hb)
        if autoconnect:
            root.after(300, self.toggle_conn)

    # ------------------------------------------------------------ 连接条
    def _build_conn(self):
        tk, ttk = self.tk, self.ttk
        bar = ttk.Frame(self.root)
        bar.pack(fill='x', padx=8, pady=(8, 0))
        ttk.Label(bar, text='端口').pack(side='left')
        self.port_var = tk.StringVar(value=self.port)
        ports = [self.port]
        try:
            from serial.tools import list_ports
            for p in list_ports.comports():
                if p.device not in ports:
                    ports.append(p.device)
        except Exception:
            pass
        self.port_cb = ttk.Combobox(bar, textvariable=self.port_var, values=ports, width=8)
        self.port_cb.pack(side='left', padx=(4, 10))
        ttk.Label(bar, text='波特率').pack(side='left')
        self.baud_var = tk.StringVar(value=str(self.baud))
        ttk.Combobox(bar, textvariable=self.baud_var, values=['921600', '115200'],
                     width=8).pack(side='left', padx=(4, 10))
        self.dtr = tk.BooleanVar(value=False)
        self.rts = tk.BooleanVar(value=False)
        ttk.Checkbutton(bar, text='DTR', variable=self.dtr).pack(side='left')
        ttk.Checkbutton(bar, text='RTS', variable=self.rts).pack(side='left', padx=(0, 10))
        self.btn_conn = ttk.Button(bar, text='连接', command=self.toggle_conn, width=8)
        self.btn_conn.pack(side='left')
        self.dot = ttk.Label(bar, text='● 未连接', foreground='#888')
        self.dot.pack(side='left', padx=10)
        ttk.Label(bar, text='（设备刚上电约 1 s 后才会应答；串口独占，别同时开别的脚本）',
                  foreground='#667').pack(side='left')

    # ------------------------------------------------------------ 状态面板
    def _build_status(self, parent):
        ttk, tk = self.ttk, self.tk
        box = ttk.LabelFrame(parent, text='状态（2 s 刷新）')
        box.pack(fill='x', pady=(0, 6))
        self.stat_vars = {}
        for i, key in enumerate(('克隆', 'sumv', '事件', '链路')):
            v = tk.StringVar(value='—')
            self.stat_vars[key] = v
            ttk.Label(box, text=key, width=5).grid(row=i, column=0, sticky='nw', padx=(6, 0), pady=2)
            ttk.Label(box, textvariable=v, foreground='#2980b9', wraplength=232,
                      justify='left').grid(row=i, column=1, sticky='w', pady=2)

    # ------------------------------------------------------------ sumv 控制
    def _build_sumv(self, parent):
        ttk, tk = self.ttk, self.tk
        box = ttk.LabelFrame(parent, text='sumv')
        box.pack(fill='x', pady=(0, 6))
        grid = ttk.Frame(box)
        grid.pack(fill='x', padx=6, pady=4)
        self.dx_var = tk.StringVar(value='300')
        self.dy_var = tk.StringVar(value='0')
        self.speed_var = tk.IntVar(value=2000)
        for i, (label, var, width) in enumerate((('dx', self.dx_var, 7), ('dy', self.dy_var, 7))):
            ttk.Label(grid, text=label).grid(row=0, column=i * 2, sticky='w')
            ttk.Entry(grid, textvariable=var, width=width).grid(row=0, column=i * 2 + 1, padx=(2, 8))
        ttk.Label(grid, text='speed').grid(row=1, column=0, sticky='w')
        ttk.Entry(grid, textvariable=self.speed_var, width=7).grid(row=1, column=1, padx=(2, 8))
        ttk.Scale(grid, from_=50, to=65535, variable=self.speed_var, orient='horizontal',
                  length=150).grid(row=1, column=2, columnspan=2, sticky='we')
        self.maxrep_var = tk.StringVar(value='0')
        ttk.Label(grid, text='每报告上限').grid(row=2, column=0, sticky='w')
        ttk.Entry(grid, textvariable=self.maxrep_var, width=5).grid(row=2, column=1, padx=(2, 8))
        ttk.Label(grid, text='(0=自动跟速度；8–120 固定)',
                  foreground='#667').grid(row=2, column=2, columnspan=2, sticky='w')

        self.human = tk.BooleanVar(value=False)
        self.tremor = tk.BooleanVar(value=False)
        self.submove = tk.BooleanVar(value=False)
        self.maxspeed = tk.BooleanVar(value=False)
        bits = ttk.Frame(box)
        bits.pack(fill='x', padx=6)
        ttk.Checkbutton(bits, text='极速(bit7)', variable=self.maxspeed).pack(side='left', padx=(0, 8))
        ttk.Checkbutton(bits, text='拟人(bit6)', variable=self.human).pack(side='left')
        ttk.Checkbutton(bits, text='手颤', variable=self.tremor).pack(side='left')
        ttk.Checkbutton(bits, text='子运动', variable=self.submove).pack(side='left')

        btns = ttk.Frame(box)
        btns.pack(fill='x', padx=6, pady=6)
        ttk.Button(btns, text='发送并抓轨迹', command=self.do_sumv).pack(side='left')
        ttk.Button(btns, text='停止', width=6,
                   command=lambda: self._call(lambda l: l.send_frame(P_SUMV_STOP))).pack(side='left', padx=4)

        box2 = ttk.LabelFrame(parent, text='按键事件')
        box2.pack(fill='x', pady=(0, 6))
        self.evt_mask = {}
        row = ttk.Frame(box2)
        row.pack(fill='x', padx=6, pady=2)
        for name, bit in (('左', 1), ('右', 2), ('中', 4), ('侧4', 8), ('侧5', 16)):
            v = tk.BooleanVar(value=(bit == 8))
            self.evt_mask[bit] = v
            ttk.Checkbutton(row, text=name, variable=v).pack(side='left')
        self.consume = tk.BooleanVar(value=False)
        row3 = ttk.Frame(box2)
        row3.pack(fill='x', padx=6)
        ttk.Checkbutton(row3, text='吃掉这些点击（PC 看不到；默认关 = 穿透）',
                        variable=self.consume).pack(side='left')
        row2 = ttk.Frame(box2)
        row2.pack(fill='x', padx=6, pady=(0, 6))
        self.btn_sub = ttk.Button(row2, text='订阅（事件 + 透传）', command=self.toggle_sub)
        self.btn_sub.pack(side='left')
        ttk.Button(row2, text='读一次', command=self.read_events).pack(side='left', padx=4)

    # -------------------------------------------------------------- 右侧标签页
    def _build_tabs(self, parent):
        ttk, tk = self.ttk, self.tk
        nb = ttk.Notebook(parent)
        nb.pack(fill='both', expand=True)
        self.nb = nb

        page1 = ttk.Frame(nb)
        nb.add(page1, text='轨迹')
        self.canvas = tk.Canvas(page1, width=760, height=330, bg='#111418',
                                highlightthickness=0)
        self.canvas.pack(fill='both', expand=True, padx=6, pady=6)
        self.metric_txt = tk.Text(page1, height=7, bg='#0b0e11', fg='#c8d2dc',
                                  font=('Consolas', 10), relief='flat')
        self.metric_txt.pack(fill='x', padx=6, pady=(0, 6))
        row = ttk.Frame(page1)
        row.pack(fill='x', padx=6, pady=(0, 6))
        ttk.Button(row, text='导出 PNG', command=self.export_png).pack(side='left')
        ttk.Button(row, text='重抓轨迹', command=self.capture_only).pack(side='left', padx=4)

        page2 = ttk.Frame(nb)
        nb.add(page2, text='事件')
        cols = ('seq', 'mask', 'edge', 't_us')
        self.evt_tree = ttk.Treeview(page2, columns=cols, show='headings', height=14)
        for c in cols:
            self.evt_tree.heading(c, text=c)
            self.evt_tree.column(c, width=110, anchor='w')
        self.evt_tree.pack(fill='both', expand=True, padx=6, pady=6)

        page3 = ttk.Frame(nb)
        nb.add(page3, text='日志')
        self.log = tk.Text(page3, bg='#0b0e11', fg='#c8d2dc', font=('Consolas', 10),
                           relief='flat', wrap='none')
        self.log.pack(fill='both', expand=True, padx=6, pady=6)
        self.log.tag_configure('tx', foreground='#81c784')
        self.log.tag_configure('rx', foreground='#4fc3f7')
        self.log.tag_configure('err', foreground='#e57373')
        self.log.tag_configure('evt', foreground='#ffd54f')

    # -------------------------------------------------------------- 测试按钮
    def _build_tests(self, parent):
        ttk = self.ttk
        bar = ttk.Frame(parent)
        bar.pack(fill='x', padx=8, pady=(0, 8))
        for text, fn in (('连通性', self.test_conn), ('延迟 ×100', self.test_ping),
                         ('克隆健康', self.test_clone), ('守恒', self.test_conserve),
                         ('跑回归', self.test_regress)):
            ttk.Button(bar, text=text, command=fn).pack(side='left', padx=2)

    # ---------------------------------------------------------------- 工具
    def _log(self, msg, tag='rx'):
        self.uiq.put(('log', msg, tag))

    def _call(self, fn, *args):
        if not (self.link and self.link.is_open):
            self._log('[!] 串口未连接', 'err')
            return
        threading.Thread(target=lambda: self._guard(fn, self.link, *args),
                         daemon=True).start()

    def _guard(self, fn, link, *args):
        try:
            fn(link, *args)
        except Exception as exc:                      # noqa: BLE001
            self._log(f'[!] {type(exc).__name__}: {exc}', 'err')

    def toggle_conn(self):
        if self.link and self.link.is_open:
            self.link.close()
            self.link = None
            self.btn_conn.configure(text='连接')
            self.dot.configure(text='● 未连接', foreground='#888')
            return
        port = self.port_var.get().strip()
        baud = int(self.baud_var.get())
        link = BoxLink(port, baud,
                       on_text=lambda s: self.uiq.put(('log', f'<< {s}', 'rx')),
                       on_event=lambda seq, pl: self.uiq.put(('evt', seq, pl)),
                       on_log=self._log)
        try:
            link.open()
        except Exception as exc:                      # noqa: BLE001
            msg = str(exc)
            busy = ('拒绝访问' in msg) or ('denied' in msg.lower()) or ('busy' in msg.lower())
            if busy:
                self._log(f'[!] {port} 被占用：可能已经有一个 boxbench 在跑（或其它脚本占着串口）。'
                          f'\n    关掉那个窗口再点"连接"。', 'err')
            else:
                self._log(f'[!] 打开失败: {exc}', 'err')
            return
        self.link = link
        self.btn_conn.configure(text='断开')
        self.dot.configure(text='● 已连接', foreground='#81c784')
        threading.Thread(target=self._poll_status, daemon=True).start()

    def _poll_status(self):
        while self.link is not None and self.link.is_open:
            self._call_inline(lambda l: self._refresh_status(l))
            time.sleep(2.0)

    def _call_inline(self, fn):
        try:
            fn(self.link)
        except Exception:                             # noqa: BLE001
            pass

    def _refresh_status(self, link):
        if link is None:
            return
        iface = link.text_request('mx.if', timeout=0.35)
        rb = link.text_request('mx.rb', timeout=0.35)
        fv = link.text_request('mx.fv', timeout=0.35)
        sv = link.motion_state()
        ev = None
        r = link.request(0x3B, timeout=0.3)
        if r and len(r) >= 12:
            ev = {'seq': r[0] | (r[1] << 8), 'count': r[2],
                  'mask': r[7], 'last_fwd': r[10], 'flags': r[11]}
        ds = link.text_request('mx.ds', timeout=0.35)
        self.uiq.put(('status', {
            '克隆': f'{iface or "?"} | {rb or "?"}' + ('' if (rb and 'bytes=7' in rb) else '  ⚠'),
            'sumv': (f"active={sv['active']} rounds={sv['rounds']} samples={sv['samples']}"
                     if sv else '—'),
            '事件': (f"enabled={ev['flags'] & 1} mask=0x{ev['mask']:02x} "
                     f"last_fwd=0x{ev['last_fwd']:02x} seq={ev['seq']}" if ev else '—'),
            '链路': f'ds={ds or "?"} rx={link.rx_bytes}B  fv={fv or "?"}',
        }))

    def _hb(self):
        try:
            if self.subscribed and self.link and self.link.is_open:
                self.link.heartbeat()
        finally:
            self.root.after(1500, self._hb)

    def _pump(self):
        try:
            while True:
                item = self.uiq.get_nowait()
                kind = item[0]
                if kind == 'log':
                    _, msg, tag = item
                    self.log.insert('end', msg + '\n', tag)
                    self.log.see('end')
                    if int(self.log.index('end-1c').split('.')[0]) > 600:
                        self.log.delete('1.0', '200.0')
                elif kind == 'evt':
                    _, seq, pl = item
                    if len(pl) >= 8:
                        t_us = int.from_bytes(pl[0:4], 'little')
                        eseq = pl[4] | (pl[5] << 8)
                        self.evt_tree.insert('', 0, values=(eseq, f'0x{pl[6]:02x}',
                                                            f'0x{pl[7]:02x}', t_us))
                        self._log(f'[evt] seq={eseq} mask=0x{pl[6]:02x} edge=0x{pl[7]:02x}',
                                  'evt')
                elif kind == 'status':
                    for k, v in item[1].items():
                        self.stat_vars[k].set(v if len(v) <= 64 else v[:61] + '...')
                elif kind == 'traj':
                    try:
                        _, samples, m, lines = item
                    except ValueError:
                        _, samples, m = item
                        lines = plots.summary_lines(m)
                    plots.draw_tk(self.canvas, samples, m)
                    self.metric_txt.delete('1.0', 'end')
                    self.metric_txt.insert('1.0', '\n'.join(lines))
                    m['mr_eff'] = max((abs(s0[1]) + abs(s0[2]) for s0 in samples), default=0)
                    self._last = (samples, m)
        except queue.Empty:
            pass
        self.root.after(30, self._pump)

    # ------------------------------------------------------------ sumv 流程
    def _mode_byte(self):
        m = 0x80 if self.maxspeed.get() else 0
        if self.human.get():
            m |= 0x40
            if self.tremor.get():
                m |= 0x02
            if self.submove.get():
                m |= 0x04
        return m

    def do_sumv(self):
        try:
            dx = int(self.dx_var.get())
            dy = int(self.dy_var.get())
            speed = max(50, min(65535, int(self.speed_var.get())))
        except ValueError:
            self._log('[!] dx/dy/speed 必须是整数', 'err')
            return
        mode = self._mode_byte()
        try:
            mr_raw = int(self.maxrep_var.get())
            maxrep = 0 if mr_raw == 0 else max(8, min(120, mr_raw))
        except ValueError:
            maxrep = 12
        self._call(self._flow_sumv, dx, dy, speed, mode, maxrep)

    def _flow_sumv(self, link, dx, dy, speed, mode, maxrep=60):
        self._log(f'[flow] sumv({dx},{dy},{speed},mode=0x{mode:02x},maxrep={maxrep})')
        link.text_request(f'mx.mv {speed} {maxrep}', timeout=0.4)
        c0 = c1 = None
        try:
            from aim_move import cursor_pos, screen_size, _dpi_aware
            _dpi_aware()
            self._screen = screen_size()
            c0 = cursor_pos()
        except Exception as exc:                       # noqa: BLE001
            self._log(f'[warn] 读光标失败（不影响轨迹）: {exc}', 'err')
        link.text_request('mx.mt clr', timeout=0.4)
        link.text_request('mx.mt on', timeout=0.4)
        rt0 = link.text_request('mx.rt', timeout=0.4)
        link.send_frame(P_SUMV, (dx & 0xFFFF).to_bytes(2, 'little', signed=True)
                        + (dy & 0xFFFF).to_bytes(2, 'little', signed=True)
                        + (speed & 0xFFFF).to_bytes(2, 'little')
                        + bytes([mode, 0]))
        st = link.wait_motion_done(8.0)
        rt1 = link.text_request('mx.rt', timeout=0.4)
        self._log(f'[flow] state={st} rt {rt0} -> {rt1}')
        try:
            if c0 is not None:
                time.sleep(0.12)
                c1 = cursor_pos()
        except Exception:                              # noqa: BLE001
            c1 = None
        self._capture(link, dx, dy, c0, c1)

    def capture_only(self):
        try:
            dx, dy = int(self.dx_var.get()), int(self.dy_var.get())
        except ValueError:
            dx = dy = 0
        self._call(self._capture, dx, dy)

    def _capture(self, link, dx, dy, c0=None, c1=None):
        entries = link.dump_motion()
        samples = plots.decode_injected(entries)
        m = plots.metrics(samples, dx, dy)
        self._log(f'[traj] 抓到 {len(samples)} 条注入样本', 'rx')
        lines = plots.summary_lines(m)
        mr_eff = (m.get('mr_eff') or 0)
        if mr_eff:
            lines.append(f'本次每报告上限 mr={mr_eff}（≈{mr_eff * 1.25:.0f} px/跳）')
        if c0 is not None and c1 is not None:
            px = (c1[0] - c0[0], c1[1] - c0[1])
            n = max(1, abs(m.get('sum_dx', 0)) + abs(m.get('sum_dy', 0)))
            gain = (abs(px[0]) + abs(px[1])) / n if n else 0.0
            sw, sh = getattr(self, '_screen', (0, 0))
            hit = (c1[0] <= 0 or c1[0] >= sw - 1 or c1[1] <= 0 or c1[1] >= sh - 1)
            lines.append(f'光标 {c0} → {c1} = {px[0]:+d},{px[1]:+d} px · '
                         f'实测增益 {gain:.2f} px/count' + ('  ⚠ 撞边（counts 被系统吃掉）' if hit else ''))
        for line in lines:
            self._log('   ' + line, 'rx')
        self.uiq.put(('traj', samples, m, lines))

    def export_png(self):
        if not getattr(self, '_last', None):
            self._log('[!] 还没有轨迹可导出', 'err')
            return
        samples, m = self._last
        out = os.path.join(os.path.dirname(HERE), 'work',
                           time.strftime('sumv_%Y%m%d_%H%M%S.png'))
        os.makedirs(os.path.dirname(out), exist_ok=True)
        plots.export_png(out, samples, m,
                         title=f"sumv({m['req_dx']},{m['req_dy']}) 轨迹",
                         meta=[f'port {self.port_var.get()} @{self.baud_var.get()}',
                               time.strftime('%Y-%m-%d %H:%M:%S')])
        self._log(f'[png] {out}', 'rx')

    # ------------------------------------------------------------ 按键事件
    def toggle_sub(self):
        if not (self.link and self.link.is_open):
            self._log('[!] 串口未连接', 'err')
            return
        if self.subscribed:
            self.link.send_frame(P_EVT_CTL, bytes([0, 0, 0, 0]))
            self.subscribed = False
            self.btn_sub.configure(text='订阅（事件 + 透传）')
            self._log('[evt] 已取消订阅（恢复全透传）')
            return
        mask = 0
        for bit, var in self.evt_mask.items():
            if var.get():
                mask |= bit
        if mask == 0:
            self._log('[!] 先勾一个按键', 'err')
            return
        consume = 1 if self.consume.get() else 0
        self.link.send_frame(P_EVT_CTL, bytes([1, mask, 1, consume]))
        self.subscribed = True
        self.btn_sub.configure(text='取消订阅（恢复透传）')
        if consume:
            self._log(f'[evt] 已订阅 mask=0x{mask:02x}（**吃掉**：这些键 PC 看不到）', 'evt')
        else:
            self._log(f'[evt] 已订阅 mask=0x{mask:02x}（**穿透**：按键照常给 PC，只上报事件）', 'evt')

    def read_events(self):
        self._call(self._read_events)

    def _read_events(self, link):
        for _ in range(8):
            r = link.request(P_EVT_READ, bytes([7]), timeout=0.4)
            if not r or r[0] == 0:
                break
            for i in range(r[0]):
                ev = r[1 + i * 8:9 + i * 8]
                if len(ev) < 8:
                    break
                print_evt = (ev[4] | (ev[5] << 8), f'0x{ev[6]:02x}', f'0x{ev[7]:02x}',
                             int.from_bytes(ev[0:4], 'little'))
                self.evt_tree.insert('', 0, values=print_evt)

    # ---------------------------------------------------------------- 测试
    def test_conn(self):
        def run(link):
            v = link.text_request('.km.version()')
            ok = (v == 'km.MAKCU')
            self._log(f"[test] version={v} → {'PASS' if ok else 'FAIL'}",
                      'rx' if ok else 'err')
        self._call(run)

    def test_ping(self):
        def run(link):
            dts = []
            lost = 0
            for i in range(100):
                t0 = time.perf_counter()
                r = link.request(P_PING, i.to_bytes(4, 'little'), timeout=0.3)
                if r is None:
                    lost += 1
                else:
                    dts.append((time.perf_counter() - t0) * 1e6)
            if not dts:
                self._log('[test] PING 全丢', 'err')
                return
            dts.sort()
            p = lambda q: dts[min(len(dts) - 1, int(q * len(dts)))]
            self._log(f'[test] PING x100 lost={lost} p50={p(.5):.0f}us '
                      f'p90={p(.9):.0f}us p99={p(.99):.0f}us', 'rx')
        self._call(run)

    def test_clone(self):
        def run(link):
            iface = link.text_request('mx.if')
            rb = link.text_request('mx.rb')
            ok = bool(iface and iface.startswith('km.2')) and bool(rb and 'bytes=7' in rb)
            self._log(f"[test] if={iface} rb={rb} → {'PASS' if ok else 'FAIL(克隆不健康)'}",
                      'rx' if ok else 'err')
        self._call(run)

    def test_conserve(self):
        def run(link):
            for dx, dy, speed in ((200, 0, 1500), (0, -150, 1500), (400, 300, 2000)):
                rt0 = link.text_request('mx.rt')
                link.send_frame(P_SUMV, (dx & 0xFFFF).to_bytes(2, 'little', signed=True)
                                + (dy & 0xFFFF).to_bytes(2, 'little', signed=True)
                                + (speed & 0xFFFF).to_bytes(2, 'little') + bytes([0, 0]))
                link.wait_motion_done(6.0)
                rt1 = link.text_request('mx.rt')
                self._log(f'[test] sumv({dx},{dy}) rt {rt0} → {rt1}', 'rx')
        self._call(run)

    def test_regress(self):
        def run():
            proj = os.path.dirname(HERE)
            self._log('[test] 正在跑回归：断开串口…', 'rx')
            if self.link and self.link.is_open:
                self.link.close()
                self.link = None
                self.btn_conn.configure(text='连接')
                self.dot.configure(text='● 未连接', foreground='#888')
            env = dict(os.environ, MAKCU_PORT=self.port_var.get(), MAKCU_BAUD=self.baud_var.get())
            proc = subprocess.run([sys.executable, '-m', 'pytest', 'verification/regress', '-q'],
                                  cwd=proj, env=env, capture_output=True, text=True)
            tail = (proc.stdout or '').strip().splitlines()[-4:]
            for line in tail:
                self._log('[pytest] ' + line, 'rx' if proc.returncode == 0 else 'err')
            self._log(f'[pytest] exit={proc.returncode}', 'rx' if proc.returncode == 0 else 'err')
        threading.Thread(target=lambda: self._guard(lambda *_: run()), daemon=True).start()


# ------------------------------------------------------------------- 无头冒烟
def run_suite(port, baud, suite='smoke'):
    link = BoxLink(port, baud, on_log=lambda s: print(' ', s))
    link.open()
    fails = []
    try:
        v = link.text_request('.km.version()')
        print('1 连通   :', v, '→', 'PASS' if v == 'km.MAKCU' else 'FAIL')
        iface, rb = link.text_request('mx.if'), link.text_request('mx.rb')
        ok = bool(iface and iface.startswith('km.2')) and bool(rb and 'bytes=7' in rb)
        print('2 克隆   :', iface, rb, '→', 'PASS' if ok else 'FAIL')
        rt0 = link.text_request('mx.rt')
        link.text_request('mx.mt clr')
        link.text_request('mx.mt on')
        link.send_frame(P_SUMV, (500).to_bytes(2, 'little', signed=True)
                        + (0).to_bytes(2, 'little', signed=True)
                        + (2000).to_bytes(2, 'little') + bytes([0, 0]))
        st = link.wait_motion_done(6.0)
        rt1 = link.text_request('mx.rt')
        print('3 守恒   :', rt0, '→', rt1, 'state=', st)
        samples = plots.decode_injected(link.dump_motion())
        m = plots.metrics(samples, 500, 0)
        for line in plots.summary_lines(m):
            print('           ', line)
        if not m.get('ok') or not m['exact']:
            fails.append('守恒/轨迹')
        if m.get('ok') and m['start5_pct'] > 20:
            fails.append('起步占比异常')
        print('4 手感   : 起步', f"{m.get('start5_pct', -1):.1f}%", '尾段',
              f"{m.get('tail5_pct', -1):.1f}%")
        link.send_frame(P_EVT_CTL, bytes([1, 8, 1]))
        time.sleep(0.3)
        print('5 事件   : 已订阅 mask=0x08（10 s 内无心跳会自动解除）')
        link.send_frame(P_EVT_CTL, bytes([0, 0, 0]))
    finally:
        link.close()
    print('冒烟结果 :', 'PASS' if not fails else 'FAIL ' + ','.join(fails))
    return 0 if not fails else 1


def main():
    ap = argparse.ArgumentParser(description='MagicBox 台架 GUI')
    ap.add_argument('--port', default=DEFAULT_PORT)
    ap.add_argument('--baud', type=int, default=DEFAULT_BAUD)
    ap.add_argument('--selftest', action='store_true', help='不开界面，跑链路+轨迹+导出自检')
    ap.add_argument('--suite', choices=['smoke'], help='无头冒烟')
    ap.add_argument('--no-autoconnect', action='store_true',
                    help='打开界面后不自动连接（默认会自动连 --port）')
    args = ap.parse_args()

    if args.selftest:
        return run_selftest(args.port, args.baud)
    if args.suite:
        return run_suite(args.port, args.baud, args.suite)

    import tkinter as tk
    from tkinter import ttk
    root = tk.Tk()
    style = ttk.Style(root)
    try:
        style.theme_use('clam')
    except Exception:
        pass
    App(root, args.port, args.baud, autoconnect=not args.no_autoconnect)
    root.mainloop()
    return 0


if __name__ == '__main__':
    sys.exit(main())
