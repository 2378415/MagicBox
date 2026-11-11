import struct, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

BIN = sys.argv[1] if len(sys.argv) > 1 else r'官方固件\V3.2_LEFT.bin'
TABLE_PTR = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x42000DBC

SEG = [(0x3c030020,0x10b60,0x010020),(0x3fc93d00,0x3004,0x020b88),
       (0x40374000,0xc484,0x023b94),(0x42000020,0x2f040,0x030020),
       (0x40380484,0x3794,0x05f068)]
d = open(BIN,'rb').read()

def v2o(v):
    for la,ln,fo in SEG:
        if la<=v<la+ln: return fo+(v-la)
    return None

def rd32(v):
    o=v2o(v)
    return struct.unpack_from('<I',d,o)[0] if o is not None else None

def cstr(v, n=64):
    o=v2o(v)
    if o is None: return None
    raw=d[o:o+n].split(b'\0')[0]
    try: return raw.decode('ascii')
    except: return repr(raw)

tbl = rd32(TABLE_PTR)
print(f'table pointer at {TABLE_PTR:#x} -> {tbl:#x}')
print(f"{'idx':>3} {'name':26} {'len':>4} {'w2':>12} {'w3':>12} {'w4':>12}  name@")
i=0
while True:
    base = tbl + i*0x14
    name_p = rd32(base)
    if not name_p: break
    s = cstr(name_p)
    if s is None:
        print(f'  stop: name ptr {name_p:#x} outside image at idx {i}')
        break
    ln = rd32(base+4); w2 = rd32(base+8); w3 = rd32(base+0xc); w4 = rd32(base+0x10)
    print(f"{i:>3} {s[:26]:26} {ln:>4} {w2:#12x} {w3:#12x} {w4:#12x}  {name_p:#x}")
    i+=1
    if i>200: break
print('entries:', i)
