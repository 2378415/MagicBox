p="components/makcu_mouse/include/makcu_mouse.h"
t=open(p,encoding="utf-8").read()
if "MAKCU_REPORT_TRACE" not in t:
    t=t.replace("""/* Last report emitted (bench observability, used by the mx.rp test command). */
const makcu_report_t *makcu_mouse_last_report(void);""",
"""/* Last report emitted (bench observability, used by the mx.rp test command). */
const makcu_report_t *makcu_mouse_last_report(void);

/* Ring of the most recent reports, for the mx.rq trace command and the T2
 * checks that assert "how the movement was split". */
#define MAKCU_REPORT_TRACE 16
const makcu_report_t *makcu_mouse_trace(unsigned *count);""")
    open(p,"w",encoding="utf-8").write(t)

p="components/makcu_mouse/src/makcu_mouse.c"
t=open(p,encoding="utf-8").read()
if "MAKCU_REPORT_TRACE" not in t:
    t=t.replace("static makcu_report_t    s_last;",
"""static makcu_report_t    s_last;
static makcu_report_t    s_trace[16];
static unsigned          s_trace_count;
static unsigned          s_trace_pos;""")
    t=t.replace("""static void emit(int8_t dx, int8_t dy, int8_t wheel)
{
    makcu_report_t r = { dx, dy, wheel, 0 };
    s_last = r;
    if (makcu_hid_report_hook != NULL) {
        makcu_hid_report_hook(&r);
    }
}""","""static void emit(int8_t dx, int8_t dy, int8_t wheel)
{
    makcu_report_t r = { dx, dy, wheel, 0 };
    s_last = r;
    s_trace[s_trace_pos] = r;
    s_trace_pos = (s_trace_pos + 1) % MAKCU_REPORT_TRACE;
    if (s_trace_count < MAKCU_REPORT_TRACE) {
        s_trace_count++;
    }
    if (makcu_hid_report_hook != NULL) {
        makcu_hid_report_hook(&r);
    }
}

const makcu_report_t *makcu_mouse_trace(unsigned *count)
{
    if (count != NULL) {
        *count = s_trace_count;
    }
    return s_trace;
}""")
    open(p,"w",encoding="utf-8").write(t)
print("trace ring added")
