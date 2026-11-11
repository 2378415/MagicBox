# -*- coding: utf-8 -*-
"""Send text commands to the MAKCU control port (CH343) and print replies.

Usage: python tools/flash/send_cmd.py [--port COM8] [--no-reset] cmd1 cmd2 ...
Each cmd is sent with a trailing CR; the reply is printed as hex + repr.
"""
import argparse
import sys
import time

import serial


def reset(ser):
    ser.dtr = False
    ser.rts = True
    time.sleep(0.05)
    ser.dtr = True
    ser.rts = False
    time.sleep(0.6)


def drain(ser, quiet=0.35, limit=2.0):
    buf = bytearray()
    t0 = time.time()
    last = time.time()
    while time.time() - t0 < limit:
        n = ser.in_waiting
        if n:
            buf += ser.read(n)
            last = time.time()
        else:
            if buf and time.time() - last > quiet:
                break
            time.sleep(0.01)
    return bytes(buf)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', default='COM8')
    ap.add_argument('--reset', dest='do_reset', action='store_true', default=True)
    ap.add_argument('--no-reset', dest='do_reset', action='store_false')
    ap.add_argument('cmds', nargs='+')
    a = ap.parse_args()

    with serial.Serial(a.port, 115200, timeout=0.1) as ser:
        if a.do_reset:
            reset(ser)
        drain(ser, limit=0.4)
        for cmd in a.cmds:
            ser.write(cmd.encode('latin-1') + b'\r')
            ser.flush()
            rep = drain(ser)
            print(f'>>> {cmd!r}')
            print(f'    len={len(rep)}  hex={rep.hex(" ")}')
            print(f'    repr={rep!r}')


if __name__ == '__main__':
    sys.exit(main())
