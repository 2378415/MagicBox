/* Runtime USB identity store - the "clone" half of P5.
 *
 * The original left chip copies the identity of the device it is cloning (VID,
 * PID, HID report descriptor, strings) and presents that to the host.  The
 * pieces are received over the UART1 link (0xA2 chunks, see makcu_link_bridge)
 * and then used as the live USB descriptors.
 *
 * This component is the store + the plumbing: usb_descriptors.c asks it first
 * and falls back to the built-in defaults when nothing valid has been loaded.
 * The link side that fills it from real hardware is still TODO (needs a second
 * chip on the bench); makcu_clone_apply_fixture() provides a canned identity so
 * the descriptor swap can be verified end to end.
 */
#ifndef MAKCU_CLONE_H
#define MAKCU_CLONE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define MAKCU_CLONE_CONFIG_MAX 128
#define MAKCU_CLONE_REPORT_MAX 192
#define MAKCU_CLONE_IF_MAX     2

/* One HID interface of the cloned device (a composite mouse exposes two: mouse
 * and keyboard/vendor).  The USB stack currently serves interface 0; the second
 * entry is captured now so enabling it later is mechanical. */
typedef struct {
    bool     valid;
    uint8_t  ep_in;                          /* interrupt IN endpoint address */
    uint8_t  report_id;
    uint16_t report_len;
    uint8_t  report[MAKCU_CLONE_REPORT_MAX];
} makcu_clone_if_t;

typedef struct {
    bool     valid;
    uint8_t  device[18];                     /* device descriptor */
    uint8_t  config[MAKCU_CLONE_CONFIG_MAX];
    uint16_t config_len;
    uint8_t  report[MAKCU_CLONE_REPORT_MAX];
    uint16_t report_len;
    /* Report ID convention of the cloned report descriptor: 0 means the
     * descriptor has no Report ID item, so reports must go out raw (tud_hid_
     * report(0, ...)).  The built-in composite descriptor uses IDs 1 (mouse) and
     * 2 (keyboard); a cloned mouse descriptor normally has none. */
    uint8_t  report_id;
    uint8_t  string_count;
    /* true when the descriptors were read off the device itself (auto-clone):
     * then the incoming reports use exactly this layout and must be forwarded
     * byte-for-byte, whatever the mouse happens to be. */
    bool     from_device;
    char     strings[4][24];                 /* manufacturer, product, serial */
    uint16_t vid_ovr;                        /* 0 = use the device's own VID/PID */
    uint16_t pid_ovr;
    uint8_t  if_count;                       /* interfaces captured (1..2) */
    makcu_clone_if_t ifs[MAKCU_CLONE_IF_MAX];
} makcu_clone_t;

/* NULL-able view of the active clone (valid == false means "use defaults"). */
const makcu_clone_t *makcu_clone_get(void);

/* Bench hook: writable view (used to retarget the cloned identity). */
makcu_clone_t *makcu_clone_mutable(void);

/* Canned identities for the bench. */
enum {
    MAKCU_CLONE_FIXTURE_NONE = 0,
    MAKCU_CLONE_FIXTURE_MOUSE_A = 1,         /* 046D:C077, 4-byte mouse report */
    MAKCU_CLONE_FIXTURE_MOUSE_B,             /* 046D:C52F, 5-byte mouse report */
    MAKCU_CLONE_FIXTURE_REAL,                /* the mouse actually behind the box */
    MAKCU_CLONE_FIXTURE_G3M                  /* G3M PRO report layout (7-byte, 16-bit) */
};

/* Load a canned identity (returns false for an unknown id). */
bool makcu_clone_apply_fixture(int which);

/* True when the active fixture declares the same report layout the right chip
 * forwards (5-byte 12-bit X/Y), i.e. the payload can be sent verbatim. */
bool makcu_clone_wants_raw_report(void);

/* Record one captured HID interface (index < MAKCU_CLONE_IF_MAX). */
/* Optional VID/PID override, kept in NVS so it survives reflashing.
 * Needed when the physical device's identity has no matching host INF (a 2.4G
 * receiver reports ids like 0E8C:F0DA whose product id even drifts), while the
 * management app keys on the vendor's own id.  `clear` restores faithful
 * cloning. */
/* Identity policy: some receivers report an id that no host INF matches while
 * the same hardware also reports the vendor's own id (which does).  Map such
 * families onto the INF-matched id automatically, so nothing has to be pinned
 * by hand.  Returns true when the descriptor was rewritten. */
bool makcu_clone_apply_id_policy(uint8_t device[18]);

/* USB serial number used for the cloned device.  The physical mouse has none, and
 * a fixed constant makes every box look like the same device to the host (stale
 * instances, and two boxes on one PC collide).  This is generated once from the
 * chip MAC plus randomness, then kept in NVS so it stays stable across reboot and
 * reflash while being unique per unit.  12 chars, same length as before. */
void makcu_clone_serial_get(char out[13]);

void makcu_clone_identity_override_load(void);
bool makcu_clone_identity_override_save(uint16_t vid, uint16_t pid);

bool makcu_clone_set_interface(uint8_t index, uint8_t ep_in,
                               const uint8_t *report, uint16_t report_len,
                               uint8_t report_id);

/* Build the active clone from descriptors read off the wire (auto-clone). */
bool makcu_clone_adopt(const uint8_t *device, size_t device_len,
                       const uint8_t *config, size_t config_len,
                       const uint8_t *report, size_t report_len,
                       const char *manufacturer, const char *product,
                       const char *serial, uint8_t report_id);

/* Drop the clone and go back to the built-in descriptors. */
void makcu_clone_clear(void);

/* Install the HID report descriptor bytes that arrived over the link. */
bool makcu_clone_set_report(const uint8_t *data, uint16_t len);

/* Install the device descriptor bytes that arrived over the link. */
bool makcu_clone_set_device(const uint8_t *data, uint16_t len);

#endif /* MAKCU_CLONE_H */
