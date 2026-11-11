import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
# 把交接文档挂到状态页与 README 处，方便接手人第一眼看到
p="docs/40-status.md"
t=open(p,encoding="utf-8").read()
if "HANDOVER.md" not in t:
    lines=t.splitlines()
    lines.insert(0,"> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）\n")
    open(p,"w",encoding="utf-8").write("\n".join(lines)+"\n")

p="tools/status.py"
s=open(p,encoding="utf-8").read()
if "HANDOVER.md" not in s:
    s=s.replace('    out = []','    out = ["> 接手先读：[HANDOVER.md](HANDOVER.md)（一句话现状 / 操作手册 / 坑位清单）", ""]',1)
    open(p,"w",encoding="utf-8").write(s)
print("README 指针已加")
