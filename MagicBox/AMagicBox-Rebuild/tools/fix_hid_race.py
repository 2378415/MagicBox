p="components/makcu_hiddev/src/makcu_hiddev.c"
t=open(p,encoding="utf-8").read()
if "s_hid_lock" not in t:
    t=t.replace("""static usb_phy_handle_t s_phy;
static bool s_mounted;""","""static usb_phy_handle_t s_phy;
static bool s_mounted;
static SemaphoreHandle_t s_hid_lock;""")
    t=t.replace('#include "freertos/task.h"','#include "freertos/semphr.h"\n#include "freertos/task.h"')
    # serialise both report paths: the mouse task and the keyboard task share one
    # HID endpoint, and an interleaved 8-byte keyboard report corrupts a 4-byte
    # mouse report in flight (observed as wild pointer jumps).
    t=t.replace("""void makcu_hiddev_report(const makcu_report_t *r)
{
    if (r == NULL || !s_mounted) {
        return;
    }
    uint8_t report[4] = {
        r->buttons,
        (uint8_t)r->dx,
        (uint8_t)r->dy,
        (uint8_t)r->wheel,
    };
    tud_hid_report(1, report, sizeof(report));       /* report ID 1 = mouse */
}""","""static bool hid_send(uint8_t report_id, const uint8_t *data, uint16_t len)
{
    if (!s_mounted) {
        return false;
    }
    if (s_hid_lock == NULL) {
        return tud_hid_report(report_id, data, len);
    }
    xSemaphoreTake(s_hid_lock, portMAX_DELAY);
    const bool ok = tud_hid_report(report_id, data, len);
    xSemaphoreGive(s_hid_lock);
    return ok;
}

void makcu_hiddev_report(const makcu_report_t *r)
{
    if (r == NULL) {
        return;
    }
    uint8_t report[4] = {
        r->buttons,
        (uint8_t)r->dx,
        (uint8_t)r->dy,
        (uint8_t)r->wheel,
    };
    hid_send(1, report, sizeof(report));             /* report ID 1 = mouse */
}""")
    t=t.replace("""void makcu_hiddev_kbd_report(const uint8_t *report8)
{
    if (report8 == NULL || !s_mounted) {
        return;
    }
    tud_hid_report(2, report8, 8);                   /* report ID 2 = keyboard */
}""","""void makcu_hiddev_kbd_report(const uint8_t *report8)
{
    if (report8 == NULL) {
        return;
    }
    hid_send(2, report8, 8);                         /* report ID 2 = keyboard */
}""")
    t=t.replace("""    if (!tusb_init()) {""","""    if (s_hid_lock == NULL) {
        s_hid_lock = xSemaphoreCreateMutex();
    }
    if (!tusb_init()) {""")
    open(p,"w",encoding="utf-8").write(t)
print("hid report mutex added")
