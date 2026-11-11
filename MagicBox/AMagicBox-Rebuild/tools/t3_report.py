#!/usr/bin/env python3
"""T3 report: normalised instruction similarity for every ported handler.

Compares the rebuilt function (symbol in the built ELF) against the original
function at its recovered address, using the same normalisation as
`tools/diff_insn.py`.

Why: the hidden opcodes (0x0D..0x14, 0x15..0x18) cannot be exercised through the
text port, so behavioural regression cannot cover them.  This is the honest
alternative evidence, and it is what the T3 gate in docs/00-plan.md asks for.

Usage:
  python tools/t3_report.py --side left
  python tools/t3_report.py --side left --only cmd_key_down cmd_key_up
"""
import argparse
import csv
import os
import subprocess
import sys
import io

HERE = os.path.dirname(os.path.abspath(__file__))
PROJ = os.path.dirname(HERE)
sys.path.insert(0, HERE)

import diff_insn as di                                   # noqa: E402

OLD_REPO = os.path.dirname(PROJ)
OBJDUMP = di.OBJDUMP


def elf_symbols(elf):
    nm = os.path.join(os.path.dirname(OBJDUMP), 'xtensa-esp-elf-nm.exe')
    out = subprocess.run([nm, '--print-size', '--defined-only', elf],
                         capture_output=True, text=True, errors='replace').stdout
    syms = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 4 and parts[2] in ('T', 't'):
            try:
                syms[parts[3]] = (int(parts[0], 16), int(parts[1], 16))
            except ValueError:
                continue
    return syms


def disasm_elf_symbol(elf, name):
    return subprocess.run([OBJDUMP, '-d', f'--disassemble={name}', elf],
                          capture_output=True, text=True, errors='replace').stdout


def original_sizes(side):
    """curated name -> (entry, size).

    The raw index keeps Ghidra's FUN_ names, the curated names live in
    rename_map.csv; join them by entry address.
    """
    idx = {}
    path = os.path.join(OLD_REPO, 'reversed', 'raw_' + side, '_index.csv')
    with open(path, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            idx[int(r['entry'], 16)] = int(r['size'])
    out = {}
    rmap = os.path.join(OLD_REPO, 'reversed', 'docs', 'rename_map.csv')
    with open(rmap, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            if r['image'] != side:
                continue
            entry = int(r['entry'], 16)
            out[r['new']] = (entry, idx.get(entry, 0x200))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--side', default='left')
    ap.add_argument('--elf', default=os.path.join(PROJ, 'app_left', 'build', 'makcu_left.elf'))
    ap.add_argument('--image', default=os.path.join(OLD_REPO, '官方固件', 'V3.2_LEFT.bin'))
    ap.add_argument('--only', nargs='*')
    ap.add_argument('--threshold', type=float, default=0.70)
    a = ap.parse_args()

    syms = elf_symbols(a.elf)
    sizes = original_sizes(a.side)
    rows = []
    for name, (addr, size) in sorted(sizes.items()):
        if name.startswith('FUN_') or name not in syms:
            continue
        if a.only and name not in a.only:
            continue
        ours = syms[name][1]
        # original function body: from its entry to the next entry in the index
        stop = addr + max(size, 4)
        text_orig = di.disasm_region(a.image, addr, min(stop, addr + 0x800))
        ops_orig = di.normalise(text_orig)
        ops_ours = di.normalise(disasm_elf_symbol(a.elf, name))
        score = di.score(ops_orig, ops_ours) if (ops_orig and ops_ours) else 0.0
        rows.append((name, addr, size, ours, len(ops_orig), len(ops_ours), score))

    rows.sort(key=lambda r: r[6])
    print(f'{"handler":22s} {"orig":>10s} {"size":>5s} {"new":>5s} '
          f'{"insn":>9s} {"sim":>6s}')
    for name, addr, size, ours, no, nn, score in rows:
        flag = '' if score >= a.threshold else '  <-- below gate'
        print(f'{name:22s} 0x{addr:08x} {size:5d} {ours:5d} {no:4d}/{nn:<4d} '
              f'{score:6.3f}{flag}')
    if rows:
        avg = sum(r[6] for r in rows) / len(rows)
        below = sum(1 for r in rows if r[6] < a.threshold)
        print(f'\n{len(rows)} handlers, mean similarity {avg:.3f}, '
              f'{below} below the {a.threshold:.2f} gate')


if __name__ == '__main__':
    main()
