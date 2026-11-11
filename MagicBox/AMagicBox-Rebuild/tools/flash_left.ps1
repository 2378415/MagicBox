# flash_left.ps1 - back up the box, flash the rebuilt app, verify, restore.
#
# The device on this desk is the LEFT chip (V3.2) reached through the CH343
# bridge; the same port carries the ROM download protocol via DTR/RTS.
#
#   pwsh -File tools\flash_left.ps1 -Action backup
#   pwsh -File tools\flash_left.ps1 -Action flash
#   pwsh -File tools\flash_left.ps1 -Action verify
#   pwsh -File tools\flash_left.ps1 -Action restore
#
# The restore image is written with the whole 4 MB dump so bootloader, partition
# table, NVS and the app all go back to the state of the backup.
param(
    [ValidateSet('backup', 'flash', 'verify', 'restore')][string]$Action = 'verify',
    [string]$Port = 'COM8',
    [string]$Backup = 'D:\JinPeng\MagicBox\work\hw_left_readback.bin'
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot
$py = 'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts\python.exe'

function Invoke-Esptool([string[]]$esptoolArgs) {
    & $py -m esptool --chip esp32s3 --port $Port --baud 921600 @esptoolArgs
    if ($LASTEXITCODE -ne 0) { throw "esptool failed: $($esptoolArgs -join ' ')" }
}

switch ($Action) {
    'backup' {
        New-Item -ItemType Directory -Force (Split-Path $Backup) | Out-Null
        Invoke-Esptool @('read_flash', '0x0', '0x400000', $Backup)
        Write-Host "backup written: $Backup ($((Get-Item $Backup).Length) bytes)"
    }
    'flash' {
        Push-Location (Join-Path $proj 'app_left')
        try {
            & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $proj 'tools\build_app.ps1') `
                -App app_left -Action ("-p $Port flash")
        } finally { Pop-Location }
    }
    'verify' {
        & $py (Join-Path $proj 'verification\regress\..\..\..\AMagicBox-Rebuild\tools\..\verification\regress\..\flash_verify.py') 2>$null
        if ($LASTEXITCODE -ne 0) {
            & $py (Join-Path $PSScriptRoot 'flash_verify.py') --port $Port
        }
    }
    'restore' {
        if (-not (Test-Path $Backup)) { throw "no backup at $Backup" }
        Invoke-Esptool @('write_flash', '0x0', $Backup)
        Write-Host 'original image restored'
        & $py (Join-Path $PSScriptRoot 'flash_verify.py') --port $Port
    }
}
