"""Right-chip reply frames, verified on the left board through `mx.rf`.

app_right cannot be flashed here (there is no second chip on this bench), so the
reply builder lives in a portable component (`components/makcu_right`) that both
apps link.  `mx.rf <cmd> [payload hex]` runs exactly that function on the left
chip and prints the bytes the right chip would answer with.

Expectations come from reversed 0x4200F6C4 + its helpers (see
components/makcu_right/include/makcu_right_frames.h for the address map).
"""
import pytest

SUFFIX = b'\r\n>>> '


@pytest.fixture(scope='session')
def harness(device_ready):
    if device_ready.cmd('mx.09') != b'km.MAKCU' + SUFFIX:
        pytest.skip('firmware built without MB_DEBUG_OPCODE')
    return device_ready


def reply(dev, sent):
    out = dev.cmd(sent)
    assert out.startswith(b'km.') and out.endswith(SUFFIX), out
    return out[3:-len(SUFFIX)].decode()


@pytest.mark.parametrize('sent,hex_reply', [
    ('mx.rf a0',            '5aa00100ff'),   # 0x4200FAC0: no device yet -> dir 0xFF
    ('mx.rf a3 00',         '5aa3010000'),   # 0x4200FAE0: re-attach flag, zeros
    ('mx.rf 1a',            '5a1a0100ff'),   # 0x4200F854: nothing attached
    ('mx.rf a4 00',         '5aa40100ff'),   # 0x4200FE44: config needs a device
    ('mx.rf b1 0102',       '5ab10000'),     # header-only reply
    ('mx.rf 77',            '5a770100ff'),   # 0x420248E4: default error
    ('mx.rf a1 00000000000000', '5aa10100ff'),   # 0xA1 with 7 bytes -> error
])
def test_right_reply_frames(harness, sent, hex_reply):
    assert reply(harness, sent) == hex_reply


def test_total_length_matches_the_field(harness):
    for sent in ('mx.rf a3 00', 'mx.rf b1', 'mx.rf 42'):
        blob = bytes.fromhex(reply(harness, sent))
        assert len(blob) == int.from_bytes(blob[2:4], 'little') + 4, (sent, blob)


def test_config_payload_limit_is_0x15(harness):
    """0x14 bytes is below the limit but still fails without a device; 0x15 is
    rejected by the length check - both answer the error byte."""
    assert reply(harness, 'mx.rf a4 ' + '00' * 0x14) == '5aa40100ff'
    assert reply(harness, 'mx.rf a4 ' + '00' * 0x15) == '5aa40100ff'
