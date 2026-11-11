# run_bench_cycle.ps1 - one command for the whole bench cycle.
#
# Flow (only the first step needs a finger on BOOT):
#   1. wait for the ROM downloader port (hold BOOT while plugging the native cable)
#   2. build + flash app_left WITHOUT the HID device (keeps the USB-Serial-JTAG
#      console alive, so every later flash works in software)
#   3. run verification/regress + verification/model over the control port
#   4. send mx.dl to re-enter download mode, restore the factory image, verify
#
#   powershell -File tools\run_bench_cycle.ps1 -Control COM8
param(
    [string]$Control = 'COM8',
    [string]$Backup = 'D:\JinPeng\MagicBox\work\hw_left_before_rebuild.bin',
    [int]$WaitSec = 300,
    [switch]$WithHid
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$py = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$log = Join-Path $proj "verification\report\bench-cycle-$stamp.log"
New-Item -ItemType Directory -Force (Split-Path $log) | Out-Null
Start-Transcript -Path $log | Out-Null

function Wait-Port([int]$seconds, [string]$exclude) {
    $deadline = (Get-Date).AddSeconds($seconds)
    while ((Get-Date) -lt $deadline) {
        foreach ($p in ([System.IO.Ports.SerialPort]::GetPortNames() | Where-Object { $_ -ne $exclude })) {
            try {
                $sp = New-Object System.IO.Ports.SerialPort($p, 115200, 'None', 8, 'One')
                $sp.ReadTimeout = 300
                $sp.Open(); $sp.Close()
                return $p
            } catch { }
        }
        Start-Sleep -Milliseconds 400
    }
    return $null
}

function Build-Flash([string]$port, [string]$hid) {
    Push-Location (Join-Path $proj 'app_left')
    try {
        & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $proj 'tools\build_app.ps1') `
            -App app_left -Clean -Define "-DMB_DEBUG_OPCODE=ON","-DMB_HID_DEVICE=$hid"
        if ($LASTEXITCODE -ne 0) { throw "build failed ($hid)" }
        & $py -m esptool --chip esp32s3 --port $port --baud 921600 --before no_reset `
            --after hard_reset write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB `
            0x0 build\bootloader\bootloader.bin `
            0x8000 build\partition_table\partition-table.bin `
            0x10000 build\makcu_left.bin
        if ($LASTEXITCODE -ne 0) { throw "flash failed ($hid)" }
    } finally { Pop-Location }
}

Write-Host '[1/4] waiting for the download-mode port ...' -ForegroundColor Cyan
$dl = Wait-Port $WaitSec $Control
if (-not $dl) { throw "no download port in ${WaitSec}s (hold BOOT while plugging the native cable)" }
Write-Host "      port $dl"

Write-Host '[2/4] build + flash (console build, harness on) ...' -ForegroundColor Cyan
Build-Flash $dl 'OFF'
Start-Sleep -Seconds 4
$usbPort = Wait-Port 20 $Control
Write-Host "      usb console port: $usbPort"

Write-Host '[3/4] regression (protocol + reports + model) ...' -ForegroundColor Cyan
Push-Location $proj
try {
    $env:MAKCU_PORT = $Control
    $env:MAKCU_SKIP_HW = '0'
    & $py -m pytest verification\regress verification\model -q
    $regress = $LASTEXITCODE
} finally { Pop-Location }
Write-Host "      pytest exit=$regress"

if ($WithHid) {
    Write-Host '[3b] build + flash the HID variant, then measure the pointer ...' -ForegroundColor Cyan
    Build-Flash $usbPort 'ON'
    Start-Sleep -Seconds 4
    & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'cursor_test.ps1') -Port $Control
}

Write-Host '[4/4] mx.dl -> restore factory image ...' -ForegroundColor Cyan
& $py (Join-Path $PSScriptRoot 'recover_download.py') --port $Control
$dl2 = Wait-Port 30 $Control
if (-not $dl2) { throw 'download port did not come back after mx.dl' }
& $py -m esptool --chip esp32s3 --port $dl2 --baud 921600 --before no_reset `
    --after no_reset write_flash 0x0 $Backup
$readback = Join-Path (Split-Path $Backup) 'hw_left_after_restore.bin'
& $py -m esptool --chip esp32s3 --port $dl2 --baud 921600 --before no_reset `
    --after hard_reset read_flash 0x0 0x400000 $readback
& $py (Join-Path $PSScriptRoot '..\..\work\cmp_restore.py')
Stop-Transcript | Out-Null
Write-Host "cycle done, log: $log" -ForegroundColor Green
