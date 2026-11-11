# set_fs.ps1 - set the pass-through forward decimator.
#
#   powershell -NoProfile -File tools\set_fs.ps1 -N 1     # forward every report (default)
#   powershell -NoProfile -File tools\set_fs.ps1 -N 2     # drop every 2nd report
#   powershell -NoProfile -File tools\set_fs.ps1 -N 3     # drop 2 of every 3
#
# Use it to find the setting where the cursor speed matches the physical mouse;
# once the right value is known the cause can be fixed properly (a decimator is
# only a calibration knob, not the intended final behaviour).
param(
    [string]$Port = 'COM3',
    [Parameter(Mandatory = $true)][int]$N
)

$ErrorActionPreference = 'Stop'
$sp = New-Object System.IO.Ports.SerialPort($Port, 921600, 'None', 8, 'One')
$sp.ReadTimeout = 800
$sp.Open()
Start-Sleep -Milliseconds 250
$sp.DiscardInBuffer()
$sp.Write("mx.fs $N`r")
Start-Sleep -Milliseconds 400
$reply = ($sp.ReadExisting() -replace "`r", '' -replace "`n", '')
$sp.Close()
Write-Host "mx.fs $N -> $reply"
