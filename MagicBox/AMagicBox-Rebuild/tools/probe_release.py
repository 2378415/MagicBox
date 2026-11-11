"""Release the CH343 reset lines, give the app time to boot, then probe again."""
import io
import sys
import time

import serial

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')
port = sys.argv[1] if len(sys.argv) > 1 else 'COM8'

s = serial.Serial(port, 115200, timeout=0.1)
s.dtr = False
s.rts = False
time.sleep(3.0)
s.reset_input_buffer()
for _ in range(2):
    s.write(b'.km.version()\r')
    s.flush()
    time.sleep(0.8)
    print('released ->', s.read(s.in_waiting or 0))

s.dtr = False
s.rts = True
time.sleep(0.05)
s.dtr = True
s.rts = False
time.sleep(1.5)
s.reset_input_buffer()
s.write(b'.km.version()\r')
s.flush()
time.sleep(0.8)
print('after documented pulse ->', s.read(s.in_waiting or 0))
s.close()
