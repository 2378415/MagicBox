p="components/makcu_dev/include/makcu_dev.h"
t=open(p,encoding="utf-8").read()
if "makcu_channel_slot_set" not in t:
    t=t.replace("""void     makcu_catch_set(makcu_dev_t *dev, int target, int on); /* +0x168 */""",
"""void     makcu_catch_set(makcu_dev_t *dev, int target, int on); /* +0x168 */

/* Writers, offsets from the original setters:
 *   channel_slot_set (0x4200F9C4): uint32 at +0x54 + target*4, target 1..5
 *   axis_slot_set    (0x4200FA50): uint32 at +0x9C + target*4, target 1..16
 *   FUN_4200F9F8 / FUN_4200FA24  : *byte* at +0x9C / +0x9D (the mx/my pair) */
void     makcu_channel_slot_set(makcu_dev_t *dev, int target, int on);
void     makcu_axis_slot_set(makcu_dev_t *dev, int target, int on);
void     makcu_axis_byte_set(makcu_dev_t *dev, int axis, int on);
int      makcu_axis_byte_get(makcu_dev_t *dev, int axis);""")
    open(p,"w",encoding="utf-8").write(t)

p="components/makcu_dev/src/makcu_dev.c"
t=open(p,encoding="utf-8").read()
if "makcu_channel_slot_set" not in t:
    t=t.replace("void makcu_buttons_set(makcu_dev_t *dev, int on)",
"""void makcu_channel_slot_set(makcu_dev_t *dev, int target, int on)
{
    if (dev == NULL || target < 1 || target > 5) {
        return;
    }
    const uint32_t word = (uint32_t)(on & 0xFF);
    memcpy(dev->tbl + 0x54 + target * 4, &word, sizeof(word));
}

void makcu_axis_slot_set(makcu_dev_t *dev, int target, int on)
{
    if (dev == NULL || target < 1 || target > 16) {
        return;
    }
    const uint32_t word = (uint32_t)(on & 0xFF);
    memcpy(dev->tbl + 0x9C + target * 4, &word, sizeof(word));
    dev->dirty = 1;                  /* *DAT_42000E04 = 1 + task notify */
}

void makcu_axis_byte_set(makcu_dev_t *dev, int axis, int on)
{
    if (dev == NULL || axis < 1 || axis > 2) {
        return;
    }
    dev->tbl[0x9B + axis] = (uint8_t)(on ? 1 : 0);
}

int makcu_axis_byte_get(makcu_dev_t *dev, int axis)
{
    if (dev == NULL || axis < 1 || axis > 2) {
        return 0;
    }
    return dev->tbl[0x9B + axis] != 0;
}

void makcu_buttons_set(makcu_dev_t *dev, int on)""")
    open(p,"w",encoding="utf-8").write(t)
print("dev extended")
