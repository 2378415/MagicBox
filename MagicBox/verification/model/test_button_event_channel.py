"""按键独立事件通道：离线调度器模型（无硬件、无固件改动）。

目的：在写固件之前，先用假时钟把"单写者调度"证明出来，回答两个问题：

1. 如果按键状态**只由事件队列**改写、运动报告**在发送时刻**才取按键字节，
   那么给定 1200 次按键变化（600 点击 @8 ms，即持续 62.5 次/秒）能不能做到
   `线上边沿 == 1200` 且 `重复边沿 == 0`？
2. 旧语义（按键变化只在"下一次运动 flush"时顺带发出）会丢多少？

模型结构（对应固件要落地的形态）：
    EventQueue   按键事件队列（深度可配，满了计数，不丢序）
    Motion      引擎以固定周期产生"运动报告"（不带按键语义）
    Writer      唯一写者：每个 tick 先清空事件队列，再发一条运动报告；
                运动报告携带的是"最近一次真正上线"的按键字节（发送时刻取值）

对应固件落点（下一步实现时）：
    makcu_mouse_set_buttons()  -> EventQueue.push()
    drain 任务/完成回调        -> Writer.tick()
    makcu_hiddev_report()      -> 运动报告，发送时刻取 s_wire_btn_last
"""
from collections import deque


class EventQueue:
    def __init__(self, depth=128):
        self.depth = depth
        self.q = deque()
        self.overflow = 0

    def push(self, t_us, buttons):
        if len(self.q) >= self.depth:
            self.overflow += 1
            return False
        self.q.append((t_us, buttons))
        return True

    def pop(self):
        return self.q.popleft() if self.q else None

    def __len__(self):
        return len(self.q)


class MotionSource:
    """引擎：每 flush_us 产生一条运动报告（只关心"有没有运动"）。"""
    def __init__(self, flush_us=1000):
        self.flush_us = flush_us
        self.next_us = flush_us

    def due(self, now_us):
        return now_us >= self.next_us

    def consume(self, now_us):
        while self.next_us <= now_us:
            self.next_us += self.flush_us
        return True


class Writer:
    """唯一写者：先发按键事件，再发运动报告。所有上线报告都从这里出。"""
    def __init__(self, events, motion, delivery_us=60):
        self.events = events
        self.motion = motion
        self.delivery_us = delivery_us      # 单条报告上线耗时（模拟端点节拍）
        self.wire = []                      # 上线序列（每条：btn）
        self.last_btn = 0x00
        self.next_free_us = 0
        self.latencies = []                 # 事件入队 -> 上线
        self.dups = 0
        self.pending_event = None

    def _busy(self, now_us):
        return now_us < self.next_free_us

    def _send(self, now_us, btn):
        if btn != self.last_btn:
            self.last_btn = btn
            self.wire.append(btn)
        else:
            self.dups += 1                  # 同值上线：运动报告重复携带，不算边沿
        self.next_free_us = now_us + self.delivery_us

    def tick(self, now_us):
        if self._busy(now_us):
            return
        if self.pending_event is None and len(self.events) > 0:
            self.pending_event = self.events.pop()
        if self.pending_event is not None:
            t_us, btn = self.pending_event
            self.pending_event = None
            self.latencies.append(now_us - t_us)
            self._send(now_us, btn)
            return
        if self.motion.due(now_us):
            self.motion.consume(now_us)
            # 运动报告在**发送时刻**取"最近上线"的按键字节 → 永远不会引入边沿
            self._send(now_us, self.last_btn)


def run(events_spec, duration_us, flush_us=1000, depth=128, delivery_us=60, step_us=50):
    """events_spec: [(t_us, btn), ...]；按时间点入队，返回 (writer, events)。"""
    ev = EventQueue(depth)
    w = Writer(ev, MotionSource(flush_us), delivery_us)
    pending = sorted(events_spec)
    pushed = 0
    t = 0
    while t <= duration_us:
        while pushed < len(pending) and pending[pushed][0] <= t:
            ev.push(pending[pushed][0], pending[pushed][1])
            pushed += 1
        w.tick(t)
        t += step_us
    # 收尾：把队列排空
    while len(ev) > 0 or w.pending_event is not None:
        w.tick(t)
        t += step_us
    return w, ev


def clicks(n, gap_ms=8, start_us=0):
    """n 次点击 = press/release 交替，间隔 gap_ms。"""
    seq = []
    t = start_us
    for _ in range(n):
        seq.append((t, 0x01))
        t += gap_ms * 1000
        seq.append((t, 0x00))
        t += gap_ms * 1000
    return seq, t


# --------------------------------------------------------------------------- #
# 1) 新设计：1200 次变化 → 1200 个边沿、0 重复
# --------------------------------------------------------------------------- #

def test_event_channel_sustained_62hz():
    spec, end_us = clicks(600, gap_ms=8)
    assert len(spec) == 1200
    w, ev = run(spec, end_us + 200_000, flush_us=1000, delivery_us=60, step_us=50)

    edges = len(w.wire)
    assert ev.overflow == 0, f'事件队列溢出 {ev.overflow} 次'
    assert edges == 1200, f'线上边沿 {edges}，期望 1200'
    # 序列必须严格 01 00 交替
    assert all(w.wire[i] == (0x01 if i % 2 == 0 else 0x00) for i in range(len(w.wire)))


def test_event_latency_bounded():
    spec, end_us = clicks(600, gap_ms=8)
    w, _ = run(spec, end_us + 200_000, flush_us=1000, delivery_us=60, step_us=50)
    worst = max(w.latencies)
    assert worst <= 3000, f'最坏事件延迟 {worst} µs（端点 {60} µs + tick {50} µs 粒度，应 ≤3 ms）'


def test_motion_never_creates_edges():
    """即使引擎每 1 ms 发一条运动报告，也不会产生任何边沿。"""
    spec, end_us = clicks(600, gap_ms=8)
    w, _ = run(spec, end_us + 200_000, flush_us=1000, delivery_us=60, step_us=50)
    # 边沿数 == 事件数；中间那些同值上线只记在 dups 里
    assert len(w.wire) == len(spec)
    assert w.dups > 0, '这个场景里应该有运动报告重复携带按键位（同值上线）'


# --------------------------------------------------------------------------- #
# 2) 旧语义：按键变化等下一次运动 flush → 会合并掉
# --------------------------------------------------------------------------- #

class LegacyWriter(Writer):
    """旧语义：按键状态每次 flush 时顺带带走；press/release 落在同一 flush 周期就合并。"""

    def __init__(self, events, motion, flush_us=1000, delivery_us=60):
        super().__init__(events, motion, delivery_us)
        self.flush_us = flush_us
        self.pending_btn = 0x00

    def tick(self, now_us):
        if self._busy(now_us):
            return
        if self.motion.due(now_us):
            self.motion.consume(now_us)
            while len(self.events) > 0:          # 把这段时间的事件全并进一条报告
                _, b = self.events.pop()
                self.pending_btn = b
            self._send(now_us, self.pending_btn)


def test_legacy_semantics_loses_edges():
    """旧语义的失效机制：两次变化落在同一个 flush 周期内 → 被合并成一次（净变化为 0）。

    注意：8 ms 间隔、1 ms flush 时旧模型其实不合并（每次变化都能赶上下一个 flush），
    固件里 `pin` 只有 667/1200 的成因要在固件侧用 `btn_collapsed` 计数确认；
    这里只负责证明"只要有合并窗口，边沿就会丢"这个机制。
    """
    spec, end_us = clicks(600, gap_ms=0.4)      # 0.4 ms 间隔 < 1 ms flush → 必合并
    ev = EventQueue(100000)
    w = LegacyWriter(ev, MotionSource(1000))
    pushed, t = 0, 0
    pending = spec
    while t <= end_us + 200_000:
        while pushed < len(pending) and pending[pushed][0] <= t:
            ev.push(*pending[pushed]); pushed += 1
        w.tick(t)
        t += 50
    assert len(w.wire) < len(spec), f'旧语义应丢边沿，实测 {len(w.wire)}/{len(spec)}'
    assert len(w.wire) <= len(spec) // 2 + 8, f'合并后应大幅减少，实测 {len(w.wire)}'


# --------------------------------------------------------------------------- #
# 3) 队列深度 / 溢出语义
# --------------------------------------------------------------------------- #

def test_burst_overflow_is_counted_not_reordered():
    # 1 ms 内推 200 个事件，深度 128 → 溢出被计数，已入队的保持顺序
    spec = [(i * 5, 0x01 if i % 2 == 0 else 0x00) for i in range(200)]
    w, ev = run(spec, 200_000, flush_us=1000, delivery_us=60, step_us=50)
    assert ev.overflow == 200 - 128 or ev.overflow > 0
    assert len(ev) == 0, '收尾后队列应清空'
    # 已入队的 128 个事件必须按序上线（不做重排）
    assert w.wire[:4] == [0x01, 0x00, 0x01, 0x00]
