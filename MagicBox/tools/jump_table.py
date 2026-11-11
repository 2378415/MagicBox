import struct, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
BIN = sys.argv[1] if len(sys.argv) > 1 else r'官方固件\V3.2_LEFT.bin'
PTR = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x42000DC8

SEG = [(0x3c030020,0x10b60,0x010020),(0x3fc93d00,0x3004,0x020b88),
       (0x40374000,0xc484,0x023b94),(0x42000020,0x2f040,0x030020),
       (0x40380484,0x3794,0x05f068)]
d = open(BIN,'rb').read()
def v2o(v):
    for la,ln,fo in SEG:
        if la<=v<la+ln: return fo+(v-la)
def rd32(v):
    o=v2o(v)
    return struct.unpack_from('<I',d,o)[0] if o is not None else None

tbl = rd32(PTR)
print(f'jump-table pointer at {PTR:#x} -> {tbl:#x}')
for i in range(32):
    t = rd32(tbl + i*4)
    if t is None: break
    print(f'  opcode {i:#04x} -> {t:#010x}')
