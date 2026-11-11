"""List vendor functions that still carry a FUN_<address> name, ranked by usage."""
import csv, glob, os, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

rows = []
for side in ('left', 'right'):
    idx = {r['entry']: r for r in csv.DictReader(
        open(os.path.join(ROOT, 'reversed', f'raw_{side}', '_index.csv'), encoding='utf-8'))}
    for path in glob.glob(os.path.join(ROOT, 'reversed', 'src', side, '*', '*.c')):
        mod = os.path.basename(os.path.dirname(path))
        if mod.startswith('idf_'):
            continue
        entry, name = os.path.basename(path)[:-2].split('_', 1)
        if not name.startswith('FUN_'):
            continue
        r = idx.get(entry)
        if not r:
            continue
        rows.append((side, mod, entry, int(r['callers']), int(r['callers']) + int(r['callees']),
                     int(r['size']), (r.get('strings') or '')[:80]))

rows.sort(key=lambda r: (-r[3], -r[4], -r[5]))
print(f'unnamed vendor functions: {len(rows)}')
print(f"{'image':5} {'module':10} {'entry':>8} {'callers':>7} {'edges':>5} {'size':>5}  strings")
for r in rows[:30]:
    print(f'{r[0]:5} {r[1]:10} {r[2]:>8} {r[3]:>7} {r[4]:>5} {r[5]:>5}  {r[6]}')
