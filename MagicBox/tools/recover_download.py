"""Send the bench recovery command and wait for the ROM downloader to appear.

The HID build has no CDC console on the native USB port, so the only way back is
the `mx.dl` harness command (sets RTC_CNTL_FORCE_DOWNLOAD_BOOT and restarts).
After that the ROM enumerates USB-Serial-JTAG again and esptool can flash.

    python tools/recover_download.py --port COM8
"""
import argparse
import sys
import time

import serial


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', default='COM8')
    a = ap.parse_args()

    try:
        with serial.Serial(a.port, 115200, timeout=0.2) as sp:
            sp.write(b'mx.dl\r')
            sp.flush()
            time.sleep(0.3)
    except Exception as exc:
        print('control port write failed:', exc)

    print('waiting for the ROM downloader port ...')
    for i in range(20):
        time.sleep(1)
        try:
            with serial.Serial(a.port, 115200, timeout=0.1):
                pass
        except Exception:
            pass
        import serial.tools.list_ports as lp
        ports = [p.device for p in lp.comports()]
        print(f'  {i + 1:2d}s ports={ports}')
        if any(p != a.port for p in ports):
            print('download port appeared')
            return 0
    print('no new port appeared - the device may need BOOT+RESET')
    return 1


if __name__ == '__main__':
    sys.exit(main())
