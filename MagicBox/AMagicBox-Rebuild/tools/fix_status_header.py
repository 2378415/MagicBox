p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace('''    out = ["> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）", ""]''','''    out = []''')
t=t.replace("""    open('docs/40-status.md', 'w', encoding='utf-8').write('\\n'.join(out))""","""    header = ['> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）', '']
    open('docs/40-status.md', 'w', encoding='utf-8').write('\\n'.join(header + out))""")
open(p,"w",encoding="utf-8").write(t)
print("status.py fixed")
