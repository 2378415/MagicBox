/* Minimal device context for the text handlers.
 *
 * The original keeps everything behind two pointers inside the device struct
 * (offsets recovered in docs/20-types.md):
 *
 *   dev+0x210  -> channel/axis slot table
 *                 +0x54  + target*4   channel enable slot   (target 1..5)
 *                 +0x9C  + target*4   axis slot             (target 1..16)
 *                 +0x124 + target*4   catch slot (read by button_flags_get)
 *                 +0x168 + target*4   catch slot (written by catch_set)
 *   dev+0x214  -> descriptor / big table
 *                 +0x269 + idx        enable bit  (idx 0..255)
 *                 +0x369 + idx        present bit
 *                 +0x636 + idx        third flag set
 *
 * Until the USB/HID layer is ported the rebuild provides a zeroed context, which
 * is exactly the state of a freshly booted device: no channel enabled, buttons
 * mode 0.  That is enough for the handlers to behave like the real firmware on
 * the wire (they see the same "slot is empty" branches).
 */
#ifndef MAKCU_DEV_H
#define MAKCU_DEV_H

#include <stdint.h>

#define MAKCU_DEV_TBL_SIZE   0x200
#define MAKCU_DEV_DESC_SIZE  0x740

typedef struct {
    uint8_t tbl[MAKCU_DEV_TBL_SIZE];    /* dev+0x210 */
    uint8_t desc[MAKCU_DEV_DESC_SIZE];  /* dev+0x214 */
    uint8_t buttons_mode;               /* DAT_42000E8C */
    uint8_t dirty;                      /* DAT_42000DAC */
} makcu_dev_t;

/* Create (once) and return the singleton context used by the app. */
makcu_dev_t *makcu_dev_instance(void);
void makcu_dev_reset(void);

/* Slot helpers - all of them mirror the original guards (null context or a
 * zero slot means "no such channel"). */
void    *makcu_chan_slot(makcu_dev_t *dev, int target);      /* +0x54 */
void    *makcu_axis_slot(makcu_dev_t *dev, int target);      /* +0x9C */
int      makcu_catch_get(makcu_dev_t *dev, int target);      /* +0x124 (flags bit0) */
void     makcu_catch_set(makcu_dev_t *dev, int target, int on); /* +0x168 */

/* Writers, offsets from the original setters:
 *   channel_slot_set (0x4200F9C4): uint32 at +0x54 + target*4, target 1..5
 *   axis_slot_set    (0x4200FA50): uint32 at +0x9C + target*4, target 1..16
 *   FUN_4200F9F8 / FUN_4200FA24  : *byte* at +0x9C / +0x9D (the mx/my pair) */
void     makcu_channel_slot_set(makcu_dev_t *dev, int target, int on);
void     makcu_axis_slot_set(makcu_dev_t *dev, int target, int on);
void     makcu_axis_byte_set(makcu_dev_t *dev, int axis, int on);
int      makcu_axis_byte_get(makcu_dev_t *dev, int axis);

/* 0x42010C44 / 0x42010C64: buttons mode flag (DAT_42000E8C) */
void     makcu_buttons_set(makcu_dev_t *dev, int on);
uint8_t  makcu_buttons_get(makcu_dev_t *dev);

/* 0x4202D26C: bit0 = catch slot set, bit1 = axis slot set */
uint8_t  makcu_button_flags(makcu_dev_t *dev, int target);

/* Mapping table in the descriptor block (dev+0x214):
 *   map_entry_write   (0x4202D4DC): desc[idx + 0x63]  = value
 *   map_entry_write16 (0x4202D4A8): desc[addr + 0x163] = 0/1
 * The channel tables used by cmd_dump_channels / cmd_channel_toggle sit at
 * desc[+0x269] (enable), desc[+0x369] (present) and dev[+0x636] (third flag). */
void     makcu_map_write(makcu_dev_t *dev, int idx, int value);
void     makcu_map_write16(makcu_dev_t *dev, int addr, int value);

/* 0x3FC99FA3: "configuration changed, resend it" flag. */
extern volatile uint8_t makcu_resend_flag;

/* desc[+0x269] / desc[+0x369] / dev[+0x636] accessors for the channel tables. */
int      makcu_desc_enabled(makcu_dev_t *dev, int idx);
int      makcu_desc_present(makcu_dev_t *dev, int idx);
int      makcu_desc_flag(makcu_dev_t *dev, int idx);
void     makcu_desc_set_enabled(makcu_dev_t *dev, int idx, int on);

#endif /* MAKCU_DEV_H */
