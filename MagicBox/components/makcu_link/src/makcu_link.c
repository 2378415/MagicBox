/* Inter-chip link frame layer - see include/makcu_link.h. */
#include "makcu_link.h"

#include <string.h>

size_t makcu_link_build(uint8_t *out, size_t out_size, uint8_t cmd,
                        const uint8_t *payload, uint16_t len)
{
    if (out == NULL || len > MAKCU_LINK_MAX_FIELD) {
        return 0;
    }
    if ((size_t)len + MAKCU_LINK_HEADER > out_size) {
        return 0;
    }
    out[0] = MAKCU_LINK_MAGIC;
    out[1] = cmd;
    out[2] = (uint8_t)(len & 0xFF);
    out[3] = (uint8_t)(len >> 8);
    if (payload != NULL && len != 0) {
        memcpy(out + MAKCU_LINK_HEADER, payload, len);
    }
    return (size_t)len + MAKCU_LINK_HEADER;
}

void makcu_link_parser_reset(makcu_link_parser_t *p)
{
    if (p == NULL) {
        return;
    }
    memset(p, 0, sizeof(*p));
}

int makcu_link_parser_feed(makcu_link_parser_t *p, uint8_t byte, makcu_frame_t *frame)
{
    if (p == NULL || frame == NULL) {
        return 0;
    }
    if (p->pos == 0) {                       /* hunting for the magic */
        if (byte != MAKCU_LINK_MAGIC) {
            return 0;
        }
        p->buf[0] = byte;
        p->pos = 1;
        return 0;
    }
    if (p->pos < MAKCU_LINK_HEADER) {        /* header */
        p->buf[p->pos++] = byte;
        if (p->pos == 3) {
            p->field = byte;                 /* len low  */
        } else if (p->pos == MAKCU_LINK_HEADER) {
            p->field |= (uint16_t)byte << 8; /* len high */
            if (p->field > MAKCU_LINK_MAX_FIELD) {
                makcu_link_parser_reset(p);  /* oversized: drop, resync */
                return 0;
            }
            if (p->field == 0) {             /* header-only frame */
                frame->cmd = p->buf[1];
                frame->len = 0;
                makcu_link_parser_reset(p);
                return 1;
            }
        }
        return 0;
    }
    p->buf[p->pos++] = byte;                 /* payload */
    if (++p->got == p->field) {
        frame->cmd = p->buf[1];
        frame->len = p->field;
        memcpy(frame->payload, p->buf + MAKCU_LINK_HEADER, p->field);
        makcu_link_parser_reset(p);
        return 1;
    }
    return 0;
}
