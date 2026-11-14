"""Reference model for the curved path (mirrors run_move/bezier_point in C).

Invariants the firmware must satisfy:
  * steps sum exactly to the request on both axes;
  * every step component stays inside the int8 report limit;
  * a long move bows away from the straight line; a short one stays straight.

Run:  python -m pytest verification/model -q
"""
STEP_LIMIT = 127
TRACE = 16


def steps_for(dx: int, dy: int) -> int:
    span = max(abs(dx), abs(dy))
    return max(1, -(-span // STEP_LIMIT))   # never capped by the trace ring


def offset_for(span: int, rnd: int) -> int:
    if span < 8:
        return 0
    limit = span // 8
    return rnd % (2 * limit + 1) - limit


def bezier_point(dx: int, dy: int, steps: int, step: int, off: int, span: int):
    span = span or 1
    cx = dx // 2 - (dy * off) // span
    cy = dy // 2 + (dx * off) // span
    t = step * 1024 // steps
    mt = 1024 - t
    a, b, c = mt * mt, 2 * mt * t, t * t
    scale = 1024 * 1024
    return (b * cx + c * dx) // scale, (b * cy + c * dy) // scale


def _fold(steps, target, axis):
    """Push the rounding residue into steps that still have head-room."""
    total = sum(s[axis] for s in steps)
    rest = target - total
    guard = 0
    while rest != 0 and guard < 4096:
        guard += 1
        for i in range(len(steps) - 1, -1, -1):
            v = steps[i][axis]
            room = (STEP_LIMIT - v) if rest > 0 else (v + STEP_LIMIT)
            if room <= 0:
                continue
            d = max(-room, min(room, rest))
            nv = list(steps[i])
            nv[axis] = v + d
            steps[i] = tuple(nv)
            rest -= d
            break
        else:
            break
    return steps


def plan(dx: int, dy: int, off: int = 0):
    steps = steps_for(dx, dy)
    if steps == 1:
        return [(dx, dy)]
    span = max(abs(dx), abs(dy))
    out, px, py = [], 0, 0
    for i in range(1, steps + 1):
        qx, qy = bezier_point(dx, dy, steps, i, off, span)
        sx = max(-STEP_LIMIT, min(STEP_LIMIT, qx - px))
        sy = max(-STEP_LIMIT, min(STEP_LIMIT, qy - py))
        out.append((sx, sy))
        px, py = qx, qy
    out = _fold(out, dx, 0)
    out = _fold(out, dy, 1)
    return out


def path(dx, dy, off=0):
    pts, x, y = [(0, 0)], 0, 0
    for sx, sy in plan(dx, dy, off):
        x, y = x + sx, y + sy
        pts.append((x, y))
    return pts


def deviation(dx, dy, off=0):
    """Largest perpendicular distance of the path from the straight line."""
    pts = path(dx, dy, off)
    nx, ny = -dy, dx
    norm = (nx * nx + ny * ny) ** 0.5 or 1.0
    return max(abs((px * nx + py * ny) / norm) for px, py in pts)


def test_sum_is_exact():
    for dx, dy in ((300, 0), (-260, 130), (1900, -1900), (37, -900), (5, 5), (-1000, 0)):
        for off in (0, 40, -70):
            steps = plan(dx, dy, off)
            assert sum(x for x, _ in steps) == dx
            assert sum(y for _, y in steps) == dy


def test_components_stay_in_int8():
    for dx, dy in ((300, 0), (-1000, 700), (254, 254), (1900, 0)):
        for off in (0, 55, -55):
            for x, y in plan(dx, dy, off):
                assert -127 <= x <= 127 and -127 <= y <= 127


def test_long_move_bows():
    assert deviation(600, 0, off=0) == 0            # no offset -> straight
    assert deviation(600, 0, off=70) >= 20          # offset -> real bow
    assert deviation(600, 0, off=-70) >= 20


def test_offset_is_bounded():
    for span in (8, 100, 600, 2000):
        limit = span // 8
        assert all(abs(offset_for(span, r)) <= limit for r in range(50))


def test_short_move_is_straight():
    assert plan(20, 10) == [(20, 10)]
    assert deviation(20, 10, off=offset_for(20, 7)) == 0
