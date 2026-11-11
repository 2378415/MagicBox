#!/usr/bin/env python3
"""Fill Ghidra decompilation gaps with per-function objdump disassembly.

Runs objdump with an explicit --start-address for every gap so decoding is
aligned to the real function entry (a global linear dump can drift on data
bytes and produce misaligned code).
"""
import csv, os, re, subprocess, sys, io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OBJDUMP = r'D:\Apply\toolchains\xtensa-esp-elf\bin\xtensa-esp-elf-objdump.exe'

REGIONS = {
    'left': [
        ('irom', 0x42000020, 0x30020, 0x2F040),
        ('iram0', 0x40374000, 0x23B94, 0xC484),
        ('iram1', 0x40380484, 0x5F068, 0x3794),
    ],
    'right': [
        ('irom', 0x42000020, 0x20020, 0x26ACC),
        ('iram0', 0x40374000, 0x1CED4, 0x3144),
        ('iram1', 0x40377144, 0x46AF4, 0xCC00),
    ],
}
BIN = {'left': os.path.join('官方固件', 'V3.2_LEFT.bin'),
       'right': os.path.join('官方固件', 'V3.7_RIGHT.bin')}
MARK = '/* ---- objdump fallback'

CALL_RE = re.compile(r'call8\s+0x([0-9a-f]+)')
L32R_RE = re.compile(r'l32r\s+(a\d+),\s+0x([0-9a-f]+) \(0x([0-9a-f]+)\)')
LINE_RE = re.compile(r'\s*([0-9a-f]+):\s+(\S.*)')


def build_maps(side):
    import glob, json
    sym = {}
    for p in glob.glob(os.path.join(ROOT, 'reversed', 'src', side, '*', '*.c')):
        e, n = os.path.basename(p)[:-2].split('_', 1)
        sym[int(e, 16)] = n
    strs = {}
    base = 'V3.2_LEFT.bin' if side == 'left' else 'V3.7_RIGHT.bin'
    path = os.path.join(ROOT, '官方固件', base + '.strings.json')
    if os.path.exists(path):
        for x in json.load(open(path, encoding='utf8')):
            if x['vaddr']:
                strs[int(x['vaddr'], 16)] = x['s']
    return sym, strs


def blobs(side):
    data = open(os.path.join(ROOT, BIN[side]), 'rb').read()
    out = []
    for name, vma, off, ln in REGIONS[side]:
        blob = os.path.join(ROOT, 'work', f'{name}_{side}.bin')
        os.makedirs(os.path.dirname(blob), exist_ok=True)
        open(blob, 'wb').write(data[off:off + ln])
        out.append((vma, vma + ln, blob, vma))
    return out


def disasm(side_blobs, start, stop):
    blob, base = None, None
    for lo, hi, path, vma in side_blobs:
        if lo <= start < hi:
            blob, base = path, vma
            break
    if blob is None:
        return []
    out = subprocess.run([OBJDUMP, '-D', '-b', 'binary', '-m', 'xtensa',
                          '--no-show-raw-insn', f'--adjust-vma={base:#x}',
                          f'--start-address={start:#x}', f'--stop-address={stop:#x}', blob],
                         capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
    lines = []
    for line in out.splitlines():
        m = LINE_RE.match(line)
        if m:
            lines.append((int(m.group(1), 16), m.group(2).strip()))
    return lines


def annotate(text, sym, strs):
    m = CALL_RE.search(text)
    if m:
        a = int(m.group(1), 16)
        if a in sym:
            return text + f'   ; {sym[a]}'
    m = L32R_RE.search(text)
    if m:
        v = int(m.group(3), 16)
        if v in strs:
            return text + '   ; "{}"'.format(strs[v].replace('\n', ' ')[:60])
        if v in sym:
            return text + f'   ; {sym[v]}'
    return text


TERM_RE = re.compile(r'^(retw\.n|retw|ret|j|jx|callx8)\b')
PAD_RE = re.compile(r'^ill\b')


def trim(raw):
    """Cut a linear dump at the end of the function.

    Linear disassembly happily runs into the next function or into literal data.
    Stop at `ill` padding, or at a fresh `entry` prologue once a terminal
    instruction has been seen (that is how the previous over-running windows
    polluted `0x4200E56C` with the body of `0x4200E624`).
    """
    seen_term = False
    for i, (_a, ins) in enumerate(raw):
        if PAD_RE.match(ins):
            return raw[:i + 1]
        if seen_term and ins.startswith('entry'):
            return raw[:i]
        if TERM_RE.match(ins):
            seen_term = True
    return raw


def gap_entries(side):
    """Explicit gap list written by merge_patched.py (fallback-only functions)."""
    path = os.path.join(ROOT, 'reversed', 'raw_' + side, '_gaps.txt')
    if not os.path.exists(path):
        return None
    out = set()
    for line in open(path, encoding='utf-8'):
        line = line.strip()
        if line:
            out.add(int(line.split('\t')[0], 16))
    return out


def main():
    filled, missed = [], []
    for side in ('left', 'right'):
        side_blobs = blobs(side)
        symbols, strings = build_maps(side)
        only = gap_entries(side)
        idx = {r['entry']: r for r in csv.DictReader(
            open(os.path.join(ROOT, 'reversed', 'raw_' + side, '_index.csv'), encoding='utf-8'))}
        src = os.path.join(ROOT, 'reversed', 'src', side)
        for module in sorted(os.listdir(src)):
            mdir = os.path.join(src, module)
            if not os.path.isdir(mdir):
                continue
            for fn in sorted(os.listdir(mdir)):
                if not fn.endswith('.c'):
                    continue
                path = os.path.join(mdir, fn)
                txt = open(path, encoding='utf-8').read()
                if MARK in txt:
                    txt = txt.split(MARK)[0].rstrip() + '\n'
                entry = int(fn.split('_')[0], 16)
                is_gap = 'halt_baddata' in txt if only is None else entry in only
                if not is_gap:
                    open(path, 'w', encoding='utf-8').write(txt)
                    continue
                if 'halt_baddata' not in txt:
                    open(path, 'w', encoding='utf-8').write(txt)
                    continue
                size = int(idx.get(f'{entry:x}', {}).get('size', 64))
                nxt = next((e for e in sorted(symbols) if e > entry + 0x20), entry + 0x800)
                limit = min(nxt, entry + max(size + 0x40, 0x200))
                raw = trim(disasm(side_blobs, entry, limit))
                if not raw:
                    missed.append((side, module, entry, 'no disassembly'))
                    open(path, 'w', encoding='utf-8').write(txt)
                    continue
                starts = {a for a, _ in raw}
                targets = set()
                for a, ins in raw:
                    for m in re.finditer(r'0x([0-9a-f]{6,8})', ins):
                        v = int(m.group(1), 16)
                        if v in starts and v != a:
                            targets.add(v)
                lines = []
                for a, ins in raw:
                    if a in targets:
                        lines.append(f'L_{a:08x}:')
                    lines.append(f'{a:08x}:  {annotate(ins, symbols, strings)}')
                block = ('\n/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----\n'
                         + '\n'.join(lines) + '\n---- end objdump fallback ---- */\n')
                open(path, 'w', encoding='utf-8').write(txt.rstrip() + '\n' + block)
                filled.append((side, module, entry, len(raw)))

    with open(os.path.join(ROOT, 'reversed', 'docs', 'known_gaps.md'), 'w', encoding='utf-8') as fh:
        fh.write('# Decompilation gaps and their disassembly fallback\n\n')
        fh.write('Two causes remain after the `excw` workaround (see `patch_excw.py` in the\n')
        fh.write('repository root tooling): Ghidra still reports a pcode/construct error on\n')
        fh.write('these function bodies, or the body decompiles into a guard fold that the\n')
        fh.write('hardware disproves (`excw` is not a no-op when it sits in a guard). Each\n')
        fh.write('affected file ends with an `objdump fallback` block produced by\n')
        fh.write('disassembling from the exact function entry, cut at `ill` padding or at the\n')
        fh.write('next `entry` prologue so it never swallows the next function.\n\n')
        fh.write('Tried and rejected: replacing the zero alignment padding in front of each\n')
        fh.write('failing address with an equal-length no-op (`tools/patch_padding.py`) leaves\n')
        fh.write('the failure count unchanged — the remaining errors are missing instruction\n')
        fh.write('constructors in the Xtensa module, not alignment drift.\n\n')
        fh.write(f'Filled: {len(filled)}  |  still missing: {len(missed)}\n\n')
        fh.write('| image | module | entry | instructions |\n|---|---|---|---:|\n')
        for side, module, entry, n in filled:
            fh.write(f'| {side} | {module} | `0x{entry:08x}` | {n} |\n')
        if missed:
            fh.write('\n## Still missing\n\n| image | module | entry | reason |\n|---|---|---|---|\n')
            for side, module, entry, why in missed:
                fh.write(f'| {side} | {module} | `0x{entry:08x}` | {why} |\n')
    print('filled:', len(filled), 'missed:', len(missed))


if __name__ == '__main__':
    main()
