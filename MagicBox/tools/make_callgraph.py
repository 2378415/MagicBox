import csv, os, glob, collections, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, 'reversed')

def load(side):
    idx = {}
    for r in csv.DictReader(open(os.path.join(ROOT, 'reversed', f'raw_{side}', '_index.csv'), encoding='utf-8')):
        idx[r['entry']] = r
    edges = []
    for line in open(os.path.join(ROOT, 'reversed', f'raw_{side}', '_edges.csv'), encoding='utf-8').read().splitlines()[1:]:
        a, _, b = line.partition(',')
        if a and b:
            edges.append((a, b))
    mod = {}
    for path in glob.glob(os.path.join(OUT, 'src', side, '*', '*.c')):
        entry = os.path.basename(path).split('_', 1)[0]
        name = os.path.basename(path)[:-2].split('_', 1)[1]
        mod[entry] = (os.path.basename(os.path.dirname(path)), name)
    return idx, edges, mod

lines = ['# Call graph summary', '',
         'Derived from `_edges.csv` (Ghidra call references). `callers` counts distinct call sites,',
         '`calls` counts distinct callees. Module names come from the reconstructed tree.', '']

for side in ('left', 'right'):
    idx, edges, mod = load(side)
    outdeg = collections.Counter(a for a, _ in edges)
    indeg = collections.Counter(b for _, b in edges)
    pairs = collections.Counter()
    for a, b in edges:
        ma = mod.get(a, ('?', '?'))[0]
        mb = mod.get(b, ('?', '?'))[0]
        if ma != mb:
            pairs[(ma, mb)] += 1
    lines.append(f'## {side}')
    lines.append('')
    lines.append('### Most-called functions')
    lines.append('')
    lines.append('| entry | module | name | callers | calls |')
    lines.append('|---|---|---|---:|---:|')
    for e, n in indeg.most_common(20):
        m, name = mod.get(e, ('?', idx.get(e, {}).get('name', '?')))
        lines.append(f'| `0x{e}` | {m} | `{name}` | {n} | {outdeg.get(e, 0)} |')
    lines.append('')
    lines.append('### Cross-module calls (top 15)')
    lines.append('')
    lines.append('| from | to | edges |')
    lines.append('|---|---|---:|')
    for (a, b), n in pairs.most_common(15):
        lines.append(f'| {a} | {b} | {n} |')
    lines.append('')

open(os.path.join(OUT, 'docs', 'call_graph.md'), 'w', encoding='utf-8').write('\n'.join(lines))
print('written docs/call_graph.md')
