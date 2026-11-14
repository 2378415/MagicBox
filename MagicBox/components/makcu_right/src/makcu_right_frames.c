/* Reply builder for the right chip - see include/makcu_right_frames.h. */
#include "makcu_right_frames.h"

#include <string.h>

static size_t put(uint8_t *out, size_t cap, uint8_t cmd, const uint8_t *p, uint16_t n)
{
    if (out == NULL || cap < (size_t)n + MAKCU_LINK_HEADER) {
        return 0;
    }
    out[0] = MAKCU_LINK_MAGIC;
    out[1] = cmd;
    out[2] = (uint8_t)(n & 0xFF);
    out[3] = (uint8_t)(n >> 8);
    if (p != NULL && n != 0) {
        memcpy(&out[MAKCU_LINK_HEADER], p, n);
    }
    return (size_t)n + MAKCU_LINK_HEADER;
}

size_t makcu_right_reply(uint8_t cmd, const uint8_t *payload, uint16_t len,
                         makcu_right_state_t *st, uint8_t *out, size_t out_size)
{
    const uint8_t error = 0xFF;
    const uint8_t zero = 0x00;
    const uint8_t dir_in = 0x00;
    const uint8_t dir_out = 0xFF;
    const uint8_t ready = (st != NULL) ? st->ready : 0;
    const uint8_t session = (st != NULL) ? st->session : 0;
    const uint8_t ep0 = (st != NULL) ? st->ep0_dir : 0;

    (void)payload;

    /* 0x4200F6C4: an oversized frame is answered before dispatch. */
    if (len > MAKCU_LINK_MAX_FIELD) {
        return put(out, out_size, cmd, &error, 1);
    }

    switch (cmd) {
    case MAKCU_LINK_EP0:
        return put(out, out_size, cmd, ep0 ? &dir_in : &dir_out, 1);

    case MAKCU_LINK_ACK:
        /* len < 8 -> error; len >= 8 goes through FUN_4200FC74 (URB path, TODO). */
        return put(out, out_size, cmd, &error, 1);

    case MAKCU_LINK_SNAPSHOT:
        /* FUN_4200F854: without an attached device/session it answers the error
         * byte; otherwise "<status><string>" with len = min(strlen,0x14)+1. */
        if (!ready || !session) {
            return put(out, out_size, cmd, &error, 1);
        }
        return put(out, out_size, cmd, &error, 1);   /* TODO: snapshot body */

    case MAKCU_LINK_A3:
        if (st != NULL) {
            st->reattach = 1;
        }
        return put(out, out_size, cmd, &zero, 1);

    case MAKCU_LINK_CONFIG:
        /* FUN_4200FE44 -> FUN_4200F804: payload < 0x15 and a device attached,
         * otherwise the error byte.  The NVS write itself is TODO. */
        if (len >= 0x15 || !ready || !session) {
            return put(out, out_size, cmd, &error, 1);
        }
        return put(out, out_size, cmd, &error, 1);   /* TODO: config write */

    case MAKCU_LINK_B1:
        return put(out, out_size, cmd, NULL, 0);

    default:
        return put(out, out_size, cmd, &error, 1);
    }
}
