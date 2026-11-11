p="verification/regress/conftest.py"
t=open(p,encoding="utf-8").read()
if "CLEAR_COMMANDS" not in t:
    t=t.replace('''@pytest.fixture(scope='session')
def device_ready(device):
    """Sanity gate: the link must answer version before any other test runs."""
    reply = device.cmd('.km.version()')
    assert reply == b'km.MAKCU\\r\\n>>> ', f'unexpected version reply: {reply!r}'
    return device''','''# The CH343 port cannot reset the chip (no EN/IO0 wiring), so RAM state survives
# between runs.  Every state-touching command is cleared before the assertions
# that expect a fresh device: channel flags (0x00), axis bytes (0x02), buttons
# mode (0x0C) and the press/release slots (0x04).
CLEAR_COMMANDS = [
    '.km.lock_ml(0)', '.km.lock_mr(0)', '.km.lock_mm(0)',
    '.km.lock_ms1(0)', '.km.lock_ms2(0)',
    '.km.lock_mx(0)', '.km.lock_my(0)',
    '.km.buttons(0)',
    '.km.left(0)', '.km.right(0)', '.km.middle(0)',
    '.km.front(0)', '.km.ms1(0)', '.km.ms2(0)',
]


@pytest.fixture(scope='session')
def device_ready(device):
    """Sanity gate: the link must answer version, then known-zero state."""
    reply = device.cmd('.km.version()')
    assert reply == b'km.MAKCU\\r\\n>>> ', f'unexpected version reply: {reply!r}'
    for cmd in CLEAR_COMMANDS:
        device.cmd(cmd)
    return device''')
    open(p,"w",encoding="utf-8").write(t)
print("fixture clears state")
