p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_clone_apply_fixture" not in t:
    t=t.replace('#include "makcu_link_bridge.h"','#include "makcu_link_bridge.h"\n#include "makcu_clone.h"')
    t=t.replace("""    if (len >= 6 && line[3] == 'l' && line[4] == 'b' && line[5] == '0') {""","""    if (len >= 5 && line[3] == 'c' && line[4] == 'l') {
        /* clone fixture: mx.cl (default A) / mx.cl <1|2> / mx.cc to clear */
        int which = MAKCU_CLONE_FIXTURE_MOUSE_A;
        if (len > 6 && line[6] >= '1' && line[6] <= '2') {
            which = line[6] - '0';
        }
        const bool ok = makcu_clone_apply_fixture(which);
#if MB_HID_DEVICE
        makcu_hiddev_rebind();
#endif
        const makcu_clone_t *c = makcu_clone_get();
        char out[32];
        const int n = snprintf(out, sizeof(out), "%d:%02x%02x:%02x%02x",
                               ok ? 1 : 0, c->device[9], c->device[8],
                               c->device[11], c->device[10]);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'c' && line[4] == 'c') {
        makcu_clone_clear();
#if MB_HID_DEVICE
        makcu_hiddev_rebind();
#endif
        makcu_reply("0", 1);
        return 1;
    }
    if (len >= 6 && line[3] == 'l' && line[4] == 'b' && line[5] == '0') {""")
    open(p,"w",encoding="utf-8").write(t)
print("mx.cl / mx.cc wired")
