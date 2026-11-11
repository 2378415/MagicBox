p="tools/t3_report.py"
t=open(p,encoding="utf-8").read()
t=t.replace('''def original_sizes(side):
    path = os.path.join(OLD_REPO, 'reversed', 'raw_' + side, '_index.csv')
    out = {}
    with open(path, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            out[r['name']] = (int(r['entry'], 16), int(r['size']))
    return out''','''def original_sizes(side):
    """curated name -> (entry, size).

    The raw index keeps Ghidra's FUN_ names, the curated names live in
    rename_map.csv; join them by entry address.
    """
    idx = {}
    path = os.path.join(OLD_REPO, 'reversed', 'raw_' + side, '_index.csv')
    with open(path, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            idx[int(r['entry'], 16)] = int(r['size'])
    out = {}
    rmap = os.path.join(OLD_REPO, 'reversed', 'docs', 'rename_map.csv')
    with open(rmap, encoding='utf-8') as fh:
        for r in csv.DictReader(fh):
            if r['image'] != side:
                continue
            entry = int(r['entry'], 16)
            out[r['new']] = (entry, idx.get(entry, 0x200))
    return out''')
open(p,"w",encoding="utf-8").write(t)
print("patched name mapping")
