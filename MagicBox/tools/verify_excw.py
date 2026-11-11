#!/usr/bin/env python3
"""Verify that every byte triple patched by patch_excw.py really decodes as excw.

Feeds the exact three bytes back through the assembler/disassembler as raw data:
if objdump still calls the triple `excw`, the patch replaced a hint instruction
with a no-op and nothing else.  Triples that decode as something else are printed
so they can be excluded.
"""
import collections
import glob
import os
import re
import subprocess
import sys
import io
import csv

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AS = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp32s3-elf-as.exe'
OD = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'
BIN = {'left': os.path.join(ROOT, '官方固件', 'V3.2_LEFT.bin'),
       'right': os.path.join(ROOT, '官方固件', 'V3.7_RIGHT.bin')}
REGIONS = {
    'left': [('irom', 0x42000020, 0x30020, 0x2F040),
             ('iram0', 0x40374000, 0x23B94, 0xC484),
             ('iram1', 0x40380484, 0x5F068, 0x3794)],
    'right': [('irom', 0x42000020, 0x20020, 0x26ACC),
              ('iram0', 0x40374000, 0x1CED4, 0x3144),
              ('iram1', 0x40377144, 0x46AF4, 0xCC00)],
}
LINE_RE = re.compile(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{4,12}\s+)?(\S.*)$', re.M)


def classify(triple):
    s = os.path.join(ROOT, 'work', 't4.s')
    o = os.path.join(ROOT, 'work', 't4.o')
    open(s, 'w', encoding='ascii').write(
        '.text\n.byte 0x%02x,0x%02x,0x%02x\n' % triple)
    r = subprocess.run([AS, '-o', o, s], capture_output=True, text=True)
    if r.returncode:
        return 'asm-error'
    out = subprocess.run([OD, '-d', o], capture_output=True, text=True).stdout
    for line in out.splitlines():
        if line.strip().startswith('0:'):
            parts = line.split('\t')
            if len(parts) >= 3:
                return parts[2].strip().split()[0]
    return '?'


def main():
    for side in ('left', 'right'):
        data = open(BIN[side], 'rb').read()
        shapes = collections.Counter()
        for path in glob.glob(os.path.join(ROOT, 'reversed', 'src', side, '*', '*.c')):
            txt = open(path, encoding='utf-8', errors='replace').read()
            for m in LINE_RE.finditer(txt):
                line_end = m.group(2).strip()
                if not line_end.startswith('excw'):
                    continue
                a = int(m.group(1), 16)
                for name, vma, off, ln in REGIONS[side]:
                    if vma <= a < vma + ln:
                        b = data[off + (a - vma):off + (a - vma) + 3]
                        shapes[tuple(b)] += 1
                        break
        bad = collections.Counter()
        for tri, c in shapes.most_common():
            mn = classify(tri)
            if mn != 'excw':
                bad[(tri, mn)] += c
        print(f'{side}: {len(shapes)} distinct triples, {sum(shapes.values())} occurrences')
        for (tri, mn), c in bad.most_common(15):
            print(f'   NOT excw: {tri[0]:02x} {tri[1]:02x} {tri[2]:02x} -> {mn}  x{c}')
        print(f'   non-excw total: {sum(bad.values())}')


if __name__ == '__main__':
    main()
