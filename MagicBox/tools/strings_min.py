import re, sys, io, struct
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
path = sys.argv[1]
pats = sys.argv[2].split(',')
d = open(path, 'rb').read()
pat = re.compile(rb'[\x20-\x7e]{3,}')
for m in pat.finditer(d):
    s = m.group().decode('ascii')
    if any(p in s for p in pats):
        print(f'  off=0x{m.start():06x}  {s[:80]}')
