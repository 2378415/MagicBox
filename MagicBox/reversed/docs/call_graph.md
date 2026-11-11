# Call graph summary

Derived from `_edges.csv` (Ghidra call references). `callers` counts distinct call sites,
`calls` counts distinct callees. Module names come from the reconstructed tree.

## left

### Most-called functions

| entry | module | name | callers | calls |
|---|---|---|---:|---:|
| `0x40381ce4` | idf_freertos | `FUN_40381ce4` | 209 | 2 |
| `0x4037bf44` | idf_freertos | `spinlock_acquire` | 150 | 2 |
| `0x4037c094` | idf_freertos | `vPortExitCritical` | 149 | 1 |
| `0x40381bb0` | idf_gpio | `FUN_40381bb0` | 142 | 4 |
| `0x40381c18` | idf_gpio | `FUN_40381c18` | 106 | 2 |
| `0x40381c60` | idf_freertos | `FUN_40381c60` | 42 | 1 |
| `0x40381e0c` | idf_esp_system | `FUN_40381e0c` | 42 | 1 |
| `0x4037bf20` | idf_freertos | `FUN_4037bf20` | 33 | 0 |
| `0x42020b54` | idf_uart | `FUN_42020b54` | 28 | 1 |
| `0x4037b768` | idf_freertos | `xQueueGenericSend` | 27 | 11 |
| `0x4037ed44` | idf_freertos | `FUN_4037ed44` | 27 | 0 |
| `0x420143e8` | uart | `uart0_reply` | 26 | 1 |
| `0x40381dd8` | idf_nvs | `FUN_40381dd8` | 21 | 1 |
| `0x4201d244` | idf_nvs | `FUN_4201d244` | 18 | 3 |
| `0x4037e0e0` | idf_freertos | `FUN_4037e0e0` | 17 | 0 |
| `0x40378e40` | idf_freertos | `FUN_40378e40` | 15 | 1 |
| `0x4037bbf4` | idf_freertos | `xQueueSemaphoreTake` | 14 | 12 |
| `0x40376ce8` | idf_esp_system | `FUN_40376ce8` | 13 | 1 |
| `0x40376d08` | idf_esp_system | `FUN_40376d08` | 13 | 5 |
| `0x4037c210` | idf_freertos | `FUN_4037c210` | 12 | 0 |

### Cross-module calls (top 15)

| from | to | edges |
|---|---|---:|
| idf_esp_system | idf_freertos | 124 |
| idf_uart | idf_freertos | 65 |
| idf_gpio | idf_freertos | 52 |
| idf_uart | idf_gpio | 45 |
| idf_freertos | idf_esp_system | 42 |
| idf_esp_system | idf_gpio | 37 |
| idf_freertos | idf_gpio | 26 |
| idf_heap | idf_freertos | 25 |
| idf_spi | idf_freertos | 21 |
| idf_freertos | idf_heap | 18 |
| idf_nvs | idf_esp_system | 18 |
| protocol | uart | 16 |
| idf_nvs | idf_gpio | 16 |
| idf_gpio | idf_esp_system | 14 |
| uart | idf_freertos | 13 |

## right

### Most-called functions

| entry | module | name | callers | calls |
|---|---|---|---:|---:|
| `0x40381d9c` | idf_freertos | `FUN_40381d9c` | 216 | 3 |
| `0x4037bbe8` | idf_freertos | `spinlock_acquire` | 130 | 2 |
| `0x4037bd38` | idf_freertos | `vPortExitCritical` | 129 | 1 |
| `0x40381ce0` | idf_esp_system | `FUN_40381ce0` | 47 | 1 |
| `0x40381e98` | idf_heap | `FUN_40381e98` | 41 | 1 |
| `0x4037bbc4` | idf_freertos | `FUN_4037bbc4` | 27 | 0 |
| `0x420180e4` | idf_uart | `FUN_420180e4` | 27 | 1 |
| `0x4037e990` | idf_freertos | `FUN_4037e990` | 26 | 1 |
| `0x40381e8c` | idf_heap | `FUN_40381e8c` | 20 | 1 |
| `0x4037b39c` | idf_freertos | `xQueueGenericSend` | 18 | 11 |
| `0x40376004` | idf_heap | `heap_caps_malloc` | 16 | 2 |
| `0x403787f4` | idf_freertos | `FUN_403787f4` | 16 | 1 |
| `0x40376244` | idf_heap | `heap_caps_free` | 14 | 2 |
| `0x4037db0c` | idf_freertos | `FUN_4037db0c` | 14 | 0 |
| `0x4037d934` | idf_freertos | `FUN_4037d934` | 14 | 0 |
| `0x42005ab0` | idf_esp_system | `FUN_42005ab0` | 13 | 0 |
| `0x42004798` | idf_esp_system | `FUN_42004798` | 13 | 0 |
| `0x4037d664` | idf_freertos | `xTaskRemoveFromEventList` | 12 | 6 |
| `0x42015dbc` | idf_heap | `FUN_42015dbc` | 12 | 5 |
| `0x40376afc` | idf_esp_system | `FUN_40376afc` | 11 | 1 |

### Cross-module calls (top 15)

| from | to | edges |
|---|---|---:|
| idf_esp_system | idf_freertos | 116 |
| idf_heap | idf_freertos | 58 |
| idf_freertos | idf_esp_system | 45 |
| idf_freertos | idf_heap | 43 |
| idf_spi | idf_freertos | 30 |
| idf_usb | idf_freertos | 30 |
| idf_uart | idf_freertos | 20 |
| idf_esp_system | idf_heap | 19 |
| idf_heap | idf_esp_system | 12 |
| hid | idf_freertos | 11 |
| idf_esp_system | idf_spi | 10 |
| idf_freertos | idf_usb | 9 |
| idf_freertos | idf_uart | 8 |
| idf_freertos | hid | 6 |
| idf_spi | idf_esp_system | 4 |
