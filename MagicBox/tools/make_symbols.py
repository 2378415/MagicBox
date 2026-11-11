import json, re, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

ident = re.compile(r'^[A-Za-z_][A-Za-z0-9_]{2,}$')

def build(xref_path, out_path):
    d = json.load(open(xref_path, encoding='utf8'))
    strings, codes = {}, {}
    for h in d['hits']:
        s = h['s']
        if not ident.match(s):
            continue
        strings.setdefault(s, set()).add(h['str'])
        codes.setdefault(s, set()).add(h['code'])
    rows = []
    for s in sorted(strings):
        if len(strings[s]) != 1:
            continue
        cl = ','.join(sorted(codes.get(s, [])))
        rows.append(f"{s}\t{list(strings[s])[0]}\t{cl}")
    open(out_path, 'w', encoding='utf8', newline='\n').write('\n'.join(rows) + '\n')
    with_codes = sum(1 for s in strings if len(strings[s]) == 1 and codes.get(s))
    print(f"{out_path}: {len(rows)} rows, {with_codes} with code xrefs")

build(r'官方固件\V3.2_LEFT.bin.xref.json', r'work\symbols_left.tsv')
build(r'官方固件\V3.7_RIGHT.bin.xref.json', r'work\symbols_right.tsv')
