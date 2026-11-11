import re, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
TXT = r'work\asm\hidden_all.objdump.txt'
HANDLERS = [(0x08,0x4200DBA0),(0x17,0x4200DBB0),(0x10,0x4200DE80),(0x18,0x4200E56C),
            (0x16,0x4200E624),(0x12,0x4200E6F0),(0x13,0x4200E718),(0x14,0x4200E998),
            (0x0F,0x4200E9D0),(0x15,0x4200EA04),(0x0E,0x4200EB1C),(0x0D,0x4200EC48),
            (0x11,0x4200ED74)]
insns, entries = [], []
for ln in open(TXT, encoding='utf8'):
    m = re.match(r'\s*([0-9a-f]+):\s+(.*)', ln)
    if not m: continue
    a, t = int(m.group(1),16), m.group(2).strip()
    insns.append((a,t))
    if t.startswith('entry'): entries.append(a)
entries.sort()
def enclosing(a):
    prev = None
    for e in entries:
        if e <= a: prev = e
        else: break
    return prev
print('entry points found:', len(entries))
for op, a in HANDLERS:
    e = enclosing(a)
    exact = 'EXACT' if e == a else f'+0x{a-e:x}'
    print(f'opcode {op:#04x}: target {a:#x}  enclosing entry {e:#x}  ({exact})')
