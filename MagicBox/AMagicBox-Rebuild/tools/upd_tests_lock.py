p="verification/regress/test_protocol.py"
t=open(p,encoding="utf-8").read()
if "lock_ml()" not in t:
    t=t.replace("""    # cmd_silent (0x19) with two arguments does answer
    ('.km.silent(0,0)', b'silent(0,0)'),""",
"""    # cmd_silent (0x19) with two arguments does answer
    ('.km.silent(0,0)', b'silent(0,0)'),
    # lock family queries (0x01 / 0x03) on a fresh device: all slots zero
    ('.km.lock_ml()', b'lock_ml()\\n0'),
    ('.km.lock_mx()', b'lock_mx()\\n0'),
    # cmd_catch_query (0x0B): channel off -> 0
    ('.km.catch_ml()', b'catch_ml()\\n0'),""")
    t=t.replace("""    '.km.lock_mx()',       # lock family: not ported in the rebuild yet""",
"""    '.km.lock_ml(1)',      # set channel flag (writes +0x54), echo only
    '.km.lock_ml(0)',      # clear + catch_set(0) + dirty=0, echo only
    '.km.lock_mx(1)',      # set axis byte (+0x9C), echo only
    '.km.lock_my(0)',      # clear axis byte (+0x9D), echo only
    '.km.left(1)',         # press form (0x04), echo only""")
    open(p,"w",encoding="utf-8").write(t)
print("tests updated")
