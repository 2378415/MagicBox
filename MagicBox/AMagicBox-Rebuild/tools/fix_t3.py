p="tools/t3_report.py"
t=open(p,encoding="utf-8").read()
t=t.replace("sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')\n","")
open(p,"w",encoding="utf-8").write(t)
print("removed duplicate stdout wrapper")
