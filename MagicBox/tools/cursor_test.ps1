# cursor_test.ps1 - end-to-end proof that the rebuilt firmware moves the pointer.
#
# Requires: the device flashed with MB_HID_DEVICE=ON (enumerates as
# VID_303A&PID_4004 HID mouse) and the control port on -Port (UART0/CH343).
#
#   powershell -File tools\cursor_test.ps1 -Port COM8
param(
    [string]$Port = 'COM8',
    [int]$Baud = 921600
)

$ErrorActionPreference = 'Stop'

Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public static class Cursor {
    [DllImport("user32.dll")] public static extern bool GetCursorPos(out POINT p);
    public struct POINT { public int X; public int Y; }
    public static int[] Get() {
        POINT p; GetCursorPos(out p); return new int[] { p.X, p.Y };
    }
}
"@

function Measure-Move([string]$cmd) {
    $before = [Cursor]::Get()
    $sp = New-Object System.IO.Ports.SerialPort($Port, $Baud, 'None', 8, 'One')
    $sp.ReadTimeout = 500
    $sp.Open()
    try {
        $sp.DiscardInBuffer()
        $sp.Write($cmd + "`r")
        Start-Sleep -Milliseconds 700
        $reply = $sp.ReadExisting()
    } finally { $sp.Close() }
    $after = [Cursor]::Get()
    [pscustomobject]@{
        cmd    = $cmd
        reply  = $reply.TrimEnd()
        dx     = $after[0] - $before[0]
        dy     = $after[1] - $before[1]
        before = "$($before[0]),$($before[1])"
        after  = "$($after[0]),$($after[1])"
    }
}

Write-Host "port $Port, device must be enumerated as HID VID_303A&PID_4004"
Get-CimInstance Win32_PnPEntity |
    Where-Object { $_.DeviceID -match 'VID_303A&PID_4004' } |
    Select-Object Name, Status | Format-Table -AutoSize

$results = @(
    Measure-Move '.km.move(60,40)'
    Measure-Move '.km.move(-60,-40)'
    Measure-Move '.km.wheel(1)'
    Measure-Move '.km.silent(25,15)'
)
$results | Format-Table cmd, dx, dy, before, after -AutoSize
