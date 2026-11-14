#!/usr/bin/env python3
r"""PC-side ground truth: capture HID input with USBPcap, reconcile it with the firmware counters.

Usage:
    python tools/verify_buttons_usb.py --port COM8 --clicks 20 --gap-ms 80
    python tools/verify_buttons_usb.py --clicks 40 --gap-ms 20 --binary-sumv --sumv-period-ms 30

Flow:
  1. park the cursor at the top-right corner (disable with --no-cursor);
  2. start USBPcapCMD on \\.\USBPcap1 (override with --device);
  3. firmware side: mx.hk 1 / mx.ss 33 / mx.gd 0, read the 0x3E baseline;
  4. inject N press/release pairs, gap-ms apart; with --binary-sumv the binary
     0x36 SUMV command is interleaved on the same serial port (single writer);
  5. read 0x3E again, stop the capture, parse the pcap (LINKTYPE_USBPCAP=249,
     interrupt input on ep 0x81);
  6. reconcile and print PASS/FAIL.

Pass criteria (all must hold):
  * firmware wire_chg delta == 2N;
  * captured button edges == 2N and strictly alternate press/release;
  * the last captured report is released (no stuck button).
Note: with motion running, consecutive reports legitimately repeat the same
button byte ("still held while moving") - only the compressed edge sequence
is judged, so repeats are reported but never counted as duplicates.
"""
import argparse
import ctypes
import os
import signal
import struct
import subprocess
import sys
import time

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                                'verification', 'regress'))
from conftest import Device  # noqa: E402


def park_cursor_topright(margin_x=40, margin_y=20):
    u = ctypes.windll.user32
    w, h = u.GetSystemMetrics(0), u.GetSystemMetrics(1)
    u.SetCursorPos(w - margin_x, margin_y)
    return w, h


def usb_stat(dev):
    p = dev.bin_request(0x3E, b'', timeout=1.0)
    assert p is not None and len(p) >= 16, f'0x3E reply too short: {None if p is None else len(p)}'
    u = lambda o: int.from_bytes(p[o:o + 2], 'little')
    return dict(pin=u(0), sent=u(2), wait=u(4), over=u(6), wire=u(14))


def audit(dev):
    """0x3F BTN_AUDIT（12 B）：引擎按键审计。"""
    p = dev.bin_request(0x3F, b'', timeout=1.0)
    if p is None or len(p) < 12:
        return None
    u = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
    return dict(in_chg=u(0), out_chg=u(4), extra=u(8))


def diag_counts(dev):
    """0x45 BTN_CNT（42 B）：frames/nonzero/fwd_drop/swallowed/btn_same/fwd_reports/rx_ovf/lf_drop."""
    p = dev.bin_request(0x45, b'', timeout=1.0)
    if p is None or len(p) < 26:
        return None
    u = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
    d = dict(frames=u(0), nonzero=u(4), fwd_drop=u(8), swallowed=u(12))
    if len(p) >= 42:
        d.update(same=u(26), fwd=u(30), rx_ovf=u(34), lf_drop=u(38))
    if len(p) >= 50:
        d.update(direct_chg=u(42), queued_chg=u(46))
    return d


def inject(dev, btn, mode='console'):
    if mode == 'bin':
        # 0x32 BUTTON：mask u8（1=左键）。走二进制帧，带 seq + CRC，控制口不会因
        # 文本行解析而在高倍率下掉帧——这是"测出来的数是真的"的前提。
        dev.bin_send(0x32, bytes([btn & 0xFF]))
        return
    pl = bytes([btn, 1, 0, 0, 0, 0, 0]).hex()
    dev.ser.write(f'mx.lf a2 81330700 {pl}\r'.encode())


def ensure_no_capture():
    """确保没有残留的 USBPcapCMD 占着抓包设备（否则新实例会立刻退出）。"""
    for _ in range(4):
        out = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq USBPcapCMD.exe'],
                             capture_output=True, text=True, errors='replace').stdout
        if 'USBPcapCMD' not in out:
            return True
        stop_capture(0)
        time.sleep(1.0)
    out = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq USBPcapCMD.exe'],
                         capture_output=True, text=True, errors='replace').stdout
    return 'USBPcapCMD' not in out


def stop_capture(pid):
    """Stop USBPcapCMD.

    USBPcapCMD carries a requireAdministrator manifest, so it runs elevated and a
    normal kill gets Access Denied; the driver also keeps the process inside a
    kernel wait.  Kill by image name from an elevated helper instead.
    """
    ps = os.path.join(os.environ.get('SystemRoot', r'C:\Windows'),
                      r'System32\WindowsPowerShell\v1.0\powershell.exe')
    cmd = ("Start-Process -FilePath taskkill.exe -ArgumentList '/F','/IM','USBPcapCMD.exe' "
           "-Verb RunAs -Wait -WindowStyle Hidden")
    subprocess.run([ps, '-NoProfile', '-ExecutionPolicy', 'Bypass', '-Command', cmd],
                   capture_output=True, timeout=60)


def parse_pcap(path):
    """Read a USBPcap pcap; retry because the writer may still hold the file."""
    data = None
    deadline = time.time() + 10
    while time.time() < deadline:
        try:
            with open(path, 'rb') as f:
                data = f.read()
            break
        except PermissionError:
            time.sleep(0.25)
    if data is None:
        raise PermissionError(f'{path} is still locked (USBPcapCMD did not exit)')
    if len(data) < 24:
        return [], None

    _magic, _vmaj, _vmin, _tz, _sig, _snap, link = struct.unpack('<IHHiIII', data[:24])
    off, reports = 24, []
    while off + 16 <= len(data):
        _ts, _tus, incl, _orig = struct.unpack('<IIII', data[off:off + 16])
        off += 16
        pkt = data[off:off + incl]
        off += incl
        if len(pkt) < 27:
            continue
        hlen, _irp, _st, _fn, _info, _bus, _dev, ep, xfer, dlen = struct.unpack('<HQIHBHHBBI', pkt[:27])
        if xfer == 1 and ep == 0x81 and dlen == 7:
            reports.append(pkt[hlen:hlen + 7])
    return reports, link


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', default=os.environ.get('MAKCU_PORT', 'COM8'))
    ap.add_argument('--baud', type=int, default=921600)
    ap.add_argument('--device', default=r'\\.\USBPcap1')
    ap.add_argument('--exe', default=r'D:\Dev\USBPcap\USBPcapCMD.exe')
    ap.add_argument('--out', default=os.path.join('work', 'btncap_verify.pcap'))
    ap.add_argument('--clicks', type=int, default=20)
    ap.add_argument('--gap-ms', type=int, default=80)
    ap.add_argument('--gap-us', type=int, default=0,
                    help='半周期（微秒）；>0 时覆盖 --gap-ms，可精确设定 55/60/65/70 次/秒等速率')
    ap.add_argument('--sumv', action='store_true',
                    help='run one sumv(400,0,4000) before the clicks (aim/load scenario)')
    ap.add_argument('--binary-sumv', action='store_true',
                    help='interleave the binary 0x36 SUMV command with the clicks')
    ap.add_argument('--sumv-period-ms', type=int, default=60)
    ap.add_argument('--sumv-counts', type=int, default=120)
    ap.add_argument('--sumv-speed', type=int, default=3000)
    ap.add_argument('--sumv-mode', type=int, default=0, choices=[0, 1, 2])
    ap.add_argument('--inject', choices=['console', 'bin'], default='console',
                    help="console = mx.lf 文本帧（旧路径）；bin = 二进制 0x32 BUTTON（带 CRC/seq，推荐）")
    ap.add_argument('--no-cursor', action='store_true')
    a = ap.parse_args()

    if not ensure_no_capture():
        print('ERROR: 有残留的 USBPcapCMD 占着抓包设备，先手动结束它', file=sys.stderr)
        return 2
    if a.gap_us > 0:
        half = a.gap_us / 1e6
    else:
        half = a.gap_ms / 1000.0

    os.makedirs(os.path.dirname(os.path.abspath(a.out)) or '.', exist_ok=True)
    if os.path.exists(a.out):
        try:
            os.remove(a.out)
        except PermissionError:
            print(f'ERROR: {a.out} is locked by a leftover USBPcapCMD', file=sys.stderr)
            return 2
    if not a.no_cursor:
        w, h = park_cursor_topright()
        print(f'cursor -> top-right ({w - 40},{20})')

    dev = Device(a.port, a.baud)
    dev.reset()
    time.sleep(0.3)
    for c in ('mx.hk 1', 'mx.ss 33', 'mx.gd 0'):
        dev.cmd(c)
    # Normalise: make sure the button is released before the capture window opens,
    # otherwise a leftover press from the previous run shows up as an extra edge.
    inject(dev, 0x00, a.inject)
    time.sleep(0.15)

    cap = subprocess.Popen([a.exe, '-d', a.device, '-A', '-o', a.out],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                           creationflags=subprocess.CREATE_NEW_PROCESS_GROUP)
    time.sleep(0.9)
    if cap.poll() is not None:
        print('ERROR: USBPcapCMD exited immediately (wrong device or no access)', file=sys.stderr)
        return 2

    before = usb_stat(dev)
    diag0 = diag_counts(dev)
    audit_before = audit(dev)
    try:
        if a.sumv:
            dev.sumv(400, 0, speed=4000, mode=0)

        if a.binary_sumv:
            # Binary 0x36 SUMV interleaved with the button injections.  One thread
            # writes the port, so there is no write race.  dx alternates sign so the
            # cursor oscillates near the top-right corner instead of hitting the edge.
            period = a.sumv_period_ms / 1000.0
            total = a.clicks * 2 * half
            t_start = time.monotonic()
            next_sumv = t_start
            sent_sumv = 0
            sign = -1
            for k in range(a.clicks * 2):
                target = t_start + (k + 1) * half
                while time.monotonic() < target:
                    if time.monotonic() >= next_sumv:
                        dev.sumv(sign * a.sumv_counts, 0, speed=a.sumv_speed, mode=a.sumv_mode)
                        sent_sumv += 1
                        sign = -sign
                        next_sumv += period
                    time.sleep(0.002)
                inject(dev, 0x01 if k % 2 == 0 else 0x00, a.inject)
            print(f'binary sumv issued: {sent_sumv} commands over {total:.2f}s')
            time.sleep(0.3)
            dev.sumv_stop()
            dev.sumv_wait_done(timeout=10.0)
        else:
            for _ in range(a.clicks):
                inject(dev, 0x01, a.inject)
                time.sleep(half)
                inject(dev, 0x00, a.inject)
                time.sleep(half)
            time.sleep(0.4)
            if a.sumv:
                dev.sumv_wait_done(timeout=10.0)
        after = usb_stat(dev)
        diag1 = diag_counts(dev)
        audit_after = audit(dev)
    finally:
        stop_capture(cap.pid)
        for _ in range(20):
            if cap.poll() is not None:
                break
            time.sleep(0.25)
        time.sleep(0.5)
        dev.cmd('mx.ss 00')
        dev.close()

    reports, link = parse_pcap(a.out)
    vals = [r[0] & 0x1F for r in reports]
    wire = (after['wire'] - before['wire']) & 0xFFFF

    d_delta = {}
    if diag0 and diag1:
        for k in diag0:
            if diag0[k] is not None and diag1.get(k) is not None:
                d_delta[k] = diag1[k] - diag0[k]
        print('firmware counters: ' + ' '.join(f'{k}+{v}' for k, v in d_delta.items()))

    edges, prev = [], 0x00
    for v in vals:
        if v != prev:
            edges.append(v)
            prev = v
    expect = []
    for _ in range(a.clicks):
        expect += [0x01, 0x00]
    runs = [i for i in range(1, len(vals)) if vals[i] == vals[i - 1]]

    print(f'pcap={a.out} linktype={link} reports={len(reports)} (same-value repeats {len(runs)})')
    print(f'firmware wire_chg +{wire} (pin {before["pin"]}->{after["pin"]}, overflow {after["over"]})')
    print(f'pc side: edges={len(edges)}')
    if edges:
        print('edge sequence:', ' '.join(f'{v:02x}' for v in edges[:40]))

    ok = True
    if link != 249:
        print(f'FAIL: linktype={link} (expected 249 = USBPCAP)')
        ok = False
    if wire != 2 * a.clicks:
        print(f'FAIL: firmware wire_chg delta {wire}, expected {2 * a.clicks}')
        ok = False
    if len(edges) != 2 * a.clicks:
        print(f'FAIL: {len(edges)} button edges on the wire, expected {2 * a.clicks} (dropped or duplicated)')
        ok = False
    if edges != expect:
        print('FAIL: edge sequence is not a clean press/release alternation')
        ok = False
    if a.inject == 'bin':
        # 二进制 0x32 走引擎路径（makcu_mouse_set_buttons），不经过链路 sink，
        # 所以"到没到"要看 0x3F 的 in_chg 增量，而不是 0x45 frames。
        achg = (audit_after['in_chg'] - audit_before['in_chg']) if audit_before and audit_after else None
        if achg is not None and achg != 2 * a.clicks:
            print(f'FAIL: 0x3F in_chg +{achg}，注入 {2 * a.clicks} 次变化（注入侧丢帧，测试无效）')
            ok = False
        if frames := d_delta.get('frames'):
            print(f'note: 0x45 frames +{frames}（0x32 不走链路，正常应为 0）')
    if vals and vals[-1] != 0x00:
        print('FAIL: last captured report still has the button pressed (stuck)')
        ok = False

    print('PASS: PC side matches firmware (no lost edge, no extra edge, no stuck)' if ok else 'FAILED')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
