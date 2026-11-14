/* makcu_hidhost - USB host core (M1: install, enumerate, claim, record).
 *
 * Layout mirrors the factory firmware's behaviour on the bench:
 *   - nothing plugged in  -> attached = false, 0xA0 answers 01 00 FF
 *   - mouse plugged in    -> attached = true,  session = USB address
 *
 * The ESP-IDF host stack runs two tasks: the library event task and our client
 * event task.  Both are started here; device handling happens in the client
 * callback context, which is fine because everything below is short and
 * non-blocking.
 */
#include <string.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "usb/usb_host.h"
#include "usb/usb_helpers.h"

#include "makcu_hidhost.h"

static const char *TAG = "hidhost";

static usb_host_client_handle_t s_client;
static SemaphoreHandle_t        s_lock;
static makcu_hidhost_info_t     s_info;
static usb_device_handle_t      s_dev;
static uint8_t                  s_dev_addr;

/* ---- IN report pump (M2) ------------------------------------------------- */
#define IN_XFERS_PER_EP 3
#define IN_BUFFER_SIZE  64

typedef struct {
    uint8_t           ep;
    bool              armed;
    int               count;
    usb_transfer_t   *xfer[IN_XFERS_PER_EP];
} in_ep_t;

static in_ep_t             s_in[MAKCU_HIDHOST_MAX_EP];
static uint8_t             s_in_count;
static bool                s_started;
static makcu_hidhost_sink_t s_sink;
static uint32_t s_submit_ok, s_submit_fail, s_complete, s_forwarded;

/* Sink (per-report forward) duration histogram, 10 us per bucket. */
#define SINK_LAT_BUCKETS 256
static uint32_t s_sink_lat[SINK_LAT_BUCKETS];
static uint32_t s_sink_n, s_sink_max_us;

void makcu_hidhost_sink_latency(uint16_t *p50_us, uint16_t *p99_us,
                                uint16_t *max_us, uint32_t *samples)
{
    uint32_t total = 0;
    for (int i = 0; i < SINK_LAT_BUCKETS; i++) { total += s_sink_lat[i]; }
    uint32_t p50 = 0, p99 = 0, acc = 0;
    for (int i = 0; i < SINK_LAT_BUCKETS; i++) {
        acc += s_sink_lat[i];
        if (p50 == 0 && acc * 100u >= total * 50u) { p50 = (uint32_t)(i + 1) * 10u; }
        if (p99 == 0 && acc * 100u >= total * 99u) { p99 = (uint32_t)(i + 1) * 10u; }
    }
    if (p50_us)  { *p50_us = (uint16_t)(p50 > 0xFFFFu ? 0xFFFFu : p50); }
    if (p99_us)  { *p99_us = (uint16_t)(p99 > 0xFFFFu ? 0xFFFFu : p99); }
    if (max_us)  { *max_us = (uint16_t)(s_sink_max_us > 0xFFFFu ? 0xFFFFu : s_sink_max_us); }
    if (samples) { *samples = s_sink_n; }
}

/* Called by the right app around the sink call. */
void makcu_hidhost_sink_latency_add(uint32_t us)
{
    uint32_t b = us / 10u;
    if (b >= SINK_LAT_BUCKETS) { b = SINK_LAT_BUCKETS - 1; }
    s_sink_lat[b]++;
    s_sink_n++;
    if (us > s_sink_max_us) { s_sink_max_us = us; }
}

/* Descriptor snapshots taken at attach time (see makcu_hidhost_raw_*). */
static uint8_t  s_raw_device[18];
static uint8_t  s_raw_config[MAKCU_HIDHOST_RAW_CONFIG_MAX];
static uint16_t s_raw_config_len;

int makcu_hidhost_raw_device(uint8_t out[18])
{
    if (out == NULL || s_raw_device[0] == 0) {
        return -1;
    }
    memcpy(out, s_raw_device, 18);
    return 18;
}

int makcu_hidhost_live_device(uint8_t out[18])
{
    if (out == NULL || !s_started) {
        return -1;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    usb_device_handle_t dev = s_dev;
    xSemaphoreGive(s_lock);
    if (dev == NULL) {
        return -1;
    }
    const usb_device_desc_t *ddesc = NULL;
    if (usb_host_get_device_descriptor(dev, &ddesc) != ESP_OK || ddesc == NULL) {
        return -1;
    }
    memcpy(out, ddesc, 18);
    return 18;
}

int makcu_hidhost_raw_config(uint8_t *out, size_t cap, uint16_t *total)
{
    if (total != NULL) {
        *total = s_raw_config_len;
    }
    if (out == NULL || cap == 0 || s_raw_config_len == 0) {
        return -1;
    }
    const size_t n = (cap < s_raw_config_len) ? cap : s_raw_config_len;
    memcpy(out, s_raw_config, n);
    return (int)n;
}

static void in_xfer_cb(usb_transfer_t *xfer);
static void arm_in_endpoints(void);
static void disarm_in_endpoints(void);

static TaskHandle_t s_rearm_task;

/* Re-submit every transfer of every slot that is not currently armed.  A partial
 * failure (some of the six submissions rejected right after a re-attach) used to
 * stay dead forever: the endpoint stream then never resumed even though the
 * device was enumerated, which is the "replug once and the mouse stops" bug. */
static void ensure_armed(void)
{
    if (!s_started || s_dev == NULL) {
        return;
    }
    for (uint8_t i = 0; i < s_in_count; i++) {
        if (s_in[i].armed) {
            continue;
        }
        for (int k = 0; k < s_in[i].count; k++) {
            usb_transfer_t *x = s_in[i].xfer[k];
            if (x == NULL) {
                continue;
            }
            x->device_handle = s_dev;
            if (usb_host_transfer_submit(x) == ESP_OK) {
                s_in[i].armed = true;
                s_submit_ok++;
            } else {
                s_submit_fail++;
            }
        }
        if (s_in[i].armed) {
            ESP_LOGW(TAG, "re-armed IN 0x%02x after a submit failure", s_in[i].ep);
        }
    }
}

/* Self-healing: a submit that fails (device just replugged, handle not ready)
 * disarms that slot; without this watchdog it would stay dead forever, which is
 * exactly the "unplug/replug once and the mouse stops" symptom. */
static void rearm_task(void *arg)
{
    (void)arg;
    for (;;) {
        vTaskDelay(pdMS_TO_TICKS(300));
        ensure_armed();
    }
}

/* ------------------------------------------------------------- descriptors */

static void record_interface(const usb_config_desc_t *cfg, int index)
{
    int offset = 0;
    const usb_intf_desc_t *itf = usb_parse_interface_descriptor(cfg, index, 0, &offset);
    if (itf == NULL) {
        return;
    }
    if (s_info.itf_count >= MAKCU_HIDHOST_MAX_IF) {
        return;
    }

    makcu_hidhost_itf_t *slot = &s_info.itf[s_info.itf_count];
    memset(slot, 0, sizeof(*slot));
    slot->iface    = itf->bInterfaceNumber;
    slot->alt      = itf->bAlternateSetting;
    slot->subclass = itf->bInterfaceSubClass;
    slot->protocol = itf->bInterfaceProtocol;

    for (int e = 0; e < itf->bNumEndpoints; e++) {
        int eoff = 0;
        const usb_ep_desc_t *ep =
            usb_parse_endpoint_descriptor_by_index(itf, e, cfg->wTotalLength, &eoff);
        if (ep == NULL) {
            break;
        }
        if ((ep->bEndpointAddress & USB_B_ENDPOINT_ADDRESS_EP_DIR_MASK) != 0) {
            if (slot->in_addr == 0) {
                slot->in_addr     = ep->bEndpointAddress;
                slot->in_mps      = ep->wMaxPacketSize;
                slot->in_interval = ep->bInterval;
            }
        } else {
            if (slot->out_addr == 0) {
                slot->out_addr = ep->bEndpointAddress;
                slot->out_mps  = ep->wMaxPacketSize;
            }
        }
    }

    s_info.itf_count++;
    ESP_LOGI(TAG, "itf %u alt %u class %u/%u in=0x%02x(%u) out=0x%02x(%u)",
             itf->bInterfaceNumber, itf->bAlternateSetting,
             itf->bInterfaceClass, itf->bInterfaceSubClass,
             slot->in_addr, slot->in_mps, slot->out_addr, slot->out_mps);
}

static void device_attached(uint8_t address)
{
    usb_device_handle_t dev = NULL;
    if (usb_host_device_open(s_client, address, &dev) != ESP_OK || dev == NULL) {
        ESP_LOGW(TAG, "open device %u failed", address);
        return;
    }

    const usb_device_desc_t *ddesc = NULL;
    if (usb_host_get_device_descriptor(dev, &ddesc) != ESP_OK || ddesc == NULL) {
        ESP_LOGW(TAG, "no device descriptor");
        usb_host_device_close(s_client, dev);
        return;
    }

    const usb_config_desc_t *cdesc = NULL;
    if (usb_host_get_active_config_descriptor(dev, &cdesc) != ESP_OK || cdesc == NULL) {
        ESP_LOGW(TAG, "no active config");
        usb_host_device_close(s_client, dev);
        return;
    }

    /* Snapshot both descriptors while we hold them. */
    memcpy(s_raw_device, ddesc, sizeof(s_raw_device));
    s_raw_config_len = (cdesc->wTotalLength > sizeof(s_raw_config))
                     ? (uint16_t)sizeof(s_raw_config) : cdesc->wTotalLength;
    memcpy(s_raw_config, cdesc, s_raw_config_len);

    xSemaphoreTake(s_lock, portMAX_DELAY);
    memset(&s_info, 0, sizeof(s_info));
    s_info.dev_addr = address;
    s_info.vid      = ddesc->idVendor;
    s_info.pid      = ddesc->idProduct;

    for (int i = 0; i < cdesc->bNumInterfaces && s_info.itf_count < MAKCU_HIDHOST_MAX_IF; i++) {
        record_interface(cdesc, i);
    }

    /* Claim every interface we recorded; failures are only warnings because a
     * composite device may expose interfaces someone else already owns. */
    for (int i = 0; i < s_info.itf_count; i++) {
        esp_err_t err = usb_host_interface_claim(s_client, dev,
                                                 s_info.itf[i].iface, s_info.itf[i].alt);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "claim itf %u failed: %s (submits will fail until this succeeds)",
                     s_info.itf[i].iface, esp_err_to_name(err));
        }
    }
    s_info.attached = true;
    s_dev = dev;
    s_dev_addr = address;
    xSemaphoreGive(s_lock);

    ESP_LOGI(TAG, "attached %04x:%04x addr=%u itfs=%u",
             s_info.vid, s_info.pid, s_info.dev_addr, s_info.itf_count);

    xSemaphoreTake(s_lock, portMAX_DELAY);
    disarm_in_endpoints();          /* free anything left from a previous attach */
    arm_in_endpoints();
    xSemaphoreGive(s_lock);

    if (s_rearm_task == NULL) {
        xTaskCreate(rearm_task, "km_rearm", 3072, NULL, 5, &s_rearm_task);
    }
}

static void arm_in_endpoints(void)
{
    for (uint8_t i = 0; i < s_info.itf_count; i++) {
        const uint8_t addr = s_info.itf[i].in_addr;
        if (addr == 0 || s_in_count >= MAKCU_HIDHOST_MAX_EP) {
            continue;
        }
        in_ep_t *slot = &s_in[s_in_count];
        memset(slot, 0, sizeof(*slot));
        slot->ep = addr;
        slot->armed = true;
        for (int k = 0; k < IN_XFERS_PER_EP; k++) {
            usb_transfer_t *x = NULL;
            if (usb_host_transfer_alloc(IN_BUFFER_SIZE, 0, &x) != ESP_OK || x == NULL) {
                ESP_LOGW(TAG, "transfer alloc failed for ep 0x%02x", addr);
                break;
            }
            x->device_handle    = s_dev;
            x->bEndpointAddress = addr;
            x->callback         = in_xfer_cb;
            x->context          = slot;
            x->num_bytes        = (s_info.itf[i].in_mps != 0) ? s_info.itf[i].in_mps
                                                              : IN_BUFFER_SIZE;
            slot->xfer[k] = x;
            slot->count++;
            const esp_err_t serr = usb_host_transfer_submit(x);
            if (serr == ESP_OK) { s_submit_ok++; } else { s_submit_fail++; }
        }
        s_in_count++;
        ESP_LOGI(TAG, "armed IN 0x%02x with %d transfers", addr, slot->count);
    }
}

static void in_xfer_cb(usb_transfer_t *xfer)
{
    in_ep_t *slot = (in_ep_t *)xfer->context;
    if (slot == NULL) {
        return;
    }
    if (xfer->status == USB_TRANSFER_STATUS_COMPLETED) {
        s_complete++;
        if (xfer->actual_num_bytes > 0) {
            const makcu_hidhost_sink_t sink = s_sink;
            if (sink != NULL) {
                sink(slot->ep, xfer->data_buffer, (uint8_t)xfer->actual_num_bytes);
                s_forwarded++;
            }
        }
    }
    /* Only keep the pipeline going when the previous transfer really completed.
     * Re-submitting after an error spins on a stale device handle (submit fails
     * immediately, the callback fires again...) and starves the whole chip -
     * that is what killed the report path after a mouse replug. */
    if (slot->armed && xfer->status == USB_TRANSFER_STATUS_COMPLETED) {
        const esp_err_t serr = usb_host_transfer_submit(xfer);
        if (serr == ESP_OK) { s_submit_ok++; } else { s_submit_fail++; }
    } else if (slot->armed) {
        s_submit_fail++;
        slot->armed = false;          /* ensure_armed() retries it every 300 ms */
    }
}

static void disarm_in_endpoints(void)
{
    for (uint8_t i = 0; i < s_in_count; i++) {
        s_in[i].armed = false;
        /* Free the transfers: they are bound to the old device handle and, more
         * importantly, the DMA pool is finite - leaking them made every re-attach
         * arm fewer endpoints until arming silently failed and the mouse died. */
        for (int k = 0; k < IN_XFERS_PER_EP; k++) {
            if (s_in[i].xfer[k] != NULL) {
                usb_host_transfer_free(s_in[i].xfer[k]);
                s_in[i].xfer[k] = NULL;
            }
        }
        s_in[i].count = 0;
    }
    s_in_count = 0;
}

void makcu_hidhost_set_sink(makcu_hidhost_sink_t sink)
{
    s_sink = sink;
}

static void device_gone(uint8_t address)
{
    s_raw_device[0]  = 0;          /* no device: raw_* report "unavailable" */
    s_raw_config_len = 0;
    disarm_in_endpoints();
    xSemaphoreTake(s_lock, portMAX_DELAY);
    usb_device_handle_t dev = s_dev;
    const uint8_t was_addr = (address != 0) ? address : s_dev_addr;
    s_dev = NULL;
    s_dev_addr = 0;
    s_info.attached = false;
    s_info.dev_addr = 0;
    s_info.itf_count = 0;
    xSemaphoreGive(s_lock);

    if (dev != NULL) {
        for (int i = 0; i < MAKCU_HIDHOST_MAX_IF; i++) {
            (void)usb_host_interface_release(s_client, dev, s_info.itf[i].iface);
        }
        usb_host_device_close(s_client, dev);
        /* reclaim the IN transfers we allocated for this device */
        (void)usb_host_device_free_all();
        for (uint8_t i = 0; i < MAKCU_HIDHOST_MAX_EP; i++) {
            for (int k = 0; k < IN_XFERS_PER_EP; k++) {
                s_in[i].xfer[k] = NULL;
            }
        }
    }
    ESP_LOGI(TAG, "detached (addr was %u)", was_addr);
}

/* ------------------------------------------------------------ client events */

static void client_event_cb(const usb_host_client_event_msg_t *msg, void *arg)
{
    (void)arg;
    switch (msg->event) {
    case USB_HOST_CLIENT_EVENT_NEW_DEV:
        device_attached(msg->new_dev.address);
        break;
    case USB_HOST_CLIENT_EVENT_DEV_GONE:
        device_gone(s_dev_addr);
        break;
    default:
        break;
    }
}

static void lib_task(void *arg)
{
    (void)arg;
    for (;;) {
        uint32_t flags = 0;
        usb_host_lib_handle_events(portMAX_DELAY, &flags);
        if (flags & USB_HOST_LIB_EVENT_FLAGS_NO_CLIENTS) {
            /* we keep our client registered for the whole run */
        }
        if (flags & USB_HOST_LIB_EVENT_FLAGS_ALL_FREE) {
            ESP_LOGD(TAG, "host stack idle");
        }
    }
}

static void client_task(void *arg)
{
    (void)arg;
    for (;;) {
        usb_host_client_handle_events(s_client, portMAX_DELAY);
    }
}

/* --------------------------------------------------------------------- API */

esp_err_t makcu_hidhost_start(void)
{
    if (s_started) {
        return ESP_OK;
    }
    if (s_lock == NULL) {
        s_lock = xSemaphoreCreateMutex();
        if (s_lock == NULL) {
            return ESP_ERR_NO_MEM;
        }
    }

    const usb_host_config_t host_config = {
        .skip_phy_setup = false,
        .intr_flags     = ESP_INTR_FLAG_LEVEL1,
    };
    esp_err_t err = usb_host_install(&host_config);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "usb_host_install: %s", esp_err_to_name(err));
        return err;
    }

    const usb_host_client_config_t client_config = {
        .is_synchronous   = false,
        .max_num_event_msg = 5,
        .async = {
            .client_event_callback = client_event_cb,
            .callback_arg          = NULL,
        },
    };
    err = usb_host_client_register(&client_config, &s_client);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "client_register: %s", esp_err_to_name(err));
        return err;
    }

    /* The report path runs in these tasks: they must outrank the link reader,
     * otherwise at 1 kHz the reader preempts them, an IN transfer is not armed in
     * time and the mouse's FIFO overwrites a report - which shows up as "the
     * cursor moves slower than the real mouse". */
    BaseType_t ok = xTaskCreate(lib_task, "usb_lib", 4096, NULL, 12, NULL);
    if (ok != pdPASS) {
        return ESP_ERR_NO_MEM;
    }
    ok = xTaskCreate(client_task, "usb_cli", 4096, NULL, 11, NULL);
    if (ok != pdPASS) {
        return ESP_ERR_NO_MEM;
    }

    s_started = true;
    ESP_LOGI(TAG, "usb host installed");
    return ESP_OK;
}

bool makcu_hidhost_attached(void)
{
    if (s_lock == NULL) {
        return false;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    const bool v = s_info.attached;
    xSemaphoreGive(s_lock);
    return v;
}

uint8_t makcu_hidhost_session(void)
{
    if (s_lock == NULL) {
        return 0;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    const uint8_t v = s_info.attached ? s_info.dev_addr : 0;
    xSemaphoreGive(s_lock);
    return v;
}

void makcu_hidhost_info(makcu_hidhost_info_t *out)
{
    if (out == NULL) {
        return;
    }
    if (s_lock == NULL) {
        memset(out, 0, sizeof(*out));
        return;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    *out = s_info;
    xSemaphoreGive(s_lock);
}

/* 16-bit: the old 8-bit values saturated at 255 within a second of 1 kHz
 * traffic, so a long run could not tell "still growing" from "stuck". */
static uint16_t sat16(uint32_t v) { return (v > 0xFFFFu) ? 0xFFFFu : (uint16_t)v; }

void makcu_hidhost_stats(uint16_t *submit_ok, uint16_t *submit_fail,
                         uint16_t *complete, uint16_t *forwarded)
{
    if (submit_ok  != NULL) { *submit_ok  = sat16(s_submit_ok); }
    if (submit_fail != NULL) { *submit_fail = sat16(s_submit_fail); }
    if (complete  != NULL) { *complete  = sat16(s_complete); }
    if (forwarded != NULL) { *forwarded = sat16(s_forwarded); }
}

/* 精确的 u32 计数（2026-11-11 加）。
 * 原来的 u16 版本满 65535 就卡住不动（实测两次读都 +0），导致"右片每秒到底收到/转发
 * 多少条"完全看不出来 —— 而 `done` vs `fwd` 的比值正是判断"鼠标没发那么多"还是
 * "右片没读全"的关键证据。 */
void makcu_hidhost_stats32(uint32_t *submit_ok, uint32_t *submit_fail,
                           uint32_t *complete, uint32_t *forwarded)
{
    if (submit_ok  != NULL) { *submit_ok  = s_submit_ok; }
    if (submit_fail != NULL) { *submit_fail = s_submit_fail; }
    if (complete  != NULL) { *complete  = s_complete; }
    if (forwarded != NULL) { *forwarded = s_forwarded; }
}

/* ------------------------------------------------------- EP0 control (M3) */

#define CTL_MAX 256

typedef struct {
    SemaphoreHandle_t done;
    int               actual;      /* -1 = failed */
    int               want;
} ctl_ctx_t;

static void ctl_cb(usb_transfer_t *xfer)
{
    ctl_ctx_t *ctx = (ctl_ctx_t *)xfer->context;
    if (ctx == NULL) {
        return;
    }
    ctx->actual = (xfer->status == USB_TRANSFER_STATUS_COMPLETED)
                ? (int)xfer->actual_num_bytes : -1;
    if (ctx->done != NULL) {
        xSemaphoreGive(ctx->done);
    }
}

int makcu_hidhost_control(const uint8_t setup[8], uint8_t *out, size_t cap,
                          uint32_t timeout_ms)
{
    if (setup == NULL || out == NULL || cap == 0 || !s_started) {
        return -1;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    usb_device_handle_t dev = s_dev;
    xSemaphoreGive(s_lock);
    if (dev == NULL) {
        return -1;
    }

    /* IDF puts the setup packet in data_buffer[0..7]; the data stage follows it
     * and actual_num_bytes counts both. */
    const uint16_t wlength = (uint16_t)setup[6] | ((uint16_t)setup[7] << 8);
    size_t dlen = (wlength == 0) ? 0u : (size_t)wlength;
    if (dlen > cap) {
        dlen = cap;
    }
    if (dlen > CTL_MAX) {
        dlen = CTL_MAX;
    }
    const size_t bufsize = 8u + dlen;

    usb_transfer_t *xfer = NULL;
    if (usb_host_transfer_alloc(bufsize, 0, &xfer) != ESP_OK || xfer == NULL) {
        return -1;
    }

    ctl_ctx_t ctx = { .done = xSemaphoreCreateBinary(), .actual = -2, .want = (int)bufsize };
    if (ctx.done == NULL) {
        usb_host_transfer_free(xfer);
        return -1;
    }

    xfer->device_handle    = dev;
    xfer->bEndpointAddress = 0;
    xfer->callback         = ctl_cb;
    xfer->context          = &ctx;
    xfer->num_bytes        = (int)bufsize;
    memcpy(xfer->data_buffer, setup, 8);

    int result = -1;
    if (usb_host_transfer_submit_control(s_client, xfer) == ESP_OK) {
        if (xSemaphoreTake(ctx.done, pdMS_TO_TICKS(timeout_ms == 0 ? 100 : timeout_ms)) == pdTRUE) {
            if (ctx.actual >= 8) {
                int n = ctx.actual - 8;                /* skip the setup packet */
                if (n > (int)cap) {
                    n = (int)cap;
                }
                if (n > 0) {
                    memcpy(out, xfer->data_buffer + 8, (size_t)n);
                }
                result = n;
            } else if (ctx.actual >= 0) {
                result = 0;                            /* status-only transfer */
            }
        }
    }
    vSemaphoreDelete(ctx.done);
    usb_host_transfer_free(xfer);
    return result;
}

/* --------------------------------------------------------- OUT submit (M4) */

typedef struct {
    SemaphoreHandle_t done;
    int               status;
} out_ctx_t;

static void out_cb(usb_transfer_t *xfer)
{
    out_ctx_t *ctx = (out_ctx_t *)xfer->context;
    if (ctx == NULL) {
        return;
    }
    ctx->status = (xfer->status == USB_TRANSFER_STATUS_COMPLETED) ? 0 : -1;
    if (ctx->done != NULL) {
        xSemaphoreGive(ctx->done);
    }
}

int makcu_hidhost_out(uint8_t ep, const uint8_t *data, uint16_t len, uint32_t timeout_ms)
{
    if (data == NULL || len == 0 || !s_started) {
        return -1;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    usb_device_handle_t dev = s_dev;
    xSemaphoreGive(s_lock);
    if (dev == NULL) {
        return -1;
    }

    usb_transfer_t *xfer = NULL;
    if (usb_host_transfer_alloc(len, 0, &xfer) != ESP_OK || xfer == NULL) {
        return -1;
    }
    out_ctx_t ctx = { .done = xSemaphoreCreateBinary(), .status = -2 };
    if (ctx.done == NULL) {
        usb_host_transfer_free(xfer);
        return -1;
    }

    memcpy(xfer->data_buffer, data, len);
    xfer->device_handle    = dev;
    xfer->bEndpointAddress = ep;
    xfer->callback         = out_cb;
    xfer->context          = &ctx;
    xfer->num_bytes        = (int)len;

    int result = -1;
    if (usb_host_transfer_submit(xfer) == ESP_OK) {
        if (xSemaphoreTake(ctx.done, pdMS_TO_TICKS(timeout_ms == 0 ? 100 : timeout_ms)) == pdTRUE) {
            if (ctx.status == 0) {
                result = 0;
            }
        }
    }
    vSemaphoreDelete(ctx.done);
    usb_host_transfer_free(xfer);
    return result;
}

/* ------------------------------------------------ asynchronous OUT (M5) */

/* A pre-allocated pool: IDF forbids freeing a transfer from inside its own
 * completion callback (the stack still owns it) - doing that corrupted the heap
 * and the whole right chip stopped answering. */
#define OUT_POOL_N    3
#define OUT_POOL_SIZE 128

typedef struct {
    usb_transfer_t *xfer;
    volatile bool   busy;
} out_slot_t;

static out_slot_t s_out_pool[OUT_POOL_N];
static bool       s_out_pool_ready;

static void out_pool_init(void)
{
    if (s_out_pool_ready) {
        return;
    }
    for (int i = 0; i < OUT_POOL_N; i++) {
        if (usb_host_transfer_alloc(OUT_POOL_SIZE, 0, &s_out_pool[i].xfer) != ESP_OK) {
            s_out_pool[i].xfer = NULL;
        }
        s_out_pool[i].busy = false;
    }
    s_out_pool_ready = true;
}

static void out_pool_cb(usb_transfer_t *xfer)
{
    out_slot_t *slot = (out_slot_t *)xfer->context;
    if (slot != NULL) {
        slot->busy = false;          /* reusable again; never freed here */
    }
}

int makcu_hidhost_out_async(uint8_t ep, const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0 || len > OUT_POOL_SIZE || !s_started) {
        return -1;
    }
    xSemaphoreTake(s_lock, portMAX_DELAY);
    usb_device_handle_t dev = s_dev;
    xSemaphoreGive(s_lock);
    if (dev == NULL) {
        return -1;
    }

    out_pool_init();

    for (int i = 0; i < OUT_POOL_N; i++) {
        out_slot_t *slot = &s_out_pool[i];
        if (slot->xfer == NULL || slot->busy) {
            continue;
        }
        memcpy(slot->xfer->data_buffer, data, len);
        slot->xfer->device_handle    = dev;
        slot->xfer->bEndpointAddress = ep;
        slot->xfer->callback         = out_pool_cb;
        slot->xfer->context          = slot;
        slot->xfer->num_bytes        = (int)len;
        slot->busy = true;
        if (usb_host_transfer_submit(slot->xfer) != ESP_OK) {
            slot->busy = false;
            return -1;
        }
        return 0;
    }
    return -1;                        /* all slots busy: caller may retry */
}
