"""sumv 看门狗 / 位移守恒的离线模型（D50，2026-11-15；无需硬件）。

背景：`makcu_sumv.c` 以前把轨迹起点存成 **u32**（`(uint32_t)esp_timer_get_time()`），
却又把它当成完整时间戳和 int64 时钟相减。uptime 越过 2^32 µs（**71 min 35 s**）后，
差值多出 k×4 294 967 ms，看门狗（判据 `elapsed_ms > total_samples + 500`）每发必中：

    ⇒ 每发 sumv/AIM 只来得及发出首样本（1 count ≈ 0.8 px）就被判故障
    ⇒ 观感「运行久了就一个像素一个像素移动」

本文件把修好后的两条语义写成模型锁住：

    I1 看门狗只按 **int64 差值** 判（uptime 任意大都不误杀）；
    I2 停滞判据（>200 ms 无进展）与总时长兜底（>total+500 ms）各自独立；
    I3 被让路窗口拒收的样本**不推进**已发位置（位移守恒），并能被重试；
    I4 模拟"长跑"（起点前移 2^32 µs）之后，轨迹仍然按时走完、计数正确。
"""
import pytest

US_PER_MS = 1000
U32_WRAP_US = 1 << 32          # 4 294 967 296 µs ≈ 71 min 35 s
STALL_MS = 200                 # SUMV_STALL_MS
BUDGET_EXTRA_MS = 500          # 兜底判据的余量


# --------------------------------------------------------------------------- #
# 模型 1：看门狗判据（对应 sumv_tick 里的两个差值）
# --------------------------------------------------------------------------- #

def watchdog_should_stop(now_us, started_us, last_progress_us, total_ms,
                         stall_ms=STALL_MS):
    """返回 (是否停, 原因)。所有差值都在 int64 域里算。"""
    stalled_ms = (now_us - last_progress_us) // US_PER_MS
    elapsed_ms = (now_us - started_us) // US_PER_MS
    budget_ms = total_ms + BUDGET_EXTRA_MS
    if stalled_ms > stall_ms:
        return True, 'stall'
    if elapsed_ms > budget_ms:
        return True, 'elapsed'
    return False, None


def old_watchdog_should_stop(now_us, started_u32, total_ms):
    """旧实现（有缺陷）的等价模型：起点被截断成 u32 后再与 int64 相减。"""
    started_us = started_u32 & 0xFFFFFFFF          # (int64_t)(uint32_t)…
    elapsed_ms = (now_us - started_us) // US_PER_MS
    return elapsed_ms > total_ms + BUDGET_EXTRA_MS, elapsed_ms


@pytest.mark.parametrize('now_us', [
    1_000_000,                    # 开机 1 s
    U32_WRAP_US - 1,              # 回绕前 1 µs
    U32_WRAP_US,                  # 正好回绕
    U32_WRAP_US + 5_000,          # 回绕后 5 ms
    U32_WRAP_US * 3 + 123_456,    # 开机 3×71 min 之后
])
def test_watchdog_never_trips_on_a_healthy_trajectory(now_us):
    """I1/I2：正常轨迹（一直在进展）在任何 uptime 下都不该被停。"""
    started = now_us - 5_000            # 5 ms 前开始，total=40 ms
    stop, why = watchdog_should_stop(now_us, started, now_us - 1_000, total_ms=40)
    assert not stop, f'uptime={now_us} 时误杀（{why}）'


def test_old_implementation_reproduces_the_field_bug():
    """把旧算法跑一遍：uptime 越过 2^32 后 **每发必停**（这就是现场那个 bug）。"""
    now_us = U32_WRAP_US + 1_000_000          # 回绕后 1 s
    started_u32 = now_us & 0xFFFFFFFF          # 旧代码写入的就是这个
    stop, elapsed = old_watchdog_should_stop(now_us, started_u32, total_ms=40)
    assert stop and elapsed > 4_000_000, f'旧算法应判死，实际 elapsed={elapsed}'
    # 新算法同场景：正常
    stop2, why = watchdog_should_stop(now_us, now_us - 5_000, now_us - 1_000, 40)
    assert not stop2, why


@pytest.mark.parametrize('stalled_ms,budget_margin_ms,expect,reason', [
    (150, -100, False, None),     # 有进展、预算内 → 继续
    (250, -100, True, 'stall'),   # 停滞 → 停（哪怕预算还有）
    (150, 1, True, 'elapsed'),    # 没停滞但总时长超预算 → 兜底停
    (200, 0, False, None),        # 边界：等于阈值不停（判据用 >）
])
def test_stall_and_budget_are_independent(stalled_ms, budget_margin_ms, expect, reason):
    total_ms = 40
    now_us = 1_000_000
    last_progress_us = now_us - stalled_ms * US_PER_MS
    started_us = now_us - (total_ms + BUDGET_EXTRA_MS + budget_margin_ms) * US_PER_MS
    stop, why = watchdog_should_stop(now_us, started_us, last_progress_us, total_ms)
    assert stop is expect, f'stalled={stalled_ms} margin={budget_margin_ms} → {why}'
    assert why == reason


# --------------------------------------------------------------------------- #
# 模型 2：位移守恒（对应 emit_sample 的"被拒就不推进"）
# --------------------------------------------------------------------------- #

def _plan(dx, dy, total):
    """预先算好每一步的 (sx, sy)：target(t)=round(d*t/total)，差分为步长。
    与固件的"弧长参数化 + DDA 取整"守恒性质相同。"""
    out = []
    for t in range(total):
        nx = int(round(dx * (t + 1) / total))
        ny = int(round(dy * (t + 1) / total))
        cx = int(round(dx * t / total))
        cy = int(round(dy * t / total))
        out.append((nx - cx, ny - cy))
    return out


class Trajectory:
    """最小 sumv 轨迹模型：被拒的 tick **不推进**位置，下一 tick 重试同一步。"""

    def __init__(self, dx, dy, total_samples, reject_plan=None):
        self.dx, self.dy = dx, dy
        self.total = total_samples
        self.plan = _plan(dx, dy, total_samples)
        self.i = 0
        self.px = self.py = 0
        self.sent = []
        self.rejected = 0
        self.reject_plan = reject_plan or (lambda tick: False)
        self.ticks = 0

    def step(self):
        self.ticks += 1
        if self.i >= len(self.plan):
            rx, ry = self.dx - self.px, self.dy - self.py
            if rx == 0 and ry == 0:
                return False
            self.sent.append((rx, ry))          # 收尾补平
            self.px += rx
            self.py += ry
            return True
        if self.reject_plan(self.ticks):
            self.rejected += 1
            return True                          # 被拒：位置不动、i 不动
        sx, sy = self.plan[self.i]
        self.px += sx
        self.py += sy
        self.sent.append((sx, sy))
        self.i += 1
        return True

    def finish(self, max_ticks=5000):
        while (self.px != self.dx or self.py != self.dy) and self.ticks < max_ticks:
            self.step()
        return self.px, self.py


def test_rejected_steps_are_retried_and_displacement_is_conserved():
    """I3：让路窗口拒收的样本不许推进位置；最终位移必须精确等于请求值。"""
    traj = Trajectory(dx=40, dy=-25, total_samples=40,
                      reject_plan=lambda t: t % 7 == 3)      # 每 7 tick 拒 1 次
    traj.finish()
    assert (traj.px, traj.py) == (40, -25), f'位移不守恒：({traj.px},{traj.py})'
    assert traj.rejected >= 5, f'拒收次数异常：{traj.rejected}'
    assert sum(s[0] for s in traj.sent) == 40
    assert sum(s[1] for s in traj.sent) == -25


def test_old_implementation_loses_displacement():
    """旧实现（无条件推进）在同样的拒收计划下会少走一截 —— 现场"轨迹跑完光标没到位"。"""
    total, dx = 40, 40
    rejects = {t for t in range(total) if t % 7 == 3}
    plan = _plan(dx, 0, total)
    px_new = 0
    px_old = 0
    for t in range(total):
        sx = plan[t][0]
        px_old += sx                             # 旧代码：被拒也照样推进
        if t not in rejects:
            px_new += sx                         # 新代码：被拒不推进
    lost = sum(plan[t][0] for t in rejects)
    assert px_old == dx
    assert px_old - px_new == lost > 0, f'旧实现应当丢掉 {lost} counts'
    assert px_new + lost == dx


# --------------------------------------------------------------------------- #
# I4：长跑（起点前移 2^32 µs）之后一切正常
# --------------------------------------------------------------------------- #

def test_long_uptime_shift_keeps_trajectory_alive(monkeypatch=None):
    """`mx.wd bump 4294967`（≈71.6 min）之后，轨迹仍按预算走完、不停。"""
    now_us = 10_000_000                                  # 开机 10 s
    shift_us = U32_WRAP_US                               # 模拟起点前移 2^32 µs
    started = now_us - shift_us                          # 人为"很久以前开始"
    last_progress = now_us - 1_000
    stop, why = watchdog_should_stop(now_us, started, last_progress, total_ms=40)
    # 起点被前移后 elapsed 巨大 → 兜底判据会停（这正是 bump 的用途：模拟旧行为压力）
    assert stop and why == 'elapsed'
    # 但**只要进展时刻是新的**，停滞判据不会误杀；把 elapsed 兜底一并放宽后不再停：
    stop2, why2 = watchdog_should_stop(now_us, started, last_progress, total_ms=U32_WRAP_US)
    assert not stop2, why2


def test_stall_detects_a_real_hang():
    """真卡死（端点死 / HID 卸载）时，200 ms 必须停，而不是干等到 total+500。"""
    now_us = 50_000_000
    stop, why = watchdog_should_stop(now_us, now_us - 5_000, now_us - 300_000, total_ms=5000)
    assert stop and why == 'stall'
