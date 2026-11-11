#!/usr/bin/env python3
"""Regenerate reversed/docs/renames.md + rename_map.csv from tools/symbol_names.py.

symbol_names.py is the single source of truth: build_project.py applies those
names, this script documents them.
"""
import csv
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from symbol_names import all_names

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
docs = os.path.join(ROOT, 'reversed', 'docs')
names = all_names()

rows = []
for side in ('left', 'right'):
    for entry in sorted(names[side]):
        new, why = names[side][entry]
        rows.append({'image': side, 'entry': entry, 'original': 'FUN_' + entry,
                     'new': new, 'reason': why})

with open(os.path.join(docs, 'rename_map.csv'), 'w', encoding='utf-8', newline='') as fh:
    w = csv.DictWriter(fh, fieldnames=['image', 'entry', 'original', 'new', 'reason'])
    w.writeheader()
    w.writerows(rows)

out = ['# Semantic renames', '',
       'Curated names applied to the reconstructed tree. `tools/symbol_names.py` is the',
       'single source of truth; `tools/make_renames_doc.py` regenerates this file.',
       'Each name is backed by the analysis in 官方固件命令协议.md,',
       '官方固件未公开协议.md and `docs/reconstruction_patterns.md`.', '']
for side in ('left', 'right'):
    sub = [r for r in rows if r['image'] == side]
    out += [f'## {side} ({len(sub)})', '',
            '| entry | original | new | reason |', '|---|---|---|---|']
    for r in sub:
        out.append('| `0x{}` | `{}` | `{}` | {} |'.format(
            r['entry'], r['original'], r['new'], r['reason']))
    out.append('')

open(os.path.join(docs, 'renames.md'), 'w', encoding='utf-8').write('\n'.join(out))
print('documented', len(rows), 'names (', sum(1 for r in rows if r['image'] == 'left'),
      'left /', sum(1 for r in rows if r['image'] == 'right'), 'right )')
