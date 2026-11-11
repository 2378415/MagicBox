"""按键顺序回归：队列里的运动报告不能把按键状态"倒回去"。

背景（2026-11-11 方案 A）：
  按键变化的报告走插队槽先上线，但运动 FIFO 里还压着"按下之前"的报告（byte0=0x00）。
  这些旧报告随后被原样发出 → PC 看到 按下 → 松开 → 按下，一次物理点击变成两次
  （游戏里就是"瞄准开了又取消"、按键抖动）。
  修法：`rep_drain_one()` 出队时把 byte0 的低 5 位改写为"最近一次真正上线"的按键字节。

断言口径（不依赖人手、不依赖线上时序）：
  * `0x42 LAST_HID` 的 `stamped` 字段必须增长 —— 只有"出队时改写了按键字节"才会计数，
    修复前这个值恒为 0；
  * 位移必须守恒（改写只动 byte0，dx/dy/wheel 一个字节都不许变）；
  * `0x3F BTN_AUDIT` 的 `extra` 必须为 0（没有凭空多出来的按键变化）。

注：线上按键序列（`hist`）会被真实鼠标的报告穿插（它一直在发 byte0=0x00），
所以这里不断言 hist 的具体内容，只断言机制与守恒。
"""
import time

import pytest


def _inject(dev, dx=1, btn=0x00, count=1):
    """7 字节 G3M 报告：btn, x_lo, x_hi, y_lo, y_hi, wheel, pan（ep=0x81 / sess=0x33）。"""
    x = dx & 0xFFFF
    payload = bytes([btn & 0xFF, x & 0xFF, (x >> 8) & 0xFF, 0, 0, 0, 0]).hex()
    line = f'mx.lf a2 81330700 {payload}\r'
    for _ in range(count):
        dev.ser.write(line.encode())
    dev.ser.flush()


def _last_hid(dev):
    p = dev.bin_request(0x42, b'', timeout=1.0)
    assert p is not None and len(p) >= 18, '0x42 无回包'
    return {
        'report': bytes(p[2:2 + p[1]]),
        'hist': list(p[10:18]),
        'stamped': int.from_bytes(bytes(p[18:20]), 'little') if len(p) >= 20 else -1,
    }


def _audit(dev):
    p = dev.bin_request(0x3F, b'', timeout=1.0)
    assert p is not None and len(p) >= 12, '0x3F 无回包'
    u = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
    return {'in_chg': u(0), 'out_chg': u(4), 'extra': u(8)}


@pytest.fixture
def wired(device_ready):
    dev = device_ready
    dev.cmd('mx.hk 1')                 # 0xA2 进 HID 路径
    dev.cmd('mx.ss 33')                # 固定会话，注入帧才会被采纳
    _inject(dev, 0, 0x00)              # 先松开
    time.sleep(0.15)
    yield dev
    _inject(dev, 0, 0x00)
    time.sleep(0.1)
    dev.cmd('mx.ss 00')


def test_queued_motion_keeps_latest_button_state(wired):
    """灌满 FIFO 后按下：出队时必须改写按键字节（stamped 增长），且位移守恒。"""
    dev = wired
    a0 = _audit(dev)
    h0 = _last_hid(dev)

    # 1) 150 条"按下前"的报告（端点每 ms 一条 → 必然积压）
    _inject(dev, 1, 0x00, count=150)
    # 2) 按下（走插队槽）
    _inject(dev, 1, 0x01)
    # 3) 按住状态再灌一批
    _inject(dev, 1, 0x01, count=40)
    time.sleep(0.35)

    h1 = _last_hid(dev)
    a1 = _audit(dev)

    assert h1['stamped'] > h0['stamped'], \
        f"出队改写计数没有增长（{h0['stamped']} → {h1['stamped']}），方案 A 没生效"
    assert a1['extra'] == a0['extra'], \
        f"多出按键变化（extra {a0['extra']} → {a1['extra']}），不应凭空产生边沿"

    # 位移侧：verbatim 转发不进 `mx.rt` 的累计（那是 makcu_mouse 层的计数器），
    # 所以这里直接看**最后一条上线报告**的字节：dx 必须还是我们注入的 1，
    # 只有 byte0 的低 5 位允许被改写成当前按键状态。
    rep = h1['report']
    assert len(rep) >= 7, f'上线报告长度异常: {rep.hex()}'
    assert rep[1] == 0x01 and rep[2] == 0x00, \
        f'dx 被改坏了: {rep.hex()}（期望 x_lo=01 x_hi=00）'
    assert (rep[0] & 0x1F) in (0x00, 0x01), f'按键字节出现意外位: {rep[0]:#x}'


def test_single_press_stays_pressed_while_motion_queues(wired):
    """只按一次、之后全是运动报告：线上按键字节不应回到 0x00（真实鼠标那 0x00 除外）。

    这里用"出队改写的次数"做判据：只要队列里存在按下前的旧报告，
    修复后它们会被改成 0x01 再发，所以 stamped 会持续增长；
    修复前 stamped 恒为 0（该字段根本不存在），会在上面的用例里已经失败。
    """
    dev = wired
    h0 = _last_hid(dev)
    _inject(dev, 1, 0x00, count=80)    # 旧状态积压
    _inject(dev, 1, 0x01)              # 按下
    _inject(dev, 1, 0x01, count=20)    # 保持
    time.sleep(0.25)
    h1 = _last_hid(dev)
    assert h1['stamped'] > h0['stamped'], '按下瞬间没有发生"出队改写"'
    # 线上最近几条按键字节里，我们注入的 0x01 必须出现过
    assert 0x01 in h1['hist'], f"线上按键历史里没有出现 0x01: {[hex(b) for b in h1['hist']]}"
