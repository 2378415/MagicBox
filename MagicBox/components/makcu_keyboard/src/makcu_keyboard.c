/* Keyboard output layer - see include/makcu_keyboard.h. */
#include "makcu_keyboard.h"

#include "makcu_kbd_hooks.h"
#include "makcu_usage.h"

#include "esp_random.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <string.h>

/* HID usage ids for the modifiers. */
#define MOD_LEFT_CTRL   0x01
#define MOD_LEFT_SHIFT  0x02
#define MOD_LEFT_ALT    0x04
#define MOD_LEFT_GUI    0x08

makcu_kbd_emit_fn makcu_kbd_emit_hook;

static uint8_t s_report[MAKCU_KBD_REPORT_LEN];       /* modifiers, 0, 6 usages */
static uint8_t s_trace[MAKCU_KBD_TRACE][MAKCU_KBD_REPORT_LEN];
static unsigned s_trace_count;
static unsigned s_trace_pos;
static uint8_t s_trace_ordered[MAKCU_KBD_TRACE * MAKCU_KBD_REPORT_LEN];

const uint8_t *makcu_keyboard_report(void)
{
    return s_report;
}

const uint8_t *makcu_keyboard_trace(unsigned *count)
{
    const unsigned n = s_trace_count;
    const unsigned start = (n == MAKCU_KBD_TRACE) ? s_trace_pos : 0;
    for (unsigned i = 0; i < n; i++) {
        memcpy(&s_trace_ordered[i * MAKCU_KBD_REPORT_LEN],
               s_trace[(start + i) % MAKCU_KBD_TRACE], MAKCU_KBD_REPORT_LEN);
    }
    if (count != NULL) {
        *count = n;
    }
    return s_trace_ordered;
}

static void flush(void)
{
    memcpy(s_trace[s_trace_pos], s_report, MAKCU_KBD_REPORT_LEN);
    s_trace_pos = (s_trace_pos + 1) % MAKCU_KBD_TRACE;
    if (s_trace_count < MAKCU_KBD_TRACE) {
        s_trace_count++;
    }
    if (makcu_kbd_emit_hook != NULL) {
        makcu_kbd_emit_hook(s_report);
    }
}

/* ------------------------------------------------------------- 6KRO state */
static int is_modifier(uint16_t usage)
{
    return usage >= 0xE0 && usage <= 0xE7;
}

static uint8_t modifier_bit(uint16_t usage)
{
    switch (usage) {
    case 0xE0: return MOD_LEFT_CTRL;
    case 0xE1: return MOD_LEFT_SHIFT;
    case 0xE2: return MOD_LEFT_ALT;
    case 0xE3: return MOD_LEFT_GUI;
    case 0xE4: return 0x10;     /* right ctrl  */
    case 0xE5: return 0x20;     /* right shift */
    case 0xE6: return 0x40;     /* right alt   */
    case 0xE7: return 0x80;     /* right gui   */
    default:   return 0;
    }
}

static void key_add(uint16_t usage)
{
    if (usage == 0) {
        return;
    }
    if (is_modifier(usage)) {
        s_report[0] |= modifier_bit(usage);            /* hid_report_set_bits */
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (s_report[2 + i] == (uint8_t)usage) {
            return;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (s_report[2 + i] == 0) {
            s_report[2 + i] = (uint8_t)usage;
            return;
        }
    }
    /* all six slots taken: the original drops the new key as well */
}

static void key_remove(uint16_t usage)
{
    if (usage == 0) {
        return;
    }
    if (is_modifier(usage)) {
        s_report[0] &= (uint8_t)~modifier_bit(usage);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (s_report[2 + i] == (uint8_t)usage) {
            s_report[2 + i] = 0;
            return;
        }
    }
}

static int key_is_down(uint16_t usage)
{
    if (is_modifier(usage)) {
        return (s_report[0] & modifier_bit(usage)) != 0;
    }
    for (int i = 0; i < 6; i++) {
        if (s_report[2 + i] == (uint8_t)usage) {
            return 1;
        }
    }
    return 0;
}

/* --------------------------------------------------------------- hooks */
static int hook_key_down(void *dev, uint16_t usage)
{
    (void)dev;
    key_add(usage);
    flush();
    return 0;
}

static int hook_key_up(void *dev, uint16_t usage)
{
    (void)dev;
    key_remove(usage);
    flush();
    return 0;
}

static int hook_key_tap(void *dev, uint16_t usage, int min_ms, int max_ms)
{
    (void)dev;
    if (min_ms < 0) {
        min_ms = 0;
    }
    if (max_ms < min_ms) {
        max_ms = min_ms;
    }
    const uint32_t span = (uint32_t)(max_ms - min_ms) + 1u;
    const uint32_t delay = (uint32_t)min_ms + (esp_random() % span);
    key_add(usage);
    flush();
    vTaskDelay(pdMS_TO_TICKS(delay));
    key_remove(usage);
    flush();
    return 0;
}

static int hook_type_string(void *dev, const char *text, int len)
{
    (void)dev;
    for (int i = 0; i < len; i++) {
        const uint8_t c = (uint8_t)text[i];
        const uint16_t usage = makcu_char_to_usage(c);
        if (usage == 0) {
            continue;
        }
        const int shifted = (c >= 'A' && c <= 'Z');
        if (shifted) {
            key_add(0xE1);
        }
        key_add(usage);
        flush();
        vTaskDelay(pdMS_TO_TICKS(8));
        key_remove(usage);
        if (shifted) {
            key_remove(0xE1);
        }
        flush();
    }
    return 0;
}

static int hook_keys_down(void *dev, const int16_t *usages, int count)
{
    (void)dev;
    for (int i = 0; i < count && i < 6; i++) {
        key_add((uint16_t)usages[i]);
    }
    flush();
    return 0;
}

static int hook_keys_up(void *dev, const int16_t *usages, int count)
{
    (void)dev;
    for (int i = 0; i < count && i < 6; i++) {
        key_remove((uint16_t)usages[i]);
    }
    flush();
    return 0;
}

static int hook_keys_combo(void *dev, const int16_t *usages, int count,
                           int min_ms, int max_ms)
{
    (void)dev;
    if (min_ms < 0) {
        min_ms = 0;
    }
    if (max_ms < min_ms) {
        max_ms = min_ms;
    }
    for (int i = 0; i < count && i < 6; i++) {
        key_add((uint16_t)usages[i]);
    }
    flush();
    const uint32_t span = (uint32_t)(max_ms - min_ms) + 1u;
    vTaskDelay(pdMS_TO_TICKS((uint32_t)min_ms + (esp_random() % span)));
    for (int i = count - 1; i >= 0; i--) {
        key_remove((uint16_t)usages[i]);
    }
    flush();
    return 0;
}

static int hook_key_state(void *dev, uint16_t usage)
{
    (void)dev;
    return key_is_down(usage);
}

void makcu_keyboard_init(void)
{
    memset(s_report, 0, sizeof(s_report));
    makcu_key_down_hook = hook_key_down;
    makcu_key_up_hook = hook_key_up;
    makcu_key_tap_hook = hook_key_tap;
    makcu_type_string_hook = hook_type_string;
    makcu_keys_down_hook = hook_keys_down;
    makcu_keys_up_hook = hook_keys_up;
    makcu_keys_combo_hook = hook_keys_combo;
    makcu_key_state_hook = hook_key_state;
}
