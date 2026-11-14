/* Serial-number backend hook.
 *
 * In the original, cmd_serial (0x4200DC84) delegates to serial_read (0x42010C84)
 * with three modes: 0 = query, 1 = restore factory serial, 2 = write the spoofed
 * serial.  The backend reads the HID descriptor / NVS, so it only exists once
 * makcu_hiddev is ported.  Until then the hook returns "no serial", which is the
 * same branch the original takes on a device that was never provisioned.
 */
#ifndef MAKCU_SERIAL_HOOKS_H
#define MAKCU_SERIAL_HOOKS_H

#include <stdint.h>

/* mode 0: fill buf/info.  Returns non-zero on success. */
typedef int (*makcu_serial_read_fn)(int mode, char *buf, int maxlen,
                                    unsigned *out_len, uint8_t *info);

extern makcu_serial_read_fn makcu_serial_read_hook;

#endif /* MAKCU_SERIAL_HOOKS_H */
