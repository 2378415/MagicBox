#!/usr/bin/env python3
"""Locate the nearest Xtensa `entry a1, N` prologue before an address and dump
the function body with rizin, filtering out misaligned garbage."""
import subprocess, sys, re, io, os
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

BIN_ELF = r'work\V3.2_LEFT_app.elf'
SEG = [(0x3c030020,0x10b60,0x010020),(0x3fc93d00,0x3004,0x020b88),
       (0x40374000,0xc484,0x023b94),(0x42000020,0x2f040,0x030020),
       (0x40380484,0x3794,0x05f068)]
BIN = r'官方固件\V3.2_LEFT.bin'

def v2o(v):
    for la, ln, fo in SEG:
        if la <= v < la + ln: return fo + (v - la)
    return None

def find_entry(d, addr, back=0x600):
    o = v2o(addr)
    for delta in range(0, back):
        p = o - delta
        if p < 0: break
        b = d[p:p+3]
        if len(b) == 3 and b[0] == 0x36 and (b[1] & 0x0F) == 1 and b[2] == 0x00:
            return addr - delta
    return None

def disasm(start, size):
    rizin = r'tools\rizin\rizin-win-installer-vs2019_static-64\bin\rizin.exe'
    cmd = [rizin, '-a','xtensa','-b','32','-q','-e','scr.color=0',
           '-c', f's {start:#x}; pD {size:#x}', BIN_ELF]
    out = subprocess.run(cmd, capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
    lines = []
    for ln in out.splitlines():
        m = re.match(r'\s*[│╎┌└─>]*\s*(0x[0-9a-f]+)\s+(.*)$', ln)
        if m:
            lines.append((int(m.group(1),16), m.group(2).rstrip()))
    return lines

if __name__ == '__main__':
    addr = int(sys.argv[1], 0)
    d = open(BIN,'rb').read()
    e = find_entry(d, addr)
    print('nearest entry before', hex(addr), '=', hex(e) if e else None)
    if e:
        for a, t in disasm(e, 0x400):
            if 'illegal' in t: continue
            print(f'  {a:#010x}  {t}')
