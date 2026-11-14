"""Ad-hoc trace probe: send a move and dump the mx.rq ring."""
import io
import sys
import time

import serial

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
port = sys.argv[1] if len(sys.argv) > 1 else 'COM8'

s = serial.Serial(port, 115200, timeout=0.2)
s.reset_input_buffer()


def cmd(text, wait=0.6):
    s.write(text.encode() + b'\r')
    s.flush()
    time.sleep(wait)
    return s.read(s.in_waiting or 0)


def signed(v):
    return v - 256 if v >= 128 else v


def dump(reply):
    body = reply.split(b'km.', 1)[-1].split(b'\r\n>>> ', 1)[0].decode(errors='replace')
    out = []
    for i in range(0, len(body), 6):
        h = body[i:i + 6]
        if len(h) < 6:
            break
        out.append(tuple(signed(int(h[j:j + 2], 16)) for j in (0, 2, 4)))
    return out


for movecmd in ('.km.move(-260,130)', '.km.move(300,0)', '.km.move(127,0)', '.km.move(128,0)'):
    print(movecmd, '->', cmd(movecmd).decode(errors='replace').strip())
    print('   trace:', dump(cmd('mx.rq')))

s.close()
