/* USB descriptors - device / configuration / string + the mouse report
 * descriptor.
 *
 * Report layout (4 bytes, input only, no report ID):
 *   byte 0  buttons  (bit0 left, bit1 right, bit2 middle)
 *   byte 1  dx  int8
 *   byte 2  dy  int8
 *   byte 3  wheel int8
 *
 * This is the standard boot-mouse shape; the original clones whatever the
 * attached device reports (P5, not ported yet).
 */
#include "tusb.h"

#include "makcu_clone.h"

#include <string.h>

#define USB_VID   0x303A            /* Espressif */
#define USB_PID   0x4004            /* TinyUSB HID example PID */
#define USB_BCD   0x0100

/* ---------------------------------------------------------- report layout */
static uint8_t const desc_report[] = {
    /* ---------------------------------------------------------- mouse (ID 1) */
    0x05, 0x01,        /* Usage Page (Generic Desktop)        */
    0x09, 0x02,        /* Usage (Mouse)                       */
    0xA1, 0x01,        /* Collection (Application)            */
    0x85, 0x01,        /*   Report ID (1)                     */
    0x09, 0x01,        /*   Usage (Pointer)                   */
    0xA1, 0x00,        /*   Collection (Physical)             */
    0x05, 0x09,        /*     Usage Page (Button)             */
    0x19, 0x01,        /*     Usage Minimum (1)               */
    0x29, 0x03,        /*     Usage Maximum (3)               */
    0x15, 0x00,        /*     Logical Minimum (0)             */
    0x25, 0x01,        /*     Logical Maximum (1)             */
    0x95, 0x03,        /*     Report Count (3)                */
    0x75, 0x01,        /*     Report Size (1)                 */
    0x81, 0x02,        /*     Input (Data,Var,Abs)            */
    0x95, 0x01,        /*     Report Count (1)                */
    0x75, 0x05,        /*     Report Size (5)                 */
    0x81, 0x01,        /*     Input (Const)                   */
    0x05, 0x01,        /*     Usage Page (Generic Desktop)    */
    0x09, 0x30,        /*     Usage (X)                       */
    0x09, 0x31,        /*     Usage (Y)                       */
    0x09, 0x38,        /*     Usage (Wheel)                   */
    0x15, 0x81,        /*     Logical Minimum (-127)          */
    0x25, 0x7F,        /*     Logical Maximum (127)           */
    0x75, 0x08,        /*     Report Size (8)                 */
    0x95, 0x03,        /*     Report Count (3)                */
    0x81, 0x06,        /*     Input (Data,Var,Rel)            */
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
};

/* --------------------------------------------------------------- device */
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = 0x00,
    .bDeviceSubClass    = 0x00,
    .bDeviceProtocol    = 0x00,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = USB_BCD,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,
    .bNumConfigurations = 0x01,
};



static tusb_desc_device_t desc_device_runtime;

/* Serve the cloned device descriptor *verbatim*.  Patching only VID/PID/bcdDevice
 * onto the template left bMaxPacketSize0 (0x40 instead of the device's 0x08),
 * iSerialNumber (3 instead of 0) and bcdDevice wrong - the management app cares
 * about those, and the real device is byte-identical to what we now serve. */
/* Serve the template with the cloned VID/PID/bcdDevice patched in.  This is the
 * configuration that was verified working end to end (mouse input + the vendor
 * channel); serving the raw 18 bytes instead (iSerialNumber = 0) creates a brand
 * new host device instance and the HID input path then never produced movement,
 * so it is intentionally not used. */
uint8_t const *tud_descriptor_device_cb(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->device[0] == 18 && c->device[1] == 0x01) {
        desc_device_runtime = desc_device;
        desc_device_runtime.idVendor  = (uint16_t)(c->device[8] | (c->device[9] << 8));
        desc_device_runtime.idProduct = (uint16_t)(c->device[10] | (c->device[11] << 8));
        desc_device_runtime.bcdDevice = (uint16_t)(c->device[12] | (c->device[13] << 8));
        return (uint8_t const *)&desc_device_runtime;
    }
    return (uint8_t const *)&desc_device;
}

/* --------------------------------------------------------- configuration */
enum {
    ITF_NUM_HID = 0,
    ITF_NUM_TOTAL,
};

#define EPNUM_HID        0x81
#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + TUD_HID_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),
    TUD_HID_DESCRIPTOR(ITF_NUM_HID, 0, HID_ITF_PROTOCOL_MOUSE,
                       sizeof(desc_report), EPNUM_HID, CFG_TUD_HID_EP_BUFSIZE, 1),
};

uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->config_len > 0) {
        return c->config;                  /* cloned identity (P5) */
    }
    return desc_configuration;
}

uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
#if defined(MB_DUAL_IF)
        /* composite clone: each HID interface carries its own descriptor */
        if (instance < c->if_count && instance < MAKCU_CLONE_IF_MAX && c->ifs[instance].valid) {
            return c->ifs[instance].report;
        }
#else
        (void)instance;
#endif
        if (c->report_len > 0) {
            return c->report;
        }
    }
    return desc_report;
}

/* ------------------------------------------------------------- strings */
static char const *string_desc_arr[] = {
    (const char[]){ 0x09, 0x04 },   /* 0: language = en_US */
    "MAKCU",                        /* 1: manufacturer */
    "MAKCU HID",                    /* 2: product */
    "000000000001",                 /* 3: serial */
};

static uint16_t _desc_str[32 + 1];

uint16_t const *tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void)langid;
    size_t chr_count;

    if (index == 0) {
        memcpy(&_desc_str[1], string_desc_arr[0], 2);
        chr_count = 1;
    } else {
        if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0])) {
            return NULL;
        }
        const char *str = string_desc_arr[index];
        const makcu_clone_t *c = makcu_clone_get();
        if (c != NULL && c->valid) {
            if (index == 1 && c->strings[0][0]) {
                str = c->strings[0];
            } else if (index == 2 && c->strings[1][0]) {
                str = c->strings[1];
            } else if (index == 3 && c->strings[2][0]) {
                str = c->strings[2];
            }
        }
        chr_count = strlen(str);
        if (chr_count > 31) {
            chr_count = 31;
        }
        for (size_t i = 0; i < chr_count; i++) {
            _desc_str[1 + i] = (uint16_t)str[i];
        }
    }
    _desc_str[0] = (uint16_t)((TUSB_DESC_STRING << 8) | (2 * chr_count + 2));
    return _desc_str;
}
