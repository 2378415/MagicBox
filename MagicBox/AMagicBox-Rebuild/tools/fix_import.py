p="tools/diff_insn.py"
t=open(p,encoding="utf-8").read()
if "import tempfile" not in t:
    t=t.replace("import subprocess","import subprocess\nimport tempfile")
    open(p,"w",encoding="utf-8").write(t)
print("tempfile import added" if "import tempfile" in open(p,encoding="utf-8").read() else "fail")
