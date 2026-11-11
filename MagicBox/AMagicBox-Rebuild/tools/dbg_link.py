import serial, time, io, sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
s=serial.Serial("COM8",115200,timeout=0.2); s.reset_input_buffer()
def cmd(t,w=0.5):
    s.write(t.encode()+b"\r"); s.flush(); time.sleep(w); return s.read(s.in_waiting or 0)
print("ls   ->", cmd("mx.ls"))
print("lb   ->", cmd("mx.lb"))
print("ls   ->", cmd("mx.ls"))
print("dc1  ->", cmd("mx.dc 1"))
s.close()
