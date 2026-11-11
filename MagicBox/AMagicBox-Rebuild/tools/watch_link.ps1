# watch_link.ps1 - live view of the left chip's UART1 counters.
#
# The counters are the only way to tell these apart:
#   rx_bytes grows, frames does not  -> bytes arrive but do not frame (baud/pins)
#   frames / hid_chunks grow         -> real two-chip traffic (right chip is talking)
#   nothing grows                    -> the right chip is silent (no reports, no power,
#                                       or the link is not on GPIO2/GPIO1)
#
# Usage (the control port must be free - no other tool may hold it):
#   powershell -NoProfile -File tools\watch_link.ps1
#   powershell -NoProfile -File tools\watch_link.ps1 -Port COM3 -Seconds 600
#
# Then move the mouse that is plugged into the right chip's host port.
param(
    [string]$Port = 'COM3',
    [int]$Baud = 921600,
    [int]$Seconds = 300,
    [int]$IntervalMs = 500,
    [switch]$SelfTest,         # send one loopback frame so the delta display can be checked
    [switch]$ProbeRight,       # poll the right chip's device state (0xA0 direction byte)
    [switch]$ArmA3,            # re-send the 0xA3 handshake so the right chip keeps forwarding
    [switch]$ProbeHid          # also print the HID send counters (mx.hs)
)

$ErrorActionPreference = 'Stop'
$sp = New-Object System.IO.Ports.SerialPort($Port, $Baud, 'None', 8, 'One')
$sp.ReadTimeout = 700
$sp.Open()
Start-Sleep -Milliseconds 200
$sp.DiscardInBuffer()

function Query($cmd) {
    $sp.DiscardInBuffer()
    $sp.Write("$cmd`r")
    Start-Sleep -Milliseconds 220
    return (($sp.ReadExisting() -replace "`r", '' -replace "`n", ''))
}


function RightState {
    # 0xA0 answers with the direction byte taken from the right chip's device state:
    #   00 -> a device is attached   ff -> nothing attached
    $sp.DiscardInBuffer()
    $sp.Write("mx.ln a0`r")
    Start-Sleep -Milliseconds 250
    $sp.DiscardInBuffer()
    $sp.Write("mx.lr`r")
    Start-Sleep -Milliseconds 250
    $raw = ($sp.ReadExisting() -replace "`r", '' -replace "`n", '')
    if ($raw -match 'cmd=a0 len=1 data=([0-9a-f]{2})') { return $Matches[1] }
    return '??'
}

$head = 'frames ep0_req ep0_in ep0_out hid a3 unk starts ends injected dropped rx_bytes'
$prev = $null
$start = Get-Date
Write-Host "watching $Port for $Seconds s   ($head)" -ForegroundColor Cyan
Write-Host "现在开始移动右片上的鼠标；计数变化会实时滚出来。" -ForegroundColor Yellow

try {
    $lastState = ''
    while (((Get-Date) - $start).TotalSeconds -lt $Seconds) {
        if ($ProbeRight) {
            $state = RightState
            if ($state -ne $lastState) {
                $stamp = (Get-Date).ToString('HH:mm:ss')
                if ($state -eq '00') {
                    Write-Host ("{0}  右片：**已枚举到设备**（0xA0 -> 00）" -f $stamp) -ForegroundColor Green
                } elseif ($state -eq 'ff') {
                    Write-Host ("{0}  右片：没有设备（0xA0 -> ff）" -f $stamp) -ForegroundColor Yellow
                } else {
                    Write-Host ("{0}  右片：无应答（{1}）" -f $stamp, $state) -ForegroundColor Red
                }
                $lastState = $state
            }
            Start-Sleep -Milliseconds 300
            continue
        }
        if ($ArmA3) {
            # frame_a3_flag (0x4200FAE0) sets *DAT_42000d48 = 1, and 0x4200FF10 only
            # queues a 0xA2 report when that flag is set - i.e. the right chip
            # forwards mouse reports only after the left chip announced itself.
            $sp.DiscardInBuffer()
            $sp.Write("mx.ln a3 00`r")
            Start-Sleep -Milliseconds 180
            $sp.DiscardInBuffer()
        }
        $hsText = ''
        if ($ProbeHid) {
            $hsRaw = Query 'mx.hs'
            if ($hsRaw -match 'km\.([0-9,]+)>>>') { $hsText = '   hs ok/busy/fail/nomount=' + $Matches[1] }
        }
        $reply = Query 'mx.ls'
        if ($reply -match '^km\.([0-9,]+)>>>') {
            $values = $Matches[1] -split ',' | ForEach-Object { [int]$_ }
            $joined = $values -join ','
            if ($prev) {
                $delta = @()
                for ($i = 0; $i -lt $values.Count; $i++) { $delta += ($values[$i] - $prev[$i]) }
                if (($delta | Measure-Object -Sum).Sum -ne 0) {
                    $stamp = (Get-Date).ToString('HH:mm:ss')
                    $deltaText = $delta -join ','
                    Write-Host ("{0}  frames {1,6}  hid {2,4}  injected {3,4}  rx {4,6}   delta {5}{6}" -f `
                        $stamp, $values[0], $values[4], $values[9], $values[11], $deltaText, $hsText) -ForegroundColor Green
                }
            } else {
                Write-Host ("baseline: " + $joined) -ForegroundColor DarkGray
                if ($SelfTest) {
                    $sp.Write("mx.lb`r")          # same port handle: shows the delta path
                    Start-Sleep -Milliseconds 300
                    $sp.DiscardInBuffer()
                }
            }
            $prev = $values
        }
        Start-Sleep -Milliseconds $IntervalMs
    }
} finally {
    $sp.Close()
}
Write-Host 'done' -ForegroundColor Cyan
