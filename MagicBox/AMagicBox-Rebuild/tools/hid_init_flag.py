p="components/makcu_hiddev/src/makcu_hiddev.c"
t=open(p,encoding="utf-8").read()
if "makcu_hiddev_init_ok" not in t:
    t=t.replace("static bool s_mounted;","static bool s_mounted;\nstatic bool s_init_ok;")
    t=t.replace("""bool makcu_hiddev_mounted(void)""","""bool makcu_hiddev_init_ok(void)
{
    return s_init_ok;
}

bool makcu_hiddev_mounted(void)""")
    t=t.replace("""    if (!tusb_init()) {
        ESP_LOGE(TAG, "tusb_init failed");
        return;
    }""","""    if (!tusb_init()) {
        ESP_LOGE(TAG, "tusb_init failed");
        return;
    }
    s_init_ok = true;""")
    open(p,"w",encoding="utf-8").write(t)
p="components/makcu_hiddev/include/makcu_hiddev.h"
t=open(p,encoding="utf-8").read()
if "makcu_hiddev_init_ok" not in t:
    t=t.replace("/* True once the host has configured us (tud_mount_cb). */",
"/* True when tusb_init() succeeded. */\nbool makcu_hiddev_init_ok(void);\n\n/* True once the host has configured us (tud_mount_cb). */")
    open(p,"w",encoding="utf-8").write(t)
print("init flag exposed")
