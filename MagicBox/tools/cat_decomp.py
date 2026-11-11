import os, sys, io, glob
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
d = sys.argv[1]
for f in sorted(glob.glob(os.path.join(d, '*.c'))):
    txt = open(f, encoding='utf8').read().splitlines()
    head = [l for l in txt if l.startswith('// entry')]
    body = txt[1:]
    print('=' * 70)
    print(os.path.basename(f), '|', head[0] if head else '')
    for line in body[:46]:
        print(line)
    if len(body) > 46:
        print(f'... ({len(body)} lines)')
