import os, glob, re, io, sys, csv
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, 'reversed')
rows = []
for side in ('left', 'right'):
    for path in glob.glob(os.path.join(OUT, 'src', side, '*', '*.c')):
        txt = open(path, encoding='utf-8', errors='replace').read()
        if 'halt_baddata' in txt:
            m = re.match(r'([0-9a-f]+)_', os.path.basename(path))
            rows.append((side, os.path.basename(os.path.dirname(path)), m.group(1) if m else '', os.path.basename(path)))
rows.sort()
with open(os.path.join(OUT, 'docs', 'known_gaps.md'), 'w', encoding='utf-8') as fh:
    fh.write('# Known decompilation gaps\n\n')
    fh.write('These functions hit a pcode/construct error in Ghidra\'s Xtensa module\n')
    fh.write('(usually the `excw` errata instruction or a literal pool inside the body).\n')
    fh.write('They decompile to `halt_baddata()` and need the objdump fallback:\n\n')
    fh.write('```powershell\nxtensa-esp-elf-objdump -D -b binary -m xtensa --adjust-vma=0x42000020 \\\n')
    fh.write('  --start-address=0x<entry> --stop-address=0x<end> work\\irom.bin\n```\n\n')
    fh.write(f'Total: {len(rows)}\n\n| image | module | entry | file |\n|---|---|---|---|\n')
    for side, mod, entry, name in rows:
        fh.write(f'| {side} | {mod} | `0x{entry}` | {name} |\n')
print('gaps:', len(rows))
