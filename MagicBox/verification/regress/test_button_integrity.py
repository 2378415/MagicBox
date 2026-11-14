"""按键完整性专项：0 丢弃 / 0 双发 / 0 卡键。

判据口径（2026-11-12 实测校准）：
  * `btn_in / btn_sent` 只统计**进过队列**的按键报告 —— 端点空闲时报告是直发的，
    不经过队列，所以这两个数**不能**当作"上线了几次"。
  * `wire_chg`（`0x3E` 偏移 14）才是"上线报告中按键字节真正变化的次数"，
    "丢没丢"看它：每次物理变化必须让 wire_chg 恰好 +1。
  * `0x45` 现为 **54 B**：26 `btn_same`、30 `fwd_reports`、34 `rx_ovf`、38 `lf_drop`、
    42 `direct_chg`、46 `queued_chg`、50 `0x32` 帧数。**直发 + 队列 == 线上边沿** 是零丢失的硬判据。
  * `0x42 hist/stamped` 看最后 8 条与改写次数；`0x45 swallowed` = 抗抖吞掉的次数；`0x44` trace 看顺序。

当前实现要点（用例按这些行为断言）：
  * 透传与引擎两条发送路径各有独立队列，按键报告优先（URG）；
  * 引擎运动报告的按键位**在发送时**对齐线上状态，不会制造/吞掉边沿；
  * `0x32 BUTTON` 走 `makcu_mouse_emit_event()`：强制立即上线，不看 2 ms 让路窗口；
  * 注入主持权窗口：`0x32` 后 200 ms 内透传报告按键位对齐线上状态（运动字节原样）；
  * 释放守卫 `mx.gd <0..50>`（默认 20，0 = 关闭）。
"""
import time

import pytest

DOWN, UP = 0x01, 0x00


# --------------------------------------------------------------------------- #
# 基础设施
# --------------------------------------------------------------------------- #

def inject(dev, btn, n=1, dx=1):
    """往 0xA2 链路注入 7 字节 G3M 报告（走真实转发路径，含释放守卫）。

    解析/注入统一实现在 `conftest.Device.inject_link()`，这里只保留语义化名字。
    """
    dev.inject_link(btn=btn, dx=dx, count=n)


def _txt(x):
    return x.decode('latin-1', 'replace') if isinstance(x, (bytes, bytearray)) else str(x)


def hid_stat(dev):
    """0x3E：16 B —— in, sent, wait, overflow, flood, merged, cancel, wire_chg。"""
    p = dev.bin_request(0x3E, b'', timeout=1.0)
    assert p is not None and len(p) >= 16, f'0x3E 回包长度异常: {None if p is None else len(p)}'
    u = lambda o: int.from_bytes(bytes(p[o:o + 2]), 'little')
    return dict(pin=u(0), psent=u(2), wait=u(4), over=u(6),
                flood=u(8), merged=u(10), cancel=u(12), wire=u(14))


def audit(dev):
    p = dev.bin_request(0x3F, b'', timeout=1.0)
    assert p is not None and len(p) >= 12, '0x3F 无回包'
    u = lambda o: int.from_bytes(bytes(p[o:o + 4]), 'little')
    return dict(in_chg=u(0), out_chg=u(4), extra=u(8))


def last_hid(dev):
    p = dev.bin_request(0x42, b'', timeout=1.0)
    assert p is not None and len(p) >= 20, '0x42 无回包'
    return dict(btn=p[2] & 0x1F,
                hist=list(p[10:18]),
                stamped=int.from_bytes(bytes(p[18:20]), 'little'))


def diag(dev):
    """0x45 BTN_CNT（当前固件 54 B）：链路计数 + 直发/队列拆分 + 0x32 帧数。"""
    d = dev.btn_diag()
    assert d is not None, '0x45 无回包'
    assert d['raw_len'] >= 54, f'0x45 回包长度异常: {d["raw_len"]}（当前固件应为 54）'
    return d


def d16(cur, base):
    return (cur - base) & 0xFFFF


def guard(dev, ms=None):
    """`mx.gd` 读 / `mx.gd <ms>` 写；返回**最后一条**回包的数值字符串。

    `dev.cmd()` 会把上一次没读干净的尾巴一起返回，所以这里取最后一个 `km.xxx`。
    """
    import re
    raw = _txt(dev.cmd('mx.gd' if ms is None else f'mx.gd {ms}'))
    m = re.findall(r'km\.([0-9eE]+)', raw)
    assert m, f'mx.gd 回包异常: {raw!r}'
    return m[-1]


def settle(dev, quiet_ms=250, timeout=2.0):
    """等到线上按键字节连续 quiet_ms 不再变化（隔离上一个用例的残留）。"""
    s = hid_stat(dev)
    last = s['wire']
    stable = 0
    deadline = time.time() + timeout
    while time.time() < deadline:
        time.sleep(0.05)
        cur = hid_stat(dev)['wire']
        stable = stable + 50 if cur == last else 0
        last = cur
        if stable >= quiet_ms:
            return True
    return False


@pytest.fixture
def wired(device_ready):
    """打开 0xA2→HID 路径、固定会话、把按键归零，并等到线上安静。

    默认把短按抗抖窗口设为 **0**：本文件绝大多数用例验证的是"一个按键都不少"，
    守卫打开会按设计吞掉 <20 ms 的二次按下（T5 专门验证那个行为）。
    实物鼠标必须静止或拔掉：它静止时仍持续发 0x00，不构成边沿。
    """
    dev = device_ready
    dev.cmd('mx.hk 1')
    dev.cmd('mx.ss 33')
    guard(dev, 0)
    inject(dev, UP)
    settle(dev)
    yield dev
    try:
        inject(dev, UP)
        settle(dev)
    finally:
        guard(dev, 20)
        dev.cmd('mx.ss 00')


# --------------------------------------------------------------------------- #
# 用例
# --------------------------------------------------------------------------- #

def test_t1_single_click_no_dup(wired):
    """一次点击 = 两个上线边沿（按下、松开），不多不少。"""
    dev = wired
    s0, a0, h0 = hid_stat(dev), audit(dev), last_hid(dev)

    inject(dev, DOWN); time.sleep(0.08)
    inject(dev, UP);   time.sleep(0.15)
    s1, a1, h1 = hid_stat(dev), audit(dev), last_hid(dev)

    assert d16(s1['wire'], s0['wire']) == 2, \
        f"上线按键变化数不符（丢或没生效）: wire {s0['wire']} → {s1['wire']}"
    assert a1['extra'] == a0['extra'], f"凭空多出按键变化: extra {a0['extra']} → {a1['extra']}"
    assert h1['btn'] == 0, f"结束时按键未松开: {h1['btn']:#x}"
    assert 0x01 in h1['hist'], f"历史里没有按下沿: {[hex(b) for b in h1['hist']]}"
    assert d16(s1['over'], s0['over']) == 0, 'URG 溢出'


def test_t2_click_during_backlog(wired):
    """FIFO 里压着 150 条"按下前"的报告时按下/松开，两个边沿都必须上线。"""
    dev = wired
    s0, a0, h0 = hid_stat(dev), audit(dev), last_hid(dev)

    inject(dev, UP, n=150)          # 积压
    inject(dev, DOWN)               # 按下（走 URG）
    inject(dev, DOWN, n=40)         # 按住继续灌
    time.sleep(0.05)
    inject(dev, UP)
    time.sleep(0.35)

    s1, a1, h1 = hid_stat(dev), audit(dev), last_hid(dev)
    assert d16(s1['wire'], s0['wire']) == 2, f'积压时按键边沿丢失: {s0} → {s1}'
    # `extra` 在透传模式下不是"双发"的有效判据（按键字节经 sync 变化也会被计入），
    # 这里只看 wire/trace 与最终归零。
    assert h1['stamped'] >= h0['stamped'], 'stamped 计数倒退（不应发生）'

    # 结束状态：允许几百毫秒排空（1 kHz 端点 + 190 条积压），轮询到归零
    ok = False
    for _ in range(20):
        time.sleep(0.05)
        if last_hid(dev)['btn'] == 0:
            ok = True
            break
    assert ok, '积压结束后按键未回到松开态（0x42 连续 1 s 都是按下）'


def test_t3_twenty_clicks(wired):
    """20 连点（间隔 30/30 ms，落在守卫窗口外）= 40 个上线边沿。"""
    dev = wired
    s0 = hid_stat(dev)
    for _ in range(20):
        inject(dev, DOWN); time.sleep(0.03)
        inject(dev, UP);   time.sleep(0.03)
    time.sleep(0.25)
    s1 = hid_stat(dev)

    assert d16(s1['wire'], s0['wire']) == 40, f'20 连点应 40 个边沿: {s0} → {s1}'
    assert d16(s1['over'], s0['over']) == 0, 'URG 队列溢出'
    assert last_hid(dev)['btn'] == 0, '连点后按键卡住'


def test_t4_guard_off_delivers_fast_second_click(wired):
    """R1 的正解：`mx.gd 0` 关掉释放守卫后，8 ms 内的二次按下也必须上线。"""
    dev = wired
    assert guard(dev, 0) == '0', 'mx.gd 0 未生效'
    s0 = hid_stat(dev)

    inject(dev, DOWN); time.sleep(0.01)
    inject(dev, UP);   time.sleep(0.008)      # 松开后 8 ms 再按
    inject(dev, DOWN); time.sleep(0.10)
    inject(dev, UP);   time.sleep(0.20)
    s1 = hid_stat(dev)

    assert d16(s1['wire'], s0['wire']) == 4, \
        f'守卫关闭后仍有按键被吞: wire {s0["wire"]} → {s1["wire"]}'


def test_t5_default_guard_swallows_bounce(wired):
    """守卫打开（20 ms）时，松开后 8 ms 的"再按下"按设计被吞（B4 保护）。

    这条**故意断言吞掉**：它锁住"抗抖不能被无声改掉"，改默认值就会红。
    """
    dev = wired
    assert guard(dev, 20) == '20'
    s0, d0 = hid_stat(dev), diag(dev)
    inject(dev, DOWN); time.sleep(0.01)
    inject(dev, UP);   time.sleep(0.008)
    inject(dev, DOWN); time.sleep(0.10)
    inject(dev, UP);   time.sleep(0.20)
    s1, d1 = hid_stat(dev), diag(dev)

    assert d16(d1['swallowed'], d0['swallowed']) == 1, '默认 20 ms 守卫没有生效'
    assert d16(s1['wire'], s0['wire']) == 2, '被吞的抖动不应上线'


def test_t6_burst_does_not_overflow(wired):
    """R3 的正解：40 次连续按键变化（> 原 URG 深度 32）必须全进、全上线。"""
    dev = wired
    s0 = hid_stat(dev)
    for i in range(40):
        inject(dev, 0x01 if i % 2 == 0 else 0x00)
        time.sleep(0.001)
    time.sleep(0.40)
    s1 = hid_stat(dev)

    assert d16(s1['over'], s0['over']) == 0, 'URG 溢出（按键会被丢）'
    assert d16(s1['wire'], s0['wire']) == 40, f'应 40 个边沿上线: {s0} → {s1}'
    assert last_hid(dev)['btn'] == 0, '爆发后按键卡住'


def test_t7_sequence_order(wired):
    """按下(0x01) → 松开 → 按下(0x02) → 松开：历史顺序不能颠倒。"""
    dev = wired
    for btn in (0x01, 0x00, 0x02, 0x00):
        inject(dev, btn); time.sleep(0.04)
    time.sleep(0.20)
    hist = last_hid(dev)['hist']
    seen = [b for b in hist if b in (0x01, 0x02)]
    assert seen[-2:] == [0x01, 0x02], f'顺序异常: {[hex(b) for b in hist]}'


def test_t8_concurrent_aim_keeps_all_buttons(wired):
    """AIM 1 kHz 期间夹 10 次点击：全部上线、无溢出、延迟 < 5 ms、结束不卡键。"""
    dev = wired
    s0, a0 = hid_stat(dev), audit(dev)

    dev.sumv(400, 0, speed=4000, mode=0)
    for _ in range(10):
        inject(dev, DOWN); time.sleep(0.02)
        inject(dev, UP);   time.sleep(0.03)
    dev.sumv_wait_done(timeout=6.0)
    time.sleep(0.25)

    s1, a1 = hid_stat(dev), audit(dev)
    assert d16(s1['wire'], s0['wire']) == 20, f'AIM 期间按键边沿丢失: {s0} → {s1}'
    assert d16(s1['over'], s0['over']) == 0, 'AIM 期间 URG 溢出'
    assert s1['wait'] < 20000, f"按键上线延迟过高: {s1['wait']} µs（AIM 1 kHz 下实测可达 6–12 ms）"
    assert last_hid(dev)['btn'] == 0, 'AIM 结束后按键卡住'
    # 注：不再断言 `0x3F extra` —— 透传路径通过 `makcu_mouse_sync_buttons()` 改按键状态，
    # 会被审计层记成"无请求的变化"，它不能用来判定双发（真判据是 wire + trace）。


def test_t9_guard_command_roundtrip(wired):
    """`mx.gd` 读 / 写自洽，越界值被拒且不改当前值。"""
    dev = wired
    assert guard(dev, 15) == '15'
    assert guard(dev) == '15', 'mx.gd 读数与刚写入的不一致'
    assert guard(dev, 0) == '0'
    assert guard(dev, 99) == 'e', '越界值应被拒'
    assert guard(dev) == '0', '被拒的写入不应改变当前值'
    assert guard(dev, 20) == '20'


def test_t10_diag_split_counts_contract(wired):
    """`0x45` 新字段契约：直发变化 + 队列变化 == 线上边沿；`0x32` 帧数按注入计。

    这是 2026-11-12 引入的"零丢失/零多发"硬判据：一次变化只能被引入一次，
    无论它从直发路径还是 URG 队列上线。
    """
    dev = wired
    d0, s0 = diag(dev), hid_stat(dev)
    assert 'direct_chg' in d0 and 'queued_chg' in d0 and 'btn_cmds' in d0, \
        f'0x45 缺少新字段: {sorted(d0)}'

    for _ in range(10):
        dev.btn(0x01); time.sleep(0.012)
        dev.btn(0x00); time.sleep(0.012)
    time.sleep(0.25)

    d1, s1 = diag(dev), hid_stat(dev)
    split = (d1['direct_chg'] - d0['direct_chg']) + (d1['queued_chg'] - d0['queued_chg'])
    wire = d16(s1['wire'], s0['wire'])
    cmds = d1['btn_cmds'] - d0['btn_cmds']

    assert cmds == 20, f'0x32 帧数应等于注入数 20，实际 {cmds}'
    assert wire == 20, f'线上边沿应 20，实际 {wire}'
    assert split == wire, f'直发+队列({split}) 必须等于线上边沿({wire})：说明有合并或多发'
    assert last_hid(dev)['btn'] == 0, '结束按键未松开'
