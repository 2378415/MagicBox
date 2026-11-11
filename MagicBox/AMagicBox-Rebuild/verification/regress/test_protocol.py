"""Protocol regression (T2) - every expectation here comes from a measurement.

Sources:
  old repo `reversed/docs/dynamic_tests.md` (wire measurements: §6 status replies,
  §8 silent(), §10 silent arity, §11 serial)
  old repo `reversed/docs/reconstruction_patterns.md` (handler semantics)
  old repo `官方固件命令协议.md` (table fields, reply framing)

Rule: a case without a measurement behind it does not belong in the exact list;
put it in the tolerant section (only checks framing) and note why.

Run against the original firmware first (golden run), then against the rebuild;
`--run-id` values are recorded in verification/report/.
"""
import pytest

SUFFIX = b'\r\n>>> '


def expect(content):
    return b'km.' + content + SUFFIX


# ---------------------------------------------------------------- exact cases
@pytest.mark.parametrize('sent,content', [
    # cmd_version (0x09)
    ('.km.version()', b'MAKCU'),
    ('.km.version', b'MAKCU'),
    # cmd_move (0x06) - echo, no status byte
    ('.km.move(10,5)', b'move(10,5)'),
    # cmd_catch_set (0x0A) - echo; channel not enabled on a fresh device
    ('.km.catch_ml(1)', b'catch_ml(1)'),
    # cmd_wheel (0x07) answers even with an empty argument
    ('.km.wheel(120)', b'wheel(120)'),
    ('.km.wheel()', b'wheel()'),
    # cmd_buttons (0x0C) - query answers "<name>\n<mode>", default mode 0
    ('.km.buttons()', b'buttons()\n0'),
    # cmd_buttons set form echoes
    ('.km.buttons(1)', b'buttons(1)'),
    ('.km.buttons(0)', b'buttons(0)'),
    # cmd_button_click (0x05) - "<name>\n<flags>", flags 0 on a fresh device
    ('.km.left()', b'left()\n0'),
    ('.km.right()', b'right()\n0'),
    # cmd_silent (0x19) with two arguments does answer
    ('.km.silent(0,0)', b'silent(0,0)'),
    # lock family queries (0x01 / 0x03) on a fresh device: all slots zero
    ('.km.lock_ml()', b'lock_ml()\n0'),
    ('.km.lock_mx()', b'lock_mx()\n0'),
    # cmd_catch_query (0x0B): channel off -> 0
    ('.km.catch_ml()', b'catch_ml()\n0'),
])
def test_exact_replies(device_ready, sent, content):
    assert device_ready.cmd(sent) == expect(content)


@pytest.mark.parametrize('sent', [
    '.km.silent()',        # <2 args: deliberately silent
    '.km.silent(0)',
    '.km.silent(1)',
    '.km.foobar()',        # lookup miss answers nothing
])
def test_no_reply(device_ready, sent):
    assert device_ready.cmd(sent) == b''


def test_serial_query(device_ready):
    """cmd_serial (0x1A) is jump-table only and hand-reconstructed."""
    reply = device_ready.cmd('.km.serial()')
    assert reply.startswith(b'km.')
    assert reply.endswith(SUFFIX)
    body = reply[3:-len(SUFFIX)]
    # measured on the original device: the literal at 0x3C036520 is 0x24 bytes
    # *including* its trailing NUL, and the trailing newline is part of the body
    assert body in (b'Mouse does not have a serial number\n',
                    b'Mouse does not have a serial number\n\x00', b'')
    # a provisioned unit answers "Original Serial : <sn>" / "Spoofed Serial : <sn>"


# ---------------------------------------------------------------- tolerant
@pytest.mark.parametrize('sent', [
    '.km.buttons(2)',      # parameter out of range: reply only, no state change
    '.km.move(1,2,3)',     # 3-arg form: moves with mode = v[2] (>=2), echoes
    '.km.lock_ml(1)',      # set channel flag (writes +0x54), echo only
    '.km.lock_ml(0)',      # clear + catch_set(0) + dirty=0, echo only
    '.km.lock_mx(1)',      # set axis byte (+0x9C), echo only
    '.km.lock_my(0)',      # clear axis byte (+0x9D), echo only
    '.km.left(1)',         # press form (0x04), echo only
])
def test_framing_only(device_ready, sent):
    """Only the framing is pinned; the value depends on state we cannot stage yet."""
    reply = device_ready.cmd(sent)
    if reply:
        assert reply.startswith(b'km.'), reply
        assert reply.endswith(SUFFIX), reply


def test_single_byte_frame_is_dropped(device_ready):
    """A single byte is not a text frame: the dispatcher finds no table entry and
    answers nothing.  (Measured on the original firmware; the rebuild matches.)"""
    assert device_ready.cmd('\x08') == b''
