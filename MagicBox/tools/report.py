#!/usr/bin/env python3
"""Report: images, partitions, and interesting strings with virtual addresses."""
import struct, sys, json, re

TYPES = {0:'app',1:'data'}
APP_SUB = {0:'factory',0x10:'ota_0',0x11:'ota_1',0x20:'test'}
DATA_SUB = {0:'ota',1:'phy',2:'nvs',3:'coredump',4:'nvs_keys',5:'efuse',6:'undefined',0x80:'esphttpd',0x81:'fat',0x82:'spiffs',0x83:'littlefs'}

def u32(b,o): return struct.unpack_from('<I',b,o)[0]

def images(d):
    out=[]
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
        end=p+1+(32 if d[off+23] else 0)
        if end>len(d): continue
        out.append({'off':off,'n':n,'entry':u32(d,off+8),'segs':segs,'size':end-off})
    return out

def parttable(d, off):
    if d[off:off+2]!=b'\xaa\x50': return None
    es=[]
    for i in range(95):
        e=off+i*32
        if e+32>len(d) or d[e:e+2]!=b'\xaa\x50': break
        es.append({'type':d[e+2],'sub':d[e+3],'off':u32(d,e+4),'size':u32(d,e+8),
                   'name':d[e+12:e+28].split(b'\0')[0].decode('utf8','replace'),'flags':u32(d,e+28)})
    return es

def app_desc(d, imgs):
    for im in imgs:
        if not im['segs']: continue
        d0=im['segs'][0][2]
        if u32(d,d0)==0xABCD5432:
            def s(o,n): return d[d0+o:d0+o+n].split(b'\0')[0].decode('utf8','replace')
            return {'file_off':im['off'],'version':s(16,32),'project':s(48,32),'time':s(80,16),
                    'date':s(96,16),'idf':s(112,32),'elf_sha256':d[d0+144:d0+176].hex()}
    return None

def strings(d, imgs, minlen=6):
    pat=re.compile(rb'[\x20-\x7e]{%d,}'%minlen)
    res=[]
    for m in pat.finditer(d):
        off=m.start()
        v=None; seg=None
        for im in imgs:
            for la,ln,fo in im['segs']:
                if fo<=off<fo+ln:
                    v=la+(off-fo); seg=(la,ln); break
            if v is not None: break
        res.append((off,v,m.group().decode('ascii')))
    return res

def main(path):
    d=open(path,'rb').read()
    imgs=images(d)
    print(f'== {path}  {len(d)} bytes ==')
    for im in imgs:
        ad = None
        print(f"\nimage @0x{im['off']:x} entry=0x{im['entry']:08x} segs={im['n']} size={im['size']}")
        for la,ln,fo in im['segs']:
            kind='IROM' if 0x42000000<=la<0x44000000 else ('DROM' if 0x3C000000<=la<0x3E000000 else ('IRAM' if 0x40370000<=la<0x40400000 else ('DRAM' if 0x3FC00000<=la<0x3FE00000 else '?')))
            print(f"   seg load=0x{la:08x} len={ln:#7x} file=0x{fo:06x} {kind}")
        desc=app_desc(d,[im])
        if desc: print('   app_desc:',json.dumps(desc,ensure_ascii=False))
    for off in range(0,min(len(d),0x20000),0x1000):
        pt=parttable(d,off)
        if pt:
            print(f"\npartition table @0x{off:x}")
            print(f"   {'name':12} {'type':6} {'sub':10} {'offset':>10} {'size':>10}")
            for e in pt:
                t=TYPES.get(e['type'],str(e['type']))
                st=(APP_SUB.get(e['sub']) if e['type']==0 else DATA_SUB.get(e['sub'])) or hex(e['sub'])
                print(f"   {e['name']:12} {t:6} {st:10} 0x{e['off']:08x} {e['size']:>10}")
    ss=strings(d,imgs)
    print(f"\nstrings total={len(ss)}")
    json.dump([{'off':o,'vaddr':(hex(v) if v is not None else None),'s':s} for o,v,s in ss],
              open(path+'.strings.json','w',encoding='utf8'),ensure_ascii=False,indent=0)

if __name__=='__main__': main(sys.argv[1])
