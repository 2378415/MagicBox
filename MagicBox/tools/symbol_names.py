"""Curated semantic names for reconstructed MAKCU functions.

Only functions whose role was established by the earlier analysis passes are
listed. Everything else keeps its `FUN_<address>` identity.
"""

LEFT = {
    # --- protocol dispatcher -------------------------------------------------
    '4200eec4': ('cmd_lookup', 'command table prefix matcher'),
    '4200ef18': ('cmd_dispatch', 'opcode jump-table dispatcher'),
    '4200dba0': ('cmd_nop', 'opcode 0x08 no-op handler'),
    '4200dbb0': ('cmd_dump_channels', 'opcode 0x17 channel table dump'),
    '4200dc18': ('cmd_reply_status', 'small status reply helper'),
    '4200dc6c': ('cmd_version', 'opcode 0x09 version query'),
    '4200ddbc': ('cmd_buttons', 'opcode 0x0C buttons() handler'),
    '4200de40': ('cmd_lock_query', 'opcode 0x01 lock_m*() handler'),
    '4200de60': ('cmd_lock_axis', 'opcode 0x03 lock_mx()/lock_my()'),
    '4200de80': ('cmd_set_string', 'opcode 0x10 quoted string setter'),
    '4200decc': ('cmd_lock_param0', 'opcode 0x00 lock_m*( handler'),
    '4200df08': ('cmd_lock_param2', 'opcode 0x02 lock_mx(/lock_my('),
    '4200df30': ('cmd_button_press', 'opcode 0x04 left(..ms2( press/release'),
    '4200df58': ('cmd_catch_set', 'opcode 0x0A catch_m*( handler'),
    '4200dfac': ('cmd_button_click', 'opcode 0x05 left()..ms2() click'),
    '4200dff0': ('cmd_catch_query', 'opcode 0x0B catch_m*() handler'),
    '4200e024': ('cmd_move', 'opcode 0x06 move() handler'),
    '4200e1b0': ('cmd_silent', 'opcode 0x19 silent( handler'),
    '4200e358': ('cmd_wheel', 'opcode 0x07 wheel( handler'),
    '4200e56c': ('cmd_channel_toggle', 'opcode 0x18 channel flag write'),
    '4200e624': ('cmd_map_entry', 'opcode 0x16 mapping table entry'),
    '4200dc84': ('cmd_serial', 'opcode 0x1A serial number query/spoof/reset'),
    '4200e6f0': ('cmd_keys_down', 'opcode 0x12 batch key down'),
    '4200e718': ('cmd_keys_up', 'opcode 0x13 batch key up'),
    '4200e998': ('cmd_keys_combo', 'opcode 0x14 combo press/release'),
    '4200e9d0': ('cmd_key_tap', 'opcode 0x0F key tap with delay range'),
    '4200ea04': ('cmd_map_16', 'opcode 0x15 16-bit index mapping write'),
    '4200eb1c': ('cmd_key_up', 'opcode 0x0E single key release'),
    '4200ec48': ('cmd_key_down', 'opcode 0x0D single key press'),
    '4200ed74': ('cmd_key_state', 'opcode 0x11 key state query'),
    # --- argument parsing ----------------------------------------------------
    '4200e458': ('parse_int_or_char', "value parser: 'c' or decimal"),
    '4200e670': ('parse_list6', 'comma list parser, max 6 values'),
    '4200e740': ('parse_range', 'a,b range parser'),
    # --- mouse ---------------------------------------------------------------
    '4200f83c': ('mouse_commit_init', 'creates mouse commit task + timer'),
    '4200f848': ('mouse_commit_task', 'mouse frame commit task body'),
    '4200f873': ('bezier_timer_cb', 'bezier smoothing timer'),
    '4200f8e4': ('mouse_submit_default', 'default submit wrapper'),
    '4200efec': ('mouse_submit', 'core relative-move submit'),
    '4200f744': ('mouse_submit_ext', 'extended 5-arg move submit'),
    '4200f96c': ('wheel_submit', 'wheel delta submit'),
    '42010bc4': ('mouse_move', '2-arg move entry'),
    '42010b60': ('mouse_move_mode', 'move with explicit mode'),
    '42010bec': ('wheel_write', 'wheel write wrapper'),
    # --- HID keyboard --------------------------------------------------------
    '42010e70': ('hid_key_down', 'write key usage into HID report'),
    '42010f00': ('hid_key_up', 'clear key usage in HID report'),
    '42010f8c': ('hid_key_tap', 'press, delay, release'),
    '42010fdc': ('hid_type_string', 'per-character tap loop'),
    '42011098': ('hid_keys_down', 'batch key down'),
    '420110b4': ('hid_keys_up', 'batch key up'),
    '420110d0': ('hid_keys_combo', 'batch down, delay, batch up'),
    '4201100c': ('hid_key_state_read', 'read one usage state'),
    '4202d2a0': ('char_to_usage', "map 'c' to HID usage id"),
    '4202d4dc': ('map_entry_write', 'write mapping table entry'),
    '4202d4a8': ('map_entry_write16', 'write 16-bit indexed entry'),
    '4202d1ac': ('catch_set', 'write catch enable slot +0x168'),
    '4202d1c8': ('lock_status_get', '24-bit status bitmask: channel/lock/catch'),
    '4202d240': ('lock_axis_get', 'axis lock flag for lock_mx()/lock_my()'),
    '4202d26c': ('button_flags_get', 'per-button catch/lock flags'),
    # --- lock / channel slot writers ----------------------------------------
    '4200f9c4': ('channel_slot_set', 'write channel enable slot +0x54 (index 1..5)'),
    '4200fa50': ('axis_slot_set', 'write axis slot +0x9C (1..16) and wake commit task'),
    '42010b8c': ('lock_axis_set', 'axis lock wrapper -> axis_slot_set'),
    '42010ba8': ('lock_set', 'button lock wrapper -> channel_slot_set'),
    '42010c30': ('version_get', 'copy the "MAKCU" version string'),
    '42010c44': ('buttons_set', 'write the buttons-mode flag'),
    '42010c64': ('buttons_get', 'read the buttons-mode flag'),
    '42010c84': ('serial_read', 'read a length-prefixed string over UART0 command 0x1A'),
    '42013c58': ('uart0_read_string', 'read a line into a caller buffer, NUL-terminated'),
    '4202d980': ('nop_stub', 'empty 5-byte stub'),
    # --- vendor soft-float helpers ------------------------------------------
    # Identified by matching their literal-pool doubles against the fdlibm /
    # libgcc coefficient sets (see tools/dump_consts.py and report §14):
    #   4201EBE8 -> k_cos  C1..C6 (0x3FA555555555554C ... 0xBDA8FAE9BE8838D4)
    #   4201ED60 -> k_sin  S1..S6 (0x3FC5555555555549 ... 0x3DE5D93A5ACFD57C)
    #   4201EEcc -> rem_pio2 (2/pi = 0.6366197723675814, returns quadrant n)
    '4201ea4c': ('__ieee754_cos', 'fdlibm cos: rem_pio2 + k_sin/k_cos switch'),
    '4201eac8': ('__ieee754_sin', 'fdlibm sin: rem_pio2 + k_sin/k_cos switch'),
    '4201eb48': ('__fixdfsi', 'double -> int32 conversion helper'),
    '4201ebe8': ('__kernel_cos', 'kd_cos: C1..C6 + 0.3 / 0.78125 thresholds'),
    '4201ed60': ('__kernel_sin', 'kd_sin: S1..S6 polynomial'),
    '4201eecc': ('__ieee754_rem_pio2', 'argument reduction, returns quadrant n'),
    '4201f2d8': ('__kernel_rem_pio2', 'large-argument reduction kernel (2/pi table)'),
    '4201fa38': ('__ieee754_floor', 'fdlibm floor: integral fast path, then mantissa mask'),
    '4201fb6c': ('__ieee754_scalbn', 'add n to the exponent, clamp on over/underflow'),
    # --- IDF helpers named from their call sites ---------------------------
    '40376788': ('clk_ticks_to_us', 'cycle counter scaled by the timer ratio'),
    '40378eb0': ('esp_random', 'hardware RNG: XOR CCOUNT samples between calls'),
    '4037ea60': ('xTaskCreatePinnedToCore', 'assert core id then create the task'),
    '420152cc': ('usb_hid_itf_reset', 'reset one USB HID interface slot'),
    '42016a78': ('sem_create_counting', 'xQueueCreateCountingSemaphore(1, n)'),
    # --- UART / protocol I/O -------------------------------------------------
    '420142a0': ('uart0_setup', 'UART0 init + task creation'),
    '4201423c': ('serial_setup', 'serial number assembly'),
    '42014369': ('uart0_send_task', 'control port send task'),
    '42014393': ('uart0_frame_consumer', 'frame consumer task'),
    '420143e8': ('uart0_reply', 'write a reply frame'),
    '420139e4': ('uart_event_task', 'uart event queue task'),
    # --- HID device side -----------------------------------------------------
    '4201455c': ('hid_data', 'HID report buffer state'),
    '420145b5': ('hid_commit_frame', 'commit one HID frame'),
    '42013ae2': ('hid_data_processing', 'report descriptor processing'),
    '42013af9': ('hid_parse_task', 'report descriptor parse task'),
    # --- misc hardware -------------------------------------------------------
    '42012a74': ('led_init', 'LED gpio init'),
    '42012aeb': ('led_flash_task', 'LED flash task'),
    '42011188': ('efuse_burn', 'eFuse write entry'),
    '420111a5': ('efuse_burn_log', 'eFuse write logging path'),
    '42012b50': ('crash_dump', 'core dump handler'),
    # --- binary frame layer (discovered while naming the leftovers) ----------
    '4200db04': ('frame_router', 'first-byte router: 0x2E text / 0xA1 ack / 0xA4 config / 0xA5 serial'),
    '4200db8c': ('uart_rx_frame', 'UART RX frame entry'),
    '4200dad8': ('frame_echo_hex', 'unknown frame hex echo'),
    '420130a4': ('config_load', 'NVS config reader (storage/config/baud_rate)'),
    # --- HID report bit-field helpers ---------------------------------------
    '4202d57c': ('hid_report_get_bits', 'read a bit field from a HID report'),
    '4202d5c4': ('hid_report_set_bits', 'write a bit field in a HID report'),
    # --- inter-chip UART1 link (from the frame-format analysis) --------------
    '42013734': ('uart1_frame_parse', 'parse a 5A/cnt/len frame, EP0 tunnel + 0xA2 path'),
    '42013884': ('uart_events', 'UART1 event loop'),
}

RIGHT = {
    '4200f208': ('usb_devices_list', 'USB device inventory'),
    '42010184': ('hid_uart_bridge', 'HID to UART bridge'),
    '4200f6a1': ('uart_event_task', 'UART event task'),
    '42001198': ('led_init', 'LED init'),
    '42010397': ('led_task', 'LED task'),
    '420100fc': ('bridge_init', 'creates 8 queues, 8x8 buffers and 8 hid_uart tasks'),
    '420102a8': ('frame_build_ep0', 'build 5A A0 01 <dir> frame'),
    '4200f6c4': ('frame_forward', 'rewrite header and forward a frame'),
    '4200fac0': ('frame_ep0_dir', 'set 0xA0 payload length=1 and direction'),
    '4200fae0': ('frame_a3_flag', 'set 0xA3 payload length=1 and flag=0'),
    '4200f6b0': ('uart1_write', 'uart_write_bytes(UART_NUM_1, ...)'),
    '4200fe68': ('hid_uart_task', 'dequeue frame, send over UART1'),
    '42010244': ('bridge_release', 'reset one bridge slot/queue'),
    '4200ff10': ('usb_event_handler', 'USB client event callback; builds 0xA2 frames'),
    '4200fec8': ('queue_drain', 'drain one bridge queue when full'),
    '4200d3e4': ('usb_xfer_submit', 'submit the transfer/URB filled by the caller (pipe, buffer, callback checks)'),
}


def all_names():
    return {'left': LEFT, 'right': RIGHT}


def reason(side, addr):
    d = LEFT if side == 'left' else RIGHT
    return d.get(addr, (None, None))
