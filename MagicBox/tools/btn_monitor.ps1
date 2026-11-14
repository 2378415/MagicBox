# Button trace monitor: polls 0x44 BTN_LOG on the box control port and appends
# every new entry to a log file. ASCII only so Windows PowerShell 5.1 can parse it.
# Usage: powershell -File tools\btn_monitor.ps1 -Port COM3 -Seconds 240 -OutFile btn_trace.log
param(
    [string]$Port = 'COM3',
    [int]$Seconds = 60,
    [string]$OutFile = 'btn_trace.log'
)

function Crc8([byte[]]$d) {
    $c = 0
    foreach ($b in $d) {
        $c = $c -bxor $b
        for ($i = 0; $i -lt 8; $i++) {
            $c = if ($c -band 0x80) { (($c -shl 1) -bxor 0x07) -band 0xFF } else { ($c -shl 1) -band 0xFF }
        }
    }
    return $c
}

function Frame([byte]$cmd, [byte[]]$p, [byte]$seq) {
    $body = @($cmd, $seq, ($p.Length -band 0xFF), (($p.Length -shr 8) -band 0xFF)) + $p
    return [byte[]](@(0x5A) + $body + @(Crc8 ([byte[]]$body)))
}

$srcName = @('pass', 'SWALLOWED', 'mute-layer', 'inject')
$sp = New-Object System.IO.Ports.SerialPort($Port, 921600, 'None', 8, 'One')
$sp.ReadTimeout = 120
$sp.DtrEnable = $false
$sp.RtsEnable = $false
$sp.Open()
$sp.DiscardInBuffer()
Start-Sleep -Milliseconds 200

$lines = New-Object System.Collections.Generic.List[string]
$lines.Add(("=== BTN_TRACE {0} port={1} ===" -f (Get-Date -Format 'yyyy-MM-dd HH:mm:ss'), $Port)) | Out-Null
$since = 0
$seq = 0x30
$sw = [Diagnostics.Stopwatch]::StartNew()
$lastT = 0

while ($sw.Elapsed.TotalSeconds -lt $Seconds) {
    $seq = ($seq + 1) -band 0xFF
    $f = Frame 0x44 ([byte[]]@(($since -band 0xFF), (($since -shr 8) -band 0xFF))) ([byte]$seq)
    $sp.DiscardInBuffer()
    $sp.Write($f, 0, $f.Length)
    Start-Sleep -Milliseconds 60
    $buf = New-Object System.Collections.Generic.List[byte]
    while ($sp.BytesToRead -gt 0) { $buf.Add([byte]$sp.ReadByte()) }
    for ($i = 0; $i -le $buf.Count - 12; $i++) {
        if ($buf[$i] -ne 0x5A) { continue }
        $len = $buf[$i + 3] -bor ($buf[$i + 4] -shl 8)
        if ($len -lt 3 -or ($i + 4 + $len) -ge $buf.Count) { continue }
        $pl = $buf[($i + 5)..($i + 4 + $len)]
        $total = $pl[0] -bor ($pl[1] -shl 8)
        $count = $pl[2]
        for ($k = 0; $k -lt $count; $k++) {
            $o = 3 + $k * 8
            if (($o + 7) -ge $pl.Count) { break }
            $t = [BitConverter]::ToUInt32([byte[]]@($pl[$o], $pl[$o + 1], $pl[$o + 2], $pl[$o + 3]), 0)
            $raw = $pl[$o + 4]
            $fwd = $pl[$o + 5]
            $src = $pl[$o + 6]
            $name = if ($src -lt $srcName.Count) { $srcName[$src] } else { "src$src" }
            $dt = if ($lastT -gt 0) { $t - $lastT } else { 0 }
            $lastT = $t
            $line = "t={0}us (+{1}us) raw=0x{2:X2} fwd=0x{3:X2} {4}" -f $t, $dt, $raw, $fwd, $name
            $lines.Add($line) | Out-Null
        }
        $since = $total
        break
    }
    $lines | Set-Content -Path $OutFile -Encoding UTF8
}
$sp.Close()
$lines.Add("=== done ===") | Out-Null
$lines | Set-Content -Path $OutFile -Encoding UTF8
