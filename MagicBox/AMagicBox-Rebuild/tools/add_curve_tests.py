p="verification/regress/test_mouse_reports.py"
t=open(p,encoding="utf-8").read()
if "test_curved_path_bows" not in t:
    t += '''

def test_curved_path_bows(harness):
    """A long move must follow the sampled curve, not a straight line: the path
    either bows (dy != 0 somewhere) or the random offset happened to be zero.
    The offset range is span/8, so a zero offset is a ~0.7% chance; 8 tries make
    the check robust while still proving the curve exists."""
    bowed = False
    for _ in range(8):
        settle(harness, '.km.move(600,0)', wait=0.5)
        tail = reports(harness)[-5:]              # ceil(600/127) = 5 steps
        assert sum(r[0] for r in tail) == 600
        assert all(abs(r[0]) <= 127 for r in tail)
        if any(r[1] != 0 for r in tail):
            bowed = True
    assert bowed


def test_bow_is_bounded(harness):
    """The perpendicular excursion stays within the documented span/8 control
    offset: with 5 steps the largest |dy| step cannot exceed span/8."""
    settle(harness, '.km.move(600,0)', wait=0.5)
    tail = reports(harness)[-5:]
    assert all(abs(r[1]) <= 600 // 8 + 8 for r in tail)
    assert sum(r[0] for r in tail) == 600
'''
    open(p,"w",encoding="utf-8").write(t)
print("curve tests added")
