# Function index

Generated from Ghidra decompilation. `entry` is the virtual address.

## left / crash (4)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200cc60` | `FUN_4200cc60` | 10 | 0 | 1 |  |
| `4200d078` | `FUN_4200d078` | 54 | 1 | 2 |  |
| `42012b38` | `crash_dump` | 875 | 1 | 7 | crash_dump \|          (((((                   \| coreCOREIDLE |
| `42018d80` | `FUN_42018d80` | 31 | 4 | 2 |  |

## left / efuse (1)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `42011188` | `efuse_burn` | 121 | 1 | 6 | EFUSE_BURN |

## left / hid (4)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `420139e4` | `uart_event_task` | 312 | 1 | 12 |  |
| `4201455c` | `hid_data` | 110 | 1 | 4 |  |
| `420152cc` | `usb_hid_itf_reset` | 86 | 1 | 0 |  |
| `42016a78` | `sem_create_counting` | 17 | 1 | 1 |  |

## left / idf/esp_system (253)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `403754ac` | `FUN_403754ac` | 100 | 1 | 2 |  |
| `40375510` | `entry` | 883 | 0 | 26 | cpu_start |
| `40375a54` | `FUN_40375a54` | 26 | 1 | 3 |  |
| `40375a70` | `esp_reset_reason_set_hint` | 48 | 2 | 1 | (hint & (~RST_REASON_MASK)) == 0 |
| `40375aa0` | `FUN_40375aa0` | 226 | 1 | 0 |  |
| `40375b88` | `FUN_40375b88` | 307 | 3 | 6 |  |
| `40376258` | `FUN_40376258` | 39 | 1 | 0 |  |
| `4037679c` | `FUN_4037679c` | 35 | 2 | 0 |  |
| `403767c0` | `FUN_403767c0` | 14 | 1 | 1 |  |
| `40376890` | `esp_intr_disable` | 195 | 2 | 5 | svd != NULL \| esp_intr_disable |
| `403769f4` | `FUN_403769f4` | 16 | 4 | 1 |  |
| `40376a04` | `FUN_40376a04` | 16 | 4 | 1 |  |
| `40376b50` | `FUN_40376b50` | 62 | 5 | 3 |  |
| `40376ce8` | `FUN_40376ce8` | 14 | 13 | 1 |  |
| `40376d08` | `FUN_40376d08` | 71 | 13 | 5 |  |
| `40376f2c` | `FUN_40376f2c` | 70 | 0 | 5 |  |
| `40376f74` | `FUN_40376f74` | 86 | 1 | 4 |  |
| `403779c4` | `FUN_403779c4` | 10 | 3 | 1 |  |
| `40377d24` | `FUN_40377d24` | 16 | 5 | 0 |  |
| `40377ef4` | `FUN_40377ef4` | 15 | 1 | 1 |  |
| `40377f14` | `FUN_40377f14` | 15 | 2 | 1 |  |
| `40378188` | `FUN_40378188` | 21 | 1 | 2 |  |
| `403781a0` | `FUN_403781a0` | 32 | 1 | 3 |  |
| `403781c0` | `FUN_403781c0` | 78 | 3 | 2 |  |
| `40378210` | `FUN_40378210` | 33 | 5 | 1 |  |
| `40378234` | `FUN_40378234` | 164 | 1 | 5 | issi \| spi_flash |
| `403782dc` | `FUN_403782dc` | 100 | 1 | 3 |  |
| `40378340` | `FUN_40378340` | 97 | 1 | 3 |  |
| `403783a8` | `slowrd` | 343 | 1 | 7 | spi_flash |
| `4037850c` | `esp_flash_erase_region` | 537 | 2 | 6 | len_remain < len \| (q8a \| esp_flash_api.c \| esp_flash_erase_ |
| `4037872c` | `FUN_4037872c` | 304 | 2 | 3 |  |
| `40378870` | `FUN_40378870` | 368 | 3 | 6 | len_remain < length |
| `403789f8` | `FUN_403789f8` | 537 | 2 | 5 | spi_flash \| E %s: flash encrypted write address must be 16 b |
| `40378c80` | `FUN_40378c80` | 10 | 0 | 1 |  |
| `40378cd0` | `FUN_40378cd0` | 16 | 0 | 0 |  |
| `40378ce0` | `FUN_40378ce0` | 11 | 0 | 1 |  |
| `40378cec` | `FUN_40378cec` | 46 | 0 | 2 |  |
| `40378d4c` | `FUN_40378d4c` | 16 | 0 | 0 |  |
| `40378d5c` | `FUN_40378d5c` | 17 | 0 | 1 |  |
| `40378d70` | `FUN_40378d70` | 17 | 0 | 1 |  |
| `40378dec` | `esp_crosscore_int_send` | 83 | 3 | 3 | core_id < CONFIG_FREERTOS_NUMBER_OF_CORES |
| `40378e50` | `FUN_40378e50` | 15 | 1 | 1 |  |
| `40378e60` | `FUN_40378e60` | 15 | 1 | 1 |  |
| `40378f8c` | `FUN_40378f8c` | 40 | 9 | 0 |  |
| `40378fb8` | `FUN_40378fb8` | 30 | 9 | 0 |  |
| `40378fd8` | `FUN_40378fd8` | 12 | 4 | 0 |  |
| `40378ff8` | `esp_cpu_stall` | 105 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM |
| `40379064` | `esp_cpu_unstall` | 77 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM |
| `403791bc` | `FUN_403791bc` | 59 | 1 | 4 |  |
| `40379200` | `FUN_40379200` | 93 | 1 | 0 |  |
| `40379260` | `FUN_40379260` | 5 | 1 | 0 |  |
| `40379294` | `FUN_40379294` | 14 | 0 | 0 |  |
| `403792a4` | `FUN_403792a4` | 201 | 1 | 0 |  |
| `403793f8` | `FUN_403793f8` | 24 | 1 | 0 |  |
| `403794f0` | `FUN_403794f0` | 40 | 3 | 1 |  |
| `40379564` | `FUN_40379564` | 64 | 8 | 1 | rtc_clk |
| `403795a4` | `FUN_403795a4` | 93 | 1 | 1 |  |
| `40379604` | `FUN_40379604` | 174 | 5 | 2 | rtc_clk |
| `403796b8` | `FUN_403796b8` | 470 | 1 | 3 | gfff |
| `40379894` | `clk_ll_cpu_set_divider` | 187 | 3 | 3 | divider > 0 |
| `40379950` | `FUN_40379950` | 488 | 3 | 7 | 0 && 'LDO dbias need to modified' \| rtc_clk.c \| rtc_clk_cpu_ |
| `40379b3c` | `FUN_40379b3c` | 15 | 1 | 2 |  |
| `40379b4c` | `FUN_40379b4c` | 41 | 2 | 2 |  |
| `40379bb8` | `FUN_40379bb8` | 380 | 1 | 0 |  |
| `40379fe8` | `slowclk_cycles` | 164 | 6 | 3 | slowclk_cycles |
| `4037a08c` | `rtc_time_us_to_slowclk` | 129 | 1 | 1 | period |
| `4037a138` | `FUN_4037a138` | 28 | 4 | 0 |  |
| `4037a1b4` | `FUN_4037a1b4` | 14 | 0 | 0 |  |
| `4037a1c4` | `FUN_4037a1c4` | 16 | 0 | 0 |  |
| `4037a1d4` | `esp_cache_get_alignment` | 56 | 1 | 3 | esp_cache_get_alignment |
| `4037b148` | `FUN_4037b148` | 75 | 0 | 0 |  |
| `4037b194` | `FUN_4037b194` | 28 | 0 | 0 |  |
| `4037b1b0` | `FUN_4037b1b0` | 27 | 1 | 0 |  |
| `4037b1cc` | `FUN_4037b1cc` | 33 | 2 | 0 |  |
| `4037b1f0` | `FUN_4037b1f0` | 28 | 1 | 0 |  |
| `4037b20c` | `FUN_4037b20c` | 34 | 1 | 0 |  |
| `4037ed9c` | `FUN_4037ed9c` | 58 | 1 | 0 |  |
| `4037edd8` | `FUN_4037edd8` | 140 | 1 | 1 |  |
| `4037ee64` | `cache_hal_disable` | 50 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037ee98` | `cache_hal_enable` | 65 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037eedc` | `cache_hal_suspend` | 41 | 2 | 3 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037ef08` | `cache_hal_resume` | 65 | 2 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037efc4` | `cache_hal_freeze` | 48 | 1 | 3 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037eff4` | `cache_hal_unfreeze` | 50 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037f028` | `cache_ll_get_line_size` | 75 | 1 | 1 | cache_level <= CACHE_LL_LEVEL_NUMS \| false |
| `4037f288` | `FUN_4037f288` | 71 | 1 | 0 |  |
| `40381de4` | `FUN_40381de4` | 40 | 7 | 2 |  |
| `40381e0c` | `FUN_40381e0c` | 10 | 42 | 1 |  |
| `40382b04` | `FUN_40382b04` | 124 | 0 | 0 |  |
| `40382b84` | `FUN_40382b84` | 104 | 0 | 0 |  |
| `40382bec` | `FUN_40382bec` | 48 | 0 | 0 |  |
| `40382c1c` | `FUN_40382c1c` | 60 | 0 | 0 |  |
| `40382c58` | `FUN_40382c58` | 111 | 0 | 0 |  |
| `40382cc8` | `FUN_40382cc8` | 8 | 0 | 0 |  |
| `40382cd0` | `FUN_40382cd0` | 52 | 1 | 0 |  |
| `40382d04` | `FUN_40382d04` | 52 | 1 | 0 |  |
| `40382d38` | `FUN_40382d38` | 48 | 0 | 0 |  |
| `40382d68` | `FUN_40382d68` | 48 | 0 | 0 |  |
| `40382d98` | `FUN_40382d98` | 31 | 1 | 0 |  |
| `40383578` | `FUN_40383578` | 143 | 0 | 0 |  |
| `40383608` | `FUN_40383608` | 109 | 0 | 0 |  |
| `40383678` | `FUN_40383678` | 22 | 0 | 0 |  |
| `40383690` | `FUN_40383690` | 20 | 0 | 0 |  |
| `403836a4` | `FUN_403836a4` | 7 | 1 | 0 |  |
| `40383bfc` | `FUN_40383bfc` | 27 | 4 | 0 |  |
| `42002190` | `FUN_42002190` | 59 | 3 | 3 |  |
| `420021cc` | `FUN_420021cc` | 47 | 1 | 1 |  |
| `42002200` | `esp_efuse_read_field_bit` | 53 | 1 | 2 | err == ESP_OK \| esp_efuse_api.c \| esp_efuse_read_field_bit |
| `420023d0` | `esp_efuse_utility_process` | 133 | 2 | 2 |  |
| `42002c14` | `FUN_42002c14` | 10 | 0 | 1 |  |
| `42002c98` | `FUN_42002c98` | 73 | 1 | 2 |  |
| `42002ce4` | `FUN_42002ce4` | 170 | 1 | 5 |  |
| `42002d90` | `FUN_42002d90` | 50 | 1 | 2 | TZ7@\| |
| `42002dc4` | `FUN_42002dc4` | 281 | 1 | 10 | rtc_clk_xtal_freq_get() == SOC_XTAL_FREQ_40M |
| `42002ee0` | `FUN_42002ee0` | 330 | 1 | 1 |  |
| `42003108` | `FUN_42003108` | 147 | 1 | 2 |  |
| `42003ab8` | `FUN_42003ab8` | 35 | 1 | 2 |  |
| `42003eb4` | `esp_ipc_init` | 135 | 0 | 4 | ipcX \| esp_ipc_init \| res == pdTRUE \| (a7@ |
| `420044a0` | `FUN_420044a0` | 280 | 1 | 1 | Pk7@@ |
| `4200473c` | `esp_log_cache_set_level` | 107 | 1 | 1 | i == 0 \|\| s_log_cache[(i - 1) / 2].generation <  \| esp_log_c |
| `4200509c` | `FUN_4200509c` | 16 | 2 | 1 |  |
| `420050ac` | `is_vect_desc_usable` | 155 | 1 | 3 | !((vd->flags & VECDESC_FL_SHARED) && (vd->flags  \| intr_allo |
| `420051f4` | `intr_alloc` | 1298 | 1 | 13 | find_desc_for_source \| intr_alloc \| esp_cpu.h \| esp_cpu_intr |
| `42005720` | `FUN_42005720` | 24 | 7 | 1 |  |
| `42005738` | `intr_free_for_current_cpu` | 203 | 2 | 6 | intr_free_for_current_cpu \| _free_for_current_cpu |
| `42005808` | `FUN_42005808` | 10 | 0 | 1 |  |
| `42005aa4` | `FUN_42005aa4` | 110 | 1 | 0 |  |
| `42005b14` | `FUN_42005b14` | 40 | 1 | 1 | ,b7@(' |
| `42005b3c` | `FUN_42005b3c` | 1168 | 1 | 1 |  |
| `42005fd8` | `FUN_42005fd8` | 119 | 1 | 1 |  |
| `42006058` | `FUN_42006058` | 748 | 1 | 1 |  |
| `4200634c` | `FUN_4200634c` | 544 | 1 | 1 |  |
| `42006580` | `FUN_42006580` | 159 | 1 | 1 | &((&HE!_ |
| `42006628` | `FUN_42006628` | 219 | 1 | 1 | &(<&Hi!4 |
| `42006710` | `FUN_42006710` | 261 | 1 | 1 | &(6fH |
| `42006820` | `FUN_42006820` | 189 | 1 | 1 | &(2&HW! |
| `420068ec` | `FUN_420068ec` | 216 | 1 | 1 | &((&H;! |
| `420069d0` | `FUN_420069d0` | 618 | 1 | 1 |  |
| `42006c44` | `FUN_42006c44` | 2764 | 1 | 13 | Fatal error: IRAM0 I_0 split line configuration  \| Fatal err |
| `4200775c` | `FUN_4200775c` | 59 | 11 | 0 |  |
| `4200779c` | `FUN_4200779c` | 65 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM && i \| esp_cpu_i |
| `420077e0` | `esp_sleep_sub_mode_config` | 79 | 1 | 4 | s_sleep_sub_mode_ref_cnt[mode] >= 0 \| sleep_modes.c \| esp_sl |
| `42007848` | `FUN_42007848` | 75 | 2 | 2 |  |
| `42007894` | `FUN_42007894` | 74 | 1 | 2 |  |
| `420078e0` | `esp_clk_tree_common` | 108 | 1 | 5 | esp_clk_tree_common |
| `42007950` | `FUN_42007950` | 79 | 2 | 2 |  |
| `420079a4` | `FUN_420079a4` | 61 | 1 | 2 |  |
| `420079e4` | `esp_newlib_locks_init` | 90 | 0 | 2 | handle == (SemaphoreHandle_t) &s_common_mutex \| handle == (S |
| `42007b90` | `FUN_42007b90` | 224 | 3 | 3 |  |
| `42007c74` | `FUN_42007c74` | 100 | 1 | 5 |  |
| `42007cd8` | `FUN_42007cd8` | 14 | 1 | 1 |  |
| `42007cf0` | `FUN_42007cf0` | 27 | 4 | 1 |  |
| `42007d0c` | `FUN_42007d0c` | 39 | 2 | 2 |  |
| `42007d34` | `FUN_42007d34` | 39 | 1 | 2 |  |
| `42007d5c` | `FUN_42007d5c` | 146 | 0 | 6 |  |
| `4200bd04` | `FUN_4200bd04` | 26 | 0 | 0 |  |
| `4200bd20` | `FUN_4200bd20` | 38 | 0 | 1 | /dev/uart/0 \| /dev/secondary |
| `4200bd7c` | `FUN_4200bd7c` | 22 | 0 | 1 |  |
| `4200c154` | `FUN_4200c154` | 219 | 2 | 5 |  |
| `4200c380` | `FUN_4200c380` | 155 | 2 | 2 |  |
| `4200cd18` | `esp_core_dump_get_user_ram_info` | 49 | 1 | 1 | start != ((void *)0) |
| `4200ce40` | `FUN_4200ce40` | 59 | 2 | 3 |  |
| `4200d898` | `esp_core_dump_get_stack` | 58 | 1 | 1 | stk_paddr != ((void *)0) && stk_vaddr != ((void  \| core_dump |
| `42017568` | `FUN_42017568` | 20 | 0 | 1 |  |
| `42018a40` | `rtc_gpio_deinit` | 115 | 1 | 5 | rtc_gpio_deinit |
| `42018ab8` | `partition` | 479 | 1 | 9 | partition |
| `42018ca8` | `esp_partition_next` | 134 | 3 | 4 | esp_partition_next |
| `42018d30` | `FUN_42018d30` | 72 | 3 | 3 |  |
| `42018da0` | `FUN_42018da0` | 14 | 1 | 1 |  |
| `42018db0` | `esp_partition_get` | 28 | 2 | 1 | iterator != NULL |
| `42018dcc` | `esp_partition_write` | 103 | 1 | 3 | partition != NULL |
| `42018e38` | `esp_partition_read_raw` | 62 | 1 | 2 | partition != NULL |
| `42018e78` | `esp_partition_write_raw` | 70 | 1 | 2 | partition != NULL |
| `42018ec0` | `esp_partition_erase_range` | 82 | 3 | 2 | partition != NULL |
| `42018f14` | `esp_partition_mmap` | 92 | 1 | 2 | partition != NULL |
| `42018f70` | `esp_partition_read` | 118 | 2 | 4 | partition != NULL |
| `42018fe8` | `FUN_42018fe8` | 74 | 1 | 3 |  |
| `42019038` | `FUN_42019038` | 41 | 1 | 1 |  |
| `42019078` | `FUN_42019078` | 8 | 1 | 1 |  |
| `42019080` | `FUN_42019080` | 18 | 1 | 1 | D\|7@ |
| `42019660` | `esp_mmu_unmap` | 236 | 1 | 4 | esp_mmu_unmap \| mmap |
| `42019750` | `esp_mmu_vaddr_to_paddr` | 181 | 1 | 4 | esp_mmu_vaddr_to_paddr \| mmap |
| `42019854` | `FUN_42019854` | 134 | 2 | 3 | 8d7@H |
| `42019924` | `FUN_42019924` | 36 | 1 | 1 |  |
| `42019948` | `esp_mspi_get_io` | 116 | 3 | 2 | io <= ESP_MSPI_IO_D7 |
| `420199c0` | `FUN_420199c0` | 130 | 1 | 3 | $}7@4> |
| `42019a48` | `FUN_42019a48` | 20 | 1 | 1 |  |
| `42019a7c` | `FUN_42019a7c` | 58 | 1 | 2 | $}7@4> |
| `42019c30` | `esp_crosscore_int_init` | 108 | 2 | 4 | /IDF/components/esp_system/crosscore_int.c \| esp_crosscore_i |
| `42019ca0` | `add_entry` | 399 | 1 | 7 | task_wdt \| add_entry |
| `42019ee4` | `esp_task_wdt_add` | 76 | 1 | 4 | esp_task_wdt_add |
| `42019fa8` | `esp_task_wdt_init` | 227 | 1 | 7 | esp_task_wdt_init |
| `4201a090` | `esp_task_wdt_reset` | 200 | 1 | 6 | esp_task_wdt_reset |
| `4201a15c` | `FUN_4201a15c` | 10 | 0 | 1 |  |
| `4201a3dc` | `FUN_4201a3dc` | 197 | 1 | 3 |  |
| `4201a4a4` | `FUN_4201a4a4` | 38 | 2 | 0 |  |
| `4201a4ec` | `FUN_4201a4ec` | 46 | 2 | 0 |  |
| `4201a51c` | `FUN_4201a51c` | 56 | 1 | 0 |  |
| `4201a720` | `FUN_4201a720` | 18 | 0 | 0 |  |
| `4201a734` | `FUN_4201a734` | 18 | 0 | 0 |  |
| `4201a748` | `clk_hal_soc_root_get_freq_mhz` | 20 | 1 | 1 | false |
| `4201a75c` | `FUN_4201a75c` | 55 | 1 | 1 | false |
| `4201a798` | `FUN_4201a798` | 64 | 3 | 2 | clk_hal |
| `4201a7d8` | `FUN_4201a7d8` | 157 | 2 | 4 | clk_hal |
| `4201a880` | `FUN_4201a880` | 30 | 1 | 1 |  |
| `4201ab5c` | `FUN_4201ab5c` | 44 | 1 | 1 |  |
| `4201acb0` | `esp_clk_tree_src_get_freq_hz` | 281 | 2 | 10 | esp_clk_tree_src_get_freq_hz \| esp_clk_tree |
| `4201afbc` | `FUN_4201afbc` | 14 | 0 | 1 |  |
| `4201c704` | `FUN_4201c704` | 21 | 0 | 1 |  |
| `4201c71c` | `FUN_4201c71c` | 21 | 0 | 1 |  |
| `4201c734` | `FUN_4201c734` | 16 | 0 | 1 |  |
| `4201c744` | `FUN_4201c744` | 32 | 0 | 1 |  |
| `4201c764` | `FUN_4201c764` | 32 | 0 | 1 |  |
| `4201c7a0` | `FUN_4201c7a0` | 14 | 0 | 1 |  |
| `4201cbe8` | `FUN_4201cbe8` | 150 | 1 | 1 |  |
| `4201e508` | `FUN_4201e508` | 114 | 1 | 7 | phys_offs != SPI_FLASH_CACHE2PHYS_FAIL \| it != NULL \| esp_ot |
| `4201e57c` | `FUN_4201e57c` | 20 | 1 | 1 |  |
| `4201e5d4` | `FUN_4201e5d4` | 14 | 2 | 1 |  |
| `4201e7d0` | `FUN_4201e7d0` | 18 | 1 | 1 |  |
| `4201e7e4` | `FUN_4201e7e4` | 24 | 0 | 2 |  |
| `4201e7fc` | `FUN_4201e7fc` | 46 | 2 | 0 |  |
| `4201e82c` | `FUN_4201e82c` | 119 | 0 | 1 |  |
| `4201e8a4` | `FUN_4201e8a4` | 44 | 0 | 1 |  |
| `4201e8d0` | `FUN_4201e8d0` | 42 | 0 | 1 |  |
| `4201e8fc` | `FUN_4201e8fc` | 8 | 0 | 0 | std::bad_alloc |
| `4201e904` | `FUN_4201e904` | 18 | 1 | 1 |  |
| `4201e918` | `FUN_4201e918` | 24 | 0 | 2 |  |
| `4201e930` | `FUN_4201e930` | 18 | 2 | 1 |  |
| `4201e944` | `FUN_4201e944` | 24 | 0 | 2 |  |
| `4201e95c` | `FUN_4201e95c` | 46 | 3 | 0 |  |
| `4201e98c` | `FUN_4201e98c` | 30 | 1 | 1 |  |
| `4201e9ac` | `FUN_4201e9ac` | 53 | 0 | 1 |  |
| `4201e9e4` | `FUN_4201e9e4` | 40 | 0 | 1 |  |
| `4201ea0c` | `FUN_4201ea0c` | 14 | 3 | 1 |  |
| `420206b4` | `FUN_420206b4` | 18 | 0 | 1 |  |
| `42020b64` | `FUN_42020b64` | 21 | 1 | 2 |  |
| `42020b94` | `FUN_42020b94` | 24 | 1 | 2 | to7@d |
| `42020bac` | `FUN_42020bac` | 74 | 1 | 2 |  |
| `4202cde0` | `FUN_4202cde0` | 7 | 0 | 0 |  |
| `4202cde8` | `FUN_4202cde8` | 5 | 0 | 0 |  |
| `4202cdf0` | `FUN_4202cdf0` | 34 | 1 | 0 |  |
| `4202ce14` | `FUN_4202ce14` | 18 | 1 | 0 |  |
| `4202d8e0` | `FUN_4202d8e0` | 72 | 1 | 0 |  |
| `4202d92c` | `FUN_4202d92c` | 5 | 1 | 0 |  |
| `4202d934` | `FUN_4202d934` | 7 | 0 | 0 |  |
| `4202d93c` | `FUN_4202d93c` | 47 | 0 | 0 |  |
| `4202d96c` | `FUN_4202d96c` | 12 | 0 | 0 |  |
| `4202d978` | `FUN_4202d978` | 5 | 1 | 0 |  |
| `4202df28` | `FUN_4202df28` | 174 | 1 | 0 |  |
| `4202dfd8` | `FUN_4202dfd8` | 1866 | 1 | 14 | Pk7@@ |
| `4202e730` | `FUN_4202e730` | 42 | 1 | 0 |  |
| `4202eff8` | `FUN_4202eff8` | 27 | 1 | 0 | lr7@ \| lr7@< |
| `4202f014` | `FUN_4202f014` | 60 | 2 | 0 | lr7@< \| lr7@ |

## left / idf/esp_timer (3)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `42008110` | `esp_timer_systimer` | 163 | 1 | 4 | esp_timer_systimer |
| `4201af0c` | `esp_timer` | 160 | 1 | 4 | esp_timer |
| `4201afb0` | `FUN_4201afb0` | 10 | 0 | 1 |  |

## left / idf/freertos (686)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40375ccc` | `FUN_40375ccc` | 18 | 0 | 2 |  |
| `40375d48` | `FUN_40375d48` | 19 | 1 | 0 |  |
| `40375dbc` | `FUN_40375dbc` | 36 | 1 | 4 |  |
| `40375de0` | `FUN_40375de0` | 15 | 2 | 0 |  |
| `40375e54` | `FUN_40375e54` | 147 | 1 | 0 |  |
| `40375ee8` | `FUN_40375ee8` | 487 | 1 | 3 |  0x%08lX:0x%08lX \| figuration error, the error address and s |
| `403760e0` | `FUN_403760e0` | 1 | 2 | 0 |  |
| `40376108` | `FUN_40376108` | 29 | 0 | 1 |  |
| `40376128` | `FUN_40376128` | 221 | 0 | 5 | cpuid == xPortGetCoreID() |
| `40376208` | `FUN_40376208` | 36 | 1 | 0 |  |
| `40376314` | `FUN_40376314` | 32 | 12 | 2 | heap_caps_malloc |
| `40376418` | `FUN_40376418` | 30 | 3 | 2 | heap_caps_realloc |
| `403767d0` | `FUN_403767d0` | 57 | 0 | 2 |  |
| `4037680c` | `FUN_4037680c` | 128 | 1 | 4 |  |
| `4037695c` | `FUN_4037695c` | 84 | 1 | 6 |  |
| `403769b0` | `FUN_403769b0` | 66 | 1 | 6 |  |
| `40376a14` | `FUN_40376a14` | 18 | 4 | 2 |  |
| `40376a28` | `FUN_40376a28` | 14 | 4 | 2 |  |
| `40376a38` | `FUN_40376a38` | 79 | 0 | 2 |  |
| `40376a88` | `FUN_40376a88` | 52 | 1 | 0 |  |
| `40376abc` | `FUN_40376abc` | 31 | 1 | 0 |  |
| `40376adc` | `FUN_40376adc` | 59 | 1 | 3 |  |
| `40376b18` | `FUN_40376b18` | 54 | 1 | 3 |  |
| `40376b90` | `FUN_40376b90` | 24 | 3 | 0 |  |
| `40376ba8` | `lock_acquire_generic` | 159 | 5 | 10 | h != ((void *)0) \| lock_acquire_generic |
| `40376c50` | `FUN_40376c50` | 88 | 2 | 7 |  |
| `40376cac` | `_lock_close` | 59 | 2 | 5 | xQueueGetMutexHolder( ( h ) ) == ((void *)0) |
| `40376d80` | `FUN_40376d80` | 40 | 0 | 4 |  |
| `40376da8` | `FUN_40376da8` | 40 | 4 | 4 |  |
| `40376dd0` | `FUN_40376dd0` | 15 | 0 | 1 |  |
| `40376de0` | `FUN_40376de0` | 15 | 4 | 1 |  |
| `40376e20` | `FUN_40376e20` | 48 | 8 | 2 | lock != NULL && 'Uninitialized lock used' |
| `40376e50` | `FUN_40376e50` | 50 | 0 | 2 | lock != NULL && 'Uninitialized lock used' |
| `40376e84` | `FUN_40376e84` | 50 | 0 | 2 | lock != NULL && 'Uninitialized lock used' |
| `40376eb8` | `FUN_40376eb8` | 34 | 0 | 2 | lock != NULL && 'Uninitialized lock used' |
| `40376edc` | `FUN_40376edc` | 34 | 8 | 2 | lock != NULL && 'Uninitialized lock used' |
| `40376f00` | `FUN_40376f00` | 41 | 1 | 0 |  |
| `40376fcc` | `FUN_40376fcc` | 27 | 6 | 1 |  |
| `40376fe8` | `FUN_40376fe8` | 38 | 0 | 0 |  |
| `40377010` | `FUN_40377010` | 22 | 5 | 1 |  |
| `40377028` | `FUN_40377028` | 86 | 2 | 5 | alarm_id < sizeof(timestamp_id) / sizeof(timesta |
| `4037712c` | `FUN_4037712c` | 187 | 2 | 4 |  |
| `403771e8` | `FUN_403771e8` | 130 | 0 | 3 |  |
| `4037726c` | `FUN_4037726c` | 22 | 0 | 0 | Unhandled interrupt %d on cpu %d! |
| `403779d0` | `bootloader_flash_execute_command_common` | 627 | 2 | 1 | mosi_len <= 32 \| miso_len <= 32 \| bootloader_flash.c \| bootl |
| `40377c44` | `FUN_40377c44` | 53 | 1 | 1 |  |
| `40377c7c` | `FUN_40377c7c` | 168 | 0 | 1 |  |
| `40377d34` | `FUN_40377d34` | 15 | 0 | 1 |  |
| `40377e34` | `FUN_40377e34` | 73 | 1 | 0 |  |
| `403780c4` | `FUN_403780c4` | 8 | 1 | 1 |  |
| `403780cc` | `FUN_403780cc` | 17 | 3 | 1 |  |
| `403780e0` | `FUN_403780e0` | 69 | 1 | 2 |  |
| `40378128` | `FUN_40378128` | 81 | 1 | 2 | JwW7 |
| `4037817c` | `FUN_4037817c` | 10 | 2 | 0 |  |
| `40378c20` | `FUN_40378c20` | 24 | 0 | 3 |  |
| `40378c8c` | `FUN_40378c8c` | 66 | 0 | 2 |  |
| `40378d38` | `FUN_40378d38` | 17 | 0 | 2 |  |
| `40378d84` | `FUN_40378d84` | 12 | 1 | 0 |  |
| `40378d90` | `FUN_40378d90` | 87 | 0 | 5 |  |
| `40378e40` | `FUN_40378e40` | 15 | 15 | 1 |  |
| `40378ef4` | `FUN_40378ef4` | 30 | 0 | 2 |  |
| `40378f14` | `FUN_40378f14` | 107 | 0 | 1 |  |
| `40378fe4` | `FUN_40378fe4` | 20 | 2 | 0 |  |
| `403790b4` | `FUN_403790b4` | 8 | 1 | 0 |  |
| `403790bc` | `FUN_403790bc` | 43 | 3 | 0 |  |
| `403790e8` | `FUN_403790e8` | 7 | 1 | 0 |  |
| `403790f0` | `mspi_timing_config_set_flash_clock` | 109 | 1 | 1 | freqdiv > 0 |
| `40379160` | `mspi_timing_config_set_psram_clock` | 89 | 1 | 1 | freqdiv > 0 |
| `403791f8` | `FUN_403791f8` | 6 | 1 | 1 |  |
| `40379270` | `FUN_40379270` | 23 | 2 | 1 | false |
| `40379370` | `FUN_40379370` | 133 | 2 | 0 |  |
| `40379410` | `FUN_40379410` | 193 | 1 | 3 | false \| clk_ll_rtc_slow_get_src |
| `403794d4` | `FUN_403794d4` | 27 | 2 | 1 |  |
| `4037951c` | `FUN_4037951c` | 68 | 1 | 1 |  |
| `40379b78` | `FUN_40379b78` | 32 | 1 | 0 |  |
| `40379b98` | `FUN_40379b98` | 32 | 2 | 0 |  |
| `40379d38` | `FUN_40379d38` | 679 | 1 | 2 |  |
| `4037a110` | `FUN_4037a110` | 40 | 2 | 0 |  |
| `4037a154` | `FUN_4037a154` | 96 | 0 | 2 |  |
| `4037a20c` | `prvGetItemByteBuf` | 154 | 0 | 1 | (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf \| ringbuf.c |
| `4037a2a8` | `prvCheckItemFitsByteBuffer` | 87 | 0 | 1 | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea \| ringbuf.c |
| `4037a300` | `prvReturnItemDefault` | 284 | 0 | 1 | ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  \| pucItem > |
| `4037a420` | `prvGetItemDefault` | 282 | 0 | 1 | pxIsSplit != ((void *)0) \| (pxRingbuffer->xItemsWaiting > 0) |
| `4037a53c` | `prvAcquireItemNoSplit` | 146 | 2 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a5d0` | `prvSendItemDoneNoSplit` | 244 | 1 | 1 | ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  \| pucItem > |
| `4037a6c8` | `prvCheckItemFitsDefault` | 150 | 0 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a764` | `FUN_4037a764` | 141 | 1 | 1 |  |
| `4037a7f4` | `prvCopyItemByteBuf` | 112 | 0 | 1 | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea \| ringbuf.c |
| `4037a864` | `prvCopyItemAllowSplit` | 218 | 0 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a940` | `FUN_4037a940` | 34 | 0 | 2 |  |
| `4037a964` | `FUN_4037a964` | 235 | 1 | 9 |  |
| `4037aa5c` | `prvReceiveGenericFromISR` | 150 | 1 | 4 | *pvItem2 < *pvItem1 \| xIsSplit == ( ( BaseType_t ) 0 ) \| rin |
| `4037aaf4` | `prvReturnItemByteBuf` | 67 | 0 | 1 | (uint8_t *)pucItem >= pxRingbuffer->pucHead \| (uint8_t *)puc |
| `4037ab38` | `prvReceiveGeneric` | 323 | 2 | 7 | *pvItem2 < *pvItem1 \| xIsSplit == ( ( BaseType_t ) 0 ) \| rin |
| `4037ac84` | `xRingbufferCreateStatic` | 116 | 1 | 2 | xBufferSize > 0 \| xBufferType < RINGBUF_TYPE_MAX \| ringbuf.c |
| `4037acf8` | `xRingbufferSend` | 88 | 3 | 2 | pxRingbuffer \| pvItem != ((void *)0) \|\| xItemSize == 0 \| rin |
| `4037ad50` | `xRingbufferSendFromISR` | 195 | 1 | 5 | pxRingbuffer \| pvItem != ((void *)0) \|\| xItemSize == 0 \| rin |
| `4037ae20` | `xRingbufferReceive` | 55 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceive |
| `4037ae58` | `xRingbufferReceiveFromISR` | 55 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceiveF |
| `4037ae90` | `xRingbufferReceiveUpTo` | 83 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceiveU |
| `4037aee4` | `vRingbufferReturnItem` | 92 | 2 | 5 | pxRingbuffer \| pvItem != ((void *)0) \| ringbuf.c \| vRingbuff |
| `4037af40` | `vRingbufferReturnItemFromISR` | 89 | 1 | 4 | pxRingbuffer \| pvItem != ((void *)0) \| ringbuf.c \| vRingbuff |
| `4037af9c` | `xRingbufferGetMaxItemSize` | 25 | 1 | 1 | pxRingbuffer |
| `4037afb8` | `xRingbufferGetCurFreeSize` | 48 | 1 | 3 | pxRingbuffer |
| `4037afe8` | `vRingbufferGetInfo` | 95 | 1 | 3 | pxRingbuffer \| vRingbufferGetInfo |
| `4037b048` | `FUN_4037b048` | 83 | 0 | 3 |  |
| `4037b09c` | `xRingbufferGetStaticBuffer` | 56 | 1 | 2 | pxRingbuffer && ppucRingbufferStorage && ppxStat \| xResult = |
| `4037b0d4` | `FUN_4037b0d4` | 54 | 1 | 0 |  |
| `4037b10c` | `FUN_4037b10c` | 58 | 0 | 0 |  |
| `4037b30c` | `FUN_4037b30c` | 34 | 0 | 0 |  |
| `4037b330` | `FUN_4037b330` | 75 | 1 | 2 | %s failed: esp_err_t 0x%x \|  (%s) \|  at 0x%08x \| file: '%s'  |
| `4037b37c` | `ESP_ERROR_CHECK` | 42 | 8 | 2 | ESP_ERROR_CHECK |
| `4037b3a8` | `FUN_4037b3a8` | 13 | 3 | 1 |  |
| `4037b3b8` | `FUN_4037b3b8` | 135 | 3 | 1 |  |
| `4037b440` | `pxQueueSetContainer` | 118 | 3 | 6 | pxQueueSetContainer \| pxQueueSetContainer->uxMessagesWaiting |
| `4037b4b8` | `xQueueGenericReset` | 161 | 5 | 6 | pxQueue \| xQueueGenericReset \| xReturn != ( ( ( BaseType_t ) |
| `4037b55c` | `xQueueGenericCreateStatic` | 134 | 4 | 2 | pxStaticQueue \| xSize == sizeof( Queue_t ) \| pxNewQueue \| qu |
| `4037b5e4` | `xQueueGenericGetStaticBuffers` | 66 | 2 | 1 | pxQueue \| ppxStaticQueue \| queue.c \| xQueueGenericGetStaticB |
| `4037b628` | `xQueueGenericCreate` | 78 | 6 | 3 | pxNewQueue \| queue.c \| xQueueGenericCreate |
| `4037b678` | `xSemaphore` | 52 | 1 | 3 | xSemaphore \| xQueueGetMutexHolder |
| `4037b6ac` | `xQueueCreateCountingSemaphoreStatic` | 123 | 1 | 2 | pxStaticQueue \| xSize == sizeof( Queue_t ) \| xHandle \| queue |
| `4037b728` | `xQueueCreateCountingSemaphore` | 47 | 1 | 1 |  |
| `4037b768` | `xQueueGenericSend` | 293 | 27 | 11 | pxQueue \| !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue \| |
| `4037b894` | `FUN_4037b894` | 62 | 7 | 3 |  |
| `4037b8d4` | `xQueueGiveMutexRecursive` | 64 | 3 | 3 | h'%} \| pxMutex |
| `4037b918` | `FUN_4037b918` | 110 | 3 | 3 | pxStaticQueue \| xSize == sizeof( Queue_t ) \| xQueueGenericCr |
| `4037b988` | `xQueueGenericSendFromISR` | 209 | 5 | 6 | pxQueue \| !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue \| |
| `4037ba5c` | `xQueueGiveFromISR` | 157 | 5 | 5 | pxQueue \| pxQueue->uxItemSize == 0 \| queue.c \| xQueueGiveFro |
| `4037bafc` | `xQueueReceive` | 242 | 6 | 9 | ( pxQueue ) \| !( ( ( pvBuffer ) == ((void *)0) ) && ( ( pxQu |
| `4037bbf4` | `xQueueSemaphoreTake` | 257 | 14 | 12 | ( pxQueue ) \| pxQueue->uxItemSize == 0 \| queue.c \| xQueueSem |
| `4037bcfc` | `xQueueTakeMutexRecursive` | 57 | 2 | 3 | pxMutex |
| `4037bd38` | `xQueueReceiveFromISR` | 138 | 2 | 4 | pxQueue \| !( ( pvBuffer == ((void *)0) ) && ( pxQueue->uxI \| |
| `4037bdf8` | `vQueueDelete` | 36 | 5 | 2 | pxQueue |
| `4037be1c` | `FUN_4037be1c` | 39 | 0 | 3 |  |
| `4037be44` | `FreeRTOS` | 38 | 0 | 4 | FreeRTOS |
| `4037be6c` | `FUN_4037be6c` | 40 | 2 | 4 |  |
| `4037be94` | `pxPortInitialiseStack` | 140 | 1 | 1 | (uxStackPointer & ( 0x000f )) == 0 \| Xs7@ |
| `4037bf20` | `FUN_4037bf20` | 34 | 33 | 0 |  |
| `4037bf44` | `spinlock_acquire` | 332 | 150 | 2 | lock \| lock->count > 0 && lock->count < 0xFF \| spinlock.h \|  |
| `4037c094` | `vPortExitCritical` | 152 | 149 | 1 | lock \| core_owner_id == lock->owner \| spinlock.h \| spinlock_ |
| `4037c130` | `FUN_4037c130` | 10 | 3 | 1 |  |
| `4037c13c` | `FUN_4037c13c` | 64 | 1 | 1 | ***ERROR*** A stack overflow in task  \|  has been detected. |
| `4037c17c` | `FUN_4037c17c` | 144 | 1 | 3 |  |
| `4037c210` | `FUN_4037c210` | 21 | 12 | 0 |  |
| `4037c2bc` | `FUN_4037c2bc` | 100 | 1 | 2 |  |
| `4037c428` | `FUN_4037c428` | 18 | 6 | 1 |  |
| `4037c43c` | `FUN_4037c43c` | 10 | 4 | 1 |  |
| `4037c448` | `FUN_4037c448` | 68 | 1 | 1 |  |
| `4037c48c` | `FUN_4037c48c` | 68 | 3 | 1 |  |
| `4037c4d0` | `FUN_4037c4d0` | 68 | 1 | 1 |  |
| `4037c514` | `vApplicationGetIdleTaskMemory` | 61 | 1 | 2 | pxTCBBufferTemp != NULL \| pxStackBufferTemp != NULL \| port_c |
| `4037c554` | `vApplicationGetTimerTaskMemory` | 62 | 1 | 2 | pxTCBBufferTemp != NULL \| pxStackBufferTemp != NULL \| port_c |
| `4037c594` | `FUN_4037c594` | 141 | 0 | 5 |  |
| `4037c624` | `FUN_4037c624` | 310 | 1 | 13 | esp_intr_alloc(ETS_SYSTIMER_TARGET0_INTR_SOURCE  \| vSystimer |
| `4037c760` | `FUN_4037c760` | 8 | 1 | 1 |  |
| `4037c768` | `FUN_4037c768` | 71 | 2 | 4 |  |
| `4037c7b0` | `FUN_4037c7b0` | 120 | 1 | 2 |  |
| `4037c82c` | `prvProcessReceivedCommands` | 352 | 0 | 9 | ( pxTimer->xTimerPeriodInTicks > 0 ) |
| `4037cab4` | `xTimerCreateTimerTask` | 86 | 1 | 4 | timers.c \| xTimerCreateTimerTask \| xReturn |
| `4037cb0c` | `prvInitialiseNewTimer` | 70 | 1 | 4 | ( xTimerPeriodInTicks > 0 ) |
| `4037cb54` | `xTimerGenericCommand` | 103 | 2 | 4 | xTimer |
| `4037cbbc` | `FUN_4037cbbc` | 36 | 4 | 0 |  |
| `4037cbe0` | `FUN_4037cbe0` | 12 | 2 | 0 |  |
| `4037cbec` | `FUN_4037cbec` | 57 | 1 | 0 |  |
| `4037cc28` | `FUN_4037cc28` | 103 | 4 | 0 |  |
| `4037cc94` | `FUN_4037cc94` | 82 | 9 | 0 |  |
| `4037cce8` | `prvIsYieldRequiredSMP` | 206 | 7 | 2 | uxTaskPriority < ( 25 ) \| prvIsYieldRequiredSMP |
| `4037cdc0` | `FUN_4037cdc0` | 241 | 4 | 2 |  |
| `4037ceb4` | `FUN_4037ceb4` | 434 | 1 | 5 |  |
| `4037d068` | `prvDeleteTCB` | 71 | 2 | 4 | pxTCB->ucStaticallyAllocated == ( ( uint8_t ) 2  |
| `4037d0b0` | `FUN_4037d0b0` | 144 | 0 | 5 |  |
| `4037d148` | `FUN_4037d148` | 143 | 1 | 4 | uxPriority < ( 25 ) \| tasks.c \| prvInitialiseNewTask |
| `4037d1d8` | `vTaskDelete` | 381 | 4 | 8 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) |
| `4037d35c` | `vTaskDelay` | 101 | 11 | 5 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) \| vTaskDela |
| `4037d3c4` | `FUN_4037d3c4` | 50 | 1 | 2 |  |
| `4037d3f8` | `vTaskPrioritySet` | 311 | 2 | 7 | uxNewPriority < ( 25 ) \| vTaskPrioritySet |
| `4037d530` | `FUN_4037d530` | 46 | 2 | 2 |  |
| `4037d560` | `FUN_4037d560` | 13 | 7 | 0 |  |
| `4037d570` | `FUN_4037d570` | 30 | 2 | 2 |  |
| `4037d590` | `pcTaskGetName` | 53 | 3 | 1 | pxTCB |
| `4037d5c8` | `xTaskIncrementTick` | 704 | 2 | 4 | xPortGetCoreID() == 0 \| ( ( ( ( pxDelayedTaskList )->uxNumbe |
| `4037d8a0` | `xTaskResumeAll` | 534 | 2 | 6 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) \| xTaskResu |
| `4037dab8` | `prvSelectHighestPriorityTaskSMP` | 554 | 1 | 5 | xTaskScheduled == ( ( BaseType_t ) 1 ) \| tasks.c \| prvSelect |
| `4037dce8` | `vTaskPlaceOnEventList` | 71 | 5 | 5 | pxEventList |
| `4037dd30` | `vTaskPlaceOnEventListRestricted` | 179 | 1 | 4 | pxEventList \| vTaskPlaceOnEventListRestricted |
| `4037dde4` | `xTaskRemoveFromEventList` | 463 | 12 | 5 | pxUnblockedTCB \| uxSchedulerSuspended[ uxPendCore ] != ( UBa |
| `4037dfb8` | `FUN_4037dfb8` | 25 | 5 | 0 |  |
| `4037dfd4` | `xTaskCheckForTimeOut` | 184 | 5 | 3 | pxTimeOut \| pxTicksToWait \| tasks.c \| xTaskCheckForTimeOut |
| `4037e0c0` | `FUN_4037e0c0` | 31 | 6 | 0 |  |
| `4037e0e0` | `FUN_4037e0e0` | 52 | 17 | 0 |  |
| `4037e114` | `FUN_4037e114` | 229 | 1 | 3 |  |
| `4037e1fc` | `xTaskPriorityDisinherit` | 205 | 1 | 4 | pxTCB == pxCurrentTCBs[ xPortGetCoreID() ] \| pxTCB->uxMutexe |
| `4037e2cc` | `vTaskPriorityDisinheritAfterTimeout` | 228 | 1 | 4 | pxTCB->uxMutexesHeld \| pxTCB != pxCurrentTCBs[ xPortGetCoreI |
| `4037e3b0` | `FUN_4037e3b0` | 63 | 1 | 2 |  |
| `4037e3f0` | `ulTaskGenericNotifyTake` | 183 | 4 | 5 | uxIndexToWait < 1 \| ulTaskGenericNotifyTake |
| `4037e4a8` | `xTaskGenericNotify` | 392 | 12 | 5 | uxIndexToNotify < 1 \| xTaskToNotify \| tasks.c \| xTaskGeneric |
| `4037e634` | `xTaskGenericNotifyFromISR` | 528 | 1 | 4 | xTaskToNotify \| uxIndexToNotify < 1 \| tasks.c \| xTaskGeneric |
| `4037e848` | `vTaskGenericNotifyGiveFromISR` | 427 | 2 | 4 | xTaskToNotify \| uxIndexToNotify < 1 \| tasks.c \| vTaskGeneric |
| `4037e9f4` | `xTaskIncrementTickOtherCores` | 108 | 1 | 3 | xCoreID != 0 |
| `4037ea60` | `xTaskCreatePinnedToCore` | 91 | 9 | 3 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT \| freertos_ |
| `4037eb00` | `xTaskCreateStaticPinnedToCore` | 214 | 2 | 5 | xPortcheckValidStackMem(puxStackBuffer) \| xPortCheckValidTCB |
| `4037ebd8` | `vTaskStartScheduler` | 169 | 1 | 7 | IDLE |
| `4037ec84` | `FUN_4037ec84` | 37 | 2 | 0 |  |
| `4037ecac` | `xTaskGetIdleTaskHandleForCore` | 50 | 1 | 1 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT \| ( xIdleTa |
| `4037ece0` | `xTaskGetCurrentTaskHandleForCore` | 34 | 3 | 1 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT |
| `4037ed04` | `FUN_4037ed04` | 61 | 1 | 2 |  |
| `4037ed44` | `FUN_4037ed44` | 40 | 27 | 0 |  |
| `4037ed6c` | `FUN_4037ed6c` | 45 | 2 | 1 |  |
| `4037ef4c` | `FUN_4037ef4c` | 52 | 1 | 0 |  |
| `4037ef84` | `FUN_4037ef84` | 62 | 2 | 0 |  |
| `4037f078` | `mmu_hal_map_region` | 192 | 0 | 1 | vaddr % page_size_in_bytes == 0 \| paddr % page_size_in_bytes |
| `4037f21c` | `mmu_hal_paddr_to_vaddr` | 103 | 1 | 1 | mmu_ll_check_valid_paddr_region(mmu_id, paddr, 1 |
| `4037f4d8` | `FUN_4037f4d8` | 604 | 0 | 1 |  |
| `4037f73c` | `FUN_4037f73c` | 550 | 0 | 0 | ;602A |
| `4037f964` | `FUN_4037f964` | 245 | 0 | 0 | ;E@BA= |
| `4037fa5c` | `FUN_4037fa5c` | 15 | 0 | 0 |  |
| `4037fa6c` | `FUN_4037fa6c` | 7 | 0 | 0 |  |
| `4037fa74` | `FUN_4037fa74` | 7 | 0 | 0 |  |
| `4037fa7c` | `FUN_4037fa7c` | 20 | 0 | 0 |  |
| `4037fa90` | `FUN_4037fa90` | 813 | 0 | 1 |  |
| `4037fdc8` | `FUN_4037fdc8` | 424 | 0 | 0 | ;502A |
| `4037ff78` | `FUN_4037ff78` | 185 | 0 | 0 | ;E@BA |
| `40380034` | `FUN_40380034` | 38 | 0 | 0 |  |
| `4038005c` | `FUN_4038005c` | 110 | 0 | 0 |  |
| `403800cc` | `FUN_403800cc` | 102 | 0 | 0 |  |
| `40380134` | `FUN_40380134` | 175 | 0 | 0 |  |
| `403801e4` | `FUN_403801e4` | 54 | 0 | 0 |  |
| `4038021c` | `FUN_4038021c` | 116 | 0 | 0 |  |
| `40380290` | `FUN_40380290` | 401 | 1 | 0 |  |
| `40380424` | `FUN_40380424` | 387 | 0 | 1 |  |
| `403805ac` | `FUN_403805ac` | 15 | 0 | 0 |  |
| `403805bc` | `FUN_403805bc` | 32 | 0 | 0 |  |
| `403805dc` | `FUN_403805dc` | 34 | 0 | 0 |  |
| `40380600` | `FUN_40380600` | 34 | 0 | 0 |  |
| `40380624` | `FUN_40380624` | 26 | 2 | 0 |  |
| `40380640` | `FUN_40380640` | 72 | 3 | 0 |  |
| `40380688` | `systimer_ll_set_alarm_period` | 121 | 1 | 1 | period < (1 << 26) |
| `40380704` | `FUN_40380704` | 82 | 1 | 1 |  |
| `40380758` | `FUN_40380758` | 62 | 2 | 0 |  |
| `40380798` | `FUN_40380798` | 13 | 2 | 0 |  |
| `403807a8` | `FUN_403807a8` | 100 | 1 | 0 |  |
| `4038080c` | `FUN_4038080c` | 30 | 2 | 0 |  |
| `4038082c` | `FUN_4038082c` | 34 | 2 | 0 |  |
| `40380850` | `FUN_40380850` | 33 | 2 | 0 |  |
| `40380874` | `FUN_40380874` | 56 | 2 | 0 |  |
| `40380a98` | `FUN_40380a98` | 7 | 2 | 0 |  |
| `40381b34` | `FUN_40381b34` | 10 | 2 | 0 |  |
| `40381b40` | `FUN_40381b40` | 35 | 1 | 3 |  |
| `40381b64` | `FUN_40381b64` | 48 | 1 | 3 |  |
| `40381b94` | `FUN_40381b94` | 27 | 2 | 2 |  |
| `40381c60` | `FUN_40381c60` | 132 | 42 | 1 | abort() was called at PC 0x \|  on core  |
| `40381ce4` | `FUN_40381ce4` | 238 | 209 | 2 | assert failed:  \| <cached disabled> |
| `40381e18` | `FUN_40381e18` | 12 | 5 | 1 |  |
| `40381e24` | `FUN_40381e24` | 10 | 8 | 1 |  |
| `40381e30` | `FUN_40381e30` | 17 | 2 | 1 |  |
| `40381e68` | `FUN_40381e68` | 5 | 0 | 0 |  |
| `40381e70` | `FUN_40381e70` | 55 | 1 | 3 |  |
| `40381ea8` | `FUN_40381ea8` | 24 | 1 | 0 |  |
| `40381ec0` | `FUN_40381ec0` | 11 | 1 | 0 |  |
| `40381f64` | `FUN_40381f64` | 25 | 0 | 1 |  |
| `40381f80` | `memspi_host_erase_sector` | 67 | 0 | 1 | start_address < 0x1000000 \| memspi_host_erase_sector |
| `40381fc4` | `memspi_host_erase_block` | 68 | 0 | 1 | start_address < 0x1000000 \| memspi_host_erase_block |
| `40382008` | `memspi_host_program_page` | 71 | 0 | 1 | address + length <= 0x1000000 \| memspi_host_program_page |
| `40382438` | `FUN_40382438` | 97 | 0 | 0 |  |
| `4038249c` | `FUN_4038249c` | 29 | 0 | 0 |  |
| `403825ec` | `FUN_403825ec` | 62 | 0 | 1 |  |
| `403832f8` | `FUN_403832f8` | 98 | 0 | 1 | (io_mode == SPI_FLASH_OPI_STR) \|\| (io_mode == SP |
| `4038335c` | `FUN_4038335c` | 128 | 0 | 1 | (io_mode == SPI_FLASH_OPI_STR) \|\| (io_mode == SP |
| `403833dc` | `FUN_403833dc` | 28 | 0 | 0 |  |
| `403833f8` | `FUN_403833f8` | 7 | 0 | 0 |  |
| `40383400` | `FUN_40383400` | 7 | 0 | 0 |  |
| `40383408` | `FUN_40383408` | 31 | 0 | 0 |  |
| `40383428` | `FUN_40383428` | 7 | 0 | 0 |  |
| `403834e4` | `FUN_403834e4` | 145 | 0 | 0 |  |
| `403838b8` | `FUN_403838b8` | 269 | 1 | 0 |  |
| `403839cc` | `FUN_403839cc` | 35 | 3 | 1 |  |
| `403839f0` | `FUN_403839f0` | 47 | 1 | 0 |  |
| `40383af4` | `FUN_40383af4` | 67 | 1 | 1 |  |
| `40383b38` | `FUN_40383b38` | 21 | 1 | 0 |  |
| `40383b50` | `FUN_40383b50` | 65 | 1 | 0 | K3G3 |
| `40383be4` | `FUN_40383be4` | 24 | 4 | 0 |  |
| `420022f8` | `write_reg` | 93 | 1 | 1 | blk >= 0 && blk < EFUSE_BLK_MAX \| num_reg <= (range_read_add |
| `42002358` | `FUN_42002358` | 120 | 0 | 1 | blk >= 0 && blk < EFUSE_BLK_MAX \| num_reg <= (range_read_add |
| `420025bc` | `FUN_420025bc` | 131 | 0 | 3 | blk >= 0 && blk < EFUSE_BLK_MAX \| num_reg <= (range_read_add |
| `420026dc` | `FUN_420026dc` | 74 | 2 | 1 | blk >= 0 && blk < EFUSE_BLK_MAX \| num_reg <= (range_read_add |
| `42002728` | `FUN_42002728` | 171 | 0 | 1 |  |
| `42002c20` | `FUN_42002c20` | 10 | 0 | 1 |  |
| `42002c2c` | `FUN_42002c2c` | 10 | 0 | 1 |  |
| `42002c38` | `FUN_42002c38` | 38 | 0 | 0 |  |
| `42002c60` | `FUN_42002c60` | 40 | 0 | 4 | flash_ret == ESP_OK |
| `4200302c` | `FUN_4200302c` | 28 | 2 | 0 |  |
| `42003048` | `FUN_42003048` | 188 | 0 | 1 |  |
| `4200319c` | `FUN_4200319c` | 38 | 2 | 0 |  |
| `420031c4` | `FUN_420031c4` | 17 | 1 | 0 |  |
| `420031d8` | `FUN_420031d8` | 162 | 1 | 2 |  |
| `4200327c` | `FUN_4200327c` | 52 | 2 | 3 |  |
| `420032b0` | `FUN_420032b0` | 90 | 3 | 0 |  |
| `4200330c` | `FUN_4200330c` | 66 | 8 | 2 |  |
| `42003350` | `FUN_42003350` | 13 | 0 | 1 |  |
| `42003360` | `FUN_42003360` | 90 | 5 | 2 |  |
| `420033bc` | `FUN_420033bc` | 171 | 2 | 2 | gfff |
| `42003468` | `FUN_42003468` | 126 | 2 | 0 |  |
| `420034e8` | `FUN_420034e8` | 728 | 1 | 12 | Guru Meditation Error: Core  \|  panic'ed ( \| Setting breakpo |
| `42003880` | `FUN_42003880` | 403 | 1 | 11 | Unknown |
| `42003a20` | `FUN_42003a20` | 107 | 0 | 3 |  |
| `42003a8c` | `FUN_42003a8c` | 12 | 1 | 1 |  |
| `42003a98` | `FUN_42003a98` | 31 | 1 | 1 |  |
| `42003adc` | `FUN_42003adc` | 80 | 0 | 1 | Debug exception reason:  \| SingleStep  \| HwBreakpoint  \| Wat |
| `42003b2c` | `FUN_42003b2c` | 82 | 0 | 2 | Memory dump at 0x |
| `42003b80` | `FUN_42003b80` | 213 | 0 | 2 | Icache sync parameter configuration error, the e \| Dcache sy |
| `42003c5c` | `FUN_42003c5c` | 240 | 1 | 4 |  |
| `42003d4c` | `FUN_42003d4c` | 55 | 1 | 0 | Exception was unhandled. \| Unknown |
| `42003d84` | `FUN_42003d84` | 101 | 1 | 1 | Unknown reason |
| `42003dec` | `FUN_42003dec` | 32 | 1 | 1 |  |
| `42003e0c` | `FUN_42003e0c` | 167 | 1 | 6 |  |
| `42003f3c` | `FUN_42003f3c` | 54 | 2 | 2 |  |
| `42003f74` | `FUN_42003f74` | 158 | 1 | 6 |  |
| `42004014` | `FUN_42004014` | 51 | 1 | 1 |  |
| `42004048` | `FUN_42004048` | 83 | 2 | 2 |  |
| `4200409c` | `FUN_4200409c` | 83 | 1 | 2 |  |
| `420040f0` | `FUN_420040f0` | 87 | 1 | 2 |  |
| `42004148` | `FUN_42004148` | 53 | 1 | 2 |  |
| `42004450` | `FUN_42004450` | 39 | 0 | 0 |  |
| `42004478` | `FUN_42004478` | 39 | 2 | 0 |  |
| `420045b8` | `FUN_420045b8` | 10 | 1 | 0 |  |
| `420045c4` | `FUN_420045c4` | 64 | 1 | 7 |  |
| `42004604` | `FUN_42004604` | 58 | 1 | 5 |  |
| `42004640` | `FUN_42004640` | 89 | 1 | 1 |  |
| `4200469c` | `FUN_4200469c` | 41 | 1 | 0 |  |
| `420046c8` | `FUN_420046c8` | 29 | 1 | 1 |  |
| `420046e8` | `FUN_420046e8` | 82 | 2 | 0 |  |
| `420047a8` | `FUN_420047a8` | 181 | 1 | 2 | i == 0 \|\| s_log_cache[(i - 1) / 2].generation <  \| esp_log_c |
| `42004864` | `FUN_42004864` | 22 | 1 | 0 |  |
| `4200487c` | `FUN_4200487c` | 120 | 1 | 1 |  |
| `420048f8` | `FUN_420048f8` | 116 | 1 | 1 |  |
| `4200496c` | `FUN_4200496c` | 17 | 1 | 1 |  |
| `42004980` | `register_heap` | 75 | 2 | 3 | heap_size <= HEAP_SIZE_MAX \| heap_init |
| `420049cc` | `FUN_420049cc` | 43 | 1 | 2 |  |
| `42004cb4` | `s_prepare_reserved_regions` | 757 | 1 | 3 | memory_layout \| memory_layout_utils.c \| s_prepare_reserved_r |
| `42004fb4` | `FUN_42004fb4` | 231 | 5 | 4 |  |
| `4200514c` | `FUN_4200514c` | 164 | 1 | 1 |  |
| `42005814` | `FUN_42005814` | 75 | 3 | 3 |  |
| `42005864` | `FUN_42005864` | 194 | 1 | 5 | 8j7@ |
| `42007830` | `FUN_42007830` | 24 | 1 | 1 |  |
| `42007a40` | `FUN_42007a40` | 50 | 0 | 1 |  |
| `42007a74` | `FUN_42007a74` | 15 | 0 | 1 |  |
| `42007adc` | `FUN_42007adc` | 97 | 1 | 3 |  |
| `42007b40` | `FUN_42007b40` | 13 | 0 | 1 | /dev/console |
| `42007b50` | `FUN_42007b50` | 12 | 1 | 1 |  |
| `42007b5c` | `FUN_42007b5c` | 51 | 1 | 2 |  |
| `42007ce8` | `FUN_42007ce8` | 8 | 1 | 1 |  |
| `42007df0` | `FUN_42007df0` | 37 | 1 | 2 |  |
| `42007e18` | `FUN_42007e18` | 102 | 0 | 3 |  |
| `42007ea0` | `FUN_42007ea0` | 69 | 1 | 3 |  |
| `42008068` | `FUN_42008068` | 166 | 1 | 8 |  |
| `420081b8` | `FUN_420081b8` | 23 | 0 | 0 |  |
| `420081d0` | `FUN_420081d0` | 40 | 0 | 0 |  |
| `420081f8` | `FUN_420081f8` | 38 | 0 | 0 |  |
| `42008220` | `FUN_42008220` | 188 | 0 | 6 |  |
| `4200846c` | `FUN_4200846c` | 173 | 0 | 3 | '9E  \| '9,  |
| `4200854c` | `FUN_4200854c` | 44 | 0 | 2 |  |
| `42008f48` | `FUN_42008f48` | 130 | 2 | 4 |  |
| `42008fcc` | `FUN_42008fcc` | 110 | 1 | 4 | \d7@L |
| `42009190` | `FUN_42009190` | 2138 | 0 | 13 | Gfah |
| `420099fc` | `FUN_420099fc` | 316 | 0 | 4 | *U`U \| (j7@ |
| `4200a0e8` | `FUN_4200a0e8` | 382 | 1 | 9 |  |
| `4200abe0` | `FUN_4200abe0` | 415 | 3 | 8 | uart_wait_tx_done \| uart \| !(is_rs485_mode && disabled && ua |
| `4200b168` | `FUN_4200b168` | 387 | 0 | 13 | uart_driver_delete \| uart \| *3P3 \| (j7@ |
| `4200b604` | `FUN_4200b604` | 26 | 0 | 0 |  |
| `4200b620` | `FUN_4200b620` | 22 | 1 | 0 |  |
| `4200b638` | `FUN_4200b638` | 8 | 1 | 0 |  |
| `4200b640` | `FUN_4200b640` | 40 | 0 | 1 |  |
| `4200b698` | `FUN_4200b698` | 111 | 0 | 5 |  |
| `4200b708` | `FUN_4200b708` | 271 | 0 | 10 |  |
| `4200b818` | `FUN_4200b818` | 129 | 0 | 3 |  |
| `4200bc70` | `FUN_4200bc70` | 15 | 1 | 0 |  |
| `4200bc80` | `FUN_4200bc80` | 15 | 2 | 0 |  |
| `4200bc90` | `FUN_4200bc90` | 37 | 1 | 1 |  |
| `4200bcb8` | `FUN_4200bcb8` | 25 | 1 | 1 |  |
| `4200bcd4` | `FUN_4200bcd4` | 46 | 0 | 0 |  |
| `4200bd48` | `FUN_4200bd48` | 30 | 0 | 1 |  |
| `4200bd68` | `FUN_4200bd68` | 20 | 0 | 1 |  |
| `4200bd94` | `FUN_4200bd94` | 22 | 0 | 1 |  |
| `4200bdac` | `FUN_4200bdac` | 22 | 0 | 1 |  |
| `4200bdc4` | `FUN_4200bdc4` | 22 | 0 | 1 |  |
| `4200bddc` | `FUN_4200bddc` | 18 | 0 | 1 | /dev/uart/0 |
| `4200be08` | `FUN_4200be08` | 20 | 0 | 1 |  |
| `4200be1c` | `FUN_4200be1c` | 18 | 0 | 1 |  |
| `4200be64` | `FUN_4200be64` | 207 | 1 | 1 |  |
| `4200bf38` | `FUN_4200bf38` | 58 | 6 | 1 | strncmp(src_path, vfs->path_prefix, vfs->path_pr |
| `4200c0d8` | `FUN_4200c0d8` | 122 | 6 | 0 |  |
| `4200c23c` | `FUN_4200c23c` | 105 | 2 | 0 |  |
| `4200c2a8` | `FUN_4200c2a8` | 105 | 2 | 0 |  |
| `4200c314` | `FUN_4200c314` | 105 | 2 | 0 |  |
| `4200c41c` | `FUN_4200c41c` | 101 | 3 | 0 |  |
| `4200c484` | `FUN_4200c484` | 105 | 1 | 0 |  |
| `4200c4f0` | `FUN_4200c4f0` | 109 | 1 | 1 |  |
| `4200c560` | `FUN_4200c560` | 78 | 0 | 2 |  |
| `4200c5b0` | `FUN_4200c5b0` | 116 | 0 | 2 |  |
| `4200c628` | `FUN_4200c628` | 80 | 0 | 2 |  |
| `4200c67c` | `FUN_4200c67c` | 123 | 0 | 2 |  |
| `4200c6fc` | `FUN_4200c6fc` | 88 | 1 | 3 |  |
| `4200c758` | `FUN_4200c758` | 71 | 1 | 1 |  |
| `4200c7a4` | `FUN_4200c7a4` | 67 | 2 | 1 |  |
| `4200c7e8` | `FUN_4200c7e8` | 117 | 1 | 1 |  |
| `4200c860` | `FUN_4200c860` | 121 | 0 | 1 |  |
| `4200c8dc` | `FUN_4200c8dc` | 113 | 1 | 1 |  |
| `4200c950` | `FUN_4200c950` | 117 | 0 | 1 |  |
| `4200cc6c` | `FUN_4200cc6c` | 8 | 1 | 1 |  |
| `4200cc74` | `FUN_4200cc74` | 162 | 1 | 6 |  |
| `4200cd4c` | `FUN_4200cd4c` | 18 | 1 | 1 |  |
| `4200cd60` | `FUN_4200cd60` | 223 | 1 | 6 |  |
| `4200ce7c` | `FUN_4200ce7c` | 55 | 1 | 2 |  |
| `4200ceb4` | `FUN_4200ceb4` | 154 | 7 | 3 |  |
| `4200cf50` | `FUN_4200cf50` | 99 | 1 | 3 |  |
| `4200cfb8` | `FUN_4200cfb8` | 13 | 1 | 1 |  |
| `4200cfc8` | `FUN_4200cfc8` | 176 | 1 | 5 |  |
| `4200d0b0` | `FUN_4200d0b0` | 43 | 0 | 1 |  |
| `4200d0dc` | `FUN_4200d0dc` | 78 | 2 | 1 |  |
| `4200d12c` | `FUN_4200d12c` | 132 | 1 | 2 |  |
| `4200d1b4` | `FUN_4200d1b4` | 133 | 1 | 1 |  |
| `4200d23c` | `FUN_4200d23c` | 102 | 1 | 1 |  |
| `4200d2a4` | `ESP_PANIC_DETAILS` | 881 | 1 | 16 | CORE \| ESP_EXTRA_INFO |
| `4200d628` | `FUN_4200d628` | 215 | 1 | 8 | ,b7@(' |
| `4200d700` | `FUN_4200d700` | 8 | 2 | 0 |  |
| `4200d708` | `FUN_4200d708` | 27 | 2 | 0 |  |
| `4200d724` | `FUN_4200d724` | 49 | 1 | 0 |  |
| `4200d758` | `FUN_4200d758` | 12 | 1 | 0 |  |
| `4200d764` | `FUN_4200d764` | 29 | 1 | 0 |  |
| `4200d784` | `FUN_4200d784` | 100 | 1 | 0 |  |
| `4200d7f0` | `FUN_4200d7f0` | 166 | 1 | 1 |  |
| `4200d8d4` | `FUN_4200d8d4` | 52 | 1 | 2 |  |
| `4200d908` | `FUN_4200d908` | 376 | 1 | 1 | task != ((void *)0) && reg_dump != ((void *)0) \| core_dump_p |
| `4200da84` | `FUN_4200da84` | 10 | 1 | 0 |  |
| `4200da90` | `FUN_4200da90` | 17 | 1 | 0 |  |
| `4200daa4` | `FUN_4200daa4` | 52 | 1 | 10 | 3.2.0 |
| `4200dad8` | `frame_echo_hex` | 44 | 1 | 1 | %02X  |
| `4200df08` | `cmd_lock_param2` | 38 | 0 | 2 |  |
| `4200f6c0` | `FUN_4200f6c0` | 132 | 0 | 3 |  |
| `4200f770` | `FUN_4200f770` | 124 | 1 | 3 |  |
| `4200f7ec` | `FUN_4200f7ec` | 80 | 1 | 0 |  |
| `4200f8a0` | `FUN_4200f8a0` | 66 | 1 | 0 |  |
| `4200f9c4` | `channel_slot_set` | 49 | 1 | 2 |  |
| `4200f9f8` | `FUN_4200f9f8` | 42 | 1 | 2 |  |
| `4200fa24` | `FUN_4200fa24` | 42 | 1 | 2 |  |
| `4200fa50` | `axis_slot_set` | 98 | 1 | 4 |  |
| `4200fab4` | `FUN_4200fab4` | 507 | 0 | 5 | 'jJ'j9 |
| `4200fcb4` | `FUN_4200fcb4` | 342 | 1 | 1 |  |
| `4200fe10` | `FUN_4200fe10` | 2023 | 1 | 2 |  |
| `420106bc` | `FUN_420106bc` | 813 | 1 | 7 |  |
| `420109ec` | `FUN_420109ec` | 365 | 0 | 8 | %s(%d) |
| `42010c08` | `FUN_42010c08` | 40 | 1 | 2 |  |
| `42010d3c` | `FUN_42010d3c` | 72 | 1 | 3 |  |
| `42010d84` | `FUN_42010d84` | 233 | 0 | 4 |  |
| `420112b8` | `FUN_420112b8` | 11 | 1 | 2 |  |
| `420128fc` | `FUN_420128fc` | 370 | 0 | 5 |  |
| `42013354` | `FUN_42013354` | 103 | 0 | 0 |  |
| `420133bc` | `FUN_420133bc` | 74 | 0 | 0 |  |
| `42013408` | `FUN_42013408` | 50 | 1 | 0 |  |
| `4201343c` | `FUN_4201343c` | 8 | 0 | 0 |  |
| `420135c0` | `FUN_420135c0` | 128 | 1 | 0 |  |
| `420136c4` | `FUN_420136c4` | 109 | 1 | 0 |  |
| `42013734` | `uart1_frame_parse` | 328 | 1 | 7 |  |
| `42013b20` | `FUN_42013b20` | 197 | 3 | 3 |  |
| `42013bec` | `FUN_42013bec` | 105 | 1 | 2 |  |
| `42013c8c` | `FUN_42013c8c` | 62 | 1 | 1 |  |
| `42013ccc` | `FUN_42013ccc` | 80 | 0 | 4 |  |
| `42013d1c` | `FUN_42013d1c` | 176 | 1 | 3 |  |
| `42013dd0` | `FUN_42013dd0` | 313 | 1 | 3 |  |
| `42013f74` | `FUN_42013f74` | 234 | 0 | 3 |  |
| `42014060` | `FUN_42014060` | 97 | 0 | 5 |  |
| `4201445c` | `FUN_4201445c` | 34 | 0 | 2 |  |
| `42014480` | `FUN_42014480` | 82 | 2 | 2 | b'ELL |
| `420144d4` | `FUN_420144d4` | 132 | 0 | 6 |  |
| `420145cc` | `FUN_420145cc` | 66 | 1 | 0 |  |
| `42014610` | `FUN_42014610` | 344 | 2 | 6 |  |
| `42014770` | `FUN_42014770` | 134 | 2 | 0 |  |
| `420147fc` | `FUN_420147fc` | 120 | 1 | 1 |  |
| `42014874` | `FUN_42014874` | 59 | 0 | 2 |  |
| `420148b0` | `FUN_420148b0` | 77 | 0 | 2 |  |
| `42014900` | `FUN_42014900` | 1322 | 1 | 8 | ep:%02x clear halt \| ep:%02x set halt |
| `42014e44` | `FUN_42014e44` | 805 | 0 | 5 |  |
| `42015170` | `FUN_42015170` | 42 | 1 | 0 |  |
| `4201519c` | `FUN_4201519c` | 51 | 1 | 0 |  |
| `420151d0` | `FUN_420151d0` | 104 | 1 | 3 |  |
| `42015238` | `FUN_42015238` | 50 | 1 | 1 |  |
| `4201526c` | `FUN_4201526c` | 46 | 1 | 0 |  |
| `4201529c` | `FUN_4201529c` | 46 | 1 | 0 |  |
| `42015324` | `FUN_42015324` | 89 | 1 | 0 |  |
| `42015380` | `FUN_42015380` | 32 | 2 | 0 |  |
| `420153a0` | `usbd_ep0` | 204 | 1 | 3 | bus overflow \| No memory to alloc for g_usbd_core[busid].usb |
| `42015470` | `FUN_42015470` | 126 | 1 | 3 | bus overflow |
| `420154f4` | `FUN_420154f4` | 1018 | 1 | 3 |  |
| `420158f0` | `FUN_420158f0` | 242 | 1 | 1 |  |
| `420159e4` | `FUN_420159e4` | 59 | 2 | 0 |  |
| `42015a20` | `FUN_42015a20` | 436 | 2 | 0 | Ep addr %02x overflow \| Ep addr %02x fifo overflow |
| `42015bd8` | `FUN_42015bd8` | 286 | 1 | 0 |  |
| `42015cf8` | `FUN_42015cf8` | 240 | 2 | 0 |  |
| `42015dec` | `FUN_42015dec` | 158 | 1 | 0 |  |
| `42015e8c` | `FUN_42015e8c` | 59 | 1 | 0 |  |
| `42015ec8` | `FUN_42015ec8` | 415 | 3 | 0 |  |
| `42016068` | `FUN_42016068` | 404 | 3 | 0 |  |
| `42016200` | `FUN_42016200` | 1908 | 1 | 6 | 8axQ |
| `4201698c` | `FUN_4201698c` | 10 | 0 | 1 |  |
| `42016998` | `FUN_42016998` | 112 | 1 | 2 |  |
| `42016a08` | `FUN_42016a08` | 39 | 1 | 2 |  |
| `42016a30` | `FUN_42016a30` | 14 | 1 | 1 |  |
| `42016a40` | `FUN_42016a40` | 40 | 1 | 1 |  |
| `42016a68` | `FUN_42016a68` | 14 | 1 | 1 |  |
| `42016a8c` | `FUN_42016a8c` | 64 | 1 | 1 |  |
| `42016acc` | `FUN_42016acc` | 20 | 1 | 1 |  |
| `42016ae0` | `FUN_42016ae0` | 14 | 1 | 1 |  |
| `42016af0` | `FUN_42016af0` | 81 | 2 | 4 |  |
| `42016b44` | `FUN_42016b44` | 108 | 1 | 4 |  |
| `420182c8` | `FUN_420182c8` | 74 | 1 | 4 |  |
| `42019094` | `FUN_42019094` | 24 | 1 | 1 |  |
| `420190ac` | `s_reserve_irom_region` | 412 | 1 | 2 | esp_mmu_map.c \| s_reserve_irom_region \| (mmu_ll_vaddr_to_lad |
| `42019808` | `FUN_42019808` | 38 | 1 | 2 | s_flash_op_mutex != NULL |
| `42019a5c` | `FUN_42019a5c` | 32 | 1 | 2 |  |
| `42019bf4` | `FUN_42019bf4` | 27 | 1 | 3 |  |
| `42019c10` | `FUN_42019c10` | 32 | 2 | 0 |  |
| `42019e34` | `task_wdt_timeout_abort` | 173 | 2 | 6 | task_wdt \| pZ7@ \| ret == pdTRUE \| task_wdt_timeout_abort |
| `42019f30` | `subscribe_idle` | 117 | 1 | 5 | /IDF/components/esp_system/task_wdt/task_wdt.c \| subscribe_i |
| `4201a168` | `FUN_4201a168` | 255 | 2 | 3 | Task watchdog got triggered. The following tasks \| task_wdt  |
| `4201a270` | `task_wdt_isr` | 359 | 0 | 12 | Tasks currently running: \| task_wdt \| cpus_fail != 0 \| task_ |
| `4201a4cc` | `FUN_4201a4cc` | 31 | 1 | 0 |  |
| `4201ab88` | `FUN_4201ab88` | 87 | 0 | 5 |  |
| `4201abe4` | `periph_rtc_dig_clk8m_disable` | 72 | 1 | 4 | s_periph_ref_counts > 0 \| periph_rtc_dig_clk8m_disable |
| `4201ac44` | `FUN_4201ac44` | 107 | 1 | 2 |  |
| `4201add4` | `FUN_4201add4` | 210 | 0 | 7 | (p7@ |
| `4201c784` | `FUN_4201c784` | 26 | 1 | 1 |  |
| `4201fc4c` | `FUN_4201fc4c` | 196 | 3 | 8 |  n7@ |
| `4201fd14` | `FUN_4201fd14` | 18 | 0 | 2 |  |
| `4201fd28` | `FUN_4201fd28` | 305 | 3 | 1 |  |
| `4201fe5c` | `FUN_4201fe5c` | 85 | 7 | 4 |  n7@ |
| `4201feb4` | `FUN_4201feb4` | 38 | 0 | 3 |  |
| `4201fedc` | `FUN_4201fedc` | 111 | 1 | 1 |  |
| `4201ff4c` | `FUN_4201ff4c` | 20 | 0 | 1 |  |
| `4201ff60` | `FUN_4201ff60` | 54 | 0 | 1 |  |
| `4201ff98` | `FUN_4201ff98` | 28 | 0 | 1 |  n7@ |
| `4201ffb4` | `FUN_4201ffb4` | 28 | 0 | 1 |  |
| `4201ffd0` | `FUN_4201ffd0` | 44 | 2 | 1 |  |
| `4201fffc` | `FUN_4201fffc` | 14 | 4 | 1 |  n7@ |
| `4202000c` | `FUN_4202000c` | 14 | 5 | 1 |  |
| `4202001c` | `FUN_4202001c` | 164 | 1 | 5 |  |
| `420200c4` | `FUN_420200c4` | 36 | 8 | 3 |  |
| `42020100` | `FUN_42020100` | 19 | 0 | 2 |  |
| `42020114` | `FUN_42020114` | 183 | 1 | 9 |  n7@ |
| `420201cc` | `FUN_420201cc` | 20 | 1 | 2 |  |
| `420201e0` | `FUN_420201e0` | 21 | 1 | 1 |  |
| `420201f8` | `FUN_420201f8` | 25 | 0 | 2 |  |
| `42020214` | `FUN_42020214` | 668 | 1 | 5 |  |
| `420204c0` | `FUN_420204c0` | 44 | 0 | 1 |  |
| `420204ec` | `FUN_420204ec` | 50 | 4 | 2 |  |
| `4202058c` | `FUN_4202058c` | 115 | 3 | 2 |  |
| `42020600` | `FUN_42020600` | 50 | 0 | 1 |  |
| `42020634` | `FUN_42020634` | 7 | 0 | 0 |  |
| `4202063c` | `FUN_4202063c` | 57 | 0 | 2 |  |
| `42020678` | `FUN_42020678` | 58 | 0 | 1 |  |
| `420206c8` | `FUN_420206c8` | 36 | 1 | 2 |  |
| `420206ec` | `FUN_420206ec` | 25 | 0 | 1 |  |
| `42020708` | `FUN_42020708` | 164 | 4 | 4 |  |
| `420207ac` | `FUN_420207ac` | 705 | 3 | 8 |  n7@ |
| `42020a78` | `FUN_42020a78` | 22 | 0 | 2 |  |
| `42020a90` | `FUN_42020a90` | 195 | 1 | 1 |  |
| `42020b7c` | `FUN_42020b7c` | 24 | 1 | 2 |  |
| `42020bf8` | `FUN_42020bf8` | 25 | 1 | 2 |  |
| `42020c14` | `FUN_42020c14` | 25 | 1 | 2 |  |
| `42020c30` | `FUN_42020c30` | 292 | 0 | 0 |  |
| `42021100` | `FUN_42021100` | 123 | 1 | 2 |  |
| `42023c70` | `FUN_42023c70` | 292 | 0 | 0 |  |
| `42024140` | `FUN_42024140` | 263 | 6 | 6 |  n7@ |
| `42026d70` | `FUN_42026d70` | 33 | 0 | 2 |  |
| `42026d94` | `FUN_42026d94` | 145 | 1 | 4 |  |
| `42026e28` | `FUN_42026e28` | 292 | 1 | 0 |  |
| `420272f8` | `FUN_420272f8` | 34 | 1 | 1 |  |
| `4202731c` | `FUN_4202731c` | 7136 | 2 | 8 |  n7@ \| @@`, \| 0123456789abcdef \| 0123456789ABCDEF \|          |
| `42028f80` | `FUN_42028f80` | 33 | 0 | 2 |  |
| `42028fa4` | `FUN_42028fa4` | 145 | 1 | 4 |  |
| `42029038` | `FUN_42029038` | 107 | 1 | 1 |  |
| `420290a4` | `FUN_420290a4` | 135 | 3 | 3 |  |
| `4202912c` | `FUN_4202912c` | 32 | 0 | 2 |  |
| `4202914c` | `FUN_4202914c` | 236 | 1 | 6 |  |
| `42029240` | `FUN_42029240` | 10 | 0 | 0 |  |
| `4202924c` | `FUN_4202924c` | 15 | 3 | 0 |  |
| `4202925c` | `FUN_4202925c` | 15 | 0 | 0 |  |
| `4202926c` | `FUN_4202926c` | 95 | 0 | 0 |  |
| `420292cc` | `FUN_420292cc` | 309 | 0 | 1 |  |
| `4202a098` | `FUN_4202a098` | 28 | 0 | 1 |  |
| `4202a0b4` | `FUN_4202a0b4` | 32 | 1 | 0 |  |
| `4202a0d4` | `FUN_4202a0d4` | 133 | 7 | 3 | REENT malloc succeeded |
| `4202a15c` | `FUN_4202a15c` | 64 | 3 | 2 | REENT malloc succeeded |
| `4202a19c` | `FUN_4202a19c` | 135 | 2 | 3 | Balloc succeeded |
| `4202a224` | `FUN_4202a224` | 146 | 0 | 3 | Balloc succeeded |
| `4202a2b8` | `FUN_4202a2b8` | 78 | 2 | 0 |  |
| `4202a308` | `FUN_4202a308` | 107 | 1 | 0 |  |
| `4202a374` | `FUN_4202a374` | 40 | 1 | 2 | Balloc succeeded |
| `4202a39c` | `FUN_4202a39c` | 376 | 1 | 2 | Balloc succeeded \| /builds/idf/crosstool-NG/.build/xtensa-es |
| `4202a518` | `FUN_4202a518` | 170 | 0 | 6 | REENT malloc succeeded |
| `4202a5c4` | `FUN_4202a5c4` | 261 | 0 | 3 | Balloc succeeded \| `V YB |
| `4202a6cc` | `FUN_4202a6cc` | 56 | 2 | 0 |  |
| `4202a708` | `FUN_4202a708` | 331 | 0 | 3 | Balloc succeeded \| /builds/idf/crosstool-NG/.build/xtensa-es |
| `4202a854` | `FUN_4202a854` | 76 | 0 | 0 |  |
| `4202a8a0` | `FUN_4202a8a0` | 139 | 1 | 1 |  |
| `4202a92c` | `FUN_4202a92c` | 181 | 0 | 4 | Balloc succeeded |
| `4202a9e4` | `FUN_4202a9e4` | 83 | 0 | 1 |  |
| `4202aa38` | `FUN_4202aa38` | 53 | 0 | 0 |  |
| `4202aa70` | `FUN_4202aa70` | 85 | 0 | 0 |  |
| `4202aac8` | `FUN_4202aac8` | 74 | 0 | 0 |  |
| `4202ab18` | `FUN_4202ab18` | 28 | 0 | 1 |  |
| `4202ab34` | `FUN_4202ab34` | 35 | 1 | 0 |  |
| `4202ab58` | `FUN_4202ab58` | 292 | 0 | 0 |  |
| `4202b028` | `FUN_4202b028` | 261 | 0 | 3 |  |
| `4202ce40` | `FUN_4202ce40` | 5 | 0 | 0 |  |
| `4202ce48` | `FUN_4202ce48` | 7 | 1 | 0 |  |
| `4202ce50` | `FUN_4202ce50` | 7 | 1 | 0 |  |
| `4202ce58` | `FUN_4202ce58` | 8 | 1 | 0 |  |
| `4202ce60` | `FUN_4202ce60` | 7 | 1 | 0 |  |
| `4202ce68` | `FUN_4202ce68` | 88 | 2 | 0 |  |
| `4202cec4` | `FUN_4202cec4` | 68 | 4 | 0 |  |
| `4202cf08` | `FUN_4202cf08` | 40 | 1 | 0 |  |
| `4202cf58` | `FUN_4202cf58` | 12 | 0 | 0 |  |
| `4202cf64` | `FUN_4202cf64` | 7 | 0 | 0 |  |
| `4202cf6c` | `FUN_4202cf6c` | 5 | 0 | 0 |  |
| `4202cf74` | `FUN_4202cf74` | 21 | 2 | 0 |  |
| `4202cf8c` | `FUN_4202cf8c` | 5 | 0 | 0 |  |
| `4202cf94` | `FUN_4202cf94` | 5 | 0 | 0 |  |
| `4202cf9c` | `FUN_4202cf9c` | 5 | 0 | 0 |  |
| `4202cfa4` | `FUN_4202cfa4` | 5 | 0 | 0 |  |
| `4202cfac` | `FUN_4202cfac` | 11 | 1 | 0 |  |
| `4202cfb8` | `FUN_4202cfb8` | 5 | 0 | 0 |  |
| `4202cfc0` | `FUN_4202cfc0` | 5 | 0 | 0 |  |
| `4202cfc8` | `FUN_4202cfc8` | 5 | 0 | 0 |  |
| `4202cfd0` | `FUN_4202cfd0` | 5 | 0 | 0 |  |
| `4202cfd8` | `FUN_4202cfd8` | 5 | 0 | 0 |  |
| `4202cfe0` | `FUN_4202cfe0` | 5 | 0 | 0 |  |
| `4202cfe8` | `FUN_4202cfe8` | 5 | 0 | 0 |  |
| `4202cff0` | `FUN_4202cff0` | 5 | 0 | 0 |  |
| `4202cff8` | `FUN_4202cff8` | 5 | 0 | 0 |  |
| `4202d000` | `FUN_4202d000` | 5 | 0 | 0 |  |
| `4202d008` | `FUN_4202d008` | 5 | 0 | 0 |  |
| `4202d010` | `FUN_4202d010` | 7 | 0 | 0 |  |
| `4202d018` | `FUN_4202d018` | 5 | 0 | 0 |  |
| `4202d020` | `FUN_4202d020` | 5 | 0 | 0 |  |
| `4202d028` | `FUN_4202d028` | 5 | 0 | 0 |  |
| `4202d030` | `FUN_4202d030` | 5 | 0 | 0 |  |
| `4202d038` | `FUN_4202d038` | 5 | 0 | 0 |  |
| `4202d040` | `FUN_4202d040` | 5 | 0 | 0 |  |
| `4202d048` | `FUN_4202d048` | 5 | 1 | 0 |  |
| `4202d050` | `FUN_4202d050` | 5 | 1 | 0 |  |
| `4202d058` | `FUN_4202d058` | 7 | 2 | 0 |  |
| `4202d060` | `FUN_4202d060` | 14 | 1 | 0 |  |
| `4202d070` | `FUN_4202d070` | 13 | 1 | 0 |  |
| `4202d080` | `FUN_4202d080` | 7 | 1 | 0 |  |
| `4202d088` | `FUN_4202d088` | 5 | 0 | 0 |  |
| `4202d090` | `FUN_4202d090` | 118 | 1 | 0 |  |
| `4202d108` | `FUN_4202d108` | 72 | 2 | 0 |  |
| `4202d150` | `FUN_4202d150` | 90 | 1 | 0 |  |
| `4202d60c` | `FUN_4202d60c` | 22 | 1 | 0 |  |
| `4202d624` | `FUN_4202d624` | 16 | 0 | 0 |  |
| `4202d634` | `FUN_4202d634` | 7 | 1 | 0 |  |
| `4202d98c` | `FUN_4202d98c` | 53 | 4 | 0 |  |
| `4202d9c4` | `FUN_4202d9c4` | 123 | 1 | 0 |  |
| `4202da48` | `FUN_4202da48` | 36 | 1 | 0 |  |
| `4202da6c` | `FUN_4202da6c` | 387 | 1 | 0 | '9CfB \| !'Lf |
| `4202dc00` | `FUN_4202dc00` | 383 | 1 | 0 | '9CfB \| !MKF |
| `4202dd8c` | `FUN_4202dd8c` | 30 | 5 | 2 |  |
| `4202ddac` | `FUN_4202ddac` | 31 | 5 | 2 |  |
| `4202ddcc` | `FUN_4202ddcc` | 341 | 1 | 6 | periph < PERIPH_MODULE_MAX \| periph_module_enable |
| `4202e75c` | `FUN_4202e75c` | 18 | 0 | 0 |  |
| `4202e770` | `main_task` | 195 | 0 | 9 | main_task \| esp_task_wdt_init(&twdt_config) |
| `4202e834` | `FUN_4202e834` | 104 | 1 | 7 | main \| esp_startup_start_app \| res == pdTRUE |
| `4202e89c` | `FUN_4202e89c` | 167 | 0 | 8 | app_start \| \d7@L |
| `4202e948` | `FUN_4202e948` | 63 | 1 | 4 | xResult == ( ( BaseType_t ) 1 ) \| \d7@L |
| `4202e988` | `FUN_4202e988` | 117 | 0 | 5 | \d7@L |
| `4202ea00` | `FUN_4202ea00` | 55 | 1 | 4 | xResult == ( ( BaseType_t ) 1 ) \| \d7@L |
| `4202ea38` | `FUN_4202ea38` | 161 | 1 | 2 | kStartScheduler \| rtScheduler |
| `4202eb90` | `FUN_4202eb90` | 76 | 1 | 3 | start_ptr |
| `4202ebe0` | `FUN_4202ebe0` | 127 | 1 | 8 |  |
| `4202ec60` | `FUN_4202ec60` | 38 | 0 | 0 |  |
| `4202ec88` | `FUN_4202ec88` | 32 | 0 | 1 | used \| free |
| `4202eca8` | `FUN_4202eca8` | 83 | 1 | 1 | !block_is_last(block) |
| `4202ecfc` | `FUN_4202ecfc` | 87 | 1 | 0 |  |
| `4202ed54` | `FUN_4202ed54` | 38 | 1 | 1 |  |
| `4202eeb4` | `FUN_4202eeb4` | 284 | 1 | 2 | ,878 \| ALIGN_SIZE == control->small_block_size / contro |
| `4202efd4` | `FUN_4202efd4` | 34 | 1 | 2 |  |

## left / idf/gpio (135)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4037622c` | `FUN_4037622c` | 24 | 3 | 2 |  |
| `40376244` | `FUN_40376244` | 17 | 1 | 0 |  |
| `40376280` | `FUN_40376280` | 62 | 1 | 0 |  |
| `403762c0` | `FUN_403762c0` | 59 | 1 | 0 |  |
| `403770dc` | `FUN_403770dc` | 40 | 1 | 1 |  |
| `40377104` | `FUN_40377104` | 40 | 1 | 1 |  |
| `4037b230` | `FUN_4037b230` | 219 | 1 | 0 |  |
| `40381bb0` | `FUN_40381bb0` | 101 | 142 | 4 |  |
| `40381c18` | `FUN_40381c18` | 70 | 106 | 2 |  |
| `40381ecc` | `FUN_40381ecc` | 19 | 0 | 0 |  |
| `40381ee0` | `memspi` | 130 | 0 | 1 | memspi |
| `4038217c` | `FUN_4038217c` | 45 | 0 | 0 |  |
| `403821ac` | `FUN_403821ac` | 31 | 0 | 0 |  |
| `403821cc` | `FUN_403821cc` | 7 | 0 | 0 |  |
| `403821d4` | `FUN_403821d4` | 47 | 0 | 0 |  |
| `40382208` | `FUN_40382208` | 29 | 0 | 0 |  |
| `40382228` | `FUN_40382228` | 26 | 0 | 1 |  |
| `40382244` | `FUN_40382244` | 31 | 0 | 0 |  |
| `40382264` | `FUN_40382264` | 60 | 0 | 1 | X,8@ \| h-8@ |
| `403822a0` | `FUN_403822a0` | 20 | 0 | 0 |  |
| `403822b4` | `FUN_403822b4` | 62 | 0 | 0 |  |
| `403822f4` | `FUN_403822f4` | 316 | 0 | 0 | &I,!x |
| `4038262c` | `FUN_4038262c` | 145 | 0 | 1 | chip_generic |
| `403827ac` | `FUN_403827ac` | 190 | 3 | 1 | chip_generic |
| `40382870` | `FUN_40382870` | 24 | 0 | 1 | X,8@ |
| `40382890` | `FUN_40382890` | 92 | 0 | 0 |  |
| `403828ec` | `FUN_403828ec` | 134 | 0 | 0 |  |
| `40382974` | `FUN_40382974` | 146 | 0 | 0 |  |
| `40382a08` | `FUN_40382a08` | 146 | 0 | 0 |  |
| `40382a9c` | `FUN_40382a9c` | 82 | 0 | 0 |  |
| `40382af0` | `FUN_40382af0` | 18 | 0 | 0 |  |
| `40382db8` | `FUN_40382db8` | 20 | 0 | 1 | 8-8@ |
| `40382dcc` | `FUN_40382dcc` | 26 | 0 | 1 |  |
| `40382de8` | `FUN_40382de8` | 7 | 0 | 0 |  |
| `40382df0` | `FUN_40382df0` | 62 | 0 | 0 |  |
| `40382e30` | `FUN_40382e30` | 32 | 0 | 0 |  |
| `40382e50` | `FUN_40382e50` | 7 | 0 | 0 |  |
| `40382e58` | `FUN_40382e58` | 47 | 0 | 0 |  |
| `40382e8c` | `FUN_40382e8c` | 106 | 0 | 0 |  |
| `40382ef8` | `FUN_40382ef8` | 134 | 0 | 0 |  |
| `40382f80` | `FUN_40382f80` | 140 | 0 | 0 |  |
| `4038300c` | `FUN_4038300c` | 140 | 0 | 0 |  |
| `40383098` | `FUN_40383098` | 50 | 0 | 0 |  |
| `40383160` | `FUN_40383160` | 132 | 0 | 0 |  |
| `403831e4` | `FUN_403831e4` | 217 | 0 | 2 | (io_mode == SPI_FLASH_OPI_STR) \|\| (io_mode == SP |
| `403836ac` | `FUN_403836ac` | 65 | 1 | 1 | Octal Flash |
| `403836f0` | `FUN_403836f0` | 30 | 0 | 0 |  |
| `40383710` | `FUN_40383710` | 317 | 1 | 1 |  |
| `40383850` | `FUN_40383850` | 103 | 1 | 4 | Octal Flash |
| `42001fcc` | `FUN_42001fcc` | 70 | 1 | 0 |  |
| `42002014` | `app_init` | 216 | 0 | 2 | app_init \| project-name \| 15:00:57 \| May  4 2025 |
| `420020ec` | `FUN_420020ec` | 16 | 0 | 2 |  |
| `420020fc` | `efuse_init` | 148 | 0 | 3 | Db7@,b7@(' \| efuse_init \| (constraint ignored) \| ,b7@(' |
| `42002238` | `FUN_42002238` | 104 | 2 | 6 | Pm7@L |
| `420022a4` | `FUN_420022a4` | 67 | 1 | 2 |  |
| `420022ec` | `FUN_420022ec` | 10 | 1 | 1 |  |
| `42002550` | `FUN_42002550` | 65 | 2 | 1 |  |
| `42002594` | `FUN_42002594` | 40 | 1 | 1 |  |
| `420027d8` | `FUN_420027d8` | 151 | 1 | 2 | efuse |
| `42002874` | `FUN_42002874` | 11 | 1 | 2 |  |
| `42002880` | `FUN_42002880` | 614 | 1 | 11 | efuse |
| `42002aec` | `FUN_42002aec` | 17 | 1 | 1 |  |
| `42002b00` | `FUN_42002b00` | 114 | 1 | 4 | efuse |
| `42002b74` | `FUN_42002b74` | 48 | 1 | 0 |  |
| `42002ba8` | `FUN_42002ba8` | 113 | 3 | 4 | cpu_start |
| `42002c88` | `FUN_42002c88` | 16 | 1 | 0 |  |
| `420037c4` | `FUN_420037c4` | 185 | 0 | 5 | cpu_start \| D (%lu) %s: calling init function: %p |
| `420041a8` | `FUN_420041a8` | 97 | 1 | 0 |  |
| `4200420c` | `FUN_4200420c` | 156 | 2 | 0 |  |
| `420042a8` | `FUN_420042a8` | 11 | 2 | 0 |  |
| `420042b4` | `FUN_420042b4` | 316 | 1 | 1 | block < ETS_EFUSE_BLOCK_MAX |
| `420043f0` | `FUN_420043f0` | 15 | 1 | 0 |  |
| `42004400` | `FUN_42004400` | 80 | 1 | 0 |  |
| `42005928` | `FUN_42005928` | 216 | 1 | 5 | sleep_gpio \| $}7@4> |
| `42005a00` | `Enable` | 141 | 1 | 4 | Enable \| sleep_gpio \| Disable |
| `42005a90` | `FUN_42005a90` | 17 | 0 | 2 |  |
| `42007ffc` | `FUN_42007ffc` | 15 | 0 | 2 |  |
| `4200800c` | `FUN_4200800c` | 90 | 1 | 5 | system_time |
| `42009144` | `FUN_42009144` | 74 | 1 | 1 | uart |
| `42011204` | `FUN_42011204` | 177 | 1 | 6 | EFUSE_BURN |
| `420112c4` | `FUN_420112c4` | 618 | 1 | 2 | PARSE |
| `42011534` | `FUN_42011534` | 77 | 1 | 3 | PARSE |
| `42011584` | `FUN_42011584` | 65 | 1 | 2 | PARSE |
| `420115c8` | `FUN_420115c8` | 342 | 1 | 2 | PARSE |
| `42011728` | `FUN_42011728` | 419 | 1 | 2 | PARSE |
| `420118d4` | `FUN_420118d4` | 97 | 1 | 2 | PARSE |
| `42011938` | `FUN_42011938` | 860 | 1 | 3 | PARSE |
| `42011ca0` | `UNKNOWN_BUTTON` | 150 | 1 | 0 | BUTTON_MIDDLE \| BUTTON_SIDE1 \| BUTTON_LEFT \| UNKNOWN_BUTTON  |
| `42011d3c` | `FUN_42011d3c` | 111 | 1 | 3 | PARSE |
| `42011dac` | `FUN_42011dac` | 139 | 1 | 2 | rbn' \| rbp' \| PARSE \| X-axis |
| `42011e3c` | `FUN_42011e3c` | 124 | 1 | 2 | rbr' \| rbt' \| PARSE \| Tilt |
| `42011ebc` | `Feature` | 1330 | 1 | 8 | PARSE \| Input \| Feature \| Feature (array) |
| `42012404` | `FUN_42012404` | 124 | 1 | 0 |  |
| `42012480` | `FUN_42012480` | 1134 | 1 | 11 | PARSE \| false \| true |
| `42014214` | `FUN_42014214` | 39 | 1 | 3 |  |
| `42016bb0` | `phy_configure_pin_input` | 139 | 1 | 3 | phy_configure_pin_input |
| `42016c40` | `phy_configure_pin_output` | 133 | 1 | 2 | phy_configure_pin_output |
| `42016cc8` | `otg_sig` | 352 | 1 | 3 | usb_phy_otg_set_mode \| usb_phy \| otg_sig |
| `4201757c` | `gpio_sleep_pulldown_dis` | 132 | 1 | 4 | GPIO number error \| gpio_sleep_pulldown_dis |
| `42017604` | `gpio_sleep_pulldown_en` | 132 | 1 | 4 | GPIO number error \| gpio_sleep_pulldown_en |
| `4201768c` | `gpio_sleep_pullup_dis` | 132 | 1 | 4 | GPIO number error \| gpio_sleep_pullup_dis |
| `42017714` | `gpio_sleep_pullup_en` | 132 | 1 | 4 | GPIO number error \| gpio_sleep_pullup_en |
| `4201779c` | `gpio_input_disable` | 111 | 1 | 2 | GPIO number error \| gpio_input_disable |
| `4201780c` | `gpio_pullup_en` | 152 | 2 | 5 | GPIO number error \| gpio_pullup_en |
| `420178a4` | `gpio_pullup_dis` | 188 | 1 | 5 | GPIO number error \| gpio_pullup_dis |
| `42017964` | `gpio_pulldown_en` | 151 | 1 | 5 | GPIO number error \| gpio_pulldown_en |
| `420179fc` | `gpio_pulldown_dis` | 148 | 1 | 5 | GPIO number error \| gpio_pulldown_dis |
| `42017a94` | `gpio_set_intr_type` | 238 | 1 | 4 | GPIO number error \| GPIO interrupt type error \| gpio_set_int |
| `42017b88` | `gpio_intr_enable` | 149 | 1 | 5 | GPIO number error \| gpio_intr_enable |
| `42017c20` | `gpio_intr_disable` | 109 | 2 | 3 | GPIO number error \| gpio_intr_disable |
| `42017c90` | `gpio_input_enable` | 123 | 3 | 2 | GPIO number error \| gpio_input_enable |
| `42017d0c` | `gpio_output_disable` | 173 | 1 | 2 | GPIO number error \| gpio_output_disable |
| `42017dbc` | `gpio_output_enable` | 173 | 1 | 2 | GPIO output gpio_num error \| gpio_output_enable |
| `42017e6c` | `gpio_od_disable` | 128 | 1 | 2 | GPIO number error \| gpio_od_disable |
| `42017ef0` | `gpio_od_enable` | 128 | 1 | 2 | GPIO number error \| gpio_od_enable |
| `42017f70` | `gpio_set_level` | 179 | 4 | 2 | GPIO output gpio_num error \| gpio_set_level |
| `42018028` | `FUN_42018028` | 451 | 2 | 17 | gpio |
| `420181f4` | `gpio_isr_handler_add` | 206 | 1 | 7 | GPIO isr service is not installed, call gpio_ins \| gpio_isr_ |
| `42018314` | `gpio_isr_register` | 179 | 1 | 5 | GPIO ISR null \| gpio_isr_register \| gpio |
| `420183cc` | `gpio_install_isr_service` | 157 | 1 | 8 | GPIO isr service already installed \| gpio_install_isr_servic |
| `4201846c` | `gpio_set_drive_capability` | 200 | 1 | 5 | GPIO number error \| GPIO drive capability error \| gpio_set_d |
| `420185f0` | `gpio_sleep_set_direction` | 410 | 1 | 2 | GPIO number error \| gpio_sleep_set_direction \| gpio \| gpio_s |
| `42018790` | `gpio_sleep_set_pull_mode` | 187 | 1 | 6 | GPIO number error \| GPIO pull mode error \| gpio_sleep_set_pu |
| `42018854` | `gpio_sleep_sel_en` | 144 | 1 | 4 | GPIO number error \| gpio_sleep_sel_en |
| `420188e8` | `gpio_sleep_sel_dis` | 144 | 1 | 4 | GPIO number error \| gpio_sleep_sel_dis |
| `4201897c` | `gpio_func_sel` | 166 | 1 | 2 | GPIO number error \| gpio_func_sel |
| `42018a24` | `FUN_42018a24` | 27 | 6 | 0 |  |
| `4201924c` | `FUN_4201924c` | 58 | 1 | 2 | esp_mmu_map |
| `4201e724` | `FUN_4201e724` | 29 | 1 | 1 |  |
| `4202ce28` | `FUN_4202ce28` | 14 | 2 | 0 |  |
| `4202ce38` | `FUN_4202ce38` | 7 | 1 | 0 |  |
| `4202d4dc` | `map_entry_write` | 32 | 0 | 0 |  |
| `4202d4fc` | `FUN_4202d4fc` | 127 | 1 | 0 |  |
| `4202eadc` | `FUN_4202eadc` | 92 | 2 | 0 |  |
| `4202eb3c` | `FUN_4202eb3c` | 82 | 1 | 0 |  |

## left / idf/heap (28)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `403762fc` | `FUN_403762fc` | 22 | 5 | 0 |  |
| `40376334` | `heap_caps_malloc_default` | 108 | 4 | 2 | heap_caps_malloc \| heap_caps_malloc_default |
| `403763a4` | `heap_caps_realloc_default` | 114 | 1 | 2 | heap_caps_realloc \| heap_caps_realloc_default |
| `40376438` | `heap_caps_calloc` | 36 | 2 | 2 | heap_caps_calloc |
| `4037645c` | `heap_caps_free` | 74 | 11 | 2 | heap != NULL && 'free() target pointer is outsid \| heap_caps |
| `403764a8` | `dram_alloc_to_iram_addr` | 347 | 2 | 4 | esp_ptr_in_diram_dram((void *)dstart) \|\| esp_ptr \| heap_caps |
| `40376608` | `FUN_40376608` | 16 | 3 | 1 |  |
| `40376618` | `heap_caps_realloc_base` | 320 | 2 | 6 | heap != NULL && 'realloc() pointer is outside he \| heap_caps |
| `40376760` | `FUN_40376760` | 39 | 1 | 1 |  |
| `40377e80` | `FUN_40377e80` | 114 | 2 | 1 |  |
| `403808b0` | `FUN_403808b0` | 42 | 2 | 2 | CORRUPT HEAP: multi_heap.c:%d detected at 0x%08x |
| `403808dc` | `FUN_403808dc` | 117 | 1 | 6 |  |
| `40380954` | `FUN_40380954` | 86 | 1 | 7 |  |
| `403809ac` | `FUN_403809ac` | 12 | 1 | 1 |  |
| `403809b8` | `FUN_403809b8` | 97 | 3 | 6 |  |
| `40380a1c` | `multi_heap_realloc_impl` | 119 | 1 | 8 | heap != NULL \| multi_heap_realloc_impl |
| `40380aa0` | `FUN_40380aa0` | 7 | 4 | 0 |  |
| `40380aa8` | `FUN_40380aa8` | 22 | 5 | 0 |  |
| `40380ac0` | `tlsf_free` | 886 | 2 | 1 | !block_is_free(block) && 'block already marked a \| !block_is |
| `40380e38` | `FUN_40380e38` | 11 | 2 | 0 |  |
| `40380e44` | `block_prepare_used` | 881 | 2 | 1 | 0 == (align & (align - 1)) && 'must align to a p \| block_siz |
| `403811bc` | `tlsf_memalign_offs` | 1335 | 1 | 1 | 0 == (align & (align - 1)) && 'must align to a p \| tlsf_cont |
| `40381700` | `tlsf_realloc` | 1064 | 1 | 3 | !block_is_last(block) \| tlsf_block_functions.h \| block_next  |
| `40381e44` | `FUN_40381e44` | 35 | 1 | 1 |  |
| `420049f8` | `heap_caps_init` | 647 | 1 | 8 | heap_init \| heap_idx <= num_heaps \| heap_idx == num_heaps \|  |
| `42004c8c` | `FUN_42004c8c` | 10 | 0 | 1 |  |
| `42004c98` | `FUN_42004c98` | 26 | 1 | 0 |  |
| `4202cf30` | `FUN_4202cf30` | 38 | 1 | 0 |  |

## left / idf/nvs (119)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4037e090` | `FUN_4037e090` | 48 | 2 | 0 |  |
| `40381dd8` | `FUN_40381dd8` | 12 | 21 | 1 |  |
| `42004180` | `FUN_42004180` | 38 | 8 | 0 | ESP_FAIL \| ERROR |
| `42007ee8` | `FUN_42007ee8` | 41 | 2 | 1 |  |
| `42007f14` | `FUN_42007f14` | 225 | 1 | 7 |  |
| `42012eac` | `FUN_42012eac` | 495 | 0 | 9 | storage \| true (115200) \| false (4 Mbps) \| config \| baud_rat |
| `420130a4` | `config_load` | 220 | 2 | 6 | storage \| config \| baud_rate |
| `42013188` | `FUN_42013188` | 451 | 1 | 10 | storage \| config |
| `42019070` | `FUN_42019070` | 8 | 2 | 0 |  |
| `4201afcc` | `nvs_open_from_partition` | 148 | 1 | 7 | nvs_open_from_partition |
| `4201b060` | `FUN_4201b060` | 110 | 1 | 3 |  |
| `4201b0d0` | `FUN_4201b0d0` | 38 | 1 | 5 |  |
| `4201b0f8` | `FUN_4201b0f8` | 79 | 1 | 8 |  |
| `4201b14c` | `FUN_4201b14c` | 30 | 3 | 2 |  |
| `4201b16c` | `nvs_close` | 126 | 3 | 5 | nvs_close \| D (%lu) %s: %s %d |
| `4201b1ec` | `nvs_set` | 103 | 1 | 4 | nvs_set |
| `4201b254` | `FUN_4201b254` | 53 | 1 | 2 |  |
| `4201b28c` | `nvs_get` | 94 | 2 | 4 | nvs_get |
| `4201b2ec` | `FUN_4201b2ec` | 326 | 3 | 3 |  |
| `4201b438` | `FUN_4201b438` | 93 | 2 | 2 |  |
| `4201b498` | `FUN_4201b498` | 165 | 1 | 2 |  |
| `4201b544` | `FUN_4201b544` | 441 | 1 | 3 |  |
| `4201b704` | `FUN_4201b704` | 263 | 1 | 2 |  |
| `4201b810` | `FUN_4201b810` | 416 | 1 | 7 |  |
| `4201b9b8` | `FUN_4201b9b8` | 557 | 1 | 7 |  |
| `4201bbf0` | `FUN_4201bbf0` | 310 | 1 | 3 |  |
| `4201bd2c` | `FUN_4201bd2c` | 247 | 1 | 2 |  |
| `4201be2c` | `FUN_4201be2c` | 686 | 2 | 9 |  |
| `4201c0ec` | `FUN_4201c0ec` | 36 | 3 | 1 |  |
| `4201c110` | `FUN_4201c110` | 243 | 1 | 2 |  |
| `4201c208` | `FUN_4201c208` | 28 | 1 | 1 |  |
| `4201c224` | `FUN_4201c224` | 141 | 3 | 3 |  |
| `4201c2b4` | `FUN_4201c2b4` | 159 | 1 | 3 |  |
| `4201c358` | `FUN_4201c358` | 67 | 1 | 1 |  |
| `4201c3a0` | `FUN_4201c3a0` | 82 | 1 | 1 |  |
| `4201c3f4` | `FUN_4201c3f4` | 150 | 1 | 1 |  |
| `4201c48c` | `FUN_4201c48c` | 108 | 1 | 1 |  |
| `4201c4fc` | `FUN_4201c4fc` | 16 | 0 | 0 |  |
| `4201c50c` | `FUN_4201c50c` | 20 | 0 | 2 |  |
| `4201c520` | `FUN_4201c520` | 40 | 0 | 1 |  |
| `4201c548` | `FUN_4201c548` | 38 | 0 | 1 |  |
| `4201c570` | `FUN_4201c570` | 36 | 0 | 1 |  |
| `4201c594` | `Spoofed` | 52 | 0 | 1 |  |
| `4201c5c8` | `FUN_4201c5c8` | 36 | 0 | 1 |  |
| `4201c5ec` | `FUN_4201c5ec` | 54 | 0 | 1 |  |
| `4201c624` | `FUN_4201c624` | 36 | 0 | 1 |  |
| `4201c648` | `FUN_4201c648` | 36 | 0 | 1 |  |
| `4201c66c` | `FUN_4201c66c` | 34 | 0 | 1 |  |
| `4201c690` | `FUN_4201c690` | 44 | 0 | 1 |  |
| `4201c6bc` | `FUN_4201c6bc` | 42 | 0 | 1 |  |
| `4201c6e8` | `FUN_4201c6e8` | 28 | 0 | 3 |  |
| `4201c7b0` | `FUN_4201c7b0` | 52 | 6 | 1 |  |
| `4201c7e4` | `FUN_4201c7e4` | 53 | 2 | 0 |  |
| `4201c81c` | `FUN_4201c81c` | 36 | 5 | 0 |  |
| `4201c840` | `FUN_4201c840` | 199 | 1 | 5 |  |
| `4201c90c` | `FUN_4201c90c` | 131 | 1 | 4 |  |
| `4201c990` | `FUN_4201c990` | 193 | 1 | 3 |  |
| `4201ca54` | `FUN_4201ca54` | 174 | 1 | 3 |  |
| `4201cb08` | `FUN_4201cb08` | 14 | 7 | 1 |  |
| `4201cb18` | `FUN_4201cb18` | 14 | 7 | 1 |  |
| `4201cb28` | `FUN_4201cb28` | 53 | 2 | 1 |  |
| `4201cb60` | `FUN_4201cb60` | 10 | 2 | 1 |  |
| `4201cb6c` | `FUN_4201cb6c` | 120 | 3 | 2 |  |
| `4201cc84` | `FUN_4201cc84` | 70 | 1 | 1 |  |
| `4201cccc` | `FUN_4201cccc` | 41 | 1 | 1 |  |
| `4201ccf8` | `FUN_4201ccf8` | 107 | 2 | 0 |  |
| `4201cd64` | `FUN_4201cd64` | 92 | 2 | 1 |  |
| `4201cdc0` | `FUN_4201cdc0` | 236 | 2 | 3 |  |
| `4201ceb0` | `FUN_4201ceb0` | 116 | 0 | 1 |  |
| `4201cf28` | `FUN_4201cf28` | 395 | 2 | 5 |  |
| `4201d0e8` | `FUN_4201d0e8` | 339 | 5 | 4 |  |
| `4201d244` | `FUN_4201d244` | 599 | 18 | 3 | 76\F \| IDLEipc0ipc1\ |
| `4201d4b0` | `FUN_4201d4b0` | 286 | 2 | 3 |  |
| `4201d5e0` | `FUN_4201d5e0` | 276 | 2 | 2 |  |
| `4201d70c` | `FUN_4201d70c` | 58 | 8 | 2 |  |
| `4201d748` | `FUN_4201d748` | 663 | 1 | 5 |  |
| `4201dafc` | `FUN_4201dafc` | 316 | 1 | 3 |  |
| `4201dc44` | `FUN_4201dc44` | 41 | 1 | 0 |  |
| `4201dc70` | `FUN_4201dc70` | 19 | 1 | 0 |  |
| `4201dc84` | `FUN_4201dc84` | 55 | 3 | 1 |  |
| `4201dcbc` | `FUN_4201dcbc` | 51 | 1 | 0 |  |
| `4201dcf0` | `FUN_4201dcf0` | 47 | 2 | 0 |  |
| `4201dd20` | `FUN_4201dd20` | 45 | 1 | 0 |  |
| `4201dd50` | `FUN_4201dd50` | 13 | 0 | 1 |  |
| `4201dd60` | `FUN_4201dd60` | 108 | 2 | 2 |  |
| `4201ddd0` | `FUN_4201ddd0` | 198 | 2 | 4 |  |
| `4201de98` | `FUN_4201de98` | 889 | 1 | 11 | hc)c |
| `4201e228` | `FUN_4201e228` | 62 | 1 | 3 |  |
| `4201e26c` | `FUN_4201e26c` | 44 | 1 | 0 |  |
| `4201e298` | `FUN_4201e298` | 40 | 2 | 0 |  |
| `4201e2c0` | `FUN_4201e2c0` | 20 | 3 | 0 |  |
| `4201e2d4` | `FUN_4201e2d4` | 552 | 3 | 2 |  |
| `4201e590` | `FUN_4201e590` | 14 | 1 | 1 |  |
| `4201e5a0` | `FUN_4201e5a0` | 16 | 1 | 0 |  |
| `4201e5b0` | `FUN_4201e5b0` | 19 | 1 | 1 |  |
| `4201e5e4` | `FUN_4201e5e4` | 85 | 1 | 2 |  |
| `4201e63c` | `FUN_4201e63c` | 92 | 0 | 3 |  |
| `4201e69c` | `FUN_4201e69c` | 36 | 0 | 2 |  |
| `4201e6c0` | `FUN_4201e6c0` | 30 | 1 | 1 |  |
| `4201e6e0` | `FUN_4201e6e0` | 66 | 1 | 4 |  |
| `4201e744` | `FUN_4201e744` | 34 | 1 | 2 |  |
| `4201e770` | `FUN_4201e770` | 15 | 3 | 1 |  |
| `4201e780` | `FUN_4201e780` | 16 | 1 | 1 |  |
| `4201e790` | `FUN_4201e790` | 62 | 1 | 4 |  |
| `4201ea1c` | `FUN_4201ea1c` | 12 | 2 | 1 |  |
| `4201ea34` | `FUN_4201ea34` | 12 | 1 | 1 |  |
| `4201ea40` | `FUN_4201ea40` | 12 | 1 | 1 |  |
| `4202d778` | `FUN_4202d778` | 7 | 0 | 0 |  |
| `4202d780` | `FUN_4202d780` | 5 | 0 | 0 |  |
| `4202d788` | `FUN_4202d788` | 18 | 1 | 0 |  |
| `4202d79c` | `FUN_4202d79c` | 10 | 0 | 0 |  |
| `4202d7a8` | `FUN_4202d7a8` | 9 | 0 | 0 |  |
| `4202d7b4` | `FUN_4202d7b4` | 9 | 0 | 0 |  |
| `4202d7c0` | `FUN_4202d7c0` | 10 | 0 | 0 |  |
| `4202d7cc` | `FUN_4202d7cc` | 5 | 0 | 0 |  |
| `4202d7d4` | `FUN_4202d7d4` | 7 | 3 | 0 |  |
| `4202d7dc` | `FUN_4202d7dc` | 13 | 1 | 0 |  |
| `4202d7ec` | `FUN_4202d7ec` | 88 | 3 | 0 |  |
| `4202d844` | `FUN_4202d844` | 48 | 2 | 0 |  |

## left / idf/spi (26)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40377e00` | `FUN_40377e00` | 21 | 1 | 3 |  |
| `40377e18` | `FUN_40377e18` | 26 | 1 | 3 |  |
| `40377f70` | `spi_flash_disable_interrupts_caches_and_other_cpu` | 183 | 3 | 8 | esp_task_stack_is_sane_cache_disabled() \| s_flash_op_cpu ==  |
| `40378028` | `spi_flash_enable_interrupts_caches_and_other_cpu` | 110 | 3 | 6 | cpuid == s_flash_op_cpu \| !(xTaskGetSchedulerState() == task |
| `40378c38` | `spi_flash_os_check_yield` | 69 | 0 | 2 | chip_status == 0 |
| `40378d1c` | `FUN_40378d1c` | 8 | 1 | 1 |  |
| `40378d24` | `FUN_40378d24` | 10 | 0 | 1 |  |
| `40378d30` | `FUN_40378d30` | 8 | 1 | 1 |  |
| `40378f84` | `FUN_40378f84` | 7 | 1 | 0 |  |
| `40379268` | `FUN_40379268` | 7 | 1 | 0 |  |
| `4037f138` | `mmu_hal_unmap_region` | 131 | 1 | 1 | vaddr % page_size_in_bytes == 0 \| mmu_hal_check_valid_ext_va |
| `4037f1c0` | `mmu_hal_vaddr_to_paddr` | 90 | 1 | 1 | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad |
| `4037f2d0` | `FUN_4037f2d0` | 33 | 1 | 0 |  |
| `4037f2f4` | `FUN_4037f2f4` | 23 | 1 | 0 |  |
| `4037f30c` | `spi_flash_encrypt_ll_plaintext_save` | 76 | 1 | 1 | plaintext_offs + size <= SOC_FLASH_ENCRYPTED_XTS |
| `4037f358` | `FUN_4037f358` | 34 | 1 | 0 |  |
| `4037f37c` | `FUN_4037f37c` | 15 | 1 | 0 |  |
| `4037f38c` | `FUN_4037f38c` | 14 | 1 | 0 |  |
| `4037f39c` | `FUN_4037f39c` | 314 | 0 | 0 |  |
| `403826c0` | `FUN_403826c0` | 176 | 0 | 6 |  |
| `40382774` | `spi_flash_chip_generic_get_write_protect` | 56 | 0 | 1 | out_write_protect!=NULL |
| `403832c0` | `spi_flash_chip_mxic_opi_get_write_protect` | 56 | 0 | 1 | out_write_protected!=NULL |
| `42019830` | `FUN_42019830` | 18 | 1 | 1 |  |
| `42019844` | `FUN_42019844` | 16 | 1 | 1 |  |
| `420198dc` | `spi_flash_munmap` | 70 | 2 | 3 | spi_flash_munmap \| 0 && 'invalid handle, or handle already u |
| `42019ab8` | `spi_flash` | 309 | 1 | 7 | P 8@ \| spi_flash |

## left / idf/spi_flash (7)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40382050` | `FUN_40382050` | 99 | 1 | 1 |  |
| `403820b8` | `FUN_403820b8` | 55 | 0 | 0 |  |
| `403820f0` | `FUN_403820f0` | 35 | 0 | 0 |  |
| `40382114` | `FUN_40382114` | 45 | 0 | 0 |  |
| `40382144` | `FUN_40382144` | 54 | 0 | 0 |  |
| `4201a554` | `flash_hal` | 94 | 1 | 3 | flash_hal |
| `4201a5b4` | `FUN_4201a5b4` | 357 | 1 | 2 |  |

## left / idf/uart (85)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40376cf8` | `FUN_40376cf8` | 14 | 9 | 1 |  |
| `40376d50` | `FUN_40376d50` | 46 | 9 | 4 |  |
| `4200851c` | `FUN_4200851c` | 47 | 0 | 2 |  |
| `42008578` | `FUN_42008578` | 769 | 0 | 5 |  |
| `42008898` | `FUN_42008898` | 584 | 0 | 7 |  |
| `42008b0c` | `FUN_42008b0c` | 104 | 0 | 1 |  |
| `42008b78` | `FUN_42008b78` | 104 | 0 | 1 |  |
| `42008be4` | `uart_fcntl` | 85 | 0 | 2 | fd >= 0 && fd < 3 |
| `42008c3c` | `uart_fstat` | 45 | 0 | 1 | fd >= 0 && fd < 3 |
| `42008c6c` | `uart_close` | 28 | 0 | 1 | fd >= 0 && fd < 3 |
| `42008c88` | `uart_fsync` | 62 | 0 | 3 | fd >= 0 && fd < 3 \| Pm7@L |
| `42008cc8` | `uart_write` | 110 | 0 | 3 | fd >= 0 && fd < 3 \| uart_write \| Pm7@L |
| `42008d38` | `uart_vfs_dev_register` | 40 | 0 | 2 | esp_vfs_register_fs('/dev/uart', &s_vfs_uart, ES |
| `42008d60` | `uart_return_char` | 388 | 0 | 4 | fd >= 0 && fd < 3 \|  :cVc \|  3cVs \| c != NONE \| s_ctx[fd]->p |
| `42008ef0` | `FUN_42008ef0` | 8 | 1 | 0 |  |
| `42008ef8` | `FUN_42008ef8` | 78 | 1 | 2 |  |
| `4200903c` | `uart_reenable_intr_mask` | 202 | 1 | 5 | uart_reenable_intr_mask |
| `4200910c` | `FUN_4200910c` | 55 | 2 | 0 |  |
| `42009b38` | `uart_set_word_length` | 115 | 1 | 5 | uart_set_word_length \| uart |
| `42009bac` | `uart_get_word_length` | 61 | 1 | 3 | uart_get_word_length |
| `42009bec` | `uart_set_stop_bits` | 115 | 1 | 5 | uart_set_stop_bits \| uart |
| `42009c60` | `uart_get_stop_bits` | 90 | 1 | 5 | uart_get_stop_bits |
| `42009cbc` | `uart_set_parity` | 90 | 1 | 5 | uart_set_parity |
| `42009d18` | `uart_get_parity` | 90 | 1 | 5 | uart_get_parity |
| `42009d74` | `uart_set_baudrate` | 292 | 2 | 6 | uart_set_baudrate |
| `42009e9c` | `uart_get_baudrate` | 149 | 1 | 7 | uart_get_baudrate |
| `42009f34` | `uart_pattern_pop_pos` | 113 | 1 | 4 | uart_pattern_pop_pos |
| `42009fa8` | `uart_pattern_queue_reset` | 166 | 0 | 6 | uart_pattern_queue_reset |
| `4200a054` | `uart_enable_tx_intr` | 144 | 1 | 5 | uart_enable_tx_intr \| uart |
| `4200a268` | `uart_set_pin` | 1419 | 2 | 7 | uart_set_pin \| uart \| `p`P \| 0s 0S  |
| `4200a808` | `uart_param_config` | 130 | 2 | 2 | uart_param_config \| uart |
| `4200ab10` | `uart_intr_config` | 200 | 0 | 7 | uart_intr_config \| uart |
| `4200ad84` | `uart_write_bytes` | 122 | 3 | 3 | uart_write_bytes \| uart |
| `4200ae00` | `uart_read_bytes` | 285 | 1 | 10 | uart_read_bytes \| uart |
| `4200af20` | `uart_get_buffered_data_len` | 111 | 1 | 4 | uart_get_buffered_data_len \| uart |
| `4200af94` | `uart_flush_input` | 466 | 4 | 11 | uart_flush_input \| uart |
| `4200b2f0` | `uart_driver_install` | 59 | 2 | 2 | uart_driver_install |
| `4200b89c` | `FUN_4200b89c` | 17 | 0 | 1 |  |
| `4200b8b0` | `FUN_4200b8b0` | 90 | 0 | 1 |  |
| `4200b90c` | `FUN_4200b90c` | 25 | 0 | 0 |  |
| `4200b928` | `FUN_4200b928` | 47 | 0 | 4 | Pm7@L |
| `4200b958` | `FUN_4200b958` | 79 | 0 | 3 | Pm7@L |
| `4200b9a8` | `FUN_4200b9a8` | 20 | 0 | 1 |  |
| `4200b9bc` | `FUN_4200b9bc` | 103 | 3 | 1 |  |
| `4200ba28` | `FUN_4200ba28` | 106 | 1 | 1 |  |
| `4200ba94` | `FUN_4200ba94` | 54 | 0 | 1 |  |
| `4200bbc4` | `FUN_4200bbc4` | 46 | 0 | 4 | Pm7@L |
| `4200bbf4` | `FUN_4200bbf4` | 107 | 0 | 4 | Pm7@L |
| `4200bc68` | `FUN_4200bc68` | 8 | 1 | 0 |  |
| `4200be44` | `FUN_4200be44` | 32 | 0 | 3 |  |
| `4200bf74` | `FUN_4200bf74` | 348 | 4 | 3 |  |
| `4200c9c8` | `FUN_4200c9c8` | 166 | 0 | 1 |  |
| `4200ca78` | `FUN_4200ca78` | 57 | 0 | 1 |  |
| `4200cab4` | `FUN_4200cab4` | 55 | 0 | 1 |  |
| `4200caec` | `FUN_4200caec` | 35 | 0 | 1 |  |
| `4200cb10` | `FUN_4200cb10` | 43 | 0 | 1 |  |
| `4200cb3c` | `FUN_4200cb3c` | 63 | 0 | 1 |  |
| `4200cb7c` | `FUN_4200cb7c` | 35 | 0 | 1 |  |
| `4200cba0` | `FUN_4200cba0` | 34 | 0 | 1 |  |
| `4200cbc4` | `FUN_4200cbc4` | 42 | 0 | 1 |  |
| `4200cbf0` | `FUN_4200cbf0` | 34 | 0 | 1 |  |
| `4200cc14` | `FUN_4200cc14` | 26 | 0 | 1 |  |
| `4200cc30` | `FUN_4200cc30` | 26 | 0 | 1 |  |
| `4200cc4c` | `FUN_4200cc4c` | 20 | 0 | 1 |  |
| `42013884` | `uart_events` | 251 | 0 | 7 | uart_events |
| `420138c4` | `FUN_420138c4` | 1 | 1 | 0 |  |
| `420139b2` | `FUN_420139b2` | 6 | 1 | 1 |  |
| `420139c8` | `FUN_420139c8` | 27 | 1 | 3 |  |
| `42018538` | `FUN_42018538` | 56 | 1 | 0 |  |
| `42018570` | `FUN_42018570` | 128 | 1 | 0 |  |
| `4201a910` | `FUN_4201a910` | 34 | 0 | 0 |  |
| `4201a934` | `FUN_4201a934` | 32 | 2 | 0 |  |
| `4201a954` | `FUN_4201a954` | 175 | 0 | 0 |  |
| `4201aa04` | `FUN_4201aa04` | 126 | 1 | 0 |  |
| `4201ac2c` | `FUN_4201ac2c` | 24 | 2 | 1 |  |
| `42020b54` | `FUN_42020b54` | 13 | 28 | 1 |  |
| `4202d63c` | `FUN_4202d63c` | 33 | 2 | 0 |  |
| `4202d660` | `FUN_4202d660` | 56 | 1 | 0 |  |
| `4202d698` | `FUN_4202d698` | 32 | 1 | 0 |  |
| `4202d6b8` | `FUN_4202d6b8` | 17 | 1 | 0 |  |
| `4202d6cc` | `FUN_4202d6cc` | 31 | 1 | 0 |  |
| `4202d6ec` | `FUN_4202d6ec` | 17 | 1 | 0 |  |
| `4202d700` | `FUN_4202d700` | 53 | 1 | 0 |  |
| `4202d738` | `FUN_4202d738` | 32 | 1 | 0 |  |
| `4202d758` | `FUN_4202d758` | 29 | 1 | 0 |  |

## left / idf/usb (10)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200b668` | `FUN_4200b668` | 16 | 0 | 0 |  |
| `4200b678` | `FUN_4200b678` | 29 | 1 | 0 |  |
| `4200bacc` | `usb_serial_jtag_return_char` | 234 | 0 | 5 | s_ctx.peek_char == NONE \| usb_serial_jtag_vfs.c \| usb_serial |
| `42016e2c` | `usb_phy_otg_dev_set_speed` | 316 | 1 | 2 | usb_phy_otg_dev_set_speed \| usb_phy |
| `42016f70` | `usb_del_phy` | 195 | 1 | 8 | usb_del_phy \| (j7@ |
| `42017038` | `usb_phy_get_phy_status` | 133 | 1 | 2 | usb_phy_get_phy_status |
| `420170c4` | `usb_phy_install` | 1177 | 1 | 18 | usb_new_phy \| usb_phy \| usb_phy_install \| (j7@ \| usb_dwc_inf |
| `4201aa84` | `FUN_4201aa84` | 58 | 1 | 0 |  |
| `4201aac0` | `FUN_4201aac0` | 24 | 1 | 0 |  |
| `4201aad8` | `FUN_4201aad8` | 131 | 1 | 0 |  |

## left / keyboard (11)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40376788` | `clk_ticks_to_us` | 17 | 2 | 0 |  |
| `40378eb0` | `esp_random` | 66 | 3 | 2 |  |
| `42010e70` | `hid_key_down` | 140 | 5 | 3 |  |
| `42010f00` | `hid_key_up` | 140 | 5 | 3 |  |
| `42010f8c` | `hid_key_tap` | 79 | 1 | 4 |  |
| `42010fdc` | `hid_type_string` | 47 | 1 | 4 |  |
| `42011098` | `hid_keys_down` | 28 | 1 | 1 |  |
| `420110b4` | `hid_keys_up` | 28 | 1 | 1 |  |
| `420110d0` | `hid_keys_combo` | 181 | 1 | 4 |  |
| `4202d57c` | `hid_report_get_bits` | 70 | 4 | 0 |  |
| `4202d5c4` | `hid_report_set_bits` | 72 | 2 | 0 |  |

## left / led (1)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `42012a74` | `led_init` | 192 | 1 | 8 | gpio_config(&io_conf) |

## left / mouse (18)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200efec` | `mouse_submit` | 1643 | 2 | 6 |  |
| `4200f744` | `mouse_submit_ext` | 42 | 1 | 1 |  |
| `4200f83c` | `mouse_commit_init` | 99 | 1 | 4 |  |
| `4200f8e4` | `mouse_submit_default` | 135 | 1 | 1 |  |
| `4200f96c` | `wheel_submit` | 88 | 1 | 1 |  |
| `42010b60` | `mouse_move_mode` | 42 | 1 | 1 |  |
| `42010bc4` | `mouse_move` | 37 | 1 | 2 |  |
| `42010bec` | `wheel_write` | 26 | 1 | 1 |  |
| `4201ea4c` | `__ieee754_cos` | 122 | 1 | 3 |  |
| `4201eac8` | `__ieee754_sin` | 124 | 1 | 3 |  |
| `4201eb48` | `__fixdfsi` | 158 | 1 | 0 |  |
| `4201ebe8` | `__kernel_cos` | 376 | 2 | 0 | LUUUUU |
| `4201ed60` | `__kernel_sin` | 361 | 2 | 0 | IUUUUU |
| `4201eecc` | `__ieee754_rem_pio2` | 1029 | 2 | 2 |  |
| `4201f2d8` | `__kernel_rem_pio2` | 1865 | 1 | 2 |  |
| `4201fa38` | `__ieee754_floor` | 304 | 1 | 0 |  |
| `4201fb6c` | `__ieee754_scalbn` | 220 | 1 | 0 |  |
| `4202d980` | `nop_stub` | 12 | 1 | 0 |  |

## left / protocol (36)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200dc18` | `cmd_reply_status` | 80 | 4 | 1 | buttons() |
| `4200dc6c` | `cmd_version` | 24 | 0 | 2 |  |
| `4200ddbc` | `cmd_buttons` | 130 | 0 | 4 | buttons() |
| `4200de40` | `cmd_lock_query` | 32 | 0 | 2 |  |
| `4200de60` | `cmd_lock_axis` | 30 | 0 | 2 |  |
| `4200de80` | `cmd_set_string` | 74 | 0 | 2 |  |
| `4200dff0` | `cmd_catch_query` | 48 | 0 | 1 |  |
| `4200e024` | `cmd_move` | 394 | 0 | 3 |  |
| `4200e1b0` | `cmd_silent` | 422 | 0 | 2 |  |
| `4200e358` | `cmd_wheel` | 251 | 0 | 2 |  |
| `4200e458` | `parse_int_or_char` | 272 | 4 | 1 |  |
| `4200e56c` | `cmd_channel_toggle` | 177 | 0 | 2 |  |
| `4200e670` | `parse_list6` | 127 | 3 | 1 |  |
| `4200e6f0` | `cmd_keys_down` | 38 | 0 | 3 |  |
| `4200e718` | `cmd_keys_up` | 38 | 0 | 3 |  |
| `4200e740` | `parse_range` | 589 | 2 | 0 |  |
| `4200e998` | `cmd_keys_combo` | 56 | 0 | 4 |  |
| `4200e9d0` | `cmd_key_tap` | 52 | 0 | 4 |  |
| `4200ea04` | `cmd_map_16` | 276 | 0 | 3 |  |
| `4200eb1c` | `cmd_key_up` | 294 | 0 | 3 |  |
| `4200ec48` | `cmd_key_down` | 294 | 0 | 3 |  |
| `4200ed74` | `cmd_key_state` | 327 | 0 | 3 |  |
| `4200eec4` | `cmd_lookup` | 82 | 1 | 0 | right() \| left() \| middle() |
| `4200ef18` | `cmd_dispatch` | 130 | 1 | 2 | ,q7@\|e |
| `4200efb0` | `catch_unknown` | 58 | 1 | 0 | catch_ml \| catch_unknown \| catch_ms1 \| catch_mm |
| `42010c30` | `version_get` | 20 | 1 | 0 |  |
| `42010c44` | `buttons_set` | 30 | 1 | 0 |  |
| `42010c64` | `buttons_get` | 32 | 1 | 0 |  |
| `4201100c` | `hid_key_state_read` | 135 | 1 | 1 |  |
| `4202d1c8` | `lock_status_get` | 120 | 1 | 0 |  |
| `4202d240` | `lock_axis_get` | 44 | 1 | 0 |  |
| `4202d2a0` | `char_to_usage` | 509 | 5 | 0 |  |
| `4202d4a8` | `map_entry_write16` | 50 | 1 | 0 |  |
| `4200dba0` | `cmd_nop` | manual |  |  | hand reconstruction |
| `4200dc84` | `cmd_serial` | manual |  |  | hand reconstruction |
| `4200e624` | `cmd_map_entry` | manual |  |  | hand reconstruction |

## left / uart (16)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200db04` | `frame_router` | 131 | 1 | 5 |  |
| `4200db8c` | `uart_rx_frame` | 18 | 1 | 1 |  |
| `4200dbb0` | `cmd_dump_channels` | 99 | 0 | 2 |  |
| `4200decc` | `cmd_lock_param0` | 59 | 0 | 3 |  |
| `4200df30` | `cmd_button_press` | 38 | 0 | 2 |  |
| `4200df58` | `cmd_catch_set` | 82 | 0 | 2 |  |
| `4200dfac` | `cmd_button_click` | 66 | 0 | 2 |  |
| `42010b8c` | `lock_axis_set` | 26 | 1 | 1 |  |
| `42010ba8` | `lock_set` | 26 | 1 | 1 |  |
| `42010c84` | `serial_read` | 178 | 0 | 3 |  |
| `42013c58` | `uart0_read_string` | 50 | 1 | 1 |  |
| `4201423c` | `serial_setup` | 97 | 3 | 6 | SERIAL_SETUP \| ,q7@\|e |
| `420142a0` | `uart0_setup` | 326 | 1 | 8 | uart_param_config(UART_NUM_0, &uart0_config) \| uart_set_pin( |
| `420143e8` | `uart0_reply` | 114 | 26 | 1 |  |
| `4202d1ac` | `catch_set` | 26 | 2 | 0 |  |
| `4202d26c` | `button_flags_get` | 50 | 1 | 0 |  |

## right / hid (23)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4200be20` | `FUN_4200be20` | 86 | 1 | 0 |  |
| `4200beac` | `FUN_4200beac` | 328 | 0 | 3 | Fail to alloc hid_class \| HID descriptor not found \| HID rep |
| `4200c3b0` | `FUN_4200c3b0` | 151 | 1 | 1 |  |
| `4200d104` | `FUN_4200d104` | 633 | 4 | 3 |  |
| `4200de08` | `FUN_4200de08` | 49 | 1 | 0 |  |
| `4200df3c` | `FUN_4200df3c` | 83 | 1 | 2 | bus overflow |
| `4200e59c` | `FUN_4200e59c` | 61 | 1 | 2 |  |
| `4200e5dc` | `FUN_4200e5dc` | 195 | 1 | 0 | invalid device bLength 0x%02x \| unexpected descriptor 0x%02x |
| `4200e6a4` | `FUN_4200e6a4` | 207 | 1 | 0 | invalid device bLength 0x%02x \| unexpected descriptor 0x%02x |
| `4200e7e4` | `FUN_4200e7e4` | 64 | 2 | 2 |  |
| `4200e93c` | `FUN_4200e93c` | 73 | 1 | 0 |  |
| `4200ea4c` | `FUN_4200ea4c` | 65 | 2 | 2 |  |
| `4200ea90` | `hubint_tim` | 622 | 0 | 12 | Fail to alloc hub_class \| Hub depth(%d) is overflow \| Unable |
| `4200f12c` | `FUN_4200f12c` | 166 | 1 | 3 | usbh_hub%u |
| `42010198` | `FUN_42010198` | 168 | 1 | 1 |  |
| `42017b5c` | `FUN_42017b5c` | 115 | 5 | 2 |  |
| `42018690` | `FUN_42018690` | 123 | 1 | 2 |  |
| `420207d0` | `FUN_420207d0` | 10 | 0 | 0 |  |
| `420207dc` | `FUN_420207dc` | 15 | 3 | 0 |  |
| `420207ec` | `FUN_420207ec` | 15 | 0 | 0 |  |
| `420207fc` | `FUN_420207fc` | 95 | 0 | 0 |  |
| `4202475c` | `FUN_4202475c` | 5 | 0 | 0 |  |
| `42024764` | `FUN_42024764` | 62 | 2 | 0 |  |

## right / idf/esp_system (499)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40375370` | `FUN_40375370` | 139 | 1 | 2 |  |
| `403753fc` | `entry` | 660 | 0 | 24 |  |
| `40375694` | `FUN_40375694` | 149 | 0 | 4 |  |
| `403757bc` | `FUN_403757bc` | 26 | 1 | 3 |  |
| `403757d8` | `esp_reset_reason_set_hint` | 48 | 3 | 1 | (hint & (~RST_REASON_MASK)) == 0 |
| `40375808` | `FUN_40375808` | 195 | 1 | 0 |  |
| `403758d0` | `FUN_403758d0` | 326 | 3 | 6 |  |
| `40375ac8` | `FUN_40375ac8` | 19 | 1 | 0 |  |
| `40375bc8` | `FUN_40375bc8` | 58 | 1 | 2 |  0x%08lX:0x%08lX |
| `40375c04` | `FUN_40375c04` | 24 | 1 | 1 |  |
| `40375c1c` | `FUN_40375c1c` | 157 | 1 | 0 |  |
| `40375cbc` | `FUN_40375cbc` | 328 | 2 | 3 |  \|<-CORRUPTED \|  \|<-CONTINUES |
| `40375f64` | `FUN_40375f64` | 72 | 1 | 0 |  |
| `40375fac` | `FUN_40375fac` | 63 | 1 | 0 |  |
| `4037650c` | `FUN_4037650c` | 17 | 0 | 0 |  |
| `40376520` | `FUN_40376520` | 41 | 1 | 0 |  |
| `4037654c` | `FUN_4037654c` | 14 | 1 | 1 |  |
| `40376670` | `FUN_40376670` | 16 | 5 | 1 |  |
| `40376680` | `FUN_40376680` | 16 | 5 | 1 |  |
| `40376690` | `esp_intr_disable` | 239 | 2 | 5 | svd != NULL \| esp_intr_disable |
| `40376968` | `FUN_40376968` | 24 | 2 | 0 |  |
| `40376afc` | `FUN_40376afc` | 14 | 11 | 1 |  |
| `40376b3c` | `FUN_40376b3c` | 15 | 11 | 1 |  |
| `40376c88` | `FUN_40376c88` | 76 | 2 | 2 |  |
| `40377394` | `FUN_40377394` | 10 | 3 | 1 |  |
| `40377670` | `FUN_40377670` | 32 | 2 | 1 |  |
| `40377690` | `FUN_40377690` | 42 | 1 | 1 |  |
| `403776bc` | `FUN_403776bc` | 146 | 1 | 1 |  |
| `40377750` | `FUN_40377750` | 16 | 5 | 0 |  |
| `40377c44` | `FUN_40377c44` | 21 | 1 | 2 |  |
| `40377c5c` | `FUN_40377c5c` | 32 | 1 | 3 |  |
| `40377c7c` | `FUN_40377c7c` | 69 | 2 | 2 |  |
| `40377cc4` | `FUN_40377cc4` | 34 | 5 | 1 |  |
| `40377ce8` | `FUN_40377ce8` | 103 | 1 | 4 | H.8@ |
| `40377d54` | `FUN_40377d54` | 106 | 1 | 3 |  |
| `40377dc0` | `FUN_40377dc0` | 108 | 1 | 3 |  |
| `40377e30` | `FUN_40377e30` | 234 | 1 | 6 |  |
| `40377f28` | `esp_flash_erase_region` | 518 | 2 | 5 | len_remain < len \| esp_flash_api.c \| esp_flash_erase_region |
| `40378140` | `FUN_40378140` | 292 | 2 | 3 | zDpU |
| `4037826c` | `FUN_4037826c` | 361 | 3 | 6 | len_remain < length \| \|\|7@0Z |
| `403783e0` | `FUN_403783e0` | 452 | 2 | 5 | \|\|7@0Z |
| `40378680` | `FUN_40378680` | 16 | 0 | 0 |  |
| `40378690` | `FUN_40378690` | 11 | 0 | 1 |  |
| `4037869c` | `FUN_4037869c` | 48 | 0 | 2 |  |
| `40378710` | `FUN_40378710` | 17 | 0 | 1 |  |
| `40378724` | `FUN_40378724` | 17 | 0 | 1 |  |
| `403787a0` | `esp_crosscore_int_send` | 84 | 3 | 3 | core_id < CONFIG_FREERTOS_NUMBER_OF_CORES |
| `40378804` | `FUN_40378804` | 15 | 1 | 1 |  |
| `40378814` | `FUN_40378814` | 15 | 1 | 1 |  |
| `40378864` | `FUN_40378864` | 24 | 2 | 2 |  |
| `4037887c` | `FUN_4037887c` | 38 | 1 | 0 |  |
| `403788a4` | `FUN_403788a4` | 7 | 1 | 0 |  |
| `403788ac` | `FUN_403788ac` | 36 | 9 | 0 |  |
| `403788d0` | `FUN_403788d0` | 26 | 9 | 0 |  |
| `403788ec` | `FUN_403788ec` | 16 | 4 | 0 |  |
| `40378910` | `esp_cpu_stall` | 130 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM |
| `40378994` | `esp_cpu_unstall` | 85 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM |
| `40378c00` | `FUN_40378c00` | 39 | 1 | 4 |  |
| `40378c28` | `FUN_40378c28` | 6 | 1 | 1 |  |
| `40378c30` | `FUN_40378c30` | 99 | 1 | 0 |  |
| `40378c94` | `FUN_40378c94` | 5 | 1 | 0 |  |
| `40378c9c` | `FUN_40378c9c` | 7 | 1 | 0 |  |
| `40378ca4` | `FUN_40378ca4` | 31 | 2 | 0 |  |
| `40378cc4` | `FUN_40378cc4` | 24 | 1 | 0 |  |
| `40378e68` | `FUN_40378e68` | 236 | 1 | 0 |  |
| `40378f58` | `FUN_40378f58` | 83 | 1 | 0 |  |
| `40378fac` | `FUN_40378fac` | 155 | 3 | 0 |  |
| `4037904c` | `FUN_4037904c` | 25 | 1 | 0 |  |
| `40379068` | `FUN_40379068` | 246 | 1 | 3 | false \| clk_ll_rtc_slow_get_src |
| `40379160` | `FUN_40379160` | 42 | 3 | 1 | false |
| `4037918c` | `FUN_4037918c` | 36 | 3 | 1 |  |
| `403791b4` | `FUN_403791b4` | 68 | 1 | 1 |  |
| `403791f8` | `FUN_403791f8` | 51 | 7 | 0 |  |
| `4037922c` | `FUN_4037922c` | 101 | 1 | 1 |  |
| `40379294` | `FUN_40379294` | 204 | 5 | 1 |  |
| `40379368` | `FUN_40379368` | 10 | 2 | 0 |  |
| `40379374` | `FUN_40379374` | 375 | 1 | 4 | gffft> |
| `403794f4` | `clk_ll_cpu_set_divider` | 191 | 2 | 4 | divider > 0 |
| `403795b4` | `FUN_403795b4` | 92 | 3 | 6 |  |
| `40379614` | `FUN_40379614` | 15 | 2 | 2 |  |
| `40379624` | `FUN_40379624` | 11 | 2 | 2 |  |
| `40379630` | `FUN_40379630` | 32 | 1 | 0 |  |
| `40379650` | `FUN_40379650` | 32 | 2 | 0 |  |
| `40379820` | `FUN_40379820` | 543 | 1 | 2 |  |
| `40379a48` | `slowclk_cycles` | 196 | 5 | 3 | slowclk_cycles \| W2D' |
| `40379b10` | `rtc_time_us_to_slowclk` | 134 | 1 | 1 | period |
| `40379bc0` | `FUN_40379bc0` | 26 | 3 | 0 |  |
| `4037ad14` | `FUN_4037ad14` | 79 | 0 | 0 |  |
| `4037ad68` | `FUN_4037ad68` | 31 | 0 | 0 |  |
| `4037ad88` | `FUN_4037ad88` | 28 | 1 | 0 |  |
| `4037ada4` | `FUN_4037ada4` | 34 | 2 | 0 |  |
| `4037adc8` | `FUN_4037adc8` | 28 | 1 | 0 |  |
| `4037ade4` | `FUN_4037ade4` | 34 | 1 | 0 |  |
| `4037ae08` | `FUN_4037ae08` | 235 | 1 | 0 |  |
| `4037af90` | `FUN_4037af90` | 13 | 3 | 1 |  |
| `4037ba60` | `FUN_4037ba60` | 110 | 1 | 1 |  |
| `4037bad0` | `FUN_4037bad0` | 18 | 0 | 2 |  |
| `4037bde0` | `FUN_4037bde0` | 63 | 1 | 1 | ***ERROR*** A stack overflow in task  \|  has been detected. |
| `4037e9d0` | `FUN_4037e9d0` | 101 | 1 | 0 |  |
| `4037ea38` | `FUN_4037ea38` | 149 | 1 | 1 |  |
| `4037ead0` | `cache_hal_disable` | 59 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU |
| `4037eb0c` | `cache_hal_enable` | 103 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037eb78` | `cache_hal_suspend` | 47 | 2 | 3 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU |
| `4037ebb0` | `cache_hal_resume` | 104 | 2 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU \| cache_hal |
| `4037ed04` | `cache_hal_freeze` | 58 | 1 | 3 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU |
| `4037ed40` | `cache_hal_unfreeze` | 58 | 1 | 1 | cache_level && (cache_level <= CACHE_LL_LEVEL_NU |
| `4037ed80` | `cache_ll_get_line_size` | 75 | 1 | 1 | cache_level <= CACHE_LL_LEVEL_NUMS \| false |
| `4037f1b0` | `FUN_4037f1b0` | 283 | 1 | 1 | &C8&S |
| `4037f2d0` | `FUN_4037f2d0` | 61 | 1 | 0 |  |
| `4037f310` | `FUN_4037f310` | 85 | 2 | 0 |  |
| `4037f368` | `FUN_4037f368` | 314 | 0 | 0 |  |
| `4037f4a4` | `FUN_4037f4a4` | 390 | 0 | 1 |  |
| `4037f62c` | `FUN_4037f62c` | 356 | 0 | 2 |  |
| `4037f790` | `FUN_4037f790` | 198 | 0 | 1 |  |
| `4037f858` | `FUN_4037f858` | 15 | 0 | 0 |  |
| `4037f868` | `FUN_4037f868` | 7 | 0 | 0 |  |
| `4037f870` | `FUN_4037f870` | 7 | 0 | 0 |  |
| `4037f878` | `FUN_4037f878` | 23 | 0 | 0 |  |
| `4037f890` | `FUN_4037f890` | 367 | 1 | 1 |  |
| `4037fa08` | `FUN_4037fa08` | 57 | 1 | 1 |  |
| `4037fa48` | `FUN_4037fa48` | 93 | 1 | 0 |  |
| `4037faa8` | `FUN_4037faa8` | 474 | 0 | 1 |  |
| `4037fc84` | `FUN_4037fc84` | 421 | 0 | 0 |  |
| `4037fe30` | `FUN_4037fe30` | 203 | 0 | 0 |  |
| `4037ff00` | `FUN_4037ff00` | 38 | 0 | 0 |  |
| `4037ff28` | `FUN_4037ff28` | 110 | 0 | 0 |  |
| `4037ff98` | `FUN_4037ff98` | 102 | 0 | 0 |  |
| `40380000` | `FUN_40380000` | 94 | 0 | 1 |  |
| `40380060` | `FUN_40380060` | 59 | 0 | 0 |  |
| `4038009c` | `FUN_4038009c` | 116 | 0 | 0 |  |
| `40380110` | `FUN_40380110` | 464 | 1 | 1 |  |
| `403802e4` | `FUN_403802e4` | 24 | 1 | 0 |  |
| `403802fc` | `FUN_403802fc` | 134 | 1 | 0 |  |
| `40380384` | `FUN_40380384` | 24 | 1 | 0 |  |
| `4038039c` | `FUN_4038039c` | 252 | 0 | 4 |  |
| `40381ce0` | `FUN_40381ce0` | 139 | 47 | 1 | abort() was called at PC 0x \|  on core  |
| `40381f84` | `FUN_40381f84` | 11 | 1 | 0 |  |
| `40381f90` | `FUN_40381f90` | 33 | 1 | 0 |  |
| `40381fb4` | `FUN_40381fb4` | 105 | 0 | 0 |  |
| `4038218c` | `FUN_4038218c` | 97 | 1 | 0 |  |
| `403821f8` | `FUN_403821f8` | 51 | 0 | 0 |  |
| `4038222c` | `FUN_4038222c` | 42 | 0 | 0 |  |
| `40382258` | `FUN_40382258` | 40 | 0 | 0 |  |
| `40382284` | `FUN_40382284` | 7 | 0 | 0 |  |
| `4038228c` | `FUN_4038228c` | 53 | 0 | 0 |  |
| `403822c4` | `FUN_403822c4` | 54 | 0 | 0 |  |
| `403822fc` | `FUN_403822fc` | 63 | 0 | 1 | P'8@ \| \*8@ |
| `4038235c` | `FUN_4038235c` | 25 | 0 | 0 |  |
| `40382378` | `FUN_40382378` | 53 | 0 | 0 |  |
| `40382948` | `FUN_40382948` | 67 | 0 | 1 |  |
| `40382990` | `FUN_40382990` | 99 | 0 | 0 |  |
| `403829f4` | `FUN_403829f4` | 21 | 1 | 1 |  |
| `40382a0c` | `FUN_40382a0c` | 30 | 0 | 1 |  |
| `40382a2c` | `FUN_40382a2c` | 21 | 1 | 1 |  |
| `40382a44` | `FUN_40382a44` | 21 | 0 | 1 |  |
| `40382a5c` | `FUN_40382a5c` | 21 | 0 | 1 |  |
| `40382a74` | `FUN_40382a74` | 24 | 0 | 1 | P'8@ |
| `40382a94` | `FUN_40382a94` | 142 | 0 | 0 |  |
| `40382b24` | `FUN_40382b24` | 138 | 0 | 0 |  |
| `40382bb0` | `FUN_40382bb0` | 138 | 0 | 0 |  |
| `40382c3c` | `FUN_40382c3c` | 108 | 0 | 0 |  |
| `40382ca8` | `FUN_40382ca8` | 79 | 0 | 0 |  |
| `40382cf8` | `FUN_40382cf8` | 18 | 0 | 0 |  |
| `40382d0c` | `FUN_40382d0c` | 145 | 0 | 0 |  |
| `40382da4` | `FUN_40382da4` | 8 | 0 | 0 |  |
| `40382dac` | `FUN_40382dac` | 152 | 3 | 0 |  |
| `40382e48` | `FUN_40382e48` | 40 | 1 | 0 |  |
| `40382e74` | `FUN_40382e74` | 20 | 0 | 1 | ,*8@D*8@` \| D*8@` |
| `40382e88` | `FUN_40382e88` | 31 | 0 | 1 |  |
| `40382ea8` | `FUN_40382ea8` | 7 | 0 | 0 |  |
| `40382eb0` | `FUN_40382eb0` | 64 | 0 | 0 |  |
| `40382ef4` | `FUN_40382ef4` | 35 | 0 | 0 |  |
| `40382f1c` | `FUN_40382f1c` | 7 | 0 | 0 |  |
| `40382f24` | `FUN_40382f24` | 53 | 0 | 0 |  |
| `40382f5c` | `FUN_40382f5c` | 114 | 0 | 0 |  |
| `40382fd0` | `FUN_40382fd0` | 138 | 0 | 0 |  |
| `403835d8` | `FUN_403835d8` | 92 | 0 | 1 |  |
| `40383634` | `FUN_40383634` | 71 | 1 | 0 |  |
| `40383680` | `FUN_40383680` | 92 | 0 | 1 |  |
| `40383784` | `FUN_40383784` | 22 | 0 | 0 |  |
| `4038379c` | `FUN_4038379c` | 25 | 0 | 0 |  |
| `403837b8` | `FUN_403837b8` | 7 | 1 | 0 |  |
| `403837c0` | `FUN_403837c0` | 13 | 1 | 0 |  |
| `403837d0` | `FUN_403837d0` | 46 | 1 | 0 |  |
| `40383804` | `FUN_40383804` | 42 | 1 | 0 |  |
| `40383830` | `FUN_40383830` | 30 | 0 | 0 |  |
| `40383850` | `FUN_40383850` | 168 | 1 | 0 |  |
| `403838f8` | `FUN_403838f8` | 58 | 1 | 0 |  |
| `40383934` | `FUN_40383934` | 96 | 1 | 4 |  |
| `40383994` | `FUN_40383994` | 76 | 1 | 4 | 498@088@ |
| `40383d28` | `FUN_40383d28` | 27 | 3 | 0 |  |
| `42001540` | `FUN_42001540` | 89 | 1 | 0 |  |
| `4200159c` | `FUN_4200159c` | 10 | 0 | 1 |  |
| `420015a8` | `FUN_420015a8` | 10 | 0 | 1 |  |
| `420015b4` | `FUN_420015b4` | 18 | 1 | 2 |  |
| `420015c8` | `FUN_420015c8` | 10 | 1 | 1 |  |
| `42001608` | `FUN_42001608` | 53 | 1 | 2 |  |
| `4200168c` | `FUN_4200168c` | 38 | 0 | 0 |  |
| `420016b4` | `FUN_420016b4` | 36 | 1 | 0 |  |
| `420016d8` | `FUN_420016d8` | 158 | 1 | 3 |  |
| `4200177c` | `FUN_4200177c` | 16 | 1 | 0 |  |
| `420017d8` | `FUN_420017d8` | 106 | 1 | 6 |  |
| `42001848` | `FUN_42001848` | 40 | 1 | 2 |  |
| `42001870` | `FUN_42001870` | 293 | 1 | 10 | rtc_clk_xtal_freq_get() == SOC_XTAL_FREQ_40M |
| `42001998` | `FUN_42001998` | 133 | 1 | 0 |  |
| `42001af8` | `FUN_42001af8` | 15 | 1 | 0 |  |
| `42001b08` | `FUN_42001b08` | 39 | 2 | 0 |  |
| `42001b30` | `FUN_42001b30` | 35 | 0 | 3 |  |
| `42001b54` | `FUN_42001b54` | 174 | 1 | 2 | pf7@ |
| `42001cf8` | `FUN_42001cf8` | 52 | 2 | 3 | TZ7@ \| pf7@ |
| `42001d2c` | `FUN_42001d2c` | 46 | 1 | 1 |  |
| `42001d5c` | `FUN_42001d5c` | 106 | 1 | 0 |  |
| `42001dc8` | `FUN_42001dc8` | 78 | 1 | 0 |  |
| `42001e18` | `FUN_42001e18` | 20 | 3 | 2 |  |
| `42001e2c` | `FUN_42001e2c` | 26 | 9 | 1 |  |
| `42001e48` | `FUN_42001e48` | 13 | 1 | 1 |  |
| `42001e58` | `FUN_42001e58` | 41 | 5 | 1 |  |
| `42001e84` | `FUN_42001e84` | 59 | 2 | 1 | gfff |
| `42001ec0` | `FUN_42001ec0` | 126 | 2 | 0 |  |
| `42001f40` | `FUN_42001f40` | 480 | 0 | 12 | Guru Meditation Error: Core  \|  panic'ed ( \| Setting breakpo |
| `42002124` | `FUN_42002124` | 25 | 1 | 1 |  |
| `42002140` | `FUN_42002140` | 63 | 2 | 2 |  |
| `42002180` | `FUN_42002180` | 10 | 1 | 1 |  |
| `4200218c` | `FUN_4200218c` | 94 | 1 | 2 |  |
| `420021ec` | `FUN_420021ec` | 29 | 0 | 4 |  |
| `420023a4` | `FUN_420023a4` | 38 | 0 | 3 |  |
| `42002410` | `FUN_42002410` | 12 | 1 | 1 |  |
| `4200243c` | `FUN_4200243c` | 36 | 1 | 2 | pf7@ |
| `42002460` | `FUN_42002460` | 80 | 0 | 1 | Debug exception reason:  \| SingleStep  \| HwBreakpoint  \| Wat |
| `420024b0` | `FUN_420024b0` | 82 | 0 | 2 | Memory dump at 0x |
| `42002504` | `FUN_42002504` | 312 | 0 | 2 | Icache sync parameter configuration error, the e \| Icache pr |
| `42002644` | `FUN_42002644` | 212 | 1 | 4 | hi7@hi |
| `420027b4` | `FUN_420027b4` | 32 | 1 | 1 |  |
| `420028b4` | `esp_ipc_init` | 145 | 0 | 4 | ipcX \| T^7@ |
| `42002b50` | `FUN_42002b50` | 39 | 1 | 0 |  |
| `42003000` | `s_prepare_reserved_regions` | 144 | 1 | 2 | reserved[i].start <= reserved[i].end \| reserved[i + 1].start |
| `420032d0` | `FUN_420032d0` | 16 | 2 | 1 |  |
| `420032e0` | `FUN_420032e0` | 79 | 1 | 0 |  |
| `42003330` | `FUN_42003330` | 36 | 2 | 0 |  |
| `42003354` | `FUN_42003354` | 86 | 1 | 3 |  |
| `42003420` | `is_vect_desc_usable` | 191 | 1 | 3 | !((vd->flags & VECDESC_FL_SHARED) && (vd->flags  \| intr_allo |
| `420034e8` | `FUN_420034e8` | 324 | 1 | 4 |  |
| `42003630` | `FUN_42003630` | 39 | 1 | 0 |  |
| `42003658` | `esp_cpu_intr_edge_ack` | 717 | 1 | 11 | intr_num >= 0 && intr_num < SOC_CPU_INTR_NUM \| \e7@ \| esp_cp |
| `42003950` | `intr_free_for_current_cpu` | 236 | 2 | 6 | intr_free_for_current_cpu |
| `42003a94` | `FUN_42003a94` | 10 | 0 | 1 |  |
| `42003b80` | `FUN_42003b80` | 190 | 1 | 4 | Pw7@ |
| `42003c40` | `FUN_42003c40` | 102 | 1 | 3 |  |
| `42003cac` | `FUN_42003cac` | 17 | 0 | 2 |  |
| `42003cc0` | `FUN_42003cc0` | 123 | 1 | 0 |  |
| `42003d3c` | `FUN_42003d3c` | 42 | 1 | 1 |  |
| `42003d68` | `FUN_42003d68` | 62 | 1 | 0 |  |
| `42003da8` | `FUN_42003da8` | 62 | 1 | 0 |  |
| `42003de8` | `FUN_42003de8` | 148 | 2 | 0 |  |
| `42003e7c` | `FUN_42003e7c` | 50 | 1 | 1 |  |
| `42003eb0` | `FUN_42003eb0` | 55 | 1 | 0 |  |
| `42003ee8` | `FUN_42003ee8` | 61 | 1 | 0 |  |
| `42003f28` | `FUN_42003f28` | 62 | 1 | 0 |  |
| `42003f68` | `FUN_42003f68` | 62 | 1 | 0 |  |
| `42003fa8` | `FUN_42003fa8` | 58 | 1 | 0 |  |
| `42003fe4` | `FUN_42003fe4` | 104 | 1 | 0 |  |
| `4200404c` | `FUN_4200404c` | 48 | 1 | 0 |  |
| `42004080` | `FUN_42004080` | 56 | 1 | 0 |  |
| `420040bc` | `FUN_420040bc` | 56 | 1 | 0 |  |
| `420040f8` | `FUN_420040f8` | 58 | 2 | 0 |  |
| `42004134` | `FUN_42004134` | 114 | 1 | 0 |  |
| `420041ac` | `FUN_420041ac` | 214 | 1 | 0 |  |
| `42004288` | `FUN_42004288` | 186 | 1 | 0 |  |
| `4200434c` | `FUN_4200434c` | 58 | 1 | 0 |  |
| `42004388` | `FUN_42004388` | 104 | 1 | 0 |  |
| `420043f4` | `FUN_420043f4` | 48 | 1 | 0 |  |
| `42004428` | `FUN_42004428` | 56 | 1 | 0 |  |
| `42004464` | `FUN_42004464` | 56 | 1 | 0 |  |
| `420044a0` | `FUN_420044a0` | 153 | 2 | 0 |  |
| `4200453c` | `FUN_4200453c` | 50 | 1 | 1 |  |
| `42004570` | `FUN_42004570` | 48 | 1 | 0 |  |
| `420045a4` | `FUN_420045a4` | 53 | 1 | 0 |  |
| `420045dc` | `FUN_420045dc` | 54 | 1 | 0 |  |
| `42004614` | `FUN_42004614` | 52 | 1 | 0 |  |
| `42004648` | `FUN_42004648` | 58 | 1 | 0 |  |
| `42004684` | `FUN_42004684` | 104 | 1 | 0 |  |
| `420046ec` | `FUN_420046ec` | 48 | 1 | 0 |  |
| `42004720` | `FUN_42004720` | 56 | 1 | 0 |  |
| `4200475c` | `FUN_4200475c` | 56 | 1 | 0 |  |
| `42004798` | `FUN_42004798` | 41 | 13 | 0 |  |
| `420047c4` | `FUN_420047c4` | 8 | 1 | 0 |  |
| `420047cc` | `FUN_420047cc` | 13 | 1 | 0 |  |
| `420047dc` | `FUN_420047dc` | 8 | 1 | 0 |  |
| `420047e4` | `FUN_420047e4` | 188 | 1 | 3 | pf7@ |
| `420048a8` | `FUN_420048a8` | 179 | 1 | 5 |  |
| `42004968` | `FUN_42004968` | 58 | 1 | 3 |  |
| `420049ac` | `FUN_420049ac` | 94 | 1 | 2 |  |
| `42004a10` | `FUN_42004a10` | 80 | 2 | 3 | &B!! |
| `42004a68` | `FUN_42004a68` | 107 | 1 | 2 |  |
| `42004adc` | `FUN_42004adc` | 99 | 2 | 3 |  |
| `42004b48` | `FUN_42004b48` | 343 | 1 | 13 |  |
| `42004cb4` | `FUN_42004cb4` | 526 | 1 | 3 |  |
| `42004ed0` | `FUN_42004ed0` | 179 | 1 | 2 |  |
| `42004f88` | `FUN_42004f88` | 89 | 2 | 5 |  |
| `42004fec` | `FUN_42004fec` | 83 | 1 | 5 |  |
| `42005044` | `FUN_42005044` | 89 | 1 | 5 |  |
| `420050a8` | `FUN_420050a8` | 110 | 1 | 8 |  |
| `4200511c` | `FUN_4200511c` | 389 | 1 | 3 |  |
| `420052a4` | `FUN_420052a4` | 2004 | 1 | 18 | Fatal error: IRAM0 I_0 split line configuration  \| Fatal err |
| `42005ab0` | `FUN_42005ab0` | 65 | 13 | 0 | &R$fb'! |
| `42005af8` | `FUN_42005af8` | 68 | 2 | 1 | core_id >= 0 && core_id < SOC_CPU_CORES_NUM && i \| esp_cpu_i |
| `42005b3c` | `esp_sleep_sub_mode_config` | 141 | 1 | 4 | s_sleep_sub_mode_ref_cnt[mode] >= 0 \| sleep_modes.c \| esp_sl |
| `42005bcc` | `source_approx_freq` | 76 | 1 | 4 | source_approx_freq \| clk_tree_rtc_slow_calibration |
| `42005c18` | `FUN_42005c18` | 89 | 2 | 2 |  |
| `42005c74` | `FUN_42005c74` | 89 | 1 | 2 |  |
| `42005cd0` | `FUN_42005cd0` | 59 | 1 | 3 |  |
| `42005d14` | `FUN_42005d14` | 22 | 3 | 1 |  |
| `42005d30` | `esp_clk_tree_lp_fast_get_freq_hz` | 82 | 1 | 3 | false |
| `42005d88` | `esp_newlib_locks_init` | 90 | 0 | 2 | handle == (SemaphoreHandle_t) &s_common_mutex \| handle == (S |
| `42005e1c` | `FUN_42005e1c` | 15 | 0 | 1 |  |
| `42005ef0` | `FUN_42005ef0` | 12 | 1 | 1 |  |
| `42005f3c` | `FUN_42005f3c` | 274 | 2 | 3 |  |
| `42006054` | `FUN_42006054` | 30 | 1 | 3 | <k7@ |
| `42006074` | `FUN_42006074` | 48 | 1 | 3 | <k7@ |
| `420060a4` | `FUN_420060a4` | 62 | 1 | 3 |  |
| `420060ec` | `FUN_420060ec` | 27 | 3 | 1 |  |
| `42006108` | `FUN_42006108` | 39 | 3 | 2 | <k7@ |
| `42006130` | `FUN_42006130` | 39 | 2 | 2 | <k7@ |
| `4200617c` | `FUN_4200617c` | 81 | 0 | 6 |  |
| `420074f0` | `FUN_420074f0` | 112 | 2 | 1 |  |
| `42007564` | `FUN_42007564` | 251 | 1 | 1 |  |
| `42007718` | `FUN_42007718` | 114 | 2 | 6 | <k7@ |
| `4200778c` | `FUN_4200778c` | 83 | 1 | 5 | <k7@ |
| `42008b58` | `FUN_42008b58` | 473 | 1 | 15 |  |
| `4200a278` | `FUN_4200a278` | 191 | 2 | 3 | <k7@ |
| `4200abf0` | `FUN_4200abf0` | 10 | 0 | 1 |  |
| `4200ac30` | `esp_core_dump_get_user_ram_info` | 49 | 1 | 1 | start != ((void *)0) |
| `4200ae00` | `FUN_4200ae00` | 17 | 1 | 3 |  |
| `4200ae14` | `FUN_4200ae14` | 62 | 2 | 3 |  |
| `4200ae54` | `FUN_4200ae54` | 54 | 1 | 2 |  |
| `4200af64` | `FUN_4200af64` | 107 | 1 | 3 |  |
| `4200afd4` | `FUN_4200afd4` | 13 | 1 | 1 |  |
| `4200afe4` | `FUN_4200afe4` | 176 | 1 | 5 |  |
| `4200b094` | `FUN_4200b094` | 120 | 2 | 2 |  |
| `4200b114` | `FUN_4200b114` | 199 | 1 | 8 | checksum_size <= 32 \| Calculated checksum \| Image checksum |
| `4200b1dc` | `FUN_4200b1dc` | 27 | 1 | 3 |  |
| `4200b954` | `core_dump_crc_print` | 50 | 1 | 1 | checksum != ((void *)0) \| '%08lx' \| core_dump_crc_print |
| `4200b990` | `FUN_4200b990` | 27 | 3 | 0 |  |
| `4200b9ac` | `FUN_4200b9ac` | 19 | 2 | 1 |  |
| `4200b9e0` | `FUN_4200b9e0` | 488 | 1 | 2 |  |
| `4200bd34` | `esp_core_dump_get_stack` | 73 | 2 | 1 | stk_paddr != ((void *)0) && stk_vaddr != ((void  \| core_dump |
| `4200bdb0` | `esp_core_dump_get_task_regs_dump` | 80 | 1 | 3 | task != ((void *)0) && reg_dump != ((void *)0) \| core_dump_p |
| `4200f1fc` | `FUN_4200f1fc` | 115 | 1 | 4 |  |
| `4200f270` | `COREDUMP_START` | 114 | 1 | 4 |  |
| `4200f2e4` | `storage` | 116 | 1 | 6 | storage |
| `4200f3ac` | `FUN_4200f3ac` | 61 | 3 | 0 |  |
| `4200f3ec` | `FUN_4200f3ec` | 200 | 1 | 6 | device_%d |
| `4200f4e0` | `FUN_4200f4e0` | 50 | 1 | 1 |  |
| `4200f93c` | `FUN_4200f93c` | 165 | 1 | 1 |  |
| `42010bec` | `FUN_42010bec` | 91 | 1 | 0 |  |
| `42010c4c` | `FUN_42010c4c` | 91 | 1 | 0 |  |
| `42010cac` | `FUN_42010cac` | 91 | 1 | 0 |  |
| `42010d0c` | `FUN_42010d0c` | 91 | 1 | 0 |  |
| `42011818` | `FUN_42011818` | 104 | 1 | 4 |  |
| `42011bcc` | `FUN_42011bcc` | 72 | 1 | 1 |  |
| `42011c14` | `FUN_42011c14` | 311 | 1 | 5 |  |
| `42011d50` | `FUN_42011d50` | 52 | 1 | 3 | <k7@ |
| `42011da8` | `FUN_42011da8` | 14 | 3 | 1 |  |
| `42011db8` | `esp_partition_next` | 138 | 3 | 4 | esp_partition_next \| <k7@ |
| `42011e44` | `FUN_42011e44` | 58 | 3 | 3 |  |
| `42011e80` | `esp_partition_get` | 28 | 3 | 1 | iterator != NULL |
| `42011e9c` | `FUN_42011e9c` | 35 | 5 | 3 |  |
| `42011ec0` | `esp_partition_write` | 117 | 1 | 3 | partition != NULL |
| `42011f40` | `esp_partition_read_raw` | 65 | 1 | 2 | partition != NULL |
| `42011f88` | `esp_partition_write_raw` | 78 | 1 | 2 | partition != NULL |
| `42011fd8` | `esp_partition_erase_range` | 98 | 3 | 2 | partition != NULL |
| `42012044` | `esp_partition_mmap` | 102 | 1 | 2 | partition != NULL |
| `420120b8` | `esp_partition_read` | 127 | 4 | 4 | partition != NULL |
| `42012140` | `FUN_42012140` | 79 | 1 | 3 |  |
| `42012190` | `FUN_42012190` | 56 | 1 | 1 |  |
| `420121cc` | `FUN_420121cc` | 8 | 2 | 0 |  |
| `420121d4` | `FUN_420121d4` | 8 | 1 | 1 |  |
| `420121dc` | `FUN_420121dc` | 18 | 1 | 1 |  |
| `4201233c` | `esp_mmu_map_init` | 262 | 1 | 3 | hw_mem_regions[i].region_size % CONFIG_MMU_PAGE_ \| esp_mmu_m |
| `42012444` | `esp_mmu_map` | 654 | 1 | 8 | 8a7@ \| found \| esp_mmu_map.c \| esp_mmu_map \| pw7@\x7@ |
| `4201283c` | `FUN_4201283c` | 146 | 2 | 3 | 8a7@ |
| `42012938` | `esp_mspi_get_io` | 124 | 3 | 2 | io <= ESP_MSPI_IO_D7 |
| `420129b8` | `FUN_420129b8` | 87 | 1 | 3 | Pw7@ |
| `42012a10` | `FUN_42012a10` | 20 | 1 | 1 | T}7@8 |
| `42012a4c` | `FUN_42012a4c` | 60 | 1 | 1 |  |
| `42012a8c` | `FUN_42012a8c` | 27 | 1 | 1 | Pw7@ |
| `42012aa8` | `FUN_42012aa8` | 165 | 1 | 7 | 0~7@ |
| `42012b94` | `esp_crosscore_int_init` | 112 | 2 | 4 | /IDF/components/esp_system/crosscore_int.c \| esp_crosscore_i |
| `42013248` | `FUN_42013248` | 62 | 1 | 0 |  |
| `42013288` | `FUN_42013288` | 45 | 1 | 0 |  |
| `420132b8` | `FUN_420132b8` | 45 | 1 | 0 |  |
| `420132e8` | `FUN_420132e8` | 22 | 0 | 1 |  |
| `42013300` | `FUN_42013300` | 35 | 1 | 1 |  |
| `42013324` | `FUN_42013324` | 41 | 0 | 3 |  |
| `42013474` | `FUN_42013474` | 18 | 0 | 0 |  |
| `42013488` | `FUN_42013488` | 18 | 0 | 0 |  |
| `4201349c` | `FUN_4201349c` | 57 | 2 | 1 | false |
| `420134dc` | `FUN_420134dc` | 51 | 3 | 0 |  |
| `42013510` | `clk_hal_soc_root_get_freq_mhz` | 74 | 1 | 2 | false |
| `42013560` | `FUN_42013560` | 166 | 2 | 1 |  |
| `4201360c` | `FUN_4201360c` | 30 | 1 | 1 |  |
| `4201362c` | `FUN_4201362c` | 10 | 1 | 1 |  |
| `42013638` | `FUN_42013638` | 110 | 1 | 0 |  |
| `420136ac` | `FUN_420136ac` | 34 | 1 | 0 |  |
| `420136f0` | `FUN_420136f0` | 185 | 1 | 0 |  |
| `420138d4` | `FUN_420138d4` | 47 | 1 | 1 |  |
| `42013904` | `FUN_42013904` | 87 | 1 | 5 |  |
| `42013a38` | `FUN_42013a38` | 250 | 3 | 8 | &B9fR |
| `42013b50` | `FUN_42013b50` | 16 | 1 | 1 |  |
| `42013b60` | `FUN_42013b60` | 34 | 3 | 1 |  |
| `42013b84` | `FUN_42013b84` | 16 | 1 | 1 |  |
| `42013b94` | `FUN_42013b94` | 100 | 1 | 3 |  |
| `42013bfc` | `FUN_42013bfc` | 28 | 1 | 1 |  |
| `42013c18` | `FUN_42013c18` | 27 | 1 | 1 |  |
| `42013c34` | `FUN_42013c34` | 21 | 1 | 1 |  |
| `42013c4c` | `FUN_42013c4c` | 34 | 1 | 5 |  |
| `42013c70` | `FUN_42013c70` | 37 | 1 | 3 |  |
| `42013c98` | `FUN_42013c98` | 43 | 1 | 3 |  |
| `42013cc4` | `FUN_42013cc4` | 20 | 1 | 1 |  |
| `42013cd8` | `FUN_42013cd8` | 58 | 1 | 4 |  |
| `42013d14` | `FUN_42013d14` | 73 | 1 | 8 |  |
| `42013d60` | `FUN_42013d60` | 64 | 2 | 6 |  |
| `42013da4` | `FUN_42013da4` | 109 | 2 | 7 |  |
| `42014e70` | `FUN_42014e70` | 18 | 0 | 0 |  |
| `42014e84` | `FUN_42014e84` | 25 | 1 | 2 |  |
| `42014ea0` | `FUN_42014ea0` | 18 | 0 | 2 |  |
| `420150cc` | `FUN_420150cc` | 15 | 0 | 0 |  |
| `420150dc` | `FUN_420150dc` | 21 | 0 | 1 |  |
| `420150f4` | `FUN_420150f4` | 32 | 0 | 1 |  |
| `42015118` | `FUN_42015118` | 21 | 0 | 1 |  |
| `42015130` | `FUN_42015130` | 32 | 0 | 1 |  |
| `42015154` | `FUN_42015154` | 16 | 0 | 1 |  |
| `4201517c` | `FUN_4201517c` | 31 | 1 | 1 |  |
| `420151bc` | `FUN_420151bc` | 28 | 1 | 0 |  |
| `420151d8` | `FUN_420151d8` | 27 | 1 | 1 |  |
| `420151f4` | `FUN_420151f4` | 21 | 1 | 1 |  |
| `4201520c` | `FUN_4201520c` | 46 | 1 | 1 |  |
| `4201523c` | `FUN_4201523c` | 57 | 5 | 1 |  |
| `42015278` | `FUN_42015278` | 16 | 5 | 1 |  |
| `4201531c` | `FUN_4201531c` | 118 | 1 | 5 |  |
| `42015394` | `FUN_42015394` | 33 | 1 | 1 |  |
| `420154e8` | `FUN_420154e8` | 14 | 7 | 1 |  |
| `420154f8` | `FUN_420154f8` | 14 | 7 | 1 | <k7@ |
| `42015658` | `FUN_42015658` | 13 | 1 | 1 |  |
| `42016760` | `FUN_42016760` | 8 | 0 | 1 |  |
| `42016b24` | `FUN_42016b24` | 65 | 1 | 3 |  |
| `42016cd8` | `FUN_42016cd8` | 126 | 1 | 7 | phys_offs != SPI_FLASH_CACHE2PHYS_FAIL \| it != NULL \| esp_ot |
| `42016eec` | `FUN_42016eec` | 29 | 1 | 1 |  |
| `420171e4` | `FUN_420171e4` | 12 | 0 | 1 |  |
| `42017c84` | `FUN_42017c84` | 18 | 0 | 1 |  |
| `42018124` | `FUN_42018124` | 24 | 1 | 2 |  |
| `420242f4` | `FUN_420242f4` | 28 | 0 | 1 |  |
| `42024310` | `FUN_42024310` | 32 | 1 | 0 |  |
| `42024330` | `FUN_42024330` | 28 | 0 | 1 |  |
| `4202434c` | `FUN_4202434c` | 35 | 1 | 0 |  |
| `42024370` | `FUN_42024370` | 7 | 0 | 0 |  |
| `42024378` | `FUN_42024378` | 7 | 1 | 0 |  |
| `42024380` | `FUN_42024380` | 5 | 0 | 0 |  |
| `42024388` | `FUN_42024388` | 7 | 1 | 0 |  |
| `42024390` | `FUN_42024390` | 5 | 0 | 0 |  |
| `42024398` | `FUN_42024398` | 198 | 1 | 0 |  |
| `420244e0` | `FUN_420244e0` | 58 | 2 | 0 |  |
| `42024678` | `FUN_42024678` | 5 | 0 | 0 |  |
| `42024680` | `FUN_42024680` | 5 | 0 | 0 |  |
| `42024688` | `FUN_42024688` | 5 | 0 | 0 |  |
| `42024690` | `FUN_42024690` | 5 | 0 | 0 |  |
| `42024698` | `FUN_42024698` | 5 | 0 | 0 |  |
| `420246a0` | `FUN_420246a0` | 5 | 0 | 0 |  |
| `420246a8` | `FUN_420246a8` | 5 | 1 | 0 |  |
| `420246b0` | `FUN_420246b0` | 5 | 1 | 0 |  |
| `420246b8` | `FUN_420246b8` | 7 | 4 | 0 |  |
| `420246c0` | `FUN_420246c0` | 14 | 2 | 0 |  |
| `420246d0` | `FUN_420246d0` | 70 | 1 | 0 |  |
| `42024718` | `FUN_42024718` | 60 | 1 | 0 |  |
| `4202498c` | `FUN_4202498c` | 26 | 1 | 0 |  |
| `420249a8` | `FUN_420249a8` | 40 | 1 | 0 |  |
| `420249d4` | `FUN_420249d4` | 29 | 1 | 0 |  |
| `420249f4` | `FUN_420249f4` | 28 | 1 | 0 |  |
| `42024ba8` | `FUN_42024ba8` | 7 | 1 | 0 |  |
| `42024bb0` | `FUN_42024bb0` | 18 | 1 | 0 |  |
| `42024bc4` | `FUN_42024bc4` | 18 | 1 | 0 |  |
| `42024bd8` | `FUN_42024bd8` | 16 | 1 | 0 |  |
| `42024be8` | `FUN_42024be8` | 33 | 2 | 0 |  |
| `42024c0c` | `FUN_42024c0c` | 33 | 1 | 0 |  |
| `42024d40` | `FUN_42024d40` | 18 | 1 | 0 |  |
| `42024d54` | `FUN_42024d54` | 10 | 0 | 0 |  |
| `42024d60` | `FUN_42024d60` | 9 | 0 | 0 |  |
| `42024d6c` | `FUN_42024d6c` | 9 | 0 | 0 |  |
| `42024d78` | `FUN_42024d78` | 10 | 0 | 0 |  |
| `42024d84` | `FUN_42024d84` | 33 | 1 | 0 |  |
| `42024df0` | `FUN_42024df0` | 33 | 2 | 0 |  |
| `42024e5c` | `FUN_42024e5c` | 7 | 3 | 0 |  |
| `420250a4` | `FUN_420250a4` | 75 | 1 | 0 |  |
| `42025200` | `FUN_42025200` | 36 | 1 | 0 |  |
| `42025ac4` | `FUN_42025ac4` | 210 | 1 | 10 | dh7@ |
| `420261fc` | `esp_startup_start_app` | 76 | 1 | 6 | main \| esp_startup_start_app \| res == pdTRUE |
| `42026248` | `FUN_42026248` | 47 | 0 | 4 |  |
| `42026a70` | `FUN_42026a70` | 27 | 1 | 0 |  |
| `42026a8c` | `FUN_42026a8c` | 76 | 2 | 0 |  |

## right / idf/freertos (610)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40375a34` | `FUN_40375a34` | 30 | 0 | 2 |  |
| `40375a54` | `FUN_40375a54` | 114 | 0 | 0 |  |
| `40375b10` | `FUN_40375b10` | 26 | 2 | 3 |  |
| `40375b2c` | `FUN_40375b2c` | 18 | 0 | 2 |  |
| `40375b40` | `FUN_40375b40` | 18 | 1 | 2 |  |
| `40375b54` | `FUN_40375b54` | 15 | 1 | 0 |  |
| `40375e0c` | `FUN_40375e0c` | 40 | 2 | 2 |  |
| `40375e34` | `FUN_40375e34` | 29 | 1 | 1 |  |
| `40375e54` | `FUN_40375e54` | 230 | 0 | 5 | cpuid == xPortGetCoreID() |
| `40375f3c` | `FUN_40375f3c` | 37 | 1 | 0 |  |
| `40376168` | `FUN_40376168` | 186 | 1 | 1 | esp_ptr_in_diram_dram((void *)dstart) \|\| esp_ptr \| esp_ptr_i |
| `4037655c` | `FUN_4037655c` | 57 | 0 | 2 |  |
| `40376598` | `FUN_40376598` | 114 | 2 | 6 |  |
| `40376788` | `FUN_40376788` | 31 | 4 | 2 |  |
| `403767a8` | `FUN_403767a8` | 25 | 4 | 2 |  |
| `403767c4` | `FUN_403767c4` | 76 | 0 | 2 |  |
| `40376810` | `FUN_40376810` | 52 | 1 | 0 |  |
| `40376864` | `FUN_40376864` | 86 | 1 | 3 |  |
| `403768bc` | `FUN_403768bc` | 79 | 0 | 3 |  |
| `4037690c` | `FUN_4037690c` | 90 | 6 | 3 |  |
| `40376980` | `FUN_40376980` | 36 | 2 | 4 |  |
| `403769a4` | `check_lock_nonzero` | 23 | 3 | 1 | lock != NULL && 'Uninitialized lock used' |
| `403769bc` | `lock_acquire_generic` | 164 | 4 | 8 | h != ((void *)0) |
| `40376a64` | `lock_release_generic` | 90 | 2 | 7 |  |
| `40376ac4` | `_lock_close` | 55 | 2 | 5 | xQueueGetMutexHolder( ( h ) ) == ((void *)0) |
| `40376b1c` | `FUN_40376b1c` | 16 | 1 | 1 |  |
| `40376b2c` | `FUN_40376b2c` | 16 | 0 | 1 |  |
| `40376b70` | `FUN_40376b70` | 19 | 4 | 1 |  |
| `40376b84` | `FUN_40376b84` | 15 | 0 | 1 |  |
| `40376be4` | `FUN_40376be4` | 37 | 0 | 2 |  |
| `40376c5c` | `FUN_40376c5c` | 41 | 1 | 0 |  |
| `40376cd4` | `FUN_40376cd4` | 36 | 0 | 2 |  |
| `40376d2c` | `FUN_40376d2c` | 103 | 0 | 2 |  |
| `40376d98` | `FUN_40376d98` | 22 | 0 | 0 | Unhandled interrupt %d on cpu %d! |
| `403773a0` | `bootloader_flash_execute_command_common` | 714 | 1 | 1 | mosi_len <= 32 \| miso_len <= 32 \| bootloader_flash.c \| bootl |
| `40377b70` | `FUN_40377b70` | 15 | 1 | 1 |  |
| `40377b80` | `FUN_40377b80` | 17 | 3 | 1 |  |
| `403785b0` | `FUN_403785b0` | 24 | 0 | 3 |  |
| `40378744` | `FUN_40378744` | 90 | 0 | 5 |  |
| `403787f4` | `FUN_403787f4` | 15 | 16 | 1 |  |
| `403788fc` | `FUN_403788fc` | 20 | 2 | 0 |  |
| `403789ec` | `FUN_403789ec` | 8 | 1 | 0 |  |
| `403789f4` | `FUN_403789f4` | 46 | 3 | 0 |  |
| `40378a24` | `FUN_40378a24` | 7 | 1 | 0 |  |
| `40378a2c` | `FUN_40378a2c` | 98 | 1 | 1 | false \| /IDF/components/hal/esp32s3/include/hal/mspi_tim \| m |
| `40378a94` | `FUN_40378a94` | 98 | 1 | 1 | false \| /IDF/components/hal/esp32s3/include/hal/mspi_tim \| m |
| `40378afc` | `mspi_timing_config_set_flash_clock` | 129 | 2 | 2 | freqdiv > 0 |
| `40378b80` | `FUN_40378b80` | 78 | 1 | 2 | freqdiv > 0 |
| `40378bd0` | `FUN_40378bd0` | 28 | 1 | 2 |  |
| `40378bec` | `FUN_40378bec` | 18 | 1 | 1 |  |
| `40378cdc` | `FUN_40378cdc` | 32 | 1 | 1 | 0 && 'LDO dbias need to modified' |
| `40378e48` | `FUN_40378e48` | 14 | 2 | 0 |  |
| `40378e58` | `FUN_40378e58` | 14 | 1 | 0 |  |
| `40379670` | `FUN_40379670` | 431 | 1 | 0 |  |
| `40379b98` | `FUN_40379b98` | 40 | 2 | 0 |  |
| `40379c9c` | `prvReturnItemByteBuf` | 64 | 0 | 1 | (uint8_t *)pucItem >= pxRingbuffer->pucHead \| (uint8_t *)puc |
| `40379cdc` | `prvGetItemByteBuf` | 214 | 0 | 1 | (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf \| ringbuf.c |
| `40379db4` | `FUN_40379db4` | 99 | 0 | 1 | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea \| ringbuf.c |
| `40379e18` | `prvReturnItemDefault` | 285 | 0 | 1 | ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  \| pucItem > |
| `40379f38` | `prvGetItemDefault` | 324 | 0 | 1 | pxIsSplit != ((void *)0) \| (pxRingbuffer->xItemsWaiting > 0) |
| `4037a07c` | `prvAcquireItemNoSplit` | 164 | 2 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a120` | `prvSendItemDoneNoSplit` | 257 | 1 | 1 | ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  \| pucItem > |
| `4037a224` | `prvCheckItemFitsDefault` | 164 | 0 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a2cc` | `FUN_4037a2cc` | 191 | 1 | 2 | lock |
| `4037a390` | `FUN_4037a390` | 125 | 0 | 1 | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea \| ringbuf.c |
| `4037a410` | `prvCopyItemAllowSplit` | 233 | 0 | 1 | ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) \| pxRingbuf |
| `4037a4fc` | `FUN_4037a4fc` | 34 | 0 | 2 |  |
| `4037a520` | `FUN_4037a520` | 210 | 1 | 9 |  |
| `4037a5f8` | `prvReceiveGeneric` | 240 | 2 | 8 | *pvItem2 < *pvItem1 \| xIsSplit == ( ( BaseType_t ) 0 ) \| rin |
| `4037a6ec` | `prvReceiveGenericFromISR` | 153 | 1 | 4 | *pvItem2 < *pvItem1 \| xIsSplit == ( ( BaseType_t ) 0 ) \| rin |
| `4037a788` | `xRingbufferCreateStatic` | 129 | 1 | 2 | xBufferSize > 0 \| xBufferType < RINGBUF_TYPE_MAX \| ringbuf.c |
| `4037a80c` | `xRingbufferSend` | 100 | 3 | 2 | pxRingbuffer \| pvItem != ((void *)0) \|\| xItemSize == 0 \| rin |
| `4037a874` | `xRingbufferSendFromISR` | 213 | 1 | 5 | pxRingbuffer \| pvItem != ((void *)0) \|\| xItemSize == 0 \| rin |
| `4037a950` | `xRingbufferReceive` | 64 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceive |
| `4037a990` | `xRingbufferReceiveFromISR` | 64 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceiveF |
| `4037a9d0` | `xRingbufferReceiveUpTo` | 90 | 1 | 2 | pxRingbuffer && pxItemSize \| ringbuf.c \| xRingbufferReceiveU |
| `4037aa2c` | `vRingbufferReturnItem` | 92 | 2 | 5 | pxRingbuffer \| pvItem != ((void *)0) \| ringbuf.c \| vRingbuff |
| `4037aa88` | `vRingbufferReturnItemFromISR` | 96 | 1 | 4 | pxRingbuffer \| pvItem != ((void *)0) \| ringbuf.c \| vRingbuff |
| `4037aae8` | `vRingbufferDelete` | 39 | 1 | 2 | pxRingbuffer |
| `4037ab10` | `xRingbufferGetMaxItemSize` | 25 | 1 | 1 | pxRingbuffer |
| `4037ab2c` | `xRingbufferGetCurFreeSize` | 48 | 1 | 3 | pxRingbuffer |
| `4037ab5c` | `FUN_4037ab5c` | 99 | 1 | 3 | pxRingbuffer \| vRingbufferGetInfo |
| `4037abc0` | `xRingbufferGetStaticBuffer` | 58 | 1 | 1 | pxRingbuffer && ppucRingbufferStorage && ppxStat \| ringbuf.c |
| `4037ac50` | `vRingbufferDeleteWithCaps` | 56 | 1 | 4 | xResult == ( ( BaseType_t ) 1 ) |
| `4037ac88` | `FUN_4037ac88` | 71 | 2 | 0 |  |
| `4037acd4` | `FUN_4037acd4` | 63 | 0 | 0 |  |
| `4037aef4` | `FUN_4037aef4` | 34 | 0 | 0 |  |
| `4037af18` | `FUN_4037af18` | 75 | 1 | 2 | %s failed: esp_err_t 0x%x \|  (%s) \|  at 0x%08x \| file: '%s'  |
| `4037af64` | `ESP_ERROR_CHECK` | 42 | 7 | 2 | ESP_ERROR_CHECK |
| `4037afa0` | `FUN_4037afa0` | 142 | 3 | 1 |  |
| `4037b030` | `FUN_4037b030` | 35 | 2 | 0 |  |
| `4037b054` | `pxQueueSetContainer` | 148 | 3 | 6 | pxQueueSetContainer \| pxQueueSetContainer->uxMessagesWaiting |
| `4037b0ec` | `xQueueGenericReset` | 174 | 3 | 6 | pxQueue \| xQueueGenericReset \| xReturn != ( ( ( BaseType_t ) |
| `4037b1a0` | `FUN_4037b1a0` | 31 | 2 | 1 |  |
| `4037b1c0` | `xQueueGenericCreateStatic` | 142 | 6 | 2 | pxStaticQueue \| queue.c \| xQueueGenericCreateStatic \| xSize  |
| `4037b250` | `xQueueGenericGetStaticBuffers` | 64 | 2 | 1 | pxQueue \| ppxStaticQueue \| queue.c \| xQueueGenericGetStaticB |
| `4037b294` | `xQueueGenericCreate` | 83 | 5 | 3 | pxNewQueue \| queue.c \| xQueueGenericCreate |
| `4037b2e8` | `xSemaphore` | 54 | 1 | 3 | xSemaphore \| xQueueGetMutexHolder |
| `4037b320` | `FUN_4037b320` | 64 | 1 | 2 | xHandle |
| `4037b360` | `FUN_4037b360` | 60 | 1 | 2 | xHandle |
| `4037b39c` | `xQueueGenericSend` | 313 | 18 | 11 | pxQueue \| !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue \| |
| `4037b4d8` | `FUN_4037b4d8` | 60 | 2 | 2 | lock |
| `4037b514` | `FUN_4037b514` | 22 | 3 | 2 |  |
| `4037b52c` | `FUN_4037b52c` | 26 | 3 | 2 |  |
| `4037b548` | `xQueueGiveMutexRecursive` | 63 | 2 | 3 | x'e= \| pxMutex |
| `4037b588` | `xQueueGenericSendFromISR` | 216 | 5 | 6 | pxQueue \| !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue \| |
| `4037b664` | `xQueueGiveFromISR` | 184 | 4 | 5 | pxQueue \| pxQueue->uxItemSize == 0 \| queue.c \| xQueueGiveFro |
| `4037b720` | `xQueueReceive` | 230 | 6 | 10 | ( pxQueue ) \| !( ( ( pvBuffer ) == ((void *)0) ) && ( ( pxQu |
| `4037b80c` | `xQueueSemaphoreTake` | 261 | 9 | 13 | ( pxQueue ) \| pxQueue->uxItemSize == 0 \| queue.c \| xQueueSem |
| `4037b914` | `xQueueTakeMutexRecursive` | 65 | 2 | 3 | pxMutex |
| `4037b958` | `xQueueReceiveFromISR` | 134 | 3 | 5 | pxQueue \| !( ( pvBuffer == ((void *)0) ) && ( pxQueue->uxI \| |
| `4037b9e0` | `uxQueueSpacesAvailable` | 50 | 2 | 3 | pxQueue |
| `4037ba14` | `vQueueDelete` | 36 | 4 | 2 | pxQueue |
| `4037ba38` | `FUN_4037ba38` | 39 | 1 | 3 |  |
| `4037bae4` | `FUN_4037bae4` | 27 | 1 | 1 |  |
| `4037bb00` | `FUN_4037bb00` | 40 | 2 | 4 |  |
| `4037bb28` | `pxPortInitialiseStack` | 153 | 1 | 1 | (uxStackPointer & ( 0x000f )) == 0 |
| `4037bbc4` | `FUN_4037bbc4` | 34 | 27 | 0 |  |
| `4037bbe8` | `spinlock_acquire` | 332 | 130 | 2 | lock \| lock->count > 0 && lock->count < 0xFF \| spinlock.h \|  |
| `4037bd38` | `vPortExitCritical` | 152 | 129 | 1 | lock \| core_owner_id == lock->owner \| spinlock.h \| spinlock_ |
| `4037bdd4` | `FUN_4037bdd4` | 10 | 3 | 1 |  |
| `4037be20` | `FUN_4037be20` | 18 | 1 | 2 |  |
| `4037be34` | `FUN_4037be34` | 21 | 10 | 0 |  |
| `4037bee0` | `FUN_4037bee0` | 100 | 1 | 2 |  |
| `4037c04c` | `FUN_4037c04c` | 18 | 6 | 1 |  |
| `4037c060` | `FUN_4037c060` | 10 | 5 | 1 |  |
| `4037c06c` | `FUN_4037c06c` | 88 | 2 | 1 |  |
| `4037c0c8` | `FUN_4037c0c8` | 88 | 3 | 1 |  |
| `4037c124` | `FUN_4037c124` | 88 | 1 | 1 |  |
| `4037c17c` | `vApplicationGetIdleTaskMemory` | 61 | 1 | 2 | pxTCBBufferTemp != NULL \| pxStackBufferTemp != NULL \| port_c |
| `4037c1bc` | `vApplicationGetTimerTaskMemory` | 64 | 1 | 2 | pxTCBBufferTemp != NULL \| pxStackBufferTemp != NULL \| port_c |
| `4037c34c` | `FUN_4037c34c` | 8 | 1 | 1 |  |
| `4037c354` | `FUN_4037c354` | 37 | 1 | 4 |  |
| `4037c400` | `FUN_4037c400` | 40 | 1 | 0 |  |
| `4037c428` | `FUN_4037c428` | 52 | 2 | 1 |  |
| `4037c47c` | `FUN_4037c47c` | 38 | 2 | 1 |  |
| `4037c4a4` | `FUN_4037c4a4` | 56 | 2 | 2 |  |
| `4037c4e0` | `FUN_4037c4e0` | 51 | 1 | 1 |  |
| `4037c514` | `FUN_4037c514` | 42 | 2 | 2 |  |
| `4037c540` | `FUN_4037c540` | 118 | 1 | 6 |  |
| `4037c5bc` | `prvProcessReceivedCommands` | 282 | 1 | 7 | ( pxTimer->xTimerPeriodInTicks > 0 ) \| timers.c \| prvProcess |
| `4037c6e4` | `FUN_4037c6e4` | 21 | 0 | 3 |  |
| `4037c6fc` | `FUN_4037c6fc` | 72 | 2 | 4 |  |
| `4037c744` | `prvInitialiseNewTimer` | 54 | 1 | 3 | ( xTimerPeriodInTicks > 0 ) |
| `4037c77c` | `xTimerCreateTimerTask` | 86 | 1 | 4 | timers.c \| xTimerCreateTimerTask \| xReturn |
| `4037c7d4` | `FUN_4037c7d4` | 38 | 1 | 2 |  |
| `4037c7fc` | `xTimerGenericCommand` | 108 | 2 | 4 | xTimer |
| `4037c86c` | `pvTimerGetTimerID` | 42 | 1 | 3 | xTimer |
| `4037c898` | `FUN_4037c898` | 30 | 1 | 0 |  |
| `4037c8b8` | `FUN_4037c8b8` | 36 | 4 | 0 |  |
| `4037c8dc` | `FUN_4037c8dc` | 12 | 2 | 0 |  |
| `4037c8e8` | `FUN_4037c8e8` | 57 | 1 | 0 |  |
| `4037c924` | `FUN_4037c924` | 91 | 3 | 0 |  |
| `4037c980` | `FUN_4037c980` | 82 | 9 | 0 |  |
| `4037c9d4` | `FUN_4037c9d4` | 69 | 2 | 0 |  |
| `4037ca1c` | `FUN_4037ca1c` | 59 | 3 | 0 |  |
| `4037ca58` | `prvIsYieldRequiredSMP` | 152 | 6 | 2 | uxTaskPriority < ( 25 ) \| prvIsYieldRequiredSMP |
| `4037caf4` | `prvSelectHighestPriorityTaskSMP` | 483 | 1 | 1 | xTaskScheduled == ( ( BaseType_t ) 1 ) \| tasks.c \| prvSelect |
| `4037ccdc` | `prvDeleteTCB` | 71 | 2 | 4 | pxTCB->ucStaticallyAllocated == ( ( uint8_t ) 2  |
| `4037cd24` | `FUN_4037cd24` | 148 | 1 | 4 |  |
| `4037cdbc` | `FUN_4037cdbc` | 279 | 4 | 2 |  |
| `4037ced8` | `FUN_4037ced8` | 15 | 0 | 2 |  |
| `4037cee8` | `FUN_4037cee8` | 158 | 2 | 4 | uxPriority < ( 25 ) \| tasks.c \| prvInitialiseNewTask |
| `4037cf88` | `FUN_4037cf88` | 103 | 1 | 1 |  |
| `4037cff0` | `FUN_4037cff0` | 417 | 2 | 5 |  |
| `4037d194` | `FUN_4037d194` | 46 | 2 | 2 |  |
| `4037d1c4` | `FUN_4037d1c4` | 13 | 5 | 0 |  |
| `4037d1d4` | `FUN_4037d1d4` | 30 | 1 | 2 |  |
| `4037d1f4` | `xTaskIncrementTick` | 704 | 2 | 5 | xPortGetCoreID() == 0 \| ( ( ( ( pxDelayedTaskList )->uxNumbe |
| `4037d4bc` | `FUN_4037d4bc` | 166 | 1 | 5 |  |
| `4037d564` | `vTaskPlaceOnEventList` | 71 | 5 | 5 | pxEventList |
| `4037d5ac` | `vTaskPlaceOnEventListRestricted` | 183 | 1 | 4 | pxEventList \| vTaskPlaceOnEventListRestricted |
| `4037d664` | `xTaskRemoveFromEventList` | 504 | 12 | 6 | pxUnblockedTCB \| tasks.c \| xTaskRemoveFromEventList \| uxSche |
| `4037d860` | `FUN_4037d860` | 25 | 6 | 0 |  |
| `4037d87c` | `xTaskCheckForTimeOut` | 182 | 5 | 4 | pxTimeOut \| pxTicksToWait \| tasks.c \| xTaskCheckForTimeOut |
| `4037d934` | `FUN_4037d934` | 31 | 14 | 0 |  |
| `4037d954` | `FUN_4037d954` | 31 | 1 | 3 |  |
| `4037d974` | `vTaskPrioritySet` | 339 | 2 | 8 | uxNewPriority < ( 25 ) |
| `4037dacc` | `pcTaskGetName` | 34 | 2 | 2 | pxTCB |
| `4037daf0` | `FUN_4037daf0` | 28 | 2 | 1 |  |
| `4037db0c` | `FUN_4037db0c` | 55 | 14 | 0 |  |
| `4037db44` | `vTaskDelete` | 242 | 2 | 11 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) \| vTaskDele |
| `4037dc38` | `vTaskDelay` | 59 | 5 | 6 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) |
| `4037dc74` | `xTaskResumeAll` | 488 | 2 | 8 | ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) \| xTaskResu |
| `4037de64` | `FUN_4037de64` | 271 | 1 | 3 |  |
| `4037df74` | `xTaskPriorityDisinherit` | 232 | 1 | 4 | pxTCB == pxCurrentTCBs[ xPortGetCoreID() ] \| pxTCB->uxMutexe |
| `4037e05c` | `vTaskPriorityDisinheritAfterTimeout` | 248 | 1 | 4 | pxTCB->uxMutexesHeld \| pxTCB != pxCurrentTCBs[ xPortGetCoreI |
| `4037e154` | `FUN_4037e154` | 71 | 1 | 2 |  |
| `4037e19c` | `ulTaskGenericNotifyTake` | 240 | 2 | 5 | uxIndexToWait < 1 \| ulTaskGenericNotifyTake |
| `4037e290` | `xTaskGenericNotify` | 462 | 3 | 5 | uxIndexToNotify < 1 \| xTaskToNotify \| tasks.c \| xTaskGeneric |
| `4037e464` | `vTaskGenericNotifyGiveFromISR` | 418 | 1 | 5 | xTaskToNotify \| uxIndexToNotify < 1 \| tasks.c \| vTaskGeneric |
| `4037e608` | `xTaskIncrementTickOtherCores` | 122 | 1 | 3 | xCoreID != 0 \| xTaskIncrementTickOtherCores |
| `4037e684` | `FUN_4037e684` | 148 | 7 | 5 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT |
| `4037e718` | `xTaskCreateStaticPinnedToCore` | 227 | 2 | 5 | xPortcheckValidStackMem(puxStackBuffer) \| xPortCheckValidTCB |
| `4037e7fc` | `FUN_4037e7fc` | 140 | 1 | 2 | IDLE |
| `4037e88c` | `vTaskStartScheduler` | 97 | 1 | 6 | xReturn != ( -1 ) \| tasks.c \| vTaskStartScheduler |
| `4037e8f0` | `FUN_4037e8f0` | 16 | 2 | 1 |  |
| `4037e900` | `xTaskGetIdleTaskHandleForCore` | 52 | 1 | 1 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT \| ( xIdleTa |
| `4037e934` | `xTaskGetCurrentTaskHandleForCore` | 39 | 2 | 1 | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT |
| `4037e95c` | `FUN_4037e95c` | 51 | 1 | 3 |  |
| `4037e990` | `FUN_4037e990` | 19 | 26 | 1 |  |
| `4037e9a8` | `FUN_4037e9a8` | 37 | 2 | 1 |  |
| `4037ec1c` | `FUN_4037ec1c` | 75 | 1 | 0 |  |
| `4037edcc` | `mmu_ll_check_entry_valid` | 51 | 2 | 1 | entry_id < SOC_MMU_ENTRY_NUM |
| `4037ee00` | `mmu_ll_get_entry_target` | 49 | 2 | 1 | entry_id < SOC_MMU_ENTRY_NUM |
| `4037ee34` | `FUN_4037ee34` | 60 | 1 | 2 |  |
| `4037ee70` | `mmu_ll_entry_id_to_paddr_base` | 48 | 1 | 1 | entry_id < SOC_MMU_ENTRY_NUM |
| `4037f074` | `mmu_hal_vaddr_to_paddr` | 84 | 1 | 6 | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad |
| `40381d6c` | `FUN_40381d6c` | 47 | 1 | 0 |  |
| `40381d9c` | `FUN_40381d9c` | 237 | 216 | 3 | assert failed:  \| <cached disabled> |
| `40381ed0` | `FUN_40381ed0` | 43 | 2 | 1 |  |
| `40381efc` | `FUN_40381efc` | 20 | 6 | 2 |  |
| `40381f10` | `FUN_40381f10` | 5 | 0 | 0 |  |
| `40381f18` | `FUN_40381f18` | 82 | 1 | 3 |  |
| `403820c8` | `memspi_host_erase_sector` | 62 | 0 | 1 | start_address < 0x1000000 |
| `40382108` | `memspi_host_erase_block` | 62 | 0 | 1 | start_address < 0x1000000 |
| `40382148` | `memspi_host_program_page` | 68 | 0 | 1 | address + length <= 0x1000000 |
| `403839e4` | `FUN_403839e4` | 269 | 1 | 0 |  |
| `40383af8` | `FUN_40383af8` | 35 | 3 | 1 |  |
| `40383b1c` | `FUN_40383b1c` | 47 | 1 | 0 |  |
| `40383c20` | `FUN_40383c20` | 67 | 1 | 1 |  |
| `40383c64` | `FUN_40383c64` | 21 | 1 | 0 |  |
| `40383c7c` | `FUN_40383c7c` | 65 | 1 | 0 | K3G3 |
| `4200164c` | `FUN_4200164c` | 10 | 0 | 1 |  |
| `42001c04` | `FUN_42001c04` | 43 | 2 | 0 |  |
| `42002258` | `FUN_42002258` | 119 | 2 | 3 |  |
| `4200241c` | `FUN_4200241c` | 31 | 1 | 1 |  |
| `4200271c` | `FUN_4200271c` | 50 | 0 | 0 | Unknown \| Exception was unhandled. |
| `42002750` | `FUN_42002750` | 97 | 0 | 1 | Unknown reason |
| `420027d4` | `FUN_420027d4` | 216 | 1 | 7 |  |
| `42002948` | `FUN_42002948` | 21 | 1 | 1 |  |
| `42002960` | `FUN_42002960` | 171 | 1 | 6 |  |
| `42002a10` | `FUN_42002a10` | 51 | 1 | 1 |  |
| `42002a44` | `FUN_42002a44` | 82 | 2 | 2 |  |
| `42002aa0` | `FUN_42002aa0` | 82 | 2 | 2 |  |
| `42002af8` | `FUN_42002af8` | 21 | 1 | 1 |  |
| `42002b10` | `FUN_42002b10` | 62 | 1 | 2 |  |
| `42002b78` | `FUN_42002b78` | 39 | 3 | 0 |  |
| `42002ba0` | `FUN_42002ba0` | 24 | 1 | 1 |  |
| `420031b8` | `FUN_420031b8` | 34 | 1 | 0 |  |
| `420031dc` | `FUN_420031dc` | 13 | 1 | 0 |  |
| `420031ec` | `FUN_420031ec` | 224 | 5 | 6 |  |
| `420033ac` | `find_desc_for_source` | 114 | 1 | 1 | svd != NULL |
| `42003a40` | `FUN_42003a40` | 78 | 1 | 3 |  |
| `42003ac4` | `FUN_42003ac4` | 90 | 1 | 4 |  |
| `42005efc` | `FUN_42005efc` | 62 | 1 | 2 |  |
| `420060e4` | `FUN_420060e4` | 8 | 1 | 1 |  |
| `42006158` | `FUN_42006158` | 36 | 1 | 2 |  |
| `420061d0` | `FUN_420061d0` | 8 | 1 | 1 |  |
| `420061d8` | `FUN_420061d8` | 45 | 2 | 2 |  |
| `42006250` | `FUN_42006250` | 77 | 1 | 3 |  |
| `420062a0` | `FUN_420062a0` | 28 | 2 | 2 |  |
| `420062bc` | `FUN_420062bc` | 186 | 1 | 7 |  |
| `4200653c` | `FUN_4200653c` | 102 | 1 | 3 |  |
| `42006634` | `FUN_42006634` | 85 | 1 | 3 |  |
| `42006848` | `FUN_42006848` | 225 | 0 | 3 |  |
| `42006930` | `FUN_42006930` | 60 | 0 | 2 |  |
| `420069a0` | `FUN_420069a0` | 865 | 0 | 5 |  |
| `42006d1c` | `FUN_42006d1c` | 825 | 0 | 7 |  |
| `42007194` | `FUN_42007194` | 49 | 0 | 1 | fd >= 0 && fd < 3 |
| `420073f4` | `FUN_420073f4` | 38 | 1 | 2 | esp_vfs_register_fs('/dev/uart', &s_vfs_uart, ES |
| `4200741c` | `FUN_4200741c` | 10 | 0 | 1 |  |
| `42007428` | `FUN_42007428` | 45 | 1 | 0 |  |
| `42007458` | `FUN_42007458` | 61 | 2 | 0 |  |
| `42007498` | `FUN_42007498` | 86 | 2 | 2 |  |
| `42007664` | `FUN_42007664` | 64 | 1 | 3 |  |
| `420077e0` | `FUN_420077e0` | 167 | 2 | 4 |  |
| `42007888` | `FUN_42007888` | 107 | 1 | 4 |  |
| `420078f4` | `FUN_420078f4` | 2161 | 0 | 14 | 0ptp \| GekpW \| 7eH\| \| 'eG\| |
| `4200817c` | `FUN_4200817c` | 110 | 2 | 4 | Db7@8a7@ |
| `420082bc` | `FUN_420082bc` | 66 | 1 | 3 |  |
| `42008300` | `FUN_42008300` | 34 | 1 | 1 |  |
| `42008324` | `FUN_42008324` | 66 | 1 | 3 |  |
| `42008368` | `FUN_42008368` | 61 | 1 | 3 |  |
| `420083a8` | `FUN_420083a8` | 61 | 1 | 3 |  |
| `420083e8` | `FUN_420083e8` | 61 | 1 | 3 |  |
| `42008428` | `FUN_42008428` | 239 | 1 | 5 |  |
| `42008518` | `FUN_42008518` | 85 | 1 | 5 |  |
| `42008570` | `FUN_42008570` | 86 | 2 | 2 |  |
| `420085c8` | `FUN_420085c8` | 111 | 1 | 4 |  |
| `4200863c` | `FUN_4200863c` | 18 | 1 | 1 |  |
| `42008650` | `FUN_42008650` | 17 | 1 | 1 |  |
| `42008664` | `FUN_42008664` | 98 | 1 | 3 |  |
| `420086c8` | `FUN_420086c8` | 373 | 1 | 9 | @d VF |
| `42008d38` | `FUN_42008d38` | 186 | 1 | 5 |  |
| `42008f7c` | `FUN_42008f7c` | 53 | 2 | 1 |  |
| `42008fb4` | `FUN_42008fb4` | 236 | 1 | 8 |  |
| `420090a4` | `FUN_420090a4` | 71 | 1 | 2 |  |
| `420090ec` | `FUN_420090ec` | 315 | 3 | 10 |  |
| `4200922c` | `FUN_4200922c` | 101 | 1 | 8 |  |
| `42009294` | `FUN_42009294` | 303 | 1 | 7 |  |
| `42009408` | `FUN_42009408` | 40 | 0 | 2 | ,m7@H |
| `42009770` | `FUN_42009770` | 149 | 0 | 3 |  |
| `42009b30` | `FUN_42009b30` | 30 | 0 | 0 |  |
| `42009b50` | `FUN_42009b50` | 36 | 0 | 1 | /dev/uart/0 \| /dev/secondary |
| `42009b74` | `FUN_42009b74` | 30 | 0 | 1 |  |
| `42009b94` | `FUN_42009b94` | 20 | 0 | 1 |  |
| `42009ba8` | `FUN_42009ba8` | 22 | 0 | 1 |  |
| `42009bc0` | `FUN_42009bc0` | 22 | 0 | 1 |  |
| `42009bd8` | `FUN_42009bd8` | 22 | 0 | 1 |  |
| `42009bf0` | `FUN_42009bf0` | 22 | 0 | 1 |  |
| `42009c08` | `FUN_42009c08` | 18 | 0 | 1 | /dev/uart/0 |
| `42009c34` | `FUN_42009c34` | 20 | 0 | 1 |  |
| `42009c48` | `FUN_42009c48` | 18 | 0 | 1 |  |
| `42009ed0` | `translate_path` | 58 | 6 | 1 | strncmp(src_path, vfs->path_prefix, vfs->path_pr |
| `42009f6c` | `FUN_42009f6c` | 34 | 1 | 0 |  |
| `42009f90` | `FUN_42009f90` | 37 | 11 | 1 |  |
| `42009fb8` | `FUN_42009fb8` | 104 | 6 | 0 |  |
| `4200a024` | `FUN_4200a024` | 249 | 2 | 5 | <k7@ |
| `4200a128` | `FUN_4200a128` | 108 | 2 | 1 |  |
| `4200a198` | `FUN_4200a198` | 108 | 2 | 1 |  |
| `4200a208` | `FUN_4200a208` | 108 | 2 | 1 |  |
| `4200a33c` | `FUN_4200a33c` | 105 | 3 | 1 |  |
| `4200a3a8` | `FUN_4200a3a8` | 108 | 1 | 1 |  |
| `4200a418` | `FUN_4200a418` | 108 | 1 | 2 |  |
| `4200a488` | `FUN_4200a488` | 77 | 0 | 2 |  |
| `4200a4d8` | `FUN_4200a4d8` | 122 | 0 | 2 |  |
| `4200a554` | `FUN_4200a554` | 84 | 0 | 2 |  |
| `4200a5ac` | `FUN_4200a5ac` | 135 | 0 | 2 |  |
| `4200a634` | `FUN_4200a634` | 86 | 1 | 3 |  |
| `4200a6e0` | `FUN_4200a6e0` | 72 | 2 | 1 |  |
| `4200a72c` | `FUN_4200a72c` | 116 | 1 | 2 |  |
| `4200a7a4` | `FUN_4200a7a4` | 120 | 0 | 2 |  |
| `4200a820` | `FUN_4200a820` | 112 | 1 | 2 |  |
| `4200a894` | `FUN_4200a894` | 116 | 0 | 2 |  |
| `4200abfc` | `FUN_4200abfc` | 41 | 1 | 1 |  |
| `4200ac28` | `FUN_4200ac28` | 8 | 2 | 1 |  |
| `4200ac64` | `FUN_4200ac64` | 18 | 1 | 1 |  |
| `4200ac78` | `FUN_4200ac78` | 33 | 2 | 1 | hi7@hi |
| `4200ac9c` | `FUN_4200ac9c` | 122 | 2 | 6 |  |
| `4200ad18` | `FUN_4200ad18` | 230 | 1 | 4 |  |
| `4200aed4` | `FUN_4200aed4` | 143 | 8 | 3 | zUpD |
| `4200b1f8` | `FUN_4200b1f8` | 36 | 2 | 1 |  |
| `4200b220` | `FUN_4200b220` | 91 | 2 | 1 |  |
| `4200b27c` | `FUN_4200b27c` | 127 | 4 | 2 |  |
| `4200b300` | `FUN_4200b300` | 31 | 1 | 1 |  |
| `4200b320` | `FUN_4200b320` | 25 | 1 | 1 |  |
| `4200b33c` | `FUN_4200b33c` | 20 | 1 | 1 |  |
| `4200b350` | `FUN_4200b350` | 140 | 1 | 2 |  |
| `4200b3e0` | `FUN_4200b3e0` | 42 | 0 | 1 |  |
| `4200b40c` | `FUN_4200b40c` | 88 | 2 | 1 |  |
| `4200b468` | `FUN_4200b468` | 123 | 1 | 2 |  |
| `4200b4e4` | `FUN_4200b4e4` | 30 | 2 | 1 |  |
| `4200b504` | `FUN_4200b504` | 37 | 1 | 2 |  |
| `4200b52c` | `FUN_4200b52c` | 165 | 1 | 6 |  |
| `4200b5d8` | `FUN_4200b5d8` | 42 | 1 | 2 |  |
| `4200b604` | `FUN_4200b604` | 38 | 1 | 2 |  |
| `4200b62c` | `FUN_4200b62c` | 113 | 1 | 5 |  |
| `4200b6a0` | `FUN_4200b6a0` | 32 | 1 | 2 |  |
| `4200b6c0` | `FUN_4200b6c0` | 58 | 1 | 2 |  |
| `4200b6fc` | `FUN_4200b6fc` | 158 | 1 | 3 | ''!;'\| |
| `4200b79c` | `ESP_EXTRA_INFO` | 150 | 1 | 5 | ESP_EXTRA_INFO |
| `4200b834` | `FUN_4200b834` | 84 | 1 | 4 |  |
| `4200b88c` | `FUN_4200b88c` | 198 | 1 | 8 |  |
| `4200b988` | `FUN_4200b988` | 8 | 2 | 0 |  |
| `4200b9c0` | `FUN_4200b9c0` | 30 | 1 | 0 |  |
| `4200bbcc` | `FUN_4200bbcc` | 52 | 1 | 0 |  |
| `4200bc00` | `FUN_4200bc00` | 12 | 1 | 0 |  |
| `4200bc0c` | `FUN_4200bc0c` | 8 | 1 | 0 |  |
| `4200bc14` | `FUN_4200bc14` | 32 | 1 | 1 |  |
| `4200bc34` | `FUN_4200bc34` | 92 | 1 | 0 |  |
| `4200bc94` | `FUN_4200bc94` | 155 | 1 | 1 |  |
| `4200bd80` | `FUN_4200bd80` | 47 | 1 | 3 |  |
| `4200be00` | `FUN_4200be00` | 10 | 1 | 0 |  |
| `4200be0c` | `FUN_4200be0c` | 17 | 1 | 0 |  |
| `4200be78` | `FUN_4200be78` | 50 | 1 | 0 |  |
| `4200bff8` | `FUN_4200bff8` | 69 | 0 | 3 |  |
| `4200c204` | `FUN_4200c204` | 242 | 2 | 0 |  |
| `4200c2f8` | `FUN_4200c2f8` | 184 | 1 | 0 |  |
| `4200c448` | `FUN_4200c448` | 94 | 2 | 1 |  |
| `4200c4a8` | `FUN_4200c4a8` | 777 | 3 | 3 |  |
| `4200c7b8` | `FUN_4200c7b8` | 162 | 1 | 3 |  |
| `4200c920` | `FUN_4200c920` | 87 | 1 | 2 |  |
| `4200c978` | `FUN_4200c978` | 18 | 3 | 2 |  |
| `4200c98c` | `FUN_4200c98c` | 55 | 2 | 2 |  |
| `4200c9c8` | `FUN_4200c9c8` | 376 | 1 | 2 |  |
| `4200cb58` | `FUN_4200cb58` | 533 | 1 | 2 | f(,0 |
| `4200cd88` | `FUN_4200cd88` | 427 | 1 | 1 |  |
| `4200d388` | `FUN_4200d388` | 90 | 4 | 5 |  |
| `4200d3e4` | `usb_xfer_submit` | 460 | 4 | 8 |  |
| `4200d5bc` | `FUN_4200d5bc` | 254 | 1 | 4 |  |
| `4200d6bc` | `FUN_4200d6bc` | 10 | 0 | 1 |  |
| `4200d73c` | `FUN_4200d73c` | 22 | 0 | 1 |  |
| `4200d754` | `FUN_4200d754` | 40 | 1 | 1 |  |
| `4200d790` | `FUN_4200d790` | 68 | 1 | 1 |  |
| `4200d7d4` | `FUN_4200d7d4` | 77 | 2 | 4 |  |
| `4200d824` | `FUN_4200d824` | 16 | 1 | 1 |  |
| `4200d834` | `FUN_4200d834` | 14 | 1 | 1 |  |
| `4200d844` | `FUN_4200d844` | 25 | 1 | 1 |  |
| `4200d860` | `FUN_4200d860` | 29 | 1 | 1 |  |
| `4200d880` | `FUN_4200d880` | 20 | 1 | 1 |  |
| `4200d894` | `FUN_4200d894` | 88 | 1 | 4 |  |
| `4200d8f0` | `FUN_4200d8f0` | 122 | 1 | 4 |  |
| `4200d970` | `FUN_4200d970` | 78 | 1 | 2 |  |
| `4200d9c0` | `FUN_4200d9c0` | 46 | 1 | 2 |  |
| `4200d9f0` | `FUN_4200d9f0` | 83 | 3 | 5 |  |
| `4200da44` | `FUN_4200da44` | 42 | 6 | 2 |  |
| `4200da70` | `FUN_4200da70` | 34 | 6 | 2 |  |
| `4200dad4` | `FUN_4200dad4` | 26 | 1 | 1 |  |
| `4200daf0` | `FUN_4200daf0` | 100 | 1 | 0 |  |
| `4200db58` | `FUN_4200db58` | 206 | 1 | 0 | invalid device bLength 0x%02x \| unexpected device descriptor |
| `4200dc2c` | `FUN_4200dc2c` | 464 | 1 | 0 | invalid config bLength 0x%02x \| unexpected config descriptor |
| `4200de3c` | `FUN_4200de3c` | 159 | 2 | 1 |  |
| `4200dee0` | `FUN_4200dee0` | 91 | 2 | 3 |  |
| `4200df94` | `FUN_4200df94` | 113 | 10 | 3 |  |
| `4200e008` | `FUN_4200e008` | 1189 | 1 | 10 | Failed to get device descriptor,errorcode:%d \| Failed to get |
| `4200e4b8` | `FUN_4200e4b8` | 48 | 3 | 3 |  |
| `4200e4e8` | `FUN_4200e4e8` | 60 | 1 | 1 |  |
| `4200e524` | `FUN_4200e524` | 60 | 1 | 1 |  |
| `4200e560` | `FUN_4200e560` | 60 | 1 | 1 |  |
| `4200e778` | `FUN_4200e778` | 106 | 1 | 1 |  |
| `4200e824` | `FUN_4200e824` | 110 | 1 | 1 |  |
| `4200e894` | `FUN_4200e894` | 110 | 1 | 1 |  |
| `4200e904` | `FUN_4200e904` | 54 | 1 | 0 |  |
| `4200e988` | `FUN_4200e988` | 104 | 0 | 4 |  |
| `4200e9f4` | `FUN_4200e9f4` | 86 | 0 | 1 |  |
| `4200ed04` | `FUN_4200ed04` | 65 | 1 | 2 |  |
| `4200ed48` | `FUN_4200ed48` | 888 | 1 | 11 | zwpp \| Failed to reset port %u,errorcode:%d \| Failed to clea |
| `4200f0cc` | `FUN_4200f0cc` | 35 | 0 | 3 |  |
| `4200f0f0` | `FUN_4200f0f0` | 22 | 3 | 1 |  |
| `4200f108` | `FUN_4200f108` | 33 | 0 | 2 |  |
| `4200f1d4` | `FUN_4200f1d4` | 39 | 1 | 6 |  |
| `4200f358` | `FUN_4200f358` | 81 | 3 | 1 |  |
| `4200f4b8` | `FUN_4200f4b8` | 39 | 0 | 2 |  |
| `4200f514` | `FUN_4200f514` | 295 | 0 | 5 | &6@&Fi |
| `4200f6b0` | `uart1_write` | 18 | 2 | 1 |  |
| `4200f6c4` | `frame_forward` | 217 | 1 | 7 |  |
| `4200f7a8` | `FUN_4200f7a8` | 89 | 0 | 4 |  |
| `4200f804` | `FUN_4200f804` | 77 | 1 | 0 |  |
| `4200f854` | `FUN_4200f854` | 138 | 1 | 0 |  |
| `4200f8e0` | `FUN_4200f8e0` | 42 | 1 | 2 |  |
| `4200f90c` | `FUN_4200f90c` | 47 | 1 | 2 |  |
| `4200f9e4` | `FUN_4200f9e4` | 39 | 1 | 2 |  |
| `4200fa0c` | `FUN_4200fa0c` | 175 | 1 | 2 |  |
| `4200fac0` | `frame_ep0_dir` | 29 | 1 | 1 |  |
| `4200fae0` | `frame_a3_flag` | 29 | 1 | 0 |  |
| `4200fb00` | `FUN_4200fb00` | 25 | 1 | 0 |  |
| `4200fb1c` | `FUN_4200fb1c` | 36 | 1 | 0 |  |
| `4200fb40` | `FUN_4200fb40` | 15 | 1 | 1 |  |
| `4200fb50` | `FUN_4200fb50` | 119 | 1 | 0 |  |
| `4200fbc8` | `FUN_4200fbc8` | 54 | 1 | 1 |  |
| `4200fc00` | `FUN_4200fc00` | 109 | 1 | 6 |  |
| `4200fc74` | `FUN_4200fc74` | 86 | 1 | 4 |  |
| `4200fccc` | `reenumTask` | 85 | 2 | 4 |  |
| `4200fd24` | `FUN_4200fd24` | 95 | 2 | 2 |  |
| `4200fd84` | `FUN_4200fd84` | 191 | 1 | 3 |          (((((                   |
| `4200fe44` | `FUN_4200fe44` | 34 | 1 | 3 |  |
| `4200fe68` | `hid_uart_task` | 95 | 0 | 3 | Db7@8a7@ |
| `4200fec8` | `queue_drain` | 70 | 1 | 2 | Db7@8a7@ |
| `4200ff10` | `usb_event_handler` | 490 | 0 | 5 |  |
| `420100fc` | `bridge_init` | 148 | 1 | 4 |  |
| `42010244` | `bridge_release` | 98 | 1 | 1 |  |
| `420102a8` | `frame_build_ep0` | 185 | 4 | 9 | Db7@8a7@ |
| `42010364` | `FUN_42010364` | 23 | 2 | 0 |  |
| `4201037c` | `led_init` | 58 | 2 | 3 | gpio_config(&io_conf) |
| `420103b8` | `FUN_420103b8` | 43 | 1 | 3 |  |
| `420103e4` | `FUN_420103e4` | 125 | 1 | 4 |  |
| `42010d6c` | `FUN_42010d6c` | 112 | 1 | 2 |  |
| `42010de0` | `FUN_42010de0` | 112 | 1 | 2 |  |
| `42010e54` | `FUN_42010e54` | 112 | 1 | 2 |  |
| `42010ec8` | `FUN_42010ec8` | 112 | 1 | 2 |  |
| `42011150` | `FUN_42011150` | 235 | 1 | 2 |  |
| `42011244` | `FUN_42011244` | 124 | 1 | 3 |  |
| `4201156c` | `FUN_4201156c` | 154 | 2 | 0 |  |
| `42011888` | `FUN_42011888` | 169 | 1 | 4 | &39' |
| `4201193c` | `FUN_4201193c` | 112 | 1 | 2 |  |
| `420119b0` | `FUN_420119b0` | 112 | 1 | 2 |  |
| `42011ab0` | `FUN_42011ab0` | 56 | 1 | 0 |  |
| `42011ae8` | `FUN_42011ae8` | 113 | 1 | 1 |  |
| `42011b80` | `FUN_42011b80` | 13 | 1 | 0 |  |
| `42011b90` | `FUN_42011b90` | 56 | 1 | 6 |  |
| `420121f0` | `FUN_420121f0` | 74 | 2 | 1 |  |
| `4201223c` | `s_reserve_irom_region` | 125 | 1 | 2 | (mmu_ll_vaddr_to_laddr((uint32_t)&_instruction_r |
| `420122bc` | `s_reserve_drom_region` | 125 | 1 | 2 | (mmu_ll_vaddr_to_laddr((uint32_t)&_rodata_reserv |
| `42012c08` | `FUN_42012c08` | 52 | 1 | 0 |  |
| `42012c40` | `FUN_42012c40` | 54 | 2 | 0 |  |
| `42012c78` | `FUN_42012c78` | 35 | 2 | 1 |  |
| `42012c9c` | `FUN_42012c9c` | 169 | 1 | 8 |  |
| `42012d50` | `FUN_42012d50` | 36 | 1 | 1 |  |
| `42012d78` | `task_wdt_timeout_abort` | 83 | 2 | 5 | ret == pdTRUE \| @[7@ |
| `42012dcc` | `FUN_42012dcc` | 94 | 1 | 4 |  |
| `42012e30` | `FUN_42012e30` | 42 | 1 | 2 |  |
| `42012e5c` | `subscribe_idle` | 102 | 1 | 5 | idle_task_handle \| esp_task_wdt_add(idle_task_handle) \| /IDF |
| `42012ec4` | `FUN_42012ec4` | 138 | 1 | 5 |  |
| `42012f54` | `FUN_42012f54` | 82 | 1 | 5 |  |
| `42012fac` | `FUN_42012fac` | 10 | 0 | 1 |  |
| `42012fb8` | `FUN_42012fb8` | 133 | 2 | 2 | Task watchdog got triggered. The following tasks \|  (CPU 1) |
| `42013044` | `task_wdt_isr` | 110 | 0 | 6 | cpus_fail != 0 \| task_wdt.c \| task_wdt_isr |
| `4201319c` | `FUN_4201319c` | 39 | 1 | 0 |  |
| `420131c8` | `FUN_420131c8` | 31 | 1 | 0 |  |
| `420131e8` | `FUN_420131e8` | 47 | 2 | 0 |  |
| `4201321c` | `FUN_4201321c` | 43 | 1 | 0 | ESP_FAIL \| ERROR |
| `420136d0` | `FUN_420136d0` | 32 | 2 | 0 |  |
| `420137ac` | `FUN_420137ac` | 88 | 1 | 1 |  |
| `4201395c` | `periph_rtc_dig_clk8m_disable` | 79 | 1 | 4 | s_periph_ref_counts > 0 \| periph_rtc_dig_clk8m_disable |
| `420139c4` | `FUN_420139c4` | 114 | 1 | 2 |  |
| `420172e4` | `FUN_420172e4` | 18 | 0 | 2 |  |
| `420174ac` | `FUN_420174ac` | 111 | 1 | 1 | pk7@ |
| `420177c8` | `FUN_420177c8` | 25 | 0 | 2 |  |
| `42017a90` | `FUN_42017a90` | 44 | 0 | 1 |  |
| `42017abc` | `FUN_42017abc` | 50 | 3 | 2 |  |
| `42017bd0` | `FUN_42017bd0` | 50 | 0 | 1 |  |
| `42017c04` | `FUN_42017c04` | 7 | 0 | 0 |  |
| `42017c0c` | `FUN_42017c0c` | 57 | 0 | 2 |  |
| `42017c48` | `FUN_42017c48` | 58 | 0 | 1 |  |
| `42018008` | `FUN_42018008` | 22 | 0 | 2 |  |
| `42018020` | `FUN_42018020` | 195 | 1 | 1 |  |
| `420180f4` | `FUN_420180f4` | 21 | 1 | 2 |  |
| `4201810c` | `FUN_4201810c` | 24 | 1 | 2 |  |
| `4201813c` | `FUN_4201813c` | 74 | 1 | 2 |  |
| `42018188` | `FUN_42018188` | 25 | 1 | 2 |  |
| `420181a4` | `FUN_420181a4` | 25 | 1 | 2 |  |
| `420181c0` | `FUN_420181c0` | 292 | 0 | 0 |  |
| `4201b200` | `FUN_4201b200` | 292 | 0 | 0 |  |
| `4201b6d0` | `vSemaphoreDeleteWithCaps` | 263 | 4 | 6 | Hl7@ |
| `4201e300` | `FUN_4201e300` | 33 | 0 | 2 |  |
| `4201e324` | `FUN_4201e324` | 145 | 1 | 4 | pk7@ |
| `420205c8` | `FUN_420205c8` | 107 | 1 | 1 |  |
| `420206bc` | `FUN_420206bc` | 32 | 0 | 2 |  |
| `4202085c` | `FUN_4202085c` | 309 | 0 | 1 |  |
| `42021628` | `FUN_42021628` | 133 | 7 | 3 | REENT malloc succeeded |
| `420216b0` | `FUN_420216b0` | 64 | 3 | 2 | REENT malloc succeeded |
| `420216f0` | `FUN_420216f0` | 135 | 2 | 3 | Balloc succeeded |
| `42021778` | `FUN_42021778` | 146 | 0 | 3 | Balloc succeeded |
| `4202180c` | `FUN_4202180c` | 78 | 2 | 0 |  |
| `4202185c` | `FUN_4202185c` | 107 | 1 | 0 |  |
| `420218c8` | `FUN_420218c8` | 40 | 1 | 2 | Balloc succeeded |
| `420218f0` | `FUN_420218f0` | 376 | 1 | 2 | Balloc succeeded \| /builds/idf/crosstool-NG/.build/xtensa-es |
| `42021a6c` | `FUN_42021a6c` | 170 | 0 | 6 | REENT malloc succeeded |
| `42021b18` | `FUN_42021b18` | 261 | 0 | 3 | Balloc succeeded \| `V YB |
| `42021c20` | `FUN_42021c20` | 56 | 2 | 0 |  |
| `42021c5c` | `FUN_42021c5c` | 331 | 0 | 3 | Balloc succeeded \| /builds/idf/crosstool-NG/.build/xtensa-es |
| `42021da8` | `FUN_42021da8` | 76 | 0 | 0 |  |
| `42021df4` | `FUN_42021df4` | 139 | 1 | 1 |  |
| `42021e80` | `FUN_42021e80` | 181 | 0 | 4 | Balloc succeeded |
| `42021f38` | `FUN_42021f38` | 83 | 0 | 1 |  |
| `42021f8c` | `FUN_42021f8c` | 53 | 0 | 0 |  |
| `42021fc4` | `FUN_42021fc4` | 85 | 0 | 0 |  |
| `4202201c` | `FUN_4202201c` | 74 | 0 | 0 |  |
| `4202206c` | `FUN_4202206c` | 292 | 0 | 0 |  |
| `42024464` | `FUN_42024464` | 7 | 0 | 0 |  |
| `4202446c` | `FUN_4202446c` | 7 | 0 | 0 |  |
| `42024474` | `FUN_42024474` | 8 | 1 | 0 |  |
| `4202447c` | `FUN_4202447c` | 7 | 0 | 0 |  |
| `42024484` | `FUN_42024484` | 88 | 2 | 0 |  |
| `4202451c` | `FUN_4202451c` | 46 | 1 | 0 |  |
| `42024578` | `FUN_42024578` | 12 | 0 | 0 |  |
| `42024584` | `FUN_42024584` | 7 | 0 | 0 |  |
| `4202458c` | `FUN_4202458c` | 5 | 0 | 0 |  |
| `42024594` | `FUN_42024594` | 26 | 1 | 0 |  |
| `420245b0` | `FUN_420245b0` | 5 | 0 | 0 |  |
| `420245e4` | `FUN_420245e4` | 5 | 0 | 0 |  |
| `420245ec` | `FUN_420245ec` | 5 | 0 | 0 |  |
| `420245f4` | `FUN_420245f4` | 20 | 2 | 0 |  |
| `42024608` | `FUN_42024608` | 5 | 0 | 0 |  |
| `42024610` | `FUN_42024610` | 5 | 0 | 0 |  |
| `42024618` | `FUN_42024618` | 5 | 0 | 0 |  |
| `42024620` | `FUN_42024620` | 5 | 0 | 0 |  |
| `42024628` | `FUN_42024628` | 5 | 0 | 0 |  |
| `42024630` | `FUN_42024630` | 5 | 0 | 0 |  |
| `42024638` | `FUN_42024638` | 5 | 0 | 0 |  |
| `42024640` | `FUN_42024640` | 37 | 1 | 0 |  |
| `42024668` | `FUN_42024668` | 5 | 0 | 0 |  |
| `42024670` | `FUN_42024670` | 7 | 0 | 0 |  |
| `42024754` | `FUN_42024754` | 7 | 1 | 0 |  |
| `420247a4` | `FUN_420247a4` | 41 | 2 | 0 |  |
| `420247d8` | `FUN_420247d8` | 67 | 1 | 0 |  |
| `4202481c` | `FUN_4202481c` | 73 | 1 | 0 |  |
| `42024868` | `FUN_42024868` | 43 | 1 | 0 |  |
| `42024898` | `FUN_42024898` | 75 | 1 | 0 |  |
| `420248e4` | `FUN_420248e4` | 15 | 1 | 0 |  |
| `420248f4` | `FUN_420248f4` | 139 | 1 | 0 |  |
| `42024984` | `FUN_42024984` | 5 | 1 | 0 |  |
| `42024a10` | `FUN_42024a10` | 40 | 3 | 0 |  |
| `42024a3c` | `FUN_42024a3c` | 56 | 1 | 0 |  |
| `42024a74` | `FUN_42024a74` | 32 | 2 | 0 |  |
| `42024a94` | `FUN_42024a94` | 17 | 1 | 0 |  |
| `42024aa8` | `FUN_42024aa8` | 31 | 2 | 0 |  |
| `42024ac8` | `FUN_42024ac8` | 17 | 1 | 0 |  |
| `42024adc` | `FUN_42024adc` | 53 | 2 | 0 |  |
| `42024b14` | `FUN_42024b14` | 37 | 1 | 0 |  |
| `42024b3c` | `FUN_42024b3c` | 29 | 1 | 0 |  |
| `42024b5c` | `FUN_42024b5c` | 76 | 1 | 0 |  |
| `42025224` | `FUN_42025224` | 616 | 1 | 0 | '8SfB \| ! mF3 \| !HlF0 \| '8*,( |
| `420254a8` | `FUN_420254a8` | 547 | 1 | 0 |  |
| `420256e4` | `FUN_420256e4` | 91 | 1 | 0 |  |
| `42025750` | `FUN_42025750` | 91 | 1 | 0 |  |
| `420257b8` | `FUN_420257b8` | 62 | 1 | 4 |  |
| `42025824` | `FUN_42025824` | 120 | 0 | 5 | periph < PERIPH_MODULE_MAX \| periph_module_enable |
| `420258a0` | `FUN_420258a0` | 74 | 1 | 2 | calib_version == 1 |
| `420258ec` | `FUN_420258ec` | 111 | 1 | 1 | pvt_scheme_ver == 1 |
| `4202595c` | `FUN_4202595c` | 38 | 1 | 1 | pvt_scheme_ver == 1 |
| `42025984` | `FUN_42025984` | 191 | 1 | 1 | pvt_scheme_ver == 1 |
| `42025a48` | `FUN_42025a48` | 123 | 1 | 3 |  |
| `42025b98` | `FUN_42025b98` | 1442 | 1 | 6 |  |
| `42026140` | `FUN_42026140` | 42 | 1 | 0 |  |
| `4202616c` | `FUN_4202616c` | 18 | 0 | 0 |  |
| `42026180` | `FUN_42026180` | 122 | 0 | 7 | esp_task_wdt_init(&twdt_config) |
| `420262d4` | `FUN_420262d4` | 63 | 1 | 4 | xResult == ( ( BaseType_t ) 1 ) \| Db7@8a7@ |
| `42026388` | `FUN_42026388` | 55 | 1 | 4 | xResult == ( ( BaseType_t ) 1 ) \| Db7@8a7@ |
| `420263c0` | `FUN_420263c0` | 66 | 1 | 1 |  |
| `42026404` | `FUN_42026404` | 118 | 2 | 3 |  |
| `4202647c` | `FUN_4202647c` | 97 | 1 | 0 |  |
| `420265f4` | `FUN_420265f4` | 38 | 0 | 0 |  |
| `4202661c` | `FUN_4202661c` | 364 | 1 | 1 | tlsf.c \| control_construct \| ALIGN_SIZE == control->small_bl |
| `4202678c` | `FUN_4202678c` | 31 | 1 | 1 | used \| free |
| `420267b0` | `FUN_420267b0` | 88 | 1 | 2 | !block_is_last(block) |
| `42026878` | `FUN_42026878` | 404 | 1 | 3 | tlsf_add_pool: Memory size must be between %u an \| current & |
| `42026a0c` | `FUN_42026a0c` | 40 | 1 | 2 |  |
| `42026a68` | `FUN_42026a68` | 7 | 1 | 0 |  |

## right / idf/heap (290)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40375fec` | `FUN_40375fec` | 22 | 5 | 0 |  |
| `40376004` | `heap_caps_malloc` | 43 | 16 | 2 | heap_caps_malloc |
| `40376030` | `heap_caps_malloc_default` | 103 | 3 | 3 | heap_caps_malloc_default |
| `40376098` | `heap_caps_realloc` | 43 | 5 | 2 | heap_caps_realloc |
| `403760c4` | `heap_caps_realloc_default` | 114 | 1 | 3 | heap_caps_realloc_default |
| `40376138` | `heap_caps_calloc` | 46 | 3 | 2 | heap_caps_calloc |
| `40376224` | `FUN_40376224` | 32 | 1 | 2 |  |
| `40376244` | `heap_caps_free` | 79 | 14 | 2 | heap != NULL && 'free() target pointer is outsid \| heap_caps |
| `40376294` | `FUN_40376294` | 221 | 2 | 3 |  |
| `40376374` | `FUN_40376374` | 16 | 3 | 1 |  |
| `40376384` | `heap_caps_realloc_base` | 342 | 2 | 6 | heap != NULL && 'realloc() pointer is outside he \| heap_caps |
| `403764dc` | `FUN_403764dc` | 47 | 1 | 1 |  |
| `40376b94` | `FUN_40376b94` | 15 | 4 | 1 |  |
| `40376bc4` | `FUN_40376bc4` | 32 | 8 | 2 |  |
| `40376c48` | `FUN_40376c48` | 19 | 8 | 2 |  |
| `40377900` | `FUN_40377900` | 109 | 2 | 1 |  |
| `4037862c` | `FUN_4037862c` | 10 | 0 | 1 |  |
| `40378638` | `FUN_40378638` | 68 | 0 | 2 |  |
| `40379c4c` | `FUN_40379c4c` | 17 | 0 | 0 |  |
| `40379c60` | `FUN_40379c60` | 17 | 0 | 0 |  |
| `40379c74` | `FUN_40379c74` | 36 | 1 | 1 |  |
| `4037abfc` | `FUN_4037abfc` | 82 | 1 | 3 |  |
| `40380760` | `FUN_40380760` | 40 | 2 | 2 | CORRUPT HEAP: multi_heap.c:%d detected at 0x%08x |
| `40380788` | `FUN_40380788` | 93 | 1 | 5 |  |
| `403807e8` | `FUN_403807e8` | 21 | 1 | 1 |  |
| `40380800` | `FUN_40380800` | 70 | 1 | 6 |  |
| `40380848` | `FUN_40380848` | 12 | 1 | 1 |  |
| `40380854` | `FUN_40380854` | 36 | 5 | 2 |  |
| `40380878` | `FUN_40380878` | 30 | 5 | 2 |  |
| `40380898` | `FUN_40380898` | 80 | 3 | 5 |  |
| `403808e8` | `multi_heap_realloc_impl` | 107 | 1 | 7 | heap != NULL |
| `4038095c` | `FUN_4038095c` | 7 | 2 | 0 |  |
| `40380964` | `FUN_40380964` | 7 | 4 | 0 |  |
| `4038096c` | `FUN_4038096c` | 22 | 5 | 0 |  |
| `40380984` | `tlsf_free` | 987 | 2 | 1 | !block_is_free(block) && 'block already marked a \| !block_is |
| `40380d68` | `FUN_40380d68` | 12 | 2 | 1 |  |
| `40380d74` | `search_suitable_block` | 972 | 2 | 1 | 0 == (align & (align - 1)) && 'must align to a p \| sl_map && |
| `40381144` | `align_up` | 1608 | 1 | 1 | 0 == (align & (align - 1)) && 'must align to a p \| tlsf_cont |
| `40381794` | `tlsf_realloc` | 1327 | 1 | 3 | !block_is_last(block) \| tlsf_realloc \| !block_is_free(block) |
| `40381cd0` | `FUN_40381cd0` | 14 | 4 | 0 |  |
| `40381e8c` | `FUN_40381e8c` | 12 | 20 | 1 |  |
| `40381e98` | `FUN_40381e98` | 10 | 41 | 1 |  |
| `40381ea4` | `FUN_40381ea4` | 12 | 5 | 1 |  |
| `40381eb0` | `FUN_40381eb0` | 10 | 8 | 1 |  |
| `40381ebc` | `FUN_40381ebc` | 17 | 2 | 1 |  |
| `42001640` | `FUN_42001640` | 10 | 0 | 1 |  |
| `4200178c` | `FUN_4200178c` | 73 | 1 | 2 |  |
| `42002bb8` | `FUN_42002bb8` | 264 | 1 | 1 |  |
| `42002cc0` | `FUN_42002cc0` | 105 | 1 | 2 |  |
| `42002d2c` | `FUN_42002d2c` | 17 | 1 | 1 |  |
| `42002d40` | `FUN_42002d40` | 40 | 2 | 2 | heap_size <= HEAP_SIZE_MAX |
| `42002d68` | `FUN_42002d68` | 43 | 1 | 2 |  |
| `42002d94` | `heap_caps_init` | 578 | 1 | 7 | heap_idx <= num_heaps \| lock \| heap_idx == num_heaps \| SLIST |
| `42002fe0` | `FUN_42002fe0` | 10 | 0 | 1 |  |
| `42002fec` | `FUN_42002fec` | 19 | 2 | 0 |  |
| `42003090` | `FUN_42003090` | 18 | 1 | 1 |  |
| `420030a4` | `FUN_420030a4` | 273 | 1 | 2 |  |
| `42003aa0` | `FUN_42003aa0` | 15 | 1 | 0 |  |
| `42003ab0` | `FUN_42003ab0` | 18 | 1 | 0 |  |
| `42003b20` | `FUN_42003b20` | 91 | 1 | 6 |  |
| `42005de4` | `FUN_42005de4` | 56 | 0 | 1 |  |
| `42005e84` | `FUN_42005e84` | 91 | 1 | 3 |  |
| `42005ee0` | `FUN_42005ee0` | 13 | 0 | 1 | /dev/console |
| `420065a8` | `FUN_420065a8` | 134 | 0 | 6 |  |
| `4200668c` | `FUN_4200668c` | 427 | 0 | 10 |  |
| `420073ec` | `FUN_420073ec` | 8 | 1 | 0 |  |
| `420081ec` | `FUN_420081ec` | 207 | 1 | 5 | 8a7@ |
| `420093c8` | `FUN_420093c8` | 30 | 1 | 0 |  |
| `420093e8` | `FUN_420093e8` | 22 | 2 | 0 |  |
| `42009400` | `FUN_42009400` | 8 | 2 | 0 |  |
| `4200958c` | `FUN_4200958c` | 111 | 1 | 4 |  |
| `42009600` | `FUN_42009600` | 27 | 0 | 2 |  |
| `4200961c` | `FUN_4200961c` | 103 | 1 | 4 |  |
| `42009684` | `FUN_42009684` | 229 | 0 | 7 |  |
| `42009a7c` | `FUN_42009a7c` | 20 | 0 | 1 |  |
| `42009a90` | `FUN_42009a90` | 8 | 1 | 0 |  |
| `42009a98` | `FUN_42009a98` | 15 | 2 | 0 |  |
| `42009aa8` | `FUN_42009aa8` | 18 | 2 | 1 |  |
| `42009abc` | `FUN_42009abc` | 37 | 1 | 1 |  |
| `42009ae4` | `FUN_42009ae4` | 23 | 1 | 1 |  |
| `42009afc` | `FUN_42009afc` | 48 | 0 | 0 |  |
| `42009c70` | `FUN_42009c70` | 20 | 1 | 1 |  |
| `42009c84` | `FUN_42009c84` | 28 | 1 | 3 |  |
| `42009ca0` | `FUN_42009ca0` | 10 | 0 | 1 |  |
| `42009cac` | `FUN_42009cac` | 27 | 1 | 0 |  |
| `42009cc8` | `FUN_42009cc8` | 30 | 1 | 1 |  |
| `42009ce8` | `FUN_42009ce8` | 211 | 1 | 2 |  |
| `42009dbc` | `FUN_42009dbc` | 38 | 1 | 1 |  |
| `42009de4` | `FUN_42009de4` | 217 | 1 | 2 |  |
| `42009f0c` | `FUN_42009f0c` | 93 | 4 | 3 |  |
| `4200a690` | `FUN_4200a690` | 76 | 2 | 1 |  |
| `4200abd0` | `FUN_4200abd0` | 20 | 1 | 1 |  |
| `4200abe4` | `FUN_4200abe4` | 10 | 0 | 1 |  |
| `4200dab4` | `FUN_4200dab4` | 16 | 1 | 1 |  |
| `4200dac4` | `FUN_4200dac4` | 14 | 1 | 1 |  |
| `42011d84` | `FUN_42011d84` | 36 | 1 | 1 |  |
| `42013e14` | `FUN_42013e14` | 32 | 1 | 0 |  |
| `42013e34` | `FUN_42013e34` | 32 | 1 | 0 |  |
| `42013e54` | `FUN_42013e54` | 74 | 1 | 0 |  |
| `42013ea0` | `FUN_42013ea0` | 26 | 1 | 1 |  |
| `42013ebc` | `FUN_42013ebc` | 72 | 1 | 2 |  |
| `42013f04` | `FUN_42013f04` | 68 | 1 | 0 |  |
| `42013f4c` | `FUN_42013f4c` | 26 | 1 | 1 |  |
| `42013f68` | `FUN_42013f68` | 72 | 1 | 2 |  |
| `42013fb0` | `FUN_42013fb0` | 27 | 1 | 0 |  |
| `42013fcc` | `FUN_42013fcc` | 21 | 1 | 1 |  |
| `42013fe4` | `FUN_42013fe4` | 36 | 2 | 0 |  |
| `4201400c` | `FUN_4201400c` | 126 | 1 | 3 |  |
| `4201408c` | `FUN_4201408c` | 78 | 8 | 1 |  |
| `420140dc` | `FUN_420140dc` | 199 | 1 | 2 |  |
| `420141a8` | `FUN_420141a8` | 259 | 3 | 4 |  |
| `420142b4` | `FUN_420142b4` | 267 | 1 | 3 |  |
| `420143c0` | `FUN_420143c0` | 102 | 3 | 3 |  |
| `42014428` | `FUN_42014428` | 152 | 1 | 3 |  |
| `420144c4` | `FUN_420144c4` | 65 | 1 | 1 |  |
| `42014508` | `FUN_42014508` | 56 | 1 | 1 |  |
| `42014544` | `FUN_42014544` | 104 | 1 | 1 |  |
| `420145b0` | `FUN_420145b0` | 94 | 1 | 1 |  |
| `42014610` | `FUN_42014610` | 133 | 1 | 4 |  |
| `42014698` | `FUN_42014698` | 215 | 1 | 5 |  |
| `42014770` | `FUN_42014770` | 33 | 1 | 2 |  |
| `42014794` | `FUN_42014794` | 45 | 2 | 2 |  |
| `420147c4` | `FUN_420147c4` | 18 | 1 | 1 |  |
| `420147d8` | `FUN_420147d8` | 33 | 1 | 2 |  |
| `420147fc` | `FUN_420147fc` | 11 | 2 | 1 |  |
| `42014808` | `FUN_42014808` | 16 | 2 | 2 |  |
| `42014818` | `FUN_42014818` | 298 | 1 | 12 |  |
| `4201494c` | `FUN_4201494c` | 33 | 1 | 2 |  |
| `42014970` | `FUN_42014970` | 460 | 1 | 8 | @4 0D |
| `42014b48` | `FUN_42014b48` | 585 | 4 | 9 |  |
| `42014d9c` | `FUN_42014d9c` | 203 | 1 | 5 |  |
| `42014eb4` | `FUN_42014eb4` | 49 | 0 | 1 |  |
| `42014eec` | `FUN_42014eec` | 48 | 0 | 1 |  |
| `42014f20` | `FUN_42014f20` | 38 | 0 | 1 |  |
| `42014f48` | `FUN_42014f48` | 34 | 0 | 1 |  |
| `42014f6c` | `FUN_42014f6c` | 34 | 0 | 1 |  |
| `42014f90` | `FUN_42014f90` | 60 | 0 | 1 |  |
| `42014fd0` | `FUN_42014fd0` | 36 | 0 | 1 |  |
| `42014ff8` | `FUN_42014ff8` | 69 | 0 | 1 |  |
| `42015040` | `FUN_42015040` | 45 | 0 | 1 |  |
| `42015074` | `FUN_42015074` | 40 | 0 | 1 |  |
| `420150a0` | `FUN_420150a0` | 41 | 0 | 1 |  |
| `42015164` | `FUN_42015164` | 23 | 0 | 1 |  |
| `4201519c` | `FUN_4201519c` | 10 | 0 | 0 |  |
| `420151a8` | `FUN_420151a8` | 18 | 0 | 1 |  |
| `42015288` | `FUN_42015288` | 143 | 1 | 8 |  |
| `420153bc` | `FUN_420153bc` | 128 | 1 | 6 |  |
| `42015440` | `FUN_42015440` | 156 | 1 | 4 |  |
| `42015508` | `FUN_42015508` | 68 | 2 | 1 |  |
| `42015550` | `FUN_42015550` | 35 | 2 | 2 |  |
| `42015574` | `FUN_42015574` | 10 | 1 | 1 |  |
| `42015580` | `FUN_42015580` | 104 | 1 | 2 |  |
| `420155ec` | `FUN_420155ec` | 100 | 3 | 4 |  |
| `42015668` | `FUN_42015668` | 79 | 2 | 0 |  |
| `420156b8` | `FUN_420156b8` | 46 | 1 | 1 |  |
| `420156e8` | `FUN_420156e8` | 20 | 2 | 0 |  |
| `420156fc` | `FUN_420156fc` | 109 | 2 | 1 |  |
| `42015770` | `FUN_42015770` | 42 | 3 | 0 |  |
| `4201579c` | `FUN_4201579c` | 20 | 1 | 0 |  |
| `420157b4` | `FUN_420157b4` | 60 | 3 | 1 |  |
| `420157f0` | `FUN_420157f0` | 44 | 1 | 1 |  |
| `42015820` | `FUN_42015820` | 30 | 2 | 1 |  |
| `42015840` | `FUN_42015840` | 48 | 1 | 0 |  |
| `42015874` | `FUN_42015874` | 75 | 3 | 1 |  |
| `420158c0` | `FUN_420158c0` | 94 | 2 | 1 |  |
| `42015920` | `FUN_42015920` | 176 | 2 | 4 |  |
| `420159d4` | `FUN_420159d4` | 112 | 2 | 1 |  |
| `42015a48` | `FUN_42015a48` | 125 | 1 | 1 |  |
| `42015ac8` | `FUN_42015ac8` | 442 | 2 | 7 |  |
| `42015c90` | `FUN_42015c90` | 291 | 5 | 7 |  |
| `42015dbc` | `FUN_42015dbc` | 613 | 12 | 5 |  |
| `4201602c` | `FUN_4201602c` | 250 | 2 | 3 |  |
| `42016130` | `FUN_42016130` | 240 | 2 | 4 | Pe ` |
| `42016228` | `FUN_42016228` | 58 | 8 | 2 |  |
| `42016264` | `FUN_42016264` | 953 | 1 | 7 | `& 2 |
| `42016634` | `FUN_42016634` | 282 | 1 | 5 |  |
| `42016768` | `FUN_42016768` | 36 | 1 | 1 |  |
| `42016790` | `FUN_42016790` | 27 | 1 | 1 |  |
| `420167ac` | `FUN_420167ac` | 21 | 1 | 1 |  |
| `420167c4` | `FUN_420167c4` | 21 | 1 | 1 |  |
| `420167dc` | `FUN_420167dc` | 64 | 2 | 4 |  |
| `42016820` | `FUN_42016820` | 162 | 2 | 6 |  |
| `420168c8` | `FUN_420168c8` | 48 | 1 | 2 |  |
| `420168fc` | `FUN_420168fc` | 545 | 1 | 15 |  |
| `42016b6c` | `FUN_42016b6c` | 44 | 2 | 0 |  |
| `42016b98` | `FUN_42016b98` | 40 | 2 | 0 |  |
| `42016bc0` | `FUN_42016bc0` | 20 | 3 | 0 |  |
| `42016bd4` | `FUN_42016bd4` | 254 | 3 | 1 |  |
| `42016d58` | `FUN_42016d58` | 14 | 1 | 1 |  |
| `42016d68` | `FUN_42016d68` | 16 | 1 | 0 |  |
| `42016d78` | `FUN_42016d78` | 19 | 1 | 1 |  |
| `42016d9c` | `FUN_42016d9c` | 14 | 2 | 1 |  |
| `42016dac` | `FUN_42016dac` | 85 | 1 | 2 |  |
| `42016e04` | `FUN_42016e04` | 92 | 0 | 3 |  |
| `42016e64` | `FUN_42016e64` | 36 | 0 | 2 |  |
| `42016e88` | `FUN_42016e88` | 30 | 1 | 1 |  |
| `42016ea8` | `FUN_42016ea8` | 66 | 1 | 4 |  |
| `42016f0c` | `FUN_42016f0c` | 42 | 1 | 2 |  |
| `42016f38` | `FUN_42016f38` | 15 | 3 | 1 |  |
| `42016f48` | `FUN_42016f48` | 16 | 1 | 1 |  |
| `42016f58` | `FUN_42016f58` | 62 | 1 | 4 |  |
| `42016f98` | `FUN_42016f98` | 18 | 1 | 1 |  |
| `42016fac` | `FUN_42016fac` | 24 | 0 | 2 |  |
| `42016fc4` | `FUN_42016fc4` | 46 | 2 | 0 |  |
| `42016ff4` | `FUN_42016ff4` | 119 | 0 | 1 |  |
| `4201706c` | `FUN_4201706c` | 44 | 0 | 1 |  |
| `42017098` | `FUN_42017098` | 42 | 0 | 1 |  |
| `420170c4` | `FUN_420170c4` | 8 | 0 | 0 | std::bad_alloc |
| `420170cc` | `FUN_420170cc` | 18 | 1 | 1 |  |
| `420170e0` | `FUN_420170e0` | 24 | 0 | 2 |  |
| `420170f8` | `FUN_420170f8` | 18 | 2 | 1 |  |
| `4201710c` | `FUN_4201710c` | 24 | 0 | 2 |  |
| `42017124` | `FUN_42017124` | 46 | 3 | 0 |  |
| `42017154` | `FUN_42017154` | 30 | 1 | 1 |  |
| `42017174` | `FUN_42017174` | 53 | 0 | 1 |  |
| `420171ac` | `FUN_420171ac` | 40 | 0 | 1 |  |
| `420171d4` | `FUN_420171d4` | 14 | 3 | 1 |  |
| `420171f0` | `FUN_420171f0` | 12 | 2 | 1 |  |
| `42017204` | `FUN_42017204` | 12 | 1 | 1 |  |
| `42017210` | `FUN_42017210` | 12 | 1 | 1 |  |
| `4201721c` | `FUN_4201721c` | 196 | 3 | 8 | Hl7@ |
| `420172f8` | `FUN_420172f8` | 305 | 3 | 1 |  |
| `4201742c` | `FUN_4201742c` | 85 | 7 | 4 | Hl7@ |
| `42017484` | `FUN_42017484` | 38 | 0 | 3 |  |
| `4201751c` | `FUN_4201751c` | 20 | 0 | 1 |  |
| `42017530` | `FUN_42017530` | 54 | 0 | 1 |  |
| `42017568` | `FUN_42017568` | 28 | 0 | 1 |  |
| `42017584` | `FUN_42017584` | 28 | 0 | 1 | Hl7@ |
| `420175a0` | `FUN_420175a0` | 44 | 2 | 1 |  |
| `420175cc` | `FUN_420175cc` | 14 | 4 | 1 |  |
| `420175dc` | `FUN_420175dc` | 14 | 5 | 1 | Hl7@ |
| `420175ec` | `FUN_420175ec` | 164 | 1 | 5 | pk7@ |
| `42017694` | `FUN_42017694` | 36 | 8 | 3 |  |
| `420176d0` | `FUN_420176d0` | 19 | 0 | 2 |  |
| `420176e4` | `FUN_420176e4` | 183 | 1 | 9 | Hl7@ |
| `4201779c` | `FUN_4201779c` | 20 | 1 | 2 |  |
| `420177b0` | `FUN_420177b0` | 21 | 1 | 1 |  |
| `420177e4` | `FUN_420177e4` | 668 | 1 | 5 |  |
| `42017c98` | `FUN_42017c98` | 164 | 4 | 4 |  |
| `42017d3c` | `FUN_42017d3c` | 705 | 3 | 8 | Hl7@ |
| `4201e3b8` | `FUN_4201e3b8` | 292 | 1 | 0 |  |
| `4201e888` | `FUN_4201e888` | 34 | 1 | 1 |  |
| `4201e8ac` | `FUN_4201e8ac` | 7136 | 2 | 8 | Hl7@ \| @@`, \| 0123456789abcdef \| 0123456789ABCDEF \|          |
| `42020510` | `FUN_42020510` | 33 | 0 | 2 |  |
| `42020534` | `FUN_42020534` | 145 | 1 | 4 | pk7@ |
| `42020634` | `FUN_42020634` | 135 | 3 | 3 |  |
| `420206dc` | `FUN_420206dc` | 236 | 1 | 6 |  |
| `4202253c` | `FUN_4202253c` | 261 | 0 | 3 |  |
| `4202454c` | `FUN_4202454c` | 44 | 2 | 0 |  |
| `420245b8` | `FUN_420245b8` | 5 | 0 | 0 |  |
| `420245c0` | `FUN_420245c0` | 5 | 0 | 0 |  |
| `420245c8` | `FUN_420245c8` | 5 | 0 | 0 |  |
| `420245d0` | `FUN_420245d0` | 11 | 1 | 0 |  |
| `420245dc` | `FUN_420245dc` | 5 | 0 | 0 |  |
| `42024c30` | `FUN_42024c30` | 33 | 1 | 0 |  |
| `42024c54` | `FUN_42024c54` | 33 | 2 | 0 |  |
| `42024c78` | `FUN_42024c78` | 54 | 2 | 0 |  |
| `42024cb0` | `FUN_42024cb0` | 33 | 2 | 0 |  |
| `42024cd4` | `FUN_42024cd4` | 33 | 1 | 0 |  |
| `42024cf8` | `FUN_42024cf8` | 33 | 1 | 0 |  |
| `42024d1c` | `FUN_42024d1c` | 33 | 1 | 0 |  |
| `42024da8` | `FUN_42024da8` | 33 | 2 | 0 |  |
| `42024dcc` | `FUN_42024dcc` | 33 | 1 | 0 |  |
| `42024e14` | `FUN_42024e14` | 33 | 1 | 0 |  |
| `42024e38` | `FUN_42024e38` | 33 | 1 | 0 |  |
| `42024e64` | `FUN_42024e64` | 13 | 1 | 0 |  |
| `42024e74` | `FUN_42024e74` | 37 | 1 | 0 |  |
| `42024e9c` | `FUN_42024e9c` | 33 | 2 | 0 |  |
| `42024ec0` | `FUN_42024ec0` | 33 | 1 | 0 |  |
| `42024ee4` | `FUN_42024ee4` | 111 | 1 | 0 |  |
| `42024f58` | `FUN_42024f58` | 84 | 1 | 0 |  |
| `42024fb0` | `FUN_42024fb0` | 39 | 2 | 0 |  |
| `42024fd8` | `FUN_42024fd8` | 42 | 6 | 0 |  |
| `42025004` | `FUN_42025004` | 56 | 2 | 0 |  |
| `4202503c` | `FUN_4202503c` | 33 | 4 | 0 |  |
| `42025060` | `FUN_42025060` | 33 | 4 | 0 |  |
| `42025084` | `FUN_42025084` | 32 | 1 | 0 |  |
| `420250f0` | `FUN_420250f0` | 5 | 1 | 0 |  |
| `420250f8` | `FUN_420250f8` | 7 | 0 | 0 |  |
| `42025100` | `FUN_42025100` | 47 | 0 | 0 |  |
| `42025130` | `FUN_42025130` | 12 | 0 | 0 |  |
| `4202513c` | `FUN_4202513c` | 5 | 1 | 0 |  |
| `42025144` | `FUN_42025144` | 53 | 4 | 0 |  |
| `4202517c` | `FUN_4202517c` | 123 | 1 | 0 |  |
| `42026278` | `FUN_42026278` | 91 | 1 | 3 | Db7@8a7@ |
| `42026314` | `FUN_42026314` | 112 | 1 | 5 | Db7@8a7@ |
| `4202653c` | `FUN_4202653c` | 78 | 1 | 3 | start_ptr |
| `4202658c` | `FUN_4202658c` | 104 | 1 | 7 |  |
| `42026808` | `FUN_42026808` | 109 | 1 | 0 |  |
| `42026a3c` | `FUN_42026a3c` | 43 | 1 | 3 |  |

## right / idf/newlib (1)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `42006208` | `pthread_cleanup_thread_specific_data_callback` | 69 | 0 | 3 | tls != NULL \| pthread_cleanup_thread_specific_data_callback |

## right / idf/spi (84)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `4037660c` | `FUN_4037660c` | 99 | 2 | 6 |  |
| `40376844` | `FUN_40376844` | 31 | 1 | 0 |  |
| `40377760` | `FUN_40377760` | 15 | 1 | 1 |  |
| `40377770` | `FUN_40377770` | 235 | 1 | 5 |  |
| `4037785c` | `FUN_4037785c` | 21 | 1 | 3 |  |
| `40377874` | `FUN_40377874` | 26 | 1 | 3 |  |
| `40377890` | `FUN_40377890` | 106 | 1 | 0 |  |
| `40377970` | `FUN_40377970` | 15 | 2 | 1 |  |
| `40377980` | `spi_flash_disable_interrupts_caches_and_other_cpu` | 207 | 4 | 8 | esp_task_stack_is_sane_cache_disabled() \| s_flash_op_cpu ==  |
| `40377a50` | `FUN_40377a50` | 38 | 0 | 2 |  |
| `40377a78` | `FUN_40377a78` | 15 | 3 | 1 |  |
| `40377ad0` | `spi_flash_enable_interrupts_caches_and_other_cpu` | 129 | 4 | 6 | cpuid == s_flash_op_cpu \| !(xTaskGetSchedulerState() == task |
| `40377b54` | `FUN_40377b54` | 25 | 0 | 2 |  |
| `40377b94` | `FUN_40377b94` | 72 | 1 | 2 |  |
| `40377be0` | `FUN_40377be0` | 88 | 1 | 2 |  |
| `40377c38` | `FUN_40377c38` | 10 | 2 | 0 |  |
| `403785f8` | `spi_flash_os_check_yield` | 48 | 0 | 2 | chip_status == 0 |
| `403786d0` | `FUN_403786d0` | 8 | 1 | 1 |  |
| `403786ec` | `FUN_403786ec` | 8 | 1 | 1 |  |
| `403786f4` | `FUN_403786f4` | 12 | 0 | 1 |  |
| `40378700` | `FUN_40378700` | 16 | 0 | 0 |  |
| `40378738` | `FUN_40378738` | 12 | 1 | 0 |  |
| `4037ec6c` | `FUN_4037ec6c` | 110 | 1 | 0 |  |
| `4037ecdc` | `FUN_4037ecdc` | 38 | 2 | 1 |  |
| `4037eea0` | `mmu_hal_paddr_to_vaddr` | 86 | 1 | 3 | mmu_ll_check_valid_paddr_region(mmu_id, paddr, 1 \| p3 9 |
| `4037eef8` | `FUN_4037eef8` | 86 | 4 | 0 |  |
| `4037ef50` | `mmu_hal_map_region` | 186 | 1 | 3 | vaddr % page_size_in_bytes == 0 \| paddr % page_size_in_bytes |
| `4037f00c` | `mmu_hal_unmap_region` | 99 | 1 | 3 | vaddr % page_size_in_bytes == 0 \| mmu_hal_check_valid_ext_va |
| `4037f0c8` | `FUN_4037f0c8` | 8 | 4 | 0 |  |
| `4037f0d0` | `spi_flash_encrypt_ll_plaintext_save` | 46 | 1 | 1 | plaintext_offs + size <= SOC_FLASH_ENCRYPTED_XTS |
| `4037f100` | `FUN_4037f100` | 33 | 1 | 0 |  |
| `4037f124` | `FUN_4037f124` | 23 | 1 | 0 |  |
| `4037f13c` | `FUN_4037f13c` | 44 | 1 | 1 |  |
| `4037f168` | `FUN_4037f168` | 37 | 1 | 0 |  |
| `4037f190` | `FUN_4037f190` | 15 | 1 | 0 |  |
| `4037f1a0` | `FUN_4037f1a0` | 14 | 1 | 0 |  |
| `40381f6c` | `FUN_40381f6c` | 24 | 1 | 0 |  |
| `40382020` | `FUN_40382020` | 55 | 0 | 0 |  |
| `40382058` | `FUN_40382058` | 35 | 0 | 0 |  |
| `4038207c` | `FUN_4038207c` | 45 | 0 | 0 |  |
| `403820ac` | `FUN_403820ac` | 25 | 0 | 1 |  |
| `403823b4` | `FUN_403823b4` | 64 | 0 | 0 |  |
| `403823f8` | `FUN_403823f8` | 85 | 0 | 0 |  |
| `40382450` | `FUN_40382450` | 334 | 0 | 0 | &H*&X |
| `403825ac` | `FUN_403825ac` | 201 | 0 | 6 |  |
| `4038267c` | `FUN_4038267c` | 109 | 0 | 0 |  |
| `403826ec` | `FUN_403826ec` | 50 | 3 | 0 |  |
| `40382720` | `FUN_40382720` | 46 | 3 | 0 |  |
| `40382750` | `FUN_40382750` | 56 | 0 | 1 |  |
| `40382788` | `FUN_40382788` | 21 | 0 | 1 |  |
| `403827a0` | `FUN_403827a0` | 54 | 0 | 0 |  |
| `40382910` | `spi_flash_chip_generic_get_write_protect` | 56 | 0 | 1 | out_write_protect!=NULL |
| `4038305c` | `FUN_4038305c` | 137 | 0 | 0 |  |
| `403830e8` | `FUN_403830e8` | 137 | 0 | 0 |  |
| `40383174` | `FUN_40383174` | 136 | 0 | 0 |  |
| `403831fc` | `FUN_403831fc` | 50 | 0 | 0 |  |
| `40383230` | `spi_flash_chip_mxic_opi_get_data_length_zoom` | 39 | 3 | 1 | (io_mode == SPI_FLASH_OPI_STR) \|\| (io_mode == SP |
| `4038325c` | `FUN_4038325c` | 167 | 0 | 1 |  |
| `40383308` | `FUN_40383308` | 75 | 0 | 1 |  |
| `40383354` | `FUN_40383354` | 115 | 0 | 1 |  |
| `403833c8` | `spi_flash_chip_mxic_opi_get_write_protect` | 56 | 0 | 1 | out_write_protected!=NULL |
| `403834a0` | `FUN_403834a0` | 35 | 0 | 0 |  |
| `403834c8` | `FUN_403834c8` | 7 | 0 | 0 |  |
| `403834d0` | `FUN_403834d0` | 7 | 0 | 0 |  |
| `403834d8` | `FUN_403834d8` | 40 | 0 | 0 |  |
| `40383504` | `FUN_40383504` | 7 | 0 | 0 |  |
| `4038350c` | `FUN_4038350c` | 74 | 1 | 0 |  |
| `40383558` | `FUN_40383558` | 56 | 0 | 1 |  |
| `40383590` | `FUN_40383590` | 69 | 1 | 0 |  |
| `40383d10` | `FUN_40383d10` | 24 | 2 | 0 |  |
| `42001658` | `FUN_42001658` | 39 | 0 | 4 | flash_ret == ESP_OK |
| `42001680` | `FUN_42001680` | 10 | 0 | 1 |  |
| `4200ae8c` | `FUN_4200ae8c` | 71 | 1 | 2 | 8\|7@( |
| `420120ac` | `FUN_420120ac` | 10 | 1 | 1 |  |
| `420126d8` | `FUN_420126d8` | 180 | 1 | 2 | \x7@ |
| `42012794` | `FUN_42012794` | 86 | 1 | 2 | tx7@ |
| `420127f0` | `spi_flash_init_lock` | 38 | 1 | 2 | s_flash_op_mutex != NULL |
| `42012818` | `FUN_42012818` | 18 | 1 | 1 |  |
| `4201282c` | `FUN_4201282c` | 16 | 1 | 1 |  |
| `420128d0` | `spi_flash_munmap` | 67 | 2 | 3 | 0 && 'invalid handle, or handle already unmapped \| spi_flash |
| `42012914` | `FUN_42012914` | 36 | 1 | 1 |  |
| `42012a24` | `FUN_42012a24` | 40 | 1 | 2 |  |
| `42012b50` | `FUN_42012b50` | 27 | 1 | 3 | 8\|7@( |
| `42012b6c` | `FUN_42012b6c` | 37 | 2 | 0 |  |

## right / idf/uart (55)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40376b0c` | `FUN_40376b0c` | 14 | 7 | 1 |  |
| `40376b4c` | `FUN_40376b4c` | 15 | 7 | 1 |  |
| `40376cf8` | `FUN_40376cf8` | 27 | 6 | 1 |  |
| `40376d14` | `FUN_40376d14` | 22 | 4 | 1 |  |
| `403785c8` | `FUN_403785c8` | 47 | 1 | 1 |  |
| `403786d8` | `FUN_403786d8` | 20 | 0 | 2 |  |
| `4037c37c` | `FUN_4037c37c` | 129 | 0 | 2 |  |
| `40380530` | `FUN_40380530` | 77 | 3 | 0 |  |
| `42006490` | `FUN_42006490` | 23 | 0 | 0 |  |
| `420064a8` | `FUN_420064a8` | 55 | 0 | 0 |  |
| `420064e0` | `FUN_420064e0` | 53 | 0 | 0 |  |
| `42006518` | `FUN_42006518` | 34 | 1 | 0 |  |
| `42006970` | `FUN_42006970` | 45 | 0 | 2 |  |
| `42007090` | `FUN_42007090` | 91 | 0 | 1 |  |
| `420070ec` | `FUN_420070ec` | 64 | 0 | 1 | d < 3 |
| `42007134` | `uart_fcntl` | 89 | 0 | 2 | fd >= 0 && fd < 3 |
| `420071c8` | `uart_close` | 30 | 0 | 1 | fd >= 0 && fd < 3 |
| `420071e8` | `uart_return_char` | 38 | 1 | 1 | s_ctx[fd]->peek_char == NONE |
| `42007210` | `uart_fsync` | 65 | 0 | 3 | fd >= 0 && fd < 3 \| Lk7@ |
| `42007254` | `uart_read` | 264 | 0 | 6 | fd >= 0 && fd < 3 \| uart_read \| c != NONE \| Lk7@ |
| `42007360` | `uart_write` | 137 | 0 | 3 | fd >= 0 && fd < 3 \| uart_write \| Lk7@ |
| `420076a4` | `FUN_420076a4` | 113 | 1 | 2 |  |
| `42008848` | `FUN_42008848` | 779 | 1 | 5 |  |
| `42008df4` | `uart_wait_tx_done` | 385 | 2 | 6 | !(is_rs485_mode && disabled && uart_hal_get_intr \| uart.c \|  |
| `42009494` | `FUN_42009494` | 111 | 1 | 1 |  |
| `42009504` | `FUN_42009504` | 132 | 1 | 1 |  |
| `42009808` | `FUN_42009808` | 17 | 0 | 1 |  |
| `4200981c` | `FUN_4200981c` | 56 | 0 | 1 |  |
| `42009858` | `FUN_42009858` | 99 | 0 | 1 |  |
| `420098c0` | `FUN_420098c0` | 25 | 0 | 0 |  |
| `420098dc` | `FUN_420098dc` | 47 | 2 | 4 | Lk7@ |
| `4200990c` | `FUN_4200990c` | 12 | 0 | 1 |  |
| `42009918` | `FUN_42009918` | 97 | 0 | 2 |  |
| `4200997c` | `FUN_4200997c` | 82 | 0 | 3 | Lk7@ |
| `420099f4` | `FUN_420099f4` | 126 | 0 | 5 | Lk7@ |
| `4200a90c` | `FUN_4200a90c` | 37 | 1 | 0 |  |
| `4200a934` | `FUN_4200a934` | 27 | 0 | 1 |  |
| `4200a950` | `FUN_4200a950` | 41 | 0 | 1 |  |
| `4200a97c` | `FUN_4200a97c` | 35 | 0 | 1 |  |
| `4200a9a0` | `FUN_4200a9a0` | 27 | 0 | 1 |  |
| `4200a9bc` | `FUN_4200a9bc` | 158 | 0 | 2 |  |
| `4200aa60` | `FUN_4200aa60` | 43 | 0 | 1 |  |
| `4200aa8c` | `FUN_4200aa8c` | 39 | 0 | 1 |  |
| `4200aab4` | `FUN_4200aab4` | 39 | 0 | 1 |  |
| `4200aadc` | `FUN_4200aadc` | 65 | 0 | 1 |  |
| `4200ab20` | `FUN_4200ab20` | 43 | 0 | 1 |  |
| `4200ab4c` | `FUN_4200ab4c` | 69 | 0 | 1 |  |
| `4200ab94` | `FUN_4200ab94` | 59 | 0 | 1 |  |
| `4200f644` | `uart_event_task` | 107 | 1 | 5 |  |
| `42010b14` | `FUN_42010b14` | 118 | 1 | 0 |  |
| `420117c0` | `FUN_420117c0` | 58 | 1 | 0 |  |
| `420117fc` | `FUN_420117fc` | 26 | 1 | 1 |  |
| `42011a24` | `FUN_42011a24` | 139 | 1 | 0 |  |
| `420139ac` | `FUN_420139ac` | 24 | 2 | 1 |  |
| `420180e4` | `FUN_420180e4` | 13 | 27 | 1 |  |

## right / idf/usb (67)

| entry | name | size | callers | callees | strings |
|---|---|---:|---:|---:|---|
| `40379bdc` | `FUN_40379bdc` | 110 | 0 | 2 |  |
| `4037c1fc` | `FUN_4037c1fc` | 329 | 1 | 13 | esp_intr_alloc(ETS_SYSTIMER_TARGET0_INTR_SOURCE  \| vSystimer |
| `4038049c` | `FUN_4038049c` | 15 | 0 | 0 |  |
| `403804ac` | `FUN_403804ac` | 32 | 0 | 0 |  |
| `403804cc` | `FUN_403804cc` | 34 | 0 | 0 |  |
| `403804f0` | `FUN_403804f0` | 34 | 0 | 0 |  |
| `40380514` | `FUN_40380514` | 26 | 2 | 0 |  |
| `40380580` | `systimer_ll_set_alarm_period` | 130 | 1 | 1 | period < (1 << 26) |
| `40380604` | `FUN_40380604` | 84 | 1 | 1 |  |
| `40380658` | `FUN_40380658` | 62 | 2 | 0 |  |
| `40380698` | `FUN_40380698` | 13 | 2 | 0 |  |
| `403806a8` | `FUN_403806a8` | 30 | 1 | 0 |  |
| `403806c8` | `FUN_403806c8` | 34 | 2 | 0 |  |
| `403806ec` | `FUN_403806ec` | 33 | 2 | 0 |  |
| `40380710` | `FUN_40380710` | 78 | 2 | 0 |  |
| `420015d4` | `FUN_420015d4` | 50 | 1 | 0 |  |
| `42001c30` | `FUN_42001c30` | 17 | 1 | 0 | 4Z7@0 |
| `42001c44` | `FUN_42001c44` | 180 | 1 | 2 |  |
| `42003938` | `FUN_42003938` | 24 | 6 | 1 |  |
| `4200637c` | `FUN_4200637c` | 15 | 0 | 2 |  |
| `42006398` | `FUN_42006398` | 62 | 1 | 3 |  |
| `420063d8` | `FUN_420063d8` | 179 | 1 | 8 |  |
| `42009430` | `FUN_42009430` | 16 | 0 | 0 |  |
| `42009440` | `FUN_42009440` | 49 | 1 | 0 |  |
| `42009474` | `FUN_42009474` | 32 | 1 | 1 |  |
| `420099d0` | `usb_serial_jtag_return_char` | 36 | 1 | 1 | s_ctx.peek_char == NONE |
| `4200c040` | `FUN_4200c040` | 106 | 1 | 0 |  |
| `4200c0ac` | `FUN_4200c0ac` | 32 | 1 | 1 |  |
| `4200c0cc` | `FUN_4200c0cc` | 98 | 1 | 0 |  |
| `4200c130` | `FUN_4200c130` | 102 | 1 | 0 |  |
| `4200c198` | `FUN_4200c198` | 107 | 2 | 0 |  |
| `4200c85c` | `FUN_4200c85c` | 72 | 1 | 1 |  |
| `4200c8a4` | `FUN_4200c8a4` | 122 | 1 | 1 |  |
| `4200cf34` | `FUN_4200cf34` | 456 | 1 | 9 |  |
| `4200d6c8` | `FUN_4200d6c8` | 111 | 1 | 2 |  |
| `4200d77c` | `FUN_4200d77c` | 17 | 1 | 1 |  |
| `4200da94` | `FUN_4200da94` | 32 | 6 | 1 |  |
| `42010468` | `FUN_42010468` | 109 | 2 | 1 |  |
| `420104dc` | `FUN_420104dc` | 107 | 2 | 0 |  |
| `4201054c` | `FUN_4201054c` | 111 | 1 | 2 |  |
| `420105c0` | `FUN_420105c0` | 140 | 1 | 2 |  |
| `42010650` | `usb_phy_otg_set_mode` | 340 | 1 | 1 | otg_sig |
| `420107a8` | `FUN_420107a8` | 232 | 1 | 0 |  |
| `42010898` | `FUN_42010898` | 76 | 1 | 0 |  |
| `420108e8` | `usb_new_phy` | 474 | 1 | 17 | usb_dwc_info.controllers[otg11_index].internal_p \| usb_new_p |
| `42010ad4` | `FUN_42010ad4` | 62 | 1 | 0 |  |
| `42010b8c` | `FUN_42010b8c` | 92 | 1 | 0 |  |
| `42010f38` | `FUN_42010f38` | 117 | 2 | 3 |  |
| `42010fb4` | `FUN_42010fb4` | 157 | 1 | 3 |  |
| `42011058` | `FUN_42011058` | 117 | 1 | 3 |  |
| `420110d4` | `FUN_420110d4` | 117 | 1 | 3 |  |
| `420112c4` | `FUN_420112c4` | 81 | 1 | 1 |  |
| `4201131c` | `FUN_4201131c` | 92 | 3 | 0 |  |
| `42011378` | `FUN_42011378` | 145 | 1 | 0 |  |
| `42011410` | `FUN_42011410` | 147 | 1 | 0 |  |
| `420114a8` | `FUN_420114a8` | 96 | 1 | 0 |  |
| `42011508` | `FUN_42011508` | 96 | 1 | 0 |  |
| `4201160c` | `FUN_4201160c` | 304 | 1 | 15 |  |
| `42011748` | `FUN_42011748` | 116 | 1 | 4 |  |
| `42011b5c` | `FUN_42011b5c` | 33 | 7 | 0 |  |
| `420130b8` | `FUN_420130b8` | 220 | 1 | 3 |  |
| `42013808` | `FUN_42013808` | 58 | 1 | 0 |  |
| `42013844` | `FUN_42013844` | 143 | 1 | 0 |  |
| `420247d0` | `FUN_420247d0` | 7 | 1 | 0 |  |
| `420257f8` | `FUN_420257f8` | 19 | 5 | 1 |  |
| `4202580c` | `FUN_4202580c` | 24 | 5 | 1 |  |
| `420264e0` | `FUN_420264e0` | 90 | 1 | 0 |  |

