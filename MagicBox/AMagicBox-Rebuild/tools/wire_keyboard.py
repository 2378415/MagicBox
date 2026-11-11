# 1) keyboard component CMakeLists: add the real implementation
p="components/makcu_keyboard/CMakeLists.txt"
open(p,"w",encoding="utf-8").write('''idf_component_register(
    SRCS "src/makcu_keyboard.c" "src/makcu_keyboard_stub.c"
    INCLUDE_DIRS "include"
    REQUIRES makcu_proto
)
''')

# 2) HID descriptors: mouse on report ID 1, keyboard on report ID 2
p="components/makcu_hiddev/src/usb_descriptors.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""static uint8_t const desc_report[] = {
    0x05, 0x01,        /* Usage Page (Generic Desktop)        */
    0x09, 0x02,        /* Usage (Mouse)                       */
    0xA1, 0x01,        /* Collection (Application)            */
    0x09, 0x01,        /*   Usage (Pointer)                   */""","""static uint8_t const desc_report[] = {
    /* ---------------------------------------------------------- mouse (ID 1) */
    0x05, 0x01,        /* Usage Page (Generic Desktop)        */
    0x09, 0x02,        /* Usage (Mouse)                       */
    0xA1, 0x01,        /* Collection (Application)            */
    0x85, 0x01,        /*   Report ID (1)                     */
    0x09, 0x01,        /*   Usage (Pointer)                   */""")
t=t.replace("""    0x81, 0x06,        /*     Input (Data,Var,Rel)            */
    0xC0,              /*   End Collection                    */
    0xC0,              /* End Collection                      */
};""","""    0x81, 0x06,        /*     Input (Data,Var,Rel)            */
    0xC0,              /*   End Collection                    */
    0xC0,              /* End Collection                      */

    /* ------------------------------------------------------- keyboard (ID 2) */
    0x05, 0x01,        /* Usage Page (Generic Desktop)        */
    0x09, 0x06,        /* Usage (Keyboard)                    */
    0xA1, 0x01,        /* Collection (Application)            */
    0x85, 0x02,        /*   Report ID (2)                     */
    0x05, 0x07,        /*   Usage Page (Keyboard/Keypad)      */
    0x19, 0xE0,        /*   Usage Minimum (LeftControl)       */
    0x29, 0xE7,        /*   Usage Maximum (Right GUI)         */
    0x15, 0x00,        /*   Logical Minimum (0)               */
    0x25, 0x01,        /*   Logical Maximum (1)               */
    0x75, 0x01,        /*   Report Size (1)                   */
    0x95, 0x08,        /*   Report Count (8)                  */
    0x81, 0x02,        /*   Input (Data,Var,Abs)  modifiers   */
    0x95, 0x01,        /*   Report Count (1)                  */
    0x75, 0x08,        /*   Report Size (8)                   */
    0x81, 0x01,        /*   Input (Const)  reserved           */
    0x95, 0x06,        /*   Report Count (6)                  */
    0x75, 0x08,        /*   Report Size (8)                   */
    0x15, 0x00,        /*   Logical Minimum (0)               */
    0x25, 0x65,        /*   Logical Maximum (101)             */
    0x05, 0x07,        /*   Usage Page (Keyboard/Keypad)      */
    0x19, 0x00,        /*   Usage Minimum (0)                 */
    0x29, 0x65,        /*   Usage Maximum (101)               */
    0x81, 0x00,        /*   Input (Data,Array)  usages        */
    0xC0,              /* End Collection                      */
};""")
open(p,"w",encoding="utf-8").write(t)

# 3) hiddev: report id aware mouse report + keyboard report entry point
p="components/makcu_hiddev/src/makcu_hiddev.c"
t=open(p,encoding="utf-8").read()
t=t.replace("    tud_hid_report(0, report, sizeof(report));","    tud_hid_report(1, report, sizeof(report));       /* report ID 1 = mouse */")
t=t.replace("""bool makcu_hiddev_mounted(void)""","""void makcu_hiddev_kbd_report(const uint8_t *report8)
{
    if (report8 == NULL || !s_mounted) {
        return;
    }
    tud_hid_report(2, report8, 8);                   /* report ID 2 = keyboard */
}

bool makcu_hiddev_mounted(void)""")
open(p,"w",encoding="utf-8").write(t)

p="components/makcu_hiddev/include/makcu_hiddev.h"
t=open(p,encoding="utf-8").read()
t=t.replace("""/* Send one 4-byte mouse report (buttons, dx, dy, wheel). */
void makcu_hiddev_report(const makcu_report_t *r);""","""/* Send one 4-byte mouse report (buttons, dx, dy, wheel). */
void makcu_hiddev_report(const makcu_report_t *r);

/* Send the 8-byte boot-keyboard report (modifiers, reserved, six usages). */
void makcu_hiddev_kbd_report(const uint8_t *report8);""")
if "#include <stdint.h>" not in t:
    t=t.replace("#include <stdbool.h>","#include <stdbool.h>\n#include <stdint.h>")
open(p,"w",encoding="utf-8").write(t)
print("descriptors + hiddev updated")
