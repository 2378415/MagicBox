import sys, io, re
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
path, off, ln = sys.argv[1], int(sys.argv[2], 0), int(sys.argv[3], 0)
d = open(path, 'rb').read()
chunk = d[off:off+ln]
for m in re.finditer(rb'[\x20-\x7e]{3,}', chunk):
    print(f'  0x{off+m.start():06x}  {m.group().decode("ascii")}')
