"""dt_hist - 转发报告间隔直方图（左片视角的 PC 侧 HID 节奏）

输出默认纯 ASCII（避免 GBK 控制台乱码）；要中文用 --cn。

为什么不用 USBPcap：本机 Wireshark 静默安装（没装 Npcap），dumpcap 不能用；
USBPcapCMD 打开根集线器也拿不到数据。固件里本来就有这张直方图（`mx.lh`，
每桶 100 µs × 256 桶，`mx.lat` 的 p50/p99 就是从它算的），直接导出更可靠。

注意：固件对报告是 **1/4 采样**，所以 1 kHz 输入的名义间隔是 4.00 ms（不是 1 ms）。

用法
----
    python tools\\dt_hist.py                      # A 透传(真鼠标) + B 1 kHz 注入
    python tools\\dt_hist.py --mode passthru      # 只测透传（需要鼠标真的在动）
    python tools\\dt_hist.py --mode inject --seconds 5
    python tools\\dt_hist.py --cn                 # 中文输出
"""
from __future__ import annotations

import argparse
import os
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from boxbench.link import BoxLink                      # noqa: E402

BUCKET_US = 100
CN = False


def T(en, zh):
    return zh if CN else en


def hz_read(link, tries=8):
    """读 mx.hz 的速率行。

    两个坑：① 文本回包会串（`mx.ss 00` 的 "auto" 会晚到）；
    ② 刚灌过 1 kHz 文本命令时控制口还在消化，头几次可能超时。
    所以：带短暂间隔重试，直到拿到含 `frames=` 的那一条。
    """
    for i in range(tries):
        if i:
            time.sleep(0.15)
        r = link.text_request('mx.hz', timeout=0.8)
        if r and 'frames=' in r:
            return r
    return 'hz: <no dt line>'


def dump_hist(link):
    """读 16 页 → 256 桶（100 µs/桶）。"""
    hist = [0] * 256
    for page in range(16):
        r = link.text_request(f'mx.lh {page}', timeout=1.0)
        if not r:
            continue
        for item in r.split(';'):
            if ':' not in item:
                continue
            try:
                idx, cnt = item.split(':')
                i = int(idx)
                if 0 <= i < 256:
                    hist[i] = int(cnt)
            except ValueError:
                continue
    return hist


def pct(hist, q):
    total = sum(hist)
    if total == 0:
        return 0
    acc = 0
    for i, c in enumerate(hist):
        acc += c
        if acc >= total * q:
            return (i + 1) * BUCKET_US
    return 256 * BUCKET_US


def show(hist, title):
    total = sum(hist)
    print('')
    print('=' * 64)
    print(title)
    print('=' * 64)
    if total == 0:
        print(T('  no samples', '  （没有样本）'))
        return
    print(f"  n={total}  p50={pct(hist, .5)}us  p90={pct(hist, .9)}us  "
          f"p99={pct(hist, .99)}us")
    nz = [(i * BUCKET_US, c) for i, c in enumerate(hist) if c]
    print(T('  bucket(us)          count    share', '  区间(µs)            条数    占比'))
    for us, c in nz[:16]:
        bar = '#' * max(1, int(50 * c / total))
        print(f"  {us:>6}-{us + BUCKET_US:<6} {c:>7}  {100.0 * c / total:5.1f}%  {bar}")
    if len(nz) > 16:
        print(T(f'  ... {len(nz) - 16} more non-empty buckets',
                f'  … 另有 {len(nz) - 16} 个非零桶'))

    mode_i = max(range(len(hist)), key=lambda i: hist[i])
    mode_ms = (mode_i + 0.5) * BUCKET_US / 1000.0
    band = mode_ms * 0.10
    in_band = sum(c for i, c in enumerate(hist)
                  if abs((i + 0.5) * BUCKET_US / 1000.0 - mode_ms) <= band)
    short = sum(c for i, c in enumerate(hist)
                if (i + 0.5) * BUCKET_US / 1000.0 < mode_ms - band)
    longg = sum(c for i, c in enumerate(hist)
                if (i + 0.5) * BUCKET_US / 1000.0 > mode_ms + band)
    print(T(f'  mode={mode_ms:.2f}ms (1/4 sampling -> nominal 4.00ms at 1kHz)',
            f'  众数 {mode_ms:.2f} ms（1/4 采样 → 1 kHz 名义 4.00 ms）'))
    print(T(f'  within +-10%: {100.0 * in_band / total:.1f}%  |  too short: '
            f'{100.0 * short / total:.1f}%  |  too long: {100.0 * longg / total:.1f}%',
            f'  正常带 ±10%: {100.0 * in_band / total:.1f}%  ·  偏短 '
            f'{100.0 * short / total:.1f}%  ·  偏长 {100.0 * longg / total:.1f}%'))
    print(T(f'  jitter (p99-p50) = {pct(hist, .99) - pct(hist, .5)} us',
            f'  抖动幅度（p99−p50）= {pct(hist, .99) - pct(hist, .5)} µs'))


def gen_1khz(link, seconds, rate=1000.0):
    link.text_request('mx.hk 1', timeout=0.5)
    link.text_request('mx.ss 33', timeout=0.5)
    frame = b'mx.lf a2 02330700 01000000000000\r'
    period = 1.0 / rate
    n = 0
    t0 = time.perf_counter()
    nxt = t0
    while time.perf_counter() - t0 < seconds:
        nxt += period
        link.write_raw(frame)
        n += 1
        d = nxt - time.perf_counter()
        if d > 0:
            time.sleep(d)
    link.text_request('mx.ss 00', timeout=0.5)
    return n


def main():
    global CN
    ap = argparse.ArgumentParser(description='report-interval histogram (mx.lh)')
    ap.add_argument('--port', default=os.environ.get('MAKCU_PORT', 'COM3'))
    ap.add_argument('--baud', type=int, default=int(os.environ.get('MAKCU_BAUD', '921600')))
    ap.add_argument('--mode', choices=['both', 'inject', 'passthru'], default='both')
    ap.add_argument('--seconds', type=float, default=5.0)
    ap.add_argument('--cn', action='store_true', help='中文输出（默认 ASCII，防控制台乱码）')
    args = ap.parse_args()
    CN = args.cn

    # 尽量把 stdout 设成 UTF-8；设不了也不影响（默认输出是 ASCII）
    try:
        sys.stdout.reconfigure(encoding='utf-8', errors='replace')
    except Exception:
        pass

    link = BoxLink(args.port, args.baud, on_log=lambda s: None)
    link.open()

    def reboot_and_wait():
        link.write_raw(b'mx.rs\r')
        time.sleep(8.0)
        for _ in range(10):
            iface = link.text_request('mx.if', timeout=0.6)
            if iface and iface.startswith('2 '):
                return True
            time.sleep(1.0)
        return False

    if args.mode in ('both', 'passthru'):
        print(T('A) passthrough (real mouse; MOVE THE MOUSE during this window)',
                'A) 真实鼠标透传（这段时间请让鼠标真的在动）'))
        if not reboot_and_wait():
            print('  [warn] clone not healthy after reboot (mx.if != 2)')
        hz_read(link)                                    # 建立速率基线
        time.sleep(args.seconds)
        hz = hz_read(link)                               # frames/s 就是实际到达率
        show(dump_hist(link), f'A passthrough {args.seconds:.0f}s')
        print(T('  rate:', '  速率:'), hz)
        print('  mx.lat:', link.text_request('mx.lat', timeout=1.0))

    if args.mode in ('both', 'inject'):
        print('')
        print(T('B) 1 kHz injection (same verbatim forward path)',
                'B) 1 kHz 注入（走同一条 verbatim 转发路径）'))
        if not reboot_and_wait():
            print('  [warn] clone not healthy after reboot (mx.if != 2)')
        hz_read(link)
        n = gen_1khz(link, args.seconds)
        time.sleep(0.3)                  # 让控制口把积压的文本命令消化完
        hz = hz_read(link)
        time.sleep(0.4)
        show(dump_hist(link), f'B inject {n} frames / {args.seconds:.0f}s')
        print(T('  rate:', '  速率:'), hz)
        print('  mx.lat:', link.text_request('mx.lat', timeout=1.0))

    link.close()
    return 0


if __name__ == '__main__':
    sys.exit(main())
