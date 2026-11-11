p="components/makcu_mouse/src/makcu_mouse.c"
t=open(p,encoding="utf-8").read()
t=t.replace("""const makcu_report_t *makcu_mouse_trace(unsigned *count)
{
    if (count != NULL) {
        *count = s_trace_count;
    }
    return s_trace;
}""","""/* Chronological copy: once the ring wraps, the oldest entry is at s_trace_pos. */
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
}""")
open(p,"w",encoding="utf-8").write(t)
print("trace ordering fixed")
