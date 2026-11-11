p="components/makcu_hiddev/src/usb_descriptors.c"
t=open(p,encoding="utf-8").read()
if "makcu_clone_get" not in t:
    t=t.replace('#include "tusb.h"','#include "tusb.h"\n\n#include "makcu_clone.h"')
    # device descriptor: clone wins when loaded
    t=t.replace("""uint8_t const *tud_descriptor_device_cb(void)
{
    return (uint8_t const *)&desc_device;
}""","""uint8_t const *tud_descriptor_device_cb(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
        return c->device;                  /* cloned identity (P5) */
    }
    return (uint8_t const *)&desc_device;
}""")
    # configuration descriptor
    t=t.replace("""uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    return desc_configuration;
}""","""uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->config_len > 0) {
        return c->config;
    }
    return desc_configuration;
}""")
    # HID report descriptor
    t=t.replace("""uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    (void)instance;
    return desc_report;
}""","""uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    (void)instance;
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->report_len > 0) {
        return c->report;
    }
    return desc_report;
}""")
    # strings: clone strings when loaded
    t=t.replace("""        const char *str = string_desc_arr[index];""","""        const char *str = string_desc_arr[index];
        const makcu_clone_t *c = makcu_clone_get();
        if (c != NULL && c->valid) {
            if (index == 1 && c->strings[0][0]) {
                str = c->strings[0];
            } else if (index == 2 && c->strings[1][0]) {
                str = c->strings[1];
            } else if (index == 3 && c->strings[2][0]) {
                str = c->strings[2];
            }
        }""")
    open(p,"w",encoding="utf-8").write(t)

# hiddev: rebind helper so a descriptor swap takes effect
p="components/makcu_hiddev/src/makcu_hiddev.c"
t=open(p,encoding="utf-8").read()
if "makcu_hiddev_rebind" not in t:
    t=t.replace("""bool makcu_hiddev_mounted(void)""","""void makcu_hiddev_rebind(void)
{
    /* Descriptors are only read while enumerating, so drop the bus and come back
     * after the store has been updated. */
    tud_disconnect();
    vTaskDelay(pdMS_TO_TICKS(30));
    tud_connect();
}

bool makcu_hiddev_mounted(void)""")
    open(p,"w",encoding="utf-8").write(t)

p="components/makcu_hiddev/include/makcu_hiddev.h"
t=open(p,encoding="utf-8").read()
if "makcu_hiddev_rebind" not in t:
    t=t.replace("/* True once the host has configured us (tud_mount_cb). */",
"""/* Re-enumerate so a changed descriptor store takes effect. */
void makcu_hiddev_rebind(void);

/* True once the host has configured us (tud_mount_cb). */""")
    open(p,"w",encoding="utf-8").write(t)

open("components/makcu_clone/CMakeLists.txt","w",encoding="utf-8").write('''idf_component_register(
    SRCS "src/makcu_clone.c"
    INCLUDE_DIRS "include"
)
''')
print("clone wired into descriptors + hiddev")
