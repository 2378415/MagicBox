/* Vendor-channel dispatch: pick a driver from the identity the clone serves.
 *
 * With no match every entry point degrades to "do nothing", which is exactly the
 * pre-migration behaviour: frames are still forwarded byte-for-byte, they are
 * just not interpreted by anybody.
 */
#include "mouse_vendor.h"

#include <string.h>

#include "g3mpro.h"

static const mouse_vendor_drv_t k_g3m_drv = {
    .name            = "g3mpro",
    .match           = g3mpro_match,
    .is_vendor_frame = g3mpro_is_vendor_frame,
    .is_vendor_port  = g3mpro_is_vendor_port,
    .expects_reply   = g3mpro_expects_reply,
    .min_gap_ms      = g3mpro_min_gap_ms,
    .on_host_out     = g3mpro_on_host_out,
    .on_dev_in       = g3mpro_on_dev_in,
    .stats           = g3mpro_stats,
};

static const mouse_vendor_drv_t *s_drv;

void mouse_vendor_init(uint16_t vid, uint16_t pid)
{
    s_drv = NULL;
    if (vid == 0 && pid == 0) {
        return;                       /* identity unknown: pass-through only */
    }
    if (k_g3m_drv.match != NULL && k_g3m_drv.match(vid, pid)) {
        s_drv = &k_g3m_drv;
    }
}

const mouse_vendor_drv_t *mouse_vendor_current(void)
{
    return s_drv;
}

bool mouse_vendor_is_vendor_frame(const uint8_t *data, uint16_t len)
{
    if (s_drv == NULL || s_drv->is_vendor_frame == NULL) {
        return false;
    }
    return s_drv->is_vendor_frame(data, len);
}

bool mouse_vendor_is_vendor_port(const uint8_t *data, uint16_t len)
{
    if (s_drv == NULL) {
        return false;
    }
    if (s_drv->is_vendor_port != NULL) {
        return s_drv->is_vendor_port(data, len);
    }
    return (s_drv->is_vendor_frame != NULL) ? s_drv->is_vendor_frame(data, len) : false;
}

void mouse_vendor_on_host_out(const uint8_t *data, uint16_t len)
{
    if (s_drv != NULL && s_drv->on_host_out != NULL) {
        s_drv->on_host_out(data, len);
    }
}

void mouse_vendor_on_dev_in(const uint8_t *data, uint16_t len)
{
    if (s_drv != NULL && s_drv->on_dev_in != NULL) {
        s_drv->on_dev_in(data, len);
    }
}

void mouse_vendor_stats(mouse_vendor_stats_t *out)
{
    if (out == NULL) {
        return;
    }
    memset(out, 0, sizeof(*out));
    if (s_drv != NULL && s_drv->stats != NULL) {
        s_drv->stats(out);
    }
}
