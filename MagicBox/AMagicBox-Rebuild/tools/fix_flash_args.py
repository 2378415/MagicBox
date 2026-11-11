p="tools/run_bench_cycle.ps1"
t=open(p,encoding="utf-8").read()
t=t.replace("""        $flashArgs = Get-Content 'build\\flash_args'
        & $py -m esptool --chip esp32s3 --port $port --baud 921600 --before no_reset `
            --after hard_reset write_flash @flashArgs""","""        & $py -m esptool --chip esp32s3 --port $port --baud 921600 --before no_reset `
            --after hard_reset write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB `
            0x0 build\\bootloader\\bootloader.bin `
            0x8000 build\\partition_table\\partition-table.bin `
            0x10000 build\\makcu_left.bin""")
open(p,"w",encoding="utf-8").write(t)
print("flash args fixed")
