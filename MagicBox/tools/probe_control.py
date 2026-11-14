"""Probe the CH343 control port with different reset timings (bring-up helper)."""
import io
import sys
import time

import serial

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')


def probe(tag, wait, pulse=True, port='COM8'):
    try:
        s = serial.Serial(port, 115200, timeout=0.1)
    except Exception as exc:
        print(tag, 'open fail', exc)
        return
    with s:
        if pulse:
            s.dtr = False
            s.rts = True
            time.sleep(0.1)
            s.dtr = True
            s.rts = False
        time.sleep(wait)
        s.reset_input_buffer()
        for cmd in ('.km.version()', '.km.buttons()', '.km.move(10,5)'):
            s.write(cmd.encode() + b'\r')
            s.flush()
            time.sleep(0.6)
            data = s.read(s.in_waiting or 0)
            print(f'{tag} {cmd!r} -> {data!r}')


if __name__ == '__main__':
    port = sys.argv[1] if len(sys.argv) > 1 else 'COM8'
    for tag, wait, pulse in (('pulse+2.0s', 2.0, True),
                             ('pulse+0.5s', 0.5, True),
                             ('no-pulse', 0.5, False)):
        probe(tag, wait, pulse, port)
