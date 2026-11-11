import glob
for comp, reqs in (("makcu_mouse", ["makcu_proto","makcu_dev"]),):
    srcs = sorted("src/" + p.split("\\")[-1].split("/")[-1] for p in glob.glob(f"components/{comp}/src/*.c"))
    lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
             '    INCLUDE_DIRS "include"', "    REQUIRES " + " ".join(reqs), ")"]
    open(f"components/{comp}/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")
    print(comp, srcs)

# app: init mouse layer + register report hook + mx.rp debug readback
p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_mouse_init" not in t:
    t=t.replace('#include "makcu_dev.h"','#include "makcu_dev.h"\n#include "makcu_mouse.h"')
    t=t.replace("""static const char *TAG = "makcu-left";""",
"""static const char *TAG = "makcu-left";

/* Bench observability: remember the last HID mouse report so the mx.rp test
 * command can read it back.  A real HID layer would replace this hook. */
static void bench_report(const makcu_report_t *r)
{
    (void)r;                       /* makcu_mouse keeps its own copy */
}""")
    t=t.replace("""    makcu_dev_reset();
    makcu_reply_set_writer(control_write);""","""    makcu_dev_reset();
    makcu_reply_set_writer(control_write);
    makcu_hid_report_hook = bench_report;
    makcu_mouse_init();""")
    # mx.rp: last report as hex
    t=t.replace("""    const int hi = hexval(line[3]);""","""    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {
        const makcu_report_t *r = makcu_mouse_last_report();
        char out[7];
        snprintf(out, sizeof(out), "%02x%02x%02x",
                 (unsigned)(uint8_t)r->dx, (unsigned)(uint8_t)r->dy, (unsigned)(uint8_t)r->wheel);
        makcu_reply(out, 6);
        return 1;
    }
    const int hi = hexval(line[3]);""")
    t=t.replace("#include <string.h>","#include <stdio.h>\n#include <string.h>")
    open(p,"w",encoding="utf-8").write(t)
print("app wired for mouse")
