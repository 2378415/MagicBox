p="components/makcu_link/src/makcu_link_bridge.c"
t=open(p,encoding="utf-8").read()
if "makcu_link_loopback_selftest" not in t:
    t=t.replace("""void makcu_link_set_loopback(bool on)""","""size_t makcu_link_loopback_selftest(const uint8_t *payload, uint16_t len)
{
    if (!s_ready) {
        return 0;
    }
    /* The loopback bit routes TXD into RXD inside the peripheral, so it has to
     * stay set until the TX FIFO has actually shifted the frame out - clearing
     * it right after uart_write_bytes() loses the frame. */
    uart_set_loop_back(LINK_UART, true);
    const size_t sent = makcu_link_send(MAKCU_LINK_HID, payload, len);
    uart_wait_tx_done(LINK_UART, pdMS_TO_TICKS(50));
    vTaskDelay(pdMS_TO_TICKS(20));
    return sent;
}

void makcu_link_set_loopback(bool on)""")
    open(p,"w",encoding="utf-8").write(t)

p="components/makcu_link/include/makcu_link_bridge.h"
t=open(p,encoding="utf-8").read()
t=t.replace("/* Bench helper: route UART1 TX back into its own RX. */",
"""/* Bench self-test: enable the internal UART loopback, send one frame through it
 * and wait until the bytes were shifted out.  Loopback stays enabled so the RX
 * side has time to see the frame; call makcu_link_set_loopback(false) to stop. */
size_t makcu_link_loopback_selftest(const uint8_t *payload, uint16_t len);

/* Bench helper: route UART1 TX back into its own RX. */""")
open(p,"w",encoding="utf-8").write(t)

p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""        makcu_link_set_loopback(true);
        const uint8_t payload[9] = { 0x01, 0x22, 0x05, 0x00, 0xDE, 0xAD, 0xBE, 0xEF, 0x11 };
        const size_t sent = makcu_link_send(0xA2, payload, sizeof(payload));
        makcu_link_set_loopback(false);""","""        const uint8_t payload[9] = { 0x01, 0x22, 0x05, 0x00, 0xDE, 0xAD, 0xBE, 0xEF, 0x11 };
        const size_t sent = makcu_link_loopback_selftest(payload, sizeof(payload));""")
t=t.replace("""    if (len >= 5 && line[3] == 'l' && line[4] == 's') {""","""    if (len >= 6 && line[3] == 'l' && line[4] == 'b' && line[5] == '0') {
        makcu_link_set_loopback(false);
        makcu_reply("0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 's') {""")
open(p,"w",encoding="utf-8").write(t)
print("loopback self-test wired")
