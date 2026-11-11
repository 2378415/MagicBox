import json, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
path = sys.argv[1]
want = sys.argv[2].split(',')
d = json.load(open(path, encoding='utf8'))
for h in d['hits']:
    if any(w in h['s'] for w in want):
        print(f"  code={h['code']:>12} lit={h['lit']:>12} str={h['str']:>12}  {h['s'][:120]}")
