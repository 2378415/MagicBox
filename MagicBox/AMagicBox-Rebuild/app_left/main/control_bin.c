/* Binary fast path on the UART0 control port - see control_bin.h. */
#include "control_bin.h"

#include <string.h>

#include "esp_timer.h"

#include "makcu_mouse.h"
#include "makcu_mouse_hooks.h"
#include "makcu_sumv.h"
#include "btn_evt.h"
#include "btn_trace.h"
#include "makcu_hiddev.h"

#define CB_MAGIC 0x5A

static cb_write_fn s_writer;

/* --- parser state ---------------------------------------------------------- */
enum {
    ST_IDLE = 0,
    ST_CMD,
    ST_SEQ,
    ST_LEN0,
    ST_LEN1,
    ST_PAYLOAD,
    ST_CRC,
};

static uint8_t  s_state;
static uint8_t  s_cmd;
static uint8_t  s_seq;
static uint16_t s_len;
static uint16_t s_got;
static uint8_t  s_payload[CB_MAX_PAYLOAD];

/* --- diagnostics (QUERY 0) ------------------------------------------------- */
static uint32_t s_pkts;       /* frames whose CRC checked out */
static uint32_t s_crc_err;
static uint32_t s_len_err;
static uint32_t s_gaps;       /* seq jumps seen on accepted frames */
static uint8_t  s_last_seq;
static bool     s_have_seq;
static uint32_t s_plans;      /* MOTION_PLAN frames accepted */

/* --- last plan timing (QUERY 2) -------------------------------------------- */
static int16_t  s_p_dx, s_p_dy;
static uint16_t s_p_dur;
static uint32_t s_p_recv_us;
static uint32_t s_p_submit_us;

static uint8_t crc8(const uint8_t *p, size_t n)
{
    uint8_t crc = 0;
    for (size_t i = 0; i < n; i++) {
        crc ^= p[i];
        for (int b = 0; b < 8; b++) {
            crc = (uint8_t)((crc & 0x80) ? ((crc << 1) ^ 0x07) : (crc << 1));
        }
    }
    return crc;
}

static void put_u32(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)(v & 0xFF);
    p[1] = (uint8_t)((v >> 8) & 0xFF);
    p[2] = (uint8_t)((v >> 16) & 0xFF);
    p[3] = (uint8_t)((v >> 24) & 0xFF);
}
static void build_frame(uint8_t cmd, uint8_t seq, const uint8_t *payload, uint16_t len)
{
    if (s_writer == NULL || len > CB_MAX_PAYLOAD) {
        return;
    }
    uint8_t frame[5 + CB_MAX_PAYLOAD + 1];
    frame[0] = CB_MAGIC;
    frame[1] = cmd;
    frame[2] = seq;
    frame[3] = (uint8_t)(len & 0xFF);
    frame[4] = (uint8_t)(len >> 8);
    if (len != 0) {
        memcpy(&frame[5], payload, len);
    }
    frame[5 + len] = crc8(&frame[1], (size_t)len + 4u);
    s_writer(frame, (size_t)len + 6u);
}

static void build_reply(uint8_t cmd, uint8_t seq, const uint8_t *payload, uint16_t len)
{
    build_frame((uint8_t)(cmd | CB_REPLY_FLAG), seq, payload, len);
}

/* 0xE1：设备主动推的按键事件（异步段，seq 为事件序号低字节） */
static void evt_push_frame(uint16_t seq, uint32_t t_us, uint8_t mask, uint8_t edge)
{
    /* 事件记录在线格式（与 btn_evt_t 的内存布局一致，EVT_READ 原样拷出）：
     *   +0 t_us u32 | +4 seq u16 | +6 mask u8 | +7 edge u8
     * 必须和 EVT_READ 的记录一致，否则上位机要写两套解码。 */
    uint8_t pl[8];
    put_u32(&pl[0], t_us);
    pl[4] = (uint8_t)(seq & 0xFF);
    pl[5] = (uint8_t)(seq >> 8);
    pl[6] = mask;
    pl[7] = edge;
    build_frame(CB_EVT_PUSH, (uint8_t)(seq & 0xFF), pl, 8);
}


static void handle_frame(void)
{
    s_pkts++;
    if (s_have_seq) {
        const uint8_t expect = (uint8_t)(s_last_seq + 1u);
        if (s_seq != expect && s_seq != s_last_seq) {
            s_gaps++;
        }
    }
    s_last_seq = s_seq;
    s_have_seq = true;

    switch (s_cmd) {
    case CB_CMD_MOTION_PLAN: {
        /* dx i16, dy i16, dur_ms u16, mode u8, flags u8 */
        if (s_len < 8) {
            s_len_err++;
            return;
        }
        const int16_t dx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        const int16_t dy = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        const uint16_t dur = (uint16_t)(s_payload[4] | (s_payload[5] << 8));
        const uint8_t mode = s_payload[6];
        const uint8_t flags = s_payload[7];
        const uint32_t t0 = (uint32_t)esp_timer_get_time();
        if (makcu_mouse_move_hook != NULL) {
            (void)makcu_mouse_move_hook(NULL, dx, dy, (mode == 1u) ? 1u : 2u);
        }
        const uint32_t t1 = (uint32_t)esp_timer_get_time();
        s_plans++;
        s_p_dx = dx;
        s_p_dy = dy;
        s_p_dur = dur;
        s_p_recv_us = t0;
        s_p_submit_us = t1 - t0;
        (void)flags;      /* tremor / bow flags are consumed by the planner (P3) */
        return;
    }
    case CB_CMD_BUTTON:
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        makcu_mouse_set_buttons(s_payload[0]);
        makcu_mouse_emit_now(0, 0, 0);
        return;
    case CB_CMD_WHEEL:
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        if (makcu_wheel_hook != NULL) {
            (void)makcu_wheel_hook(NULL, (int8_t)s_payload[0]);
        }
        return;
    case CB_CMD_QUERY: {
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        uint8_t rp[26];
        switch (s_payload[0]) {
        case 0: {                       /* counters */
            put_u32(&rp[0], s_pkts);
            put_u32(&rp[4], s_crc_err);
            put_u32(&rp[8], s_len_err);
            put_u32(&rp[12], s_gaps);
            rp[16] = s_last_seq;
            rp[17] = 1;                 /* protocol version */
            build_reply(s_cmd, s_seq, rp, 18);
            return;
        }
        case 1: {                       /* caps + clock */
            rp[0] = 1;                  /* protocol version */
            rp[1] = CB_MAX_PAYLOAD;
            rp[2] = 0;                  /* plan engine: 0 = chunked/Bezier (P3 -> 1) */
            rp[3] = 0;
            put_u32(&rp[4], (uint32_t)esp_timer_get_time());
            build_reply(s_cmd, s_seq, rp, 12);
            return;
        }
        case 2: {                       /* last plan */
            rp[0] = (uint8_t)(s_p_dx & 0xFF);
            rp[1] = (uint8_t)((uint16_t)s_p_dx >> 8);
            rp[2] = (uint8_t)(s_p_dy & 0xFF);
            rp[3] = (uint8_t)((uint16_t)s_p_dy >> 8);
            rp[4] = (uint8_t)(s_p_dur & 0xFF);
            rp[5] = (uint8_t)(s_p_dur >> 8);
            put_u32(&rp[6], s_p_recv_us);
            put_u32(&rp[10], s_p_submit_us);
            put_u32(&rp[14], s_plans);
            build_reply(s_cmd, s_seq, rp, 18);
            return;
        }
        default:
            s_len_err++;
            return;
        }
    }
    case CB_CMD_SUMV: {
        /* dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]
         * dur_ms 只在 mode bit0（固定时长）时生效。fire-and-forget。 */
        if (s_len < 8) {
            s_len_err++;
            return;
        }
        makcu_sumv_req_t req;
        req.dx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        req.dy = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        req.speed = (uint16_t)(s_payload[4] | (s_payload[5] << 8));
        req.mode = s_payload[6];
        req.seed = s_payload[7];
        req.dur_ms = (s_len >= 10) ? (uint16_t)(s_payload[8] | (s_payload[9] << 8)) : 0;
        (void)makcu_sumv_start(&req);
        s_plans++;
        return;
    }
    case CB_CMD_AIM: {
        /* dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]
         * 无回包（fire-and-forget）；结果码用 AIM_STATE 读。 */
        if (s_len < 6) {
            s_len_err++;
            return;
        }
        const int16_t adx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        const int16_t ady = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        const uint8_t ms = s_payload[4];
        const uint8_t flags = s_payload[5];
        const uint8_t dead = (s_len >= 7) ? s_payload[6] : 0;
        (void)makcu_sumv_aim(adx, ady, ms, flags, dead);
        s_plans++;
        return;
    }
    case CB_CMD_HID_STAT: {
        uint16_t bin = 0, bsent = 0, bwait = 0, bdrop = 0;
        makcu_hiddev_button_stats(&bin, &bsent, &bwait, &bdrop);
        uint16_t wire_chg = 0, wire_flood = 0, btn_merged = 0, btn_cancel = 0;
        makcu_hiddev_btn_wire(&wire_chg, &wire_flood, &btn_merged, &btn_cancel);
        uint8_t rp[14];
        rp[0] = (uint8_t)(bin & 0xFF);        rp[1] = (uint8_t)(bin >> 8);
        rp[2] = (uint8_t)(bsent & 0xFF);      rp[3] = (uint8_t)(bsent >> 8);
        rp[4] = (uint8_t)(bwait & 0xFF);      rp[5] = (uint8_t)(bwait >> 8);
        rp[6] = (uint8_t)(bdrop & 0xFF);      rp[7] = (uint8_t)(bdrop >> 8);
        /* S3：追加 flood（1 s 内按键字节变化 > 50 次的窗口数）；老客户端按长度忽略 */
        rp[8] = (uint8_t)(wire_flood & 0xFF);
        rp[9] = (uint8_t)(wire_flood >> 8);
        (void) wire_chg;
        rp[10] = (uint8_t)(btn_merged & 0xFF);
        rp[11] = (uint8_t)(btn_merged >> 8);
        rp[12] = (uint8_t)(btn_cancel & 0xFF);
        rp[13] = (uint8_t)(btn_cancel >> 8);
        build_reply(s_cmd, s_seq, rp, 14);
        return;
    }
    case CB_CMD_AIM_STATE: {
        uint8_t rp[12];
        (void)makcu_sumv_aim_state(rp, sizeof(rp));
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_SUMV_STOP:
        makcu_sumv_stop();
        return;
    case CB_CMD_SUMV_STATE: {
        makcu_sumv_stats_t st;
        makcu_sumv_stats(&st);
        uint8_t rp[32];
        rp[0] = st.active ? 1u : 0u;
        put_u32(&rp[1], st.samples);
        put_u32(&rp[5], st.aborted);
        put_u32(&rp[9], st.rounds);
        put_u32(&rp[13], st.mute_dropped);
        put_u32(&rp[17], st.btn_forwarded);
        put_u32(&rp[21], st.speed_eff);
        put_u32(&rp[25], st.remain_ms);
        build_reply(s_cmd, s_seq, rp, 29);
        return;
    }
    case CB_CMD_BTN_CNT: {
        extern uint32_t btn_diag_counts(uint8_t which);
        uint8_t rp[26];
        put_u32(&rp[0], btn_diag_counts(0));
        put_u32(&rp[4], btn_diag_counts(1));
        put_u32(&rp[8], btn_diag_counts(2));
        put_u32(&rp[12], btn_diag_counts(3));
        /* 追加最近一帧原始报告的前 8 字节（看真实布局：byte0 到底是不是按键） */
        extern void btn_diag_last_frame(uint8_t *out);
        extern uint8_t btn_diag_last_ep(void);
        extern uint8_t btn_diag_last_len(void);
        rp[16] = btn_diag_last_ep();
        rp[17] = btn_diag_last_len();
        btn_diag_last_frame(&rp[18]);
        build_reply(s_cmd, s_seq, rp, 26);
        return;
    }
    case CB_CMD_BTN_LOG: {
        /* 请求：since u16（序号）；回包：total u16, count u8, count × 8B 记录 */
        uint16_t since = 0;
        if (s_len >= 2) {
            since = (uint16_t)(s_payload[0] | (s_payload[1] << 8));
        }
        btn_trace_entry_t entries[5];
        uint16_t total = 0;
        uint16_t n = btn_trace_read(since, entries, 5, &total);
        uint8_t rp[2 + 1 + 5 * 8];
        rp[0] = (uint8_t)(total & 0xFF);
        rp[1] = (uint8_t)(total >> 8);
        rp[2] = (uint8_t)n;
        uint8_t *p = &rp[3];
        for (uint16_t i = 0; i < n; i++) {
            p[0] = (uint8_t)(entries[i].t_us & 0xFF);
            p[1] = (uint8_t)((entries[i].t_us >> 8) & 0xFF);
            p[2] = (uint8_t)((entries[i].t_us >> 16) & 0xFF);
            p[3] = (uint8_t)((entries[i].t_us >> 24) & 0xFF);
            p[4] = entries[i].raw;
            p[5] = entries[i].fwd;
            p[6] = entries[i].src;
            p[7] = 0;
            p += 8;
        }
        build_reply(s_cmd, s_seq, rp, (uint16_t)(3 + n * 8));
        return;
    }
    case CB_CMD_LAST_HID: {
        /* 20 B：rid,len,8B 报告 | 8B 上线按键字节历史 | stamped(u16)
         * `stamped` = 方案 A 生效后"出队时被改写按键字节"的报告数（≈按下瞬间的队列深度）。 */
        uint8_t rp[20] = {0};
        makcu_hiddev_last_report(rp, 10);
        makcu_hiddev_btn_history(&rp[10], 8);
        const uint16_t stamped = makcu_hiddev_btn_stamped();
        rp[18] = (uint8_t)(stamped & 0xFF);
        rp[19] = (uint8_t)(stamped >> 8);
        build_reply(s_cmd, s_seq, rp, 20);
        return;
    }
    case CB_CMD_AIM_RESET: {
        makcu_sumv_aim_clear_stats();
        return;                       /* fire-and-forget */
    }
    case CB_CMD_EVT_RESET: {
        btn_evt_reset_stats();
        return;
    }
    case CB_CMD_BTN_AUDIT: {
        /* 按键回环审计：12 B
         *   [0..3]  in_chg  —— set_buttons 真正改变字节的次数（= 注入的按键变化数）
         *   [4..7]  out_chg —— 实际发出去的报告里按键字节变化的次数
         *   [8..11] extra   —— 变了但没有变化请求挂着（凭空多发）
         * 正常终态：in_chg == out_chg、extra == 0。 */
        uint32_t in_chg = 0, out_chg = 0, extra = 0;
        makcu_mouse_btn_audit(&in_chg, &out_chg, &extra);
        uint8_t rp[12];
        put_u32(&rp[0], in_chg);
        put_u32(&rp[4], out_chg);
        put_u32(&rp[8], extra);
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_EVT_CTL: {
        /* enable u8, mask u8, push u8 [, consume u8]
         * 默认 **穿透**：订阅只产生事件，按键照常给 PC；
         * 第 4 字节 = 1 才是"吃掉"（PC 看不到这次点击）。为兼容老客户端，
         * 长度不足 4 时按穿透处理。 */
        if (s_len < 3) {
            s_len_err++;
            return;
        }
        btn_evt_ctl(s_payload[0] != 0, s_payload[1], s_payload[2] != 0,
                    (s_len >= 4) && (s_payload[3] != 0));
        return;
    }
    case CB_CMD_EVT_READ: {
        /* count u8 → 回 [count][n x 8B 事件]，单帧最多 7 条（payload 上限 64） */
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        uint8_t want = s_payload[0];
        if (want > 7) {
            want = 7;
        }
        uint8_t buf[1 + 7 * 8];
        const uint8_t n = btn_evt_read(&buf[1], want);
        buf[0] = n;
        build_reply(s_cmd, s_seq, buf, (uint16_t)(1u + (uint16_t)n * 8u));
        return;
    }
    case CB_CMD_EVT_STAT: {
        btn_evt_stat_t st;
        btn_evt_stat(&st);
        uint8_t rp[12];
        rp[0] = (uint8_t)(st.head_seq & 0xFF);
        rp[1] = (uint8_t)(st.head_seq >> 8);
        rp[2] = st.count;
        put_u32(&rp[3], st.overflow);
        rp[7] = st.mask;
        rp[8] = st.pending;
        rp[9] = st.cur;
        rp[10] = st.last_fwd;
        rp[11] = (uint8_t)((st.enabled ? 1u : 0u) | (st.push ? 2u : 0u) |
                           (st.auto_released ? 4u : 0u) | (st.consume ? 8u : 0u));
        btn_evt_heartbeat();
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_PING: {
        if (s_len < 4) {
            s_len_err++;
            return;
        }
        btn_evt_heartbeat();                     /* PING 也算客户端存活 */
        uint8_t rp[12];
        memcpy(&rp[0], s_payload, 4);            /* echo the counter */
        put_u32(&rp[4], (uint32_t)esp_timer_get_time());
        rp[8] = (uint8_t)(s_plans & 0xFF);
        rp[9] = (uint8_t)((s_plans >> 8) & 0xFF);
        rp[10] = s_last_seq;
        rp[11] = 0;
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    default:
        return;                          /* unknown command: silently ignored */
    }
}

void cb_reset(cb_write_fn writer)
{
    s_writer = writer;
    btn_evt_set_push_fn(evt_push_frame);
    s_state = ST_IDLE;
    s_cmd = s_seq = 0;
    s_len = s_got = 0;
    s_pkts = s_crc_err = s_len_err = s_gaps = s_plans = 0;
    s_last_seq = 0;
    s_have_seq = false;
    s_p_dx = s_p_dy = 0;
    s_p_dur = 0;
    s_p_recv_us = s_p_submit_us = 0;
}

void cb_stats(uint32_t *pkts, uint32_t *crc_err, uint32_t *len_err,
              uint32_t *gaps, uint8_t *last_seq, uint32_t *plans)
{
    if (pkts)     { *pkts = s_pkts; }
    if (crc_err)  { *crc_err = s_crc_err; }
    if (len_err)  { *len_err = s_len_err; }
    if (gaps)     { *gaps = s_gaps; }
    if (last_seq) { *last_seq = s_last_seq; }
    if (plans)    { *plans = s_plans; }
}

bool cb_feed(uint8_t byte, bool at_line_start)
{
    switch (s_state) {
    case ST_IDLE:
        if (byte != CB_MAGIC || !at_line_start) {
            return false;                /* not ours: leave it to the text parser */
        }
        s_state = ST_CMD;
        return true;
    case ST_CMD:
        s_cmd = byte;
        s_state = ST_SEQ;
        return true;
    case ST_SEQ:
        s_seq = byte;
        s_state = ST_LEN0;
        return true;
    case ST_LEN0:
        s_len = byte;
        s_state = ST_LEN1;
        return true;
    case ST_LEN1:
        s_len = (uint16_t)(s_len | ((uint16_t)byte << 8));
        s_got = 0;
        if (s_len > CB_MAX_PAYLOAD) {
            s_len_err++;
            s_state = ST_IDLE;           /* drop the frame, resync on next 0x5A */
            return true;
        }
        s_state = (s_len == 0) ? ST_CRC : ST_PAYLOAD;
        return true;
    case ST_PAYLOAD:
        s_payload[s_got++] = byte;
        if (s_got >= s_len) {
            s_state = ST_CRC;
        }
        return true;
    case ST_CRC: {
        uint8_t buf[4 + CB_MAX_PAYLOAD];
        buf[0] = s_cmd;
        buf[1] = s_seq;
        buf[2] = (uint8_t)(s_len & 0xFF);
        buf[3] = (uint8_t)(s_len >> 8);
        if (s_len != 0) {
            memcpy(&buf[4], s_payload, s_len);
        }
        const uint8_t want = crc8(buf, (size_t)s_len + 4u);
        s_state = ST_IDLE;
        if (want != byte) {
            s_crc_err++;                 /* fire-and-forget: drop, never complain */
            return true;
        }
        handle_frame();
        return true;
    }
    default:
        s_state = ST_IDLE;
        return true;
    }
}
