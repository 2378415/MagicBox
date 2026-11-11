"""link_probe.py - 控制口二进制快速通道的功能与延迟探针。

协议（见 app_left/main/control_bin.h）：

    5A <cmd> <seq> <len u16 LE> <payload> <crc8>
    crc8 = poly 0x07，覆盖 cmd..payload（即整帧去掉 magic 与 crc 自身）

交互命令不回包；只有 QUERY / PING 回（cmd | 0x80，seq 原样带回）。所以延迟只能用
PING 量，丢包只能靠 seq 缺口 + CRC 计数统计。

用法：
    python tools/link_probe.py --ping 200
    python tools/link_probe.py --plan 300 0
    python tools/link_probe.py --button 1 --wheel -1
    python tools/link_probe.py --all
"""
import argparse
import os
import statistics
import sys
import time

try:
    import serial
except ImportError:
    serial = None

PORT = os.environ.get('MAKCU_PORT', 'COM3')
BAUD = int(os.environ.get('MAKCU_BAUD', '921600'))

MAGIC = 0x5A
P_MOTION = 0x31
P_BUTTON = 0x32
P_WHEEL = 0x33
P_QUERY = 0x34
P_PING = 0x35
P_SUMV = 0x36
P_SUMV_STOP = 0x37
P_SUMV_STATE = 0x38
P_AIM = 0x3C
P_AIM_STATE = 0x3D
P_EVT_CTL = 0x39
P_EVT_READ = 0x3A
P_EVT_STAT = 0x3B
P_EVT_PUSH = 0xE1
REPLY = 0x80


def crc8(data):
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = ((crc << 1) ^ 0x07) & 0xFF if (crc & 0x80) else ((crc << 1) & 0xFF)
    return crc


def frame(cmd, seq, payload=b''):
    body = bytes([cmd, seq & 0xFF, len(payload) & 0xFF, (len(payload) >> 8) & 0xFF]) + payload
    return bytes([MAGIC]) + body + bytes([crc8(body)])


def open_port(port, baud):
    if serial is None:
        sys.exit('pyserial missing')
    s = serial.Serial(port, baud, timeout=0.05)
    s.dtr = False
    s.rts = False
    time.sleep(0.4)
    s.reset_input_buffer()
    return s


class Reader:
    """后台不需要线程：这里用非阻塞轮询把字节攒成帧。"""

    def __init__(self, ser):
        self.ser = ser
        self.buf = bytearray()
        self.cache = []

    def pump(self, deadline, want=None):
        """读到 deadline 为止；给了 want(cmd, seq) 就在命中后立刻返回，别把等待算进 RTT。"""
        while time.time() < deadline:
            n = self.ser.in_waiting
            if n:
                self.buf += self.ser.read(n)
                if want is not None:
                    for f in self.frames():
                        self.cache.append(f)
                        if want(f['cmd'], f['seq']):
                            return True
            else:
                time.sleep(0.0005)
        return False

    def frames(self):
        out = []
        while True:
            i = self.buf.find(MAGIC)
            if i < 0 or len(self.buf) - i < 6:
                if i > 0:
                    del self.buf[:i]
                return out
            if i > 0:
                del self.buf[:i]
            if len(self.buf) < 5:
                return out
            ln = self.buf[3] | (self.buf[4] << 8)
            total = 5 + ln + 1
            if len(self.buf) < total:
                return out
            body = bytes(self.buf[1:5 + ln])
            if crc8(body) != self.buf[total - 1]:
                del self.buf[:1]
                continue
            out.append({'cmd': body[0], 'seq': body[1], 'payload': body[4:]})
            del self.buf[:total]


def ping(ser, n=100):
    rd = Reader(ser)
    rtts = []
    lost = 0
    for i in range(n):
        seq = i & 0xFF
        payload = (i * 0x010101).to_bytes(4, 'little')
        rd.cache.clear()
        t0 = time.perf_counter()
        ser.write(frame(P_PING, seq, payload))
        ser.flush()
        hit = rd.pump(time.time() + 0.15,
                      want=lambda c, q: c == (P_PING | REPLY) and q == seq)
        got = next((f for f in rd.cache
                    if f['cmd'] == (P_PING | REPLY) and f['seq'] == seq), None)
        if got is None or not hit:
            lost += 1
            continue
        rtts.append((time.perf_counter() - t0) * 1e6)
        if got['payload'][:4] != payload:
            print('  ! ping payload mismatch')
    if not rtts:
        print('ping: no replies (lost %d/%d)' % (lost, n))
        return
    rtts.sort()
    p = lambda q: rtts[min(len(rtts) - 1, int(q * len(rtts)))]
    print(f'ping x{n}: lost {lost}  p50 {p(0.5):.0f} us  p90 {p(0.9):.0f} us  '
          f'p99 {p(0.99):.0f} us  max {rtts[-1]:.0f} us  (min {rtts[0]:.0f})')


def query(ser, what, wait=0.15):
    rd = Reader(ser)
    seq = 0x77
    ser.write(frame(P_QUERY, seq, bytes([what])))
    ser.flush()
    rd.pump(time.time() + wait)
    for f in rd.frames():
        if f['cmd'] == (P_QUERY | REPLY):
            return f['payload']
    return None


def show_query(ser):
    p0 = query(ser, 0)
    if p0:
        pkts = int.from_bytes(p0[0:4], 'little')
        crc = int.from_bytes(p0[4:8], 'little')
        ln = int.from_bytes(p0[8:12], 'little')
        gaps = int.from_bytes(p0[12:16], 'little')
        print(f'query0: pkts={pkts} crc_err={crc} len_err={ln} seq_gaps={gaps} '
              f'last_seq={p0[16]} proto={p0[17]}')
    else:
        print('query0: no reply')
    p1 = query(ser, 1)
    if p1:
        clk = int.from_bytes(p1[4:8], 'little')
        print(f'query1: proto={p1[0]} max_payload={p1[1]} plan_engine={p1[2]} clock_us={clk}')
    else:
        print('query1: no reply')
    p2 = query(ser, 2)
    if p2:
        dx = int.from_bytes(p2[0:2], 'little', signed=True)
        dy = int.from_bytes(p2[2:4], 'little', signed=True)
        dur = int.from_bytes(p2[4:6], 'little')
        recv = int.from_bytes(p2[6:10], 'little')
        sub = int.from_bytes(p2[10:14], 'little')
        plans = int.from_bytes(p2[14:18], 'little')
        print(f'query2: last_plan dx={dx} dy={dy} dur={dur}ms recv_us={recv} '
              f'submit_us={sub} plans={plans}')
    else:
        print('query2: no reply')


def plan(ser, dx, dy, dur=0, mode=0, flags=0):
    payload = (int(dx).to_bytes(2, 'little', signed=True)
               + int(dy).to_bytes(2, 'little', signed=True)
               + int(dur).to_bytes(2, 'little')
               + bytes([mode, flags]))
    ser.write(frame(P_MOTION, 0x10, payload))
    ser.flush()
    print(f'motion_plan: dx={dx} dy={dy} dur={dur} mode={mode} flags={flags} '
          f'({len(payload) + 6} bytes)')


def text(ser, cmd, wait=0.25, retries=3):
    for _ in range(retries):
        ser.reset_input_buffer()
        ser.write(cmd.encode() + b'\r')
        ser.flush()
        time.sleep(wait)
        out = ser.read(ser.in_waiting).decode('latin-1', 'replace')
        if out:
            return out.replace('\r\n>>> ', '').strip()
    return ''


def sumv(ser, dx, dy, speed=0, mode=0x00, seed=0, dur=0, wait=0.0):
    """0x36 SUMV：dx i16, dy i16, speed u16, mode u8, seed u8 [, dur u16]"""
    payload = (int(dx).to_bytes(2, 'little', signed=True)
               + int(dy).to_bytes(2, 'little', signed=True)
               + int(speed).to_bytes(2, 'little')
               + bytes([mode & 0xFF, seed & 0xFF]))
    if mode & 1:
        payload += int(dur).to_bytes(2, 'little')
    ser.write(frame(P_SUMV, 0x40, payload))
    ser.flush()
    print(f'sumv: dx={dx} dy={dy} speed={speed or 400} mode=0x{mode:02x} '
          f'({len(payload) + 6} bytes)')
    if wait:
        time.sleep(wait)


def sumv_state(ser, wait=0.2):
    rd = Reader(ser)
    ser.write(frame(P_SUMV_STATE, 0x41))
    ser.flush()
    rd.pump(time.time() + wait)
    for f in rd.frames():
        if f['cmd'] == (P_SUMV_STATE | REPLY):
            p = f['payload']

            def u32(o):
                return int.from_bytes(p[o:o + 4], 'little')
            print(f"sumv_state: active={p[0]} samples={u32(1)} aborted={u32(5)} "
                  f"rounds={u32(9)} muted={u32(13)} btn_fwd={u32(17)} "
                  f"speed_eff={u32(21)} remain_ms={u32(25)}")
            return p
    print('sumv_state: no reply')
    return None


def sumv_stop(ser):
    ser.write(frame(P_SUMV_STOP, 0x42))
    ser.flush()
    print('sumv_stop sent')


def evt_listen(ser, mask, seconds, self_test=False, consume=False):
    """订阅按键事件并打印。mask: 1 左 2 右 4 中 8 侧4 16 侧5。

    consume=False（默认）：**穿透**——按键照常给 PC，只上报事件；
    consume=True：**吃掉**——订阅的键从转发报告里抹掉，PC 看不到。
    """
    # enable + push + consume(默认 0 = 穿透；1 = 吃掉这些键)
    ser.write(frame(P_EVT_CTL, 0x70, bytes([1, mask & 0x1F, 1, 1 if consume else 0])))
    ser.flush()
    mode = '吃掉：这些键 PC 看不到' if consume else '穿透：按键照常给 PC'
    print(f'evt: 已订阅 mask=0x{mask:02x}（{mode}）', flush=True)
    rd = Reader(ser)
    t_end = time.time() + seconds
    last_hb = time.time()
    selftest_done = not self_test
    while time.time() < t_end:
        if not selftest_done:
            # 台架自测：用 mx.lfx 注入"真实鼠标"报告（侧键按下 → 松开）
            print('  (selftest) 注入 侧键 按下 / 松开', flush=True)
            ser.write(b'mx.lfx 08000000000000\r'); ser.flush()
            time.sleep(0.4)
            ser.write(b'mx.lfx 00000000000000\r'); ser.flush()
            selftest_done = True
        rd.pump(time.time() + 0.05)
        for f in rd.frames():
            if f['cmd'] == P_EVT_PUSH:
                p = f['payload']
                t_us = int.from_bytes(p[0:4], 'little')
                seq = p[4] | (p[5] << 8)
                print(f'  EVT  seq={seq:5d} t_us={t_us:10d} mask=0x{p[6]:02x} edge=0x{p[7]:02x}')
            elif f['cmd'] == (P_EVT_STAT | REPLY):
                p = f['payload']
                print(f'  STAT seq={p[0] | (p[1] << 8)} count={p[2]} '
                      f'overflow={int.from_bytes(p[3:7], "little")} mask=0x{p[7]:02x} '
                      f'pending=0x{p[8]:02x} cur=0x{p[9]:02x} last_fwd=0x{p[10]:02x} '
                      f'flags=0x{p[11]:02x}')
        if time.time() - last_hb > 1.2:            # 心跳，避免 10 s 自动恢复
            last_hb = time.time()
            ser.write(frame(P_EVT_STAT, 0x71)); ser.flush()
    ser.write(frame(P_EVT_CTL, 0x72, bytes([0, 0, 0, 0])))   # 取消订阅
    ser.flush()
    print('evt: 已取消订阅')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', default=PORT)
    ap.add_argument('--baud', type=int, default=BAUD)
    ap.add_argument('--ping', type=int, help='PING 次数')
    ap.add_argument('--plan', nargs=2, type=int, metavar=('DX', 'DY'))
    ap.add_argument('--dur', type=int, default=0)
    ap.add_argument('--button', type=int, help='按键位图（1=左 2=右 4=中）')
    ap.add_argument('--wheel', type=int)
    ap.add_argument('--query', action='store_true')
    ap.add_argument('--sumv', nargs=2, type=int, metavar=('DX', 'DY'),
                    help='二进制 SUMV（拟人化相对移动）')
    ap.add_argument('--speed', type=int, default=0, help='SUMV 速度 counts/s，0=默认 400')
    ap.add_argument('--max-report', type=int, default=0,
                    help='每报告最多 counts（8–127）；会先发 mx.mv 应用，决定速度上限')
    ap.add_argument('--sumv-stop', action='store_true')
    ap.add_argument('--evt', type=lambda x: int(x, 0),
                    help='订阅按键事件（掩码，可写 0x08）并打印，如 --evt 0x08')
    ap.add_argument('--evt-seconds', type=float, default=8.0)
    ap.add_argument('--evt-selftest', action='store_true',
                    help='订阅期间用 mx.lfx 注入一次"侧键按下/松开"做自测')
    ap.add_argument('--evt-consume', action='store_true',
                    help='订阅时把这些键吃掉（PC 看不到）；默认穿透')

    ap.add_argument('--aim', nargs=2, type=int, metavar=('DX', 'DY'),
                    help='瞄准专用：发 0x3C AIM（按 max_ms 定时长）')
    ap.add_argument('--aim-ms', type=int, default=8, help='AIM 的 max_ms（默认 8）')
    ap.add_argument('--aim-dead', type=int, default=0, help='AIM 死区 counts（0=固件默认 2）')
    ap.add_argument('--aim-fast', action='store_true', help='AIM 用极速档')
    ap.add_argument('--aim-state', action='store_true', help='只读 AIM_STATE')
    ap.add_argument('--all', action='store_true')
    args = ap.parse_args()

    ser = open_port(args.port, args.baud)
    try:
        print('text  .km.version() ->', text(ser, '.km.version()'))

        if args.aim_state or args.aim:
            if args.aim:
                ax, ay = args.aim
                pl = ((ax & 0xFFFF).to_bytes(2, 'little')
                      + (ay & 0xFFFF).to_bytes(2, 'little')
                      + bytes([max(4, min(255, args.aim_ms)),
                               1 if args.aim_fast else 0,
                               max(0, min(255, args.aim_dead))]))
                ser.write(frame(P_AIM, 0x60, pl))
                ser.flush()
                print(f'aim  : 已发 AIM({ax},{ay}, max_ms={args.aim_ms})')
            time.sleep(0.15)
            rd = Reader(ser)
            ser.write(frame(P_AIM_STATE, 0x61))
            ser.flush()
            rd.pump(time.time() + 0.6)
            st = None
            for f in rd.frames():
                if f['cmd'] == (P_AIM_STATE | REPLY):
                    st = f['payload']
                    break
            if st and len(st) >= 12:
                res = {1: '已启动/已到位', 2: '被替换', 3: '拒绝', 4: '死区',
                       5: '看门狗故障', 6: '超限'}.get(st[1], st[1])
                print(f'aim  : active={st[0]} last_result={st[1]}({res}) '
                      f'counts={st[2] | (st[3] << 8)} dur={st[4] | (st[5] << 8)}ms '
                      f'aborted={st[6] | (st[7] << 8)} rounds={st[8] | (st[9] << 8)} '
                      f'dead_hits={st[10]} gen={st[11]}')
            else:
                print('aim  : 回包超时')
            if args.aim:
                return 0

        if args.all:
            args.ping = 100
            args.query = True
            args.plan = (200, 0)
            args.button = 0
            args.wheel = 1
        if args.query:
            show_query(ser)
        if args.sumv:
            if args.max_report:
                text(ser, f'mx.mv {args.speed or 400} {args.max_report}')
            sumv(ser, args.sumv[0], args.sumv[1], args.speed)
            for _ in range(60):
                p = sumv_state(ser, 0.12)
                if p is not None and p[0] == 0:
                    break
            print('mx.rt:', text(ser, 'mx.rt'))
        if args.sumv_stop:
            sumv_stop(ser)
        if args.evt is not None:
            evt_listen(ser, args.evt, args.evt_seconds, args.evt_selftest,
                       consume=args.evt_consume)
        if args.ping:
            ping(ser, args.ping)
            show_query(ser)
        if args.plan:
            rt0 = text(ser, 'mx.rt')
            plan(ser, args.plan[0], args.plan[1], args.dur)
            time.sleep(0.5)
            show_query(ser)
            print('mx.rt  before/after:', rt0, '/', text(ser, 'mx.rt'))
        if args.button is not None:
            ser.write(frame(P_BUTTON, 0x20, bytes([args.button])))
            ser.flush()
            time.sleep(0.2)
            print('button ->', args.button, '| mx.bo:', text(ser, 'mx.bo'))
            ser.write(frame(P_BUTTON, 0x21, bytes([0])))
            ser.flush()
            time.sleep(0.2)
        if args.wheel is not None:
            ser.write(frame(P_WHEEL, 0x30, bytes([args.wheel & 0xFF])))
            ser.flush()
            time.sleep(0.3)
            print('wheel ->', args.wheel, '| mx.rt:', text(ser, 'mx.rt'))
    finally:
        ser.close()


if __name__ == '__main__':
    main()

