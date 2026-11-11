p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_keyboard_init" not in t:
    t=t.replace('#include "makcu_hiddev.h"','#include "makcu_hiddev.h"\n#include "makcu_keyboard.h"')
    t=t.replace("""#if MB_HID_DEVICE
    makcu_hiddev_init();
    makcu_hid_report_hook = makcu_hiddev_report;   /* reports go out over USB */
#endif""","""    makcu_keyboard_init();
#if MB_HID_DEVICE
    makcu_hiddev_init();
    makcu_hid_report_hook = makcu_hiddev_report;       /* mouse reports over USB */
    makcu_kbd_emit_hook = makcu_hiddev_kbd_report;     /* keyboard reports over USB */
#endif""")
    # mx.rk: dump the keyboard report ring
    t=t.replace("""    if (len >= 5 && line[3] == 'r' && line[4] == 'q') {""","""    if (len >= 5 && line[3] == 'r' && line[4] == 'k') {
        unsigned count = 0;
        const uint8_t *tr = makcu_keyboard_trace(&count);
        char out[MAKCU_KBD_TRACE * MAKCU_KBD_REPORT_LEN * 2 + 1];
        size_t n = 0;
        for (unsigned i = 0; i < count * MAKCU_KBD_REPORT_LEN; i++) {
            n += (size_t)snprintf(out + n, sizeof(out) - n, "%02x", tr[i]);
        }
        makcu_reply(out, n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'q') {""")
    open(p,"w",encoding="utf-8").write(t)

# main component must see makcu_keyboard (already in REQUIRES) - verify and build
print(open("app_left/main/CMakeLists.txt",encoding="utf-8").read().splitlines()[9])
