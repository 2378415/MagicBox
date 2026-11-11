p="components/makcu_mouse/src/makcu_mouse.c"
t=open(p,encoding="utf-8").read()
if "bezier" not in t:
    t=t.replace("""/* ------------------------------------------------------------- step engine */""",
"""/* ------------------------------------------------------------- step engine */""")
    t=t.replace("""static void run_move(int16_t dx, int16_t dy, int16_t wheel)
{""","""/*
 * Curved path.  The original rotates the requested vector by a random angle and
 * walks a sine/cosine shape (0x4200EFEC head); the exact double arithmetic is not
 * reproduced here, but the observable shape is: a bowed path whose curvature is
 * random per move and bounded by a fraction of the span.  Quadratic Bezier with
 * a random perpendicular control offset gives that shape, and sampling with
 * rounding-on-cumulative-position keeps the sum exactly equal to the request.
 */
static int bezier_offset(int span)
{
    if (span < 8) {
        return 0;                              /* short moves stay straight */
    }
    const int limit = span / 8;
    const int r = (int)(esp_random() % (uint32_t)(2 * limit + 1));
    return r - limit;
}

static void bezier_point(int dx, int dy, int steps, int step, int64_t *out_x, int64_t *out_y)
{
    /* P0 = (0,0), P1 = (dx,dy), control C = midpoint + perpendicular offset */
    const int span = (dx < 0 ? -dx : dx) > (dy < 0 ? -dy : dy)
                     ? (dx < 0 ? -dx : dx) : (dy < 0 ? -dy : dy);
    const int off = bezier_offset(span);
    /* perpendicular of (dx,dy), normalised by the span */
    const int64_t cx = (int64_t)dx / 2 - ((int64_t)dy * off) / (span ? span : 1);
    const int64_t cy = (int64_t)dy / 2 + ((int64_t)dx * off) / (span ? span : 1);

    /* t in 0..1 sampled at step/steps, using 1/1024 fixed point */
    const int64_t t = (int64_t)step * 1024 / steps;
    const int64_t mt = 1024 - t;
    const int64_t a = mt * mt;                 /* (1-t)^2, scaled 1024^2 */
    const int64_t b = 2 * mt * t;
    const int64_t c = t * t;
    const int64_t scale = 1024LL * 1024LL;
    *out_x = (a * 0 + b * cx + c * dx) / scale;
    *out_y = (a * 0 + b * cy + c * dy) / scale;
}

static void run_move(int16_t dx, int16_t dy, int16_t wheel)
{""")
    t=t.replace("""    int8_t xs[MAKCU_REPORT_TRACE] = {0};
    int8_t ys[MAKCU_REPORT_TRACE] = {0};
    distribute(dx, steps, xs);
    distribute(dy, steps, ys);
""","""    int8_t xs[MAKCU_REPORT_TRACE] = {0};
    int8_t ys[MAKCU_REPORT_TRACE] = {0};
    if (steps == 1) {
        xs[0] = (int8_t)dx;
        ys[0] = (int8_t)dy;
    } else {
        /* sample the curve and take first differences of the rounded positions */
        int64_t px = 0, py = 0;
        for (int i = 1; i <= steps; i++) {
            int64_t qx, qy;
            bezier_point(dx, dy, steps, i, &qx, &qy);
            int64_t step_x = qx - px;
            int64_t step_y = qy - py;
            if (step_x > 127) step_x = 127;
            if (step_x < -127) step_x = -127;
            if (step_y > 127) step_y = 127;
            if (step_y < -127) step_y = -127;
            xs[i - 1] = (int8_t)step_x;
            ys[i - 1] = (int8_t)step_y;
            px = qx;
            py = qy;
        }
        /* fold the rounding residue of the last sample into the final step so the
         * sum still equals the request exactly */
        int sum_x = 0, sum_y = 0;
        for (int i = 0; i < steps; i++) { sum_x += xs[i]; sum_y += ys[i]; }
        int fix_x = dx - sum_x;
        int fix_y = dy - sum_y;
        while (fix_x != 0) {
            int d = fix_x > 0 ? (fix_x > 127 ? 127 : fix_x) : (fix_x < -127 ? -127 : fix_x);
            xs[steps - 1] = (int8_t)(xs[steps - 1] + d);
            fix_x -= d;
        }
        while (fix_y != 0) {
            int d = fix_y > 0 ? (fix_y > 127 ? 127 : fix_y) : (fix_y < -127 ? -127 : fix_y);
            ys[steps - 1] = (int8_t)(ys[steps - 1] + d);
            fix_y -= d;
        }
    }
""")
    t=t.replace('#include "freertos/FreeRTOS.h"','#include "esp_random.h"\n\n#include "freertos/FreeRTOS.h"')
    open(p,"w",encoding="utf-8").write(t)
print("bezier path added")
