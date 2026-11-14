/* G3M PRO vendor protocol - the only place that knows what a 64-byte vendor
 * frame looks like, which commands must be answered, and how fast they may be
 * sent.  Everything here was measured (see include/g3mpro.h for the sources);
 * anything unmeasured stays on the conservative side of the table.
 *
 * Hard rule: this file never performs I/O.  Transport lives in vendor_chan.c,
 * so a protocol misunderstanding can never block the USB or UART1 threads.
 */
#include "g3mpro.h"

#include <stdio.h>
#include <string.h>

#include "esp_timer.h"

#include "mouse_vendor.h"

/* ---- command table ------------------------------------------------------- */
typedef struct {
    uint8_t     cmd;
    const char *name;
    bool        reply;      /* the device answers this command             */
    bool        write;      /* carries configuration -> 40 ms minimum gap  */
} g3m_cmd_t;

static const g3m_cmd_t k_cmds[] = {
    { G3M_CMD_BATTERY,    "battery/poll", false, false },
    { G3M_CMD_CFG_READ,   "cfg.read",     true,  false },
    { G3M_CMD_INFO_1B,    "info.1b",      true,  false },
    { G3M_CMD_INFO_1D,    "info.1d",      true,  false },
    { G3M_CMD_INFO_1F,    "info.1f",      true,  false },
    { G3M_CMD_INFO_20,    "info.20",      true,  false },
    { G3M_CMD_DPI_WRITE,  "dpi.write",    true,  true  },
    { G3M_CMD_DPI_COMMIT, "dpi.commit",   true,  true  },
    { G3M_CMD_POLL_56,    "poll.56",      false, false },
    { G3M_CMD_POLL_7F,    "poll.7f",      false, false },
    { G3M_CMD_POLL_90,    "poll.90",      false, false },
};

static const g3m_cmd_t *cmd_find(uint8_t cmd)
{
    for (size_t i = 0; i < sizeof(k_cmds) / sizeof(k_cmds[0]); i++) {
        if (k_cmds[i].cmd == cmd) {
            return &k_cmds[i];
        }
    }
    return NULL;
}

/* ---- state --------------------------------------------------------------- */
static mouse_vendor_stats_t s_st;
static g3mpro_dpi_state_t   s_dpi = G3MPRO_DPI_IDLE;
static uint8_t  s_prev_out[G3M_VEN_LEN];
static bool     s_have_prev;
static uint32_t s_last_out_us;
static uint32_t s_last_cmd_us[256];

/* ---- identity / frame predicates ---------------------------------------- */
bool g3mpro_match(uint16_t vid, uint16_t pid)
{
    const bool pid_ok = (pid == G3M_PID_PRIMARY) || ((pid & 0xFF00u) == G3M_PID_FAMILY);
    const bool vid_ok = (vid == G3M_VID_PRIMARY) || (vid == G3M_VID_0E8C) ||
                        (vid == G3M_VID_0ECC) || (vid == G3M_VID_06CC) ||
                        (vid == G3M_VID_068C);
    return pid_ok && vid_ok;
}

bool g3mpro_is_vendor_frame(const uint8_t *data, uint16_t len)
{
    return data != NULL && len == G3M_VEN_LEN && data[0] == G3M_VEN_RID;
}

bool g3mpro_is_vendor_port(const uint8_t *data, uint16_t len)
{
    return data != NULL && len > 0u && data[0] == G3M_VEN_RID;
}

bool g3mpro_expects_reply(uint8_t cmd)
{
    const g3m_cmd_t *e = cmd_find(cmd);
    return e != NULL && e->reply;
}

uint32_t g3mpro_min_gap_ms(uint8_t cmd)
{
    const g3m_cmd_t *e = cmd_find(cmd);
    if (e == NULL) {
        return 0;                       /* unknown: never throttle, never wait */
    }
    return e->write ? G3M_MIN_WRITE_GAP_MS : 0;
}

const char *g3mpro_cmd_name(uint8_t cmd)
{
    const g3m_cmd_t *e = cmd_find(cmd);
    return e != NULL ? e->name : "unknown";
}

/* ---- round-trip latency (per command, OUT -> matching IN) ----------------- */
#define G3M_LAT_BUCKETS 40              /* 1 ms per bucket, index 39 = ">=39 ms" */
static uint32_t s_lat_hist[G3M_LAT_BUCKETS];
static uint32_t s_lat_n;
static uint32_t s_lat_sum;
static uint32_t s_lat_max;
static uint32_t s_lat_last;
static uint32_t s_pend_ts[256];
static bool     s_pend[256];

static void lat_record(uint32_t d_us)
{
    uint32_t b = d_us / 1000u;
    if (b >= G3M_LAT_BUCKETS) {
        b = G3M_LAT_BUCKETS - 1u;
    }
    s_lat_hist[b]++;
    s_lat_n++;
    s_lat_sum += d_us;
    if (d_us > s_lat_max) { s_lat_max = d_us; }
    s_lat_last = d_us;
}

static uint32_t lat_pct(uint32_t pct)
{
    if (s_lat_n == 0) {
        return 0;
    }
    const uint32_t want = (s_lat_n * pct + 99u) / 100u;
    uint32_t acc = 0;
    for (uint32_t i = 0; i < G3M_LAT_BUCKETS; i++) {
        acc += s_lat_hist[i];
        if (acc >= want) {
            return (i + 1u) * 1000u;    /* 桶上界 */
        }
    }
    return G3M_LAT_BUCKETS * 1000u;
}

void g3mpro_latency(g3mpro_lat_t *out)
{
    if (out == NULL) {
        return;
    }
    out->n       = s_lat_n;
    out->last_us = s_lat_last;
    out->avg_us  = (s_lat_n != 0) ? (s_lat_sum / s_lat_n) : 0;
    out->max_us  = s_lat_max;
    out->p50_us  = lat_pct(50);
    out->p99_us  = lat_pct(99);
}

/* ---- distinct-frame sampler (mx.vd) -------------------------------------- */
#define G3M_DIST     8
#define G3M_DIST_HEAD 16
typedef struct {
    uint8_t  used;
    uint8_t  cmd;
    uint8_t  head[G3M_DIST_HEAD];
    uint16_t sum;                       /* 整帧（64 B）校验和：内容任何一处变化都会变 */
    uint16_t cnt;
    uint32_t last_us;
} g3m_dist_t;

static g3m_dist_t s_dist_out[G3M_DIST];
static g3m_dist_t s_dist_in[G3M_DIST];
static uint8_t    s_dist_out_pos;
static uint8_t    s_dist_in_pos;

static void dist_take(g3m_dist_t *tbl, uint8_t *pos, const uint8_t *data, uint16_t len)
{
    const uint8_t cmd = data[1];
    /* 整帧校验和：DPI 之类的值可能在第 18/27 字节，只看前 12 字节会漏掉变化。 */
    uint16_t sum = 0;
    for (uint16_t i = 0; i < len; i++) {
        sum = (uint16_t)(sum * 31u + data[i]);
    }
    for (uint8_t i = 0; i < G3M_DIST; i++) {
        if (tbl[i].used && tbl[i].cmd == cmd && tbl[i].sum == sum) {
            tbl[i].cnt++;
            tbl[i].last_us = (uint32_t)esp_timer_get_time();
            return;
        }
    }
    g3m_dist_t *slot = &tbl[*pos];
    slot->used = 1;
    slot->cmd = cmd;
    memcpy(slot->head, data, (len < G3M_DIST_HEAD) ? len : G3M_DIST_HEAD);
    slot->sum = sum;
    slot->cnt = 1;
    slot->last_us = (uint32_t)esp_timer_get_time();
    *pos = (uint8_t)((*pos + 1) % G3M_DIST);
}

size_t g3mpro_dump_distinct(char *out, size_t cap)
{
    if (out == NULL || cap < 32) {
        return 0;
    }
    size_t at = 0;
    for (uint8_t t = 0; t < 2; t++) {
        const g3m_dist_t *tbl = (t == 0) ? s_dist_out : s_dist_in;
        at += (size_t)snprintf(out + at, cap - at, "%s:", (t == 0) ? "OUT" : "IN ");
        for (uint8_t i = 0; i < G3M_DIST && at + 40 < cap; i++) {
            if (!tbl[i].used) {
                continue;
            }
            at += (size_t)snprintf(out + at, cap - at, " [%02x]", tbl[i].cmd);
            for (uint8_t k = 0; k < 8u && at + 3 < cap; k++) {
                at += (size_t)snprintf(out + at, cap - at, "%02x", tbl[i].head[k]);
            }
            at += (size_t)snprintf(out + at, cap - at, "$%04x x%u",
                                   (unsigned)tbl[i].sum, (unsigned)tbl[i].cnt);
        }
        at += (size_t)snprintf(out + at, cap - at, "\n");
    }
    return at;
}

/* ---- accounting (cheap, no I/O) ----------------------------------------- */
static void copy_head(uint8_t dst[8], const uint8_t *src, uint16_t len)
{
    const uint16_t n = (len > 8u) ? 8u : len;
    for (uint16_t i = 0; i < 8u; i++) {
        dst[i] = (i < n) ? src[i] : 0;
    }
}

void g3mpro_on_host_out(const uint8_t *data, uint16_t len)
{
    if (!g3mpro_is_vendor_frame(data, len)) {
        s_st.filtered++;
        return;
    }
    const uint8_t cmd = data[1];
    s_st.out_frames++;
    s_st.last_out_cmd = cmd;
    s_st.last_len = len;
    copy_head(s_st.last_out, data, len);

    if (s_have_prev && memcmp(s_prev_out, data, G3M_VEN_LEN) == 0) {
        s_st.dup++;
    }
    memcpy(s_prev_out, data, G3M_VEN_LEN);
    s_have_prev = true;

    if (cmd == G3M_CMD_BATTERY) {
        s_st.heartbeat++;
    }
    s_last_out_us = (uint32_t)esp_timer_get_time();
    s_last_cmd_us[cmd] = s_last_out_us;
    dist_take(s_dist_out, &s_dist_out_pos, data, G3M_VEN_LEN);
    /* 往返计时起点：同 cmd 的 IN 到达时结算（HECATE 的请求/应答同 cmd 字节）。 */
    s_pend[cmd] = true;
    s_pend_ts[cmd] = s_last_out_us;

    /* Passive DPI state machine: only observes, never injects (R4 wires it up
     * to take decisions once the timings have been measured on the wire). */
    switch (cmd) {
    case G3M_CMD_CFG_READ:
        if (s_dpi == G3MPRO_DPI_IDLE || s_dpi == G3MPRO_DPI_OK) {
            s_dpi = G3MPRO_DPI_READ;
        } else if (s_dpi == G3MPRO_DPI_COMMIT) {
            s_dpi = G3MPRO_DPI_VERIFY;
        }
        break;
    case G3M_CMD_DPI_WRITE:
        s_dpi = G3MPRO_DPI_WRITE;
        break;
    case G3M_CMD_DPI_COMMIT:
        s_dpi = (s_dpi == G3MPRO_DPI_WRITE) ? G3MPRO_DPI_COMMIT : G3MPRO_DPI_ERR;
        if (s_dpi == G3MPRO_DPI_ERR) {
            s_st.dpi_err_step = G3M_CMD_DPI_COMMIT;
        }
        break;
    default:
        break;
    }
}

void g3mpro_on_dev_in(const uint8_t *data, uint16_t len)
{
    if (!g3mpro_is_vendor_frame(data, len)) {
        s_st.filtered++;
        return;
    }
    s_st.in_frames++;
    s_st.last_in_cmd = data[1];
    copy_head(s_st.last_in, data, len);

    if (s_pend[s_st.last_in_cmd]) {
        const uint32_t now = (uint32_t)esp_timer_get_time();
        lat_record(now - s_pend_ts[s_st.last_in_cmd]);
        s_pend[s_st.last_in_cmd] = false;
    }
    dist_take(s_dist_in, &s_dist_in_pos, data, G3M_VEN_LEN);

    if (s_dpi == G3MPRO_DPI_VERIFY) {
        s_dpi = G3MPRO_DPI_OK;
    }
}

void g3mpro_note_out(const uint8_t *data, uint16_t len) { g3mpro_on_host_out(data, len); }
void g3mpro_note_in(const uint8_t *data, uint16_t len)  { g3mpro_on_dev_in(data, len); }

void g3mpro_stats(mouse_vendor_stats_t *out)
{
    if (out == NULL) {
        return;
    }
    s_st.dpi_state = (uint8_t)s_dpi;
    *out = s_st;
}
