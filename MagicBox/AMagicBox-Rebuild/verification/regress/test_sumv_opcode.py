"""0x36 SUMV / 0x37 SUMV_STOP / 0x38 SUMV_STATE 的硬件在环回归。

为什么单开一个文件：`mx.*` 是台架文本旁路，sumv 的**真实接口是二进制帧**，所以这些
用例自己组帧（conftest 的 `bin_send / bin_request / sumv / rt` 辅助），断言全走
"累积位移守恒"这条口径 —— 不依赖光标在屏幕的绝对位置，也不受 Windows 指针加速影响。

口径：
  * `mx.rt` 的累计 dx/dy 是**固件侧真正发出去的 counts**，sumv 走完一条 D 的轨迹后
    它必须增加 D（±2，留给队列收尾）；
  * `0x38` 的 `rounds` 每条轨迹 +1，`aborted` 只在被 REPLACE / stop 打断时 +1；
  * 全程 `active` 必须能观测到 1（否则说明第一条就失败，后面的断言没意义）。
"""
import time

import pytest


@pytest.fixture
def sumv(device_ready):
    """每条用例前后都确保没有残留轨迹在跑。"""
    dev = device_ready
    dev.sumv_stop()
    time.sleep(0.05)
    st0 = dev.sumv_state()
    assert st0 is not None and st0['raw_len'] == 29, f'SUMV_STATE 不可用: {st0}'
    yield dev, st0
    dev.sumv_stop()
    time.sleep(0.05)


def test_sumv_state_is_29_bytes(sumv):
    """0x38 必须回 29 字节，且字段自洽（这是所有断言的基准）。"""
    dev, st = sumv
    assert st['raw_len'] == 29
    assert st['active'] == 0
    for key in ('samples', 'aborted', 'rounds', 'muted', 'fwd', 'speed_eff', 'remain'):
        assert isinstance(st[key], int)


def test_sumv_moves_exactly_the_requested_counts(sumv):
    """一条 D=600 的轨迹：累计 dx 必须正好 +600，rounds +1。"""
    dev, st0 = sumv
    rt0 = dev.rt()
    dev.sumv(600, 0, speed=12000)
    st1 = dev.sumv_wait_done(timeout=3.0)
    assert st1 is not None and st1['active'] == 0, f'轨迹没有结束: {st1}'
    dx = dev.rt()[0] - rt0[0]
    assert abs(dx - 600) <= 2, f'累计位移 {dx}，期望 600（±2）'
    assert st1['rounds'] == st0['rounds'] + 1
    assert st1['aborted'] == st0['aborted']
    assert st1['samples'] > st0['samples']


def test_sumv_reports_active_while_running(sumv):
    """长一点的轨迹（6000）在跑的瞬间必须能看到 active==1。"""
    dev, _ = sumv
    dev.sumv(6000, 0, speed=12000)
    seen_active = False
    seen_remain = 0
    deadline = time.time() + 1.0
    while time.time() < deadline:
        st = dev.sumv_state()
        if st is None:
            break
        if st['active']:
            seen_active = True
            seen_remain = max(seen_remain, st['remain'])
            break
        time.sleep(0.005)
    dev.sumv_stop()
    assert seen_active, '整条轨迹期间都没看到 active==1'
    assert seen_remain > 0, f'active 时 remain 应大于 0，实际 {seen_remain}'


def test_sumv_stop_aborts_and_leaves_partial_movement(sumv):
    """跑一半 stop：aborted +1，位移停在 0..D 之间（不能走完，也不能一步没走）。"""
    dev, st0 = sumv
    rt0 = dev.rt()
    dev.sumv(6000, 0, speed=12000)
    time.sleep(0.04)                      # 40 ms ≈ 走掉 1/5 左右
    dev.sumv_stop()
    time.sleep(0.05)
    st1 = dev.sumv_state()
    dx = dev.rt()[0] - rt0[0]
    assert st1['active'] == 0, f'stop 之后还在跑: {st1}'
    assert st1['aborted'] == st0['aborted'] + 1, f'aborted 没 +1: {st0} → {st1}'
    assert 0 < dx < 6000, f'部分位移应在 0..6000 之间，实际 {dx}'


def test_sumv_replace_counts_as_abort_and_keeps_new_target(sumv):
    """跑起来之后再下一条：旧轨迹算 aborted，最终位移由新轨迹决定。"""
    dev, st0 = sumv
    rt0 = dev.rt()
    dev.sumv(6000, 0, speed=12000)
    time.sleep(0.03)
    dev.sumv(100, 0, speed=12000)         # REPLACE
    st1 = dev.sumv_wait_done(timeout=3.0)
    dx = dev.rt()[0] - rt0[0]
    assert st1['active'] == 0
    assert st1['aborted'] >= st0['aborted'] + 1, f'REPLACE 没有计 aborted: {st0} → {st1}'
    assert st1['rounds'] >= st0['rounds'] + 1
    # 被替换掉的那条只走了 30 ms（远小于 6000），最终位移必须远小于 6000
    assert dx < 2000, f'REPLACE 后位移 {dx}，旧轨迹没被截断'


def test_sumv_zero_distance_is_rejected(sumv):
    """D=0 被**拒绝**（`makcu_sumv_start()` 里 `cheb == 0 → return false`）。

    实测语义：不产生位移、不启动任务，`rounds` 和 `aborted` 都**不变**
    —— 它不是"跑完一条 0 距离的轨迹"，也不是"被打断"。
    """
    dev, st0 = sumv
    rt0 = dev.rt()
    dev.sumv(0, 0, speed=12000)
    time.sleep(0.15)
    st1 = dev.sumv_state()
    dx = dev.rt()[0] - rt0[0]
    assert st1['active'] == 0
    assert abs(dx) <= 1, f'D=0 却有位移 {dx}'
    assert st1['rounds'] == st0['rounds'], f'D=0 不该计 rounds: {st0} → {st1}'
    assert st1['aborted'] == st0['aborted'], f'D=0 不该计 aborted: {st0} → {st1}'
    assert st1['samples'] == st0['samples'], f'D=0 不该产生采样: {st0} → {st1}'


def test_sumv_diagonal_keeps_both_axes(sumv):
    """斜向 (300,-200)：两轴累计都要对得上（防止只走一轴的老 bug）。"""
    dev, _ = sumv
    rt0 = dev.rt()
    dev.sumv(300, -200, speed=12000)
    st1 = dev.sumv_wait_done(timeout=3.0)
    dx = dev.rt()[0] - rt0[0]
    dy = dev.rt()[1] - rt0[1]
    assert st1['active'] == 0
    assert abs(dx - 300) <= 2 and abs(dy + 200) <= 2, f'斜向位移 ({dx}, {dy})，期望 (300, -200)'


def test_sumv_speed_affects_duration(sumv):
    """同样的 D，speed 越大用时越短（验证 speed → mr → 时长这条链路）。"""
    dev, _ = sumv

    def timed(dx, speed):
        t0 = time.time()
        dev.sumv(dx, 0, speed=speed)
        dev.sumv_wait_done(timeout=6.0)
        return time.time() - t0

    slow = timed(2000, 12000)             # mr≈13 → 约 150 ms
    fast = timed(2000, 40000)             # mr≈41 → 约 50 ms
    assert fast < slow * 0.75, f'高速档没有更快：slow={slow*1000:.0f}ms fast={fast*1000:.0f}ms'


def test_sumv_mode_constant_velocity_runs(sumv):
    """mode bit3（恒速档，AIM 用的就是它）也必须能正常走完并守恒。"""
    dev, st0 = sumv
    rt0 = dev.rt()
    dev.sumv(400, 0, speed=12000, mode=0x08)
    st1 = dev.sumv_wait_done(timeout=3.0)
    dx = dev.rt()[0] - rt0[0]
    assert st1['active'] == 0
    assert abs(dx - 400) <= 2, f'恒速档位移 {dx}，期望 400（±2）'
    assert st1['rounds'] == st0['rounds'] + 1
