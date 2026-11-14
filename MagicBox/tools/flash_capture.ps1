# flash_capture.ps1 - flash app_left over the ROM loader on UART0 and grab the
# boot + enumeration log.
#
# The board keeps the CH343 on UART0 attached, so a full cycle needs no BOOT
# press: `mx.dl` reboots into the ROM downloader (D21), esptool writes from
# COM8/COM3 and hard-resets, and this script reopens the port immediately to
# capture the TinyUSB debug stream of the first enumeration.
#
#   pwsh -File tools\flash_capture.ps1 -Port COM3 -Seconds 12
param(
    [string]$Port   = 'COM3',
    [int]$Seconds   = 12,
    # The control port moved to 921600 (see docs/HANDOVER.md 14.20).  The ROM
    # downloader still syncs at 115200 - esptool raises the rate itself.
    [int]$Baud      = 921600,
    [string]$OutFile = 'D:\JinPeng\MagicBox\work\usbdiag\boot_log.txt'
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$build = Join-Path $proj 'app_left\build'
$py = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'

function Enter-DownloadMode([string]$p) {
    $sp = New-Object System.IO.Ports.SerialPort($p, $Baud, 'None', 8, 'One')
    $sp.ReadTimeout = 400
    $sp.Open()
    try {
        $sp.DiscardInBuffer()
        $sp.Write("mx.dl`r")
        Start-Sleep -Milliseconds 900
        $banner = $sp.ReadExisting()
    } finally { $sp.Close() }
    if ($banner -notmatch 'waiting for download') {
        throw "no ROM banner on ${p}: " + ($banner -replace '[^\x20-\x7e]', '.')
    }
    Write-Host ($banner -split "`n" | Where-Object { $_ -match 'boot:0x|waiting' }) -ForegroundColor Cyan
}

Enter-DownloadMode $Port
Start-Sleep -Seconds 2

Push-Location $build
try {
    & $py -m esptool --chip esp32s3 --port $Port --baud 921600 --before no_reset --after hard_reset `
        write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB `
        0x0 bootloader\bootloader.bin 0x8000 partition_table\partition-table.bin 0x10000 makcu_left.bin
    if ($LASTEXITCODE -ne 0) { throw "flash failed ($LASTEXITCODE)" }
} finally { Pop-Location }

# grab the boot log straight away: the app is already running by the time esptool
# releases the port, so the first lines may be lost - the enumeration follows and
# that is what this run is about.
New-Item -ItemType Directory -Force -Path (Split-Path $OutFile) | Out-Null
$sp = New-Object System.IO.Ports.SerialPort($Port, $Baud, 'None', 8, 'One')
$sp.Open()
$sb = New-Object System.Text.StringBuilder
$deadline = (Get-Date).AddSeconds($Seconds)
try {
    while ((Get-Date) -lt $deadline) {
        $n = $sp.BytesToRead
        if ($n -gt 0) { [void]$sb.Append($sp.ReadExisting()) }
        else { Start-Sleep -Milliseconds 60 }
    }
} finally { $sp.Close() }
Set-Content -Path $OutFile -Value $sb.ToString() -Encoding UTF8
Write-Host "log -> $OutFile ($($sb.Length) chars)" -ForegroundColor Green
$sb.ToString() -split "`r?`n" | Where-Object { $_ -match 'tusb|USBD|usbd|HID|mount|configur|SET_|GET_|dev_addr|bus_reset|ESP_|makcu|Stall|stall' } | Select-Object -First 60
