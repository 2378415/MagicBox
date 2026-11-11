import os, io, sys, struct
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")

# ---------- partitions ----------
left = [("nvs","data","nvs",0x009000,0x006000),
        ("phy_init","data","phy",0x00f000,0x001000),
        ("factory","app","factory",0x010000,0x100000),
        ("coredump","data","coredump",0x110000,0x010000),
        ("storage","data","nvs",0x120000,0x020000)]
with open("partitions_left.csv","w",encoding="utf-8") as fh:
    fh.write("# name,type,subtype,offset,size,flags   -- measured from work/hw_left_readback.bin @0x8000\n")
    fh.write("# name,   type,  subtype,  offset,   size,   flags\n")
    fh.write("# (ESP-IDF partitions_left.csv format below)\n")
    fh.write("# Name,Type,SubType,Offset,Size,Flags\n")
    for n,t,s,o,sz in left:
        fh.write(f"{n},{t},{s},0x{o:06x},0x{sz:06x},\n")
print("partitions_left.csv written")

# ---------- sdkconfig.defaults ----------
common = """# sdkconfig defaults for the MAKCU rebuild.
# Values marked [measured] come from the image / hardware, [derived] from code
# inspection, [guess] must be confirmed by the P0 recompilation baseline.
CONFIG_IDF_TARGET="esp32s3"
CONFIG_IDF_FIRMWARE_CHIP_ID=0x0009

# [measured] app descriptor says idf v5.4.1, project-name, no OTA partitions
CONFIG_APP_PROJECT_VER_FROM_CONFIG=y
CONFIG_PARTITION_TABLE_CUSTOM=y
CONFIG_PARTITION_TABLE_CUSTOM_FILENAME="partitions_left.csv"

# [derived] single-app, 1 MB factory partition, coredump + second NVS
CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH=y
CONFIG_ESP_COREDUMP_DATA_FORMAT_ELF=y

# [guess] FreeRTOS tick: 100 Hz matches the observed vTaskDelay(1) granularity
# and the 1 ms commit delay in pulse_move; confirm in P0.
CONFIG_FREERTOS_HZ=100

# [derived] the firmware ships no secure boot / flash encryption (eFuse read)
CONFIG_SECURE_BOOT=n
CONFIG_SECURE_FLASH_ENC_ENABLED=n

# [derived] UART console is disabled at boot (eFuse UART_PRINT_CONTROL=0b11);
# keep the driver but no boot banner, otherwise timing changes.
CONFIG_LOG_DEFAULT_LEVEL_WARN=y
CONFIG_BOOTLOADER_LOG_LEVEL_WARN=y
"""
with open("sdkconfig.defaults.left","w",encoding="utf-8") as fh:
    fh.write(common)
    fh.write("""
# LEFT = device side: USB HID device (TinyUSB device stack), UART0 control port,
# UART1 inter-chip link.
CONFIG_TINYUSB_CDC_ENABLED=n
CONFIG_ESP_CONSOLE_UART_DEFAULT=y
""")
with open("sdkconfig.defaults.right","w",encoding="utf-8") as fh:
    fh.write(common)
    fh.write("""
# RIGHT = host side: USB host + HID parsing, UART1 inter-chip link.
CONFIG_USB_HOST_ENABLED=y
CONFIG_ESP_CONSOLE_UART_DEFAULT=y
""")
print("sdkconfig.defaults.{left,right} written")
