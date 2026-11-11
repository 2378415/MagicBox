/* Device context - see include/makcu_dev.h for the offset map. */
#include "makcu_dev.h"

#include <string.h>

static makcu_dev_t s_dev;

makcu_dev_t *makcu_dev_instance(void)
{
    return &s_dev;
}

void makcu_dev_reset(void)
{
    memset(&s_dev, 0, sizeof(s_dev));
}

/* All slot helpers keep the original "0 means absent" convention. */
void *makcu_chan_slot(makcu_dev_t *dev, int target)
{
    if (dev == NULL || target < 1 || target > 5) {
        return NULL;
    }
    uint32_t word;
    memcpy(&word, dev->tbl + 0x54 + target * 4, sizeof(word));
    return (word == 0) ? NULL : (void *)(uintptr_t)word;
}

void *makcu_axis_slot(makcu_dev_t *dev, int target)
{
    if (dev == NULL || target < 1 || target > 16) {
        return NULL;
    }
    uint32_t word;
    memcpy(&word, dev->tbl + 0x9C + target * 4, sizeof(word));
    return (word == 0) ? NULL : (void *)(uintptr_t)word;
}

int makcu_catch_get(makcu_dev_t *dev, int target)
{
    if (dev == NULL || target < 1 || target > 16) {
        return 0;
    }
    uint32_t word;
    memcpy(&word, dev->tbl + 0x124 + target * 4, sizeof(word));
    return word != 0;
}

void makcu_catch_set(makcu_dev_t *dev, int target, int on)
{
    if (dev == NULL || target < 1 || target > 5) {
        return;
    }
    const uint32_t word = on ? 1u : 0u;
    memcpy(dev->tbl + 0x168 + target * 4, &word, sizeof(word));
}

void makcu_channel_slot_set(makcu_dev_t *dev, int target, int on)
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

void makcu_buttons_set(makcu_dev_t *dev, int on)
{
    if (dev == NULL) {
        return;
    }
    dev->buttons_mode = on ? 1 : 0;
}

uint8_t makcu_buttons_get(makcu_dev_t *dev)
{
    return (dev == NULL) ? 0 : dev->buttons_mode;
}

volatile uint8_t makcu_resend_flag;

void makcu_map_write(makcu_dev_t *dev, int idx, int value)
{
    if (dev == NULL || idx < 0 || idx > 0xFF) {
        return;
    }
    dev->desc[idx + 0x63] = (uint8_t)(value & 0xFF);
}

void makcu_map_write16(makcu_dev_t *dev, int addr, int value)
{
    if (dev == NULL || addr < 0 || addr > 0xFF || (value != 0 && value != 1)) {
        return;
    }
    dev->desc[addr + 0x163] = (uint8_t)value;
}

int makcu_desc_enabled(makcu_dev_t *dev, int idx)
{
    return (dev != NULL && idx >= 0 && idx <= 0xFF && dev->desc[idx + 0x269] != 0);
}

int makcu_desc_present(makcu_dev_t *dev, int idx)
{
    return (dev != NULL && idx >= 0 && idx <= 0xFF && dev->desc[idx + 0x369] != 0);
}

int makcu_desc_flag(makcu_dev_t *dev, int idx)
{
    return (dev != NULL && idx >= 0 && idx <= 0xFF && dev->desc[idx + 0x636] != 0);
}

void makcu_desc_set_enabled(makcu_dev_t *dev, int idx, int on)
{
    if (dev != NULL && idx >= 0 && idx <= 0xFF) {
        dev->desc[idx + 0x269] = (uint8_t)(on ? 1 : 0);
    }
}

uint8_t makcu_button_flags(makcu_dev_t *dev, int target)
{
    if (dev == NULL || target < 1 || target > 16) {
        return 0;
    }
    uint32_t catch_word = 0, axis_word = 0;
    memcpy(&catch_word, dev->tbl + 0x124 + target * 4, sizeof(catch_word));
    memcpy(&axis_word, dev->tbl + 0x9C + target * 4, sizeof(axis_word));
    return (uint8_t)((catch_word != 0) | ((axis_word != 0) << 1));
}
