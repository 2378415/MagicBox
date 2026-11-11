"""控制口链路层：串口线程、二进制帧解析、文本回包、mx.mt 轨迹转储。

设计要点
--------
* 一个 reader 线程读串口，把原始分片塞进 `rawq`（供轨迹转储用），同时把解析出的
  二进制帧 / 文本回包分发给回调。GUI 只在主线程 `after()` 里取队列，不碰串口。
* 二进制请求按 (cmd, seq) 匹配；`0xE1` 是设备主动推的事件帧，直接进事件回调。
* 文本回包规则：`km.` + 内容 + `\\r\\n>>> `；`mx.*` 台架命令也走这条通道。
* 心跳：`heartbeat()` 由上层每 1.5 s 调一次，避免按键事件订阅 10 s 后自动失效。
"""
from __future__ import annotations

import queue
import re
import threading
import time

import serial

MAGIC = 0x5A
REPLY = 0x80

P_MOTION = 0x31
P_BUTTON = 0x32
P_WHEEL = 0x33
P_QUERY = 0x34
P_PING = 0x35
P_SUMV = 0x36
P_SUMV_STOP = 0x37
P_SUMV_STATE = 0x38
P_EVT_CTL = 0x39
P_EVT_READ = 0x3A
P_EVT_STAT = 0x3B
P_EVT_PUSH = 0xE1

MT_RE = re.compile(r'(\d{4,}),([0-9a-f]{2}),(\d{1,2}),([0-9a-f]{0,16})')


def crc8(data: bytes) -> int:
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = ((crc << 1) ^ 0x07) & 0xFF if (crc & 0x80) else ((crc << 1) & 0xFF)
    return crc


def frame(cmd: int, seq: int, payload: bytes = b'') -> bytes:
    body = bytes([cmd, seq & 0xFF, len(payload) & 0xFF, (len(payload) >> 8) & 0xFF]) + payload
    return bytes([MAGIC]) + body + bytes([crc8(body)])


class BoxLink:
    """一条控制口连接。所有方法都能在后台线程里调用（内部有锁）。"""

    def __init__(self, port: str, baud: int = 921600,
                 on_text=None, on_event=None, on_frame=None, on_log=None):
        self.port = port
        self.baud = baud
        self.on_text = on_text
        self.on_event = on_event
        self.on_frame = on_frame
        self.on_log = on_log

        self._ser: serial.Serial | None = None
        self._thr: threading.Thread | None = None
        self._stop = threading.Event()
        self._lock = threading.Lock()
        self._seq = 0

        self.rawq: queue.Queue = queue.Queue(maxsize=4000)
        self._binary_wait: dict[tuple[int, int], queue.Queue] = {}
        self._text_q: queue.Queue = queue.Queue()

        self._txt_acc = bytearray()
        self._bin_acc = bytearray()
        self.rx_bytes = 0
        self.rx_error = None            # 读/解析线程的最近一次异常 

    # ---------------------------------------------------------------- 连接
    def open(self):
        self._ser = serial.Serial(self.port, self.baud, timeout=0.02, write_timeout=1.0)
        try:
            self._ser.dtr = False
            self._ser.rts = False
        except Exception:
            pass
        time.sleep(0.35)                      # 设备刚上电要 ~1s 才应答
        self._ser.reset_input_buffer()
        self._stop.clear()
        self._thr = threading.Thread(target=self._reader, name='boxbench-rx', daemon=True)
        self._thr.start()
        self._log(f'[link] 已打开 {self.port} @{self.baud}')

    def close(self):
        self._stop.set()
        if self._thr is not None:
            self._thr.join(timeout=1.0)
            self._thr = None
        if self._ser is not None:
            try:
                self._ser.close()
            except Exception:
                pass
            self._ser = None
        self._log('[link] 已关闭')

    @property
    def is_open(self) -> bool:
        return self._ser is not None and self._ser.is_open

    def _log(self, msg: str):
        if self.on_log is not None:
            self.on_log(msg)

    # ----------------------------------------------------------------- 收发
    def write_raw(self, data: bytes):
        if not self.is_open:
            raise RuntimeError('串口未连接')
        with self._lock:
            self._ser.write(data)
            self._ser.flush()

    def send_text(self, cmd: str):
        cmd = cmd if cmd.endswith('\r') else cmd + '\r'
        self.write_raw(cmd.encode('latin-1'))
        self._log(f'>> {cmd.strip()}')

    def next_seq(self) -> int:
        self._seq = (self._seq + 1) & 0xFF
        return self._seq

    def send_frame(self, cmd: int, payload: bytes = b'', seq: int | None = None):
        seq = self.next_seq() if seq is None else seq
        self.write_raw(frame(cmd, seq, payload))
        return seq

    def request(self, cmd: int, payload: bytes = b'', timeout: float = 0.5,
                seq: int | None = None) -> bytes | None:
        """二进制请求：等 `cmd|0x80` 且 seq 匹配的回包。"""
        seq = self.next_seq() if seq is None else seq
        q: queue.Queue = queue.Queue(maxsize=4)
        self._binary_wait[(cmd | REPLY, seq)] = q
        try:
            self.write_raw(frame(cmd, seq, payload))
            return q.get(timeout=timeout)
        except queue.Empty:
            return None
        finally:
            self._binary_wait.pop((cmd | REPLY, seq), None)

    def text_request(self, cmd: str, timeout: float = 0.6) -> str | None:
        """文本请求：等一条 `km.` 回包（去掉尾部 prompt）。"""
        while not self._text_q.empty():
            try:
                self._text_q.get_nowait()
            except queue.Empty:
                break
        self.send_text(cmd)
        try:
            return self._text_q.get(timeout=timeout)
        except queue.Empty:
            return None

    def heartbeat(self):
        """保活：按键事件订阅 10 s 没有心跳会被设备自动解除。"""
        if self.is_open:
            try:
                self.send_frame(P_EVT_STAT)
            except Exception:
                pass

    # ------------------------------------------------------------- reader
    def _reader(self):
        # 不要用 self._ser.read(512)：pyserial 会等满 512 字节或超时才返回，
        # 12 字节的 PING 回包会被硬拖到 latency 上限（实测 60 ms）。用 in_waiting 轮询。
        while not self._stop.is_set():
            try:
                n = self._ser.in_waiting
                if n:
                    chunk = self._ser.read(n)
                else:
                    time.sleep(0.0005)
                    continue
            except Exception as exc:                       # noqa: BLE001
                self.rx_error = f'read: {type(exc).__name__}: {exc}'
                break
            if not chunk:
                continue
            self.rx_bytes += len(chunk)
            try:
                self.rawq.put_nowait(chunk)
            except queue.Full:
                try:
                    self.rawq.get_nowait()
                    self.rawq.put_nowait(chunk)
                except Exception:
                    pass
            self._bin_acc += chunk
            try:
                self._parse_binary()
                self._parse_text()
            except Exception as exc:                       # noqa: BLE001
                self.rx_error = f'parse: {type(exc).__name__}: {exc}'
                self._bin_acc.clear()

    def _parse_binary(self):
        buf = self._bin_acc
        i = 0
        while True:
            idx = buf.find(MAGIC, i)
            if idx < 0 or len(buf) - idx < 6:
                break
            if len(buf) - idx < 5:
                break
            ln = buf[idx + 3] | (buf[idx + 4] << 8)
            total = 5 + ln + 1
            if len(buf) - idx < total:
                break
            body = bytes(buf[idx + 1:idx + 5 + ln])
            if crc8(body) != buf[idx + total - 1]:
                i = idx + 1
                continue
            cmd, seq, payload = body[0], body[1], body[4:]
            self._dispatch_frame(cmd, seq, payload)
            i = idx + total
        if i > 0:
            del buf[:i]

    def _dispatch_frame(self, cmd: int, seq: int, payload: bytes):
        if cmd == P_EVT_PUSH:
            if self.on_event is not None:
                self.on_event(seq, payload)
            return
        q = self._binary_wait.get((cmd, seq))
        if q is not None:
            try:
                q.put_nowait(payload)
            except queue.Full:
                pass
        if self.on_frame is not None:
            self.on_frame(cmd, seq, payload)

    def _parse_text(self):
        buf = self._bin_acc
        while True:
            start = buf.find(b'km.')
            if start < 0:
                break
            end = buf.find(b'\r\n>>> ', start)
            if end < 0:
                if start > 0:
                    del buf[:start]
                return
            line = bytes(buf[start:end]).decode('latin-1', 'replace')
            del buf[:end + 6]
            self.on_text_reply(line)

    def on_text_reply(self, line: str):
        # 台架命令也可能以 km. 开头（回显），统一进队列；面板自己按需过滤
        try:
            self._text_q.put_nowait(line)
        except queue.Full:
            pass
        if self.on_text is not None:
            self.on_text(line)

    # ------------------------------------------------------- mx.mt 轨迹转储
    def dump_motion(self, timeout: float = 8.0, expect: int | None = None):
        """发 `mx.mt d` 并收集 dump（会冻结环形缓冲）。返回 [(t_us, ep, len, hex)]。"""
        while not self.rawq.empty():
            try:
                self.rawq.get_nowait()
            except queue.Empty:
                break
        self.write_raw(b'mx.mt d\r')
        buf = b''
        t0 = time.time()
        entries = []
        total = expect
        while time.time() - t0 < timeout:
            try:
                chunk = self.rawq.get(timeout=0.1)
                buf += chunk
            except queue.Empty:
                pass
            text = buf.decode('latin-1', 'replace')
            if total is None:
                m = re.search(r'd (\d+)', text)
                if m:
                    total = int(m.group(1))
            entries = MT_RE.findall(text)
            if total is not None and len(entries) >= total:
                break
        return [(int(a), int(b, 16), int(c), d) for a, b, c, d in entries]

    def motion_state(self):
        """读 sumv 状态：active,samples,aborted,rounds,muted,fwd,speed_eff,remain"""
        r = self.request(P_SUMV_STATE, timeout=0.4)
        if r is None or len(r) < 29:
            return None
        u32 = lambda o: int.from_bytes(r[o:o + 4], 'little')
        return {
            'active': r[0], 'samples': u32(1), 'aborted': u32(5), 'rounds': u32(9),
            'muted': u32(13), 'fwd': u32(17), 'speed_eff': u32(21), 'remain_ms': u32(25),
        }

    def wait_motion_done(self, timeout: float = 8.0):
        t0 = time.time()
        while time.time() - t0 < timeout:
            st = self.motion_state()
            if st is not None and st['active'] == 0:
                return st
            time.sleep(0.05)
        return self.motion_state()
