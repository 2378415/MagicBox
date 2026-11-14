"""按键 × 二进制 SUMV 并发用例（2026-11-12 新增）。

要求（用户口径）：**按键与 `0x36 SUMV` 二进制指令并发执行，70 次/秒，一次不丢。**

判据（全部硬断言，不用"差不多"）：
  * `0x3E.wire_chg` 增量 == 2 × 点击次数（每点一次 = 按下 + 松开两个边沿）；
  * `0x45.direct_chg + 0x45.queued_chg` == `wire_chg` 增量（每次变化只被引入一次，
    既没被合并，也没多发）；
  * `0x45.btn_cmds` == 2 × 点击次数（注入帧一帧不丢，传输侧自查）；
  * `0x3E.over` == 0（URG 队列零溢出）；
  * 结束时按键处于松开态（不卡键）；
  * SUMV 确实在跑（`mx.rt` 累计位移 != 0）。

时序：单线程粗调度（串口只有一个写者），按键每 `half_us` 交替，SUMV 每 `sumv_period_ms`
发一条、方向交替（避免一直往一个方向撞边界）。
"""
import time

import pytest

HALF_US_70HZ = 7143          # 半周期 7.143 ms => 70 次点击/秒
SUMU_PERIOD_MS = 12          # AIM 并发负载：约 83 条 SUMV/秒


@pytest.fixture
def clicking(device_ready):
    """打开 0xA2 路径 + 固定会话 + 关闭释放守卫 + 按键归零，并等到线上安静。"""
    dev = device_ready
    dev.cmd('mx.hk 1')
    dev.cmd('mx.ss 33')
    dev.cmd('mx.gd 0')
    dev.btn(0x00)
    time.sleep(0.2)
    _wait_wire_quiet(dev)
    yield dev
    try:
        dev.sumv_stop()
        dev.btn(0x00)
        time.sleep(0.2)
        _wait_wire_quiet(dev)
    finally:
        dev.cmd('mx.gd 20')
        dev.cmd('mx.ss 00')


def _wait_wire_quiet(dev, quiet_polls=3, timeout=2.0):
    """等 `0x3E.wire` 连续几次轮询不变（隔离上一条用例的残留边沿）。"""
    last = dev.hid_stat()['wire']
    stable = 0
    deadline = time.time() + timeout
    while time.time() < deadline:
        time.sleep(0.05)
        cur = dev.hid_stat()['wire']
        if cur == last:
            stable += 1
            if stable >= quiet_polls:
                return True
        else:
            stable, last = 0, cur
    return False


def _run(dev, clicks, mode=0):
    """跑一轮并发，返回 (wire_delta, split, cmds, over_delta, 用时秒)。"""
    d0, s0 = dev.btn_diag(), dev.hid_stat()
    assert d0 is not None and s0 is not None, '诊断命令无回包（固件版本不对？）'
    rt0 = dev.rt()

    elapsed = dev.click_with_sumv(clicks, half_us=HALF_US_70HZ,
                                 sumv_period_ms=SUMU_PERIOD_MS,
                                 speed=7000, counts=30, mode=mode)

    dev.sumv_stop()
    dev.sumv_wait_done(timeout=3.0)
    time.sleep(0.3)

    d1, s1 = dev.btn_diag(), dev.hid_stat()
    rt1 = dev.rt()
    wire = (s1['wire'] - s0['wire']) & 0xFFFF
    over = (s1['over'] - s0['over']) & 0xFFFF
    split = (d1['direct_chg'] - d0['direct_chg']) + (d1['queued_chg'] - d0['queued_chg'])
    cmds = d1['btn_cmds'] - d0['btn_cmds']
    moved = abs(rt1[0] - rt0[0]) + abs(rt1[1] - rt0[1])
    return wire, split, cmds, over, elapsed, moved


def test_c1_70hz_clicks_with_binary_sumv(clicking):
    """70 次/秒 × 700 次点击（≈10 s）与 SUMV 并发：1400 个边沿，一个不少。"""
    dev = clicking
    wire, split, cmds, over, elapsed, moved = _run(dev, 700, mode=0)

    assert cmds == 1400, f'0x32 注入帧 {cmds}，期望 1400（传输侧丢帧）'
    assert wire == 1400, f'线上按键边沿 {wire}，期望 1400（丢键或没生效）'
    assert split == wire, f'直发+队列 {split} != 线上边沿 {wire}（合并或多发）'
    assert over == 0, f'URG 队列溢出 {over} 次'
    assert dev.last_hid()['btn'] == 0, '结束时按键未松开（卡键）'
    assert moved != 0, 'SUMV 没有产生位移（并发负载没跑起来）'
    assert 9.0 < elapsed < 12.0, f'实际用时 {elapsed:.2f}s，节拍偏离 70 次/秒'


def test_c2_70hz_short_burst(clicking):
    """同样 70 次/秒，但只跑 150 次点击（≈2.1 s），用于快速回归。"""
    dev = clicking
    wire, split, cmds, over, elapsed, moved = _run(dev, 150, mode=0)

    assert cmds == 300, f'0x32 注入帧 {cmds}，期望 300'
    assert wire == 300, f'线上按键边沿 {wire}，期望 300'
    assert split == wire, f'直发+队列 {split} != 线上边沿 {wire}'
    assert over == 0, f'URG 队列溢出 {over} 次'
    assert dev.last_hid()['btn'] == 0, '结束时按键未松开（卡键）'
    assert moved != 0, 'SUMV 没有产生位移'


def test_c3_70hz_with_queue_mode_sumv(clicking):
    """队列模式（mode=2）的 SUMV 并发：以前这条路径会多出 2 个边沿。"""
    dev = clicking
    wire, split, cmds, over, elapsed, moved = _run(dev, 150, mode=2)

    assert cmds == 300, f'0x32 注入帧 {cmds}，期望 300'
    assert wire == 300, f'线上按键边沿 {wire}，期望 300'
    assert split == wire, f'直发+队列 {split} != 线上边沿 {wire}'
    assert over == 0, f'URG 队列溢出 {over} 次'
    assert dev.last_hid()['btn'] == 0, '结束时按键未松开（卡键）'
