import glob, os
# hiddev CMakeLists: srcs + requires tinyusb & makcu_mouse
srcs = sorted("src/" + os.path.basename(p) for p in glob.glob("components/makcu_hiddev/src/*.c"))
lines = ["idf_component_register(", "    SRCS " + " ".join(f'"{s}"' for s in srcs),
         '    INCLUDE_DIRS "include"',
         "    REQUIRES espressif__tinyusb makcu_mouse", ")"]
open("components/makcu_hiddev/CMakeLists.txt","w",encoding="utf-8").write("\n".join(lines)+"\n")

# app: HID option + wiring
p="app_left/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_HID_DEVICE" not in t:
    t=t.replace('option(MB_DEBUG_OPCODE "enable the mx.<opcode> test harness" OFF)',
'''option(MB_DEBUG_OPCODE "enable the mx.<opcode> test harness" OFF)

# USB HID device (OTG).  Shares D+/D- with USB-Serial-JTAG on the ESP32-S3, so
# enabling it forces the control console onto UART0.
option(MB_HID_DEVICE "enumerate as a USB HID mouse" ON)''')
    open(p,"w",encoding="utf-8").write(t)

p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_HID_DEVICE" not in t:
    t=t.replace('''if(MB_DEBUG_OPCODE)
    add_compile_definitions(MB_DEBUG_OPCODE=1)
endif()''','''if(MB_DEBUG_OPCODE)
    add_compile_definitions(MB_DEBUG_OPCODE=1)
endif()
if(MB_HID_DEVICE)
    add_compile_definitions(MB_HID_DEVICE=1)
endif()''')
    open(p,"w",encoding="utf-8").write(t)

p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_hiddev_init" not in t:
    t=t.replace('#include "makcu_mouse.h"','#include "makcu_mouse.h"\n#include "makcu_hiddev.h"')
    # HID owns the USB peripheral -> no USB-Serial-JTAG console
    t=t.replace("#define MB_CONTROL_USB_JTAG 1","#if MB_HID_DEVICE\n#define MB_CONTROL_USB_JTAG 0   /* OTG owns D+/D- */\n#else\n#define MB_CONTROL_USB_JTAG 1\n#endif")
    t=t.replace("""    makcu_hid_report_hook = bench_report;
    makcu_mouse_init();""","""    makcu_hid_report_hook = bench_report;
    makcu_mouse_init();
#if MB_HID_DEVICE
    makcu_hiddev_init();
    makcu_hid_report_hook = makcu_hiddev_report;   /* reports go out over USB */
#endif""")
    # recovery: force download boot so the bench can always restore
    t=t.replace("""    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {""","""    if (len >= 5 && line[3] == 'd' && line[4] == 'l') {
        /* recovery path: reboot straight into the ROM downloader so the bench
         * can always flash a new image (OTG/HID builds have no CDC console) */
        REG_WRITE(RTC_CNTL_OPTION1_REG, RTC_CNTL_FORCE_DOWNLOAD_BOOT);
        esp_restart();
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {""")
    t=t.replace('#include "nvs_flash.h"','#include "esp_system.h"\n#include "soc/rtc_cntl_reg.h"\n#include "nvs_flash.h"')
    open(p,"w",encoding="utf-8").write(t)
print("hid wiring done")
