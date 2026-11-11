"""Inter-chip link (UART1) regression, verified with a hardware loopback.

There is only one board on the bench, so the two-chip path cannot be exercised
end to end.  Instead the firmware can route UART1 TX back into its own RX
(uart_set_loop_back) and send a synthetic 0xA2 frame:

    mx.lb          -> send one 0xA2 frame with payload 01 22 05 00 DE AD BE EF 11
    mx.ls          -> frame counters (frames, ep0, ep0_in, ep0_out, hid, a3, unknown)
    mx.dc <ep>     -> hex of what the bridge reassembled for that endpoint

That covers the whole chain: build -> UART wire -> parser -> dispatch -> chunk
reassembly.  What it cannot cover is the EP0 tunnel, which needs a real second
chip (and a device-stack hook that is still P5 work).
"""
import time

import pytest

SUFFIX = b'\r\n>>> '


@pytest.fixture(scope='session')
def harness(device_ready):
    if device_ready.cmd('mx.09') != b'km.MAKCU' + SUFFIX:
        pytest.skip('firmware built without MB_DEBUG_OPCODE')
    return device_ready


def body(reply):
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    return reply[3:-len(SUFFIX)].decode()


def counters(dev):
    return [int(v) for v in body(dev.cmd('mx.ls')).split(',')]


def frame(tag):
    return b'km.' + tag.encode() + SUFFIX


def test_frame_is_built_and_written(harness):
    """9 payload bytes + 4 header bytes must reach the UART."""
    assert harness.cmd('mx.lb') == frame('13')


def test_loopback_frame_is_parsed(harness):
    before = counters(harness)
    harness.cmd('mx.lb')
    time.sleep(0.3)
    after = counters(harness)
    assert after[0] > before[0], 'no frame reached the parser'
    assert after[4] > before[4], 'not dispatched as a HID chunk'


def test_chunk_is_reassembled(harness):
    """payload[0]=ep 1, payload[1]=session 0x22, payload[2]=len 5, then DE AD BE EF 11."""
    harness.cmd('mx.lz')                  # the buffers accumulate across sends
    harness.cmd('mx.lb')
    time.sleep(0.3)
    assert body(harness.cmd('mx.dc 1')).endswith('deadbeef11')


def test_other_endpoint_stays_untouched(harness):
    """The chunk went to endpoint 1, so endpoint 0 must not have received it."""
    harness.cmd('mx.lz')
    harness.cmd('mx.lb')
    time.sleep(0.3)
    assert not body(harness.cmd('mx.dc 0')).endswith('deadbeef11')


# ---------------------------------------------------------------- 0xA0 tunnel
# The original (reversed 0x42013734) treats 0xA0 as a two-way handshake around a
# single "pending" flag: len==1 && payload[0]==0x00 opens a session, 0xFF (or an
# empty payload) closes it if one is open.  `mx.lf` pushes a real frame through
# the internal loopback so the parser and the state machine both run.

def counters11(dev):
    # frames, ep0_requests, ep0_in, ep0_out, hid_chunks, a3, unknown,
    # ep0_starts, ep0_ends, injected, dropped, rx_bytes
    return [int(v) for v in body(dev.cmd('mx.ls')).split(',')]


def test_raw_rx_counter_tracks_bytes(harness):
    """rx_bytes counts every byte UART1 delivered, valid frame or not - it is the
    only way to tell "nothing on the wire" from "garbage at the wrong baud"."""
    before = counters11(harness)[11]
    assert harness.cmd('mx.lb').startswith(b'km.')
    time.sleep(0.2)
    after = counters11(harness)[11]
    assert after >= before + 13, (before, after)      # 9-byte payload + 4-byte header


def test_ep0_session_opens_and_closes(harness):
    # The 2 s 0xA3 heartbeat can answer between our probe and the mx.lr read.
    harness.cmd('mx.hb 0')
    harness.cmd('mx.lf a0 ff')                        # normalise: close any session
    time.sleep(0.1)
    assert body(harness.cmd('mx.ef')) == '0'          # nothing open at rest
    before = counters11(harness)
    assert harness.cmd('mx.lf a0 00').startswith(b'km.')     # 1 payload byte + 4 header
    harness.cmd('mx.lf a0 00')
    time.sleep(0.2)
    assert body(harness.cmd('mx.ef')) == '1'
    mid = counters11(harness)
    assert mid[7] >= before[7] + 2                    # ep0_starts
    harness.cmd('mx.lf a0 ff')
    time.sleep(0.2)
    after = counters11(harness)
    assert body(harness.cmd('mx.ef')) == '0'
    assert after[8] == mid[8] + 1                     # ep0_ends


def test_ep0_close_without_session_is_ignored(harness):
    assert harness.cmd('mx.lf a0 ff').startswith(b'km.')
    time.sleep(0.2)
    before = counters11(harness)
    harness.cmd('mx.lf a0 ff')
    time.sleep(0.2)
    after = counters11(harness)
    assert after[8] == before[8]                      # no pending session -> no end
    assert body(harness.cmd('mx.ef')) == '0'


def test_ep0_other_direction_is_ignored(harness):
    before = counters11(harness)
    harness.cmd('mx.lf a0 7f')
    time.sleep(0.2)
    after = counters11(harness)
    assert after[7] == before[7]                      # not a start
    assert after[8] == before[8]                      # not an end


# --------------------------------------------------------------- 0xA2 inject
# payload = [ep, session, len, 0, data...]; the first frame adopts its session id
# and every later one has to match, otherwise it is counted as dropped.
# The cases below pin session 0x33 (mx.ss) since the live mouse uses its own id,
# and use a different one (0x5A) only for the mismatch case - that keeps them independent
# of the order the suite happens to run in.

def ensure_real_clone(dev, tag=''):
    """用例自带前置：保证盒子跑的是"克隆真实鼠标"。

    为什么需要：`test_clone_descriptors.py` 会把盒子切到 4 字节出厂夹具；
    如果它没收尾干净（或中途重启），本模块的 0xA2 注入用例会在错误的报告布局下执行，
    表现为"计数不涨 / 注入没落地"的随机失败。这里就地 `mx.ac`（立即重克隆，不重启），
    最多 3 轮，成本几乎为零——健康时一次 `mx.if` 就返回。
    """
    for _ in range(3):
        iface = body(dev.cmd('mx.if'))
        if iface.startswith('2 '):
            return True
        dev.cmd('mx.ac')
        time.sleep(1.5)
    iface = body(dev.cmd('mx.if'))
    print(f'\n[link_bridge{(":" + tag) if tag else ""}] mx.ac 后仍不健康: mx.if={iface!r}')
    return False


def adopt_session(dev):
    # Pin the session instead of relying on first-frame adoption: with a real
    # mouse on the right chip, live 0xA2 traffic would adopt its own id first.
    dev.cmd('mx.ss 33')
    time.sleep(0.1)


def test_hid_frame_injects_a_report(harness):
    assert ensure_real_clone(harness, 'inject'), '克隆不健康，先修盒子'
    adopt_session(harness)
    before = counters11(harness)
    # ep 2, session 0x22, len 4, pad 0, data 01 02 ff 00
    assert harness.cmd('mx.lf a2 02330400 0102ff00').startswith(b'km.')
    time.sleep(0.25)
    after = counters11(harness)
    # 真实鼠标流也会让 injected 涨，所以用 >=；载荷本身由下面的 mx.ei 精确核对
    assert after[9] >= before[9] + 1, (before, after)      # reports_injected
    assert body(harness.cmd('mx.ei')) == '0102ff00'


def test_hid_frame_session_mismatch_is_dropped(harness):
    assert ensure_real_clone(harness, 'session_mismatch'), '克隆不健康，先修盒子'
    adopt_session(harness)
    # 真实鼠标的 0xA2 流每秒几百帧，会同时抬高 injected/dropped 计数，
    # 严格等式会随机失败。台架隔离（mx.hk 1）把 0xA2 挡在 HID 路径外，计数才干净。
    harness.cmd('mx.hk 0')            # 0 = 隔离（0xA2 不进 HID 路径）
    try:
        before = counters11(harness)
        harness.cmd('mx.lf a2 025a0400 0a0b0c0d')          # session 0x5A
        time.sleep(0.25)
        after = counters11(harness)
        # 真实鼠标的 0xA2 在 mx.hk 0 下同样会被计成 dropped，
        # 所以只能要求"至少 +1"（我们这一帧必在其中）
        assert after[10] >= before[10] + 1, (before, after)   # reports_dropped
        assert after[9] == before[9]                          # nothing injected
        assert body(harness.cmd('mx.ei')) != '0a0b0c0d'
    finally:
        harness.cmd('mx.hk 1')        # 1 = 恢复（sink 重新启用，后续用例要用）


def test_hid_frame_zero_length_is_dropped(harness):
    assert ensure_real_clone(harness, 'zero_length'), '克隆不健康，先修盒子'
    adopt_session(harness)
    harness.cmd('mx.hk 0')          # 同上：隔离真实鼠标流，计数才可做严格断言
    try:
        before = counters11(harness)
        harness.cmd('mx.lf a2 02330000')
        time.sleep(0.25)
        after = counters11(harness)
        # 同上：live 鼠标流也会累加 dropped，用 >= 才不会随机失败
        assert after[10] >= before[10] + 1, (before, after)
        assert after[9] == before[9]
    finally:
        harness.cmd('mx.hk 1')


def test_report_is_unpacked_from_12bit(harness):
    """The real mouse sends 12-bit packed X/Y: byte2 = x[11:8] | (y[3:0] << 4).

    Reading byte2 as an 8-bit Y axis made Y run 16x too fast (its low four bits
    sit in the high nibble of that byte) while X felt slow.  The vectors below
    come from a live 100 s capture (report run-21/22); mx.du decodes them with
    the very function the injection path uses.
    """
    cases = [
        ('0001100000', '1,1,0'),
        ('0000f0ff00', '0,-1,0'),
        ('00ff0f0000', '-1,0,0'),
        ('0000300000', '0,3,0'),
        ('0000c0ff00', '0,-4,0'),
    ]
    for data, expect in cases:
        assert body(harness.cmd('mx.du ' + data)) == expect, (data, expect)


def test_buttons_and_wheel_are_forwarded(harness):
    """Button byte 0 and wheel byte 4 must reach the mouse layer.

    mx.bw counts them on the device, so the assertion does not depend on what is
    on screen or on when the test happens to poll.
    """
    harness.cmd('mx.fs 1')
    adopt_session(harness)          # pin 0x33; live mouse traffic uses another id
    time.sleep(0.15)
    bw = body(harness.cmd('mx.bw')).split(',')
    btn0, wheel0, sum0 = int(bw[0]), int(bw[1]), int(bw[2])

    assert harness.cmd('mx.lf a2 02330500 0100000000').startswith(b'km.')
    time.sleep(0.15)
    bw = body(harness.cmd('mx.bw')).split(',')
    assert int(bw[0]) == btn0 + 1, bw            # btn_events
    assert int(bw[3]) == 1, bw                   # last_buttons

    assert harness.cmd('mx.lf a2 02330500 0000000002').startswith(b'km.')
    time.sleep(0.15)
    bw = body(harness.cmd('mx.bw')).split(',')
    assert int(bw[1]) == wheel0 + 1, bw          # wheel_events
    assert int(bw[2]) == sum0 + 2, bw            # wheel_sum
    harness.cmd('mx.ss 00')
