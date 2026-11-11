#!/usr/bin/env python3
"""Neutralise the `excw` errata placeholders so Ghidra can finish those functions.

`excw` (exception wait) is a hint instruction with no architectural effect: the
ESP32-S3 toolchain sprinkles it in as an errata workaround, and Ghidra's Xtensa
module treats it as the end of control flow, which is why 153 functions only have
an objdump fallback block.

Only sites that are *instruction starts of a real function* are patched: each
affected function is disassembled from its own entry (address-aligned) up to the
next function entry, so bytes that merely look like `excw` inside data or in an
over-running fallback window are never touched.  Each hit is replaced by
`and aN, aN, aN` (a true no-op on the same register).  The official images under
`官方固件/` are never modified; output goes to `work/*.nop.bin`.

Usage: python tools/patch_excw.py [left|right|both]
"""
import csv
import glob
import os
import re
import sys
import io
import subprocess
import collections

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'reversed', 'src')
OBJDUMP = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'
BIN = {'left': os.path.join(ROOT, '官方固件', 'V3.2_LEFT.bin'),
       'right': os.path.join(ROOT, '官方固件', 'V3.7_RIGHT.bin')}
OUT = {'left': os.path.join(ROOT, 'work', 'V3.2_LEFT.nop.bin'),
       'right': os.path.join(ROOT, 'work', 'V3.7_RIGHT.nop.bin')}
REGIONS = {
    'left': [('irom', 0x42000020, 0x30020, 0x2F040),
             ('iram0', 0x40374000, 0x23B94, 0xC484),
             ('iram1', 0x40380484, 0x5F068, 0x3794)],
    'right': [('irom', 0x42000020, 0x20020, 0x26ACC),
              ('iram0', 0x40374000, 0x1CED4, 0x3144),
              ('iram1', 0x40377144, 0x46AF4, 0xCC00)],
}
LINE_RE = re.compile(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{4,12}\s+)?(\S.*)$', re.M)


def gaps(side):
    """Function entries whose source file carries an objdump fallback block."""
    out = []
    for path in glob.glob(os.path.join(SRC, side, '*', '*.c')):
        txt = open(path, encoding='utf-8', errors='replace').read()
        if 'objdump fallback' in txt or 'halt_baddata' in txt:
            out.append(int(os.path.basename(path).split('_')[0], 16))
    return sorted(set(out))


def region_of(side, addr):
    for name, vma, off, ln in REGIONS[side]:
        if vma <= addr < vma + ln:
            return name, off + (addr - vma)
    return None, None


def carve_blobs(side, data):
    """Write one binary blob per region so objdump can be pointed at real VMAs."""
    paths = {}
    for name, vma, off, ln in REGIONS[side]:
        p = os.path.join(ROOT, 'work', f'{name}_{side}.bin')
        open(p, 'wb').write(data[off:off + ln])
        paths[name] = (p, vma, vma + ln)
    return paths


def disasm_excw(blobs, start, stop):
    blob, base = None, None
    for name, (p, lo, hi) in blobs.items():
        if lo <= start < hi:
            blob, base = p, lo
            break
    if blob is None:
        return []
    out = subprocess.run([OBJDUMP, '-D', '-b', 'binary', '-m', 'xtensa',
                          '--no-show-raw-insn', f'--adjust-vma={base:#x}',
                          f'--start-address={start:#x}', f'--stop-address={stop:#x}',
                          blob], capture_output=True, text=True,
                         encoding='utf-8', errors='replace').stdout
    hits = []
    for m in LINE_RE.finditer(out):
        if m.group(2).strip().startswith('excw'):
            hits.append(int(m.group(1), 16))
    return hits


def main():
    which = sys.argv[1] if len(sys.argv) > 1 else 'both'
    sides = ('left', 'right') if which == 'both' else (which,)
    for side in sides:
        data = bytearray(open(BIN[side], 'rb').read())
        blobs = carve_blobs(side, data)
        idx = {int(r['entry'], 16): int(r['size'])
               for r in csv.DictReader(open(os.path.join(
                   ROOT, 'reversed', 'raw_' + side, '_index.csv'), encoding='utf-8'))}
        entries = sorted(idx)
        todo = gaps(side)
        hits = set()
        for e in todo:
            nxt = next((x for x in entries if x > e), e + 0x400)
            hits.update(a for a in disasm_excw(blobs, e, nxt) if a < nxt)
        shapes = collections.Counter()
        patched = 0
        for a in sorted(hits):
            name, off = region_of(side, a)
            if name is None:
                continue
            b = data[off:off + 3]
            shapes[(b[0], b[2])] += 1
            n = b[1] >> 4
            data[off:off + 3] = bytes([n << 4, (n << 4) | n, 0x10])
            patched += 1
        open(OUT[side], 'wb').write(data)
        print(f'{side}: {len(todo)} gap functions, {len(hits)} aligned excw sites, '
              f'patched {patched} -> {OUT[side]}')
        for (b0, b2), c in shapes.most_common(6):
            print(f'   observed bytes b0=0x{b0:02x} b2=0x{b2:02x}  x{c}')


if __name__ == '__main__':
    main()
