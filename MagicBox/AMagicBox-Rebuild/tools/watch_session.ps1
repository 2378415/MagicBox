# watch_session.ps1 - capture one bench session of the two-chip pass-through.
#
# Logs, once per tick, to a file (and to the console):
#   state  = the right chip's device state (mx.ln a0 -> mx.lr; 00 = device, ff = none)
#   frames = UART1 frames seen            (right chip is talking)
#   hid    = 0xA2 reports accepted        (real mouse data reached the left chip)
#   hs     = tud_hid_report outcome       (ok / busy / failed / no_mount)
#
# Run it, then do this on the bench:
#   1. (if state=ff) unplug/replug the mouse on the RIGHT chip
#   2. move the mouse until the cursor stops following
#   3. click left/right a few times
#   4. move again
# That sequence is what separates "the right chip stops forwarding" (frames/hid
# stop) from "the left chip stops injecting" (hid keeps growing, hs ok does not).
#
#   powershell -NoProfile -File tools\watch_session.ps1 -Port COM3 -Seconds 180
param(
    [string]$Port = 'COM3',
    [int]$Baud = 921600,
    [int]$Seconds = 180,
    [string]$OutFile = 'D:\JinPeng\MagicBox\work\watch_session.log'
)

$ErrorActionPreference = 'Stop'
$sp = New-Object System.IO.Ports.SerialPort($Port, $Baud, 'None', 8, 'One')
$sp.ReadTimeout = 600
$sp.Open()
Start-Sleep -Milliseconds 200
$sp.DiscardInBuffer()

function Q($cmd, $wait = 220) {
    $sp.DiscardInBuffer()
    $sp.Write("$cmd`r")
    Start-Sleep -Milliseconds $wait
    return (($sp.ReadExisting() -replace "`r", '' -replace "`n", ''))
}

function RightState {
    Q 'mx.ln a0' | Out-Null
    Start-Sleep -Milliseconds 90
    $r = Q 'mx.lr'
    if ($r -match 'cmd=a0 len=1 data=([0-9a-f]{2})') { return $Matches[1] }
    return '??'
}

$lines = New-Object System.Collections.Generic.List[string]
$lines.Add("== start $(Get-Date -Format 'HH:mm:ss') ==")
$prev = $null
$prevState = ''
$end = (Get-Date).AddSeconds($Seconds)

try {
    while ((Get-Date) -lt $end) {
        $state = RightState
        $ls = Q 'mx.ls'
        $hsText = '?'
        $hs = Q 'mx.hs'
        if ($hs -match 'km\.([0-9,]+)>>>') { $hsText = $Matches[1] }

        if ($ls -match 'km\.([0-9,]+)>>>') {
            $v = $Matches[1] -split ',' | ForEach-Object { [int]$_ }
            $changed = (-not $prev) -or ($v[0] -ne $prev[0]) -or ($v[4] -ne $prev[4]) -or ($state -ne $prevState)
            if ($changed) {
                $line = "{0}  state={1}  frames={2,6}  hid={3,5}  injected={4,5}  rx={5,7}  hs={6}" -f `
                    (Get-Date -Format 'HH:mm:ss'), $state, $v[0], $v[4], $v[9], $v[11], $hsText
                $lines.Add($line)
                Write-Host $line
            }
            $prev = $v
            $prevState = $state
        }
        Start-Sleep -Milliseconds 350
    }
} finally {
    $sp.Close()
    $lines.Add("== end $(Get-Date -Format 'HH:mm:ss') ==")
    $lines | Set-Content -Path $OutFile -Encoding UTF8
    Write-Host "log -> $OutFile" -ForegroundColor Green
}
