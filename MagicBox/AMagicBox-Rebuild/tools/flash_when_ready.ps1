# flash_when_ready.ps1 - flash as soon as the ROM downloader shows up.
#
# The board only exposes a usable USB port while it is in ROM download mode
# (hold BOOT / IO0, then plug in or tap RESET).  This script polls for it and
# flashes immediately, so the button press is only needed once.
#
#   powershell -File tools\flash_when_ready.ps1 -Control COM8
param(
    [string]$Control = 'COM8',
    [string]$Baud = '921600',
    [int]$TimeoutSec = 180
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$build = Join-Path $proj 'app_left\build'
$esptool = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'

if (-not (Test-Path (Join-Path $build 'flash_args'))) {
    throw "no build/flash_args - build app_left first"
}

Write-Host "waiting for a download-mode port (control port $Control excluded) ..."
$deadline = (Get-Date).AddSeconds($TimeoutSec)
$target = $null
while ((Get-Date) -lt $deadline) {
    $ports = [System.IO.Ports.SerialPort]::GetPortNames() | Where-Object { $_ -ne $Control }
    foreach ($p in $ports) {
        # a port that opens is a live one; ROM mode answers within a second
        try {
            $sp = New-Object System.IO.Ports.SerialPort($p, 921600, 'None', 8, 'One')
            $sp.ReadTimeout = 300
            $sp.Open()
            $sp.Close()
            $target = $p
            break
        } catch { }
    }
    if ($target) { break }
    Start-Sleep -Milliseconds 500
}

if (-not $target) { throw "no usable port appeared within ${TimeoutSec}s" }
Write-Host "flashing through $target"

Push-Location $build
try {
    $args = @('-m', 'esptool', '--chip', 'esp32s3', '--port', $target,
              '--baud', $Baud, '--before', 'no_reset', '--after', 'hard_reset',
              'write_flash', '@flash_args')
    & $esptool @args
    if ($LASTEXITCODE -ne 0) { throw "esptool failed ($LASTEXITCODE)" }
} finally {
    Pop-Location
}
Write-Host 'flash done'
