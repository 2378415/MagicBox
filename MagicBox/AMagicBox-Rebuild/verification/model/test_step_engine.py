"""Reference model for the mouse step engine (mirrors makcu_mouse.c).

The C side cannot be exercised right now (the bench board needs a manual BOOT
press to re-enter download mode), so this file pins the *algorithm* the C
implements and is kept in sync by review:

    STEP_LIMIT = 127          # int8 report component limit
    steps      = ceil(span / STEP_LIMIT)   # spans the larger component
    each step  = largest-remainder split of the total, so the sum is exact

When the board is reachable again, verification/regress/test_mouse_reports.py
checks the same invariants against the firmware through `mx.rq`.
"""
import math

STEP_LIMIT = 127
TRACE = 16


def distribute(total: int, steps: int):
    sign = -1 if total < 0 else 1
    mag = abs(total)
    base, rem = divmod(mag, steps)
    return [sign * (base + (1 if i < rem else 0)) for i in range(steps)]


def plan(dx: int, dy: int):
    span = max(abs(dx), abs(dy))
    steps = max(1, math.ceil(span / STEP_LIMIT))
    xs, ys = distribute(dx, steps), distribute(dy, steps)
    return list(zip(xs, ys))


def test_single_report_when_small():
    assert plan(20, -5) == [(20, -5)]
    assert plan(0, 0) == [(0, 0)]


def test_split_keeps_components_inside_int8():
    for dx, dy in ((300, 0), (0, -400), (500, 500), (-1000, 300)):
        steps = plan(dx, dy)
        for x, y in steps:
            assert -127 <= x <= 127
            assert -127 <= y <= 127


def test_sum_is_exact():
    for dx, dy in ((300, 0), (127, 0), (128, 0), (-400, 250), (1900, -1900)):
        steps = plan(dx, dy)
        assert sum(x for x, _ in steps) == dx
        assert sum(y for _, y in steps) == dy


def test_step_count_matches_the_span():
    assert len(plan(127, 0)) == 1
    assert len(plan(128, 0)) == 2
    assert len(plan(255, 0)) == 3
    assert len(plan(0, -254)) == 2


def test_trace_does_not_cap_the_step_count():
    """The 16-entry report ring is observability only.  A move longer than
    16*127 = 2032 counts must still be split into ceil(span/127) reports and sum
    exactly - the first rebuild silently truncated those moves."""
    steps = plan(5000, 0)
    assert len(steps) == math.ceil(5000 / STEP_LIMIT) == 40
    assert sum(x for x, _ in steps) == 5000
    assert max(abs(x) for x, _ in steps) <= STEP_LIMIT
    # the full int16 range fits as well
    steps = plan(-32767, 32767)
    assert len(steps) == math.ceil(32767 / STEP_LIMIT)
    assert sum(x for x, _ in steps) == -32767
    assert sum(y for _, y in steps) == 32767
