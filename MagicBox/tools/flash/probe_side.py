# -*- coding: utf-8 -*-
"""读取设备 flash 片段，与 LEFT/RIGHT 官方镜像比对，判定当前连的是哪一片。"""
import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
IMAGES = {
    "LEFT V3.2": os.path.join(ROOT, "官方固件", "V3.2_LEFT.bin"),
    "RIGHT V3.7": os.path.join(ROOT, "官方固件", "V3.7_RIGHT.bin"),
}


def load(p):
    with open(p, "rb") as f:
        return f.read()


def main():
    probe_path = sys.argv[1]
    off = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x10000
    probe = load(probe_path)
    print(f"probe: {probe_path}  bytes={len(probe)}  flash_off=0x{off:x}")
    print(f"probe sha256: {__import__('hashlib').sha256(probe).hexdigest()}")
    best = None
    for name, path in IMAGES.items():
        img = load(path)
        seg = img[off:off + len(probe)]
        n = min(len(seg), len(probe))
        if n == 0:
            continue
        same = sum(1 for a, b in zip(seg[:n], probe[:n]) if a == b)
        ratio = same / n
        # 首个不同字节偏移
        first_diff = next((i for i in range(n) if seg[i] != probe[i]), None)
        print(f"{name:10s} match {same}/{n} = {ratio:.2%}  first_diff={('0x%x' % first_diff) if first_diff is not None else 'none'}")
        if best is None or ratio > best[1]:
            best = (name, ratio)
    if best:
        print(f"判定: {best[0]}  (匹配度 {best[1]:.2%})")


if __name__ == "__main__":
    main()
