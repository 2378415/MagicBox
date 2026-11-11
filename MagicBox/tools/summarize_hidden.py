import re, json, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

TXT = r'work\asm\hidden_all.objdump.txt'
STR = r'官方固件\V3.2_LEFT.bin.strings.json'
HANDLERS = [
    (0x08, 0x4200DBA0), (0x17, 0x4200DBB0), (0x10, 0x4200DE80),
    (0x18, 0x4200E56C), (0x16, 0x4200E624), (0x12, 0x4200E6F0),
    (0x13, 0x4200E718), (0x14, 0x4200E998), (0x0F, 0x4200E9D0),
    (0x15, 0x4200EA04), (0x0E, 0x4200EB1C), (0x0D, 0x4200EC48),
    (0x11, 0x4200ED74),
]
strings = {int(x['vaddr'], 16): x['s'] for x in json.load(open(STR, encoding='utf8')) if x['vaddr']}

lines = []
for ln in open(TXT, encoding='utf8'):
    m = re.match(r'\s*([0-9a-f]+):\s+(.*)', ln)
    if m:
        lines.append((int(m.group(1), 16), m.group(2).strip()))

bounds = sorted(a for _, a in HANDLERS) + [0x4200EE00]
for op, addr in HANDLERS:
    end = min(b for b in bounds if b > addr)
    body = [(a, t) for a, t in lines if addr <= a < end]
    calls, lits, consts, chars = [], [], [], []
    for a, t in body:
        m = re.search(r'call8\s+0x([0-9a-f]+)', t)
        if m: calls.append((a, int(m.group(1), 16)))
        m = re.search(r'l32r\s+a\d+,\s+0x[0-9a-f]+ \(0x([0-9a-f]+)\)', t)
        if m:
            v = int(m.group(1), 16)
            lits.append((a, v, strings.get(v)))
        m = re.search(r'movi\s+a\d+,\s+0x([0-9a-f]+)', t)
        if m and int(m.group(1), 16) > 0xFF: consts.append((a, int(m.group(1), 16)))
        m = re.search(r'addi\s+a\d+,\s+a\d+,\s+-0x([0-9a-f]+)', t)
        if m and int(m.group(1), 16) < 0x80: chars.append((a, int(m.group(1), 16)))
    print(f"\n=== opcode {op:#04x} @ {addr:#x}  ({len(body)} insns, end {end:#x}) ===")
    print(f"  first: {body[0][1] if body else '?'}")
    if calls:
        print("  calls: " + ", ".join(f"{a:#x}->{t:#x}" for a, t in calls[:8]))
    if consts:
        print("  consts: " + ", ".join(f"{v:#x}@{a:#x}" for a, v in consts[:8]))
    if chars:
        uniq = sorted({c for _, c in chars})
        print("  char-imm: " + ", ".join(f"-0x{c:x}" for c in uniq[:12]))
    sm = [(a, v, s) for a, v, s in lits if s]
    if sm:
        print("  strings:")
        for a, v, s in sm[:8]:
            print(f"    {a:#x} -> {v:#x} {s[:70]!r}")
