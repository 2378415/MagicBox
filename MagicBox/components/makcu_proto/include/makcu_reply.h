/* Reply framing, recovered from uart0_reply (0x420143E8).
 *
 * Observed on the wire (old repo docs/dynamic_tests.md):
 *     .km.version()   ->  km.MAKCU\r\n>>> 
 *     .km.serial()    ->  km.Mouse does not have a serial number\n\r\n>>> 
 *     .km.buttons()   ->  km.buttons()\n0\r\n>>> 
 *
 * So the framing is:  "km." + content + "\r\n>>> "
 * and handlers are called with the line *after* the leading "km." has been
 * stripped by the frame consumer.  Handlers that append a status byte build
 * "<name>\n<digit>" themselves and pass it as content; handlers that just echo
 * pass their whole argument text.
 *
 * The writer is injected by the platform layer so this component stays free of
 * IDF headers and can be unit tested on the host.
 */
#ifndef MAKCU_REPLY_H
#define MAKCU_REPLY_H

#include <stddef.h>
#include <stdint.h>

#define MAKCU_REPLY_PREFIX   "km."
#define MAKCU_REPLY_SUFFIX   "\r\n>>> "
#define MAKCU_REPLY_MAX      640   /* 2 + 0x259 + 9 in the original frame */

typedef void (*makcu_write_fn)(const void *data, size_t len);

/* Install the transport used by the reply helpers (UART0 in the app). */
void makcu_reply_set_writer(makcu_write_fn fn);

/* Compose "km." + content + "\r\n>>> " into out (NUL terminated).
 * Returns the number of bytes to transmit, or 0 when it does not fit. */
size_t makcu_reply_format(char *out, size_t out_size, const char *content, size_t content_len);

/* Format and transmit. Both return the number of bytes sent (0 when dropped). */
size_t makcu_reply(const char *content, size_t content_len);
size_t makcu_reply_echo(const char *buf, int len);

/* Reply "<name>\n<digit>" - cmd_reply_status (0x4200DC18).  The buttons family
 * is normalised to "buttons()" exactly like the original. */
size_t makcu_reply_status(const char *name, int name_len, uint8_t status);

#endif /* MAKCU_REPLY_H */
