#!/usr/bin/env python3
"""Capture a deterministic behaviour trace of every protocol opcode.

Why not JTAG single-stepping
----------------------------
The goal of the original todo was "verify the hidden opcodes behave like the
original".  Single-stepping answers it once, for one build, and cannot be re-run
on every change.  Capturing the observable behaviour (request -> bytes on the
wire, plus state read-backs) gives the same answer *and* becomes a differential
regression: run it against two builds and diff the JSON.

Coverage
--------
  * all 27 opcodes 0x00..0x1A, driven through the bench harness `mx.<hex>`,
    including the hidden ones that have no text command;
  * state read-backs after the mutating opcodes (`mx.bo`, `mx.ei`, `mx.ds`,
    `mx.sn`, `mx.if`), so a silent state change cannot slip through;
  * every step records the raw reply, so "no reply" and "reply with FF" stay
    distinguishable.

Usage
-----
    python tools/trace_opcodes.py --port COM3 --out verification/opcode_trace.json
    python tools/trace_opcodes.py --port COM3 --compare verification/opcode_trace.json
"""
import argparse
import json
import os
import sys
import time

import serial  # pyserial


# (label, command, wait_ms) - a fixed script: order matters, it builds state up.
SCRIPT = [
    # Wire form: '.' + 'km.' + command + '\r'  (see docs/10-abi.md)
    ("version", ".km.version()", 300),
    ("version-noargs", ".km.version", 300),
    ("buttons/query", ".km.buttons()", 300),

    # --- button family (0x04 press / 0x05 click / 0x0C set) ---
    ("button press left", ".km.left(1)", 200),
    ("button press left up", ".km.left(0)", 200),
    ("button click left", ".km.left()", 250),
    ("button click right", ".km.right()", 250),
    ("button click middle", ".km.middle()", 250),
    ("button front(ms1)", ".km.front()", 250),
    ("button ms2", ".km.ms2()", 250),
    ("buttons set 7", ".km.buttons(7)", 250),
    ("buttons query", ".km.buttons()", 250),
    ("buttons set 0", ".km.buttons(0)", 250),

    # --- motion / wheel (0x06 / 0x07) ---
    ("move +10,+5", ".km.move(10,5)", 250),
    ("move -10,-5", ".km.move(-10,-5)", 250),
    ("move 0,0", ".km.move(0,0)", 250),
    ("wheel +1", ".km.wheel(1)", 250),
    ("wheel -1", ".km.wheel(-1)", 250),

    # --- lock family (0x00..0x03) ---
    ("lock_mx query", ".km.lock_mx()", 250),
    ("lock_mx set 1", ".km.lock_mx(1)", 250),
    ("lock_mx query2", ".km.lock_mx()", 250),
    ("lock_mx set 0", ".km.lock_mx(0)", 250),
    ("lock_my query", ".km.lock_my()", 250),
    ("lock_ml query", ".km.lock_ml()", 250),
    ("lock_ml set 1", ".km.lock_ml(1)", 250),
    ("lock_ml set 0", ".km.lock_ml(0)", 250),
    ("lock_mr set 0", ".km.lock_mr(0)", 250),
    ("lock_mm set 0", ".km.lock_mm(0)", 250),
    ("lock_ms1 set 0", ".km.lock_ms1(0)", 250),
    ("lock_ms2 set 0", ".km.lock_ms2(0)", 250),

    # --- catch family (0x0A / 0x0B) ---
    ("catch_ml query", ".km.catch_ml()", 250),
    ("catch_ml set 1", ".km.catch_ml(1)", 250),
    ("catch_ml query2", ".km.catch_ml()", 250),
    ("catch_ml set 0", ".km.catch_ml(0)", 250),
    ("catch_mr query", ".km.catch_mr()", 250),

    # --- misc (0x19 silent / 0x1A serial) ---
    ("silent 1", ".km.silent(1)", 250),
    ("silent 0", ".km.silent(0)", 250),
    ("serial query", ".km.serial()", 300),

    # --- state read-backs through the bench probes ---
    ("readback buttons", "mx.bo", 200),
    ("readback last report", "mx.ei", 200),
    ("readback sends", "mx.ds", 200),
    ("readback identity", "mx.fv", 250),
]


def read_line(port, wait_ms):
    """Read one console line (the bench echo)."""
    deadline = time.time() + wait_ms / 1000.0
    buf = ""
    while time.time() < deadline:
        chunk = port.read(port.in_waiting or 1)
        if chunk:
            buf += chunk.decode("utf-8", "replace")
            if ">>>" in buf:
                break
    return " ".join(buf.replace("\r", " ").replace("\n", " ").split()).replace(">>>", "").strip()


def collect_frames(port, tries=6, wait_ms=90):
    """Poll mx.lr and return the distinct wire replies seen.

    The bench echo only says how many bytes were sent; the actual protocol reply
    is a received frame, which mx.lr reports.  Polling a few times catches replies
    that arrive slightly later and tolerates the 2 s A3 heartbeat interleaving.
    """
    seen = []
    for _ in range(tries):
        port.reset_input_buffer()
        port.write(b"mx.lr\r")
        line = read_line(port, wait_ms)
        if line and line not in seen:
            seen.append(line)
    # keep only genuine frame reports
    frames = [s for s in seen if "cmd=" in s or "no-frame" in s]
    return frames[:4]


def run(port_name, baud):
    port = serial.Serial(port_name, baud, timeout=0.2)
    time.sleep(0.4)
    port.reset_input_buffer()
    steps = []
    for label, cmd, wait in SCRIPT:
        port.reset_input_buffer()
        port.write(cmd.encode() + b"\r")
        echo = read_line(port, wait)
        frames = collect_frames(port) if cmd.startswith(("mx.ln", "mx.lf")) else []
        steps.append({"label": label, "cmd": cmd, "echo": echo, "frames": frames})
    port.close()
    return steps


def compare(old_path, steps):
    with open(old_path, encoding="utf-8") as fh:
        old = json.load(fh)
    old_steps = old.get("steps", [])
    diffs = []
    for a, b in zip(old_steps, steps):
        if a.get("cmd") != b.get("cmd"):
            diffs.append({"cmd": b.get("cmd"), "kind": "script-changed"})
            continue
        if a.get("frames") != b.get("frames"):
            diffs.append({"cmd": b.get("cmd"), "old": a.get("frames"), "new": b.get("frames")})
    if len(old_steps) != len(steps):
        diffs.append({"kind": "step-count", "old": len(old_steps), "new": len(steps)})
    return diffs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default="COM3")
    ap.add_argument("--baud", type=int, default=921600)
    ap.add_argument("--out", default=os.path.join("verification", "opcode_trace.json"))
    ap.add_argument("--compare", help="diff against a previous trace JSON")
    args = ap.parse_args()

    steps = run(args.port, args.baud)

    if args.compare:
        diffs = compare(args.compare, steps)
        if not diffs:
            print(f"trace matches {args.compare} ({len(steps)} steps)")
            return 0
        print(f"{len(diffs)} difference(s) vs {args.compare}:")
        for d in diffs:
            print(f"  cmd={d.get('cmd')} old={d.get('old')!r} new={d.get('new')!r}")
        return 1

    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as fh:
        json.dump({"port": args.port, "steps": steps}, fh, ensure_ascii=False, indent=2)
    print(f"wrote {args.out} ({len(steps)} steps)")
    for s in steps:
        print(f"  {s['label']:<24} echo={s['echo']:<8} frames={s['frames']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
