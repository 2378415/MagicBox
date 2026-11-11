"""trace_motion.py - 采集并分析控制口（mx.mt）的报告序列，回答
"从盒子里转发出去的鼠标移动，是否符合人工操作轨迹"。

数据来源（关键）：不是抓包、不是驱动层，而是**左片 HID 提交前的那一跳**
（app_left 的 link_report_to_mouse → mt_tap）。每条记录是
`(本机 µs 时间戳, ep, 报告长度, 原始报告字节)`，因此它描述的是"PC 侧实际会收到什么"，
而不是"传感器产生了什么"。盒子若发生合并/限流/丢帧，会直接反映在这份时间序列里。

两种用法：

  # 采集（先 arm，等 seconds 秒，再一次性 dump 并冻结环形缓冲）
  python tools/trace_motion.py --capture 12 --out work/motion.json
  # 离线复算（同一份数据可重复出报告）
  python tools/trace_motion.py --analyze work/motion.json --report verification/motion_analysis.md

只用标准库，不依赖 numpy。
"""
import argparse
import json
import math
import os
import re
import statistics
import sys
import time

try:
    import serial
except ImportError:
    serial = None

PORT = os.environ.get('MAKCU_PORT', 'COM3')
BAUD = int(os.environ.get('MAKCU_BAUD', '921600'))

ENTRY_RE = re.compile(r'(\d{4,}),([0-9a-f]{2}),(\d{1,2}),([0-9a-f]{0,16})')


# ------------------------------------------------------------------ capture
def _clean(text):
    """把回包里的换行和 '>>> ' 提示符去掉，只留内容。"""
    return ' '.join(text.replace('\r\n>>>', ' ').replace('\n', ' ').split())


def _drain(ser, quiet=0.25, limit=1.5):
    buf = b''
    t0 = last = time.time()
    while time.time() - t0 < limit:
        n = ser.in_waiting
        if n:
            buf += ser.read(n)
            last = time.time()
        elif buf and time.time() - last > quiet:
            break
        else:
            time.sleep(0.01)
    return buf.decode('latin-1', 'replace')


def _cmd(ser, text, wait=0.25):
    ser.reset_input_buffer()
    ser.write(text.encode('latin-1') + b'\r')
    ser.flush()
    time.sleep(wait)
    return _drain(ser)


def capture(port, baud, seconds, out_path, repeat=1, gap=2.0, dump_only=False):
    """采集 `repeat` 个 burst，每个 burst 记录 `seconds` 秒（环形缓冲 3072 条，
    运动中约 3.4 s，静止时约 20 s，所以分段采集比一次长采更保真）。
    dump_only=True 表示不动环、直接把当前已录到的内容 dump 出来（用于"先 arm，
    人动完再说"的两段式流程）。"""
    if serial is None:
        sys.exit('pyserial missing')
    ser = serial.Serial(port, baud, timeout=0.2)
    time.sleep(0.3)
    _drain(ser, limit=0.4)

    before = {
        'fv': _clean(_cmd(ser, 'mx.fv')),
        'ds': _clean(_cmd(ser, 'mx.ds')),
        'ls': _clean(_cmd(ser, 'mx.ls')),
        'hi': _clean(_cmd(ser, 'mx.hi')),
    }

    entries = []
    expected = 0
    if dump_only:
        repeat = 1
    for burst in range(repeat):
        if not dump_only:
            arm = _cmd(ser, 'mx.mt on')
            print(f'[burst {burst + 1}/{repeat}] armed ({arm.strip()}) - 现在移动鼠标 {seconds:g} 秒',
                  flush=True)
            time.sleep(seconds)

        status = _cmd(ser, 'mx.mt')
        m = re.search(r'(on|off),(\d+)/(\d+)', status)
        total = int(m.group(2)) if m else -1
        expected += max(0, total)

        ser.reset_input_buffer()
        ser.write(b'mx.mt d\r')
        ser.flush()
        raw = b''
        t0 = time.time()
        while time.time() - t0 < 60:
            n = ser.in_waiting
            if n:
                raw += ser.read(n)
                t0 = time.time()
                if total > 0 and len(ENTRY_RE.findall(raw.decode('latin-1', 'replace'))) >= total:
                    break
            else:
                time.sleep(0.02)
        text = raw.decode('latin-1', 'replace')
        got = [
            {'t': int(a), 'ep': int(b, 16), 'len': int(c), 'hex': d, 'b': burst}
            for a, b, c, d in ENTRY_RE.findall(text)
        ]
        print(f'  burst {burst + 1}: parsed {len(got)} entries (device count {total})')
        entries.extend(got)
        if burst + 1 < repeat:
            time.sleep(gap)

    after = {
        'ds': _clean(_cmd(ser, 'mx.ds')),
        'ls': _clean(_cmd(ser, 'mx.ls')),
        'hi': _clean(_cmd(ser, 'mx.hi')),
    }
    ser.close()

    data = {'port': port, 'seconds': seconds, 'repeat': repeat, 'before': before,
            'after': after, 'entries': entries}
    os.makedirs(os.path.dirname(out_path) or '.', exist_ok=True)
    with open(out_path, 'w', encoding='utf-8') as fh:
        json.dump(data, fh)
    print(f'parsed {len(entries)} entries total (device claimed {expected}) -> {out_path}')
    return data


# ------------------------------------------------------------------ decode
def decode(ep, length, hx):
    """返回 (buttons, dx, dy, wheel, pan)。布局判定：
    ep==0x00 = 注入路径（makcu_mouse 的 4 字节 int8：btn, dx, dy, wheel）；
    7 字节 = G3M PRO（5 键 + X16 + Y16 + wheel + pan）；其余 >=4 = 12-bit 打包。"""
    b = bytes.fromhex(hx)
    if ep == 0x00 and len(b) >= 4:
        def s8(v):
            return v - 256 if v >= 128 else v
        return b[0], s8(b[1]), s8(b[2]), s8(b[3]), 0
    if length >= 7 and len(b) >= 5:
        btn = b[0]
        x = int.from_bytes(b[1:3], 'little', signed=True)
        y = int.from_bytes(b[3:5], 'little', signed=True)
        whl = b[5] if len(b) > 5 else 0
        pan = b[6] if len(b) > 6 else 0
        return btn, x, y, (whl - 256 if whl > 127 else whl), (pan - 256 if pan > 127 else pan)
    if len(b) >= 4:
        btn = b[0]
        x12 = b[1] | ((b[2] & 0x0F) << 8)
        y12 = (b[2] >> 4) | (b[3] << 4)
        x = x12 - 0x1000 if x12 & 0x800 else x12
        y = y12 - 0x1000 if y12 & 0x800 else y12
        whl = b[4] if len(b) > 4 else 0
        return btn, x, y, (whl - 256 if whl > 127 else whl), 0
    return 0, 0, 0, 0, 0


def pct(vals, p):
    if not vals:
        return 0.0
    s = sorted(vals)
    k = (len(s) - 1) * p / 100.0
    lo, hi = int(math.floor(k)), int(math.ceil(k))
    if lo == hi:
        return float(s[lo])
    return s[lo] + (s[hi] - s[lo]) * (k - lo)


def _max_run(vals):
    best = run = 1
    for a, b in zip(vals, vals[1:]):
        run = run + 1 if a == b else 1
        best = max(best, run)
    return best


def _or_buttons(items):
    v = 0
    for m in items:
        v |= m['btn']
    return v


# ------------------------------------------------------------------ analysis
def analyse(data):
    ents = data.get('entries', [])
    mouse = []
    for e in ents:
        if e['ep'] not in (0x81, 0x00):
            continue
        btn, x, y, whl, pan = decode(e['ep'], e['len'], e['hex'])
        mouse.append({'t': e['t'], 'btn': btn, 'x': x, 'y': y, 'whl': whl, 'pan': pan,
                      'b': e.get('b', 0)})

    n = len(mouse)
    res = {'n_raw': len(ents), 'n_mouse': n, 'n_other': len(ents) - n,
           'bursts': len({m['b'] for m in mouse})}
    if n < 8:
        res['error'] = 'too few mouse reports: %d' % n
        return res

    span = (mouse[-1]['t'] - mouse[0]['t']) / 1e6
    res['span_s'] = span

    # ---- 0. 时间戳分块重建 ------------------------------------------------
    # 取样点是"桥接层处理该帧的时刻"，而 UART1 是按块读取的：同一块里 5–10 帧被
    # 连续解析，彼此只差 ~20 µs。若把逐帧 dt 当设备节拍，会得出 p50 = 19 µs 这种
    # 假值。所以把相邻且 dt < 200 µs 的帧合并成一个"送达块"，块级聚合才代表真实节拍；
    # 块内各帧的位移仍然精确，只是彼此的先后时间不可分辨。
    blocks, cur = [], [mouse[0]]
    for m in mouse[1:]:
        if m['b'] != cur[-1]['b'] or (m['t'] - cur[-1]['t']) >= 200:
            blocks.append(cur)
            cur = [m]
        else:
            cur.append(m)
    blocks.append(cur)

    blk = []
    for group in blocks:
        blk.append({
            't': group[0]['t'], 'end': group[-1]['t'], 'n': len(group),
            'x': sum(m['x'] for m in group),
            'y': sum(m['y'] for m in group),
            'whl': sum(m['whl'] for m in group),
            'btn': 0 if not group else _or_buttons(group),
            'b': group[0]['b'],
        })
    res['blocks'] = len(blk)
    res['reports_per_block'] = statistics.fmean([b['n'] for b in blk])

    # ---- 1. 送达节拍（块级，无分块伪影） ---------------------------------
    dt = [b['t'] - a['t'] for a, b in zip(blk, blk[1:]) if a['b'] == b['b']]
    res['dt'] = {
        'n': len(dt),
        'p1': pct(dt, 1), 'p10': pct(dt, 10), 'p25': pct(dt, 25), 'p50': pct(dt, 50),
        'p75': pct(dt, 75), 'p90': pct(dt, 90), 'p99': pct(dt, 99), 'max': max(dt),
        'mean': statistics.fmean(dt),
        'sd': statistics.pstdev(dt) if len(dt) > 1 else 0.0,
    }
    res['dt']['cv'] = res['dt']['sd'] / res['dt']['mean'] if res['dt']['mean'] else 0.0
    bins = [(0, 500), (500, 1500), (1500, 2500), (2500, 5000), (5000, 15000),
            (15000, 50000), (50000, 10 ** 9)]
    res['dt_hist'] = []
    for lo_hi in bins:
        c = sum(1 for d in dt if lo_hi[0] <= d < lo_hi[1])
        res['dt_hist'].append((lo_hi, c, 100.0 * c / len(dt) if dt else 0.0))
    gaps = [d for d in dt if d > 40000]
    res['gaps'] = {
        'n_40ms': sum(1 for d in dt if d > 40000),
        'n_200ms': sum(1 for d in dt if d > 200000),
        'share': 100.0 * len(gaps) / len(dt) if dt else 0.0,
        'max': max(gaps) if gaps else 0,
    }
    res['dt_same_run_max'] = _max_run(dt)

    # ---- 2. 位移幅度（逐帧，数值精确） -----------------------------------
    moving = [m for m in mouse if m['x'] or m['y']]
    res['moving_n'] = len(moving)
    res['idle_share'] = 100.0 * (n - len(moving)) / n
    mags = [abs(m['x']) + abs(m['y']) for m in moving] or [0]
    res['mag'] = {
        'p10': pct(mags, 10), 'p50': pct(mags, 50), 'p90': pct(mags, 90), 'max': max(mags),
        'distinct': len({(m['x'], m['y']) for m in moving}),
        'lsb_share': 100.0 * sum(1 for m in moving if abs(m['x']) <= 1 and abs(m['y']) <= 1) / max(1, len(moving)),
        'max_abs_axis': max([abs(m['x']) for m in moving] + [abs(m['y']) for m in moving] + [0]),
    }
    res['mag']['scale_ratio'] = (res['mag']['max'] / res['mag']['p50']) if res['mag']['p50'] else 0.0
    # 逐帧最长"完全相同位移"连跑：慢速拖动天然会出现（每帧 1 count），所以只作参考；
    # 真正的反回放判据用下面的"块级恒定速度连跑时长"。
    res['same_delta_run_max'] = _max_run([(m['x'], m['y']) for m in moving])
    run, best, best_len, start = 1, 1, 1, None
    for i in range(1, len(blk)):
        same = (blk[i]['x'], blk[i]['y']) == (blk[i - 1]['x'], blk[i - 1]['y']) and \
               (blk[i]['x'] or blk[i]['y'])
        if same:
            run += 1
            if run > best:
                best, best_len, start = run, i - run + 1, blk[i]
        else:
            run = 1
    res['blk_same_run_max'] = best
    res['blk_same_run_ms'] = 0.0
    if best > 1:
        idx = max(0, len(blk) - 1)
        # 找出该连跑的起止块以计算时长
        run, cur_start = 1, 0
        for i in range(1, len(blk)):
            same = (blk[i]['x'], blk[i]['y']) == (blk[i - 1]['x'], blk[i - 1]['y']) and \
                   (blk[i]['x'] or blk[i]['y'])
            if same:
                run += 1
                if run == best:
                    res['blk_same_run_ms'] = (blk[i]['t'] - blk[i - run + 1]['t']) / 1000.0
            else:
                run = 1

    # ---- 3. 分段 + 速度/加速度曲线（块级） -------------------------------
    segs, cur_seg, idle = [], [], 0
    for i, b in enumerate(blk):
        if i == 0:
            cur_seg = [b]
            continue
        gap = b['t'] - blk[i - 1]['t']
        if gap > 40000 or b['b'] != blk[i - 1]['b']:
            if len(cur_seg) > 3:
                segs.append(cur_seg)
            cur_seg = [b]
            idle = 0
            continue
        cur_seg.append(b)
        idle = idle + 1 if (b['x'] == 0 and b['y'] == 0) else 0
        if idle >= 3:
            segs.append(cur_seg)
            cur_seg = []
            idle = 0
    if len(cur_seg) > 3:
        segs.append(cur_seg)

    seg_stats = []
    for s in segs:
        if len(s) < 10:
            continue
        vs = []
        for a, b in zip(s, s[1:]):
            d = b['t'] - a['t']
            if d <= 0:
                continue
            vs.append(math.hypot(b['x'], b['y']) * 1e6 / d)
        if len(vs) < 8 or max(vs) <= 0:
            continue
        peak = max(vs)
        pi = vs.index(peak)
        # 速度序列 3 点滑动平均：块级速度仍带传感器噪声，不平滑会让"加速度变号"
        # 被噪声淹没（合成自测里曾算出 600 次/秒这种假值）。
        sm = []
        for i in range(len(vs)):
            lo, hi = max(0, i - 1), min(len(vs), i + 2)
            sm.append(statistics.fmean(vs[lo:hi]))
        accs = []
        for a, b in zip(sm, sm[1:]):
            dv = b - a
            if abs(dv) < 0.05 * peak:
                continue
            accs.append(dv)
        sign_changes = sum(1 for a, b in zip(accs, accs[1:]) if a * b < 0)
        sub = 0
        for i in range(1, len(sm) - 1):
            if sm[i] > sm[i - 1] and sm[i] >= sm[i + 1] and sm[i] > 0.4 * peak:
                sub += 1
        # 方向：只取幅度在段中位数以上的块（小位移的 atan2 基本是噪声）
        seg_mags = sorted(abs(b['x']) + abs(b['y']) for b in s)
        floor = max(2, seg_mags[len(seg_mags) // 2])
        turns = []
        for a, b in zip(s, s[1:]):
            if abs(a['x']) + abs(a['y']) < floor or abs(b['x']) + abs(b['y']) < floor:
                continue
            th1 = math.atan2(a['y'], a['x'])
            th2 = math.atan2(b['y'], b['x'])
            turns.append(math.degrees(abs((th2 - th1 + math.pi) % (2 * math.pi) - math.pi)))
        dur = (s[-1]['t'] - s[0]['t']) / 1e6 or 1e-6
        seg_stats.append({
            'n': sum(b['n'] for b in s), 'dur_s': dur,
            'dist': sum(abs(b['x']) + abs(b['y']) for b in s),
            'peak_v': peak, 'mean_v': statistics.fmean(vs),
            'mean_over_peak': statistics.fmean(vs) / peak,
            'peak_pos': pi / max(1, len(vs) - 1),
            'acc_sign_changes_per_s': sign_changes / dur,
            'subpeaks': sub,
            'turn_deg_per_s': (sum(turns) / dur) if turns else 0.0,
        })
    res['segments'] = seg_stats

    # ---- 4. 交互事件（点击/滚轮） ----------------------------------------
    clicks = 0
    prev = 0
    for b in blk:
        if (b['btn'] & 0x07) and not (prev & 0x07):
            clicks += 1
        prev = b['btn']
    res['interaction'] = {
        'press_edges': clicks,
        'btn_or': _or_buttons(mouse),
        'wheel_sum': sum(m['whl'] for m in mouse),
        'wheel_blocks': sum(1 for b in blk if b['whl']),
    }

    # ---- 5. 合成/自动化指纹（负向判据） ----------------------------------
    res['synthetic_flags'] = {
        'blk_same_run_max': res['blk_same_run_max'],
        'blk_same_run_ms': res['blk_same_run_ms'],
        'dt_same_run_max': res['dt_same_run_max'],
    }
    return res


# ------------------------------------------------------------------ report
def verdict(r):
    """把特征折成一句话结论 + 每条判据的支持/反对。"""
    if 'error' in r:
        return '数据不足', []
    d, mg, segs = r['dt'], r['mag'], r['segments']
    checks = []

    def add(name, ok, detail):
        checks.append((name, bool(ok), detail))

    add('间隔分布有右尾（速度随动作变化）', d['cv'] > 0.35 and d['p99'] > 2.5 * d['p50'],
        f"CV={d['cv']:.2f}, p50={d['p50']:.0f}us, p99={d['p99']:.0f}us")
    add('存在微停顿（>40 ms 的空档）', r['gaps']['n_40ms'] > 0,
        f"{r['gaps']['n_40ms']} 次, 最长 {r['gaps']['max']/1000:.0f} ms")
    add('幅度跨多个数量级（不是恒定步长）', mg['scale_ratio'] > 5 and mg['distinct'] > 20,
        f"max/p50={mg['scale_ratio']:.1f}, 不同位移值 {mg['distinct']} 种")
    if segs:
        bell = [s for s in segs if 0.15 <= s['peak_pos'] <= 0.75 and s['mean_over_peak'] > 0.2]
        add('每段速度呈"加速-峰值-减速"钟形', len(bell) >= max(1, len(segs) // 2),
            f"{len(bell)}/{len(segs)} 段峰值落在 0.15–0.75，mean/peak={statistics.fmean([s['mean_over_peak'] for s in segs]):.2f}")
        add('存在子运动/修正（速度曲线多峰）', sum(s['subpeaks'] for s in segs) > 0,
            f"局部极大合计 {sum(s['subpeaks'] for s in segs)} 个")
        add('加速度正负切换（人手持续修正）',
            statistics.fmean([s['acc_sign_changes_per_s'] for s in segs]) > 2,
            f"平均 {statistics.fmean([s['acc_sign_changes_per_s'] for s in segs]):.1f} 次/秒")
        add('直线段仍有方向抖动（非完美直线）',
            statistics.fmean([s['turn_deg_per_s'] for s in segs]) > 50,
            f"平均 {statistics.fmean([s['turn_deg_per_s'] for s in segs]):.0f} 度/秒")
    else:
        add('存在可分析的连续运动段', False, '没有 ≥10 条报告的连续段（是不是没动？）')
    add('有 LSB 级抖动（传感器噪声/手抖）', mg['lsb_share'] > 3,
        f"{mg['lsb_share']:.1f}% 的报告两轴都不超过 1 count")
    add('没有长时间恒定速度（非定速注入/回放）',
        r.get('blk_same_run_ms', 0) < 200 and r.get('blk_same_run_max', 0) < 40,
        f"块级恒定速度最长 {r.get('blk_same_run_max', 0)} 块 / {r.get('blk_same_run_ms', 0):.0f} ms")
    inter = r.get('interaction', {})
    add('有真实交互事件（点击/滚轮与运动交织）',
        inter.get('press_edges', 0) > 0 or inter.get('wheel_blocks', 0) > 0,
        f"按下沿 {inter.get('press_edges', 0)} 次, 滚轮 {inter.get('wheel_sum', 0)} 格 / "
        f"{inter.get('wheel_blocks', 0)} 个送达块")

    ok = sum(1 for _, k, _ in checks if k)
    if ok >= len(checks) - 1 and ok >= 6:
        text = '符合人工移动轨迹'
    elif ok >= len(checks) // 2:
        text = '大体符合人工轨迹，但特征不全'
    else:
        text = '与人工轨迹特征明显不符'
    return text, checks


def write_report(r, data, path):
    text, checks = verdict(r)
    lines = []
    A = lines.append
    A('# 控制口鼠标移动：人工轨迹符合性分析\n')
    mode = (f"实时采集 {data.get('seconds'):g} 秒 x {data.get('repeat', 1)} 段"
            if data.get('seconds') else "dump-only（先 arm，动作完成后转储环形缓冲）")
    A(f"> 数据：`mx.mt` 记录，端口 {data.get('port')}，{mode}。"
      f"生成时间 {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
    A('## 1. 数据来源\n')
    A('`mx.mt` 是左片在 **HID 提交前** 的一跳取样点（`link_report_to_mouse()` → `mt_tap()`）：')
    A('每条记录 = 本机 µs 时间戳 + 端点 + 原始报告字节。它描述的是"PC 侧实际会收到什么"，')
    A('盒子内部的合并/限流/丢帧都会直接体现在这份时间序列上。\n')
    A(f"- 原始帧 {r['n_raw']} 条，其中鼠标端点 `0x81` {r['n_mouse']} 条"
      f"（其它端点 {r['n_other']} 条，属厂商通道，不参与轨迹分析）")
    A(f"- 覆盖时长 {r.get('span_s', 0):.2f} s，运动中报告 {r.get('moving_n', 0)} 条"
      f"（静止/保活 {r.get('idle_share', 0):.1f}%）")
    A(f"- 时间戳粒度：取样点是**桥接层的解析时刻**，UART1 又是按块读取的，"
      f"相邻帧会被连续解析（本份数据平均 {r.get('reports_per_block', 0):.1f} 帧/块，块内只差约 20 us）。"
      f"因此所有间隔/速度统计都建立在**送达块**上（把相邻且 <200 us 的帧合并成一块），"
      f"块内各帧只用于位移统计 —— 逐帧 dt 不能当设备节拍用。共 {r.get('blocks', 0)} 个送达块。\n")
    if 'error' in r:
        A('**数据不足：** ' + r['error'])
        open(path, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
        return text
    d, mg = r['dt'], r['mag']
    A('## 2. 送达节拍与微停顿（块级）\n')
    A("设备节拍本身受鼠标回报率约束（本机是无线 2.4G），所以这里看的不是频率准不准，")
    A("而是**间隔分布的形状**：人手动作的快慢变化会让间隔出现长尾，定速注入则集中在单一值上。\n")
    A('| 分位 | p1 | p10 | p25 | p50 | p75 | p90 | p99 | max |')
    A('|---|---|---|---|---|---|---|---|---|')
    A('| µs | {:.0f} | {:.0f} | {:.0f} | {:.0f} | {:.0f} | {:.0f} | {:.0f} | {:.0f} |'.format(
        d['p1'], d['p10'], d['p25'], d['p50'], d['p75'], d['p90'], d['p99'], d['max']))
    A('')
    A(f"均值 {d['mean']:.0f} us，标准差 {d['sd']:.0f} µs，**CV = {d['cv']:.2f}**"
      f"（恒定速率注入会趋近 0；人手因动作快慢不同会明显偏离 0）。\n")
    A('| 区间 | 条数 | 占比 |')
    A('|---|---:|---:|')
    for (lo, hi), c, p in r['dt_hist']:
        lab = f'{lo}–{hi} µs' if hi < 10 ** 9 else f'>{lo} µs'
        A(f'| {lab} | {c} | {p:.1f}% |')
    A('')
    A(f"微停顿：>40 ms {r['gaps']['n_40ms']} 次，>200 ms {r['gaps']['n_200ms']} 次，"
      f"最长 {r['gaps']['max']/1000:.0f} ms。\n")
    A('## 3. 位移幅度与量化\n')
    A('| 指标 | 值 |')
    A('|---|---|')
    A(f"| 位移绝对值 abs(dx)+abs(dy) 的 p10 / p50 / p90 / max | {mg['p10']:.0f} / {mg['p50']:.0f} / {mg['p90']:.0f} / {mg['max']:.0f} |")
    A(f"| 不同 (dx,dy) 组合数 | {mg['distinct']} |")
    A(f"| max / p50（幅度跨度） | {mg['scale_ratio']:.1f} |")
    A(f"| 两轴都不超过 1 count 的占比（LSB 抖动） | {mg['lsb_share']:.1f}% |")
    A(f"| 单轴最大位移 | {mg['max_abs_axis']} counts |")
    A(f"| 逐帧最长\"完全相同位移\"连跑 | {r['same_delta_run_max']} 条（慢速拖动天然会出现） |")
    A(f"| 块级恒定速度最长连跑 | {r.get('blk_same_run_max', 0)} 块 / {r.get('blk_same_run_ms', 0):.0f} ms |")
    it = r.get('interaction', {})
    A(f"| 按下沿 / 按键位 OR / 滚轮累计 / 滚轮块数 | {it.get('press_edges', 0)} / 0x{it.get('btn_or', 0):02x} / {it.get('wheel_sum', 0)} / {it.get('wheel_blocks', 0)} |")
    A(f"| 最长\"完全相同间隔\"连跑 | {r['dt_same_run_max']} 条 |")
    A('')
    if r.get('segments'):
        A('## 4. 速度 / 加速度曲线（块级，按微停顿切段）\n')
        A('| 段 | 报告数 | 时长 s | 距离 counts | 峰值速度 | mean/peak | 峰值位置 | 加速度变号/秒 | 速度局部极大 | 方向抖动 度/秒 |')
        A('|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|')
        for i, s in enumerate(r['segments'][:12], 1):
            A(f"| {i} | {s['n']} | {s['dur_s']:.2f} | {s['dist']:.0f} | {s['peak_v']:.0f} | "
              f"{s['mean_over_peak']:.2f} | {s['peak_pos']:.2f} | {s['acc_sign_changes_per_s']:.1f} | "
              f"{s['subpeaks']} | {s['turn_deg_per_s']:.0f} |")
        A('')
        A('读法：峰值位置在 0.15–0.75 之间且 mean/peak 明显小于 1，说明是"起-峰-收"的钟形曲线；')
        A('恒定速度的注入（合成）会得到 mean/peak≈1、峰值位置≈末位、加速度变号≈0。\n')
    A('## 5. 判据逐条核对\n')
    A('| # | 判据 | 结果 | 依据 |')
    A('|---|---|---|---|')
    for i, (name, ok, detail) in enumerate(checks, 1):
        A(f"| {i} | {name} | {'✅' if ok else '❌'} | {detail} |")
    A('')
    A('## 6. 结论\n')
    A(f'**{text}**（{sum(1 for _, k, _ in checks if k)}/{len(checks)} 条判据成立）\n')
    A('支持该结论的关键特征：')
    for name, ok, detail in checks:
        if ok:
            A(f'- {name} —— {detail}')
    bad = [c for c in checks if not c[1]]
    if bad:
        A('\n未成立的判据：')
        for name, _, detail in bad:
            A(f'- {name} —— {detail}')
    if 'after' in data:
        A('\n## 7. 盒子保真度（同期计数器）\n')
        A('```')
        for k in ('ds', 'ls', 'hi'):
            if data['after'].get(k):
                A(f"{k}: {data['after'][k]}")
        A('```')
        q = (data['after'].get('ds') or '').split(',')
        l = (data['after'].get('ls') or '').split(',')
        qdrop = q[1].strip() if len(q) > 1 else '?'
        ldrop = l[10].strip() if len(l) > 10 else '?'
        linj = l[9].strip() if len(l) > 9 else '?'
        A('')
        A(f'- 报告队列丢弃（`ds` 第 2 项）：**{qdrop}**')
        A(f'- 链路层注入/丢弃（`ls` 第 10/11 项）：**{linj} / {ldrop}**')
        A('- 判读：队列丢弃为 0 且链路丢弃相对注入量可忽略，说明序列里的每一帧都是设备')
        A('  原始报告，没有被合并、限流或重采样 —— 也就是说上面那些"人工特征"是盒子')
        A('  **透传**出来的，而不是盒子自己造出来的形状。')
    open(path, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
    return text


def main():
    try:
        sys.stdout.reconfigure(encoding='utf-8', errors='replace')
    except Exception:
        pass
    ap = argparse.ArgumentParser()
    ap.add_argument('--capture', type=float, help='每个 burst 采集秒数')
    ap.add_argument('--repeat', type=int, default=1, help='burst 个数（默认 1）')
    ap.add_argument('--gap', type=float, default=2.0, help='burst 间隔秒数')
    ap.add_argument('--dump-only', action='store_true',
                    help='不重新 arm，直接 dump 当前环形缓冲（配合先前手动 mx.mt on）')
    ap.add_argument('--port', default=PORT)
    ap.add_argument('--baud', type=int, default=BAUD)
    ap.add_argument('--out', default='work/motion.json')
    ap.add_argument('--analyze', help='离线复算已有的 json')
    ap.add_argument('--report', default='verification/motion_analysis.md')
    args = ap.parse_args()

    if args.capture:
        data = capture(args.port, args.baud, args.capture, args.out,
                       repeat=args.repeat, gap=args.gap, dump_only=args.dump_only)
    elif args.dump_only:
        data = capture(args.port, args.baud, 0, args.out, dump_only=True)
    elif args.analyze:
        with open(args.analyze, encoding='utf-8') as fh:
            data = json.load(fh)
    else:
        ap.error('需要 --capture 或 --analyze')

    r = analyse(data)
    text, checks = verdict(r)
    os.makedirs(os.path.dirname(args.report) or '.', exist_ok=True)
    write_report(r, data, args.report)
    print()
    print(f'结论: {text}  ({sum(1 for _, k, _ in checks if k)}/{len(checks)} 判据成立)')
    for name, ok, detail in checks:
        print(('  [ok] ' if ok else '  [--] ') + name + ' — ' + detail)
    print('report ->', args.report)


if __name__ == '__main__':
    main()
