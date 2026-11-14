"""Descriptor-clone regression (P5 store + runtime descriptor swap).

`mx.cl` / `mx.cl 2` load a canned identity (device descriptor, configuration,
HID report descriptor, strings) and re-enumerate; `mx.cc` drops it again.  The
reply is "<ok>:<vid>:<pid>" so the store contents can be asserted without a USB
analyser.  The host-side enumeration check lives in tools/clone_check.ps1.
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


def test_clone_fixture_a(harness):
    assert body(harness.cmd('mx.cl')) == '1:046d:c077'


def test_clone_fixture_b(harness):
    assert body(harness.cmd('mx.cl 2')) == '1:046d:c52f'


def test_clone_clear(harness):
    assert body(harness.cmd('mx.cc')) == '0'


def test_clone_survives_a_move(harness):
    """A clone must not disturb the report path: move still answers and the
    trace still shows the requested delta."""
    harness.cmd('mx.hk 0')          # keep live 0xA2 traffic out of the trace
    harness.cmd('mx.cl')
    harness.cmd('.km.move(9,7)')
    time.sleep(0.3)
    reply = harness.cmd('mx.rq')
    trace = body(reply)
    assert '090700' in trace
    harness.cmd('mx.hk 1')
    harness.cmd('mx.cc')


def test_fixture_g3m_report_layout(harness):
    """Fixture 4 carries the G3M PRO's real 93-byte report descriptor (7-byte
    reports: 5 buttons + X16 + Y16 + wheel + AC pan).  A button byte injected on
    the wire must be counted, i.e. the report is forwarded verbatim."""
    harness.cmd('mx.hk 1')
    harness.cmd('mx.cl 4')
    time.sleep(0.3)
    dv = body(harness.cmd('mx.dv'))
    assert 'rep93' in dv, dv                       # report descriptor length
    assert '6d0477c0' in dv, dv                    # 046D:C077 identity

    harness.cmd('mx.ss 33')
    time.sleep(0.1)
    before = body(harness.cmd('mx.bw ')).split(',')
    assert harness.cmd('mx.lf a2 02330700 01000000000000').startswith(b'km.')
    time.sleep(0.2)
    after = body(harness.cmd('mx.bw ')).split(',')
    assert int(after[0]) > int(before[0]), (before, after)   # button events rose
    harness.cmd('mx.ss 00')
    harness.cmd('mx.cl 1')


def test_side_button_bits_survive_the_wire(harness):
    """Side buttons mapped to standard mouse buttons (HECATE Connect -> 鼠标4/5)
    ride in byte0 of the 7-byte mouse report as bit3/bit4.  The forwarder must
    pass them through untouched (fixture 4 is verbatim)."""
    harness.cmd('mx.cl 4')
    time.sleep(0.3)
    harness.cmd('mx.hk 1')
    harness.cmd('mx.ss 33')
    time.sleep(0.1)
    before = int(body(harness.cmd('mx.bo ')).split(',')[0], 16)
    for byte0 in ('08', '10'):                    # 键4 / 键5
        harness.cmd('mx.lf a2 02330700 %s000000000000' % byte0)
        time.sleep(0.15)
    after = int(body(harness.cmd('mx.bo ')).split(',')[0], 16)
    harness.cmd('mx.ss 00')
    assert after & 0x08, (hex(before), hex(after))     # button 4 seen
    assert after & 0x10, (hex(before), hex(after))     # button 5 seen
    harness.cmd('mx.cl 1')


@pytest.fixture(autouse=True, scope='module')
def _restore_after_clone_tests(harness):
    """本模块故意把盒子切到出厂夹具；跑完必须换回"克隆真实鼠标"。

    否则按字母序后面的模块（test_hidden_opcodes / test_link_bridge / test_mouse_reports）
    全部在 4 字节报告布局下执行，真实鼠标的 7 字节报告被当 12-bit 解 → 成片失败。
    用 `mx.ac`（立即重克隆，不重启）比 `mx.rs` 可靠得多。
    """
    yield
    try:
        harness.cmd('mx.ac')
        time.sleep(2.0)
        iface = body(harness.cmd('mx.if'))
        if not iface.startswith('2 '):
            harness.cmd('mx.rs')          # 兜底
            time.sleep(8.0)
            iface = body(harness.cmd('mx.if'))
        print(f'\n[clone-descriptors] 收尾恢复: mx.if={iface!r}')
    except Exception as exc:              # noqa: BLE001
        print(f'\n[clone-descriptors] 收尾恢复失败: {exc}')

