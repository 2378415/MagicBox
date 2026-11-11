# Read the right chip's memory through the patched 0xA5 opcode (op 0xEE).
#
#   . tools\rd_right.ps1 -Port COM3
#   Read-RightBytes -Addr 0x3FC9FD64 -Count 32
#
# Reply framing: frame = 5A A5 <len:u16> <bytes...>; we chunk in 8-byte reads
# because a longer reply overruns the right chip's TX buffer.
param([string]$Port = 'COM3')

$script:ser = $null

function Connect-Right {
    param([string]$p = $Port)
    for ($i = 0; $i -lt 10; $i++) {
        try {
            $script:ser = New-Object System.IO.Ports.SerialPort($p, 115200, 'None', 8, 'One')
            $script:ser.ReadTimeout = 800
            $script:ser.Open()
            Start-Sleep -Milliseconds 400
            $script:ser.DiscardInBuffer()
            return $true
        } catch {
            Start-Sleep -Milliseconds 700
            $script:ser = $null
        }
    }
    return $false
}

function Send-Line([string]$cmd) {
    $script:ser.DiscardInBuffer()
    $script:ser.Write("$cmd`r")
    Start-Sleep -Milliseconds 80
    return ($script:ser.ReadExisting() -replace "`r", '' -replace "`n", '')
}

function Read-RightChunk {
    param([uint32]$Addr, [byte]$Count)
    $cmd = "mx.ln a5 EE0800{0:X8}{1:X2}" -f $Addr, $Count
    $script:ser.DiscardInBuffer()
    $script:ser.Write("$cmd`r")
    Start-Sleep -Milliseconds 90
    for ($k = 0; $k -lt 16; $k++) {
        $r = Send-Line 'mx.lr'
        if ($r -match 'cmd=a5 len=(\d+) data=([0-9a-f]*)') {
            return $Matches[2]
        }
    }
    return ''
}

function Read-RightBytes {
    param([uint32]$Addr, [int]$Count)
    $out = ''
    $off = 0
    while ($off -lt $Count) {
        $n = [Math]::Min(8, $Count - $off)
        $hex = Read-RightChunk -Addr ($Addr + $off) -Count ([byte]$n)
        if (-not $hex) { return $out + ('??' * ($Count - $off)) }
        $out += $hex
        $off += $n
        Start-Sleep -Milliseconds 30
    }
    return $out
}

function HexToU32 {
    param([string]$Hex)          # little-endian hex string, 8 chars per word
    $vals = @()
    for ($i = 0; $i + 8 -le $Hex.Length; $i += 8) {
        $seg = $Hex.Substring($i, 8)
        $v = 0
        for ($k = 3; $k -ge 0; $k--) { $v = ($v -shl 8) -bor [Convert]::ToUInt32($seg.Substring($k * 2, 2), 16) }
        $vals += $v
    }
    return $vals
}

function Close-Right { if ($script:ser -and $script:ser.IsOpen) { $script:ser.Close() } }
