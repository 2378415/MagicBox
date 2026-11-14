# flash_left_auto.ps1 - one-command flash of the LEFT chip (bench-mode self recovery)
#
#   powershell -File tools\flash_left_auto.ps1             # build + flash + verify
#   powershell -File tools\flash_left_auto.ps1 -NoBuild    # flash existing build output
#
# Requires the bench build (MB_DEBUG_OPCODE=ON) so that `mx.dl` on the control port
# can put the chip into the ROM downloader.  Once there it enumerates as
# VID_303A&PID_0009 on the native USB cable, so flashing does not depend on the
# CH343 DTR/RTS lines (this board does not wire them to EN/IO0).
#
# Steps: mx.dl -> wait for the downloader port -> write 0x10000 -> full readback
# compare -> remind to power-cycle.
param(
    [switch]$NoBuild,
    [string]$UartPort = 'COM3',
    [string]$Define = '-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=99,-DMB_DUAL_IF=ON'
)
$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$py   = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'
$bin  = Join-Path $proj 'app_left\build\makcu_left.bin'

if (-not $NoBuild) {
    Write-Host '== building app_left (bench mode) =='
    & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $proj 'tools\build_app.ps1') `
        -App app_left -Define $Define | Select-String -Pattern 'binary size|error:' | ForEach-Object { $_.Line }
}
if (-not (Test-Path $bin)) { throw "image not found: $bin" }
$size = (Get-Item $bin).Length
Write-Host "== image: $bin ($size B) =="

function Find-Downloader {
    $p = Get-CimInstance Win32_SerialPort -ErrorAction SilentlyContinue |
         Where-Object { $_.PNPDeviceID -match 'VID_303A&PID_0009&MI_00' } |
         Select-Object -First 1
    if ($p) { return $p.DeviceID }
    return $null
}

$dl = Find-Downloader
if ($dl) {
    Write-Host "== left chip already in download mode: $dl =="
} else {
    Write-Host '== sending mx.dl on the control port =='
    $pyCode = @"
import serial, time
s = serial.Serial('$UartPort', 921600, timeout=0.3)
s.dtr = False; s.rts = False
time.sleep(0.3)
s.write(b'mx.dl\r'); s.flush(); time.sleep(0.6)
n = s.in_waiting
print('mx.dl reply:', repr(s.read(n) if n else b''))
s.close()
"@
    & $py -c $pyCode
    for ($i = 0; $i -lt 25 -and -not $dl; $i++) {
        Start-Sleep -Milliseconds 400
        $dl = Find-Downloader
    }
    if (-not $dl) {
        throw 'downloader port (VID_303A&PID_0009) never appeared - enter download mode by hand, then rerun with -NoBuild'
    }
    Write-Host "== downloader ready: $dl =="
}

Write-Host '== writing 0x10000 =='
& $py -m esptool --chip esp32s3 --port $dl --baud 921600 --before no_reset --after no_reset `
    write_flash 0x10000 $bin
if ($LASTEXITCODE -ne 0) { throw 'esptool write_flash failed' }

$readLen = [int]([math]::Ceiling($size / 4096.0)) * 4096
$lenArg  = '0x{0:x}' -f $readLen
$tmp = Join-Path $env:TEMP 'left_app_verify.bin'
& $py -m esptool --chip esp32s3 --port $dl --before no_reset --after no_reset `
    read_flash 0x10000 $lenArg $tmp | Out-Null
$a = [System.IO.File]::ReadAllBytes($tmp)
$b = [System.IO.File]::ReadAllBytes($bin)
$diff = 0
for ($i = 0; $i -lt $b.Length; $i++) { if ($a[$i] -ne $b[$i]) { $diff++ } }
Write-Host "== readback diff: $diff byte(s) =="
if ($diff -ne 0) { throw 'readback does not match the image' }

Write-Host '== OK =='
Write-Host 'Left chip is still in the ROM downloader: unplug/replug the left USB cable to boot the new firmware.'
