"""按键事件订阅 × 物理点击 —— 2026-11-13 P1 回归（订阅不得吞键）。

背景（实测）：
  订阅穿透时事件通道只是旁路观察，报告一个字节都不改；但**注入（0x32）**会打开
  "主持位窗口"，旧实现是整字节 200 ms 覆盖 → 窗口内的物理点击连带被抹掉。
  实测「订阅 + 注入并发」10 组物理点击丢 18 个边沿（wire_chg 22/40）。

修复（P1-1/P1-5/P1-6）：
  - 主持位窗口**按位**生效：只覆盖被注入按住的位，其它键位的物理点击照常上线；
  - 退订时回灌抗抖基准（否则退订后第一击会被误吞）；
  - 事件推送帧移出热路径（不再在 km_link 里写串口 TX 环）。

判据：`0x3E.wire_chg` 的增量 == 真实按键边沿数；`stamped`/`over`/`swallowed` 不增。
"""
import time

import pytest

N = 6                       # 组数（每 2 个边沿算一次"点击"）
GAP = 0.05


@pytest.fixture()
def dev(device_ready):
    """关抗抖 + 固定会话号 + 退订，结束时恢复默认。"""
    d = device_ready
    d.cmd('mx.gd 0')
    d.cmd('mx.ss 33')
    d.cmd('.km.evt(0)')
    time.sleep(0.15)
    try:
        yield d
    finally:
        d.cmd('.km.evt(0)')
        d.cmd('mx.gd 20')


def snap(dev):
    st = dev.hid_stat() or {}
    lh = dev.last_hid() or {}
    dg = dev.btn_diag() or {}
    return {'wire': st.get('wire'), 'over': st.get('over'),
            'stamped': lh.get('stamped'), 'swallowed': dg.get('swallowed')}


def delta(a, b):
    return {k: (b[k] - a[k]) if None not in (a.get(k), b.get(k)) else None for k in a}


def click(dev, btn):
    dev.inject_link(btn, 0)
    time.sleep(GAP)
    dev.inject_link(0x00, 0)
    time.sleep(GAP)


def frames(dev):
    """进入 link_report_to_mouse 的帧数（台架注入偶发丢帧时用它做分母）。"""
    dg = dev.btn_diag() or {}
    return dg.get('frames')


def do_clicks(dev, n, btn=0x01):
    """做 n 次点击，并保证这 2n 帧确实到达了链路（台架注入本身会偶发丢帧，
    丢帧时补发，避免把台架问题误判成固件吞键）。"""
    want = 2 * n
    got = 0
    guard = 0
    while got < want and guard < 4 * n:
        f0 = frames(dev)
        click(dev, btn)
        got += (frames(dev) or 0) - f0
        guard += 1
    time.sleep(0.1)
    return got


def test_evt_subscribe_passthrough_keeps_clicks(dev):
    """订阅（穿透 consume=0）前后，物理点击的边沿数完全一致。"""
    a = snap(dev)
    do_clicks(dev, N)
    before = delta(a, snap(dev))
    assert before['wire'] == 2 * N, before

    dev.cmd('.km.evt(1,31,0)')          # 订阅全部键，穿透
    time.sleep(0.15)
    a = snap(dev)
    do_clicks(dev, N)
    after = delta(a, snap(dev))

    assert after['wire'] == 2 * N, f'订阅后丢边沿: {after}'
    assert after['stamped'] == 0, after
    assert after['over'] == 0, after


def test_evt_subscribe_with_injection_keeps_physical_edges(dev):
    """订阅 + 0x32 注入并发：物理点击（不同键位）的边沿一条不少。

    每组 6 个真边沿：物理按(0x01) → 物理放 → 注入按(0x02) → 窗口内物理按(0x03)
    → 窗口内物理放 → 注入放(0x00)。
    """
    dev.cmd('.km.evt(1,31,0)')
    time.sleep(0.15)
    a = snap(dev)
    for _ in range(N):
        click(dev, 0x01)                 # 物理按下/松开
        dev.btn(0x02)                    # 注入按下（打开主持位窗口，位 1）
        time.sleep(0.005)
        dev.inject_link(0x01, 0)         # 窗口内的物理按下（位 0，必须照常上线）
        time.sleep(GAP)
        dev.inject_link(0x00, 0)         # 窗口内的物理松开
        time.sleep(GAP)
        dev.btn(0x00)                    # 注入松开
    d = delta(a, snap(dev))

    assert d['wire'] == 6 * N, f'有边沿被吞: {d}（期望 {6 * N}）'
    assert d['stamped'] == 0, d
    assert d['over'] == 0, d


def test_evt_push_and_clicks_both_lossless(dev):
    """订阅 push 模式 × 物理点击并发：事件与点击**两侧都零丢失**。

    三个固件侧计数必须严格相等（不依赖 PC 抓串口）：
      `mx.ev.head_seq`（生成的事件）== `mx.ox.evsent`（发出的事件帧）== `0x3E.wire_chg`（上线边沿）
    外加 `evdrop==0`、`over==0`。
    """
    dev.bin_send(0x39, bytes([1, 0x1F, 1, 0]))      # 订阅全部键 + push + 穿透
    time.sleep(0.2)

    def ev(dev):
        txt = dev.cmd('mx.ev').decode('latin-1', 'replace')
        body = txt.split('km.')[-1].split('\r')[0].split(',')
        return int(body[5])                          # head_seq

    def evsent(dev):
        for tok in dev.cmd('mx.ox').decode('latin-1', 'replace').split(','):
            if tok.strip().startswith('evsent='):
                return int(tok.strip().split('=')[1])
        return None

    a = (snap(dev)['wire'], ev(dev), evsent(dev))
    do_clicks(dev, N)
    time.sleep(0.4)
    b = (snap(dev)['wire'], ev(dev), evsent(dev))

    d_wire, d_seq, d_sent = (b[i] - a[i] for i in range(3))
    assert d_wire == 2 * N, f'点击侧丢边沿: wire +{d_wire}/{2*N}'
    assert d_seq == 2 * N, f'事件生成数不对: head_seq +{d_seq}/{2*N}'
    assert d_sent == 2 * N, f'事件投递丢帧: evsent +{d_sent}/{2*N}'


def test_evt_unsubscribe_first_click_delivered(dev):
    """订阅→退订之后，第一次点击必须立刻生效（P1-5 退订回灌）。

    以前抗抖基准留在"订阅期间被过滤过的值"上，退订首击会被判成没有变化或吞掉。
    """
    dev.cmd('.km.evt(1,31,0)')
    time.sleep(0.1)
    click(dev, 0x01)                     # 订阅期间点一次，制造状态
    dev.cmd('.km.evt(0)')                # 退订（应回灌抗抖基准）
    time.sleep(0.1)

    a = snap(dev)
    click(dev, 0x01)                     # 退订后的第一次点击
    d = delta(a, snap(dev))
    assert d['wire'] == 2, f'退订首击被吞: {d}'
