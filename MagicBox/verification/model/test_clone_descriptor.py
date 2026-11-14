"""Reference model for the cloned USB descriptors (mirrors makcu_clone.c).

The clone identity is handed to the host as raw bytes, so one misplaced byte
breaks the whole descriptor chain: the host walks bLength from descriptor to
descriptor, and a wrong length either hides the endpoint or leaves a zero-length
entry behind.  That is exactly what happened on the bench - `build_config()`
emitted a 10-byte HID descriptor while `wTotalLength` still said 34, so the host
saw `bLength=0` at offset 27, never found the interrupt endpoint, and failed
`URB_SELECT_CONFIGURATION` with `USBD_STATUS_INVALID_PARAMETER` (0x80000300).
Windows reported it as "Problem 10: this device cannot start" and the firmware
kept `tud_mount_cb` unset (`mx.dv` -> `mnt=0`).

Layout this model pins down:

    config 9 | interface 9 | HID 9 | endpoint 7  =  34 = wTotalLength

Run:  python -m pytest verification/model -q
"""

CONFIG_TOTAL = 9 + 9 + 9 + 7
REPORT_4B = bytes([
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x03, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x03, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01, 0x75, 0x05,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38,
    0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x03, 0x81, 0x06,
    0xC0, 0xC0,
])


def build_device(vid: int, pid: int) -> bytes:
    b = bytearray(18)
    b[0] = 18
    b[1] = 0x01
    b[2] = 0x00
    b[3] = 0x02                      # bcdUSB 2.00
    b[4] = b[5] = b[6] = 0           # class/subclass/protocol: per-interface
    b[7] = 64                        # bMaxPacketSize0
    b[8] = vid & 0xFF
    b[9] = (vid >> 8) & 0xFF
    b[10] = pid & 0xFF
    b[11] = (pid >> 8) & 0xFF
    b[12] = 0x00                     # bcdDevice 1.00
    b[13] = 0x01
    b[14], b[15], b[16] = 1, 2, 3    # iManufacturer / iProduct / iSerial
    b[17] = 1                        # bNumConfigurations
    return bytes(b)


def build_config(report_len: int) -> bytes:
    out = bytearray()
    # configuration: bLength, type, wTotalLength, bNumInterfaces, bConfigValue,
    # iConfiguration, bmAttributes, bMaxPower
    out += bytes([9, 0x02, CONFIG_TOTAL & 0xFF, CONFIG_TOTAL >> 8,
                  1, 1, 0, 0xA0, 50])
    # interface: HID class, boot subclass, mouse protocol, 1 endpoint, iInterface 0
    out += bytes([9, 0x04, 0, 0, 1, 0x03, 0x01, 0x02, 0])
    # HID descriptor: bcdHID 1.11, country 0, one report descriptor, its length
    out += bytes([9, 0x21, 0x11, 0x01, 0x00, 0x01, 0x22,
                  report_len & 0xFF, report_len >> 8])
    # endpoint: EP1 IN, interrupt, 64-byte packets, 1 ms
    out += bytes([7, 0x05, 0x81, 0x03, 64, 0, 1])
    return bytes(out)


def walk(blob: bytes):
    """Walk a configuration descriptor the way the host does."""
    chain, i = [], 0
    while i < len(blob):
        ln = blob[i]
        ty = blob[i + 1] if i + 1 < len(blob) else None
        if ln == 0:
            chain.append((i, 0, ty))
            break
        chain.append((i, ln, ty))
        i += ln
    return chain


def test_config_length_matches_wtotal():
    cfg = build_config(len(REPORT_4B))
    assert len(cfg) == CONFIG_TOTAL
    assert cfg[2] | (cfg[3] << 8) == len(cfg)


def test_chain_walks_cleanly():
    cfg = build_config(len(REPORT_4B))
    chain = walk(cfg)
    assert chain == [(0, 9, 0x02), (9, 9, 0x04), (18, 9, 0x21), (27, 7, 0x05)]
    assert chain[-1][0] + chain[-1][1] == len(cfg)


def test_hid_declares_the_real_report_length():
    cfg = build_config(len(REPORT_4B))
    hid = cfg[18:27]
    assert hid[0] == 9 and hid[1] == 0x21
    assert hid[5] == 1                        # bNumDescriptors
    assert hid[6] == 0x22                     # report descriptor
    assert hid[7] | (hid[8] << 8) == len(REPORT_4B) == 52


def test_endpoint_is_complete():
    cfg = build_config(len(REPORT_4B))
    ep = cfg[27:]
    assert list(ep) == [7, 0x05, 0x81, 0x03, 64, 0, 1]


def test_device_descriptor_is_consistent():
    dev = build_device(0x046D, 0xC077)
    assert len(dev) == 18 and dev[0] == 18 and dev[1] == 0x01
    assert dev[7] == 64                       # must match CFG_TUD_ENDPOINT0_SIZE
    assert (dev[8] | (dev[9] << 8), dev[10] | (dev[11] << 8)) == (0x046D, 0xC077)


def test_regression_ten_byte_hid_descriptor_is_caught():
    """The bug that broke enumeration: one extra 0x00 inside the HID descriptor
    (right after bcdHID) shifts the endpoint out of the declared wTotalLength."""
    broken = bytearray(build_config(len(REPORT_4B)))
    broken[22:22] = b"\x00"                   # what build_config() used to emit
    del broken[-1]                            # ...and the host truncates to wTotalLength
    chain = walk(bytes(broken))
    assert chain[-1] == (27, 0, 0x07)          # zero-length descriptor at 27
    assert [t for _, _, t in chain] != [0x02, 0x04, 0x21, 0x05]
