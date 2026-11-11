p="components/makcu_dev/include/makcu_dev.h"
t=open(p,encoding="utf-8").read()
if "makcu_map_write" not in t:
    t=t.replace("""/* 0x4202D26C: bit0 = catch slot set, bit1 = axis slot set */
uint8_t  makcu_button_flags(makcu_dev_t *dev, int target);""",
"""/* 0x4202D26C: bit0 = catch slot set, bit1 = axis slot set */
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
void     makcu_desc_set_enabled(makcu_dev_t *dev, int idx, int on);""")
    open(p,"w",encoding="utf-8").write(t)

p="components/makcu_dev/src/makcu_dev.c"
t=open(p,encoding="utf-8").read()
if "makcu_map_write" not in t:
    t=t.replace("uint8_t makcu_button_flags(makcu_dev_t *dev, int target)",
"""volatile uint8_t makcu_resend_flag;

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

uint8_t makcu_button_flags(makcu_dev_t *dev, int target)""")
    open(p,"w",encoding="utf-8").write(t)

# wheel hook
p="components/makcu_proto/include/makcu_mouse_hooks.h"
t=open(p,encoding="utf-8").read()
if "makcu_wheel_fn" not in t:
    t=t.replace("extern makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;",
"""extern makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;

/* 0x4200F96C wheel_submit: store the int8 delta, raise the commit request. */
typedef int (*makcu_wheel_fn)(void *dev, int8_t delta);
extern makcu_wheel_fn          makcu_wheel_hook;""")
    open(p,"w",encoding="utf-8").write(t)
p="components/makcu_proto/src/makcu_mouse_hooks.c"
t=open(p,encoding="utf-8").read()
if "makcu_wheel_hook" not in t:
    t=t.replace("makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;",
"makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;\nmakcu_wheel_fn          makcu_wheel_hook;")
    open(p,"w",encoding="utf-8").write(t)
print("dev + wheel hook extended")
