#!/usr/bin/env python3
"""Talk to the control port once and report what the firmware answers.

Used by tools/flash_left.ps1 for the "verify" step, and useful on its own:

    python tools/flash_verify.py --port COM8

Checks, in order:
  1. the port opens and the DTR/RTS pulse brings the app out of reset;
  2. `.km.version()` answers `km.MAKCU\\r\\n>>> ` (our cmd_version);
  3. `.km.move(10,5)` echoes (our cmd_move, motion hook still stubbed);
  4. `.km.silent()` stays silent (handler not ported yet -> NULL slot).

Exit code 0 when every check matches the expected partial-rebuild behaviour.
"""
import argparse
import sys
import time

try:
    import serial
except ImportError:
    raise SystemExit('pyserial is required: python -m pip install pyserial')

SUFFIX = b'\r\n>>> '


class Link:
    def __init__(self, port, baud=115200):
        self.ser = serial.Serial(port, baud, timeout=0.1)

    def reset(self):
        self.ser.dtr = False
        self.ser.rts = True
        time.sleep(0.05)
        self.ser.dtr = True
        self.ser.rts = False
        time.sleep(0.8)

    def drain(self, quiet=0.35, limit=2.0):
        buf = bytearray()
        start = last = time.time()
        while time.time() - start < limit:
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
        self.ser.write(text.encode('latin-1') + b'\r')
        self.ser.flush()
        return self.drain()

    def close(self):
        self.ser.close()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', default='COM8')
    a = ap.parse_args()

    try:
        link = Link(a.port)
    except Exception as exc:
        print(f'FAIL open {a.port}: {exc}')
        return 2
    try:
        link.reset()
        link.drain(limit=0.4)
        checks = []

        reply = link.cmd('.km.version()')
        checks.append(('version', reply == b'km.MAKCU' + SUFFIX, reply))

        reply = link.cmd('.km.version')          # prefix match, no brackets
        checks.append(('version-prefix', reply == b'km.MAKCU' + SUFFIX, reply))

        reply = link.cmd('.km.move(10,5)')
        checks.append(('move-echo', reply == b'km.move(10,5)' + SUFFIX, reply))

        reply = link.cmd('.km.silent()')         # NULL slot in this build
        checks.append(('silent-null', reply == b'', reply))

        ok = True
        for name, passed, reply in checks:
            print(f'{"PASS" if passed else "FAIL"} {name:16s} reply={reply!r}')
            ok = ok and passed
        return 0 if ok else 1
    finally:
        link.close()


if __name__ == '__main__':
    sys.exit(main())
