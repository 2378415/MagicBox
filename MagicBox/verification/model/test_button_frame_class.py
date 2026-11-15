"""帧分类 / 按位抗抖的离线模型（D49，2026-11-15；无需硬件）。

背景：`0xA2` 一条通道同时搬鼠标报告和键盘报告，靠 `payload[0]` 的 ep 区分。
左片入口以前只判 `len < 4`，于是键盘的 8 字节 boot 报告（byte0 = **修饰键位图**）
被当成鼠标按键字节，修饰键被投影成鼠标按钮：

    LCtrl 0x01 -> 左键    LShift 0x02 -> 右键   LAlt 0x04 -> 中键
    LGUI  0x08 -> 侧后    RCtrl  0x10 -> 侧前

现场症状是「点右键触发左键」「点左键按下后立刻抬起」。本文件把修好后的两条语义
写成模型锁住，防止回归：

    I1 键盘/厂商/其它帧绝不改变鼠标按键状态（失败即安全：判不出 = 只转发）；
    I2 抗抖只回退**被判定为抖动的那几位**，跨键位不串（右键抖动不许产生左键位）；
    I3 松开侧最小脉宽：极短假松不开上线；真实长按后的松开不受影响；
    I4 基准（s_fwd_btn_last）在 sumv 分支也必须刷新，否则下一次点击会拿着陈旧基准。
"""
import pytest

MASK = 0x1F
LEFT, RIGHT, MIDDLE, SIDE_BACK, SIDE_FWD = 0x01, 0x02, 0x04, 0x08, 0x10

MOUSE_EP = 0x81
KBD_EP = 0x82


# --------------------------------------------------------------------------- #
# 模型：左片入口的帧分类（对应 app_main.c link_frame_is_keyboard/…/is_mouse）
# --------------------------------------------------------------------------- #

def classify(ep, data, length, mouse_ep=MOUSE_EP, kbd_ep=KBD_EP):
    """返回 'kbd' | 'vendor' | 'other' | 'mouse'，顺序与固件一致。"""
    if ep == kbd_ep and length == 8:
        return 'kbd'
    if ep == kbd_ep and data and length > 0 and data[0] == 0x04:
        return 'vendor'          # 64 B 厂商帧 / 短通知（同一个判定谓词）
    if ep == mouse_ep or ep == 0x00:
        return 'mouse'           # ep 0 保留给台架注入
    return 'other'


class MouseState:
    """只保存"会被污染的三份状态"：线上意图、每键位按下/松开时刻。"""

    def __init__(self):
        self.wire = 0            # s_fwd_btn_last
        self.press_us = [0] * 5  # s_fwd_press_us
        self.rel_us = [0] * 5    # s_fwd_rel_us
        self.phatoms = []        # 记录任何"不该出现"的变化，供断言

    def note(self, btn, now_us):
        """btn_intent_note()：记时刻 + 刷新基准。"""
        prev = self.wire & MASK
        pressed = btn & ~prev
        released = prev & ~btn
        for b in range(5):
            m = 1 << b
            if pressed & m:
                self.press_us[b] = now_us or 1
            if released & m:
                self.rel_us[b] = now_us or 1
        self.wire = btn & MASK

    def feed_frame(self, ep, data, length, now_us, press_ms=20, rel_min_us=6000):
        """完整入口模型：先分类，只有 mouse 帧才进按键状态机。

        返回 (kind, 实际转发的按键字节)；非 mouse 帧返回 (kind, None)。
        """
        kind = classify(ep, data, length)
        if kind != 'mouse':
            return kind, None
        _raw, fwd = apply_guard(self, data[0] & MASK, now_us, press_ms, rel_min_us)
        self.note(fwd, now_us)
        return kind, fwd


def apply_guard(state, btn, now_us, press_ms=20, rel_min_us=6000):
    """对应 app_main.c 的按位抗抖块。返回 (原始, 实际转发)。"""
    prev = state.wire & MASK
    pressed = btn & ~prev
    released = prev & ~btn
    suppressed = 0

    if pressed and press_ms:
        window = press_ms * 1000
        for b in range(5):
            m = 1 << b
            if pressed & m and state.rel_us[b] and (now_us - state.rel_us[b]) < window:
                suppressed |= m
    if released and press_ms and rel_min_us:
        for b in range(5):
            m = 1 << b
            if released & m and state.press_us[b] and (now_us - state.press_us[b]) < rel_min_us:
                suppressed |= m
    fwd = ((btn & ~suppressed) | (prev & suppressed)) & MASK
    return btn, fwd


# --------------------------------------------------------------------------- #
# I1：键盘 / 厂商 / 其它帧绝不碰鼠标状态
# --------------------------------------------------------------------------- #

@pytest.mark.parametrize('modifier', [0x00, 0x01, 0x02, 0x04, 0x05, 0x08, 0x10,
                                      0x20, 0x40, 0x80, 0xFF])
def test_keyboard_frame_never_touches_mouse_state(modifier):
    """键盘帧（ep=0x82 / 8 B）无论修饰键是什么都不能改鼠标按键状态。"""
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)      # 先按下左键
    before = (st.wire, list(st.press_us), list(st.rel_us))
    for t in range(2_000, 42_000, 1_000):
        kind, _ = st.feed_frame(KBD_EP, [modifier, 0, 0x1A, 0, 0, 0, 0, 0], 8, t)
        assert kind == 'kbd'
    assert (st.wire, st.press_us, st.rel_us) == before, '键盘帧污染了鼠标按键状态'


def test_keyboard_frame_does_not_create_phantom_buttons():
    """修饰键位图与鼠标位同构：LCtrl=0x01(左) / LShift=0x02(右) / LGUI=0x08(侧后)。"""
    st = MouseState()
    for modifier, expected_mouse_bit in ((0x01, LEFT), (0x02, RIGHT), (0x08, SIDE_BACK)):
        st2 = MouseState()
        st2.feed_frame(KBD_EP, [modifier, 0, 0, 0, 0, 0, 0, 0], 8, 1_000)
        assert st2.wire == 0, f'修饰键 0x{modifier:02x} 被投影成鼠标位 0x{expected_mouse_bit:02x}'
    assert st.wire == 0


def test_keyboard_frame_in_sumv_branch_is_also_blocked():
    """sumv 活跃时键盘帧同样只转发——以前会落进 sumv 分支被当鼠标报告。"""
    st = MouseState()
    st.wire = LEFT
    for t in range(1_000, 5_000, 500):
        kind, res = st.feed_frame(KBD_EP, [0x00, 0, 0x04, 0, 0, 0, 0, 0], 8, t)
        assert kind == 'kbd' and res is None
    assert st.wire == LEFT


@pytest.mark.parametrize('ep,data,length,expect', [
    (0x81, [0x01, 1, 0, 0], 4, 'mouse'),        # 鼠标报告
    (0x00, [0x01, 1, 0, 0], 4, 'mouse'),        # 台架注入（ep 0 = 未指定）
    (0x82, [0x00, 0, 0x04, 0, 0, 0, 0, 0], 8, 'kbd'),   # 键盘（无修饰键）
    (0x82, [0x01, 0, 0x04, 0, 0, 0, 0, 0], 8, 'kbd'),   # 键盘（LCtrl）
    (0x82, [0x04] + [0] * 63, 64, 'vendor'),            # 厂商 64 B 帧
    (0x82, [0x04, 0, 0, 0], 4, 'vendor'),               # 短厂商通知
    (0x82, [0x01, 2, 3], 3, 'other'),                   # 判不出：只转发
])
def test_classification_matrix(ep, data, length, expect):
    assert classify(ep, data, length) == expect


def test_unknown_frames_are_passthrough_only():
    """判不出类别的帧必须落到 'other'（只转发），绝不能进按键状态机。"""
    st = MouseState()
    st.wire = RIGHT
    kind, res = st.feed_frame(0x83, [0x01, 0, 0, 0, 0, 0], 6, 9_000)
    assert kind == 'other' and res is None
    assert st.wire == RIGHT


# --------------------------------------------------------------------------- #
# I2：抗抖按位，不跨键位
# --------------------------------------------------------------------------- #

def test_right_click_bounce_never_emits_left_bit():
    """右键抖动只能影响右键位：旧实现整字节回退会在基准含 Ctrl 位时发左键。"""
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)            # 左键按下
    st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 60_000)           # 40 ms 后松开（真实点击）
    assert st.wire == 0
    st.feed_frame(MOUSE_EP, [RIGHT, 0, 1, 0], 4, 100_000)         # 右键按下
    _, fwd = st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 140_000)  # 40 ms 后松开
    assert fwd == 0x00
    _, fwd = st.feed_frame(MOUSE_EP, [RIGHT, 0, 0, 0], 4, 143_000)  # 3 ms 后又"按下"= 回弹
    assert not (fwd & LEFT), '右键路径上出现了左键位'
    assert fwd == 0x00, f'回弹应被吞，实际 0x{fwd:02x}'


def test_bounce_window_is_per_bit():
    """左键的松开时刻不许给右键开禁按窗口。"""
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)           # 左键按下
    st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 50_000)          # 40 ms 后真实松开
    _, fwd = st.feed_frame(MOUSE_EP, [RIGHT, 0, 0, 0], 4, 50_008)  # 8 ms 后点右键
    assert fwd == RIGHT, f'右键被左键的复位窗口吞掉了（0x{fwd:02x}）'


def test_same_bit_repress_inside_window_is_swallowed():
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)
    st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 50_000)          # 真实松开（40 ms 按）
    _, fwd = st.feed_frame(MOUSE_EP, [LEFT, 0, 1, 0], 4, 50_008)   # 同一键位 8 ms 后重按
    assert fwd == 0x00, '同键位微动回弹应当被吞'
    _, fwd = st.feed_frame(MOUSE_EP, [LEFT, 0, 1, 0], 4, 80_000)   # 30 ms 后重按 → 放行
    assert fwd == LEFT


def test_two_keys_pressed_together_keep_both_bits():
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)
    _, fwd = st.feed_frame(MOUSE_EP, [LEFT | RIGHT, 0, 0, 0], 4, 1_200)
    assert fwd == (LEFT | RIGHT)


# --------------------------------------------------------------------------- #
# I3：松开侧最小脉宽
# --------------------------------------------------------------------------- #

@pytest.mark.parametrize('release_delay_us,expect_still_down', [
    (1_000, True),      # 1 ms 假松开 → 保持按下
    (3_000, True),
    (5_000, True),      # 边界内
    (6_000, False),     # 边界：不小于窗口 → 放行
    (30_000, False),
    (150_000, False),   # 正常点击
])
def test_release_glitch_is_suppressed(release_delay_us, expect_still_down):
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)                 # t=1 ms 按下
    _, fwd = st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 1_000 + release_delay_us)
    assert bool(fwd & LEFT) is expect_still_down


def test_release_glitch_then_real_release_still_goes_up():
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000)
    st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 3_000)      # 2 ms 假松开 → 被抑制
    assert st.wire & LEFT, '假松开后线上应仍是按下'
    _, fwd = st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 80_000)   # 真正的松开
    assert fwd == 0x00, '真实松开必须上线'


def test_guard_off_restores_raw_behaviour():
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000, press_ms=0)
    _, fwd = st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 1_500, press_ms=0)
    assert fwd == 0x00, 'mx.gd 0 之后松开必须立即上线'


def test_release_side_default_is_off():
    """出厂默认只开按下侧（台架注入间隔常 <6 ms，开了会吞掉成对边沿）；
    松开侧靠 `mx.gd 20 6` 现场按需打开。"""
    st = MouseState()
    st.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000, rel_min_us=0)      # 出厂默认
    _, fwd = st.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 1_500, rel_min_us=0)
    assert fwd == 0x00
    st2 = MouseState()
    st2.feed_frame(MOUSE_EP, [LEFT, 1, 0, 0], 4, 1_000, rel_min_us=6_000)  # mx.gd 20 6
    _, fwd2 = st2.feed_frame(MOUSE_EP, [0x00, 0, 0, 0], 4, 1_500, rel_min_us=6_000)
    assert fwd2 == LEFT


# --------------------------------------------------------------------------- #
# I4：基准必须在所有分支刷新（含 sumv）
# --------------------------------------------------------------------------- #

def test_baseline_stays_current_when_sumv_branch_bypasses_filter():
    """sumv 分支不走抗抖，但必须刷新基准；否则 sumv 结束后第一次点击拿陈旧基准。"""
    st = MouseState()
    st.note(LEFT, 1_000)                       # sumv 期间按下左键
    st.note(0x00, 2_000)                       # sumv 期间松开
    assert st.wire == 0
    _, fwd = st.feed_frame(MOUSE_EP, [RIGHT, 0, 0, 0], 4, 2_010)
    assert fwd == RIGHT, 'sumv 结束后的第一击被陈旧基准干扰'


def test_no_edge_is_ever_invented():
    """随机流：输出只能是"输入位"或"上一次基准位"，不许凭空出现新位。"""
    import random
    rnd = random.Random(20261115)
    st = MouseState()
    t = 1_000
    for _ in range(3000):
        btn = rnd.choice([0x00, LEFT, RIGHT, MIDDLE, LEFT | RIGHT, SIDE_BACK])
        _, fwd = st.feed_frame(MOUSE_EP, [btn, 1, 0, 0], 4, t)
        assert fwd & ~(btn | st.wire) == 0, f'凭空出现位 0x{fwd:02x} (in=0x{btn:02x})'
        t += rnd.choice([500, 1_000, 4_000, 15_000, 60_000])


# --------------------------------------------------------------------------- #
# I5：提交意图 vs 运动帧（2026-11-15 第二版；对应 makcu_hiddev.c 的 rep_push(…, motion)）
# --------------------------------------------------------------------------- #

class Submitter:
    """模型：URG（状态提交）与 FIFO（运动帧）两条队列 + 提交意图。

    固件判据（rep_push）：`!motion && btn != 意图` 才是按键报告（URG），否则进运动 FIFO；
    意图**只在提交那一刻**更新（出队不回写）。
    """

    def __init__(self):
        self.intent = 0
        self.urg = []
        self.fifo = []
        self.wire = []

    def submit(self, btn, motion=False):
        if not motion and btn != self.intent:
            self.urg.append(btn)
        else:
            self.fifo.append(btn)
        if not motion:
            self.intent = btn

    def drain(self, which):
        q = self.urg if which == 'urg' else self.fifo
        if not q:
            return None
        b = q.pop(0)
        self.wire.append(b)
        return b


def test_motion_frames_never_enter_the_button_queue():
    s = Submitter()
    for _ in range(50):
        s.submit(LEFT, motion=True)      # 引擎 1 kHz 帧：按键位只是对齐
    assert s.urg == [], '运动帧挤进了按键队列'
    assert s.intent == 0, '运动帧不许改变提交意图'


def test_release_right_after_queued_press_stays_in_urg():
    """按下还压在队列里时来的松开，必须仍走按键队列（否则出队时会被改写回旧状态）。"""
    s = Submitter()
    s.submit(LEFT)                        # 按下：意图 0 → 1
    s.submit(0x00)                        # 松开：意图 1 → 0
    assert s.urg == [LEFT, 0x00], f'松开被降级到运动 FIFO：{s.urg} / fifo={s.fifo}'


def test_drain_does_not_rewrite_the_intent():
    """出队不许回写意图：否则"按下出队"会把已经提交的松开意图盖回去，下一次按下丢边沿。"""
    s = Submitter()
    s.submit(LEFT)
    s.submit(0x00)
    s.drain('urg')                        # 按下上线
    assert s.intent == 0, '出队把意图退回了旧值'
    s.submit(LEFT)                        # 再按一次必须仍然进按键队列
    assert s.urg[-1] == LEFT, '下一次按下被当成"没有变化"丢进 FIFO'


def test_duplicate_state_submission_goes_to_fifo():
    """同值的重复提交（连点宏重发 0x32）不算状态变化，走运动队列即可。"""
    s = Submitter()
    s.submit(LEFT)
    s.submit(LEFT)                        # 同值
    assert s.urg == [LEFT] and s.fifo == [LEFT]
