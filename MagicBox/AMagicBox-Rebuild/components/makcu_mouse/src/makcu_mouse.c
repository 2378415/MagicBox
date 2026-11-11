/* Mouse commit layer - see include/makcu_mouse.h. */
#include "makcu_mouse.h"

#include "makcu_dev.h"
#include "makcu_mouse_hooks.h"

#include "esp_random.h"
#include "esp_timer.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

static SemaphoreHandle_t s_lock;
static TaskHandle_t      s_task;
static makcu_report_t    s_last;
static makcu_report_t    s_trace[MAKCU_REPORT_TRACE];
static unsigned          s_trace_count;
static unsigned          s_trace_pos;
static volatile uint8_t  s_request;
static volatile int64_t  s_btn_guard_until_us;   /* 按键让路窗口截止时刻（µs，0 = 无窗口） */
static volatile bool     s_moving;      /* run_move() 正在发一条移动 */

/* Pending state, mirroring DAT_42000E44 / E48 (dx/dy), E88 (wheel),
 * E4C (move flag) and E04 (commit request). */
static int16_t s_pending_dx;
static int16_t s_pending_dy;
static int16_t s_pending_wheel;

/* Cumulative sum of everything handed to the HID layer since boot.  This is the
 * bench proof that the step split conserves the request: `mx.rt` reads it back,
 * so a test can assert "5000 counts in, 5000 counts out" without seeing the
 * whole (ring-truncated) report sequence. */
static int32_t s_total_dx;
static int32_t s_total_dy;
static int32_t s_total_wheel;

makcu_hid_report_fn makcu_hid_report_hook;

const makcu_report_t *makcu_mouse_last_report(void)
{
    return &s_last;
}

void makcu_mouse_totals(int32_t *dx, int32_t *dy, int32_t *wheel)
{
    if (dx != NULL) {
        *dx = s_total_dx;
    }
    if (dy != NULL) {
        *dy = s_total_dy;
    }
    if (wheel != NULL) {
        *wheel = s_total_wheel;
    }
}

/* Chronological copy: once the ring wraps, the oldest entry is at s_trace_pos. */
static makcu_report_t s_trace_ordered[MAKCU_REPORT_TRACE];

const makcu_report_t *makcu_mouse_trace(unsigned *count)
{
    const unsigned n = s_trace_count;
    const unsigned start = (n == MAKCU_REPORT_TRACE) ? s_trace_pos : 0;
    for (unsigned i = 0; i < n; i++) {
        s_trace_ordered[i] = s_trace[(start + i) % MAKCU_REPORT_TRACE];
    }
    if (count != NULL) {
        *count = n;
    }
    return s_trace_ordered;
}

static volatile uint8_t s_buttons;

/* ---- 按键回环审计（0x3F BTN_AUDIT）----
 * 目的：证明"注入一次按键 → 总线上正好一条按键变化"，既不丢也不多发。
 *   in_chg    : set_buttons() 真正改变字节的次数（注入/命令请求的"变化"）
 *   out_chg   : 真正发出去的报告里按键字节发生变化的次数
 *   extra     : 字节变了但没有任何"变化请求"挂着（= 凭空多发一条）
 * 正常终态：in_chg == out_chg 且 extra == 0。 */
static uint32_t s_btn_in_chg;
static uint32_t s_btn_out_chg;
static uint32_t s_btn_extra;
static uint8_t  s_btn_last_sent;      /* 上一条报告里的按键字节 */
static bool     s_btn_pending;        /* 有"变化"已请求、还没发出去 */

static void emit(int8_t dx, int8_t dy, int8_t wheel);

/* S1：把真实报告的按键字节同步进 s_buttons，但**不发送、不计 in_chg**。
 * 正常透传路径以前完全绕过 s_buttons，导致引擎注入携带的字节与真实报告不一致，
 * hiddev 于是把每条报告都当成"按键变化"（实测 824 条假按键、50 ms 等待）。 */
void makcu_mouse_sync_buttons(uint8_t buttons)
{
    const uint8_t b = (uint8_t)(buttons & 0x1Fu);
    if (b != s_buttons) {
        s_buttons = b;
        s_btn_in_chg++;   /* P1：真实透传的按键变化也要计入"请求"，否则 extra 虚高 */
    }
}

void makcu_mouse_set_buttons(uint8_t buttons)
{
    if (buttons != s_buttons) {
        s_buttons = buttons;
        s_btn_in_chg++;
        s_btn_pending = true;
    }
}

void makcu_mouse_emit_now(int8_t dx, int8_t dy, int8_t wheel)
{
    /* 让路窗口：按键刚生效，2 ms 内引擎不抢端点，保证按键报告是紧挨着的下一条。
     * 必须用 64 位比较：旧写法 (int32_t)(deadline - now) 在 deadline=0（无窗口）时
     * 会把 (2^32 - uptime) 当成正数 → 开机后大部分时间所有注入都被丢弃（光标不动）。 */
    if (s_btn_guard_until_us != 0 && esp_timer_get_time() < s_btn_guard_until_us) {
        return;
    }
    /* 引擎 1 kHz 注入与真实报告转发会并发；不加锁时一次按键切换前后的两条报告会被穿插，
     * 主机看到“按下→松开→按下”＝游戏里的双击/开镜闪断。 */
    if (s_lock != NULL) {
        xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
        emit(dx, dy, wheel);
        xSemaphoreGiveRecursive(s_lock);
    } else {
        emit(dx, dy, wheel);
    }
}

static void emit(int8_t dx, int8_t dy, int8_t wheel)
{
    makcu_report_t r = { dx, dy, wheel, s_buttons };
    s_last = r;
    s_total_dx += dx;
    s_total_dy += dy;
    s_total_wheel += wheel;
    s_trace[s_trace_pos] = r;
    s_trace_pos = (s_trace_pos + 1) % MAKCU_REPORT_TRACE;
    if (s_trace_count < MAKCU_REPORT_TRACE) {
        s_trace_count++;
    }
    if (r.buttons != s_btn_last_sent) {
        if (!s_btn_pending) {
            s_btn_extra++;                  /* 没人请求过却变了 = 多发 */
        }
        s_btn_pending = false;
        s_btn_out_chg++;
        s_btn_last_sent = r.buttons;
    }
    if (makcu_hid_report_hook != NULL) {
        makcu_hid_report_hook(&r);
    }
}

void makcu_mouse_btn_audit(uint32_t *in_chg, uint32_t *out_chg, uint32_t *extra)
{
    if (in_chg) { *in_chg = s_btn_in_chg; }
    if (out_chg) { *out_chg = s_btn_out_chg; }
    if (extra) { *extra = s_btn_extra; }
}

static void request_commit(void)
{
    s_request = 1;                              /* *DAT_42000E04 = 1 */
    if (s_task != NULL) {
        xTaskNotifyGive(s_task);
    }
}

/* --------------------------------------------------------------- submissions */
void makcu_mouse_forward(int8_t dx, int8_t dy, int8_t wheel, uint8_t buttons)
{
    makcu_mouse_set_buttons(buttons);
    if (s_lock == NULL) {
        emit(dx, dy, wheel);
        return;
    }
    xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    const bool backlog = (s_pending_dx != 0) || (s_pending_dy != 0) || (s_pending_wheel != 0);
    if (backlog) {
        /* Keep the order: everything already queued goes out first. */
        s_pending_dx = (int16_t)(s_pending_dx + dx);
        s_pending_dy = (int16_t)(s_pending_dy + dy);
        s_pending_wheel = (int16_t)(s_pending_wheel + wheel);
        xSemaphoreGiveRecursive(s_lock);
        request_commit();
        return;
    }
    emit(dx, dy, wheel);
    xSemaphoreGiveRecursive(s_lock);
}

void makcu_mouse_pump(void)
{
    if (s_lock == NULL) {
        return;
    }
    /* 正在执行一条 queued move 时不要插进来：pump 每来一次 HID 完成回调就会
     * 取走 pending 并只发一条 ±127，会把一次 3 步的移动拆成 pump 步 + 剩余步，
     * 表现为 mx.rq 里的步进与期望不一致（回归里 test_two_axis_split_sums 偶发
     * 断言失败就是这个）。 */
    if (s_moving) {
        return;
    }
    xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    int32_t dx = s_pending_dx;
    int32_t dy = s_pending_dy;
    int32_t dw = s_pending_wheel;
    if (dx == 0 && dy == 0 && dw == 0) {
        xSemaphoreGiveRecursive(s_lock);
        return;
    }
    const int8_t sx = (int8_t)(dx > 127 ? 127 : (dx < -128 ? -128 : dx));
    const int8_t sy = (int8_t)(dy > 127 ? 127 : (dy < -128 ? -128 : dy));
    const int8_t sw = (int8_t)(dw > 127 ? 127 : (dw < -128 ? -128 : dw));
    s_pending_dx = (int16_t)(dx - sx);
    s_pending_dy = (int16_t)(dy - sy);
    s_pending_wheel = (int16_t)(dw - sw);
    emit(sx, sy, sw);
    xSemaphoreGiveRecursive(s_lock);
}

int makcu_mouse_submit_delta(int16_t dx, int16_t dy, int8_t wheel)
{
    if (s_lock == NULL) {
        return -1;
    }
    xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    int32_t ax = (int32_t)s_pending_dx + dx;
    int32_t ay = (int32_t)s_pending_dy + dy;
    int32_t aw = (int32_t)s_pending_wheel + wheel;
    if (ax > 32767) { ax = 32767; }
    if (ax < -32768) { ax = -32768; }
    if (ay > 32767) { ay = 32767; }
    if (ay < -32768) { ay = -32768; }
    if (aw > 32767) { aw = 32767; }
    if (aw < -32768) { aw = -32768; }
    s_pending_dx = (int16_t)ax;
    s_pending_dy = (int16_t)ay;
    s_pending_wheel = (int16_t)aw;
    xSemaphoreGiveRecursive(s_lock);
    request_commit();
    return 0;
}

static int submit_default(void *dev, int16_t x, int16_t y, uint32_t mode)
{
    (void)dev;
    (void)mode;
    if (s_lock == NULL) {
        return -1;
    }
    xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    s_pending_dx = x;                           /* DAT_42000E44 */
    s_pending_dy = y;                           /* DAT_42000E48 */
    xSemaphoreGiveRecursive(s_lock);
    request_commit();
    return 0;
}

static int submit_ext(void *dev, int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4)
{
    (void)dev;
    (void)v2;
    return submit_default(NULL, v0, v1, (uint32_t)(v3 + v4));
}

static int submit_pulse(void *dev, int16_t dx, int16_t dy)
{
    /* 0x42010D3C: forward, wait for the commit semaphore, delay 1 tick, back. */
    submit_default(dev, dx, dy, 1);
    vTaskDelay(1);
    submit_default(dev, (int16_t)-dx, (int16_t)-dy, 0);
    return 0;
}

static int submit_wheel(void *dev, int8_t delta)
{
    (void)dev;
    if (s_lock == NULL) {
        return -1;
    }
    xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    s_pending_wheel = delta;                    /* DAT_42000E88 */
    xSemaphoreGiveRecursive(s_lock);
    request_commit();
    return 0;
}

/* ------------------------------------------------------------- step engine */
/*
 * A HID mouse report carries int8 deltas, so any move longer than 127 counts has
 * to be split - the original does exactly that in the loop of 0x4200EFEC (which
 * also applies a randomly rotated "sway").  Ported here:
 *   - split so that every component stays inside [-127, 127];
 *   - largest-remainder distribution, so the steps sum to the exact request;
 *   - one tick between steps (the original waits on the commit semaphore, which
 *     the tick-driven task releases);
 * Not ported yet: the rotation / easing (the random angle and the double math in
 * the head of 0x4200EFEC) - the steps are evenly spaced along the straight line.
 */
#define STEP_LIMIT 127

/* A single int16 move is at most 32767 counts, i.e. ceil(32767/127) = 259
 * reports.  The trace ring keeps only the newest 16 (mx.rq), but the motion
 * itself must never be truncated: the steps have to sum to the request exactly.
 * (The first rebuild capped the step count at the trace size, which silently
 * shortened every move longer than 16*127 = 2032 counts.) */
#define STEP_MAX ((32767 + STEP_LIMIT - 1) / STEP_LIMIT)

/*
 * Curved path.  The original rotates the requested vector by a random angle and
 * walks a sine/cosine shape (0x4200EFEC head); the exact double arithmetic is not
 * reproduced here, but the observable shape is: a bowed path whose curvature is
 * random per move and bounded by a fraction of the span.  Quadratic Bezier with
 * a random perpendicular control offset gives that shape, and sampling with
 * rounding-on-cumulative-position keeps the sum exactly equal to the request.
 */
static int bezier_offset(int span)
{
    if (span < 8) {
        return 0;                              /* short moves stay straight */
    }
    const int limit = span / 8;
    const int r = (int)(esp_random() % (uint32_t)(2 * limit + 1));
    return r - limit;
}

/* The control offset is drawn once per move and passed in: re-drawing it for
 * every sample would jitter the path instead of bowing it (the old signature
 * called bezier_offset() inside the loop). */
static void bezier_point(int dx, int dy, int span, int off, int steps, int step,
                         int64_t *out_x, int64_t *out_y)
{
    /* P0 = (0,0), P1 = (dx,dy), control C = midpoint + perpendicular offset */
    /* perpendicular of (dx,dy), normalised by the span */
    const int64_t cx = (int64_t)dx / 2 - ((int64_t)dy * off) / (span ? span : 1);
    const int64_t cy = (int64_t)dy / 2 + ((int64_t)dx * off) / (span ? span : 1);

    /* t in 0..1 sampled at step/steps, using 1/1024 fixed point */
    const int64_t t = (int64_t)step * 1024 / steps;
    const int64_t mt = 1024 - t;
    const int64_t a = mt * mt;                 /* (1-t)^2, scaled 1024^2 */
    const int64_t b = 2 * mt * t;
    const int64_t c = t * t;
    const int64_t scale = 1024LL * 1024LL;
    *out_x = (a * 0 + b * cx + c * dx) / scale;
    *out_y = (a * 0 + b * cy + c * dy) / scale;
}

static void fold_residue(int8_t *v, int steps, int target)
{
    int sum = 0;
    for (int i = 0; i < steps; i++) {
        sum += v[i];
    }
    int rest = target - sum;
    int guard = 0;
    while (rest != 0 && guard++ < 4096) {
        int placed = 0;
        for (int i = steps - 1; i >= 0; i--) {
            const int room = (rest > 0) ? (STEP_LIMIT - v[i]) : (v[i] + STEP_LIMIT);
            if (room <= 0) {
                continue;
            }
            int d = (rest > room) ? room : ((rest < -room) ? -room : rest);
            v[i] = (int8_t)(v[i] + d);
            rest -= d;
            placed = 1;
            break;
        }
        if (!placed) {
            break;
        }
    }
}

static void run_move(int16_t dx, int16_t dy, int16_t wheel)
{
    const int ax = (dx < 0) ? -dx : dx;
    const int ay = (dy < 0) ? -dy : dy;
    const int span = (ax > ay) ? ax : ay;
    int steps = (span + STEP_LIMIT - 1) / STEP_LIMIT;
    if (steps < 1) {
        steps = 1;
    }
    if (steps > STEP_MAX) {
        steps = STEP_MAX;                      /* unreachable for an int16 move */
    }

    /* Only the mouse task calls this, so static buffers keep the stack small
     * while still covering a full-range move. */
    static int8_t xs[STEP_MAX];
    static int8_t ys[STEP_MAX];
    if (steps == 1) {
        xs[0] = (int8_t)dx;
        ys[0] = (int8_t)dy;
    } else {
        /* sample the curve and take first differences of the rounded positions */
        const int off = bezier_offset(span);
        int64_t px = 0, py = 0;
        for (int i = 1; i <= steps; i++) {
            int64_t qx, qy;
            bezier_point(dx, dy, span, off, steps, i, &qx, &qy);
            int64_t step_x = qx - px;
            int64_t step_y = qy - py;
            if (step_x > 127) step_x = 127;
            if (step_x < -127) step_x = -127;
            if (step_y > 127) step_y = 127;
            if (step_y < -127) step_y = -127;
            xs[i - 1] = (int8_t)step_x;
            ys[i - 1] = (int8_t)step_y;
            px = qx;
            py = qy;
        }
        /* push the rounding residue into whichever steps still have head-room,
         * so the sum equals the request *and* no component leaves int8 */
        fold_residue(xs, steps, dx);
        fold_residue(ys, steps, dy);
    }

    for (int i = 0; i < steps; i++) {
        emit(xs[i], ys[i], (i == 0) ? (int8_t)wheel : 0);
        if (i + 1 < steps) {
            vTaskDelay(1);
        }
    }
}

/* ------------------------------------------------------------------- task */
void makcu_mouse_task(void *arg)
{
    (void)arg;
    for (;;) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        if (!s_request) {
            continue;
        }
        s_request = 0;
        int16_t dx, dy, wheel;
        xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
        dx = s_pending_dx;
        dy = s_pending_dy;
        wheel = s_pending_wheel;
        s_pending_dx = 0;
        s_pending_dy = 0;
        s_pending_wheel = 0;
        xSemaphoreGiveRecursive(s_lock);
        if (dx != 0 || dy != 0 || wheel != 0) {
            s_moving = true;
            run_move(dx, dy, wheel);
            s_moving = false;
        }
    }
}

void makcu_mouse_init(void)
{
    if (s_lock == NULL) {
        s_lock = xSemaphoreCreateRecursiveMutex();
    }
    if (s_task == NULL) {
        xTaskCreate(makcu_mouse_task, "km_mouse", 4096, NULL, 12, &s_task);
    }
    /* Install the protocol-facing hooks (previously NULL). */
    makcu_mouse_move_hook = submit_default;
    makcu_mouse_move_ext_hook = submit_ext;
    makcu_mouse_pulse_hook = submit_pulse;
    makcu_wheel_hook = submit_wheel;
}

/* 按键最高优先级：立刻更新状态并补一条零位移报告，不参与 pending 合并、不被去抖丢弃。
 * 与引擎注入互斥，所以输出顺序严格是“旧状态 → 新状态”，不会有人把新状态盖回去。 */
#define MAKCU_BTN_GUARD_US 2000u
void makcu_mouse_button_priority(uint8_t buttons)
{
    if (s_lock != NULL) {
        xSemaphoreTakeRecursive(s_lock, portMAX_DELAY);
    }
    /* P1：瞄准期真实按键走的就是这条路径，以前不计数 → 审计把真实点击误算成"多发" */
    if ((uint8_t)(buttons & 0x1Fu) != s_buttons) {
        s_btn_in_chg++;
    }
    s_buttons = (uint8_t)(buttons & 0x1Fu);
    emit(0, 0, 0);
    s_btn_guard_until_us = esp_timer_get_time() + MAKCU_BTN_GUARD_US;
    if (s_lock != NULL) {
        xSemaphoreGiveRecursive(s_lock);
    }
}