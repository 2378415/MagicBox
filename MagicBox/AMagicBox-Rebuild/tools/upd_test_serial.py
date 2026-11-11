p="verification/regress/test_protocol.py"
t=open(p,encoding="utf-8").read()
t=t.replace("""    body = reply[3:-len(SUFFIX)]
    assert body in (b'Mouse does not have a serial number', b'')""",
"""    body = reply[3:-len(SUFFIX)]
    # measured on the original device: the literal at 0x3C036520 is 0x24 bytes
    # *including* its trailing NUL, and the trailing newline is part of the body
    assert body in (b'Mouse does not have a serial number\\n',
                    b'Mouse does not have a serial number\\n\\x00', b'')""")
open(p,"w",encoding="utf-8").write(t)
print("test updated")
