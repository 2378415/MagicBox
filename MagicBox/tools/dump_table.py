import struct, json, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
BIN = r'官方固件\V3.2_LEFT.bin'
SEG = [(0x3c030020,0x10b60,0x010020),(0x3fc93d00,0x3004,0x020b88),
       (0x40374000,0xc484,0x023b94),(0x42000020,0x2f040,0x030020),
       (0x40380484,0x3794,0x05f068)]
d = open(BIN,'rb').read()
ss = json.load(open(BIN + '.strings.json', encoding='utf8'))
smap = {int(x['vaddr'],16): x['s'] for x in ss if x['vaddr']}
def v2o(v):
    for la,ln,fo in SEG:
        if la<=v<la+ln: return fo+(v-la)
for base in (0x42000b00, 0x42000c00, 0x42000d00):
    print(f'--- literal words @ {base:#x} ---')
    for i in range(0, 0x100, 4):
        v = struct.unpack_from('<I', d, v2o(base+i))[0]
        tag = ''
        if v in smap: tag = 'STR ' + smap[v][:60]
        elif 0x42000000 <= v < 0x44000000: tag = 'CODE/RO'
        elif 0x3c030000 <= v < 0x3c041000: tag = 'DATA/RO'
        elif v == 0: tag = 'NULL'
        print(f'  {base+i:#010x}: {v:#010x}  {tag}')
