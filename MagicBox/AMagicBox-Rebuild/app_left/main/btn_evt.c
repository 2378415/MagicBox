/* 按键事件 + 订阅即消费 - 见 btn_evt.h。 */
#include "btn_evt.h"

#include <string.h>

#include "esp_log.h"
#include "esp_timer.h"

#define EVT_RING      32
#define EVT_HB_TIMEOUT_US  (10 * 1000 * 1000)   /* 10 s 无心跳 → 自动恢复透传 */

static const char *TAG = "btn_evt";

static btn_evt_t s_ring[EVT_RING];
static uint8_t   s_head;        /* 下一条写入位置 */
static uint8_t   s_tail;        /* 下一条读出位置 */
static uint8_t   s_count;

static uint16_t  s_seq;         /* 事件序号（只增不减） */
static uint32_t  s_overflow;

static bool      s_enabled;
static bool      s_push;
static bool      s_auto_released;
static uint8_t   s_mask;        /* 订阅的位（产生事件） */
static bool      s_consume;     /* true=吃掉这些位（PC 看不到）；false=只报事件、照常透传 */
static uint8_t   s_pending;     /* 订阅瞬间按住、仍在透传的位 */
static uint8_t   s_prev_watched;/* 上一拍的 watched 位（算边沿） */
static uint8_t   s_cur;         /* 最近一次真实按键位图 */
static uint8_t   s_last_fwd;    /* 最近一次转发给 PC 的按键字节 */

static volatile int64_t s_last_hb_us;
static btn_evt_push_fn  s_push_fn;
static esp_timer_handle_t s_timer;

void btn_evt_set_push_fn(btn_evt_push_fn fn)
{
    s_push_fn = fn;
}

bool btn_evt_enabled(void)
{
    return s_enabled;
}

uint8_t btn_evt_mask(void)
{
    return s_mask;
}

void btn_evt_heartbeat(void)
{
    s_last_hb_us = esp_timer_get_time();
}

void btn_evt_ctl(bool enable, uint8_t mask, bool push, bool consume)
{
    if (!enable) {
        if (s_enabled) {
            ESP_LOGI(TAG, "unsubscribed (was mask 0x%02x consume=%d)", s_mask, (int)s_consume);
        }
        s_enabled = false;
        s_push = false;
        s_consume = false;
        s_mask = 0;
        s_pending = 0;
        s_prev_watched = 0;
        return;
    }
    /* 只有"吃掉"模式才需要 pending：订阅瞬间已经按住的键先继续透传到松开，
     * 避免 PC 卡在"按下"。穿透模式下按键本来就照常发，pending 恒为 0。 */
    s_pending = consume ? (uint8_t)(s_cur & mask) : 0;
    s_mask = mask;
    s_push = push;
    s_consume = consume;
    s_enabled = true;
    s_auto_released = false;
    s_prev_watched = (uint8_t)(s_cur & mask);
    btn_evt_heartbeat();
    ESP_LOGI(TAG, "subscribed mask=0x%02x push=%d consume=%d pending=0x%02x",
             s_mask, (int)s_push, (int)s_consume, s_pending);
}

static void ring_push(uint32_t t_us, uint8_t mask, uint8_t edge)
{
    if (s_count >= EVT_RING) {
        /* 覆盖最旧，计数溢出；seq 不重置，上位机能算出掉了多少条 */
        s_tail = (uint8_t)((s_tail + 1) % EVT_RING);
        s_count--;
        s_overflow++;
    }
    s_ring[s_head].t_us = t_us;
    s_ring[s_head].seq = s_seq++;
    s_ring[s_head].mask = mask;
    s_ring[s_head].edge = edge;
    s_head = (uint8_t)((s_head + 1) % EVT_RING);
    s_count++;
}

/* 重置环形缓冲与统计（0x41 EVT_RESET）。 */
void btn_evt_reset_stats(void)
{
    s_head = 0;
    s_tail = 0;
    s_count = 0;
    s_seq = 0;
    s_overflow = 0;
}

uint8_t btn_evt_filter(uint8_t raw_buttons)
{
    s_cur = raw_buttons;

    uint8_t fwd = raw_buttons;
    if (s_enabled && s_mask != 0) {
        const uint8_t watched = (uint8_t)(raw_buttons & s_mask);
        const uint8_t edge = (uint8_t)(watched ^ s_prev_watched);

        if (s_consume) {
            /* 吃掉模式：被消费的位 = watched 里不属于"订阅时已按住"的那部分 */
            const uint8_t consumed = (uint8_t)(watched & ~s_pending);
            fwd = (uint8_t)(raw_buttons & ~consumed);
            /* 松开后不再需要透传：pending 只保留仍然按住的位 */
            s_pending = (uint8_t)(s_pending & raw_buttons);
        }
        /* 穿透模式（默认）：fwd 保持原样，只产生事件 */

        if (edge != 0) {
            const uint32_t now = (uint32_t)esp_timer_get_time();
            if (s_push && s_push_fn != NULL) {
                /* 推模式：事件走异步通道，不再入环。
                 * 以前两条路都写、又没人读环 → 环常年满，overflow 一直涨，
                 * 看起来像"在丢事件"，其实推通道一条没丢。 */
                s_seq++;
                s_push_fn((uint16_t)(s_seq - 1u), now, raw_buttons, edge);
            } else {
                ring_push(now, raw_buttons, edge);
            }
        }
        s_prev_watched = watched;
    } else {
        s_prev_watched = 0;
    }
    s_last_fwd = fwd;
    return fwd;
}

uint8_t btn_evt_read(uint8_t *out, uint8_t max)
{
    if (out == NULL || max == 0) {
        return 0;
    }
    uint8_t n = 0;
    while (n < max && s_count != 0) {
        memcpy(out + (size_t)n * sizeof(btn_evt_t), &s_ring[s_tail], sizeof(btn_evt_t));
        s_tail = (uint8_t)((s_tail + 1) % EVT_RING);
        s_count--;
        n++;
    }
    btn_evt_heartbeat();
    return n;
}

bool btn_evt_consume(void)
{
    return s_consume;
}

void btn_evt_stat(btn_evt_stat_t *st)
{
    if (st == NULL) {
        return;
    }
    st->enabled = s_enabled;
    st->consume = s_consume;
    st->push = s_push;
    st->auto_released = s_auto_released;
    st->mask = s_mask;
    st->pending = s_pending;
    st->cur = s_cur;
    st->last_fwd = s_last_fwd;
    st->head_seq = s_seq;
    st->count = s_count;
    st->overflow = s_overflow;
}

/* 失联保护：订阅期间 10 s 没有任何心跳 → 恢复全透传 */
static void evt_watchdog(void *arg)
{
    (void)arg;
    if (!s_enabled) {
        return;
    }
    const int64_t now = esp_timer_get_time();
    if (now - s_last_hb_us > EVT_HB_TIMEOUT_US) {
        ESP_LOGW(TAG, "no client heartbeat for 10 s: dropping subscription (mask 0x%02x)", s_mask);
        btn_evt_ctl(false, 0, false, false);
        s_auto_released = true;
    }
}

void btn_evt_init(void)
{
    s_head = s_tail = s_count = 0;
    s_seq = 0;
    s_overflow = 0;
    s_enabled = false;
    s_push = false;
    s_auto_released = false;
    s_mask = 0;
    s_pending = 0;
    s_prev_watched = 0;
    s_cur = 0;
    s_last_fwd = 0;
    btn_evt_heartbeat();

    if (s_timer == NULL) {
        const esp_timer_create_args_t args = {
            .callback = evt_watchdog,
            .arg = NULL,
            .name = "btn_evt_wd",
        };
        if (esp_timer_create(&args, &s_timer) != ESP_OK) {
            ESP_LOGE(TAG, "esp_timer_create failed");
            s_timer = NULL;
        } else {
            (void)esp_timer_start_periodic(s_timer, 1000 * 1000);   /* 1 s */
        }
    }
    ESP_LOGI(TAG, "button event channel up (subscribe = consume)");
}
