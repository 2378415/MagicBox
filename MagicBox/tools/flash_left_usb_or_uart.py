"""刷左片：优先走 USB-OTG 下载器（COM4，能自己 hard-reset 启动），否则退回 UART0。

为什么两套：`mx.dl` 置 RTC 强制下载位后，ROM 有可能只枚举 UART0（COM3）而不枚举 USB；
USB 那条路 `--after hard-reset` 能经 RTS 复位启动，UART0 那条（CH343 的 RTS 没接 EN）
写完只能靠拔插电源。
"""
import os
import re
import subprocess
import sys
import time

import serial

PY = r"D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe"
UART_PORT = "COM3"
BIN = r"D:\GitHub\MagicBox\MagicBox\app_left\build\makcu_left.bin"


def ports():
    from serial.tools import list_ports
    return {p.device: p for p in list_ports.comports()}


def vidpid(port):
    info = ports().get(port)
    return (info.vid, info.pid) if info else (None, None)


def ping(port=UART_PORT, baud=921600, timeout=0.35):
    try:
        s = serial.Serial(port, baud, timeout=0.4)
        s.dtr = False
        s.rts = False
        time.sleep(0.25)
        s.reset_input_buffer()
        s.write(b".km.version()\r")
        s.flush()
        time.sleep(timeout)
        n = s.in_waiting
        r = s.read(n) if n else b""
        s.close()
        return r
    except Exception:
        return b""


def send_dl():
    s = serial.Serial(UART_PORT, 921600, timeout=0.5)
    s.dtr = False
    s.rts = False
    time.sleep(0.3)
    s.write(b"mx.dl\r")
    s.flush()
    time.sleep(0.6)
    r = s.read(32) if s.in_waiting else b""
    s.close()
    return r


def esptool(*args):
    cmd = [PY, "-m", "esptool", "--chip", "esp32s3"] + list(args)
    p = subprocess.run(cmd, capture_output=True, text=True)
    lines = [l for l in (p.stdout + p.stderr).splitlines()
             if re.search(r"Wrote|verified|error|Error|Hard resetting|Stub|MAC:", l)]
    return p.returncode, lines


def find_usb_downloader(wait_s=12.0):
    t0 = time.time()
    while time.time() - t0 < wait_s:
        for dev, info in ports().items():
            if info.vid == 0x303A and info.pid == 0x0009:
                return dev
        time.sleep(0.4)
    return None


def main():
    if b"MAKCU" not in ping():
        print("控制口无响应，先确认盒子在跑（需要拔插一次）")
        return 1
    print("mx.dl:", send_dl()[:12])
    usb = find_usb_downloader()
    if usb:
        print(f"USB 下载器: {usb}")
        rc, out = esptool("--port", usb, "--baud", "921600", "--before", "no-reset",
                          "--after", "hard-reset", "write-flash", "0x10000", BIN)
        print("\n".join(out))
        if rc != 0:
            return 1
    else:
        print("USB 下载器没出现 → 退回 UART0（写完需要拔插一次电源）")
        time.sleep(1.5)
        rc, out = esptool("--port", UART_PORT, "--baud", "460800", "--before", "no-reset",
                          "--after", "no-reset", "write-flash", "0x10000", BIN)
        print("\n".join(out))
        if rc != 0:
            return 1
        print("NEED_REPLUG")
        return 2
    for i in range(40):
        time.sleep(1.5)
        if b"MAKCU" in ping():
            print(f"app 已回来（{(i+1)*1.5:.0f}s）")
            return 0
    print("写完但控制口没回来")
    return 3


if __name__ == "__main__":
    sys.exit(main())
