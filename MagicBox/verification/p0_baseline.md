# P0 baseline - rebuilt handlers vs the official V3.2 image

- image: `V3.2_LEFT.bin`
- elf:   `app_left\build\makcu_left.elf`
- threshold: ratio >= 0.7

| metric | value |
|---|---|
| handlers scored | 27 |
| structurally equivalent | **0 (0.0%)** |
| close (ratio >= 0.5) | 7 (25.9%) |
| mean similarity ratio | 0.3566 |
| instruction-count parity (<=25%) | 8 (29.6%) |
| bucket 0x101-0x200 | 0/6 equivalent, mean 0.3259 |
| bucket 0x41-0x100 | 0/7 equivalent, mean 0.3043 |
| bucket <=0x40 | 0/11 equivalent, mean 0.4085 |
| bucket >0x200 | 0/3 equivalent, mean 0.35 |

| op | handler | addr | orig insn | ours | ratio(win) | ratio(full) | verdict |
|---|---|---|---|---|---|---|---|
| 0x00 | `cmd_lock_param0` | 0x4200decc | 23 | 30 | 0.49 | 0.49 | diverged |
| 0x01 | `cmd_lock_query` | 0x4200de40 | 13 | 16 | 0.34 | 0.34 | diverged |
| 0x02 | `cmd_lock_param2` | 0x4200df08 | 14 | 18 | 0.50 | 0.50 | diverged |
| 0x03 | `cmd_lock_axis` | 0x4200de60 | 12 | 15 | 0.30 | 0.30 | diverged |
| 0x04 | `cmd_button_press` | 0x4200df30 | 14 | 18 | 0.50 | 0.50 | diverged |
| 0x05 | `cmd_button_click` | 0x4200dfac | 27 | 30 | 0.39 | 0.39 | diverged |
| 0x06 | `cmd_move` | 0x4200e024 | 149 | 41 | 0.20 | 0.08 | diverged |
| 0x07 | `cmd_wheel` | 0x4200e358 | 197 | 14 | 0.21 | 0.04 | diverged |
| 0x08 | `cmd_nop` | 0x4200dba0 | 6 | 5 | 0.20 | 0.18 | diverged |
| 0x09 | `cmd_version` | 0x4200dc6c | 9 | 5 | 0.40 | 0.43 | diverged |
| 0x0A | `cmd_catch_set` | 0x4200df58 | 20 | 31 | 0.24 | 0.24 | diverged |
| 0x0B | `cmd_catch_query` | 0x4200dff0 | 19 | 24 | 0.19 | 0.19 | diverged |
| 0x0C | `cmd_buttons` | 0x4200ddbc | 48 | 72 | 0.22 | 0.22 | diverged |
| 0x0D | `cmd_key_down` | 0x4200ec48 | 107 | 9 | 0.44 | 0.09 | diverged |
| 0x0E | `cmd_key_up` | 0x4200eb1c | 107 | 9 | 0.44 | 0.09 | diverged |
| 0x0F | `cmd_key_tap` | 0x4200e9d0 | 23 | 27 | 0.52 | 0.52 | diverged |
| 0x10 | `cmd_set_string` | 0x4200de80 | 30 | 33 | 0.60 | 0.60 | diverged |
| 0x11 | `cmd_key_state` | 0x4200ed74 | 379 | 25 | 0.28 | 0.03 | diverged |
| 0x12 | `cmd_keys_down` | 0x4200e6f0 | 16 | 9 | 0.56 | 0.56 | diverged |
| 0x13 | `cmd_keys_up` | 0x4200e718 | 241 | 9 | 0.56 | 0.06 | diverged |
| 0x14 | `cmd_keys_combo` | 0x4200e998 | 25 | 35 | 0.50 | 0.50 | diverged |
| 0x15 | `cmd_map_16` | 0x4200ea04 | 103 | 18 | 0.22 | 0.12 | diverged |
| 0x16 | `cmd_map_entry` | 0x4200e624 | 79 | 43 | 0.30 | 0.21 | diverged |
| 0x17 | `cmd_dump_channels` | 0x4200dbb0 | 67 | 31 | 0.19 | 0.10 | diverged |
| 0x18 | `cmd_channel_toggle` | 0x4200e56c | 67 | 57 | 0.19 | 0.11 | diverged |
| 0x19 | `cmd_silent` | 0x4200e1b0 | 167 | 24 | 0.33 | 0.08 | diverged |
| 0x1A | `cmd_serial` | 0x4200dc84 | 112 | 122 | 0.32 | 0.32 | diverged |
