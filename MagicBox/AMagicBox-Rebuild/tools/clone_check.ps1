# clone_check.ps1 - host-side proof that the descriptor clone took effect.
#
# Loads a canned identity through the bench command and watches what Windows
# enumerates.  Needs the HID build (-DMB_HID_DEVICE=ON -DMB_DEBUG_OPCODE=ON).
#
#   powershell -File tools\clone_check.ps1 -Port COM8
param([string]$Port = 'COM8')

$ErrorActionPreference = 'Stop'
$sp = New-Object System.IO.Ports.SerialPort($Port, 921600, 'None', 8, 'One')
$sp.Open()

function Send-Cmd([string]$text) {
    $sp.DiscardInBuffer()
    $sp.Write($text + "`r")
    Start-Sleep -Milliseconds 400
    return $sp.ReadExisting().Trim()
}

function Show-Identity([string]$label) {
    $rows = Get-CimInstance Win32_PnPEntity |
        Where-Object { $_.DeviceID -match 'VID_046D|VID_303A' } |
        Select-Object DeviceID, Name
    Write-Host "== $label ==" -ForegroundColor Cyan
    if (-not $rows) { Write-Host '  (no matching USB device)' }
    $rows | Format-Table -AutoSize
}

try {
    Show-Identity 'before'
    Write-Host ('mx.cl        -> ' + (Send-Cmd 'mx.cl'))
    Start-Sleep -Seconds 3
    Show-Identity 'after mx.cl (expect 046D:C077)'
    Write-Host ('mx.cl 2      -> ' + (Send-Cmd 'mx.cl 2'))
    Start-Sleep -Seconds 3
    Show-Identity 'after mx.cl 2 (expect 046D:C52F)'
    Write-Host ('mx.cc        -> ' + (Send-Cmd 'mx.cc'))
    Start-Sleep -Seconds 3
    Show-Identity 'after mx.cc (expect 303A:4004 back)'
} finally { $sp.Close() }
