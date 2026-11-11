#!/usr/bin/env python3
"""Convert an ESP32 app image (inside a merged flash dump) to ELF32/XTENSA for disassembly."""
import struct, sys

def u32(b,o): return struct.unpack_from('<I',b,o)[0]

def find_app(d, want_off=None):
    cands=[]
    for off in range(0,len(d)-24,16):
        if d[off]!=0xE9: continue
        n=d[off+1]
        if not 1<=n<=16: continue
        p=off+24; segs=[]; ok=True
        for i in range(n):
            if p+8>len(d): ok=False;break
            la=u32(d,p); ln=u32(d,p+4)
            if ln>0x200000 or p+8+ln>len(d): ok=False;break
            segs.append((la,ln,p+8)); p+=8+ln
        if not ok: continue
        if segs and u32(d,segs[0][2])==0xABCD5432:
            cands.append((off,segs,u32(d,off+4)))
    if want_off is not None:
        for c in cands:
            if c[0]==want_off: return c
        raise SystemExit(f'app image not found at {want_off:#x}')
    if not cands: raise SystemExit('no app image')
    return max(cands,key=lambda c:c[0])

def build(d, out, off=None):
    off,segs,entry = find_app(d,off)
    # ELF header
    ehsize, phentsize, nph = 52, 32, len(segs)
    data_start = ehsize + phentsize*nph
    data_start = (data_start + 15) & ~15
    body = bytearray()
    phdrs = []
    cur = data_start
    for (la,ln,fo) in segs:
        blob = d[fo:fo+ln]
        phdrs.append((cur, la, ln, 5 if (0x42000000<=la<0x44000000 or 0x40370000<=la<0x40400000) else 6))
        body += blob
        cur += len(blob)
        pad = (-cur) & 15
        body += b'\0'*pad
        cur += pad
    e = bytearray()
    e += b'\x7fELF' + bytes([1,1,1,0]) + b'\0'*8
    e += struct.pack('<HHIIIIIHHHHHH', 2, 94, 1, entry, ehsize, 0, 0, ehsize,
                     phentsize, nph, 40, 0, 0)
    for (o,v,sz,fl) in phdrs:
        e += struct.pack('<IIIIIIII', 1, o, v, v, sz, sz, fl, 4)
    e += b'\0'*(data_start-len(e))
    e += body
    open(out,'wb').write(e)
    print(f'app @0x{off:x} entry=0x{entry:08x} segs={len(segs)} -> {out} ({len(e)} bytes)')
    for (la,ln,fo) in segs:
        print(f'  vaddr 0x{la:08x} len 0x{ln:x}')

if __name__=='__main__':
    d=open(sys.argv[1],'rb').read()
    build(d, sys.argv[2], int(sys.argv[3],0) if len(sys.argv)>3 else None)
