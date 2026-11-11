p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
# mx.lb0 must be matched before mx.lb, otherwise the prefix branch wins
lb0 = """    if (len >= 6 && line[3] == 'l' && line[4] == 'b' && line[5] == '0') {
        makcu_link_set_loopback(false);
        makcu_reply("0", 1);
        return 1;
    }
"""
if lb0 in t:
    t = t.replace(lb0, "")
    anchor = "    if (len >= 5 && line[3] == 'l' && line[4] == 'b') {"
    t = t.replace(anchor, lb0 + anchor)
    open(p,"w",encoding="utf-8").write(t)
    print("mx.lb0 moved ahead of mx.lb")
else:
    print("lb0 block not found - check manually")
