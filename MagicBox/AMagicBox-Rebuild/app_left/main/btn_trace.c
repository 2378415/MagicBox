#include "btn_trace.h"

#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/portmacro.h"
#include <string.h>

#define BTN_TRACE_DEPTH 64

static btn_trace_entry_t s_ring[BTN_TRACE_DEPTH];
static volatile uint16_t s_head;     /* 下一条写入位置 */
static volatile uint16_t s_total;    /* 累计写入条数（用于 since 序号） */
static portMUX_TYPE s_lock = portMUX_INITIALIZER_UNLOCKED;

void btn_trace_add(uint8_t raw, uint8_t fwd, uint8_t src)
{
    portENTER_CRITICAL(&s_lock);
    btn_trace_entry_t *e = &s_ring[s_head];
    e->t_us = (uint32_t)esp_timer_get_time();
    e->raw = (uint8_t)(raw & 0x1Fu);
    e->fwd = (uint8_t)(fwd & 0x1Fu);
    e->src = src;
    e->pad = 0;
    s_head = (uint16_t)((s_head + 1u) % BTN_TRACE_DEPTH);
    s_total++;
    portEXIT_CRITICAL(&s_lock);
}

uint16_t btn_trace_read(uint16_t since, btn_trace_entry_t *out, uint16_t max, uint16_t *total)
{
    if (out == NULL || max == 0) {
        if (total != NULL) {
            *total = s_total;
        }
        return 0;
    }
    portENTER_CRITICAL(&s_lock);
    const uint16_t total_now = s_total;
    /* 只保留最近 DEPTH 条 */
    uint16_t oldest = 0;
    if (total_now > BTN_TRACE_DEPTH) {
        oldest = (uint16_t)(total_now - BTN_TRACE_DEPTH);
    }
    uint16_t start = since;
    if (start < oldest) {
        start = oldest;
    }
    uint16_t n = 0;
    while (start < total_now && n < max) {
        const uint16_t idx = (uint16_t)((start % BTN_TRACE_DEPTH));
        out[n++] = s_ring[idx];
        start++;
    }
    portEXIT_CRITICAL(&s_lock);
    if (total != NULL) {
        *total = total_now;
    }
    return n;
}
