/* Reply builder for the right chip's frame_forward (0x4200F6C4).
 *
 * Pure C, no IDF dependency: the right chip has only one board here, so the same
 * function is also called from the left chip's `mx.rf` bench command.  That way
 * the reply bytes are verified on hardware even though app_right cannot be
 * flashed without the second chip.
 *
 * Wire format:  5A <cmd> <len:u16> <payload>
 *
 *   oversized payload (> MAKCU_LINK_MAX_FIELD)   5A <cmd> 01 00 FF   (no dispatch)
 *   0xA0  0x4200FAC0   5A A0 01 00 <dir>     dir = st->ep0_dir ? 00 : FF
 *   0xA1  0x4200F6C4   5A A1 01 00 FF        (len < 8; the >= 8 URB path is TODO)
 *   0x1A  0x4200F854   error while no device is attached
 *   0xA3  0x4200FAE0   5A A3 01 00 00        (also raises st->reattach)
 *   0xA4  0x4200FE44   error when len >= 0x15 or no device is attached
 *   0xB1               5A B1 00 00            (header only)
 *   other 0x420248E4   5A <cmd> 01 00 FF
 */
#ifndef MAKCU_RIGHT_FRAMES_H
#define MAKCU_RIGHT_FRAMES_H

#include <stddef.h>
#include <stdint.h>

#include "makcu_link.h"

/* Host-side state the original reads while building replies:
 *   ready    DAT_42000d28+4  a device is attached
 *   session  *DAT_42000d2c   0x1A snapshot / 0xA4 config need it
 *   ep0_dir  *DAT_42000d88   0xA0 direction
 *   reattach *DAT_42000d48   set by 0xA3
 */
typedef struct {
    uint8_t ready;
    uint8_t session;
    uint8_t ep0_dir;
    uint8_t reattach;
} makcu_right_state_t;

/* Build the reply for one incoming frame.  Returns the total bytes written
 * (payload + 4) or 0 when out is too small / NULL. */
size_t makcu_right_reply(uint8_t cmd, const uint8_t *payload, uint16_t len,
                         makcu_right_state_t *st, uint8_t *out, size_t out_size);

#endif /* MAKCU_RIGHT_FRAMES_H */
