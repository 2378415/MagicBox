p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "mx.rq" not in t and "line[3] == 'q'" not in t:
    t=t.replace("""    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {""","""    if (len >= 5 && line[3] == 'r' && line[4] == 'q') {
        /* trace dump: every report as 3 hex bytes, most recent last */
        unsigned count = 0;
        const makcu_report_t *tr = makcu_mouse_trace(&count);
        char out[16 * 6 + 1];
        size_t n = 0;
        for (unsigned i = 0; i < count; i++) {
            n += (size_t)snprintf(out + n, sizeof(out) - n, "%02x%02x%02x",
                                  (unsigned)(uint8_t)tr[i].dx,
                                  (unsigned)(uint8_t)tr[i].dy,
                                  (unsigned)(uint8_t)tr[i].wheel);
        }
        makcu_reply(out, n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {""")
    open(p,"w",encoding="utf-8").write(t)
print("mx.rq added")
