/* The lock family - opcodes 0x00..0x03, handlers 0x4200DECC / DE40 / DF08 / DE60.
 *
 * Four handlers cover "set / query" x "button channel / axis":
 *
 *   0x00 cmd_lock_param0 (0x4200DECC)  lock_ml( / lock_mr( ... : set the channel
 *        flag.  `'1'` enables; anything else disables *and* clears the catch slot
 *        and the dirty flag:
 *            lock_set(dev, target, arg[0]=='1');        // channel_slot_set +0x54
 *            if (arg[0] != '1') { catch_set(dev,target,0); dirty = 0; }
 *            reply();
 *   0x01 cmd_lock_query (0x4200DE40)   lock_ml() ... : reply
 *            "<name>\n<digit>" where digit = (channel slot +0x54 != 0).
 *   0x02 cmd_lock_param2 (0x4200DF08)  lock_mx( / lock_my( : write the *byte*
 *        +0x9C (axis 1) or +0x9D (axis 2) through FUN_42010C08 / F9F8 / FA24.
 *   0x03 cmd_lock_axis (0x4200DE60)    lock_mx() / lock_my() : read that byte.
 *
 * The query/set pairs are exactly complementary, which is why the table lists
 * "lock_mx()" (query) before "lock_mx(" (set): the prefix matcher takes the
 * first hit.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

void cmd_lock_param0(const char *buf, int len, void *dev_ptr,
                     const makcu_cmd_t *entry, const char *arg, int arglen)
{
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen == 0 || entry == NULL) {
        return;
    }
    const int target = (int)entry->target;
    const int on = (arg[0] == '1');

    makcu_channel_slot_set(dev, target, on);        /* lock_set -> 0x4200F9C4 */
    if (!on) {
        makcu_catch_set(dev, target, 0);            /* catch_set -> 0x4202D1AC */
        if (dev != NULL) {
            dev->dirty = 0;                         /* *DAT_42000DAC = 0 */
        }
    }
    makcu_reply_echo(buf, len);
}

void cmd_lock_query(const char *buf, int len, void *dev_ptr,
                    const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)buf;
    (void)len;
    (void)arg;
    (void)arglen;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (dev == NULL || entry == NULL) {
        return;                                     /* original: no dev -> silence */
    }
    const uint8_t status = (uint8_t)(makcu_chan_slot(dev, (int)entry->target) != NULL);
    makcu_reply_status(entry->name, (int)entry->len, status);
}

void cmd_lock_param2(const char *buf, int len, void *dev_ptr,
                     const makcu_cmd_t *entry, const char *arg, int arglen)
{
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen == 0 || entry == NULL) {
        return;
    }
    const int axis = (int)entry->target;            /* 1 = mx, 2 = my */
    makcu_axis_byte_set(dev, axis, arg[0] == '1');  /* 0x42010C08 -> F9F8/FA24 */
    makcu_reply_echo(buf, len);
}

void cmd_lock_axis(const char *buf, int len, void *dev_ptr,
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
    const uint8_t status = (uint8_t)makcu_axis_byte_get(dev, (int)entry->target);
    makcu_reply_status(entry->name, (int)entry->len, status);
}
