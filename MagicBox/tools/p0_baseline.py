#!/usr/bin/env python3
"""P0 baseline: how close is each rebuilt handler to the original binary?

Why this exists
---------------
The old metric counted *exact* instruction-sequence matches and reported 7/816
(0.9%).  That number says nothing useful: a rebuilt function will differ in
register allocation, literal-pool placement and branch offsets while still being
the same code.  This tool answers the question that actually matters:

    for every handler:  which ones are structurally equivalent, and how far off
                        are the ones that are not?

Method
------
  * original side: carve the handler's region out of the official image (sizes
    come from the gap to the next handler address) and disassemble it;
  * rebuilt side: take the same function from our own ELF by symbol name;
  * normalise both with tools/diff_insn.py's normaliser (mnemonics + operand
    shapes, addresses/immediates/labels folded away);
  * score = difflib ratio over the normalised sequences;
  * bucket by original size, and report a size-parity hit rate separately, since
    "same size" is the precondition for a bit-level match.

Usage
-----
    python tools/p0_baseline.py                       # default paths
    python tools/p0_baseline.py --json out/p0.json --md out/p0.md
    python tools/p0_baseline.py --threshold 0.85 --verbose
"""
import argparse
import difflib
import json
import os
import re
import subprocess
import sys
import io

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

import diff_insn  # noqa: E402  (sibling module: carves/disassembles/normalises)

DEFAULT_IMAGE = r"D:\JinPeng\MagicBox\官方固件\V3.2_LEFT.bin"
DEFAULT_ELF = os.path.join(ROOT, "app_left", "build", "makcu_left.elf")

# Original handler addresses, transcribed from the header comment of each
# handler source (components/makcu_proto/src/*.c).  Keeping the table here makes
# the report reproducible without re-parsing comments; update both together.
HANDLERS = [
    (0x00, "cmd_lock_param0", 0x4200DECC),
    (0x01, "cmd_lock_query", 0x4200DE40),
    (0x02, "cmd_lock_param2", 0x4200DF08),
    (0x03, "cmd_lock_axis", 0x4200DE60),
    (0x04, "cmd_button_press", 0x4200DF30),
    (0x05, "cmd_button_click", 0x4200DFAC),
    (0x06, "cmd_move", 0x4200E024),
    (0x07, "cmd_wheel", 0x4200E358),
    (0x08, "cmd_nop", 0x4200DBA0),
    (0x09, "cmd_version", 0x4200DC6C),
    (0x0A, "cmd_catch_set", 0x4200DF58),
    (0x0B, "cmd_catch_query", 0x4200DFF0),
    (0x0C, "cmd_buttons", 0x4200DDBC),
    (0x0D, "cmd_key_down", 0x4200EC48),
    (0x0E, "cmd_key_up", 0x4200EB1C),
    (0x0F, "cmd_key_tap", 0x4200E9D0),
    (0x10, "cmd_set_string", 0x4200DE80),
    (0x11, "cmd_key_state", 0x4200ED74),
    (0x12, "cmd_keys_down", 0x4200E6F0),
    (0x13, "cmd_keys_up", 0x4200E718),
    (0x14, "cmd_keys_combo", 0x4200E998),
    (0x15, "cmd_map_16", 0x4200EA04),
    (0x16, "cmd_map_entry", 0x4200E624),
    (0x17, "cmd_dump_channels", 0x4200DBB0),
    (0x18, "cmd_channel_toggle", 0x4200E56C),
    (0x19, "cmd_silent", 0x4200E1B0),
    (0x1A, "cmd_serial", 0x4200DC84),
]

INSN_LINE = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+)\s+(\S+)(.*)$")


def find_objdump():
    """Locate xtensa-esp-elf-objdump.exe (same probing order as diff_insn)."""
    for env in ("MAKCU_TOOLCHAIN_BIN",):
        if os.environ.get(env):
            cand = os.path.join(os.environ[env], "xtensa-esp-elf-objdump.exe")
            if os.path.isfile(cand):
                return cand
    for base in (r"D:\esp-tools\tools\xtensa-esp-elf", r"D:\Apply\toolchains"):
        if not os.path.isdir(base):
            continue
        for root, _dirs, files in os.walk(base):
            if "xtensa-esp-elf-objdump.exe" in files:
                return os.path.join(root, "xtensa-esp-elf-objdump.exe")
    return None


def disasm_elf_functions(objdump, elf):
    """symbol -> list of instruction text (mnemonic + operands)."""
    out = subprocess.run([objdump, "-d", "--no-show-raw-insn", elf],
                         capture_output=True, text=True, errors="replace").stdout
    funcs = {}
    current = None
    for line in out.splitlines():
        m = re.match(r"^([0-9a-f]+) <([^>]+)>:$", line.strip())
        if m:
            current = m.group(2)
            funcs[current] = []
            continue
        if current is None:
            continue
        im = diff_insn.LINE_RE.match(line)
        if im:
            mn, args = im.group(2), (im.group(3) or "").split(";")[0].strip()
            funcs[current].append(f"{mn} {args}".strip())
    return {k: v for k, v in funcs.items() if v}


def original_regions(image):
    """name -> (addr, size) using the gap to the next handler address."""
    addrs = sorted(a for _op, _n, a in HANDLERS)
    regions = {}
    for _op, name, addr in HANDLERS:
        later = [a for a in addrs if a > addr]
        end = later[0] if later else addr + 0x400
        regions[name] = (addr, end - addr)
    return regions


def best_window_ratio(orig, mine):
    """Best difflib ratio of `mine` against any same-length window of `orig`.

    The original region is guessed from the gap to the next handler address, which
    often includes trailing helper code.  Comparing the full sequences therefore
    understates equivalence; sliding a window of our length finds the handler body
    wherever it sits inside the region.
    """
    n = len(mine)
    if n == 0 or len(orig) < n:
        return difflib.SequenceMatcher(None, orig, mine).ratio(), 0
    best, best_at = -1.0, 0
    sm = difflib.SequenceMatcher(None, autojunk=False)
    for at in range(0, len(orig) - n + 1):
        sm.set_seq2(mine)
        sm.set_seq1(orig[at:at + n])
        r = sm.ratio()
        if r > best:
            best, best_at = r, at
    return best, best_at


def bucket_of(size):
    if size <= 0x40:
        return "<=0x40"
    if size <= 0x100:
        return "0x41-0x100"
    if size <= 0x200:
        return "0x101-0x200"
    return ">0x200"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--image", default=DEFAULT_IMAGE)
    ap.add_argument("--elf", default=DEFAULT_ELF)
    ap.add_argument("--json", default=os.path.join(ROOT, "verification", "p0_baseline.json"))
    ap.add_argument("--md", default=os.path.join(ROOT, "verification", "p0_baseline.md"))
    ap.add_argument("--close", type=float, default=0.50,
                    help="ratio for the 'close' tier")
    ap.add_argument("--threshold", type=float, default=0.70,
                    help="ratio >= threshold counts as structurally equivalent")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    for path in (args.image, args.elf):
        if not os.path.isfile(path):
            print(f"missing input: {path}")
            return 2
    objdump = find_objdump()
    if objdump is None:
        print("xtensa-esp-elf-objdump.exe not found")
        return 2

    ours = disasm_elf_functions(objdump, args.elf)
    regions = original_regions(args.image)

    rows = []
    for op, name, addr in HANDLERS:
        start, size = regions[name]
        orig_text = diff_insn.disasm_region(args.image, start, start + size)
        orig = diff_insn.normalise(orig_text) if orig_text else []
        mine = ours.get(name, [])
        # ours already holds "mnemonic operands" lines; run them through the same
        # normaliser by prefixing a fake address so LINE_RE matches.
        mine_text = "\n".join(f"0: {m}" for m in mine)
        mine_n = diff_insn.normalise(mine_text) if mine else []
        if not orig or not mine_n:
            rows.append({
                "opcode": op, "name": name, "orig_addr": hex(addr), "orig_size": size,
                "our_size": len(mine_n), "ratio": None,
                "verdict": "missing" if not mine_n else "no-original",
                "bucket": bucket_of(size),
            })
            continue
        ratio_full = difflib.SequenceMatcher(None, orig, mine_n).ratio()
        ratio_win, win_at = best_window_ratio(orig, mine_n)
        # size parity: within 25% of the original instruction count
        parity = abs(len(mine_n) - len(orig)) <= max(2, int(len(orig) * 0.25))
        rows.append({
            "opcode": op, "name": name, "orig_addr": hex(addr), "orig_size": size,
            "orig_insn": len(orig), "our_size": len(mine_n),
            "ratio": round(ratio_win, 4), "ratio_full": round(ratio_full, 4),
            "window_at": win_at, "size_parity": parity,
            "verdict": "equivalent" if ratio_win >= args.threshold else "diverged",
            "bucket": bucket_of(size),
        })

    scored = [r for r in rows if r.get("ratio") is not None]
    equivalent = [r for r in scored if r["verdict"] == "equivalent"]
    parity = [r for r in scored if r.get("size_parity")]

    close = [r for r in scored if r["ratio"] >= args.close]
    buckets = {}
    for r in scored:
        b = buckets.setdefault(r["bucket"], {"n": 0, "eq": 0, "sum": 0.0})
        b["n"] += 1
        b["sum"] += r["ratio"]
        if r["verdict"] == "equivalent":
            b["eq"] += 1

    summary = {
        "image": args.image,
        "elf": args.elf,
        "handlers": len(HANDLERS),
        "scored": len(scored),
        "equivalent": len(equivalent),
        "equivalent_pct": round(100.0 * len(equivalent) / len(scored), 1) if scored else 0.0,
        "close": len(close),
        "close_pct": round(100.0 * len(close) / len(scored), 1) if scored else 0.0,
        "close_threshold": args.close,
        "mean_ratio": round(sum(r["ratio"] for r in scored) / len(scored), 4) if scored else 0.0,
        "size_parity": len(parity),
        "size_parity_pct": round(100.0 * len(parity) / len(scored), 1) if scored else 0.0,
        "threshold": args.threshold,
        "buckets": {k: {"n": v["n"], "eq": v["eq"],
                        "mean": round(v["sum"] / v["n"], 4)} for k, v in sorted(buckets.items())},
        "missing": [r["name"] for r in rows if r["verdict"] in ("missing", "no-original")],
    }

    os.makedirs(os.path.dirname(args.json), exist_ok=True)
    with open(args.json, "w", encoding="utf-8") as fh:
        json.dump({"summary": summary, "handlers": rows}, fh, ensure_ascii=False, indent=2)

    lines = []
    lines.append("# P0 baseline - rebuilt handlers vs the official V3.2 image\n")
    lines.append(f"- image: `{os.path.basename(args.image)}`")
    lines.append(f"- elf:   `{os.path.relpath(args.elf, ROOT)}`")
    lines.append(f"- threshold: ratio >= {args.threshold}\n")
    lines.append("| metric | value |")
    lines.append("|---|---|")
    lines.append(f"| handlers scored | {summary['scored']} |")
    lines.append(f"| structurally equivalent | **{summary['equivalent']} "
                 f"({summary['equivalent_pct']}%)** |")
    lines.append(f"| close (ratio >= {args.close}) | {summary['close']} "
                 f"({summary['close_pct']}%) |")
    lines.append(f"| mean similarity ratio | {summary['mean_ratio']} |")
    lines.append(f"| instruction-count parity (<=25%) | {summary['size_parity']} "
                 f"({summary['size_parity_pct']}%) |")
    for k, v in summary["buckets"].items():
        lines.append(f"| bucket {k} | {v['eq']}/{v['n']} equivalent, mean {v['mean']} |")
    lines.append("\n| op | handler | addr | orig insn | ours | ratio(win) | ratio(full) | verdict |")
    lines.append("|---|---|---|---|---|---|---|---|")
    for r in rows:
        ratio = "-" if r.get("ratio") is None else f"{r['ratio']:.2f}"
        full = "-" if r.get("ratio_full") is None else f"{r['ratio_full']:.2f}"
        lines.append(f"| 0x{r['opcode']:02X} | `{r['name']}` | {r['orig_addr']} | "
                     f"{r.get('orig_insn', '-')} | {r['our_size']} | {ratio} | {full} | "
                     f"{r['verdict']} |")
    if summary["missing"]:
        lines.append("\nMissing / not comparable: " + ", ".join(summary["missing"]))
    text = "\n".join(lines) + "\n"
    with open(args.md, "w", encoding="utf-8") as fh:
        fh.write(text)

    print(text)
    if args.verbose:
        for r in rows:
            if r.get("ratio") is not None and r["verdict"] != "equivalent":
                print(f"  diverged: {r['name']} ratio={r['ratio']} "
                      f"orig={r['orig_insn']} ours={r['our_size']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
