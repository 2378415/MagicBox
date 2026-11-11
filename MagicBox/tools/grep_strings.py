import json, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

path = sys.argv[1]
pats = sys.argv[2].split(',') if len(sys.argv) > 2 else None
limit = int(sys.argv[3]) if len(sys.argv) > 3 else 200
ss = json.load(open(path, encoding='utf8'))
print('==', path, 'strings:', len(ss))
n = 0
for x in ss:
    s = x['s']
    if pats and not any(p in s for p in pats):
        continue
    print(f"  {x['vaddr'] or '-':>12}  {s[:120]}")
    n += 1
    if n >= limit:
        break
print('shown', n)
