# Flash the right chip (ESP32-S3, VID 303A:1001 / USB-Serial-JTAG).
#
# Wiring: the right-side port takes EITHER the mouse (normal use) OR the data
# cable (flashing).  The middle CH343 (COM3) can stay plugged all the time.
#
#   powershell -File tools\flash_right.ps1                     # flash factory image
#   powershell -File tools\flash_right.ps1 -Image work\V3.7_RIGHT_patchedB.bin
#   powershell -File tools\flash_right.ps1 -Backup             # 4 MB readback first
#
# Factory images live in ..\官方固件\ ; the full pre-patch dump is
# work\hw_right_full_before_patch.bin (sha256 F4B3C2EC…).
param(
    [string]$Image  = 'D:\JinPeng\MagicBox\官方固件\V3.7_RIGHT.bin',
    [string]$Port   = '',
    [string]$Baud   = '921600',
    # 0x0 for a full image (bootloader + partition table + app, like the factory
    # V3.7_RIGHT.bin); 0x10000 for an app-only image such as
    # app_right/build/makcu_right.bin.
    [string]$Offset = '0x0',
    [switch]$Backup,
    [string]$BackupPath = 'D:\JinPeng\MagicBox\work\hw_right_readback.bin'
)

$esptool = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\esptool.exe'
if (-not (Test-Path $esptool)) { throw "esptool not found: $esptool" }
if (-not (Test-Path $Image))   { throw "image not found: $Image" }

if (-not $Port) {
    for ($i = 0; $i -lt 10 -and -not $Port; $i++) {
        $Port = (Get-CimInstance Win32_SerialPort -ErrorAction SilentlyContinue |
                 Where-Object { $_.PNPDeviceID -match 'VID_303A&PID_1001' } |
                 Select-Object -First 1).DeviceID
        if (-not $Port) { Start-Sleep -Milliseconds 800 }
    }
}
if (-not $Port) {
    throw "right chip not found (VID_303A&PID_1001). Swap the mouse for the data cable on the right-side port."
}
Write-Host "right chip on $Port"

if ($Backup) {
    Write-Host "reading back 4 MB to $BackupPath ..."
    & $esptool --chip esp32s3 --port $Port read_flash 0x0 0x400000 $BackupPath
    if ($LASTEXITCODE -ne 0) { throw "readback failed" }
    Write-Host ("readback sha256 = " + (Get-FileHash $BackupPath -Algorithm SHA256).Hash)
}

Write-Host "flashing $Image at $Offset ..."
$out = & $esptool --chip esp32s3 --port $Port --baud $Baud write_flash $Offset $Image 2>&1
$out | Select-String -Pattern 'Wrote|Hash of data verified|error|FAIL' | ForEach-Object { $_.Line }

if (-not ($out -match 'Hash of data verified')) { throw "flash did not verify" }

# quick readback of the first 64 KB and compare with the image
$head = 'D:\JinPeng\MagicBox\work\right_verify_head.bin'
$offNum = [Convert]::ToInt64($Offset, 16)
& $esptool --chip esp32s3 --port $Port read_flash $Offset 0x10000 $head | Out-Null
$a = [System.IO.File]::ReadAllBytes($head)
$b = [System.IO.File]::ReadAllBytes($Image)
$n = [Math]::Min($a.Length, $b.Length)
$diff = 0
for ($i = 0; $i -lt $n; $i++) { if ($a[$i] -ne $b[$i]) { $diff++ } }
Write-Host "readback (first 64 KB) differs in $diff bytes"
if ($diff -ne 0) { throw "readback mismatch" }

# 2026-11-10: on this board the USB-Serial-JTAG "hard reset" is a no-op - after
# write + readback the chip stays in the ROM downloader (verified: `esptool
# --before no_reset chip_id` still syncs, and the right chip answers nothing on
# UART1).  The only reliable reset is a power cycle, which the cable swap gives
# you for free: unplug the data cable and plug the mouse back into the right-side
# port.  Then check from the left chip: `mx.ls` rx_bytes must grow and `mx.hi`
# must answer.
Write-Host "OK - image verified."
Write-Host "NOTE: the chip is still in the ROM downloader; a hard reset over USB-Serial-JTAG does not work here."
Write-Host "      Unplug the data cable, plug the MOUSE back into the right-side port (that power-cycles the board),"
Write-Host "      then on COM3:  mx.ls  (rx_bytes must grow)  /  mx.hi  (must answer)"
