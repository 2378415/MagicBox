"""Compact inspection of selected functions: callers/callees names + body head."""
import csv, glob, os, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SIDE = sys.argv[1]
ENTRIES = sys.argv[2:]

idx = {r['entry']: r for r in csv.DictReader(
    open(os.path.join(ROOT, 'reversed', f'raw_{SIDE}', '_index.csv'), encoding='utf-8'))}
names, paths = {}, {}
for p in glob.glob(os.path.join(ROOT, 'reversed', 'src', SIDE, '*', '*.c')):
    e, n = os.path.basename(p)[:-2].split('_', 1)
    names[e] = n
    paths[e] = p
callers, callees = {}, {}
for line in open(os.path.join(ROOT, 'reversed', f'raw_{SIDE}', '_edges.csv'), encoding='utf-8').read().splitlines()[1:]:
    a, _, b = line.partition(',')
    if a and b:
        callers.setdefault(b, []).append(a)
        callees.setdefault(a, []).append(b)

for e in ENTRIES:
    r = idx.get(e)
    p = paths.get(e)
    print('=' * 78)
    print(f"{e}  {names.get(e,'?')}  size={r['size'] if r else '?'}  module={os.path.basename(os.path.dirname(p)) if p else '?'}")
    print('  callers: ' + ', '.join(f'{c}:{names.get(c, "?")}' for c in callers.get(e, [])[:6]))
    print('  callees: ' + ', '.join(f'{c}:{names.get(c, "?")}' for c in callees.get(e, [])[:8]))
    if r and r.get('strings'):
        print('  strings: ' + r['strings'][:150])
    if p:
        body = open(p, encoding='utf-8').read().splitlines()
        for line in body[:16]:
            print('   ', line[:110])
