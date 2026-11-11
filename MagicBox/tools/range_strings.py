import json, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
path = sys.argv[1]
lo = int(sys.argv[2], 0); hi = int(sys.argv[3], 0)
ss = json.load(open(path, encoding='utf8'))
n = 0
for x in ss:
    if x['vaddr'] is None: continue
    v = int(x['vaddr'], 16)
    if lo <= v < hi:
        print(f"  {x['vaddr']}  off={x['off']:#07x}  {x['s'][:140]}")
        n += 1
print('count', n)
