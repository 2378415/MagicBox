/* Inter-chip link (UART1) frame layer - portable C, no IDF dependency.
 *
 * Wire format (docs/uart1_link.md §6/§8):
 *
 *      +0   0x5A magic
 *      +1   command (0xA0 EP0 tunnel, 0xA1, 0xA2 HID report, 0xA3, 0x1A, 0xA4, 0xB1 ...)
 *      +2   u16 little-endian = number of bytes AFTER the 4-byte header
 *      +4   payload[ field ]
 *      total length = field + 4
 *
 * The receiver state machine below is the same shape as FUN_4200F514: a
 * zero-length field is a valid frame (header only).
 */
#ifndef MAKCU_LINK_H
#define MAKCU_LINK_H

#include <stddef.h>
#include <stdint.h>

#define MAKCU_LINK_MAGIC      0x5A
#define MAKCU_LINK_HEADER     4
#define MAKCU_LINK_MAX_FIELD  0x400      /* DAT_420004FC: buffer limit in the original */

/* command bytes */
#define MAKCU_LINK_EP0        0xA0
#define MAKCU_LINK_ACK        0xA1
#define MAKCU_LINK_HID        0xA2
#define MAKCU_LINK_A3         0xA3
#define MAKCU_LINK_SNAPSHOT   0x1A
#define MAKCU_LINK_CONFIG     0xA4
#define MAKCU_LINK_B1         0xB1

typedef struct {
    uint8_t  cmd;
    uint16_t len;                     /* payload length, header excluded */
    uint8_t  payload[MAKCU_LINK_MAX_FIELD];
} makcu_frame_t;

/* Build a frame into out.  Returns total bytes written (len + 4), 0 on overflow. */
size_t makcu_link_build(uint8_t *out, size_t out_size, uint8_t cmd,
                        const uint8_t *payload, uint16_t len);

/* Streaming parser: feed one byte at a time, emits complete frames.
 * Returns 1 and fills *frame when a frame completes, 0 otherwise. */
typedef struct {
    uint8_t  buf[MAKCU_LINK_HEADER + MAKCU_LINK_MAX_FIELD];
    uint16_t pos;                     /* bytes collected in buf */
    uint16_t field;                   /* declared payload length */
    uint16_t got;                     /* payload bytes collected */
} makcu_link_parser_t;

void makcu_link_parser_reset(makcu_link_parser_t *p);
int  makcu_link_parser_feed(makcu_link_parser_t *p, uint8_t byte, makcu_frame_t *frame);

#endif /* MAKCU_LINK_H */
