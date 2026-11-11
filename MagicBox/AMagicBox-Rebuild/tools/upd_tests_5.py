p="verification/regress/test_hidden_opcodes.py"
t=open(p,encoding="utf-8").read()
if "mx.17" not in t:
    t=t.replace('''    # 0x14: combo with delays
    ("mx.14 'a',1,2", b"'a',1,2"),''','''    # 0x14: combo with delays
    ("mx.14 'a',1,2", b"'a',1,2"),
    # 0x15 / 0x16: mapping-table writes (both echo when the parse succeeds)
    ('mx.15 3,1', b'3,1'),
    ('mx.16 3,1', b'3,1'),
    # 0x18: channel toggle - idx 0 is not "present" on a fresh device -> echo
    ('mx.18 0,1', b'0,1'),''')
    t=t.replace('''@pytest.mark.parametrize('sent', [
    'mx.0d',        # empty argument -> silent
    'mx.10',        # set_string needs quotes -> silent
    'mx.1a',        # serial without arguments still answers the failure text
])''','''@pytest.mark.parametrize('sent', [
    'mx.0d',        # empty argument -> silent
    'mx.10',        # set_string needs quotes -> silent
    'mx.16 0,1',    # map_entry: first value 0 -> silent (0x4200E65A)
    'mx.1a',        # serial without arguments still answers the failure text
])''')
    t=t.replace('''def test_hidden_key_state(harness):''','''def test_hidden_dump_channels(harness):
    """0x17 on a fresh device: no entry has all three flags -> literal "0"."""
    assert harness.cmd('mx.17') == expect(b'0')


def test_hidden_key_state(harness):''')
    open(p,"w",encoding="utf-8").write(t)

p="verification/regress/test_protocol.py"
t=open(p,encoding="utf-8").read()
if "wheel(120)" not in t:
    t=t.replace("""    # cmd_catch_set (0x0A) - echo; channel not enabled on a fresh device
    ('.km.catch_ml(1)', b'catch_ml(1)'),""","""    # cmd_catch_set (0x0A) - echo; channel not enabled on a fresh device
    ('.km.catch_ml(1)', b'catch_ml(1)'),
    # cmd_wheel (0x07) answers even with an empty argument
    ('.km.wheel(120)', b'wheel(120)'),
    ('.km.wheel()', b'wheel()'),""")
    open(p,"w",encoding="utf-8").write(t)
print("tests extended")
