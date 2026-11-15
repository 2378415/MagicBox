"""sumv 长跑退化回归（D50，2026-11-15）。

背景：`makcu_sumv.c` 的轨迹起点原来是 **u32**（`(uint32_t)esp_timer_get_time()`），
Uptime 越过 2^32 µs（71 min 35 s）后看门狗每发必判故障 → 每发 sumv 只发出首样本
（1 count ≈ 0.8 px），现场观感"运行久了就一个像素一个像素移动"。

台架复现方式：`mx.wd bump <ms>` 把轨迹起点/进展时刻人为前移（模拟很久以前开始），
不需要真等 71 分钟。判据：

  * 10 发 sumv 全部 `rounds`（正常走完），`aborted` 不涨、`stalls` 不涨；
  * `mx.rt` 累计位移守恒（每发 20 counts，10 发共 200）；
  * `mx.sv` 现在有 10 个字段（前 8 个位置不变，后两个是 stalls / emit_rejected）。

修前行为：第一发就会被看门狗掐断（`aborted` 每发 +1、`rounds` 不涨、位移只有个位数），
所以这条用例在旧固件上必红。
"""
import time

import pytest

SUMV_COUNTS = 20          # 每发请求的 counts（切比雪夫长度）
ROUNDS = 10               # 连发次数
SPEED = 12000             # counts/s（20 counts → ~2 ms）
BUMP_MS = 4_295_000       # > 2^32 µs = 4 294 967.296 ms → 模拟 uptime 越过回绕点


def sv(dev):
    """解析 `mx.sv`：active,samples,aborted,rounds,dropped,forwarded,speed_eff,remain,stalls,emit_rejected。"""
    reply = dev.cmd('mx.sv').decode('latin-1', 'replace')
    nums = [int(x) for x in reply.replace('km.', '').replace('>>>', '')
            .replace('\r', '').replace('\n', '').split(',') if x.strip().isdigit()]
    assert len(nums) >= 8, f'mx.sv 回包解析失败: {reply!r}'
    keys = ['active', 'samples', 'aborted', 'rounds', 'dropped', 'forwarded',
            'speed_eff', 'remain', 'stalls', 'emit_rejected']
    return dict(zip(keys, nums))


def test_mx_sv_has_the_new_fields(device_ready):
    """D50 追加了 stalls / emit_rejected；老客户端按前 8 个字段取前缀仍然兼容。"""
    st = sv(device_ready)
    assert 'stalls' in st and 'emit_rejected' in st, f'mx.sv 字段不够: {st}'


def test_mx_wd_reports_uptime(device_ready):
    """`mx.wd` 裸调用回显 uptime(ms)，且是 int64 计算（不会在 2^32 处回绕）。"""
    reply = device_ready.cmd('mx.wd').decode('latin-1', 'replace')
    assert 'km.' in reply, f'mx.wd 无回包: {reply!r}'
    uptime_ms = int(''.join(ch for ch in reply.split('km.')[-1] if ch.isdigit()) or 0)
    assert uptime_ms > 0, f'uptime 解析失败: {reply!r}'


def test_sumv_survives_a_simulated_long_uptime(device_ready):
    """核心用例：把起点前移 71.6 min 后，10 发 sumv 必须全部正常走完。"""
    dev = device_ready
    dev.cmd('mx.hk 1')
    dev.cmd('mx.ss 33')
    dev.cmd('mx.gd 0')                 # 关抗抖，避免影响位移
    time.sleep(0.2)

    before = sv(dev)
    rt0 = dev.rt()
    assert dev.cmd(f'mx.wd bump {BUMP_MS}').decode('latin-1', 'replace').strip(), 'mx.wd bump 无回包'

    for _ in range(ROUNDS):
        dev.sumv(SUMV_COUNTS, 0, speed=SPEED)
        st = dev.sumv_wait_done(timeout=1.0)
        assert st is not None and st['active'] == 0, f'轨迹没走完: {st}'

    time.sleep(0.3)
    after = sv(dev)
    rt1 = dev.rt()

    rounds = after['rounds'] - before['rounds']
    aborted = after['aborted'] - before['aborted']
    stalls = after.get('stalls', 0) - before.get('stalls', 0)
    moved = rt1[0] - rt0[0]

    assert rounds == ROUNDS, f'正常走完 {rounds}/{ROUNDS}（旧固件会 0）: {after}'
    assert aborted == 0, f'被中止 {aborted} 次（旧固件会 {ROUNDS}）: {after}'
    assert stalls == 0, f'看门狗误触发 {stalls} 次: {after}'
    assert moved == ROUNDS * SUMV_COUNTS, \
        f'位移不守恒: {moved} != {ROUNDS * SUMV_COUNTS}（旧固件只走首样本）'


def test_stop_still_works_after_bump(device_ready):
    """bump 之后 `0x37 SUMV_STOP` 依然能立刻停（别把看门狗改活导致停不下来）。"""
    dev = device_ready
    dev.cmd(f'mx.wd bump {BUMP_MS}')
    dev.sumv(2000, 0, speed=50)        # 长轨迹：40 s 才走完
    time.sleep(0.05)
    assert dev.sumv_state()['active'] == 1, '轨迹应该正在跑'
    dev.sumv_stop()
    st = dev.sumv_wait_done(timeout=1.0)
    assert st is not None and st['active'] == 0, f'stop 之后仍在跑: {st}'
