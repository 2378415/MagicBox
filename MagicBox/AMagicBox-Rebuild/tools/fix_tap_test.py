p="verification/regress/test_hidden_opcodes.py"
t=open(p,encoding="utf-8").read()
t=t.replace('''    # 0x0F: tap with a delay window
    ("mx.0f 'a',1,5", b"'a',1,5"),''','''    # 0x0F: tap with a delay window.  The usage parser only accepts the 'c' form
    # when the *whole* argument ends with a quote, so the delay form has to use
    # the decimal usage id (that is what the original accepts as well).
    ('mx.0f 4,1,5', b'4,1,5'),''')
open(p,"w",encoding="utf-8").write(t)
print("test fixed")
