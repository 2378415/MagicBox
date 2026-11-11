#!/usr/bin/env python3
"""Brute-force assembler sweep: which Xtensa instruction encodes to `70 aa 62`?

The three bytes that objdump prints as `excw` inside the guard sequences are not
what the assembler emits for `excw` (that is `80 20 00`), so the byte pattern is
searched over a generated candidate space instead of a hand-written list.
"""
import itertools
import os
import subprocess
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AS = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp32s3-elf-as.exe'
OD = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'
S = os.path.join(ROOT, 'work', 't5.s')
O = os.path.join(ROOT, 'work', 't5.o')
TARGETS = {'62aa70', '628870', '62a070', '628070'}   # objdump prints bytes reversed


def asm(src):
    open(S, 'w', encoding='ascii').write('.text\n  ' + src + '\n  nop\n')
    r = subprocess.run([AS, '-o', O, S], capture_output=True, text=True)
    if r.returncode:
        return None, r.stderr.strip().splitlines()[-1] if r.stderr.strip() else 'err'
    out = subprocess.run([OD, '-d', O], capture_output=True, text=True).stdout
    for line in out.splitlines():
        if line.strip().startswith('0:'):
            parts = line.split('\t')
            if len(parts) >= 3:
                return parts[1].replace(' ', ''), parts[2].strip()
    return None, 'no-line'


def candidates():
    regs = ['a7', 'a8', 'a9', 'a10']
    two = ['neg', 'abs', 'nsa', 'nsau', 'ssa8b', 'ssa8l', 'ssr', 'ssl',
           'srl', 'sll', 'sra', 'mul16u', 'mul16s', 'mull', 'quos', 'quou',
           'remu', 'rems', 'rer', 'wer', 'ill']
    three = ['add', 'sub', 'and', 'or', 'xor', 'addx2', 'addx4', 'addx8',
             'max', 'min', 'moveqz', 'movnez', 'movgez', 'movltz', 'src',
             'sll', 'srl', 'sra', 'mul16u', 'mul16s', 'mull', 'quos', 'quou',
             'remu', 'rems', 'abs', 'neg']
    for m in two:
        for r in regs:
            yield f'{m} {r}, {r}'
    for m in three:
        for t, s, r in itertools.product(regs, regs, regs):
            yield f'{m} {r}, {s}, {t}'
    for m in ('l32i', 'l16si', 'l16ui', 'l8ui', 's32i', 's16i', 's8i'):
        for t, s in itertools.product(regs, regs):
            for off in (0, 1, 2, 3, 4, 8, 0x54, 0x9c, 0x210, 0x214, 0x369, 0x636):
                yield f'{m} {t}, {s}, {off}'
    for m in ('movi', 'addi', 'beqz', 'bnez', 'bgez', 'bltz', 'beqi', 'bnei'):
        for r in regs:
            for imm in (0, 1, 2, 4, 8):
                yield f'{m} {r}, {imm}, 1f' if m.startswith('b') else f'{m} {r}, {imm}'
    yield 'nop\n1:'


def main():
    seen = {}
    for src in candidates():
        b, dis = asm(src.split('\n')[0] if not src.startswith('nop') else 'nop')
        if not b:
            continue
        seen.setdefault(b, (src, dis))
    hits = {b: v for b, v in seen.items() if b in TARGETS}
    print(f'tried {len(seen)} encodings')
    for b, (src, dis) in sorted(hits.items()):
        print(f'  MATCH {b}: {src!r}   ->  {dis}')
    if not hits:
        # show the neighbourhood: which encodings start with the same byte
        near = [(b, v) for b, v in seen.items() if b.startswith('62') and b[2:4] in ('aa', '88')]
        for b, (src, dis) in near[:20]:
            print(f'  near  {b}: {src!r} -> {dis}')


if __name__ == '__main__':
    main()
