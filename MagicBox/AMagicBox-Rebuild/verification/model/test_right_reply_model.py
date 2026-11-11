"""Reference model for the right chip's frame_forward replies (mirrors
app_right/main/app_main.c, which mirrors reversed 0x4200F6C4).

Every incoming UART1 frame gets exactly one reply on the same port.  The reply
bytes come from the decompiled helpers, so this model pins them:

  oversized payload            -> 5A <cmd> 01 00 FF     (never dispatched)
  0xA0                          -> 5A A0 01 00 <dir>    dir = *DAT_42000d88 ? 00 : FF
  0xA1 len < 8                  -> 5A A1 01 00 FF
  0xA1 len >= 8                 -> error (URB path not ported)
  0x1A no device                -> 5A 1A 01 00 FF
  0xA3                          -> 5A A3 01 00 00
  0xA4 len >= 0x15 / no device  -> 5A A4 01 00 FF
  0xB1                          -> 5A B1 00 00        (header only)
  anything else                 -> 5A <cmd> 01 00 FF

Run:  python -m pytest verification/model -q
"""

MAGIC = 0x5A
MAX_FIELD = 0x400


def frame(cmd: int, payload: bytes = b"") -> bytes:
    return bytes([MAGIC, cmd]) + len(payload).to_bytes(2, "little") + payload


def forward(cmd: int, payload: bytes, *, ready=0, session=0, ep0_dir=0) -> bytes:
    """Reply frame the right chip sends for one incoming frame."""
    if len(payload) > MAX_FIELD:
        return frame(cmd, b"\xff")

    if cmd == 0xA0:
        return frame(cmd, bytes([0x00 if ep0_dir else 0xFF]))
    if cmd == 0xA1:
        return frame(cmd, b"\xff")
    if cmd == 0x1A:
        return frame(cmd, b"\xff")              # no device attached in this model
    if cmd == 0xA3:
        return frame(cmd, b"\x00")
    if cmd == 0xA4:
        if len(payload) >= 0x15 or not ready or not session:
            return frame(cmd, b"\xff")
        return frame(cmd, b"\xff")              # write path is TODO
    if cmd == 0xB1:
        return frame(cmd, b"")
    return frame(cmd, b"\xff")


def test_total_length_is_field_plus_header():
    for cmd in (0xA0, 0xA1, 0x1A, 0xA3, 0xA4, 0xB1, 0x77):
        reply = forward(cmd, b"\x01")
        assert len(reply) == int.from_bytes(reply[2:4], "little") + 4


def test_error_frame_shape():
    assert forward(0x77, b"") == bytes([0x5A, 0x77, 0x01, 0x00, 0xFF])
    assert forward(0xA1, b"\x00" * 7) == bytes([0x5A, 0xA1, 0x01, 0x00, 0xFF])


def test_ep0_direction_follows_the_host_state():
    assert forward(0xA0, b"", ep0_dir=0) == bytes([0x5A, 0xA0, 0x01, 0x00, 0xFF])
    assert forward(0xA0, b"", ep0_dir=1) == bytes([0x5A, 0xA0, 0x01, 0x00, 0x00])


def test_a3_sets_the_reattach_flag_and_answers_zero():
    assert forward(0xA3, b"\x00") == bytes([0x5A, 0xA3, 0x01, 0x00, 0x00])


def test_b1_is_header_only():
    assert forward(0xB1, b"\x01\x02") == bytes([0x5A, 0xB1, 0x00, 0x00])


def test_snapshot_needs_a_device():
    assert forward(0x1A, b"") == bytes([0x5A, 0x1A, 0x01, 0x00, 0xFF])


def test_config_len_limit_is_0x15():
    assert forward(0xA4, b"\x00" * 0x14) == bytes([0x5A, 0xA4, 0x01, 0x00, 0xFF])
    assert forward(0xA4, b"\x00" * 0x15) == bytes([0x5A, 0xA4, 0x01, 0x00, 0xFF])


def test_oversized_frame_is_answered_without_dispatch():
    big = b"\x00" * (MAX_FIELD + 1)
    assert forward(0xA4, big) == bytes([0x5A, 0xA4, 0x01, 0x00, 0xFF])
    assert forward(0xA3, big) == bytes([0x5A, 0xA3, 0x01, 0x00, 0xFF])
