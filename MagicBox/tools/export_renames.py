import csv, os, sys, io
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from symbol_names import all_names

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, 'reversed', 'docs')
os.makedirs(OUT, exist_ok=True)

rows, skipped = [], []
for side, table in all_names().items():
    idx = {r['entry']: r for r in csv.DictReader(
        open(os.path.join(ROOT, 'reversed', f'raw_{side}', '_index.csv'), encoding='utf-8'))}
    tsv = []
    for addr, (new, why) in sorted(table.items()):
        if addr in idx:
            rows.append((side, addr, idx[addr]['name'], new, why))
            tsv.append(f'{addr}\t{new}')
        else:
            skipped.append((side, addr, new, why))
    open(os.path.join(OUT, f'rename_{side}.tsv'), 'w', encoding='utf-8').write('\n'.join(tsv) + '\n')

with open(os.path.join(OUT, 'rename_map.csv'), 'w', encoding='utf-8', newline='') as fh:
    w = csv.writer(fh)
    w.writerow(['image', 'entry', 'original', 'new', 'reason'])
    w.writerows(rows)
with open(os.path.join(OUT, 'rename_skipped.csv'), 'w', encoding='utf-8', newline='') as fh:
    w = csv.writer(fh)
    w.writerow(['image', 'entry', 'new', 'reason'])
    w.writerows(skipped)
print('applied renames:', len(rows), 'skipped (not a function entry):', len(skipped))
