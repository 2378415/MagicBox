p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
old_start = t.find("    if (len >= 5 && line[3] == 'd' && line[4] == 'v') {")
old_end = t.find("    if (len >= 5 && line[3] == 'c' && line[4] == 'l') {")
if old_start != -1 and old_end > old_start:
    new = '''    if (len >= 5 && line[3] == 'd' && line[4] == 'v') {
        /* full hex dump of what the device stack would hand to the host */
        const uint8_t *dev = tud_descriptor_device_cb();
        const uint8_t *cfg = tud_descriptor_configuration_cb(0);
        const uint8_t *rep = tud_hid_descriptor_report_cb(0);
        const makcu_clone_t *c = makcu_clone_get();
        const unsigned cfg_len = (c != NULL && c->valid && c->config_len) ? c->config_len : 34u;
        const unsigned rep_len = (c != NULL && c->valid && c->report_len) ? c->report_len : 52u;
        char out[256];
        size_t at = 0;
        at += (size_t)snprintf(out + at, sizeof(out) - at, "init=%u mnt=%u ",
                               makcu_hiddev_init_ok() ? 1u : 0u,
                               makcu_hiddev_mounted() ? 1u : 0u);
        for (unsigned i = 0; i < 18; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev[i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " ");
        for (unsigned i = 0; i < cfg_len; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", cfg[i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " rep%u:%02x", rep_len, rep[0]);
        makcu_reply(out, at);
        return 1;
    }
'''
    t = t[:old_start] + new + t[old_end:]
    open(p,"w",encoding="utf-8").write(t)
    print("mx.dv now dumps full descriptors")
