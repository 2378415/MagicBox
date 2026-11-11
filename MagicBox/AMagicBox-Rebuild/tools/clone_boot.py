# 1) mx.cl / mx.cc: store only, no esp_restart (a software reset from the app
#    leaves the USB PHY attached and the host never re-enumerates).
p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""        makcu_reply(out, (size_t)n);
        /* descriptors are only read while enumerating: apply by rebooting */
        vTaskDelay(pdMS_TO_TICKS(150));
        esp_restart();
        return 1;""","""        makcu_reply(out, (size_t)n);
        /* Descriptors are only read while enumerating.  A software reset leaves
         * the USB PHY attached and the host stops enumerating, so the clone takes
         * effect on the next real reset (flash or replug) - see docs D23. */
        return 1;""")
t=t.replace("""        makcu_clone_clear();
        makcu_reply("0", 1);
        vTaskDelay(pdMS_TO_TICKS(150));
        esp_restart();
        return 1;""","""        makcu_clone_clear();
        makcu_reply("0", 1);
        return 1;""")
# 2) boot-time fixture so the clone path can be verified without a runtime reset
t=t.replace("""#if MB_HID_DEVICE
    makcu_hiddev_init();""","""#if MB_CLONE_FIXTURE
    /* Bench: load a canned identity before the device stack enumerates, so the
     * very first enumeration already uses the cloned descriptors. */
    makcu_clone_apply_fixture(MB_CLONE_FIXTURE);
#endif
#if MB_HID_DEVICE
    makcu_hiddev_init();""")
open(p,"w",encoding="utf-8").write(t)

p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_CLONE_FIXTURE" not in t:
    t=t.replace('''if(MB_HID_DEVICE)
    add_compile_definitions(MB_HID_DEVICE=1)
endif()''','''if(MB_HID_DEVICE)
    add_compile_definitions(MB_HID_DEVICE=1)
endif()
if(MB_CLONE_FIXTURE)
    add_compile_definitions(MB_CLONE_FIXTURE=${MB_CLONE_FIXTURE})
endif()''')
    open(p,"w",encoding="utf-8").write(t)
p="app_left/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_CLONE_FIXTURE" not in t:
    t=t.replace('option(MB_HID_DEVICE "enumerate as a USB HID mouse" ON)',
'''option(MB_HID_DEVICE "enumerate as a USB HID mouse" ON)

# Bench only: load clone fixture N (1 = 046D:C077, 2 = 046D:C52F) at boot so the
# first enumeration already uses the cloned identity.
set(MB_CLONE_FIXTURE "" CACHE STRING "clone fixture loaded at boot (1 or 2)")''')
    open(p,"w",encoding="utf-8").write(t)
print("boot-time clone fixture wired")
