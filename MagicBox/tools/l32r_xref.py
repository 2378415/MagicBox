#!/usr/bin/env python3
"""Find l32r literal-pool references to known rodata addresses (Xtensa).

ESP-IDF builds with -mlongcalls, so calls and data loads go through 32-bit
literal pools: `l32r aN, .L` (+ `callx8 aN`). Decoding l32r targets recovers
xrefs without a full CFG. Segments are auto-detected from the merged image.
"""
import struct, sys, json, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

def u32(b, o): return struct.unpack_from('<I', b, o)[0]

def app_segments(d):
    best = None
    for off in range(0, len(d) - 24, 16):
        if d[off] != 0xE9: continue
        n = d[off+1]
        if not 1 <= n <= 16: continue
        p = off + 24; segs = []; ok = True
        for _ in range(n):
            if p + 8 > len(d): ok = False; break
            la, ln = u32(d, p), u32(d, p+4)
            if ln > 0x200000 or p + 8 + ln > len(d): ok = False; break
            segs.append((la, ln, p+8)); p += 8 + ln
        if not ok or not segs: continue
        if u32(d, segs[0][2]) == 0xABCD5432:
            best = segs
    return best

def main(binpath, strings_json):
    d = open(binpath, 'rb').read()
    segs = app_segments(d)
    ss = json.load(open(strings_json, encoding='utf8'))
    smap = {int(x['vaddr'], 16): x['s'] for x in ss if x['vaddr']}

    def v2o(v):
        for la, ln, fo in segs:
            if la <= v < la + ln: return fo + (v - la)
        return None
    def read32(v):
        o = v2o(v)
        return u32(d, o) if o is not None and o + 4 <= len(d) else None

    hits = []
    for la, ln, fo in segs:
        if not (0x40370000 <= la < 0x40400000 or 0x42000000 <= la < 0x44000000):
            continue
        for off in range(fo, fo + ln - 3):
            b = d[off:off+3]
            if (b[0] & 0x0F) != 0x01: continue
            va = la + (off - fo)
            imm = struct.unpack('<h', b[1:3])[0]
            t = (((va + 3) & ~3) + (imm << 2)) & 0xFFFFFFFF
            v = read32(t)
            if v in smap:
                hits.append({'code': hex(va), 'lit': hex(t), 'str': hex(v), 's': smap[v]})
    json.dump({'bin': binpath, 'hits': hits}, open(binpath + '.xref.json', 'w', encoding='utf8'),
              ensure_ascii=False, indent=1)
    print(f'{binpath}: xref hits {len(hits)}, unique strings {len({h["str"] for h in hits})}')

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
