"""Keyboard output regression: the 8-byte boot-keyboard report.

The report layout is (modifiers, reserved, usage0..usage5).  Reports are read
back through the bench command `mx.rk`, which dumps the component's ring as
hex, so the checks work on a console build as well as on a HID build.

State is cleared first: a test that left a key down would leak into the next.
"""
import pytest

SUFFIX = b'\r\n>>> '
REPORT_LEN = 8


@pytest.fixture(scope='session')
def harness(device_ready):
    if device_ready.cmd('mx.09') != b'km.MAKCU' + SUFFIX:
        pytest.skip('firmware built without MB_DEBUG_OPCODE')
    for usage in ('04', '05', '0b', '0c'):
        device_ready.cmd(f'mx.0e {int(usage, 16)}')      # release leftovers
    return device_ready


def reports(dev):
    reply = dev.cmd('mx.rk')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    body = reply[3:-len(SUFFIX)].decode()
    return [body[i:i + REPORT_LEN * 2] for i in range(0, len(body), REPORT_LEN * 2)]


def last(dev):
    return reports(dev)[-1]


def test_key_down_sets_usage(harness):
    harness.cmd("mx.0d 'a'")                     # usage 0x04
    assert last(harness) == '0000040000000000'
    harness.cmd("mx.0e 'a'")
    assert last(harness) == '0000000000000000'


def test_key_up_clears_usage(harness):
    harness.cmd("mx.0d 'b'")                     # usage 0x05
    assert last(harness)[4:6] == '05'
    harness.cmd("mx.0e 'b'")
    assert last(harness) == '0000000000000000'


def test_tap_emits_down_then_up(harness):
    harness.cmd('mx.0f 4,1,5')
    tail = reports(harness)[-2:]
    assert tail[0][4:6] == '04'
    assert tail[1] == '0000000000000000'


def test_batch_down_lists_both(harness):
    harness.cmd("mx.12 'a','b'")                 # 0x04 and 0x05
    report = last(harness)
    assert report[4:6] == '04' and report[6:8] == '05' or \
           report[6:8] == '04' and report[4:6] == '05'
    harness.cmd('mx.13 4,5')
    assert last(harness) == '0000000000000000'


def test_type_string_types_each_char(harness):
    harness.cmd("mx.10 'hi'")                    # h = 0x0b, i = 0x0c
    tail = reports(harness)[-4:]
    seen = {r[4:6] for r in tail}
    assert '0b' in seen and '0c' in seen
    assert tail[-1] == '0000000000000000'        # nothing left held


def test_combo_presses_all_then_releases(harness):
    harness.cmd("mx.14 4,5,1,2")
    tail = reports(harness)[-2:]
    pressed = tail[0]
    assert pressed[4:6] and pressed[6:8]        # at least two usages held
    assert tail[1] == '0000000000000000'


def test_key_state_reports_held(harness):
    harness.cmd("mx.0d 'a'")
    assert harness.cmd("mx.11 'a'") == b'km.mx\n1' + SUFFIX
    harness.cmd("mx.0e 'a'")
    assert harness.cmd("mx.11 'a'") == b'km.mx\n0' + SUFFIX
