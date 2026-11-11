#!/usr/bin/env python3
"""Build a readable source tree from raw Ghidra decompilation dumps (v3).

Layout:
  reversed/src/<image>/<module>/<entry>_<name>.c   one function per file
  reversed/include/re_types.h
  reversed/docs/function_index.md, module_map.md
  reversed/README.md
Module assignment: pinned seeds + label propagation over the call graph.
"""
import csv, glob, os, re, shutil, sys, io, collections, json, random

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from symbol_names import all_names

CURATED = all_names()


def rename_text(text, side):
    for addr, (new, _why) in CURATED[side].items():
        text = re.sub(r'\bFUN_' + addr + r'\b', new, text)
    return text


def display_name(side, addr, fallback):
    return CURATED[side].get(addr, (fallback, ''))[0]


UNREACH_RE = re.compile(r'^/\* WARNING: Removing unreachable block \(ram,0x[0-9a-f]+\) \*/$')


def collapse_warnings(text):
    """Collapse per-block decompiler warnings into one summary line."""
    out, run = [], 0
    for line in text.splitlines():
        if UNREACH_RE.match(line.strip()):
            run += 1
            continue
        if run:
            out.append(f'/* ({run} unreachable decompiler blocks omitted) */')
            run = 0
        out.append(line)
    if run:
        out.append(f'/* ({run} unreachable decompiler blocks omitted) */')
    return '\n'.join(out)


ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW = {'left': os.path.join(ROOT, 'reversed', 'raw_left'),
       'right': os.path.join(ROOT, 'reversed', 'raw_right')}
OUT = os.path.join(ROOT, 'reversed')

IDF_FAMILY = [
    ('xTask', 'freertos'), ('vTask', 'freertos'), ('xQueue', 'freertos'),
    ('xSemaphore', 'freertos'), ('xTimer', 'freertos'), ('prv', 'freertos'),
    ('esp_timer', 'esp_timer'), ('heap_', 'heap'), ('tlsf', 'heap'),
    ('multi_heap', 'heap'), ('esp_', 'esp_system'), ('panic', 'esp_system'),
    ('core_dump', 'esp_system'), ('intr_', 'esp_system'), ('clk_', 'esp_system'),
    ('rtc_', 'esp_system'), ('cache', 'esp_system'), ('hal_', 'hal'),
    ('ll_', 'hal'), ('soc_', 'hal'), ('regi2c', 'hal'), ('uart_', 'uart'),
    ('gpio_', 'gpio'), ('spi_', 'spi'), ('flash_', 'spi_flash'), ('nvs_', 'nvs'),
    ('vfs_', 'vfs'), ('newlib', 'newlib'), ('pthread', 'newlib'),
    ('syscall', 'newlib'), ('crc', 'crc'), ('tinyusb', 'usb'), ('tusb', 'usb'),
    ('dwc', 'usb'), ('hcd_', 'usb'), ('usb_', 'usb'), ('pp_', 'usb'),
    ('mbedtls', 'mbedtls'), ('lwip', 'lwip'), ('wifi', 'wifi'), ('bt_', 'bt'),
    ('nimble', 'bt'), ('emac', 'net'), ('gdma', 'dma'), ('rmt_', 'rmt'),
    ('ledc_', 'ledc'), ('i2c_', 'i2c'), ('adc_', 'adc'), ('timer_', 'timer'),
    ('pcnt_', 'pcnt'), ('sdmmc', 'sdmmc'), ('jtag', 'debug'),
    ('app_trace', 'debug'), ('perfmon', 'debug'),
]

SEEDS = {
    'left': {
        'protocol': ['4200eec4', '4200ef18', '4200e024', '4200e358', '4200dba0',
                     '4200e56c', '4200e624', '4200e6f0', '4200e718', '4200e998',
                     '4200e9d0', '4200ea04', '4200eb1c', '4200ec48', '4200ed74',
                     '4200de80', '4200e1b0', '4200ddbc', '4200dc6c'],
        'keyboard': ['42010e70', '42010f00', '42010f8c', '42010fdc', '42011098',
                     '420110b4', '420110d0'],
        'mouse':    ['4200f83c', '4200f848', '4200f8e4', '42010bc4', '42010b60',
                     '4200efec', '4200f744', '4200f96c', '42010bec'],
        'hid':      ['42013af9', '420139e4', '4201455c', '420145b5', '42013ae2'],
        'uart':     ['420142a0', '4201423c', '42014369', '42014393', '420143e8'],
        'led':      ['42012a74', '42012aeb'],
        'efuse':    ['42011188', '420111a5'],
        'crash':    ['42012b50'],
    },
    'right': {
        'host_usb': ['4200f208', '4200f3f7', '42010184', '4200d9ad', '42010184'],
        'uart':     ['4200f6a1', '42010700', '42010800'],
        'led':      ['42001198', '42010397'],
    },
}

STR_MARKERS = [
    ('MAKCU 2024', 'protocol'), ('buttons(', 'protocol'), ('lock_m', 'protocol'),
    ('catch_m', 'protocol'), ('move(', 'protocol'), ('wheel(', 'protocol'),
    ('Bezier', 'mouse'), ('Mouse_Commit', 'mouse'), ('MouseCommitTask', 'mouse'),
    ('HID report descriptor', 'hid'), ('Spoofed', 'hid'), ('Serial: %s', 'hid'),
    ('UART0', 'uart'), ('setupUart0', 'uart'),
    ('USB_PHY_SEL', 'efuse'), ('UART_PRINT_CONTROL', 'efuse'),
    ('LedFlashTask', 'led'), ('led_init', 'led'),
    ('COREDUMP', 'crash'), ('crash_dump', 'crash'),
]


def safe(name):
    return re.sub(r'[^A-Za-z0-9_.-]', '_', name)


def load(side):
    raw = RAW[side]
    idx = {}
    with open(os.path.join(raw, '_index.csv'), encoding='utf-8') as fh:
        for row in csv.DictReader(fh):
            idx[row['entry'].strip()] = row
    edges = []
    with open(os.path.join(raw, '_edges.csv'), encoding='utf-8') as fh:
        next(fh)
        for line in fh:
            a, _, b = line.strip().partition(',')
            if a and b and a in idx and b in idx:
                edges.append((a, b))
    return idx, edges


def idf_family(name):
    for prefix, fam in IDF_FAMILY:
        if name.startswith(prefix):
            return fam
    return None


def propagate(idx, edges, seeds):
    adj = collections.defaultdict(list)
    for a, b in edges:
        adj[a].append(b)
        adj[b].append(a)
    label = {}
    for e, row in idx.items():
        fam = idf_family(row['name'])
        if fam:
            label[e] = 'idf/' + fam
    for mod, entries in seeds.items():
        for e in entries:
            if e in idx:
                label[e] = mod
    for e, row in idx.items():
        if e in label:
            continue
        s = row.get('strings') or ''
        for marker, mod in STR_MARKERS:
            if marker in s:
                label[e] = mod
                break
    # label propagation, IDF labels pinned
    pinned = set(e for e, l in label.items() if l.startswith('idf/'))
    pinned |= set(e for l in seeds.values() for e in l)
    nodes = [e for e in idx if e not in label]
    nodes.sort()
    rnd = random.Random(20261109)
    for _ in range(12):
        rnd.shuffle(nodes)
        changed = 0
        for n in nodes:
            cnt = collections.Counter()
            for nb in adj[n]:
                if nb in label:
                    cnt[label[nb]] += 1
            if not cnt:
                continue
            best, _n = cnt.most_common(1)[0]
            if label.get(n) != best:
                label[n] = best
                changed += 1
        if changed == 0:
            break
    # BFS through still-unlabelled nodes so leaves inherit the nearest labelled module
    frontier = [n for n in idx if n in label]
    while frontier:
        nxt = []
        for n in frontier:
            for nb in adj[n]:
                if nb not in label:
                    label[nb] = label[n]
                    nxt.append(nb)
        frontier = nxt
    for e in idx:
        label.setdefault(e, 'misc')

    # isolated functions (no call edges at all): inherit from the nearest labelled
    # function by address, since the linker keeps related code close together
    import bisect
    labelled = sorted((int(e, 16), l) for e, l in label.items() if l != 'misc')
    if labelled:
        addrs = [a for a, _ in labelled]
        for e in list(label):
            if label[e] != 'misc':
                continue
            a = int(e, 16)
            i = bisect.bisect_left(addrs, a)
            cand = []
            if i < len(addrs):
                cand.append(labelled[i])
            if i > 0:
                cand.append(labelled[i - 1])
            best = min(cand, key=lambda t: abs(t[0] - a))
            label[e] = best[1]
    return label


def main():
    os.makedirs(os.path.join(OUT, 'include'), exist_ok=True)
    os.makedirs(os.path.join(OUT, 'docs'), exist_ok=True)
    index_rows = []
    summary = {}
    for side in ('left', 'right'):
        idx, edges = load(side)
        label = propagate(idx, edges, SEEDS[side])
        groups = collections.defaultdict(list)
        for e, row in idx.items():
            groups[label[e]].append((int(e, 16), e, row))
        side_dir = os.path.join(OUT, 'src', side)
        if os.path.isdir(side_dir):
            for d in os.listdir(side_dir):
                p = os.path.join(side_dir, d)
                if os.path.isdir(p):
                    for f in os.listdir(p):
                        os.remove(os.path.join(p, f))
                    os.rmdir(p)
                else:
                    os.remove(p)
        for mod, items in sorted(groups.items()):
            mod_dir = os.path.join(side_dir, mod.replace('idf/', 'idf_'))
            os.makedirs(mod_dir, exist_ok=True)
            items.sort()
            disp = {}
            for _, e, row in items:
                lines = open(os.path.join(RAW[side], row['file']), encoding='utf-8').read().splitlines()
                body = [l for l in lines if not (l.startswith('// ') and ' size=' in l)]
                text = rename_text('\n'.join(body).strip() + '\n', side)
                text = collapse_warnings(text)
                name = display_name(side, e, row['name'])
                disp[e] = name
                fname = os.path.join(mod_dir, f'{e}_{safe(name)}.c')
                with open(fname, 'w', encoding='utf-8') as fh:
                    fh.write(text)
                index_rows.append((side, mod, e, name, row['size'],
                                   row['callers'], row['callees'], row.get('strings', '')))
            with open(os.path.join(mod_dir, '_README.md'), 'w', encoding='utf-8') as fh:
                fh.write(f'# {side} / {mod}\n\n{len(items)} functions, sorted by address.\n\n')
                fh.write('| entry | name | size | callers | callees |\n|---|---|---:|---:|---:|\n')
                for _, e, row in items:
                    fh.write(f'| `{e}` | `{disp[e]}` | {row["size"]} | {row["callers"]} | {row["callees"]} |\n')
        summary[side] = {m: len(v) for m, v in groups.items()}
        print(side, json.dumps(summary[side], ensure_ascii=False))

    # hand-written reconstructions for functions Ghidra cannot model at all
    # (jump-table-only entry points, undecodable LX7 instructions)
    for side in ('left', 'right'):
        for p in sorted(glob.glob(os.path.join(OUT, 'manual', side, '*', '*.c'))):
            mod = os.path.basename(os.path.dirname(p))
            fn = os.path.basename(p)
            entry, name = fn[:-2].split('_', 1)
            mod_dir = os.path.join(OUT, 'src', side, mod.replace('idf/', 'idf_'))
            os.makedirs(mod_dir, exist_ok=True)
            shutil.copyfile(p, os.path.join(mod_dir, fn))
            index_rows.append((side, mod, entry, name, 'manual', '', '', 'hand reconstruction'))
        if glob.glob(os.path.join(OUT, 'manual', side, '*', '*.c')):
            print('manual reconstructions included:', side)

    with open(os.path.join(OUT, 'include', 're_types.h'), 'w', encoding='utf-8') as fh:
        fh.write("""/* Minimal type stubs so the reconstructed sources are readable in an editor.
 * This tree is NOT directly compilable: it is decompiler output, not original code. */
#ifndef RE_TYPES_H
#define RE_TYPES_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t  undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef uint8_t  undefined;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef uint8_t  byte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef void     code;
typedef int      ssize_t_re;

#endif
""")

    by_mod = collections.defaultdict(list)
    for r in index_rows:
        by_mod[(r[0], r[1])].append(r)
    with open(os.path.join(OUT, 'docs', 'function_index.md'), 'w', encoding='utf-8') as fh:
        fh.write('# Function index\n\nGenerated from Ghidra decompilation. `entry` is the virtual address.\n\n')
        for (side, mod), rows in sorted(by_mod.items()):
            fh.write(f'## {side} / {mod} ({len(rows)})\n\n')
            fh.write('| entry | name | size | callers | callees | strings |\n|---|---|---:|---:|---:|---|\n')
            for _, _, e, name, size, nc, nce, strs in rows:
                s = (strs or '')[:60].replace('|', '\\|')
                fh.write(f'| `{e}` | `{name}` | {size} | {nc} | {nce} | {s} |\n')
            fh.write('\n')

    with open(os.path.join(OUT, 'docs', 'module_map.md'), 'w', encoding='utf-8') as fh:
        fh.write('# Module map\n\nAssignment: pinned seeds + label propagation over the call graph.\n')
        fh.write('Counts include the hand reconstructions under `manual/`.\n')
        for side in ('left', 'right'):
            fh.write(f'\n## {side}\n\n| module | functions |\n|---|---:|\n')
            counts = collections.Counter(m for s, m, *_ in index_rows if s == side)
            for m, c in sorted(counts.items(), key=lambda kv: -kv[1]):
                fh.write(f'| {m} | {c} |\n')
            fh.write(f'\n**total {sum(counts.values())}**\n')

    make_headers(index_rows)
    make_scaffold(summary)
    print('total functions:', len(index_rows))


def parse_proto(text, name):
    """Best-effort prototype for `name`.

    Compiler output is not a declaration: the return type may sit on the line
    above, the parameter list may span lines, or the first hit may be a call
    site.  Anything unusable degrades to `void name(void);` — a prototype is
    documentation here, not a contract.
    """
    parent = re.escape(name) + r'[ \t]*\('
    m = None
    for m in re.finditer(r'^[ \t]*([A-Za-z_][\w \t\*]*?)[ \t]+' + parent, text, re.M):
        pass
    prefix = ''
    start = None
    if m is not None:
        prefix = m.group(1).strip() + ' '
        start = m.start(1)
    else:
        m2 = None
        for m2 in re.finditer(r'^[ \t]*' + parent, text, re.M):
            pass
        if m2 is None:
            return f'void {name}(void);'
        start = m2.start()
        above = text[:start].rstrip('\n').split('\n')[-1].strip()
        if re.fullmatch(r'[A-Za-z_][\w \t\*]*', above) and len(above) < 40 \
                and above not in ('return', 'else', 'do'):
            prefix = above + ' '
    seg = text[start:]
    idx = seg.find(name + '(')
    if idx < 0:
        return f'void {name}(void);'
    depth, i = 0, idx + len(name)
    while i < len(seg):
        c = seg[i]
        if c == '(':
            depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0:
                break
        i += 1
    if depth != 0 or i >= len(seg):
        return f'void {name}(void);'
    sig = re.sub(r'\s+', ' ', prefix + seg[idx:i + 1]).strip()
    if not re.match(r'^[A-Za-z_]', sig) or sig.split()[0] in ('return', 'if', 'while'):
        return f'void {name}(void);'
    return sig + ';'


def make_headers(index_rows):
    inc = os.path.join(OUT, 'include')
    os.makedirs(inc, exist_ok=True)
    rawidx = {}
    for side in ('left', 'right'):
        rawidx[side] = {r['entry']: r for r in csv.DictReader(
            open(os.path.join(RAW[side], '_index.csv'), encoding='utf-8'))}
    by_mod = collections.defaultdict(list)
    for side, mod, entry, name, size, nc, nce, strs in index_rows:
        by_mod[(side, mod)].append((entry, name))
    written = 0
    for (side, mod), items in sorted(by_mod.items()):
        guard = 'RE_' + re.sub(r'[^A-Za-z0-9]', '_', side + '_' + mod).upper() + '_H'
        path = os.path.join(inc, f're_{side}_{re.sub(r"[^A-Za-z0-9]", "_", mod)}.h')
        externs = set()
        protos = []
        for entry, name in sorted(items):
            raw_row = rawidx[side].get(str(entry))
            if not raw_row:
                protos.append(f'void {name}(void);')
                continue
            raw = os.path.join(RAW[side], raw_row['file'])
            try:
                text = open(raw, encoding='utf-8').read()
            except Exception:
                protos.append(f'void {name}(void);')
                continue
            protos.append(rename_text(parse_proto(text, raw_row['name']), side))
            cand = re.findall(r'\b(?:DAT|PTR)_[A-Za-z0-9_]+', text)
            externs.update(c for c in cand if re.search(r'[0-9a-f]{6,}$', c))
        with open(path, 'w', encoding='utf-8') as fh:
            fh.write(f'/* prototypes for {side}/{mod} - generated from decompiled bodies, not original headers */\n')
            fh.write(f'#ifndef {guard}\n#define {guard}\n\n#include "re_types.h"\n\n')
            for e in sorted(externs)[:400]:
                fh.write(f'extern undefined4 {e};\n')
            fh.write('\n')
            for p in protos:
                fh.write(p + '\n')
            fh.write(f'\n#endif /* {guard} */\n')
        written += 1
    print('headers written:', written)


def make_scaffold(summary):
    with open(os.path.join(OUT, 'CMakeLists.txt'), 'w', encoding='utf-8') as fh:
        fh.write("""# Navigation scaffold only.
# The sources under src/ are Ghidra decompiler output: they have no original
# headers, no original types and no linkable runtime. This file exists so IDEs
# and code browsers can enumerate the reconstructed translation units, not to
# produce a firmware image.

cmake_minimum_required(VERSION 3.16)
project(makcu_reversed C)

file(GLOB_RECURSE RE_SOURCES CONFIGURE_DEPENDS "src/*/*.c")
add_custom_target(re_sources SOURCES ${RE_SOURCES})
""")
    with open(os.path.join(OUT, 'docs', 'headers.md'), 'w', encoding='utf-8') as fh:
        fh.write('# Headers\n\n')
        fh.write('`include/re_types.h` provides the width-ambiguous type stubs used by the\n')
        fh.write('decompiler output (`undefined1/2/4/8`, `undefined`, `longlong`, `byte`,\n')
        fh.write('`ushort`, `uint`, `code`, plus `<stdbool.h>` for the `bool` returns Ghidra\n')
        fh.write('produces).\n\n')
        fh.write('`include/re_<image>_<module>.h` holds one prototype per function in that\n')
        fh.write('module plus `extern undefined4` declarations for the `DAT_`/`PTR_` globals\n')
        fh.write('the module touches. They are generated from the decompiled bodies, so a\n')
        fh.write('prototype is only as accurate as Ghidra\'s parameter recovery.\n\n')
        fh.write('## 1. 生成方式\n\n')
        fh.write('`tools/build_project.py::make_headers()` 按模块聚合函数入口与名字，再从\n')
        fh.write('`reversed/raw_<side>/<entry>_<name>.c` 里还原原型。反编译产物不是声明，\n')
        fh.write('所以做了三件事：\n\n')
        fh.write('1. 返回类型可能单独占一行（`undefined4` + 换行 + `FUN_xxx(...)`），取上一行；\n')
        fh.write('2. 参数表可能跨行，按括号配对后压成一行；\n')
        fh.write('3. 若只找到调用点或解析不完整，退化为 `void name(void);`。\n\n')
        fh.write('## 2. 语法检查（2026-11-09）\n\n')
        fh.write('用官方工具链真编译头文件（不链接、不看语义，只看声明是否自洽）：\n\n')
        fh.write('```powershell\n')
        fh.write("$gcc = 'D:\\Apply\\toolchains\\xtensa-esp-elf\\bin\\xtensa-esp32s3-elf-gcc.exe'\n")
        fh.write('foreach ($h in Get-ChildItem reversed\\include\\*.h) {\n')
        fh.write('    & $gcc -fsyntax-only -std=c99 -I reversed\\include -xc $h.FullName\n')
        fh.write('}\n```\n\n')
        fh.write('| 轮次 | 失败头文件 | 原因 |\n|---|---:|---|\n')
        fh.write('| 首次 | 16 / 27 | `bool` 未定义、`undefined`/`longlong` 缺 typedef、返回类型独占一行被漏掉 |\n')
        fh.write('| 补 typedef | 11 / 27 | 只剩“返回类型在上一行”这一类 |\n')
        fh.write('| 修原型解析 | **0 / 27** | — |\n\n')
        fh.write('结论：26 个模块头 + `re_types.h` 全部通过 `-fsyntax-only`。这**不等于**\n')
        fh.write('源码树可编译：`src/*.c` 是反编译输出，没有原始头文件依赖、类型与链接信息。\n\n')
        fh.write('## 3. 参数可信度\n\n')
        fh.write('| 现象 | 影响 | 依据 |\n|---|---|---|\n')
        fh.write('| 参数个数可能偏少 | 有些原型只列出被用到的前几个参数 | Ghidra 按调用点恢复 |\n')
        fh.write('| 返回类型宽度不确定 | `undefined4` 可能实际是 `int`/指针 | 宽度推断 |\n')
        fh.write('| 同一函数在不同调用点签名不同 | 跳表调用（`callx8`）绕过原型检查 | `cmd_*` handler 走跳表 |\n')
        fh.write('| 手工重建的 2 个函数 | 原型由反汇编手写，比生成版更可靠 | `reversed/manual/` |\n')


if __name__ == '__main__':
    main()
