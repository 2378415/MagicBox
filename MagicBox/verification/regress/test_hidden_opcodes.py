"""Hidden-opcode regression (T2 for the opcodes that have no text command).

0x0D..0x18 are only reachable through the opcode jump table, so the text protocol
cannot exercise them.  Bench builds compiled with -DMB_DEBUG_OPCODE=1 accept

    mx.<hex opcode> <args>

and call the handler directly with the arguments as its line, which is enough to
pin the reply half of each handler.

The suite skips itself when the firmware was built without the harness.
"""
import pytest

SUFFIX = b'\r\n>>> '


def expect(content):
    return b'km.' + content + SUFFIX


@pytest.fixture(scope='session')
def harness(device_ready):
    """Skip unless the firmware exposes the mx.<op> harness."""
    reply = device_ready.cmd('mx.09')                 # cmd_version through the table
    if reply != expect(b'MAKCU'):
        pytest.skip('firmware built without MB_DEBUG_OPCODE')
    return device_ready


@pytest.mark.parametrize('sent,content', [
    # 0x0D / 0x0E: single key down / up, 'c' form and decimal form
    ("mx.0d 'a'", b"'a'"),
    ('mx.0d 4', b'4'),
    ("mx.0e 'a'", b"'a'"),
    # 0x0F: tap with a delay window.  The usage parser only accepts the 'c' form
    # when the *whole* argument ends with a quote, so the delay form has to use
    # the decimal usage id (that is what the original accepts as well).
    ('mx.0f 4,1,5', b'4,1,5'),
    # 0x10: quoted string typing
    ("mx.10 'hi'", b"'hi'"),
    # 0x12 / 0x13: batch down / up
    ("mx.12 'a','b'", b"'a','b'"),
    ("mx.13 'a','b'", b"'a','b'"),
    # 0x14: combo with delays
    ("mx.14 'a',1,2", b"'a',1,2"),
    # 0x15 / 0x16: mapping-table writes (both echo when the parse succeeds)
    ('mx.15 3,1', b'3,1'),
    ('mx.16 3,1', b'3,1'),
    # 0x18: channel toggle - idx 0 is not "present" on a fresh device -> echo
    ('mx.18 0,1', b'0,1'),
])
def test_hidden_echo_handlers(harness, sent, content):
    assert harness.cmd(sent) == expect(content)


def test_hidden_dump_channels(harness):
    """0x17 on a fresh device: no entry has all three flags -> literal "0"."""
    assert harness.cmd('mx.17') == expect(b'0')


def test_hidden_key_state(harness):
    """0x11 replies '<name>\\n<state>'; the harness passes the name "mx"."""
    assert harness.cmd("mx.11 'a'") == expect(b'mx\n0')


@pytest.mark.parametrize('sent', [
    'mx.0d',        # empty argument -> silent
    'mx.10',        # set_string needs quotes -> silent
    'mx.16 0,1',    # map_entry: first value 0 -> silent (0x4200E65A)
    'mx.1a',        # serial without arguments still answers the failure text
])
def test_hidden_silent_cases(harness, sent):
    reply = harness.cmd(sent)
    if sent == 'mx.1a':
        assert reply.endswith(SUFFIX) and b'serial number' in reply
    else:
        assert reply == b''


# ---------------------------------------------------------------- side effects
# The mapping handlers and cmd_channel_toggle are *write-only on the wire*: their
# replies are just the echoed line, so the text protocol cannot show what they
# stored.  `mx.dd` dumps the four tables (map_write desc[+0x63], map_write16
# desc[+0x163], channel enable desc[+0x269], "present" desc[+0x369], third flag
# desc[+0x636]) plus the resend flag; `mx.dp <idx>` sets the present bit so the
# gated 0x18 write path can be exercised on a device that never saw a real
# channel table.  Bench build only (MB_DEBUG_OPCODE), like every other mx.*.

def dd(dev):
    reply = dev.cmd('mx.dd')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    body = reply[3:-len(SUFFIX)].decode()
    fields = {}
    for part in body.split():
        key, _, value = part.partition('=')
        fields[key] = value
    return fields


def byte_of(fields, key, idx):
    return fields[key][idx * 2:idx * 2 + 2]


def test_nop_echoes_its_line(harness):
    """0x08 is not a stub: it answers with the line it was handed.  The harness
    passes the *argument* as the line, hence `mx.08 hello` -> `km.hello`."""
    assert harness.cmd('mx.08 hello') == expect(b'hello')


def test_map_handlers_write_their_own_table(harness):
    """0x15 -> desc[+0x163+idx], 0x16 -> desc[+0x63+idx].  Different tables: a
    mixed-up offset would show up as the wrong field changing."""
    harness.cmd('mx.15 5,1')
    harness.cmd('mx.16 5,1')
    fields = dd(harness)
    assert byte_of(fields, 'w16', 5) == '01', fields
    assert byte_of(fields, 'w', 5) == '01', fields


def test_channel_toggle_is_gated_on_present(harness):
    """idx 6 is never marked present here: 0x18 echoes but must not write the
    enable bit and must not touch the resend flag (0x4200E5AA gate)."""
    before = dd(harness)
    assert harness.cmd('mx.18 6,1') == expect(b'6,1')
    after = dd(harness)
    assert byte_of(after, 'en', 6) == byte_of(before, 'en', 6), (before, after)
    assert after['rs'] == before['rs'], (before, after)


def test_channel_toggle_writes_enable_and_resend(harness):
    """With the present bit set, 0x18 writes desc[+0x269+idx] and drives the
    resend flag inverted: on -> 0, off -> 1."""
    harness.cmd('mx.dp 7')
    harness.cmd('mx.18 7,1')
    fields = dd(harness)
    assert byte_of(fields, 'en', 7) == '01', fields
    assert fields['rs'] == '0', fields

    harness.cmd('mx.18 7,0')
    fields = dd(harness)
    assert byte_of(fields, 'en', 7) == '00', fields
    assert fields['rs'] == '1', fields
