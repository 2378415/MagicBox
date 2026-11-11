# config descriptor must be regenerated at runtime: its HID class block carries
# the report-descriptor length, so a 46-byte clone with the built-in 52-byte
# declaration makes the host reject the device.
p="components/makcu_hiddev/src/usb_descriptors.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""    /* The configuration block stays the built-in (proven) one: a synthesised
     * clone configuration failed to enumerate, see docs D23. */
    return desc_configuration;""","""    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->config_len > 0) {
        return c->config;                  /* cloned identity (P5) */
    }
    return desc_configuration;""")
open(p,"w",encoding="utf-8").write(t)

# mx.dv: dump the live descriptors so consistency can be checked over the wire
p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "mx.dv" not in t and "line[3] == 'd' && line[4] == 'v'" not in t:
    t=t.replace('#include "makcu_clone.h"','#include "makcu_clone.h"\n#include "tusb.h"')
    t=t.replace("""    if (len >= 5 && line[3] == 'c' && line[4] == 'l') {""","""    if (len >= 5 && line[3] == 'd' && line[4] == 'v') {
        char out[160];
        const uint8_t *dev = tud_descriptor_device_cb();
        const uint8_t *cfg = tud_descriptor_configuration_cb(0);
        const uint8_t *rep = tud_hid_descriptor_report_cb(0);
        const makcu_clone_t *c = makcu_clone_get();
        const uint16_t rep_len = (c != NULL && c->valid && c->report_len)
                                 ? c->report_len : 0;
        const uint16_t cfg_len = (c != NULL && c->valid && c->config_len)
                                 ? c->config_len : 0;
        const int n = snprintf(out, sizeof(out),
                               "dev=%02x%02x:%02x%02x cfg=%u:%u rep=%u:%02x",
                               dev[9], dev[8], dev[11], dev[10],
                               (unsigned)cfg_len, (unsigned)cfg[2] | ((unsigned)cfg[3] << 8),
                               (unsigned)rep_len, (unsigned)rep[0]);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'c' && line[4] == 'l') {""")
    open(p,"w",encoding="utf-8").write(t)
print("runtime config restored + mx.dv added")
