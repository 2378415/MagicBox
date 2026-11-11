/* cmd_catch_query - opcode 0x0B, handler 0x4200DFF0.
 *
 * Decompiled:
 *     if (dev == 0 || dev->tbl == 0) return;             // silence
 *     base = dev->tbl + entry->target * 4;
 *     if      (*(uint32_t *)(base + 0x54)  == 0) status = 0;   // channel off
 *     else if (*(uint32_t *)(base + 0x168) == 0) status = 0;   // catch off
 *     else if (*(uint32_t *)(base + 0x124) != 0) status = 1;   // catch armed
 *     cmd_reply_status(entry->name, entry->len, status);
 *
 * Note the third term: +0x124 is the "armed" slot that button_flags_get also
 * reads, while +0x168 is what catch_set() writes.  A device that only ran
 * catch_ml(1) therefore still reports 0 until the armed slot is set elsewhere.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

void cmd_catch_query(const char *buf, int len, void *dev_ptr,
                     const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)buf;
    (void)len;
    (void)arg;
    (void)arglen;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (dev == NULL || entry == NULL) {
        return;
    }
    const int target = (int)entry->target;
    uint8_t status = 0;
    if (makcu_chan_slot(dev, target) != NULL          /* +0x54 channel enabled */
        && makcu_catch_get(dev, target)) {            /* +0x124 armed */
        status = 1;
    }
    makcu_reply_status(entry->name, (int)entry->len, status);
}
