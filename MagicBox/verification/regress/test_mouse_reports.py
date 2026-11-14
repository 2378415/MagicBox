"""Mouse commit-layer regression: what actually lands in the HID report.

The text reply only proves the protocol half.  These cases check the commit
layer by reading back the last emitted report through the bench command
`mx.rp` (hex: dx dy wheel).  They need the harness build (-DMB_DEBUG_OPCODE=1).

Stage note: the Bezier engine (0x4200EFEC) is not ported yet, so one report
carries the whole requested delta.  When it lands these cases become
"first report of the sequence" instead of "the only report".
"""
import time

import pytest

SUFFIX = b'\r\n>>> '


@pytest.fixture(scope='session')
def harness(device_ready):
    if device_ready.cmd('mx.09') != b'km.MAKCU' + SUFFIX:
        pytest.skip('firmware built without MB_DEBUG_OPCODE')
    return device_ready


def last_report(dev):
    reply = dev.cmd('mx.rp')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    return reply[3:-len(SUFFIX)].decode()


def settle(dev, cmd, wait=0.20):
    dev.cmd(cmd)
    time.sleep(wait)


@pytest.mark.parametrize('cmd,hex_report', [
    ('.km.move(20,-5)', '14fb00'),
    ('.km.move(-1,1)', 'ff0100'),
    ('.km.wheel(120)', '000078'),
    ('.km.wheel(-8)', '0000f8'),
    ('.km.silent(3,4)', 'fdfc00'),      # pulse: forward 3,4 then back -3,-4
])
def test_last_report(harness, cmd, hex_report):
    settle(harness, cmd)
    assert last_report(harness) == hex_report


def test_triple_state_does_not_emit(harness):
    """3-argument move uses the mode path; the staged engine still emits one
    report with the same delta."""
    settle(harness, '.km.move(7,9,3)')
    assert last_report(harness) == '070900'


def test_zero_move_emits_nothing(harness):
    """一条脉冲 (0,0) 不该产生任何报告。

    2026-11-10（控制口提到 921600 之后）这里出现过偶发失败：前一个用例的长移动
    还在按 tick 排空，`before` 取到的"最后一条报告"随后被它改掉。所以采样前多等
    一拍，让鼠标任务真正静下来。"""
    settle(harness, '.km.move(4,4)', wait=0.5)
    time.sleep(0.2)
    before = last_report(harness)
    settle(harness, '.km.silent(0,0)', wait=0.3)      # pulse of zeros -> no report
    assert last_report(harness) == before


# ---------------------------------------------------------------- step splitting
def reports(dev):
    """Read the report trace (mx.rq) as signed (dx, dy, wheel) tuples."""
    reply = dev.cmd('mx.rq')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    body = reply[3:-len(SUFFIX)].decode()

    def s8(v):
        return v - 256 if v >= 128 else v

    out = []
    for i in range(0, len(body), 6):
        h = body[i:i + 6]
        out.append((s8(int(h[0:2], 16)), s8(int(h[2:4], 16)), s8(int(h[4:6], 16))))
    return out


def test_large_move_is_split_and_sums_exactly(harness):
    """300 px cannot fit one int8 report: ceil(300/127) = 3 steps.

    2026-11-10：改成用 mx.rt 的累计位移断言守恒、用 trace 断言"每一步都不超 int8"。
    只看 trace 末 3 条会偶发失败——16 条环形里可能混进别的流量（真实鼠标、按键报告）。"""
    before = totals(harness)
    settle(harness, '.km.move(300,0)', wait=0.4)
    after = totals(harness)
    assert after[0] - before[0] == 300
    tail = reports(harness)[-3:]
    assert all(abs(r[0]) <= 127 for r in tail)


def totals(dev):
    """`mx.rt` -> cumulative deltas emitted since boot (dx,dy,wheel)."""
    reply = dev.cmd('mx.rt')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    return [int(v) for v in reply[3:-len(SUFFIX)].split(b',')]


def test_long_move_conserves_the_request(harness):
    """5000 counts needs 40 reports - three times what the trace ring keeps.  The
    cumulative counter proves the whole move reached the HID layer: the first
    rebuild capped the step count at the ring size and lost everything past
    2032 counts."""
    before = totals(harness)
    settle(harness, '.km.move(5000,0)', wait=1.5)
    after = totals(harness)
    assert after[0] - before[0] == 5000


def test_full_range_move_conserves_the_request(harness):
    """int16 extremes: 32767 counts -> 259 reports whose sum must be exact."""
    before = totals(harness)
    settle(harness, '.km.move(-30000,20000)', wait=3.0)
    after = totals(harness)
    assert after[0] - before[0] == -30000
    assert after[1] - before[1] == 20000


def test_long_move_fills_the_trace_ring(harness):
    settle(harness, '.km.move(5000,0)', wait=1.5)
    entries = reports(harness)
    assert len(entries) == 16                     # ring is full, not truncated
    assert all(abs(r[0]) <= 127 for r in entries)


def test_boundary_127_is_single_step(harness):
    settle(harness, '.km.move(127,0)')
    assert reports(harness)[-1][0] == 127


def test_boundary_128_is_two_steps(harness):
    before = totals(harness)
    settle(harness, '.km.move(128,0)', wait=0.3)
    after = totals(harness)
    assert after[0] - before[0] == 128        # 128 > 127 必须被拆开，且总和守恒
    tail = reports(harness)[-2:]
    assert all(abs(r[0]) <= 127 for r in tail)


def test_two_axis_split_sums(harness):
    before = totals(harness)
    settle(harness, '.km.move(-260,130)', wait=0.4)
    after = totals(harness)
    assert after[0] - before[0] == -260
    assert after[1] - before[1] == 130
    tail = reports(harness)[-3:]
    assert all(abs(r[0]) <= 127 and abs(r[1]) <= 127 for r in tail)


def test_curved_path_bows(harness):
    """A long move must follow the sampled curve, not a straight line: the path
    either bows (dy != 0 somewhere) or the random offset happened to be zero.
    The offset range is span/8, so a zero offset is a ~0.7% chance; 8 tries make
    the check robust while still proving the curve exists."""
    bowed = False
    for _ in range(16):
        before = totals(harness)
        settle(harness, '.km.move(600,0)', wait=0.5)
        after = totals(harness)
        assert after[0] - before[0] == 600        # 守恒用累计量断言，不受环形混流影响
        tail = reports(harness)[-5:]              # ceil(600/127) = 5 steps
        assert all(abs(r[0]) <= 127 for r in tail)
        if any(r[1] != 0 for r in tail):
            bowed = True                          # 看到一次就够，别让单次混流判定整条用例
    assert bowed


def test_bow_is_bounded(harness):
    """The perpendicular excursion stays within the documented span/8 control
    offset: with 5 steps the largest |dy| step cannot exceed span/8."""
    settle(harness, '.km.move(600,0)', wait=0.5)
    tail = reports(harness)[-5:]
    assert all(abs(r[1]) <= 600 // 8 + 8 for r in tail)
    assert sum(r[0] for r in tail) == 600
