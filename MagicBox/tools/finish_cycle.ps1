# finish_cycle.ps1 - flash the build that is already in app_left/build, run the
# tests, then restore the factory image.
#
#   powershell -File tools\finish_cycle.ps1 -Control COM8
param(
    [string]$Control = 'COM8',
    [string]$Backup = 'D:\JinPeng\MagicBox\work\hw_left_before_rebuild.ps1'.Replace('.ps1', '.bin'),
    [int]$WaitSec = 300,
    [switch]$KeepImage
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$py = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'   # esptool
$pySys = 'D:\Apply\Python311\python.exe'                                # pytest
$build = Join-Path $proj 'app_left\build'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$log = Join-Path $proj "verification\report\finish-$stamp.log"

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

"waiting for the download-mode port ..." | Tee-Object -FilePath $log
$dl = Wait-Port $WaitSec $Control
if (-not $dl) { throw "no download port in ${WaitSec}s (hold BOOT while plugging the native cable)" }

"flashing through $dl" | Tee-Object -FilePath $log -Append
Push-Location $build
try {
    & $py -m esptool --chip esp32s3 --port $dl --baud 921600 --before no_reset --after hard_reset `
        write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB `
        0x0 bootloader\bootloader.bin 0x8000 partition_table\partition-table.bin 0x10000 makcu_left.bin `
        2>&1 | Tee-Object -FilePath $log -Append | Select-Object -Last 3
} finally { Pop-Location }
Start-Sleep -Seconds 4

"running regression over $Control ..." | Tee-Object -FilePath $log -Append
Push-Location $proj
try {
    $env:MAKCU_PORT = $Control
    $env:MAKCU_SKIP_HW = '0'
    & $pySys -m pytest verification\regress verification\model -q 2>&1 |
        Tee-Object -FilePath $log -Append | Select-Object -Last 8
} finally { Pop-Location }

if ($KeepImage) { "keeping the rebuilt image on the device" | Tee-Object -FilePath $log -Append; return }

"restoring the factory image ..." | Tee-Object -FilePath $log -Append
& $py (Join-Path $PSScriptRoot 'recover_download.py') --port $Control | Tee-Object -FilePath $log -Append
$dl2 = Wait-Port 30 $Control
if (-not $dl2) { throw 'download port did not come back after mx.dl' }

& $py -m esptool --chip esp32s3 --port $dl2 --baud 921600 --before no_reset --after no_reset `
    write_flash 0x0 $Backup 2>&1 | Tee-Object -FilePath $log -Append | Select-Object -Last 2

$readback = Join-Path (Split-Path $Backup) 'hw_left_after_restore.bin'
& $py -m esptool --chip esp32s3 --port $dl2 --baud 921600 --before no_reset --after hard_reset `
    read_flash 0x0 0x400000 $readback 2>&1 | Tee-Object -FilePath $log -Append | Select-Object -Last 2

& $py (Join-Path $PSScriptRoot '..\work\cmp_restore.py') 2>&1 |
    Tee-Object -FilePath $log -Append | Select-Object -Last 5

"done, log: $log" | Tee-Object -FilePath $log -Append
