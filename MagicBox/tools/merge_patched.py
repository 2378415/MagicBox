#!/usr/bin/env python3
"""Merge the no-op-patched Ghidra dump into the canonical raw dump.

The patched images (see patch_excw.py) let Ghidra finish 150 of the 153
functions that previously only had an objdump fallback block.  This script
rewrites `reversed/raw_<side>/` from the patched dump while keeping the
canonical function names, and refuses the handful of bodies that are provably
wrong:

* `decompile failed` – the function is still undecodable;
* guard functions whose patched body folds to a bare `return;` while marking the
  rest unreachable.  That fold is an artefact: `excw` is not a no-op there, and
  hardware shows the body does run (`.km.silent(0,0)` replies, `.km.silent(1)`
  does not).  The objdump fallback body is carried over instead.

Usage: python tools/merge_patched.py [--dry]
"""
import csv
import glob
import os
import re
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PAIRS = [('work/raw_nop_left', 'reversed/raw_left'),
         ('work/raw_nop_right', 'reversed/raw_right')]
RETURN_ONLY = re.compile(r'^\s*return;\s*$', re.M)


def degenerate(text):
    """True when the fold threw the body away (excw is not a no-op there)."""
    n = text.count('Removing unreachable block')
    if n < 4:
        return False
    body = '\n'.join(l for l in text.splitlines()
                     if 'Removing unreachable block' not in l)
    return bool(RETURN_ONLY.search(body)) and len(body) < 900


def load_index(path):
    if not os.path.exists(path):
        return {}
    return {r['entry']: r for r in csv.DictReader(open(path, encoding='utf-8'))}


def main():
    dry = '--dry' in sys.argv
    for patched_dir, canon_dir in PAIRS:
        patched = os.path.join(ROOT, patched_dir)
        canon = os.path.join(ROOT, canon_dir)
        if not os.path.isdir(patched):
            print(f'skip {patched_dir} (missing)')
            continue
        old_idx = load_index(os.path.join(canon, '_index.csv'))
        old_files = {os.path.basename(p) for p in glob.glob(os.path.join(canon, '*.c'))}
        old_by_entry = {}
        for fn in old_files:
            old_by_entry[fn.split('_')[0]] = fn

        rows, keep, degrade, missing, replaced = [], 0, [], 0, 0
        for p in sorted(glob.glob(os.path.join(patched, '*.c'))):
            base = os.path.basename(p)
            entry = base.split('_')[0]
            txt = open(p, encoding='utf-8', errors='replace').read()
            old = old_idx.get(entry)
            name = old['name'] if old else base.split('_', 1)[1][:-2]
            if 'decompile failed' in txt or degenerate(txt):
                degrade.append((entry, name, 'failed' if 'decompile failed' in txt else 'guard-fold'))
                src = old_by_entry.get(entry)
                if src:
                    txt = open(os.path.join(canon, src), encoding='utf-8', errors='replace').read()
                    keep += 1
                else:
                    missing += 1
            else:
                txt = txt.replace(f"// {entry}  ", f"// {entry}  {name}  ", 1)
                if old and old.get('size') != base:
                    pass
                replaced += 1
            target = os.path.join(canon, f'{entry}_{name}.c')
            if not dry:
                open(target, 'w', encoding='utf-8').write(txt)
            rows.append((entry, name, base))

        # index / edges rebuilt with canonical names
        pidx = load_index(os.path.join(patched, '_index.csv'))
        if not dry:
            with open(os.path.join(canon, '_gaps.txt'), 'w', encoding='utf-8') as fh:
                for entry, name, why in degrade:
                    fh.write(f'{entry}\t{name}\t{why}\n')
            with open(os.path.join(canon, '_index.csv'), 'w', encoding='utf-8', newline='') as fh:
                w = csv.writer(fh)
                w.writerow(['entry', 'name', 'size', 'callers', 'callees', 'file', 'strings'])
                for entry, name, base in rows:
                    r = pidx.get(entry, {})
                    w.writerow([entry, name, r.get('size', ''), r.get('callers', ''),
                                r.get('callees', ''), f'{entry}_{name}.c', r.get('strings', '')])
            src_edges = os.path.join(patched, '_edges.csv')
            if os.path.exists(src_edges):
                open(os.path.join(canon, '_edges.csv'), 'w', encoding='utf-8').write(
                    open(src_edges, encoding='utf-8').read())
            keepset = {f'{e}_{n}.c' for e, n, _ in rows}
            for fn in old_files - keepset:
                os.remove(os.path.join(canon, fn))
        print(f'{patched_dir}: {len(rows)} functions, patched bodies {replaced}, '
              f'fallback kept {keep}, missing {missing}')
        for d in degrade:
            print(f'   kept fallback: {d[0]} {d[1]} ({d[2]})')


if __name__ == '__main__':
    main()
