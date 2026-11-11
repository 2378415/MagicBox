#!/usr/bin/env python3
"""Replace zero padding inside gap functions with real no-ops.

GCC pads code for loop/branch alignment with 2- or 3-byte zero runs
(`00 00`, `00 00 00`).  Both binutils and Ghidra consume those bytes as if
they were instructions, which lands the decoder one byte off and ends in an
"Unable to resolve constructor" abort several bytes later.

This tool patches *only* the zero runs that sit immediately before an address
Ghidra reported as undecodable (or that the caller names explicitly), replacing
them with a same-length no-op (`and aN, aN, aN` for 3 bytes, `nop.n` for 2).
Padding is never executed, so the replacement cannot change behaviour.

Usage:
  python tools/patch_padding.py left "42020d8a:3" "42023dca:3" ...
  python tools/patch_padding.py right "4201b35a:3"
Input image: work/<image>.nop.bin   Output: work/<image>.nop2.bin
"""
import os
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IN = {'left': os.path.join(ROOT, 'work', 'V3.2_LEFT.nop.bin'),
      'right': os.path.join(ROOT, 'work', 'V3.7_RIGHT.nop.bin')}
OUT = {'left': os.path.join(ROOT, 'work', 'V3.2_LEFT.nop2.bin'),
       'right': os.path.join(ROOT, 'work', 'V3.7_RIGHT.nop2.bin')}
REGIONS = {
    'left': [('irom', 0x42000020, 0x30020, 0x2F040),
             ('iram0', 0x40374000, 0x23B94, 0xC484),
             ('iram1', 0x40380484, 0x5F068, 0x3794)],
    'right': [('irom', 0x42000020, 0x20020, 0x26ACC),
              ('iram0', 0x40374000, 0x1CED4, 0x3144),
              ('iram1', 0x40377144, 0x46AF4, 0xCC00)],
}
NOP2 = bytes([0x3d, 0xf0])                       # nop.n


def nop_n(n, reg=5):
    """A no-op of exactly n bytes (2/3/4/6)."""
    if n == 2:
        return NOP2
    if n == 3:
        return bytes([reg << 4, (reg << 4) | reg, 0x10])   # and aN,aN,aN
    return (NOP2 * (n // 2)) + (nop_n(1) if n % 2 else b'')


def nop_n1():
    return bytes([0x3d, 0xf0])


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return
    side = sys.argv[1]
    data = bytearray(open(IN[side], 'rb').read())
    for spec in sys.argv[2:]:
        addr_s, _, len_s = spec.partition(':')
        addr, n = int(addr_s, 16), int(len_s or 3)
        done = False
        for name, vma, off, ln in REGIONS[side]:
            if vma <= addr < vma + ln:
                o = off + (addr - vma)
                old = bytes(data[o:o + n])
                data[o:o + n] = nop_n(n)
                print(f'  {side} {addr:08x} ({name}) {old.hex(" ")} -> {nop_n(n).hex(" ")}')
                done = True
                break
        if not done:
            print(f'  {side} {addr:08x}: outside regions, skipped')
    open(OUT[side], 'wb').write(data)
    print('wrote', OUT[side])


if __name__ == '__main__':
    main()
