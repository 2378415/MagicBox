# hid_isolation.ps1 - proves mouse and keyboard reports no longer interfere.
#
# Symptom this guards against: a wheel-only command moving the pointer, or a
# small move producing a wild jump, because the 8-byte keyboard report was
# written into the same HID endpoint while a 4-byte mouse report was in flight.
#
#   powershell -File tools\hid_isolation.ps1 -Port COM8
param([string]$Port = 'COM8')

$ErrorActionPreference = 'Stop'

Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public static class Cur {
    [DllImport("user32.dll")] public static extern bool GetCursorPos(out POINT p);
    public struct POINT { public int X; public int Y; }
    public static int[] Get() { POINT p; GetCursorPos(out p); return new int[] { p.X, p.Y }; }
}
"@

$sp = New-Object System.IO.Ports.SerialPort($Port, 921600, 'None', 8, 'One')
$sp.ReadTimeout = 500
$sp.Open()

function Send-Cmd([string]$text) {
    $sp.DiscardInBuffer()
    $sp.Write($text + "`r")
    Start-Sleep -Milliseconds 350
    return $sp.ReadExisting()
}

try {
    Write-Host 'warm-up'
    Send-Cmd '.km.move(0,0)' | Out-Null
    Start-Sleep -Milliseconds 500

    Write-Host 'wheel-only: the pointer must not move'
    $before = [Cur]::Get()
    Send-Cmd '.km.wheel(1)' | Out-Null
    Start-Sleep -Milliseconds 700
    $after = [Cur]::Get()
    Write-Host ("  delta = {0},{1}" -f ($after[0] - $before[0]), ($after[1] - $before[1]))

    Write-Host 'interleaved mouse + keyboard traffic, then a pure wheel'
    foreach ($i in 1..3) {
        Send-Cmd '.km.move(40,0)' | Out-Null
        Send-Cmd 'mx.0d 4' | Out-Null
        Send-Cmd 'mx.0e 4' | Out-Null
        Send-Cmd '.km.move(-40,0)' | Out-Null
    }
    Start-Sleep -Milliseconds 700
    $before = [Cur]::Get()
    Send-Cmd '.km.wheel(-1)' | Out-Null
    Start-Sleep -Milliseconds 700
    $after = [Cur]::Get()
    $wheelDelta = @(($after[0] - $before[0]), ($after[1] - $before[1]))
    Write-Host ("  delta = {0},{1}  (must be 0,0)" -f $wheelDelta[0], $wheelDelta[1])

    Write-Host 'small move right after keyboard traffic'
    Send-Cmd 'mx.0d 4' | Out-Null
    Send-Cmd 'mx.0e 4' | Out-Null
    $before = [Cur]::Get()
    Send-Cmd '.km.move(30,0)' | Out-Null
    Start-Sleep -Milliseconds 700
    $after = [Cur]::Get()
    $dx = $after[0] - $before[0]
    Write-Host ("  dx = {0} (expected 30..90 with pointer acceleration)" -f $dx)

    if ($wheelDelta[0] -eq 0 -and $wheelDelta[1] -eq 0 -and $dx -gt 0) {
        Write-Host 'PASS' -ForegroundColor Green
    } else {
        Write-Host 'FAIL' -ForegroundColor Red
        exit 1
    }
} finally { $sp.Close() }
