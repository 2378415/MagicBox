p="components/makcu_mouse/src/makcu_mouse.c"
t=open(p,encoding="utf-8").read()
# 1) drop the now unused distribute() helper
start = t.find("static int distribute(int16_t total, int steps, int8_t *out)")
if start != -1:
    end = t.find("/*\n * Curved path.", start)
    t = t[:start] + t[end:]
# 2) residue folding with head-room instead of dumping into the last step
t = t.replace("""        /* fold the rounding residue of the last sample into the final step so the
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
        }""",
"""        /* push the rounding residue into whichever steps still have head-room,
         * so the sum equals the request *and* no component leaves int8 */
        fold_residue(xs, steps, dx);
        fold_residue(ys, steps, dy);""")
t = t.replace("""static void run_move(int16_t dx, int16_t dy, int16_t wheel)
{""","""static void fold_residue(int8_t *v, int steps, int target)
{
    int sum = 0;
    for (int i = 0; i < steps; i++) {
        sum += v[i];
    }
    int rest = target - sum;
    int guard = 0;
    while (rest != 0 && guard++ < 4096) {
        int placed = 0;
        for (int i = steps - 1; i >= 0; i--) {
            const int room = (rest > 0) ? (STEP_LIMIT - v[i]) : (v[i] + STEP_LIMIT);
            if (room <= 0) {
                continue;
            }
            int d = (rest > room) ? room : ((rest < -room) ? -room : rest);
            v[i] = (int8_t)(v[i] + d);
            rest -= d;
            placed = 1;
            break;
        }
        if (!placed) {
            break;
        }
    }
}

static void run_move(int16_t dx, int16_t dy, int16_t wheel)
{""")
open(p,"w",encoding="utf-8").write(t)
print("C side aligned with the model")
