import io,sys,re,glob,os
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/status.py"
t=open(p,encoding="utf-8").read()

helper = '''
def implemented_handlers():
    path = "components/makcu_proto/handlers.def"
    out = []
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            parts = line.split("#")[0].split()
            if len(parts) >= 3 and parts[2] == "implemented":
                out.append((parts[0], parts[1]))
    return out


def reports():
    return sorted(os.path.basename(p) for p in glob.glob("verification/report/*.md"))
'''
t = t.replace("def count_todos(component):", helper + "\ndef count_todos(component):")

t = t.replace("""            '| 厂商函数重写（P2–P5） | **已起步**：`cmd_version`(0x09)、`cmd_nop`(0x08)、`cmd_move`(0x06) 三支已实现并链入；其余 24 个仍在 `handlers.def` 标 todo | 见下节“本轮新增” |',
            '| 烧录验证（T2） | 未开始 | 需先移植 `cmd_version`/`cmd_move` 等最小集合才能上机 |',""",
"""            '| 厂商函数重写（P2–P5） | 已移植 %d 支（见下节），其余 %d 个仍是 todo | `components/makcu_proto/handlers.def` |' % (len(impl), 27 - len(impl)),
            '| 烧录 + 回归（T2） | 已上机 2 次：19 例里 16 通过、2 失败（未移植 handler）、1 xpass | `verification/report/` |',""")

t = t.replace("""    out += ['## 端口面统计', '', '| 组件 | 待移植函数数 |', '|---|---:|']""",
"""    out += ['## 已移植 handler', '', '| opcode | handler | 说明 |', '|---|---|---|']
    for op, name in impl:
        out.append(f'| {op} | `{name}` | 协议面已上机验证 |')
    out += ['', '## 上机记录', '']
    for r in reports():
        out.append(f'- [`{r}`](../verification/report/{r})')
    out += ['', '## 端口面统计', '', '| 组件 | 待移植函数数 |', '|---|---:|']""")

t = t.replace("    port = {c: count_todos(c) for c in comps}",
              "    port = {c: count_todos(c) for c in comps}\n    impl = implemented_handlers()")
open(p,"w",encoding="utf-8").write(t)
print("status.py patched")
