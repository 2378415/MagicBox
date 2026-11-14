/* TinyUSB configuration for the MAKCU rebuild (device side, HID only).
 *
 * The original left chip enumerates as a HID mouse whose report descriptor is
 * cloned from the real device.  Clone-on-boot is not ported yet, so this build
 * uses a standard 4-byte mouse report (buttons, dx, dy, wheel) and the same
 * VID/PID family the box uses.
 */
#ifndef TUSB_CONFIG_H
#define TUSB_CONFIG_H

#define CFG_TUSB_MCU                OPT_MCU_ESP32S3
#define CFG_TUSB_OS                 OPT_OS_FREERTOS
#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED)

#ifdef MB_TUSB_DEBUG
#define CFG_TUSB_DEBUG              MB_TUSB_DEBUG
#endif

#define CFG_TUD_ENDPOINT0_SIZE      64
#define CFG_TUD_ENABLED             1
/* MB_DUAL_IF=1 serves the cloned device's full composite configuration
 * (mouse + keyboard/vendor interface, see D38); the default stays single so the
 * verified bench configuration is untouched. */
#ifndef CFG_TUD_HID
#if defined(MB_DUAL_IF)
#define CFG_TUD_HID                 2
#else
#define CFG_TUD_HID                 1
#endif
#endif
#define CFG_TUD_HID_EP_BUFSIZE      64

#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_ALIGN          __attribute__ ((aligned(4)))

#endif /* TUSB_CONFIG_H */
