p="components/makcu_clone/src/makcu_clone.c"
t=open(p,encoding="utf-8").read()
if "RTC_NOINIT_ATTR" not in t:
    t=t.replace('#include <string.h>','''#include <string.h>

#include "esp_attr.h"

/* The clone has to survive the reboot that applies it: descriptors are only read
 * while enumerating, and a runtime tud_disconnect/tud_connect cycle did not
 * bring the device back on this stack.  RTC no-init memory outlives a software
 * reset and costs nothing. */
#define CLONE_MAGIC 0x4D4B434Cu          /* "MKCL" */

static RTC_NOINIT_ATTR uint32_t s_magic;
static RTC_NOINIT_ATTR makcu_clone_t s_rtc_clone;''')
    t=t.replace("""static makcu_clone_t s_clone;

const makcu_clone_t *makcu_clone_get(void)
{
    return &s_clone;
}

void makcu_clone_clear(void)
{
    memset(&s_clone, 0, sizeof(s_clone));
}""","""#define s_clone s_rtc_clone

const makcu_clone_t *makcu_clone_get(void)
{
    if (s_magic != CLONE_MAGIC) {
        return NULL;
    }
    return &s_clone;
}

void makcu_clone_clear(void)
{
    memset(&s_clone, 0, sizeof(s_clone));
    s_magic = 0;
}""")
    t=t.replace("""    memcpy(s_clone.report, data, len);
    s_clone.report_len = len;
    s_clone.valid = true;
    return true;""","""    memcpy(s_clone.report, data, len);
    s_clone.report_len = len;
    s_clone.valid = true;
    s_magic = CLONE_MAGIC;
    return true;""")
    t=t.replace("""    memcpy(s_clone.device, data, sizeof(s_clone.device));
    s_clone.valid = true;
    return true;""","""    memcpy(s_clone.device, data, sizeof(s_clone.device));
    s_clone.valid = true;
    s_magic = CLONE_MAGIC;
    return true;""")
    # fixtures: stamp the magic
    t=t.replace("""        strcpy(s_clone.strings[2], "000000000001");
        s_clone.valid = true;
        return true;""","""        strcpy(s_clone.strings[2], "000000000001");
        s_clone.valid = true;
        s_magic = CLONE_MAGIC;
        return true;""")
    t=t.replace("""        strcpy(s_clone.strings[2], "000000000002");
        s_clone.valid = true;
        return true;""","""        strcpy(s_clone.strings[2], "000000000002");
        s_clone.valid = true;
        s_magic = CLONE_MAGIC;
        return true;""")
    open(p,"w",encoding="utf-8").write(t)

# app: apply + reboot instead of runtime rebind
p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""        const bool ok = makcu_clone_apply_fixture(which);
#if MB_HID_DEVICE
        makcu_hiddev_rebind();
#endif
        const makcu_clone_t *c = makcu_clone_get();""","""        const bool ok = makcu_clone_apply_fixture(which);
        const makcu_clone_t *c = makcu_clone_get();""")
t=t.replace("""        const int n = snprintf(out, sizeof(out), "%d:%02x%02x:%02x%02x",
                               ok ? 1 : 0, c->device[9], c->device[8],
                               c->device[11], c->device[10]);
        makcu_reply(out, (size_t)n);
        return 1;""","""        const int n = snprintf(out, sizeof(out), "%d:%02x%02x:%02x%02x",
                               ok ? 1 : 0, c->device[9], c->device[8],
                               c->device[11], c->device[10]);
        makcu_reply(out, (size_t)n);
        /* descriptors are only read while enumerating: apply by rebooting */
        vTaskDelay(pdMS_TO_TICKS(150));
        esp_restart();
        return 1;""")
t=t.replace("""    if (len >= 5 && line[3] == 'c' && line[4] == 'c') {
        makcu_clone_clear();
#if MB_HID_DEVICE
        makcu_hiddev_rebind();
#endif
        makcu_reply("0", 1);
        return 1;
    }""","""    if (len >= 5 && line[3] == 'c' && line[4] == 'c') {
        makcu_clone_clear();
        makcu_reply("0", 1);
        vTaskDelay(pdMS_TO_TICKS(150));
        esp_restart();
        return 1;
    }""")
open(p,"w",encoding="utf-8").write(t)
print("clone now applies across a reboot via RTC no-init memory")
