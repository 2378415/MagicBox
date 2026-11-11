"""pytest fixtures for protocol regression against real hardware (T2).

The device is a MAKCU box whose control port is a CH343 bridge (COM8 on this
machine).  Two quirks are already documented in the old repo and handled here:

  * the port enumerates as soon as it has power, even when the app is stuck, so
    a DTR/RTS pulse is required before every session;
  * replies are "km." + content + "\\r\\n>>> " and some commands answer with
    nothing at all (unknown command, `silent()` with fewer than two arguments).

Environment:
    MAKCU_PORT   default COM8
    MAKCU_BAUD   default 921600
    MAKCU_SKIP_HW=1  to collect tests without hardware
"""
import os
import re
import time

import pytest

try:
    import serial
except ImportError:            # hardware tests get skipped without pyserial
    serial = None

PORT = os.environ.get('MAKCU_PORT', 'COM8')
BAUD = int(os.environ.get('MAKCU_BAUD', '921600'))
SKIP = os.environ.get('MAKCU_SKIP_HW') == '1'


class Device:
    def __init__(self, port, baud):
        self.ser = serial.Serial(port, baud, timeout=0.1)

    def reset(self):
        """DTR/RTS pulse: DTR false->true, RTS true->false (old repo, §1)."""
        self.ser.dtr = False
        self.ser.rts = True
        time.sleep(0.05)
        self.ser.dtr = True
        self.ser.rts = False
        time.sleep(0.6)

    def drain(self, quiet=0.35, limit=2.0):
        buf = bytearray()
        t0 = last = time.time()
        while time.time() - t0 < limit:
            n = self.ser.in_waiting
            if n:
                buf += self.ser.read(n)
                last = time.time()
            elif buf and time.time() - last > quiet:
                break
            else:
                time.sleep(0.01)
        return bytes(buf)

    def cmd(self, text):
        """Send one command line (CR terminated) and return the raw reply."""
        self.ser.write(text.encode('latin-1') + b'\r')
        self.ser.flush()
        return self.drain()

    # ---------------------------------------------------------- 二进制帧
    # 0x36 SUMV 这类命令没有文本接口（`mx.*` 是台架旁路），所以测试要自己组帧：
    #   5A <cmd> <seq> <len_lo> <len_hi> <payload...> <crc8>
    # crc8 = poly 0x07，覆盖 cmd..payload（不含 5A 和 crc 本身）。
    @staticmethod
    def _crc8(data):
        crc = 0
        for b in data:
            crc ^= b
            for _ in range(8):
                crc = ((crc << 1) ^ 0x07) & 0xFF if (crc & 0x80) else ((crc << 1) & 0xFF)
        return crc

    def _frame(self, cmd, seq, payload=b''):
        body = bytes([cmd, seq & 0xFF, len(payload) & 0xFF, (len(payload) >> 8) & 0xFF]) + payload
        return b'\x5a' + body + bytes([self._crc8(body)])

    def _next_seq(self):
        self._seq = (getattr(self, '_seq', 0) + 1) & 0xFF
        return self._seq

    def bin_send(self, cmd, payload=b'', seq=None):
        """发一帧，不等回包（0x36/0x37 这类无回包的命令）。"""
        seq = self._next_seq() if seq is None else seq
        self.ser.reset_input_buffer()
        self.ser.write(self._frame(cmd, seq, payload))
        self.ser.flush()
        return seq

    def bin_request(self, cmd, payload=b'', timeout=2.0, seq=None):
        """发一帧并等回包（`cmd|0x80` 且 seq 匹配），返回 payload；超时返回 None。"""
        seq = self._next_seq() if seq is None else seq
        self.ser.reset_input_buffer()
        self.ser.write(self._frame(cmd, seq, payload))
        self.ser.flush()
        want = cmd | 0x80
        buf = bytearray()
        deadline = time.time() + timeout
        while time.time() < deadline:
            n = self.ser.in_waiting
            if n:
                buf += self.ser.read(n)
            while True:
                i = buf.find(0x5A)
                if i < 0:
                    buf.clear()
                    break
                if i:
                    del buf[:i]
                if len(buf) < 6:
                    break
                ln = buf[3] | (buf[4] << 8)
                total = 5 + ln + 1
                if len(buf) < total:
                    break
                frame_bytes = bytes(buf[:total])
                # CRC 覆盖 cmd..payload（不含 0x5A 前缀、不含 crc 本身）
                if self._crc8(frame_bytes[1:-1]) != frame_bytes[-1]:
                    del buf[:1]
                    continue
                c, sq = frame_bytes[1], frame_bytes[2]
                del buf[:total]
                if c == want and sq == seq:
                    return frame_bytes[5:5 + ln]
            time.sleep(0.002)
        return None

    def sumv_state(self):
        """0x38 SUMV_STATE → dict（29 B），失败返回 None。"""
        p = self.bin_request(0x38, b'', timeout=1.5)
        if p is None or len(p) < 29:
            return None
        u32 = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
        return {
            'active': p[0],
            'samples': u32(1),
            'aborted': u32(5),
            'rounds': u32(9),
            'muted': u32(13),
            'fwd': u32(17),
            'speed_eff': u32(21),
            'remain': u32(25),
            'raw_len': len(p),
        }

    def sumv(self, dx, dy, speed=12000, mode=0, seed=0, dur_ms=None):
        """0x36 SUMV：dx/dy 是 counts（i16），speed 是 counts/s。"""
        pl = (int(dx) & 0xFFFF).to_bytes(2, 'little') + (int(dy) & 0xFFFF).to_bytes(2, 'little')
        pl += (int(speed) & 0xFFFF).to_bytes(2, 'little') + bytes([mode & 0xFF, seed & 0xFF])
        if dur_ms is not None:
            pl += (int(dur_ms) & 0xFFFF).to_bytes(2, 'little')
        return self.bin_send(0x36, pl)

    def sumv_stop(self):
        return self.bin_send(0x37, b'')

    def sumv_wait_done(self, timeout=4.0):
        """轮询到 active==0；返回最后一次 state（超时也会返回当前值）。"""
        deadline = time.time() + timeout
        st = None
        while time.time() < deadline:
            st = self.sumv_state()
            if st is not None and st['active'] == 0:
                return st
            time.sleep(0.01)
        return st

    def rt(self):
        """mx.rt → (dx, dy, wheel) 累计位移。

        坑：`mx.lf ...` 这类命令的回包（一个数字）可能和 `mx.rt` 的回包黏在一起，
        形如 `15\r\n>>> 0,0,0\r\n>>> `。所以用正则抓**最后一组** `a,b,c`。
        """
        reply = self.cmd('mx.rt').decode('latin-1', 'replace')
        hit = re.findall(r'(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)', reply)
        assert hit, f'mx.rt 回包解析失败: {reply!r}'
        dx, dy, wheel = hit[-1]
        return int(dx), int(dy), int(wheel)

    def close(self):
        self.ser.close()


@pytest.fixture(scope='session')
def device():
    if SKIP or serial is None:
        pytest.skip('hardware tests disabled (MAKCU_SKIP_HW=1 or pyserial missing)')
    try:
        dev = Device(PORT, BAUD)
    except Exception as exc:            # no port, busy port, ...
        pytest.skip(f'cannot open {PORT}: {exc}')
    dev.reset()
    dev.drain(limit=0.4)
    yield dev
    dev.close()


# The CH343 port cannot reset the chip (no EN/IO0 wiring), so RAM state survives
# between runs.  Every state-touching command is cleared before the assertions
# that expect a fresh device: channel flags (0x00), axis bytes (0x02), buttons
# mode (0x0C) and the press/release slots (0x04).
CLEAR_COMMANDS = [
    '.km.lock_ml(0)', '.km.lock_mr(0)', '.km.lock_mm(0)',
    '.km.lock_ms1(0)', '.km.lock_ms2(0)',
    '.km.lock_mx(0)', '.km.lock_my(0)',
    '.km.buttons(0)',
    '.km.left(0)', '.km.right(0)', '.km.middle(0)',
    '.km.front(0)', '.km.ms1(0)', '.km.ms2(0)',
]


@pytest.fixture(scope='session')
def device_ready(device):
    """Sanity gate: the link must answer version, then known-zero state."""
    reply = device.cmd('.km.version()')
    assert reply == b'km.MAKCU\r\n>>> ', f'unexpected version reply: {reply!r}'
    for cmd in CLEAR_COMMANDS:
        device.cmd(cmd)
    return device


# ---------------------------------------------------------------- 克隆状态护栏
# `test_clone_descriptors.py` 会用 `mx.cl <n>` 装上 4 字节的出厂夹具（默认 1 号），
# 文件末尾虽然又发了一次 `mx.cl 1`，但**从来没有恢复成"克隆真实鼠标"**。
# 结果是：按字母序排在它后面的 `test_mouse_reports.py` 面对的是一个 4 字节夹具，
# 真实鼠标的 7 字节报告被当 12-bit 解 → mx.rq / mx.rt 里全是垃圾 → 位移断言成片失败。
# （2026-11-11 定位：`mx.if` 变成 0、`mx.rb` 变成 `bytes=4 desc=52`。）
#
# 这个 autouse 的模块级 fixture 在每个测试模块结束后检查一次：只要接口数不是 2
# （复合构建下唯一的健康态），就 `mx.rs` 重启让固件重新 autoclone，并等它枚举回来。
REAL_CLONE_IFACE_HEAD = '2 '


def _clone_is_real(dev):
    reply = dev.cmd('mx.if')
    text = reply.decode('latin-1', 'replace').replace('km.', '').strip()
    return text.startswith(REAL_CLONE_IFACE_HEAD), text


def _clone_is_fixture():
    """返回 (是否需要恢复, mx.if 文本)。"""
    try:
        dev = Device(PORT, BAUD)
    except Exception:
        return False, 'port busy'
    try:
        return (not _clone_is_real(dev)[0]), _clone_is_real(dev)[1]
    finally:
        try:
            dev.close()
        except Exception:
            pass


def _restore_real_clone(tag):
    """确保盒子跑的是"克隆真实鼠标"。不是就 mx.rs 重启重克隆，最多 3 轮。"""
    need, text = _clone_is_fixture()
    if not need:
        return True
    for attempt in range(1, 4):
        print(f'\n[clone-guard:{tag}] 第 {attempt} 次: mx.if={text!r} → mx.rs 重启重克隆')
        try:
            dev = Device(PORT, BAUD)
            dev.cmd('mx.rs')
            dev.close()
        except Exception:
            pass
        # 2026-11-11 补：reboot 之后右片有时很久都不重新枚举到鼠标，光等没用。
        # `mx.ac` = "立刻重克隆一次"（不重启），实测能马上把 4 字节夹具换回真实克隆。
        time.sleep(3.0)
        try:
            dev = Device(PORT, BAUD)
            ok2, text2 = _clone_is_real(dev)
            if not ok2:
                dev.cmd('mx.ac')
                time.sleep(1.5)
                ok2, text2 = _clone_is_real(dev)
            dev.close()
            if ok2:
                time.sleep(1.5)
                print(f'[clone-guard:{tag}] mx.ac 恢复完成（第 {attempt} 次）: mx.if={text2!r}')
                return True
        except Exception:
            pass
        deadline = time.time() + 12
        while time.time() < deadline:
            time.sleep(2.0)
            need, text = _clone_is_fixture()
            if not need:
                time.sleep(2.0)      # 让 0xA2 会话 / link bridge 也回到稳定态
                print(f'[clone-guard:{tag}] 恢复完成（第 {attempt} 次）: mx.if={text!r}')
                return True
    print(f'[clone-guard:{tag}] 3 次重启后仍没恢复（mx.if={text!r}），后续用例可能失败')
    return False


@pytest.fixture(scope='session', autouse=True)
def ensure_real_clone_at_start():
    """**会话开始**就先确认克隆健康。

    背景：`test_clone_descriptors.py` 会装上 4 字节出厂夹具，跑完盒子通常就停在夹具上；
    下一轮回归如果直接开跑，前面几个模块全在错误的报告布局下执行，会成片失败。
    所以在任何用例之前先恢复一次。
    """
    if SKIP or serial is None:
        yield
        return
    _restore_real_clone('session-start')
    yield


@pytest.fixture(autouse=True, scope='module')
def restore_real_clone():
    yield
    if SKIP or serial is None:
        return
    _restore_real_clone('module-end')


