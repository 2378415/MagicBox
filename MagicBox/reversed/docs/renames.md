# Semantic renames

Curated names applied to the reconstructed tree. `tools/symbol_names.py` is the
single source of truth; `tools/make_renames_doc.py` regenerates this file.
Each name is backed by the analysis in 官方固件命令协议.md,
官方固件未公开协议.md and `docs/reconstruction_patterns.md`.

## left (105)

| entry | original | new | reason |
|---|---|---|---|
| `0x40376788` | `FUN_40376788` | `clk_ticks_to_us` | cycle counter scaled by the timer ratio |
| `0x40378eb0` | `FUN_40378eb0` | `esp_random` | hardware RNG: XOR CCOUNT samples between calls |
| `0x4037ea60` | `FUN_4037ea60` | `xTaskCreatePinnedToCore` | assert core id then create the task |
| `0x4200dad8` | `FUN_4200dad8` | `frame_echo_hex` | unknown frame hex echo |
| `0x4200db04` | `FUN_4200db04` | `frame_router` | first-byte router: 0x2E text / 0xA1 ack / 0xA4 config / 0xA5 serial |
| `0x4200db8c` | `FUN_4200db8c` | `uart_rx_frame` | UART RX frame entry |
| `0x4200dba0` | `FUN_4200dba0` | `cmd_nop` | opcode 0x08 no-op handler |
| `0x4200dbb0` | `FUN_4200dbb0` | `cmd_dump_channels` | opcode 0x17 channel table dump |
| `0x4200dc18` | `FUN_4200dc18` | `cmd_reply_status` | small status reply helper |
| `0x4200dc6c` | `FUN_4200dc6c` | `cmd_version` | opcode 0x09 version query |
| `0x4200dc84` | `FUN_4200dc84` | `cmd_serial` | opcode 0x1A serial number query/spoof/reset |
| `0x4200ddbc` | `FUN_4200ddbc` | `cmd_buttons` | opcode 0x0C buttons() handler |
| `0x4200de40` | `FUN_4200de40` | `cmd_lock_query` | opcode 0x01 lock_m*() handler |
| `0x4200de60` | `FUN_4200de60` | `cmd_lock_axis` | opcode 0x03 lock_mx()/lock_my() |
| `0x4200de80` | `FUN_4200de80` | `cmd_set_string` | opcode 0x10 quoted string setter |
| `0x4200decc` | `FUN_4200decc` | `cmd_lock_param0` | opcode 0x00 lock_m*( handler |
| `0x4200df08` | `FUN_4200df08` | `cmd_lock_param2` | opcode 0x02 lock_mx(/lock_my( |
| `0x4200df30` | `FUN_4200df30` | `cmd_button_press` | opcode 0x04 left(..ms2( press/release |
| `0x4200df58` | `FUN_4200df58` | `cmd_catch_set` | opcode 0x0A catch_m*( handler |
| `0x4200dfac` | `FUN_4200dfac` | `cmd_button_click` | opcode 0x05 left()..ms2() click |
| `0x4200dff0` | `FUN_4200dff0` | `cmd_catch_query` | opcode 0x0B catch_m*() handler |
| `0x4200e024` | `FUN_4200e024` | `cmd_move` | opcode 0x06 move() handler |
| `0x4200e1b0` | `FUN_4200e1b0` | `cmd_silent` | opcode 0x19 silent( handler |
| `0x4200e358` | `FUN_4200e358` | `cmd_wheel` | opcode 0x07 wheel( handler |
| `0x4200e458` | `FUN_4200e458` | `parse_int_or_char` | value parser: 'c' or decimal |
| `0x4200e56c` | `FUN_4200e56c` | `cmd_channel_toggle` | opcode 0x18 channel flag write |
| `0x4200e624` | `FUN_4200e624` | `cmd_map_entry` | opcode 0x16 mapping table entry |
| `0x4200e670` | `FUN_4200e670` | `parse_list6` | comma list parser, max 6 values |
| `0x4200e6f0` | `FUN_4200e6f0` | `cmd_keys_down` | opcode 0x12 batch key down |
| `0x4200e718` | `FUN_4200e718` | `cmd_keys_up` | opcode 0x13 batch key up |
| `0x4200e740` | `FUN_4200e740` | `parse_range` | a,b range parser |
| `0x4200e998` | `FUN_4200e998` | `cmd_keys_combo` | opcode 0x14 combo press/release |
| `0x4200e9d0` | `FUN_4200e9d0` | `cmd_key_tap` | opcode 0x0F key tap with delay range |
| `0x4200ea04` | `FUN_4200ea04` | `cmd_map_16` | opcode 0x15 16-bit index mapping write |
| `0x4200eb1c` | `FUN_4200eb1c` | `cmd_key_up` | opcode 0x0E single key release |
| `0x4200ec48` | `FUN_4200ec48` | `cmd_key_down` | opcode 0x0D single key press |
| `0x4200ed74` | `FUN_4200ed74` | `cmd_key_state` | opcode 0x11 key state query |
| `0x4200eec4` | `FUN_4200eec4` | `cmd_lookup` | command table prefix matcher |
| `0x4200ef18` | `FUN_4200ef18` | `cmd_dispatch` | opcode jump-table dispatcher |
| `0x4200efec` | `FUN_4200efec` | `mouse_submit` | core relative-move submit |
| `0x4200f744` | `FUN_4200f744` | `mouse_submit_ext` | extended 5-arg move submit |
| `0x4200f83c` | `FUN_4200f83c` | `mouse_commit_init` | creates mouse commit task + timer |
| `0x4200f848` | `FUN_4200f848` | `mouse_commit_task` | mouse frame commit task body |
| `0x4200f873` | `FUN_4200f873` | `bezier_timer_cb` | bezier smoothing timer |
| `0x4200f8e4` | `FUN_4200f8e4` | `mouse_submit_default` | default submit wrapper |
| `0x4200f96c` | `FUN_4200f96c` | `wheel_submit` | wheel delta submit |
| `0x4200f9c4` | `FUN_4200f9c4` | `channel_slot_set` | write channel enable slot +0x54 (index 1..5) |
| `0x4200fa50` | `FUN_4200fa50` | `axis_slot_set` | write axis slot +0x9C (1..16) and wake commit task |
| `0x42010b60` | `FUN_42010b60` | `mouse_move_mode` | move with explicit mode |
| `0x42010b8c` | `FUN_42010b8c` | `lock_axis_set` | axis lock wrapper -> axis_slot_set |
| `0x42010ba8` | `FUN_42010ba8` | `lock_set` | button lock wrapper -> channel_slot_set |
| `0x42010bc4` | `FUN_42010bc4` | `mouse_move` | 2-arg move entry |
| `0x42010bec` | `FUN_42010bec` | `wheel_write` | wheel write wrapper |
| `0x42010c30` | `FUN_42010c30` | `version_get` | copy the "MAKCU" version string |
| `0x42010c44` | `FUN_42010c44` | `buttons_set` | write the buttons-mode flag |
| `0x42010c64` | `FUN_42010c64` | `buttons_get` | read the buttons-mode flag |
| `0x42010c84` | `FUN_42010c84` | `serial_read` | read a length-prefixed string over UART0 command 0x1A |
| `0x42010e70` | `FUN_42010e70` | `hid_key_down` | write key usage into HID report |
| `0x42010f00` | `FUN_42010f00` | `hid_key_up` | clear key usage in HID report |
| `0x42010f8c` | `FUN_42010f8c` | `hid_key_tap` | press, delay, release |
| `0x42010fdc` | `FUN_42010fdc` | `hid_type_string` | per-character tap loop |
| `0x4201100c` | `FUN_4201100c` | `hid_key_state_read` | read one usage state |
| `0x42011098` | `FUN_42011098` | `hid_keys_down` | batch key down |
| `0x420110b4` | `FUN_420110b4` | `hid_keys_up` | batch key up |
| `0x420110d0` | `FUN_420110d0` | `hid_keys_combo` | batch down, delay, batch up |
| `0x42011188` | `FUN_42011188` | `efuse_burn` | eFuse write entry |
| `0x420111a5` | `FUN_420111a5` | `efuse_burn_log` | eFuse write logging path |
| `0x42012a74` | `FUN_42012a74` | `led_init` | LED gpio init |
| `0x42012aeb` | `FUN_42012aeb` | `led_flash_task` | LED flash task |
| `0x42012b50` | `FUN_42012b50` | `crash_dump` | core dump handler |
| `0x420130a4` | `FUN_420130a4` | `config_load` | NVS config reader (storage/config/baud_rate) |
| `0x42013734` | `FUN_42013734` | `uart1_frame_parse` | parse a 5A/cnt/len frame, EP0 tunnel + 0xA2 path |
| `0x42013884` | `FUN_42013884` | `uart_events` | UART1 event loop |
| `0x420139e4` | `FUN_420139e4` | `uart_event_task` | uart event queue task |
| `0x42013ae2` | `FUN_42013ae2` | `hid_data_processing` | report descriptor processing |
| `0x42013af9` | `FUN_42013af9` | `hid_parse_task` | report descriptor parse task |
| `0x42013c58` | `FUN_42013c58` | `uart0_read_string` | read a line into a caller buffer, NUL-terminated |
| `0x4201423c` | `FUN_4201423c` | `serial_setup` | serial number assembly |
| `0x420142a0` | `FUN_420142a0` | `uart0_setup` | UART0 init + task creation |
| `0x42014369` | `FUN_42014369` | `uart0_send_task` | control port send task |
| `0x42014393` | `FUN_42014393` | `uart0_frame_consumer` | frame consumer task |
| `0x420143e8` | `FUN_420143e8` | `uart0_reply` | write a reply frame |
| `0x4201455c` | `FUN_4201455c` | `hid_data` | HID report buffer state |
| `0x420145b5` | `FUN_420145b5` | `hid_commit_frame` | commit one HID frame |
| `0x420152cc` | `FUN_420152cc` | `usb_hid_itf_reset` | reset one USB HID interface slot |
| `0x42016a78` | `FUN_42016a78` | `sem_create_counting` | xQueueCreateCountingSemaphore(1, n) |
| `0x4201ea4c` | `FUN_4201ea4c` | `__ieee754_cos` | fdlibm cos: rem_pio2 + k_sin/k_cos switch |
| `0x4201eac8` | `FUN_4201eac8` | `__ieee754_sin` | fdlibm sin: rem_pio2 + k_sin/k_cos switch |
| `0x4201eb48` | `FUN_4201eb48` | `__fixdfsi` | double -> int32 conversion helper |
| `0x4201ebe8` | `FUN_4201ebe8` | `__kernel_cos` | kd_cos: C1..C6 + 0.3 / 0.78125 thresholds |
| `0x4201ed60` | `FUN_4201ed60` | `__kernel_sin` | kd_sin: S1..S6 polynomial |
| `0x4201eecc` | `FUN_4201eecc` | `__ieee754_rem_pio2` | argument reduction, returns quadrant n |
| `0x4201f2d8` | `FUN_4201f2d8` | `__kernel_rem_pio2` | large-argument reduction kernel (2/pi table) |
| `0x4201fa38` | `FUN_4201fa38` | `__ieee754_floor` | fdlibm floor: integral fast path, then mantissa mask |
| `0x4201fb6c` | `FUN_4201fb6c` | `__ieee754_scalbn` | add n to the exponent, clamp on over/underflow |
| `0x4202d1ac` | `FUN_4202d1ac` | `catch_set` | write catch enable slot +0x168 |
| `0x4202d1c8` | `FUN_4202d1c8` | `lock_status_get` | 24-bit status bitmask: channel/lock/catch |
| `0x4202d240` | `FUN_4202d240` | `lock_axis_get` | axis lock flag for lock_mx()/lock_my() |
| `0x4202d26c` | `FUN_4202d26c` | `button_flags_get` | per-button catch/lock flags |
| `0x4202d2a0` | `FUN_4202d2a0` | `char_to_usage` | map 'c' to HID usage id |
| `0x4202d4a8` | `FUN_4202d4a8` | `map_entry_write16` | write 16-bit indexed entry |
| `0x4202d4dc` | `FUN_4202d4dc` | `map_entry_write` | write mapping table entry |
| `0x4202d57c` | `FUN_4202d57c` | `hid_report_get_bits` | read a bit field from a HID report |
| `0x4202d5c4` | `FUN_4202d5c4` | `hid_report_set_bits` | write a bit field in a HID report |
| `0x4202d980` | `FUN_4202d980` | `nop_stub` | empty 5-byte stub |

## right (16)

| entry | original | new | reason |
|---|---|---|---|
| `0x42001198` | `FUN_42001198` | `led_init` | LED init |
| `0x4200d3e4` | `FUN_4200d3e4` | `usb_xfer_submit` | submit the transfer/URB filled by the caller (pipe, buffer, callback checks) |
| `0x4200f208` | `FUN_4200f208` | `usb_devices_list` | USB device inventory |
| `0x4200f6a1` | `FUN_4200f6a1` | `uart_event_task` | UART event task |
| `0x4200f6b0` | `FUN_4200f6b0` | `uart1_write` | uart_write_bytes(UART_NUM_1, ...) |
| `0x4200f6c4` | `FUN_4200f6c4` | `frame_forward` | rewrite header and forward a frame |
| `0x4200fac0` | `FUN_4200fac0` | `frame_ep0_dir` | set 0xA0 payload length=1 and direction |
| `0x4200fae0` | `FUN_4200fae0` | `frame_a3_flag` | set 0xA3 payload length=1 and flag=0 |
| `0x4200fe68` | `FUN_4200fe68` | `hid_uart_task` | dequeue frame, send over UART1 |
| `0x4200fec8` | `FUN_4200fec8` | `queue_drain` | drain one bridge queue when full |
| `0x4200ff10` | `FUN_4200ff10` | `usb_event_handler` | USB client event callback; builds 0xA2 frames |
| `0x420100fc` | `FUN_420100fc` | `bridge_init` | creates 8 queues, 8x8 buffers and 8 hid_uart tasks |
| `0x42010184` | `FUN_42010184` | `hid_uart_bridge` | HID to UART bridge |
| `0x42010244` | `FUN_42010244` | `bridge_release` | reset one bridge slot/queue |
| `0x420102a8` | `FUN_420102a8` | `frame_build_ep0` | build 5A A0 01 <dir> frame |
| `0x42010397` | `FUN_42010397` | `led_task` | LED task |
