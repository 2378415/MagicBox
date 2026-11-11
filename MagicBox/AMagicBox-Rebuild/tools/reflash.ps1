# reflash.ps1 - flash without touching the board.
#
# Discovery (2026-11-09): in ROM download mode the loader also answers on
# UART0, i.e. through the CH343 (COM8) that is already attached.  Together with
# the `mx.dl` harness command that means a full cycle needs no BOOT press:
#
#   mx.dl  -> chip reboots into the ROM loader, banner "DOWNLOAD(USB/UART0)"
#   esptool --port COM8 --before no_reset ... write_flash
#
# Usage:
#   powershell -File tools\reflash.ps1 -Port COM8                    # flash app_left/build
#   powershell -File tools\reflash.ps1 -Port COM8 -Restore           # restore factory image
param(
    [string]$Port = 'COM8',
    [string]$Baud = '921600',
    [string]$Backup = 'D:\JinPeng\MagicBox\work\hw_left_before_rebuild.bin',
    [switch]$Restore,
    [switch]$SkipDownload
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$py = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'
$pySys = 'D:\Apply\Python311\python.exe'

function Enter-DownloadMode([string]$port) {
    $sp = New-Object System.IO.Ports.SerialPort($port, 921600, 'None', 8, 'One')
    $sp.ReadTimeout = 400
    $sp.Open()
    try {
        $sp.DiscardInBuffer()
        $sp.Write("mx.dl`r")
        Start-Sleep -Milliseconds 800
        $banner = $sp.ReadExisting()
    } finally { $sp.Close() }
    if ($banner -notmatch 'waiting for download') {
        throw "no ROM banner on $port (got: $($banner -replace '[^\x20-\x7e]', '.'))"
    }
    Write-Host "ROM loader is up: $((($banner -split "`n") | Where-Object { $_ -match 'boot:0x' }) -join '')"
}

if (-not $SkipDownload) {
    Enter-DownloadMode $Port
    Start-Sleep -Seconds 2
}

if ($Restore) {
    Write-Host "restoring $Backup"
    & $py -m esptool --chip esp32s3 --port $Port --baud $Baud --before no_reset --after no_reset write_flash 0x0 $Backup
    if ($LASTEXITCODE -ne 0) { throw "restore write failed ($LASTEXITCODE)" }
    $readback = Join-Path (Split-Path $Backup) 'hw_left_after_restore.bin'
    Remove-Item $readback -ErrorAction SilentlyContinue
    & $py -m esptool --chip esp32s3 --port $Port --baud $Baud --before no_reset --after hard_reset read_flash 0x0 0x400000 $readback
    & $pySys (Join-Path (Split-Path $PSScriptRoot) 'work\cmp_restore.py')
    return
}

$build = Join-Path $proj 'app_left\build'
Write-Host "flashing app_left/build"
Push-Location $build
try {
    & $py -m esptool --chip esp32s3 --port $Port --baud $Baud --before no_reset --after hard_reset `
        write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB `
        0x0 bootloader\bootloader.bin 0x8000 partition_table\partition-table.bin 0x10000 makcu_left.bin
    if ($LASTEXITCODE -ne 0) { throw "flash failed ($LASTEXITCODE)" }
} finally { Pop-Location }
Write-Host 'flash done'
