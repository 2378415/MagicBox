#!/usr/bin/env python3
"""Normalised instruction-level similarity between two code regions (T3 gate).

Why not a byte diff: a rebuilt function will differ in register allocation,
literal-pool placement and branch offsets while still being the same code.  This
tool normalises those away and scores the remaining structure:

  * keep the mnemonic and the operand *shape* (registers, immediate widths),
    drop absolute addresses and label names;
  * numbers become `#imm`, addresses become `@addr`, local labels become `L`;
  * score = difflib ratio over the normalised mnemonic sequence (0..1).

Usage:
  # compare two functions inside the same official image
  python tools/diff_insn.py --image-a "D:/JinPeng/MagicBox/官方固件/V3.2_LEFT.bin" \
                            --a 0x4200e024 --b 0x4200e358

  # compare a rebuilt object (built with the same toolchain) against the original
  python tools/diff_insn.py --image-a ... --a 0x4200e024 --objdump-b build/cmd_move.objdump.txt

Exit code: 0 when score >= --threshold (default 0.70), else 1.
"""
import argparse
import difflib
import os
import re
import subprocess
import tempfile
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

def _find_objdump():
    """Locate xtensa-esp-elf-objdump.exe.

    The first bench machine kept the toolchain at D:\\Apply\\toolchains; the
    2026-11 rebuild installs it through idf_tools under D:\\esp-tools, so probe
    MAKCU_TOOLCHAIN_BIN, the legacy path and every idf_tools version directory
    instead of hardcoding one location.
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
SEGMENTS = [
    (0x3C030020, 0x10B60, 0x010020),
    (0x3FC93D00, 0x3004, 0x020B88),
    (0x40374000, 0xC484, 0x023B94),
    (0x42000020, 0x2F040, 0x030020),
    (0x40380484, 0x3794, 0x05F068),
]
LINE_RE = re.compile(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2,12}\s+)?([a-z][\w.]*)\s*(.*)$')
IMM_RE = re.compile(r'0x[0-9a-f]+|-?\b\d+\b')
REG_RE = re.compile(r'\b(?:a[0-9]{1,2}|sp|pc|sar|lcount|lbeg|lend|f[0-9]{1,2})\b')
LBL_RE = re.compile(r'\b(?:L_|\.L)?[0-9a-f]{5,}\b')


def carve_blob(image, start, stop):
    data = open(image, 'rb').read()
    for vaddr, ln, off in SEGMENTS:
        if vaddr <= start < vaddr + ln:
            blob = data[off:off + ln]
            tmpdir = tempfile.mkdtemp(prefix='makcu_diff_')
            out = os.path.join(tmpdir, f'seg_{start:08x}.bin')
            open(out, 'wb').write(blob)
            return out, vaddr
    raise SystemExit(f'address {start:#x} is outside the known segments')


def disasm_region(image, start, stop):
    blob, base = carve_blob(image, start, stop)
    out = subprocess.run([OBJDUMP, '-D', '-b', 'binary', '-m', 'xtensa',
                          '--no-show-raw-insn', f'--adjust-vma={base:#x}',
                          f'--start-address={start:#x}', f'--stop-address={stop:#x}',
                          blob], capture_output=True, text=True,
                         encoding='utf-8', errors='replace').stdout
    return out


def normalise(text):
    ops = []
    for line in text.splitlines():
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


def score(a, b):
    if not a and not b:
        return 1.0
    if not a or not b:
        return 0.0
    sm = difflib.SequenceMatcher(a=a, b=b, autojunk=False)
    return sm.ratio()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--image-a')
    ap.add_argument('--image-b')
    ap.add_argument('--a', help='start address in image-a (0x...)')
    ap.add_argument('--b', help='start address in image-b (or image-a when --stop-b omitted)')
    ap.add_argument('--stop-a', help='end address in image-a')
    ap.add_argument('--stop-b', help='end address in image-b')
    ap.add_argument('--size-a', type=lambda s: int(s, 0), default=0x200)
    ap.add_argument('--size-b', type=lambda s: int(s, 0), default=0x200)
    ap.add_argument('--objdump-b', help='pre-disassembled text for the rebuilt side')
    ap.add_argument('--threshold', type=float, default=0.70)
    ap.add_argument('--verbose', action='store_true')
    a = ap.parse_args()

    start_a = int(a.a, 0)
    stop_a = int(a.stop_a, 0) if a.stop_a else start_a + a.size_a
    text_a = disasm_region(a.image_a, start_a, stop_a)

    if a.objdump_b:
        text_b = open(a.objdump_b, encoding='utf-8', errors='replace').read()
    else:
        image_b = a.image_b or a.image_a
        start_b = int(a.b, 0)
        stop_b = int(a.stop_b, 0) if a.stop_b else start_b + a.size_b
        text_b = disasm_region(image_b, start_b, stop_b)

    ops_a, ops_b = normalise(text_a), normalise(text_b)
    s = score(ops_a, ops_b)
    print(f'A: {len(ops_a)} instructions   B: {len(ops_b)} instructions')
    print(f'similarity: {s:.3f}   threshold: {a.threshold:.2f}   '
          f'{"PASS" if s >= a.threshold else "FAIL"}')
    if a.verbose:
        for line in difflib.unified_diff(ops_a, ops_b, 'original', 'rebuilt', lineterm='', n=1):
            print(line)
    return 0 if s >= a.threshold else 1


if __name__ == '__main__':
    sys.exit(main())
