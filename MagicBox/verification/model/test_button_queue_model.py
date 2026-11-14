"""按键队列 / 释放守卫的离线模型（无需硬件，CI 可直接跑）。

目的：把 `makcu_hiddev.c` 里"按键 → URG 队列 → 上线"和 `app_main.c` 里
"短按抗抖（释放守卫）"的语义各写一份 40 行的等价模型，然后用属性测试
盯住三条不变量：

  I1 每条进队的按键报告最终都会上线（0 丢弃），顺序不变；
  I2 上线序列里**没有多余边沿**（相邻同值不算边沿，0 双发）；
  I3 只有"队列满且等不到空位"时才允许 overflow（R3 的边界）。

守卫模型另外锁住"窗口边界"的语义：`now - release < window` 才吞。

这些用例与真机用例（`verification/regress/test_button_integrity.py`）用同一组
时间参数，先在模型里证明逻辑正确，再去台架上复核。
"""
from collections import deque

import pytest

DOWN, UP = 0x01, 0x00


# --------------------------------------------------------------------------- #
# 模型：按键专用队列（对应 makcu_hiddev.c 的 urg_push / rep_drain_one）
# --------------------------------------------------------------------------- #

class UrgQueue:
    """按键队列：逐条入队、逐条出队，不合并；满时先等空位，等不到才记账。"""

    def __init__(self, depth=64, wait_slots=10):
        self.depth = depth
        self.wait_slots = wait_slots     # 每次 push 最多能等几个"帧"
        self.q = deque()
        self.wire = []                   # 真正上线过的 (btn) 序列
        self.dropped = 0
        self.pushes = 0

    def push(self, btn):
        self.pushes += 1
        waited = 0
        while len(self.q) >= self.depth and waited < self.wait_slots:
            self.drain_one()             # 模拟完成回调腾出空位
            waited += 1
        if len(self.q) >= self.depth:
            self.dropped += 1
            return False
        self.q.append(btn)
        return True

    def drain_one(self):
        if not self.q:
            return None
        b = self.q.popleft()
        self.wire.append(b)
        return b

    def drain_all(self):
        while self.q:
            self.drain_one()


def edges(seq):
    """把上线序列压成边沿序列（相邻同值合并）。"""
    out = []
    for b in seq:
        if not out or out[-1] != b:
            out.append(b)
    return out


# --------------------------------------------------------------------------- #
# 模型：释放守卫（对应 app_main.c 的 s_release_guard_ms 判定）
# --------------------------------------------------------------------------- #

class ReleaseGuard:
    def __init__(self, window_ms=20):
        self.window_us = window_ms * 1000
        self.last = UP
        self.release_us = None          # None = 还没发生过松开（第一次按下永远放行）

    def classify(self, btn, now_us):
        """返回 (是否吞掉, 实际转发值)。"""
        pressed = btn & ~self.last
        swallow = (pressed != 0 and self.window_us != 0 and self.release_us is not None
                   and (now_us - self.release_us) < self.window_us)
        fwd = self.last if swallow else btn
        if self.last & ~fwd:
            self.release_us = now_us
        self.last = fwd
        return swallow, fwd


# --------------------------------------------------------------------------- #
# I1 / I2：不丢、不乱序、不多发
# --------------------------------------------------------------------------- #

@pytest.mark.parametrize('depth', [1, 2, 8, 64])
def test_no_loss_and_order_under_backpressure(depth):
    q = UrgQueue(depth=depth, wait_slots=10_000)     # 允许一直等 → 一条都不该丢
    seq = [DOWN, UP, DOWN, UP, 0x02, UP, 0x01, 0x01, UP]
    for b in seq:
        assert q.push(b)
        if len(q.q) >= depth:                        # 模拟端点忙时慢速排空
            q.drain_one()
    q.drain_all()

    assert q.dropped == 0, f'depth={depth} 时丢了 {q.dropped} 条'
    assert q.wire == seq, f'顺序被改：{q.wire} != {seq}'
    # 相邻同值不算边沿：上线边沿数 == 输入边沿数
    assert len(edges(q.wire)) == len(edges(seq))


def test_random_stream_has_no_duplicate_edges():
    import random
    rnd = random.Random(20261112)
    q = UrgQueue(depth=64, wait_slots=10_000)
    seq = [rnd.choice([DOWN, UP, 0x02, 0x04]) for _ in range(2000)]
    for i, b in enumerate(seq):
        q.push(b)
        if i % 3 == 0:
            q.drain_one()
    q.drain_all()

    assert q.dropped == 0
    assert q.wire == seq
    # I2：每条边沿都来自输入，没有凭空多出来的
    assert edges(q.wire) == edges(seq)


def test_overflow_only_when_no_slot_ever_frees():
    q = UrgQueue(depth=4, wait_slots=0)          # 不允许等待 = 旧行为
    for _ in range(10):
        q.push(DOWN)
    assert q.dropped == 6, f'满队列应记 6 次溢出，实际 {q.dropped}'
    assert len(q.q) == 4, '溢出后不应覆盖已排队的报告'


def test_overflow_recovers_when_slots_free():
    """新行为（2026-11-12）：等得到空位就不许丢。"""
    q = UrgQueue(depth=4, wait_slots=10)
    for _ in range(10):
        q.push(DOWN)
    q.drain_all()
    assert q.dropped == 0, f'有空位仍丢 {q.dropped} 条'
    assert len(q.wire) == 10


# --------------------------------------------------------------------------- #
# I3：释放守卫窗口边界（对应 R1 / B4）
# --------------------------------------------------------------------------- #

@pytest.mark.parametrize('window_ms,delta_ms,expect_swallow', [
    (20, 0,  True),      # 松开瞬间又按下 → 抖动
    (20, 8,  True),      # 典型微动回跳
    (20, 19, True),      # 窗口内
    (20, 20, False),     # 边界：不小于窗口 → 放行
    (20, 25, False),
    (0,  0,  False),     # 守卫关闭 = 一个都不许少
    (0,  8,  False),
    (0,  19, False),
])
def test_release_guard_boundaries(window_ms, delta_ms, expect_swallow):
    g = ReleaseGuard(window_ms)
    g.classify(DOWN, 0)                       # 按下
    g.classify(UP, 10_000)                    # 松开（记 release 时刻）
    swallow, fwd = g.classify(DOWN, 10_000 + delta_ms * 1000)
    assert swallow is expect_swallow, \
        f'window={window_ms}ms delta={delta_ms}ms 期望 {expect_swallow}，实际 {swallow}'
    assert fwd == (UP if expect_swallow else DOWN)


def test_guard_off_never_loses_edges():
    g = ReleaseGuard(0)
    t = 0
    seq = [DOWN, UP, DOWN, UP, DOWN, UP]      # 每次间隔 4 ms 的"疯狂连点"
    fwd = []
    for b in seq:
        _, f = g.classify(b, t)
        fwd.append(f)
        t += 4_000
    assert fwd == seq, f'守卫关闭后仍丢了边沿: {fwd}'


def test_guard_on_loses_only_sub_window_repress():
    """守卫打开时的损失必须**有界且可解释**：只吞"松开后 < window 的再次按下"。"""
    g = ReleaseGuard(20)
    seq = [(DOWN, 0), (UP, 10_000), (DOWN, 12_000), (UP, 100_000)]
    fwd = [g.classify(b, t)[1] for b, t in seq]
    assert fwd == [DOWN, UP, UP, UP], f'吞的范围不对: {fwd}'
    # 之后的正常点击不受影响
    assert g.classify(DOWN, 200_000)[1] == DOWN
