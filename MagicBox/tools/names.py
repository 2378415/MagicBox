import json, re, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
d = json.load(open(sys.argv[1], encoding='utf8'))
ident = re.compile(r'^[A-Za-z_][A-Za-z0-9_]{3,}$')
seen = {}
for h in d['hits']:
    s = h['s']
    if ident.match(s):
        seen.setdefault(s, set()).add(h['code'])
for s in sorted(seen):
    print(f"  {s:52} {', '.join(sorted(seen[s]))}")
print('identifiers with xrefs:', len(seen))
