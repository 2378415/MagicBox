#!/usr/bin/env python3
"""Brute-force which Xtensa mnemonic assembles to the 3 bytes `70 aa 62`."""
import os
import subprocess
import sys
import io
import tempfile

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
AS = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp32s3-elf-as.exe'
OD = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'
TMP = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'work')

CANDS = [
    'excw', 'esync', 'rsync', 'isync', 'memw', 'extw', 'nop', 'ill', 'retw',
    'neg a10, a10', 'abs a10, a10', 'nsa a10, a10', 'nsau a10, a10',
    'ssa8b a10', 'ssa8l a10', 'ssai 2', 'ssr a10', 'ssl a10',
    'mov a10, a10', 'or a10, a10, a10', 'and a10, a10, a10',
    'add a10, a10, a10', 'sub a10, a10, a10', 'addx4 a10, a10, a10',
    'clamps a10, a10, 2', 'max a10, a10, a10', 'min a10, a10, a10',
    'moveqz a10, a10, a10', 'movnez a10, a10, a10', 'movgez a10, a10, a10',
    'extui a10, a10, 2, 2', 'sext a10, a10, 2', 'zext a10, a10, 2',
    'srl a10, a10', 'sll a10, a10', 'sra a10, a10', 'src a10, a10, a10',
    'mul16u a10, a10, a10', 'mul16s a10, a10, a10', 'mull a10, a10, a10',
    'quos a10, a10, a10', 'quou a10, a10, a10', 'remu a10, a10, a10',
    'rer a10, a10', 'wer a10, a10', 'rur a10, a10', 'wur a10, a10',
    'rsr a10, lcount', 'rsr a10, lbeg', 'wsr a10, lbeg', 'wsr a10, lcount',
    'rfi 2', 'break 2', 'syscall', 'waiti 2', 'rfe', 'rfwo', 'rfwu',
    'l32ai a10, a10, 0', 's32ri a10, a10, 0', 'l32r a10, start',
    'entry a1, 32', 'loop a10, start', 'loopnez a10, start', 'loopgtz a10, start',
    'bnez a10, start', 'beqz a10, start', 'ball a10, a10, start',
    'bnone a10, a10, start', 'blt a10, a10, start', 'bge a10, a10, start',
    'bbs a10, a10, start', 'bbc a10, a10, start',
    'movi a10, 2', 'movi.n a10, 2', 'mov.n a10, a10', 'addi a10, a10, -2',
    'l32i.n a10, a10, 2', 's32i.n a10, a10, 2', 'l8ui a10, a10, 2',
    'beq a10, a10, start', 'bne a10, a10, start', 'beqi a10, 2, start',
    'j start', 'jx a10', 'callx8 a10', 'call0 start', 'call8 start',
]


def asm(src):
    s = os.path.join(TMP, 't2.s')
    o = os.path.join(TMP, 't2.o')
    open(s, 'w', encoding='ascii').write('.text\nstart:\n  ' + src + '\n  nop\n')
    r = subprocess.run([AS, '-o', o, s], capture_output=True, text=True)
    if r.returncode != 0:
        return None
    out = subprocess.run([OD, '-d', o], capture_output=True, text=True).stdout
    for line in out.splitlines():
        line = line.strip()
        if line.startswith('0:') or line.startswith('1:') or line.startswith('2:'):
            parts = line.split('\t')
            if len(parts) >= 2:
                return parts[1].replace(' ', '')
    return None


def main():
    want = '70aa62'
    for c in CANDS:
        b = asm(c)
        mark = ' <== MATCH' if b == want else ''
        if b and b[:6] in ('70aa62', '62aa70'):
            mark = ' <== MATCH'
        print(f'{c:34s} {b}{mark}')


if __name__ == '__main__':
    main()
