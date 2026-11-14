/* Runtime USB identity store - see include/makcu_clone.h. */
#include "makcu_clone.h"

#include "nvs.h"
#include <stdio.h>
#include "esp_random.h"
#include "esp_mac.h"
#include "nvs_flash.h"

#include <string.h>

#include "esp_attr.h"

/* The clone has to survive the reboot that applies it: descriptors are only read
 * while enumerating, and a runtime tud_disconnect/tud_connect cycle did not
 * bring the device back on this stack.  RTC no-init memory outlives a software
 * reset and costs nothing. */
#define CLONE_MAGIC 0x4D4B434Cu          /* "MKCL" */

static RTC_NOINIT_ATTR uint32_t s_magic;
static RTC_NOINIT_ATTR makcu_clone_t s_rtc_clone;

#define s_clone s_rtc_clone

makcu_clone_t *makcu_clone_mutable(void)
{
    return &s_clone;
}

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
}

bool makcu_clone_set_report(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0 || len > MAKCU_CLONE_REPORT_MAX) {
        return false;
    }
    memcpy(s_clone.report, data, len);
    s_clone.report_len = len;
    s_clone.valid = true;
    s_magic = CLONE_MAGIC;
    return true;
}

bool makcu_clone_set_device(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len != sizeof(s_clone.device)) {
        return false;
    }
    memcpy(s_clone.device, data, sizeof(s_clone.device));
    s_clone.valid = true;
    s_magic = CLONE_MAGIC;
    return true;
}

/* ------------------------------------------------------------- fixtures */
/* A standard 4-byte mouse report: buttons(3) + 5 const, x, y, wheel. */
static const uint8_t k_report_4b[] = {
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x03, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x03, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01, 0x75, 0x05,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38,
    0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x03, 0x81, 0x06,
    0xC0, 0xC0,
};

/* Same shape plus an AC pan byte, i.e. a 5-byte report. */
static const uint8_t k_report_5b[] = {
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x03, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x03, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01, 0x75, 0x05,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38,
    0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x03, 0x81, 0x06,
    0x05, 0x0C, 0x0A, 0x38, 0x02, 0x15, 0x81, 0x25, 0x7F, 0x75,
    0x08, 0x95, 0x01, 0x81, 0x06, 0xC0, 0xC0,
};

/* ---- byte-exact descriptors read from the real mouse (EP0 tunnel) ----------
 * Source: GET_DESCRIPTOR over the link (0xA1 tunnel, see verification report 24):
 *   device  18 B : 30FA:0302, bcdUSB 1.10, EP0 8 B, bcdDevice 1.00, iM=1 iP=2 iS=3
 *   config  34 B : 1 interface, HID boot/mouse, report desc 64 B,
 *                  endpoint 0x81 interrupt, wMaxPacketSize 5, bInterval 1
 *   report  64 B : 3 buttons + 5 pad bits, X/Y 12-bit (-2048..2047), wheel 8-bit
 *   strings      : "Instant" / "USB Optical Mouse" / (none)
 * The 12-bit packing is why the wire bytes look like x[7:0], x[11:8]|y[3:0]<<4,
 * y[11:4], wheel. */
static const uint8_t k_device_real[18] = {
    0x12, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x08, 0xFA, 0x30,
    0x02, 0x03, 0x00, 0x01, 0x01, 0x02, 0x00, 0x01,
};

static const uint8_t k_config_real[34] = {
    0x09, 0x02, 0x22, 0x00, 0x01, 0x01, 0x00, 0xA0, 0x32, 0x09,
    0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, 0x09, 0x21,
    0x11, 0x01, 0x00, 0x01, 0x22, 0x40, 0x00, 0x07, 0x05, 0x81,
    0x03, 0x05, 0x00, 0x01,
};

static const uint8_t k_report_12b[64] = {
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x03, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x03, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01, 0x75, 0x05,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x16, 0x00,
    0xF8, 0x26, 0xFF, 0x07, 0x75, 0x0C, 0x95, 0x02, 0x81, 0x06,
    0x09, 0x38, 0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x01,
    0x81, 0x06, 0xC0, 0xC0,
};

/* G3M PRO's mouse report descriptor, read off the device over the EP0 tunnel:
 * 5 buttons + 3 pad, X/Y 16-bit, wheel 8-bit, AC pan 8-bit  -> 7-byte report. */
static const uint8_t k_report_g3m[93] = {
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x05, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x05, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01, 0x75, 0x03,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x16, 0x00,
    0x80, 0x26, 0xFF, 0x7F, 0x75, 0x10, 0x95, 0x02, 0x81, 0x06,
    0x09, 0x38, 0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x01,
    0x81, 0x06, 0x05, 0x0C, 0x0A, 0x38, 0x02, 0x15, 0x81, 0x25,
    0x7F, 0x75, 0x08, 0x95, 0x01, 0x81, 0x06, 0xC0, 0x05, 0x0C,
    0x09, 0x00, 0x15, 0x80, 0x25, 0x7F, 0x95, 0x40, 0x75, 0x08,
    0xB1, 0x02, 0xC0,
};

static void build_device(uint8_t *out, uint16_t vid, uint16_t pid)
{
    /* bLength, bDescriptorType, bcdUSB 2.00 */
    out[0] = 18;
    out[1] = 0x01;
    out[2] = 0x00;
    out[3] = 0x02;
    /* class/subclass/protocol, EP0 size */
    out[4] = 0x00;
    out[5] = 0x00;
    out[6] = 0x00;
    out[7] = 64;
    out[8] = (uint8_t)(vid & 0xFF);
    out[9] = (uint8_t)(vid >> 8);
    out[10] = (uint8_t)(pid & 0xFF);
    out[11] = (uint8_t)(pid >> 8);
    out[12] = 0x00;                      /* bcdDevice 1.00 */
    out[13] = 0x01;
    out[14] = 0x01;                      /* iManufacturer */
    out[15] = 0x02;                      /* iProduct */
    out[16] = 0x03;                      /* iSerialNumber */
    out[17] = 0x01;                      /* bNumConfigurations */
}

/* One HID interface, interrupt IN endpoint, polling 1 ms. */
static void build_config(uint8_t *out, uint16_t *len_out, uint8_t report_len)
{
    const uint16_t total = 9 + 9 + 9 + 7;   /* config + interface + HID + EP */
    uint8_t *p = out;
    *p++ = 9;                            /* configuration */
    *p++ = 0x02;
    *p++ = (uint8_t)(total & 0xFF);
    *p++ = (uint8_t)(total >> 8);
    *p++ = 1;                            /* bNumInterfaces */
    *p++ = 1;                            /* bConfigurationValue */
    *p++ = 0;                            /* iConfiguration */
    *p++ = 0xA0;                         /* bmAttributes: bus powered, remote wake */
    *p++ = 50;                           /* bMaxPower 100 mA */
    *p++ = 9;                            /* interface */
    *p++ = 0x04;
    *p++ = 0;                            /* bInterfaceNumber */
    *p++ = 0;                            /* bAlternateSetting */
    *p++ = 1;                            /* bNumEndpoints */
    *p++ = 0x03;                         /* HID */
    *p++ = 0x01;                         /* boot interface */
    *p++ = 0x02;                         /* mouse protocol */
    *p++ = 0;                            /* iInterface */
    *p++ = 9;                            /* HID descriptor: 9 bytes, no more */
    *p++ = 0x21;
    *p++ = 0x11;
    *p++ = 0x01;                         /* bcdHID 1.11 */
    *p++ = 0;                            /* country code */
    *p++ = 1;                            /* bNumDescriptors */
    *p++ = 0x22;                         /* report descriptor */
    *p++ = report_len;
    *p++ = 0;
    *p++ = 7;                            /* endpoint */
    *p++ = 0x05;
    *p++ = 0x81;                         /* EP1 IN */
    *p++ = 0x03;                         /* interrupt */
    *p++ = 64;
    *p++ = 0;
    *p++ = 1;                            /* bInterval 1 ms */
    *len_out = total;
}

bool makcu_clone_apply_fixture(int which)
{
    makcu_clone_clear();
    switch (which) {
    case MAKCU_CLONE_FIXTURE_MOUSE_A:
        build_device(s_clone.device, 0x046D, 0xC077);
        memcpy(s_clone.report, k_report_4b, sizeof(k_report_4b));
        s_clone.report_len = sizeof(k_report_4b);
        build_config(s_clone.config, &s_clone.config_len, (uint8_t)sizeof(k_report_4b));
        s_clone.report_id = 0;               /* 4-byte report, no Report ID item */
        strcpy(s_clone.strings[0], "Logitech");
        strcpy(s_clone.strings[1], "USB Optical Mouse");
        strcpy(s_clone.strings[2], "000000000001");
        s_clone.valid = true;
        s_magic = CLONE_MAGIC;
        return true;
    case MAKCU_CLONE_FIXTURE_MOUSE_B:
        build_device(s_clone.device, 0x046D, 0xC52F);
        memcpy(s_clone.report, k_report_5b, sizeof(k_report_5b));
        s_clone.report_len = sizeof(k_report_5b);
        build_config(s_clone.config, &s_clone.config_len, (uint8_t)sizeof(k_report_5b));
        s_clone.report_id = 0;               /* 5-byte report, no Report ID item */
        strcpy(s_clone.strings[0], "Logitech");
        strcpy(s_clone.strings[1], "USB Receiver");
        strcpy(s_clone.strings[2], "000000000002");
        s_clone.valid = true;
        s_magic = CLONE_MAGIC;
        return true;
    case MAKCU_CLONE_FIXTURE_G3M:              /* G3M PRO report layout, safe identity */
        build_device(s_clone.device, 0x046D, 0xC077);
        memcpy(s_clone.report, k_report_g3m, sizeof(k_report_g3m));
        s_clone.report_len = sizeof(k_report_g3m);
        build_config(s_clone.config, &s_clone.config_len, (uint8_t)sizeof(k_report_g3m));
        s_clone.report_id = 0;
        strcpy(s_clone.strings[0], "Logitech");
        strcpy(s_clone.strings[1], "USB Optical Mouse");
        strcpy(s_clone.strings[2], "000000000004");
        s_clone.valid = true;
        s_clone.from_device = true;            /* 7-byte reports go out verbatim */
        s_magic = CLONE_MAGIC;
        return true;
    case MAKCU_CLONE_FIXTURE_REAL:
        memcpy(s_clone.device, k_device_real, sizeof(k_device_real));
        memcpy(s_clone.config, k_config_real, sizeof(k_config_real));
        s_clone.config_len = sizeof(k_config_real);
        memcpy(s_clone.report, k_report_12b, sizeof(k_report_12b));
        s_clone.report_len = sizeof(k_report_12b);
        s_clone.report_id = 0;               /* no Report ID item */
        strcpy(s_clone.strings[0], "Instant");
        strcpy(s_clone.strings[1], "USB Optical Mouse");
        strcpy(s_clone.strings[2], "000000000003");
        s_clone.valid = true;
        s_magic = CLONE_MAGIC;
        return true;
    default:
        return false;
    }
}

bool makcu_clone_wants_raw_report(void)
{
    /* Auto-cloned identity: the descriptor and the wire bytes come from the same
     * device, so the report must be forwarded untouched whatever the mouse is
     * (G3M PRO is 7 bytes / 16-bit axes; the canned 12-bit fixture is 5 bytes). */
    return s_clone.valid && (s_clone.from_device || s_clone.report_len == sizeof(k_report_12b));
}

bool makcu_clone_adopt(const uint8_t *device, size_t device_len,
                       const uint8_t *config, size_t config_len,
                       const uint8_t *report, size_t report_len,
                       const char *manufacturer, const char *product,
                       const char *serial, uint8_t report_id)
{
    if (device == NULL || device_len != sizeof(s_clone.device) ||
        config == NULL || config_len == 0 || config_len > sizeof(s_clone.config) ||
        report == NULL || report_len == 0 || report_len > sizeof(s_clone.report)) {
        return false;
    }
    /* An identity override set by the bench must survive the clear() below. */
    const uint16_t vid_save = s_clone.vid_ovr;
    const uint16_t pid_save = s_clone.pid_ovr;
    makcu_clone_clear();
    s_clone.vid_ovr = vid_save;
    s_clone.pid_ovr = pid_save;
    memcpy(s_clone.device, device, device_len);
    if (vid_save != 0) {
        s_clone.device[8] = (uint8_t)(vid_save & 0xFF);
        s_clone.device[9] = (uint8_t)(vid_save >> 8);
        s_clone.device[10] = (uint8_t)(pid_save & 0xFF);
        s_clone.device[11] = (uint8_t)(pid_save >> 8);
    }
#if defined(MB_FORCE_VID) && defined(MB_FORCE_PID)
    /* Compile-time identity wins: it also overwrites any stale RTC override left
     * behind by an older firmware layout. */
    s_clone.device[8]  = (uint8_t)(MB_FORCE_VID & 0xFF);
    s_clone.device[9]  = (uint8_t)(MB_FORCE_VID >> 8);
    s_clone.device[10] = (uint8_t)(MB_FORCE_PID & 0xFF);
    s_clone.device[11] = (uint8_t)(MB_FORCE_PID >> 8);
    s_clone.vid_ovr = MB_FORCE_VID;
    s_clone.pid_ovr = MB_FORCE_PID;
#endif
    /* Receivers may report an id no INF matches; map it to the vendor id so the
     * management app keeps working without pinning anything by hand.  An
     * explicit override (mx.vp / MB_FORCE_VIDPID) still wins. */
    /* The policy must not be defeated by a stale override.  A stored override that
     * either echoes the device or points at one of the receiver families is noise
     * (it is what a leftover write looks like), so the alias mapping always wins
     * for those; an override to a genuinely different, INF-backed id still wins. */
    const uint16_t dev_vid = (uint16_t)(device[8] | (device[9] << 8));
    const uint16_t dev_pid = (uint16_t)(device[10] | (device[11] << 8));
    const bool ovr_empty = (s_clone.vid_ovr == 0 && s_clone.pid_ovr == 0);
    const bool ovr_echo  = (s_clone.vid_ovr == dev_vid && s_clone.pid_ovr == dev_pid);
    const bool ovr_receiver = (s_clone.vid_ovr == 0x0E8C || s_clone.vid_ovr == 0x0ECC ||
                               s_clone.vid_ovr == 0x06CC || s_clone.vid_ovr == 0x068C);
    if (ovr_empty || ovr_echo || ovr_receiver) {
        (void)makcu_clone_apply_id_policy(s_clone.device);
    }

    memcpy(s_clone.config, config, config_len);
    s_clone.config_len = (uint16_t)config_len;
    memcpy(s_clone.report, report, report_len);
    s_clone.report_len = (uint16_t)report_len;
    s_clone.report_id = report_id;
    if (manufacturer != NULL) { strncpy(s_clone.strings[0], manufacturer, sizeof(s_clone.strings[0]) - 1); }
    if (product != NULL)      { strncpy(s_clone.strings[1], product, sizeof(s_clone.strings[1]) - 1); }
    if (serial != NULL)       { strncpy(s_clone.strings[2], serial, sizeof(s_clone.strings[2]) - 1); }
    s_clone.valid = true;
    s_clone.from_device = true;      /* reports use exactly this layout -> verbatim */
    s_magic = CLONE_MAGIC;
    return true;
}

bool makcu_clone_set_interface(uint8_t index, uint8_t ep_in,
                               const uint8_t *report, uint16_t report_len,
                               uint8_t report_id)
{
    if (index >= MAKCU_CLONE_IF_MAX || report == NULL || report_len == 0 ||
        report_len > MAKCU_CLONE_REPORT_MAX) {
        return false;
    }
    makcu_clone_if_t *it = &s_clone.ifs[index];
    memcpy(it->report, report, report_len);
    it->report_len = report_len;
    it->report_id = report_id;
    it->ep_in = ep_in;
    it->valid = true;
    if ((uint8_t)(index + 1) > s_clone.if_count) {
        s_clone.if_count = (uint8_t)(index + 1);
    }
    return true;
}


/* ------------------------------------------- VID/PID override in NVS */

#define NVS_OVR_NS   "makcu_clone"
#define NVS_OVR_VID  "vid_ovr"
#define NVS_OVR_PID  "pid_ovr"

void makcu_clone_identity_override_load(void)
{
    /* Drop any override left in RTC memory by an earlier firmware revision: a
     * stale value kept resurfacing in mx.fv and could shadow the identity alias
     * policy.  The bench override (mx.vp) is RAM-only and re-applied on demand. */
    s_clone.vid_ovr = 0;
    s_clone.pid_ovr = 0;
}

bool makcu_clone_identity_override_save(uint16_t vid, uint16_t pid)
{
    /* RAM only (see identity_override_load); kept for the mx.vp interface. */
    s_clone.vid_ovr = vid;
    s_clone.pid_ovr = pid;
    if (s_clone.valid) {
        s_clone.device[8]  = (uint8_t)(vid & 0xFF);
        s_clone.device[9]  = (uint8_t)(vid >> 8);
        s_clone.device[10] = (uint8_t)(pid & 0xFF);
        s_clone.device[11] = (uint8_t)(pid >> 8);
    }
    return true;
}


/* ---------------------------------------------- identity alias policy */

/* Receiver families that report an id without a host INF.  Each entry maps
 * <vid, pid-mask, pid-base> onto the id the vendor's own INF matches; the HID
 * layout and the vendor protocol are identical, only the id differs.
 * Add entries here when another device family shows the same behaviour. */
typedef struct {
    uint16_t vid;
    uint16_t pid_mask;
    uint16_t pid_base;
    uint16_t to_vid;
    uint16_t to_pid;
} makcu_id_alias_t;

static const makcu_id_alias_t k_id_alias[] = {
    /* The G3M PRO's 2.4G receiver reports a different id depending on its state.
     * Observed so far: 0E8C:F0Dx, 0ECC:F0Dx/F0Fx, 06CC:F0Dx.  None of them has a
     * host INF, while the vendor's own id does, and the HID layout plus the
     * vendor protocol are identical - so map the whole family onto 320F:706E.
     * Add an entry here when a new reporting id shows up (mx.vf prints the
     * currently served bytes). */
    { 0x0E8C, 0xF000, 0xF000, 0x320F, 0x706E },
    { 0x0ECC, 0xF000, 0xF000, 0x320F, 0x706E },
    { 0x06CC, 0xF000, 0xF000, 0x320F, 0x706E },
    { 0x320F, 0xFFFF, 0x706E, 0x320F, 0x706E },   /* the vendor id itself */
};

bool makcu_clone_apply_id_policy(uint8_t device[18])
{
    if (device == NULL || device[0] != 18 || device[1] != 0x01) {
        return false;
    }
    const uint16_t vid = (uint16_t)(device[8] | (device[9] << 8));
    const uint16_t pid = (uint16_t)(device[10] | (device[11] << 8));
    for (size_t i = 0; i < sizeof(k_id_alias) / sizeof(k_id_alias[0]); i++) {
        const makcu_id_alias_t *a = &k_id_alias[i];
        if (vid == a->vid && (pid & a->pid_mask) == a->pid_base) {
            device[8]  = (uint8_t)(a->to_vid & 0xFF);
            device[9]  = (uint8_t)(a->to_vid >> 8);
            device[10] = (uint8_t)(a->to_pid & 0xFF);
            device[11] = (uint8_t)(a->to_pid >> 8);
            return true;
        }
    }
    return false;
}


/* ----------------------------------------- per-unit random serial number */

#define NVS_OVR_SN   "serial"

void makcu_clone_serial_get(char out[13])
{
    if (out == NULL) {
        return;
    }
    nvs_handle_t h;
    char buf[16] = { 0 };

    if (nvs_open(NVS_OVR_NS, NVS_READONLY, &h) == ESP_OK) {
        size_t len = sizeof(buf);
        (void)nvs_get_str(h, NVS_OVR_SN, buf, &len);
        nvs_close(h);
    }

    if (buf[0] == 0) {
        /* First boot: derive from the chip MAC (unique per unit) and mix in a
         * hardware random so cloned boxes never collide. */
        uint8_t mac[6] = { 0 };
        (void)esp_efuse_mac_get_default(mac);
        const uint32_t r1 = esp_random();
        const uint32_t r2 = esp_random();
        /* 12 chars: MB + 2 hex (MAC) + 8 hex (random) */
        const uint32_t mix = (r1 ^ (r2 << 13) ^ r2) & 0xFFFFFFFFu;
        snprintf(buf, sizeof(buf), "MB%02X%02X%08lX",
                 (unsigned)mac[4], (unsigned)mac[5], (unsigned long)mix);
        if (nvs_open(NVS_OVR_NS, NVS_READWRITE, &h) == ESP_OK) {
            (void)nvs_set_str(h, NVS_OVR_SN, buf);
            (void)nvs_commit(h);
            nvs_close(h);
        }
    }

    if (buf[0] == 0) {
        snprintf(buf, sizeof(buf), "MBDEADBEEF01");   /* NVS unavailable */
    }
    memcpy(out, buf, 13);   /* caller buffer is 13 bytes */
}
