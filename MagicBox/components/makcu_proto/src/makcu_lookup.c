/* Prefix matcher - reimplementation of cmd_lookup (0x4200EEC4).
 *
 * Original pseudocode (docs/命令协议 §1):
 *     entry = table;
 *     do {
 *         len = entry->len;
 *         if (len <= input_len && strncmp(input, entry->name, len) == 0) return entry;
 *         entry = (entry_t*)((char*)entry + 0x14);
 *     } while (entry->name != NULL);
 *     return NULL;
 *
 * Consequences that the regression suite pins down:
 *   - matching is a *prefix* test, so ".km.version" (no brackets) works;
 *   - the first matching row wins, which is why "lock_mx()" is listed before
 *     "lock_mx(" and "buttons()" before "buttons(";
 *   - a miss returns NULL and the dispatcher emits *nothing* (`.km.foobar()`).
 */
#include "makcu_cmd.h"

#include <string.h>

const makcu_cmd_t *makcu_lookup(const char *buf, int len, int *skip)
{
    if (buf == NULL || len <= 0) {
        return NULL;
    }
    for (unsigned i = 0; i < makcu_cmd_count; i++) {
        const makcu_cmd_t *e = &makcu_cmd_table[i];
        if (e->name == NULL || e->len == 0 || (int)e->len > len) {
            continue;
        }
        if (memcmp(buf, e->name, e->len) == 0) {
            if (skip != NULL) {
                *skip = (int)e->len;
            }
            return e;
        }
    }
    return NULL;
}
