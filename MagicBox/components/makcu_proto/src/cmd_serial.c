/* cmd_serial - opcode 0x1A, handler 0x4200DC84.
 *
 * Jump-table-only entry, reconstructed by hand from the no-op-patched decompile
 * plus the string literals in the image:
 *
 *   0x3C036520  "Mouse does not have a serial number\n"   (0x24 bytes incl. NUL)
 *   0x3C03650C  "Original"
 *   0x3C036518  "Spoofed"
 *   0x3C0364F0  "%s Serial : %s"                          (format string)
 *
 * Behaviour:
 *   .km.serial()        query  -> "<type> Serial : <sn>"  or the failure text
 *   .km.serial()        with the argument being exactly ")" behaves the same
 *   .km.serial(0)       restore the factory serial, echoes the line on success
 *   .km.serial("<sn>")  store a spoofed serial (<= 0x14 chars), echoes on success
 *   any failure         replies the 0x24-byte failure string
 *
 * Measured reply on the original device (old repo dynamic_tests.md §11):
 *   km.Mouse does not have a serial number\n\r\n>>> 
 */
#include "makcu_cmd.h"
#include "makcu_reply.h"
#include "makcu_serial_hooks.h"

#include <stdio.h>
#include <string.h>

/* Literal at 0x3C036520, length 0x24 (the trailing NUL is part of the length the
 * original passes to uart0_reply). */
static const char kNoSerial[] = "Mouse does not have a serial number\n";

static void reply_no_serial(void)
{
    makcu_reply(kNoSerial, sizeof(kNoSerial));      /* 36 bytes, NUL included */
}

void cmd_serial(const char *buf, int len, void *dev,
                const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)dev;
    (void)entry;

    const int is_query = (arglen == 0) || (arglen == 1 && arg[0] == ')');

    if (is_query) {
        char text[0x15 + 1];
        uint8_t info[0x24];
        unsigned out_len = 0;

        memset(text, 0, sizeof(text));
        memset(info, 0, sizeof(info));
        if (makcu_serial_read_hook == NULL
            || !makcu_serial_read_hook(0, text, 0x15, &out_len, info)) {
            reply_no_serial();
            return;
        }
        char line[0x40];
        if (info[0] == 0xFF) {
            snprintf(line, sizeof(line), "%s", kNoSerial);
        } else if (info[0] < 2) {
            if (out_len < sizeof(text)) {
                text[out_len] = '\0';
            } else {
                text[sizeof(text) - 1] = '\0';
            }
            snprintf(line, sizeof(line), "%s Serial : %s",
                     info[0] != 0 ? "Spoofed" : "Original", text);
        } else {
            snprintf(line, sizeof(line), "Unknown indicator 0x%02X", info[0]);
        }
        makcu_reply(line, strlen(line));
        return;
    }

    int ok;
    if (arglen == 2 && arg[0] == '0' && arg[1] == ')') {
        ok = (makcu_serial_read_hook != NULL)
             && makcu_serial_read_hook(1, NULL, 0, NULL, NULL);   /* restore */
    } else {
        char text[0x14 + 1];
        int n = arglen;
        if (n > 0 && arg[n - 1] == ')') {
            n--;                                    /* strip the closing bracket */
        }
        if (n > 0x14) {
            n = 0x14;
        }
        memcpy(text, arg, (size_t)n);
        text[n] = '\0';
        ok = (makcu_serial_read_hook != NULL)
             && makcu_serial_read_hook(2, text, n, NULL, NULL);    /* write */
    }
    if (ok) {
        makcu_reply_echo(buf, len);
    } else {
        reply_no_serial();
    }
}
