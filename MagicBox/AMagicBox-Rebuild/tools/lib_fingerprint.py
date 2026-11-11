#!/usr/bin/env python3
"""Fingerprint firmware functions and match them against an IDF build (T3 / P0).

Two jobs:

1. `index`   - walk the already dumped linear disassembly of the official images
               (old repo `work/asm/*.txt`) plus the function index
               (`reversed/raw_<side>/_index.csv`) and write one fingerprint per
               function: normalised mnemonic hash + size + in-degree.
               Run once; the result is the reference side of the comparison.

2. `compare` - take the `nm`/`.map` of a freshly built ESP-IDF (same version,
               same toolchain, same sdkconfig) and report, for every IDF symbol,
               whether the firmware contains a function with the same
               normalised instruction hash.  A high hit rate is the P0 gate:
               it proves the build environment is reproduced, so vendor code can
               then be scored function by function with tools/diff_insn.py.

Usage:
  python tools/lib_fingerprint.py index --old-repo D:/JinPeng/MagicBox --out fingerprints
  python tools/lib_fingerprint.py compare --firmware fingerprints/left.json \
      --nm build/esp-idf/esp-idf.map --min-hit 0.95
"""
import argparse
import collections
import csv
import hashlib
import json
import os
import re
import subprocess
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

def _find_objdump():
    """Locate xtensa-esp-elf-objdump.exe (nm lives next to it).

    Legacy bench path first for the old machine, then the idf_tools layout used
    after the 2026-11 rebuild; MAKCU_TOOLCHAIN_BIN overrides both.
    """
    env = os.environ.get('MAKCU_TOOLCHAIN_BIN')
    cands = []
    if env:
        cands.append(os.path.join(env, 'xtensa-esp-elf-objdump.exe'))
    legacy = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'
    cands.append(legacy)
    root = r'D:\esp-tools\tools\xtensa-esp-elf'
    if os.path.isdir(root):
        for d in sorted(os.listdir(root), reverse=True):
            cands.append(os.path.join(root, d, 'xtensa-esp-elf', 'bin',
                                      'xtensa-esp-elf-objdump.exe'))
    for c in cands:
        if os.path.isfile(c):
            return c
    return legacy


OBJDUMP = _find_objdump()
LINE_RE = re.compile(r'^\s*([0-9a-f]{8}):\s+(?:[0-9a-f]{2,12}\s+)?([a-z][\w.]*)\s*(.*)$')
IMM_RE = re.compile(r'0x[0-9a-f]+|-?\b\d+\b')
REG_RE = re.compile(r'\b(?:a[0-9]{1,2}|sp|pc|sar|lcount|lbeg|lend)\b')
LBL_RE = re.compile(r'\b(?:L_|\.L)?[0-9a-f]{5,}\b')
BASE_RE = re.compile(r'^[0-9a-f]{8}:')


def normalise_ops(lines):
    ops = []
    for line in lines:
        m = LINE_RE.match(line)
        if not m:
            continue
        mn, args = m.group(2), m.group(3)
        if mn in ('ill', '.byte', 'excw'):
            continue
        args = args.split(';')[0]
        args = LBL_RE.sub('L', args)
        args = IMM_RE.sub('#imm', args)
        args = REG_RE.sub('r', args)
        args = re.sub(r'\s+', ' ', args).strip()
        ops.append(f'{mn} {args}'.strip())
    return ops


def fingerprint(ops):
    h = hashlib.sha1()
    for op in ops:
        h.update(op.encode('utf-8'))
        h.update(b'\n')
    return h.hexdigest()[:16]


def load_index(path):
    rows = {}
    with open(path, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            rows[int(r['entry'], 16)] = r
    return rows


def load_asm(paths):
    """address -> instruction text, from the linear dumps."""
    table = {}
    for p in paths:
        if not os.path.exists(p):
            continue
        for line in open(p, encoding='utf-8', errors='replace'):
            m = BASE_RE.match(line.strip())
            if not m:
                continue
            table[int(line.strip().split(':')[0], 16)] = line.rstrip('\n')
    return table


def cmd_index(a):
    out = {}
    for side in ('left', 'right'):
        idx = load_index(os.path.join(a.old_repo, 'reversed', 'raw_' + side, '_index.csv'))
        asm_dir = os.path.join(a.old_repo, 'work', 'asm')
        lines = load_asm([os.path.join(asm_dir, f'{n}_{side}.txt')
                          for n in ('irom', 'iram0', 'iram1')])
        entries = sorted(idx)
        funcs = {}
        for i, entry in enumerate(entries):
            nxt = entries[i + 1] if i + 1 < len(entries) else entry + 0x400
            body = [lines[x] for x in range(entry, min(nxt, entry + 0x2000)) if x in lines]
            ops = normalise_ops(body)
            if not ops:
                continue
            funcs[f'{entry:08x}'] = {
                'name': idx[entry]['name'],
                'insns': len(ops),
                'callers': idx[entry].get('callers', ''),
                'fp': fingerprint(ops),
            }
        out[side] = funcs
        print(f'{side}: {len(funcs)} fingerprints')
    os.makedirs(a.out, exist_ok=True)
    for side, funcs in out.items():
        path = os.path.join(a.out, side + '.json')
        json.dump(funcs, open(path, 'w', encoding='utf-8'), indent=0)
        print('wrote', path)


def parse_map(path):
    """symbol -> (address, size) from a GNU ld map or nm -S listing."""
    syms = {}
    if not os.path.exists(path):
        return syms
    text = open(path, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'^\s*([0-9a-f]{8})\s+([0-9a-f]{8})\s+\S+\s+(\w+)$', text, re.M):
        syms[m.group(3)] = (int(m.group(1), 16), int(m.group(2), 16))
    for m in re.finditer(r'^\s*0x([0-9a-f]+)\s+(\w+)$', text, re.M):
        syms.setdefault(m.group(2), (int(m.group(1), 16), 0))
    return syms


def cmd_compare(a):
    funcs = json.load(open(a.firmware, encoding='utf-8'))
    by_fp = collections.defaultdict(list)
    for addr, f in funcs.items():
        by_fp[f['fp']].append(addr)
    syms = parse_map(a.map)
    if not syms:
        raise SystemExit(f'no symbols parsed from {a.map}')
    hit = miss = 0
    misses = []
    for name, (addr, size) in syms.items():
        # only compare plausible code symbols
        if not (0x40370000 <= addr < 0x40400000 or 0x42000000 <= addr < 0x44000000):
            continue
        matches = by_fp.get(name) or []
        if matches:
            hit += 1
        else:
            miss += 1
            misses.append((name, addr, size))
    total = hit + miss
    rate = hit / total if total else 0.0
    print(f'IDF symbols in code ranges: {total}')
    print(f'exact-hash hits: {hit}  ({rate:.1%})   misses: {miss}')
    if misses:
        print('first misses (rebuilt side must be re-checked or the build differs):')
        for name, addr, size in misses[:20]:
            print(f'  {name:40s} 0x{addr:08x} size={size}')
    print('P0 gate:', 'PASS' if rate >= a.min_hit else 'FAIL')
    return 0 if rate >= a.min_hit else 1


def read_symbols_nm(elf):
    """name -> (address, size) straight from the rebuilt ELF."""
    nm = os.path.join(os.path.dirname(OBJDUMP), 'xtensa-esp-elf-nm.exe')
    out = subprocess.run([nm, '--print-size', '--defined-only', elf],
                         capture_output=True, text=True, errors='replace').stdout
    syms = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) != 4:
            continue
        addr, size, _typ, name = parts
        try:
            syms[name] = (int(addr, 16), int(size, 16))
        except ValueError:
            continue
    return syms


def hash_elf_symbols(elf):
    """name -> normalised instruction hash, by disassembling the built ELF once."""
    text = subprocess.run([OBJDUMP, '-d', '-j', '.flash.text', elf],
                          capture_output=True, text=True, errors='replace').stdout
    if 'Disassembly of section' not in text:
        text = subprocess.run([OBJDUMP, '-d', elf], capture_output=True, text=True,
                              errors='replace').stdout
    per_sym = collections.defaultdict(list)
    current = None
    for line in text.splitlines():
        head = re.match(r'^[0-9a-f]{8} <([^>]+)>:$', line.strip())
        if head:
            current = head.group(1)
            continue
        if current:
            per_sym[current].append(line)
    return {name: fingerprint(normalise_ops(lines)) for name, lines in per_sym.items()}


def cmd_compare_elf(a):
    funcs = json.load(open(a.firmware, encoding='utf-8'))
    by_fp = collections.defaultdict(list)
    for addr, f in funcs.items():
        by_fp[f['fp']].append(addr)
    hashes = hash_elf_symbols(a.elf)
    syms = read_symbols_nm(a.elf)
    hit, miss, misses = 0, 0, []
    for name, (addr, size) in syms.items():
        if name not in hashes or size < 8:
            continue
        if hashes[name] in by_fp:
            hit += 1
        else:
            miss += 1
            misses.append(name)
    total = hit + miss
    rate = hit / total if total else 0.0
    print(f'rebuilt code symbols compared: {total}')
    print(f'identical (normalised) to a function in the official image: {hit}  ({rate:.1%})')
    print(f'different: {miss}')
    if misses:
        print('diverged symbols (expected for -O level / config drift, or ROM funcs):')
        for n in misses[:25]:
            print('  ', n)
    print('P0 gate:', 'PASS' if rate >= a.min_hit else 'FAIL')
    return 0 if rate >= a.min_hit else 1


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    i = sub.add_parser('index')
    i.add_argument('--old-repo', default=r'D:\JinPeng\MagicBox')
    i.add_argument('--out', default='verification/fingerprints')
    ce = sub.add_parser('compare-elf')
    ce.add_argument('--firmware', required=True)
    ce.add_argument('--elf', required=True)
    ce.add_argument('--min-hit', type=float, default=0.95)
    c = sub.add_parser('compare')
    c.add_argument('--firmware', required=True)
    c.add_argument('--map', required=True)
    c.add_argument('--min-hit', type=float, default=0.95)
    a = ap.parse_args()
    if a.cmd == 'index':
        cmd_index(a)
    elif a.cmd == 'compare-elf':
        sys.exit(cmd_compare_elf(a))
    else:
        sys.exit(cmd_compare(a))


if __name__ == '__main__':
    main()
