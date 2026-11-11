#!/usr/bin/env python3
"""ESP32-S3 flash image parser: locate images, partition table, app descriptor."""
import struct, sys, json, os

def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def u16(b, o): return struct.unpack_from('<H', b, o)[0]

def parse_image(d, off, label=''):
    """Parse one ESP image at file offset off. Returns dict or None."""
    if off + 24 > len(d) or d[off] != 0xE9:
        return None
    nseg = d[off+1]
    if not (1 <= nseg <= 16):
        return None
    mode = d[off+2]
    sz_freq = d[off+3]
    entry = u32(d, off+8)
    chip_id = u16(d, off+16)
    hash_app = d[off+23]
    p = off + 24
    segs = []
    ok = True
    for i in range(nseg):
        if p + 8 > len(d):
            ok = False; break
        la = u32(d, p); ln = u32(d, p+4)
        if ln > 0x200000 or p + 8 + ln > len(d):
            ok = False; break
        segs.append({'i': i, 'load': la, 'len': ln, 'file_off': p+8})
        p += 8 + ln
    if not ok:
        return None
    # checksum byte + optional sha256
    cs_off = p
    end = p + 1 + (32 if hash_app else 0)
    img = {
        'label': label, 'file_off': off, 'seg_count': nseg, 'spi_mode': mode,
        'flash_size_code': sz_freq >> 4, 'flash_freq_code': sz_freq & 0xF,
        'entry': entry, 'chip_id': chip_id, 'hash_appended': hash_app,
        'segments': segs, 'end_off': end, 'size': end - off,
    }
    # app descriptor lives at start of first segment for app images
    if segs:
        d0 = segs[0]['file_off']
        if d0 + 4 <= len(d) and u32(d, d0) == 0xABCD5432:
            def cstr(o, n):
                return d[o:o+n].split(b'\x00')[0].decode('utf-8', 'replace')
            img['app_desc'] = {
                'magic': hex(u32(d, d0)),
                'secure_version': u32(d, d0+4),
                'version': cstr(d0+16, 32),
                'project_name': cstr(d0+48, 32),
                'time': cstr(d0+80, 16),
                'date': cstr(d0+96, 16),
                'idf_ver': cstr(d0+112, 32),
                'elf_sha256': d[d0+144:d0+176].hex(),
            }
    return img

def parse_parttable(d, off):
    if d[off:off+2] != b'\xaa\x50':
        return None
    entries = []
    for i in range(95):
        e = off + i*32
        if e + 32 > len(d): break
        if d[e:e+2] == b'\xaa\x50':
            if d[e:e+2] == b'\xaa\x50' and d[e+2:e+18].strip(b'\xff') == b'':
                continue
        magic, ptype, subtype, poff, psize = d[e:e+2], d[e+2], d[e+3], u32(d, e+4), u32(d, e+8)
        name = d[e+12:e+28].split(b'\x00')[0].decode('utf-8','replace')
        flags = u32(d, e+28)
        if magic != b'\xaa\x50':
            break
        entries.append({'index': i, 'type': ptype, 'subtype': subtype, 'offset': poff,
                        'size': psize, 'name': name, 'flags': flags})
    return entries

def main(path):
    d = open(path, 'rb').read()
    out = {'path': os.path.abspath(path), 'size': len(d), 'sha256_prefix': None}
    # scan 16-byte aligned offsets for images
    imgs = []
    for off in range(0, len(d) - 24, 16):
        if d[off] != 0xE9: continue
        im = parse_image(d, off, label=f'img@{off:#x}')
        if im and im['size'] > 64:
            imgs.append(im)
    # partition table candidates
    pts = []
    for off in range(0, min(len(d), 0x20000), 0x1000):
        pt = parse_parttable(d, off)
        if pt:
            pts.append({'file_off': off, 'entries': pt})
    out['images'] = imgs
    out['partition_tables'] = pts
    print(json.dumps(out, indent=2, ensure_ascii=False))

if __name__ == '__main__':
    main(sys.argv[1])
