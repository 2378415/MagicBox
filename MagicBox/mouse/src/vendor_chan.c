/* Dedicated vendor channel - implementation (see include/vendor_chan.h).
 *
 * R1 scope: legacy transport only.  vchan_out() forwards to the 0xA5 queue that
 * app_main installs, so the firmware behaves exactly like HEAD; the stats and
 * the 0xB0..0xB2 entry point exist so R2 is a build-flag flip, not a rewrite.
 */
#include "vendor_chan.h"

#include <string.h>

#include "esp_timer.h"
#include "freertos/FreeRTOS.h"

#include "makcu_link.h"
#include "makcu_link_bridge.h"

static vchan_tx_fn s_legacy_tx;
static vchan_in_fn s_in_sink;

static volatile uint32_t s_tx_frames;
static volatile uint32_t s_tx_fail;
static volatile uint32_t s_rx_frames;
static volatile uint32_t s_ack_ok;
static volatile uint32_t s_ack_timeout;
static volatile uint32_t s_drop;
static volatile uint32_t s_retry;
static volatile uint32_t s_rtt_max_us;

void vchan_set_legacy_tx(vchan_tx_fn fn)
{
    s_legacy_tx = fn;
}

void vchan_set_in_sink(vchan_in_fn fn)
{
    s_in_sink = fn;
}

int vchan_init(void)
{
#if defined(MB_VENDOR_CHANNEL)
    /* R2: queue + task are created here.  Left empty on purpose until the right
     * chip speaks 0xB0; creating the task earlier would just idle. */
    return 0;
#else
    /* Legacy mode: the 0xA5 queue must already be installed by the app. */
    return (s_legacy_tx != NULL) ? 0 : -1;
#endif
}

int vchan_out(uint8_t ep, const uint8_t *data, uint16_t len, uint32_t wait_ack_ms)
{
    (void)wait_ack_ms;          /* the legacy path is asynchronous by design */
    if (data == NULL || len == 0) {
        s_tx_fail++;
        return -1;
    }
#if defined(MB_VENDOR_CHANNEL)
    /* R2: <seq><ep><len:u16><data> over 0xB0, optional 0xB2 wait. */
    return -1;                  /* not reachable until R2 lands */
#else
    if (s_legacy_tx == NULL) {
        s_tx_fail++;
        return -1;
    }
    const int rc = s_legacy_tx(ep, data, len);
    if (rc == 0) {
        s_tx_frames++;
    } else {
        s_tx_fail++;
    }
    return rc;
#endif
}

void vchan_on_dev_in(uint8_t ep, const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) {
        return;
    }
    s_rx_frames++;
    if (s_in_sink != NULL) {
        s_in_sink(ep, data, len);
    }
}

bool vchan_on_frame(uint8_t cmd, const uint8_t *payload, uint16_t len)
{
    (void)cmd;
    (void)payload;
    (void)len;
    /* R1: the right chip does not emit 0xB0/0xB1/0xB2 yet.  Returning false
     * keeps the unknown-frame counter honest. */
    return false;
}

vchan_stats_t vchan_stats(void)
{
    vchan_stats_t st;
    st.tx_frames   = s_tx_frames;
    st.tx_fail     = s_tx_fail;
    st.rx_frames   = s_rx_frames;
    st.ack_ok      = s_ack_ok;
    st.ack_timeout = s_ack_timeout;
    st.drop        = s_drop;
    st.retry       = s_retry;
    st.rtt_max_us  = s_rtt_max_us;
    return st;
}
