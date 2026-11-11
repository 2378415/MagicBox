import serial, time, io, sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
s=serial.Serial("COM8",115200,timeout=0.2)
s.dtr=False; s.rts=True; time.sleep(0.05); s.dtr=True; s.rts=False
time.sleep(1.5)
print("boot log (2s):", s.read(s.in_waiting or 0)[:600])
s.write(b".km.version()\r"); s.flush(); time.sleep(0.5)
print("version:", s.read(s.in_waiting or 0))
s.close()
