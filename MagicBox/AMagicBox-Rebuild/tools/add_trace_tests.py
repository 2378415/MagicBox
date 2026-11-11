p="verification/regress/test_mouse_reports.py"
t=open(p,encoding="utf-8").read()
if "mx.rq" not in t:
    t += '''

# ---------------------------------------------------------------- step splitting
def reports(dev):
    """Read the report trace (mx.rq) as signed (dx, dy, wheel) tuples."""
    reply = dev.cmd('mx.rq')
    assert reply.startswith(b'km.') and reply.endswith(SUFFIX), reply
    body = reply[3:-len(SUFFIX)].decode()

    def s8(v):
        return v - 256 if v >= 128 else v

    out = []
    for i in range(0, len(body), 6):
        h = body[i:i + 6]
        out.append((s8(int(h[0:2], 16)), s8(int(h[2:4], 16)), s8(int(h[4:6], 16))))
    return out


def test_large_move_is_split_and_sums_exactly(harness):
    """300 px cannot fit one int8 report: ceil(300/127) = 3 steps."""
    settle(harness, '.km.move(300,0)', wait=0.4)
    tail = reports(harness)[-3:]
    assert sum(r[0] for r in tail) == 300
    assert all(abs(r[0]) <= 127 for r in tail)


def test_boundary_127_is_single_step(harness):
    settle(harness, '.km.move(127,0)')
    assert reports(harness)[-1][0] == 127


def test_boundary_128_is_two_steps(harness):
    settle(harness, '.km.move(128,0)')
    tail = reports(harness)[-2:]
    assert sum(r[0] for r in tail) == 128
    assert all(abs(r[0]) <= 127 for r in tail)


def test_two_axis_split_sums(harness):
    settle(harness, '.km.move(-260,130)', wait=0.4)
    tail = reports(harness)[-3:]
    assert sum(r[0] for r in tail) == -260
    assert sum(r[1] for r in tail) == 130
'''
    open(p,"w",encoding="utf-8").write(t)
print("trace tests added")
