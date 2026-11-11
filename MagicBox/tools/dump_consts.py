#!/usr/bin/env python3
"""Dump the literal-pool constants a function references, as doubles/ints.

The Xtensa compiler keeps 64-bit constants in an in-body literal pool; Ghidra
exposes them as `DAT_4200xxxx`.  This tool reads those addresses straight from
the official image so the values can be compared with known library constants
(fdlibm/newlib coefficients, limits, ...).

Usage:
  python tools/dump_consts.py <side> <entry> [<entry> ...]
"""
import glob
import os
import re
import struct
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REGIONS = {
    'left': [('irom', 0x42000020, 0x30020, 0x2F040),
             ('drom', 0x3C030020, 0x20020, 0x10B60),
             ('iram0', 0x40374000, 0x23B94, 0xC484),
             ('iram1', 0x40380484, 0x5F068, 0x3794)],
    'right': [('irom', 0x42000020, 0x20020, 0x26ACC),
              ('drom', 0x3C030020, 0x20020, 0xA26C),
              ('iram0', 0x40374000, 0x1CED4, 0x3144),
              ('iram1', 0x40377144, 0x46AF4, 0xCC00)],
}
BIN = {'left': os.path.join(ROOT, '官方固件', 'V3.2_LEFT.bin'),
       'right': os.path.join(ROOT, '官方固件', 'V3.7_RIGHT.bin')}
DAT_RE = re.compile(r'\bDAT_([0-9a-f]{8})\b')


def load(side):
    data = open(BIN[side], 'rb').read()
    return data


def read(side, data, addr, n=8):
    for _name, vma, off, ln in REGIONS[side]:
        if vma <= addr < vma + ln:
            o = off + (addr - vma)
            return data[o:o + n]
    return None


def main():
    side, entries = sys.argv[1], sys.argv[2:]
    data = load(side)
    for entry in entries:
        files = glob.glob(os.path.join(ROOT, 'reversed', 'src', side, '*',
                                       f'{entry}_*.c'))
        if not files:
            print(f'no file for {entry}')
            continue
        text = open(files[0], encoding='utf-8').read()
        addrs = sorted({int(a, 16) for a in DAT_RE.findall(text)})
        print(f'== {side} {entry}  ({len(addrs)} literals)  {os.path.basename(files[0])}')
        for a in addrs:
            b = read(side, data, a)
            if not b or len(b) < 8:
                print(f'  {a:08x}: <not in image>')
                continue
            d = struct.unpack('<d', b)[0]
            lo, hi = struct.unpack('<II', b)
            print(f'  {a:08x}: {b.hex(" ")}  double={d!r:26} hi=0x{hi:08x} lo=0x{lo:08x}')


if __name__ == '__main__':
    main()
