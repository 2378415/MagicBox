p="components/makcu_link/CMakeLists.txt"
open(p,"w",encoding="utf-8").write('''idf_component_register(
    SRCS "src/makcu_link.c" "src/makcu_link_bridge.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_driver_uart
)
''')
print(open(p,encoding="utf-8").read())

# app: init bridge + mx.lb / mx.dc / mx.ls debug commands
p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_link_bridge_init" not in t:
    t=t.replace('#include "makcu_keyboard.h"','#include "makcu_keyboard.h"\n#include "makcu_link_bridge.h"')
    t=t.replace("    makcu_keyboard_init();","""    makcu_keyboard_init();
    makcu_link_bridge_init();""")
    t=t.replace("""    if (len >= 5 && line[3] == 'r' && line[4] == 'k') {""","""    if (len >= 5 && line[3] == 'l' && line[4] == 'b') {
        /* loopback bench: route UART1 TX into its own RX, send one 0xA2 chunk */
        makcu_link_set_loopback(true);
        const uint8_t payload[9] = { 0x01, 0x22, 0x05, 0x00, 0xDE, 0xAD, 0xBE, 0xEF, 0x11 };
        const size_t sent = makcu_link_send(0xA2, payload, sizeof(payload));
        makcu_link_set_loopback(false);
        char out[16];
        const int n = snprintf(out, sizeof(out), "%u", (unsigned)sent);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 's') {
        const makcu_link_stats_t st = makcu_link_stats();
        char out[96];
        const int n = snprintf(out, sizeof(out), "%u,%u,%u,%u,%u,%u,%u",
                               (unsigned)st.frames, (unsigned)st.ep0_requests,
                               (unsigned)st.ep0_in, (unsigned)st.ep0_out,
                               (unsigned)st.hid_chunks, (unsigned)st.a3_frames,
                               (unsigned)st.unknown);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'c') {
        /* mx.dc <endpoint> -> hex of what the bridge reassembled */
        int ep = 0;
        if (len > 6 && line[6] >= '0' && line[6] <= '7') {
            ep = line[6] - '0';
        }
        uint8_t buf[64];
        const size_t n = makcu_link_chunk(ep, buf, sizeof(buf));
        char out[64 * 2 + 1];
        size_t at = 0;
        for (size_t i = 0; i < n; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", buf[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'k') {""")
    open(p,"w",encoding="utf-8").write(t)
print("app wired for link bridge")
