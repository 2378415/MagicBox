#!/usr/bin/env python3
"""Locate every `excw` site in both images and dump its raw 3 bytes.

`excw` is what objdump decodes on the errata/workaround triple that makes
Ghidra abort a function.  Knowing the exact byte patterns lets us patch them
into a NOP triple and re-decompile those functions for real.
"""
import os
import re
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

REGIONS = {
    'left': [('irom', 0x42000020, 0x30020, 0x2F040),
             ('iram0', 0x40374000, 0x23B94, 0xC484),
             ('iram1', 0x40380484, 0x5F068, 0x3794)],
    'right': [('irom', 0x42000020, 0x20020, 0x26ACC),
              ('iram0', 0x40374000, 0x1CED4, 0x3144),
              ('iram1', 0x40377144, 0x46AF4, 0xCC00)],
}
BIN = {'left': os.path.join(ROOT, '官方固件', 'V3.2_LEFT.bin'),
       'right': os.path.join(ROOT, '官方固件', 'V3.7_RIGHT.bin')}
LINE_RE = re.compile(r'^\s*([0-9a-f]+):\s+(.*)$', re.M)


def main():
    total = {}
    for side in ('left', 'right'):
        data = open(BIN[side], 'rb').read()
        for name, vma, off, ln in REGIONS[side]:
            blob = data[off:off + ln]
            asm = os.path.join(ROOT, 'work', 'asm', f'{name}_{side}.txt')
            if not os.path.exists(asm):
                continue
            txt = open(asm, encoding='utf-8', errors='replace').read()
            sites = []
            for m in LINE_RE.finditer(txt):
                addr, ins = int(m.group(1), 16), m.group(2).strip()
                if ins.startswith('excw'):
                    sites.append(addr)
            pats = {}
            for a in sites:
                b = blob[a - vma:a - vma + 3]
                pats.setdefault(b.hex(' '), []).append(a)
            for p, addrs in sorted(pats.items()):
                print(f'{side:5s} {name:5s} {p}  x{len(addrs):3d}  '
                      + ' '.join(f'{a:08x}' for a in addrs[:8])
                      + (' ...' if len(addrs) > 8 else ''))
            total[(side, name)] = len(sites)
    print('\ntotals:', total, 'sum:', sum(total.values()))


if __name__ == '__main__':
    main()
